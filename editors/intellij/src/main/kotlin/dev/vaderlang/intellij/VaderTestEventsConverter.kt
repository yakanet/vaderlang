package dev.vaderlang.intellij

import com.google.gson.JsonObject
import com.google.gson.JsonParser
import com.intellij.execution.process.ProcessOutputTypes
import com.intellij.execution.testframework.TestConsoleProperties
import com.intellij.execution.testframework.sm.ServiceMessageBuilder
import com.intellij.execution.testframework.sm.runner.OutputToGeneralTestEventsConverter
import com.intellij.openapi.util.Key
import java.io.File
import kotlin.math.roundToLong

// Reads the report of `vader test --reporter=json` (`docs/TOOLING.md`, *Tests*):
// a JSON text sequence (RFC 7464) where an event follows a record separator (RS)
// and ends its line, and everything else on stdout is what the tests write.
//
// Each event becomes the TeamCity service message the platform's converter
// reads, so the tree, the durations and the attribution of output to the
// running test are the platform's. The tests' output skips the platform's line
// splitter: a `print` without a newline left in it would glue the next service
// message to the end of its line.
internal class VaderTestEventsConverter(testFrameworkName: String, properties: TestConsoleProperties) :
    OutputToGeneralTestEventsConverter(testFrameworkName, properties) {

    // Stdout not handed on yet: an event a read cut stays here until its newline.
    private val pending = StringBuilder()

    // The suite of the module whose tests run: the next module, an error or the
    // summary closes it.
    private var openSuite: String? = null

    override fun process(text: String, outputType: Key<*>) {
        if (outputType != ProcessOutputTypes.STDOUT) {
            super.process(text, outputType)
            return
        }
        pending.append(text)
        while (true) {
            val separator = pending.indexOf(RS)
            if (separator < 0) {
                handOutput(pending.length)
                return
            }
            handOutput(separator)
            val end = pending.indexOf("\n")
            if (end < 0) return
            handEvent(pending.substring(1, end))
            pending.delete(0, end + 1)
        }
    }

    // An event the process did not finish is output, without its RS.
    override fun flushBufferOnProcessTermination(exitCode: Int) {
        if (pending.startsWith(RS)) pending.deleteCharAt(0)
        handOutput(pending.length)
        super.flushBufferOnProcessTermination(exitCode)
    }

    private fun handOutput(length: Int) {
        if (length == 0) return
        fireOnUncapturedOutput(pending.substring(0, length), ProcessOutputTypes.STDOUT)
        pending.delete(0, length)
    }

    // A line that does not read as an event is shown as it is.
    private fun handEvent(text: String) {
        val event = runCatching { JsonParser.parseString(text).asJsonObject }.getOrNull()
        if (event == null) {
            fireOnUncapturedOutput("$text\n", ProcessOutputTypes.STDOUT)
            return
        }
        for (message in serviceMessages(event)) super.process("$message\n", ProcessOutputTypes.STDOUT)
    }

    private fun serviceMessages(event: JsonObject): List<ServiceMessageBuilder> {
        val test = event.text("test")
        return when (event.text("event")) {
            "module" -> closeSuite() + startSuite(moduleName(event), event.text("path"))
            "start" -> listOf(started(test, location(event.text("file"), event.text("line"))).withFilter(event.text("filter")))
            "pass" -> listOf(finished(test, event))
            "fail" -> failed(test, event)
            // A module that did not run shows as a failed test of its name: what
            // went wrong is on stderr, which the console shows beside it.
            "error" -> {
                val name = moduleName(event)
                closeSuite() + started(name, location(event.text("path"))) + failed(name, event)
            }
            "summary" -> closeSuite()
            else -> emptyList()
        }
    }

    private fun startSuite(name: String, path: String): List<ServiceMessageBuilder> {
        openSuite = name
        return listOf(ServiceMessageBuilder.testSuiteStarted(name).withLocation(location(path)))
    }

    private fun closeSuite(): List<ServiceMessageBuilder> {
        val name = openSuite ?: return emptyList()
        openSuite = null
        return listOf(ServiceMessageBuilder.testSuiteFinished(name))
    }
}

private const val RS = '\u001e'

// The name a module shows under: the one it declares, else its file's.
private fun moduleName(event: JsonObject): String =
    event.text("module").ifEmpty { File(event.text("path")).name }

private fun started(test: String, location: String?): ServiceMessageBuilder =
    ServiceMessageBuilder.testStarted(test).withLocation(location)

// The failure `event` reports for `test`, and the end of that test.
private fun failed(test: String, event: JsonObject): List<ServiceMessageBuilder> = listOf(
    ServiceMessageBuilder.testFailed(test).addAttribute("message", event.text("message")),
    finished(test, event),
)

// The end of `test`, with how long it ran when `event` says so.
private fun finished(test: String, event: JsonObject): ServiceMessageBuilder {
    val milliseconds = event.get("duration_ms")?.asDouble?.roundToLong() ?: 0
    return ServiceMessageBuilder.testFinished(test).addAttribute("duration", milliseconds.toString())
}

// A `file://` URL the platform's `FileUrlProvider` reads, with a line from 1 when
// there is one. Null for a folder, the entry of a folder module, which the
// provider would turn into a null location.
private fun location(path: String, line: String = ""): String? {
    if (!File(path).isFile) return null
    if (line.isEmpty()) return "file://$path"
    return "file://$path:$line"
}

private fun ServiceMessageBuilder.withLocation(location: String?): ServiceMessageBuilder {
    if (location == null) return this
    return addAttribute("locationHint", location)
}

// The `--filter` that keeps the test alone, as its `metainfo`: "Rerun Failed
// Tests" reads it back (`VaderRerunFailedTestsAction`).
private fun ServiceMessageBuilder.withFilter(filter: String): ServiceMessageBuilder {
    if (filter.isEmpty()) return this
    return addAttribute("metainfo", filter)
}

private fun JsonObject.text(name: String): String =
    get(name)?.takeIf { it.isJsonPrimitive }?.asString.orEmpty()
