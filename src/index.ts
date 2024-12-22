import {tokenize} from './tokens'
import {parseProgram} from "./parser";
import util from 'node:util'

const source = `
struct Square {
    width: u8
}

fun add(a: u8, b: u8): u8 {
    return a + b
}

// Single line comment
fun main(): int {
    var a = add(2, 3) * 4 / 4
    if(a == 0) {
        println(0)
    } elif (demo) {
        println(1)
    } else {
        println(2)
    }
    println("Hello world \${a}")
    return 0
}
`;

for (const token of tokenize(source)) {
    console.log(token)
}

const root = parseProgram(source);
console.log(util.inspect(root, {depth: null}))