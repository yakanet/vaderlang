# Vader for VS Code

VS Code extension for the [Vader](../../README.md) programming language. Provides syntax highlighting (TextMate grammar) plus semantic highlighting via a Language Server.

## Features

- Syntax highlighting for `.vader` files
- Semantic tokens via the Vader Language Server (richer highlighting for keywords, types, functions, parameters, decorators, and VaderDoc `@param` / `@return` / `@error` / `@example` tags)
- Comment toggling (`//`, `/* */`, `///`) and `///` auto-continuation on Enter
- Bracket matching and auto-closing pairs

## Requirements

The extension spawns the Vader CLI to host the Language Server. Install the `vader` binary from the [project's distribution](../../README.md#installation) and ensure it is on your `PATH` (or set `vader.lsp.path` to the absolute path).

> VS Code launched from the macOS Dock / Windows Start Menu inherits a *GUI* `PATH` that often differs from your shell's. If you see `spawn vader ENOENT`, the binary isn't on that inherited `PATH` — set `vader.lsp.path` to an absolute path (or to `${workspaceFolder}/build/vader` when working inside the Vader repo).

## Settings

- `vader.lsp.path` (default `"vader"`) — path to the Vader CLI binary. Supports `${workspaceFolder}` interpolation.
- `vader.lsp.args` (default `["lsp"]`) — arguments passed to the binary to start the language server. Supports `${workspaceFolder}` interpolation.
- `vader.lsp.trace.server` — `off` / `messages` / `verbose`. Controls the verbosity of the `Vader Language Server` output channel.

## Shared grammar

The TextMate grammar (`vader.tmLanguage.json`) and `language-configuration.json` live in [`editors/common/`](../common/) and are copied here by `node sync.js`. `vsce package` invokes the sync via the `vscode:prepublish` hook so the packaged grammar is always current.

## Install locally

From this directory :

```bash
npm install                                           # vscode-languageclient + esbuild
npm run build                                          # bundle src/extension.ts → out/extension.js
ln -s "$PWD" ~/.vscode/extensions/vader-0.1.0          # symlink into extensions folder
```

Then reload VS Code (`Cmd+Shift+P` → *Developer: Reload Window*).

Alternatively, package and install :

```bash
npm install -g @vscode/vsce
vsce package
code --install-extension vader-0.1.0.vsix
```
