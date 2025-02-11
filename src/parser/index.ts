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
import {ErrorReporter} from "../utils/errors.ts";
import fs from "node:fs";
import path from "node:path";

export class Parser {
    private tokens: Token[];
    private index = 0;
    public mainMethod: string | undefined = undefined;
    private reporter: ErrorReporter;
    private debug = true;
    private loadedFiles = new Set<string>();

    constructor(private content: string, source_path?: string) {
        this.reporter = new ErrorReporter(this.content);
        this.tokens = [...tokenize(content, source_path ?? 'memory://scratch')];
        //console.log(this.tokens)
    }

    private eat() {
        return this.tokens[++this.index];
    }

    loadFile(filename: string) {
        const normalized = path.normalize(filename + '.vader');
        if (this.loadedFiles.has(normalized)) {
            return
        }
        this.loadedFiles.add(normalized);
        const content = fs.readFileSync(normalized, {encoding: 'utf-8'})
        const tokens = [...tokenize(content, normalized)]
        this.tokens = [...this.tokens.slice(0, this.index), ...tokens.slice(0, -1), ...this.tokens.slice(this.index)]
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
            this.reportError(message, this.current.location)
        }
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
        scope: UnresolvedScope,
        location: {
            start: 0,
            end: 0, // need to be the last token location
            file: source_path,
        }
    }
    while (!parser.isCurrentType('EOF')) {
        program.body.push(parseStatement(parser))
    }
    const lastToken = parser.expect('EOF');
    program.location.end = lastToken.location.end;
    program.mainMethod = parser.mainMethod;
    return program;
}

const decorators: Decorator[] = [];

function parseStatement(parser: Parser): Statement {
    if (parser.isCurrentType('Identifier')) {
        return parseIdentifierStatement(parser);
    }
    if (parser.isCurrentKeyword('load')) {
        return parseLoadStatement(parser);
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
    let type: VaderType = {
        name: identifier,
        kind: 'raw'
    }
    while (parser.isCurrentType('OpenSquareBracket')) {
        parser.expect('OpenSquareBracket');
        if (parser.isCurrentType('CloseSquareBracket')) {
            parser.expect('CloseSquareBracket');
            type = {
                type,
                size: 0,
                kind: "array"
            }
        } else {
            const arraySize = parseExpression(parser);
            parser.expectTrue(arraySize.kind != "NumberExpression", 'Const array could be only initialized with a constant number');
            type = {
                type,
                size: (arraySize as NumberExpression).value,
                kind: "array"
            }
            parser.expect('CloseSquareBracket');
        }
    }

    return type
}


function parseLoadStatement(parser: Parser) {
    parser.expectKeyword('load');
    const pathToken = parser.expect("StringLiteral");
    parser.loadFile(pathToken.value)
    return parseStatement(parser);
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
        const token = parser.expect('EqualToken');
        const value = parseExpression(parser);
        return {
            kind: 'VariableAssignmentStatement',
            identifier: identifier.value,
            value,
            scope: UnresolvedScope,
            location: token.location
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
    let returnType: VaderType = BasicVaderType.void;
    if (parser.isCurrentType('LambdaArrowToken')) {
        parser.expect('LambdaArrowToken')
        returnType = parseType(parser);
    }
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
        scope: UnresolvedScope,
        location: {
            start: identifier.location.start,
            end: parser.current.location.start,
            file: identifier.location.file,
        }
    }
}

function parseFunctionArguments(parser: Parser): { name: string, type: VaderType }[] {
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

function parseVariableDeclarationAndAssignment(parser: Parser, isConstant: boolean, identifier: Token, type: VaderType): VariableDeclarationStatement {
    const value = parseExpression(parser);
    return {
        kind: 'VariableDeclarationStatement',
        name: identifier.value,
        isConstant,
        type: type,
        value,
        scope: UnresolvedScope,
        location: {
            start: identifier.location.start,
            end: parser.current.location.start,
            file: identifier.location.file,
        }
    }
}

function parseStruct(parser: Parser, identifier: Token) {
    parser.expectKeyword('struct');
    const structStatement: StructStatement = {
        kind: 'StructStatement',
        name: identifier.value,
        definition: [],
        scope: UnresolvedScope,
        location: {
            start: identifier.location.start,
            end: parser.current.location.start,
            file: identifier.location.file,
        }
    };

    parser.expect('OpenCurlyBracket');
    while (!parser.isCurrentType('CloseCurlyBracket')) {
        const attributeName = parser.expect('Identifier').value
        parser.expect('ColonToken');
        const typeName = parseType(parser)
        structStatement.definition.push({attributeName, typeName})
    }
    parser.expect('CloseCurlyBracket');
    return structStatement;
}

function parseForStatement(parser: Parser): Statement {
    const forToken = parser.expectKeyword('for');
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
        scope: UnresolvedScope,
        location: {
            start: forToken.location.start,
            end: parser.current.location.start,
            file: forToken.location.file,
        }
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
            scope: UnresolvedScope,
            location: {
                start: token.location.start,
                end: parser.current.location.start, // FIXME: Wrong need to be the full dotted expression
                file: token.location.file,
            }
        }
    }

    if (parser.isCurrentType('Identifier')) {
        const token = parser.expect('Identifier')
        lhs = {
            kind: "VariableExpression",
            type: BasicVaderType.unknown,
            value: token.value,
            scope: UnresolvedScope,
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
        lhs = {
            kind: "NumberExpression",
            type,
            value: Number(token.value),
            scope: UnresolvedScope,
            location: {
                start: token.location.start,
                end: token.location.end,
                file: token.location.file,
            }
        }
    }

    if (parser.isCurrentType('StringLiteral')) {
        const token = parser.expect('StringLiteral')
        lhs = {
            kind: "StringExpression",
            type: BasicVaderType.string,
            value: token.value.replaceAll('\\n', '\n'),
            scope: UnresolvedScope,
            location: {
                start: token.location.start,
                end: token.location.end,
                file: token.location.file,
            }
        }
    }

    if (!lhs) {
        parser.reportError(`Unknown expression: ${parser.current.type}`, parser.current.location)
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
            const {value: operator, location} = parser.expect(token);
            const rhs = parseExpression(parser);
            return {
                kind: 'BinaryExpression',
                operator,
                type: BasicVaderType.unknown,
                lhs,
                rhs,
                scope: UnresolvedScope,
                location
            }
        }
    }
    return lhs;
}

function parseReturnStatement(parser: Parser): ReturnStatement {
    const token = parser.expectKeyword('return');

    return {
        kind: 'ReturnStatement',
        expression: parseExpression(parser),
        scope: UnresolvedScope,
        location: {
            start: token.location.start,
            end: token.location.end,
            file: token.location.file,
        }
    };
}


function parseIfExpression(parser: Parser) {
    const ifToken = parser.expectKeyword('if');
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
        scope: UnresolvedScope,
        location: {
            start: ifToken.location.start,
            end: 0,
            file: ifToken.location.file,
        }
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
    ifBlock.location.end = parser.current.location.start;
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
        scope: UnresolvedScope,
        location: {
            start: identifier.location.start,
            end: parser.current.location.start,
            file: identifier.location.file,
        }
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
