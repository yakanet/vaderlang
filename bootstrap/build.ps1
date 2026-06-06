#!/usr/bin/env pwsh
# Build the full Vader compiler from the committed C seed, in one shot:
#   seed (bootstrap.c.gz) -> stage1 -> stage1 compiles main.vader -> build\vader.exe
#
# Needs a mingw-w64 C compiler (gcc or clang) on PATH — MSVC is NOT supported
# (the runtime uses __attribute__((weak))). gzip is NOT required: the seed is
# decompressed through .NET's GZipStream. The compiler defaults to gcc; override
# with `-CC clang` or by setting $env:CC. See docs/BOOTSTRAP.md.
[CmdletBinding()]
param([string]$CC = $(if ($env:CC) { $env:CC } else { 'gcc' }))

$ErrorActionPreference = 'Stop'
Set-Location (Split-Path -Parent $PSScriptRoot)

function Step($msg) { Write-Host "==> $msg" -ForegroundColor Cyan }
$runtime = "runtime\c\vader_runtime.c"
New-Item -ItemType Directory -Force build | Out-Null

Step "[1/4] Decompressing seed  bootstrap\bootstrap.c.gz -> build\bootstrap.c"
$in  = [IO.File]::OpenRead("bootstrap\bootstrap.c.gz")
$gz  = [IO.Compression.GZipStream]::new($in, [IO.Compression.CompressionMode]::Decompress)
$out = [IO.File]::Create("build\bootstrap.c")
try { $gz.CopyTo($out) } finally { $out.Close(); $gz.Close(); $in.Close() }

Step "[2/4] Compiling stage1 from the seed  ($CC)"
& $CC -O2 -o build\stage1.exe build\bootstrap.c $runtime -Iruntime\c -lm
if ($LASTEXITCODE -ne 0) { throw "stage1 compilation failed ($CC exited $LASTEXITCODE)" }

Step "[3/4] stage1 -> emitting the full compiler's C  build\main.c  (self-compiles ~30 kLoC, ~30s)"
& .\build\stage1.exe vader\cli\main.vader build\main.c
if ($LASTEXITCODE -ne 0) { throw "stage1 failed to compile vader/cli/main.vader (exit $LASTEXITCODE)" }

Step "[4/4] Compiling the full compiler  ($CC) -> build\vader.exe"
& $CC -O2 -o build\vader.exe build\main.c $runtime -Iruntime\c -lm
if ($LASTEXITCODE -ne 0) { throw "full compiler compilation failed ($CC exited $LASTEXITCODE)" }

Write-Host "==> done  vader built at build\vader.exe" -ForegroundColor Green
& .\build\vader.exe --version
