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
# Logical is what `-j` sees; physical is what compiles. SMT or a CPU quota makes
# the two diverge, and only the scaling brick below shows the effect.
$topology = if ($IsWindows) {
    $p = Get-CimInstance Win32_Processor
    "{0} physical cores, {1} logical" -f ($p | Measure-Object NumberOfCores -Sum).Sum, ($p | Measure-Object NumberOfLogicalProcessors -Sum).Sum
} elseif ($IsLinux) {
    (& lscpu | Select-String '^(Thread\(s\) per core|Core\(s\) per socket|Socket\(s\))' | ForEach-Object { "$_".Trim() -replace '\s+', ' ' }) -join '; '
} else { 'n/a' }
Row 'topology' $topology
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

    # The same -O1 compile, k copies at once. With k real cores free, the wall
    # time stays flat; it grows by k/cores once they run out. Each copy writes its
    # own object, so they share nothing but the machine.
    foreach ($k in 1, 2, 4) {
        Brick "cc -O1, largest unit, $k at once" {
            $procs = foreach ($j in 1..$k) {
                $argv = @('-O1', '-std=c11', '-DNDEBUG', '-Iruntime/c', '-c', $unit.FullName, '-o', (Join-Path $tmp "par$j.o"))
                Start-Process -FilePath $cc -ArgumentList (($argv | ForEach-Object { '"' + $_ + '"' }) -join ' ') -NoNewWindow -PassThru
            }
            foreach ($p in $procs) { $null = $p.Handle }
            $procs | Wait-Process
            foreach ($p in $procs) { if ($p.ExitCode -ne 0) { throw "$cc exited $($p.ExitCode)" } }
        }
    }
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

# ---- the LTO link alone ---------------------------------------------------

# Relink the objects the whole build just left, with the link line
# `vader/pipeline/emit.vader::lto_flags` uses for gcc. `-flto=auto` lets
# lto-wrapper pick the LTRANS parallelism (it drives the jobs through `make`);
# `-flto=1` forces them serial. Equal times mean the parallelism is not there.
$objs = @(Get-ChildItem (Join-Path $tmp 'exe') -Filter '*.o' | ForEach-Object { $_.FullName })
if ($objs.Count -gt 0) {
    Row 'objects linked' "$($objs.Count)"
    $linked = Join-Path $tmp "relinked$exe"
    $trace = Join-Path $tmp 'link-v.txt'
    Brick 'LTO link, -flto=auto -O3' {
        & $cc -v -flto=auto -O3 @objs -o $linked -lm *> $trace
        if ($LASTEXITCODE -ne 0) { throw "$cc link exited $LASTEXITCODE" }
    }
    $v = Get-Content $trace
    $ltrans = @($v | Where-Object { $_ -match 'ltrans' -and $_ -match 'cc1|lto1' }).Count
    $make = @($v | Where-Object { $_ -match '(^|[\\/ ])make(\.exe)?[ "]' -or $_ -match 'jobserver|serial' } | Select-Object -First 2)
    Row 'lto-wrapper: LTRANS compiler runs' "$ltrans"
    Row 'lto-wrapper: make / jobserver / serial lines' ($(if ($make) { ($make -join ' // ').Substring(0, [Math]::Min(300, ($make -join ' // ').Length)) } else { 'none' }))
    Brick 'LTO link, -flto=1 -O3 (serial)' { Run $cc (@('-flto=1', '-O3') + $objs + @('-o', $linked, '-lm')) }
} else {
    Row 'objects linked' 'none left by the whole build'
}

# ---- report ---------------------------------------------------------------

$table = @('| brick | measure |', '|---|---|') + $rows
$title = "### CI probe — $([Runtime.InteropServices.RuntimeInformation]::OSDescription)"
$table | ForEach-Object { Write-Host $_ }
if ($env:GITHUB_STEP_SUMMARY) {
    (@($title, '') + $table + '') | Out-File -FilePath $env:GITHUB_STEP_SUMMARY -Append -Encoding utf8
}
Remove-Item -Recurse -Force $tmp -ErrorAction SilentlyContinue
