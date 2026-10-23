# raylib 6.2

[raylib](https://www.raylib.com) is a C library for games and graphics programs,
by Ramon Santamaria and contributors, under the zlib licence (`LICENSE`). This
folder holds what a Vader program needs to call it: the binding `raylib.vader`,
raylib's header, and a static archive per target.

A project reaches it by naming the toolchain's `third_party/` folder in its
`vader.json`:

```json
{ "includePaths": ["$VADER_HOME/third_party"] }
```

then `import "raylib"`. `examples/raylib_sprite` is a complete program.

## Where each file comes from

The release archives are those of
[raylib 6.2](https://github.com/raysan5/raylib/releases/tag/6.2), each checked
against the sha256 GitHub publishes for it.

| target | `lib/<target>/libraylib.a` | sha256 of the committed file |
|---|---|---|
| `darwin-arm64` | `raylib-6.2_macos.tar.gz`, `lib/libraylib.a`, thinned to its arm64 half (`lipo -thin arm64`) | `e8f22c20c1667fb69d381c7dec53094acd9bf837daab7faec7fcb82ce51c9380` |
| `linux-x86_64` | `raylib-6.2_linux_amd64.tar.gz`, `lib/libraylib.a` | `f0ac4cc3e9c1ceadae4ef6ead1f41a235ec333c5af21aa64aebd173c3b9dbcb1` |

| release archive | sha256 |
|---|---|
| `raylib-6.2_macos.tar.gz` | `100437734a44d56ed9d2a1c4b249dbfc6d6cc3477a45e306f9f56fe5f1e2b4ef` |
| `raylib-6.2_linux_amd64.tar.gz` | `586bbc32f3596d439382b1c5dbc6c1c573eb7e1d00fe92be7d4deb116883720d` |
| `raylib-6.2_win64_mingw-w64.zip` | `48ba378d100fe7e13fc2c35d708764b855b815596f3b0a31746e37259283961f` |
| source, `archive/refs/tags/6.2.tar.gz` | `df7a13129b1bec9e73a6962efff170beba310ee6eab8f94cd000b7316b4db5ee` |

`include/raylib.h` and `LICENSE` come from the source tree. The header is the one
every release archive ships, the Windows one with CRLF line endings.

## Windows

Not shipped yet: on Windows, `raylib.h` and `<windows.h>` cannot share a C
translation unit, and the C that `vader build` emits includes both, so a raylib
program does not build there. The archives join the others once it does:

- `windows-x86_64`: `raylib-6.2_win64_mingw-w64.zip`, `lib/libraylib.a`. It links
  against the UCRT (`__acrt_iob_func`), as llvm-mingw and recent MinGW
  toolchains do.
- `windows-arm64`: raylib publishes no MinGW archive for this target. It builds
  from the 6.2 source with llvm-mingw 20260826 (clang 23.1.0, UCRT), using the
  flags of raylib's `src/Makefile` for `PLATFORM_DESKTOP_GLFW` on Windows. In
  `src/`:

```
aarch64-w64-mingw32-clang -c <module>.c -Wall -D_GNU_SOURCE -DPLATFORM_DESKTOP_GLFW \
    -DGRAPHICS_API_OPENGL_33 -Wno-missing-braces -Werror=pointer-arith \
    -fno-strict-aliasing -std=c99 -DUNICODE -O1 \
    -Werror=implicit-function-declaration -I. -Iexternal/glfw/include
```

for `rcore`, `rshapes`, `rtextures`, `rtext`, `rmodels` and `raudio`, the same
with `-U_GNU_SOURCE` added for `rglfw`, then
`llvm-ar rcs libraylib.a rcore.o rshapes.o rtextures.o rtext.o rmodels.o raudio.o rglfw.o`.
