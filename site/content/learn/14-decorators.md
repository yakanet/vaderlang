# Decorators

A decorator is a mark written with `@` above a declaration. The compiler has its own, which act on the program as it compiles. A program declares others; they do nothing until a build plugin reads them.

## The compiler's decorators

`@test`, `@deprecated`, `@displayable` and the others are declared in `std/core`, with where each may be written and what it takes. Written anywhere else, one is an error.

```vader
# module "main"
# import "std/console"
@displayable
Color :: enum { Red, Green, Blue }

main :: fn() -> i32 {
    println("${Color.Green}")
    return 0
}
```

```text
Green
```

`@displayable` gives the enum a `Display` that prints each variant's name. `@deprecated(reason = "use paint")` has the compiler warn at each call of a function, and `@test` marks a test for `vader test`. The table and the rules: §12 *Decorators*.

## Declaring a decorator

`decorator` declares one like a struct: the places it may be written, then its fields, each holding a value known at compile time. Written above a declaration, it takes its fields as a call takes its parameters, a field with a default left out.

```vader
# module "main"
# import "std/console"
Method :: enum { Get, Post }

/// Where a handler answers.
Route :: decorator(.Function, repeatable = true) {
    path: string
    method: Method = .Get
}

@Route("/users")
@Route("/people", method = .Post)
list_users :: fn() -> string = "ada, grace"

main :: fn() -> i32 {
    println(list_users())
    return 0
}
```

```text
ada, grace
```

`repeatable = true` lets `@Route` be written twice. The compiler checks the place, the arguments and their types of each. The rules: §12 *Declaring a decorator*, §12 *Writing a declared decorator*.

## A plugin that reads them

A plugin, as in *Build plugins*, receives every declared decorator with its value: one argument per field, the defaults filled in. An argument written `@comptime` arrives computed. This one writes a `route` that calls the handler of a path, and logs the calls of the handlers marked `@Logged`. The decorated functions stay as written: the code the plugin writes calls them.

```vader
# module "app"
# import "std/console"
/// Where a handler answers.
Route :: decorator(.Function) {
    path: string
}

/// The calls of a handler the router logs.
Logged :: decorator(.Function) {}

versioned :: fn(path: string) -> string = "/v1${path}"

@Route(@comptime versioned("/users"))
@Logged
list_users :: fn() -> string = "ada, grace"

@Route("/health")
health :: fn() -> string = "ok"

main :: fn() -> i32 {
    println(route("/v1/users"))
    println(route("/health"))
    println(route("/nope"))
    return 0
}
```

```text
log: list_users
ada, grace
ok
404
```

The plugin finds a decorator by the module that declares it and its name, then reads a field by its name:

```vader
module "build"

import "std/string_builder"
import "toolchain/build"
AST :: import "toolchain/ast"

// A `route` that calls the handler of a path, logging those marked `@Logged`.
Router :: struct {}

Router implements BuildPlugin {
    on_module :: fn(self, ctx: BuildContext, msg: TypecheckedMessage) -> void {
        out :: StringBuilder {}
        for d in msg.declarations {
            if d is AST.FnDecl {
                write_route(out, d, msg.module_name)
            }
        }
        if out.byte_len() == 0 {
            return
        }
        ctx.emit_module(msg.module_name, """
            import "std/console"

            route :: fn(path: string) -> string {
            ${out.to_string()}    return "404"
            }
            """)
    }
}

// The branch of `route` that calls `f`, when it answers a path.
write_route :: fn(out: StringBuilder, f: AST.FnDecl, module: string) -> void {
    route :: AST.find_declared_decorator(f.decorators, module, "Route") else return
    out.append("    if path == \"${AST.string_field(route, "path", 0)}\" {\n")
    if AST.find_declared_decorator(f.decorators, module, "Logged") != null {
        out.append("        println(\"log: ${f.name}\")\n")
    }
    out.append("        return ${f.name}()\n    }\n")
}

build :: fn(args: string[]) -> i32 {
    ctx :: new_build_context(args)
    ctx.add_entry("app", "src/main.vader")
    ctx.use(Router {})
    return ctx.emit_native()
}
```

The compiler ran `versioned` before the plugin heard the module, so the path of `list_users` arrives as `"/v1/users"`. A plugin checks a value the way it reads one, and stops the build with `ctx.report` at the decorator's span, as in *Build plugins*: two routes on one path, say. The rules: §11 *Plugins*.
