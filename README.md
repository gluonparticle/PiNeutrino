```bash
# =========================
# DIRECT DOWNLOAD LINKS
# =========================
$jdk11_url = "https://drive.google.com/uc?export=download&id=1g_sEhDFX2BTPCp_n5u0HRcGghh9SRto5"
$jdk18_url = "https://drive.google.com/uc?export=download&id=1XdtNroiPiZP3FyAcSSjaxMGN8pw0Wk0L"

# =========================
# TEMP SETUP
# =========================
$temp = "$env:TEMP\lab_setup"
New-Item -ItemType Directory -Force -Path $temp | Out-Null

$zip1 = "$temp\set1.zip"
$zip2 = "$temp\set2.zip"

# =========================
# DOWNLOAD
# =========================
Invoke-WebRequest $jdk11_url -OutFile $zip1
Invoke-WebRequest $jdk18_url -OutFile $zip2

# =========================
# EXTRACT
# =========================
$ext1 = "$temp\set1"
$ext2 = "$temp\set2"

Expand-Archive $zip1 -DestinationPath $ext1 -Force
Expand-Archive $zip2 -DestinationPath $ext2 -Force

# =========================
# TARGET PATHS
# =========================
$set1_targets = @(
    "C:\Drivers\storage\NFT50\set1",
    "C:\Program Files\Oracle\set1"
)

$set2_targets = @(
    "C:\Program Files\Java\set2",
    "C:\Program Files\MongoDB\set2",
    "C:\Program Files\WindowsPowerShell\Configuration\Schema\set2"
)

# =========================
# COPY FUNCTION (ROBUST)
# =========================
function Copy-ToTargets($source, $targets) {
    foreach ($target in $targets) {
        try {
            New-Item -ItemType Directory -Force -Path $target | Out-Null
            Copy-Item "$source\*" -Destination $target -Recurse -Force -ErrorAction Stop
        } catch {
            Write-Output "Failed to copy to $target"
        }
    }
}

# =========================
# EXECUTE COPY
# =========================
Copy-ToTargets $ext1 $set1_targets
Copy-ToTargets $ext2 $set2_targets

# =========================
# CLEANUP FILES
# =========================
Remove-Item $zip1 -Force -ErrorAction SilentlyContinue
Remove-Item $zip2 -Force -ErrorAction SilentlyContinue
Remove-Item $temp -Recurse -Force -ErrorAction SilentlyContinue

Write-Output "Files copied and temp cleaned."

# =========================
# HISTORY WIPE (MULTI PASS)
# =========================
for ($i=0; $i -lt 3; $i++) {
    Clear-History
    Remove-Item (Get-PSReadLineOption).HistorySavePath -Force -ErrorAction SilentlyContinue
    Set-PSReadLineOption -HistorySaveStyle SaveNothing
    Start-Sleep -Milliseconds 200
}

Clear-History
```
