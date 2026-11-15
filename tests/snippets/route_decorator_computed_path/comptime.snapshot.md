# Comptime

## tests/snippets/route_decorator_computed_path

- `@comptime __decorator_argument__main_0 = "/api/users"`, tree-walk
- `@comptime __decorator_argument__main_1 = 14_i32`, vm
- `@comptime __decorator_argument__main_2 = "/a/b"`, vm
- `@Route = Route { .path = "/api/users", .weight = 14_i32 }`, 25:1
- `@Route = Route { .path = "/a/b", .weight = 1_i32 }`, 28:1
