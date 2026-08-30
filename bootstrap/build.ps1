#!/usr/bin/env pwsh
# Build the full Vader compiler from the committed C seed -- TWO stages:
#   seed   -cc->                 build\stage0.exe  (bootstrap compiler; emits C only)
#   stage0 -emit C-> cc release-> build\vader.exe  (= stage1, the shipped compiler)
#
# `-ThreeStage` adds the round `verify.sh` needs, which compares stage1 against
# the stage2 it produces. See bootstrap/build.sh's header for the reasoning.
#
# Needs a mingw-w64 C compiler (gcc or clang) on PATH -- MSVC is NOT supported
# (the runtime uses __attribute__((weak))). The seed is plain C, compiled where
# it is tracked -- nothing to decompress. The compiler defaults to gcc; override
# with `-CC clang` or $env:CC. It is resolved to an absolute path and passed to
# stage1 via --cc. stage0 & stage1 are throwaways built -O1 ($env:STAGE0_CFLAGS);
# only stage2/vader is built -O3 (via stage1's --release). Pass -Dist to also
# assemble a self-contained dist\vader-windows-<arch>\ bundle. See docs/BOOTSTRAP.md.
[CmdletBinding()]
param([string]$CC = $(if ($env:CC) { $env:CC } else { 'gcc' }), [switch]$Dist, [switch]$ThreeStage)

$ErrorActionPreference = 'Stop'
Set-Location (Split-Path -Parent $PSScriptRoot)
# Set-Location only updates $PWD ; .NET resolves relative paths against
# [Environment]::CurrentDirectory, which Set-Location never touches. Sync it so
# the cc/stage child processes resolve relative paths against the repo root.
[Environment]::CurrentDirectory = $PWD.Path

$ccCmd = Get-Command $CC -ErrorAction SilentlyContinue
if ($null -eq $ccCmd) { throw "C compiler '$CC' not found on PATH (use -CC ...)" }
$ccAbs = $ccCmd.Source
$stage0cflags = if ($env:STAGE0_CFLAGS) { $env:STAGE0_CFLAGS } else { '-O1' }
$ccJobs = if ($env:CC_JOBS -match '^[1-9][0-9]*$') { [int]$env:CC_JOBS } else { [Environment]::ProcessorCount }
$runtime = "runtime\c\vader_runtime.c"

# Arena sizing is RAM-proportional (runtime\c\vader_runtime.c::vader_gc_init --
# old init + cap derived from physical RAM, single VADER_GC_RAM_PERCENT knob), so
# the bootstrap self-compiles at a saner initial size on any machine with no manual
# override. This used to pin VADER_GC_YOUNG_BYTES / VADER_GC_OLD_BYTES to avoid the
# default-256-MB-old GC thrash; the RAM model + auto-grow now handle that. Any
# VADER_GC_* value the caller exports still wins (advanced escape hatch).

function Step($msg) { Write-Host "==> $msg" -ForegroundColor Cyan }
New-Item -ItemType Directory -Force build | Out-Null

# The seed is a SET: the units every target shares, plus the ones that differ for
# this host. A unit lands in the second group only when the targets actually
# emitted different bytes for it, so today there are none — the list is globbed
# rather than hardcoded, and starts working the day one appears.
$hostArch = if ($env:PROCESSOR_ARCHITECTURE -eq 'ARM64') { 'arm64' } else { 'x86_64' }
$hostTarget = "windows-$hostArch"
$seedShared = @(Get-ChildItem -Path 'bootstrap\seed' -Include 'bootstrap.split.g.c','bootstrap-*.c' -Recurse -ErrorAction SilentlyContinue | ForEach-Object { $_.FullName })
$seedHost = @(Get-ChildItem -Path 'bootstrap\seed' -Filter "bootstrap.$hostTarget-*.c" -ErrorAction SilentlyContinue | ForEach-Object { $_.FullName })
if ($seedShared.Count -eq 0) {
    throw "no seed under bootstrap\seed\ -- run bootstrap/seed.sh regenerate"
}

# Release codegen policy, DUPLICATED from `vader/pipeline/emit.vader` -- which
# calls itself its single source of truth, and is right to. The two-stage build
# hands `build\vader.exe` to a `cc` this script drives, so the script has to know
# the policy; there is no compiler in the loop yet to ask.
function CcFlavour {
    $banner = (& $ccAbs --version 2>&1 | Out-String).ToLower()
    if ($banner -match 'clang') { return 'clang' }
    if ($banner -match 'gcc|free software foundation') { return 'gcc' }
    return 'unknown'
}

function LtoCompileFlags {
    switch (CcFlavour) { 'clang' { @('-flto=thin') } 'gcc' { @('-flto=auto') } default { @() } }
}

function LtoLinkFlags {
    switch (CcFlavour) {
        'clang' { @('-flto=thin', '-O3', '-Wl,-mllvm,-import-instr-limit=300') }
        'gcc'   { @('-flto=auto', '-O3') }
        default { @() }
    }
}

function CcLinkParallel($flags, $objDirRel, $outFile, $units, $what, $ldflags) {
    $objDir = Join-Path $PWD $objDirRel
    $rtInc = Join-Path $PWD 'runtime\c'
    $cc = $ccAbs
    $failed = $units | ForEach-Object -ThrottleLimit $ccJobs -Parallel {
        $c = $using:cc
        $f = $using:flags
        $inc = $using:rtInc
        $obj = Join-Path $using:objDir ([IO.Path]::GetFileNameWithoutExtension($_) + '.o')
        # `2>&1` is load bearing: a cc WARNING left on the runspace's error
        # stream reaches the parent pipeline, where the script's 'Stop'
        # preference makes it terminating -- the build died on a warning before
        # $LASTEXITCODE could be read. Folding it into the output stream keeps
        # the text and makes the exit code the only verdict.
        $out = & $c $f "-I$inc" -c $_ -o $obj 2>&1
        if ($out) { Write-Host (($out | Out-String).TrimEnd()) }
        if ($LASTEXITCODE -ne 0) { $_ }
    }
    if ($failed) { throw "$what compilation failed for: $($failed -join ', ')" }
    $objs = @(Get-ChildItem -Path $objDir -Filter '*.o' | ForEach-Object { $_.FullName })
    if ($objs.Count -eq 0) { throw "$what link: no objects under $objDir" }
    # `@(...)` on $null yields a ONE-element array holding $null, which reaches a
    # native command as an empty argument -- and gcc reads an empty file name as
    # stdin ("-E or -x required when input is from standard input"). Filter it.
    $link = @(@(if ($null -ne $ldflags) { $ldflags } else { $flags }) |
        Where-Object { $null -ne $_ -and "$_" -ne '' })
    & $ccAbs @link -o $outFile @objs -lm
    if ($LASTEXITCODE -ne 0) {
        Write-Host "link command was: $ccAbs $($link -join ' ') -o $outFile <$($objs.Count) objects> -lm"
        throw "$what link failed (exit $LASTEXITCODE)"
    }
}

# Two stages by default: stage1 is built `--release` and IS the shipped compiler.
# `-ThreeStage` adds the round `verify.sh` needs to compare stage1 against stage2.
if ($ThreeStage) {
    $stages = 3
    $stage1Out = 'build\stage1.exe'
    $stage1Cflags = $stage0cflags
    $stage1Ldflags = @($stage0cflags)
} else {
    $stages = 2
    $stage1Out = 'build\vader.exe'
    $stage1Cflags = @('-std=c11', '-O3', '-DNDEBUG', '-falign-functions=64') + (LtoCompileFlags)
    $stage1Ldflags = LtoLinkFlags
}

Step "[1/$stages] Building stage0 (bootstrap compiler, from the seed)  [$ccAbs $stage0cflags, $hostTarget, -j$ccJobs]"
$work0 = Join-Path $PWD 'build\work\stage0'
Remove-Item -Recurse -Force $work0 -ErrorAction SilentlyContinue
New-Item -ItemType Directory -Force $work0 | Out-Null
$seedUnits = @($seedShared) + @($seedHost) + @((Join-Path $PWD $runtime))
CcLinkParallel $stage0cflags 'build\work\stage0' 'build\stage0.exe' $seedUnits 'stage0' $null

Step "[2/$stages] Building stage1 (full compiler, via stage0)  -- self-compiles"
$work1 = Join-Path $PWD 'build\work\stage1'
Remove-Item -Recurse -Force $work1 -ErrorAction SilentlyContinue
New-Item -ItemType Directory -Force $work1 | Out-Null
& .\build\stage0.exe vader\cli\main.vader (Join-Path $work1 'stage1')
if ($LASTEXITCODE -ne 0) { throw "stage0 failed to emit stage1 units (exit $LASTEXITCODE)" }
$stage1Units = @(Get-ChildItem -Path $work1 -Filter '*.c' | ForEach-Object { $_.FullName })
$stage1Units += (Join-Path $PWD $runtime)
CcLinkParallel $stage1Cflags 'build\work\stage1' $stage1Out $stage1Units 'stage1' $stage1Ldflags

if ($ThreeStage) {
    Step "[3/3] Building vader = stage2 (via stage1, --release)"
    $stage2Dir = Join-Path $PWD 'build\work\stage2'
    Remove-Item -Recurse -Force $stage2Dir -ErrorAction SilentlyContinue
    New-Item -ItemType Directory -Force $stage2Dir | Out-Null
    $stage2Out = Join-Path $stage2Dir 'vader'
    & .\build\stage1.exe build --release --emit=executable "--out=$stage2Out" --cc=$ccAbs vader\cli\main.vader
    if ($LASTEXITCODE -ne 0) { throw "stage1 failed to build vader (exit $LASTEXITCODE)" }
    # `cc -o vader` writes `vader.exe` here and `vader` on Unix -- the same reason
    # `vader/pipeline::linked_binary` probes instead of guessing.
    $produced = @(Get-ChildItem -Path $stage2Dir -Filter 'vader*' -File |
        Where-Object { $_.Extension -in @('.exe', '') })
    if ($produced.Count -eq 0) { throw "stage1 produced no binary under $stage2Dir" }
    Move-Item -Force $produced[0].FullName (Join-Path 'build' $produced[0].Name)
}

Write-Host "==> done  vader built at build\vader.exe" -ForegroundColor Green
& .\build\vader.exe --version

if ($Dist) {
    $arch = if ($env:PROCESSOR_ARCHITECTURE -eq 'ARM64') { 'arm64' } else { 'x64' }
    $distDir = "dist\vader-windows-$arch"

    Step "[dist] Bundling $distDir  (vader + lib/ + src/vader + runtime/c)"
    if (Test-Path $distDir) { Remove-Item -Recurse -Force $distDir }
    New-Item -ItemType Directory -Force "$distDir\runtime" | Out-Null
    New-Item -ItemType Directory -Force "$distDir\src" | Out-Null
    Copy-Item build\vader.exe "$distDir\vader.exe"
    # One module root, copied whole -- see the matching block in bootstrap/build.sh.
    Copy-Item -Recurse lib "$distDir\lib"
    Copy-Item -Recurse vader "$distDir\src\vader"
    # Drop the human front-ends -- see bootstrap/dist-exclude.txt.
    foreach ($excluded in Get-Content bootstrap\dist-exclude.txt) {
        if ($excluded -match '^\s*(#|$)') { continue }
        Remove-Item -Recurse -Force "$distDir\src\vader\$($excluded.Trim())" -ErrorAction SilentlyContinue
    }
    Copy-Item -Recurse runtime\c "$distDir\runtime\c"

    Write-Host "==> dist  $distDir ready -- a self-contained toolchain (resolves lib\ + runtime\c\ next to the binary, so it runs -- and drives builds -- from any directory)." -ForegroundColor Green
}
