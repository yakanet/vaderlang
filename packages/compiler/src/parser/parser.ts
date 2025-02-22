import type {Token} from "../tokens/types.ts";
import {ErrorReporter} from "../utils/errors.ts";
import type {ModuleResolver} from "../resolver/module_resolver.ts";
import {keywords, tokenize} from "../tokens";

export class Parser {
    private tokens: Token[] = [];
    private index = 0;
    private reporter = new ErrorReporter()
    private debug = true;
    private loadedFiles = new Set<string>();

    constructor(public readonly resolver: ModuleResolver) {
    }

    private eat() {
        return this.tokens[this.index++];
    }

    loadVaderFile(filename: string) {
        try {
            let path = filename;
            if (!path.endsWith('.vader')) {
                path += '.vader'
            }
            const {key, content, location} = this.resolver.resolve(path);
            if (this.loadedFiles.has(key)) {
                return
            }
            const tokens = [...tokenize(content, location)]
            if (this.tokens.length) {
                tokens.pop(); // Removing EOF
            }
            this.tokens = [...this.tokens.slice(0, this.index), ...tokens, ...this.tokens.slice(this.index)]
        } catch (e: any) {
            this.reporter.reportError(e.message, this.current.location);
        }
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

    reportError(message: string, location: Token['location']): never {
        this.reporter.reportError(message, location)
        if (this.debug) {
            throw new Error('debug')
        } else {
            process.exit(1);
        }
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
