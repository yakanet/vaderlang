package dev.vaderlang.intellij

import com.intellij.openapi.fileChooser.FileChooserDescriptorFactory
import com.intellij.openapi.options.Configurable
import com.intellij.openapi.ui.TextFieldWithBrowseButton
import com.intellij.ui.components.JBLabel
import com.intellij.util.ui.FormBuilder
import com.intellij.util.ui.UIUtil
import javax.swing.JComponent
import javax.swing.JPanel

// Settings → Tools → Vader. Mirrors the VSCode extension's
// `vader.lsp.path` knob : a single optional override for the binary
// the LSP support spawns. Empty value falls back to `vader` from PATH.
internal class VaderConfigurable : Configurable {

    private var pathField: TextFieldWithBrowseButton? = null
    private var panel: JPanel? = null

    override fun getDisplayName(): String = "Vader"

    override fun createComponent(): JComponent {
        val field = TextFieldWithBrowseButton()
        field.addBrowseFolderListener(
            "Select Vader Executable",
            "Path to the vader CLI binary used to spawn the language server.",
            null,
            FileChooserDescriptorFactory.createSingleFileNoJarsDescriptor(),
        )
        pathField = field

        val hint = JBLabel(
            "<html>Leave empty to spawn <code>vader lsp</code> from <code>\$PATH</code> " +
                "(default behaviour, matches the VSCode extension).</html>",
        )
        hint.foreground = UIUtil.getContextHelpForeground()

        // `FormBuilder.addLabeledComponent` renders the label as plain
        // text — the `<html>` prefix is what flips it into Swing's
        // HTML mode so the `<code>` styling matches the hint below.
        val built = FormBuilder.createFormBuilder()
            .addLabeledComponent(
                "<html>Path to <code>vader</code> executable:</html>",
                field, 1, false,
            )
            .addComponentToRightColumn(hint, 1)
            .addComponentFillVertically(JPanel(), 0)
            .panel
        panel = built
        reset()
        return built
    }

    override fun isModified(): Boolean {
        val current = pathField?.text ?: ""
        return current.trim() != VaderSettings.getInstance().lspPath
    }

    override fun apply() {
        VaderSettings.getInstance().lspPath = (pathField?.text ?: "").trim()
    }

    override fun reset() {
        pathField?.text = VaderSettings.getInstance().lspPath
    }

    override fun disposeUIResources() {
        pathField = null
        panel = null
    }
}
