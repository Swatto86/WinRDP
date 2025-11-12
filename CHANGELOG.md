# WinRDP Changelog

All notable changes to WinRDP will be documented in this file.

## [1.4.0] - 2025-11-08

### Fixed
- **Critical Encryption Bug** - Fixed DPAPI encryption to work with SYSTEM account for autostart scenarios
  - Changed from user-specific encryption to machine-level encryption
  - Uses `CRYPTPROTECT_LOCAL_MACHINE` flag for both encryption and decryption
  - Allows application to run under SYSTEM account (autostart, services)
  - Data encrypted by any user/process can now be decrypted by any user/process on same machine
  - Still maintains machine-bound security - encrypted data only decryptable on same computer
  - Fixes issue where CSV file couldn't be read when launched by Windows Task Scheduler or as service
  - **Important**: Files encrypted with v1.3.0 need to be re-encrypted (open and save) to work with autostart
- **Empty Example Hosts** - Fixed example hosts.csv showing no servers on first launch
  - Added 3 example server entries to hosts.csv
  - Users now see example servers immediately after installation
  - Examples can be modified or deleted through the application UI

### Security Note
- Machine-level encryption is less secure than user-specific encryption, but necessary for:
  - Applications that auto-start with Windows (run by SYSTEM account)
  - Services running under SYSTEM or other service accounts
  - Scenarios where multiple users need access to same encrypted data
- Data remains encrypted at rest and machine-bound (cannot be decrypted on different computers)
- Application-specific entropy still provides additional security layer

### Changed
- Updated encryption module documentation to reflect machine-level encryption
- Modified `CryptProtectData` to use `CRYPTPROTECT_LOCAL_MACHINE` flag
- Modified `CryptUnprotectData` to use `CRYPTPROTECT_LOCAL_MACHINE` flag
- Updated all encryption-related comments and documentation

---

## [1.3.0] - 2025-11-08

### Added
- **CSV File Encryption** - Host data is now encrypted using Windows DPAPI
  - Automatic encryption of hosts.csv file on save
  - Transparent decryption on load
  - User-specific encryption - only the Windows user who created the file can decrypt it (changed to machine-level in v1.4.0)
  - No manual key management required
  - Backward compatible - can still read unencrypted files from previous versions
  - File format includes magic number and version for future extensibility
  - Uses Windows Data Protection API (DPAPI) for secure, OS-integrated encryption

### Changed
- Hosts CSV file is now stored in encrypted format by default
- Updated application version to 1.3.0
- Added crypt32.lib dependency for encryption support

### Technical Details
- New encryption module (encryption.c/encryption.h) using CryptProtectData/CryptUnprotectData
- Modified LoadHosts() to detect and decrypt encrypted files
- Modified SaveHosts() to encrypt data before writing
- Encrypted file format: [MAGIC][VERSION][ENCRYPTED_DATA]
- Application-specific entropy for additional security layer

## [1.5.0] - 2025-11-12

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

- **Delete Host with Del Key and Context Menu** - Multiple convenient ways to delete hosts
  - Press Delete key on selected host in any ListView to remove it
  - Right-click on host to show context menu with Delete option
  - Works in both Connect to Host screen and Manage Hosts screen
  - Confirmation dialog prevents accidental deletions
  - Context menu also provides quick access to Connect/Edit actions
  - Follows standard Windows UI conventions for consistency
  - List automatically refreshes after deletion while preserving search filters

- **Visual Feedback on Connection** - Clear indication when launching RDP
  - Wait cursor (hourglass) appears during connection
  - Window title briefly shows "Launching connection to [hostname]..."
  - 100ms delay ensures user sees the feedback
  - Applies to all connection methods: button click, double-click, Enter key, context menu
  - System tray recent connections continue to launch directly for quick access
  - Professional user experience with clear action confirmation

- **Highlight Search Results** - Precise visual indication of matching text in ListView
  - Only the matching characters are highlighted (not the entire row)
  - Yellow background (RGB 255, 255, 150) with black text for perfect contrast
  - Highlights both hostname and description columns
  - Text remains properly centered in columns during highlighting
  - Case-insensitive matching for better usability
  - Respects selection state (blue highlight preserved when selected)
  - Uses custom draw (NM_CUSTOMDRAW) with manual text rendering
  - Automatically updates as you type in search box
  - Works in both main server list and host management dialogs
  - Works perfectly in both dark and light modes
  - Makes it immediately clear which characters matched your search

- **Auto-resize Description Column** - Dynamic column width adjustment
  - Description column automatically resizes when window is resized
  - Always fills available space between fixed-width columns
  - Hostname column fixed at 170px, Last Connected at 160px
  - Description gets remaining space (minimum 100px)
  - Smooth resizing as you drag window edges
  - Better use of screen real estate on large monitors
  - Responsive design that works at any window size
  
### Upcoming Features (Planned)

The following UX improvements are planned for future releases:

1. **Import/Export Functionality** - Backup and share host configurations
   - Menu options to import/export hosts.csv
   - Choose custom file location for backup
   - Easy migration between systems
   - Support for JSON and XML formats
   - Selective export (export filtered results only)

2. **Host Grouping/Folders** - Organize servers by category
   - Create folders like "Production", "Development", "Test"
   - Expandable/collapsible tree view in ListView
   - Drag and drop hosts between folders
   - Filter by folder in search
   - Backup folder structure in CSV

3. **Connection History Log** - Detailed tracking of all connection attempts
   - Full history beyond just "Last Connected"
   - Log file with timestamps and connection duration
   - View history dialog with filtering and search
   - Track successful and failed connections
   - Export history for auditing purposes

4. **Advanced RDP Settings Per Host** - Customize connection parameters
   - Screen resolution options (fullscreen, windowed, custom)
   - Color depth settings (15-bit, 16-bit, 24-bit, 32-bit)
   - Multi-monitor configuration (single, all monitors, specific monitors)
   - Audio redirection settings (local, remote, none)
   - Clipboard redirection toggle
   - Printer redirection options
   - Drive mapping configuration
   - RemoteApp support
   - Gateway server settings
   - Store settings in enhanced CSV format

5. **Host Online Status** - Check if servers are reachable before connecting
   - Ping check with visual indicator (green/red/yellow dots)
   - Port 3389 availability check
   - Background status checking with configurable interval
   - Manual refresh button
   - Sort by online/offline status
   - Skip ping for specific hosts (firewall scenarios)

6. **Quick Actions and Shortcuts** - Faster workflow operations
   - Copy hostname/IP to clipboard (Ctrl+C)
   - Copy credentials to clipboard with timeout
   - Pin favorite hosts to top of list
   - Star/favorite system with quick filter
   - Recent hosts counter configuration (currently fixed at 5)

7. **Connection Profiles** - Reusable RDP setting templates
   - Create named profiles (e.g., "High Quality", "Low Bandwidth")
   - Apply profile to multiple hosts at once
   - Default profile selection
   - Profile management dialog

8. **Bulk Operations** - Edit multiple hosts simultaneously
   - Multi-select in ListView (Ctrl+Click, Shift+Click)
   - Bulk credential update
   - Bulk folder assignment
   - Bulk delete with confirmation

9. **Smart Reconnect Features** - Handle connection failures gracefully
   - Configurable connection timeout
   - Auto-retry on connection failure
   - Connection error logging
   - Remember last failed connection for diagnostics

10. **Tags and Metadata** - Additional organization options
    - Add multiple tags per host (comma-separated)
    - Filter by tags
    - Tag-based color coding in ListView
    - Custom fields (OS version, owner, purpose, etc.)

11. **Connection Statistics** - Usage analytics and insights
    - Total connections per host
    - Connection duration tracking
    - Most frequently used hosts
    - Statistics dashboard
    - Generate usage reports

12. **Session Management** - Handle active RDP sessions
    - Detect and display active RDP sessions
    - Disconnect/logoff remote sessions
    - Shadow other user sessions (admin feature)
    - Session timeout warnings

13. **Configuration Options** - User preferences and settings
    - Settings dialog for application preferences
    - Configurable hotkey combinations
    - Auto-refresh interval for status checks
    - Startup behavior options
    - UI font and size preferences
    - Default RDP options

14. **Network Discovery Enhancements** - Better scanning capabilities
    - Scan specific IP ranges (CIDR notation)
    - Scheduled automatic scans
    - Detect changes in network (new/removed computers)
    - Remember last scan parameters
    - Exclude specific hosts from scan results

15. **Backup and Sync** - Cloud backup and multi-PC synchronization
    - Automatic backup scheduling
    - OneDrive/Dropbox integration
    - Sync hosts across multiple computers
    - Conflict resolution for concurrent edits
    - Version history for configuration

16. **Security Enhancements** - Additional protection features
    - Master password for application access
    - Inactivity timeout with auto-lock
    - Credential expiration reminders
    - Two-factor authentication support
    - Audit log for security events
    - Encrypted clipboard for credential copying

17. **Command-Line Interface** - Automation and scripting support
    - Launch specific hosts from command line
    - Import/export via command line
    - Headless connection mode
    - Script-friendly output formats
    - Integration with PowerShell scripts

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

**WinRDP - Directed by Swatto • Built with AI**  
Educational Windows API Programming Project

