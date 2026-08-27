# `tools/windows-vm` — a real Windows oracle, from the macOS terminal

A headless **Windows 11 ARM64** guest on Apple Silicon, accelerated by
Hypervisor.framework and driven entirely over SSH. No hypervisor UI is ever
opened.

## Why

`wine` is a fast local loop, not a Windows oracle — its
`GetFileAttributesA("C:")` succeeds, so it never reproduced the drive-root bug
(TODO.md, *"Where wine belongs"*). The real `windows-latest` CI job **is** an
oracle, but at a ~12 min round trip. This VM is a genuine NT kernel with genuine
Win32 semantics, roughly a minute away.

**What it covers**: the 28 `_WIN32` branches of `runtime/c/vader_runtime.c`,
drive roots, path separators, CRLF stdio, pipes, process spawn — every bug the
Windows job has actually caught.

**What it does not**: CI builds `x86_64-w64-mingw32` with gcc; this guest builds
`aarch64` with clang. It isolates *OS* behaviour from *arch* behaviour, which is
the axis the bugs live on — but a gcc-on-x86 codegen bug will not reproduce
here. Install an x86_64 mingw in the same guest and let Prism emulate it if that
day comes; the OS underneath stays real either way.

## One-time setup

```sh
brew install --cask vagrant           # 2.4+, for box_architecture support
brew install --cask virtualbox        # 7.2+, a supported Apple Silicon build
cd tools/windows-vm && vagrant up     # ~15 GB box download, then provisioning
```

Both are `pkg` casks, so each asks for your password once. No Vagrant plugin is
needed: VirtualBox is the built-in provider.

`vagrant up` boots the guest headless and installs, from pinned upstream zips:

| | version | why this one |
|---|---|---|
| `llvm-mingw` | 20260826 (ucrt-aarch64) | GCC has no usable aarch64-windows host build; `bootstrap/build.ps1` already takes `-CC clang` |
| `bun` | 1.3.13 (windows-aarch64) | the exact pin in `.github/workflows/build.yml` |
| `pwsh` | 7.6.5 (win-arm64) | CI runs `pwsh bootstrap/build.ps1`, so we do too |

## Daily use

Plain Vagrant does almost all of it, from this directory:

```sh
vagrant ssh                                      # interactive PowerShell
vagrant ssh -c "Set-Location C:/vader; ls build" # one-off command
vagrant halt | status | provision | destroy
```

Vagrant owns the key and the connection — nothing is written outside
`.vagrant/`, no host ssh config, no key parked in `~/.ssh`. The guest is
disposable and `vagrant destroy` takes its credentials with it.

The one gap is getting the tree *onto* the guest, which is what `bin/vwin`
covers and nothing else:

```sh
bin/vwin sync            # push the working tree to C:\vader
bin/vwin build           # sync, then bootstrap/build.ps1 -CC clang
bin/vwin test tests/lsp  # sync, then bun run test --only-failures
```

## Two decisions worth knowing

**No shared folder.** `vboxsf`/HGFS change the very filesystem semantics this VM
exists to test, and the box ships no Guest Additions anyway. `vwin sync` pushes
the tree onto the guest's own NTFS at `C:\vader` — a tarball of everything
`git ls-files` reports, so `node_modules/`, `build/` and `dist/` never cross the
wire (4200 files, 7 MB compressed, a couple of seconds). Removed files are not pruned; use
`vwin sync --clean` after a branch switch.

Vagrant's own answer to this is a `type: "rsync"` synced folder, which would
buy `vagrant rsync-auto`. It was weighed and dropped: the Windows guest
capability rewrites `C:` to `/cygdrive/C` because it expects a cygwin rsync in
the guest, and putting MSYS2 on that PATH is the hazard `.github/workflows/`
already warns about (an MSYS `gcc` links against `msys-2.0.dll`). Its
`rsync__exclude` would also be a hand-maintained copy of `.gitignore`, free to
drift, where `git ls-files` cannot.

**Windows Search and SysMain are switched off** by the provisioner. WSearch
re-indexed the 4200 files `vwin sync` rewrites every iteration, and it dominated
the run time: three builds before the change took 110 s, 126 s and 252 s; two
after took 79.7 s and 81.6 s. The fastest run before is still 35 % slower than
the slowest run after, and the 2.3× spread collapses to 1.02×. Neither service
touches filesystem semantics, so this costs no fidelity.

**Defender is already excluded — by the box, not by us.** `Get-MpPreference`
reports `ExclusionPath = c:\`, so there is nothing to add. Note what that does
*not* buy: with the whole drive excluded, `MsMpEng` still burned 165 s of CPU
over 27 min of uptime, because an exclusion covers real-time file scanning and
not behavioural monitoring, AMSI or scheduled scans.

## Resources

Defaults to 6 vCPU / 8 GB, overridable:

```sh
VADER_WIN_CPUS=8 VADER_WIN_MEMORY=12288 vagrant up
```

## The box

`gusztavvargadr/windows-11-25h2-professional`, `box_architecture = "arm64"` —
the Windows 11 image published for arm64 (VirtualBox and VMware Fusion only),
Packer-built from Microsoft media and released monthly. `box_architecture` is
mandatory: the registry serves amd64 by default, which VirtualBox would have to
emulate.

There is **no official Microsoft or HashiCorp Windows box** — Microsoft has
never published one and retired its ready-made dev VMs in October 2024. This
family is the de-facto standard. It is built from evaluation media, so the
licence has a clock; `vagrant destroy && vagrant up` resets it.

Switching to VMware Fusion is a one-line change (`--provider vmware_desktop`) —
the same box publishes both arm64 variants.
