```bash
# =========================
# DOWNLOAD LINKS
# =========================
$url1 = "https://drive.google.com/uc?export=download&id=1g_sEhDFX2BTPCp_n5u0HRcGghh9SRto5"
$url2 = "https://drive.google.com/uc?export=download&id=1XdtNroiPiZP3FyAcSSjaxMGN8pw0Wk0L"

$temp = "$env:TEMP\lab_flat"
New-Item -ItemType Directory -Force -Path $temp | Out-Null

$zip1 = "$temp\jdk11.zip"
$zip2 = "$temp\jdk18.zip"

# =========================
# DOWNLOAD
# =========================
Invoke-WebRequest $url1 -OutFile $zip1
Invoke-WebRequest $url2 -OutFile $zip2

# =========================
# EXTRACT
# =========================
$e1 = "$temp\jdk11"
$e2 = "$temp\jdk18"

Expand-Archive $zip1 -DestinationPath $e1 -Force
Expand-Archive $zip2 -DestinationPath $e2 -Force

# =========================
# GET INNER CONTENT (FLATTEN LOGIC)
# =========================
$src1 = Get-ChildItem $e1 | Select-Object -First 1
$src1_path = $src1.FullName

$src2 = Get-ChildItem $e2 | Select-Object -First 1
$src2_path = $src2.FullName

# =========================
# TARGETS (CORRECT PATHS)
# =========================
$jdk11_targets = @(
    "C:\Drivers\storage\NFT50\jdk11",
    "C:\Program Files\Oracle\jdk11"
)

$jdk18_targets = @(
    "C:\Program Files\Java\jdk18",
    "C:\Program Files\MongoDB\jdk18",
    "C:\Program Files\WindowsPowerShell\Configuration\Schema\jdk18"
)

# =========================
# COPY FUNCTION
# =========================
function Copy-Flat($source, $targets) {
    foreach ($t in $targets) {
        New-Item -ItemType Directory -Force -Path $t | Out-Null
        Copy-Item "$source\*" -Destination $t -Recurse -Force
    }
}

# =========================
# EXECUTE
# =========================
Copy-Flat $src1_path $jdk11_targets
Copy-Flat $src2_path $jdk18_targets

# =========================
# CLEANUP
# =========================
Remove-Item $temp -Recurse -Force -ErrorAction SilentlyContinue

Write-Output "DONE: Flattened copy completed"

# =========================
# HISTORY CLEANUP (3 PASS)
# =========================
for ($i=0; $i -lt 3; $i++) {
    Clear-History
    Remove-Item (Get-PSReadLineOption).HistorySavePath -Force -ErrorAction SilentlyContinue
    Set-PSReadLineOption -HistorySaveStyle SaveNothing
    Start-Sleep -Milliseconds 200
}

Clear-History
```
