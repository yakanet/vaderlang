import type {Token} from "../tokens/types.ts";
import type {ModuleResolver} from "../resolver/module_resolver.ts";

export class ErrorReporter {
    constructor(private resolver: ModuleResolver) {
    }

    reportError(message: string, location: Token['location']): void {
        let {line, column} = this.findLocation(location);
        line += 1; // There is a +1 offset in IDE or Code editor
        column += 1; // There is a +1 offset in IDE or Code editor
        if (location.file) {
            console.log(`ERROR: ${location.file}(${line},${column}) ${message}`);
        } else {
            console.log(`ERROR:${line}:${column}: ${message}`);
        }
    }

    private findLocation(location: Token['location']) {
        const {content} = this.resolver.resolve(location.file)
        const offset = location.start;
        const lines = content.split('\n');
        let row = 0;
        let currentOffset = 0;
        for (let line of lines) {
            const end = currentOffset + line.length
            if (offset >= currentOffset && offset <= end) {
                return {line: row, column: offset - currentOffset}
            }
            row++
            currentOffset += line.length + 1;
        }
        throw new Error(`Could not determine location of ${offset}`)
    }
}
