# Build plugins

A project builds from a `vader.json`, or from a `build.vader` when it wants a say in its own build: a Vader program, the build driver, that `vader build` compiles and runs. A plugin is the part of a driver worth sharing, a type that listens to the build: one observes it, one enforces a rule, one writes code. Each example is a project of two files, `src/main.vader` and `build.vader`, shown in that order; the driver keeps its `module` and its imports, which are part of what it shows.

## A build driver

The program, `src/main.vader`:

```vader
# module "app"
# import "std/console"
Point :: struct {
    x: i32
    y: i32
}

main :: fn() -> i32 {
    p :: Point { .x = 1, .y = 2 }
    println("${p.x + p.y}")
    return 0
}
```

```text
3
```

The driver next to it, `build.vader`:

```vader
module "build"

import "toolchain/build"

build :: fn(args: string[]) -> i32 {
    ctx :: new_build_context(args)
    ctx.add_entry("app", "src/main.vader")
    return ctx.emit_native()
}
```

`ctx.add_entry` names a program to build, and `ctx.emit_native()` runs the build and returns its exit code. The driver is an ordinary program: what it prints, `vader build` prints. The rules: §11 *Programmable build API* and §11 *What the command decides*.

## A plugin that observes

A plugin implements `BuildPlugin`, whose members do nothing unless it overrides them: `on_module` hears each module of the project once it is type checked, `on_phase` each phase the build reaches, and `on_complete` the end of the build. `ctx.use` plugs it in. Its state lives in its fields. With the same `src/main.vader`:

```vader
module "build"

import "std/console"
import "toolchain/build"
AST :: import "toolchain/ast"

// Counts the structs and the functions of the project.
Census :: struct {
    structs: i32 = 0
    functions: i32 = 0
}

Census implements BuildPlugin {
    on_module :: fn(self, ctx: BuildContext, msg: TypecheckedMessage) -> void {
        for d in msg.declarations {
            if d is AST.StructDecl {
                self.structs += 1
            }
            if d is AST.FnDecl {
                self.functions += 1
            }
        }
    }

    on_complete :: fn(self, ctx: BuildContext, code: i32) -> void {
        println("census: ${self.structs} struct(s), ${self.functions} function(s)")
    }
}

build :: fn(args: string[]) -> i32 {
    ctx :: new_build_context(args)
    ctx.add_entry("app", "src/main.vader")
    ctx.use(Census {})
    return ctx.emit_native()
}
```

```text
census: 1 struct(s), 1 function(s)
```

A plugin receives the declarations as nodes of `toolchain/ast`: every declaration of the module, with what it writes outside the body of a function. A function arrives with its signature, a constant with its value, a struct with its fields and their defaults; the body of a function stays behind. The vaderdoc written above a declaration is asked for: `ctx.doc_of(d)`. Only the modules of the project arrive, never those of the standard library. The rules: §11 *Plugins* and §11 *The message stream*.

## A plugin that enforces a rule

`ctx.report` points at a place in the source and fails the build, as any error does. A house rule, struct names start with a capital, applied to a program that breaks it:

```vader
# module "app"
# import "std/console"
point :: struct {
    x: i32
}
#
# main :: fn() -> i32 {
#     p :: point { .x = 1 }
#     println("${p.x}")
#     return 0
# }
```

```vader
module "build"

import "std/string"
import "toolchain/build"
AST :: import "toolchain/ast"

// Struct names start with a capital.
Capitalised :: struct {}

Capitalised implements BuildPlugin {
    on_module :: fn(self, ctx: BuildContext, msg: TypecheckedMessage) -> void {
        for d in msg.declarations {
            if d is AST.StructDecl && d.name[0..<1].to_upper() != d.name[0..<1] {
                ctx.report(d.name_span, "struct `${d.name}` should start with a capital")
            }
        }
    }
}

build :: fn(args: string[]) -> i32 {
    ctx :: new_build_context(args)
    ctx.add_entry("app", "src/main.vader")
    ctx.use(Capitalised {})
    return ctx.emit_native()
}
```

```text
[src/main.vader:3:1] error[H6004] build driver reported a problem: struct `point` should start with a capital
```

The build stops there, as on any other error: the program is not written. The rules: §11 *Plugins*.

## A plugin that writes code

`ctx.emit_module(name, source)` hands the build the text of a module. Given the name of a module of the project, the text joins that module, so the code it holds sees the module's declarations. The build type checks it with the rest, in a round of its own, and the plugin hears it like any other module. This program calls a `describe` it does not write:

```vader
# module "app"
# import "std/console"
Point :: struct {
    x: i32
    y: i32
}

main :: fn() -> i32 {
    println(describe(Point { .x = 1, .y = 2 }))
    return 0
}
```

```text
Point(x = 1, y = 2)
```

The plugin writes one `describe` for each struct, from its name and the names of its fields:

```vader
module "build"

import "std/string_builder"
import "toolchain/build"
AST :: import "toolchain/ast"

// A `describe` for each struct, which prints its fields.
Describe :: struct {}

Describe implements BuildPlugin {
    on_module :: fn(self, ctx: BuildContext, msg: TypecheckedMessage) -> void {
        for d in msg.declarations {
            if d is AST.StructDecl {
                ctx.emit_module(msg.module_name, described(d))
            }
        }
    }
}

described :: fn(s: AST.StructDecl) -> string {
    out :: StringBuilder {}
    out.append("describe :: fn(v: ${s.name}) -> string = \"${s.name}(")
    for i in 0..<s.fields.len() {
        if i > 0 {
            out.append(", ")
        }
        out.append("${s.fields[i].name} = \${v.${s.fields[i].name}}")
    }
    out.append(")\"\n")
    return out.to_string()
}

build :: fn(args: string[]) -> i32 {
    ctx :: new_build_context(args)
    ctx.add_entry("app", "src/main.vader")
    ctx.use(Describe {})
    return ctx.emit_native()
}
```

The generated code is written under `build/generated/`, where it can be read. A module of its own, a name no module of the project holds, is imported like any other. The rules: §11 *Generating code* and §11 *Generated modules*.

## Sharing a plugin

A plugin is a type: put it in a module of a library, and a driver plugs it in with an import. `json/derive` is one, giving each struct marked `@json` a `to_json`. The decorators come from `json`, the module the program imports: `@json_name("key")` renames a field, `@json_skip` leaves one out. Declaring your own and reading them: *Decorators*.

```vader
# module "app"
# import "std/console"
import "json"

@json
Point :: struct {
    x: i32
    y: i32
}

main :: fn() -> i32 {
    println(to_json(Point { .x = 1, .y = 2 }))
    return 0
}
```

```text
{"x":1,"y":2}
```

```vader
module "build"

import "json/derive"
import "toolchain/build"

build :: fn(args: string[]) -> i32 {
    ctx :: new_build_context(args)
    ctx.add_entry("app", "src/main.vader")
    ctx.use(JsonDerive {})
    return ctx.emit_native()
}
```

The rules: §11 *Plugins*.
