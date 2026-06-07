package dev.vaderlang.intellij

import com.intellij.execution.configurations.GeneralCommandLine
import com.intellij.openapi.project.Project
import com.redhat.devtools.lsp4ij.LanguageServerFactory
import com.redhat.devtools.lsp4ij.server.OSProcessStreamConnectionProvider
import com.redhat.devtools.lsp4ij.server.StreamConnectionProvider

// Wires the Vader Language Server into LSP4IJ. LSP4IJ takes care of the
// JSON-RPC plumbing, lifecycle, PSI integration (goto-def with the
// Ctrl-hover underline preview, find-usages, …) — we only have to tell
// it how to spawn the server process.
//
// The binary path is read from `VaderSettings` (Settings → Tools →
// Vader) and falls back to `vader` from `$PATH` when not set — same
// default as the VSCode extension.
internal class VaderLanguageServerFactory : LanguageServerFactory {
    override fun createConnectionProvider(project: Project): StreamConnectionProvider =
        VaderConnectionProvider(project)
}

private class VaderConnectionProvider(project: Project) : OSProcessStreamConnectionProvider() {
    init {
        val configured = VaderSettings.getInstance().lspPath.trim()
        val binary = if (configured.isNotEmpty()) configured else "vader"
        val cmd = GeneralCommandLine(binary, "lsp")
        // Spawn from the project root so the server's stdlib probe
        // (`default_stdlib_root` → `<cwd>/stdlib` fallback) resolves the
        // workspace stdlib, mirroring how the VSCode client launches it.
        // Without this the process inherits the IDE's cwd and every `std/*`
        // import fails to resolve.
        project.basePath?.let { cmd.withWorkDirectory(it) }
        commandLine = cmd
    }
}
