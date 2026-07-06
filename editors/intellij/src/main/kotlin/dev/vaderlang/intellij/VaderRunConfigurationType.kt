package dev.vaderlang.intellij

import com.intellij.execution.Executor
import com.intellij.execution.configurations.CommandLineState
import com.intellij.execution.configurations.ConfigurationFactory
import com.intellij.execution.configurations.ConfigurationType
import com.intellij.execution.configurations.ConfigurationTypeBase
import com.intellij.execution.configurations.GeneralCommandLine
import com.intellij.execution.configurations.RunConfiguration
import com.intellij.execution.configurations.RunConfigurationBase
import com.intellij.execution.configurations.RunConfigurationOptions
import com.intellij.execution.configurations.RunProfileState
import com.intellij.execution.process.ProcessHandler
import com.intellij.execution.process.ProcessHandlerFactory
import com.intellij.execution.process.ProcessTerminatedListener
import com.intellij.execution.runners.ExecutionEnvironment
import com.intellij.icons.AllIcons
import com.intellij.openapi.fileChooser.FileChooserDescriptorFactory
import com.intellij.openapi.options.SettingsEditor
import com.intellij.openapi.project.Project
import com.intellij.openapi.util.NotNullLazyValue
import com.intellij.openapi.ui.TextFieldWithBrowseButton
import com.intellij.util.ui.FormBuilder
import javax.swing.JComponent

// A native "Vader" run configuration : pick a `.vader` file and Run it via
// `vader run` (the same VM path as the CLI). Appears under Add New
// Configuration → Vader. Step-debugging with breakpoints is the separate
// "Debug Adapter Protocol" configuration (LSP4IJ) driving `vader dap`.
//
// Compiles + packages against the 2024.2 platform (compileKotlin/buildPlugin
// green here); the Run button behaviour is a manual in-IDE check.
internal class VaderRunConfigurationType : ConfigurationTypeBase(
    "VaderRunConfiguration",
    "Vader",
    "Run a Vader program with `vader run`",
    NotNullLazyValue.createValue { AllIcons.Actions.Execute },
) {
    init { addFactory(VaderConfigurationFactory(this)) }
}

internal class VaderConfigurationFactory(type: ConfigurationType) : ConfigurationFactory(type) {
    override fun getId(): String = "Vader"

    override fun createTemplateConfiguration(project: Project): RunConfiguration =
        VaderRunConfiguration(project, this, "Vader")

    override fun getOptionsClass(): Class<out RunConfigurationOptions> =
        VaderRunConfigurationOptions::class.java
}

// Persisted state — the target `.vader` file (serialized to the `.run/*.xml`).
internal class VaderRunConfigurationOptions : RunConfigurationOptions() {
    private val programPathProp = string("").provideDelegate(this, "programPath")
    fun getProgramPath(): String = programPathProp.getValue(this) ?: ""
    fun setProgramPath(value: String) = programPathProp.setValue(this, value)
}

internal class VaderRunConfiguration(
    project: Project,
    factory: ConfigurationFactory,
    name: String,
) : RunConfigurationBase<VaderRunConfigurationOptions>(project, factory, name) {

    public override fun getOptions(): VaderRunConfigurationOptions =
        super.getOptions() as VaderRunConfigurationOptions

    fun getProgramPath(): String = options.getProgramPath()
    fun setProgramPath(value: String) = options.setProgramPath(value)

    override fun getConfigurationEditor(): SettingsEditor<out RunConfiguration> =
        VaderSettingsEditor()

    override fun getState(executor: Executor, environment: ExecutionEnvironment): RunProfileState =
        object : CommandLineState(environment) {
            override fun startProcess(): ProcessHandler {
                // Binary path from the shared plugin settings (Settings → Tools →
                // Vader), falling back to `vader` on $PATH — same as the LSP/DAP
                // factories. Run from the project root so `std/*` imports resolve.
                val configured = VaderSettings.getInstance().lspPath.trim()
                val binary = if (configured.isNotEmpty()) configured else "vader"
                val commandLine = GeneralCommandLine(binary, "run", getProgramPath())
                environment.project.basePath?.let { commandLine.withWorkDirectory(it) }
                val handler = ProcessHandlerFactory.getInstance().createColoredProcessHandler(commandLine)
                ProcessTerminatedListener.attach(handler)
                return handler
            }
        }
}

internal class VaderSettingsEditor : SettingsEditor<VaderRunConfiguration>() {
    private val fileField = TextFieldWithBrowseButton()

    init {
        fileField.addBrowseFolderListener(
            "Select Vader File",
            "Pick the .vader file to run",
            null,
            FileChooserDescriptorFactory.createSingleFileNoJarsDescriptor(),
        )
    }

    private val panel: JComponent = FormBuilder.createFormBuilder()
        .addLabeledComponent("Vader file:", fileField)
        .panel

    override fun createEditor(): JComponent = panel
    override fun resetEditorFrom(s: VaderRunConfiguration) { fileField.text = s.getProgramPath() }
    override fun applyEditorTo(s: VaderRunConfiguration) { s.setProgramPath(fileField.text) }
}
