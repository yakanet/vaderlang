import type {Expression, FunctionDeclaration, Program, Statement} from "../parser/types.ts";
import child_process from "node:child_process";
import fs from 'node:fs';
import { Scope, Ref } from "./scope.ts";

export class QbeEmitter {
    private strings = new Map<string, Ref>();
    private functions = new Map<string, FunctionDeclaration>();
    private write: (message: string) => void;
    private buffer = '';

    constructor() {
        this.write = (message) => this.buffer += message;
    }

    emit(program: Program, outputPath: string) {
        const scope = new Scope();
        for (const statement of program.body) {
            this.emitStatement(statement, scope);
        }
        for (const [value, ref] of this.strings) {
            this.writeln(`data ${ref} = {b "${value}" }`, scope)
        }

        // Write
        fs.mkdirSync(`${outputPath}/qbe`, {recursive: true, });
        fs.writeFileSync(`${outputPath}/qbe/build.ssa`, this.buffer, {encoding: "utf-8"})
        execCommand(['qbe', '-o', `${outputPath}/qbe/build-arm64-darwin.s`, '-t', 'arm64_apple', `${outputPath}/qbe/build.ssa`])
        execCommand(['qbe', '-o', `${outputPath}/qbe/build-amd64-darwin.s`, '-t', 'amd64_apple', `${outputPath}/qbe/build.ssa`])
        execCommand(['cc', '-o', `${outputPath}/app`, `${outputPath}/qbe/build-arm64-darwin.s`])
    }

    private writeln(message: string, scope: Scope) {
        this.write(`${'\t'.repeat(scope.depth)}${message}\n`);
    }

    private debugln(message: string, scope: Scope) {
        this.writeln(`\n# ${message}`, scope);
    }

    private emitStatement(statement: Statement, scope: Scope) {
        switch (statement.type) {
            case 'FunctionDeclaration': {
                this.functions.set(statement.name, statement);
                const functionScope = new Scope(scope);

                this.debugln('FunctionDeclaration -- ' + statement.name, scope)
                const exportableFn = statement.name === 'main';
                const params = statement.parameters.map(p => functionScope.newVariable(p.type, p.name));

                const header = [
                    exportableFn ? 'export' : '',
                    'function',
                    statement.returnType ?? '',
                    `$${statement.name}(${params.map(p => `${p.type} ${p}`).join(', ')}) {`,
                ];
                this.writeln(header.filter(x => x).join(' '), scope)
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

            case 'CallExpression': {
                const params = statement.parameters.map(p => this.emitExpression(p, scope));
                this.debugln(`CallExpression -- ${statement.functionName}`, scope);
                this.writeln(`call $${statement.functionName}(${params.map(p => `${p?.type} ${p}`)})`, scope)
                return;
            }
        }

        throw new Error(`Undeclared statement ${statement.type}`);
    }


    private emitExpression(expression: Expression, scope: Scope): Ref | undefined {
        switch (expression.type) {
            case 'NumberExpression': {
                const ref = scope.newVariable('w');
                this.debugln(`NumberExpression ${expression.value}`, scope)
                this.writeln(`${ref} =w copy ${expression.value}`, scope);
                return ref;
            }
            case 'BinaryExpression':
                switch (expression.operator) {
                    case '+': {
                        const lhs = this.emitExpression(expression.lhs, scope);
                        const rhs = this.emitExpression(expression.rhs, scope);
                        if (!lhs || lhs.type !== rhs?.type) {
                            throw new Error(`Incompatible binary expression between ${lhs?.named} and ${rhs?.named}`);
                        }
                        const res = scope.newVariable(lhs.type);
                        this.debugln('BinaryExpression +', scope);
                        this.writeln(`${res} =w add ${lhs}, ${rhs}`, scope);
                        return res;
                    }

                    default: {
                        throw new Error(`unimplemented binary operation ${expression.operator}`);
                    }
                }
            case 'VariableExpression': {
                return scope.lookupVariable(expression.value);
            }
            case 'CallExpression': {
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
            case 'StringExpression': {
                let ref = this.strings.get(expression.value);
                if (!ref) {
                    ref = new Ref(String('_str_' + this.strings.size), 'l', '$');
                    this.strings.set(expression.value, ref);
                }
                this.debugln(`StringExpression -- ${expression.value}`, scope);
                return ref;
            }
        }
        throw new Error(`Undeclared expression ${expression.type}`)
    }
}


function execCommand(commands: string[]) {
    console.time(commands.join(' '))
    const res = child_process.spawnSync(commands[0], commands.slice(1), {
        shell: true,
    })
    console.timeEnd(commands.join(' '))
    if (res.error || res.status) {
        console.log(res.stderr.toString())
        throw res.error;
    }
}
