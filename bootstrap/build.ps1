#!/usr/bin/env pwsh
# Build the full Vader compiler from the committed C seed -- TWO stages:
#   seed   -cc->                 build\stage0.exe  (bootstrap compiler; emits C only)
#   stage0 -emit C-> cc release-> build\vader.exe  (= stage1, the shipped compiler)
#
# `-ThreeStage` adds the round `verify.sh` needs, which compares stage1 against
# the stage2 it produces. See bootstrap/build.sh's header for the reasoning.
#
# Runs on Windows PowerShell 5.1 as well as PowerShell 7+ -- keep it that way:
# nothing here may use a 7-only form (`ForEach-Object -Parallel`, `??`, `?:`,
# `&&`), since 5.1 is what a stock Windows offers and the CI only runs 7.
# Needs a mingw-w64 C compiler (gcc or clang) on PATH -- MSVC is NOT supported
# (the runtime uses __attribute__((weak))). The seed is plain C, compiled where
# it is tracked -- nothing to decompress. The compiler defaults to gcc; override
# with `-CC clang` or $env:CC. It is resolved to an absolute path and passed to
# stage1 via --cc. stage0 is a throwaway built -O1 ($env:STAGE0_CFLAGS); stage1 is
# built -O3+LTO in both modes, because `verify.sh` compares its emission against
# stage2's and two differently-built binaries do not answer that. Pass -Dist to also
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
$seedRoot = Join-Path $PWD 'bootstrap\seed'

# A host the seed does not name by triple builds from its OS SIBLING. What lands
# in a per-target directory is chosen by `@target`, whose granularity is the OS
# and never the arch, so every arch of one OS emits the same bytes --
# `seed\windows-x86_64` and `seed\windows-arm64` were byte-identical, which is
# why `seed.sh::SEED_TARGETS` seeds one arch per OS. Only an OS with no slice at
# all is unbuildable.
$seedTarget = $hostTarget
if (-not (Test-Path (Join-Path $seedRoot $seedTarget))) {
    $seedTarget = @(Get-ChildItem -Path $seedRoot -Directory -Filter 'windows-*' |
                    Sort-Object Name | ForEach-Object { $_.Name })[0]
}
if (-not $seedTarget) {
    $seeded = (Get-ChildItem -Path $seedRoot -Directory | ForEach-Object { $_.Name }) -join ' '
    throw "no seed for $hostTarget -- seeded targets: $seeded"
}
if ($seedTarget -ne $hostTarget) {
    Write-Host "no seed for $hostTarget -- building stage0 from its OS sibling $seedTarget"
}
$seedIncDir = Join-Path $seedRoot $seedTarget
$seedHost = @(Get-ChildItem -Path $seedIncDir -Filter '*.c' -ErrorAction SilentlyContinue | ForEach-Object { $_.FullName })
$seedInc = @($seedIncDir, $seedRoot)
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

# Start-Process joins -ArgumentList with spaces and quotes nothing of its own,
# so an include root or source path holding a space would arrive as two
# arguments.
function QuoteArg($a) {
    $s = "$a"
    if ($s -match '[\s"]') { return '"' + ($s -replace '"', '\"') + '"' }
    return $s
}

# One cc process per unit, at most $ccJobs at a time. Windows PowerShell 5.1 has
# no `ForEach-Object -Parallel`, and its `$using:` reaches only into jobs and
# remote sessions -- driving the processes directly is the one form 5.1 and 7
# both accept, so this stays a single code path instead of a per-version branch.
function CcCompileAll($flags, $objDir, $units, $incArgs, $what) {
    $queue = [System.Collections.Queue]::new()
    foreach ($u in $units) { $queue.Enqueue($u) }
    $running = [System.Collections.ArrayList]::new()
    $failed = [System.Collections.ArrayList]::new()
    while ($queue.Count -gt 0 -or $running.Count -gt 0) {
        while ($running.Count -lt $ccJobs -and $queue.Count -gt 0) {
            $unit = $queue.Dequeue()
            $obj = Join-Path $objDir ([IO.Path]::GetFileNameWithoutExtension($unit) + '.o')
            $log = "$obj.log"
            $argv = @(@($flags) + $incArgs + @('-c', $unit, '-o', $obj) |
                Where-Object { $null -ne $_ -and "$_" -ne '' })
            $proc = Start-Process -FilePath $ccAbs -NoNewWindow -PassThru `
                -ArgumentList (($argv | ForEach-Object { QuoteArg $_ }) -join ' ') `
                -RedirectStandardError $log
            # Reading .Handle keeps the handle open: without it .ExitCode is
            # unavailable once the child is gone, and every unit reads as a pass.
            $null = $proc.Handle
            [void]$running.Add([pscustomobject]@{ Proc = $proc; Unit = $unit; Log = $log })
        }
        Start-Sleep -Milliseconds 40
        for ($i = $running.Count - 1; $i -ge 0; $i--) {
            $slot = $running[$i]
            if (-not $slot.Proc.HasExited) { continue }
            $slot.Proc.WaitForExit()
            $text = if (Test-Path $slot.Log) { Get-Content -Raw $slot.Log } else { '' }
            Remove-Item $slot.Log -Force -ErrorAction SilentlyContinue
            if ($text -and "$text".Trim()) { Write-Host "$text".TrimEnd() }
            if ($slot.Proc.ExitCode -ne 0) { [void]$failed.Add($slot.Unit) }
            $running.RemoveAt($i)
        }
    }
    if ($failed.Count -gt 0) { throw "$what compilation failed for: $($failed -join ', ')" }
}

function CcLinkParallel($flags, $objDirRel, $outFile, $units, $what, $ldflags, $extraInc) {
    $objDir = Join-Path $PWD $objDirRel
    $rtInc = Join-Path $PWD 'runtime\c'
    # `$extraInc` is a LIST of include roots, most specific first: the seed's
    # per-target directory owns `bootstrap.imports.h`, its root the shared
    # `bootstrap.split.h`.
    $incArgs = @($extraInc | Where-Object { $null -ne $_ } | ForEach-Object { "-I$_" }) +
               @("-I$rtInc")
    CcCompileAll $flags $objDir $units $incArgs $what
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
# `-ThreeStage` adds the round `verify.sh` needs to compare stage1 against stage2 ;
# only the OUTPUT PATH differs between the modes. stage1 carries the release flags
# in both, which is load-bearing rather than tidy -- see bootstrap/build.sh, which
# had the same -O1 mismatch and made the fixed-point gate report an -O sensitivity
# as a fixed-point failure.
if ($ThreeStage) {
    $stages = 3
    $stage1Out = 'build\stage1.exe'
} else {
    $stages = 2
    $stage1Out = 'build\vader.exe'
}
$stage1Cflags = @('-std=c11', '-O3', '-DNDEBUG', '-falign-functions=64') + (LtoCompileFlags)
$stage1Ldflags = LtoLinkFlags

Step "[1/$stages] Building stage0 (bootstrap compiler, from the seed)  [$ccAbs $stage0cflags, $hostTarget, -j$ccJobs]"
$work0 = Join-Path $PWD 'build\work\stage0'
Remove-Item -Recurse -Force $work0 -ErrorAction SilentlyContinue
New-Item -ItemType Directory -Force $work0 | Out-Null
$seedUnits = @($seedShared) + @($seedHost) + @((Join-Path $PWD $runtime))
CcLinkParallel $stage0cflags 'build\work\stage0' 'build\stage0.exe' $seedUnits 'stage0' $null $seedInc

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
