import type {Token} from "../tokens/types.ts";


export class ErrorReporter {
    constructor(private content: string) {
    }

    reportError(message: string, location: Token['location']): void {
        let {line, column} = this.findLocation(location.start,);
        line += 1; // There is a +1 offset in IDE or Code editor
        column += 1; // There is a +1 offset in IDE or Code editor
        if (location.file) {
            console.log(`ERROR: ${location.file}(${line},${column}) ${message}`);
        } else {
            console.log(`ERROR:${line}:${column}: ${message}`);
        }
    }

    private findLocation(offset: number) {
        const lines = this.content.split('\n');
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
