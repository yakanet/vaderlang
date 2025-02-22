import {Parser} from "./parser.ts";
import {
    BasicVaderType,
    type ConditionalExpression,
    type ConditionalStatement,
    type ReturnStatement,
    type Statement,
    type VaderType,
    type VariableDeclarationStatement
} from "./types.ts";
import type {Decorator, Token} from "../tokens/types.ts";
import {optionalRoundBracket, parseBlockStatement, parseType} from "./common.ts";
import {parseExpression} from "./expression.ts";

export function parseStatement(parser: Parser): Statement {
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
        return parseDecorator(parser);
    }
    return parseExpression(parser)
}

// TODO refactor this
export const decorators: Decorator[] = [];

function parseDecorator(parser: Parser) {
    const token = parser.expect('Decorator');
    switch (token.value) {
        case 'intrinsic':
            decorators.push(token.value)
            return parseStatement(parser)
        case 'load':
            const pathToken = parser.expect("StringLiteral");
            parser.loadVaderFile(pathToken.value)
            return parseStatement(parser);
        case 'file':
            return parser.reportError(`@file decorator is not applicable as a statement`, token.location);
    }
    parser.reportError(`Unknown decorator: ${token.value}`, token.location);
}


/**
 * identifier()
 * identifier ::
 * identifier :=
 * identifier =
 * @param parser
 */
function parseIdentifierStatement(parser: Parser): Statement {
    if (parser.next.type === 'ColonToken') {
        const identifier = parser.expect('Identifier')
        parser.expect('ColonToken');
        // id ::
        if (parser.isCurrentType('ColonToken')) {
            parser.expect('ColonToken');
            return parseVariableDeclarationAndAssignment(parser, true, identifier, BasicVaderType.unknown)
        }
        // id :=
        if (parser.isCurrentType('EqualToken')) {
            parser.expect('EqualToken');
            return parseVariableDeclarationAndAssignment(parser, false, identifier, BasicVaderType.unknown);
        }
        const type = parseType(parser);
        // id :type :
        if (parser.isCurrentType('ColonToken')) {
            parser.expect('ColonToken');
            return parseVariableDeclarationAndAssignment(parser, true, identifier, type)
        }
        // id :type =
        if (parser.isCurrentType('EqualToken')) {
            parser.expect('EqualToken');
            return parseVariableDeclarationAndAssignment(parser, false, identifier, type);
        }
    }

    const left = parseExpression(parser);
    if (parser.isCurrentType('EqualToken')) {
        parser.expect('EqualToken');
        const value = parseExpression(parser);
        return {
            kind: 'VariableAssignmentStatement',
            identifier: left,
            value,
            location: {
                start: left.location.start,
                file: left.location.file,
                end: value.location.end
            }
        }
    }
    return left;
}


function parseVariableDeclarationAndAssignment(parser: Parser, isConstant: boolean, identifier: Token, type: VaderType): VariableDeclarationStatement {
    const value = parseExpression(parser);

    return {
        kind: 'VariableDeclarationStatement',
        name: identifier.value,
        isConstant,
        type: type,
        value,
        location: {
            start: identifier.location.start,
            end: value.location.end,
            file: identifier.location.file,
        }
    } satisfies VariableDeclarationStatement
}


/**
 * for (?statement; statement; statement)? { statement* }
 * @param parser
 */
function parseForStatement(parser: Parser): Statement {
    const forToken = parser.expectKeyword('for');
    const [initialization, condition, iteration] = optionalRoundBracket(parser, () => {
        const initialization = parseIdentifierStatement(parser)
        parser.expect('SemicolonToken')
        const condition = parseExpression(parser);
        parser.expect('SemicolonToken')
        const iteration = parseIdentifierStatement(parser)
        return [initialization, condition, iteration]
    })
    const body = parseBlockStatement(parser);
    return {
        kind: 'ForStatement',
        initialization,
        condition,
        iteration,
        body,
        location: {
            start: forToken.location.start,
            end: parser.previous.location.end,
            file: forToken.location.file,
        }
    }
}


/**
 * return expression
 * @param parser
 */
function parseReturnStatement(parser: Parser): ReturnStatement {
    const token = parser.expectKeyword('return');
    return {
        kind: 'ReturnStatement',
        expression: parseExpression(parser),
        location: {
            ...token.location,
            end: parser.previous.location.end
        }
    };
}


/**
 * if(?expression)? { statement[] }
 *  [elif (?expression)? { statement[] }]*
 *  [else { statement[]}]?
 *
 * @param parser
 * @param kind
 */
export function parseIfStatement(parser: Parser, kind: 'ConditionalStatement' | 'ConditionalExpression' = 'ConditionalStatement') {
    const ifToken = parser.expectKeyword('if');
    const ifCondition = optionalRoundBracket(parser, () => parseExpression(parser));
    const ifStatements = parseBlockStatement(parser);
    const ifBlock = {
        kind,
        type: BasicVaderType.unknown,
        ifBody: ifStatements,
        condition: ifCondition,
        location: {
            start: ifToken.location.start,
            end: ifToken.location.start,
            file: ifToken.location.file,
        }
    } satisfies ConditionalStatement | ConditionalExpression;
    let currentBlock: ConditionalStatement | ConditionalExpression = ifBlock;
    while (parser.isCurrentKeyword('elif')) {
        const elifToken = parser.expectKeyword('elif')
        const condition = optionalRoundBracket(parser, () => parseExpression(parser));
        const body = parseBlockStatement(parser);
        currentBlock.elseBody = [{
            kind,
            type: BasicVaderType.unknown,
            ifBody: body,
            condition: condition,
            location: {
                start: elifToken.location.start,
                end: elifToken.location.start,
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