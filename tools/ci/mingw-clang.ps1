# tools/ci/mingw-clang.ps1 — point the Windows runner's own LLVM at MinGW, and
# export it as `CC` for every later step of the job.
#
# The image ships LLVM (MSVC-targeting by default) and a MinGW-Builds gcc at
# C:\mingw64. A copy of clang named `x86_64-w64-mingw32-clang.exe` targets MinGW
# by its name, and the `.cfg` beside it — which clang reads on its own — points
# it at the MinGW sysroot, at lld (ThinLTO needs it), and back at the resource
# directory the copy no longer sits next to. The `.cfg` is named after the
# NORMALISED triple, `x86_64-w64-windows-gnu`: that is the name clang looks up,
# not the executable's prefix. Nothing is downloaded.
#
# `bootstrap/build.ps1`, `vader build` and the test suite all read `CC`.
$ErrorActionPreference = 'Stop'

$clang = (Get-Command clang -ErrorAction SilentlyContinue).Source
if (-not $clang) { $clang = 'C:\Program Files\LLVM\bin\clang.exe' }
if (-not (Test-Path $clang)) { throw "no clang on PATH nor at $clang" }

# The sysroot is the MinGW gcc's: its headers, CRT and import libraries.
$triple = (& gcc -dumpmachine).Trim()
if ($triple -ne 'x86_64-w64-mingw32') { throw "gcc targets '$triple', not x86_64-w64-mingw32" }
$sysroot = (Split-Path -Parent (Split-Path -Parent (Get-Command gcc).Source)) -replace '\\', '/'
if (-not (Test-Path "$sysroot/$triple/include")) { throw "no MinGW headers under $sysroot/$triple" }

$resource = (& $clang -print-resource-dir).Trim() -replace '\\', '/'
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
    "-resource-dir=`"$resource`""
) | Set-Content -Path (Join-Path $shim 'x86_64-w64-windows-gnu-clang.cfg') -Encoding ascii

& $cc --version
# A hello world first: a toolchain that cannot link a trivial program would fail
# the build for a reason that has nothing to do with Vader.
$hello = Join-Path $shim 'hello.c'
Set-Content -Path $hello -Value '#include <stdio.h>
int main(void) { puts("hello from mingw clang"); return 0; }'
& $cc -O2 $hello -o (Join-Path $shim 'hello.exe')
if ($LASTEXITCODE -ne 0) { throw "hello.c did not build (exit $LASTEXITCODE)" }
& (Join-Path $shim 'hello.exe')
if ($LASTEXITCODE -ne 0) { throw "hello.exe exited $LASTEXITCODE" }

if ($env:GITHUB_ENV) { "CC=$cc" | Out-File -FilePath $env:GITHUB_ENV -Append -Encoding utf8 }
