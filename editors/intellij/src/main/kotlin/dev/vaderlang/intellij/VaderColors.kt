package dev.vaderlang.intellij

import com.intellij.openapi.editor.DefaultLanguageHighlighterColors
import com.intellij.openapi.editor.colors.TextAttributesKey

// Colour keys the plugin OWNS, with values supplied per scheme by
// `colorSchemes/Vader*.xml` (declared as `additionalTextAttributes` in plugin.xml).
//
// Why not reuse an existing key: type names have no coloured key to borrow.
// LSP4IJ maps the `type` semantic token to `LSP_TYPE` → `CLASS_NAME`, which dark
// themes leave at the plain foreground (IntelliJ colours class *declarations* in
// Java, not references). Yielding to the TextMate grammar instead — the trick that
// fixed call sites — does not work here either: IntelliJ only maps a SUBSET of
// TextMate scopes onto its colour keys, and `support.type.primitive.vader` (the
// grammar's scope for `i32` / `string` / `usize`) is not in it, so primitives stay
// white whichever side paints them.
//
// Declaring our own key with an explicit value is therefore the only
// theme-independent option. It also puts the colour under the user's control:
// the key shows up in Settings → Editor → Color Scheme once referenced.
//
// `fallbackKey` still matters — it is what a scheme with no explicit value for
// `VADER_TYPE` resolves to.
internal object VaderColors {
    val TYPE: TextAttributesKey =
        TextAttributesKey.createTextAttributesKey("VADER_TYPE", DefaultLanguageHighlighterColors.CLASS_NAME)
}
