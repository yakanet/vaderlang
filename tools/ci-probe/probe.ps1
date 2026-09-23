# tools/ci-probe/probe.ps1 — time the bricks of a compiler build, the same way on
# every runner, so the Windows and Linux jobs can be compared brick by brick.
#
# Runs after `bootstrap/build.sh` / `build.ps1` and reuses what they left: the
# compiler (`build/vader`) and stage1's C (`build/work/stage1/*.c`). Every brick
# is timed alone, one after the other, so no two compete for the cores. Prints a
# table and appends it to $GITHUB_STEP_SUMMARY when that is set.
#
# Temporary: wired into the test jobs by .github/workflows/build.yml while the
# Windows/Linux ratio is being explained.
$ErrorActionPreference = 'Stop'
Set-Location (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))

$exe    = if ($IsWindows) { '.exe' } else { '' }
$vader  = Join-Path 'build' "vader$exe"
$cc     = if ($env:CC) { $env:CC } else { 'gcc' }
$tmp    = Join-Path ([IO.Path]::GetTempPath()) 'vader-ci-probe'
Remove-Item -Recurse -Force $tmp -ErrorAction SilentlyContinue
New-Item -ItemType Directory -Force $tmp | Out-Null

$rows = [System.Collections.Generic.List[string]]::new()
function Row([string]$what, [string]$value) { $rows.Add("| $what | $value |") }

# Seconds taken by `$block`. A native command that fails throws, so a broken
# brick shows as an error row instead of a fast, meaningless time.
function Seconds([scriptblock]$block) {
    $sw = [Diagnostics.Stopwatch]::StartNew()
    & $block
    $sw.Stop()
    return $sw.Elapsed.TotalSeconds
}
function Run([string]$file, [string[]]$argv) {
    $out = & $file @argv 2>&1
    if ($LASTEXITCODE -ne 0) {
        $tail = ($out | Select-Object -Last 3) -join ' / '
        throw "$file exited ${LASTEXITCODE}: $tail"
    }
}
function Brick([string]$what, [scriptblock]$block) {
    try { Row $what ("{0:N2} s" -f (Seconds $block)) }
    catch { Row $what "error: $($_.Exception.Message)" }
}

# ---- the machine ----------------------------------------------------------

$cpu = if ($IsWindows) {
    $name = (Get-CimInstance Win32_Processor | Select-Object -First 1).Name
    if ($name) { $name } else { $env:PROCESSOR_IDENTIFIER }
} elseif ($IsLinux) {
    ((Get-Content /proc/cpuinfo | Select-String '^model name' | Select-Object -First 1) -split ':', 2)[1].Trim()
} else {
    (& sysctl -n machdep.cpu.brand_string)
}
Row 'os' ([Runtime.InteropServices.RuntimeInformation]::OSDescription)
Row 'cpu' "$cpu, $([Environment]::ProcessorCount) logical"
Row 'cc' ((& $cc --version | Select-Object -First 1) -join '')
if ($IsWindows) {
    try { Row 'defender real-time' ((Get-MpComputerStatus).RealTimeProtectionEnabled) }
    catch { Row 'defender real-time' 'n/a' }
}

# ---- process creation -----------------------------------------------------

# The compiler driver alone: `gcc -c` is several processes (cc1, as), and the
# test suite spawns `vader` and `cc` thousands of times.
$n = 50
Row "spawn: ``$cc --version`` (per call)" ("{0:N1} ms" -f ((Seconds { 1..$n | ForEach-Object { Run $cc @('--version') } }) * 1000 / $n))
Row 'spawn: `vader --version` (per call)' ("{0:N1} ms" -f ((Seconds { 1..$n | ForEach-Object { Run $vader @('--version') } }) * 1000 / $n))
$empty = Join-Path $tmp 'empty.c'
Set-Content -Path $empty -Value ''
# `-###` prints each command the driver would run, one per line, quoted.
$sub = @(& $cc '-###' -c $empty -o (Join-Path $tmp 'empty.o') 2>&1 | Where-Object { "$_" -match '^ "' }).Count
Row "processes behind one ``$cc -c``" "$sub"

# ---- file system ----------------------------------------------------------

$files = Join-Path $tmp 'files'
New-Item -ItemType Directory -Force $files | Out-Null
$blob = [byte[]]::new(4096)
Brick 'fs: write + read + delete 2000 files of 4 KB' {
    for ($i = 0; $i -lt 2000; $i++) { [IO.File]::WriteAllBytes((Join-Path $files "$i.bin"), $blob) }
    for ($i = 0; $i -lt 2000; $i++) { $null = [IO.File]::ReadAllBytes((Join-Path $files "$i.bin")) }
    Remove-Item -Recurse -Force $files
}

# ---- one translation unit, one core ---------------------------------------

$units = @(Get-ChildItem 'build/work/stage1' -Filter '*.c' | Sort-Object Length -Descending)
if ($units.Count -gt 0) {
    $unit = $units[0]
    Row 'largest stage1 unit' ("{0} ({1:N1} MB, {2} units in all)" -f $unit.Name, ($unit.Length / 1MB), $units.Count)
    $obj = Join-Path $tmp 'unit.o'
    $base = @('-std=c11', '-DNDEBUG', '-Iruntime/c', '-c', $unit.FullName, '-o', $obj)
    Brick 'cc -O1, largest unit'               { Run $cc (@('-O1') + $base) }
    Brick 'cc -O3, largest unit'               { Run $cc (@('-O3') + $base) }
    Brick 'cc -O3 -flto=auto, largest unit'    { Run $cc (@('-O3', '-flto=auto') + $base) }
} else {
    Row 'largest stage1 unit' 'none under build/work/stage1'
}

# ---- the compiler building itself -----------------------------------------

$entry = 'vader/cli/main.vader'
# `--out` names a prefix; its directory has to exist.
New-Item -ItemType Directory -Force (Join-Path $tmp 'c'), (Join-Path $tmp 'exe') | Out-Null
Brick 'front end: `vader build --release --emit=c` (1 thread)' {
    Run $vader @('build', '--release', '--emit=c', "--out=$(Join-Path $tmp 'c/vader')", $entry)
}
Brick 'whole: `vader build --release --emit=executable`' {
    Run $vader @('build', '--release', '--emit=executable', "--cc=$cc", "--out=$(Join-Path $tmp 'exe/vader')", $entry)
}

# ---- report ---------------------------------------------------------------

$table = @('| brick | measure |', '|---|---|') + $rows
$title = "### CI probe — $([Runtime.InteropServices.RuntimeInformation]::OSDescription)"
$table | ForEach-Object { Write-Host $_ }
if ($env:GITHUB_STEP_SUMMARY) {
    (@($title, '') + $table + '') | Out-File -FilePath $env:GITHUB_STEP_SUMMARY -Append -Encoding utf8
}
Remove-Item -Recurse -Force $tmp -ErrorAction SilentlyContinue
