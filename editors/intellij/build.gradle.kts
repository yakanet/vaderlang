plugins {
    id("org.jetbrains.kotlin.jvm")
    id("org.jetbrains.intellij.platform")
}

group = "dev.vaderlang"
version = "0.1.0"

dependencies {
    intellijPlatform {
        // Community is enough now : we no longer rely on the bundled
        // `com.intellij.platform.lsp` module (which only ships with
        // commercial IDEs). LSP integration is delegated to LSP4IJ —
        // a third-party plugin (EPL-2.0, Red Hat) that works on every
        // IntelliJ-based IDE, Community included. The user installs
        // LSP4IJ once from the Marketplace and our plugin layers on
        // top of it.
        intellijIdeaCommunity("2024.2")
        bundledPlugin("org.jetbrains.plugins.textmate")
        plugin("com.redhat.devtools.lsp4ij:0.20.1")
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
    val common = layout.projectDirectory.dir("../common")

    from(common) { include("*.tmLanguage.json"); into("bundle/syntaxes/") }
    from(common) { include("*language-configuration.json"); into("bundle/") }
    from(common) { include("*.svg"); into("icons/") }
}
