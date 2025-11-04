# WinRDP Changelog

All notable changes to WinRDP will be documented in this file.

## [Unreleased]

### Added
- **Edit Global Credentials Button** - New button on main window to change global credentials
  - Allows users to update their default RDP credentials without restarting
  - Opens the credentials dialog directly from the server list
  - Convenient access for switching between different user accounts

### Changed
- **Hotkey Toggle Behavior** - Global hotkey (Ctrl+Shift+R) now toggles the server list window
  - Pressing the hotkey shows the window if it's not visible
  - Pressing the hotkey closes the window if it's currently visible
  - Provides quick access and dismissal with the same keyboard shortcut

### Improved
- **Consistent Textbox Heights** - All single-line textboxes now use uniform height (13 pixels)
  - Applied across all dialogs: Login, Main, Manage Hosts, Add/Edit Host, Scan Domain
  - Creates a more cohesive, professional appearance
  - Improved visual consistency throughout the application
- **Consistent Button Widths** - All main window buttons now have uniform width (100 pixels)
  - Professional appearance with evenly-sized buttons
  - Consistent 5-pixel spacing between buttons
- **Smart Countdown Timer** - Login dialog countdown only appears on application startup
  - When editing credentials via button, no countdown timer appears
  - Prevents rushed editing experience
  - Shows simple "✓ Credentials saved" message in edit mode

---

## [1.0.1] - December 2025 - Bug Fix Release

### Fixed
- **Critical Autostart Bug** - Fixed empty server list when application auto-starts with Windows
  - Server list now loads correctly regardless of current working directory
  - Changed from relative path (`hosts.csv`) to absolute path based on executable location
  - Uses `GetModuleFileNameW()` to ensure file is always found in executable directory
  - Fixes issue where autostart worked but server list appeared empty

### Added
- **Example hosts.csv** - Included sample server entries for first-time users
  - File is automatically installed with example entries
  - Users can modify or delete entries through the application UI

### Changed
- Updated file path handling to use absolute paths for hosts.csv
- Improved reliability for autostart scenarios

---

## [1.0.0] - December 2025 - Professional Release

### Added
- **Professional Installer** - NSIS installer with modern wizard interface
  - Proper 64-bit installation to correct Program Files directory
  - Start Menu shortcuts
  - Windows Add/Remove Programs integration
  - Complete uninstaller
  - Attribution to Swatto
- **About Dialog** - Professional information dialog
  - Shows application name, version, and author
  - Lists key features
  - Accessible from system tray context menu
  - Dark mode support
- **Build Scripts** - `build-installer.bat` for automated installer creation

### Changed
- Updated author attribution throughout source code to "Swatto"
- Professional branding in installer and About dialog

---

## [0.9.0] - December 2025 - Enhanced Features

### Added
- **Global Hotkey Support (Ctrl+Shift+R)** - Instantly open WinRDP from anywhere
- **Bulk Delete Feature (Ctrl+Shift+Alt+D)** - Secret hotkey for complete cleanup
- **Per-Host Credentials** - Individual credentials per server
- **Network Computer Discovery** - Auto-discover computers on network
- **Dark Mode Support** - Automatic Windows theme detection
- Enhanced documentation and learning resources

### Changed
- Improved UI modernization and vertical text centering
- Enhanced memory management documentation
- Updated code commentary and educational guides

---

## [0.1.0] - Initial Release

### Added
- Core RDP connection management
- Windows Credential Manager integration
- CSV-based host storage
- System tray integration
- Autostart functionality
- Search functionality
- ListView controls for host management
- Complete Windows API educational implementation

---

## Legend

- **Added** - New features
- **Changed** - Changes in existing functionality
- **Deprecated** - Soon-to-be removed features
- **Removed** - Removed features
- **Fixed** - Bug fixes
- **Security** - Security improvements

---

**WinRDP by Swatto**  
Educational Windows API Programming Project

