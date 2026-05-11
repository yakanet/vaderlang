package dev.vaderlang.intellij

import com.intellij.execution.configurations.GeneralCommandLine
import com.intellij.openapi.project.Project
import com.intellij.openapi.vfs.VirtualFile
import com.intellij.platform.lsp.api.LspServerSupportProvider
import com.intellij.platform.lsp.api.ProjectWideLspServerDescriptor

// Wires the IntelliJ Platform LSP API onto the Vader CLI. The actual
// server is a Vader program (`vader/lsp/main_entry.vader`) run by the
// `vader lsp` subcommand — this class only handles the JetBrains side
// of the integration.
//
// The LSP API ships only in IDEs that bundle the `com.intellij.modules.lsp`
// module (Ultimate, RustRover, GoLand, …). The optional <depends> entry
// in plugin.xml keeps the plugin loadable in Community editions — those
// users still get TextMate-driven highlighting, just no semantic tokens.
internal class VaderLspServerSupport : LspServerSupportProvider {
    override fun fileOpened(
        project: Project,
        file: VirtualFile,
        serverStarter: LspServerSupportProvider.LspServerStarter,
    ) {
        if (file.extension == "vader") {
            serverStarter.ensureServerStarted(VaderLspServerDescriptor(project))
        }
    }
}

private class VaderLspServerDescriptor(project: Project) :
    ProjectWideLspServerDescriptor(project, "Vader") {

    override fun isSupportedFile(file: VirtualFile): Boolean = file.extension == "vader"

    // The descriptor mirrors the VSCode extension's default: spawn `vader lsp`
    // from PATH. Users who installed the binary outside their PATH need to
    // either symlink it or arrange their IDE launcher to inherit the right
    // environment — same constraint as the VSCode side.
    override fun createCommandLine(): GeneralCommandLine =
        GeneralCommandLine("vader", "lsp")
}
