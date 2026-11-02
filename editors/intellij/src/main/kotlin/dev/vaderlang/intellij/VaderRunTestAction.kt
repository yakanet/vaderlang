package dev.vaderlang.intellij

import com.intellij.execution.ProgramRunnerUtil
import com.intellij.execution.RunManager
import com.intellij.execution.configurations.ConfigurationTypeUtil
import com.intellij.execution.executors.DefaultRunExecutor
import com.intellij.openapi.actionSystem.ActionUpdateThread
import com.intellij.openapi.actionSystem.AnActionEvent
import com.redhat.devtools.lsp4ij.commands.LSPCommand
import com.redhat.devtools.lsp4ij.commands.LSPCommandAction
import java.io.File
import java.net.URI

// The command of the server's "run test" code lenses (`vader.runTest`): runs a
// "Vader Test" configuration, whose console shows the test tree. LSP4IJ hands a
// lens command the server does not execute to the action registered under its
// name (`plugin.xml`). The arguments are the document URI, the folder to run
// from, then the test name, absent for the whole module.
//
// The configuration is a temporary one, kept in the run list so that it reruns
// from the toolbar. A lens run again reuses the temporary configuration of its
// file and test: a name alone would take another file's test of the same name.
internal class VaderRunTestAction : LSPCommandAction() {
    override fun commandPerformed(command: LSPCommand, e: AnActionEvent) {
        val project = e.project ?: return
        val uri = command.getArgumentAt(0, String::class.java) ?: return
        val folder = command.getArgumentAt(1, String::class.java) ?: return
        // `getArgumentAt` throws on the index one past the last.
        val test = command.takeIf { it.arguments.size > 2 }?.getArgumentAt(2, String::class.java).orEmpty()
        val file = File(URI(uri)).path
        val runManager = RunManager.getInstance(project)
        val type = ConfigurationTypeUtil.findConfigurationType(VaderTestConfigurationType::class.java)
        val settings = runManager.getConfigurationSettingsList(type).firstOrNull {
            val configuration = it.configuration as VaderTestRunConfiguration
            it.isTemporary && configuration.file == file && configuration.test == test
        } ?: runManager.createConfiguration(test.ifEmpty { File(file).name }, type.configurationFactories[0]).also {
            val configuration = it.configuration as VaderTestRunConfiguration
            configuration.file = file
            configuration.test = test
            runManager.setTemporaryConfiguration(it)
        }
        (settings.configuration as VaderTestRunConfiguration).folder = folder
        runManager.selectedConfiguration = settings
        ProgramRunnerUtil.executeConfiguration(settings, DefaultRunExecutor.getRunExecutorInstance())
    }

    // Running a configuration opens its console: UI, on the event dispatch thread.
    override fun getCommandPerformedThread(): ActionUpdateThread = ActionUpdateThread.EDT
}
