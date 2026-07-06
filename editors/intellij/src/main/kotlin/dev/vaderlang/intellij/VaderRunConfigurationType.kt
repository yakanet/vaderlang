package dev.vaderlang.intellij

import com.intellij.execution.Executor
import com.intellij.execution.configurations.CommandLineState
import com.intellij.execution.configurations.ConfigurationFactory
import com.intellij.execution.configurations.ConfigurationType
import com.intellij.execution.configurations.ConfigurationTypeBase
import com.intellij.execution.configurations.GeneralCommandLine
import com.intellij.execution.configurations.RunConfiguration
import com.intellij.execution.configurations.RunConfigurationOptions
import com.intellij.execution.configurations.RunProfileState
import com.intellij.execution.executors.DefaultRunExecutor
import com.intellij.execution.process.ProcessHandler
import com.intellij.execution.process.ProcessHandlerFactory
import com.intellij.execution.process.ProcessTerminatedListener
import com.intellij.execution.runners.ExecutionEnvironment
import com.intellij.icons.AllIcons
import com.intellij.openapi.project.Project
import com.intellij.openapi.util.NotNullLazyValue
import com.redhat.devtools.lsp4ij.dap.DebugMode
import com.redhat.devtools.lsp4ij.dap.configurations.DAPRunConfiguration
import com.redhat.devtools.lsp4ij.dap.configurations.DAPRunConfigurationOptions
import com.redhat.devtools.lsp4ij.templates.ServerMappingSettings

// A native "Vader" run/debug configuration : pick a `.vader` file, then Run OR
// Debug it (breakpoints, stepping) — one config, both buttons. It's a thin
// preset over LSP4IJ's DAP run configuration: we extend DAPRunConfiguration and
// pin it to our registered "Vader Debug Adapter" (spawns `vader dap`), so we
// reuse LSP4IJ's whole tested Run+Debug machinery instead of reimplementing it.
//
// Compiles + packages against LSP4IJ 0.20.1 here; the Run/Debug behaviour is a
// manual in-IDE check (runIde).
internal class VaderRunConfigurationType : ConfigurationTypeBase(
    "VaderRunConfiguration",
    "Vader",
    "Run or debug a Vader program",
    NotNullLazyValue.createValue { AllIcons.Actions.Execute },
) {
    init { addFactory(VaderConfigurationFactory(this)) }
}

internal class VaderConfigurationFactory(type: ConfigurationType) : ConfigurationFactory(type) {
    override fun getId(): String = "Vader"

    override fun createTemplateConfiguration(project: Project): RunConfiguration {
        val config = VaderRunConfiguration(project, this, "Vader")
        // Pin to our registered debugAdapterServer (see VaderDebugAdapterServerFactory)
        // + map *.vader for breakpoints. The user only picks the file to run.
        //
        // NOTE: LSP4IJ's DAP API is version-sensitive (ServerMappingSettings /
        // DAPRunConfiguration signatures drift across releases), so the plugin
        // MUST be built against the LSP4IJ version actually installed — a mismatch
        // throws NoSuchMethodError here at RunManager init. See build.gradle.kts
        // (pinned to LSP4IJ 0.20.1).
        config.serverId = SERVER_ID
        config.serverName = SERVER_NAME
        config.debugMode = DebugMode.LAUNCH
        config.serverMappings = listOf(
            ServerMappingSettings.createFileNamePatternsMappingSettings(listOf("*.vader"), "vader"),
        )
        return config
    }

    // Options are DAP's — VaderRunConfiguration is just a preset DAP config.
    override fun getOptionsClass(): Class<out RunConfigurationOptions> =
        DAPRunConfigurationOptions::class.java
}

// A DAP run configuration pinned to the Vader debug adapter, split by executor:
//
//   • Debug → the inherited DAPRunConfiguration path (DAP client, breakpoints,
//     stepping, variables) driving `vader dap`.
//   • Run   → a plain `vader run <file>` process with a colored console, NO
//     debugger — same VM path as the CLI.
//
// LSP4IJ ships a single ProgramRunner (DAPDebugRunner) that ALWAYS opens an
// XDebugSession, and it claims every executor its config's `canRun` accepts —
// so out of the box pressing Run also launches a debug session. We fix that by
// declining the Run executor in `canRun` (DAPDebugRunner then yields Run to the
// platform's default run runner) and returning a plain CommandLineState from
// `getState` for that executor.
internal class VaderRunConfiguration(
    project: Project,
    factory: ConfigurationFactory,
    name: String,
) : DAPRunConfiguration(project, factory, name) {

    // Run → plain `vader run`; every other executor (Debug) → the DAP path.
    override fun getState(executor: Executor, environment: ExecutionEnvironment): RunProfileState? {
        if (executor.id != DefaultRunExecutor.EXECUTOR_ID) return super.getState(executor, environment)
        return object : CommandLineState(environment) {
            override fun startProcess(): ProcessHandler {
                // Binary path from the shared plugin settings (Settings → Tools →
                // Vader), falling back to `vader` on $PATH — same source the DAP/LSP
                // factories use. Run from the project root so `std/*` imports resolve.
                val configured = VaderSettings.getInstance().lspPath.trim()
                val binary = if (configured.isNotEmpty()) configured else "vader"
                val commandLine = GeneralCommandLine(binary, "run", file)
                environment.project.basePath?.let { commandLine.withWorkDirectory(it) }
                val handler = ProcessHandlerFactory.getInstance().createColoredProcessHandler(commandLine)
                ProcessTerminatedListener.attach(handler)
                return handler
            }
        }
    }

    // Hand the Run executor to the platform's default run runner (→ getState
    // above), so only Debug flows through LSP4IJ's always-debugging DAPDebugRunner.
    override fun canRun(executorId: String): Boolean =
        executorId != DefaultRunExecutor.EXECUTOR_ID && super.canRun(executorId)
}

internal const val SERVER_ID = "dev.vaderlang.vader-dap"
internal const val SERVER_NAME = "Vader Debug Adapter"
