# Vader for JetBrains IDEs

IntelliJ Platform plugin providing syntax highlighting **plus full LSP integration** for the [Vader](../../README.md) programming language. Works on every JetBrains IDE that supports [LSP4IJ](https://plugins.jetbrains.com/plugin/23257-lsp4ij) — IntelliJ IDEA Community and Ultimate, PyCharm, WebStorm, RustRover, GoLand, CLion, …

## Features

- Syntax highlighting for `.vader` files via the bundled `org.jetbrains.plugins.textmate` plugin
- Grammar shared with the [VS Code extension](../vscode/) through [`editors/common/`](../common/) — single source of truth, no duplication
- **LSP-driven semantic features** : goto-definition (with the Ctrl/Cmd-hover preview link), hover with VaderDoc, semantic tokens, diagnostics — delivered by the Vader Language Server (`vader lsp`) and wired through LSP4IJ

## Prerequisites

This plugin depends on **[LSP4IJ](https://plugins.jetbrains.com/plugin/23257-lsp4ij)** (Red Hat, EPL-2.0). LSP4IJ is the generic LSP client we layer on top of — it handles the JSON-RPC plumbing, server lifecycle, PSI integration, and the Ctrl/Cmd-hover link preview that the IntelliJ Platform's native LSP API doesn't render.

Install LSP4IJ from the JetBrains Marketplace first :

*Settings* → *Plugins* → *Marketplace* → search **LSP4IJ** → *Install* → restart the IDE.

The Vader plugin will refuse to install (or stay disabled) without it.

## Build

You need a JDK 17+ on `PATH`. The Gradle wrapper is already committed, so no global Gradle install is required :

```bash
./gradlew buildPlugin
```

The packaged plugin lands in `build/distributions/vader-intellij-0.1.0.zip`.

To run the JetBrains Plugin Verifier against several IDE versions (same checks as the Marketplace) :

```bash
./gradlew verifyPlugin
```

## Install

1. Make sure LSP4IJ is installed first (see *Prerequisites* above).
2. Open your JetBrains IDE.
3. Open *Settings* (<kbd>⌘</kbd><kbd>,</kbd> on macOS / <kbd>Ctrl</kbd><kbd>Alt</kbd><kbd>S</kbd> elsewhere) → *Plugins*.
4. Click the gear icon ⚙️ at the top → *Install Plugin from Disk…*
5. Pick the `.zip` from `build/distributions/`.
6. Restart the IDE when prompted.
7. Open any `.vader` file — highlighting + LSP features kick in.

## Configure

The plugin spawns the language server via `vader lsp`. If the `vader` binary isn't on your `$PATH`, point the plugin at it explicitly :

*Settings* → *Tools* → *Vader* → *Path to `vader` executable*.

Leave empty to spawn `vader lsp` from `$PATH` (matches the VSCode extension's default).

## Develop

`runIde` launches a sandboxed IDE instance with the plugin already installed :

```bash
./gradlew runIde
```

Use it to iterate without rebuilding and reinstalling each time.

## Uninstall

*Settings* → *Plugins* → *Installed* tab → search **Vader** → *Uninstall*.

## Shared grammar

The TextMate grammar (`vader.tmLanguage.json`) and `language-configuration.json` are **not** stored in this folder. They live in [`editors/common/`](../common/) and are copied into the plugin resources at build time by Gradle's `processResources` task. To evolve the grammar, edit the files in `editors/common/` and rebuild.
