/*
 * Encryption Module Header
 * 
 * This module provides encryption/decryption functionality for sensitive data
 * using Windows Data Protection API (DPAPI).
 * 
 * DPAPI provides machine-level encryption without requiring explicit key management.
 * The encryption keys are derived from the machine's credentials and managed
 * by Windows automatically.
 * 
 * Key features (v1.4.0+):
 *   - Machine-level encryption (any user/process on same machine can decrypt)
 *   - No manual key management required
 *   - Integrates with Windows security infrastructure
 *   - Supports optional entropy for additional security
 *   - Enables autostart scenarios (SYSTEM account can decrypt)
 *   - Data remains machine-bound (cannot be decrypted on different computers)
 */

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <windows.h>

/*
 * EncryptData - Encrypt data using Windows DPAPI
 * 
 * This function encrypts plaintext data using CryptProtectData. The encrypted
 * data can only be decrypted by the same Windows user on the same machine.
 * 
 * Parameters:
 *   plaintext       - Pointer to data to encrypt
 *   plaintextSize   - Size of plaintext data in bytes
 *   ciphertext      - Pointer to receive encrypted data (caller must free with LocalFree)
 *   ciphertextSize  - Pointer to receive size of encrypted data
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 * 
 * Memory Management:
 *   The caller is responsible for freeing the ciphertext buffer using LocalFree()
 * 
 * Example:
 *   BYTE* encrypted = NULL;
 *   DWORD encryptedSize = 0;
 *   if (EncryptData(data, dataSize, &encrypted, &encryptedSize)) {
 *       // Use encrypted data...
 *       LocalFree(encrypted);
 *   }
 */
BOOL EncryptData(const BYTE* plaintext, DWORD plaintextSize,
                 BYTE** ciphertext, DWORD* ciphertextSize);

/*
 * DecryptData - Decrypt data using Windows DPAPI
 * 
 * This function decrypts data that was encrypted with CryptProtectData.
 * It can only decrypt data that was encrypted by the same Windows user.
 * 
 * Parameters:
 *   ciphertext      - Pointer to encrypted data
 *   ciphertextSize  - Size of encrypted data in bytes
 *   plaintext       - Pointer to receive decrypted data (caller must free with LocalFree)
 *   plaintextSize   - Pointer to receive size of decrypted data
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 * 
 * Memory Management:
 *   The caller is responsible for freeing the plaintext buffer using LocalFree()
 * 
 * Example:
 *   BYTE* decrypted = NULL;
 *   DWORD decryptedSize = 0;
 *   if (DecryptData(encrypted, encryptedSize, &decrypted, &decryptedSize)) {
 *       // Use decrypted data...
 *       LocalFree(decrypted);
 *   }
 */
BOOL DecryptData(const BYTE* ciphertext, DWORD ciphertextSize,
                 BYTE** plaintext, DWORD* plaintextSize);

#endif // ENCRYPTION_H

