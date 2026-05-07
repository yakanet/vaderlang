# Vader for VS Code

Minimal VS Code extension providing syntax highlighting for the [Vader](../../README.md) programming language.

## Features

- Syntax highlighting for `.vader` files
- Comment toggling (`//`, `/* */`)
- Bracket matching and auto-closing pairs

## Install locally

From this directory:

```bash
# Symlink into your VS Code extensions folder
ln -s "$PWD" ~/.vscode/extensions/vader-0.1.0
```

Then reload VS Code (`Cmd+Shift+P` → *Developer: Reload Window*).

Alternatively, package and install with [`vsce`](https://github.com/microsoft/vscode-vsce):

```bash
npm install -g @vscode/vsce
vsce package
code --install-extension vader-0.1.0.vsix
```
