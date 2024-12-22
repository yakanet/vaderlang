import {keywords, tokenize} from "../tokens";
import type {Token} from "../tokens/types.ts";
import type {
    CallExpression,
    ConditionalExpression,
    Expression,
    FunctionDeclaration,
    Program,
    ReturnStatement,
    Statement,
    StructStatement,
    VariableDeclarationStatement
} from "./types.ts";

export class Parser {
    private readonly tokens: Token[];
    private index = 0;

    constructor(private content: string) {
        this.tokens = [...tokenize(content)];
    }

    private eat() {
        return this.tokens[++this.index];
    }

    expectKeyword(keyword: typeof keywords[number]) {
        const token = this.current();
        if (this.isCurrentKeyword(keyword)) {
            return this.eat();
        }
        throw new Error(`Expected keyword ${keyword} but get ${token.type}`)
    }

    isCurrentKeyword(keyword: typeof keywords[number]) {
        return this.current().type === 'Keyword' && this.current().value === keyword;
    }

    isCurrentType(type: Token['type']) {
        return this.current().type === type;
    }

    private findLocation(offset: number) {
        const lines = this.content.split('\n');
        let row = 0;
        let currentOffset = 0;
        for (let line of lines) {
            const end = currentOffset + line.length
            if (offset >= currentOffset && offset <= end) {
                return {line: row, column: offset - currentOffset}
            }
            row++
            currentOffset += line.length + 1;
        }
        throw new Error(`Could not determine location of ${offset}`)
    }

    reportError(message: string, token: Token = this.current()): never {
        const {line, column} = this.findLocation(token.offset);
        console.log(`ERROR:${line}:${column}: ${message}`);
        process.exit(1);
    }

    expect(type: Token['type']): Token {
        if (this.current()?.type === type) {
            const c = this.current()
            this.eat();
            return c;
        }

        this.reportError(`Expected tokens ${type} but got ${this.current().type}`);
    }

    private current(): Token {
        return this.tokens[this.index];
    }

    next() {
        return this.tokens[this.index + 1];
    }
}

export function parseProgram(content: string): Program {
    const parser = new Parser(content);
    const program: Program = {
        type: 'Program',
        body: [],
    }
    while (!parser.isCurrentType('EOF')) {
        program.body.push(parseStatement(parser))
    }
    parser.expect('EOF');
    return program;
}

function parseStatement(parser: Parser): Statement {
    if (parser.isCurrentKeyword('struct')) {
        return parseStruct(parser)
    }
    if (parser.isCurrentKeyword('fun')) {
        return parseFunction(parser)
    }
    if (parser.isCurrentKeyword('return')) {
        return parseReturnStatement(parser)
    }
    if (parser.isCurrentKeyword('var')) {
        return parseVariableDeclaration(parser)
    }
    if (parser.isCurrentKeyword('val')) {
        return parseVariableDeclaration(parser)
    }
    return parseExpression(parser)
}

function parseType(parser: Parser): string {
    return parser.expect('Identifier').value;
}

function parseStruct(parser: Parser) {
    parser.expectKeyword('struct');
    const structName = parser.expect('Identifier');
    parser.expect('OpenCurlyBracket');
    const structStatement: StructStatement = {
        type: 'StructStatement',
        name: structName.value,
        definition: []
    };
    while (!parser.isCurrentType('CloseCurlyBracket')) {
        const attributeName = parser.expect('Identifier').value
        parser.expect('ColonToken');
        const typeName = parseType(parser)
        structStatement.definition.push({attributeName, typeName})
    }
    parser.expect('CloseCurlyBracket');
    return structStatement;
}

function parseExpression(parser: Parser): Expression {
    let lhs: Expression | null = null;

    if (parser.isCurrentKeyword('if')) {
        lhs = parseIfExpression(parser)
    }

    if (parser.isCurrentType('NumberToken')) {
        const token = parser.expect('NumberToken')
        lhs = {
            type: "NumberExpression",
            value: Number(token.value),
        }
    }
    if (parser.isCurrentType('StringLiteral')) {
        const token = parser.expect('StringLiteral')
        lhs = {
            type: "StringExpression",
            value: token.value,
        }
    }
    if (parser.isCurrentType('Identifier')) {
        if (parser.next()?.type === 'OpenParenthesis') {
            lhs = parseCallExpression(parser);
        } else {
            const token = parser.expect('Identifier')
            lhs = {
                type: "VariableExpression",
                value: token.value,
            }
        }
    }

    if (!lhs) {
        parser.reportError(`Unknown expression`)
    }
    if (parser.isCurrentType('PlusToken')) {
        parser.expect('PlusToken');
        const rhs = parseExpression(parser);
        lhs = {
            type: 'BinaryExpression',
            operator: '+',
            lhs,
            rhs
        }
    }
    if (parser.isCurrentType('StarToken')) {
        parser.expect('StarToken');
        const rhs = parseExpression(parser);
        lhs = {
            type: 'BinaryExpression',
            operator: '*',
            lhs,
            rhs
        }
    }
    if (parser.isCurrentType('DivideToken')) {
        parser.expect('DivideToken');
        const rhs = parseExpression(parser);
        lhs = {
            type: 'BinaryExpression',
            operator: '/',
            lhs,
            rhs
        }
    }
    if (parser.isCurrentType('DoubleEqualToken')) {
        parser.expect('DoubleEqualToken');
        const rhs = parseExpression(parser);
        lhs = {
            type: 'BinaryExpression',
            operator: '==',
            lhs,
            rhs
        }
    }
    return lhs
}

function parseReturnStatement(parser: Parser): ReturnStatement {
    parser.expectKeyword('return');

    return {
        type: 'ReturnStatement',
        expression: parseExpression(parser),
    };
}


function parseIfExpression(parser: Parser) {
    parser.expectKeyword('if');
    parser.expect('OpenParenthesis');
    const ifCondition = parseExpression(parser);
    parser.expect('CloseParenthesis');
    const ifStatements = parseBlockStatement(parser);
    const ifBlock: ConditionalExpression = {
        type: 'ConditionalExpression',
        branches: [],
        ifCondition,
        ifBody: ifStatements
    }
    while (parser.isCurrentKeyword('elif')) {
        parser.expectKeyword('elif')
        parser.expect('OpenParenthesis')
        const condition = parseExpression(parser)
        parser.expect('CloseParenthesis')
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
    parser.expect('OpenParenthesis');
    const parameters: Expression[] = [];
    let hasNext = !parser.isCurrentType('CloseParenthesis');
    while (hasNext) {
        parameters.push(parseExpression(parser));
        hasNext = false
        if (parser.isCurrentType('CommaToken')) {
            parser.expect('CommaToken')
            hasNext = true;
        }
    }
    parser.expect('CloseParenthesis');
    return {
        type: 'CallExpression',
        functionName: identifier.value,
        parameters
    }
}

function parseVariableDeclaration(parser: Parser) {
    const current = parser.expect('Keyword');
    const isConstant = current.value === 'val';
    const identifier = parser.expect('Identifier');
    let variableType = ''

    if (parser.isCurrentType('ColonToken')) {
        parser.expect('ColonToken')
        variableType = parseType(parser)
    }

    const variableDeclaration: VariableDeclarationStatement = {
        type: 'VariableDeclarationStatement',
        name: identifier.value,
        variableType,
        isConstant
    }
    if (parser.isCurrentType('EqualToken')) {
        parser.expect('EqualToken');
        variableDeclaration.value = parseExpression(parser);
    }
    if (variableDeclaration.isConstant && !variableDeclaration.value) {
        parser.reportError(`Constant variable declaration must have a value`, identifier)
    }
    if (!variableDeclaration.variableType && !variableDeclaration.value) {
        parser.reportError(`Unable to define a type for ${identifier.value}`, identifier)
    }
    return variableDeclaration;
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

function parseFunction(parser: Parser) {
    parser.expectKeyword('fun');
    const functionName = parser.expect('Identifier');
    parser.expect('OpenParenthesis');
    const functionDeclaration: FunctionDeclaration = {
        name: functionName.value,
        body: [],
        parameters: [],
        returnType: ''
    }
    let hasNext = !parser.isCurrentType('CloseParenthesis');
    while (hasNext) {
        const paramName = parser.expect('Identifier')
        parser.expect('ColonToken');
        const paramType = parseType(parser);
        functionDeclaration.parameters.push({
            type: paramType,
            name: paramName.value,
        });
        hasNext = false;
        if (parser.isCurrentType('CommaToken')) {
            parser.expect('CommaToken');
            hasNext = true;
        }
    }
    parser.expect('CloseParenthesis');
    parser.expect('ColonToken');
    functionDeclaration.returnType = parseType(parser);
    functionDeclaration.body = parseBlockStatement(parser)
    return functionDeclaration;
}