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

const encoder = new TextEncoder();

const GLOBAL_SCOPE = '$$GLOBAL_SCOPE$$'

export class WasmEmitter {
    private memoryLayout: { offset: number, data: Uint8Array }[] = [];
    private memoryOffset = 0;

    public readonly module = new binaryen.Module();
    private forCount = 0;
    private currentScope: string = GLOBAL_SCOPE;
    private symbols: Record<string, Map<string, {
        type: VaderType,
        index: number,
        scope: 'parameter' | 'local' | 'global'
    }>> = {};
    private customTypes = new Map<VaderType, binaryen.Type>();

    constructor() {
        addWasiFunction(this.module);
        this.symbols[GLOBAL_SCOPE] = new Map();
    }

    emit(program: Program) {
        this.module.setFeatures(binaryen.Features.All)
        this.module.setMemory(1, -1);

        for (const statement of program.body) {
            this.emitTopLevelStatement(statement);
        }

        this.emitMainMethod(program);

        this.module.setMemory(1, -1, "memory", this.memoryLayout.map(layout => ({
            data: layout.data,
            offset: this.module.i32.const(layout.offset),
        })));
        assert(this.module.validate());
        this.module.optimize()
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
            const funct = this.module.addFunction(
                "_start",
                binaryen.createType([]),
                binaryen.none,
                [],
                this.module.block(null, [
                    this.module.call(
                        "wasi_snapshot_preview1:proc_exit",
                        [this.module.call(mainVariable.name, [], binaryen.i32)],
                        binaryen.none
                    ),
                ])
            );
            this.module.setStart(funct);
        } else if (isTypeEquals(mainFunction.type.returnType, BasicVaderType.void)) {
            this.module.setStart(this.module.getFunction(mainVariable.name));
        } else {
            throw new Error(`main method should return a void type or u32 type`)
        }
    }

    emitTopLevelStatement(statement: Statement) {
        switch (statement.kind) {
            case "VariableDeclarationStatement": {
                assert(this.currentScope === GLOBAL_SCOPE);
                this.symbols[this.currentScope].set(
                    statement.name,
                    {
                        type: statement.type,
                        scope: 'global',
                        index: -1
                    }
                )
                switch (statement.type.kind) {
                    case 'struct': {
                        const builder = new TypeBuilder(1);
                        builder.setStructType(0, statement.type.parameters.map(parameter => {
                            return {
                                type: this.mapBinaryenType(parameter.type),
                                packedType: 0,
                                mutable: true,
                            }
                        }))
                        this.customTypes.set(statement.type, builder.buildAndDispose().heapTypes[0])
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
                        this.currentScope = statement.name;
                        this.symbols[this.currentScope] = new Map()
                        for (const parameter of funct.type.parameters) {
                            this.symbols[this.currentScope].set(parameter.name, {
                                type: parameter.type,
                                scope: 'parameter',
                                index: this.symbols[this.currentScope].size
                            })
                        }
                        const body = funct.body.map((stmt) => this.emitStatement(stmt))
                        this.module.addFunction(
                            statement.name,
                            binaryen.createType(
                                [...this.symbols[this.currentScope].values()]
                                    .filter(({scope}) => scope === 'parameter')
                                    .map(({type}) => this.mapBinaryenType(type))
                            ),
                            this.mapBinaryenType(funct.type.returnType),
                            [...this.symbols[this.currentScope].values()]
                                .filter(({scope}) => scope === 'local')
                                .map(({type}) => this.mapBinaryenType(type)),
                            this.module.block(null, body)
                        );
                        this.currentScope = GLOBAL_SCOPE;
                        //this.module.addFunctionExport(statement.name, statement.name);
                        return;
                    }
                    case 'primitive':
                        return this.module.addGlobal(
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
        switch (stmt.kind) {
            case "ReturnStatement":
                return this.module.return(this.emitExpression(stmt.expression));

            case "ConditionalStatement": {
                return this.module.if(
                    this.emitExpression(stmt.condition),
                    this.module.block(null, stmt.ifBody.map(b => this.emitStatement(b))),
                    stmt.elseBody ? this.module.block(null, stmt.elseBody.map(b => this.emitStatement(b as any))) : undefined
                )
            }

            case "VariableDeclarationStatement": {
                if (this.currentScope === GLOBAL_SCOPE) {
                    this.symbols[this.currentScope].set(stmt.name, {
                        type: stmt.type,
                        scope: 'global',
                        index: -1
                    })
                    return this.module.global.set(
                        stmt.name,
                        this.emitExpression(stmt.value!)
                    );
                }
                const variable = this.symbols[this.currentScope].get(stmt.name)
                if (variable) {
                    throw new Error(`redefinition of variable ${stmt.name}`)
                }
                const index = this.symbols[this.currentScope].size
                this.symbols[this.currentScope].set(stmt.name, {
                    type: stmt.type,
                    scope: 'local',
                    index
                })
                return this.module.local.set(index, this.emitExpression(stmt.value!))
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
                        return gc.structs.setMember(this.module, base.expression, param.index, this.emitExpression(stmt.value))
                    }  if (keys.at(-2)!.type.kind === 'array') {
                        const base = keys.at(-2)!
                        const param = keys.at(-1)!;
                        assert(param);
                        return gc.arrays.setItem(this.module, base.expression, param.index, this.emitExpression(stmt.value))
                    } else {
                        throw new Error(`Unimplemented assignment on ${typeToString(identifier.type)}`)
                    }
                }
                if (identifier.kind === 'IdentifierExpression') {
                    let variable =
                        this.symbols[this.currentScope].get(identifier.identifier)
                        ?? this.symbols[GLOBAL_SCOPE].get(identifier.identifier)
                    if (!variable) {
                        throw new Error(`Undeclared variable ${identifier.identifier}`);
                    }
                    if (variable.scope === 'global') {
                        return this.module.global.set(
                            identifier.identifier,
                            this.emitExpression(stmt.value)
                        );
                    }
                    return this.module.local.set(variable.index, this.emitExpression(stmt.value));
                } else {
                    throw new Error(`assignment with left-side dynamic is not supported yet`)
                }
            }

            case 'ForStatement': {
                const forCount = this.forCount++;
                return this.module.block(null, [
                    this.emitStatement(stmt.initialization),
                    this.module.loop('outer_' + forCount,
                        this.module.block('inner_' + forCount, [
                            this.module.br_if('inner_' + forCount, this.module.i32.eqz(this.emitStatement(stmt.condition))),
                            ...stmt.body.map(b => this.emitStatement(b)),
                            this.emitStatement(stmt.iteration),
                            this.module.br('outer_' + forCount)
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
        switch (expression.kind) {
            case 'CallExpression': {
                const functionType = this.symbols[GLOBAL_SCOPE].get(expression.functionName)?.type;
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

                const previousScope = this.currentScope;
                this.currentScope = expression.functionName;
                const result = this.module.call(
                    expression.functionName,
                    parameters,
                    this.mapBinaryenType(functionType.returnType)
                );
                this.currentScope = previousScope;
                return result
            }
            case "IdentifierExpression": {
                let variable =
                    this.symbols[this.currentScope].get(expression.identifier)
                    ?? this.symbols[GLOBAL_SCOPE].get(expression.identifier)
                if (!variable) {
                    throw new Error(`Undeclared variable ${expression.identifier}`);
                }
                if (variable.scope === 'global') {
                    return this.module.global.get(expression.identifier, this.mapBinaryenType(variable.type));
                }
                const functionVariable = this.symbols[this.currentScope].get(expression.identifier);
                if (!functionVariable) {
                    throw new Error(`Could not find ${expression.identifier} in ${this.currentScope}`)
                }
                return this.module.local.get(
                    functionVariable.index,
                    this.mapBinaryenType(functionVariable.type)
                );
            }
            case "NumberExpression": {
                return createBinaryenConst(this.module, expression.type, expression.value!);
            }

            case "ConditionalExpression": {
                return this.module.if(
                    this.emitExpression(expression.condition),
                    this.module.block(null, expression.ifBody.map(b => this.emitStatement(b)), this.mapBinaryenType(expression.type)),
                    expression.elseBody ? this.module.block(null, expression.elseBody.map(b => this.emitStatement(b as any)), this.mapBinaryenType(expression.type)) : undefined
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
                return fn(
                    this.emitExpression(expression.lhs),
                    this.emitExpression(expression.rhs)
                );
            }
        }
        throw new Error("expression " + expression.kind + " is not implemented.");
    }

    private instantiateStruct(expression: StructInstantiationExpression): binaryen.ExpressionRef {
        assert(expression.type.kind === "struct");
        const structType = this.customTypes.get(expression.type)
        if (!structType) {
            throw new Error(`Undeclared struct ${typeToString(expression.type)}`)
        }
        // TODO Map named properties
        const parameters = expression.parameters.map(p => this.emitExpression(p.value))
        return gc.structs.newFromFields(this.module, structType, parameters)
    }

    private instantiateArray(expression: ArrayDeclarationExpression): binaryen.ExpressionRef {
        assert(expression.type.kind === "array");
        if (expression.value) {
            return gc.arrays.newFromItems(this.module, this.mapBinaryenType(expression.type), expression.value.map(p => this.emitExpression(p)))
        }
        if (expression.type.length === undefined) {
            throw new Error(`unknown array type for ${typeToString(expression.type)}`);
        }
        return gc.arrays.newFromInit(this.module, this.mapBinaryenType(expression.type), this.emitExpression(expression.type.length), null);
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
                exprs = gc.structs.getMember(this.module, exprs, index, this.mapBinaryenType(previousType.parameters[index].type), false)
                previousType = property.type
                results.push({type: previousType, expression: exprs, index})
            } else if (previousType.kind === 'array') {
                assert(property.kind === 'ArrayIndexExpression');
                const index = this.emitExpression(property.index);
                // getItem could return null ref
                exprs = gc.arrays.getItem(
                    this.module,
                    exprs,
                    index,
                    this.mapBinaryenType(property.type),
                    false
                )
                previousType = property.index.type
                results.push({type: previousType, expression: exprs, index})
            } else {
                throw new Error(`unimplemented dot expression with left side ${typeToString(previousType)}`)
            }
        }
        return results;
    }

    binaryOperations = new Map<string, (a: number, b: number) => number>([
        [["+", binaryen.i32, binaryen.i32].join(), this.module.i32.add],
        [["+", binaryen.f32, binaryen.f32].join(), this.module.f32.add],
        [["*", binaryen.i32, binaryen.i32].join(), this.module.i32.mul],
        [["*", binaryen.f32, binaryen.f32].join(), this.module.f32.mul],
        [["/", binaryen.i32, binaryen.i32].join(), this.module.i32.div_u],
        [["/", binaryen.f32, binaryen.f32].join(), this.module.f32.div],
        [["-", binaryen.i32, binaryen.i32].join(), this.module.i32.sub],
        [["-", binaryen.f32, binaryen.f32].join(), this.module.f32.sub],
        [['==', binaryen.i32, binaryen.i32].join(), this.module.i32.eq],
        [['!=', binaryen.i32, binaryen.i32].join(), this.module.i32.ne],
        [['&&', binaryen.i32, binaryen.i32].join(), this.module.i32.and],
        [['||', binaryen.i32, binaryen.i32].join(), this.module.i32.or],
        [['<', binaryen.i32, binaryen.i32].join(), this.module.i32.lt_u],
        [['<=', binaryen.i32, binaryen.i32].join(), this.module.i32.le_u],
        [['>', binaryen.i32, binaryen.i32].join(), this.module.i32.gt_u],
        [['>=', binaryen.i32, binaryen.i32].join(), this.module.i32.ge_u],
        [['%', binaryen.i32, binaryen.i32].join(), this.module.i32.rem_u],
    ]);

    malloc(sizeOrData: number | Uint8Array): binaryen.MemorySegment {
        const size = typeof sizeOrData === "number" ? sizeOrData : sizeOrData.length;
        const data = typeof sizeOrData === "number" ? new Uint8Array(sizeOrData) : sizeOrData;
        const segment: binaryen.MemorySegment = {
            data,
            offset: this.memoryOffset,
        };
        this.memoryOffset += align_ptr(size)
        this.memoryLayout.push(segment);
        return segment;
    }

    emitPrint(stmt: CallExpression) {
        assert(stmt.parameters[0]?.kind === "StringExpression");
        const string = stmt.parameters[0] as StringExpression;

        const string_memory_address = this.malloc(encoder.encode(string.value));
        const iov_memory_address = this.malloc(size_of(BasicVaderType.ptr) + size_of(BasicVaderType.u32));
        const result_memory_address = this.malloc(size_of(BasicVaderType.u32));

        return this.module.block(null, [
            // Store iovs
            // Start of data  (= *buf)
            this.module.i32.store(
                0,
                0,
                this.module.i32.const(iov_memory_address.offset),
                this.module.i32.const(string_memory_address.offset),
            ),
            // Length of data (= buf_len)
            this.module.i32.store(
                0,
                0,
                this.module.i32.const(iov_memory_address.offset + 4),
                this.module.i32.const(string_memory_address.data.length),
            ),
            this.module.drop(
                this.module.call(
                    "wasi_snapshot_preview1:fd_write",
                    [
                        this.module.i32.const(1), // stdout = 1
                        this.module.i32.const(iov_memory_address.offset), // ptr of iovs
                        this.module.i32.const(1), // number of iovs (iovs is an array)
                        this.module.i32.const(result_memory_address.offset), // where to store the returned error code
                    ],
                    binaryen.i32
                )
            ),
        ]);
    }

    emitExit(stmt: CallExpression) {
        assert(stmt.parameters.length === 1);
        return this.module.call("wasi_snapshot_preview1:proc_exit", [
            this.emitExpression(stmt.parameters[0])
        ], binaryen.none)
    }

    private emitArrayLength(expression: CallExpression) {
        assert(expression.parameters.length === 1)
        assert(expression.parameters[0].type.kind === 'array');
        return gc.arrays.length(this.module, this.emitExpression(expression.parameters[0]))
    }

    mapBinaryenType(t: VaderType): binaryen.Type {
        if (t.kind === 'array') {
            if (!this.customTypes.has(t)) {
                const builder = new TypeBuilder(1);
                builder.setArrayType(0, {
                    type: this.mapBinaryenType(t.type), packedType: 0, mutable: true
                })
                this.customTypes.set(t, builder.buildAndDispose().heapTypes[0])
            }
            return this.customTypes.get(t)!;
        }
        if (t.kind === 'struct') {
            const type = this.customTypes.get(t)
            if (!type) {
                throw new Error(`Undeclared type ${typeToString(t)}`)
            }
            return type;
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
}

function align_ptr(address: number) {
    if (address % 4 === 0) {
        return address;
    }
    return address + 4 - (address % 4);
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

function createBinaryenConst(module: binaryen.Module, t: VaderType, value: number) {
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

