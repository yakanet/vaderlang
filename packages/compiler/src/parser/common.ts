import {Parser} from "./parser.ts";
import {type ArrayVaderType, BasicVaderType, type Expression, type Statement, type VaderType} from "./types.ts";
import {parseStatement} from "./statement.ts";
import {parseExpression} from "./expression.ts";

/**
 * identifier | []+identifier | [_]+identifier | [number]+identifier
 * @param parser
 */
export function parseType(parser: Parser): VaderType {
    if (parser.isCurrentType('OpenSquareBracket')) {
        const arrayType: ArrayVaderType = {
            kind: 'array',
            type: BasicVaderType.unknown,
            dimension: 1
        }
        if (parser.isCurrentType('OpenSquareBracket')) {
            parser.expect('OpenSquareBracket')
            if (parser.isCurrentType('UnderscoreToken')) {
                parser.expect('UnderscoreToken');
            } else if (!parser.isCurrentType('CloseSquareBracket')) {
                arrayType.length = parseExpression(parser);
            }
            parser.expect('CloseSquareBracket');
        }
        const childType = parseType(parser);
        if (childType.kind === 'array') {
            arrayType.type = childType;
            arrayType.dimension = childType.dimension + 1;
        } else {
            arrayType.type = childType;
        }
        return arrayType;
    }
    const identifier = parser.expect('Identifier').value;
    return {
        kind: 'unknown',
        name: identifier
    }
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
