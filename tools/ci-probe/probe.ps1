# tools/ci-probe/probe.ps1 — where the Windows job spends its time beyond the
# C compiler: the Vader runtime's own start-up and memory, and the test suite
# file by file. Runs the same way on every runner so the two jobs compare.
#
#   probe.ps1 runtime   after the build: start-up under several GC sizes, and
#                       the per-pass VADER_PROFILE table of a self-compile
#   probe.ps1 tests     after the suite: the slowest files and tests, read from
#                       the JUnit report the Test step writes to build/junit.xml
#
# Prints markdown and appends it to $GITHUB_STEP_SUMMARY when that is set.
# Temporary: wired into the test jobs by .github/workflows/build.yml.
param([Parameter(Mandatory)][ValidateSet('runtime', 'tests')][string]$Mode)
$ErrorActionPreference = 'Stop'
Set-Location (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))

$exe   = if ($IsWindows) { '.exe' } else { '' }
$vader = Join-Path 'build' "vader$exe"
$os    = [Runtime.InteropServices.RuntimeInformation]::OSDescription
$out   = [System.Collections.Generic.List[string]]::new()

function Report {
    $out | ForEach-Object { Write-Host $_ }
    if ($env:GITHUB_STEP_SUMMARY) {
        $out | Out-File -FilePath $env:GITHUB_STEP_SUMMARY -Append -Encoding utf8
    }
}

# Milliseconds per `vader --version`, a command that does little beyond
# initialising the runtime, with `$vars` set for the duration.
function StartupMs([hashtable]$vars) {
    foreach ($k in $vars.Keys) { Set-Item "Env:$k" $vars[$k] }
    try {
        $n = 50
        $sw = [Diagnostics.Stopwatch]::StartNew()
        for ($i = 0; $i -lt $n; $i++) {
            & $vader --version *> $null
            if ($LASTEXITCODE -ne 0) { throw "vader --version exited $LASTEXITCODE" }
        }
        $sw.Stop()
        return "{0:N2} ms" -f ($sw.Elapsed.TotalMilliseconds / $n)
    } finally {
        foreach ($k in $vars.Keys) { Remove-Item "Env:$k" -ErrorAction SilentlyContinue }
    }
}

if ($Mode -eq 'runtime') {
    $out.Add("### Runtime probe — $os")
    $out.Add('')
    $out.Add("$([Environment]::ProcessorCount) logical processors")
    $out.Add('')
    # The default old-gen reservation is RAM-proportional (4 GB cap), and the
    # card table is allocated for all of it at start-up; `VADER_GC_RAM_PERCENT=1`
    # drops the reservation to its 256 MB floor. `VADER_GC_YOUNG_BYTES` sizes
    # the young semi-spaces (32 MB each by default).
    $out.Add('| `vader --version` start-up | per call |')
    $out.Add('|---|---|')
    $out.Add("| default | $(StartupMs @{}) |")
    $out.Add("| ``VADER_GC_RAM_PERCENT=1`` (old reservation 256 MB) | $(StartupMs @{ VADER_GC_RAM_PERCENT = '1' }) |")
    $out.Add("| ``VADER_GC_YOUNG_BYTES=1048576`` (young 2 × 1 MB) | $(StartupMs @{ VADER_GC_YOUNG_BYTES = '1048576' }) |")
    $out.Add("| both | $(StartupMs @{ VADER_GC_RAM_PERCENT = '1'; VADER_GC_YOUNG_BYTES = '1048576' }) |")
    $out.Add('')

    $dir = Join-Path ([IO.Path]::GetTempPath()) 'vader-runtime-probe'
    Remove-Item -Recurse -Force $dir -ErrorAction SilentlyContinue
    New-Item -ItemType Directory -Force $dir | Out-Null
    $env:VADER_PROFILE = '1'
    try {
        $sw = [Diagnostics.Stopwatch]::StartNew()
        $lines = & $vader build --release --emit=c "--out=$(Join-Path $dir 'vader')" vader/cli/main.vader 2>&1
        $sw.Stop()
    } finally {
        Remove-Item Env:VADER_PROFILE -ErrorAction SilentlyContinue
    }
    $out.Add("Self-compile front end (``vader build --release --emit=c``), $('{0:N2}' -f $sw.Elapsed.TotalSeconds) s wall, ``VADER_PROFILE=1``:")
    $out.Add('')
    $out.Add('```')
    $table = @($lines | ForEach-Object { "$_" } | Where-Object { $_ -match '^\s+(PASS|TOTAL|[a-z-]+\s+[0-9.]+ms)|peak-RSS' })
    if ($table.Count -eq 0) { $table = @('(no VADER_PROFILE table in the output)') }
    $table | ForEach-Object { $out.Add($_) }
    $out.Add('```')
    $out.Add('')
    Remove-Item -Recurse -Force $dir -ErrorAction SilentlyContinue
    Report
    exit 0
}

# ---- tests ----------------------------------------------------------------

$junit = Join-Path 'build' 'junit.xml'
$out.Add("### Test timings — $os")
$out.Add('')
if (-not (Test-Path $junit)) {
    $out.Add("no $junit — the Test step did not write its report")
    Report
    exit 0
}
[xml]$doc = Get-Content -Raw $junit
$suites = @($doc.testsuites.testsuite)
$total = ($suites | Measure-Object -Property time -Sum).Sum
$out.Add("$($suites.Count) files, $('{0:N1}' -f $total) s summed over files (workers run in parallel, so this exceeds the step's wall time).")
$out.Add('')
$out.Add('| slowest files | s | tests |')
$out.Add('|---|---|---|')
$suites | Sort-Object { [double]$_.time } -Descending | Select-Object -First 15 | ForEach-Object {
    $out.Add("| $($_.name) | $('{0:N1}' -f [double]$_.time) | $($_.tests) |")
}
$out.Add('')
$out.Add('| slowest tests | s |')
$out.Add('|---|---|')
$cases = foreach ($s in $suites) { foreach ($c in @($s.testcase)) { if ($c) { $c } } }
$cases | Sort-Object { [double]$_.time } -Descending | Select-Object -First 15 | ForEach-Object {
    $name = "$($_.file) › $($_.name)" -replace '\|', '/'
    if ($name.Length -gt 110) { $name = $name.Substring(0, 110) + '…' }
    $out.Add("| $name | $('{0:N1}' -f [double]$_.time) |")
}
$out.Add('')
Report
