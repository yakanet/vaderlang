import {tokenize} from './tokens'
import {parseProgram} from "./parser";
import util from 'node:util'
import fs from 'node:fs';
import child_process from "node:child_process";
import {QbeEmitter} from "./emit/qbe-emitter.ts";

const source = `
fun add(a: w, b: w): w {
    return a + b
}

fun main(): w {
    //val a: w = 2 + 3
    //val b: w = add(a, 6)
    printf("Hello world\n")
    return 33
}
// struct Square {
//     width: u8
// }
// 
// 
// 
// 
// 
// // Single line comment
// fun main(): u8 {
//     var a = 2 + 3 * 4
//     if(a == 0) {
//         println(0)
//     } elif (demo) {
//         println(1)
//     } else {
//         println(2)
//     }
//     println("Hello world \${a}")
//     return 0
// }
`;

for (const token of tokenize(source)) {
    console.log(token)
}

const root = parseProgram(source);
console.log(util.inspect(root, {depth: null}));

let buffer = '';
const emitter = new QbeEmitter((message) => buffer += message)
emitter.emit(root)
fs.mkdirSync('build/qbe', {recursive: true, });
fs.writeFileSync('build/qbe/build.ssa', buffer, {encoding: "utf-8"})
execCommand(['qbe', '-o', 'build/qbe/build-arm64-darwin.s', '-t', 'arm64_apple', 'build/qbe/build.ssa'])
execCommand(['qbe', '-o', 'build/qbe/build-amd64-darwin.s', '-t', 'amd64_apple', 'build/qbe/build.ssa'])

execCommand(['cc', '-o', 'build/app', 'build/qbe/build-arm64-darwin.s'])

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
