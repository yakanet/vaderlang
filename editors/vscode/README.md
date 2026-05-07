# Vader for VS Code

Minimal VS Code extension providing syntax highlighting for the [Vader](../../README.md) programming language.

## Features

- Syntax highlighting for `.vader` files
- Comment toggling (`//`, `/* */`)
- Bracket matching and auto-closing pairs

## Shared grammar

The TextMate grammar (`vader.tmLanguage.json`) and `language-configuration.json` are **not** versioned inside this folder — they live in [`editors/common/`](../common/) and are copied here by an `npm` script:

```bash
npm run sync
```

Re-run it any time the grammar changes upstream. `vsce package` runs it automatically via the `vscode:prepublish` hook, so packaging is always in sync.

## Install locally

From this directory:

```bash
npm run sync                                          # mirror grammar from ../common/
ln -s "$PWD" ~/.vscode/extensions/vader-0.1.0         # symlink into extensions folder
```

Then reload VS Code (`Cmd+Shift+P` → *Developer: Reload Window*).

Alternatively, package and install with [`vsce`](https://github.com/microsoft/vscode-vsce) (the sync runs automatically as part of prepublish):

```bash
npm install -g @vscode/vsce
vsce package
code --install-extension vader-0.1.0.vsix
```
