# Comptime

## tests/snippets/route_decorator_written

- `const VERSION = "1.0"`, folded
- `@Route = Route { .method = Method.Get, .path = "/users/{id}", .tags = [] }`, 18:1
- `@Route = Route { .method = Method.Get, .path = "/people/{id}", .tags = ["legacy"] }`, 19:1
- `@Route = Route { .method = Method.Post, .path = "/users", .tags = [] }`, 22:1
- `@Hidden = Hidden {  }`, 23:1
- `@Owner = Owner { .team = "accounts" }`, 29:1

## tests/snippets/route_decorator_written/http
