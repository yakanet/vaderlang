import {keywords, tokenize} from "../tokens";
import type {Token} from "../tokens/types.ts";
import type {
    BinaryExpression,
    CallExpression,
    ConditionalExpression,
    Expression,
    FunctionDeclaration,
    NumberExpression,
    Program,
    ReturnStatement,
    Statement,
    StructStatement,
    VaderType,
    VariableDeclarationStatement,
    VariableExpression
} from "./types.ts";

export class Parser {
    private readonly tokens: Token[];
    private index = 0;
    public mainMethod: string | undefined = undefined;

    constructor(private content: string, private source_path?: string) {
        this.tokens = [...tokenize(content)];
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


    expectKeywords(keywordz: typeof keywords[number][], message?: string) {
        const token = this.current;
        for (const keyword of keywordz) {
            if (this.isCurrentKeyword(keyword)) {
                return this.eat();
            }
        }
        throw new Error(message ?? `Expected one of the following keywords ${keywordz} but get ${token.value}`)
    }

    isCurrentKeyword(keyword: typeof keywords[number]) {
        return this.current.type === 'Keyword' && this.current.value === keyword;
    }

    isCurrentType(type: Token['type']) {
        return this.current.type === type;
    }

    expectTrue(value: boolean, message: string) {
        if(!value) {
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
                return {line: row, column: offset - currentOffset}
            }
            row++
            currentOffset += line.length + 1;
        }
        throw new Error(`Could not determine location of ${offset}`)
    }

    reportError(message: string, token: Token = this.current): never {
        let {line, column} = this.findLocation(token.offset);
        line += 1; // There is a +1 offset in IDE or Code editor
        column += 1; // There is a +1 offset in IDE or Code editor
        if(this.source_path) {
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
        type: 'Program',
        body: [],
        mainMethod: undefined,
    }
    while (!parser.isCurrentType('EOF')) {
        program.body.push(parseStatement(parser))
    }
    parser.expect('EOF');
    program.mainMethod = parser.mainMethod;
    return program;
}

function parseStatement(parser: Parser): Statement {
    if(parser.isCurrentType('Identifier')) {
        return parseIdentifierStatement(parser);
    }
    if (parser.isCurrentKeyword('return')) {
        return parseReturnStatement(parser)
    }
    if (parser.isCurrentKeyword('for')) {
        return parseForStatement(parser)
    }
    return parseExpression(parser)
}

function parseType(parser: Parser): VaderType {
    const identifier = parser.expect('Identifier').value;
    let arrayData: VaderType['array'] = undefined;
    if(parser.isCurrentType('OpenSquareBracket')) {
        parser.expect('OpenSquareBracket');
        if(parser.isCurrentType('CloseSquareBracket')) {
            parser.expect('CloseSquareBracket');
            arrayData = {
                arrayLenght: 0
            }
        } else {
            const arraySize = parseExpression(parser);
            parser.expectTrue(arraySize.type != "NumberExpression", 'Const array could be only initialized with a constant number');
            arrayData = {
                arrayLenght: (arraySize as NumberExpression).value
            }
        }
    }

    return {
        name: identifier,
        array: arrayData
    }
}

function parseIdentifierStatement(parser: Parser): Statement {
    const identifier = parser.expect('Identifier');
    // id ::
    if(parser.isCurrentType('ColonColonToken')) {
        parser.expect('ColonColonToken');
        return parseVariableDeclaration(parser, true, identifier, undefined)
    }

    // id :=
    if(parser.isCurrentType('ColonEqualToken')) {
        parser.expect('ColonEqualToken');
        return parseVariableDeclaration(parser, false, identifier, undefined)
    }

    if(parser.isCurrentType('ColonToken')) {
        parser.expect('ColonToken');
        const type = parseType(parser);
        // id :type :
        if(parser.isCurrentType('ColonToken')) {
            parser.expect('ColonToken');
            return parseVariableDeclaration(parser, true, identifier, type);
        }
        // id :type =
        if(parser.isCurrentType('EqualToken')) {
            parser.expect('ColonToken');
            return parseVariableDeclaration(parser, false, identifier, type);
        }
    }
    if(parser.isCurrentType('EqualToken')) {
        parser.expect('EqualToken');
        const value = parseExpression(parser);
        return {
            type: 'VariableAssignment',
            identifier: identifier.value,
            value
        }
    }
    parser.reportError(`Unexpected identifier ${identifier.value}`);
}

function parseVariableDeclaration(parser: Parser, isConstant: boolean, identifier: Token, type?: VaderType): Statement {
    if(parser.isCurrentKeyword('fn')) {
        parser.expectTrue(isConstant, `Function declaration could only be used with :: operator`)
        return parseFunctionDeclaration(parser, identifier)
    }
    if(parser.isCurrentKeyword('struct')) {
        parser.expectTrue(isConstant, `Struct declaration could only be used with :: operator`)
        return parseStruct(parser, identifier)
    }
    return parseVariableDeclarationAndAssignment(parser, isConstant, identifier, type);
}

function parseFunctionDeclaration(parser: Parser, identifier: Token): FunctionDeclaration {
    parser.expectKeyword('fn')
    const parameters = parseFunctionArguments(parser);
    parser.expect('LambdaArrowToken')
    const returnType = parseType(parser);
    const body = parseBlockStatement(parser);
    return {
        type: 'FunctionDeclaration',
        name: identifier.value,
        parameters,
        returnType,
        body
    }
}

function parseFunctionArguments(parser: Parser) : {name: string, type: VaderType}[]{
    debugger
    parser.expect('OpenParenthesis')
    const parameters: {name: string, type: VaderType}[] = [];
    while(!parser.isCurrentType('CloseParenthesis')) {
        const identifier = parser.expect('Identifier')
        parser.expect('ColonToken');
        const type = parseType(parser);
        parameters.push({ name: identifier.value, type})
        if(!parser.isCurrentType('CommaToken')) {
            break
        }
        parser.expect('CommaToken');
    }
    parser.expect('CloseParenthesis')
    return parameters;
}

function parseVariableDeclarationAndAssignment(parser: Parser, isConstant: boolean, identifier: Token, type?: VaderType): VariableDeclarationStatement {
    const value = parseExpression(parser);
    return {
        type: 'VariableDeclarationStatement',
        name: identifier.value,
        isConstant,
        variableType: type,
        value
    }
}

function parseStruct(parser: Parser, identifier: Token) {
    parser.expectKeyword('struct');
    const structStatement: StructStatement = {
        type: 'StructStatement',
        name: identifier.value,
        definition: []
    };

    parser.expect('OpenCurlyBracket');
    while (!parser.isCurrentType('CloseCurlyBracket')) {
        console.log(parser.current)
        const attributeName = parser.expect('Identifier').value
        parser.expect('ColonToken');
        const typeName = parseType(parser)
        structStatement.definition.push({attributeName, typeName})
    }
    parser.expect('CloseCurlyBracket');
    return structStatement;
}

function parseForStatement(parser: Parser): Statement {
    parser.expectKeyword('for');
    let hasOpeningParenthesis = parser.isCurrentType('OpenParenthesis');
    if(hasOpeningParenthesis) {
        parser.expect('OpenParenthesis');
    }
    const initialization = parseIdentifierStatement(parser)
    parser.expect('SemicolonToken')
    const condition = parseExpression(parser);
    parser.expect('SemicolonToken')
    const iteration = parseIdentifierStatement(parser)
    if(hasOpeningParenthesis) {
        parser.expect('CloseParenthesis')
    }
    const body = parseBlockStatement(parser);
    return {
        type: 'ForStatement',
        initialization,
        condition,
        iteration,
        body,
    }

}

function parseExpression(parser: Parser): Expression {
    let lhs: Expression | null = null;

    if (parser.isCurrentKeyword('if')) {
        lhs = parseIfExpression(parser)
    }

    if (parser.isCurrentType('OpenParenthesis')) {
        parser.expect('OpenParenthesis');
        lhs = parseExpression(parser);
        parser.expect('CloseParenthesis');
    }

    if (parser.isCurrentType('Identifier') && parser.next?.type === 'OpenParenthesis') {
        lhs = parseCallExpression(parser);
    }

    if(parser.isCurrentType('Identifier') && parser.next?.type === 'DotToken') {
        debugger
        const variable = [parser.expect('Identifier')];
        while(parser.isCurrentType('DotToken')) {
            parser.expect('DotToken')
            variable.push(parser.expect('Identifier'))
        }
        lhs = {
            type: 'VariableExpression',
            value: variable.map(v => v.value)
        }
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
        const token = parser.expect('Identifier')
        lhs = {
            type: "VariableExpression",
            value: [token.value],
        }
    }

    if (!lhs) {
        parser.reportError(`Unknown expression: ${parser.current.type}`)
    }

    lhs = parseBinaryExpression(parser, lhs)

    return lhs
}

function parseBinaryExpression(parser:Parser, lhs: Expression): Expression {
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
        'HigherThanEqualToken'
    ]);
    for(const operator of binaryToken) {
        if (parser.isCurrentType(operator)) {
            const token = parser.expect(operator);
            const rhs = parseExpression(parser);
            return {
                type: 'BinaryExpression',
                operator: token.value,
                lhs,
                rhs
            }
        }
    }
    return lhs;
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
        branches: [{
            body: ifStatements,
            condition: ifCondition
        }],
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

function parseBlockStatement(parser: Parser): Statement[] {
    parser.expect('OpenCurlyBracket');
    const statements: Statement[] = []
    while (!parser.isCurrentType('CloseCurlyBracket')) {
        statements.push(parseStatement(parser))
    }
    parser.expect('CloseCurlyBracket');
    return statements;
}
