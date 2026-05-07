plugins {
    id("org.jetbrains.kotlin.jvm")
    id("org.jetbrains.intellij.platform")
}

group = "dev.vaderlang"
version = "0.1.0"

dependencies {
    intellijPlatform {
        intellijIdeaCommunity("2024.2")
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

    from(grammar) { into("bundle/syntaxes/") }
    from(languageConfig) { into("bundle/") }

    inputs.files(grammar, languageConfig)
}
