import {Scope} from "./scope";
import {
    type ArrayDeclarationExpression,
    type ArrayVaderType,
    BasicVaderType,
    type Expression,
    type ForStatement,
    type FunctionDeclarationExpression,
    isTypeEquals,
    type Program,
    type ReturnStatement,
    type Statement,
    type StructVaderType,
    typeToString,
    type VaderType,
    type VariableDeclarationStatement,
} from "../parser/types";
import assert from "node:assert";

export function resolve(program: Program): Program {
    const scope = new Scope();
    const body = program.body.map((statement) =>
        resolveStatement(statement, scope)
    );
    return {
        ...program,
        body,
    };
}

function resolveStatement(
    statement: Statement,
    scope: Scope
): Statement {
    switch (statement.kind) {
        case "Program":
            throw new Error("unreachable");
        case "ReturnStatement":
            return {
                ...statement,
                expression: resolveExpression(statement.expression, scope),
            } satisfies ReturnStatement;

        case 'ConditionalStatement': {
            return {
                ...statement,
                condition: resolveExpression(statement.condition, scope),
                type: BasicVaderType.void,
                ifBody: statement.ifBody.map(b => resolveStatement(b, scope)),
                elseBody: statement.elseBody?.map(b => resolveStatement(b, scope)),
            }
        }
        case "VariableDeclarationStatement":
            return resolveVariableDeclaration(statement, scope);
        case "VariableAssignmentStatement": {
            const res = resolveExpression(statement.value, scope);
            // TODO: Should check if the variable is constant or not
            return {
                ...statement,
                identifier: resolveExpression(statement.identifier, scope),
                value: res,
            };
        }
        case "ForStatement":
            const initialization = resolveStatement(statement.initialization, scope)
            const cloneScope = new Scope(scope)
            return {
                ...statement,
                initialization,
                condition: resolveExpression(statement.condition, cloneScope),
                iteration: resolveStatement(statement.iteration, cloneScope),
                body: statement.body.map(b => resolveStatement(b, cloneScope)),
            } satisfies ForStatement
    }
    return resolveExpression(statement, scope);
}

function resolveFunctionDeclaration(
    statement: FunctionDeclarationExpression,
    scope: Scope
): FunctionDeclarationExpression {
    const functionScope = new Scope(scope);
    let i = 0;
    for (const parameter of statement.type.parameters) {
        parameter.type = resolveType(parameter.type, scope);
        functionScope.newFunctionParameter(parameter.type, i++, parameter.name);
    }
    const body = statement.body.map((stmt) =>
        resolveStatement(stmt, functionScope)
    );
    statement.type.returnType = resolveType(statement.type.returnType, scope);
    return {
        ...statement,
        body,
    };
}

function resolveVariableDeclaration(
    statement: VariableDeclarationStatement,
    scope: Scope
): Statement {
    const value = statement.value
        ? resolveExpression(statement.value, scope)
        : undefined;

    const type =
        statement.type !== BasicVaderType.unknown
            ? statement.type
            : value?.type ?? BasicVaderType.unknown;
    // TODO need to check if we can cast the number with the range (ex: u32 should be between 0..2^32−1)
    if (value && value.type !== type) {
        value.type = type;
    }
    if (scope.depth === 0) {
        scope.newGlobalVariable(type, statement.name);
    } else {
        scope.newLocalVariable(type, scope.allFunctionLevelVariable().filter(v => v.source.kind !== 'GlobalParameterSource').length, statement.name);
    }
    return {
        ...statement,
        type,
        value,
    };
}

function resolveType(type: VaderType, scope: Scope): VaderType {
    if (type.kind === 'array') {
        return {
            ...type,
            type: resolveType(type.type, scope),
            length: type.length ? resolveExpression(type.length, scope) : undefined
        }
    }
    if (type.kind === 'unknown') {
        if (type.name in BasicVaderType) {
            return (BasicVaderType as any)[type.name];
        }
        const resolved = scope.lookupVariable(type.name);
        return resolved.type;
    }
    return type;
}

function resolveExpression(
    expression: Expression,
    scope: Scope
): Expression {
    switch (expression.kind) {
        case "BinaryExpression": {
            const lhs = resolveExpression(expression.lhs, scope)
            const rhs = resolveExpression(expression.rhs, scope)
            return {
                ...expression,
                type: lhs.type !== BasicVaderType.unknown ? lhs.type : rhs.type, // TODO typechecker need to check left and right type
                lhs,
                rhs,
            };
        }
        case "FunctionDeclarationExpression":
            return resolveFunctionDeclaration(expression, scope);
        case "CallExpression": {
            const resolved = scope.lookupVariable(expression.functionName);
            const parameters = expression.parameters.map((param) =>
                resolveExpression(param, scope)
            );
            if (resolved.type.kind !== 'function') {
                throw new Error(`Only function can be call, here try to call a ${resolved.source.kind}`);
            }

            return {
                ...expression,
                kind: 'CallExpression',
                parameters,
                type: resolved.type.returnType,
            };

        }
        case "StructDeclarationExpression": {
            assert(expression.type.kind === 'struct');
            for (const parameter of expression.type.parameters) {
                if (parameter.type.kind === 'unknown') {
                    parameter.type = resolveType(parameter.type, scope)
                }
                //type.parameters.push({name: parameter.name, type: parameter.type});
            }
            return {
                ...expression,
            }
        }
        case 'IdentifierExpression': {
            const variable = scope.lookupVariable(expression.identifier)
            return {
                ...expression,
                type: resolveType(variable.type, scope),
            }
        }

        case 'ArrayDeclarationExpression': {
            return {
                ...expression,
                type: resolveType(expression.type, scope) as ArrayVaderType,
                value: expression.value?.map(i => resolveExpression(i, scope)),
            } satisfies ArrayDeclarationExpression;
        }
        case 'StructInstantiationExpression': {
            const resolved = scope.lookupVariable(expression.structName)
            if (resolved.type.kind !== 'struct') {
                throw new Error(`Trying to instantiate a struct, but ${resolved.named} is not a struct`);
            }
            if (resolved.type.parameters.length !== expression.parameters.length) {
                throw new Error(`wrong number of arguments (expected ${resolved.type.parameters.length}, got ${expression.parameters.length})`);
            }
            if (expression.parameters.length > 0) {
                const isNamedParameter = !!expression.parameters[0].name;
                for (let i = 0; i < expression.parameters.length; i++) {
                    let target: StructVaderType['parameters'][number]
                    if (isNamedParameter) {
                        assert(expression.parameters[i].name !== undefined)
                        const t = resolved.type.parameters.find(t => t.name === expression.parameters[i].name);
                        if (!t) {
                            throw new Error(`undeclared ${expression.parameters[i].name} on struct: ${typeToString(resolved.type)}`);
                        }
                        t.type = resolveType(t.type, scope);
                        target = t;
                    } else {
                        assert(expression.parameters[i].name === undefined)
                        target = resolved.type.parameters[i];
                    }
                    expression.parameters[i].value = resolveExpression(expression.parameters[i].value, scope);
                    if (!isTypeEquals(expression.parameters[i].value.type, target.type)) {
                        throw new Error(`wrong type for parameter ${resolved.type.parameters[i].name} (expected ${typeToString(target.type)}, got ${typeToString(expression.parameters[i].value.type)}))`);
                    }
                }
            }
            return {
                ...expression,
                type: resolved.type,
            }
        }
        case 'DotExpression': {
            expression.identifier = resolveExpression(expression.identifier, scope);
            assert(!isTypeEquals(expression.identifier.type, BasicVaderType.unknown))
            let previousType = expression.identifier.type;
            for (let i = 0; i < expression.properties.length; i++) {
                const property = expression.properties[i];
                if (previousType.kind === 'array') {
                    if (property.kind !== 'ArrayIndexExpression') {
                        throw new Error(`unrecognized expression ${typeToString(previousType)}.${property.identifier}`);
                    }
                    property.index = resolveExpression(property.index, scope) as any;
                    property.type = property.index.type;
                    previousType = property.type;
                } else if (previousType.kind === 'struct') {
                    if (property.kind !== 'IdentifierExpression') {
                        throw new Error(`unrecognized expression ${typeToString(previousType)}.${typeToString(property.type)}`);
                    }
                    const resolvedType = previousType.parameters.find(p => p.name === property.identifier)
                    if (!resolvedType) {
                        throw new Error(`Unresolved property ${property.identifier}`);
                    }
                    expression.properties[i].type = resolvedType.type;
                    previousType = property.type;
                } else {
                    throw new Error(`Not allowed to use dot expression on ${typeToString(previousType)}`)
                }
            }
            return {
                ...expression,
                type: expression.properties.length > 0 ? expression.properties[expression.properties.length - 1].type : expression.identifier.type,
            }
        }
        case 'ConditionalExpression': {
            const ifBody = expression.ifBody.map(b => resolveStatement(b, scope));
            const elseBody = expression.elseBody?.map(b => resolveStatement(b, scope))
            const returnIf = ifBody.at(-1) as Expression;
            const returnElse = elseBody?.at(-1) as Expression | undefined;
            if (returnElse && !isTypeEquals(returnIf.type, returnElse.type)) {
                throw new Error(`return type mismatch in conditional expression ${JSON.stringify([returnIf.type, returnElse.type])} at ${expression.location.start}`);
            }
            return {
                ...expression,
                condition: resolveExpression(expression.condition, scope),
                type: returnIf.type,
                ifBody,
                elseBody,
            }
        }
        default:
            return {...expression};
    }
}
