import {keywords, tokenize} from "../tokens";
import type {Decorator, Token} from "../tokens/types.ts";
import {
    type ArrayDeclarationExpression,
    type ArrayIndexExpression,
    type ArrayVaderType,
    BasicVaderType,
    type CallExpression,
    type ConditionalExpression,
    type ConditionalStatement,
    type Expression,
    type FunctionDeclarationExpression,
    type FunctionVaderType,
    type Program,
    type ReturnStatement,
    type Statement,
    type StringExpression,
    type StructDeclarationExpression,
    type StructInstantiationExpression,
    type VaderType,
    type VariableDeclarationStatement,
} from "./types.ts";
import {UnresolvedScope} from "../resolver/scope.ts";
import {ErrorReporter} from "../utils/errors.ts";
import type {ModuleResolver} from "../resolver/module_resolver.ts";

export class Parser {
    private tokens: Token[] = [];
    private index = 0;
    public mainMethod: string | undefined = undefined;
    private reporter: ErrorReporter;
    private debug = true;
    private loadedFiles = new Set<string>();

    constructor(public readonly resolver: ModuleResolver) {
        this.reporter = new ErrorReporter(resolver);
    }

    private eat() {
        return this.tokens[++this.index];
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

    get previous(): Token {
        return this.tokens[this.index - 1];
    }

    get next(): Token {
        return this.tokens[this.index + 1];
    }
}

export function parseProgram(entryFile: string, resolver: ModuleResolver): Program {
    const parser = new Parser(resolver);
    parser.loadVaderFile(entryFile)
    const program: Program = {
        kind: 'Program',
        body: [],
        mainMethod: undefined,
        scope: UnresolvedScope,
        location: parser.current.location
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
    if (parser.isCurrentKeyword('return')) {
        return parseReturnStatement(parser)
    }
    if (parser.isCurrentKeyword('for')) {
        return parseForStatement(parser)
    }
    if (parser.isCurrentKeyword('if')) {
        return parseIfStatement(parser)
    }
    if (parser.isCurrentType('Decorator')) {
        const token = parser.expect('Decorator');
        if (token.value === 'intrinsic') {
            decorators.push(token.value)
        } else if (token.value === 'load') {
            const pathToken = parser.expect("StringLiteral");
            parser.loadVaderFile(pathToken.value)
        } else if (token.value === 'file') {
            parser.reportError(`@file decorator is not applicable as a statement`, token.location);
        } else {
            parser.reportError(`Unknown decorator: ${token.value}`, token.location);
        }
        return parseStatement(parser)
    }
    return parseExpression(parser)
}

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
            scope: UnresolvedScope
        }
    } catch (e) {
        parser.reportError(`Unresolved file ${file_token.value}`, file_token.location)
    }
}


function parseType(parser: Parser): VaderType {
    const identifier = parser.expect('Identifier').value;
    let type: VaderType = {
        kind: 'unknown',
        name: identifier,
    }
    if (identifier in BasicVaderType) {
        type = (BasicVaderType as any)[identifier];
    }
    if (parser.isCurrentType('OpenSquareBracket')) {
        type = {
            kind: 'array',
            type,
        } satisfies ArrayVaderType
        while (parser.isCurrentType('OpenSquareBracket')) {
            parser.expect('OpenSquareBracket')
            if (parser.isCurrentType('UnderscoreToken')) {
                parser.expect('UnderscoreToken');
                type.length = -1;
            } else if (parser.isCurrentType('NumberToken')) {
                type.length = Number(parser.expect('NumberToken').value);
                if (type.length % 1 || type.length < 0) {
                    parser.reportError(`Wrong size for the array. Should be a positive integer`, parser.previous.location);
                }
            }
            parser.expect('CloseSquareBracket');
        }
    }
    return type
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
        const value = parseFunctionDeclarationExpression(parser)
        return parseVariableDeclarationAndAssignment(parser, isConstant, identifier, type, value)
    }
    if (parser.isCurrentKeyword('struct')) {
        parser.expectTrue(isConstant, `Struct declaration could only be used with :: operator`)
        const value = parseStructDeclaration(parser)
        return parseVariableDeclarationAndAssignment(parser, isConstant, identifier, type, value)
    }
    if (parser.isCurrentKeyword('if')) {
        const value = parseIfStatement(parser, 'ConditionalExpression');
        return parseVariableDeclarationAndAssignment(parser, isConstant, identifier, type, {
            ...value,
            kind: 'ConditionalExpression'
        });
    }
    if (parser.isCurrentType('Identifier') && parser.next.type === 'OpenCurlyBracket') {
        const value = parseStructInstantiation(parser);
        return parseVariableDeclarationAndAssignment(parser, isConstant, identifier, type, value);
    }
    if (parser.isCurrentType('Identifier') && parser.next.type === 'OpenSquareBracket') {
        const value = parseArrayInitializationExpression(parser);
        return parseVariableDeclarationAndAssignment(parser, isConstant, identifier, type, value);
    }
    return parseVariableDeclarationAndAssignment(parser, isConstant, identifier, type);
}

function parseArrayInitializationExpression(parser: Parser): Expression {
    const token = parser.current;
    const type = parseType(parser)
    if (type.kind !== 'array') {
        throw new Error(`unreachable ${type.kind} should be an array.`);
    }

    const initialValue: Expression[] = []
    let hasInitialValue = false;
    if (parser.isCurrentType('OpenCurlyBracket')) {
        parser.expect('OpenCurlyBracket')
        hasInitialValue = true;
        while (!parser.isCurrentType('CloseCurlyBracket')) {
            initialValue.push(parseExpression(parser));
            if (!parser.isCurrentType('CommaToken')) {
                break
            }
            parser.expect('CommaToken');
        }
        parser.expect('CloseCurlyBracket')
    }

    if (type.length && type.length < 0) {
        if (!hasInitialValue) {
            parser.reportError(`Array initial value is mandatory when creating an array with no specified size`, parser.previous.location);
        } else {
            type.length = initialValue.length;
        }
    } else if (hasInitialValue && type.length !== initialValue.length) {
        parser.reportError(`Type mismatch between array size and initial value size`, parser.previous.location);
    }

    return {
        kind: 'ArrayDeclarationExpression',
        type: type,
        value: hasInitialValue ? initialValue : undefined,
        scope: UnresolvedScope,
        location: {
            ...token.location,
            end: parser.previous.location.end
        }
    } satisfies ArrayDeclarationExpression
}

function parseArrayIndexExpression(parser: Parser) {
    const token = parser.expect('Identifier');
    const left: ArrayIndexExpression = {
        kind: 'ArrayIndexExpression',
        indexes: [],
        identifier: token.value,
        location: {...token.location},
        scope: UnresolvedScope,
        type: BasicVaderType.unknown
    }
    do {
        parser.expect('OpenSquareBracket')
        left.indexes.push(parseExpression(parser));
        parser.expect('CloseSquareBracket')
    } while (parser.isCurrentType('OpenSquareBracket'))
    return left;
}

function parseStructInstantiation(parser: Parser) {
    const structType = parser.expect('Identifier');
    const instance: StructInstantiationExpression = {
        kind: 'StructInstantiationExpression',
        parameters: [],
        structName: structType.value,
        type: BasicVaderType.unknown,
        location: {
            ...structType.location
        },
        scope: UnresolvedScope,
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


function parseFunctionDeclarationExpression(parser: Parser): FunctionDeclarationExpression {
    const token = parser.expectKeyword('fn')
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
        scope: UnresolvedScope,
        location: {
            start: token.location.start,
            end: parser.previous.location.end,
            file: token.location.file,
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

function parseVariableDeclarationAndAssignment(parser: Parser, isConstant: boolean, identifier: Token, type: VaderType, value?: Expression): VariableDeclarationStatement {
    if (!value) {
        value = parseExpression(parser);
    }
    if (identifier.value === 'main' && value?.type.kind === 'function') {
        parser.mainMethod = identifier.value;
    }
    return {
        kind: 'VariableDeclarationStatement',
        name: identifier.value,
        isConstant,
        type: type,
        value,
        scope: UnresolvedScope,
        location: {
            start: identifier.location.start,
            end: parser.previous.location.end,
            file: identifier.location.file,
        }
    }
}

function parseStructDeclaration(parser: Parser) {
    const token = parser.expectKeyword('struct');
    const structStatement: StructDeclarationExpression = {
        kind: 'StructDeclarationExpression',
        type: {
            kind: 'struct',
            parameters: []
        },
        scope: UnresolvedScope,
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
            end: parser.previous.location.end,
            file: forToken.location.file,
        }
    }

}

function parseDotExpression(parser: Parser, from: Expression): Expression {
    if (from.kind !== 'VariableExpression' && from.kind !== 'NumberExpression') {
        parser.reportError(`Attempt to use a dot expression on ${from.kind}`, from.location);
    }

    let left: Expression
    if (from.kind === 'VariableExpression') {
        left = {
            kind: 'DotExpression',
            properties: [{
                name: from.value,
                type: BasicVaderType.unknown,
                location: {...from.location},
            }],
            type: BasicVaderType.unknown,
            scope: UnresolvedScope,
            location: {...from.location},
        }
    } else {
        left = from;
    }

    while (parser.isCurrentType('DotToken')) {
        parser.expect('DotToken');
        const propertyName = parser.expect('Identifier');
        if (parser.isCurrentType('OpenRoundBracket')) {
            const result = parseCallArguments(parser);
            left = {
                kind: 'CallExpression',
                functionName: propertyName.value,
                scope: UnresolvedScope,
                location: {
                    start: propertyName.location.start,
                    end: parser.previous.location.end,
                    file: propertyName.location.file
                },
                parameters: [
                    left,
                    ...result
                ]
            } as CallExpression
        } else if (left.kind === 'DotExpression') {
            left.properties.push({
                name: propertyName.value,
                type: BasicVaderType.unknown,
                location: propertyName.location
            })
        } else {
            parser.reportError(`Could not handle dot expression with kind ${left.kind}`, left.location);
        }
    }
    left.location.end = parser.previous.location.end;
    return left;
}

function parseExpression(parser: Parser): Expression {
    let lhs: Expression | null = null;

    if (parser.isCurrentType('Decorator')) {
        const token = parser.expect('Decorator');
        if (token.value === 'file') {
            return parseFileDecorator(parser, token);
        } else {
            parser.reportError(`Unknown decorator: ${token.value}`, token.location);
        }
    }

    if (parser.isCurrentType('OpenRoundBracket')) {
        parser.expect('OpenRoundBracket');
        lhs = parseExpression(parser);
        parser.expect('CloseRoundBracket');
    }

    if (parser.isCurrentType('Identifier') && parser.next?.type === 'OpenRoundBracket') {
        lhs = parseCallExpression(parser);
    }

    if (parser.isCurrentType('Identifier') && parser.next?.type === 'OpenCurlyBracket') {
        lhs = parseStructInstantiation(parser);
    }

    if (parser.isCurrentType('Identifier') && parser.next?.type === 'OpenSquareBracket') {
        lhs = parseArrayIndexExpression(parser);
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

    if (parser.isCurrentType('DotToken')) {
        lhs = parseDotExpression(parser, lhs);
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
        location: token.location
    };
}

function parseIfStatement(parser: Parser, kind: 'ConditionalStatement' | 'ConditionalExpression' = 'ConditionalStatement') {
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
    const ifBlock = {
        kind,
        type: BasicVaderType.unknown, // need to be resolved
        ifBody: ifStatements,
        condition: ifCondition,
        scope: UnresolvedScope,
        location: {
            start: ifToken.location.start,
            end: 0,
            file: ifToken.location.file,
        }
    } satisfies ConditionalStatement | ConditionalExpression;
    let currentBlock: ConditionalStatement | ConditionalExpression = ifBlock;
    while (parser.isCurrentKeyword('elif')) {
        const elifToken = parser.expectKeyword('elif')
        hasOpeningParenthesis = parser.isCurrentType('OpenRoundBracket');
        if (hasOpeningParenthesis) {
            parser.expect('OpenRoundBracket');
        }
        const condition = parseExpression(parser)
        if (hasOpeningParenthesis) {
            parser.expect('CloseRoundBracket');
        }
        const body = parseBlockStatement(parser);
        currentBlock.elseBody = [{
            kind,
            type: BasicVaderType.unknown, // need to be resolved
            ifBody: body,
            condition: condition,
            scope: UnresolvedScope,
            location: {
                start: elifToken.location.start,
                end: 0,
                file: elifToken.location.file,
            }
        }]
        currentBlock = currentBlock.elseBody[0] as ConditionalStatement | ConditionalExpression;
    }
    if (parser.isCurrentKeyword('else')) {
        parser.expectKeyword('else')
        currentBlock.elseBody = parseBlockStatement(parser)
    }
    ifBlock.location.end = parser.previous.location.end;
    return ifBlock;
}


function parseCallExpression(parser: Parser): CallExpression {
    const identifier = parser.expect('Identifier')
    const parameters = parseCallArguments(parser);
    return {
        kind: 'CallExpression',
        type: BasicVaderType.unknown, // Need to be resolved later
        functionName: identifier.value,
        parameters,
        scope: UnresolvedScope,
        location: {
            start: identifier.location.start,
            end: parser.previous.location.end,
            file: identifier.location.file,
        }
    }
}

function parseCallArguments(parser: Parser) {
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

function parseBlockStatement(parser: Parser): Statement[] {
    parser.expect('OpenCurlyBracket');
    const statements: Statement[] = []
    while (!parser.isCurrentType('CloseCurlyBracket')) {
        statements.push(parseStatement(parser))
    }
    parser.expect('CloseCurlyBracket');
    return statements;
}
