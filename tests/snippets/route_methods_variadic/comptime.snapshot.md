# Comptime

## tests/snippets/route_methods_variadic

- `@Route = Route { .methods = [Method.Get, Method.Post], .path = "/users" }`, 22:1
- `@Route = Route { .methods = [], .path = "/ping" }`, 25:1
- `@Route = Route { .methods = [Method.Put], .path = "/items" }`, 28:1
