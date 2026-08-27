# tools/windows-vm/provision/toolchain.ps1 -- install the ARM64-native build
# toolchain into the guest. Runs once on `vagrant up`; re-run with `vwin
# provision`.
#
# Every package is a pinned zip fetched straight from its upstream release, so a
# reprovision is reproducible and no package manager sits in the loop. The Bun
# pin tracks .github/workflows/build.yml so the local suite and CI run the same
# runtime; llvm-mingw replaces the mingw-w64 gcc CI uses, because GCC has no
# usable aarch64-windows host build and bootstrap/build.ps1 already accepts
# `-CC clang`.
#
# Note what is deliberately NOT done here: no Defender exclusion for C:\vader.
# Real-time scanning is part of what a Windows build costs, and the point of
# this VM is to observe that faithfully.

$ErrorActionPreference = 'Stop'
# Invoke-WebRequest is roughly an order of magnitude slower with the progress
# bar on -- it repaints per chunk over a slow console.
$ProgressPreference = 'SilentlyContinue'

$LLVM_MINGW_VERSION = '20260826'
$BUN_VERSION        = '1.3.13'
$PWSH_VERSION       = '7.6.5'

$root      = 'C:\vader-tools'
$guestRepo = 'C:\vader'

$packages = @(
    @{
        name  = 'llvm-mingw'
        url   = "https://github.com/mstorsjo/llvm-mingw/releases/download/$LLVM_MINGW_VERSION/llvm-mingw-$LLVM_MINGW_VERSION-ucrt-aarch64.zip"
        bin   = 'bin'
        probe = 'clang.exe'
    },
    @{
        name  = 'bun'
        url   = "https://github.com/oven-sh/bun/releases/download/bun-v$BUN_VERSION/bun-windows-aarch64.zip"
        bin   = ''
        probe = 'bun.exe'
    },
    @{
        name  = 'pwsh'
        url   = "https://github.com/PowerShell/PowerShell/releases/download/v$PWSH_VERSION/PowerShell-$PWSH_VERSION-win-arm64.zip"
        bin   = ''
        probe = 'pwsh.exe'
    }
)

function Install-Package($package) {
    $destination = Join-Path $root $package.name
    $binDir      = if ($package.bin) { Join-Path $destination $package.bin } else { $destination }

    if (Test-Path (Join-Path $binDir $package.probe)) {
        Write-Host "==> $($package.name) already installed at $destination"
        return $binDir
    }

    Write-Host "==> $($package.name)  <- $($package.url)"
    $archive = Join-Path $env:TEMP "$($package.name).zip"
    $staging = Join-Path $env:TEMP "$($package.name)-staging"

    Invoke-WebRequest -Uri $package.url -OutFile $archive -UseBasicParsing
    Remove-Item -Recurse -Force $staging, $destination -ErrorAction SilentlyContinue
    Expand-Archive -Path $archive -DestinationPath $staging -Force

    # Upstream archives disagree on shape: llvm-mingw and bun wrap everything in
    # a single versioned directory, PowerShell extracts flat. Unwrap the former
    # so the layout under $root is uniform.
    $entries = @(Get-ChildItem $staging)
    $payload = if ($entries.Count -eq 1 -and $entries[0].PSIsContainer) { $entries[0].FullName } else { $staging }

    New-Item -ItemType Directory -Force (Split-Path -Parent $destination) | Out-Null
    Move-Item $payload $destination
    Remove-Item -Recurse -Force $staging, $archive -ErrorAction SilentlyContinue

    return $binDir
}

# Desktop conveniences that cost real CPU in a build VM and buy nothing here.
# WSearch re-indexes the ~4200 files `vwin sync` rewrites on every iteration --
# the reindexing the guest was visibly doing -- and SysMain prefetches for
# interactive use that never happens on a headless box. Neither touches
# filesystem semantics, so switching them off does not weaken the fidelity this
# VM exists for. Defender is deliberately left alone: the box already ships
# `ExclusionPath = c:\`, and the rest of its cost is behavioural monitoring an
# exclusion cannot reach anyway.
foreach ($service in "WSearch", "SysMain") {
    if (Get-Service $service -ErrorAction SilentlyContinue) {
        Set-Service -Name $service -StartupType Disabled
        Stop-Service -Name $service -Force -ErrorAction SilentlyContinue
        Write-Host "==> disabled $service"
    }
}

New-Item -ItemType Directory -Force $root, $guestRepo | Out-Null

$binDirs = foreach ($package in $packages) { Install-Package $package }

# User scope, not Machine: this provisioner runs unprivileged on purpose (see
# the Vagrantfile), and `vagrant` is the account every SSH session lands in.
$path  = [Environment]::GetEnvironmentVariable('Path', 'User')
$parts = @($path -split ';' | Where-Object { $_ })
foreach ($dir in $binDirs) {
    if ($parts -notcontains $dir) { $parts += $dir }
}
[Environment]::SetEnvironmentVariable('Path', ($parts -join ';'), 'User')
$env:Path = ($parts -join ';') + ';' + $env:Path

Write-Host ''
Write-Host '==> toolchain ready'
& clang --version | Select-Object -First 1
& clang -dumpmachine
Write-Host "bun  $(& bun --version)"
Write-Host "pwsh $(& pwsh --version)"
Write-Host "repo target: $guestRepo  (push it with ``vwin sync``)"
