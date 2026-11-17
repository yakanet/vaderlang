# Comptime

## tests/snippets/decorator_value_in_body

- `@comptime __decorator_argument__main_0 = "/v2/orders"`, vm
- `@Route = Route { .method = "GET", .path = "/users", .tags = [] }`, 22:1
- `@Route = Route { .method = "POST", .path = "/v2/orders", .tags = ["shop", "write"] }`, 25:1
