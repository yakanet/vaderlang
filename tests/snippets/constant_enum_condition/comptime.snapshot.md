# Comptime

## tests/snippets/constant_enum_condition

- `@comptime CHOSEN = Mode.Fast`, tree-walk
- `const MODE = Mode.Fast`, folded
- `const NAMED = Mode.Fast`, folded
- `const OFF_BROWSER = true`, folded
- `const ON_BROWSER = false`, folded
- `const OS = Os.Linux`, folded
- `const SEPARATOR = '\u002f'`, folded
