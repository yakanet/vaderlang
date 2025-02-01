import type { Token } from "./types.ts";

export class Tokenizer {
  public current: number = 0;

  constructor(private content: string) {}

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
  "if",
  "else",
  "elif",
  'for',
  "struct",
  "foreign",
  "return",
  "fn",
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
  return c === " " || c === "\n" || c === "\t" || c === "\r" || c === "\f";
}

export function* tokenize(content: string): Generator<Token> {
  const tokenizer = new Tokenizer(content);
  while (tokenizer.hasNext()) {
    let c = tokenizer.eat()!;

    if (is_whitespace(c)) {
      continue;
    }

    const createToken = (tokenType: Token["type"], value = c) =>
      ({
        type: tokenType,
        value,
        offset: tokenizer.current,
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
        if(tokenizer.next() === '>') {
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
            if(!tokenizer.hasNext()) {
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
        yield createToken("OpenParenthesis");
        break;
      case c === ")":
        yield createToken("CloseParenthesis");
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
        yield createToken("LowerThanToken", "LowerThanEqualToken");
        break;
      case c === ">":
        yield createToken("HigherThanToken", "HigherThanEqualToken");
        break;
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
        let buffer = c;
        while (tokenizer.hasNext()) {
          const c2 = tokenizer.next()!;
          let seen_dot = false;
          if (is_digit(c2)) {
            buffer += tokenizer.eat()!;
          } else if (c2 === "_") {
            tokenizer.eat();
          } else if (c2 === "." && !seen_dot) {
            seen_dot = true;
            buffer += tokenizer.eat()!;
          } else {
            break;
          }
        }
        yield createToken("NumberToken", buffer);
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
    offset: tokenizer.current,
    value: "\0",
  };
}
