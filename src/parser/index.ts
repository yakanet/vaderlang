import {type Program,} from "./types.ts";
import type {ModuleResolver} from "../resolver/module_resolver.ts";
import {Parser} from "./parser.ts";
import {parseStatement} from "./statement.ts";

export function parseProgram(entryFile: string, resolver: ModuleResolver): Program {
    const parser = new Parser(resolver);
    parser.loadVaderFile(entryFile)
    const program: Program = {
        kind: 'Program',
        body: [],
        location: {
            ...parser.current.location,
            start: 0
        }
    }
    while (!parser.isCurrentType('EOF')) {
        program.body.push(parseStatement(parser))
    }
    const lastToken = parser.expect('EOF');
    program.location.end = lastToken.location.end;
    return program;
}

