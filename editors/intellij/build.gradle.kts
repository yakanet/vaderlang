plugins {
    id("org.jetbrains.kotlin.jvm")
    id("org.jetbrains.intellij.platform")
}

group = "dev.vaderlang"
version = "0.1.0"

dependencies {
    intellijPlatform {
        // Ultimate (free for plugin development) ships the LSP API
        // (`com.intellij.platform.lsp`), which the Community edition
        // doesn't bundle. Compiling against Ultimate gives us access to
        // `LspServerSupportProvider` ; at runtime the plugin gracefully
        // skips its LSP extension on IDEs that lack the module thanks
        // to the `<depends optional="true">` declaration in plugin.xml.
        intellijIdeaUltimate("2024.2")
        bundledPlugin("org.jetbrains.plugins.textmate")
    }
}

kotlin {
    jvmToolchain(21)
}

intellijPlatform {
    pluginConfiguration {
        ideaVersion {
            sinceBuild = "242"
            untilBuild = provider { null }
        }
    }
}

tasks.processResources {
    val grammar = layout.projectDirectory.file("../common/vader.tmLanguage.json")
    val languageConfig = layout.projectDirectory.file("../common/language-configuration.json")
    val vaderIcon = layout.projectDirectory.file("../common/vader.svg")
    val virIcon = layout.projectDirectory.file("../common/vir.svg")

    from(grammar) { into("bundle/syntaxes/") }
    from(languageConfig) { into("bundle/") }
    from(vaderIcon) { into("icons/") }
    from(virIcon) { into("icons/") }

    inputs.files(grammar, languageConfig, vaderIcon, virIcon)
}
