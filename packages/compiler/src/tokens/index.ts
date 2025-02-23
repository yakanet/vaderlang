import type {Token} from "./types.ts";
import type {Position} from "../parser/types.ts";

export class Tokenizer {
    private current: number = 0;
    public line = 0;
    public column = 0;
    private previousPosition: Position | null = null;

    constructor(private content: string) {
    }

    hasNext() {
        return this.current < this.content.length;
    }

    next(offset = 0): string | null {
        if (this.current + offset <= this.content.length) {
            return this.content[this.current + offset];
        }
        return null;
    }

    getCurrentPosition(): Position {
        return {
            offset: this.current,
            line: this.line,
            column: this.column,
        }
    }

    eat(): string | null {
        this.previousPosition = this.getCurrentPosition();
        if (this.content[this.current] === '\n') {
            this.line++;
            this.column = 0;
        } else {
            this.column++
        }
        if (this.hasNext()) {
            return this.content[this.current++];
        }
        return null;
    }

    rollback() {
        if (!this.previousPosition) {
            throw new Error(`Could not rollback position`)
        }
        this.column = this.previousPosition.column;
        this.current = this.previousPosition.offset;
        this.line = this.previousPosition.line;
        this.previousPosition = null;
    }

    pick() {
        return this.content[this.current];
    }
}

export const keywords = [
    "if",
    "else",
    "elif",
    'for',
    "struct",
    "return",
    "fn",
    "true",
    "false"
] as const;
const keywordIndex = new Set(keywords);

function is_alpha(c: string) {
    return /^[a-zA-Z]/.test(c);
}

function is_alphanum(c: string) {
    return /^\w/.test(c);
}

function is_digit(c: string) {
    if (!c) {
        return false;
    }
    const code = c.charCodeAt(0)
    return code >= '0'.charCodeAt(0) && code <= '9'.charCodeAt(0);
}

function is_whitespace(c: string) {
    return c === " " || c === "\n" || c === "\t" || c === "\r" || c === "\f";
}

export function* tokenize(content: string, file: string): Generator<Token> {
    const tokenizer = new Tokenizer(content);

    //Shebang
    if (tokenizer.next() === '#') {
        while (tokenizer.eat() !== "\n") {
            if (!tokenizer.hasNext()) {
                break
            }
        }
    }
    while (tokenizer.hasNext()) {
        let start = tokenizer.getCurrentPosition()
        let c = tokenizer.eat()!;

        if (is_whitespace(c)) {
            continue;
        }


        const createToken = (tokenType: Token["type"], value = c) =>
            ({
                type: tokenType,
                value,
                location: {
                    start,
                    end: tokenizer.getCurrentPosition(),
                    file
                },
            } as Token);

        const parseOperator = (
            singleChar: Token["type"],
            withEquals?: Token["type"],
            withDuplicate?: Token["type"]
        ) => {
            if (withEquals && tokenizer.next() === "=") {
                tokenizer.eat();
                return createToken(withEquals, `${c}=`);
            }
            if (withDuplicate && tokenizer.next() === c) {
                tokenizer.eat();
                return createToken(withDuplicate, `${c}${c}`);
            }
            return createToken(singleChar);
        };
        switch (true) {
            case c === "=":
                yield parseOperator("EqualToken", "DoubleEqualToken");
                break;
            case c === "+":
                yield parseOperator("PlusToken", "PlusEqualToken", "PlusPlusToken");
                break;
            case c === "-":
                if (tokenizer.next() === '>') {
                    tokenizer.eat();
                    yield createToken('LambdaArrowToken', '->')
                } else {
                    yield parseOperator("DashToken", "DashEqualToken", "DashDashToken");
                }
                break;
            case c === "*":
                yield parseOperator("StarToken", "StarEqualToken");
                break;
            case c === "&":
                yield parseOperator("BitwiseAndToken", undefined, "BooleanAndToken");
                break;
            case c === "|":
                yield parseOperator("BitwiseOrToken", undefined, "BooleanOrToken");
                break;
            case c === ".":
                yield parseOperator("DotToken", undefined, "DotDotToken");
                break;
            case c === "/":
                if (tokenizer.next() === "/") {
                    while (tokenizer.eat() !== "\n") {
                        if (!tokenizer.hasNext()) {
                            break
                        }
                    }
                    break;
                }
                yield parseOperator("SlashToken", "SlashEqualToken");
                break;
            case c === "%":
                yield parseOperator("PercentToken", "PercentEqualToken");
                break;
            case c === "!":
                yield parseOperator("BangToken", "BangEqualToken");
                break;
            case c === ";":
                yield createToken("SemicolonToken");
                break;
            case c === "(":
                yield createToken("OpenRoundBracket");
                break;
            case c === ")":
                yield createToken("CloseRoundBracket");
                break;
            case c === "{":
                yield createToken("OpenCurlyBracket");
                break;
            case c === "}":
                yield createToken("CloseCurlyBracket");
                break;
            case c === "[":
                yield createToken("OpenSquareBracket");
                break;
            case c === "]":
                yield createToken("CloseSquareBracket");
                break;
            case c === ":":
                yield createToken("ColonToken");
                break;
            case c === ",":
                yield createToken("CommaToken");
                break;
            case c === "<":
                yield parseOperator("LowerThanToken", "LowerThanEqualToken");
                break;
            case c === ">":
                yield parseOperator("HigherThanToken", "HigherThanEqualToken");
                break;
            case c === "_":
                yield createToken("UnderscoreToken");
                break
            case c === '"': {
                let buffer = "";
                while (tokenizer.hasNext() && tokenizer.next() !== '"') {
                    buffer += tokenizer.eat();
                }
                tokenizer.eat(); // closing " char
                yield createToken("StringLiteral", buffer);
                break;
            }
            case is_digit(c): {
                tokenizer.rollback(); // put back the digit char
                const buffer = nextNumber(tokenizer);
                yield createToken('NumberToken', buffer);
                break;
            }
            case c === "@":
            case is_alpha(c): {
                let buffer = c;
                const isDecorator = c === "@";
                if (isDecorator) {
                    buffer = "";
                }
                while (tokenizer.hasNext()) {
                    const c2 = tokenizer.next();
                    if (c2 && is_alphanum(c2)) {
                        buffer += tokenizer.eat()!;
                    } else {
                        break;
                    }
                }
                if (isDecorator) {
                    yield createToken("Decorator", buffer);
                } else if (keywordIndex.has(buffer as any)) {
                    yield createToken("Keyword", buffer);
                } else {
                    yield createToken("Identifier", buffer);
                }
                break;
            }
            default: {
                throw new Error(`Unknown char '${c}'`);
            }
        }
    }
    yield {
        type: "EOF",
        location: {
            start: tokenizer.getCurrentPosition(),
            end: tokenizer.getCurrentPosition(),
            file
        },
        value: "\0",
    };
}

function nextNumber(tokenizer: Tokenizer) {
    let buffer = '';
    if (tokenizer.eat() === '0') {
        if (tokenizer.next())
            switch (tokenizer.pick()) {
                case 'b': {
                    tokenizer.eat()
                    buffer += scanMantissa(tokenizer, 2).toString(10);
                    break
                }
                case 'o': {
                    tokenizer.eat()
                    buffer += scanMantissa(tokenizer, 8).toString(10);
                    break
                }
                case 'x': {
                    tokenizer.eat()
                    buffer += scanMantissa(tokenizer, 16).toString(10);
                    break
                }
                default: {
                    return "0"
                }
            }
    } else {
        tokenizer.rollback(); // put back the digit char
        buffer += scanMantissa(tokenizer, 10).toString(10);
        if (tokenizer.pick() === '.' && is_digit(tokenizer.next(1)!)) {
            buffer += tokenizer.eat();
            buffer += scanMantissa(tokenizer, 10)
        }
    }
    return buffer;
}

const charToNumber = {
    2: ['0', '1'],
    8: ['0', '1', '2', '3', '4', '5', '6', '7'],
    10: ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'],
    16: ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'],
} as const;

function scanMantissa(tokenizer: Tokenizer, radix: keyof typeof charToNumber): number {
    const letters = charToNumber[radix];
    let n: number[] = [];
    while (tokenizer.hasNext()) {
        const c = tokenizer.pick();
        if (c === '_') {
            tokenizer.eat();
            continue;
        }
        const index = letters.findIndex(l => l === c);
        if (index < 0) {
            break;
        }
        tokenizer.eat();
        n.push(index)
    }
    return n.toReversed().reduce((a, b, i) => {
        return Math.pow(radix, i) * b + a
    }, 0);
}
