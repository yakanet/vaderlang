# tools/ci-probe/clang.ps1 — can the runner image's own LLVM replace MinGW's gcc,
# and what does it cost?
#
# The image ships LLVM (MSVC-targeting by default) and a MinGW-Builds gcc at
# C:\mingw64. A copy of clang named `x86_64-w64-mingw32-clang.exe` targets MinGW
# by its name, and the `.cfg` beside it — which clang reads on its own — points
# it at the MinGW sysroot, at lld (ThinLTO needs it), and back at the resource
# directory the copy no longer sits next to. The `.cfg` is named after the
# NORMALISED triple, `x86_64-w64-windows-gnu`: that is the name clang looks up,
# not the executable's prefix. Nothing is downloaded.
#
# Rebuilds the compiler with `bootstrap/build.ps1 -CC <that clang>` on the same
# machine that built it with gcc earlier in the job, so the two times compare.
# Runs last: build.ps1 overwrites build\, which the tests have finished with.
# Temporary: wired into the Windows job by .github/workflows/build.yml.
$ErrorActionPreference = 'Stop'
Set-Location (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))

$out = [System.Collections.Generic.List[string]]::new()
function Report {
    $out | ForEach-Object { Write-Host $_ }
    if ($env:GITHUB_STEP_SUMMARY) {
        $out | Out-File -FilePath $env:GITHUB_STEP_SUMMARY -Append -Encoding utf8
    }
}
$out.Add('### Clang (image LLVM, MinGW target) build probe')
$out.Add('')

try {
    $clang = (Get-Command clang -ErrorAction SilentlyContinue).Source
    if (-not $clang) { $clang = 'C:\Program Files\LLVM\bin\clang.exe' }
    if (-not (Test-Path $clang)) { throw "no clang on PATH nor at $clang" }
    $sysroot = 'C:/mingw64'
    if (-not (Test-Path $sysroot)) { throw "no MinGW sysroot at $sysroot" }
    $resource = (& $clang -print-resource-dir).Trim()
    # The copy looks for lld beside itself, then on PATH; name it outright.
    $lld = Join-Path (Split-Path -Parent $clang) 'ld.lld.exe'
    if (-not (Test-Path $lld)) { throw "no ld.lld.exe beside $clang" }

    $shim = Join-Path $env:RUNNER_TEMP 'mingw-clang'
    New-Item -ItemType Directory -Force $shim | Out-Null
    $cc = Join-Path $shim 'x86_64-w64-mingw32-clang.exe'
    Copy-Item $clang $cc -Force
    @(
        "--sysroot=$sysroot",
        '-fuse-ld=lld',
        "--ld-path=`"$($lld -replace '\\', '/')`"",
        "-resource-dir=`"$($resource -replace '\\', '/')`""
    ) | Set-Content -Path (Join-Path $shim 'x86_64-w64-windows-gnu-clang.cfg') -Encoding ascii

    $out.Add("- clang: ``$((& $cc --version | Select-Object -First 1))``")
    $out.Add("- target: ``$((& $cc -print-target-triple).Trim())``")

    # A hello world first: if the toolchain cannot link a trivial program, the
    # build below would fail for a reason that has nothing to do with Vader.
    $hello = Join-Path $shim 'hello.c'
    Set-Content -Path $hello -Value '#include <stdio.h>
int main(void) { puts("hello from mingw clang"); return 0; }'
    & $cc -O2 $hello -o (Join-Path $shim 'hello.exe') 2>&1 | ForEach-Object { $out.Add("    $_") }
    if ($LASTEXITCODE -ne 0) { throw "hello.c did not build (exit $LASTEXITCODE)" }
    $out.Add("- hello world: ``$((& (Join-Path $shim 'hello.exe')).Trim())``")
    $out.Add('')

    $t0 = Get-Date
    $stages = [System.Collections.Generic.List[string]]::new()
    & pwsh -NoProfile -File bootstrap/build.ps1 -CC $cc *>&1 | ForEach-Object {
        $line = "$_"
        if ($line -match '==>|wrote|error|failed') {
            $stages.Add(("{0,7:N1} s  {1}" -f ((Get-Date) - $t0).TotalSeconds, $line))
        }
    }
    $total = ((Get-Date) - $t0).TotalSeconds
    $out.Add("``build.ps1 -CC <mingw clang>``: **$('{0:N1}' -f $total) s** (exit $LASTEXITCODE)")
    $out.Add('')
    $out.Add('```')
    $stages | ForEach-Object { $out.Add($_) }
    $out.Add('```')
    if (Test-Path 'build\vader.exe') {
        $out.Add("- ``build\vader.exe --version``: ``$((& .\build\vader.exe --version 2>&1 | Select-Object -First 1))``")
    }
} catch {
    $out.Add("probe failed: $($_.Exception.Message)")
}
$out.Add('')
Report
