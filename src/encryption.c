/*
 * Encryption Module Implementation
 * 
 * This module implements encryption/decryption using Windows Data Protection API (DPAPI).
 * 
 * DPAPI Overview:
 *   - CryptProtectData() encrypts data using keys derived from machine credentials
 *   - CryptUnprotectData() decrypts data encrypted on the same machine
 *   - No explicit key management needed
 *   - Keys are managed by Windows LSA (Local Security Authority)
 *   - Data can be decrypted by any user on the same machine
 * 
 * Security Properties:
 *   - Machine-specific: Any user/process on this machine can decrypt
 *   - Machine-bound: Data encrypted on one machine can't be decrypted on another
 *   - Integrates with Windows security: Uses machine's encryption keys
 *   - Supports autostart scenarios: SYSTEM account can decrypt user-encrypted data
 * 
 * Use Cases:
 *   - Protecting sensitive application data (like our CSV file)
 *   - Storing configuration with sensitive information
 *   - Local credential storage
 *   - Applications that run under SYSTEM (autostart, services)
 * 
 * Version History:
 *   - v1.0-1.3: Used user-specific encryption (CRYPTPROTECT_LOCAL_MACHINE not set)
 *   - v1.4+: Changed to machine-level encryption to support autostart scenarios
 */

#include <windows.h>
#include <wincrypt.h>
#include <stdio.h>
#include "encryption.h"

// Optional entropy to add extra layer of security
// This is a constant "salt" that makes the encryption more unique to our application
// Even if another application uses DPAPI, they won't be able to decrypt our data
// without knowing this entropy value
static const BYTE ENTROPY_DATA[] = "WinRDP-CSV-Encryption-v1.3";
static const DWORD ENTROPY_SIZE = sizeof(ENTROPY_DATA);

/*
 * EncryptData - Encrypt data using Windows DPAPI
 * 
 * Learning Notes - DPAPI Encryption:
 * 
 * 1. DATA_BLOB Structure:
 *    - Simple structure with cbData (size) and pbData (pointer to data)
 *    - Used for both input and output
 * 
 * 2. CryptProtectData Function:
 *    - Takes plaintext DATA_BLOB, returns ciphertext DATA_BLOB
 *    - Optional description (we use "WinRDP CSV Data")
 *    - Optional entropy (additional secret for extra security)
 *    - Flags: 0 for current user, or CRYPTPROTECT_LOCAL_MACHINE
 * 
 * 3. Memory Management:
 *    - CryptProtectData allocates memory using LocalAlloc
 *    - Caller must free with LocalFree (not free!)
 *    - We return the pointer and size to caller
 * 
 * 4. Error Handling:
 *    - Returns FALSE on failure
 *    - Use GetLastError() to get error code
 *    - Common errors: ERROR_INVALID_PARAMETER, ERROR_NOT_ENOUGH_MEMORY
 */
BOOL EncryptData(const BYTE* plaintext, DWORD plaintextSize,
                 BYTE** ciphertext, DWORD* ciphertextSize)
{
    // Input validation
    if (plaintext == NULL || plaintextSize == 0 || 
        ciphertext == NULL || ciphertextSize == NULL)
    {
        return FALSE;
    }
    
    // Initialize output parameters
    *ciphertext = NULL;
    *ciphertextSize = 0;
    
    // Set up input data blob
    DATA_BLOB dataIn;
    dataIn.pbData = (BYTE*)plaintext;
    dataIn.cbData = plaintextSize;
    
    // Set up entropy (optional additional secret)
    DATA_BLOB entropy;
    entropy.pbData = (BYTE*)ENTROPY_DATA;
    entropy.cbData = ENTROPY_SIZE;
    
    // Output data blob (will be filled by CryptProtectData)
    DATA_BLOB dataOut;
    ZeroMemory(&dataOut, sizeof(dataOut));
    
    /*
     * CryptProtectData - The main DPAPI encryption function
     * 
     * Parameters:
     *   1. Input data blob (our plaintext)
     *   2. Description (shown in Credential Manager if stored there)
     *   3. Optional entropy (extra secret, NULL if not used)
     *   4. Reserved (must be NULL)
     *   5. Prompt struct (NULL = no UI prompt)
     *   6. Flags (CRYPTPROTECT_LOCAL_MACHINE = machine-level encryption)
     *   7. Output data blob (receives encrypted data)
     * 
     * The function allocates memory for dataOut.pbData using LocalAlloc
     * 
     * CRYPTPROTECT_LOCAL_MACHINE allows any user/process on this machine to decrypt,
     * including SYSTEM account (needed for autostart scenarios). This is less secure
     * than user-specific encryption, but necessary for services and autostart apps.
     */
    if (!CryptProtectData(
            &dataIn,                    // Data to encrypt
            L"WinRDP CSV Data",         // Description
            &entropy,                   // Optional entropy
            NULL,                       // Reserved
            NULL,                       // Prompt struct
            CRYPTPROTECT_LOCAL_MACHINE, // Flags (machine-level encryption)
            &dataOut))                  // Output
    {
        DWORD error = GetLastError();
        
        // Log error for debugging (in production, you might want better logging)
        wchar_t errorMsg[256];
        swprintf_s(errorMsg, 256, 
                   L"CryptProtectData failed with error code: %lu\n"
                   L"This might indicate system security issues or insufficient permissions.",
                   error);
        MessageBoxW(NULL, errorMsg, L"Encryption Error", MB_OK | MB_ICONERROR);
        
        return FALSE;
    }
    
    // Success! Return the encrypted data
    // Note: Caller is responsible for calling LocalFree on this pointer
    *ciphertext = dataOut.pbData;
    *ciphertextSize = dataOut.cbData;
    
    return TRUE;
}

/*
 * DecryptData - Decrypt data using Windows DPAPI
 * 
 * Learning Notes - DPAPI Decryption:
 * 
 * 1. Symmetry with Encryption:
 *    - Same DATA_BLOB structure used
 *    - Must use same entropy that was used for encryption
 *    - Must use same flags (CRYPTPROTECT_LOCAL_MACHINE) for machine-level data
 * 
 * 2. CryptUnprotectData Function:
 *    - Reverses CryptProtectData
 *    - Automatically handles verification based on encryption mode
 *    - Returns original plaintext
 * 
 * 3. Security:
 *    - Machine-level: Any user/process on this machine can decrypt
 *    - Will fail if entropy doesn't match
 *    - Will fail if data is corrupted
 *    - Will fail if encrypted on different machine
 * 
 * 4. Description:
 *    - Can optionally retrieve description string
 *    - We don't need it, so we pass NULL
 */
BOOL DecryptData(const BYTE* ciphertext, DWORD ciphertextSize,
                 BYTE** plaintext, DWORD* plaintextSize)
{
    // Input validation
    if (ciphertext == NULL || ciphertextSize == 0 || 
        plaintext == NULL || plaintextSize == NULL)
    {
        return FALSE;
    }
    
    // Initialize output parameters
    *plaintext = NULL;
    *plaintextSize = 0;
    
    // Set up input data blob (encrypted data)
    DATA_BLOB dataIn;
    dataIn.pbData = (BYTE*)ciphertext;
    dataIn.cbData = ciphertextSize;
    
    // Set up entropy (must match what was used for encryption)
    DATA_BLOB entropy;
    entropy.pbData = (BYTE*)ENTROPY_DATA;
    entropy.cbData = ENTROPY_SIZE;
    
    // Output data blob (will be filled by CryptUnprotectData)
    DATA_BLOB dataOut;
    ZeroMemory(&dataOut, sizeof(dataOut));
    
    /*
     * CryptUnprotectData - The main DPAPI decryption function
     * 
     * Parameters:
     *   1. Input data blob (encrypted data)
     *   2. Optional description output (NULL if we don't need it)
     *   3. Optional entropy (must match encryption entropy)
     *   4. Reserved (must be NULL)
     *   5. Prompt struct (NULL = no UI prompt)
     *   6. Flags (CRYPTPROTECT_LOCAL_MACHINE for machine-level decryption)
     *   7. Output data blob (receives decrypted data)
     * 
     * The function allocates memory for dataOut.pbData using LocalAlloc
     * 
     * Note: The flags parameter should match what was used during encryption.
     * Since we use CRYPTPROTECT_LOCAL_MACHINE for encryption, we use it here too.
     */
    if (!CryptUnprotectData(
            &dataIn,                    // Encrypted data
            NULL,                       // Description (we don't need it back)
            &entropy,                   // Optional entropy (must match!)
            NULL,                       // Reserved
            NULL,                       // Prompt struct
            CRYPTPROTECT_LOCAL_MACHINE, // Flags (must match encryption)
            &dataOut))                  // Output
    {
        /*
         * Common error codes:
         *   ERROR_INVALID_DATA - Data is corrupted or not encrypted with DPAPI
         *   ERROR_INVALID_PARAMETER - Bad parameters
         *   NTE_BAD_DATA - Wrong user or wrong entropy
         * 
         * We don't show error dialog here - might be legitimate (file not encrypted yet)
         * Let the caller handle it appropriately
         */
        return FALSE;
    }
    
    // Success! Return the decrypted data
    // Note: Caller is responsible for calling LocalFree on this pointer
    *plaintext = dataOut.pbData;
    *plaintextSize = dataOut.cbData;
    
    return TRUE;
}

