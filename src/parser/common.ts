import {Parser} from "./parser.ts";
import {type ArrayVaderType, BasicVaderType, type Expression, type Statement, type VaderType} from "./types.ts";
import {parseStatement} from "./statement.ts";
import {parseExpression} from "./expression.ts";

/**
 * identifier | identifier[]+ | identifier[_]+ | identifier[number]+
 * @param parser
 */
export function parseType(parser: Parser): VaderType {
    let type: VaderType = {...BasicVaderType.unknown};
    let originalType: VaderType = type;
    if (parser.isCurrentType('OpenSquareBracket')) {
        const arrayType: ArrayVaderType = {
            kind: 'array',
            type,
            dimension: 0
        }
        while (parser.isCurrentType('OpenSquareBracket')) {
            arrayType.dimension++;
            parser.expect('OpenSquareBracket')
            if (parser.isCurrentType('UnderscoreToken')) {
                parser.expect('UnderscoreToken');
                arrayType.length = -1;
            } else if (parser.isCurrentType('NumberToken')) {
                arrayType.length = Number(parser.expect('NumberToken').value);
                if (arrayType.length % 1 || arrayType.length < 0) {
                    parser.reportError(`Wrong size for the array. Should be a positive integer`, parser.previous.location);
                }
            }
            parser.expect('CloseSquareBracket');
        }
        type = arrayType;
    }
    const identifier = parser.expect('Identifier').value;
    originalType.name = identifier
    if (identifier in BasicVaderType) {
        originalType.name = (BasicVaderType as any)[identifier].name;
        originalType.kind = (BasicVaderType as any)[identifier].kind;
    }
    return type
}

/**
 * ([identifier: type,?]*)
 * @param parser
 */
export function parseFunctionArguments(parser: Parser): { name: string, type: VaderType }[] {
    parser.expect('OpenRoundBracket')
    const parameters: { name: string, type: VaderType }[] = [];
    while (!parser.isCurrentType('CloseRoundBracket')) {
        const identifier = parser.expect('Identifier')
        parser.expect('ColonToken');
        const type = parseType(parser);
        parameters.push({name: identifier.value, type})
        if (!parser.isCurrentType('CommaToken')) {
            break
        }
        parser.expect('CommaToken');
    }
    parser.expect('CloseRoundBracket')
    return parameters;
}


/**
 * ([identifier: Type,?]+)
 * @param parser
 */
export function parseCallArguments(parser: Parser) {
    parser.expect('OpenRoundBracket');
    const parameters: Expression[] = [];
    let hasNext = !parser.isCurrentType('CloseRoundBracket');
    while (hasNext) {
        parameters.push(parseExpression(parser));
        hasNext = false
        if (parser.isCurrentType('CommaToken')) {
            parser.expect('CommaToken')
            hasNext = true;
        }
    }
    parser.expect('CloseRoundBracket');
    return parameters;
}

export function parseBlockStatement(parser: Parser): Statement[] {
    parser.expect('OpenCurlyBracket');
    const statements: Statement[] = []
    while (!parser.isCurrentType('CloseCurlyBracket')) {
        statements.push(parseStatement(parser))
    }
    parser.expect('CloseCurlyBracket');
    return statements;
}

export function optionalRoundBracket<T>(parser: Parser, cb: () => T): T {
    const hasBracket = parser.isCurrentType('OpenRoundBracket');
    if (hasBracket) {
        parser.expect('OpenRoundBracket');
    }
    const result = cb();
    if (hasBracket) {
        parser.expect('CloseRoundBracket');
    }
    return result;
}
