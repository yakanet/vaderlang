## macOS

For Apple Silicon, macOS 13 or later.

```sh
tar -xzf vader-darwin-arm64.tar.gz
xattr -d com.apple.quarantine vader-darwin-arm64/vader
./vader-darwin-arm64/vader --version
```

The binary is not signed: `xattr` lifts the quarantine macOS puts on a downloaded file. `vader build` uses the C compiler of the Xcode command line tools (`xcode-select --install`).

## Linux

For x86-64, with glibc 2.35 or later (Ubuntu 22.04, Debian 12 and later).

```sh
tar -xzf vader-linux-x64.tar.gz
./vader-linux-x64/vader --version
```

`vader build` uses `cc`: install gcc or clang.

## Windows

For x64, Windows 10 or later.

```powershell
tar -xf vader-windows-x64.zip
.\vader-windows-x64\vader.exe --version
```

`vader build` needs a MinGW-w64 C compiler, gcc or clang; MSVC is not supported. One way to get it:

```powershell
winget install BrechtSanders.WinLibs.MCF.UCRT
```

## Keep the folder whole

`vader` finds its library and its C runtime in the folder beside it: move the folder, not the binary alone, and add it to your `PATH`. To keep the binary elsewhere, set `VADER_HOME` to the folder.

## Build from source

A C compiler is all it takes: the repository holds the compiler as C, which builds the current sources in three stages.

```sh
git clone https://github.com/yakanet/vaderlang.git
cd vaderlang
bash bootstrap/build.sh --dist
```

The toolchain lands in `dist/vader-<os>-<arch>/`, the same folder an archive holds. On Windows, run `bootstrap\build.ps1 -Dist` from PowerShell, with a MinGW-w64 compiler.
