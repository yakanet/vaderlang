# Programs for the Brainfuck example

Programs to run with `examples/brainfuck`, for instance
`vader run examples/brainfuck examples/brainfuck/programs/life.bf`. Those that
read input say what they expect in their comments. They all count on byte cells
and on 0 at end of input, which is what the example gives them.

## `hello.bf`: Wikipedia

From the [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) article of the
English Wikipedia, whose text is under **CC BY-SA 4.0**. It prints
`Hello World!`.

## brainfuck.org

By Daniel B. Cristofani (the quines modify Erik Bosman's 410-byte quine),
downloaded from [brainfuck.org](https://brainfuck.org/) on 2026-10-26. The `.b`
suffix of the originals became `.bf`, and line ends are normalised to LF. A quine
prints its own source, so each quine file holds only what it prints: the credit
the originals end with lives here instead.

### CC BY-SA 4.0

Each of these files states, in its own header, that it is licensed under
**CC BY-SA 4.0**.

| file | source | what it does |
|---|---|---|
| `bounce.bf` | https://brainfuck.org/bounce.b | a particle automaton |
| `chessboard.bf` | https://brainfuck.org/chessboard.b | prints an ASCII art chessboard from a FEN position |
| `ghost.bf` | https://brainfuck.org/ghost.b | a tiny game |
| `life.bf` | https://brainfuck.org/life.b | Conway's Game of Life, played at the keyboard |
| `tictactoe.bf` | https://brainfuck.org/tictactoe.b | plays tic-tac-toe |

### No licence stated

These files state no licence of their own: brainfuck.org publishes them for
anyone to read and run.

| file | source | what it does |
|---|---|---|
| `392quine.bf` | https://brainfuck.org/392quine.b | a quine |
| `400quine.bf` | https://brainfuck.org/400quine.b | a quine |
| `bsort.bf` | https://brainfuck.org/bsort.b | sorts its input's bytes, by bubble sort |
| `collatz.bf` | https://brainfuck.org/collatz.b | counts the Collatz steps of each number read |
| `dbf2c.bf` | https://brainfuck.org/dbf2c.b | translates Brainfuck to C |
| `dbfi.bf` | https://brainfuck.org/dbfi.b | a Brainfuck interpreter: a program, `!`, then its input |
| `dquine.bf` | https://brainfuck.org/dquine.b | a quine |
| `dvorak.bf` | https://brainfuck.org/dvorak.b | a Dvorak filter for QWERTY keyboards |
| `e.bf` | https://brainfuck.org/e.b | computes the digits of e, without end |
| `factorial2.bf` | https://brainfuck.org/factorial2.b | prints factorials, without end |
| `fib.bf` | https://brainfuck.org/fib.b | prints Fibonacci numbers, without end |
| `golden.bf` | https://brainfuck.org/golden.b | computes the digits of the golden ratio, without end |
| `head.bf` | https://brainfuck.org/head.b | prints the first ten lines of its input |
| `impeccable.bf` | https://brainfuck.org/impeccable.b | prints the impeccable numbers (OEIS A014221) |
| `isort.bf` | https://brainfuck.org/isort.b | sorts its input's bytes, by insertion sort |
| `jabh.bf` | https://brainfuck.org/jabh.b | prints "Just another brainfuck hacker," |
| `null.bf` | https://brainfuck.org/null.b | the empty quine |
| `numwarp.bf` | https://brainfuck.org/numwarp.b | a number obfuscator or prettifier |
| `qsort.bf` | https://brainfuck.org/qsort.b | sorts its input's bytes, by quicksort |
| `random.bf` | https://brainfuck.org/random.b | random bytes from the Rule 30 automaton, without end |
| `rot13.bf` | https://brainfuck.org/rot13.b | rot13 of its input |
| `sierpinski.bf` | https://brainfuck.org/sierpinski.b | prints a Sierpinski triangle |
| `squares.bf` | https://brainfuck.org/squares.b | prints the squares from 0 to 10000 |
| `squares2.bf` | https://brainfuck.org/squares2.b | prints squares, without end |
| `thuemorse.bf` | https://brainfuck.org/thuemorse.b | prints the Thue-Morse sequence, without end |
| `utm.bf` | https://brainfuck.org/utm.b | a universal Turing machine |
| `wc.bf` | https://brainfuck.org/wc.b | counts lines, words and bytes |
| `xmastree.bf` | https://brainfuck.org/xmastree.b | prints a Christmas tree of the height read |
