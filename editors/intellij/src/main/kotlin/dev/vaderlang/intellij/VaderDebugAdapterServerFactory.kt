package dev.vaderlang.intellij

import com.intellij.execution.ExecutionException
import com.intellij.execution.configurations.RunConfigurationOptions
import com.intellij.execution.process.ProcessHandler
import com.intellij.execution.runners.ExecutionEnvironment
import com.intellij.openapi.fileTypes.FileType
import com.intellij.openapi.project.Project
import com.intellij.openapi.vfs.VirtualFile
import com.redhat.devtools.lsp4ij.dap.DebugMode
import com.redhat.devtools.lsp4ij.dap.client.LaunchUtils
import com.redhat.devtools.lsp4ij.dap.configurations.options.FileOptionConfigurable
import com.redhat.devtools.lsp4ij.dap.configurations.options.WorkingDirectoryConfigurable
import com.redhat.devtools.lsp4ij.dap.definitions.DebugAdapterServerDefinition
import com.redhat.devtools.lsp4ij.dap.descriptors.DebugAdapterDescriptor
import com.redhat.devtools.lsp4ij.dap.descriptors.DebugAdapterDescriptorFactory
import com.redhat.devtools.lsp4ij.dap.descriptors.ServerReadyConfig

// Wires the `vader dap` Debug Adapter into LSP4IJ, mirroring
// `VaderLanguageServerFactory` (the LSP side). LSP4IJ owns the DAP client
// plumbing, breakpoints, stepping UI, variables view — we only tell it how to
// spawn the adapter process, and hand it the `launch` request payload.
//
// UX note (differs from VSCode): LSP4IJ exposes DAP through its generic
// "Debug Adapter Protocol" run/debug configuration. The user creates one,
// picks "Vader" as the server, and points it at a `.vader` file — there's no
// automatic F5 gutter action like the VSCode extension.
//
// Compiles + packages against LSP4IJ 0.20.1 (compileKotlin + buildPlugin green
// here). A live debug session hasn't been driven inside a running IDE — do a
// `./gradlew runIde` smoke test (set a breakpoint in a `.vader` file, run a
// "Debug Adapter Protocol" config selecting "Vader Debug Adapter") to confirm
// end to end.
internal class VaderDebugAdapterServerFactory : DebugAdapterDescriptorFactory() {
    override fun createDebugAdapterDescriptor(
        options: RunConfigurationOptions,
        environment: ExecutionEnvironment,
    ): DebugAdapterDescriptor = VaderDebugAdapterDescriptor(options, environment, serverDefinition)

    // Which files can carry a DAP breakpoint for this server — the equivalent of
    // the VSCode extension's `contributes.breakpoints: [{ language: "vader" }]`.
    // LSP4IJ's `DAPBreakpointTypeBase.canPutAt` calls this when placing a gutter
    // breakpoint. The inherited default delegates to the server definition's
    // `serverMappings`, but an EP-registered `debugAdapterServer` has NO mapping
    // attributes (see plugin.xml) so those are empty → every `.vader` file reads
    // as non-debuggable and breakpoints are silently never sent. Answer directly.
    override fun isDebuggableFile(file: VirtualFile, project: Project): Boolean =
        isVaderFile(file)
}

private class VaderDebugAdapterDescriptor(
    options: RunConfigurationOptions,
    environment: ExecutionEnvironment,
    serverDefinition: DebugAdapterServerDefinition?,
) : DebugAdapterDescriptor(options, environment, serverDefinition) {

    // Spawn `vader dap` over stdio. Binary path comes from the shared plugin
    // settings (Settings → Tools → Vader), falling back to `vader` on $PATH —
    // same source the LSP factory uses. The working directory is the debuggee
    // file's dir so the compiler's stdlib probe resolves `std/*` imports (the
    // native binary resolves stdlib relative to itself, but cwd is the safe
    // default that mirrors `vader run`).
    override fun startServer(): ProcessHandler {
        val configured = VaderSettings.getInstance().lspPath.trim()
        val binary = if (configured.isNotEmpty()) configured else "vader"
        val commandLine = createStartServerCommandLine("$binary dap")
        return startServer(commandLine)
    }

    // The DAP `launch` request arguments. `program` is the file selected in the
    // run configuration ; `vader dap`'s `cmd_dap` compiles + runs it in the VM.
    override fun getDapParameters(): Map<String, Any> {
        // language=JSON
        val launchJson = """
            {
              "type": "vader",
              "name": "Launch Vader file",
              "request": "launch",
              "program": "${'$'}{file}",
              "cwd": "${'$'}{workspaceFolder}"
            }
        """.trimIndent()
        val file = (options as FileOptionConfigurable).file
        val workspaceFolder = (options as WorkingDirectoryConfigurable).workingDirectory
        val context = LaunchUtils.LaunchContext(file, workspaceFolder)
        return LaunchUtils.getDapParameters(launchJson, context)
    }

    // `vader dap` talks DAP directly over the process stdin/stdout. LSP4IJ's
    // `DAPDebugProcess.getTransportStreams` picks the socket transport only when
    // a port is resolved; the `ServerReadyConfig(int)` (connect-timeout only,
    // no port / address / trace pattern) leaves the port null, so LSP4IJ falls
    // back to `DefaultTransportStreams(process stdin, stdout)` — i.e. stdio.
    // `0` = don't wait, the process is ready to talk as soon as it's spawned.
    override fun getServerReadyConfig(debugMode: DebugMode): ServerReadyConfig =
        ServerReadyConfig(0)

    override fun getFileType(): FileType? = null

    // Session-side counterpart of the factory override above: LSP4IJ's
    // `DAPBreakpointHandlerBase` calls this per breakpoint to decide whether to
    // send it to the running adapter. Without it the default delegates to the
    // (empty) server-definition mappings and no breakpoint reaches `vader dap`.
    override fun isDebuggableFile(file: VirtualFile, project: Project): Boolean =
        isVaderFile(file)
}

// A `.vader` source file — the only thing the Vader debug adapter can debug.
private fun isVaderFile(file: VirtualFile): Boolean = file.name.endsWith(".vader")
