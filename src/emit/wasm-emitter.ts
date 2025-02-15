import {
    type ArrayDeclarationExpression,
    type ArrayIndexExpression,
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

const encoder = new TextEncoder();

const GLOBAL_SCOPE = '$$GLOBAL_SCOPE$$'

export class WasmEmitter {
    private memoryLayout: { offset: number, data: Uint8Array }[] = [];
    public readonly module = new binaryen.Module();
    private forCount = 0;
    private currentScope: string = GLOBAL_SCOPE;
    private symbols: Record<string, Map<string, {
        type: VaderType,
        index: number,
        scope: 'parameter' | 'local' | 'global'
    }>> = {};

    constructor() {
        addWasiFunction(this.module);
        this.symbols[GLOBAL_SCOPE] = new Map();
    }

    emit(program: Program) {
        this.module.setMemory(1, -1);

        for (const statement of program.body) {
            this.emitTopLevelStatement(statement);
        }

        this.emitMainMethod(program);

        this.module.setMemory(1, -1, "memory", this.memoryLayout.map(layout => ({
            data: layout.data,
            offset: this.module.i32.const(layout.offset),
        })));
        this.module.optimize();
        assert(this.module.validate());
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
                    case 'struct':
                        return;
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
                                    .map(({type}) => mapBinaryenType(type))
                            ),
                            mapBinaryenType(funct.type.returnType),
                            [...this.symbols[this.currentScope].values()]
                                .filter(({scope}) => scope === 'local')
                                .map(({type}) => mapBinaryenType(type)),
                            this.module.block(null, body)
                        );
                        this.currentScope = GLOBAL_SCOPE;
                        this.module.addFunctionExport(statement.name, statement.name);
                        return;
                    }
                    case 'array':
                    case 'primitive':
                        return this.module.addGlobal(
                            statement.name,
                            mapBinaryenType(statement.type),
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
                let variable =
                    this.symbols[this.currentScope].get(stmt.identifier)
                    ?? this.symbols[GLOBAL_SCOPE].get(stmt.identifier)
                if (!variable) {
                    throw new Error(`Undeclared variable ${stmt.identifier}`);
                }
                if (variable.scope === 'global') {
                    return this.module.global.set(
                        stmt.identifier,
                        this.emitExpression(stmt.value)
                    );
                }
                return this.module.local.set(variable.index, this.emitExpression(stmt.value));
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
        expression: Statement
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
                    mapBinaryenType(functionType.returnType)
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
                if(variable.scope === 'global') {
                    return this.module.global.get(expression.identifier, mapBinaryenType(variable.type));
                }
                const functionVariable = this.symbols[this.currentScope].get(expression.identifier);
                if (!functionVariable) {
                    throw new Error(`Could not find ${expression.identifier} in ${this.currentScope}`)
                }
                return this.module.local.get(
                    functionVariable.index,
                    mapBinaryenType(functionVariable.type)
                );
            }
            case "NumberExpression": {
                return createBinaryenConst(this.module, expression.type, expression.value!);
            }

            case "ConditionalExpression": {
                return this.module.if(
                    this.emitExpression(expression.condition),
                    this.module.block(null, expression.ifBody.map(b => this.emitStatement(b)), mapBinaryenType(expression.type)),
                    expression.elseBody ? this.module.block(null, expression.elseBody.map(b => this.emitStatement(b as any)), mapBinaryenType(expression.type)) : undefined
                )
            }

            case 'StructInstantiationExpression':
                return this.instantiateStruct(expression);

            case 'DotExpression':
                return this.emitDotExpression(expression);

            case 'ArrayDeclarationExpression':
                return this.instantiateArray(expression)

            case 'ArrayIndexExpression':
                return this.emitArrayIndexExpression(expression)

            case "BinaryExpression": {
                const fn = this.binaryOperations.get(
                    [
                        expression.operator,
                        mapBinaryenType(expression.type),
                        mapBinaryenType(expression.type),
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
        const size = size_of(expression.type);
        const segment = this.malloc(size);
        let offset = 0;
        const exp: binaryen.ExpressionRef[] = [];
        for (const p of expression.parameters) {
            exp.push(this.module.i32.store(
                offset,
                0,
                this.module.i32.const(segment.offset),
                this.emitExpression(p.value)
            ));
            offset += size_of(p.value.type);
        }
        return this.module.block(null, [
            ...exp,
            this.module.i32.const(segment.offset)
        ], binaryen.i32);
    }

    private instantiateArray(expression: ArrayDeclarationExpression): binaryen.ExpressionRef {
        assert(expression.type.kind === "array");
        if (expression.type.length === undefined) {
            throw new Error(`unknown array type for ${typeToString(expression.type)}`);
        }
        const size = size_of(expression.type);
        const segment = this.malloc(size);
        let offset = 0;
        let primitive_type: VaderType = expression.type;
        while (primitive_type.kind === "array") {
            primitive_type = primitive_type.type
        }
        const offset_padding = size_of(primitive_type);
        const exp: binaryen.ExpressionRef[] = [];
        if (expression.value) {
            for (const v of expression.value) {
                exp.push(this.module.i32.store(
                    offset,
                    0,
                    this.module.i32.const(segment.offset),
                    this.emitExpression(v)
                ))
                offset += offset_padding;
            }
        }
        return this.module.block(null, [
            ...exp,
            this.module.i32.const(segment.offset)
        ], binaryen.i32);
    }

    private emitDotExpression(expression: DotExpression) {
        let exprs: binaryen.ExpressionRef
        if (this.currentScope === GLOBAL_SCOPE) {
            exprs = this.module.global.get(expression.properties[0].name, binaryen.i32);
        } else {
            const functionVariable = this.symbols[this.currentScope].get(expression.properties[0].name);
            if (!functionVariable) {
                throw new Error(`could not resolve ${expression.properties[0].name} in ${this.currentScope}`);
            }
            exprs = this.module.local.get(functionVariable.index, binaryen.i32);
        }
        let previousType = expression.properties[0].type
        for (let i = 1; i < expression.properties.length; i++) {
            if (previousType.kind === 'struct') {
                let offset = 0;
                const index = previousType.parameters.findIndex(p => p.name === expression.properties[i].name)
                for (let j = 0; j < index; j++) {
                    offset += size_of(previousType.parameters[j].type);
                }
                exprs = this.module.i32.load(
                    offset,
                    0,
                    exprs,
                )
                previousType = previousType.parameters[index].type
            }
        }
        return exprs;
    }

    private emitArrayIndexExpression(expression: ArrayIndexExpression) {
        const identifier = this.emitExpression(expression.identifier);
        let index = this.module.i32.const(1);
        let lastType = expression.type;
        for (let i = 0; i < expression.indexes.length; i++) {
            index = this.module.i32.mul(index, this.emitExpression(expression.indexes[i]));
            lastType = (lastType as any).type
        }
        index = this.module.i32.mul(index, this.module.i32.const(size_of(lastType)));
        return this.module.i32.load(
            0,
            0,
            this.module.i32.add(identifier, index),
        )
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
    ]);

    private memoryOffset = 0;

    malloc(sizeOrData: number | Uint8Array): binaryen.MemorySegment {
        const size = typeof sizeOrData === "number" ? sizeOrData : sizeOrData.length;
        const data = typeof sizeOrData === "number" ? new Uint8Array(sizeOrData) : sizeOrData;
        const segment: binaryen.MemorySegment = {
            data,
            offset: this.memoryOffset,
        };
        this.memoryOffset += align_ptr(size + 1)
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
}

function align_ptr(address: number) {
    if (address % 4 === 0) {
        return address;
    }
    return address + 4 - (address % 4);
}

function size_of(t: VaderType): number {
    if (t.kind === 'array') {
        return (t.length ?? 1) * size_of(t.type);
    }
    if (t.kind === 'struct') {
        let size = 0;
        for (const p of t.parameters) {
            size += size_of(p.type)
        }
        return size;
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

function mapBinaryenType(t: VaderType): binaryen.Type {
    if (t.kind === 'array') {
        return binaryen.i32;
    }
    if (t.kind === 'struct') {
        return binaryen.i32;
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
