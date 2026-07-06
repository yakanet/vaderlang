package dev.vaderlang.intellij

import com.intellij.execution.configurations.ConfigurationFactory
import com.intellij.execution.configurations.ConfigurationType
import com.intellij.execution.configurations.ConfigurationTypeBase
import com.intellij.execution.configurations.RunConfiguration
import com.intellij.execution.configurations.RunConfigurationOptions
import com.intellij.icons.AllIcons
import com.intellij.openapi.project.Project
import com.intellij.openapi.util.NotNullLazyValue
import com.redhat.devtools.lsp4ij.dap.DebugMode
import com.redhat.devtools.lsp4ij.dap.configurations.DAPRunConfiguration
import com.redhat.devtools.lsp4ij.dap.configurations.DAPRunConfigurationOptions
import com.redhat.devtools.lsp4ij.launching.ServerMappingSettings

// A native "Vader" run/debug configuration : pick a `.vader` file, then Run OR
// Debug it (breakpoints, stepping) — one config, both buttons. It's a thin
// preset over LSP4IJ's DAP run configuration: we extend DAPRunConfiguration and
// pin it to our registered "Vader Debug Adapter" (spawns `vader dap`), so we
// reuse LSP4IJ's whole tested Run+Debug machinery instead of reimplementing it.
//
// Compiles + packages against LSP4IJ 0.13.0 here; the Run/Debug behaviour is a
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

// A DAP run configuration pinned to the Vader debug adapter. Everything (the
// Run/Debug launch, the DAP client, breakpoints, variables) comes from
// DAPRunConfiguration; we only supply the type identity + presets.
internal class VaderRunConfiguration(
    project: Project,
    factory: ConfigurationFactory,
    name: String,
) : DAPRunConfiguration(project, factory, name)

internal const val SERVER_ID = "dev.vaderlang.vader-dap"
internal const val SERVER_NAME = "Vader Debug Adapter"
