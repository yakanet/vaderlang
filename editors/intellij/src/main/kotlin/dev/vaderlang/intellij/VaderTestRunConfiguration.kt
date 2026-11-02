package dev.vaderlang.intellij

import com.intellij.execution.Executor
import com.intellij.execution.configurations.CommandLineState
import com.intellij.execution.configurations.ConfigurationFactory
import com.intellij.execution.configurations.ConfigurationType
import com.intellij.execution.configurations.ConfigurationTypeBase
import com.intellij.execution.configurations.LocatableConfigurationBase
import com.intellij.execution.configurations.LocatableRunConfigurationOptions
import com.intellij.execution.configurations.RunConfiguration
import com.intellij.execution.configurations.RunProfileState
import com.intellij.execution.configurations.RuntimeConfigurationError
import com.intellij.execution.process.ProcessHandler
import com.intellij.execution.runners.ExecutionEnvironment
import com.intellij.execution.testframework.AbstractTestProxy
import com.intellij.execution.testframework.TestConsoleProperties
import com.intellij.execution.testframework.actions.AbstractRerunFailedTestsAction
import com.intellij.execution.testframework.sm.FileUrlProvider
import com.intellij.execution.testframework.sm.SMCustomMessagesParsing
import com.intellij.execution.testframework.sm.SMTestRunnerConnectionUtil
import com.intellij.execution.testframework.sm.runner.OutputToGeneralTestEventsConverter
import com.intellij.execution.testframework.sm.runner.SMTRunnerConsoleProperties
import com.intellij.execution.testframework.sm.runner.SMTestLocator
import com.intellij.execution.testframework.sm.runner.SMTestProxy
import com.intellij.execution.ui.ConsoleView
import com.intellij.icons.AllIcons
import com.intellij.openapi.fileChooser.FileChooserDescriptorFactory
import com.intellij.openapi.options.SettingsEditor
import com.intellij.openapi.project.Project
import com.intellij.openapi.ui.TextFieldWithBrowseButton
import com.intellij.openapi.util.NotNullLazyValue
import com.intellij.ui.components.JBTextField
import com.intellij.util.ui.FormBuilder
import java.io.File
import java.io.IOException
import javax.swing.JComponent
import javax.swing.JPanel

// A "Vader Test" run configuration: `vader test --reporter=json` on a file, its
// report read into the IDE's test console (tree, durations, each test's output,
// navigation to the test, rerun, rerun of the failed tests). The "run test"
// code lenses create one (`VaderRunTestAction`).
internal class VaderTestConfigurationType : ConfigurationTypeBase(
    "VaderTestRunConfiguration",
    "Vader Test",
    "Run the tests of a Vader module in the test console",
    NotNullLazyValue.createValue { AllIcons.RunConfigurations.TestState.Run },
) {
    init { addFactory(VaderTestConfigurationFactory(this)) }
}

internal class VaderTestConfigurationFactory(type: ConfigurationType) : ConfigurationFactory(type) {
    override fun getId(): String = "VaderTest"

    override fun createTemplateConfiguration(project: Project): RunConfiguration =
        VaderTestRunConfiguration(project, this, "Vader Test")

    override fun getOptionsClass(): Class<VaderTestOptions> = VaderTestOptions::class.java
}

internal class VaderTestOptions : LocatableRunConfigurationOptions() {
    // The file whose module runs: `vader test` takes its whole folder module.
    var file by string("")
    // Where `vader test` runs: its project, whose `vader.json` it reads.
    var folder by string("")
    // `--filter`: the test to run, empty for every test of the module.
    var test by string("")
}

internal class VaderTestRunConfiguration(
    project: Project,
    factory: ConfigurationFactory,
    name: String,
) : LocatableConfigurationBase<VaderTestOptions>(project, factory, name) {

    override fun getOptions(): VaderTestOptions = super.getOptions() as VaderTestOptions

    var file: String
        get() = options.file.orEmpty()
        set(value) { options.file = value }

    var folder: String
        get() = options.folder.orEmpty()
        set(value) { options.folder = value }

    var test: String
        get() = options.test.orEmpty()
        set(value) { options.test = value }

    // The filters a run of the configuration passes: its test, if it has one.
    val filters: List<String>
        get() = listOfNotNull(test.ifBlank { null })

    override fun checkConfiguration() {
        if (file.isBlank()) throw RuntimeConfigurationError("No Vader file to test")
    }

    override fun getConfigurationEditor(): SettingsEditor<VaderTestRunConfiguration> = VaderTestSettingsEditor()

    override fun getState(executor: Executor, environment: ExecutionEnvironment): RunProfileState =
        VaderTestState(environment, this, filters)
}

// `vader test` on the file of `configuration`, kept to the tests one of
// `filters` keeps when there are any.
private class VaderTestState(
    environment: ExecutionEnvironment,
    private val configuration: VaderTestRunConfiguration,
    private val filters: List<String>,
) : CommandLineState(environment) {

    override fun startProcess(): ProcessHandler {
        val arguments = buildList {
            add("test")
            add("--reporter=json")
            if (filters.isNotEmpty()) {
                add("--filter")
                add("-")
            }
            add(configuration.file)
        }
        val handler = startVaderProcess(arguments, workDirectory())
        // The filters go through stdin, where a command line has a length limit.
        try {
            handler.processInput?.writer(Charsets.UTF_8)?.use { it.write(filters.joinToString("\n")) }
        } catch (_: IOException) {
            // The process is gone: its exit says why.
        }
        return handler
    }

    // The configured folder, else the file's project, else the file's folder.
    private fun workDirectory(): String =
        configuration.folder.ifBlank { vaderProjectOf(configuration.file) ?: File(configuration.file).parent }

    // The test console: the platform attaches the converter when the process starts.
    override fun createConsole(executor: Executor): ConsoleView =
        SMTestRunnerConnectionUtil.createConsole(TEST_FRAMEWORK, VaderTestConsoleProperties(configuration, executor))
}

private class VaderTestConsoleProperties(configuration: RunConfiguration, executor: Executor) :
    SMTRunnerConsoleProperties(configuration, TEST_FRAMEWORK, executor), SMCustomMessagesParsing {

    override fun createTestEventsConverter(
        testFrameworkName: String,
        consoleProperties: TestConsoleProperties,
    ): OutputToGeneralTestEventsConverter = VaderTestEventsConverter(testFrameworkName, consoleProperties)

    // The converter's location hints are `file://<path>:<line>` URLs.
    override fun getTestLocator(): SMTestLocator = FileUrlProvider.INSTANCE

    override fun createRerunFailedTestsAction(consoleView: ConsoleView): AbstractRerunFailedTestsAction =
        VaderRerunFailedTestsAction(consoleView, this)
}

// "Rerun Failed Tests": the configuration again, kept to the failed tests by the
// filter each one's `metainfo` holds. A failed test without one is a module that
// did not compile, which only a run of the whole configuration shows again.
private class VaderRerunFailedTestsAction(console: ConsoleView, properties: TestConsoleProperties) :
    AbstractRerunFailedTestsAction(console) {

    init { init(properties) }

    override fun getRunProfile(environment: ExecutionEnvironment): MyRunProfile? {
        val configuration = myConsoleProperties.configuration as? VaderTestRunConfiguration ?: return null
        val filters = failedFilters(getFailedTests(configuration.project)) ?: configuration.filters
        return object : MyRunProfile(configuration) {
            override fun getState(executor: Executor, environment: ExecutionEnvironment): RunProfileState =
                VaderTestState(environment, configuration, filters)
        }
    }
}

// The filters of the failed `tests`, null when one has none. The failures hold
// the suites of the failed tests too, which have none either.
private fun failedFilters(tests: List<AbstractTestProxy>): List<String>? {
    val filters = mutableListOf<String>()
    for (test in tests) {
        if (!test.isLeaf) continue
        filters.add((test as? SMTestProxy)?.metainfo ?: return null)
    }
    return filters
}

private class VaderTestSettingsEditor : SettingsEditor<VaderTestRunConfiguration>() {
    private val file = TextFieldWithBrowseButton()
    private val folder = TextFieldWithBrowseButton()
    private val test = JBTextField()

    init {
        file.addBrowseFolderListener(
            "Select Vader File", null, null,
            FileChooserDescriptorFactory.createSingleFileDescriptor("vader"),
        )
        folder.addBrowseFolderListener(
            "Select Working Directory", null, null,
            FileChooserDescriptorFactory.createSingleFolderDescriptor(),
        )
    }

    override fun createEditor(): JComponent = FormBuilder.createFormBuilder()
        .addLabeledComponent("File:", file)
        .addLabeledComponent("Working directory:", folder)
        .addLabeledComponent("Test (--filter):", test)
        .addComponentFillVertically(JPanel(), 0)
        .panel

    override fun resetEditorFrom(configuration: VaderTestRunConfiguration) {
        file.text = configuration.file
        folder.text = configuration.folder
        test.text = configuration.test
    }

    override fun applyEditorTo(configuration: VaderTestRunConfiguration) {
        configuration.file = file.text.trim()
        configuration.folder = folder.text.trim()
        configuration.test = test.text.trim()
    }
}

private const val TEST_FRAMEWORK = "Vader"
