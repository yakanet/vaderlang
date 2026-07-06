package dev.vaderlang.intellij

import com.intellij.execution.actions.ConfigurationContext
import com.intellij.execution.actions.LazyRunConfigurationProducer
import com.intellij.execution.configurations.ConfigurationFactory
import com.intellij.execution.configurations.ConfigurationTypeUtil
import com.intellij.execution.lineMarker.ExecutorAction
import com.intellij.execution.lineMarker.RunLineMarkerContributor
import com.intellij.icons.AllIcons
import com.intellij.openapi.util.Ref
import com.intellij.psi.PsiElement

// A `main ::` fn decl at the top of a .vader file gets a green ▶ gutter icon,
// like Java/Kotlin `main`. Clicking it Runs (or Debugs) the file through the
// Vader run configuration (VaderRunConfigurationProducer builds it).
//
// Vader has no PSI (TextMate-only highlighting), so this hooks the TextMate
// leaf whose text is `main` and confirms — from the surrounding line — that it's
// a top-level `main :: fn` declaration. Registered for the `textmate` language,
// gated to `*.vader` files.
//
// ⚠️ Not verified in a running IDE — whether TextMate yields a `main` leaf here
// is a live check (`./gradlew runIde`). If it doesn't, the gutter icon simply
// won't appear; the "Vader" run configuration (Add New Configuration) still works.
internal class VaderRunLineMarkerContributor : RunLineMarkerContributor() {
    override fun getInfo(element: PsiElement): Info? {
        // Leaf tokens only (no children) — avoids one Info per ancestor node.
        if (element.firstChild != null) return null
        if (element.text != "main") return null
        val file = element.containingFile ?: return null
        val vf = file.virtualFile ?: return null
        if (!vf.name.endsWith(".vader")) return null
        if (!isMainFnDeclLine(file.text, element.textRange.startOffset)) return null

        val actions = ExecutorAction.getActions(0)
        return Info(
            AllIcons.RunConfigurations.TestState.Run,
            actions,
            { _ -> "Run Vader file" },
        )
    }
}

// True when the source line holding `offset` is a top-level `main :: …` binding
// (the entry point), not just any token spelled "main".
private fun isMainFnDeclLine(text: String, offset: Int): Boolean {
    var start = offset
    while (start > 0 && text[start - 1] != '\n') start--
    var end = offset
    while (end < text.length && text[end] != '\n') end++
    val line = text.substring(start, end)
    return Regex("^\\s*main\\s*::").containsMatchIn(line)
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
        configuration.setProgramPath(vf.path)
        configuration.name = vf.name
        return true
    }

    override fun isConfigurationFromContext(
        configuration: VaderRunConfiguration,
        context: ConfigurationContext,
    ): Boolean {
        val vf = context.location?.virtualFile ?: return false
        return configuration.getProgramPath() == vf.path
    }
}
