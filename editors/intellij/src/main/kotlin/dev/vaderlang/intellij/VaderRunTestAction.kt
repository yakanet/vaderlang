package dev.vaderlang.intellij

import com.intellij.execution.RunContentExecutor
import com.intellij.execution.configurations.GeneralCommandLine
import com.intellij.execution.process.ProcessHandlerFactory
import com.intellij.execution.process.ProcessTerminatedListener
import com.intellij.openapi.actionSystem.ActionUpdateThread
import com.intellij.openapi.actionSystem.AnActionEvent
import com.redhat.devtools.lsp4ij.commands.LSPCommand
import com.redhat.devtools.lsp4ij.commands.LSPCommandAction
import java.io.File
import java.net.URI

// The command of the server's "run test" code lenses (`vader.runTest`), in a Run
// console. LSP4IJ hands a lens command the server does not execute to the action
// registered under its name (`plugin.xml`). The arguments are the document URI,
// the folder to run from, then the test name, absent for the whole module.
internal class VaderRunTestAction : LSPCommandAction() {
    override fun commandPerformed(command: LSPCommand, e: AnActionEvent) {
        val project = e.project ?: return
        val uri = command.getArgumentAt(0, String::class.java) ?: return
        val folder = command.getArgumentAt(1, String::class.java) ?: return
        // `getArgumentAt` throws on the index one past the last.
        val name = command.takeIf { it.arguments.size > 2 }?.getArgumentAt(2, String::class.java)
        val file = File(URI(uri)).path
        val filter = name?.let { listOf("--filter", it) }.orEmpty()
        val commandLine = GeneralCommandLine(listOf(vaderBinary(), "test") + filter + file)
            .withWorkDirectory(folder)
        val handler = ProcessHandlerFactory.getInstance().createColoredProcessHandler(commandLine)
        ProcessTerminatedListener.attach(handler)
        RunContentExecutor(project, handler)
            .withTitle(name ?: File(file).name)
            .withActivateToolWindow(true)
            .run()
    }

    // The console is UI: it is built on the event dispatch thread.
    override fun getCommandPerformedThread(): ActionUpdateThread = ActionUpdateThread.EDT
}
