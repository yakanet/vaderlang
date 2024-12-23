import type {Expression, FunctionDeclaration, Program, Statement} from "../parser/types.ts";

class Ref {
    constructor(public readonly named: string, public readonly type: string, private varType = '%') {
    }

    toString() {
        return `${this.varType}${this.named}`
    }
}

class Scope {
    private variableRef = 0;
    private namedVariables = new Map<string, Ref>();
    public readonly depth: number;

    constructor(private parent?: Scope) {
        this.depth = parent ? parent.depth + 1 : 0;
    }

    newVariable(type: string, name?: string) {
        if (name) {
            if (this.namedVariables.has(name)) {
                throw new Error(`Already declared variable ${name}`);
            }
            const ref = new Ref(name, type);
            this.namedVariables.set(name, ref)
            return ref;
        } else {
            return new Ref(`_${this.variableRef++}`, type);
        }
    }

    lookupVariable(value: string): Ref {
        const ref = this.namedVariables.get(value);
        if (ref) {
            return ref;
        }
        if (this.parent) {
            return this.parent.lookupVariable(value)
        }
        throw new Error(`Unknown variable name ${value}`);
    }
}

export class QbeEmitter {
    private strings = new Map<string, Ref>();
    private functions = new Map<string, FunctionDeclaration>();

    constructor(private write: (message: string) => void) {
    }

    emit(program: Program) {
        const scope = new Scope();
        for (const statement of program.body) {
            this.emitStatement(statement, scope);
        }
        for (const [value, ref] of this.strings) {
            this.writeln(`data ${ref} = {b "${value}" }`, scope)
        }
    }

    private writeln(message: string, scope: Scope) {
        this.write(`${'\t'.repeat(scope.depth)}${message}\n`);
    }

    private debugln(message: string, scope: Scope) {
        this.write('\n');
        this.writeln(`# ${message}`, scope);
    }

    private emitStatement(statement: Statement, scope: Scope) {
        switch (statement.type) {
            case 'FunctionDeclaration': {
                this.functions.set(statement.name, statement);
                const isMain = statement.name === 'main';

                const functionScope = new Scope(scope);

                this.debugln('FunctionDeclaration -- ' + statement.name, scope)
                let code = isMain ? 'export ' : ''
                code += 'function '
                if (statement.returnType) {
                    code += statement.returnType + ' '
                }
                code += '$' + statement.name + ' '
                code += '(';
                const params = statement.parameters.map(p => functionScope.newVariable(p.type, p.name));
                code += params.map(p => `${p.type} ${p}`).join(', ')
                code += ') {';
                this.writeln(code, scope)
                this.writeln(`@start`, scope)
                for (const child of statement.body) {
                    this.emitStatement(child, functionScope);
                }
                this.writeln(`}`, scope);
                return
            }

            case 'VariableDeclarationStatement': {
                const ref = scope.newVariable(statement.variableType, statement.name);
                if (statement.value) {
                    const value = this.emitExpression(statement.value, scope);
                    this.debugln(`VariableDeclarationStatement -- ${statement.name}`, scope)
                    this.writeln(`${ref} =w copy ${value}`, scope)
                }
                return ref;
            }
            case "ReturnStatement": {
                const ref = this.emitExpression(statement.expression, scope)
                this.debugln('ReturnStatement', scope)
                this.writeln(`ret ${ref}`, scope);
                return;
            }
        }
        if (statement.type === 'CallExpression') {
            const params = statement.parameters.map(p => this.emitExpression(p, scope));
            this.debugln(`CallExpression -- ${statement.functionName}`, scope);
            this.writeln(`call $${statement.functionName}(${params.map(p => `${p?.type} ${p}`)})`, scope)
            return;
        }

        throw new Error(`Undeclared statement ${statement.type}`);
    }


    private emitExpression(expression: Expression, scope: Scope): Ref | undefined {
        if (expression.type === 'NumberExpression') {
            const ref = scope.newVariable('w');
            this.debugln(`NumberExpression ${expression.value}`, scope)
            this.writeln(`${ref} =w copy ${expression.value}`, scope);
            return ref;
        }
        if (expression.type === 'BinaryExpression') {
            switch (expression.operator) {
                case '+': {
                    const lhs = this.emitExpression(expression.lhs, scope)
                    const rhs = this.emitExpression(expression.rhs, scope);
                    if (!lhs || lhs.type !== rhs?.type) {
                        throw new Error(`Incompatible binary expression between ${lhs?.named} and ${rhs?.named}`);
                    }
                    const res = scope.newVariable(lhs.type);
                    this.debugln('BinaryExpression +', scope)
                    this.writeln(`${res} =w add ${lhs}, ${rhs}`, scope);
                    return res;
                }

                default:
                    throw new Error(`unimplemented binary operation ${expression.operator}`)
            }
        }
        if (expression.type === 'VariableExpression') {
            return scope.lookupVariable(expression.value);
        }

        if (expression.type === 'CallExpression') {
            const params = expression.parameters.map(p => this.emitExpression(p, scope));
            const resolvedFunction = this.functions.get(expression.functionName);
            if (!resolvedFunction) {
                throw new Error(`Unresolved function ${expression.functionName}`)
            }
            const res = scope.newVariable(resolvedFunction?.returnType);
            this.debugln(`CallExpression -- ${expression.functionName}`, scope);
            this.writeln(`${res} =w call $${expression.functionName}(${params.map(p => `${p!.type} ${p}`)})`, scope)
            return res;
        }

        if (expression.type === 'StringExpression') {
            let ref = this.strings.get(expression.value);
            if (!ref) {
                ref = new Ref(String('_str_' + this.strings.size), 'l', '$');
                this.strings.set(expression.value, ref);
            }
            this.debugln(`StringExpression -- ${expression.value}`, scope);
            return ref;
        }
        throw new Error(`Undeclared expression ${expression.type}`)
    }
}