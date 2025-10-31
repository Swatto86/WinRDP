/*
 * Resource Identifiers
 * 
 * These constants identify UI elements (dialogs, buttons, menus, etc.)
 * They're used in both C code and resource (.rc) files.
 * 
 * Naming convention:
 *   IDD_ = Dialog ID
 *   IDC_ = Control ID (button, edit box, etc.)
 *   IDM_ = Menu item ID
 *   IDS_ = String resource ID
 *   IDI_ = Icon ID
 */

#ifndef RESOURCE_H
#define RESOURCE_H

// Dialog IDs
#define IDD_LOGIN               100
#define IDD_MAIN                101
#define IDD_HOSTS               102
#define IDD_ADD_HOST            103
#define IDD_SCAN_RESULTS        104
#define IDD_SCAN_DOMAIN         105

// Control IDs - Login Dialog
#define IDC_EDIT_USERNAME       200
#define IDC_EDIT_PASSWORD       201
#define IDC_BTN_SAVE_CREDS      202
#define IDC_BTN_DELETE_CREDS    203
#define IDC_STATIC_STATUS       204
#define IDC_STATIC              -1

// Control IDs - Main Dialog
#define IDC_LIST_SERVERS        210
#define IDC_EDIT_SEARCH         211
#define IDC_BTN_CONNECT         212
#define IDC_BTN_MANAGE          213

// Control IDs - Host Management Dialog
#define IDC_LIST_HOSTS          220
#define IDC_BTN_ADD_HOST        221
#define IDC_BTN_EDIT_HOST       222
#define IDC_BTN_DELETE_HOST     223
#define IDC_BTN_SCAN_DOMAIN     224
#define IDC_EDIT_SEARCH_HOSTS   225

// Control IDs - Add/Edit Host Dialog
#define IDC_EDIT_HOSTNAME       230
#define IDC_EDIT_DESCRIPTION    231
#define IDC_CHECK_USE_HOST_CREDS 232
#define IDC_EDIT_HOST_USERNAME  233
#define IDC_EDIT_HOST_PASSWORD   234
#define IDC_STATIC_HOST_USERNAME 235
#define IDC_STATIC_HOST_PASSWORD 236

// Control IDs - Scan Results Dialog
#define IDC_LIST_SCAN_RESULTS   240
#define IDC_BTN_ADD_SELECTED    241
#define IDC_STATIC_SCAN_STATUS  242

// Control IDs - Scan Domain Dialog
#define IDC_EDIT_DOMAIN         250
#define IDC_CHECK_WORKSTATIONS  254
#define IDC_CHECK_SERVERS       255
#define IDC_CHECK_DOMAIN_CTRL   256

// Menu IDs
#define IDM_OPEN                300
#define IDM_EXIT                301
#define IDM_ABOUT               302
#define IDM_DELETE_ALL          303

// System Tray
#define ID_TRAYICON             400
#define WM_TRAYICON             (WM_USER + 1)

// Icons
#define IDI_MAINICON            500

// Accelerator Tables
#define IDM_HOSTS_ACCEL         600

#endif // RESOURCE_H

