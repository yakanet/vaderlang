package dev.vaderlang.intellij

import com.intellij.codeInsight.daemon.LineMarkerInfo
import com.intellij.codeInsight.daemon.LineMarkerProviderDescriptor
import com.intellij.icons.AllIcons
import com.intellij.openapi.diagnostic.Logger
import com.intellij.openapi.editor.markup.GutterIconRenderer
import com.intellij.openapi.ui.popup.JBPopupFactory
import com.intellij.openapi.util.TextRange
import com.intellij.openapi.vfs.VirtualFile
import com.intellij.pom.Navigatable
import com.intellij.psi.PsiElement
import com.intellij.psi.PsiFile
import com.intellij.psi.PsiManager
import com.intellij.ui.awt.RelativePoint
import java.awt.event.MouseEvent

// Gutter icons across a `@target` group: the bare declaration gets Java's
// "implemented by" arrow pointing down to its bodies, each `@target(.Os, …)`
// body gets "implementing" pointing back up to the declaration it fills.
//
// TWO THINGS THIS MUST NOT ASSUME, both learned by getting them wrong.
//
// 1. That a `.vader` file has a PSI tree with one leaf per identifier. It does
//    not — `plugin.xml` says it plainly: "TextMate-only language, no PSI
//    Language registered". A plain-text PSI is a SINGLE leaf spanning the whole
//    file, so anchoring one marker per leaf would put every icon on line 1.
//    Each marker therefore carries its own `TextRange`, which is what decides
//    the gutter line; the element is only an anchor.
//
// 2. That the provider is reached under `language="textmate"`. Registered for
//    both that and `TEXT`, because which one a `.vader` file actually resolves
//    to is not answerable outside a running IDE — and the symptom of guessing
//    wrong is silence, not an error. The `▶` marker on `main` guessed once and
//    has never fired.
//
// WHY THE FOLDER IS ENOUGH, rather than asking the language server (which
// answers this exactly, via `textDocument/implementation`): a marker provider
// runs inside highlighting and a per-line JSON-RPC round-trip is not affordable
// there. A Vader module IS a directory — `module "..."` must match the folder,
// and two module names in one folder is R2022 — so every body of a group lives
// beside the declaration, including the cross-file shape the SPEC's own example
// uses (`path.vader` + `path-windows.vader`).
internal class VaderImplementationLineMarkerProvider : LineMarkerProviderDescriptor() {
    override fun getName(): String = "Vader @target bodies"

    override fun getIcon() = AllIcons.Gutter.ImplementedMethod

    // Cheap pass, runs on every keystroke: reading sibling files belongs in the
    // slow pass, which the daemon runs afterwards off the critical path.
    override fun getLineMarkerInfo(element: PsiElement): LineMarkerInfo<*>? = null

    override fun collectSlowLineMarkers(
        elements: MutableList<out PsiElement>,
        result: MutableCollection<in LineMarkerInfo<*>>,
    ) {
        // One pass per FILE, not per element. With a single-leaf plain-text PSI
        // there is one element anyway; with a finer tree there would be
        // thousands, and scanning the folder once each would be quadratic.
        val done = HashSet<VirtualFile>()
        for (element in elements) {
            val file = element.containingFile ?: continue
            val self = file.virtualFile ?: continue
            if (!self.name.endsWith(".vader")) continue
            if (!done.add(self)) continue
            markFile(file, self, element, result)
        }
    }

    private fun markFile(
        file: PsiFile,
        self: VirtualFile,
        anchor: PsiElement,
        result: MutableCollection<in LineMarkerInfo<*>>,
    ) {
        val text = file.text
        val psi = PsiManager.getInstance(file.project)
        var seen = 0
        var matched = 0

        for (decl in declarationsIn(text)) {
            val decorator = targetDecoratorAbove(text, decl.nameStart) ?: continue
            seen++
            val bare = decorator == "@target"
            val targets = if (bare) {
                bodiesOf(decl.name, self, psi)
            } else {
                declarationOf(decl.name, self, psi)
            }
            if (targets.isEmpty()) continue
            matched++

            val icon = if (bare) AllIcons.Gutter.ImplementedMethod else AllIcons.Gutter.ImplementingMethod
            val tooltip = if (bare) {
                "Bodies of `${decl.name}` — one per target"
            } else {
                "Declaration of `${decl.name}` — the signature this body fills"
            }
            // The RANGE is what places the icon, not the anchor: see (1) above.
            // But `LineMarkerInfo` requires the range to lie INSIDE the anchor,
            // so the anchor is the element covering the name — the whole-file
            // leaf under a plain-text PSI, the identifier under a finer one —
            // and the range is clipped to it. Anchoring everything on one
            // arbitrary element instead throws in a loop under a fine tree.
            val host = file.findElementAt(decl.nameStart) ?: anchor
            val end = minOf(decl.nameStart + decl.name.length, host.textRange.endOffset)
            if (decl.nameStart < host.textRange.startOffset || end <= decl.nameStart) continue
            result.add(
                LineMarkerInfo(
                    host,
                    TextRange(decl.nameStart, end),
                    icon,
                    { tooltip },
                    { event, _ -> navigate(event, targets, tooltip) },
                    GutterIconRenderer.Alignment.RIGHT,
                    { tooltip },
                ),
            )
        }
        if (seen > 0) {
            LOG.info("vader: @target gutter in ${self.name} — $seen group member(s), $matched marker(s)")
        }
    }

    // `JBPopupFactory` rather than `NavigationUtil.getPsiElementPopup`: that
    // helper is not in the platform distribution this plugin builds against
    // (checked in `ideaIC-2024.2`'s jars — only `DomNavigationUtil` is there),
    // and a chooser built from core API cannot go missing under another IDE
    // version. The body → declaration direction always has exactly one target
    // anyway; R2039 makes a second one an error.
    private fun navigate(event: MouseEvent, targets: List<PsiElement>, title: String) {
        if (targets.size == 1) {
            (targets[0] as? Navigatable)?.navigate(true)
            return
        }
        JBPopupFactory.getInstance()
            .createPopupChooserBuilder(targets)
            .setTitle(title)
            .setRenderer(TargetCellRenderer())
            .setItemChosenCallback { (it as? Navigatable)?.navigate(true) }
            .createPopup()
            .show(RelativePoint(event))
    }

    private companion object {
        val LOG = Logger.getInstance(VaderImplementationLineMarkerProvider::class.java)
    }
}

// `file.vader:12` per row — the file is what tells two bodies of one group
// apart, since they share the name by construction.
private class TargetCellRenderer : javax.swing.DefaultListCellRenderer() {
    override fun getListCellRendererComponent(
        list: javax.swing.JList<*>?, value: Any?, index: Int,
        selected: Boolean, focused: Boolean,
    ): java.awt.Component {
        val label = if (value is PsiElement) {
            val vf = value.containingFile?.virtualFile
            val doc = com.intellij.psi.PsiDocumentManager
                .getInstance(value.project).getDocument(value.containingFile)
            val line = doc?.getLineNumber(value.textRange.startOffset)?.plus(1)
            if (vf != null && line != null) "${vf.name}:${line}" else vf?.name ?: value.text
        } else {
            value?.toString() ?: ""
        }
        return super.getListCellRendererComponent(list, label, index, selected, focused)
    }
}

private class Decl(val name: String, val nameStart: Int)

// Every `name ::` binding in the file, with the absolute offset of the name.
//
// Read from the TEXT rather than from PSI leaves — see (1) on the class. The
// `export` prefix is accepted here and only checked by the compiler: a body
// carrying it is R2037, and a marker that vanished on invalid source would read
// as "no bodies" rather than as an error.
private fun declarationsIn(text: String): List<Decl> {
    val out = mutableListOf<Decl>()
    for (m in Regex("(?m)^[ \\t]*(?:export[ \\t]+)?([A-Za-z_][A-Za-z0-9_]*)[ \\t]*::").findAll(text)) {
        val g = m.groups[1] ?: continue
        out.add(Decl(g.value, g.range.first))
    }
    return out
}

// The `@target` governing the declaration whose name starts at `offset` —
// `"@target"` for the bare form, `"@target(...)"` for a body — or null when
// there is none. Walks up past vaderdoc and other decorators, which may legally
// sit between the two.
private fun targetDecoratorAbove(text: String, offset: Int): String? {
    var cursor = lineStart(text, offset)
    while (cursor > 0) {
        val prev = lineAround(text, cursor - 1).trim()
        cursor = lineStart(text, cursor - 1)
        if (prev.isEmpty() || prev.startsWith("//")) continue
        if (prev == "@target") return "@target"
        if (prev.startsWith("@target")) return prev
        if (prev.startsWith("@")) continue
        return null
    }
    return null
}

// Every `@target(...)`-decorated declaration of `name` in the module — that is,
// in the folder.
private fun bodiesOf(name: String, self: VirtualFile, psi: PsiManager): List<PsiElement> =
    matchesInFolder(
        self, psi,
        Regex("@target\\s*\\([^)]*\\)\\s*(\\n\\s*@[^\\n]*)*\\s*\\n\\s*${Regex.escape(name)}\\s*::"),
        name,
    )

// The module's bare `@target` declaration of `name` — the signature a body
// fills. One per group (a second is R2039), but returned as a list: on invalid
// source the honest answer is "these, plural" rather than an arbitrary pick.
private fun declarationOf(name: String, self: VirtualFile, psi: PsiManager): List<PsiElement> =
    matchesInFolder(
        self, psi,
        // `@target` NOT followed by `(` — the tab/space class stops the match
        // from swallowing the body form.
        Regex("@target[ \\t]*(\\n\\s*@[^\\n]*)*\\s*\\n\\s*(export\\s+)?${Regex.escape(name)}\\s*::"),
        name,
    )

private fun matchesInFolder(
    self: VirtualFile, psi: PsiManager, pattern: Regex, name: String,
): List<PsiElement> {
    val folder = self.parent ?: return emptyList()
    val out = mutableListOf<PsiElement>()
    for (sibling in folder.children) {
        if (sibling.isDirectory || !sibling.name.endsWith(".vader")) continue
        val psiFile = psi.findFile(sibling) ?: continue
        for (m in pattern.findAll(psiFile.text)) {
            // Locate the name INSIDE the match rather than counting back from
            // its end: `name ::` and `name::` are both legal, so arithmetic on
            // the tail lands on whitespace for one of them.
            val at = m.range.first + m.value.lastIndexOf(name)
            out.add(psiFile.findElementAt(at.coerceAtLeast(0)) ?: continue)
        }
    }
    return out
}

private fun lineStart(text: String, offset: Int): Int {
    var start = offset.coerceIn(0, text.length)
    while (start > 0 && text[start - 1] != '\n') start--
    return start
}

private fun lineAround(text: String, offset: Int): String {
    val start = lineStart(text, offset)
    var end = offset.coerceIn(0, text.length)
    while (end < text.length && text[end] != '\n') end++
    return text.substring(start, end)
}
