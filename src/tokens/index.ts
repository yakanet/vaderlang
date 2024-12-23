import type {Token} from "./types.ts";

export class Tokenizer {
    public current: number = 0;

    constructor(private content: string) {
    }

    hasNext() {
        return this.current < this.content.length;
    }

    next(): string | null {
        if (this.hasNext()) {
            return this.content[this.current];
        }
        return null;
    }

    eat(): string | null {
        if (this.hasNext()) {
            return this.content[this.current++];
        }
        return null;
    }
}

export const keywords = [
    'var',
    'val',
    'if',
    'else',
    'elif',
    'this',
    'struct',
    'return',
    'extern',
    'fun'
] as const;
const keywordIndex = new Set(keywords);

function is_alpha(c: string) {
    return /^[a-zA-Z]/.test(c);
}

function is_alphanum(c: string) {
    return /^\w/.test(c);
}

function is_digit(c: string) {
    return /^\d/.test(c);
}

function is_whitespace(c: string) {
    return c === ' ' || c === '\n' || c === '\t' || c === '\r' || c === '\f';
}

export function* tokenize(content: string): Generator<Token> {
    const tokenizer = new Tokenizer(content);
    while (tokenizer.hasNext()) {
        let c = tokenizer.eat()!;

        if (is_whitespace(c)) {
            continue;
        }

        const createToken = (tokenType: Token['type'], value = c) => ({
            type: tokenType,
            value,
            offset: tokenizer.current
        }) as Token;

        const parseOperator = (singleChar: Token['type'], withEquals?: Token['type'], withDuplicate?: Token['type']) => {
            if (withEquals && tokenizer.next() === '=') {
                tokenizer.eat();
                return createToken(withEquals, `${c}=`)
            }
            if (withDuplicate && tokenizer.next() === c) {
                tokenizer.eat();
                return createToken(withDuplicate, `${c}${c}`)
            }
            return createToken(singleChar);
        }
        switch (true) {
            case (c === '=') :
                yield parseOperator('EqualToken', 'DoubleEqualToken');
                break
            case (c === '+'):
                yield parseOperator('PlusToken', 'PlusEqualToken', 'PlusPlusToken');
                break;
            case (c === '-'):
                yield parseOperator('DashToken', 'DashEqualToken', 'DashDashToken')
                break;
            case (c === '*'):
                yield parseOperator('StarToken', 'StarEqualToken');
                break;
            case (c === '/'):
                if (tokenizer.next() === '/') {
                    while (tokenizer.eat() !== '\n') {
                    }
                    break;
                }
                yield createToken('SlashToken', 'SlashEqualToken')
                break;
            case (c === '%'):
                yield parseOperator('PercentToken', 'PercentEqualToken')
                break
            case (c === '('):
                yield createToken('OpenParenthesis')
                break;
            case (c === ')'):
                yield createToken('CloseParenthesis')
                break;
            case (c === '{'):
                yield createToken('OpenCurlyBracket')
                break;
            case (c === '}'):
                yield createToken('CloseCurlyBracket')
                break;
            case (c === '['):
                yield createToken('OpenSquareBracket')
                break;
            case (c === ']'):
                yield createToken('CloseSquareBracket')
                break;
            case (c === ':'):
                yield createToken('ColonToken')
                break;
            case (c === ','):
                yield createToken('CommaToken')
                break;
            case (c === '"'): {
                let buffer = '';
                while (tokenizer.hasNext() && tokenizer.next() !== '"') {
                    buffer += tokenizer.eat()
                }
                tokenizer.eat() // closing " char
                yield createToken('StringLiteral', buffer)
                break
            }
            case is_digit(c): {
                let buffer = c;
                while (tokenizer.hasNext()) {
                    if (is_digit(tokenizer.next()!)) {
                        buffer += tokenizer.eat()!;
                    } else {
                        break;
                    }
                }
                yield createToken('NumberToken', buffer)
                break;
            }
            case is_alpha(c): {
                let buffer = c;
                while (tokenizer.hasNext()) {
                    const c2 = tokenizer.next();
                    if (c2 && is_alphanum(c2)) {
                        buffer += tokenizer.eat()!;
                    } else {
                        break;
                    }
                }
                if (keywordIndex.has(buffer as any)) {
                    yield createToken('Keyword', buffer)
                } else {
                    yield createToken('Identifier', buffer)
                }
                break
            }
            default: {
                throw new Error(`Unknown char '${c}'`)
            }
        }
    }
    yield {
        type: 'EOF',
        offset: tokenizer.current,
        value: '\0',
    }
}
