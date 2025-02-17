import {gc, TypeBuilder} from "binaryen-gc";
import binaryen from "binaryen";
import fs from "node:fs";

const builder = new TypeBuilder(2);

// Simple Vec type { x: i32, y: i32, z: i32 }
builder.setStructType(0, [
    {type: binaryen.i32, packedType: 0, mutable: true},
    {type: binaryen.i32, packedType: 0, mutable: true},
    {type: binaryen.i32, packedType: 0, mutable: true},
]);

// Simple Array type i32[]
builder.setArrayType(1, {
    type: binaryen.i32, packedType: 0, mutable: true
})

const types = builder.buildAndDispose();

const [structType, arrayType] = types.heapTypes;

// Simple module with a function that returns a Vec, and a main function that reads the x value
const mod = new binaryen.Module();
mod.setFeatures(binaryen.Features.All);

// Main function that reads the x value of the Vec
 mod.addFunction(
    "main",
    binaryen.none,
    binaryen.i32,
    [structType, arrayType, binaryen.i32, binaryen.i32],
    mod.block(null, [
        mod.local.set(0, gc.structs.newFromFields(mod, structType, [
            mod.i32.const(1),
            mod.i32.const(2),
            mod.i32.const(3),
        ])),
        mod.local.set(1, gc.arrays.newFromItems(mod, arrayType, [
            mod.i32.const(1),
            mod.i32.const(2),
            mod.i32.const(3)
        ])),
        gc.structs.setMember(mod, mod.local.get(0, structType), 0, mod.i32.const(100)),
        mod.local.set(2, gc.structs.getMember(mod, mod.local.get(0, structType), 0, binaryen.i32, false)),
        mod.local.set(3, gc.arrays.getItem(mod, mod.local.get(1, arrayType), mod.i32.const(1), binaryen.i32, false)),
        mod.local.get(2, binaryen.i32)
    ])
);
mod.addFunctionExport("main", "main");
//mod.optimize()
mod.validate();
//mod.setStart(f)

mod.setMemory(1, -1, "memory")

console.log(mod.emitText());
fs.writeFileSync('gc.wasm', mod.emitBinary())