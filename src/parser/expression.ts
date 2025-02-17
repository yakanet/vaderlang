import {Parser} from "./parser.ts";
import {
    type ArrayDeclarationExpression,
    type ArrayIndexExpression,
    BasicVaderType,
    type BinaryExpression,
    type CallExpression,
    type DotExpression,
    type Expression,
    type FunctionVaderType,
    type NumberExpression,
    type StringExpression,
    type StructDeclarationExpression,
    type StructInstantiationExpression,
    type VaderType
} from "./types.ts";
import {parseBlockStatement, parseCallArguments, parseFunctionArguments, parseType} from "./common.ts";
import {decorators, parseIfStatement} from "./statement.ts";
import type {Token} from "../tokens/types.ts";

export function parseExpression(parser: Parser): Expression {
    return parseLogicalExpression(parser)
}

function parseLogicalExpression(parser: Parser): Expression {
    const operations = new Set<Token['type']>([
        'BitwiseAndToken',
        'BitwiseOrToken',
        'BooleanAndToken',
        'BooleanOrToken',
    ]);
    let left = parseComparisonExpression(parser)
    while (operations.has(parser.current.type)) {
        const operatorToken = parser.expects([...operations.values()])
        const right = parseComparisonExpression(parser);
        left = createBinaryExpression(left, right, operatorToken)
    }
    return left;
}

function parseComparisonExpression(parser: Parser): Expression {
    const operations = new Set<Token['type']>([
        'LowerThanToken',
        'LowerThanEqualToken',
        'HigherThanToken',
        'HigherThanEqualToken',
        'DoubleEqualToken',
        'BangEqualToken'
    ]);
    let left = parseAdditiveExpression(parser)
    while (operations.has(parser.current.type)) {
        const operatorToken = parser.expects([...operations.values()])
        const right = parseAdditiveExpression(parser);
        left = createBinaryExpression(left, right, operatorToken)
    }
    return left;
}

function parseAdditiveExpression(parser: Parser): Expression {
    const operations = new Set<Token['type']>([
        'PlusToken',
        'DashToken'
    ]);
    let left = parseMultiplicativeExpression(parser)
    while (operations.has(parser.current.type)) {
        const operatorToken = parser.expects([...operations.values()])
        const right = parseMultiplicativeExpression(parser);
        left = createBinaryExpression(left, right, operatorToken)
    }
    return left;
}

function parseMultiplicativeExpression(parser: Parser): Expression {
    const operations = new Set<Token['type']>([
        'StarToken',
        'SlashToken'
    ]);
    let left = parseUnaryExpression(parser)
    while (operations.has(parser.current.type)) {
        const operatorToken = parser.expects([...operations.values()])
        const right = parseUnaryExpression(parser);
        left = createBinaryExpression(left, right, operatorToken)
    }
    return left;
}

function parseUnaryExpression(parser: Parser): Expression {
    return parseStructInstantiation(parser)
}

function parseStructInstantiation(parser: Parser): Expression {
    let left = parseArrayIndexExpression(parser)
    if (left.kind === 'IdentifierExpression' && parser.isCurrentType('OpenCurlyBracket')) {
        const instance: StructInstantiationExpression = {
            kind: 'StructInstantiationExpression',
            parameters: [],
            structName: left.identifier,
            type: BasicVaderType.unknown,
            location: {
                ...left.location
            },
        }
        parser.expect('OpenCurlyBracket');
        while (!parser.isCurrentType('CloseCurlyBracket')) {
            let name: string | undefined = undefined;
            if (parser.isCurrentType('DotToken')) {
                parser.expect('DotToken')
                name = parser.expect('Identifier').value;
                parser.expect('EqualToken')
            }
            instance.parameters.push({name, value: parseExpression(parser)});
            if (!parser.isCurrentType('CommaToken')) {
                break
            }
            parser.expect('CommaToken');
        }
        parser.expect('CloseCurlyBracket')
        instance.location.end = parser.previous.location.end;
        return instance;
    }
    return left;
}

function parseArrayIndexExpression(parser: Parser): Expression {
    let left = parseMemberExpression(parser)
    if (parser.isCurrentType('OpenSquareBracket')) {
        return parseArrayIndexBracketExpression(parser, left)
    }
    return left;
}

function parseMemberExpression(parser: Parser): Expression {
    let left = parseCallExpression(parser);
    if (!parser.isCurrentType('DotToken') || left.kind !== 'IdentifierExpression' && left.kind !== 'NumberExpression') {
        return left;
    }
    left = {
        kind: 'DotExpression',
        identifier: left,
        properties: [],
        type: BasicVaderType.unknown,
        location: {...left.location},
    }
    while (parser.isCurrentType('DotToken') || parser.isCurrentType('OpenSquareBracket')) {
        if (parser.isCurrentType('DotToken')) {
            parser.expect('DotToken');
            const propertyName = parser.expect('Identifier');
            if (parser.isCurrentType('OpenRoundBracket')) {
                const result = parseCallArguments(parser);
                left = {
                    kind: 'CallExpression',
                    functionName: propertyName.value,
                    location: {
                        start: left.location.start,
                        end: parser.previous.location.end,
                        file: propertyName.location.file
                    },
                    parameters: [
                        left,
                        ...result
                    ]
                } as CallExpression
            } else if (left.kind === 'DotExpression') {
                (left as DotExpression).properties.push({
                    name: propertyName.value,
                    type: BasicVaderType.unknown,
                    location: propertyName.location
                })
            } else {
                parser.reportError(`Could not handle dot expression with kind ${left.kind}`, left.location);
            }
        } else if (parser.isCurrentType('OpenSquareBracket')) {
            left = parseArrayIndexBracketExpression(parser, left)
        }
    }
    left.location.end = parser.previous.location.end;
    return left;
}

function parseCallExpression(parser: Parser): Expression {
    let left = parsePrimaryExpression(parser);
    if (left.kind === 'IdentifierExpression' && parser.isCurrentType("OpenRoundBracket")) {
        const parameters = parseCallArguments(parser);
        return {
            kind: 'CallExpression',
            type: BasicVaderType.unknown,
            functionName: left.identifier,
            parameters,
            location: {
                start: left.location.start,
                end: parser.previous.location.end,
                file: left.location.file,
            }
        }
    }
    return left;
}

function parsePrimaryExpression(parser: Parser): Expression {
    if (parser.isCurrentType('Identifier')) {
        const token = parser.expect('Identifier')
        return {
            kind: "IdentifierExpression",
            type: BasicVaderType.unknown,
            identifier: token.value,
            location: {
                start: token.location.start,
                end: token.location.end,
                file: token.location.file,
            }
        }
    }

    if (parser.isCurrentType('NumberToken')) {
        const token = parser.expect('NumberToken')
        let type: VaderType;
        // TODO need to handle more types
        if (token.value.indexOf('.') > -1) {
            type = BasicVaderType.f32
        } else {
            type = BasicVaderType.u32
        }
        return {
            kind: "NumberExpression",
            type,
            value: Number(token.value),
            location: {
                start: token.location.start,
                end: token.location.end,
                file: token.location.file,
            }
        }
    }

    if (parser.isCurrentType('StringLiteral')) {
        const token = parser.expect('StringLiteral')
        return {
            kind: "StringExpression",
            type: BasicVaderType.string,
            value: token.value.replaceAll('\\n', '\n'),
            location: {
                start: token.location.start,
                end: token.location.end,
                file: token.location.file,
            }
        }
    }

    if (parser.isCurrentType('OpenRoundBracket')) {
        parser.expect('OpenRoundBracket');
        const left = parseExpression(parser);
        parser.expect('CloseRoundBracket');
        return left;
    }

    if (parser.isCurrentKeyword('true')) {
        const token = parser.expectKeyword('true')
        return {
            kind: "NumberExpression",
            type: BasicVaderType.boolean,
            value: 1,
            location: {...token.location}
        }
    }

    if (parser.isCurrentKeyword('false')) {
        const token = parser.expectKeyword('false')
        return {
            kind: "NumberExpression",
            type: BasicVaderType.boolean,
            value: 0,
            location: {...token.location}
        }
    }

    if (parser.isCurrentKeyword('if')) {
        return parseIfExpression(parser);
    }

    if (parser.isCurrentKeyword('struct')) {
        return parseStructDeclaration(parser);
    }

    if (parser.isCurrentKeyword('fn')) {
        return parseFunctionDeclaration(parser);
    }

    if (parser.isCurrentType('OpenSquareBracket')) {
        return parseArrayInitializationExpression(parser);
    }

    if (parser.isCurrentType('Decorator')) {
        const token = parser.expect('Decorator');
        if (token.value === 'file') {
            return parseFileDecorator(parser, token);
        } else {
            parser.reportError(`Unknown decorator: ${token.value}`, token.location);
        }
    }

    parser.reportError(`unknown expression ${parser.current.value}`, parser.current.location)
}

//////////////////

function parseFileDecorator(parser: Parser, decorator: Token): StringExpression {
    parser.expect('OpenRoundBracket');
    const file_token = parser.expect('StringLiteral');
    parser.expect('CloseRoundBracket');
    try {
        const resolved = parser.resolver.resolve(file_token.value);
        return {
            kind: 'StringExpression',
            type: BasicVaderType.string,
            value: resolved.content,
            location: decorator.location,
        }
    } catch (e) {
        parser.reportError(`Unresolved file ${file_token.value}`, file_token.location)
    }
}

function parseIfExpression(parser: Parser): Expression {
    return parseIfStatement(parser, 'ConditionalExpression') as Expression;
}


function parseArrayIndexBracketExpression(parser: Parser, left: Expression) {
    const array: ArrayIndexExpression = {
        kind: 'ArrayIndexExpression',
        indexes: [],
        identifier: left,
        location: {...left.location},
        type: BasicVaderType.unknown
    }
    do {
        parser.expect('OpenSquareBracket')
        array.indexes.push(parseExpression(parser));
        parser.expect('CloseSquareBracket')
    } while (parser.isCurrentType('OpenSquareBracket'))
    return array;
}


/**
 * struct {[identifier: type]*}
 * @param parser
 */
function parseStructDeclaration(parser: Parser) {
    const token = parser.expectKeyword('struct');
    const structStatement: StructDeclarationExpression = {
        kind: 'StructDeclarationExpression',
        type: {
            kind: 'struct',
            parameters: []
        },
        location: {
            start: token.location.start,
            end: parser.previous.location.end,
            file: token.location.file,
        }
    };

    parser.expect('OpenCurlyBracket');
    while (!parser.isCurrentType('CloseCurlyBracket')) {
        const name = parser.expect('Identifier').value
        parser.expect('ColonToken');
        const type = parseType(parser)
        structStatement.type.parameters.push({name, type})
    }
    parser.expect('CloseCurlyBracket');
    return structStatement;
}


function parseArrayInitializationExpression(parser: Parser): Expression {
    const token = parser.current;
    const type = parseType(parser)
    if (type.kind !== 'array') {
        throw new Error(`unreachable ${type.kind} should be an array.`);
    }

    const initialValue: Expression[] = []
    const initialValueToken = parser.current;
    let hasInitialValue = false;
    if (parser.isCurrentType('OpenCurlyBracket')) {
        parser.expect('OpenCurlyBracket')
        hasInitialValue = true;
        while (!parser.isCurrentType('CloseCurlyBracket')) {
            initialValue.push(parseMemberExpression(parser));
            if (!parser.isCurrentType('CommaToken')) {
                break
            }
            parser.expect('CommaToken');
        }
        parser.expect('CloseCurlyBracket')
    }

    if (!type.length) {
        if (!hasInitialValue) {
            parser.reportError(`Array initial value is mandatory when creating an array with no specified size`, parser.previous.location);
        } else {
            type.length = {
                kind: 'NumberExpression',
                type: BasicVaderType.u32,
                value: initialValue.length,
                location: {
                    ...initialValueToken.location,
                    end: parser.current.location.end
                }
            } satisfies NumberExpression;
        }
    } else if (hasInitialValue) {
        if (type.length.kind === 'NumberExpression' && type.length.value !== initialValue.length) {
            parser.reportError(`Type mismatch between array size and initial value size`, parser.previous.location);
        }
    }

    return {
        kind: 'ArrayDeclarationExpression',
        type: type,
        value: hasInitialValue ? initialValue : undefined,
        location: {
            ...token.location,
            end: parser.previous.location.end
        }
    } satisfies ArrayDeclarationExpression

}

function parseFunctionDeclaration(parser: Parser): Expression {
    const token = parser.expectKeyword('fn');
    const parameters = parseFunctionArguments(parser);
    let returnType: VaderType = BasicVaderType.void;
    if (parser.isCurrentType('LambdaArrowToken')) {
        parser.expect('LambdaArrowToken')
        returnType = parseType(parser);
    }
    const type: FunctionVaderType = {
        kind: 'function',
        decorators: [...decorators],
        parameters,
        returnType
    }
    decorators.length = 0;
    const body = type.decorators.includes('intrinsic') ? [] : parseBlockStatement(parser);

    return {
        kind: 'FunctionDeclarationExpression',
        type,
        body,
        location: {
            start: token.location.start,
            end: parser.previous.location.end,
            file: token.location.file,
        }
    }
}

function createBinaryExpression(left: Expression, right: Expression, operatorToken: Token): Expression {
    return {
        kind: "BinaryExpression",
        operator: operatorToken.value,
        type: BasicVaderType.unknown,
        lhs: left,
        rhs: right,
        location: {
            start: left.location.start,
            end: right.location.end,
            file: left.location.file
        }
    } satisfies BinaryExpression;
}
