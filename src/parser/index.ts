import {keywords, tokenize} from "../tokens";
import type {Token} from "../tokens/types.ts";
import {
    BasicVaderType,
    type CallExpression,
    type ConditionalExpression,
    type Decorator,
    type Expression,
    type FunctionDeclaration,
    type NumberExpression,
    type Program,
    type ReturnStatement,
    type Statement,
    type StructStatement,
    type VaderType,
    type VariableDeclarationStatement,
} from "./types.ts";
import {UnresolvedScope} from "../resolver/scope.ts";

export class Parser {
    private readonly tokens: Token[];
    private index = 0;
    public mainMethod: string | undefined = undefined;

    constructor(private content: string, private source_path?: string) {
        this.tokens = [...tokenize(content)];
        //console.log(this.tokens)
    }

    private eat() {
        return this.tokens[++this.index];
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

    expectTrue(value: boolean, message: string) {
        if (!value) {
            this.reportError(message)
        }
    }

    private findLocation(offset: number) {
        const lines = this.content.split('\n');
        let row = 0;
        let currentOffset = 0;
        for (let line of lines) {
            const end = currentOffset + line.length
            if (offset >= currentOffset && offset <= end) {
                return { line: row, column: offset - currentOffset }
            }
            row++
            currentOffset += line.length + 1;
        }
        throw new Error(`Could not determine location of ${offset}`)
    }

    reportError(message: string, token: Token = this.current): never {
        let { line, column } = this.findLocation(token.offset);
        line += 1; // There is a +1 offset in IDE or Code editor
        column += 1; // There is a +1 offset in IDE or Code editor
        if (this.source_path) {
            console.log(`ERROR: ${this.source_path}(${line},${column - token.value.length}) ${message}`);
        } else {
            console.log(`ERROR:${line}:${column - token.value.length}: ${message}`);
        }
        throw new Error('debug')
        process.exit(1);
    }

    expect(type: Token['type'], message?: string): Token {
        if (this.current?.type === type) {
            const c = this.current
            this.eat();
            return c;
        }
        this.reportError(message ?? `Expected tokens ${type} but got ${this.current.type}`);
    }

    get current(): Token {
        return this.tokens[this.index];
    }

    get next(): Token {
        return this.tokens[this.index + 1];
    }
}

export function parseProgram(content: string, source_path: string): Program {
    const parser = new Parser(content, source_path);
    const program: Program = {
        kind: 'Program',
        body: [],
        mainMethod: undefined,
        scope: UnresolvedScope
    }
    while (!parser.isCurrentType('EOF')) {
        program.body.push(parseStatement(parser))
    }
    parser.expect('EOF');
    program.mainMethod = parser.mainMethod;
    return program;
}

const decorators: Decorator[] = [];

function parseStatement(parser: Parser): Statement {
    if (parser.isCurrentType('Identifier')) {
        return parseIdentifierStatement(parser);
    }
    if (parser.isCurrentKeyword('return')) {
        return parseReturnStatement(parser)
    }
    if (parser.isCurrentKeyword('for')) {
        return parseForStatement(parser)
    }
    if (parser.isCurrentType('Decorator')) {
        const token = parser.expect('Decorator');
        if (token.value === 'intrinsic') {
            decorators.push(token.value)
        } else {
            throw new Error(`Unknown decorator: ${token.value}`);
        }
        return parseStatement(parser)
    }
    return parseExpression(parser)
}

function parseType(parser: Parser): VaderType {
    const identifier = parser.expect('Identifier').value;
    let arrayData: VaderType['array'] = undefined;
    if (parser.isCurrentType('OpenSquareBracket')) {
        parser.expect('OpenSquareBracket');
        if (parser.isCurrentType('CloseSquareBracket')) {
            parser.expect('CloseSquareBracket');
            arrayData = {
                arrayLength: 0
            }
        } else {
            const arraySize = parseExpression(parser);
            parser.expectTrue(arraySize.kind != "NumberExpression", 'Const array could be only initialized with a constant number');
            arrayData = {
                arrayLength: (arraySize as NumberExpression).value
            }
        }
    }

    return {
        name: identifier,
        array: arrayData
    }
}

function parseIdentifierStatement(parser: Parser): Statement {
    if (parser.next.type === 'OpenRoundBracket') {
        return parseCallExpression(parser);
    }
    const identifier = parser.expect('Identifier');
    if (parser.isCurrentType('ColonToken')) {
        parser.expect('ColonToken');
        // id ::
        if (parser.isCurrentType('ColonToken')) {
            parser.expect('ColonToken');
            return parseVariableDeclaration(parser, true, identifier, BasicVaderType.unknown)
        }
        // id :=
        if (parser.isCurrentType('EqualToken')) {
            parser.expect('EqualToken');
            return parseVariableDeclaration(parser, false, identifier, BasicVaderType.unknown);
        }
        const type = parseType(parser);
        // id :type :
        if (parser.isCurrentType('ColonToken')) {
            parser.expect('ColonToken');
            return parseVariableDeclaration(parser, true, identifier, type)
        }
        // id :type =
        if (parser.isCurrentType('EqualToken')) {
            parser.expect('EqualToken');
            return parseVariableDeclaration(parser, false, identifier, type);
        }
    }

    if (parser.isCurrentType('EqualToken')) {
        parser.expect('EqualToken');
        const value = parseExpression(parser);
        return {
            kind: 'VariableAssignmentStatement',
            identifier: identifier.value,
            value,
            scope: UnresolvedScope
        }
    }
    return parseExpression(parser)
}

function parseVariableDeclaration(parser: Parser, isConstant: boolean, identifier: Token, type: VaderType): Statement {
    if (parser.isCurrentKeyword('fn')) {
        parser.expectTrue(isConstant, `Function declaration could only be used with :: operator`)
        return parseFunctionDeclaration(parser, identifier)
    }
    if (parser.isCurrentKeyword('struct')) {
        parser.expectTrue(isConstant, `Struct declaration could only be used with :: operator`)
        return parseStruct(parser, identifier)
    }
    return parseVariableDeclarationAndAssignment(parser, isConstant, identifier, type);
}

function parseFunctionDeclaration(parser: Parser, identifier: Token): FunctionDeclaration {
    if (identifier.value === 'main') {
        parser.mainMethod = identifier.value;
    }
    parser.expectKeyword('fn')
    const parameters = parseFunctionArguments(parser);
    parser.expect('LambdaArrowToken')
    const returnType = parseType(parser);
    const functionDecorators = [...decorators];
    decorators.length = 0;
    const body = functionDecorators.includes('intrinsic') ? [] : parseBlockStatement(parser);
    return {
        kind: 'FunctionDeclaration',
        name: identifier.value,
        parameters,
        returnType,
        decorators: functionDecorators,
        body,
        scope: UnresolvedScope
    }
}

function parseFunctionArguments(parser: Parser): { name: string, type: VaderType }[] {
    parser.expect('OpenRoundBracket')
    const parameters: { name: string, type: VaderType }[] = [];
    while (!parser.isCurrentType('CloseRoundBracket')) {
        const identifier = parser.expect('Identifier')
        parser.expect('ColonToken');
        const type = parseType(parser);
        parameters.push({ name: identifier.value, type })
        if (!parser.isCurrentType('CommaToken')) {
            break
        }
        parser.expect('CommaToken');
    }
    parser.expect('CloseRoundBracket')
    return parameters;
}

function parseVariableDeclarationAndAssignment(parser: Parser, isConstant: boolean, identifier: Token, type: VaderType): VariableDeclarationStatement {
    const value = parseExpression(parser);
    return {
        kind: 'VariableDeclarationStatement',
        name: identifier.value,
        isConstant,
        type: type,
        value,
        scope: UnresolvedScope
    }
}

function parseStruct(parser: Parser, identifier: Token) {
    parser.expectKeyword('struct');
    const structStatement: StructStatement = {
        kind: 'StructStatement',
        name: identifier.value,
        definition: [],
        scope: UnresolvedScope
    };

    parser.expect('OpenCurlyBracket');
    while (!parser.isCurrentType('CloseCurlyBracket')) {
        const attributeName = parser.expect('Identifier').value
        parser.expect('ColonToken');
        const typeName = parseType(parser)
        structStatement.definition.push({ attributeName, typeName })
    }
    parser.expect('CloseCurlyBracket');
    return structStatement;
}

function parseForStatement(parser: Parser): Statement {
    parser.expectKeyword('for');
    let hasOpeningParenthesis = parser.isCurrentType('OpenRoundBracket');
    if (hasOpeningParenthesis) {
        parser.expect('OpenRoundBracket');
    }
    const initialization = parseIdentifierStatement(parser)
    parser.expect('SemicolonToken')
    const condition = parseExpression(parser);
    parser.expect('SemicolonToken')
    const iteration = parseIdentifierStatement(parser)
    if (hasOpeningParenthesis) {
        parser.expect('CloseRoundBracket')
    }
    const body = parseBlockStatement(parser);
    return {
        kind: 'ForStatement',
        initialization,
        condition,
        iteration,
        body,
        scope: UnresolvedScope
    }

}

function parseExpression(parser: Parser): Expression {
    let lhs: Expression | null = null;

    if (parser.isCurrentKeyword('if')) {
        lhs = parseIfExpression(parser)
    }

    if (parser.isCurrentType('OpenRoundBracket')) {
        parser.expect('OpenRoundBracket');
        lhs = parseExpression(parser);
        parser.expect('CloseRoundBracket');
    }

    if (parser.isCurrentType('Identifier') && parser.next?.type === 'OpenRoundBracket') {
        lhs = parseCallExpression(parser);
    }

    if (parser.isCurrentType('Identifier') && parser.next?.type === 'DotToken') {
        const token = parser.expect('Identifier');
        // TODO need to handle dot expression this.x.y.z
        // TODO need to handle array value x[2]
        lhs = {
            kind: 'VariableExpression',
            type: BasicVaderType.unknown,
            value: token.value,
            scope: UnresolvedScope
        }
    }

    if (parser.isCurrentType('Identifier')) {
        const token = parser.expect('Identifier')
        lhs = {
            kind: "VariableExpression",
            type: BasicVaderType.unknown,
            value: token.value,
            scope: UnresolvedScope
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
        lhs = {
            kind: "NumberExpression",
            type,
            value: Number(token.value),
            scope: UnresolvedScope
        }
    }

    if (parser.isCurrentType('StringLiteral')) {
        const token = parser.expect('StringLiteral')
        lhs = {
            kind: "StringExpression",
            type: { name: 'u8', array: { arrayLength: token.value.length } },
            value: token.value.replaceAll('\\n', '\n'),
            scope: UnresolvedScope
        }
    }

    if (!lhs) {
        parser.reportError(`Unknown expression: ${parser.current.type}`)
    }

    lhs = parseBinaryExpression(parser, lhs)

    return lhs
}

function parseBinaryExpression(parser: Parser, lhs: Expression): Expression {
    const binaryToken = new Set<Token['type']>([
        'StarToken',
        'SlashToken',
        'PlusToken',
        'BitwiseAndToken',
        'BitwiseOrToken',
        'BooleanAndToken',
        'BooleanOrToken',
        'DoubleEqualToken',
        'BangEqualToken',
        'LowerThanToken',
        'LowerThanEqualToken',
        'HigherThanToken',
        'HigherThanEqualToken',
    ]);
    for (const token of binaryToken) {
        if (parser.isCurrentType(token)) {
            const { value: operator } = parser.expect(token);
            const rhs = parseExpression(parser);
            return {
                kind: 'BinaryExpression',
                operator,
                type: BasicVaderType.unknown,
                lhs,
                rhs,
                scope: UnresolvedScope
            }
        }
    }
    return lhs;
}

function parseReturnStatement(parser: Parser): ReturnStatement {
    parser.expectKeyword('return');

    return {
        kind: 'ReturnStatement',
        expression: parseExpression(parser),
        scope: UnresolvedScope
    };
}


function parseIfExpression(parser: Parser) {
    parser.expectKeyword('if');
    let hasOpeningParenthesis = parser.isCurrentType('OpenRoundBracket');
    if (hasOpeningParenthesis) {
        parser.expect('OpenRoundBracket');
    }
    const ifCondition = parseExpression(parser);
    if (hasOpeningParenthesis) {
        parser.expect('CloseRoundBracket');
    }
    const ifStatements = parseBlockStatement(parser);
    const ifBlock: ConditionalExpression = {
        kind: 'ConditionalExpression',
        type: BasicVaderType.unknown, // need to be resolved
        branches: [{
            body: ifStatements,
            condition: ifCondition
        }],
        scope: UnresolvedScope
    }
    while (parser.isCurrentKeyword('elif')) {
        parser.expectKeyword('elif')
        hasOpeningParenthesis = parser.isCurrentType('OpenRoundBracket');
        if (hasOpeningParenthesis) {
            parser.expect('OpenRoundBracket');
        }
        const condition = parseExpression(parser)
        if (hasOpeningParenthesis) {
            parser.expect('CloseRoundBracket');
        }
        const body = parseBlockStatement(parser);
        ifBlock.branches.push({
            condition,
            body
        })
    }
    if (parser.isCurrentKeyword('else')) {
        parser.expectKeyword('else')
        ifBlock.elseBody = parseBlockStatement(parser)
    }
    return ifBlock;
}


function parseCallExpression(parser: Parser): CallExpression {
    const identifier = parser.expect('Identifier')
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
    return {
        kind: 'CallExpression',
        type: BasicVaderType.unknown, // Need to be resolved later
        functionName: identifier.value,
        parameters,
        scope: UnresolvedScope
    }
}

function parseBlockStatement(parser: Parser): Statement[] {
    parser.expect('OpenCurlyBracket');
    const statements: Statement[] = []
    while (!parser.isCurrentType('CloseCurlyBracket')) {
        statements.push(parseStatement(parser))
    }
    parser.expect('CloseCurlyBracket');
    return statements;
}
