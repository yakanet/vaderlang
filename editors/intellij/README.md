# Vader for JetBrains IDEs

Minimal IntelliJ Platform plugin providing syntax highlighting for the [Vader](../../README.md) programming language. Works in IntelliJ IDEA, PyCharm, WebStorm, RustRover, GoLand, CLion — anywhere the bundled TextMate plugin is available.

## Features

- Syntax highlighting for `.vader` files via the bundled `org.jetbrains.plugins.textmate` plugin
- Grammar shared with the [VS Code extension](../vscode/) through [`editors/common/`](../common/) — single source of truth, no duplication

> Limited to syntax highlighting for now. No PSI, no completion, no go-to-definition.

## Build

You need a JDK 17+ on `PATH`. The Gradle wrapper is already committed, so no global Gradle install is required:

```bash
./gradlew buildPlugin
```

The packaged plugin lands in `build/distributions/vader-intellij-0.1.0.zip`.

To run the JetBrains Plugin Verifier against several IDE versions (same checks as the Marketplace):

```bash
./gradlew verifyPlugin
```

## Install

1. Open your JetBrains IDE.
2. Open *Settings* (<kbd>⌘</kbd><kbd>,</kbd> on macOS / <kbd>Ctrl</kbd><kbd>Alt</kbd><kbd>S</kbd> elsewhere) → *Plugins*.
3. Click the gear icon ⚙️ at the top → *Install Plugin from Disk…*
4. Pick the `.zip` from `build/distributions/`.
5. Restart the IDE when prompted.
6. Open any `.vader` file — highlighting kicks in.

## Develop

`runIde` launches a sandboxed IDE instance with the plugin already installed:

```bash
./gradlew runIde
```

Use it to iterate without rebuilding and reinstalling each time.

## Uninstall

*Settings* → *Plugins* → *Installed* tab → search **Vader** → *Uninstall*.

## Shared grammar

The TextMate grammar (`vader.tmLanguage.json`) and `language-configuration.json` are **not** stored in this folder. They live in [`editors/common/`](../common/) and are copied into the plugin resources at build time by Gradle's `processResources` task. To evolve the grammar, edit the files in `editors/common/` and rebuild.
