# Icon Generator for WinRDP
# Creates an icon with two monitors and a connecting arrow using .NET System.Drawing

Add-Type -AssemblyName System.Drawing

function New-RDPIcon {
    param(
        [int]$Size
    )
    
    # Create bitmap with transparency
    $bitmap = New-Object System.Drawing.Bitmap($Size, $Size)
    $graphics = [System.Drawing.Graphics]::FromImage($bitmap)
    $graphics.SmoothingMode = [System.Drawing.Drawing2D.SmoothingMode]::AntiAlias
    
    # Colors - professional blue monitor
    $primaryBlue = [System.Drawing.Color]::FromArgb(0, 120, 215)      # Windows blue
    $greenBezel = [System.Drawing.Color]::FromArgb(16, 185, 129)      # Green for bezel/stand
    $lightBlue = [System.Drawing.Color]::FromArgb(80, 150, 200, 240)  # Highlight
    
    # Calculate dimensions - leave room for stand at bottom
    $margin = [Math]::Max(2, [Math]::Floor($Size / 20))
    $standTotalHeight = [Math]::Max(4, [Math]::Floor($Size / 6))
    
    # Screen dimensions (16:10 aspect ratio, typical monitor)
    $screenWidth = $Size - ($margin * 2)
    $screenHeight = [Math]::Floor(($Size - $standTotalHeight - $margin) * 0.85)
    $screenX = $margin
    $screenY = $margin
    
    # Bezel (frame around screen)
    $bezelWidth = [Math]::Max(2, [Math]::Floor($Size / 20))
    
    # Draw bezel (green frame)
    $bezelRect = New-Object System.Drawing.Rectangle($screenX, $screenY, $screenWidth, $screenHeight)
    $bezelBrush = New-Object System.Drawing.SolidBrush($greenBezel)
    $graphics.FillRectangle($bezelBrush, $bezelRect)
    
    # Draw screen (blue, inset from bezel)
    $innerScreenX = $screenX + $bezelWidth
    $innerScreenY = $screenY + $bezelWidth
    $innerScreenWidth = $screenWidth - ($bezelWidth * 2)
    $innerScreenHeight = $screenHeight - ($bezelWidth * 2)
    
    $innerScreenRect = New-Object System.Drawing.Rectangle(
        $innerScreenX, $innerScreenY, $innerScreenWidth, $innerScreenHeight)
    $screenBrush = New-Object System.Drawing.SolidBrush($primaryBlue)
    $graphics.FillRectangle($screenBrush, $innerScreenRect)
    
    # Add gloss highlight at top for modern look
    if ($Size -gt 20) {
        $highlightHeight = [Math]::Max(3, [Math]::Floor($innerScreenHeight / 2.5))
        $highlightBrush = New-Object System.Drawing.SolidBrush($lightBlue)
        $highlightRect = New-Object System.Drawing.Rectangle(
            ($innerScreenX + 2),
            ($innerScreenY + 2),
            ($innerScreenWidth - 4),
            $highlightHeight
        )
        $graphics.FillRectangle($highlightBrush, $highlightRect)
        $highlightBrush.Dispose()
    }
    
    # Draw monitor stand
    $standNeckWidth = [Math]::Max(3, [Math]::Floor($screenWidth / 8))
    $standNeckHeight = [Math]::Max(3, [Math]::Floor($standTotalHeight * 0.6))
    $standNeckX = $screenX + [Math]::Floor(($screenWidth - $standNeckWidth) / 2)
    $standNeckY = $screenY + $screenHeight
    
    # Stand neck (connects screen to base)
    $standBrush = New-Object System.Drawing.SolidBrush($greenBezel)
    $neckRect = New-Object System.Drawing.Rectangle(
        $standNeckX, $standNeckY, $standNeckWidth, $standNeckHeight)
    $graphics.FillRectangle($standBrush, $neckRect)
    
    # Stand base (wider oval/rectangle at bottom)
    $baseWidth = [Math]::Max(6, [Math]::Floor($screenWidth / 2.5))
    $baseHeight = [Math]::Max(2, [Math]::Floor($standTotalHeight * 0.4))
    $baseX = $screenX + [Math]::Floor(($screenWidth - $baseWidth) / 2)
    $baseY = $standNeckY + $standNeckHeight
    
    if ($Size -gt 24) {
        # Draw rounded rectangle for base (more modern look)
        $basePath = New-Object System.Drawing.Drawing2D.GraphicsPath
        $radius = [Math]::Min($baseHeight, [Math]::Floor($baseWidth / 8))
        $baseRect = New-Object System.Drawing.Rectangle($baseX, $baseY, $baseWidth, $baseHeight)
        
        # Create rounded rectangle path
        $basePath.AddArc($baseX, $baseY, $radius * 2, $radius * 2, 180, 90)
        $basePath.AddArc($baseX + $baseWidth - $radius * 2, $baseY, $radius * 2, $radius * 2, 270, 90)
        $basePath.AddArc($baseX + $baseWidth - $radius * 2, $baseY + $baseHeight - $radius * 2, $radius * 2, $radius * 2, 0, 90)
        $basePath.AddArc($baseX, $baseY + $baseHeight - $radius * 2, $radius * 2, $radius * 2, 90, 90)
        $basePath.CloseFigure()
        
        $graphics.FillPath($standBrush, $basePath)
        $basePath.Dispose()
    }
    else {
        # Simple rectangle for small icons
        $baseRect = New-Object System.Drawing.Rectangle($baseX, $baseY, $baseWidth, $baseHeight)
        $graphics.FillRectangle($standBrush, $baseRect)
    }
    
    # Cleanup
    $graphics.Dispose()
    $bezelBrush.Dispose()
    $screenBrush.Dispose()
    $standBrush.Dispose()
    
    return $bitmap
}

# Generate icon at multiple sizes
Write-Host "Generating WinRDP icon with two monitors and connecting arrow..." -ForegroundColor Cyan
Write-Host ""

$sizes = @(16, 32, 48, 64, 128, 256)
$images = @()

foreach ($size in $sizes) {
    Write-Host "  Creating ${size}x${size} icon..." -ForegroundColor Gray
    $images += New-RDPIcon -Size $size
}

# Save the largest as PNG preview for easy viewing
$previewPath = "src\app_icon_preview.png"
Write-Host ""
Write-Host "Saving preview PNG..." -ForegroundColor Gray
$images[-1].Save($previewPath, [System.Drawing.Imaging.ImageFormat]::Png)
Write-Host "  ✓ Preview saved: $previewPath" -ForegroundColor Green

# For ICO file, we need to use a different approach
# Save multiple bitmaps as an ICO file
$icoPath = "src\app.ico"
Write-Host ""
Write-Host "Creating multi-resolution ICO file..." -ForegroundColor Gray

# Create ICO file manually
$icoStream = [System.IO.File]::Create($icoPath)
$writer = New-Object System.IO.BinaryWriter($icoStream)

# ICO header
$writer.Write([UInt16]0)        # Reserved (must be 0)
$writer.Write([UInt16]1)        # Image type (1 = ICO)
$writer.Write([UInt16]$sizes.Count)  # Number of images

# Calculate image data offsets
$headerSize = 6 + ($sizes.Count * 16)
$offset = $headerSize
$imageData = @()

# Write directory entries and prepare image data
foreach ($size in $sizes) {
    $img = $images[$sizes.IndexOf($size)]
    
    # Convert to 32-bit ARGB PNG data
    $ms = New-Object System.IO.MemoryStream
    $img.Save($ms, [System.Drawing.Imaging.ImageFormat]::Png)
    $pngData = $ms.ToArray()
    $ms.Dispose()
    
    $imageData += $pngData
    
    # Directory entry
    $writer.Write([Byte]($size % 256))   # Width (0 means 256)
    $writer.Write([Byte]($size % 256))   # Height (0 means 256)
    $writer.Write([Byte]0)               # Color palette (0 = no palette)
    $writer.Write([Byte]0)               # Reserved
    $writer.Write([UInt16]1)             # Color planes
    $writer.Write([UInt16]32)            # Bits per pixel
    $writer.Write([UInt32]$pngData.Length)  # Image data size
    $writer.Write([UInt32]$offset)       # Image data offset
    
    $offset += $pngData.Length
}

# Write image data
foreach ($data in $imageData) {
    $writer.Write($data)
}

$writer.Close()
$icoStream.Close()

# Cleanup
foreach ($img in $images) {
    $img.Dispose()
}

Write-Host "  ✓ Icon created: $icoPath" -ForegroundColor Green
Write-Host ""
Write-Host "Icon generation complete!" -ForegroundColor Cyan
Write-Host "  Location: $icoPath" -ForegroundColor White
Write-Host "  Sizes: $($sizes -join ', ')" -ForegroundColor White
Write-Host "  Preview: $previewPath" -ForegroundColor White
Write-Host ""
Write-Host "Rebuild your application to use the new icon." -ForegroundColor Yellow
