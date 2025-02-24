import {
    type ArrayDeclarationExpression,
    BasicVaderType,
    type CallExpression,
    type DotExpression,
    type FunctionDeclarationExpression,
    isTypeEquals,
    type Program,
    type Statement,
    type StringExpression,
    type StructInstantiationExpression,
    typeToString,
    type VaderType,
    type VariableDeclarationStatement,
} from "../parser/types";
import binaryen from "binaryen";
import {addWasiFunction} from "./wasi.ts";
import assert from "node:assert";
import {gc, TypeBuilder} from "binaryen-gc";
import {BinaryenModule} from "./binaryen-module.ts";

const encoder = new TextEncoder();

export class WasmEmitter {
    public readonly mod = new BinaryenModule();
    private forCount = 0;
    private customTypes = new Map<VaderType, binaryen.Type>();

    constructor(enableDebug: boolean) {
        this.mod.enableDebug = enableDebug;
        addWasiFunction(this.mod.module);
    }

    emit(program: Program) {
        for (const statement of program.body) {
            this.emitTopLevelStatement(statement);
        }
        this.emitMainMethod(program);

        const module = this.mod.build();
        assert(module.validate());
        if (!this.mod.enableDebug) {
            module.optimize()
        }
        return module;
    }

    emitMainMethod(program: Program) {
        const mainVariable = program.body.find(b => b.kind === 'VariableDeclarationStatement' && b.name === 'main') as VariableDeclarationStatement
        if (!mainVariable) {
            return;
        }
        const mainFunction = mainVariable.value;
        if (mainFunction?.kind !== 'FunctionDeclarationExpression') {
            throw new Error(`main method must be a function`);
        }
        // TODO pass program param
        if (mainFunction.type.returnType.kind !== 'primitive') {
            throw new Error(`main method should return a void type or u32 type`)
        }
        if (isTypeEquals(mainFunction.type.returnType, BasicVaderType.u32)) {
            const funct = this.mod.inFunctionScope('_start', mainFunction, () => {
                return this.mod.module.addFunction(
                    "_start",
                    binaryen.createType([]),
                    binaryen.none,
                    [],
                    this.mod.module.block(null, [
                        this.mod.module.call(
                            "wasi_snapshot_preview1:proc_exit",
                            [this.mod.module.call(mainVariable.name, [], binaryen.i32)],
                            binaryen.none
                        ),
                    ])
                );
            })
            this.mod.module.setStart(funct);
        } else if (isTypeEquals(mainFunction.type.returnType, BasicVaderType.void)) {
            this.mod.module.setStart(this.mod.module.getFunction(mainVariable.name));
        } else {
            throw new Error(`main method should return a void type or u32 type`)
        }
    }

    emitTopLevelStatement(statement: Statement) {
        switch (statement.kind) {
            case "VariableDeclarationStatement": {
                assert(this.mod.isGlobalScope());
                this.mod.addSymbol(statement.name, statement.type, 'global', -1);
                switch (statement.type.kind) {
                    case 'struct': {
                        // Emitted in lazy mode
                        return;
                    }
                    case 'array':
                        throw new Error(`unreachable array creation on a top level statement`)
                    case 'function': {
                        assert(statement.value?.kind === 'FunctionDeclarationExpression');
                        const funct = statement.value as FunctionDeclarationExpression;
                        if (statement.type.decorators.includes('intrinsic')) {
                            return;
                        }
                        this.mod.inFunctionScope(statement.name, funct, () => {
                            for (const parameter of funct.type.parameters) {
                                this.mod.addSymbol(parameter.name, parameter.type, 'parameter', this.mod.currentSymbolIndex())
                            }
                            const body = funct.body.map((stmt) => this.emitStatement(stmt))

                            return this.mod.module.addFunction(
                                statement.name,
                                binaryen.createType(
                                    this.mod.getSymbols()
                                        .filter(({scope}) => scope === 'parameter')
                                        .map(({type}) => this.mapBinaryenType(type))
                                ),
                                this.mapBinaryenType(funct.type.returnType),
                                this.mod.getSymbols()
                                    .filter(({scope}) => scope === 'local')
                                    .map(({type}) => this.mapBinaryenType(type)),
                                this.mod.module.block(null, body)
                            );
                        })
                        //this.mod.module.addFunctionExport(statement.name, statement.name);
                        return;
                    }
                    case 'primitive':
                        return this.mod.module.addGlobal(
                            statement.name,
                            this.mapBinaryenType(statement.type),
                            !statement.isConstant,
                            this.emitExpression(statement.value!)
                        );
                    default:
                        throw new Error(`unrecognized top level declaration of variable type ${typeToString(statement.type)}`);
                }
            }
        }
        throw new Error(statement.kind + " is not implemented yet");
    }

    emitStatement(stmt: Statement): binaryen.ExpressionRef {
        const {addDebugStatement} = this.mod.createDebugStatement(stmt);
        switch (stmt.kind) {
            case "ReturnStatement":
                return addDebugStatement(
                    this.mod.module.return(this.emitExpression(stmt.expression))
                );

            case "ConditionalStatement": {
                return this.mod.module.if(
                    this.emitExpression(stmt.condition),
                    this.mod.module.block(null, stmt.ifBody.map(b => this.emitStatement(b))),
                    stmt.elseBody ? this.mod.module.block(null, stmt.elseBody.map(b => this.emitStatement(b as any))) : undefined
                )
            }

            case "VariableDeclarationStatement": {
                if (this.mod.isGlobalScope()) {
                    this.mod.addSymbol(stmt.name, stmt.type, 'global', -1)
                    return this.mod.module.global.set(
                        stmt.name,
                        this.emitExpression(stmt.value!)
                    );
                }
                const variable = this.mod.resolveSymbol(stmt.name)
                if (variable) {
                    throw new Error(`redefinition of variable ${stmt.name}`)
                }
                const index = this.mod.currentSymbolIndex()
                this.mod.addSymbol(stmt.name, stmt.type, 'local', index)
                return addDebugStatement(
                    this.mod.module.local.set(index, this.emitExpression(stmt.value!))
                )
            }

            case "VariableAssignmentStatement": {
                const identifier = stmt.identifier;
                if (identifier.kind === 'DotExpression') {
                    const keys = this.emitDotExpression(identifier);
                    assert(keys.length >= 2);
                    if (keys.at(-2)!.type.kind === 'struct') {
                        const base = keys.at(-2)!
                        const param = keys.at(-1)!;
                        assert(param);
                        return addDebugStatement(
                            gc.structs.setMember(this.mod.module, base.expression, param.index, this.emitExpression(stmt.value))
                        )
                    }
                    if (keys.at(-2)!.type.kind === 'array') {
                        const base = keys.at(-2)!
                        const param = keys.at(-1)!;
                        assert(param);
                        return addDebugStatement(
                            gc.arrays.setItem(this.mod.module, base.expression, param.index, this.emitExpression(stmt.value))
                        )
                    } else {
                        throw new Error(`Unimplemented assignment on ${typeToString(identifier.type)}`)
                    }
                }
                if (identifier.kind === 'IdentifierExpression') {
                    let variable = this.mod.resolveSymbol(identifier.identifier, 'all')
                    if (!variable) {
                        throw new Error(`Undeclared variable ${identifier.identifier}`);
                    }
                    if (variable.scope === 'global') {
                        return this.mod.module.global.set(
                            identifier.identifier,
                            this.emitExpression(stmt.value)
                        );
                    }
                    return addDebugStatement(
                        this.mod.module.local.set(variable.index, this.emitExpression(stmt.value))
                    );
                } else {
                    throw new Error(`assignment with left-side dynamic is not supported yet`)
                }
            }

            case 'ForStatement': {
                const forCount = this.forCount++;
                return this.mod.module.block(null, [
                    this.emitStatement(stmt.initialization),
                    this.mod.module.loop('outer_' + forCount,
                        this.mod.module.block('inner_' + forCount, [
                            this.mod.addDebugStatement(this.mod.module.br_if('inner_' + forCount, this.mod.addDebugStatement(this.mod.module.i32.eqz(this.emitStatement(stmt.condition)), stmt.condition)), stmt.condition),
                            ...stmt.body.map(b => this.emitStatement(b)),
                            this.mod.addDebugStatement(this.emitStatement(stmt.iteration), stmt.iteration),
                            this.mod.addDebugStatement(this.mod.module.br('outer_' + forCount), stmt.iteration),
                        ])
                    )
                ])
            }
        }
        return this.emitExpression(stmt);
    }

    private emitExpression(
        expression: Statement,
    ): binaryen.ExpressionRef {
        const {addDebugStatement} = this.mod.createDebugStatement(expression);
        switch (expression.kind) {
            case 'CallExpression': {
                const functionType = this.mod.resolveSymbol(expression.functionName, 'global')?.type;
                if (!functionType) {
                    throw new Error(`unresolved call to function ${expression.functionName}`);
                }
                if (functionType.kind !== 'function') {
                    throw new Error(`could only call function, trying to call ${typeToString(functionType)}.`);
                }
                if (functionType.decorators.includes('intrinsic')) {
                    switch (expression.functionName) {
                        case 'print':
                            return this.emitPrint(expression)
                        case 'exit':
                            return this.emitExit(expression);
                        case 'length':
                            return this.emitArrayLength(expression)
                        default:
                            throw new Error(`unknown intrinsic function '${expression.functionName}'`)
                    }
                }
                const parameters = expression.parameters.map(p => this.emitExpression(p));

                const call = this.mod.inCallScope(() => this.mod.module.call(
                    expression.functionName,
                    parameters,
                    this.mapBinaryenType(functionType.returnType)
                ));
                addDebugStatement(call)
                return call;
            }
            case "IdentifierExpression": {
                let variable = this.mod.resolveSymbol(expression.identifier, 'all')
                if (!variable) {
                    throw new Error(`Undeclared variable ${expression.identifier}`);
                }
                if (variable.scope === 'global') {
                    return this.mod.module.global.get(expression.identifier, this.mapBinaryenType(variable.type));
                }
                const functionVariable = this.mod.resolveSymbol(expression.identifier, 'local');
                if (!functionVariable) {
                    throw new Error(`Could not find ${expression.identifier}`)
                }
                return addDebugStatement(this.mod.module.local.get(
                    functionVariable.index,
                    this.mapBinaryenType(functionVariable.type)
                ));
            }
            case "NumberExpression": {
                return addDebugStatement(
                    createBinaryenConst(this.mod.module, expression.type, expression.value!)
                );
            }

            case "ConditionalExpression": {
                return this.mod.module.if(
                    this.mod.addDebugStatement(this.emitExpression(expression.condition), expression.condition),
                    this.mod.module.block(null, expression.ifBody.map(b => this.emitStatement(b)), this.mapBinaryenType(expression.type)),
                    expression.elseBody ? this.mod.module.block(null, expression.elseBody.map(b => this.emitStatement(b as any)), this.mapBinaryenType(expression.type)) : undefined
                )
            }

            case 'StructInstantiationExpression':
                return this.instantiateStruct(expression);

            case 'DotExpression':
                return this.emitDotExpression(expression).at(-1)!.expression;

            case 'ArrayDeclarationExpression':
                return this.instantiateArray(expression)

            case "BinaryExpression": {
                const fn = this.binaryOperations.get(
                    [
                        expression.operator,
                        this.mapBinaryenType(expression.type),
                        this.mapBinaryenType(expression.type),
                    ].join()
                );

                if (!fn) {
                    throw new Error(
                        `no binary expression defined for ${typeToString(expression.type)} ${expression.operator}`
                    );
                }
                return addDebugStatement(fn(
                    this.emitExpression(expression.lhs),
                    this.emitExpression(expression.rhs)
                ));
            }
        }
        throw new Error("expression " + expression.kind + " is not implemented.");
    }

    private instantiateStruct(expression: StructInstantiationExpression): binaryen.ExpressionRef {
        assert(expression.type.kind === "struct");
        let structType = this.mapBinaryenType(expression.type)
        // TODO Map named properties
        const parameters = expression.parameters.map(p => this.emitExpression(p.value))
        const {addDebugStatement} = this.mod.createDebugStatement(expression);
        return addDebugStatement(gc.structs.newFromFields(this.mod.module, structType, parameters))
    }

    private instantiateArray(expression: ArrayDeclarationExpression): binaryen.ExpressionRef {
        assert(expression.type.kind === "array");
        if (expression.value) {
            return this.mod.addDebugStatement(
                gc.arrays.newFromItems(
                    this.mod.module,
                    this.mapBinaryenType(expression.type),
                    expression.value.map(p => this.emitExpression(p))
                ),
                expression
            );
        }
        if (expression.type.length === undefined) {
            throw new Error(`unknown array type for ${typeToString(expression.type)}`);
        }
        let init: binaryen.ExpressionRef | null = null;
        if (expression.type.type.kind === 'struct') {
            init = this.emitDefaultType(expression.type.type)
        }
        return this.mod.addDebugStatement(
            gc.arrays.newFromInit(
                this.mod.module,
                this.mapBinaryenType(expression.type),
                this.emitExpression(expression.type.length),
                init!
            ),
            expression
        );
    }

    private emitDotExpression(expression: DotExpression) {
        let exprs = this.emitExpression(expression.identifier);
        let previousType = expression.identifier.type
        const results = [{type: previousType, expression: exprs, index: -1}];
        for (let i = 0; i < expression.properties.length; i++) {
            const property = expression.properties[i];
            if (previousType.kind === 'struct') {
                assert(property.kind === 'IdentifierExpression');
                const index = previousType.parameters.findIndex(p => p.name === property.identifier)
                exprs = gc.structs.getMember(this.mod.module, exprs, index, this.mapBinaryenType(previousType.parameters[index].type), is_signed(property.type))
                previousType = property.type
                results.push({type: previousType, expression: exprs, index})
            } else if (previousType.kind === 'array') {
                assert(property.kind === 'ArrayIndexExpression');
                const index = this.emitExpression(property.index);
                // getItem could return null ref
                exprs = gc.arrays.getItem(
                    this.mod.module,
                    exprs,
                    index,
                    this.mapBinaryenType(property.type),
                    is_signed(property.type)
                )
                previousType = property.type
                results.push({type: previousType, expression: exprs, index})
            } else {
                throw new Error(`unimplemented dot expression with left side ${typeToString(previousType)}`)
            }
        }
        this.mod.addDebugStatement(results.at(-1)!.expression, expression)
        return results;
    }

    binaryOperations = new Map<string, (a: number, b: number) => number>([
        [["+", binaryen.i32, binaryen.i32].join(), this.mod.module.i32.add],
        [["+", binaryen.f32, binaryen.f32].join(), this.mod.module.f32.add],
        [["*", binaryen.i32, binaryen.i32].join(), this.mod.module.i32.mul],
        [["*", binaryen.f32, binaryen.f32].join(), this.mod.module.f32.mul],
        [["/", binaryen.i32, binaryen.i32].join(), this.mod.module.i32.div_u],
        [["/", binaryen.f32, binaryen.f32].join(), this.mod.module.f32.div],
        [["-", binaryen.i32, binaryen.i32].join(), this.mod.module.i32.sub],
        [["-", binaryen.f32, binaryen.f32].join(), this.mod.module.f32.sub],
        [['==', binaryen.i32, binaryen.i32].join(), this.mod.module.i32.eq],
        [['!=', binaryen.i32, binaryen.i32].join(), this.mod.module.i32.ne],
        [['&&', binaryen.i32, binaryen.i32].join(), this.mod.module.i32.and],
        [['||', binaryen.i32, binaryen.i32].join(), this.mod.module.i32.or],
        [['<', binaryen.i32, binaryen.i32].join(), this.mod.module.i32.lt_u],
        [['<=', binaryen.i32, binaryen.i32].join(), this.mod.module.i32.le_u],
        [['>', binaryen.i32, binaryen.i32].join(), this.mod.module.i32.gt_u],
        [['>=', binaryen.i32, binaryen.i32].join(), this.mod.module.i32.ge_u],
        [['%', binaryen.i32, binaryen.i32].join(), this.mod.module.i32.rem_u],
    ]);


    emitPrint(stmt: CallExpression) {
        assert(stmt.parameters[0]?.kind === "StringExpression");
        const string = stmt.parameters[0] as StringExpression;

        const string_memory_address = this.mod.malloc(encoder.encode(string.value));
        const iov_memory_address = this.mod.malloc(size_of(BasicVaderType.ptr) + size_of(BasicVaderType.u32));
        const result_memory_address = this.mod.malloc(size_of(BasicVaderType.u32));

        return this.mod.addDebugStatement(
            this.mod.module.block(null, [
                // Store iovs
                // Start of data  (= *buf)
                this.mod.module.i32.store(
                    0,
                    0,
                    this.mod.module.i32.const(iov_memory_address.offset),
                    this.mod.module.i32.const(string_memory_address.offset),
                ),
                // Length of data (= buf_len)
                this.mod.module.i32.store(
                    0,
                    0,
                    this.mod.module.i32.const(iov_memory_address.offset + 4),
                    this.mod.module.i32.const(string_memory_address.data.length),
                ),
                this.mod.module.drop(
                    this.mod.module.call(
                        "wasi_snapshot_preview1:fd_write",
                        [
                            this.mod.module.i32.const(1), // stdout = 1
                            this.mod.module.i32.const(iov_memory_address.offset), // ptr of iovs
                            this.mod.module.i32.const(1), // number of iovs (iovs is an array)
                            this.mod.module.i32.const(result_memory_address.offset), // where to store the returned error code
                        ],
                        binaryen.i32
                    )
                ),
            ]),
            stmt);
    }

    emitExit(stmt: CallExpression) {
        assert(stmt.parameters.length === 1);
        return this.mod.addDebugStatement(
            this.mod.module.call("wasi_snapshot_preview1:proc_exit", [
                this.emitExpression(stmt.parameters[0])
            ], binaryen.none),
            stmt);
    }

    private emitArrayLength(expression: CallExpression) {
        assert(expression.parameters.length === 1)
        assert(expression.parameters[0].type.kind === 'array');
        return this.mod.addDebugStatement(
            gc.arrays.length(this.mod.module, this.emitExpression(expression.parameters[0])),
            expression
        );
    }

    mapBinaryenType(t: VaderType): binaryen.Type {
        if (t.kind === 'array') {
            const type = this.customTypes.get(t);
            if (type) {
                return type
            }
            const builder = new TypeBuilder(1);
            builder.setArrayType(0, {
                type: this.mapBinaryenType(t.type), packedType: 0, mutable: true
            })
            const expr = builder.buildAndDispose().heapTypes[0]
            this.customTypes.set(t, expr);
            return expr;
        }
        if (t.kind === 'struct') {
            const type = this.customTypes.get(t)
            if (type) {
                return type;
            }
            const builder = new TypeBuilder(1);
            builder.setStructType(0, t.parameters.map(parameter => {
                return {
                    type: this.mapBinaryenType(parameter.type),
                    packedType: 0,
                    mutable: true,
                }
            }))
            const expr = builder.buildAndDispose().heapTypes[0];
            this.customTypes.set(t, expr)
            return expr;
        }
        if (t.kind === 'function') {
            throw new Error(`Unreachable`)
        }
        switch (t.name) {
            case "boolean":
            case "int":
            case "u8":
            case "u16":
            case "u32":
                return binaryen.i32;
            case "long":
            case "u64":
                return binaryen.i64;
            case "float":
            case "f32":
                return binaryen.f32;
            case "f64":
                return binaryen.f64;
            case "void":
                return binaryen.none;
        }
        throw new Error(`Type mapping for ${typeToString(t)} is not implemented.`);
    }

    private emitDefaultType(type: VaderType): binaryen.ExpressionRef {
        switch (type.kind) {
            case "primitive":
                return createBinaryenConst(this.mod.module, type, 0)
            case "struct": {
                const structType = this.mapBinaryenType(type)
                const parameters = type.parameters.map(p => this.emitDefaultType(p.type))
                return gc.structs.newFromFields(this.mod.module, structType, parameters)
            }
            case 'array': {
                const arrayType = this.mapBinaryenType(type);
                return gc.arrays.newFromItems(this.mod.module, arrayType, []);
            }
        }
        throw new Error(`could not emit default value for ${typeToString(type)}`)

    }
}


function size_of(t: VaderType): number {
    if (t.kind === 'array') {
        return 4;
    }
    if (t.kind === 'struct') {
        return 4;
    }

    if (t.kind === 'function') {
        throw new Error(`unreachable`)
    }
    switch (t.name) {
        case "boolean":
        case "u8":
        case "u32":
            return 4;
        case "long":
        case "u64":
            return 8;
        case "float":
        case "f32":
            return 4;
        case "f64":
            return 8;
        case "void":
            return 0;
    }
    throw new Error("size of type " + typeToString(t) + " is not implemented.");
}

function is_signed(type: VaderType) {
    if (type.kind === 'primitive') {
        return type.signed;
    }
    return false;
}

function createBinaryenConst(module: binaryen.Module, t: VaderType, value: number = 0) {
    if (t.kind === 'array') {
        throw new Error(`Unimplemented array type`)
    }
    if (t.kind === 'function') {
        throw new Error(`Unreachable`)
    }
    if (t.kind === 'struct') {
        throw new Error(`Unreachable`)
    }
    switch (t.name) {
        case "boolean":
        case "int":
        case "u8":
        case "u16":
        case "u32":
            return module.i32.const(value);
        case "long":
        case "u64":
            return module.i64.const(value, 0);
        case "float":
        case "f32":
            return module.f32.const(value);
        case "f64":
            return module.f64.const(value);
        case "void":
            return binaryen.none;
    }
    throw new Error("const of type " + typeToString(t) + " is not implemented.");
}

