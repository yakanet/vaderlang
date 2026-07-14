#!/usr/bin/env pwsh
# Build the full Vader compiler from the committed C seed -- a 3-stage bootstrap:
#   seed   -cc->            build\stage0.exe   (bootstrap compiler; emits C only)
#   stage0 -emit C-> cc->   build\stage1.exe   (intermediate full compiler)
#   stage1 -build native->  build\vader.exe    (= stage2, the shipped compiler)
#
# Needs a mingw-w64 C compiler (gcc or clang) on PATH -- MSVC is NOT supported
# (the runtime uses __attribute__((weak))). gzip is NOT required: the seed is
# decompressed through .NET's GZipStream. The compiler defaults to gcc; override
# with `-CC clang` or $env:CC. It is resolved to an absolute path and passed to
# stage1 via --cc. stage0 & stage1 are throwaways built -O0 ($env:STAGE0_CFLAGS);
# only stage2/vader is built -O3 (via stage1's --release). Pass -Dist to also
# assemble a self-contained dist\vader-windows-<arch>\ bundle. See docs/BOOTSTRAP.md.
[CmdletBinding()]
param([string]$CC = $(if ($env:CC) { $env:CC } else { 'gcc' }), [switch]$Dist)

$ErrorActionPreference = 'Stop'
Set-Location (Split-Path -Parent $PSScriptRoot)
# Set-Location only updates $PWD ; .NET file APIs (OpenRead/Create below) resolve
# relative paths against [Environment]::CurrentDirectory, which Set-Location never
# touches. Sync it so the seed decompression and the cc/stage child processes all
# resolve relative paths against the repo root.
[Environment]::CurrentDirectory = $PWD.Path

$ccCmd = Get-Command $CC -ErrorAction SilentlyContinue
if ($null -eq $ccCmd) { throw "C compiler '$CC' not found on PATH (use -CC ...)" }
$ccAbs = $ccCmd.Source
$stage0cflags = if ($env:STAGE0_CFLAGS) { $env:STAGE0_CFLAGS } else { '-O0' }
$runtime = "runtime\c\vader_runtime.c"

# Arena sizing is RAM-proportional (runtime\c\vader_runtime.c::vader_gc_init --
# old init + cap derived from physical RAM, single VADER_GC_RAM_PERCENT knob), so
# the bootstrap self-compiles at a saner initial size on any machine with no manual
# override. This used to pin VADER_GC_YOUNG_BYTES / VADER_GC_OLD_BYTES to avoid the
# default-256-MB-old GC thrash; the RAM model + auto-grow now handle that. Any
# VADER_GC_* value the caller exports still wins (advanced escape hatch).

function Step($msg) { Write-Host "==> $msg" -ForegroundColor Cyan }
New-Item -ItemType Directory -Force build | Out-Null

Step "[1/3] Building stage0 (bootstrap compiler, from the seed)  [$ccAbs $stage0cflags]"
$in  = [IO.File]::OpenRead("bootstrap\bootstrap.c.gz")
$gz  = [IO.Compression.GZipStream]::new($in, [IO.Compression.CompressionMode]::Decompress)
$out = [IO.File]::Create("build\bootstrap.c")
try { $gz.CopyTo($out) } finally { $out.Close(); $gz.Close(); $in.Close() }
& $ccAbs $stage0cflags -o build\stage0.exe build\bootstrap.c $runtime -Iruntime\c -lm
if ($LASTEXITCODE -ne 0) { throw "stage0 compilation failed (exit $LASTEXITCODE)" }

Step "[2/3] Building stage1 (full compiler, via stage0)  -- self-compiles"
& .\build\stage0.exe vader\cli\main.vader build\stage1.c
if ($LASTEXITCODE -ne 0) { throw "stage0 failed to emit stage1.c (exit $LASTEXITCODE)" }
& $ccAbs $stage0cflags -o build\stage1.exe build\stage1.c $runtime -Iruntime\c -lm
if ($LASTEXITCODE -ne 0) { throw "stage1 compilation failed (exit $LASTEXITCODE)" }

Step "[3/3] Building vader = stage2 (via stage1, --release)"
& .\build\stage1.exe build vader\cli\main.vader --release --target=native --out=build\vader --cc=$ccAbs
if ($LASTEXITCODE -ne 0) { throw "stage1 failed to build vader (exit $LASTEXITCODE)" }

Write-Host "==> done  vader built at build\vader.exe" -ForegroundColor Green
& .\build\vader.exe --version

if ($Dist) {
    $arch = if ($env:PROCESSOR_ARCHITECTURE -eq 'ARM64') { 'arm64' } else { 'x64' }
    $distDir = "dist\vader-windows-$arch"

    Step "[dist] Bundling $distDir  (vader + stdlib + runtime/c)"
    if (Test-Path $distDir) { Remove-Item -Recurse -Force $distDir }
    New-Item -ItemType Directory -Force "$distDir\runtime" | Out-Null
    Copy-Item build\vader.exe "$distDir\vader.exe"
    Copy-Item -Recurse stdlib "$distDir\stdlib"
    Copy-Item -Recurse runtime\c "$distDir\runtime\c"

    Write-Host "==> dist  $distDir ready -- a self-contained toolchain (resolves stdlib\ + runtime\c\ next to the binary, so it runs from any directory)." -ForegroundColor Green
}
