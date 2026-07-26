package dev.vaderlang.intellij

import com.intellij.openapi.editor.DefaultLanguageHighlighterColors
import com.intellij.openapi.editor.colors.TextAttributesKey
import com.intellij.psi.PsiFile
import com.redhat.devtools.lsp4ij.client.features.LSPSemanticTokensFeature

// Narrow overrides on top of LSP4IJ's own semantic-token colouring.
//
// LSP4IJ already ships a complete `DefaultSemanticTokensColorsProvider` mapping
// every standard token type to an `LSP_*` key the user can recolour under
// Settings → Editor → Color Scheme. That default is kept for everything not
// handled below — replacing it wholesale would take those settings away.
//
// Each override answers one question: does the token type end up coloured for the
// user, or not? Three answers, three branches:
//
//   documentation modifier → an explicit doc-comment key. Our own modifier
//     (`TOKEN_MODIFIERS` in `vader/lsp/protocol/tokens.vader`), which LSP4IJ's
//     default knows nothing about, so vaderdoc tags would read as live code.
//   type → the plugin's own key, because NEITHER side colours it (see `VaderColors`).
//   function → null, i.e. no semantic colouring at all, because the TextMate
//     grammar already paints call sites via `entity.name.function.call.vader`
//     while LSP4IJ's `LSP_FUNCTION` → `FUNCTION_CALL` is a key themes leave at the
//     plain foreground. Emitting a token there REPLACED a coloured scope with an
//     uncoloured key, whitening every call — while the same call inside a string
//     interpolation (no AST token emitted) stayed coloured. Returning null makes
//     LSP4IJ skip the highlight (`SemanticTokensData` null-checks the key), so the
//     grammar keeps it.
internal class VaderSemanticTokensFeature : LSPSemanticTokensFeature() {
    override fun getTextAttributesKey(
        tokenType: String,
        tokenModifiers: List<String>,
        file: PsiFile,
    ): TextAttributesKey? {
        if (tokenModifiers.contains(DOCUMENTATION)) {
            when (tokenType) {
                "decorator" -> return DefaultLanguageHighlighterColors.DOC_COMMENT_TAG
                "parameter" -> return DefaultLanguageHighlighterColors.DOC_COMMENT_TAG_VALUE
                "comment" -> return DefaultLanguageHighlighterColors.DOC_COMMENT
            }
        }
        if (tokenType == "type") {
            return VaderColors.TYPE
        }
        if (tokenType == "function") {
            return null
        }
        return super.getTextAttributesKey(tokenType, tokenModifiers, file)
    }

    private companion object {
        const val DOCUMENTATION = "documentation"
    }
}
