# Comptime

## tests/snippets/ticket_relabel

# Diagnostics

- `[14:5] error[T3020] function body returns a value incompatible with its declared return type: expected i32, got i32 | string`
- ``[14:21] error[T3098] a member taking `Self`, or returning it inside another type, cannot be dispatched by its receiver's tag: `add` takes another `Self`, which may be another variant ; narrow `i32 | string` first``
- `[21:9] error[T3020] function body returns a value incompatible with its declared return type: expected i32, got i32 | string`
- ``[21:25] error[T3098] a member taking `Self`, or returning it inside another type, cannot be dispatched by its receiver's tag: `add` takes another `Self`, which may be another variant ; narrow `i32 | string` first``
- `[32:5] error[T3020] function body returns a value incompatible with its declared return type: expected i32, got i32 | string`
- ``[32:27] error[T3098] a member taking `Self`, or returning it inside another type, cannot be dispatched by its receiver's tag: `add` takes another `Self`, which may be another variant ; narrow `i32 | string` first``
