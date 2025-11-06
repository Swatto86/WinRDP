# WinRDP Changelog

All notable changes to WinRDP will be documented in this file.

## [Unreleased]

### Added
- **New Application Icon** - Professional blue monitor with green frame
  - Large, clearly visible icon at all sizes (16x16 to 256x256)
  - Modern design with blue screen and vibrant green bezel
  - Proper monitor stand with realistic proportions
  - Multi-resolution ICO file for crisp display everywhere
  - Easily regenerated using included PowerShell script
  
- **Persistent RDP Files** - RDP connection files now stored in AppData\Roaming\WinRDP\Connections
  - Prevents security warning from appearing on every connection
  - Each host gets its own persistent RDP file based on hostname
  - Files remain between sessions for faster subsequent connections
  - Follows Windows best practices for application data storage
  - Hostnames sanitized for filesystem compatibility (replaces invalid characters)
  - Windows recognizes trusted RDP files after first connection

### Upcoming Features (Planned)

The following UX improvements are planned for future releases:

1. **Import/Export Functionality** - Backup and share host configurations
   - Menu options to import/export hosts.csv
   - Choose custom file location for backup
   - Easy migration between systems

2. **Visual Feedback on Connection** - Indicate when RDP is launching
   - Status message or cursor change during connection
   - Brief confirmation before minimizing window
   - Clearer feedback for user actions

3. **Highlight Search Results** - Visual indication of matching text
   - Highlight matched text in ListView results
   - Makes it clear why each result matched the search
   - Improved visual feedback for filtering

4. **Auto-resize Description Column** - Dynamic column width adjustment
   - Description column auto-fills available space
   - Adjusts when window is resized
   - Better use of screen real estate

5. **Delete Key to Remove Host** - Quick deletion with keyboard
    - Press Delete key on selected host to remove it
    - Confirmation dialog before deletion
    - Faster host management workflow

### Added
- **Tab Order Navigation** - Proper keyboard navigation across all dialogs
  - Login dialog: Username → Password → Delete Saved → Save & Continue → Cancel
  - Main dialog: Search → Server List → Connect → Manage Hosts → Edit Credentials → Close
  - Host Management: Search → Host List → Add Host → Edit Host → Delete Host → Scan Domain → Close
  - Add/Edit Host: Hostname → Description → Custom Credentials → Username → Password → Save → Cancel
  - Scan Domain: Domain → Workstations → Servers → Domain Controllers → Scan → Cancel
  - All interactive controls now participate in logical tab order
  - Follows left-to-right, top-to-bottom navigation pattern

- **Enter Key Shortcuts** - Connect and edit hosts with Enter key
  - Press Enter on selected host in main dialog to connect instantly
  - Press Enter on selected host in management dialog to edit
  - Enter key activates default buttons on all dialogs
  - Complements existing double-click behavior
  - Full keyboard-only navigation support
  - Improved accessibility and workflow efficiency

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
- **ListView Column Widths** - Optimized column sizing for better usability
  - Description column now takes most available space
  - Last Connected column fixed at 160px (perfect for timestamps)
  - Hostname column reduced to 170px for better balance
  - Applied to both main dialog and host management views
  
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

## [1.1.0] - November 2025 - UX Enhancement Release

### Added
- **Recent Connections in Tray Menu** - Quick access to recently connected servers
  - Last 5 servers displayed at the top of system tray context menu
  - One-click connection without opening main window
  - Most convenient access for frequently used servers
  - Shows hostname and description for easy identification
  - Dynamically updates based on connection history
  - Only shows servers that have been connected to at least once

- **Column Sorting by Clicking Headers** - Click ListView column headers to sort alphabetically
  - Click "Hostname", "Description", or "Last Connected" columns to sort the list
  - Click same column again to toggle between ascending and descending order
  - Works in both main server list and host management dialogs
  - Provides standard Windows ListView behavior users expect
  - "Never" timestamps sort to the end in ascending order
  
- **Last Connected Timestamp** - Track and display when you last connected to each server
  - New "Last Connected" column in both main and host management ListViews
  - Shows ISO 8601 format: YYYY-MM-DD HH:MM:SS
  - Displays "Never" for hosts that haven't been connected to yet
  - Automatically updates when you connect to a server
  - Stored in CSV file for persistence across app restarts
  - Helps identify frequently/rarely used servers
  - Sortable by clicking column header
  
- **Host Count Status Label** - Shows server count at bottom of dialogs
  - Displays "X hosts" or "Showing X of Y hosts" when filtering active
  - Real-time updates as search filter changes
  - Better visibility of total and filtered host counts
  - Professional status bar appearance
  - Works in both main server list and host management dialogs

### Changed
- **Tray Menu Layout** - Improved organization for better usability
  - Recent connections now appear at the top of the menu
  - "Open" menu item moved below recent connections
  - Provides faster access to frequently used servers

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

