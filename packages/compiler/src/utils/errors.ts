import type {Token} from "../tokens/types.ts";

export class ErrorReporter {
    constructor() {
    }

    reportError(message: string, location: Token['location']): void {
        let {line, column} = location.start;
        if (location.file) {
            console.log(`ERROR: ${location.file}(${line},${column}) ${message}`);
        } else {
            console.log(`ERROR:${line}:${column}: ${message}`);
        }
    }
}
