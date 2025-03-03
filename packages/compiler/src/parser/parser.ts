import type {Location, Token} from "../tokens/types.ts";
import {keywords, tokenize} from "../tokens";
import type { BundleContext } from "../context/context.ts";

export class Parser {
    private tokens: Token[] = [];
    private index = 0;
    private loadedFiles = new Set<string>();

    constructor(public readonly context: BundleContext) {
    }

    private eat() {
        return this.tokens[this.index++];
    }

    loadVaderFile(filename: string, from: string): boolean {
        try {
            let path = filename;
            if (!path.endsWith('.vader')) {
                path += '.vader'
            }
            const {key, content, location} = this.context.resolve(path, from);
            if (this.loadedFiles.has(key)) {
                return true
            }
            this.loadedFiles.add(key);
            const tokens = [...tokenize(content, location)]
            if (this.tokens.length) {
                tokens.pop(); // Removing EOF
            }
            this.tokens = [...this.tokens.slice(0, this.index), ...tokens, ...this.tokens.slice(this.index)]
            return true;
        } catch (e: any) {
            debugger
        }
        return false;
    }

    expectKeyword(keyword: typeof keywords[number], message?: string) {
        const token = this.current;
        if (this.isCurrentKeyword(keyword)) {
            return this.eat();
        }
        throw new Error(message ?? `Expected keyword ${keyword} but get ${token.type}`)
    }

    isCurrentKeyword(keyword: typeof keywords[number]) {
        return this.current.type === 'Keyword' && this.current.value === keyword;
    }

    isCurrentType(type: Token['type']) {
        return this.current.type === type;
    }

    reportError(message: string, location: Location): never {
        this.context.reportError(message, location);
        throw new Error(`Parsing error: ${message}`)
    }

    expect(type: Token['type'], message?: string): Token {
        if (this.current?.type === type) {
            const c = this.current
            this.eat();
            return c;
        }
        this.reportError(message ?? `Expected tokens ${type} but got ${this.current.type}`, this.current.location);
    }

    expects(types: Token['type'][], message?: string) {
        for (const type of types) {
            if (this.current?.type === type) {
                const c = this.current
                this.eat();
                return c;
            }
        }
        this.reportError(message ?? `Expected tokens ${types} but got ${this.current.type}`, this.current.location);
    }

    get current(): Token {
        return this.tokens[this.index];
    }

    get previous(): Token {
        return this.tokens[this.index - 1];
    }

    get next(): Token {
        return this.tokens[this.index + 1];
    }
}
