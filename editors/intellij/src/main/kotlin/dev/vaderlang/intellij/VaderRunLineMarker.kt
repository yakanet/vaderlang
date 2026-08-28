package dev.vaderlang.intellij

import com.intellij.codeInsight.daemon.LineMarkerInfo
import com.intellij.codeInsight.daemon.LineMarkerProviderDescriptor
import com.intellij.execution.actions.ConfigurationContext
import com.intellij.execution.actions.LazyRunConfigurationProducer
import com.intellij.execution.configurations.ConfigurationFactory
import com.intellij.execution.configurations.ConfigurationTypeUtil
import com.intellij.execution.lineMarker.ExecutorAction
import com.intellij.icons.AllIcons
import com.intellij.openapi.actionSystem.ActionGroup
import com.intellij.openapi.actionSystem.DefaultActionGroup
import com.intellij.openapi.editor.markup.GutterIconRenderer
import com.intellij.openapi.util.Ref
import com.intellij.openapi.util.TextRange
import com.intellij.psi.PsiElement

// A top-level `main ::` in a .vader file gets a green ▶ gutter icon, like
// Java/Kotlin `main`. Clicking it Runs (or Debugs) the file through the Vader
// run configuration (VaderRunConfigurationProducer builds it).
//
// WAS a `RunLineMarkerContributor` keyed on `element.text == "main"`, and never
// fired — measured, over three rounds. A `.vader` file has no PSI Language
// (`plugin.xml`), and its tree does NOT give one leaf per identifier, so no
// element ever has the text `main`. Registering for `TEXT` as well as
// `textmate` did not change that, which is what isolated the cause: the sibling
// `@target` marker fires under exactly that registration, and it differs only
// in reading the file TEXT and carrying an explicit `TextRange`.
//
// So this uses the same recipe. The contributor form cannot: it yields one
// `Info` per element with no say over the line, which under a coarse tree puts
// every icon in the wrong place — the reason it is a provider now.
internal class VaderRunLineMarkerProvider : LineMarkerProviderDescriptor() {
    override fun getName(): String = "Vader main"

    override fun getIcon() = AllIcons.RunConfigurations.TestState.Run

    override fun getLineMarkerInfo(element: PsiElement): LineMarkerInfo<*>? = null

    override fun collectSlowLineMarkers(
        elements: MutableList<out PsiElement>,
        result: MutableCollection<in LineMarkerInfo<*>>,
    ) {
        val done = HashSet<String>()
        for (element in elements) {
            val file = element.containingFile ?: continue
            val vf = file.virtualFile ?: continue
            if (!vf.name.endsWith(".vader")) continue
            if (!done.add(vf.path)) continue

            val text = file.text
            val m = MAIN_DECL.find(text) ?: continue
            val g = m.groups[1] ?: continue
            val start = g.range.first
            // The anchor must CONTAIN the range — see the `@target` marker for
            // why anchoring on an arbitrary element throws under a fine tree.
            val host = file.findElementAt(start) ?: continue
            val end = minOf(start + g.value.length, host.textRange.endOffset)
            if (start < host.textRange.startOffset || end <= start) continue
            result.add(RunMarkerInfo(host, TextRange(start, end)))
        }
    }

    private companion object {
        // Top-level only: `^` with no leading whitespace. A `main` nested in a
        // block is a different binding and not the program's entry.
        val MAIN_DECL = Regex("(?m)^(main)[ \\t]*::")
    }
}

// `RunLineMarkerContributor` builds the Run/Debug menu for free; a plain
// `LineMarkerInfo` does not, so the gutter renderer is overridden to carry the
// same `ExecutorAction`s the contributor would have supplied.
private class RunMarkerInfo(element: PsiElement, range: TextRange) : LineMarkerInfo<PsiElement>(
    element,
    range,
    AllIcons.RunConfigurations.TestState.Run,
    { "Run Vader file" },
    null,
    GutterIconRenderer.Alignment.LEFT,
    { "Run Vader file" },
) {
    override fun createGutterRenderer(): GutterIconRenderer =
        object : LineMarkerGutterIconRenderer<PsiElement>(this) {
            override fun getPopupMenuActions(): ActionGroup =
                DefaultActionGroup(*ExecutorAction.getActions(0))

            override fun isNavigateAction(): Boolean = true
        }
}

// Builds a "Vader" run configuration from a .vader file's context — so the
// gutter ▶ (and Run on a .vader editor tab) target that file.
internal class VaderRunConfigurationProducer : LazyRunConfigurationProducer<VaderRunConfiguration>() {
    override fun getConfigurationFactory(): ConfigurationFactory =
        ConfigurationTypeUtil.findConfigurationType(VaderRunConfigurationType::class.java)
            .configurationFactories[0]

    override fun setupConfigurationFromContext(
        configuration: VaderRunConfiguration,
        context: ConfigurationContext,
        sourceElement: Ref<PsiElement>,
    ): Boolean {
        val vf = context.location?.virtualFile ?: return false
        if (!vf.name.endsWith(".vader")) return false
        configuration.file = vf.path
        configuration.name = vf.name
        return true
    }

    override fun isConfigurationFromContext(
        configuration: VaderRunConfiguration,
        context: ConfigurationContext,
    ): Boolean {
        val vf = context.location?.virtualFile ?: return false
        return configuration.file == vf.path
    }
}
