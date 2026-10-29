# Get started

## Install

Download the archive for your system from the [download page](/download/), extract it, and check that it runs:

```sh
./vader-linux-x64/vader --version
```

The folder holds everything `vader` needs: keep it whole, and add it to your `PATH`. `vader run` needs nothing else; `vader build` also needs a C compiler (clang or gcc). You can also [build Vader from source](/download/#build-from-source) with a C compiler alone.

## Your first program

Save this as `hello.vader`, in a folder of its own:

```vader
module "main"

import "std/io"

main :: fn() -> i32 {
    println("Hello, World!")
    return 0
}
```

```text
Hello, World!
```

Run it on the VM, or compile it to a native binary:

```sh
vader run hello.vader
vader build --out=hello hello.vader && ./hello
```

Every file starts with its `module` line, and a program starts at `main`, whose result is the exit status.

## Start a project

`vader new` writes a project: a `vader.json` that declares the program, `src/main.vader`, and a `.gitignore`.

```sh
vader new my-app
cd my-app
vader run .
vader build
```

`vader build` writes the binary under `build/`. `vader test` runs the `@test` functions the project declares.

## Set up your editor

The extensions for [VS Code](https://github.com/yakanet/vaderlang/tree/main/editors/vscode) and for [IntelliJ](https://github.com/yakanet/vaderlang/tree/main/editors/intellij) and the other JetBrains IDEs color the code and run `vader lsp`, the language server: completion, navigation, rename, formatting. They are installed from the repository for now.

## Read on

- [Learn](/learn/): the language one construct at a time, each with a short program.
- [Examples](/examples/): whole programs, with what they print.
- [The language reference](/spec/): its rules, chapter by chapter.
- [The library reference](/lib/): every module the toolchain ships.
