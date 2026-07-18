package dev.vaderlang.intellij

import com.intellij.execution.configurations.GeneralCommandLine
import com.intellij.openapi.project.Project
import com.intellij.psi.PsiFile
import com.redhat.devtools.lsp4ij.LanguageServerFactory
import com.redhat.devtools.lsp4ij.client.features.LSPClientFeatures
import com.redhat.devtools.lsp4ij.client.features.LSPFormattingFeature
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

    override fun createClientFeatures(): LSPClientFeatures =
        LSPClientFeatures().setFormattingFeature(VaderFormattingFeature())
}

// `.vader` files are mapped to the server by filename glob (TextMate grammar,
// no IntelliJ Language/PSI). LSP4IJ's default `LSPFormattingFeature` defers to
// an existing native formatter — and IntelliJ's generic plain-text formatter
// counts as one — so "Reformat Code" (⌘⌥L) was a silent no-op ("No lines were
// changed"). Overriding `isExistingFormatterOverrideable` to true makes LSP4IJ
// route formatting to the Vader Language Server's `textDocument/formatting`.
private class VaderFormattingFeature : LSPFormattingFeature() {
    override fun isExistingFormatterOverrideable(file: PsiFile): Boolean = true
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
