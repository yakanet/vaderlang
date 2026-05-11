package dev.vaderlang.intellij

import com.intellij.openapi.application.ApplicationManager
import com.intellij.openapi.components.PersistentStateComponent
import com.intellij.openapi.components.Service
import com.intellij.openapi.components.State
import com.intellij.openapi.components.Storage

// Application-level settings for the Vader plugin. Today's only knob is
// the path to the `vader` CLI binary the LSP support uses to spawn
// `vader lsp`. Stored in the IDE's per-user config dir as `vader.xml`
// so the value survives IDE restarts and applies across every project.
//
// The `@Service(Level.APP)` annotation auto-registers the singleton —
// no explicit `<applicationService>` entry in plugin.xml is required on
// recent IntelliJ Platform builds (242+ shipped with this plugin).
@State(name = "VaderSettings", storages = [Storage("vader.xml")])
@Service(Service.Level.APP)
internal class VaderSettings : PersistentStateComponent<VaderSettings.State> {

    class State {
        // Absolute path to a `vader` executable. Empty value means
        // "spawn `vader lsp` from $PATH" — same default as the VSCode
        // extension, so the plugin works out of the box for users who
        // have `vader` symlinked / installed system-wide.
        var lspPath: String = ""
    }

    private var stateRef = State()

    override fun getState(): State = stateRef
    override fun loadState(loaded: State) { stateRef = loaded }

    var lspPath: String
        get() = stateRef.lspPath
        set(value) { stateRef.lspPath = value }

    companion object {
        fun getInstance(): VaderSettings =
            ApplicationManager.getApplication().getService(VaderSettings::class.java)
    }
}
