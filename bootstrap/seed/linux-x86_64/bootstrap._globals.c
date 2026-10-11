#include "bootstrap.split.h"

/* Compile-time atom table — see docs/ATOM_INTERNING.md. */
const char vader_atom_blob[] =
    "\n" "\0"
    "\n  sites:\n" "\0"
    "\n * " "\0"
    "\n# Diagnostics" "\0"
    "\n[VADER_OPT_REPORT] composites that could cross a call in registers\n" "\0"
    "\n[VADER_OPT_REPORT] optimisations that handed over to the general path\n" "\0"
    "\x1b[" "\0"
    " " "\0"
    "  " "\0"
    "    " "\0"
    "        ." "\0"
    "    (the gate a STRUCT return needs ; a tuple has no identity to break)\n\n  sites:\n" "\0"
    "    [" "\0"
    "    to_string :: fn(self) -> string = match self {\n" "\0"
    "    }\n}\n" "\0"
    "   of which `T | null`: " "\0"
    "   parameters: " "\0"
    "  (every leaf a non-reference primitive, payload at most " "\0"
    "  held back, a parameter the callee writes through: " "\0"
    "  returns whose every `return` builds its value on the spot: " "\0"
    "  returns: " "\0"
    " \"\\0\"" "\0"
    " (" "\0"
    " (*" "\0"
    " (+" "\0"
    " (got " "\0"
    " (incl. env)" "\0"
    " (jump_table=" "\0"
    " (std/core must be force-loaded)" "\0"
    " */\n" "\0"
    " +tag" "\0"
    " -> \"" "\0"
    " : " "\0"
    " : give it a marked type (`" "\0"
    " : hand out a fresh value from a fn instead" "\0"
    " : no inlinable Into<[...]> coercion" "\0"
    " : the level that differs is " "\0"
    " ; " "\0"
    " ; a `[...]` pattern requires a tuple or array" "\0"
    " ; compare the contents with `content_equals` or `is_permutation_of`, the references with `===`" "\0"
    " ; in `" "\0"
    " ; its impl requires `" "\0"
    " =" "\0"
    " = " "\0"
    " ? " "\0"
    " B" "\0"
    " __vret = " "\0"
    " `" "\0"
    " all offer it" "\0"
    " already used by `" "\0"
    " are returned" "\0"
    " argument(s), got " "\0"
    " as f64" "\0"
    " as numeric" "\0"
    " at " "\0"
    " at pc=" "\0"
    " break;" "\0"
    " but '" "\0"
    " bytes)\n" "\0"
    " bytes=" "\0"
    " cannot tell its impls apart" "\0"
    " does not fit in `" "\0"
    " element(s)), got " "\0"
    " elements" "\0"
    " elements into " "\0"
    " enters a loop past its header; the CFG is irreducible" "\0"
    " entry" "\0"
    " exceeds the buffer" "\0"
    " expects " "\0"
    " field " "\0"
    " fields) at pc=" "\0"
    " fills in " "\0"
    " fits the interpreter block" "\0"
    " for " "\0"
    " for `" "\0"
    " fresh" "\0"
    " function " "\0"
    " has no enclosing scope" "\0"
    " has no type id at pc=" "\0"
    " here" "\0"
    " implementor" "\0"
    " implements Display {\n" "\0"
    " implements Into<" "\0"
    " in '" "\0"
    " in `" "\0"
    " index " "\0"
    " is `" "\0"
    " is a callback, and the interpreter has no address for a Vader function" "\0"
    " is a struct the type table does not describe" "\0"
    " is ambiguous between traits: " "\0"
    " is an array whose element type the VM cannot lend (only integer elements are covered)" "\0"
    " is negative at pc=" "\0"
    " is not a struct" "\0"
    " is not a struct at pc=" "\0"
    " is not assignable to " "\0"
    " is not covered" "\0"
    " is not indexable" "\0"
    " is not valid in a character literal" "\0"
    " lacks a type" "\0"
    " levels deep" "\0"
    " may both cover an " "\0"
    " mirrors a C struct whose field `" "\0"
    " more diagnostic(s)" "\0"
    " nested levels)" "\0"
    " nested more than " "\0"
    " not in [" "\0"
    " not in the module type table" "\0"
    " of " "\0"
    " of `" "\0"
    " offset" "\0"
    " offset " "\0"
    " on " "\0"
    " out of bounds (len=" "\0"
    " out of range (struct has " "\0"
    " out of range at pc=" "\0"
    " param(s)" "\0"
    " param(s) but call site supplied " "\0"
    " parameter is not covered" "\0"
    " parameter(s) at " "\0"
    " parameter(s), got " "\0"
    " parameters; the host passes one" "\0"
    " prefix" "\0"
    " printed before `coalesce_temporaries` gave it a slot" "\0"
    " receiver" "\0"
    " receiver at pc=" "\0"
    " required methods" "\0"
    " requires a wildcard arm" "\0"
    " results \xe2\x80\x94 this consumer was not taught about arity" "\0"
    " signedness" "\0"
    " slots=" "\0"
    " slots[" "\0"
    " steps (non-terminating @comptime?)" "\0"
    " take " "\0"
    " take a key " "\0"
    " takes a key " "\0"
    " targets" "\0"
    " to " "\0"
    " to a slot of type " "\0"
    " type=" "\0"
    " unresolved" "\0"
    " value(s) but the stack holds " "\0"
    " value(s) where " "\0"
    " value(s) where another path brings " "\0"
    " value, which cannot yet be baked into a comptime constant" "\0"
    " variant ; narrow `" "\0"
    " variants do not fit `" "\0"
    " where it accepts " "\0"
    " with " "\0"
    " {\n" "\0"
    " { " "\0"
    " | " "\0"
    " | null`" "\0"
    " }" "\0"
    " }).__vb)" "\0"
    " }).__vu)" "\0"
    " \xe2\x80\x94 " "\0"
    " \xe2\x80\x94 `" "\0"
    " \xe2\x80\x94 `@target` groups are keyed by name alone, so a name cannot carry two overloads" "\0"
    " \xe2\x80\x94 a `" "\0"
    " \xe2\x80\x94 a variant is named on the enum type" "\0"
    " \xe2\x80\x94 annotate `" "\0"
    " \xe2\x80\x94 annotate the return in `" "\0"
    " \xe2\x80\x94 annotate the return of `" "\0"
    " \xe2\x80\x94 convert it explicitly, e.g. " "\0"
    " \xe2\x80\x94 its elements come from `" "\0"
    " \xe2\x80\x94 mark the bound of `" "\0"
    " \xe2\x80\x94 neither type nor trait is owned by this module" "\0"
    " \xe2\x80\x94 not provided in this impl block" "\0"
    " \xe2\x80\x94 qualify it with a namespace import (`Ns :: import \"\xe2\x80\xa6\"` then `Ns." "\0"
    " \xe2\x80\x94 source and target must differ" "\0"
    " \xe2\x80\x94 through a mutable array or struct, and in a trait's arguments, the `!` must match ; a fn cannot take a parameter with other rights than its slot hands it" "\0"
    " \xe2\x86\x92 " "\0"
    " \xe2\x86\x92 bb" "\0"
    "!" "\0"
    "!=" "\0"
    "!==" "\0"
    "!`" "\0"
    "!` at " "\0"
    "!in" "\0"
    "\"" "\0"
    "\"\n" "\0"
    "\"\"" "\0"
    "\"\"\"" "\0"
    "\"` (a module's folder must match its declared name)" "\0"
    "#" "\0"
    "#define " "\0"
    "#include " "\0"
    "#line " "\0"
    "$" "\0"
    "$Add$add" "\0"
    "$Async$" "\0"
    "$Cell<" "\0"
    "$Cell_" "\0"
    "$Display$to_string" "\0"
    "$Div$div" "\0"
    "$Equals$equals" "\0"
    "$Iterator$" "\0"
    "$Iterator$next" "\0"
    "$Mul$mul" "\0"
    "$Sub$sub" "\0"
    "$default$" "\0"
    "$exit" "\0"
    "$guard" "\0"
    "$i" "\0"
    "$leave" "\0"
    "$main" "\0"
    "$resume" "\0"
    "${" "\0"
    "%" "\0"
    "%=" "\0"
    "&" "\0"
    "&&" "\0"
    "'" "\0"
    "' (id=" "\0"
    "' : impl '" "\0"
    "' : no impl for type " "\0"
    "' : receiver tag " "\0"
    "' at pc=" "\0"
    "' declares " "\0"
    "' expects " "\0"
    "' must take exactly one env param at pc=" "\0"
    "' takes " "\0"
    "' takes a " "\0"
    "' \xe2\x80\x94 a `br` to bb" "\0"
    "' \xe2\x80\x94 a method reference on a primitive isn't a first-class value ; call it directly or wrap it in a lambda" "\0"
    "' \xe2\x80\x94 bb" "\0"
    "' \xe2\x80\x94 field-set target isn't a real struct member ; upstream lowering bug" "\0"
    "' \xe2\x80\x94 impl-member/for-in materialisation gap (GATE B1)" "\0"
    "' \xe2\x80\x94 no dedicated Op ; add a case to intrinsic_op_for_name" "\0"
    "'\\u" "\0"
    "(" "\0"
    "(((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(" "\0"
    "(((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(" "\0"
    "((vader_fn_erased_sig_" "\0"
    "((void) 0)" "\0"
    "()" "\0"
    "(-__builtin_inf())" "\0"
    "(...)`" "\0"
    "(__typeof__(" "\0"
    "(int32_t)(((union { float __vf; uint32_t __vb; }){ .__vf = " "\0"
    "(int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = " "\0"
    "(none)" "\0"
    "(size_t)vader_type_info_table[(int32_t)(uintptr_t)" "\0"
    "(\xe2\x80\xa6)`" "\0"
    ")" "\0"
    ") " "\0"
    ") -> " "\0"
    ") at function '" "\0"
    ") at pc=" "\0"
    ") does not fit in `" "\0"
    ") exceeds " "\0"
    ") exceeds object byte length " "\0"
    ") in '" "\0"
    ") {\n" "\0"
    ") }).__vd)" "\0"
    ") }).__vf)" "\0"
    ") \xe2\x80\x94 a value escaped a scope boundary ; coalesce.vader's live-range invariant is violated" "\0"
    ") \xe2\x80\x94 callback target was never materialised" "\0"
    ") \xe2\x80\x94 fn-as-value materialisation gap (GATE B1)" "\0"
    ") \xe2\x80\x94 make-closure materialisation gap (GATE B1)" "\0"
    ") \xe2\x80\x94 narrow with `if`/`match` first" "\0"
    ")(" "\0"
    ")) " "\0"
    ")->" "\0"
    ");\n" "\0"
    ")`" "\0"
    "){ " "\0"
    "*" "\0"
    "*%" "\0"
    "*%=" "\0"
    "*=" "\0"
    "+" "\0"
    "+%" "\0"
    "+%=" "\0"
    "+=" "\0"
    "+env>" "\0"
    "," "\0"
    ",\n" "\0"
    ", " "\0"
    ", ." "\0"
    ", ... " "\0"
    ", but the host passes a string[]" "\0"
    ", but the trait lends its receiver read-only" "\0"
    ", but this receiver is immutable" "\0"
    ", but this slot is declared `" "\0"
    ", f_" "\0"
    ", found " "\0"
    ", got " "\0"
    ", have=" "\0"
    ", not a function" "\0"
    ", which fills in " "\0"
    ", which the module table does not hold" "\0"
    "-" "\0"
    "-%" "\0"
    "-%=" "\0"
    "-0.0" "\0"
    "-=" "\0"
    "->" "\0"
    "->buf" "\0"
    "->buf->slots" "\0"
    "->code" "\0"
    "->code)" "\0"
    "->env" "\0"
    "->f_" "\0"
    "->offset" "\0"
    "-entry table" "\0"
    "-inf" "\0"
    "." "\0"
    ".." "\0"
    "..." "\0"
    "../" "\0"
    "..<" "\0"
    "..=" "\0"
    "./" "\0"
    ".0" "\0"
    ".b" "\0"
    ".c" "\0"
    ".f" "\0"
    ".i" "\0"
    ".imports.h" "\0"
    ".kind" "\0"
    ".obj" "\0"
    ".ptr_count" "\0"
    ".ptr_offsets" "\0"
    ".s" "\0"
    ".size" "\0"
    ".slot_size" "\0"
    ".split.g.c" "\0"
    ".split.h" "\0"
    ".to_" "\0"
    ".vader" "\0"
    "/" "\0"
    "/* " "\0"
    "// Generated per build by `vader/target/baked` \xe2\x80\x94 never on disk, never edited." "\0"
    "// The compilation target, baked. See `std/target::current_os` for the OTHER" "\0"
    "// question: the platform this program is RUNNING on." "\0"
    "/// The architecture this build is FOR. Parameterises values; selects nothing." "\0"
    "/// The operating system this build is FOR. Selects code through `@target`." "\0"
    "/=" "\0"
    "/e" "\0"
    "/proc/self/exe" "\0"
    "0" "\0"
    "0.0" "\0"
    "0123456789abcdef" "\0"
    "1" "\0"
    "1-tuple types are not allowed" "\0"
    "31" "\0"
    "33" "\0"
    ":" "\0"
    ": " "\0"
    ": ;" "\0"
    ": <type>!` instead" "\0"
    ": T[]!: \xe2\x80\xa6`)" "\0"
    ": `@c_pointer` on a " "\0"
    ": a `f32` result is not covered" "\0"
    ": argument " "\0"
    ": caller supplied " "\0"
    ": cannot open " "\0"
    ": cannot read " "\0"
    ": count " "\0"
    ": expected array, got " "\0"
    ": expected bool, got " "\0"
    ": expected f64, got " "\0"
    ": expected fn, got " "\0"
    ": expected i32, got " "\0"
    ": expected i64, got " "\0"
    ": expected integer Value, got " "\0"
    ": expected object, got " "\0"
    ": expected string, got " "\0"
    ": expected struct, got " "\0"
    ": field `" "\0"
    ": mirror nests deeper than " "\0"
    ": more than 8 arguments" "\0"
    ": symbol not found" "\0"
    ": the interpreter has no address for a Vader function" "\0"
    "::" "\0"
    "::into::" "\0"
    ":=" "\0"
    ";" "\0"
    ";\n" "\0"
    "; " "\0"
    "<" "\0"
    "<<" "\0"
    "<=" "\0"
    "<baked>/std/target/baked" "\0"
    "<baked>/std/target/baked/baked.vader" "\0"
    "<builtin>" "\0"
    "<callee>" "\0"
    "<clone>:" "\0"
    "<displayable>:" "\0"
    "<error: " "\0"
    "<fn " "\0"
    "<materialized>" "\0"
    "<obj#" "\0"
    "<synthetic>" "\0"
    "<type " "\0"
    "<unknown>" "\0"
    "<vader-vm>" "\0"
    "=" "\0"
    "= " "\0"
    "==" "\0"
    "===" "\0"
    "=>" "\0"
    ">" "\0"
    ">=" "\0"
    ">>" "\0"
    ">`" "\0"
    "?" "\0"
    "??" "\0"
    "?[]" "\0"
    "@" "\0"
    "@fields needs std/core::Field" "\0"
    "@fields owner module not loaded" "\0"
    "@fields owner module not typechecked" "\0"
    "@fields target is not a struct" "\0"
    "@fields target struct decl not found" "\0"
    "@file expects a single string-literal argument" "\0"
    "@file path could not be read" "\0"
    "@unreachable match \xe2\x80\x94 a variant the arms assert cannot occur was reached" "\0"
    "A" "\0"
    "A:" "\0"
    "ARRAY" "\0"
    "Add" "\0"
    "Any" "\0"
    "Arm64" "\0"
    "Array<" "\0"
    "ArrayTypeExpr" "\0"
    "Async" "\0"
    "AwaitExpr" "\0"
    "BinaryExpr" "\0"
    "BinaryOp.In" "\0"
    "BinaryOp.Is" "\0"
    "BinaryOp.NotIn" "\0"
    "BinaryOp.NotSame" "\0"
    "BinaryOp.Same" "\0"
    "BlockExpr" "\0"
    "BoolLitExpr" "\0"
    "Browser" "\0"
    "C4001" "\0"
    "C4002" "\0"
    "C4003" "\0"
    "C4004" "\0"
    "C4005" "\0"
    "C4006" "\0"
    "C4007" "\0"
    "C4008" "\0"
    "C4009" "\0"
    "C4010" "\0"
    "C4011" "\0"
    "C4012" "\0"
    "C4013" "\0"
    "C4014" "\0"
    "C4015" "\0"
    "C4016" "\0"
    "CPointer" "\0"
    "CallExpr" "\0"
    "CallExpr (arity mismatch)" "\0"
    "CallExpr (block has statements before trailing)" "\0"
    "CallExpr (body too complex)" "\0"
    "CallExpr (callee has no body)" "\0"
    "CallExpr (callee unresolved)" "\0"
    "CallExpr (no FnDecl for callee)" "\0"
    "CallExpr (non-ident callee)" "\0"
    "CallExpr (param sym unresolved)" "\0"
    "CastExpr" "\0"
    "CharLitExpr" "\0"
    "Comparable" "\0"
    "Compile-time atom table \xe2\x80\x94 see docs/ATOM_INTERNING.md." "\0"
    "Comptime data pool \xe2\x80\x94 read-only arrays in `.rodata`." "\0"
    "Contains" "\0"
    "Continuation" "\0"
    "Continue" "\0"
    "Darwin" "\0"
    "Display" "\0"
    "Div" "\0"
    "DotVariantExpr" "\0"
    "E:" "\0"
    "ENV access requires `--allow-env`" "\0"
    "Equals" "\0"
    "Error" "\0"
    "F:(" "\0"
    "F<" "\0"
    "FC" "\0"
    "FF" "\0"
    "FI" "\0"
    "FN" "\0"
    "Fc:" "\0"
    "Ff:" "\0"
    "Fi:" "\0"
    "Field" "\0"
    "FieldExpr" "\0"
    "FloatLitExpr" "\0"
    "Fn(" "\0"
    "FnTypeExpr" "\0"
    "Generated by vader \xe2\x80\x94 do not edit. Foreign imports." "\0"
    "Generated by vader \xe2\x80\x94 do not edit. Shared declarations." "\0"
    "GenericInstExpr" "\0"
    "GetStdHandle" "\0"
    "GetStdHandle which" "\0"
    "Hash" "\0"
    "Headers named by `@c_header` \xe2\x80\x94 they own the prototypes below." "\0"
    "I7001" "\0"
    "I7002" "\0"
    "I7003" "\0"
    "I7004" "\0"
    "I7005" "\0"
    "I7006" "\0"
    "I7008" "\0"
    "I7009" "\0"
    "I7010" "\0"
    "I7011" "\0"
    "I7012" "\0"
    "INT32_C(" "\0"
    "INT32_MIN" "\0"
    "INT64_C(" "\0"
    "INT64_MIN" "\0"
    "IdentExpr" "\0"
    "IdentExpr (" "\0"
    "IdentExpr (unresolved)" "\0"
    "IfExpr" "\0"
    "Index" "\0"
    "IndexExpr" "\0"
    "IndexSet" "\0"
    "IntLitExpr" "\0"
    "Into" "\0"
    "IntrinsicCallExpr" "\0"
    "Iterator" "\0"
    "Iterator<" "\0"
    "L0001" "\0"
    "L0002" "\0"
    "L0003" "\0"
    "L0004" "\0"
    "L0005" "\0"
    "L0006" "\0"
    "L0007" "\0"
    "L0008" "\0"
    "L0009" "\0"
    "L0010" "\0"
    "L0011" "\0"
    "LambdaExpr" "\0"
    "Linux" "\0"
    "M" "\0"
    "M5001" "\0"
    "M5002" "\0"
    "M5003" "\0"
    "M5004" "\0"
    "M5005" "\0"
    "M5006" "\0"
    "M5007" "\0"
    "M5009" "\0"
    "M5010" "\0"
    "M:" "\0"
    "MatchExpr" "\0"
    "Mul" "\0"
    "MutableMap" "\0"
    "MutableSet" "\0"
    "MutableTypeExpr" "\0"
    "N:(" "\0"
    "NO_COLOR" "\0"
    "NULL" "\0"
    "NullCoalesceExpr" "\0"
    "NullLitExpr" "\0"
    "Nv:" "\0"
    "Out-of-arena pointers are immortal to the GC (it never copies /" "\0"
    "P" "\0"
    "P1001" "\0"
    "P1002" "\0"
    "P1003" "\0"
    "P1004" "\0"
    "P1005" "\0"
    "P1006" "\0"
    "P1007" "\0"
    "P1008" "\0"
    "P1009" "\0"
    "P1010" "\0"
    "P1011" "\0"
    "P1012" "\0"
    "P1013" "\0"
    "P1014" "\0"
    "P1015" "\0"
    "P1016" "\0"
    "P1017" "\0"
    "P1018" "\0"
    "P1019" "\0"
    "P1020" "\0"
    "P1021" "\0"
    "P1022" "\0"
    "P1023" "\0"
    "P1027" "\0"
    "P1028" "\0"
    "P1029" "\0"
    "P1030" "\0"
    "P1031" "\0"
    "P1032" "\0"
    "P1033" "\0"
    "P1035" "\0"
    "P1037" "\0"
    "P1038" "\0"
    "P:" "\0"
    "R2001" "\0"
    "R2002" "\0"
    "R2003" "\0"
    "R2004" "\0"
    "R2005" "\0"
    "R2006" "\0"
    "R2007" "\0"
    "R2008" "\0"
    "R2009" "\0"
    "R2010" "\0"
    "R2011" "\0"
    "R2012" "\0"
    "R2013" "\0"
    "R2014" "\0"
    "R2015" "\0"
    "R2016" "\0"
    "R2017" "\0"
    "R2018" "\0"
    "R2019" "\0"
    "R2020" "\0"
    "R2021" "\0"
    "R2022" "\0"
    "R2023" "\0"
    "R2024" "\0"
    "R2025" "\0"
    "R2026" "\0"
    "R2027" "\0"
    "R2028" "\0"
    "R2029" "\0"
    "R2030" "\0"
    "R2031" "\0"
    "R2032" "\0"
    "R2033" "\0"
    "R2034" "\0"
    "R2035" "\0"
    "R2036" "\0"
    "R2037" "\0"
    "R2038" "\0"
    "R2039" "\0"
    "R2040" "\0"
    "R2041" "\0"
    "R2042" "\0"
    "Range" "\0"
    "RangeExpr" "\0"
    "Rem" "\0"
    "S" "\0"
    "S:" "\0"
    "Self" "\0"
    "SeqLitExpr" "\0"
    "Sf:" "\0"
    "Stop" "\0"
    "StringLitExpr" "\0"
    "Struct#" "\0"
    "StructLitExpr" "\0"
    "Sub" "\0"
    "Suspended" "\0"
    "T3001" "\0"
    "T3002" "\0"
    "T3003" "\0"
    "T3004" "\0"
    "T3005" "\0"
    "T3006" "\0"
    "T3007" "\0"
    "T3008" "\0"
    "T3009" "\0"
    "T3010" "\0"
    "T3013" "\0"
    "T3014" "\0"
    "T3015" "\0"
    "T3016" "\0"
    "T3017" "\0"
    "T3018" "\0"
    "T3019" "\0"
    "T3020" "\0"
    "T3021" "\0"
    "T3022" "\0"
    "T3023" "\0"
    "T3024" "\0"
    "T3025" "\0"
    "T3026" "\0"
    "T3027" "\0"
    "T3028" "\0"
    "T3029" "\0"
    "T3030" "\0"
    "T3031" "\0"
    "T3032" "\0"
    "T3033" "\0"
    "T3034" "\0"
    "T3035" "\0"
    "T3036" "\0"
    "T3037" "\0"
    "T3038" "\0"
    "T3039" "\0"
    "T3040" "\0"
    "T3041" "\0"
    "T3042" "\0"
    "T3043" "\0"
    "T3050" "\0"
    "T3051" "\0"
    "T3052" "\0"
    "T3053" "\0"
    "T3054" "\0"
    "T3055" "\0"
    "T3056" "\0"
    "T3058" "\0"
    "T3059" "\0"
    "T3060" "\0"
    "T3061" "\0"
    "T3062" "\0"
    "T3063" "\0"
    "T3064" "\0"
    "T3066" "\0"
    "T3067" "\0"
    "T3068" "\0"
    "T3069" "\0"
    "T3070" "\0"
    "T3071" "\0"
    "T3072" "\0"
    "T3073" "\0"
    "T3074" "\0"
    "T3075" "\0"
    "T3076" "\0"
    "T3077" "\0"
    "T3078" "\0"
    "T3079" "\0"
    "T3080" "\0"
    "T3081" "\0"
    "T3082" "\0"
    "T3083" "\0"
    "T3084" "\0"
    "T3085" "\0"
    "T3086" "\0"
    "T3087" "\0"
    "T3088" "\0"
    "T3089" "\0"
    "T3090" "\0"
    "T3091" "\0"
    "T3092" "\0"
    "T3093" "\0"
    "T3094" "\0"
    "T3095" "\0"
    "T3096" "\0"
    "T3097" "\0"
    "T3098" "\0"
    "T3099" "\0"
    "T3100" "\0"
    "T:" "\0"
    "T<" "\0"
    "Trait#" "\0"
    "Tup" "\0"
    "Tuple<" "\0"
    "U:(" "\0"
    "U<" "\0"
    "UINT64_C" "\0"
    "UnaryExpr" "\0"
    "Union<" "\0"
    "Ur:" "\0"
    "User @extern foreign symbols \xe2\x80\x94 resolved by the linker." "\0"
    "VADER_ARRAY_CHECK_INDEX" "\0"
    "VADER_ARRAY_RESOLVE_BUF" "\0"
    "VADER_ATOM_FLAG_PERM" "\0"
    "VADER_BOX_TAG_NULL" "\0"
    "VADER_COMPTIME_ATOM_COUNT" "\0"
    "VADER_GC_POP_FRAME" "\0"
    "VADER_GC_PUSH_RAW" "\0"
    "VADER_HOME" "\0"
    "VADER_LIKELY" "\0"
    "VADER_OPT_REPORT" "\0"
    "VADER_TYPE_INDEX_ARRAY_BUF" "\0"
    "VADER_TYPE_KIND_" "\0"
    "VADER_TYPE_KIND_STRUCT" "\0"
    "VADER_WRITE_BARRIER" "\0"
    "W0001" "\0"
    "W0002" "\0"
    "W0005" "\0"
    "W0007" "\0"
    "W0008" "\0"
    "W0009" "\0"
    "W0010" "\0"
    "W0011" "\0"
    "W0012" "\0"
    "W0013" "\0"
    "W0014" "\0"
    "W0015" "\0"
    "W0016" "\0"
    "W0017" "\0"
    "W0018" "\0"
    "Wasi" "\0"
    "Wasm32" "\0"
    "Windows" "\0"
    "WriteFile" "\0"
    "X86_64" "\0"
    "X:" "\0"
    "Y:" "\0"
    "[" "\0"
    "[]" "\0"
    "\\" "\0"
    "]" "\0"
    "] " "\0"
    "] for `" "\0"
    "].slot_size" "\0"
    "]; }" "\0"
    "^" "\0"
    "_" "\0"
    "_0" "\0"
    "_1" "\0"
    "_Alignas" "\0"
    "_Alignof" "\0"
    "_Atomic" "\0"
    "_Bool" "\0"
    "_Complex" "\0"
    "_Generic" "\0"
    "_Imaginary" "\0"
    "_Noreturn" "\0"
    "_Static_assert" "\0"
    "_Static_assert(" "\0"
    "_Thread_local" "\0"
    "__" "\0"
    "__Tuple" "\0"
    "__Tuple_" "\0"
    "__args" "\0"
    "__async_" "\0"
    "__asyncstate_" "\0"
    "__builtin_inf()" "\0"
    "__builtin_nan(\"\")" "\0"
    "__builtin_offsetof" "\0"
    "__comptime_" "\0"
    "__const_" "\0"
    "__defer_" "\0"
    "__defer_env_" "\0"
    "__defers" "\0"
    "__gen_" "\0"
    "__gen_state_" "\0"
    "__genstate_" "\0"
    "__lambda_" "\0"
    "__lambda_env_" "\0"
    "__o" "\0"
    "__vret" "\0"
    "__wb_frame" "\0"
    "__wb_roots" "\0"
    "_a" "\0"
    "_arr" "\0"
    "_buf" "\0"
    "_cap" "\0"
    "_count" "\0"
    "_e" "\0"
    "_f" "\0"
    "_glue" "\0"
    "_hdr" "\0"
    "_len" "\0"
    "_offsets" "\0"
    "_pc" "\0"
    "_root" "\0"
    "_slots" "\0"
    "_t" "\0"
    "_t) " "\0"
    "_v" "\0"
    "_vt" "\0"
    "_write" "\0"
    "_x" "\0"
    "`" "\0"
    "` " "\0"
    "` (" "\0"
    "` (depth " "\0"
    "` (local " "\0"
    "` : " "\0"
    "` : annotate that element type at " "\0"
    "` : this call " "\0"
    "` `!` at " "\0"
    "` after prune_unused_types \xe2\x80\x94 the table is final by then, so the slot would survive as an orphan `ref` and panic at the first field access. Look the type up and skip the entry instead, as `build_impl_table_from_vtable` does." "\0"
    "` against non-enum context type" "\0"
    "` against unresolved type" "\0"
    "` already declared in a sibling file of this module" "\0"
    "` already declared in this module" "\0"
    "` already has a body for `." "\0"
    "` already implements `" "\0"
    "` already provided in this struct literal" "\0"
    "` and `" "\0"
    "` and no general body ; " "\0"
    "` are never the same object" "\0"
    "` are unrelated distinct types" "\0"
    "` arg " "\0"
    "` at " "\0"
    "` at pc=" "\0"
    "` both accept " "\0"
    "` cannot be inferred" "\0"
    "` cannot decorate a parameter \xe2\x80\x94 only `@c_pointer` and `@c_out` can" "\0"
    "` cannot have a body \xe2\x80\x94 drop the `= ...` / `{ ... }`" "\0"
    "` crosses as an address \xe2\x80\x94 mark the parameter `@c_pointer`" "\0"
    "` declared here, but `" "\0"
    "` declares `self!`" "\0"
    "` decorates a PARAMETER of an `@extern` ; it does not apply to " "\0"
    "` does not apply to a struct field ; only `@internal` does" "\0"
    "` does not fit in u64" "\0"
    "` does not implement `" "\0"
    "` does not implement it" "\0"
    "` does not implement it ; add `@displayable` to " "\0"
    "` element" "\0"
    "` expects an enum-typed slot, got " "\0"
    "` field `" "\0"
    "` first" "\0"
    "` for " "\0"
    "` for `" "\0"
    "` from `" "\0"
    "` grants no mutation" "\0"
    "` has " "\0"
    "` has a `break` / `continue` outside any loop" "\0"
    "` has a `module` declaration ; " "\0"
    "` has no C representation: `" "\0"
    "` has no `Display` bound" "\0"
    "` has no `IndexSet` to write through" "\0"
    "` has no bare `@target` declaration in this module" "\0"
    "` has no body for `" "\0"
    "` has no field named `" "\0"
    "` has no identity ; compare with `" "\0"
    "` has no interior to mutate \xe2\x80\x94 drop the `!`" "\0"
    "` has no jump target inside the body" "\0"
    "` has no symbol" "\0"
    "` has the same signature as a function of this module" "\0"
    "` has the type argument `" "\0"
    "` here \xe2\x80\x94 the body binds by POSITION, so a reordered name silently " "\0"
    "` holds its bare value, but a closure reads it through a cell" "\0"
    "` implements `" "\0"
    "` imports `" "\0"
    "` in '" "\0"
    "` in `" "\0"
    "` in a " "\0"
    "` instead of a label" "\0"
    "` into " "\0"
    "` is" "\0"
    "` is `" "\0"
    "` is `@internal` to module `" "\0"
    "` is a " "\0"
    "` is a body ; the bare `@target` declaration carries `export`" "\0"
    "` is a callback that names no function \xe2\x80\x94 typecheck should have refused it (T3080)" "\0"
    "` is a module const at " "\0"
    "` is a plain struct \xe2\x80\x94 a struct member needs its own `@c_struct` naming the C type it mirrors" "\0"
    "` is a trait ; call `" "\0"
    "` is already a type parameter" "\0"
    "` is already declared at " "\0"
    "` is already defined with the same signature in this module" "\0"
    "` is already matched above" "\0"
    "` is an enum with variant data \xe2\x80\x94 it stores a rank, not the value C expects" "\0"
    "` is bodyless and otherwise unbound at runtime ; for a function-*type*, spell the `fn(...)` type inline at its use sites rather than as a named bodyless declaration" "\0"
    "` is boxed as its representation ; narrow `" "\0"
    "` is declared `" "\0"
    "` is declared with `::` \xe2\x80\x94 use `:=` to allow mutation" "\0"
    "` is exported by " "\0"
    "` is frozen by the module-const default at " "\0"
    "` is handed mutable elements here" "\0"
    "` is impure and cannot run at comptime \xe2\x80\x94 it answers for the machine the compiler runs on, so baking it would make the same source emit differently per builder" "\0"
    "` is matched by an earlier arm" "\0"
    "` is mutable only through a bound marked `!`" "\0"
    "` is never a value of `" "\0"
    "` is never used" "\0"
    "` is no longer supported \xe2\x80\x94 the literal coerces from context" "\0"
    "` is not a C scalar and cannot be laid out" "\0"
    "` is not a member of `" "\0"
    "` is not a struct" "\0"
    "` is not a type" "\0"
    "` is not a variant of " "\0"
    "` is not allowed in expression position" "\0"
    "` is not an enclosing loop's iteration variable or label" "\0"
    "` is not an identifier \xe2\x80\x94 the mangled name is corrupt" "\0"
    "` is not defined for `" "\0"
    "` is not wired into intrinsic_manifest \xe2\x80\x94 add it to `intrinsic_id_for` (+ its `vm/host.vader::dispatch_import` and `c_emit/host.vader::import_shim` arms), or give it a dedicated op in `intrinsic_op_for_mangled`" "\0"
    "` is reached through an immutable path" "\0"
    "` is read while its own value is typed" "\0"
    "` is shipped under the library root, so it cannot import `" "\0"
    "` is used instead: `x: " "\0"
    "` jumps to a loop labelled `" "\0"
    "` lends out read-only \xe2\x80\x94 drop the `!`, or mark the slot's parameter `!` to allow it" "\0"
    "` lists `." "\0"
    "` may meet " "\0"
    "` mirrors a nested C struct but holds no value" "\0"
    "` more than once" "\0"
    "` must be a constant" "\0"
    "` must be prefixed with `$`" "\0"
    "` must be written `$" "\0"
    "` must precede a `match` expression" "\0"
    "` mutates `" "\0"
    "` mutates a parameter that `" "\0"
    "` mutates its receiver (declared `self!`), " "\0"
    "` names `" "\0"
    "` names a type parameter, and an impl member keeps " "\0"
    "` names no operating system" "\0"
    "` names nothing" "\0"
    "` needs " "\0"
    "` not defined for " "\0"
    "` not found" "\0"
    "` of `" "\0"
    "` of `@c_struct` `" "\0"
    "` on " "\0"
    "` on `" "\0"
    "` on a type that implements it" "\0"
    "` on non-struct type " "\0"
    "` only means something on an `@extern` declaration" "\0"
    "` or make `" "\0"
    "` overload accepts a receiver of type `" "\0"
    "` parameter `" "\0"
    "` private" "\0"
    "` promises " "\0"
    "` requires `" "\0"
    "` requires method `" "\0"
    "` resolved elsewhere but not in this module's table" "\0"
    "` resolved to a symbol with no local in this function \xe2\x80\x94 a binding was lost between the resolver and here" "\0"
    "` return: " "\0"
    "` returns `" "\0"
    "` returns `Self` inside another type, built for one" "\0"
    "` share no variant" "\0"
    "` sits at a different position in each variant of " "\0"
    "` takes " "\0"
    "` takes `" "\0"
    "` takes `self` ; call it on a value of " "\0"
    "` takes another `Self`, which may be another" "\0"
    "` takes no `self` ; call it on the type" "\0"
    "` takes no argument" "\0"
    "` takes no impl of its own" "\0"
    "` takes one value, got " "\0"
    "` tests `is " "\0"
    "` through its `Iterator` impl \xe2\x80\x94 " "\0"
    "` twice in the same `@target`" "\0"
    "` value, which dispatches by the trait alone," "\0"
    "` was already supplied" "\0"
    "` was declared earlier in this folder" "\0"
    "` without context" "\0"
    "` would test for `" "\0"
    "` would write the same file" "\0"
    "` yields but returns " "\0"
    "` \xe2\x80\x94 " "\0"
    "` \xe2\x80\x94 a `string` and an array already cross as pointers, so drop the decorator" "\0"
    "` \xe2\x80\x94 a mirrored field must be a numeric scalar, `bool`, `char`, `CPointer`, an enum, or another `@c_struct`" "\0"
    "` \xe2\x80\x94 a trait requires traits, joined by `&`" "\0"
    "` \xe2\x80\x94 already declared on `" "\0"
    "` \xe2\x80\x94 annotate the result slot, or pass the type argument explicitly" "\0"
    "` \xe2\x80\x94 enumerate its variants or mark the match `@partial`" "\0"
    "` \xe2\x80\x94 its folder declares `module \"" "\0"
    "` \xe2\x80\x94 narrow it with `if`/`match` first" "\0"
    "` \xe2\x80\x94 narrow the union with `if`/`match` first (a value combinator handles a single unhappy variant, `T | null` or `T | Error`, not both)" "\0"
    "` \xe2\x80\x94 only `toolchain/build` may" "\0"
    "` \xe2\x80\x94 only an ARRAY of value elements can be a mutable " "\0"
    "` \xe2\x80\x94 the marker belongs on the ARRAY level only : its " "\0"
    "` \xe2\x80\x94 the marker belongs on the ARRAY level, which is the " "\0"
    "` \xe2\x80\x94 to read a scalar back, lend a one-element array" "\0"
    "` \xe2\x80\x94 two generic " "\0"
    "` \xe2\x80\x94 write `" "\0"
    "` \xe2\x80\x94 write the impl on `T[]` or on a concrete array" "\0"
    "`!` already applies to this type level" "\0"
    "`!` belongs on the type, not the parameter name" "\0"
    "`!` requires bool" "\0"
    "`&&` / `||` require `bool` operands, got " "\0"
    "`'s type at " "\0"
    "`(` after `@" "\0"
    "`(` after `fn` in function type" "\0"
    "`(` after function name" "\0"
    "`(` after generic argument list" "\0"
    "`)" "\0"
    "`) in '" "\0"
    "`) or destructure the one you mean" "\0"
    "`)` after decorator arguments" "\0"
    "`)` after enum header" "\0"
    "`)` after function parameter types" "\0"
    "`)` to close `@" "\0"
    "`)` to close argument list" "\0"
    "`)` to close parameter list" "\0"
    "`)` to close parenthesised expression" "\0"
    "`)` to close parenthesised type" "\0"
    "`)` to close type parameter list" "\0"
    "`, " "\0"
    "`, `" "\0"
    "`, and " "\0"
    "`, but the trait lends `" "\0"
    "`, but the trait promises `" "\0"
    "`, closing an import cycle" "\0"
    "`, got `" "\0"
    "`, which erases ; " "\0"
    "`, which has no `Equals`" "\0"
    "`, which is mutated" "\0"
    "`, which is not a function \xe2\x80\x94 typecheck should have refused it (T3080)" "\0"
    "`, which is not exported from its module ; export `" "\0"
    "`, which mutates it" "\0"
    "`->` between lambda params and body" "\0"
    "`->` between pattern and arm body" "\0"
    "`->` to introduce a SAM impl body" "\0"
    "`-` requires numeric" "\0"
    "`." "\0"
    "`...rest` must be the last element" "\0"
    "`.` before struct literal field name" "\0"
    "`: " "\0"
    "`: expected " "\0"
    "`: type` bound is redundant; write `$T` instead" "\0"
    "`:=`, `::`, or `:` after destructure pattern" "\0"
    "`:` after field name" "\0"
    "`:` between type annotation and value" "\0"
    "`==` on `" "\0"
    "`=` after destructuring assignment target" "\0"
    "`=` after struct literal field name" "\0"
    "`=` or `:` after type annotation" "\0"
    "`>` to close generic argument list" "\0"
    "`>` to close type-param list" "\0"
    "`??` fallback diverges" "\0"
    "`??` fallback type " "\0"
    "`??` left operand is never null \xe2\x80\x94 the fallback is unreachable" "\0"
    "`@" "\0"
    "`@assert` expects 1 or 2 arguments : `@assert(cond)` or `@assert(cond, \"message\")`" "\0"
    "`@assert` message must be a static string literal (no interpolation)" "\0"
    "`@c_out` needs an array or a `@c_struct` for C to write into, got `" "\0"
    "`@c_pointer` needs a scalar or a `@c_struct` to take the address of, got `" "\0"
    "`@c_struct` layout \xe2\x80\x94 checked against the real headers." "\0"
    "`@c_struct` names the C type a STRUCT mirrors ; it does not apply to " "\0"
    "`@c_struct` type `" "\0"
    "`@comptime for` binding not resolved" "\0"
    "`@comptime for` cannot be unrolled" "\0"
    "`@comptime for` does not support `[k, v]` destructure" "\0"
    "`@comptime for` exceeds the unroll cap (256)" "\0"
    "`@comptime for` requires a compile-time-known array literal" "\0"
    "`@displayable` applies to an enum only" "\0"
    "`@displayable` generates the `Display` of `" "\0"
    "`@extern` accepts 0, 1, or 2 string arguments \xe2\x80\x94 got " "\0"
    "`@extern` arguments must be plain string literals (no interpolation)" "\0"
    "`@extern` declaration must not have a body" "\0"
    "`@extern` fn `" "\0"
    "`@extern` parameter type must be a primitive, `string`, or a primitive-element array, got `" "\0"
    "`@extern` return type must be a primitive, `string`, `CPointer | null`, or `void`, got `" "\0"
    "`@target` body carries `export`" "\0"
    "`@target` body does not have the declaration's signature" "\0"
    "`@target` body matches no declaration" "\0"
    "`@target` selects a function body ; it does not apply to " "\0"
    "`Into<T>` cannot use `T` as its target (identity coercion is forbidden)" "\0"
    "`Into` coercion cannot be lowered" "\0"
    "`[v] * n` repeats one reference \xe2\x80\x94 every slot shares this freshly allocated element" "\0"
    "`]` to close bracketed type" "\0"
    "`]` to close destructure pattern" "\0"
    "`]` to close destructuring assignment" "\0"
    "`]` to close index" "\0"
    "`]` to close seq literal" "\0"
    "`as` binding not allowed after `!is`: the binding would have no live then-branch since the type-check is negated" "\0"
    "`as` binding not allowed in a `&&` condition" "\0"
    "`await` drives this value through `resume`" "\0"
    "`await` in a short-circuit operand or loop condition is not yet supported" "\0"
    "`await` is not allowed inside a nested lambda (a lambda cannot be an async coroutine)" "\0"
    "`bool` values are not ordered (no Comparable impl); only == and != are valid at comptime" "\0"
    "`break` / `continue` only allowed inside a loop" "\0"
    "`break` / `continue` target must be an enclosing loop's iteration variable or label" "\0"
    "`const` was removed from the language" "\0"
    "`defer` is not yet supported inside a generator" "\0"
    "`for x in iter` requires an Iterator impl on " "\0"
    "`for`" "\0"
    "`for` advances this iterator through `next`" "\0"
    "`implements` keyword" "\0"
    "`in` / `not in` lowering deferred" "\0"
    "`in` after for-loop binding" "\0"
    "`return` returns " "\0"
    "`self` only valid inside a method body" "\0"
    "`std/core::Range` not reachable \xe2\x80\x94 cannot lower range expression" "\0"
    "`std/core::Range` resolved to a non-struct symbol" "\0"
    "`type`-valued locals are not yet supported (Layer 4 milestone B.1) ; use the immutable form `name :: <type-expr>` for an in-fn type alias, or a top-level alias `Name :: type[T] ...`" "\0"
    "`void` is reserved and cannot be used as an identifier" "\0"
    "`yield` is only allowed directly inside a generator's own body, not in a nested lambda" "\0"
    "`{` to open block" "\0"
    "`{` to open enum body" "\0"
    "`{` to open match arms" "\0"
    "`{` to open struct body" "\0"
    "`{` to open struct pattern" "\0"
    "`{` to open trait body" "\0"
    "`}` to close block" "\0"
    "`}` to close enum body" "\0"
    "`}` to close impl body" "\0"
    "`}` to close import list" "\0"
    "`}` to close match" "\0"
    "`}` to close struct body" "\0"
    "`}` to close struct literal" "\0"
    "`}` to close struct pattern" "\0"
    "`}` to close trait body" "\0"
    "`}` to close variant data" "\0"
    "`~` requires int" "\0"
    "a" "\0"
    "a `" "\0"
    "a `!` that grants nothing" "\0"
    "a `...rest` binding collects from an array, got `" "\0"
    "a `...rest` target collects from an array, got `" "\0"
    "a `@target` selector must be an operating-system variant, written `.Linux`, `.Darwin`, `.Windows`, `.Wasi` or `.Browser`" "\0"
    "a `for` walks an array, a string or an `Iterator`, got `" "\0"
    "a `{ \xe2\x80\xa6 }` pattern reads the fields of a struct, got `" "\0"
    "a bodyless function must be `@intrinsic` (host-provided) or `@extern` (foreign symbol)" "\0"
    "a bound cannot be a union" "\0"
    "a bound names traits, joined by `&`" "\0"
    "a call on a union" "\0"
    "a cast to `" "\0"
    "a constant cannot depend on its own value" "\0"
    "a constant value cannot hold a mutable level" "\0"
    "a constant \xe2\x80\x94 use `VADER_OS`, which is a value" "\0"
    "a cyclic or non-terminating comptime expression (exceeded " "\0"
    "a debugged run needs a state from `prepare_debug`" "\0"
    "a declaration takes at least two" "\0"
    "a destructuring assignment writes to names, fields and indices \xe2\x80\x94 not to this" "\0"
    "a destructuring target takes a plain `=` \xe2\x80\x94 write out the element the compound applies to" "\0"
    "a function" "\0"
    "a function is defined more than once" "\0"
    "a function that `yield`s must return `Iterator<T>`" "\0"
    "a generator produces values via `yield`; `return` with a value is not allowed (use a bare `return` to stop)" "\0"
    "a jump frame popped where none was pushed" "\0"
    "a literal of " "\0"
    "a match arm cannot destructure a tuple" "\0"
    "a match pattern cannot bind a name" "\0"
    "a member taking `Self`, or returning it inside another type, cannot be dispatched by its receiver's tag" "\0"
    "a member that mutates its receiver is called on it" "\0"
    "a mutable module const needs a flat element type" "\0"
    "a no-return call returned" "\0"
    "a plain name in an `import \"p\" { \xe2\x80\xa6 }` modifier list \xe2\x80\x94 use `x as _` (exclude) or `x as y` (rename)" "\0"
    "a read-only value cannot fill a slot that promises mutation" "\0"
    "a rebound binding a closure captures is not held in a cell" "\0"
    "a return hands back a different number of values than the function declares" "\0"
    "a shipped library must not import the compiler" "\0"
    "a static member is called on a type, not on a value" "\0"
    "a static member is called, not taken as a value" "\0"
    "a struct" "\0"
    "a trait" "\0"
    "a transient coroutine marker survived lowering" "\0"
    "a tuple element is" "\0"
    "a type argument of `" "\0"
    "a type implementing a trait more than once cannot fill it here" "\0"
    "a union holding an enum or a distinct cannot dispatch through a trait" "\0"
    "a union mixes the same type at two mutabilities" "\0"
    "a variant is" "\0"
    "a written type is read-only by default \xe2\x80\x94 drop `const`, and write `!` where mutation is needed" "\0"
    "a:<" "\0"
    "ac(" "\0"
    "accept " "\0"
    "access to a struct field marked `@internal` from outside its declaring module" "\0"
    "add" "\0"
    "add one above the imports, e.g. `module \"main\"`" "\0"
    "alias" "\0"
    "alias after `as`" "\0"
    "align_of" "\0"
    "align_of: argument is not a type" "\0"
    "allow_unused" "\0"
    "already exists" "\0"
    "am(" "\0"
    "ambiguous overload resolution" "\0"
    "amp" "\0"
    "an `as` binding cannot appear in a `&&` condition ; narrow the variable in place (`if x is T && \xe2\x80\xa6`) or nest the checks (`if x is T as a { if \xe2\x80\xa6 }`)" "\0"
    "an `implements` block" "\0"
    "an `is` test cannot tell apart the instances of a generic that share one body" "\0"
    "an `is` test compares the shape \xe2\x80\x94 mutability has no runtime representation, so drop the `!` (the narrowed binding keeps the scrutinee's own mutability)" "\0"
    "an alternative binds nothing: test `is A | B` and read `." "\0"
    "an array renders only when interpolated directly, not through type " "\0"
    "an assignment takes at least one target" "\0"
    "an element is" "\0"
    "an element of it is written here" "\0"
    "an enum" "\0"
    "an impl member" "\0"
    "an impl member must be declared by its trait" "\0"
    "an impl member must have its trait method's signature" "\0"
    "an impl on an array has a partly generic element" "\0"
    "an in-loop element access the compiler could not prove in range \xe2\x80\x94 it re-checks bounds on every iteration" "\0"
    "an index write mutates this receiver through `set_at`" "\0"
    "an instance body lowered with no instance" "\0"
    "an instance member is called on a value, not on a type" "\0"
    "an instance whose body is shared \xe2\x80\x94 its values cannot be told apart " "\0"
    "an operand is past the register engine's encoding" "\0"
    "and" "\0"
    "and_and" "\0"
    "and_res" "\0"
    "any" "\0"
    "are offered ; call it so its arguments pick one" "\0"
    "arg" "\0"
    "argc" "\0"
    "argument " "\0"
    "argument for `" "\0"
    "argv" "\0"
    "arm64" "\0"
    "arr" "\0"
    "arr_member::" "\0"
    "array" "\0"
    "array bounds-check" "\0"
    "array index must be an integer, got " "\0"
    "array.clear" "\0"
    "array.clear receiver" "\0"
    "array.copy" "\0"
    "array.copy destination range out of bounds (dst must already be long enough) at pc=" "\0"
    "array.copy dst" "\0"
    "array.copy dst_start" "\0"
    "array.copy len" "\0"
    "array.copy source range out of bounds at pc=" "\0"
    "array.copy src" "\0"
    "array.copy src_start" "\0"
    "array.get" "\0"
    "array.len" "\0"
    "array.new" "\0"
    "array.new length " "\0"
    "array.push" "\0"
    "array.push_all" "\0"
    "array.push_all receiver" "\0"
    "array.push_all source" "\0"
    "array.remove_last" "\0"
    "array.remove_last receiver" "\0"
    "array.repeat" "\0"
    "array.repeat count" "\0"
    "array.repeat receiver" "\0"
    "array.set" "\0"
    "array.slice" "\0"
    "array.slice hi" "\0"
    "array.slice lo" "\0"
    "array.slice receiver" "\0"
    "arrow" "\0"
    "as" "\0"
    "assert" "\0"
    "assign" "\0"
    "assigned value's type is not assignable to the target's declared type" "\0"
    "async `main` suspended, but this build has no scheduler (Phase 2b) to resume it" "\0"
    "async block-split: await target not spilled" "\0"
    "async lowering: `Async` core trait not found" "\0"
    "async lowering: `Suspended` core type not found" "\0"
    "at" "\0"
    "atexit" "\0"
    "auto" "\0"
    "await" "\0"
    "await outside an async coroutine" "\0"
    "awaited" "\0"
    "b" "\0"
    "bad file descriptor" "\0"
    "bang" "\0"
    "binary op not allowed in type position" "\0"
    "binding" "\0"
    "binding name after `as`" "\0"
    "binding name in destructure pattern" "\0"
    "binds its type parameter to a type granting mutation" "\0"
    "bitand" "\0"
    "bitor" "\0"
    "bits_to_f32" "\0"
    "bits_to_f64" "\0"
    "bitxor" "\0"
    "block" "\0"
    "bool" "\0"
    "bool.and" "\0"
    "bool.const " "\0"
    "bool.eq" "\0"
    "bool.ne" "\0"
    "bool.not" "\0"
    "bool.or" "\0"
    "bootstrap: cannot write `" "\0"
    "boundimpl::" "\0"
    "boxed" "\0"
    "br" "\0"
    "br (pc " "\0"
    "br_if" "\0"
    "br_if (pc " "\0"
    "break" "\0"
    "break;" "\0"
    "breakpoint" "\0"
    "broken pipe" "\0"
    "browser" "\0"
    "buf" "\0"
    "buf->length" "\0"
    "buf->slots" "\0"
    "buffer.new" "\0"
    "buffer.new size" "\0"
    "buffer.new size " "\0"
    "buffer_to_string" "\0"
    "buffer_to_string len" "\0"
    "buffer_to_string receiver" "\0"
    "buffer_write_string" "\0"
    "buffer_write_string off" "\0"
    "buffer_write_string receiver" "\0"
    "buffer_write_string source" "\0"
    "build" "\0"
    "build the elements in a loop when each slot needs its own" "\0"
    "build/generated" "\0"
    "build_core_struct_lit: missing field `" "\0"
    "build_core_struct_lit: not a struct type" "\0"
    "build_core_struct_lit: struct decl not indexed for " "\0"
    "builtin-fn" "\0"
    "builtin-type" "\0"
    "but this receiver is immutable" "\0"
    "byte" "\0"
    "byte index out of bounds" "\0"
    "byte_at" "\0"
    "byte_at index" "\0"
    "byte_at receiver" "\0"
    "byte_len" "\0"
    "bytecode emit: `" "\0"
    "bytecode emit: bodyless `@intrinsic` host `" "\0"
    "bytecode/emit_ctx: intern_type would mint `" "\0"
    "bytecode: `bc_single_result_type` reached a signature with " "\0"
    "bytecode: `bc_single_result` reached a signature with " "\0"
    "bytes" "\0"
    "bytes receiver" "\0"
    "bytes-view elision" "\0"
    "bytes: no u8 type" "\0"
    "bytes: no u8[] type" "\0"
    "bytes_to_string byte" "\0"
    "bytes_to_string receiver" "\0"
    "bytes_used" "\0"
    "c" "\0"
    "c0" "\0"
    "c1" "\0"
    "c_ast: temp " "\0"
    "c_emit: `else` outside an `if`" "\0"
    "c_emit: a baked number of kind `" "\0"
    "c_emit: baked struct symbol_id " "\0"
    "c_emit: op names function " "\0"
    "c_emit: operand stack not empty at " "\0"
    "c_header" "\0"
    "c_out" "\0"
    "c_pointer" "\0"
    "c_struct" "\0"
    "c_variadic" "\0"
    "call" "\0"
    "call stack overflow (depth > " "\0"
    "call.import" "\0"
    "call.indirect" "\0"
    "call.indirect arity mismatch at pc=" "\0"
    "call.indirect on non-fn type " "\0"
    "call.indirect receiver" "\0"
    "call_ind" "\0"
    "callback argument must name a function directly" "\0"
    "callee has type " "\0"
    "cancel" "\0"
    "cannot assign a value of type " "\0"
    "cannot cast " "\0"
    "cannot destructure `" "\0"
    "cannot destructure a value of type " "\0"
    "cannot infer enum type for `." "\0"
    "cannot infer enum type from context" "\0"
    "cannot infer type argument \xe2\x80\x94 nothing at this call site binds the type parameter" "\0"
    "cannot mutate `" "\0"
    "cannot mutate an immutable array" "\0"
    "cannot mutate through an immutable access path" "\0"
    "cannot open file" "\0"
    "cannot reassign a constant binding" "\0"
    "cap" "\0"
    "cap_" "\0"
    "capacity" "\0"
    "caret" "\0"
    "case" "\0"
    "case " "\0"
    "cast" "\0"
    "cell" "\0"
    "cell_get" "\0"
    "chained `" "\0"
    "chained `!in`" "\0"
    "chained `!is`" "\0"
    "char" "\0"
    "char**" "\0"
    "char.const " "\0"
    "char_literal" "\0"
    "character literal (codepoint " "\0"
    "character literal cannot be empty" "\0"
    "character literal must contain exactly one codepoint" "\0"
    "character literal's codepoint does not fit the target integer type" "\0"
    "chars" "\0"
    "clear" "\0"
    "close failed" "\0"
    "closure" "\0"
    "coalesce" "\0"
    "code after a divergent statement" "\0"
    "codepoint escape must have 1\xe2\x80\x93""6 hex digits" "\0"
    "codepoint exceeds U+10FFFF" "\0"
    "colon" "\0"
    "comma" "\0"
    "compare" "\0"
    "comparison of arrays or structs" "\0"
    "comparison operand kinds disagree" "\0"
    "comparison operator" "\0"
    "compile-time assertion failed" "\0"
    "compound assignment needs a single target" "\0"
    "comptime" "\0"
    "comptime VM produced a " "\0"
    "comptime call stack overflow" "\0"
    "comptime division by zero" "\0"
    "comptime evaluation depends on itself" "\0"
    "comptime evaluation exceeded " "\0"
    "comptime evaluation panicked" "\0"
    "comptime feature not yet supported" "\0"
    "comptime index out of bounds" "\0"
    "comptime type-value lowering deferred" "\0"
    "comptime value has incompatible type" "\0"
    "comptime void value" "\0"
    "computes something else" "\0"
    "concat_" "\0"
    "cond" "\0"
    "condition must be `bool`" "\0"
    "conflicting trait impl for the same type" "\0"
    "const" "\0"
    "const " "\0"
    "const char*" "\0"
    "const uint16_t[]" "\0"
    "const_init" "\0"
    "consumed" "\0"
    "consumer: the callee has no body" "\0"
    "contains" "\0"
    "continue" "\0"
    "continue;" "\0"
    "control leaves the body with " "\0"
    "convert at pc=" "\0"
    "copy_to" "\0"
    "could be " "\0"
    "cp_slice" "\0"
    "cursor" "\0"
    "cyclic type alias" "\0"
    "d" "\0"
    "darwin" "\0"
    "data" "\0"
    "data.const" "\0"
    "data_const" "\0"
    "decl_const" "\0"
    "decl_var" "\0"
    "declaration is never used in its module" "\0"
    "decorator argument has the wrong form" "\0"
    "decorator arguments must be string literals at comptime" "\0"
    "decorator name after `@`" "\0"
    "decorator not allowed on this parameter" "\0"
    "decorator unknown to the compiler" "\0"
    "default" "\0"
    "default:" "\0"
    "defer" "\0"
    "defer thunk '" "\0"
    "defer.pop_exec" "\0"
    "defer.pop_exec " "\0"
    "defer.pop_exec underflow (count=" "\0"
    "defer.push" "\0"
    "deprecated" "\0"
    "destr_el" "\0"
    "destr_rest" "\0"
    "destr_src" "\0"
    "destructure of " "\0"
    "directory not empty" "\0"
    "dispatch$" "\0"
    "displayable" "\0"
    "div" "\0"
    "do" "\0"
    "dollar" "\0"
    "dot" "\0"
    "dotdotdot" "\0"
    "double" "\0"
    "drop" "\0"
    "duplicate `@extern` C symbol `" "\0"
    "duplicate bare `@target` declaration" "\0"
    "duplicate enum variant value" "\0"
    "duplicate field name in struct literal" "\0"
    "duplicate import binding" "\0"
    "duplicate non-fn declaration across files of the same module" "\0"
    "duplicate top-level symbol in module" "\0"
    "e" "\0"
    "ekeys" "\0"
    "elements are emitted as read-only statics, and keeping the element type read-only is what makes the writable slots safe" "\0"
    "else" "\0"
    "emit_branch: unresolved target at pc " "\0"
    "emit_end: no scope ends at pc " "\0"
    "empty `[]` is not a valid type" "\0"
    "empty input" "\0"
    "empty modifier list on an import \xe2\x80\x94 `import \"p\" {}` is just a wildcard, write `import \"p\"`" "\0"
    "end" "\0"
    "end of file" "\0"
    "end_" "\0"
    "entered unreachable code: " "\0"
    "entry block is not block 0" "\0"
    "entry function '" "\0"
    "enum" "\0"
    "enum backing type must be a primitive integer" "\0"
    "enum variant data must be a struct" "\0"
    "enum variant value out of range for backing type" "\0"
    "enum without variant data" "\0"
    "env" "\0"
    "eof" "\0"
    "eq" "\0"
    "eq_l" "\0"
    "eq_r" "\0"
    "equals" "\0"
    "equals arg" "\0"
    "equals receiver" "\0"
    "error" "\0"
    "error value" "\0"
    "escape \\" "\0"
    "escape \\' is not valid in a string literal" "\0"
    "evals" "\0"
    "every `" "\0"
    "every enum implements `Equals`, comparing by variant : " "\0"
    "every value of `" "\0"
    "exec_fn_value: no function named '" "\0"
    "executable statement at top level (only declarations allowed)" "\0"
    "expected " "\0"
    "expected '{' after \\u" "\0"
    "expected `" "\0"
    "expected `,` or `]`" "\0"
    "expected `,` or `}`" "\0"
    "expected `->` or `{` after trait reference (got " "\0"
    "expected `null`" "\0"
    "expected `true` or `false`" "\0"
    "expected a declaration" "\0"
    "expected a generic argument list" "\0"
    "expected a pattern" "\0"
    "expected a statement" "\0"
    "expected a target selector such as `.Windows`" "\0"
    "expected a type" "\0"
    "expected an expression" "\0"
    "expected an expression of a known type" "\0"
    "expected an identifier" "\0"
    "expected digit" "\0"
    "expected digit after `.`" "\0"
    "expected digit in exponent" "\0"
    "expected digits after base prefix" "\0"
    "expected key `" "\0"
    "expected member declaration `name :: fn(...)` (got " "\0"
    "expected parameter name (got " "\0"
    "expected token" "\0"
    "explicit `import \"std/core\"` is redundant (prelude already in scope)" "\0"
    "exponent has no digits" "\0"
    "export" "\0"
    "export VADER_ARCH: Arch: ." "\0"
    "export VADER_OS: Os: ." "\0"
    "exported `" "\0"
    "exported decl references a module-private decl in its signature" "\0"
    "exported declaration exposes a non-exported type" "\0"
    "exported function is never reached from the project's roots" "\0"
    "exposes a field of type" "\0"
    "expression" "\0"
    "expression cannot be evaluated at compile time" "\0"
    "expression is not callable" "\0"
    "expression is not indexable" "\0"
    "expression nesting too deep" "\0"
    "expression-bodied function cannot also declare an explicit return type" "\0"
    "extern" "\0"
    "extern " "\0"
    "extern `" "\0"
    "extern: a `string` result is not covered on the VM" "\0"
    "f" "\0"
    "f32" "\0"
    "f32_to_bits" "\0"
    "f64" "\0"
    "f64.add" "\0"
    "f64.const " "\0"
    "f64.div" "\0"
    "f64.eq" "\0"
    "f64.ge" "\0"
    "f64.gt" "\0"
    "f64.le" "\0"
    "f64.lt" "\0"
    "f64.mul" "\0"
    "f64.ne" "\0"
    "f64.neg" "\0"
    "f64.sub" "\0"
    "f64_to_bits" "\0"
    "f:(" "\0"
    "f_" "\0"
    "false" "\0"
    "fat_arrow" "\0"
    "feature not yet implemented" "\0"
    "ffi_call desc" "\0"
    "ffi_call desc byte" "\0"
    "ffi_call fn_ptr" "\0"
    "ffi_call frame" "\0"
    "ffi_call frame byte" "\0"
    "ffi_open name" "\0"
    "ffi_symbol lib" "\0"
    "ffi_symbol name" "\0"
    "field" "\0"
    "field `" "\0"
    "field access names no member of its receiver" "\0"
    "field already provided in struct literal" "\0"
    "field defaults cannot fill each other in" "\0"
    "field does not exist on this type" "\0"
    "field name" "\0"
    "field name after `.`" "\0"
    "field name after `.` in qualified type" "\0"
    "field name in struct pattern" "\0"
    "field_array" "\0"
    "field_count" "\0"
    "field_count: argument is not a type" "\0"
    "field_index" "\0"
    "field_index: `" "\0"
    "field_index: field name must be a static string literal" "\0"
    "field_index: first argument is not a type" "\0"
    "field_index: struct declaration for `" "\0"
    "fields" "\0"
    "file" "\0"
    "file not found" "\0"
    "file too large" "\0"
    "files in the same folder declare different module names" "\0"
    "finish_buffer" "\0"
    "fit ; give the call's result a type" "\0"
    "float" "\0"
    "float_literal" "\0"
    "fn" "\0"
    "fn(" "\0"
    "fn.addr" "\0"
    "fn.addr at pc=" "\0"
    "fn.ref" "\0"
    "fn_addr" "\0"
    "fn_ref" "\0"
    "fnobj" "\0"
    "for" "\0"
    "for (;;) {" "\0"
    "for-in fusion" "\0"
    "for-in needs an `Iterator` step type from std/core" "\0"
    "for-in receiver has no `Iterator` impl" "\0"
    "for_arr" "\0"
    "for_discard" "\0"
    "for_elem" "\0"
    "for_hi" "\0"
    "for_i" "\0"
    "for_len" "\0"
    "for_pat" "\0"
    "from the other instances erasing `" "\0"
    "function body returns a value incompatible with its declared return type" "\0"
    "function defined more than once with the same signature in a module" "\0"
    "function is not callable in comptime context" "\0"
    "function reference" "\0"
    "function reference resolves to no emitted function" "\0"
    "function signature must be fully annotated" "\0"
    "fuse_arr" "\0"
    "fuse_hi" "\0"
    "fuse_i" "\0"
    "fuse_iter" "\0"
    "fuse_len" "\0"
    "fuse_lo" "\0"
    "fuse_step" "\0"
    "fused chain emitted before `bind_chain_operands` bound its operands" "\0"
    "gc_atom_roots" "\0"
    "gc_frame" "\0"
    "gc_frame.prev" "\0"
    "gc_raw_roots" "\0"
    "gc_roots" "\0"
    "gc_stack_objs" "\0"
    "gen_elem" "\0"
    "generator block-split: a `break` / `continue` outside any loop" "\0"
    "generator block-split: gb_compile_ctrl on a leaf stmt" "\0"
    "generator block-split: unresolved loop label in break/continue" "\0"
    "generator lowering: no `Iterator` step type in std/core" "\0"
    "generator source: the generator has no body" "\0"
    "generic argument count mismatch" "\0"
    "generic instance discovery did not converge" "\0"
    "generic-inst expression not lowered" "\0"
    "got " "\0"
    "goto" "\0"
    "goto " "\0"
    "gt" "\0"
    "gte" "\0"
    "hand out a fresh value from a fn instead" "\0"
    "hash" "\0"
    "hash receiver" "\0"
    "hdr" "\0"
    "header" "\0"
    "heap object (set / map)" "\0"
    "hint" "\0"
    "host `" "\0"
    "i" "\0"
    "i16" "\0"
    "i32" "\0"
    "i32.add" "\0"
    "i32.bitand" "\0"
    "i32.bitnot" "\0"
    "i32.bitor" "\0"
    "i32.bitxor" "\0"
    "i32.const " "\0"
    "i32.div" "\0"
    "i32.div by zero at pc=" "\0"
    "i32.eq" "\0"
    "i32.ge" "\0"
    "i32.gt" "\0"
    "i32.le" "\0"
    "i32.lt" "\0"
    "i32.mod by zero at pc=" "\0"
    "i32.mul" "\0"
    "i32.ne" "\0"
    "i32.neg" "\0"
    "i32.rem" "\0"
    "i32.shl" "\0"
    "i32.shr" "\0"
    "i32.sub" "\0"
    "i64" "\0"
    "i64.add" "\0"
    "i64.bitand" "\0"
    "i64.bitnot" "\0"
    "i64.bitor" "\0"
    "i64.bitxor" "\0"
    "i64.const " "\0"
    "i64.div" "\0"
    "i64.div by zero at pc=" "\0"
    "i64.eq" "\0"
    "i64.ge" "\0"
    "i64.gt" "\0"
    "i64.le" "\0"
    "i64.lt" "\0"
    "i64.mul" "\0"
    "i64.ne" "\0"
    "i64.neg" "\0"
    "i64.rem" "\0"
    "i64.rem by zero at pc=" "\0"
    "i64.shl" "\0"
    "i64.shr" "\0"
    "i64.sub" "\0"
    "i8" "\0"
    "id" "\0"
    "ident" "\0"
    "identifier did not resolve at lowering" "\0"
    "idx" "\0"
    "if" "\0"
    "if (" "\0"
    "if condition must be `bool`, got " "\0"
    "if open" "\0"
    "if_res" "\0"
    "impl" "\0"
    "impl block missing required trait method" "\0"
    "impl_member::" "\0"
    "implements" "\0"
    "impls of one trait cannot overlap" "\0"
    "import" "\0"
    "import \"std/target\"" "\0"
    "import cycle detected" "\0"
    "import path" "\0"
    "import path is empty" "\0"
    "import-binding" "\0"
    "imported name" "\0"
    "imported name not exported by module" "\0"
    "imported symbol shadows a builtin" "\0"
    "impure host call at comptime" "\0"
    "in" "\0"
    "in_hi" "\0"
    "in_lo" "\0"
    "in_x" "\0"
    "includePaths" "\0"
    "inclusive" "\0"
    "incomplete escape sequence" "\0"
    "index past the end of a " "\0"
    "inf" "\0"
    "info" "\0"
    "inline" "\0"
    "inline " "\0"
    "inlined" "\0"
    "inlined call: parameter `" "\0"
    "inner" "\0"
    "inside string literal" "\0"
    "instance of `" "\0"
    "instruction names a local outside the function" "\0"
    "int" "\0"
    "int16_t" "\0"
    "int32_t" "\0"
    "int64_t" "\0"
    "int8_t" "\0"
    "int_literal" "\0"
    "integer literal " "\0"
    "integer literal after `=`" "\0"
    "integer literal does not fit the target integer type" "\0"
    "integer literal exceeds the u64 range" "\0"
    "intern_string" "\0"
    "internal" "\0"
    "interp_close" "\0"
    "interp_open" "\0"
    "interpolation expression must follow `${`" "\0"
    "interpolation not allowed in import path" "\0"
    "interrupted" "\0"
    "into" "\0"
    "intptr_t" "\0"
    "intrinsic" "\0"
    "intrinsic not implemented by the lowerer" "\0"
    "intrinsic size_of.type" "\0"
    "intrinsic size_of.type: expected type value, got " "\0"
    "intrinsic size_of.type: type " "\0"
    "invalid Unicode codepoint escape" "\0"
    "invalid \\u escape" "\0"
    "invalid `@extern` declaration" "\0"
    "invalid `main` signature" "\0"
    "invalid argument" "\0"
    "invalid cast" "\0"
    "invalid character literal" "\0"
    "invalid digit" "\0"
    "invalid escape sequence" "\0"
    "invalid hex digit in codepoint escape" "\0"
    "invalid module name (does not match `[a-z][a-z0-9_]*(/[a-z][a-z0-9_]*)*` grammar)" "\0"
    "invalid number" "\0"
    "is" "\0"
    "is a directory" "\0"
    "is impure and cannot run at comptime" "\0"
    "is read-only" "\0"
    "isize" "\0"
    "it fills `" "\0"
    "it is handed mutable elements here" "\0"
    "it is passed to `" "\0"
    "it is passed to a parameter that mutates it" "\0"
    "it is stored into an element that grants mutation" "\0"
    "it is stored where a mutable value is expected" "\0"
    "it is written through here" "\0"
    "iter" "\0"
    "iter_ekeys" "\0"
    "iter_evals" "\0"
    "iter_pos" "\0"
    "iter_size" "\0"
    "iter_src" "\0"
    "its `.bytes()` receiver is reassigned in the body" "\0"
    "its `@target` bodies cover " "\0"
    "its source writes the `!`" "\0"
    "k" "\0"
    "kw_as" "\0"
    "kw_await" "\0"
    "kw_break" "\0"
    "kw_const" "\0"
    "kw_continue" "\0"
    "kw_defer" "\0"
    "kw_else" "\0"
    "kw_enum" "\0"
    "kw_export" "\0"
    "kw_false" "\0"
    "kw_fn" "\0"
    "kw_for" "\0"
    "kw_if" "\0"
    "kw_implements" "\0"
    "kw_import" "\0"
    "kw_in" "\0"
    "kw_is" "\0"
    "kw_match" "\0"
    "kw_null" "\0"
    "kw_return" "\0"
    "kw_self" "\0"
    "kw_struct" "\0"
    "kw_trait" "\0"
    "kw_true" "\0"
    "kw_yield" "\0"
    "l" "\0"
    "lambda capture not yet supported for this binding kind" "\0"
    "lambda parameter `" "\0"
    "lbrace" "\0"
    "lbracket" "\0"
    "leading zeros are not allowed" "\0"
    "len" "\0"
    "length" "\0"
    "level the data pool can make writable" "\0"
    "lib" "\0"
    "linux" "\0"
    "literal could take several members of the union" "\0"
    "load_f64" "\0"
    "load_i32" "\0"
    "load_i64" "\0"
    "load_slot" "\0"
    "load_slot_f64" "\0"
    "load_slot_i32" "\0"
    "load_slot_i64" "\0"
    "load_u8" "\0"
    "local" "\0"
    "local binding shadows an outer local or parameter of the same name" "\0"
    "local is declared mutable but never reassigned \xe2\x80\x94 declare it with `::`" "\0"
    "local is read but never written" "\0"
    "local.field" "\0"
    "local.get" "\0"
    "local.set" "\0"
    "local.tee" "\0"
    "logical operator requires bool operands" "\0"
    "long" "\0"
    "loop" "\0"
    "loop_" "\0"
    "lower_string_lit: " "\0"
    "lower_ufcs: a free-fn UFCS dispatch recorded no chosen fn" "\0"
    "lparen" "\0"
    "lt" "\0"
    "lte" "\0"
    "m" "\0"
    "main" "\0"
    "main must return i32" "\0"
    "main takes either no parameters or a single `[string]` argument" "\0"
    "main(argv): missing [string] type" "\0"
    "make_closure" "\0"
    "malformed numeric literal" "\0"
    "match" "\0"
    "match arm can never be taken \xe2\x80\x94 an earlier arm already covers it" "\0"
    "match arm is unreachable after lowering" "\0"
    "match on non-union " "\0"
    "match-arm guard must be `bool`, got " "\0"
    "maximum nesting depth exceeded" "\0"
    "memory_copy" "\0"
    "memory_copy dest range [" "\0"
    "memory_copy dst" "\0"
    "memory_copy dst_off" "\0"
    "memory_copy n" "\0"
    "memory_copy negative length/offset at pc=" "\0"
    "memory_copy source range [" "\0"
    "memory_copy src" "\0"
    "memory_copy src_off" "\0"
    "method call lacks a resolvable `self` receiver" "\0"
    "midir/build: `" "\0"
    "midir/build: argument " "\0"
    "midir/emit: no field `" "\0"
    "midir/emit: unhandled Instruction reached emit_instr \xe2\x80\x94 a variant has no emitter" "\0"
    "midir/emit: unhandled intrinsic `" "\0"
    "midir/emit: unresolved callee '" "\0"
    "midir/emit: unresolved closure fn '" "\0"
    "midir/emit: unresolved fn-addr '" "\0"
    "midir/emit: unresolved fn-ref '" "\0"
    "midir/structure: '" "\0"
    "midir: coroutine marker (LoweredYield/LoweredAwait) reached build_stmt \xe2\x80\x94 lower_coroutine should have consumed it" "\0"
    "midir: lowered_to_bc_value reached a non-primitive leaf \xe2\x80\x94 is_bakeable/converter drift" "\0"
    "minus" "\0"
    "minus_assign" "\0"
    "minus_percent" "\0"
    "minus_percent_assign" "\0"
    "missing function body" "\0"
    "missing newline between top-level declarations" "\0"
    "missing required " "\0"
    "missing required argument" "\0"
    "missing required argument `" "\0"
    "missing required field in struct literal" "\0"
    "missing terminator" "\0"
    "mod" "\0"
    "module" "\0"
    "module \"std/target/baked\"" "\0"
    "module const ; drop the `!` to get the read-only form" "\0"
    "module declaration missing on first non-trivial line" "\0"
    "module folder is empty (no .vader files)" "\0"
    "module name" "\0"
    "module not found" "\0"
    "more than one module declaration in the same file" "\0"
    "mul" "\0"
    "name" "\0"
    "name after `...` in destructure pattern" "\0"
    "name is exported by several wildcard-imported modules" "\0"
    "name the scrutinee in the header: `match \xe2\x80\xa6 as " "\0"
    "named argument duplicates a positional one" "\0"
    "nan" "\0"
    "narrow" "\0"
    "narrow it to `" "\0"
    "negative literal does not fit unsigned `" "\0"
    "neq" "\0"
    "never" "\0"
    "new_buffer" "\0"
    "new_byte_buffer" "\0"
    "newline" "\0"
    "next" "\0"
    "no Iterator impl on " "\0"
    "no `" "\0"
    "no `.vader` file in `" "\0"
    "no `@target` body covers the target being built" "\0"
    "no body per instance ; dispatch through a trait instead" "\0"
    "no entry function (index=" "\0"
    "no impl member `" "\0"
    "no impl of " "\0"
    "no parameter named `" "\0"
    "no register form for this op" "\0"
    "no space left on device" "\0"
    "no vtable for " "\0"
    "no_return" "\0"
    "non-associative operator chained" "\0"
    "non-exhaustive match" "\0"
    "non-exhaustive match (T3013 should have caught this)" "\0"
    "not a directory" "\0"
    "not an assignment target" "\0"
    "not every path through the body returns a value" "\0"
    "not yet implemented: " "\0"
    "not_same" "\0"
    "nothing" "\0"
    "nothing mutates this value at this level \xe2\x80\x94 remove the `!`" "\0"
    "null" "\0"
    "null.const" "\0"
    "obj" "\0"
    "object" "\0"
    "off" "\0"
    "offset" "\0"
    "offsetof(" "\0"
    "offsetof(vader_array_t, buf)" "\0"
    "offsetof(vader_fn_t, env)" "\0"
    "on both sides, or pin the slot's type" "\0"
    "one `next()` per iteration instead of an inlined loop (the call itself is usually devirtualised, and the step pair usually crosses in registers); the fast paths cover an int range, a raw `T[]`, a map / set, a fusible combinator chain and a direct generator" "\0"
    "only one impl per (type, trait) is allowed" "\0"
    "open failed" "\0"
    "operand kinds disagree for arithmetic op" "\0"
    "operand kinds disagree for bit / mod / shift op" "\0"
    "operand type does not implement the trait this operator requires" "\0"
    "operator " "\0"
    "operator !=" "\0"
    "operator ==" "\0"
    "operator in" "\0"
    "operator not defined for these operand types" "\0"
    "or" "\0"
    "or narrow to an object first" "\0"
    "or_or" "\0"
    "or_res" "\0"
    "orphan impl forbidden" "\0"
    "other" "\0"
    "out" "\0"
    "overflow" "\0"
    "p" "\0"
    "p:" "\0"
    "panic" "\0"
    "panic unwind defer" "\0"
    "param" "\0"
    "parameter " "\0"
    "parameter `" "\0"
    "parse_float: invalid float `" "\0"
    "partial" "\0"
    "path contains a NUL byte" "\0"
    "payload" "\0"
    "payload." "\0"
    "percent" "\0"
    "percent_assign" "\0"
    "permission denied" "\0"
    "pipe" "\0"
    "place_operand" "\0"
    "plus" "\0"
    "plus_assign" "\0"
    "plus_percent" "\0"
    "plus_percent_assign" "\0"
    "pointer" "\0"
    "pooled constant holds a non-primitive leaf" "\0"
    "positional argument after a named argument" "\0"
    "prefer targeting this loop by its iteration variable over a label ; a label is only needed for a `while` / infinite loop that has no variable" "\0"
    "primitive" "\0"
    "ptr" "\0"
    "ptrdiff_t" "\0"
    "push" "\0"
    "push_all" "\0"
    "put `null` where `" "\0"
    "question_question" "\0"
    "r" "\0"
    "r:" "\0"
    "range_excl" "\0"
    "range_incl" "\0"
    "range_lo" "\0"
    "rb" "\0"
    "rbrace" "\0"
    "rbracket" "\0"
    "reached unreachable: " "\0"
    "reaches pc=" "\0"
    "read failed" "\0"
    "read_dir: cannot open `" "\0"
    "readonly " "\0"
    "recursive expression-bodied function requires an explicit `-> Type` annotation" "\0"
    "recv" "\0"
    "redeclaration of a name already bound in this block" "\0"
    "ref" "\0"
    "ref.cast" "\0"
    "ref.eq" "\0"
    "ref.ne" "\0"
    "reg_translate: a string has no constant register" "\0"
    "reg_translate: constant missing from the prepass" "\0"
    "register" "\0"
    "relative import (`./` / `../`) is not part of the language" "\0"
    "relocates them), so `data.const` boxes a zero-copy view." "\0"
    "rem" "\0"
    "remove_last" "\0"
    "render its variant names, or implement `Display`" "\0"
    "repeated `!` on the same type level" "\0"
    "resolver: no scope for `" "\0"
    "rest-binding (`...name`) lowering deferred" "\0"
    "rest-binding only valid inside tuple destructure" "\0"
    "restrict" "\0"
    "result" "\0"
    "resume" "\0"
    "resumed" "\0"
    "retag" "\0"
    "return" "\0"
    "return " "\0"
    "return a `" "\0"
    "return from main" "\0"
    "return.lit " "\0"
    "return: a multi-value return reached the outermost frame" "\0"
    "return;" "\0"
    "returns" "\0"
    "returns a read-only value" "\0"
    "root" "\0"
    "rparen" "\0"
    "run_async_main" "\0"
    "s" "\0"
    "s:" "\0"
    "same" "\0"
    "satisfies" "\0"
    "sched_arm deadline" "\0"
    "scope end (pc " "\0"
    "scope open (pc " "\0"
    "scrut" "\0"
    "self" "\0"
    "self only valid as the first parameter of a method" "\0"
    "self-import: file imports its own module" "\0"
    "set_at" "\0"
    "several impls of " "\0"
    "several impls on " "\0"
    "several impls' `" "\0"
    "shebang only allowed on first line" "\0"
    "shl" "\0"
    "short" "\0"
    "short impl form requires a trait with exactly one method" "\0"
    "short write" "\0"
    "shr" "\0"
    "signed" "\0"
    "size" "\0"
    "size_of" "\0"
    "size_of.type" "\0"
    "size_of: argument is not a type" "\0"
    "size_t" "\0"
    "sizeof" "\0"
    "sizeof(" "\0"
    "slash" "\0"
    "slash_assign" "\0"
    "slice" "\0"
    "slice_r" "\0"
    "slice_target" "\0"
    "slotarr" "\0"
    "slots" "\0"
    "split: two units named `" "\0"
    "split: unit name for `" "\0"
    "spread" "\0"
    "spread source must be assignable to " "\0"
    "star" "\0"
    "star_assign" "\0"
    "star_percent" "\0"
    "star_percent_assign" "\0"
    "start" "\0"
    "state" "\0"
    "static" "\0"
    "static " "\0"
    "std/async" "\0"
    "std/async.vader" "\0"
    "std/collections" "\0"
    "std/core" "\0"
    "std/core.vader" "\0"
    "std/io/io.vader" "\0"
    "std/string_builder" "\0"
    "std/target" "\0"
    "std/target/baked" "\0"
    "std_abort$panic" "\0"
    "std_core$" "\0"
    "std_core$Buffer$ByteAccess$intern_string" "\0"
    "std_core$Buffer$ByteAccess$load_u8" "\0"
    "std_core$Buffer$ByteAccess$memory_copy" "\0"
    "std_core$Buffer$ByteAccess$store_u8" "\0"
    "std_core$Buffer$ByteAccess$write_string" "\0"
    "std_core$byte_at" "\0"
    "std_core$byte_len" "\0"
    "std_core$bytes" "\0"
    "std_core$bytes_to_string" "\0"
    "std_core$f32$Float32Bits$to_bits" "\0"
    "std_core$f64$FloatBits$to_bits" "\0"
    "std_core$string$Comparable$compare" "\0"
    "std_core$string$Equals$equals" "\0"
    "std_core$u32$Bits32Float$from_bits" "\0"
    "std_core$u64$BitsFloat$from_bits" "\0"
    "std_core$usize$BufferAlloc$new_buffer" "\0"
    "std_io$IOError" "\0"
    "std_runtime$bytes_copied" "\0"
    "std_runtime$bytes_used" "\0"
    "std_runtime$collect" "\0"
    "std_runtime$collections" "\0"
    "std_runtime$sched_arm" "\0"
    "std_runtime$sched_now" "\0"
    "std_runtime$sched_park" "\0"
    "std_target$current_arch" "\0"
    "std_target$current_os" "\0"
    "stddef.h" "\0"
    "stdlib.h" "\0"
    "step" "\0"
    "stepping `" "\0"
    "storage" "\0"
    "store_f64" "\0"
    "store_f64 value" "\0"
    "store_i32" "\0"
    "store_i64" "\0"
    "store_i64 value" "\0"
    "store_slot" "\0"
    "store_slot_f64" "\0"
    "store_slot_i32" "\0"
    "store_slot_i64" "\0"
    "store_u8" "\0"
    "stray backslash (Vader has no line continuation)" "\0"
    "string" "\0"
    "string + non-string" "\0"
    "string codepoint index out of bounds" "\0"
    "string index must be an integer, got " "\0"
    "string interpolation expression must implement `Display`" "\0"
    "string.compare" "\0"
    "string.const" "\0"
    "string.eq" "\0"
    "string.h" "\0"
    "string.ne" "\0"
    "string.slice_codepoints" "\0"
    "string.slice_codepoints hi" "\0"
    "string.slice_codepoints lo" "\0"
    "string.slice_codepoints receiver" "\0"
    "string[] index" "\0"
    "string[] receiver" "\0"
    "string_begin" "\0"
    "string_end" "\0"
    "string_part" "\0"
    "strlen" "\0"
    "struct" "\0"
    "struct " "\0"
    "struct field access on non-struct type " "\0"
    "struct literal field name" "\0"
    "struct literal not allowed at the top level of a control-flow condition" "\0"
    "struct { " "\0"
    "struct.get" "\0"
    "struct.new" "\0"
    "struct.new on non-struct type " "\0"
    "struct.new type " "\0"
    "struct.new_stack" "\0"
    "struct.set" "\0"
    "struct.set field " "\0"
    "struct.set on non-struct type " "\0"
    "struct.set receiver" "\0"
    "struct.set_stack" "\0"
    "sub" "\0"
    "switch" "\0"
    "switch (" "\0"
    "symbol is not exported from its module" "\0"
    "synthetic" "\0"
    "sys_write at pc=" "\0"
    "sys_write buf" "\0"
    "sys_write byte" "\0"
    "sys_write count" "\0"
    "sys_write fd" "\0"
    "t" "\0"
    "tag" "\0"
    "takes a parameter of type" "\0"
    "target" "\0"
    "target this loop by its variable `" "\0"
    "terminator names a block outside the function" "\0"
    "test" "\0"
    "test can never match \xe2\x80\x94 operands have no overlapping values" "\0"
    "test the field that holds it instead (`x.value is " "\0"
    "test the type with `is [T, U]` and destructure in the arm: `[a, b] :: \xe2\x80\xa6`" "\0"
    "that no enclosing loop carries" "\0"
    "the `import \"...\" as name` form was removed ; write `name :: import \"...\"` instead" "\0"
    "the array descriptor stays heap-allocated because " "\0"
    "the callback" "\0"
    "the collection" "\0"
    "the compiler deduces this `!` from the body \xe2\x80\x94 remove it" "\0"
    "the data of `" "\0"
    "the element" "\0"
    "the entry is `" "\0"
    "the enum name adds nothing here \xe2\x80\x94 the slot already pins it, so the bare variant reads the same" "\0"
    "the parameter is `@c_out` \xe2\x80\x94 C writes through it" "\0"
    "the parameter is declared `!` \xe2\x80\x94 the callee may mutate it" "\0"
    "the running process" "\0"
    "the same path is wildcard-imported twice in one file" "\0"
    "the scoped `name :: import \"...\" { a, b }` form was removed ; use `name :: import \"...\"` for a namespace or `import \"...\" { a, b }` to destructure" "\0"
    "the top level" "\0"
    "the type argument" "\0"
    "the value" "\0"
    "the variant" "\0"
    "the variant data of `" "\0"
    "the view escapes \xe2\x80\x94 it is used for something other than `.len()` / `[i]`" "\0"
    "this argument is immutable, but its parameter grants mutation" "\0"
    "this body takes " "\0"
    "this element is reached through an immutable path" "\0"
    "this free function is only in scope through its namespace alias" "\0"
    "this function mutates a parameter the target slot lends out read-only" "\0"
    "this impl and the one at " "\0"
    "this lambda promises " "\0"
    "this method mutates its receiver (`self!`), but the receiver is immutable" "\0"
    "through the scrutinee, or split the arm" "\0"
    "tilde" "\0"
    "to_string" "\0"
    "too few elements to destructure" "\0"
    "too many arguments : expected " "\0"
    "toolchain/build" "\0"
    "total_collections" "\0"
    "total_copied" "\0"
    "trailing characters after JSON value" "\0"
    "trailing comma allowed but list ended unexpectedly" "\0"
    "trait" "\0"
    "trait `" "\0"
    "trait name" "\0"
    "trait name does not refer to a trait" "\0"
    "trait not satisfied" "\0"
    "trait/impl members must use the `name :: fn(...)` form (the bare `fn name(...)` form was retired)" "\0"
    "true" "\0"
    "tup" "\0"
    "tuple" "\0"
    "two `@target` bodies cover the same platform" "\0"
    "two folders declare the same module name globally" "\0"
    "type" "\0"
    "type does not have generic parameters" "\0"
    "type mismatch" "\0"
    "type parameter `" "\0"
    "type parameter must be prefixed with `$`" "\0"
    "type parameter name" "\0"
    "type parameter name after `$`" "\0"
    "type value" "\0"
    "type-alias" "\0"
    "type-param" "\0"
    "type-param name" "\0"
    "type-valued slot is not yet supported in this position" "\0"
    "type-valued slot not lowered" "\0"
    "type.const" "\0"
    "type_args" "\0"
    "type_array" "\0"
    "type_check" "\0"
    "type_const" "\0"
    "type_index" "\0"
    "type_kind" "\0"
    "type_kind: argument is not a type" "\0"
    "type_name" "\0"
    "type_name: argument is not a type" "\0"
    "type_of" "\0"
    "typed numeric suffix `" "\0"
    "typedef" "\0"
    "typedef " "\0"
    "typedef struct " "\0"
    "u" "\0"
    "u)" "\0"
    "u, (void*)(uintptr_t)" "\0"
    "u, NULL)" "\0"
    "u16" "\0"
    "u32" "\0"
    "u32.div" "\0"
    "u32.div by zero at pc=" "\0"
    "u32.ge" "\0"
    "u32.gt" "\0"
    "u32.le" "\0"
    "u32.lt" "\0"
    "u32.rem" "\0"
    "u32.rem by zero at pc=" "\0"
    "u32.shr" "\0"
    "u64" "\0"
    "u64.div" "\0"
    "u64.div by zero at pc=" "\0"
    "u64.ge" "\0"
    "u64.gt" "\0"
    "u64.le" "\0"
    "u64.lt" "\0"
    "u64.rem" "\0"
    "u64.rem by zero at pc=" "\0"
    "u64.shr" "\0"
    "u8" "\0"
    "u:<" "\0"
    "uint16_t" "\0"
    "uint32_t" "\0"
    "uint64_t" "\0"
    "uint8_t" "\0"
    "uintptr_t" "\0"
    "unary `" "\0"
    "unbound host import '" "\0"
    "unbound import: " "\0"
    "underscore not allowed here" "\0"
    "unexpected character" "\0"
    "unexpected end of input" "\0"
    "unexpected token" "\0"
    "union" "\0"
    "unknown" "\0"
    "unknown decorator placement" "\0"
    "unknown enum variant" "\0"
    "unknown escape" "\0"
    "unknown escape \\" "\0"
    "unknown named argument" "\0"
    "unknown target selector" "\0"
    "unknown variant `" "\0"
    "unop" "\0"
    "unreachable" "\0"
    "unreachable code" "\0"
    "unreachable match arm" "\0"
    "unreachable return in " "\0"
    "unresolved ident " "\0"
    "unresolved identifier" "\0"
    "unresolved type name" "\0"
    "unsigned" "\0"
    "unterminated array" "\0"
    "unterminated block comment" "\0"
    "unterminated character literal" "\0"
    "unterminated escape" "\0"
    "unterminated object" "\0"
    "unterminated string" "\0"
    "unterminated string literal" "\0"
    "usage: bootstrap <input.vader> <output-prefix>" "\0"
    "use of `Self` outside a trait or impl context" "\0"
    "use of deprecated declaration" "\0"
    "use postfix `T[]` for an array, or a plain value if you meant the element" "\0"
    "usize" "\0"
    "vader.h" "\0"
    "vader.json" "\0"
    "vader.json malformed or unreadable" "\0"
    "vader/" "\0"
    "vader: panic \xe2\x80\x94 " "\0"
    "vader_" "\0"
    "vader_array_box_slots" "\0"
    "vader_array_buf_t*" "\0"
    "vader_array_bytes" "\0"
    "vader_array_clear" "\0"
    "vader_array_copy" "\0"
    "vader_array_is_borrowed" "\0"
    "vader_array_new" "\0"
    "vader_array_ptr_offsets" "\0"
    "vader_array_push" "\0"
    "vader_array_push_all" "\0"
    "vader_array_push_bool" "\0"
    "vader_array_push_f32" "\0"
    "vader_array_push_f64" "\0"
    "vader_array_push_i16" "\0"
    "vader_array_push_i32" "\0"
    "vader_array_push_i64" "\0"
    "vader_array_push_i8" "\0"
    "vader_array_push_u16" "\0"
    "vader_array_push_u8" "\0"
    "vader_array_read_u8" "\0"
    "vader_array_ref_load_box" "\0"
    "vader_array_ref_load_obj" "\0"
    "vader_array_ref_store" "\0"
    "vader_array_ref_store_box" "\0"
    "vader_array_remove_last" "\0"
    "vader_array_repeat" "\0"
    "vader_array_slice" "\0"
    "vader_array_t" "\0"
    "vader_array_t*" "\0"
    "vader_atom_blob" "\0"
    "vader_atom_comptime_table" "\0"
    "vader_atom_entry_t" "\0"
    "vader_atom_init_with_comptime" "\0"
    "vader_atom_intern" "\0"
    "vader_atom_roots_register" "\0"
    "vader_atom_shutdown" "\0"
    "vader_box_" "\0"
    "vader_box_eq" "\0"
    "vader_box_null" "\0"
    "vader_box_obj" "\0"
    "vader_box_obj(" "\0"
    "vader_box_t" "\0"
    "vader_box_t*" "\0"
    "vader_buffer_intern_string" "\0"
    "vader_buffer_load_f64" "\0"
    "vader_buffer_load_i32" "\0"
    "vader_buffer_load_i64" "\0"
    "vader_buffer_load_u8" "\0"
    "vader_buffer_memory_copy" "\0"
    "vader_buffer_new" "\0"
    "vader_buffer_store_f64" "\0"
    "vader_buffer_store_i32" "\0"
    "vader_buffer_store_i64" "\0"
    "vader_buffer_store_u8" "\0"
    "vader_buffer_t*" "\0"
    "vader_buffer_write_string" "\0"
    "vader_cstr_free_for" "\0"
    "vader_current_arch" "\0"
    "vader_current_os" "\0"
    "vader_data_" "\0"
    "vader_defer_pop_exec" "\0"
    "vader_defer_push" "\0"
    "vader_ffi_call_n" "\0"
    "vader_ffi_callback_escape" "\0"
    "vader_ffi_open" "\0"
    "vader_ffi_symbol" "\0"
    "vader_fn_erased_sig_" "\0"
    "vader_fn_lift_" "\0"
    "vader_fn_ptr_offsets" "\0"
    "vader_fn_static_" "\0"
    "vader_fn_t" "\0"
    "vader_fn_t*" "\0"
    "vader_fn_tramp_" "\0"
    "vader_gc_alloc" "\0"
    "vader_gc_collect" "\0"
    "vader_gc_frame_t" "\0"
    "vader_gc_get_stats" "\0"
    "vader_gc_shutdown" "\0"
    "vader_gc_top" "\0"
    "vader_global_const_arrays" "\0"
    "vader_global_const_frame" "\0"
    "vader_global_const_objs" "\0"
    "vader_host_" "\0"
    "vader_obj_header_init" "\0"
    "vader_obj_header_t" "\0"
    "vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3];" "\0"
    "vader_obj_header_t*" "\0"
    "vader_panic" "\0"
    "vader_profile$vader_prof_begin" "\0"
    "vader_profile$vader_prof_dump" "\0"
    "vader_profile$vader_prof_end" "\0"
    "vader_ref_box" "\0"
    "vader_runtime_argv" "\0"
    "vader_sched_arm" "\0"
    "vader_sched_now" "\0"
    "vader_sched_park" "\0"
    "vader_slice_t" "\0"
    "vader_string_as_string" "\0"
    "vader_string_byte_at" "\0"
    "vader_string_byte_len" "\0"
    "vader_string_bytes_view" "\0"
    "vader_string_codepoint_at" "\0"
    "vader_string_compare" "\0"
    "vader_string_hash" "\0"
    "vader_string_slice_codepoints" "\0"
    "vader_string_t" "\0"
    "vader_string_t*" "\0"
    "vader_string_to_cstr" "\0"
    "vader_struct_" "\0"
    "vader_trap" "\0"
    "vader_type_info_count" "\0"
    "vader_type_info_t" "\0"
    "vader_type_info_table" "\0"
    "vader_unreachable" "\0"
    "vader_vm$ffi_call" "\0"
    "vader_vm$ffi_open" "\0"
    "vader_vm$ffi_symbol" "\0"
    "vader_vt_" "\0"
    "value" "\0"
    "value " "\0"
    "value cannot be destructured into this many elements" "\0"
    "value is not iterable" "\0"
    "value-position expression not allowed in a type slot" "\0"
    "variant " "\0"
    "variant ." "\0"
    "variant data is constant" "\0"
    "variant data on an enum whose header declares none" "\0"
    "variant name" "\0"
    "variant name after `.`" "\0"
    "variant_count" "\0"
    "variant_count: argument is not a type" "\0"
    "vcall" "\0"
    "virtual.call " "\0"
    "virtual.call '" "\0"
    "void" "\0"
    "void*" "\0"
    "void**" "\0"
    "volatile" "\0"
    "vtable dispatchers" "\0"
    "vtable forwards" "\0"
    "vtable miss in " "\0"
    "wake_at" "\0"
    "warning" "\0"
    "wasi" "\0"
    "wasm32" "\0"
    "wb" "\0"
    "which already implements it" "\0"
    "which only `null` can be told from" "\0"
    "while" "\0"
    "while (" "\0"
    "while condition must be `bool`, got " "\0"
    "wildcard arm on a closed union silences exhaustiveness checking ; enumerate the variants or mark the match `@partial`" "\0"
    "wildcard arm on closed union `" "\0"
    "windows" "\0"
    "would block" "\0"
    "write" "\0"
    "write `" "\0"
    "write `." "\0"
    "write `_`, and name the scrutinee in the header: `match \xe2\x80\xa6 as " "\0"
    "write_bool" "\0"
    "write_int" "\0"
    "write_string" "\0"
    "write_string_at" "\0"
    "write_unsigned" "\0"
    "wrong number of arguments" "\0"
    "wrong number of decorator arguments" "\0"
    "x86_64" "\0"
    "xor" "\0"
    "yield" "\0"
    "yield outside a generator body" "\0"
    "yielded value type does not match the generator's element type" "\0"
    "{" "\0"
    "{\n" "\0"
    "{ " "\0"
    "{ }" "\0"
    "{0}" "\0"
    "{char}" "\0"
    "{float}" "\0"
    "{integer}" "\0"
    "|" "\0"
    "||" "\0"
    "}" "\0"
    "} " "\0"
    "} else if (" "\0"
    "} else {" "\0"
    "};\n" "\0"
    "~" "\0"
    "\xe2\x80\xa6" "\0"
    "\xe2\x80\xa6 and " "\0";

const vader_atom_entry_t vader_atom_comptime_table[] = {
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[0] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18] },
    { 0u, 0u, 68u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33] },
    { 0u, 0u, 71u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[102] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[174] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[177] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[179] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[182] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[187] },
    { 0u, 0u, 82u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[197] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[280] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[286] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[338] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[347] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[372] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[388] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[446] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[499] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[561] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[573] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[579] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[582] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[586] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[590] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[597] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[610] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[624] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[657] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[662] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[668] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[674] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[678] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[706] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[750] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[787] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[817] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[821] },
    { 0u, 0u, 95u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[868] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[964] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[972] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[995] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[998] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1002] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1006] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1009] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1020] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1023] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1037] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1056] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1070] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1089] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1097] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1109] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1114] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1122] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1130] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1137] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1146] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1154] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1183] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1202] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1221] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1231] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1247] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1302] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1309] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1329] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1339] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1347] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1363] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1374] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1402] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1408] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1415] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1422] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1433] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1457] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1480] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1486] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1499] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1522] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1540] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1546] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1552] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1560] },
    { 0u, 0u, 71u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1566] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1638] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1684] },
    { 0u, 0u, 86u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1715] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1802] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1822] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1839] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1863] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1886] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1902] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1920] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1957] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1971] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1984] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2004] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2038] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2058] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2074] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2093] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2103] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2133] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2138] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2144] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2152] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2161] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2166] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2187] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2214] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2235] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2245] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2279] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2305] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2323] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2343] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2376] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2384] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2438] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2448] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2465] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2483] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2508] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2562] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2574] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2582] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2590] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2626] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2633] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2646] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2660] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2669] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2674] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2694] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2701] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2713] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2744] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2761] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2798] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2857] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2877] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2900] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2919] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2926] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2930] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2934] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2938] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2947] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2950] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2960] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2970] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2976] },
    { 0u, 0u, 83u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2983] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3067] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3076] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3117] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3133] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3163] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3193] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3227] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3257] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3282] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3334] },
    { 0u, 0u, 71u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3371] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3443] },
    { 0u, 0u, 158u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3478] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3637] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3643] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3651] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3653] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3656] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3660] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3663] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3670] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3674] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3676] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3679] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3682] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3686] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3738] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3740] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3749] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3759] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3766] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3768] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3777] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3785] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3792] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3799] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3818] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3827] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3842] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3853] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3868] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3877] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3886] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3896] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3902] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3909] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3912] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3919] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3925] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3933] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3936] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3938] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3941] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3943] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3946] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3948] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3955] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3966] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3988] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4006] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4015] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4027] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4038] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4079] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4088] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4099] },
    { 0u, 0u, 107u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4118] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4226] },
    { 0u, 0u, 73u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4235] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4309] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4364] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4424] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4428] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4430] },
    { 0u, 0u, 62u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4492] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4555] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4578] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4589] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4592] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4611] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4618] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4631] },
    { 0u, 0u, 60u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4691] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4752] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4759] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4810] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4817] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4819] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4822] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4828] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4844] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4853] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4873] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4884] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4914] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4921] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4926] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4937] },
    { 0u, 0u, 90u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4948] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5039] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5084] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5132] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5181] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5218] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5221] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5225] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5229] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5233] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5236] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5240] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5242] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5245] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5249] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5252] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5254] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5257] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5261] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5264] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5270] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5272] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5275] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5278] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5282] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5289] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5322] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5367] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5400] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5430] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5435] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5444] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5451] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5459] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5476] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5494] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5533] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5535] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5538] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5542] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5547] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5550] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5553] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5559] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5572] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5579] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5587] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5593] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5598] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5607] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5620] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5625] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5627] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5630] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5634] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5638] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5642] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5646] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5649] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5652] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5655] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5658] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5661] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5664] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5675] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5681] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5686] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5697] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5710] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5713] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5719] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5730] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5741] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5750] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5755] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5762] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5764] },
    { 0u, 0u, 79u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5768] },
    { 0u, 0u, 76u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5848] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5925] },
    { 0u, 0u, 78u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5979] },
    { 0u, 0u, 75u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6058] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6134] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6137] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6140] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6155] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6157] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6161] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6178] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6180] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6210] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6213] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6216] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6218] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6221] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6225] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6244] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6258] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6279] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6311] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6323] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6342] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6357] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6372] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6381] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6404] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6426] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6447] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6467] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6488] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6509] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6540] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6564] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6588] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6612] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6622] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6650] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6674] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6693] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6747] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6750] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6759] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6762] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6764] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6767] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6770] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6772] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6775] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6778] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6803] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6840] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6850] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6859] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6868] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6883] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6892] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6897] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6912] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6918] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6930] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6937] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6947] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6958] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6960] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6963] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6966] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6970] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6973] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6975] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6978] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6981] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6984] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6986] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6989] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6993] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6995] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7025] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7057] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7094] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7125] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7162] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7209] },
    { 0u, 0u, 73u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7238] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7312] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7314] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7317] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7323] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7327] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7331] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7337] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7344] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7358] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7364] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7374] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7385] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7397] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7409] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7424] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7441] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7455] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7465] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7477] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7485] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7491] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7497] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7503] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7509] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7515] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7521] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7527] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7533] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7539] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7545] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7551] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7557] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7563] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7569] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7575] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7581] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7590] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7599] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7625] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7673] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7701] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7731] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7760] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7792] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7820] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7852] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7861] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7873] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7884] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7940] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7994] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8003] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8016] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8025] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8032] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8040] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8044] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8059] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8062] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8096] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8103] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8109] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8113] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8116] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8119] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8122] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8125] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8128] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8132] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8136] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8140] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8146] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8156] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8169] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8173] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8184] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8237] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8294] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8310] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8323] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8342] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8347] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8411] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8417] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8423] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8429] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8435] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8441] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8447] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8453] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8459] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8465] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8471] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8477] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8486] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8496] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8505] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8515] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8525] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8537] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8560] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8567] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8573] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8583] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8592] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8603] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8608] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8626] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8635] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8645] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8651] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8657] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8663] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8669] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8675] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8681] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8687] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8693] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8699] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8705] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8711] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8722] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8728] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8730] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8736] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8742] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8748] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8754] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8760] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8766] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8772] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8778] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8784] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8787] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8797] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8801] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8812] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8823] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8839] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8843] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8852] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8857] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8874] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8886] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8890] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8954] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8956] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8962] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8968] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8974] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8980] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8986] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8992] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8998] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9004] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9010] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9016] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9022] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9028] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9034] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9040] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9046] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9052] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9058] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9064] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9070] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9076] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9082] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9088] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9094] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9100] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9106] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9112] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9118] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9124] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9130] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9136] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9142] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9148] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9154] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9157] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9163] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9169] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9175] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9181] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9187] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9193] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9199] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9205] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9211] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9217] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9223] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9229] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9235] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9241] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9247] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9253] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9259] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9265] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9271] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9277] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9283] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9289] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9295] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9301] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9307] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9313] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9319] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9325] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9331] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9337] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9343] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9349] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9355] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9361] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9367] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9373] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9379] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9385] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9391] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9397] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9403] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9409] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9415] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9425] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9429] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9431] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9434] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9439] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9450] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9454] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9459] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9473] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9481] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9495] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9499] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9509] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9515] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9521] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9527] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9533] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9539] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9545] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9551] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9557] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9563] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9569] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9575] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9581] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9587] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9593] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9599] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9605] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9611] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9617] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9623] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9629] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9635] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9641] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9647] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9653] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9659] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9665] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9671] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9677] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9683] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9689] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9695] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9701] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9707] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9713] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9719] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9725] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9731] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9737] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9743] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9749] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9755] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9761] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9767] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9773] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9779] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9785] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9791] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9797] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9803] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9809] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9815] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9821] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9827] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9833] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9839] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9845] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9851] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9857] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9863] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9869] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9875] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9881] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9887] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9893] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9899] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9905] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9911] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9917] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9923] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9929] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9935] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9941] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9947] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9953] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9959] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9965] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9971] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9977] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9983] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9989] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9995] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10001] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10007] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10013] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10019] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10025] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10031] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10037] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10043] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10049] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10052] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10055] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10062] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10066] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10073] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10077] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10080] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10089] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10099] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10106] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10110] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10167] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10191] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10215] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10236] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10255] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10281] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10300] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10318] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10329] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10342] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10359] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10386] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10403] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10426] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10446] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10452] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10458] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10464] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10470] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10476] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10482] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10488] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10494] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10500] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10506] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10512] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10518] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10524] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10530] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10536] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10541] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10548] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10556] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10566] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10573] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10576] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10579] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10581] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10584] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10586] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10588] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10591] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10599] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10611] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10616] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10618] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10620] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10623] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10626] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10635] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10644] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10652] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10658] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10667] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10676] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10687] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10697] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10712] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10728] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10742] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10745] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10753] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10762] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10769] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10778] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10792] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10808] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10826] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10845] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10857] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10866] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10875] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10888] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10897] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10904] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10917] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10929] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10939] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10953] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10957] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10964] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10975] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10986] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10989] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10994] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10999] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11004] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11011] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11014] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11017] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11023] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11028] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11033] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11042] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11046] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11052] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11059] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11062] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11067] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11070] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11074] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11081] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11084] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11086] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11089] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11093] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11103] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11113] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11118] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11153] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11168] },
    { 0u, 0u, 225u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11178] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11404] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11436] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11462] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11514] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11548] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11576] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11599] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11641] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11649] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11674] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11702] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11733] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11740] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11746] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11755] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11770] },
    { 0u, 0u, 68u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11791] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11860] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11914] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11974] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11997] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12016] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12080] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12139] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12161] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12184] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12208] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12257] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12267] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12302] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12312] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12320] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12327] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12335] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12344] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12365] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12372] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12418] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12450] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12479] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12504] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12541] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12592] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12612] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12635] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12670] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12715] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12752] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12768] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12822] },
    { 0u, 0u, 68u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12848] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12917] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12979] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12994] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13006] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13013] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13020] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13028] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13049] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13057] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13062] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13069] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13098] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13106] },
    { 0u, 0u, 83u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13168] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13252] },
    { 0u, 0u, 94u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13276] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13371] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13393] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13423] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13449] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13509] },
    { 0u, 0u, 76u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13536] },
    { 0u, 0u, 164u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13613] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13778] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13822] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13838] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13893] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13911] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13955] },
    { 0u, 0u, 160u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13989] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14150] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14181] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14226] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14250] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14266] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14328] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14371] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14394] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14412] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14428] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14451] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14491] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14548] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14603] },
    { 0u, 0u, 211u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14626] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14838] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14877] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14916] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14975] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14999] },
    { 0u, 0u, 84u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15028] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15113] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15124] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15136] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15183] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15200] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15221] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15249] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15270] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15306] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15318] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15347] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15391] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15401] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15453] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15481] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15497] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15506] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15525] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15537] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15544] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15563] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15569] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15576] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15607] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15629] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15680] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15692] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15732] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15746] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15756] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15768] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15781] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15801] },
    { 0u, 0u, 106u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15853] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15960] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15971] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15983] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16035] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16054] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16105] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16114] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16124] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16164] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16209] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16249] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16269] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16296] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16320] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16333] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16368] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16398] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16444] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16467] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16505] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16523] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16542] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16570] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16592] },
    { 0u, 0u, 78u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16599] },
    { 0u, 0u, 108u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16678] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16787] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16832] },
    { 0u, 0u, 68u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16860] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16929] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16987] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17023] },
    { 0u, 0u, 137u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17063] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17201] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17234] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17290] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17346] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17405] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17459] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17478] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17492] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17545] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17584] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17632] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17650] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17692] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17705] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17718] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17750] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17774] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17806] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17809] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17817] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17852] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17882] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17904] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17939] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17955] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17982] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18010] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18048] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18080] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18113] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18117] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18122] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18130] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18155] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18183] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18210] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18219] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18238] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18263] },
    { 0u, 0u, 71u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18283] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18355] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18407] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18427] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18463] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18497] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18531] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18552] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18555] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18590] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18627] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18631] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18644] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18692] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18737] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18758] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18796] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18806] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18848] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18884] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18917] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18952] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18981] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19004] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19024] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19088] },
    { 0u, 0u, 82u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19091] },
    { 0u, 0u, 68u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19174] },
    { 0u, 0u, 67u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19243] },
    { 0u, 0u, 74u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19311] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19386] },
    { 0u, 0u, 69u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19443] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19513] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19532] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19569] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19604] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19658] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19703] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19763] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19802] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19846] },
    { 0u, 0u, 68u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19901] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19970] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20013] },
    { 0u, 0u, 91u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20028] },
    { 0u, 0u, 88u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20120] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20209] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20241] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20298] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20336] },
    { 0u, 0u, 71u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20394] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20466] },
    { 0u, 0u, 84u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20500] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20585] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20613] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20646] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20684] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20703] },
    { 0u, 0u, 112u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20728] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20841] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20886] },
    { 0u, 0u, 73u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20929] },
    { 0u, 0u, 85u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21003] },
    { 0u, 0u, 88u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21089] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21178] },
    { 0u, 0u, 83u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21226] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21310] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21348] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21396] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21442] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21448] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21492] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21513] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21547] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21575] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21593] },
    { 0u, 0u, 65u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21632] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21698] },
    { 0u, 0u, 181u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21748] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21930] },
    { 0u, 0u, 86u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21985] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22072] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22090] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22112] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22135] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22159] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22186] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22209] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22228] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22251] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22274] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22299] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22318] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22343] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22371] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22399] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22423] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22449] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22466] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22468] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22472] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22498] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22548] },
    { 0u, 0u, 120u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22597] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22718] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22775] },
    { 0u, 0u, 86u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22831] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22918] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22944] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22980] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22998] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23010] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23052] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23097] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23145] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23204] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23254] },
    { 0u, 0u, 78u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23287] },
    { 0u, 0u, 90u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23366] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23457] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23468] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23505] },
    { 0u, 0u, 107u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23556] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23664] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23706] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23720] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23759] },
    { 0u, 0u, 103u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23794] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23898] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23949] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23998] },
    { 0u, 0u, 101u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24024] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24126] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24186] },
    { 0u, 0u, 75u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24245] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24321] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24368] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24420] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24468] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24477] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24485] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24532] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24551] },
    { 0u, 0u, 62u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24572] },
    { 0u, 0u, 69u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24635] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24705] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24753] },
    { 0u, 0u, 95u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24766] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24862] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24866] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24870] },
    { 0u, 0u, 77u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24878] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24956] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24960] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25008] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25014] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25031] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25040] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25073] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25086] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25101] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25105] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25135] },
    { 0u, 0u, 150u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25139] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25290] },
    { 0u, 0u, 77u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25312] },
    { 0u, 0u, 153u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25390] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25544] },
    { 0u, 0u, 67u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25602] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25670] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25710] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25724] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25757] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25765] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25780] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25825] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25879] },
    { 0u, 0u, 106u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25928] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26035] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26089] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26131] },
    { 0u, 0u, 69u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26186] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26256] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26306] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26310] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26318] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26326] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26330] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26378] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26382] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26387] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26397] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26412] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26417] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26423] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26427] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26440] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26446] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26465] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26502] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26514] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26535] },
    { 0u, 0u, 83u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26546] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26630] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26645] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26666] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26681] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26726] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26741] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26762] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26772] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26782] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26792] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26810] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26821] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26836] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26860] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26882] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26900] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26927] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26940] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26959] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26981] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26991] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27003] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27018] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27033] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27054] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27060] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27063] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27070] },
    { 0u, 0u, 69u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27077] },
    { 0u, 0u, 79u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27147] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27227] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27271] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27316] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27364] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27367] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27374] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27379] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27385] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27418] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27426] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27428] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27448] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27453] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27492] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27500] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27524] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27560] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27613] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27620] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27626] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27638] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27650] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27657] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27663] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27668] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27677] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27689] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27697] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27705] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27714] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27722] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27748] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27760] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27766] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27769] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27777] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27783] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27794] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27800] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27807] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27818] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27830] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27838] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27842] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27854] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27865] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27876] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27892] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27909] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27926] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27947] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27973] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27993] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28017] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28046] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28073] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28079] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28137] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28153] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28192] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28233] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28285] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28296] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28309] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28340] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28345] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28370] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28378] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28392] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28409] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28418] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28435] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28479] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28523] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28583] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28638] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28644] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28659] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28678] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28696] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28716] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28737] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28762] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28773] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28775] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28778] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28781] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28794] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28825] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28858] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28890] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28917] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28953] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28962] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28968] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28978] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28987] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28998] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29003] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29033] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29045] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29059] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29095] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29125] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29148] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29157] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29205] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29222] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29229] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29260] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29273] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29294] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29330] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29360] },
    { 0u, 0u, 81u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29396] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29478] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29494] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29527] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29574] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29591] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29626] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29630] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29635] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29644] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29650] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29655] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29661] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29666] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29671] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29680] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29690] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29704] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29718] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29723] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29730] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29742] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29755] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29785] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29819] },
    { 0u, 0u, 66u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29872] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29939] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29945] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29951] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29964] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29972] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29981] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30014] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30058] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30085] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30091] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30097] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30105] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30137] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30171] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30191] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30221] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30263] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30272] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30296] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30325] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30351] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30389] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30419] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30448] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30483] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30512] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30550] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30587] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30607] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30631] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30639] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30644] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30669] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30710] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30716] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30723] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30735] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30752] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30763] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30772] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30805] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30814] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30823] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30833] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30863] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30878] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30886] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30896] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30905] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30912] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30930] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30932] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30939] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30944] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30955] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30966] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30977] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30986] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31026] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31064] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31120] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31145] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31185] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31219] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31227] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31236] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31242] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31256] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31271] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31287] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31320] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31331] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31342] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31351] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31362] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31372] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31388] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31408] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31418] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31430] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31434] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31437] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31444] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31448] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31458] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31465] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31470] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31501] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31538] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31567] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31606] },
    { 0u, 0u, 60u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31631] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31692] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31729] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31731] },
    { 0u, 0u, 119u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31737] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31857] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31862] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31900] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31931] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31962] },
    { 0u, 0u, 91u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31974] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32066] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32070] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32082] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32087] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32114] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32141] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32158] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32163] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32209] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32244] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32293] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32319] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32323] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32327] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32330] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32335] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32340] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32347] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32358] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32374] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32380] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32392] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32401] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32444] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32450] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32458] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32514] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32531] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32566] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32628] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32638] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32660] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32671] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32691] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32711] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32760] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32776] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32803] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32826] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32859] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32878] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32899] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32945] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32961] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32984] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33023] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33046] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33061] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33086] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33113] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33147] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33162] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33214] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33244] },
    { 0u, 0u, 68u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33259] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33328] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33351] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33358] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33385] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33408] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33419] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33483] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33532] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33592] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33616] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33627] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33674] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33701] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33729] },
    { 0u, 0u, 70u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33757] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33828] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33835] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33843] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33852] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33903] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33905] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33909] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33921] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33925] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33933] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33944] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33952] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33959] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33966] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33973] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33980] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33987] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33995] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34002] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34010] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34018] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34030] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34034] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34037] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34043] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34053] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34081] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34095] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34114] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34130] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34145] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34165] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34179] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34194] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34210] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34216] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34224] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34269] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34310] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34351] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34385] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34396] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34417] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34456] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34485] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34497] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34509] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34545] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34557] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34572] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34628] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34670] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34708] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34715] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34720] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34735] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34750] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34806] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34820] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34856] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34862] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34876] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34879] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34883] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34891] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34906] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34913] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34921] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34928] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34934] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34938] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34949] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34963] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35014] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35053] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35061] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35073] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35082] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35089] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35095] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35103] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35111] },
    { 0u, 0u, 72u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35146] },
    { 0u, 0u, 67u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35219] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35287] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35332] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35351] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35402] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35445] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35454] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35462] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35469] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35479] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35488] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35496] },
    { 0u, 0u, 67u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35506] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35574] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35588] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35597] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35611] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35624] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35633] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35647] },
    { 0u, 0u, 62u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35656] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35719] },
    { 0u, 0u, 62u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35773] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35836] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35892] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35936] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35968] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36012] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36048] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36053] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36058] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36064] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36067] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36071] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36112] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36117] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36131] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36135] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36142] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36166] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36171] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36178] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36180] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36184] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36188] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36196] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36207] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36218] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36228] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36239] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36250] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36258] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36281] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36288] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36295] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36302] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36309] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36316] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36339] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36347] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36354] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36362] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36370] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36378] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36386] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36394] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36398] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36406] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36417] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36428] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36438] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36449] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36460] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36468] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36491] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36498] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36505] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36512] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36519] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36526] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36534] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36541] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36549] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36557] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36580] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36588] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36596] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36604] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36607] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36610] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36616] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36655] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36659] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36662] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36667] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36701] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36709] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36716] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36721] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36762] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36776] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36787] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36821] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36828] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36848] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36870] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36882] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36903] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36918] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36932] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36969] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37003] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37032] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37035] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37041] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37047] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37052] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37065] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37075] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37102] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37127] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37131] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37136] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37143] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37151] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37159] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37185] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37191] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37213] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37227] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37274] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37278] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37286] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37294] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37302] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37309] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37321] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37338] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37364] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37417] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37455] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37469] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37478] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37491] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37503] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37545] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37586] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37598] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37603] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37612] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37622] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37663] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37686] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37736] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37766] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37799] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37817] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37847] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37872] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37889] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37902] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37928] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37942] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37966] },
    { 0u, 0u, 81u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38004] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38086] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38101] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38104] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38119] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38156] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38169] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38175] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38186] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38221] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38239] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38283] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38333] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38380] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38407] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38412] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38423] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38434] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38443] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38453] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38462] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38512] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38540] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38566] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38568] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38574] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38583] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38592] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38601] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38613] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38622] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38630] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38638] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38648] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38657] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38663] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38670] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38676] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38690] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38700] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38706] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38712] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38721] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38729] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38739] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38747] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38757] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38766] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38774] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38783] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38785] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38840] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38859] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38866] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38875] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38905] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38909] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38916] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38954] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38958] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38964] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39012] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39021] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39030] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39039] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39049] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39063] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39077] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39091] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39099] },
    { 0u, 0u, 66u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39105] },
    { 0u, 0u, 71u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39172] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39244] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39276] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39288] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39298] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39308] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39318] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39358] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39363] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39368] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39374] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39393] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39451] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39458] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39461] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39465] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39467] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39472] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39493] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39557] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39591] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39604] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39630] },
    { 0u, 0u, 65u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39636] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39702] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39742] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39762] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39799] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39830] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39842] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39867] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39883] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39903] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39917] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39959] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39986] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40002] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40022] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40069] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40084] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40107] },
    { 0u, 0u, 81u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40130] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40212] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40246] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40278] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40314] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40347] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40379] },
    { 0u, 0u, 114u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40398] },
    { 0u, 0u, 87u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40513] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40601] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40607] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40620] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40634] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40655] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40677] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40724] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40742] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40768] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40796] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40837] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40856] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40860] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40867] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40893] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40947] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41000] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41041] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41053] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41070] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41120] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41124] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41129] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41169] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41223] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41272] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41315] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41319] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41326] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41341] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41382] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41386] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41392] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41403] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41419] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41427] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41432] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41453] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41458] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41480] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41528] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41584] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41610] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41627] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41639] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41660] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41689] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41713] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41728] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41738] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41771] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41792] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41845] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41861] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41886] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41934] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41956] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41965] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41973] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42033] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42038] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42049] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42053] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42060] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42064] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42071] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42081] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42110] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42136] },
    { 0u, 0u, 256u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42174] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42431] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42474] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42486] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42527] },
    { 0u, 0u, 64u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42575] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42640] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42650] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42662] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42674] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42686] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42731] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42734] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42763] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42769] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42776] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42798] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42804] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42808] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42817] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42819] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42822] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42828] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42847] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42853] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42864] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42876] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42905] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42913] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42938] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42946] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42955] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42963] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42978] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42996] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43001] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43015] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43020] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43032] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43045] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43065] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43073] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43116] },
    { 0u, 0u, 141u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43159] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43301] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43311] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43315] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43325] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43330] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43339] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43358] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43376] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43378] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43381] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43392] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43403] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43412] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43415] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43422] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43431] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43453] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43465] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43477] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43501] },
    { 0u, 0u, 78u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43511] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43590] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43595] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43647] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43651] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43660] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43667] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43674] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43723] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43772] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43781] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43840] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43897] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43901] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43913] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43962] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43998] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44023] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44066] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44115] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44124] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44131] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44138] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44146] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44152] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44159] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44167] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44178] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44195] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44207] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44264] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44272] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44280] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44306] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44311] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44318] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44333] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44335] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44338] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44343] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44353] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44372] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44387] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44403] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44409] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44414] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44465] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44506] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44513] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44531] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44549] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44566] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44601] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44605] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44611] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44668] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44680] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44684] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44691] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44696] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44704] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44717] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44749] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44756] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44763] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44771] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44777] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44790] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44796] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44804] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44817] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44825] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44831] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44856] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44879] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44886] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44923] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44928] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44940] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44953] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44973] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44979] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44985] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44992] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45000] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45010] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45026] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45042] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45051] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45066] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45082] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45101] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45112] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45129] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45145] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45155] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45196] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45231] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45270] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45306] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45346] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45363] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45381] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45396] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45421] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45454] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45485] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45520] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45550] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45585] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45618] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45656] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45671] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45696] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45719] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45739] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45763] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45785] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45807] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45830] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45854] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45876] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45885] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45894] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45899] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45910] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45918] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45928] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45944] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45954] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45964] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45980] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45991] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46006] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46021] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46036] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46045] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46094] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46101] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46121] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46158] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46196] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46253] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46268] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46281] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46291] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46300] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46310] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46334] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46361] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46388] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46421] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46436] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46454] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46467] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46478] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46490] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46497] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46504] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46512] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46552] },
    { 0u, 0u, 71u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46578] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46650] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46660] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46671] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46682] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46713] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46730] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46747] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46758] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46776] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46807] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46827] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46844] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46848] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46855] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46864] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46903] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46913] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46930] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46944] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46959] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46975] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46988] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46990] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46994] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47020] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47027] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47062] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47108] },
    { 0u, 0u, 60u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47113] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47174] },
    { 0u, 0u, 74u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47225] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47300] },
    { 0u, 0u, 82u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47331] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47414] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47465] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47478] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47493] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47551] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47565] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47577] },
    { 0u, 0u, 96u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47592] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47689] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47739] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47798] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47818] },
    { 0u, 0u, 146u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47871] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48018] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48032] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48050] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48060] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48072] },
    { 0u, 0u, 73u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48094] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48168] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48230] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48247] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48297] },
    { 0u, 0u, 69u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48361] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48431] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48457] },
    { 0u, 0u, 73u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48479] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48553] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48593] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48599] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48609] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48641] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48672] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48688] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48706] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48719] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48756] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48807] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48813] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48821] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48832] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48869] },
    { 0u, 0u, 97u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48889] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48987] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48992] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48996] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49002] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49047] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49097] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49102] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49140] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49154] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49171] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49212] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49232] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49262] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49273] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49284] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49295] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49311] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49366] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49395] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49406] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49416] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49427] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49438] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49449] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49460] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49470] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49504] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49514] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49548] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49556] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49579] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49587] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49596] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49612] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49614] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49617] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49639] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49648] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49652] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49656] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49664] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49687] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49694] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49701] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49708] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49715] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49723] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49746] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49754] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49758] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49766] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49789] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49796] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49803] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49810] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49817] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49825] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49848] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49856] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49859] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49863] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49872] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49881] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49890] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49898] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49908] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49916] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49938] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49955] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49983] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50004] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50028] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50045] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50051] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50059] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50087] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50108] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50123] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50140] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50163] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50187] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50205] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50210] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50222] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50239] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50261] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50284] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50302] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50324] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50345] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50354] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50373] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50400] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50431] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50451] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50471] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50491] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50519] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50566] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50612] },
    { 0u, 0u, 73u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50642] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50716] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50722] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50730] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50741] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50776] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50783] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50801] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50808] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50830] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50849] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50867] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50885] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50902] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50926] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50942] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50966] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50983] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51004] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51026] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51047] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51068] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51089] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51110] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51131] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51151] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51172] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51192] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51212] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51237] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51262] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51284] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51310] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51334] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51353] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51371] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51385] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51400] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51416] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51442] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51461] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51491] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51509] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51535] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51555] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51566] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51579] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51594] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51608] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51623] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51635] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51648] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51675] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51697] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51719] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51741] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51762] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51787] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51804] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51827] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51850] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51873] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51895] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51911] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51937] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51957] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51976] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51993] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52005] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52026] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52043] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52060] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52086] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52101] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52118] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52139] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52154] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52175] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52192] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52203] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52215] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52231] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52246] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52263] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52280] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52299] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52317] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52330] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52356] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52381] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52405] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52417] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52439] },
    { 0u, 0u, 119u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52458] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52578] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52598] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52610] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52641] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52671] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52700] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52714] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52733] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52749] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52765] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52782] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52796] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52819] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52840] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52862] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52886] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52912] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52933] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52951] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52981] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[52996] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53012] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53033] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53047] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53058] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53080] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53098] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53120] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53138] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53156] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53174] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53194] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53204] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53210] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53217] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53270] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53292] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53345] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53354] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53364] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53389] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53440] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53453] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53476] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53490] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53528] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53534] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53548] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53563] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53568] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53574] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53581] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53590] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53609] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53625] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53641] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53649] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53657] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53662] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53669] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53672] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53700] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53735] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53741] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53749] },
    { 0u, 0u, 117u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53786] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53904] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53935] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53943] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53955] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53961] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53969] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[53978] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54042] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54053] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54063] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54076] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54092] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54107] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54133] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54169] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54176] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54180] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54186] },
    { 0u, 0u, 62u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54217] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54280] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54282] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54285] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54288] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54292] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54296] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54303] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54311] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54321] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54323] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54326] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54328] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54331] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54343] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54352] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54356] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54358] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[54362] },
};

#define VADER_COMPTIME_ATOM_COUNT 2658u

/* Comptime data pool — read-only arrays in `.rodata`.
 * Out-of-arena pointers are immortal to the GC (it never copies /
 * relocates them), so `data.const` boxes a zero-copy view. */
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint64_t slots[1302]; } vader_data_0_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1302u, 1302u, 252u, 4u, { 0u, 0u, 0u },
    {
        (uint64_t) UINT64_C(17218479456385750618), (uint64_t) UINT64_C(1242899115359157055),
        (uint64_t) UINT64_C(10761549660241094136), (uint64_t) UINT64_C(5388497965526861063),
        (uint64_t) UINT64_C(13451937075301367670), (uint64_t) UINT64_C(6735622456908576329),
        (uint64_t) UINT64_C(16814921344126709587), (uint64_t) UINT64_C(17642900107990496220),
        (uint64_t) UINT64_C(10509325840079193492), (uint64_t) UINT64_C(8720969558280366185),
        (uint64_t) UINT64_C(13136657300098991865), (uint64_t) UINT64_C(10901211947850457732),
        (uint64_t) UINT64_C(16420821625123739831), (uint64_t) UINT64_C(18238200953240460069),
        (uint64_t) UINT64_C(10263013515702337394), (uint64_t) UINT64_C(18316404623416369399),
        (uint64_t) UINT64_C(12828766894627921743), (uint64_t) UINT64_C(13672133742415685941),
        (uint64_t) UINT64_C(16035958618284902179), (uint64_t) UINT64_C(12478481159592219522),
        (uint64_t) UINT64_C(10022474136428063862), (uint64_t) UINT64_C(5493207715531443249),
        (uint64_t) UINT64_C(12528092670535079827), (uint64_t) UINT64_C(16089881681269079869),
        (uint64_t) UINT64_C(15660115838168849784), (uint64_t) UINT64_C(15500666083158961933),
        (uint64_t) UINT64_C(9787572398855531115), (uint64_t) UINT64_C(9687916301974351208),
        (uint64_t) UINT64_C(12234465498569413894), (uint64_t) UINT64_C(7498209359040551106),
        (uint64_t) UINT64_C(15293081873211767368), (uint64_t) UINT64_C(149389661945913074),
        (uint64_t) UINT64_C(9558176170757354605), (uint64_t) UINT64_C(93368538716195671),
        (uint64_t) UINT64_C(11947720213446693256), (uint64_t) UINT64_C(4728396691822632493),
        (uint64_t) UINT64_C(14934650266808366570), (uint64_t) UINT64_C(5910495864778290617),
        (uint64_t) UINT64_C(9334156416755229106), (uint64_t) UINT64_C(8305745933913819539),
        (uint64_t) UINT64_C(11667695520944036383), (uint64_t) UINT64_C(1158810380537498616),
        (uint64_t) UINT64_C(14584619401180045478), (uint64_t) UINT64_C(15283571030954036982),
        (uint64_t) UINT64_C(18230774251475056848), (uint64_t) UINT64_C(9881091751837770420),
        (uint64_t) UINT64_C(11394233907171910530), (uint64_t) UINT64_C(6175682344898606512),
        (uint64_t) UINT64_C(14242792383964888162), (uint64_t) UINT64_C(16942974967978033949),
        (uint64_t) UINT64_C(17803490479956110203), (uint64_t) UINT64_C(11955346673117766628),
        (uint64_t) UINT64_C(11127181549972568877), (uint64_t) UINT64_C(5166248661484910190),
        (uint64_t) UINT64_C(13908976937465711096), (uint64_t) UINT64_C(11069496845283525642),
        (uint64_t) UINT64_C(17386221171832138870), (uint64_t) UINT64_C(13836871056604407053),
        (uint64_t) UINT64_C(10866388232395086794), (uint64_t) UINT64_C(4036358391950366504),
        (uint64_t) UINT64_C(13582985290493858492), (uint64_t) UINT64_C(14268820026792733938),
        (uint64_t) UINT64_C(16978731613117323115), (uint64_t) UINT64_C(17836025033490917422),
        (uint64_t) UINT64_C(10611707258198326947), (uint64_t) UINT64_C(8841672636718129437),
        (uint64_t) UINT64_C(13264634072747908684), (uint64_t) UINT64_C(6440404777470273892),
        (uint64_t) UINT64_C(16580792590934885855), (uint64_t) UINT64_C(8050505971837842365),
        (uint64_t) UINT64_C(10362995369334303659), (uint64_t) UINT64_C(11949095260039733334),
        (uint64_t) UINT64_C(12953744211667879574), (uint64_t) UINT64_C(10324683056622278764),
        (uint64_t) UINT64_C(16192180264584849468), (uint64_t) UINT64_C(3682481783923072647),
        (uint64_t) UINT64_C(10120112665365530917), (uint64_t) UINT64_C(11524923151806696212),
        (uint64_t) UINT64_C(12650140831706913647), (uint64_t) UINT64_C(571095884476206553),
        (uint64_t) UINT64_C(15812676039633642058), (uint64_t) UINT64_C(14548927910877421904),
        (uint64_t) UINT64_C(9882922524771026286), (uint64_t) UINT64_C(13704765962725776594),
        (uint64_t) UINT64_C(12353653155963782858), (uint64_t) UINT64_C(7907585416552444934),
        (uint64_t) UINT64_C(15442066444954728573), (uint64_t) UINT64_C(661109733835780360),
        (uint64_t) UINT64_C(9651291528096705358), (uint64_t) UINT64_C(2719036592861056677),
        (uint64_t) UINT64_C(12064114410120881697), (uint64_t) UINT64_C(12622167777931096654),
        (uint64_t) UINT64_C(15080143012651102122), (uint64_t) UINT64_C(1942651667131707105),
        (uint64_t) UINT64_C(9425089382906938826), (uint64_t) UINT64_C(5825843310384704845),
        (uint64_t) UINT64_C(11781361728633673532), (uint64_t) UINT64_C(16505676174835656864),
        (uint64_t) UINT64_C(14726702160792091916), (uint64_t) UINT64_C(2185351144835019464),
        (uint64_t) UINT64_C(18408377700990114895), (uint64_t) UINT64_C(2731688931043774330),
        (uint64_t) UINT64_C(11505236063118821809), (uint64_t) UINT64_C(8624834609543440812),
        (uint64_t) UINT64_C(14381545078898527261), (uint64_t) UINT64_C(15392729280356688919),
        (uint64_t) UINT64_C(17976931348623159077), (uint64_t) UINT64_C(5405853545163697437),
        (uint64_t) UINT64_C(11235582092889474423), (uint64_t) UINT64_C(5684501474941004850),
        (uint64_t) UINT64_C(14044477616111843029), (uint64_t) UINT64_C(2493940825248868159),
        (uint64_t) UINT64_C(17555597020139803786), (uint64_t) UINT64_C(7729112049988473103),
        (uint64_t) UINT64_C(10972248137587377366), (uint64_t) UINT64_C(9442381049670183593),
        (uint64_t) UINT64_C(13715310171984221708), (uint64_t) UINT64_C(2579604275232953683),
        (uint64_t) UINT64_C(17144137714980277135), (uint64_t) UINT64_C(3224505344041192104),
        (uint64_t) UINT64_C(10715086071862673209), (uint64_t) UINT64_C(8932844867666826921),
        (uint64_t) UINT64_C(13393857589828341511), (uint64_t) UINT64_C(15777742103010921555),
        (uint64_t) UINT64_C(16742321987285426889), (uint64_t) UINT64_C(15110491610336264040),
        (uint64_t) UINT64_C(10463951242053391806), (uint64_t) UINT64_C(2526528228819083169),
        (uint64_t) UINT64_C(13079939052566739757), (uint64_t) UINT64_C(12381532322878629770),
        (uint64_t) UINT64_C(16349923815708424697), (uint64_t) UINT64_C(1641857348316123500),
        (uint64_t) UINT64_C(10218702384817765435), (uint64_t) UINT64_C(12555375888766046947),
        (uint64_t) UINT64_C(12773377981022206794), (uint64_t) UINT64_C(11082533842530170780),
        (uint64_t) UINT64_C(15966722476277758493), (uint64_t) UINT64_C(4629795266307937667),
        (uint64_t) UINT64_C(9979201547673599058), (uint64_t) UINT64_C(5199465050656154994),
        (uint64_t) UINT64_C(12474001934591998822), (uint64_t) UINT64_C(15722703350174969551),
        (uint64_t) UINT64_C(15592502418239998528), (uint64_t) UINT64_C(10430007150863936130),
        (uint64_t) UINT64_C(9745314011399999080), (uint64_t) UINT64_C(6518754469289960081),
        (uint64_t) UINT64_C(12181642514249998850), (uint64_t) UINT64_C(8148443086612450102),
        (uint64_t) UINT64_C(15227053142812498563), (uint64_t) UINT64_C(962181821410786819),
        (uint64_t) UINT64_C(9516908214257811601), (uint64_t) UINT64_C(16742264702877599426),
        (uint64_t) UINT64_C(11896135267822264502), (uint64_t) UINT64_C(7092772823314835570),
        (uint64_t) UINT64_C(14870169084777830627), (uint64_t) UINT64_C(18089338065998320271),
        (uint64_t) UINT64_C(9293855677986144142), (uint64_t) UINT64_C(8999993282035256217),
        (uint64_t) UINT64_C(11617319597482680178), (uint64_t) UINT64_C(2026619565689294464),
        (uint64_t) UINT64_C(14521649496853350222), (uint64_t) UINT64_C(11756646493966393888),
        (uint64_t) UINT64_C(18152061871066687778), (uint64_t) UINT64_C(5472436080603216552),
        (uint64_t) UINT64_C(11345038669416679861), (uint64_t) UINT64_C(8031958568804398249),
        (uint64_t) UINT64_C(14181298336770849826), (uint64_t) UINT64_C(14651634229432885715),
        (uint64_t) UINT64_C(17726622920963562283), (uint64_t) UINT64_C(9091170749936331336),
        (uint64_t) UINT64_C(11079139325602226427), (uint64_t) UINT64_C(3376138709496513133),
        (uint64_t) UINT64_C(13848924157002783033), (uint64_t) UINT64_C(18055231442152805128),
        (uint64_t) UINT64_C(17311155196253478792), (uint64_t) UINT64_C(8733981247408842698),
        (uint64_t) UINT64_C(10819471997658424245), (uint64_t) UINT64_C(5458738279630526686),
        (uint64_t) UINT64_C(13524339997073030306), (uint64_t) UINT64_C(11435108867965546262),
        (uint64_t) UINT64_C(16905424996341287883), (uint64_t) UINT64_C(5070514048102157020),
        (uint64_t) UINT64_C(10565890622713304927), (uint64_t) UINT64_C(863228270850154185),
        (uint64_t) UINT64_C(13207363278391631158), (uint64_t) UINT64_C(14914093393844856443),
        (uint64_t) UINT64_C(16509204097989538948), (uint64_t) UINT64_C(9419244705451294746),
        (uint64_t) UINT64_C(10318252561243461842), (uint64_t) UINT64_C(15110399977761835024),
        (uint64_t) UINT64_C(12897815701554327303), (uint64_t) UINT64_C(9664627935347517973),
        (uint64_t) UINT64_C(16122269626942909129), (uint64_t) UINT64_C(7469098900757009562),
        (uint64_t) UINT64_C(10076418516839318205), (uint64_t) UINT64_C(16197401859041600736),
        (uint64_t) UINT64_C(12595523146049147757), (uint64_t) UINT64_C(6411694268519837208),
        (uint64_t) UINT64_C(15744403932561434696), (uint64_t) UINT64_C(12626303854077184414),
        (uint64_t) UINT64_C(9840252457850896685), (uint64_t) UINT64_C(7891439908798240259),
        (uint64_t) UINT64_C(12300315572313620856), (uint64_t) UINT64_C(14475985904425188227),
        (uint64_t) UINT64_C(15375394465392026070), (uint64_t) UINT64_C(18094982380531485284),
        (uint64_t) UINT64_C(9609621540870016294), (uint64_t) UINT64_C(6697677969404790399),
        (uint64_t) UINT64_C(12012026926087520367), (uint64_t) UINT64_C(17595469498610763806),
        (uint64_t) UINT64_C(15015033657609400459), (uint64_t) UINT64_C(17382650854836066854),
        (uint64_t) UINT64_C(9384396036005875287), (uint64_t) UINT64_C(8558313775058847832),
        (uint64_t) UINT64_C(11730495045007344109), (uint64_t) UINT64_C(6086206200396171886),
        (uint64_t) UINT64_C(14663118806259180136), (uint64_t) UINT64_C(12219443768922602761),
        (uint64_t) UINT64_C(18328898507823975170), (uint64_t) UINT64_C(15274304711153253452),
        (uint64_t) UINT64_C(11455561567389984481), (uint64_t) UINT64_C(14158126462898171311),
        (uint64_t) UINT64_C(14319451959237480602), (uint64_t) UINT64_C(3862600023340550427),
        (uint64_t) UINT64_C(17899314949046850752), (uint64_t) UINT64_C(14051622066030463842),
        (uint64_t) UINT64_C(11187071843154281720), (uint64_t) UINT64_C(8782263791269039901),
        (uint64_t) UINT64_C(13983839803942852150), (uint64_t) UINT64_C(10977829739086299876),
        (uint64_t) UINT64_C(17479799754928565188), (uint64_t) UINT64_C(4498915137003099037),
        (uint64_t) UINT64_C(10924874846830353242), (uint64_t) UINT64_C(12035193997481712706),
        (uint64_t) UINT64_C(13656093558537941553), (uint64_t) UINT64_C(5820620459997365075),
        (uint64_t) UINT64_C(17070116948172426941), (uint64_t) UINT64_C(11887461593424094248),
        (uint64_t) UINT64_C(10668823092607766838), (uint64_t) UINT64_C(9735506505103752857),
        (uint64_t) UINT64_C(13336028865759708548), (uint64_t) UINT64_C(2946011094524915263),
        (uint64_t) UINT64_C(16670036082199635685), (uint64_t) UINT64_C(3682513868156144079),
        (uint64_t) UINT64_C(10418772551374772303), (uint64_t) UINT64_C(4607414176811284001),
        (uint64_t) UINT64_C(13023465689218465379), (uint64_t) UINT64_C(1147581702586717097),
        (uint64_t) UINT64_C(16279332111523081723), (uint64_t) UINT64_C(15269535183515560084),
        (uint64_t) UINT64_C(10174582569701926077), (uint64_t) UINT64_C(7237616480483531100),
        (uint64_t) UINT64_C(12718228212127407596), (uint64_t) UINT64_C(13658706619031801779),
        (uint64_t) UINT64_C(15897785265159259495), (uint64_t) UINT64_C(17073383273789752224),
        (uint64_t) UINT64_C(9936115790724537184), (uint64_t) UINT64_C(17588393573759676996),
        (uint64_t) UINT64_C(12420144738405671481), (uint64_t) UINT64_C(3538747893490044629),
        (uint64_t) UINT64_C(15525180923007089351), (uint64_t) UINT64_C(9035120885289943691),
        (uint64_t) UINT64_C(9703238076879430844), (uint64_t) UINT64_C(12564479580947296663),
        (uint64_t) UINT64_C(12129047596099288555), (uint64_t) UINT64_C(15705599476184120828),
        (uint64_t) UINT64_C(15161309495124110694), (uint64_t) UINT64_C(15020313326802763131),
        (uint64_t) UINT64_C(9475818434452569184), (uint64_t) UINT64_C(4776009810824339053),
        (uint64_t) UINT64_C(11844773043065711480), (uint64_t) UINT64_C(5970012263530423816),
        (uint64_t) UINT64_C(14805966303832139350), (uint64_t) UINT64_C(7462515329413029771),
        (uint64_t) UINT64_C(9253728939895087094), (uint64_t) UINT64_C(52386062455755702),
        (uint64_t) UINT64_C(11567161174868858867), (uint64_t) UINT64_C(9288854614924470436),
        (uint64_t) UINT64_C(14458951468586073584), (uint64_t) UINT64_C(6999382250228200141),
        (uint64_t) UINT64_C(18073689335732591980), (uint64_t) UINT64_C(8749227812785250177),
        (uint64_t) UINT64_C(11296055834832869987), (uint64_t) UINT64_C(14691639419845557168),
        (uint64_t) UINT64_C(14120069793541087484), (uint64_t) UINT64_C(13752863256379558556),
        (uint64_t) UINT64_C(17650087241926359355), (uint64_t) UINT64_C(17191079070474448196),
        (uint64_t) UINT64_C(11031304526203974597), (uint64_t) UINT64_C(8438581409832836170),
        (uint64_t) UINT64_C(13789130657754968246), (uint64_t) UINT64_C(15159912780718433117),
        (uint64_t) UINT64_C(17236413322193710308), (uint64_t) UINT64_C(9726518939043265588),
        (uint64_t) UINT64_C(10772758326371068942), (uint64_t) UINT64_C(15302446373756816800),
        (uint64_t) UINT64_C(13465947907963836178), (uint64_t) UINT64_C(9904685930341245193),
        (uint64_t) UINT64_C(16832434884954795223), (uint64_t) UINT64_C(3157485376071780683),
        (uint64_t) UINT64_C(10520271803096747014), (uint64_t) UINT64_C(8890957387685944783),
        (uint64_t) UINT64_C(13150339753870933768), (uint64_t) UINT64_C(1890324697752655170),
        (uint64_t) UINT64_C(16437924692338667210), (uint64_t) UINT64_C(2362905872190818963),
        (uint64_t) UINT64_C(10273702932711667006), (uint64_t) UINT64_C(6088502188546649756),
        (uint64_t) UINT64_C(12842128665889583757), (uint64_t) UINT64_C(16833999772538088003),
        (uint64_t) UINT64_C(16052660832361979697), (uint64_t) UINT64_C(7207441660390446292),
        (uint64_t) UINT64_C(10032913020226237310), (uint64_t) UINT64_C(16033866083812498692),
        (uint64_t) UINT64_C(12541141275282796638), (uint64_t) UINT64_C(10818960567910847557),
        (uint64_t) UINT64_C(15676426594103495798), (uint64_t) UINT64_C(4300328673033783639),
        (uint64_t) UINT64_C(9797766621314684873), (uint64_t) UINT64_C(16522763475928278486),
        (uint64_t) UINT64_C(12247208276643356092), (uint64_t) UINT64_C(6818396289628184396),
        (uint64_t) UINT64_C(15309010345804195115), (uint64_t) UINT64_C(8522995362035230495),
        (uint64_t) UINT64_C(9568131466127621947), (uint64_t) UINT64_C(3021029092058325107),
        (uint64_t) UINT64_C(11960164332659527433), (uint64_t) UINT64_C(17611344420355070096),
        (uint64_t) UINT64_C(14950205415824409292), (uint64_t) UINT64_C(8179122470161673908),
        (uint64_t) UINT64_C(9343878384890255807), (uint64_t) UINT64_C(14335323580705822000),
        (uint64_t) UINT64_C(11679847981112819759), (uint64_t) UINT64_C(13307468457454889596),
        (uint64_t) UINT64_C(14599809976391024699), (uint64_t) UINT64_C(12022649553391224092),
        (uint64_t) UINT64_C(18249762470488780874), (uint64_t) UINT64_C(10416625923311642211),
        (uint64_t) UINT64_C(11406101544055488046), (uint64_t) UINT64_C(11122077220497164286),
        (uint64_t) UINT64_C(14257626930069360058), (uint64_t) UINT64_C(4679224488766679549),
        (uint64_t) UINT64_C(17822033662586700072), (uint64_t) UINT64_C(15072402647813125244),
        (uint64_t) UINT64_C(11138771039116687545), (uint64_t) UINT64_C(9420251654883203278),
        (uint64_t) UINT64_C(13923463798895859431), (uint64_t) UINT64_C(16387000587031392001),
        (uint64_t) UINT64_C(17404329748619824289), (uint64_t) UINT64_C(15872064715361852097),
        (uint64_t) UINT64_C(10877706092887390181), (uint64_t) UINT64_C(3002511419460075705),
        (uint64_t) UINT64_C(13597132616109237726), (uint64_t) UINT64_C(8364825292752482535),
        (uint64_t) UINT64_C(16996415770136547158), (uint64_t) UINT64_C(1232659579085827361),
        (uint64_t) UINT64_C(10622759856335341973), (uint64_t) UINT64_C(14605470292210805812),
        (uint64_t) UINT64_C(13278449820419177467), (uint64_t) UINT64_C(4421779809981343554),
        (uint64_t) UINT64_C(16598062275523971834), (uint64_t) UINT64_C(915538744049291538),
        (uint64_t) UINT64_C(10373788922202482396), (uint64_t) UINT64_C(5183897733458195115),
        (uint64_t) UINT64_C(12967236152753102995), (uint64_t) UINT64_C(6479872166822743894),
        (uint64_t) UINT64_C(16209045190941378744), (uint64_t) UINT64_C(3488154190101041964),
        (uint64_t) UINT64_C(10130653244338361715), (uint64_t) UINT64_C(2180096368813151227),
        (uint64_t) UINT64_C(12663316555422952143), (uint64_t) UINT64_C(16560178516298602746),
        (uint64_t) UINT64_C(15829145694278690179), (uint64_t) UINT64_C(16088537126945865529),
        (uint64_t) UINT64_C(9893216058924181362), (uint64_t) UINT64_C(7749492695127472003),
        (uint64_t) UINT64_C(12366520073655226703), (uint64_t) UINT64_C(463493832054564196),
        (uint64_t) UINT64_C(15458150092069033378), (uint64_t) UINT64_C(14414425345350368957),
        (uint64_t) UINT64_C(9661343807543145861), (uint64_t) UINT64_C(13620701859271368502),
        (uint64_t) UINT64_C(12076679759428932327), (uint64_t) UINT64_C(3190819268807046916),
        (uint64_t) UINT64_C(15095849699286165408), (uint64_t) UINT64_C(17823582141290972357),
        (uint64_t) UINT64_C(9434906062053853380), (uint64_t) UINT64_C(11139738838306857723),
        (uint64_t) UINT64_C(11793632577567316725), (uint64_t) UINT64_C(13924673547883572154),
        (uint64_t) UINT64_C(14742040721959145907), (uint64_t) UINT64_C(3570783879572301480),
        (uint64_t) UINT64_C(18427550902448932383), (uint64_t) UINT64_C(18298537904747540562),
        (uint64_t) UINT64_C(11517219314030582739), (uint64_t) UINT64_C(18354115218108294707),
        (uint64_t) UINT64_C(14396524142538228424), (uint64_t) UINT64_C(18330958004207980480),
        (uint64_t) UINT64_C(17995655178172785531), (uint64_t) UINT64_C(4466953431550423984),
        (uint64_t) UINT64_C(11247284486357990957), (uint64_t) UINT64_C(486002885505321038),
        (uint64_t) UINT64_C(14059105607947488696), (uint64_t) UINT64_C(5219189625309039202),
        (uint64_t) UINT64_C(17573882009934360870), (uint64_t) UINT64_C(6523987031636299002),
        (uint64_t) UINT64_C(10983676256208975543), (uint64_t) UINT64_C(17912549950054850588),
        (uint64_t) UINT64_C(13729595320261219429), (uint64_t) UINT64_C(17779001419141175331),
        (uint64_t) UINT64_C(17161994150326524287), (uint64_t) UINT64_C(8388693718644305452),
        (uint64_t) UINT64_C(10726246343954077679), (uint64_t) UINT64_C(12160462601793772764),
        (uint64_t) UINT64_C(13407807929942597099), (uint64_t) UINT64_C(10588892233814828051),
        (uint64_t) UINT64_C(16759759912428246374), (uint64_t) UINT64_C(8624429273841147159),
        (uint64_t) UINT64_C(10474849945267653984), (uint64_t) UINT64_C(778582277723329070),
        (uint64_t) UINT64_C(13093562431584567480), (uint64_t) UINT64_C(973227847154161338),
        (uint64_t) UINT64_C(16366953039480709350), (uint64_t) UINT64_C(1216534808942701673),
        (uint64_t) UINT64_C(10229345649675443343), (uint64_t) UINT64_C(14595392310871352257),
        (uint64_t) UINT64_C(12786682062094304179), (uint64_t) UINT64_C(13632554370161802418),
        (uint64_t) UINT64_C(15983352577617880224), (uint64_t) UINT64_C(12429006944274865118),
        (uint64_t) UINT64_C(9989595361011175140), (uint64_t) UINT64_C(7768129340171790699),
        (uint64_t) UINT64_C(12486994201263968925), (uint64_t) UINT64_C(9710161675214738374),
        (uint64_t) UINT64_C(15608742751579961156), (uint64_t) UINT64_C(16749388112445810871),
        (uint64_t) UINT64_C(9755464219737475723), (uint64_t) UINT64_C(1244995533423855986),
        (uint64_t) UINT64_C(12194330274671844653), (uint64_t) UINT64_C(15391302472061983695),
        (uint64_t) UINT64_C(15242912843339805817), (uint64_t) UINT64_C(5404070034795315907),
        (uint64_t) UINT64_C(9526820527087378635), (uint64_t) UINT64_C(14906758817815542202),
        (uint64_t) UINT64_C(11908525658859223294), (uint64_t) UINT64_C(14021762503842039848),
        (uint64_t) UINT64_C(14885657073574029118), (uint64_t) UINT64_C(8303831092947774002),
        (uint64_t) UINT64_C(9303535670983768199), (uint64_t) UINT64_C(578208414664970847),
        (uint64_t) UINT64_C(11629419588729710248), (uint64_t) UINT64_C(14557818573613377271),
        (uint64_t) UINT64_C(14536774485912137810), (uint64_t) UINT64_C(18197273217016721589),
        (uint64_t) UINT64_C(18170968107390172263), (uint64_t) UINT64_C(13523219484416126178),
        (uint64_t) UINT64_C(11356855067118857664), (uint64_t) UINT64_C(15369541205401160717),
        (uint64_t) UINT64_C(14196068833898572081), (uint64_t) UINT64_C(765182433041899281),
        (uint64_t) UINT64_C(17745086042373215101), (uint64_t) UINT64_C(5568164059729762005),
        (uint64_t) UINT64_C(11090678776483259438), (uint64_t) UINT64_C(5785945546544795205),
        (uint64_t) UINT64_C(13863348470604074297), (uint64_t) UINT64_C(16455803970035769814),
        (uint64_t) UINT64_C(17329185588255092872), (uint64_t) UINT64_C(6734696907262548556),
        (uint64_t) UINT64_C(10830740992659433045), (uint64_t) UINT64_C(4209185567039092847),
        (uint64_t) UINT64_C(13538426240824291306), (uint64_t) UINT64_C(9873167977226253963),
        (uint64_t) UINT64_C(16923032801030364133), (uint64_t) UINT64_C(3118087934678041646),
        (uint64_t) UINT64_C(10576895500643977583), (uint64_t) UINT64_C(4254647968387469981),
        (uint64_t) UINT64_C(13221119375804971979), (uint64_t) UINT64_C(706623942056949572),
        (uint64_t) UINT64_C(16526399219756214973), (uint64_t) UINT64_C(14718337982853350677),
        (uint64_t) UINT64_C(10328999512347634358), (uint64_t) UINT64_C(11504804248497038125),
        (uint64_t) UINT64_C(12911249390434542948), (uint64_t) UINT64_C(5157633273766521849),
        (uint64_t) UINT64_C(16139061738043178685), (uint64_t) UINT64_C(6447041592208152311),
        (uint64_t) UINT64_C(10086913586276986678), (uint64_t) UINT64_C(6335244004343789146),
        (uint64_t) UINT64_C(12608641982846233347), (uint64_t) UINT64_C(17142427042284512241),
        (uint64_t) UINT64_C(15760802478557791684), (uint64_t) UINT64_C(16816347784428252397),
        (uint64_t) UINT64_C(9850501549098619803), (uint64_t) UINT64_C(1286845328412881940),
        (uint64_t) UINT64_C(12313126936373274753), (uint64_t) UINT64_C(15443614715798266137),
        (uint64_t) UINT64_C(15391408670466593442), (uint64_t) UINT64_C(5469460339465668959),
        (uint64_t) UINT64_C(9619630419041620901), (uint64_t) UINT64_C(8030098730593431003),
        (uint64_t) UINT64_C(12024538023802026126), (uint64_t) UINT64_C(14649309431669176658),
        (uint64_t) UINT64_C(15030672529752532658), (uint64_t) UINT64_C(9088264752731695015),
        (uint64_t) UINT64_C(9394170331095332911), (uint64_t) UINT64_C(10291851488884697288),
        (uint64_t) UINT64_C(11742712913869166139), (uint64_t) UINT64_C(8253128342678483706),
        (uint64_t) UINT64_C(14678391142336457674), (uint64_t) UINT64_C(5704724409920716729),
        (uint64_t) UINT64_C(18347988927920572092), (uint64_t) UINT64_C(16354277549255671720),
        (uint64_t) UINT64_C(11467493079950357558), (uint64_t) UINT64_C(998051431430019017),
        (uint64_t) UINT64_C(14334366349937946947), (uint64_t) UINT64_C(10470936326142299579),
        (uint64_t) UINT64_C(17917957937422433684), (uint64_t) UINT64_C(8476984389250486570),
        (uint64_t) UINT64_C(11198723710889021052), (uint64_t) UINT64_C(14521487280136329914),
        (uint64_t) UINT64_C(13998404638611276315), (uint64_t) UINT64_C(18151859100170412392),
        (uint64_t) UINT64_C(17498005798264095394), (uint64_t) UINT64_C(18078137856785627587),
        (uint64_t) UINT64_C(10936253623915059621), (uint64_t) UINT64_C(15910522178918405146),
        (uint64_t) UINT64_C(13670317029893824527), (uint64_t) UINT64_C(6053094668365842720),
        (uint64_t) UINT64_C(17087896287367280659), (uint64_t) UINT64_C(2954682317029915496),
        (uint64_t) UINT64_C(10679935179604550411), (uint64_t) UINT64_C(17987577512639554849),
        (uint64_t) UINT64_C(13349918974505688014), (uint64_t) UINT64_C(17872785872372055657),
        (uint64_t) UINT64_C(16687398718132110018), (uint64_t) UINT64_C(13117610303610293764),
        (uint64_t) UINT64_C(10429624198832568761), (uint64_t) UINT64_C(12810192458183821506),
        (uint64_t) UINT64_C(13037030248540710952), (uint64_t) UINT64_C(2177682517447613171),
        (uint64_t) UINT64_C(16296287810675888690), (uint64_t) UINT64_C(2722103146809516464),
        (uint64_t) UINT64_C(10185179881672430431), (uint64_t) UINT64_C(6313000485183335694),
        (uint64_t) UINT64_C(12731474852090538039), (uint64_t) UINT64_C(3279564588051781713),
        (uint64_t) UINT64_C(15914343565113172548), (uint64_t) UINT64_C(17934513790346890853),
        (uint64_t) UINT64_C(9946464728195732843), (uint64_t) UINT64_C(1985699082112030975),
        (uint64_t) UINT64_C(12433080910244666053), (uint64_t) UINT64_C(16317181907922202431),
        (uint64_t) UINT64_C(15541351137805832567), (uint64_t) UINT64_C(6561419329620589327),
        (uint64_t) UINT64_C(9713344461128645354), (uint64_t) UINT64_C(11018416108653950185),
        (uint64_t) UINT64_C(12141680576410806693), (uint64_t) UINT64_C(4549648098962661924),
        (uint64_t) UINT64_C(15177100720513508366), (uint64_t) UINT64_C(10298746142130715309),
        (uint64_t) UINT64_C(9485687950320942729), (uint64_t) UINT64_C(1825030320404309164),
        (uint64_t) UINT64_C(11857109937901178411), (uint64_t) UINT64_C(6892973918932774359),
        (uint64_t) UINT64_C(14821387422376473014), (uint64_t) UINT64_C(4004531380238580045),
        (uint64_t) UINT64_C(9263367138985295633), (uint64_t) UINT64_C(16337890167931276240),
        (uint64_t) UINT64_C(11579208923731619542), (uint64_t) UINT64_C(6587304654631931588),
        (uint64_t) UINT64_C(14474011154664524427), (uint64_t) UINT64_C(17457502855144690293),
        (uint64_t) UINT64_C(18092513943330655534), (uint64_t) UINT64_C(17210192550503474962),
        (uint64_t) UINT64_C(11307821214581659709), (uint64_t) UINT64_C(6144684325637283947),
        (uint64_t) UINT64_C(14134776518227074636), (uint64_t) UINT64_C(12292541425473992838),
        (uint64_t) UINT64_C(17668470647783843295), (uint64_t) UINT64_C(15365676781842491048),
        (uint64_t) UINT64_C(11042794154864902059), (uint64_t) UINT64_C(16521077016292638761),
        (uint64_t) UINT64_C(13803492693581127574), (uint64_t) UINT64_C(16039660251938410547),
        (uint64_t) UINT64_C(17254365866976409468), (uint64_t) UINT64_C(10826203278068237376),
        (uint64_t) UINT64_C(10783978666860255917), (uint64_t) UINT64_C(15989749085647424168),
        (uint64_t) UINT64_C(13479973333575319897), (uint64_t) UINT64_C(6152128301777116498),
        (uint64_t) UINT64_C(16849966666969149871), (uint64_t) UINT64_C(12301846395648783526),
        (uint64_t) UINT64_C(10531229166855718669), (uint64_t) UINT64_C(14606183024921571560),
        (uint64_t) UINT64_C(13164036458569648337), (uint64_t) UINT64_C(4422670725869800738),
        (uint64_t) UINT64_C(16455045573212060421), (uint64_t) UINT64_C(10140024425764638826),
        (uint64_t) UINT64_C(10284403483257537763), (uint64_t) UINT64_C(8643358275316593218),
        (uint64_t) UINT64_C(12855504354071922204), (uint64_t) UINT64_C(6192511825718353619),
        (uint64_t) UINT64_C(16069380442589902755), (uint64_t) UINT64_C(7740639782147942024),
        (uint64_t) UINT64_C(10043362776618689222), (uint64_t) UINT64_C(2532056854628769813),
        (uint64_t) UINT64_C(12554203470773361527), (uint64_t) UINT64_C(12388443105140738074),
        (uint64_t) UINT64_C(15692754338466701909), (uint64_t) UINT64_C(10873867862998534689),
        (uint64_t) UINT64_C(9807971461541688693), (uint64_t) UINT64_C(9102010423587778132),
        (uint64_t) UINT64_C(12259964326927110866), (uint64_t) UINT64_C(15989199047912110569),
        (uint64_t) UINT64_C(15324955408658888583), (uint64_t) UINT64_C(10763126773035362404),
        (uint64_t) UINT64_C(9578097130411805364), (uint64_t) UINT64_C(13644483260788183358),
        (uint64_t) UINT64_C(11972621413014756705), (uint64_t) UINT64_C(17055604075985229198),
        (uint64_t) UINT64_C(14965776766268445882), (uint64_t) UINT64_C(7484447039699372786),
        (uint64_t) UINT64_C(9353610478917778676), (uint64_t) UINT64_C(9289465418239495895),
        (uint64_t) UINT64_C(11692013098647223345), (uint64_t) UINT64_C(11611831772799369869),
        (uint64_t) UINT64_C(14615016373309029182), (uint64_t) UINT64_C(679731660717048624),
        (uint64_t) UINT64_C(18268770466636286477), (uint64_t) UINT64_C(10073036612751086588),
        (uint64_t) UINT64_C(11417981541647679048), (uint64_t) UINT64_C(8601490892183123070),
        (uint64_t) UINT64_C(14272476927059598810), (uint64_t) UINT64_C(10751863615228903838),
        (uint64_t) UINT64_C(17840596158824498513), (uint64_t) UINT64_C(4216457482181353989),
        (uint64_t) UINT64_C(11150372599265311570), (uint64_t) UINT64_C(14164500972431816003),
        (uint64_t) UINT64_C(13937965749081639463), (uint64_t) UINT64_C(8482254178684994196),
        (uint64_t) UINT64_C(17422457186352049329), (uint64_t) UINT64_C(5991131704928854841),
        (uint64_t) UINT64_C(10889035741470030830), (uint64_t) UINT64_C(15273672361649004036),
        (uint64_t) UINT64_C(13611294676837538538), (uint64_t) UINT64_C(9868718415206479237),
        (uint64_t) UINT64_C(17014118346046923173), (uint64_t) UINT64_C(3112525982153323238),
        (uint64_t) UINT64_C(10633823966279326983), (uint64_t) UINT64_C(4251171748059520976),
        (uint64_t) UINT64_C(13292279957849158729), (uint64_t) UINT64_C(702278666647013315),
        (uint64_t) UINT64_C(16615349947311448411), (uint64_t) UINT64_C(5489534351736154548),
        (uint64_t) UINT64_C(10384593717069655257), (uint64_t) UINT64_C(1125115960621402641),
        (uint64_t) UINT64_C(12980742146337069071), (uint64_t) UINT64_C(6018080969204141205),
        (uint64_t) UINT64_C(16225927682921336339), (uint64_t) UINT64_C(2910915193077788602),
        (uint64_t) UINT64_C(10141204801825835211), (uint64_t) UINT64_C(17960223060169475540),
        (uint64_t) UINT64_C(12676506002282294014), (uint64_t) UINT64_C(17838592806784456521),
        (uint64_t) UINT64_C(15845632502852867518), (uint64_t) UINT64_C(13074868971625794844),
        (uint64_t) UINT64_C(9903520314283042199), (uint64_t) UINT64_C(3560107088838733873),
        (uint64_t) UINT64_C(12379400392853802748), (uint64_t) UINT64_C(18285191916330581054),
        (uint64_t) UINT64_C(15474250491067253436), (uint64_t) UINT64_C(4409745821703674701),
        (uint64_t) UINT64_C(9671406556917033397), (uint64_t) UINT64_C(11979463175419572496),
        (uint64_t) UINT64_C(12089258196146291747), (uint64_t) UINT64_C(1139270913992301908),
        (uint64_t) UINT64_C(15111572745182864683), (uint64_t) UINT64_C(15259146697772541097),
        (uint64_t) UINT64_C(9444732965739290427), (uint64_t) UINT64_C(7231123676894144234),
        (uint64_t) UINT64_C(11805916207174113034), (uint64_t) UINT64_C(4427218577690292388),
        (uint64_t) UINT64_C(14757395258967641292), (uint64_t) UINT64_C(14757395258967641293),
        (uint64_t) UINT64_C(9223372036854775808), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(11529215046068469760), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(14411518807585587200), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(18014398509481984000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(11258999068426240000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(14073748835532800000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(17592186044416000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(10995116277760000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(13743895347200000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(17179869184000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(10737418240000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(13421772800000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(16777216000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(10485760000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(13107200000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(16384000000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(10240000000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(12800000000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(16000000000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(10000000000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(12500000000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(15625000000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(9765625000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(12207031250000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(15258789062500000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(9536743164062500000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(11920928955078125000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(14901161193847656250), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(9313225746154785156), (uint64_t) UINT64_C(4611686018427387904),
        (uint64_t) UINT64_C(11641532182693481445), (uint64_t) UINT64_C(5764607523034234880),
        (uint64_t) UINT64_C(14551915228366851806), (uint64_t) UINT64_C(11817445422220181504),
        (uint64_t) UINT64_C(18189894035458564758), (uint64_t) UINT64_C(5548434740920451072),
        (uint64_t) UINT64_C(11368683772161602973), (uint64_t) UINT64_C(17302829768357445632),
        (uint64_t) UINT64_C(14210854715202003717), (uint64_t) UINT64_C(7793479155164643328),
        (uint64_t) UINT64_C(17763568394002504646), (uint64_t) UINT64_C(14353534962383192064),
        (uint64_t) UINT64_C(11102230246251565404), (uint64_t) UINT64_C(4359273333062107136),
        (uint64_t) UINT64_C(13877787807814456755), (uint64_t) UINT64_C(5449091666327633920),
        (uint64_t) UINT64_C(17347234759768070944), (uint64_t) UINT64_C(2199678564482154496),
        (uint64_t) UINT64_C(10842021724855044340), (uint64_t) UINT64_C(1374799102801346560),
        (uint64_t) UINT64_C(13552527156068805425), (uint64_t) UINT64_C(1718498878501683200),
        (uint64_t) UINT64_C(16940658945086006781), (uint64_t) UINT64_C(6759809616554491904),
        (uint64_t) UINT64_C(10587911840678754238), (uint64_t) UINT64_C(6530724019560251392),
        (uint64_t) UINT64_C(13234889800848442797), (uint64_t) UINT64_C(17386777061305090048),
        (uint64_t) UINT64_C(16543612251060553497), (uint64_t) UINT64_C(7898413271349198848),
        (uint64_t) UINT64_C(10339757656912845935), (uint64_t) UINT64_C(16465723340661719040),
        (uint64_t) UINT64_C(12924697071141057419), (uint64_t) UINT64_C(15970468157399760896),
        (uint64_t) UINT64_C(16155871338926321774), (uint64_t) UINT64_C(15351399178322313216),
        (uint64_t) UINT64_C(10097419586828951109), (uint64_t) UINT64_C(4982938468024057856),
        (uint64_t) UINT64_C(12621774483536188886), (uint64_t) UINT64_C(10840359103457460224),
        (uint64_t) UINT64_C(15777218104420236108), (uint64_t) UINT64_C(4327076842467049472),
        (uint64_t) UINT64_C(9860761315262647567), (uint64_t) UINT64_C(11927795063396681728),
        (uint64_t) UINT64_C(12325951644078309459), (uint64_t) UINT64_C(10298057810818464256),
        (uint64_t) UINT64_C(15407439555097886824), (uint64_t) UINT64_C(8260886245095692416),
        (uint64_t) UINT64_C(9629649721936179265), (uint64_t) UINT64_C(5163053903184807760),
        (uint64_t) UINT64_C(12037062152420224081), (uint64_t) UINT64_C(11065503397408397604),
        (uint64_t) UINT64_C(15046327690525280101), (uint64_t) UINT64_C(18443565265187884909),
        (uint64_t) UINT64_C(9403954806578300063), (uint64_t) UINT64_C(13833071299956122020),
        (uint64_t) UINT64_C(11754943508222875079), (uint64_t) UINT64_C(12679653106517764621),
        (uint64_t) UINT64_C(14693679385278593849), (uint64_t) UINT64_C(11237880364719817872),
        (uint64_t) UINT64_C(18367099231598242312), (uint64_t) UINT64_C(212292400617608628),
        (uint64_t) UINT64_C(11479437019748901445), (uint64_t) UINT64_C(132682750386005392),
        (uint64_t) UINT64_C(14349296274686126806), (uint64_t) UINT64_C(4777539456409894645),
        (uint64_t) UINT64_C(17936620343357658507), (uint64_t) UINT64_C(15195296357367144114),
        (uint64_t) UINT64_C(11210387714598536567), (uint64_t) UINT64_C(7191217214140771119),
        (uint64_t) UINT64_C(14012984643248170709), (uint64_t) UINT64_C(4377335499248575995),
        (uint64_t) UINT64_C(17516230804060213386), (uint64_t) UINT64_C(10083355392488107898),
        (uint64_t) UINT64_C(10947644252537633366), (uint64_t) UINT64_C(10913783138732455340),
        (uint64_t) UINT64_C(13684555315672041708), (uint64_t) UINT64_C(4418856886560793367),
        (uint64_t) UINT64_C(17105694144590052135), (uint64_t) UINT64_C(5523571108200991709),
        (uint64_t) UINT64_C(10691058840368782584), (uint64_t) UINT64_C(10369760970266701674),
        (uint64_t) UINT64_C(13363823550460978230), (uint64_t) UINT64_C(12962201212833377092),
        (uint64_t) UINT64_C(16704779438076222788), (uint64_t) UINT64_C(6979379479186945558),
        (uint64_t) UINT64_C(10440487148797639242), (uint64_t) UINT64_C(13585484211346616781),
        (uint64_t) UINT64_C(13050608935997049053), (uint64_t) UINT64_C(7758483227328495169),
        (uint64_t) UINT64_C(16313261169996311316), (uint64_t) UINT64_C(14309790052588006865),
        (uint64_t) UINT64_C(10195788231247694572), (uint64_t) UINT64_C(18166990819722280098),
        (uint64_t) UINT64_C(12744735289059618216), (uint64_t) UINT64_C(4261994450943298507),
        (uint64_t) UINT64_C(15930919111324522770), (uint64_t) UINT64_C(5327493063679123134),
        (uint64_t) UINT64_C(9956824444577826731), (uint64_t) UINT64_C(7941369183226839863),
        (uint64_t) UINT64_C(12446030555722283414), (uint64_t) UINT64_C(5315025460606161924),
        (uint64_t) UINT64_C(15557538194652854267), (uint64_t) UINT64_C(15867153862612478214),
        (uint64_t) UINT64_C(9723461371658033917), (uint64_t) UINT64_C(7611128154919104931),
        (uint64_t) UINT64_C(12154326714572542396), (uint64_t) UINT64_C(14125596212076269068),
        (uint64_t) UINT64_C(15192908393215677995), (uint64_t) UINT64_C(17656995265095336336),
        (uint64_t) UINT64_C(9495567745759798747), (uint64_t) UINT64_C(8729779031470891258),
        (uint64_t) UINT64_C(11869459682199748434), (uint64_t) UINT64_C(6300537770911226168),
        (uint64_t) UINT64_C(14836824602749685542), (uint64_t) UINT64_C(17099044250493808518),
        (uint64_t) UINT64_C(9273015376718553464), (uint64_t) UINT64_C(6075216638131242420),
        (uint64_t) UINT64_C(11591269220898191830), (uint64_t) UINT64_C(7594020797664053025),
        (uint64_t) UINT64_C(14489086526122739788), (uint64_t) UINT64_C(269153960225290473),
        (uint64_t) UINT64_C(18111358157653424735), (uint64_t) UINT64_C(336442450281613091),
        (uint64_t) UINT64_C(11319598848533390459), (uint64_t) UINT64_C(7127805559067090038),
        (uint64_t) UINT64_C(14149498560666738074), (uint64_t) UINT64_C(4298070930406474644),
        (uint64_t) UINT64_C(17686873200833422592), (uint64_t) UINT64_C(14595960699862869113),
        (uint64_t) UINT64_C(11054295750520889120), (uint64_t) UINT64_C(9122475437414293195),
        (uint64_t) UINT64_C(13817869688151111400), (uint64_t) UINT64_C(11403094296767866494),
        (uint64_t) UINT64_C(17272337110188889250), (uint64_t) UINT64_C(14253867870959833118),
        (uint64_t) UINT64_C(10795210693868055781), (uint64_t) UINT64_C(13520353437777283602),
        (uint64_t) UINT64_C(13494013367335069727), (uint64_t) UINT64_C(3065383741939440791),
        (uint64_t) UINT64_C(16867516709168837158), (uint64_t) UINT64_C(17666787732706464701),
        (uint64_t) UINT64_C(10542197943230523224), (uint64_t) UINT64_C(6430056314514152534),
        (uint64_t) UINT64_C(13177747429038154030), (uint64_t) UINT64_C(8037570393142690668),
        (uint64_t) UINT64_C(16472184286297692538), (uint64_t) UINT64_C(823590954573587527),
        (uint64_t) UINT64_C(10295115178936057836), (uint64_t) UINT64_C(5126430365035880108),
        (uint64_t) UINT64_C(12868893973670072295), (uint64_t) UINT64_C(6408037956294850135),
        (uint64_t) UINT64_C(16086117467087590369), (uint64_t) UINT64_C(3398361426941174765),
        (uint64_t) UINT64_C(10053823416929743980), (uint64_t) UINT64_C(13653190937906703988),
        (uint64_t) UINT64_C(12567279271162179975), (uint64_t) UINT64_C(17066488672383379985),
        (uint64_t) UINT64_C(15709099088952724969), (uint64_t) UINT64_C(16721424822051837077),
        (uint64_t) UINT64_C(9818186930595453106), (uint64_t) UINT64_C(3533361486141316317),
        (uint64_t) UINT64_C(12272733663244316382), (uint64_t) UINT64_C(13640073894531421205),
        (uint64_t) UINT64_C(15340917079055395478), (uint64_t) UINT64_C(7826720331309500698),
        (uint64_t) UINT64_C(9588073174409622174), (uint64_t) UINT64_C(280014188641050032),
        (uint64_t) UINT64_C(11985091468012027717), (uint64_t) UINT64_C(9573389772656088348),
        (uint64_t) UINT64_C(14981364335015034646), (uint64_t) UINT64_C(16578423234247498339),
        (uint64_t) UINT64_C(9363352709384396654), (uint64_t) UINT64_C(5749828502977298558),
        (uint64_t) UINT64_C(11704190886730495817), (uint64_t) UINT64_C(16410657665576399005),
        (uint64_t) UINT64_C(14630238608413119772), (uint64_t) UINT64_C(6678264026688335045),
        (uint64_t) UINT64_C(18287798260516399715), (uint64_t) UINT64_C(8347830033360418806),
        (uint64_t) UINT64_C(11429873912822749822), (uint64_t) UINT64_C(2911550761636567802),
        (uint64_t) UINT64_C(14287342391028437277), (uint64_t) UINT64_C(12862810488900485560),
        (uint64_t) UINT64_C(17859177988785546597), (uint64_t) UINT64_C(2243455055843443238),
        (uint64_t) UINT64_C(11161986242990966623), (uint64_t) UINT64_C(3708002419115845976),
        (uint64_t) UINT64_C(13952482803738708279), (uint64_t) UINT64_C(23317005467419566),
        (uint64_t) UINT64_C(17440603504673385348), (uint64_t) UINT64_C(13864204312116438170),
        (uint64_t) UINT64_C(10900377190420865842), (uint64_t) UINT64_C(17888499731927549664),
        (uint64_t) UINT64_C(13625471488026082303), (uint64_t) UINT64_C(13137252628054661272),
        (uint64_t) UINT64_C(17031839360032602879), (uint64_t) UINT64_C(11809879766640938686),
        (uint64_t) UINT64_C(10644899600020376799), (uint64_t) UINT64_C(14298703881791668535),
        (uint64_t) UINT64_C(13306124500025470999), (uint64_t) UINT64_C(13261693833812197764),
        (uint64_t) UINT64_C(16632655625031838749), (uint64_t) UINT64_C(11965431273837859301),
        (uint64_t) UINT64_C(10395409765644899218), (uint64_t) UINT64_C(9784237555362356015),
        (uint64_t) UINT64_C(12994262207056124023), (uint64_t) UINT64_C(3006924907348169211),
        (uint64_t) UINT64_C(16242827758820155028), (uint64_t) UINT64_C(17593714189467375226),
        (uint64_t) UINT64_C(10151767349262596893), (uint64_t) UINT64_C(1772699331562333708),
        (uint64_t) UINT64_C(12689709186578246116), (uint64_t) UINT64_C(6827560182880305039),
        (uint64_t) UINT64_C(15862136483222807645), (uint64_t) UINT64_C(8534450228600381299),
        (uint64_t) UINT64_C(9913835302014254778), (uint64_t) UINT64_C(7639874402088932264),
        (uint64_t) UINT64_C(12392294127517818473), (uint64_t) UINT64_C(326470965756389522),
        (uint64_t) UINT64_C(15490367659397273091), (uint64_t) UINT64_C(5019774725622874806),
        (uint64_t) UINT64_C(9681479787123295682), (uint64_t) UINT64_C(831516194300602802),
        (uint64_t) UINT64_C(12101849733904119602), (uint64_t) UINT64_C(10262767279730529310),
        (uint64_t) UINT64_C(15127312167380149503), (uint64_t) UINT64_C(3605087062808385830),
        (uint64_t) UINT64_C(9454570104612593439), (uint64_t) UINT64_C(9170708441896323000),
        (uint64_t) UINT64_C(11818212630765741799), (uint64_t) UINT64_C(6851699533943015846),
        (uint64_t) UINT64_C(14772765788457177249), (uint64_t) UINT64_C(3952938399001381903),
        (uint64_t) UINT64_C(9232978617785735780), (uint64_t) UINT64_C(13999801545444333449),
        (uint64_t) UINT64_C(11541223272232169725), (uint64_t) UINT64_C(17499751931805416812),
        (uint64_t) UINT64_C(14426529090290212157), (uint64_t) UINT64_C(8039631859474607303),
        (uint64_t) UINT64_C(18033161362862765196), (uint64_t) UINT64_C(14661225842770647033),
        (uint64_t) UINT64_C(11270725851789228247), (uint64_t) UINT64_C(18386638188586430203),
        (uint64_t) UINT64_C(14088407314736535309), (uint64_t) UINT64_C(18371611717305649850),
        (uint64_t) UINT64_C(17610509143420669137), (uint64_t) UINT64_C(9129456591349898601),
        (uint64_t) UINT64_C(11006568214637918210), (uint64_t) UINT64_C(17235125415662156385),
        (uint64_t) UINT64_C(13758210268297397763), (uint64_t) UINT64_C(12320534732722919674),
        (uint64_t) UINT64_C(17197762835371747204), (uint64_t) UINT64_C(10788982397476261688),
        (uint64_t) UINT64_C(10748601772107342002), (uint64_t) UINT64_C(15966486035277439363),
        (uint64_t) UINT64_C(13435752215134177503), (uint64_t) UINT64_C(10734735507242023396),
        (uint64_t) UINT64_C(16794690268917721879), (uint64_t) UINT64_C(8806733365625141341),
        (uint64_t) UINT64_C(10496681418073576174), (uint64_t) UINT64_C(12421737381156795194),
        (uint64_t) UINT64_C(13120851772591970218), (uint64_t) UINT64_C(6303799689591218185),
        (uint64_t) UINT64_C(16401064715739962772), (uint64_t) UINT64_C(17103121648843798539),
        (uint64_t) UINT64_C(10250665447337476733), (uint64_t) UINT64_C(1466078993672598279),
        (uint64_t) UINT64_C(12813331809171845916), (uint64_t) UINT64_C(6444284760518135752),
        (uint64_t) UINT64_C(16016664761464807395), (uint64_t) UINT64_C(8055355950647669691),
        (uint64_t) UINT64_C(10010415475915504622), (uint64_t) UINT64_C(2728754459941099604),
        (uint64_t) UINT64_C(12513019344894380777), (uint64_t) UINT64_C(12634315111781150314),
        (uint64_t) UINT64_C(15641274181117975972), (uint64_t) UINT64_C(1957835834444274180),
        (uint64_t) UINT64_C(9775796363198734982), (uint64_t) UINT64_C(10447019433382447170),
        (uint64_t) UINT64_C(12219745453998418728), (uint64_t) UINT64_C(3835402254873283155),
        (uint64_t) UINT64_C(15274681817498023410), (uint64_t) UINT64_C(4794252818591603944),
        (uint64_t) UINT64_C(9546676135936264631), (uint64_t) UINT64_C(7608094030047140369),
        (uint64_t) UINT64_C(11933345169920330789), (uint64_t) UINT64_C(4898431519131537557),
        (uint64_t) UINT64_C(14916681462400413486), (uint64_t) UINT64_C(10734725417341809851),
        (uint64_t) UINT64_C(9322925914000258429), (uint64_t) UINT64_C(2097517367411243253),
        (uint64_t) UINT64_C(11653657392500323036), (uint64_t) UINT64_C(7233582727691441970),
        (uint64_t) UINT64_C(14567071740625403795), (uint64_t) UINT64_C(9041978409614302462),
        (uint64_t) UINT64_C(18208839675781754744), (uint64_t) UINT64_C(6690786993590490174),
        (uint64_t) UINT64_C(11380524797363596715), (uint64_t) UINT64_C(4181741870994056359),
        (uint64_t) UINT64_C(14225655996704495894), (uint64_t) UINT64_C(615491320315182544),
        (uint64_t) UINT64_C(17782069995880619867), (uint64_t) UINT64_C(9992736187248753989),
        (uint64_t) UINT64_C(11113793747425387417), (uint64_t) UINT64_C(3939617107816777291),
        (uint64_t) UINT64_C(13892242184281734271), (uint64_t) UINT64_C(9536207403198359517),
        (uint64_t) UINT64_C(17365302730352167839), (uint64_t) UINT64_C(7308573235570561493),
        (uint64_t) UINT64_C(10853314206470104899), (uint64_t) UINT64_C(11485387299872682789),
        (uint64_t) UINT64_C(13566642758087631124), (uint64_t) UINT64_C(9745048106413465582),
        (uint64_t) UINT64_C(16958303447609538905), (uint64_t) UINT64_C(12181310133016831978),
        (uint64_t) UINT64_C(10598939654755961816), (uint64_t) UINT64_C(695789805494438130),
        (uint64_t) UINT64_C(13248674568444952270), (uint64_t) UINT64_C(869737256868047663),
        (uint64_t) UINT64_C(16560843210556190337), (uint64_t) UINT64_C(10310543607939835386),
        (uint64_t) UINT64_C(10350527006597618960), (uint64_t) UINT64_C(17973304801030866876),
        (uint64_t) UINT64_C(12938158758247023701), (uint64_t) UINT64_C(4019886927579031980),
        (uint64_t) UINT64_C(16172698447808779626), (uint64_t) UINT64_C(9636544677901177879),
        (uint64_t) UINT64_C(10107936529880487266), (uint64_t) UINT64_C(10634526442115624078),
        (uint64_t) UINT64_C(12634920662350609083), (uint64_t) UINT64_C(4069786015789754290),
        (uint64_t) UINT64_C(15793650827938261354), (uint64_t) UINT64_C(475546501309804958),
        (uint64_t) UINT64_C(9871031767461413346), (uint64_t) UINT64_C(4908902581746016003),
        (uint64_t) UINT64_C(12338789709326766682), (uint64_t) UINT64_C(15359500264037295811),
        (uint64_t) UINT64_C(15423487136658458353), (uint64_t) UINT64_C(9976003293191843956),
        (uint64_t) UINT64_C(9639679460411536470), (uint64_t) UINT64_C(17764217104313372233),
        (uint64_t) UINT64_C(12049599325514420588), (uint64_t) UINT64_C(12981899343536939483),
        (uint64_t) UINT64_C(15061999156893025735), (uint64_t) UINT64_C(16227374179421174354),
        (uint64_t) UINT64_C(9413749473058141084), (uint64_t) UINT64_C(17059637889779315827),
        (uint64_t) UINT64_C(11767186841322676356), (uint64_t) UINT64_C(2877803288514593168),
        (uint64_t) UINT64_C(14708983551653345445), (uint64_t) UINT64_C(3597254110643241460),
        (uint64_t) UINT64_C(18386229439566681806), (uint64_t) UINT64_C(9108253656731439729),
        (uint64_t) UINT64_C(11491393399729176129), (uint64_t) UINT64_C(1080972517029761926),
        (uint64_t) UINT64_C(14364241749661470161), (uint64_t) UINT64_C(5962901664714590312),
        (uint64_t) UINT64_C(17955302187076837701), (uint64_t) UINT64_C(12065313099320625794),
        (uint64_t) UINT64_C(11222063866923023563), (uint64_t) UINT64_C(9846663696289085073),
        (uint64_t) UINT64_C(14027579833653779454), (uint64_t) UINT64_C(7696643601933968437),
        (uint64_t) UINT64_C(17534474792067224318), (uint64_t) UINT64_C(397432465562684739),
        (uint64_t) UINT64_C(10959046745042015198), (uint64_t) UINT64_C(14083453346258841674),
        (uint64_t) UINT64_C(13698808431302518998), (uint64_t) UINT64_C(8380944645968776284),
        (uint64_t) UINT64_C(17123510539128148748), (uint64_t) UINT64_C(1252808770606194547),
        (uint64_t) UINT64_C(10702194086955092967), (uint64_t) UINT64_C(10006377518483647400),
        (uint64_t) UINT64_C(13377742608693866209), (uint64_t) UINT64_C(7896285879677171346),
        (uint64_t) UINT64_C(16722178260867332761), (uint64_t) UINT64_C(14482043368023852087),
        (uint64_t) UINT64_C(10451361413042082976), (uint64_t) UINT64_C(2133748077373825698),
        (uint64_t) UINT64_C(13064201766302603720), (uint64_t) UINT64_C(2667185096717282123),
        (uint64_t) UINT64_C(16330252207878254650), (uint64_t) UINT64_C(3333981370896602653),
        (uint64_t) UINT64_C(10206407629923909156), (uint64_t) UINT64_C(6695424375237764562),
        (uint64_t) UINT64_C(12758009537404886445), (uint64_t) UINT64_C(8369280469047205703),
        (uint64_t) UINT64_C(15947511921756108056), (uint64_t) UINT64_C(15073286604736395033),
        (uint64_t) UINT64_C(9967194951097567535), (uint64_t) UINT64_C(9420804127960246895),
        (uint64_t) UINT64_C(12458993688871959419), (uint64_t) UINT64_C(7164319141522920715),
        (uint64_t) UINT64_C(15573742111089949274), (uint64_t) UINT64_C(4343712908476262990),
        (uint64_t) UINT64_C(9733588819431218296), (uint64_t) UINT64_C(7326506586225052273),
        (uint64_t) UINT64_C(12166986024289022870), (uint64_t) UINT64_C(9158133232781315341),
        (uint64_t) UINT64_C(15208732530361278588), (uint64_t) UINT64_C(2224294504121868368),
        (uint64_t) UINT64_C(9505457831475799117), (uint64_t) UINT64_C(10613556101930943538),
        (uint64_t) UINT64_C(11881822289344748896), (uint64_t) UINT64_C(17878631145841067327),
        (uint64_t) UINT64_C(14852277861680936121), (uint64_t) UINT64_C(3901544858591782542),
        (uint64_t) UINT64_C(9282673663550585075), (uint64_t) UINT64_C(13967680582688333849),
        (uint64_t) UINT64_C(11603342079438231344), (uint64_t) UINT64_C(12847914709933029407),
        (uint64_t) UINT64_C(14504177599297789180), (uint64_t) UINT64_C(16059893387416286759),
        (uint64_t) UINT64_C(18130221999122236476), (uint64_t) UINT64_C(1628122660560806833),
        (uint64_t) UINT64_C(11331388749451397797), (uint64_t) UINT64_C(10240948699705280078),
        (uint64_t) UINT64_C(14164235936814247246), (uint64_t) UINT64_C(17412871893058988002),
        (uint64_t) UINT64_C(17705294921017809058), (uint64_t) UINT64_C(12542717829468959195),
        (uint64_t) UINT64_C(11065809325636130661), (uint64_t) UINT64_C(12450884661845487401),
        (uint64_t) UINT64_C(13832261657045163327), (uint64_t) UINT64_C(1728547772024695539),
        (uint64_t) UINT64_C(17290327071306454158), (uint64_t) UINT64_C(15995742770313033136),
        (uint64_t) UINT64_C(10806454419566533849), (uint64_t) UINT64_C(5385653213018257806),
        (uint64_t) UINT64_C(13508068024458167311), (uint64_t) UINT64_C(11343752534700210161),
        (uint64_t) UINT64_C(16885085030572709139), (uint64_t) UINT64_C(9568004649947874797),
        (uint64_t) UINT64_C(10553178144107943212), (uint64_t) UINT64_C(3674159897003727796),
        (uint64_t) UINT64_C(13191472680134929015), (uint64_t) UINT64_C(4592699871254659745),
        (uint64_t) UINT64_C(16489340850168661269), (uint64_t) UINT64_C(1129188820640936778),
        (uint64_t) UINT64_C(10305838031355413293), (uint64_t) UINT64_C(3011586022114279438),
        (uint64_t) UINT64_C(12882297539194266616), (uint64_t) UINT64_C(8376168546070237202),
        (uint64_t) UINT64_C(16102871923992833270), (uint64_t) UINT64_C(10470210682587796502),
        (uint64_t) UINT64_C(10064294952495520794), (uint64_t) UINT64_C(1932195658189984910),
        (uint64_t) UINT64_C(12580368690619400992), (uint64_t) UINT64_C(11638616609592256945),
        (uint64_t) UINT64_C(15725460863274251240), (uint64_t) UINT64_C(14548270761990321182),
        (uint64_t) UINT64_C(9828413039546407025), (uint64_t) UINT64_C(9092669226243950738),
        (uint64_t) UINT64_C(12285516299433008781), (uint64_t) UINT64_C(15977522551232326327),
        (uint64_t) UINT64_C(15356895374291260977), (uint64_t) UINT64_C(6136845133758244197),
        (uint64_t) UINT64_C(9598059608932038110), (uint64_t) UINT64_C(15364743254667372383),
        (uint64_t) UINT64_C(11997574511165047638), (uint64_t) UINT64_C(9982557031479439671),
        (uint64_t) UINT64_C(14996968138956309548), (uint64_t) UINT64_C(3254824252494523781),
        (uint64_t) UINT64_C(9373105086847693467), (uint64_t) UINT64_C(11257637194663853171),
        (uint64_t) UINT64_C(11716381358559616834), (uint64_t) UINT64_C(9460360474902428559),
        (uint64_t) UINT64_C(14645476698199521043), (uint64_t) UINT64_C(2602078556773259891),
        (uint64_t) UINT64_C(18306845872749401303), (uint64_t) UINT64_C(17087656251248738576),
        (uint64_t) UINT64_C(11441778670468375814), (uint64_t) UINT64_C(17597314184671543466),
        (uint64_t) UINT64_C(14302223338085469768), (uint64_t) UINT64_C(12773270693984653525),
        (uint64_t) UINT64_C(17877779172606837210), (uint64_t) UINT64_C(15966588367480816906),
        (uint64_t) UINT64_C(11173611982879273256), (uint64_t) UINT64_C(14590803748102898470),
        (uint64_t) UINT64_C(13967014978599091570), (uint64_t) UINT64_C(18238504685128623088),
        (uint64_t) UINT64_C(17458768723248864463), (uint64_t) UINT64_C(13574758819556003052),
        (uint64_t) UINT64_C(10911730452030540289), (uint64_t) UINT64_C(15401753289863583763),
        (uint64_t) UINT64_C(13639663065038175362), (uint64_t) UINT64_C(5417133557047315992),
        (uint64_t) UINT64_C(17049578831297719202), (uint64_t) UINT64_C(15994788983163920798),
        (uint64_t) UINT64_C(10655986769561074501), (uint64_t) UINT64_C(14608429132904838403),
        (uint64_t) UINT64_C(13319983461951343127), (uint64_t) UINT64_C(4425478360848884291),
        (uint64_t) UINT64_C(16649979327439178909), (uint64_t) UINT64_C(920161932633717460),
        (uint64_t) UINT64_C(10406237079649486818), (uint64_t) UINT64_C(2880944217109767365),
        (uint64_t) UINT64_C(13007796349561858522), (uint64_t) UINT64_C(12824552308241985014),
        (uint64_t) UINT64_C(16259745436952323153), (uint64_t) UINT64_C(6807318348447705459),
        (uint64_t) UINT64_C(10162340898095201970), (uint64_t) UINT64_C(15783789013848285672),
        (uint64_t) UINT64_C(12702926122619002463), (uint64_t) UINT64_C(10506364230455581282),
        (uint64_t) UINT64_C(15878657653273753079), (uint64_t) UINT64_C(8521269269642088699),
        (uint64_t) UINT64_C(9924161033296095674), (uint64_t) UINT64_C(12243322321167387293),
        (uint64_t) UINT64_C(12405201291620119593), (uint64_t) UINT64_C(6080780864604458308),
        (uint64_t) UINT64_C(15506501614525149491), (uint64_t) UINT64_C(12212662099182960789),
        (uint64_t) UINT64_C(9691563509078218432), (uint64_t) UINT64_C(5327070802775656541),
        (uint64_t) UINT64_C(12114454386347773040), (uint64_t) UINT64_C(6658838503469570676),
        (uint64_t) UINT64_C(15143067982934716300), (uint64_t) UINT64_C(8323548129336963345),
        (uint64_t) UINT64_C(9464417489334197687), (uint64_t) UINT64_C(14425589617690377899),
        (uint64_t) UINT64_C(11830521861667747109), (uint64_t) UINT64_C(13420301003685584469),
        (uint64_t) UINT64_C(14788152327084683887), (uint64_t) UINT64_C(2940318199324816875),
        (uint64_t) UINT64_C(9242595204427927429), (uint64_t) UINT64_C(8755227902219092403),
        (uint64_t) UINT64_C(11553244005534909286), (uint64_t) UINT64_C(15555720896201253407),
        (uint64_t) UINT64_C(14441555006918636608), (uint64_t) UINT64_C(10221279083396790951),
        (uint64_t) UINT64_C(18051943758648295760), (uint64_t) UINT64_C(12776598854245988689),
        (uint64_t) UINT64_C(11282464849155184850), (uint64_t) UINT64_C(7985374283903742931),
        (uint64_t) UINT64_C(14103081061443981063), (uint64_t) UINT64_C(758345818024902856),
        (uint64_t) UINT64_C(17628851326804976328), (uint64_t) UINT64_C(14782990327813292282),
        (uint64_t) UINT64_C(11018032079253110205), (uint64_t) UINT64_C(9239368954883307676),
        (uint64_t) UINT64_C(13772540099066387756), (uint64_t) UINT64_C(16160897212031522499),
        (uint64_t) UINT64_C(17215675123832984696), (uint64_t) UINT64_C(1754377441329851508),
        (uint64_t) UINT64_C(10759796952395615435), (uint64_t) UINT64_C(1096485900831157192),
        (uint64_t) UINT64_C(13449746190494519293), (uint64_t) UINT64_C(15205665431321110202),
        (uint64_t) UINT64_C(16812182738118149117), (uint64_t) UINT64_C(5172023733869224041),
        (uint64_t) UINT64_C(10507614211323843198), (uint64_t) UINT64_C(5538357842881958977),
        (uint64_t) UINT64_C(13134517764154803997), (uint64_t) UINT64_C(16146319340457224530),
        (uint64_t) UINT64_C(16418147205193504997), (uint64_t) UINT64_C(6347841120289366950),
        (uint64_t) UINT64_C(10261342003245940623), (uint64_t) UINT64_C(6273243709394548296),
    },
};
const vader_array_t vader_data_0 = {
    { 19u, 0u, 0u, 0u, NULL }, 1302u, 1302u, 0u, (vader_array_buf_t*) &vader_data_0_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint64_t slots[684]; } vader_data_1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 684u, 684u, 252u, 4u, { 0u, 0u, 0u },
    {
        (uint64_t) UINT64_C(1), (uint64_t) UINT64_C(2305843009213693952),
        (uint64_t) UINT64_C(11068046444225730970), (uint64_t) UINT64_C(1844674407370955161),
        (uint64_t) UINT64_C(5165088340638674453), (uint64_t) UINT64_C(1475739525896764129),
        (uint64_t) UINT64_C(7821419487252849886), (uint64_t) UINT64_C(1180591620717411303),
        (uint64_t) UINT64_C(8824922364862649494), (uint64_t) UINT64_C(1888946593147858085),
        (uint64_t) UINT64_C(7059937891890119595), (uint64_t) UINT64_C(1511157274518286468),
        (uint64_t) UINT64_C(13026647942995916322), (uint64_t) UINT64_C(1208925819614629174),
        (uint64_t) UINT64_C(9774590264567735146), (uint64_t) UINT64_C(1934281311383406679),
        (uint64_t) UINT64_C(11509021026396098440), (uint64_t) UINT64_C(1547425049106725343),
        (uint64_t) UINT64_C(16585914450600699399), (uint64_t) UINT64_C(1237940039285380274),
        (uint64_t) UINT64_C(15469416676735388068), (uint64_t) UINT64_C(1980704062856608439),
        (uint64_t) UINT64_C(16064882156130220778), (uint64_t) UINT64_C(1584563250285286751),
        (uint64_t) UINT64_C(9162556910162266299), (uint64_t) UINT64_C(1267650600228229401),
        (uint64_t) UINT64_C(7281393426775805432), (uint64_t) UINT64_C(2028240960365167042),
        (uint64_t) UINT64_C(16893161185646375315), (uint64_t) UINT64_C(1622592768292133633),
        (uint64_t) UINT64_C(2446482504291369283), (uint64_t) UINT64_C(1298074214633706907),
        (uint64_t) UINT64_C(7603720821608101175), (uint64_t) UINT64_C(2076918743413931051),
        (uint64_t) UINT64_C(2393627842544570617), (uint64_t) UINT64_C(1661534994731144841),
        (uint64_t) UINT64_C(16672297533003297786), (uint64_t) UINT64_C(1329227995784915872),
        (uint64_t) UINT64_C(11918280793837635165), (uint64_t) UINT64_C(2126764793255865396),
        (uint64_t) UINT64_C(5845275820328197809), (uint64_t) UINT64_C(1701411834604692317),
        (uint64_t) UINT64_C(15744267100488289217), (uint64_t) UINT64_C(1361129467683753853),
        (uint64_t) UINT64_C(3054734472329800808), (uint64_t) UINT64_C(2177807148294006166),
        (uint64_t) UINT64_C(17201182836831481939), (uint64_t) UINT64_C(1742245718635204932),
        (uint64_t) UINT64_C(6382248639981364905), (uint64_t) UINT64_C(1393796574908163946),
        (uint64_t) UINT64_C(2832900194486363201), (uint64_t) UINT64_C(2230074519853062314),
        (uint64_t) UINT64_C(5955668970331000884), (uint64_t) UINT64_C(1784059615882449851),
        (uint64_t) UINT64_C(1075186361522890384), (uint64_t) UINT64_C(1427247692705959881),
        (uint64_t) UINT64_C(12788344622662355584), (uint64_t) UINT64_C(2283596308329535809),
        (uint64_t) UINT64_C(13920024512871794791), (uint64_t) UINT64_C(1826877046663628647),
        (uint64_t) UINT64_C(3757321980813615186), (uint64_t) UINT64_C(1461501637330902918),
        (uint64_t) UINT64_C(10384555214134712795), (uint64_t) UINT64_C(1169201309864722334),
        (uint64_t) UINT64_C(5547241898389809503), (uint64_t) UINT64_C(1870722095783555735),
        (uint64_t) UINT64_C(4437793518711847602), (uint64_t) UINT64_C(1496577676626844588),
        (uint64_t) UINT64_C(10928932444453298728), (uint64_t) UINT64_C(1197262141301475670),
        (uint64_t) UINT64_C(17486291911125277965), (uint64_t) UINT64_C(1915619426082361072),
        (uint64_t) UINT64_C(6610335899416401726), (uint64_t) UINT64_C(1532495540865888858),
        (uint64_t) UINT64_C(12666966349016942027), (uint64_t) UINT64_C(1225996432692711086),
        (uint64_t) UINT64_C(12888448528943286597), (uint64_t) UINT64_C(1961594292308337738),
        (uint64_t) UINT64_C(17689456452638449924), (uint64_t) UINT64_C(1569275433846670190),
        (uint64_t) UINT64_C(14151565162110759939), (uint64_t) UINT64_C(1255420347077336152),
        (uint64_t) UINT64_C(7885109000409574610), (uint64_t) UINT64_C(2008672555323737844),
        (uint64_t) UINT64_C(9997436015069570011), (uint64_t) UINT64_C(1606938044258990275),
        (uint64_t) UINT64_C(7997948812055656009), (uint64_t) UINT64_C(1285550435407192220),
        (uint64_t) UINT64_C(12796718099289049614), (uint64_t) UINT64_C(2056880696651507552),
        (uint64_t) UINT64_C(2858676849947419045), (uint64_t) UINT64_C(1645504557321206042),
        (uint64_t) UINT64_C(13354987924183666206), (uint64_t) UINT64_C(1316403645856964833),
        (uint64_t) UINT64_C(17678631863951955605), (uint64_t) UINT64_C(2106245833371143733),
        (uint64_t) UINT64_C(3074859046935833515), (uint64_t) UINT64_C(1684996666696914987),
        (uint64_t) UINT64_C(13527933681774397782), (uint64_t) UINT64_C(1347997333357531989),
        (uint64_t) UINT64_C(10576647446613305481), (uint64_t) UINT64_C(2156795733372051183),
        (uint64_t) UINT64_C(15840015586774465031), (uint64_t) UINT64_C(1725436586697640946),
        (uint64_t) UINT64_C(8982663654677661702), (uint64_t) UINT64_C(1380349269358112757),
        (uint64_t) UINT64_C(18061610662226169046), (uint64_t) UINT64_C(2208558830972980411),
        (uint64_t) UINT64_C(10759939715039024913), (uint64_t) UINT64_C(1766847064778384329),
        (uint64_t) UINT64_C(12297300586773130254), (uint64_t) UINT64_C(1413477651822707463),
        (uint64_t) UINT64_C(15986332124095098083), (uint64_t) UINT64_C(2261564242916331941),
        (uint64_t) UINT64_C(9099716884534168143), (uint64_t) UINT64_C(1809251394333065553),
        (uint64_t) UINT64_C(14658471137111155161), (uint64_t) UINT64_C(1447401115466452442),
        (uint64_t) UINT64_C(4348079280205103483), (uint64_t) UINT64_C(1157920892373161954),
        (uint64_t) UINT64_C(14335624477811986218), (uint64_t) UINT64_C(1852673427797059126),
        (uint64_t) UINT64_C(7779150767507678651), (uint64_t) UINT64_C(1482138742237647301),
        (uint64_t) UINT64_C(2533971799264232598), (uint64_t) UINT64_C(1185710993790117841),
        (uint64_t) UINT64_C(15122401323048503126), (uint64_t) UINT64_C(1897137590064188545),
        (uint64_t) UINT64_C(12097921058438802501), (uint64_t) UINT64_C(1517710072051350836),
        (uint64_t) UINT64_C(5988988032009131678), (uint64_t) UINT64_C(1214168057641080669),
        (uint64_t) UINT64_C(16961078480698431330), (uint64_t) UINT64_C(1942668892225729070),
        (uint64_t) UINT64_C(13568862784558745064), (uint64_t) UINT64_C(1554135113780583256),
        (uint64_t) UINT64_C(7165741412905085728), (uint64_t) UINT64_C(1243308091024466605),
        (uint64_t) UINT64_C(11465186260648137165), (uint64_t) UINT64_C(1989292945639146568),
        (uint64_t) UINT64_C(16550846638002330379), (uint64_t) UINT64_C(1591434356511317254),
        (uint64_t) UINT64_C(16930026125143774626), (uint64_t) UINT64_C(1273147485209053803),
        (uint64_t) UINT64_C(4951948911778577463), (uint64_t) UINT64_C(2037035976334486086),
        (uint64_t) UINT64_C(272210314680951647), (uint64_t) UINT64_C(1629628781067588869),
        (uint64_t) UINT64_C(3907117066486671641), (uint64_t) UINT64_C(1303703024854071095),
        (uint64_t) UINT64_C(6251387306378674625), (uint64_t) UINT64_C(2085924839766513752),
        (uint64_t) UINT64_C(16069156289328670670), (uint64_t) UINT64_C(1668739871813211001),
        (uint64_t) UINT64_C(9165976216721026213), (uint64_t) UINT64_C(1334991897450568801),
        (uint64_t) UINT64_C(7286864317269821294), (uint64_t) UINT64_C(2135987035920910082),
        (uint64_t) UINT64_C(16897537898041588005), (uint64_t) UINT64_C(1708789628736728065),
        (uint64_t) UINT64_C(13518030318433270404), (uint64_t) UINT64_C(1367031702989382452),
        (uint64_t) UINT64_C(6871453250525591353), (uint64_t) UINT64_C(2187250724783011924),
        (uint64_t) UINT64_C(9186511415162383406), (uint64_t) UINT64_C(1749800579826409539),
        (uint64_t) UINT64_C(11038557946871817048), (uint64_t) UINT64_C(1399840463861127631),
        (uint64_t) UINT64_C(10282995085511086630), (uint64_t) UINT64_C(2239744742177804210),
        (uint64_t) UINT64_C(8226396068408869304), (uint64_t) UINT64_C(1791795793742243368),
        (uint64_t) UINT64_C(13959814484210916090), (uint64_t) UINT64_C(1433436634993794694),
        (uint64_t) UINT64_C(11267656730511734774), (uint64_t) UINT64_C(2293498615990071511),
        (uint64_t) UINT64_C(5324776569667477496), (uint64_t) UINT64_C(1834798892792057209),
        (uint64_t) UINT64_C(7949170070475892320), (uint64_t) UINT64_C(1467839114233645767),
        (uint64_t) UINT64_C(17427382500606444826), (uint64_t) UINT64_C(1174271291386916613),
        (uint64_t) UINT64_C(5747719112518849781), (uint64_t) UINT64_C(1878834066219066582),
        (uint64_t) UINT64_C(15666221734240810795), (uint64_t) UINT64_C(1503067252975253265),
        (uint64_t) UINT64_C(12532977387392648636), (uint64_t) UINT64_C(1202453802380202612),
        (uint64_t) UINT64_C(5295368560860596524), (uint64_t) UINT64_C(1923926083808324180),
        (uint64_t) UINT64_C(4236294848688477220), (uint64_t) UINT64_C(1539140867046659344),
        (uint64_t) UINT64_C(7078384693692692099), (uint64_t) UINT64_C(1231312693637327475),
        (uint64_t) UINT64_C(11325415509908307358), (uint64_t) UINT64_C(1970100309819723960),
        (uint64_t) UINT64_C(9060332407926645887), (uint64_t) UINT64_C(1576080247855779168),
        (uint64_t) UINT64_C(14626963555825137356), (uint64_t) UINT64_C(1260864198284623334),
        (uint64_t) UINT64_C(12335095245094488799), (uint64_t) UINT64_C(2017382717255397335),
        (uint64_t) UINT64_C(9868076196075591040), (uint64_t) UINT64_C(1613906173804317868),
        (uint64_t) UINT64_C(15273158586344293478), (uint64_t) UINT64_C(1291124939043454294),
        (uint64_t) UINT64_C(13369007293925138595), (uint64_t) UINT64_C(2065799902469526871),
        (uint64_t) UINT64_C(7005857020398200553), (uint64_t) UINT64_C(1652639921975621497),
        (uint64_t) UINT64_C(16672732060544291412), (uint64_t) UINT64_C(1322111937580497197),
        (uint64_t) UINT64_C(11918976037903224966), (uint64_t) UINT64_C(2115379100128795516),
        (uint64_t) UINT64_C(5845832015580669650), (uint64_t) UINT64_C(1692303280103036413),
        (uint64_t) UINT64_C(12055363241948356366), (uint64_t) UINT64_C(1353842624082429130),
        (uint64_t) UINT64_C(841837113407818570), (uint64_t) UINT64_C(2166148198531886609),
        (uint64_t) UINT64_C(4362818505468165179), (uint64_t) UINT64_C(1732918558825509287),
        (uint64_t) UINT64_C(14558301248600263113), (uint64_t) UINT64_C(1386334847060407429),
        (uint64_t) UINT64_C(12225235553534690011), (uint64_t) UINT64_C(2218135755296651887),
        (uint64_t) UINT64_C(2401490813343931363), (uint64_t) UINT64_C(1774508604237321510),
        (uint64_t) UINT64_C(1921192650675145090), (uint64_t) UINT64_C(1419606883389857208),
        (uint64_t) UINT64_C(17831303500047873437), (uint64_t) UINT64_C(2271371013423771532),
        (uint64_t) UINT64_C(6886345170554478103), (uint64_t) UINT64_C(1817096810739017226),
        (uint64_t) UINT64_C(1819727321701672159), (uint64_t) UINT64_C(1453677448591213781),
        (uint64_t) UINT64_C(16213177116328979020), (uint64_t) UINT64_C(1162941958872971024),
        (uint64_t) UINT64_C(14873036941900635463), (uint64_t) UINT64_C(1860707134196753639),
        (uint64_t) UINT64_C(15587778368262418694), (uint64_t) UINT64_C(1488565707357402911),
        (uint64_t) UINT64_C(8780873879868024632), (uint64_t) UINT64_C(1190852565885922329),
        (uint64_t) UINT64_C(2981351763563108441), (uint64_t) UINT64_C(1905364105417475727),
        (uint64_t) UINT64_C(13453127855076217722), (uint64_t) UINT64_C(1524291284333980581),
        (uint64_t) UINT64_C(7073153469319063855), (uint64_t) UINT64_C(1219433027467184465),
        (uint64_t) UINT64_C(11317045550910502167), (uint64_t) UINT64_C(1951092843947495144),
        (uint64_t) UINT64_C(12742985255470312057), (uint64_t) UINT64_C(1560874275157996115),
        (uint64_t) UINT64_C(10194388204376249646), (uint64_t) UINT64_C(1248699420126396892),
        (uint64_t) UINT64_C(1553625868034358140), (uint64_t) UINT64_C(1997919072202235028),
        (uint64_t) UINT64_C(8621598323911307159), (uint64_t) UINT64_C(1598335257761788022),
        (uint64_t) UINT64_C(17965325103354776697), (uint64_t) UINT64_C(1278668206209430417),
        (uint64_t) UINT64_C(13987124906400001422), (uint64_t) UINT64_C(2045869129935088668),
        (uint64_t) UINT64_C(121653480894270168), (uint64_t) UINT64_C(1636695303948070935),
        (uint64_t) UINT64_C(97322784715416134), (uint64_t) UINT64_C(1309356243158456748),
        (uint64_t) UINT64_C(14913111714512307107), (uint64_t) UINT64_C(2094969989053530796),
        (uint64_t) UINT64_C(8241140556867935363), (uint64_t) UINT64_C(1675975991242824637),
        (uint64_t) UINT64_C(17660958889720079260), (uint64_t) UINT64_C(1340780792994259709),
        (uint64_t) UINT64_C(17189487779326395846), (uint64_t) UINT64_C(2145249268790815535),
        (uint64_t) UINT64_C(13751590223461116677), (uint64_t) UINT64_C(1716199415032652428),
        (uint64_t) UINT64_C(18379969808252713988), (uint64_t) UINT64_C(1372959532026121942),
        (uint64_t) UINT64_C(14650556434236701088), (uint64_t) UINT64_C(2196735251241795108),
        (uint64_t) UINT64_C(652398703163629901), (uint64_t) UINT64_C(1757388200993436087),
        (uint64_t) UINT64_C(11589965406756634890), (uint64_t) UINT64_C(1405910560794748869),
        (uint64_t) UINT64_C(7475898206584884855), (uint64_t) UINT64_C(2249456897271598191),
        (uint64_t) UINT64_C(2291369750525997561), (uint64_t) UINT64_C(1799565517817278553),
        (uint64_t) UINT64_C(9211793429904618695), (uint64_t) UINT64_C(1439652414253822842),
        (uint64_t) UINT64_C(18428218302589300235), (uint64_t) UINT64_C(2303443862806116547),
        (uint64_t) UINT64_C(7363877012587619542), (uint64_t) UINT64_C(1842755090244893238),
        (uint64_t) UINT64_C(13269799239553916280), (uint64_t) UINT64_C(1474204072195914590),
        (uint64_t) UINT64_C(10615839391643133024), (uint64_t) UINT64_C(1179363257756731672),
        (uint64_t) UINT64_C(2227947767661371545), (uint64_t) UINT64_C(1886981212410770676),
        (uint64_t) UINT64_C(16539753473096738529), (uint64_t) UINT64_C(1509584969928616540),
        (uint64_t) UINT64_C(13231802778477390823), (uint64_t) UINT64_C(1207667975942893232),
        (uint64_t) UINT64_C(6413489186596184024), (uint64_t) UINT64_C(1932268761508629172),
        (uint64_t) UINT64_C(16198837793502678189), (uint64_t) UINT64_C(1545815009206903337),
        (uint64_t) UINT64_C(5580372605318321905), (uint64_t) UINT64_C(1236652007365522670),
        (uint64_t) UINT64_C(8928596168509315048), (uint64_t) UINT64_C(1978643211784836272),
        (uint64_t) UINT64_C(18210923379033183008), (uint64_t) UINT64_C(1582914569427869017),
        (uint64_t) UINT64_C(7190041073742725760), (uint64_t) UINT64_C(1266331655542295214),
        (uint64_t) UINT64_C(436019273762630246), (uint64_t) UINT64_C(2026130648867672343),
        (uint64_t) UINT64_C(7727513048493924843), (uint64_t) UINT64_C(1620904519094137874),
        (uint64_t) UINT64_C(9871359253537050198), (uint64_t) UINT64_C(1296723615275310299),
        (uint64_t) UINT64_C(4726128361433549347), (uint64_t) UINT64_C(2074757784440496479),
        (uint64_t) UINT64_C(7470251503888749801), (uint64_t) UINT64_C(1659806227552397183),
        (uint64_t) UINT64_C(13354898832594820487), (uint64_t) UINT64_C(1327844982041917746),
        (uint64_t) UINT64_C(13989140502667892133), (uint64_t) UINT64_C(2124551971267068394),
        (uint64_t) UINT64_C(14880661216876224029), (uint64_t) UINT64_C(1699641577013654715),
        (uint64_t) UINT64_C(11904528973500979224), (uint64_t) UINT64_C(1359713261610923772),
        (uint64_t) UINT64_C(4289851098633925465), (uint64_t) UINT64_C(2175541218577478036),
        (uint64_t) UINT64_C(18189276137874781665), (uint64_t) UINT64_C(1740432974861982428),
        (uint64_t) UINT64_C(3483374466074094362), (uint64_t) UINT64_C(1392346379889585943),
        (uint64_t) UINT64_C(1884050330976640656), (uint64_t) UINT64_C(2227754207823337509),
        (uint64_t) UINT64_C(5196589079523222848), (uint64_t) UINT64_C(1782203366258670007),
        (uint64_t) UINT64_C(15225317707844309248), (uint64_t) UINT64_C(1425762693006936005),
        (uint64_t) UINT64_C(5913764258841343181), (uint64_t) UINT64_C(2281220308811097609),
        (uint64_t) UINT64_C(8420360221814984868), (uint64_t) UINT64_C(1824976247048878087),
        (uint64_t) UINT64_C(17804334621677718864), (uint64_t) UINT64_C(1459980997639102469),
        (uint64_t) UINT64_C(17932816512084085415), (uint64_t) UINT64_C(1167984798111281975),
        (uint64_t) UINT64_C(10245762345624985047), (uint64_t) UINT64_C(1868775676978051161),
        (uint64_t) UINT64_C(4507261061758077715), (uint64_t) UINT64_C(1495020541582440929),
        (uint64_t) UINT64_C(7295157664148372495), (uint64_t) UINT64_C(1196016433265952743),
        (uint64_t) UINT64_C(7982903447895485668), (uint64_t) UINT64_C(1913626293225524389),
        (uint64_t) UINT64_C(10075671573058298858), (uint64_t) UINT64_C(1530901034580419511),
        (uint64_t) UINT64_C(4371188443704728763), (uint64_t) UINT64_C(1224720827664335609),
        (uint64_t) UINT64_C(14372599139411386667), (uint64_t) UINT64_C(1959553324262936974),
        (uint64_t) UINT64_C(15187428126271019657), (uint64_t) UINT64_C(1567642659410349579),
        (uint64_t) UINT64_C(15839291315758726049), (uint64_t) UINT64_C(1254114127528279663),
        (uint64_t) UINT64_C(3206773216762499739), (uint64_t) UINT64_C(2006582604045247462),
        (uint64_t) UINT64_C(13633465017635730761), (uint64_t) UINT64_C(1605266083236197969),
        (uint64_t) UINT64_C(14596120828850494932), (uint64_t) UINT64_C(1284212866588958375),
        (uint64_t) UINT64_C(4907049252451240275), (uint64_t) UINT64_C(2054740586542333401),
        (uint64_t) UINT64_C(236290587219081897), (uint64_t) UINT64_C(1643792469233866721),
        (uint64_t) UINT64_C(14946427728742906810), (uint64_t) UINT64_C(1315033975387093376),
        (uint64_t) UINT64_C(16535586736504830250), (uint64_t) UINT64_C(2104054360619349402),
        (uint64_t) UINT64_C(5849771759720043554), (uint64_t) UINT64_C(1683243488495479522),
        (uint64_t) UINT64_C(15747863852001765813), (uint64_t) UINT64_C(1346594790796383617),
        (uint64_t) UINT64_C(10439186904235184007), (uint64_t) UINT64_C(2154551665274213788),
        (uint64_t) UINT64_C(15730047152871967852), (uint64_t) UINT64_C(1723641332219371030),
        (uint64_t) UINT64_C(12584037722297574282), (uint64_t) UINT64_C(1378913065775496824),
        (uint64_t) UINT64_C(9066413911450387881), (uint64_t) UINT64_C(2206260905240794919),
        (uint64_t) UINT64_C(10942479943902220628), (uint64_t) UINT64_C(1765008724192635935),
        (uint64_t) UINT64_C(8753983955121776503), (uint64_t) UINT64_C(1412006979354108748),
        (uint64_t) UINT64_C(10317025513452932081), (uint64_t) UINT64_C(2259211166966573997),
        (uint64_t) UINT64_C(874922781278525018), (uint64_t) UINT64_C(1807368933573259198),
        (uint64_t) UINT64_C(8078635854506640661), (uint64_t) UINT64_C(1445895146858607358),
        (uint64_t) UINT64_C(13841606313089133175), (uint64_t) UINT64_C(1156716117486885886),
        (uint64_t) UINT64_C(14767872471458792434), (uint64_t) UINT64_C(1850745787979017418),
        (uint64_t) UINT64_C(746251532941302978), (uint64_t) UINT64_C(1480596630383213935),
        (uint64_t) UINT64_C(597001226353042382), (uint64_t) UINT64_C(1184477304306571148),
        (uint64_t) UINT64_C(15712597221132509104), (uint64_t) UINT64_C(1895163686890513836),
        (uint64_t) UINT64_C(8880728962164096960), (uint64_t) UINT64_C(1516130949512411069),
        (uint64_t) UINT64_C(10793931984473187891), (uint64_t) UINT64_C(1212904759609928855),
        (uint64_t) UINT64_C(17270291175157100626), (uint64_t) UINT64_C(1940647615375886168),
        (uint64_t) UINT64_C(2748186495899949531), (uint64_t) UINT64_C(1552518092300708935),
        (uint64_t) UINT64_C(2198549196719959625), (uint64_t) UINT64_C(1242014473840567148),
        (uint64_t) UINT64_C(18275073973719576693), (uint64_t) UINT64_C(1987223158144907436),
        (uint64_t) UINT64_C(10930710364233751031), (uint64_t) UINT64_C(1589778526515925949),
        (uint64_t) UINT64_C(12433917106128911148), (uint64_t) UINT64_C(1271822821212740759),
        (uint64_t) UINT64_C(8826220925580526867), (uint64_t) UINT64_C(2034916513940385215),
        (uint64_t) UINT64_C(7060976740464421494), (uint64_t) UINT64_C(1627933211152308172),
        (uint64_t) UINT64_C(16716827836597268165), (uint64_t) UINT64_C(1302346568921846537),
        (uint64_t) UINT64_C(11989529279587987770), (uint64_t) UINT64_C(2083754510274954460),
        (uint64_t) UINT64_C(9591623423670390216), (uint64_t) UINT64_C(1667003608219963568),
        (uint64_t) UINT64_C(15051996368420132820), (uint64_t) UINT64_C(1333602886575970854),
        (uint64_t) UINT64_C(13015147745246481542), (uint64_t) UINT64_C(2133764618521553367),
        (uint64_t) UINT64_C(3033420566713364587), (uint64_t) UINT64_C(1707011694817242694),
        (uint64_t) UINT64_C(6116085268112601993), (uint64_t) UINT64_C(1365609355853794155),
        (uint64_t) UINT64_C(9785736428980163188), (uint64_t) UINT64_C(2184974969366070648),
        (uint64_t) UINT64_C(15207286772667951197), (uint64_t) UINT64_C(1747979975492856518),
        (uint64_t) UINT64_C(1097782973908629988), (uint64_t) UINT64_C(1398383980394285215),
        (uint64_t) UINT64_C(1756452758253807981), (uint64_t) UINT64_C(2237414368630856344),
        (uint64_t) UINT64_C(5094511021344956708), (uint64_t) UINT64_C(1789931494904685075),
        (uint64_t) UINT64_C(4075608817075965366), (uint64_t) UINT64_C(1431945195923748060),
        (uint64_t) UINT64_C(6520974107321544586), (uint64_t) UINT64_C(2291112313477996896),
        (uint64_t) UINT64_C(1527430471115325346), (uint64_t) UINT64_C(1832889850782397517),
        (uint64_t) UINT64_C(12289990821117991246), (uint64_t) UINT64_C(1466311880625918013),
        (uint64_t) UINT64_C(17210690286378213644), (uint64_t) UINT64_C(1173049504500734410),
        (uint64_t) UINT64_C(9090360384495590213), (uint64_t) UINT64_C(1876879207201175057),
        (uint64_t) UINT64_C(18340334751822203140), (uint64_t) UINT64_C(1501503365760940045),
        (uint64_t) UINT64_C(14672267801457762512), (uint64_t) UINT64_C(1201202692608752036),
        (uint64_t) UINT64_C(16096930852848599373), (uint64_t) UINT64_C(1921924308174003258),
        (uint64_t) UINT64_C(1809498238053148529), (uint64_t) UINT64_C(1537539446539202607),
        (uint64_t) UINT64_C(12515645034668249793), (uint64_t) UINT64_C(1230031557231362085),
        (uint64_t) UINT64_C(1578287981759648052), (uint64_t) UINT64_C(1968050491570179337),
        (uint64_t) UINT64_C(12330676829633449412), (uint64_t) UINT64_C(1574440393256143469),
        (uint64_t) UINT64_C(13553890278448669853), (uint64_t) UINT64_C(1259552314604914775),
        (uint64_t) UINT64_C(3239480371808320148), (uint64_t) UINT64_C(2015283703367863641),
        (uint64_t) UINT64_C(17348979556414297411), (uint64_t) UINT64_C(1612226962694290912),
        (uint64_t) UINT64_C(6500486015647617283), (uint64_t) UINT64_C(1289781570155432730),
        (uint64_t) UINT64_C(10400777625036187652), (uint64_t) UINT64_C(2063650512248692368),
        (uint64_t) UINT64_C(15699319729512770768), (uint64_t) UINT64_C(1650920409798953894),
        (uint64_t) UINT64_C(16248804598352126938), (uint64_t) UINT64_C(1320736327839163115),
        (uint64_t) UINT64_C(7551343283653851484), (uint64_t) UINT64_C(2113178124542660985),
        (uint64_t) UINT64_C(6041074626923081187), (uint64_t) UINT64_C(1690542499634128788),
        (uint64_t) UINT64_C(12211557331022285596), (uint64_t) UINT64_C(1352433999707303030),
        (uint64_t) UINT64_C(1091747655926105338), (uint64_t) UINT64_C(2163894399531684849),
        (uint64_t) UINT64_C(4562746939482794594), (uint64_t) UINT64_C(1731115519625347879),
        (uint64_t) UINT64_C(7339546366328145998), (uint64_t) UINT64_C(1384892415700278303),
        (uint64_t) UINT64_C(8053925371383123274), (uint64_t) UINT64_C(2215827865120445285),
        (uint64_t) UINT64_C(6443140297106498619), (uint64_t) UINT64_C(1772662292096356228),
        (uint64_t) UINT64_C(12533209867169019542), (uint64_t) UINT64_C(1418129833677084982),
        (uint64_t) UINT64_C(5295740528502789974), (uint64_t) UINT64_C(2269007733883335972),
        (uint64_t) UINT64_C(15304638867027962949), (uint64_t) UINT64_C(1815206187106668777),
        (uint64_t) UINT64_C(4865013464138549713), (uint64_t) UINT64_C(1452164949685335022),
        (uint64_t) UINT64_C(14960057215536570740), (uint64_t) UINT64_C(1161731959748268017),
        (uint64_t) UINT64_C(9178696285890871890), (uint64_t) UINT64_C(1858771135597228828),
        (uint64_t) UINT64_C(14721654658196518159), (uint64_t) UINT64_C(1487016908477783062),
        (uint64_t) UINT64_C(4398626097073393881), (uint64_t) UINT64_C(1189613526782226450),
        (uint64_t) UINT64_C(7037801755317430209), (uint64_t) UINT64_C(1903381642851562320),
        (uint64_t) UINT64_C(5630241404253944167), (uint64_t) UINT64_C(1522705314281249856),
        (uint64_t) UINT64_C(814844308661245011), (uint64_t) UINT64_C(1218164251424999885),
        (uint64_t) UINT64_C(1303750893857992017), (uint64_t) UINT64_C(1949062802279999816),
        (uint64_t) UINT64_C(15800395974054034906), (uint64_t) UINT64_C(1559250241823999852),
        (uint64_t) UINT64_C(5261619149759407279), (uint64_t) UINT64_C(1247400193459199882),
        (uint64_t) UINT64_C(12107939454356961969), (uint64_t) UINT64_C(1995840309534719811),
        (uint64_t) UINT64_C(5997002748743659252), (uint64_t) UINT64_C(1596672247627775849),
        (uint64_t) UINT64_C(8486951013736837725), (uint64_t) UINT64_C(1277337798102220679),
        (uint64_t) UINT64_C(2511075177753209390), (uint64_t) UINT64_C(2043740476963553087),
        (uint64_t) UINT64_C(13076906586428298482), (uint64_t) UINT64_C(1634992381570842469),
        (uint64_t) UINT64_C(14150874083884549109), (uint64_t) UINT64_C(1307993905256673975),
        (uint64_t) UINT64_C(4194654460505726958), (uint64_t) UINT64_C(2092790248410678361),
        (uint64_t) UINT64_C(18113118827372222859), (uint64_t) UINT64_C(1674232198728542688),
        (uint64_t) UINT64_C(3422448617672047318), (uint64_t) UINT64_C(1339385758982834151),
        (uint64_t) UINT64_C(16543964232501006678), (uint64_t) UINT64_C(2143017214372534641),
        (uint64_t) UINT64_C(9545822571258895019), (uint64_t) UINT64_C(1714413771498027713),
        (uint64_t) UINT64_C(15015355686490936662), (uint64_t) UINT64_C(1371531017198422170),
        (uint64_t) UINT64_C(5577825024675947042), (uint64_t) UINT64_C(2194449627517475473),
        (uint64_t) UINT64_C(11840957649224578280), (uint64_t) UINT64_C(1755559702013980378),
        (uint64_t) UINT64_C(16851463748863483271), (uint64_t) UINT64_C(1404447761611184302),
        (uint64_t) UINT64_C(12204946739213931940), (uint64_t) UINT64_C(2247116418577894884),
        (uint64_t) UINT64_C(13453306206113055875), (uint64_t) UINT64_C(1797693134862315907),
        (uint64_t) UINT64_C(3383947335406624054), (uint64_t) UINT64_C(1438154507889852726),
        (uint64_t) UINT64_C(16482362180876329456), (uint64_t) UINT64_C(2301047212623764361),
        (uint64_t) UINT64_C(9496540929959153242), (uint64_t) UINT64_C(1840837770099011489),
        (uint64_t) UINT64_C(11286581558709232917), (uint64_t) UINT64_C(1472670216079209191),
        (uint64_t) UINT64_C(5339916432225476010), (uint64_t) UINT64_C(1178136172863367353),
        (uint64_t) UINT64_C(4854517476818851293), (uint64_t) UINT64_C(1885017876581387765),
        (uint64_t) UINT64_C(3883613981455081034), (uint64_t) UINT64_C(1508014301265110212),
        (uint64_t) UINT64_C(14174937629389795797), (uint64_t) UINT64_C(1206411441012088169),
        (uint64_t) UINT64_C(11611853762797942306), (uint64_t) UINT64_C(1930258305619341071),
        (uint64_t) UINT64_C(5600134195496443521), (uint64_t) UINT64_C(1544206644495472857),
        (uint64_t) UINT64_C(15548153800622885787), (uint64_t) UINT64_C(1235365315596378285),
        (uint64_t) UINT64_C(6430302007287065643), (uint64_t) UINT64_C(1976584504954205257),
        (uint64_t) UINT64_C(16212288050055383484), (uint64_t) UINT64_C(1581267603963364205),
        (uint64_t) UINT64_C(12969830440044306787), (uint64_t) UINT64_C(1265014083170691364),
        (uint64_t) UINT64_C(9683682259845159889), (uint64_t) UINT64_C(2024022533073106183),
        (uint64_t) UINT64_C(15125643437359948558), (uint64_t) UINT64_C(1619218026458484946),
        (uint64_t) UINT64_C(8411165935146048523), (uint64_t) UINT64_C(1295374421166787957),
        (uint64_t) UINT64_C(17147214310975587960), (uint64_t) UINT64_C(2072599073866860731),
        (uint64_t) UINT64_C(10028422634038560045), (uint64_t) UINT64_C(1658079259093488585),
        (uint64_t) UINT64_C(8022738107230848036), (uint64_t) UINT64_C(1326463407274790868),
        (uint64_t) UINT64_C(9147032156827446534), (uint64_t) UINT64_C(2122341451639665389),
        (uint64_t) UINT64_C(11006974540203867551), (uint64_t) UINT64_C(1697873161311732311),
        (uint64_t) UINT64_C(5116230817421183718), (uint64_t) UINT64_C(1358298529049385849),
        (uint64_t) UINT64_C(15564666937357714594), (uint64_t) UINT64_C(2173277646479017358),
        (uint64_t) UINT64_C(1383687105660440706), (uint64_t) UINT64_C(1738622117183213887),
        (uint64_t) UINT64_C(12174996128754083534), (uint64_t) UINT64_C(1390897693746571109),
        (uint64_t) UINT64_C(8411947361780802685), (uint64_t) UINT64_C(2225436309994513775),
        (uint64_t) UINT64_C(6729557889424642148), (uint64_t) UINT64_C(1780349047995611020),
        (uint64_t) UINT64_C(5383646311539713719), (uint64_t) UINT64_C(1424279238396488816),
        (uint64_t) UINT64_C(1235136468979721303), (uint64_t) UINT64_C(2278846781434382106),
        (uint64_t) UINT64_C(15745504434151418335), (uint64_t) UINT64_C(1823077425147505684),
        (uint64_t) UINT64_C(16285752362063044992), (uint64_t) UINT64_C(1458461940118004547),
        (uint64_t) UINT64_C(5649904260166615347), (uint64_t) UINT64_C(1166769552094403638),
        (uint64_t) UINT64_C(5350498001524674232), (uint64_t) UINT64_C(1866831283351045821),
        (uint64_t) UINT64_C(591049586477829062), (uint64_t) UINT64_C(1493465026680836657),
        (uint64_t) UINT64_C(11540886113407994219), (uint64_t) UINT64_C(1194772021344669325),
        (uint64_t) UINT64_C(18673707743239135), (uint64_t) UINT64_C(1911635234151470921),
        (uint64_t) UINT64_C(14772334225162232601), (uint64_t) UINT64_C(1529308187321176736),
        (uint64_t) UINT64_C(8128518565387875758), (uint64_t) UINT64_C(1223446549856941389),
        (uint64_t) UINT64_C(1937583260394870242), (uint64_t) UINT64_C(1957514479771106223),
        (uint64_t) UINT64_C(8928764237799716840), (uint64_t) UINT64_C(1566011583816884978),
        (uint64_t) UINT64_C(14521709019723594119), (uint64_t) UINT64_C(1252809267053507982),
        (uint64_t) UINT64_C(8477339172590109297), (uint64_t) UINT64_C(2004494827285612772),
        (uint64_t) UINT64_C(17849917782297818407), (uint64_t) UINT64_C(1603595861828490217),
        (uint64_t) UINT64_C(6901236596354434079), (uint64_t) UINT64_C(1282876689462792174),
        (uint64_t) UINT64_C(18420676183650915173), (uint64_t) UINT64_C(2052602703140467478),
        (uint64_t) UINT64_C(3668494502695001169), (uint64_t) UINT64_C(1642082162512373983),
        (uint64_t) UINT64_C(10313493231639821582), (uint64_t) UINT64_C(1313665730009899186),
        (uint64_t) UINT64_C(9122891541139893884), (uint64_t) UINT64_C(2101865168015838698),
        (uint64_t) UINT64_C(14677010862395735754), (uint64_t) UINT64_C(1681492134412670958),
        (uint64_t) UINT64_C(673562245690857633), (uint64_t) UINT64_C(1345193707530136767),
    },
};
const vader_array_t vader_data_1 = {
    { 19u, 0u, 0u, 0u, NULL }, 684u, 684u, 0u, (vader_array_buf_t*) &vader_data_1_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint64_t slots[652]; } vader_data_2_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 652u, 652u, 252u, 4u, { 0u, 0u, 0u },
    {
        (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(1152921504606846976), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1441151880758558720), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1801439850948198400), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(2251799813685248000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1407374883553280000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1759218604441600000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(2199023255552000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1374389534720000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1717986918400000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(2147483648000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1342177280000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1677721600000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(2097152000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1310720000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1638400000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(2048000000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1280000000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1600000000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(2000000000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1250000000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1562500000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1953125000000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1220703125000000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1525878906250000000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1907348632812500000), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1192092895507812500), (uint64_t) UINT64_C(0),
        (uint64_t) UINT64_C(1490116119384765625), (uint64_t) UINT64_C(4611686018427387904),
        (uint64_t) UINT64_C(1862645149230957031), (uint64_t) UINT64_C(9799832789158199296),
        (uint64_t) UINT64_C(1164153218269348144), (uint64_t) UINT64_C(12249790986447749120),
        (uint64_t) UINT64_C(1455191522836685180), (uint64_t) UINT64_C(15312238733059686400),
        (uint64_t) UINT64_C(1818989403545856475), (uint64_t) UINT64_C(14528612397897220096),
        (uint64_t) UINT64_C(2273736754432320594), (uint64_t) UINT64_C(13692068767113150464),
        (uint64_t) UINT64_C(1421085471520200371), (uint64_t) UINT64_C(12503399940464050176),
        (uint64_t) UINT64_C(1776356839400250464), (uint64_t) UINT64_C(15629249925580062720),
        (uint64_t) UINT64_C(2220446049250313080), (uint64_t) UINT64_C(9768281203487539200),
        (uint64_t) UINT64_C(1387778780781445675), (uint64_t) UINT64_C(7598665485932036096),
        (uint64_t) UINT64_C(1734723475976807094), (uint64_t) UINT64_C(274959820560269312),
        (uint64_t) UINT64_C(2168404344971008868), (uint64_t) UINT64_C(9395221924704944128),
        (uint64_t) UINT64_C(1355252715606880542), (uint64_t) UINT64_C(2520655369026404352),
        (uint64_t) UINT64_C(1694065894508600678), (uint64_t) UINT64_C(12374191248137781248),
        (uint64_t) UINT64_C(2117582368135750847), (uint64_t) UINT64_C(14651398557727195136),
        (uint64_t) UINT64_C(1323488980084844279), (uint64_t) UINT64_C(13702562178731606016),
        (uint64_t) UINT64_C(1654361225106055349), (uint64_t) UINT64_C(3293144668132343808),
        (uint64_t) UINT64_C(2067951531382569187), (uint64_t) UINT64_C(18199116482078572544),
        (uint64_t) UINT64_C(1292469707114105741), (uint64_t) UINT64_C(8913837547316051968),
        (uint64_t) UINT64_C(1615587133892632177), (uint64_t) UINT64_C(15753982952572452864),
        (uint64_t) UINT64_C(2019483917365790221), (uint64_t) UINT64_C(12152082354571476992),
        (uint64_t) UINT64_C(1262177448353618888), (uint64_t) UINT64_C(15190102943214346240),
        (uint64_t) UINT64_C(1577721810442023610), (uint64_t) UINT64_C(9764256642163156992),
        (uint64_t) UINT64_C(1972152263052529513), (uint64_t) UINT64_C(17631875447420442880),
        (uint64_t) UINT64_C(1232595164407830945), (uint64_t) UINT64_C(8204786253993389888),
        (uint64_t) UINT64_C(1540743955509788682), (uint64_t) UINT64_C(1032610780636961552),
        (uint64_t) UINT64_C(1925929944387235853), (uint64_t) UINT64_C(2951224747111794922),
        (uint64_t) UINT64_C(1203706215242022408), (uint64_t) UINT64_C(3689030933889743652),
        (uint64_t) UINT64_C(1504632769052528010), (uint64_t) UINT64_C(13834660704216955373),
        (uint64_t) UINT64_C(1880790961315660012), (uint64_t) UINT64_C(17870034976990372916),
        (uint64_t) UINT64_C(1175494350822287507), (uint64_t) UINT64_C(17725857702810578241),
        (uint64_t) UINT64_C(1469367938527859384), (uint64_t) UINT64_C(3710578054803671186),
        (uint64_t) UINT64_C(1836709923159824231), (uint64_t) UINT64_C(26536550077201078),
        (uint64_t) UINT64_C(2295887403949780289), (uint64_t) UINT64_C(11545800389866720434),
        (uint64_t) UINT64_C(1434929627468612680), (uint64_t) UINT64_C(14432250487333400542),
        (uint64_t) UINT64_C(1793662034335765850), (uint64_t) UINT64_C(8816941072311974870),
        (uint64_t) UINT64_C(2242077542919707313), (uint64_t) UINT64_C(17039803216263454053),
        (uint64_t) UINT64_C(1401298464324817070), (uint64_t) UINT64_C(12076381983474541759),
        (uint64_t) UINT64_C(1751623080406021338), (uint64_t) UINT64_C(5872105442488401391),
        (uint64_t) UINT64_C(2189528850507526673), (uint64_t) UINT64_C(15199280947623720629),
        (uint64_t) UINT64_C(1368455531567204170), (uint64_t) UINT64_C(9775729147674874978),
        (uint64_t) UINT64_C(1710569414459005213), (uint64_t) UINT64_C(16831347453020981627),
        (uint64_t) UINT64_C(2138211768073756516), (uint64_t) UINT64_C(1296220121283337709),
        (uint64_t) UINT64_C(1336382355046097823), (uint64_t) UINT64_C(15455333206886335848),
        (uint64_t) UINT64_C(1670477943807622278), (uint64_t) UINT64_C(10095794471753144002),
        (uint64_t) UINT64_C(2088097429759527848), (uint64_t) UINT64_C(6309871544845715001),
        (uint64_t) UINT64_C(1305060893599704905), (uint64_t) UINT64_C(12499025449484531656),
        (uint64_t) UINT64_C(1631326116999631131), (uint64_t) UINT64_C(11012095793428276666),
        (uint64_t) UINT64_C(2039157646249538914), (uint64_t) UINT64_C(11494245889320060820),
        (uint64_t) UINT64_C(1274473528905961821), (uint64_t) UINT64_C(532749306367912313),
        (uint64_t) UINT64_C(1593091911132452277), (uint64_t) UINT64_C(5277622651387278295),
        (uint64_t) UINT64_C(1991364888915565346), (uint64_t) UINT64_C(7910200175544436838),
        (uint64_t) UINT64_C(1244603055572228341), (uint64_t) UINT64_C(14499436237857933952),
        (uint64_t) UINT64_C(1555753819465285426), (uint64_t) UINT64_C(8900923260467641632),
        (uint64_t) UINT64_C(1944692274331606783), (uint64_t) UINT64_C(12480606065433357876),
        (uint64_t) UINT64_C(1215432671457254239), (uint64_t) UINT64_C(10989071563364309441),
        (uint64_t) UINT64_C(1519290839321567799), (uint64_t) UINT64_C(9124653435777998898),
        (uint64_t) UINT64_C(1899113549151959749), (uint64_t) UINT64_C(8008751406574943263),
        (uint64_t) UINT64_C(1186945968219974843), (uint64_t) UINT64_C(5399253239791291175),
        (uint64_t) UINT64_C(1483682460274968554), (uint64_t) UINT64_C(15972438586593889776),
        (uint64_t) UINT64_C(1854603075343710692), (uint64_t) UINT64_C(759402079766405302),
        (uint64_t) UINT64_C(1159126922089819183), (uint64_t) UINT64_C(14784310654990170340),
        (uint64_t) UINT64_C(1448908652612273978), (uint64_t) UINT64_C(9257016281882937117),
        (uint64_t) UINT64_C(1811135815765342473), (uint64_t) UINT64_C(16182956370781059300),
        (uint64_t) UINT64_C(2263919769706678091), (uint64_t) UINT64_C(7808504722524468110),
        (uint64_t) UINT64_C(1414949856066673807), (uint64_t) UINT64_C(5148944884728197234),
        (uint64_t) UINT64_C(1768687320083342259), (uint64_t) UINT64_C(1824495087482858639),
        (uint64_t) UINT64_C(2210859150104177824), (uint64_t) UINT64_C(1140309429676786649),
        (uint64_t) UINT64_C(1381786968815111140), (uint64_t) UINT64_C(1425386787095983311),
        (uint64_t) UINT64_C(1727233711018888925), (uint64_t) UINT64_C(6393419502297367043),
        (uint64_t) UINT64_C(2159042138773611156), (uint64_t) UINT64_C(13219259225790630210),
        (uint64_t) UINT64_C(1349401336733506972), (uint64_t) UINT64_C(16524074032238287762),
        (uint64_t) UINT64_C(1686751670916883715), (uint64_t) UINT64_C(16043406521870471799),
        (uint64_t) UINT64_C(2108439588646104644), (uint64_t) UINT64_C(803757039314269066),
        (uint64_t) UINT64_C(1317774742903815403), (uint64_t) UINT64_C(14839754354425000045),
        (uint64_t) UINT64_C(1647218428629769253), (uint64_t) UINT64_C(4714634887749086344),
        (uint64_t) UINT64_C(2059023035787211567), (uint64_t) UINT64_C(9864175832484260821),
        (uint64_t) UINT64_C(1286889397367007229), (uint64_t) UINT64_C(16941905809032713930),
        (uint64_t) UINT64_C(1608611746708759036), (uint64_t) UINT64_C(2730638187581340797),
        (uint64_t) UINT64_C(2010764683385948796), (uint64_t) UINT64_C(10930020904093113806),
        (uint64_t) UINT64_C(1256727927116217997), (uint64_t) UINT64_C(18274212148543780162),
        (uint64_t) UINT64_C(1570909908895272496), (uint64_t) UINT64_C(4396021111970173586),
        (uint64_t) UINT64_C(1963637386119090621), (uint64_t) UINT64_C(5053356204195052443),
        (uint64_t) UINT64_C(1227273366324431638), (uint64_t) UINT64_C(15540067292098591362),
        (uint64_t) UINT64_C(1534091707905539547), (uint64_t) UINT64_C(14813398096695851299),
        (uint64_t) UINT64_C(1917614634881924434), (uint64_t) UINT64_C(13870059828862294966),
        (uint64_t) UINT64_C(1198509146801202771), (uint64_t) UINT64_C(12725888767650480803),
        (uint64_t) UINT64_C(1498136433501503464), (uint64_t) UINT64_C(15907360959563101004),
        (uint64_t) UINT64_C(1872670541876879330), (uint64_t) UINT64_C(14553786618154326031),
        (uint64_t) UINT64_C(1170419088673049581), (uint64_t) UINT64_C(4357175217410743827),
        (uint64_t) UINT64_C(1463023860841311977), (uint64_t) UINT64_C(10058155040190817688),
        (uint64_t) UINT64_C(1828779826051639971), (uint64_t) UINT64_C(7961007781811134206),
        (uint64_t) UINT64_C(2285974782564549964), (uint64_t) UINT64_C(14199001900486734687),
        (uint64_t) UINT64_C(1428734239102843727), (uint64_t) UINT64_C(13137066357181030455),
        (uint64_t) UINT64_C(1785917798878554659), (uint64_t) UINT64_C(11809646928048900164),
        (uint64_t) UINT64_C(2232397248598193324), (uint64_t) UINT64_C(16604401366885338411),
        (uint64_t) UINT64_C(1395248280373870827), (uint64_t) UINT64_C(16143815690179285109),
        (uint64_t) UINT64_C(1744060350467338534), (uint64_t) UINT64_C(10956397575869330579),
        (uint64_t) UINT64_C(2180075438084173168), (uint64_t) UINT64_C(6847748484918331612),
        (uint64_t) UINT64_C(1362547148802608230), (uint64_t) UINT64_C(17783057643002690323),
        (uint64_t) UINT64_C(1703183936003260287), (uint64_t) UINT64_C(17617136035325974999),
        (uint64_t) UINT64_C(2128979920004075359), (uint64_t) UINT64_C(17928239049719816230),
        (uint64_t) UINT64_C(1330612450002547099), (uint64_t) UINT64_C(17798612793722382384),
        (uint64_t) UINT64_C(1663265562503183874), (uint64_t) UINT64_C(13024893955298202172),
        (uint64_t) UINT64_C(2079081953128979843), (uint64_t) UINT64_C(5834715712847682405),
        (uint64_t) UINT64_C(1299426220705612402), (uint64_t) UINT64_C(16516766677914378815),
        (uint64_t) UINT64_C(1624282775882015502), (uint64_t) UINT64_C(11422586310538197711),
        (uint64_t) UINT64_C(2030353469852519378), (uint64_t) UINT64_C(11750802462513761473),
        (uint64_t) UINT64_C(1268970918657824611), (uint64_t) UINT64_C(10076817059714813937),
        (uint64_t) UINT64_C(1586213648322280764), (uint64_t) UINT64_C(12596021324643517422),
        (uint64_t) UINT64_C(1982767060402850955), (uint64_t) UINT64_C(5566670318688504437),
        (uint64_t) UINT64_C(1239229412751781847), (uint64_t) UINT64_C(2346651879933242642),
        (uint64_t) UINT64_C(1549036765939727309), (uint64_t) UINT64_C(7545000868343941206),
        (uint64_t) UINT64_C(1936295957424659136), (uint64_t) UINT64_C(4715625542714963254),
        (uint64_t) UINT64_C(1210184973390411960), (uint64_t) UINT64_C(5894531928393704067),
        (uint64_t) UINT64_C(1512731216738014950), (uint64_t) UINT64_C(16591536947346905892),
        (uint64_t) UINT64_C(1890914020922518687), (uint64_t) UINT64_C(17287239619732898039),
        (uint64_t) UINT64_C(1181821263076574179), (uint64_t) UINT64_C(16997363506238734644),
        (uint64_t) UINT64_C(1477276578845717724), (uint64_t) UINT64_C(2799960309088866689),
        (uint64_t) UINT64_C(1846595723557147156), (uint64_t) UINT64_C(10973347230035317489),
        (uint64_t) UINT64_C(1154122327223216972), (uint64_t) UINT64_C(13716684037544146861),
        (uint64_t) UINT64_C(1442652909029021215), (uint64_t) UINT64_C(12534169028502795672),
        (uint64_t) UINT64_C(1803316136286276519), (uint64_t) UINT64_C(11056025267201106687),
        (uint64_t) UINT64_C(2254145170357845649), (uint64_t) UINT64_C(18439230838069161439),
        (uint64_t) UINT64_C(1408840731473653530), (uint64_t) UINT64_C(13825666510731675991),
        (uint64_t) UINT64_C(1761050914342066913), (uint64_t) UINT64_C(3447025083132431277),
        (uint64_t) UINT64_C(2201313642927583642), (uint64_t) UINT64_C(6766076695385157452),
        (uint64_t) UINT64_C(1375821026829739776), (uint64_t) UINT64_C(8457595869231446815),
        (uint64_t) UINT64_C(1719776283537174720), (uint64_t) UINT64_C(10571994836539308519),
        (uint64_t) UINT64_C(2149720354421468400), (uint64_t) UINT64_C(6607496772837067824),
        (uint64_t) UINT64_C(1343575221513417750), (uint64_t) UINT64_C(17482743002901110588),
        (uint64_t) UINT64_C(1679469026891772187), (uint64_t) UINT64_C(17241742735199000331),
        (uint64_t) UINT64_C(2099336283614715234), (uint64_t) UINT64_C(15387775227926763111),
        (uint64_t) UINT64_C(1312085177259197021), (uint64_t) UINT64_C(5399660979626290177),
        (uint64_t) UINT64_C(1640106471573996277), (uint64_t) UINT64_C(11361262242960250625),
        (uint64_t) UINT64_C(2050133089467495346), (uint64_t) UINT64_C(11712474920277544544),
        (uint64_t) UINT64_C(1281333180917184591), (uint64_t) UINT64_C(10028907631919542777),
        (uint64_t) UINT64_C(1601666476146480739), (uint64_t) UINT64_C(7924448521472040567),
        (uint64_t) UINT64_C(2002083095183100924), (uint64_t) UINT64_C(14176152362774801162),
        (uint64_t) UINT64_C(1251301934489438077), (uint64_t) UINT64_C(3885132398186337741),
        (uint64_t) UINT64_C(1564127418111797597), (uint64_t) UINT64_C(9468101516160310080),
        (uint64_t) UINT64_C(1955159272639746996), (uint64_t) UINT64_C(15140935484454969608),
        (uint64_t) UINT64_C(1221974545399841872), (uint64_t) UINT64_C(479425281859160394),
        (uint64_t) UINT64_C(1527468181749802341), (uint64_t) UINT64_C(5210967620751338397),
        (uint64_t) UINT64_C(1909335227187252926), (uint64_t) UINT64_C(17091912818251750210),
        (uint64_t) UINT64_C(1193334516992033078), (uint64_t) UINT64_C(12141518985959911954),
        (uint64_t) UINT64_C(1491668146240041348), (uint64_t) UINT64_C(15176898732449889943),
        (uint64_t) UINT64_C(1864585182800051685), (uint64_t) UINT64_C(11791404716994875166),
        (uint64_t) UINT64_C(1165365739250032303), (uint64_t) UINT64_C(10127569877816206054),
        (uint64_t) UINT64_C(1456707174062540379), (uint64_t) UINT64_C(8047776328842869663),
        (uint64_t) UINT64_C(1820883967578175474), (uint64_t) UINT64_C(836348374198811271),
        (uint64_t) UINT64_C(2276104959472719343), (uint64_t) UINT64_C(7440246761515338900),
        (uint64_t) UINT64_C(1422565599670449589), (uint64_t) UINT64_C(13911994470321561530),
        (uint64_t) UINT64_C(1778206999588061986), (uint64_t) UINT64_C(8166621051047176104),
        (uint64_t) UINT64_C(2222758749485077483), (uint64_t) UINT64_C(2798295147690791113),
        (uint64_t) UINT64_C(1389224218428173427), (uint64_t) UINT64_C(17332926989895652603),
        (uint64_t) UINT64_C(1736530273035216783), (uint64_t) UINT64_C(17054472718942177850),
        (uint64_t) UINT64_C(2170662841294020979), (uint64_t) UINT64_C(8353202440125167204),
        (uint64_t) UINT64_C(1356664275808763112), (uint64_t) UINT64_C(10441503050156459005),
        (uint64_t) UINT64_C(1695830344760953890), (uint64_t) UINT64_C(3828506775840797949),
        (uint64_t) UINT64_C(2119787930951192363), (uint64_t) UINT64_C(86973725686804766),
        (uint64_t) UINT64_C(1324867456844495227), (uint64_t) UINT64_C(13943775212390669669),
        (uint64_t) UINT64_C(1656084321055619033), (uint64_t) UINT64_C(3594660960206173375),
        (uint64_t) UINT64_C(2070105401319523792), (uint64_t) UINT64_C(2246663100128858359),
        (uint64_t) UINT64_C(1293815875824702370), (uint64_t) UINT64_C(12031700912015848757),
        (uint64_t) UINT64_C(1617269844780877962), (uint64_t) UINT64_C(5816254103165035138),
        (uint64_t) UINT64_C(2021587305976097453), (uint64_t) UINT64_C(5941001823691840913),
        (uint64_t) UINT64_C(1263492066235060908), (uint64_t) UINT64_C(7426252279614801142),
        (uint64_t) UINT64_C(1579365082793826135), (uint64_t) UINT64_C(4671129331091113523),
        (uint64_t) UINT64_C(1974206353492282669), (uint64_t) UINT64_C(5225298841145639904),
        (uint64_t) UINT64_C(1233878970932676668), (uint64_t) UINT64_C(6531623551432049880),
        (uint64_t) UINT64_C(1542348713665845835), (uint64_t) UINT64_C(3552843420862674446),
        (uint64_t) UINT64_C(1927935892082307294), (uint64_t) UINT64_C(16055585193321335241),
        (uint64_t) UINT64_C(1204959932551442058), (uint64_t) UINT64_C(10846109454796893243),
        (uint64_t) UINT64_C(1506199915689302573), (uint64_t) UINT64_C(18169322836923504458),
        (uint64_t) UINT64_C(1882749894611628216), (uint64_t) UINT64_C(11355826773077190286),
        (uint64_t) UINT64_C(1176718684132267635), (uint64_t) UINT64_C(9583097447919099954),
        (uint64_t) UINT64_C(1470898355165334544), (uint64_t) UINT64_C(11978871809898874942),
        (uint64_t) UINT64_C(1838622943956668180), (uint64_t) UINT64_C(14973589762373593678),
        (uint64_t) UINT64_C(2298278679945835225), (uint64_t) UINT64_C(2440964573842414192),
        (uint64_t) UINT64_C(1436424174966147016), (uint64_t) UINT64_C(3051205717303017741),
        (uint64_t) UINT64_C(1795530218707683770), (uint64_t) UINT64_C(13037379183483547984),
        (uint64_t) UINT64_C(2244412773384604712), (uint64_t) UINT64_C(8148361989677217490),
        (uint64_t) UINT64_C(1402757983365377945), (uint64_t) UINT64_C(14797138505523909766),
        (uint64_t) UINT64_C(1753447479206722431), (uint64_t) UINT64_C(13884737113477499304),
        (uint64_t) UINT64_C(2191809349008403039), (uint64_t) UINT64_C(15595489723564518921),
        (uint64_t) UINT64_C(1369880843130251899), (uint64_t) UINT64_C(14882676136028260747),
        (uint64_t) UINT64_C(1712351053912814874), (uint64_t) UINT64_C(9379973133180550126),
        (uint64_t) UINT64_C(2140438817391018593), (uint64_t) UINT64_C(17391698254306313589),
        (uint64_t) UINT64_C(1337774260869386620), (uint64_t) UINT64_C(3292878744173340370),
        (uint64_t) UINT64_C(1672217826086733276), (uint64_t) UINT64_C(4116098430216675462),
        (uint64_t) UINT64_C(2090272282608416595), (uint64_t) UINT64_C(266718509671728212),
        (uint64_t) UINT64_C(1306420176630260372), (uint64_t) UINT64_C(333398137089660265),
        (uint64_t) UINT64_C(1633025220787825465), (uint64_t) UINT64_C(5028433689789463235),
        (uint64_t) UINT64_C(2041281525984781831), (uint64_t) UINT64_C(10060300083759496378),
        (uint64_t) UINT64_C(1275800953740488644), (uint64_t) UINT64_C(12575375104699370472),
        (uint64_t) UINT64_C(1594751192175610805), (uint64_t) UINT64_C(1884160825592049379),
        (uint64_t) UINT64_C(1993438990219513507), (uint64_t) UINT64_C(17318501580490888525),
        (uint64_t) UINT64_C(1245899368887195941), (uint64_t) UINT64_C(7813068920331446945),
        (uint64_t) UINT64_C(1557374211108994927), (uint64_t) UINT64_C(5154650131986920777),
        (uint64_t) UINT64_C(1946717763886243659), (uint64_t) UINT64_C(915813323278131534),
        (uint64_t) UINT64_C(1216698602428902287), (uint64_t) UINT64_C(14979824709379828129),
        (uint64_t) UINT64_C(1520873253036127858), (uint64_t) UINT64_C(9501408849870009354),
        (uint64_t) UINT64_C(1901091566295159823), (uint64_t) UINT64_C(12855909558809837702),
        (uint64_t) UINT64_C(1188182228934474889), (uint64_t) UINT64_C(2234828893230133415),
        (uint64_t) UINT64_C(1485227786168093612), (uint64_t) UINT64_C(2793536116537666769),
        (uint64_t) UINT64_C(1856534732710117015), (uint64_t) UINT64_C(8663489100477123587),
        (uint64_t) UINT64_C(1160334207943823134), (uint64_t) UINT64_C(1605989338741628675),
        (uint64_t) UINT64_C(1450417759929778918), (uint64_t) UINT64_C(11230858710281811652),
        (uint64_t) UINT64_C(1813022199912223647), (uint64_t) UINT64_C(9426887369424876662),
        (uint64_t) UINT64_C(2266277749890279559), (uint64_t) UINT64_C(12809333633531629769),
        (uint64_t) UINT64_C(1416423593681424724), (uint64_t) UINT64_C(16011667041914537212),
        (uint64_t) UINT64_C(1770529492101780905), (uint64_t) UINT64_C(6179525747111007803),
        (uint64_t) UINT64_C(2213161865127226132), (uint64_t) UINT64_C(13085575628799155685),
        (uint64_t) UINT64_C(1383226165704516332), (uint64_t) UINT64_C(16356969535998944606),
        (uint64_t) UINT64_C(1729032707130645415), (uint64_t) UINT64_C(15834525901571292854),
        (uint64_t) UINT64_C(2161290883913306769), (uint64_t) UINT64_C(2979049660840976177),
        (uint64_t) UINT64_C(1350806802445816731), (uint64_t) UINT64_C(17558870131333383934),
        (uint64_t) UINT64_C(1688508503057270913), (uint64_t) UINT64_C(8113529608884566205),
        (uint64_t) UINT64_C(2110635628821588642), (uint64_t) UINT64_C(9682642023980241782),
        (uint64_t) UINT64_C(1319147268013492901), (uint64_t) UINT64_C(16714988548402690132),
        (uint64_t) UINT64_C(1648934085016866126), (uint64_t) UINT64_C(11670363648648586857),
        (uint64_t) UINT64_C(2061167606271082658), (uint64_t) UINT64_C(11905663298832754689),
        (uint64_t) UINT64_C(1288229753919426661), (uint64_t) UINT64_C(1047021068258779650),
        (uint64_t) UINT64_C(1610287192399283327), (uint64_t) UINT64_C(15143834390605638274),
        (uint64_t) UINT64_C(2012858990499104158), (uint64_t) UINT64_C(4853210475701136017),
        (uint64_t) UINT64_C(1258036869061940099), (uint64_t) UINT64_C(1454827076199032118),
        (uint64_t) UINT64_C(1572546086327425124), (uint64_t) UINT64_C(1818533845248790147),
        (uint64_t) UINT64_C(1965682607909281405), (uint64_t) UINT64_C(3442426662494187794),
        (uint64_t) UINT64_C(1228551629943300878), (uint64_t) UINT64_C(13526405364972510550),
        (uint64_t) UINT64_C(1535689537429126097), (uint64_t) UINT64_C(3072948650933474476),
        (uint64_t) UINT64_C(1919611921786407622), (uint64_t) UINT64_C(15755650962115585259),
        (uint64_t) UINT64_C(1199757451116504763), (uint64_t) UINT64_C(15082877684217093670),
        (uint64_t) UINT64_C(1499696813895630954), (uint64_t) UINT64_C(9630225068416591280),
        (uint64_t) UINT64_C(1874621017369538693), (uint64_t) UINT64_C(8324733676974063502),
        (uint64_t) UINT64_C(1171638135855961683), (uint64_t) UINT64_C(5794231077790191473),
        (uint64_t) UINT64_C(1464547669819952104), (uint64_t) UINT64_C(7242788847237739342),
        (uint64_t) UINT64_C(1830684587274940130), (uint64_t) UINT64_C(18276858095901949986),
        (uint64_t) UINT64_C(2288355734093675162), (uint64_t) UINT64_C(16034722328366106645),
        (uint64_t) UINT64_C(1430222333808546976), (uint64_t) UINT64_C(1596658836748081690),
        (uint64_t) UINT64_C(1787777917260683721), (uint64_t) UINT64_C(6607509564362490017),
        (uint64_t) UINT64_C(2234722396575854651), (uint64_t) UINT64_C(1823850468512862308),
        (uint64_t) UINT64_C(1396701497859909157), (uint64_t) UINT64_C(6891499104068465790),
        (uint64_t) UINT64_C(1745876872324886446), (uint64_t) UINT64_C(17837745916940358045),
        (uint64_t) UINT64_C(2182346090406108057), (uint64_t) UINT64_C(4231062170446641922),
        (uint64_t) UINT64_C(1363966306503817536), (uint64_t) UINT64_C(5288827713058302403),
        (uint64_t) UINT64_C(1704957883129771920), (uint64_t) UINT64_C(6611034641322878003),
        (uint64_t) UINT64_C(2131197353912214900), (uint64_t) UINT64_C(13355268687681574560),
        (uint64_t) UINT64_C(1331998346195134312), (uint64_t) UINT64_C(16694085859601968200),
        (uint64_t) UINT64_C(1664997932743917890), (uint64_t) UINT64_C(11644235287647684442),
        (uint64_t) UINT64_C(2081247415929897363), (uint64_t) UINT64_C(4971804045566108824),
        (uint64_t) UINT64_C(1300779634956185852), (uint64_t) UINT64_C(6214755056957636030),
        (uint64_t) UINT64_C(1625974543695232315), (uint64_t) UINT64_C(3156757802769657134),
        (uint64_t) UINT64_C(2032468179619040394), (uint64_t) UINT64_C(6584659645158423613),
        (uint64_t) UINT64_C(1270292612261900246), (uint64_t) UINT64_C(17454196593302805324),
        (uint64_t) UINT64_C(1587865765327375307), (uint64_t) UINT64_C(17206059723201118751),
        (uint64_t) UINT64_C(1984832206659219134), (uint64_t) UINT64_C(6142101308573311315),
        (uint64_t) UINT64_C(1240520129162011959), (uint64_t) UINT64_C(3065940617289251240),
        (uint64_t) UINT64_C(1550650161452514949), (uint64_t) UINT64_C(8444111790038951954),
        (uint64_t) UINT64_C(1938312701815643686), (uint64_t) UINT64_C(665883850346957067),
        (uint64_t) UINT64_C(1211445438634777304), (uint64_t) UINT64_C(832354812933696334),
        (uint64_t) UINT64_C(1514306798293471630), (uint64_t) UINT64_C(10263815553021896226),
        (uint64_t) UINT64_C(1892883497866839537), (uint64_t) UINT64_C(17944099766707154901),
        (uint64_t) UINT64_C(1183052186166774710), (uint64_t) UINT64_C(13206752671529167818),
        (uint64_t) UINT64_C(1478815232708468388), (uint64_t) UINT64_C(16508440839411459773),
        (uint64_t) UINT64_C(1848519040885585485), (uint64_t) UINT64_C(12623618533845856310),
        (uint64_t) UINT64_C(1155324400553490928), (uint64_t) UINT64_C(15779523167307320387),
        (uint64_t) UINT64_C(1444155500691863660), (uint64_t) UINT64_C(1277659885424598868),
        (uint64_t) UINT64_C(1805194375864829576), (uint64_t) UINT64_C(1597074856780748586),
        (uint64_t) UINT64_C(2256492969831036970), (uint64_t) UINT64_C(5609857803915355770),
        (uint64_t) UINT64_C(1410308106144398106), (uint64_t) UINT64_C(16235694291748970521),
        (uint64_t) UINT64_C(1762885132680497632), (uint64_t) UINT64_C(1847873790976661535),
        (uint64_t) UINT64_C(2203606415850622041), (uint64_t) UINT64_C(12684136165428883219),
        (uint64_t) UINT64_C(1377254009906638775), (uint64_t) UINT64_C(11243484188358716120),
        (uint64_t) UINT64_C(1721567512383298469), (uint64_t) UINT64_C(219297180166231438),
        (uint64_t) UINT64_C(2151959390479123087), (uint64_t) UINT64_C(7054589765244976505),
        (uint64_t) UINT64_C(1344974619049451929), (uint64_t) UINT64_C(13429923224983608535),
        (uint64_t) UINT64_C(1681218273811814911), (uint64_t) UINT64_C(12175718012802122765),
        (uint64_t) UINT64_C(2101522842264768639), (uint64_t) UINT64_C(14527352785642408584),
        (uint64_t) UINT64_C(1313451776415480399), (uint64_t) UINT64_C(13547504963625622826),
        (uint64_t) UINT64_C(1641814720519350499), (uint64_t) UINT64_C(12322695186104640628),
        (uint64_t) UINT64_C(2052268400649188124), (uint64_t) UINT64_C(16925056528170176201),
        (uint64_t) UINT64_C(1282667750405742577), (uint64_t) UINT64_C(7321262604930556539),
        (uint64_t) UINT64_C(1603334688007178222), (uint64_t) UINT64_C(18374950293017971482),
        (uint64_t) UINT64_C(2004168360008972777), (uint64_t) UINT64_C(4566814905495150320),
        (uint64_t) UINT64_C(1252605225005607986), (uint64_t) UINT64_C(14931890668723713708),
        (uint64_t) UINT64_C(1565756531257009982), (uint64_t) UINT64_C(9441491299049866327),
        (uint64_t) UINT64_C(1957195664071262478), (uint64_t) UINT64_C(1289246043478778550),
        (uint64_t) UINT64_C(1223247290044539049), (uint64_t) UINT64_C(6223243572775861092),
        (uint64_t) UINT64_C(1529059112555673811), (uint64_t) UINT64_C(3167368447542438461),
        (uint64_t) UINT64_C(1911323890694592264), (uint64_t) UINT64_C(1979605279714024038),
        (uint64_t) UINT64_C(1194577431684120165), (uint64_t) UINT64_C(7086192618069917952),
        (uint64_t) UINT64_C(1493221789605150206), (uint64_t) UINT64_C(18081112809442173248),
        (uint64_t) UINT64_C(1866527237006437757), (uint64_t) UINT64_C(13606538515115052232),
        (uint64_t) UINT64_C(1166579523129023598), (uint64_t) UINT64_C(7784801107039039482),
        (uint64_t) UINT64_C(1458224403911279498), (uint64_t) UINT64_C(507629346944023544),
        (uint64_t) UINT64_C(1822780504889099373), (uint64_t) UINT64_C(5246222702107417334),
        (uint64_t) UINT64_C(2278475631111374216), (uint64_t) UINT64_C(3278889188817135834),
        (uint64_t) UINT64_C(1424047269444608885), (uint64_t) UINT64_C(8710297504448807696),
        (uint64_t) UINT64_C(1780059086805761106),
    },
};
const vader_array_t vader_data_2 = {
    { 19u, 0u, 0u, 0u, NULL }, 652u, 652u, 0u, (vader_array_buf_t*) &vader_data_2_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint64_t slots[55]; } vader_data_3_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 55u, 55u, 252u, 4u, { 0u, 0u, 0u },
    {
        (uint64_t) UINT64_C(576460752303423489), (uint64_t) UINT64_C(461168601842738791),
        (uint64_t) UINT64_C(368934881474191033), (uint64_t) UINT64_C(295147905179352826),
        (uint64_t) UINT64_C(472236648286964522), (uint64_t) UINT64_C(377789318629571618),
        (uint64_t) UINT64_C(302231454903657294), (uint64_t) UINT64_C(483570327845851670),
        (uint64_t) UINT64_C(386856262276681336), (uint64_t) UINT64_C(309485009821345069),
        (uint64_t) UINT64_C(495176015714152110), (uint64_t) UINT64_C(396140812571321688),
        (uint64_t) UINT64_C(316912650057057351), (uint64_t) UINT64_C(507060240091291761),
        (uint64_t) UINT64_C(405648192073033409), (uint64_t) UINT64_C(324518553658426727),
        (uint64_t) UINT64_C(519229685853482763), (uint64_t) UINT64_C(415383748682786211),
        (uint64_t) UINT64_C(332306998946228969), (uint64_t) UINT64_C(531691198313966350),
        (uint64_t) UINT64_C(425352958651173080), (uint64_t) UINT64_C(340282366920938464),
        (uint64_t) UINT64_C(544451787073501542), (uint64_t) UINT64_C(435561429658801234),
        (uint64_t) UINT64_C(348449143727040987), (uint64_t) UINT64_C(557518629963265579),
        (uint64_t) UINT64_C(446014903970612463), (uint64_t) UINT64_C(356811923176489971),
        (uint64_t) UINT64_C(570899077082383953), (uint64_t) UINT64_C(456719261665907162),
        (uint64_t) UINT64_C(365375409332725730), (uint64_t) UINT64_C(292300327466180584),
        (uint64_t) UINT64_C(467680523945888934), (uint64_t) UINT64_C(374144419156711148),
        (uint64_t) UINT64_C(299315535325368918), (uint64_t) UINT64_C(478904856520590269),
        (uint64_t) UINT64_C(383123885216472215), (uint64_t) UINT64_C(306499108173177772),
        (uint64_t) UINT64_C(490398573077084435), (uint64_t) UINT64_C(392318858461667548),
        (uint64_t) UINT64_C(313855086769334039), (uint64_t) UINT64_C(502168138830934462),
        (uint64_t) UINT64_C(401734511064747569), (uint64_t) UINT64_C(321387608851798056),
        (uint64_t) UINT64_C(514220174162876889), (uint64_t) UINT64_C(411376139330301511),
        (uint64_t) UINT64_C(329100911464241209), (uint64_t) UINT64_C(526561458342785934),
        (uint64_t) UINT64_C(421249166674228747), (uint64_t) UINT64_C(336999333339382998),
        (uint64_t) UINT64_C(539198933343012796), (uint64_t) UINT64_C(431359146674410237),
        (uint64_t) UINT64_C(345087317339528190), (uint64_t) UINT64_C(552139707743245103),
        (uint64_t) UINT64_C(441711766194596083),
    },
};
const vader_array_t vader_data_3 = {
    { 19u, 0u, 0u, 0u, NULL }, 55u, 55u, 0u, (vader_array_buf_t*) &vader_data_3_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint64_t slots[47]; } vader_data_4_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 47u, 47u, 252u, 4u, { 0u, 0u, 0u },
    {
        (uint64_t) UINT64_C(1152921504606846976), (uint64_t) UINT64_C(1441151880758558720),
        (uint64_t) UINT64_C(1801439850948198400), (uint64_t) UINT64_C(2251799813685248000),
        (uint64_t) UINT64_C(1407374883553280000), (uint64_t) UINT64_C(1759218604441600000),
        (uint64_t) UINT64_C(2199023255552000000), (uint64_t) UINT64_C(1374389534720000000),
        (uint64_t) UINT64_C(1717986918400000000), (uint64_t) UINT64_C(2147483648000000000),
        (uint64_t) UINT64_C(1342177280000000000), (uint64_t) UINT64_C(1677721600000000000),
        (uint64_t) UINT64_C(2097152000000000000), (uint64_t) UINT64_C(1310720000000000000),
        (uint64_t) UINT64_C(1638400000000000000), (uint64_t) UINT64_C(2048000000000000000),
        (uint64_t) UINT64_C(1280000000000000000), (uint64_t) UINT64_C(1600000000000000000),
        (uint64_t) UINT64_C(2000000000000000000), (uint64_t) UINT64_C(1250000000000000000),
        (uint64_t) UINT64_C(1562500000000000000), (uint64_t) UINT64_C(1953125000000000000),
        (uint64_t) UINT64_C(1220703125000000000), (uint64_t) UINT64_C(1525878906250000000),
        (uint64_t) UINT64_C(1907348632812500000), (uint64_t) UINT64_C(1192092895507812500),
        (uint64_t) UINT64_C(1490116119384765625), (uint64_t) UINT64_C(1862645149230957031),
        (uint64_t) UINT64_C(1164153218269348144), (uint64_t) UINT64_C(1455191522836685180),
        (uint64_t) UINT64_C(1818989403545856475), (uint64_t) UINT64_C(2273736754432320594),
        (uint64_t) UINT64_C(1421085471520200371), (uint64_t) UINT64_C(1776356839400250464),
        (uint64_t) UINT64_C(2220446049250313080), (uint64_t) UINT64_C(1387778780781445675),
        (uint64_t) UINT64_C(1734723475976807094), (uint64_t) UINT64_C(2168404344971008868),
        (uint64_t) UINT64_C(1355252715606880542), (uint64_t) UINT64_C(1694065894508600678),
        (uint64_t) UINT64_C(2117582368135750847), (uint64_t) UINT64_C(1323488980084844279),
        (uint64_t) UINT64_C(1654361225106055349), (uint64_t) UINT64_C(2067951531382569187),
        (uint64_t) UINT64_C(1292469707114105741), (uint64_t) UINT64_C(1615587133892632177),
        (uint64_t) UINT64_C(2019483917365790221),
    },
};
const vader_array_t vader_data_4 = {
    { 19u, 0u, 0u, 0u, NULL }, 47u, 47u, 0u, (vader_array_buf_t*) &vader_data_4_buf,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e0 = {
    { 806u, 0u, 0u, 0u, NULL }, 439u, 1618u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e1 = {
    { 806u, 0u, 0u, 0u, NULL }, 440u, 1473u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e2 = {
    { 806u, 0u, 0u, 0u, NULL }, 441u, 1707u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e3 = {
    { 806u, 0u, 0u, 0u, NULL }, 442u, 1469u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e4 = {
    { 806u, 0u, 0u, 0u, NULL }, 443u, 1470u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e5 = {
    { 806u, 0u, 0u, 0u, NULL }, 444u, 418u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e6 = {
    { 806u, 0u, 0u, 0u, NULL }, 445u, 1477u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e7 = {
    { 806u, 0u, 0u, 0u, NULL }, 446u, 478u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e8 = {
    { 806u, 0u, 0u, 0u, NULL }, 447u, 1471u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e9 = {
    { 806u, 0u, 0u, 0u, NULL }, 448u, 1475u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e10 = {
    { 806u, 0u, 0u, 0u, NULL }, 449u, 1474u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e11 = {
    { 806u, 0u, 0u, 0u, NULL }, 450u, 417u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e12 = {
    { 806u, 0u, 0u, 0u, NULL }, 451u, 1510u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e13 = {
    { 806u, 0u, 0u, 0u, NULL }, 452u, 1732u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e14 = {
    { 806u, 0u, 0u, 0u, NULL }, 453u, 1465u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_5_e15 = {
    { 806u, 0u, 0u, 0u, NULL }, 454u, 1817u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[16]; } vader_data_5_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 16u, 16u, 806u, 0u, { 0u, 0u, 0u },
    {
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e0 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e1 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e2 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e3 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e4 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e5 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e6 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e7 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e8 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e9 },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e10,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e11,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e12,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e13,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e14,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_5_e15,
            },
        },
    },
};
const vader_array_t vader_data_5 = {
    { 73u, 0u, 0u, 0u, NULL }, 16u, 16u, 0u, (vader_array_buf_t*) &vader_data_5_buf,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e0 = {
    { 806u, 0u, 0u, 0u, NULL }, 600u, 2009u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e1 = {
    { 806u, 0u, 0u, 0u, NULL }, 601u, 1812u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e2 = {
    { 806u, 0u, 0u, 0u, NULL }, 602u, 1815u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e3 = {
    { 806u, 0u, 0u, 0u, NULL }, 603u, 1543u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e4 = {
    { 806u, 0u, 0u, 0u, NULL }, 604u, 1810u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e5 = {
    { 806u, 0u, 0u, 0u, NULL }, 605u, 2449u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e6 = {
    { 806u, 0u, 0u, 0u, NULL }, 606u, 2450u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e7 = {
    { 806u, 0u, 0u, 0u, NULL }, 607u, 2300u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e8 = {
    { 806u, 0u, 0u, 0u, NULL }, 608u, 2359u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e9 = {
    { 806u, 0u, 0u, 0u, NULL }, 609u, 1513u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e10 = {
    { 806u, 0u, 0u, 0u, NULL }, 610u, 1541u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e11 = {
    { 806u, 0u, 0u, 0u, NULL }, 611u, 1816u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e12 = {
    { 806u, 0u, 0u, 0u, NULL }, 612u, 2169u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e13 = {
    { 806u, 0u, 0u, 0u, NULL }, 613u, 2466u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e14 = {
    { 806u, 0u, 0u, 0u, NULL }, 614u, 2007u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e15 = {
    { 806u, 0u, 0u, 0u, NULL }, 615u, 2178u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e16 = {
    { 806u, 0u, 0u, 0u, NULL }, 616u, 1648u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e17 = {
    { 806u, 0u, 0u, 0u, NULL }, 617u, 2075u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e18 = {
    { 806u, 0u, 0u, 0u, NULL }, 618u, 1157u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e19 = {
    { 806u, 0u, 0u, 0u, NULL }, 619u, 2006u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e20 = {
    { 806u, 0u, 0u, 0u, NULL }, 620u, 2010u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e21 = {
    { 806u, 0u, 0u, 0u, NULL }, 621u, 1679u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e22 = {
    { 806u, 0u, 0u, 0u, NULL }, 622u, 2366u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e23 = {
    { 806u, 0u, 0u, 0u, NULL }, 623u, 2170u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e24 = {
    { 806u, 0u, 0u, 0u, NULL }, 624u, 2134u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e25 = {
    { 806u, 0u, 0u, 0u, NULL }, 625u, 1542u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e26 = {
    { 806u, 0u, 0u, 0u, NULL }, 626u, 1613u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e27 = {
    { 806u, 0u, 0u, 0u, NULL }, 627u, 1607u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e28 = {
    { 806u, 0u, 0u, 0u, NULL }, 628u, 1137u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e29 = {
    { 806u, 0u, 0u, 0u, NULL }, 629u, 1483u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e30 = {
    { 806u, 0u, 0u, 0u, NULL }, 630u, 2014u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e31 = {
    { 806u, 0u, 0u, 0u, NULL }, 631u, 2330u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e32 = {
    { 806u, 0u, 0u, 0u, NULL }, 632u, 1209u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e33 = {
    { 806u, 0u, 0u, 0u, NULL }, 633u, 1213u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e34 = {
    { 806u, 0u, 0u, 0u, NULL }, 634u, 2441u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e35 = {
    { 806u, 0u, 0u, 0u, NULL }, 635u, 1126u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e36 = {
    { 806u, 0u, 0u, 0u, NULL }, 636u, 1124u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e37 = {
    { 806u, 0u, 0u, 0u, NULL }, 637u, 2365u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e38 = {
    { 806u, 0u, 0u, 0u, NULL }, 638u, 1538u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e39 = {
    { 806u, 0u, 0u, 0u, NULL }, 639u, 1125u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e40 = {
    { 806u, 0u, 0u, 0u, NULL }, 640u, 2030u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_6_e41 = {
    { 806u, 0u, 0u, 0u, NULL }, 641u, 1185u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[42]; } vader_data_6_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 42u, 42u, 806u, 0u, { 0u, 0u, 0u },
    {
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e0 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e1 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e2 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e3 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e4 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e5 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e6 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e7 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e8 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e9 },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e10,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e11,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e12,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e13,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e14,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e15,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e16,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e17,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e18,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e19,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e20,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e21,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e22,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e23,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e24,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e25,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e26,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e27,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e28,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e29,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e30,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e31,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e32,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e33,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e34,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e35,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e36,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e37,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e38,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e39,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e40,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_6_e41,
            },
        },
    },
};
const vader_array_t vader_data_6 = {
    { 73u, 0u, 0u, 0u, NULL }, 42u, 42u, 0u, (vader_array_buf_t*) &vader_data_6_buf,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e0 = {
    { 806u, 0u, 0u, 0u, NULL }, 772u, 2461u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e1 = {
    { 806u, 0u, 0u, 0u, NULL }, 773u, 2445u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e2 = {
    { 806u, 0u, 0u, 0u, NULL }, 774u, 2621u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e3 = {
    { 806u, 0u, 0u, 0u, NULL }, 775u, 1508u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e4 = {
    { 806u, 0u, 0u, 0u, NULL }, 776u, 1940u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e5 = {
    { 806u, 0u, 0u, 0u, NULL }, 777u, 2126u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e6 = {
    { 806u, 0u, 0u, 0u, NULL }, 778u, 2103u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e7 = {
    { 806u, 0u, 0u, 0u, NULL }, 779u, 1552u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e8 = {
    { 806u, 0u, 0u, 0u, NULL }, 780u, 1615u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e9 = {
    { 806u, 0u, 0u, 0u, NULL }, 781u, 1130u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e10 = {
    { 806u, 0u, 0u, 0u, NULL }, 782u, 1964u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e11 = {
    { 806u, 0u, 0u, 0u, NULL }, 783u, 1941u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e12 = {
    { 806u, 0u, 0u, 0u, NULL }, 784u, 2326u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e13 = {
    { 806u, 0u, 0u, 0u, NULL }, 785u, 2322u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_7_e14 = {
    { 806u, 0u, 0u, 0u, NULL }, 786u, 2049u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[15]; } vader_data_7_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 15u, 15u, 806u, 0u, { 0u, 0u, 0u },
    {
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e0 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e1 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e2 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e3 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e4 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e5 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e6 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e7 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e8 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e9 },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e10,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e11,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e12,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e13,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_7_e14,
            },
        },
    },
};
const vader_array_t vader_data_7 = {
    { 73u, 0u, 0u, 0u, NULL }, 15u, 15u, 0u, (vader_array_buf_t*) &vader_data_7_buf,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_8_e0 = {
    { 806u, 0u, 0u, 0u, NULL }, 502u, 1218u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_8_e1 = {
    { 806u, 0u, 0u, 0u, NULL }, 503u, 1709u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_8_e2 = {
    { 806u, 0u, 0u, 0u, NULL }, 504u, 1659u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_8_e3 = {
    { 806u, 0u, 0u, 0u, NULL }, 505u, 2312u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_8_e4 = {
    { 806u, 0u, 0u, 0u, NULL }, 506u, 1835u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_8_e5 = {
    { 806u, 0u, 0u, 0u, NULL }, 507u, 1942u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_8_e6 = {
    { 806u, 0u, 0u, 0u, NULL }, 508u, 1557u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_8_e7 = {
    { 806u, 0u, 0u, 0u, NULL }, 509u, 2101u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_8_e8 = {
    { 806u, 0u, 0u, 0u, NULL }, 510u, 1212u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_8_e9 = {
    { 806u, 0u, 0u, 0u, NULL }, 511u, 1211u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_8_e10 = {
    { 806u, 0u, 0u, 0u, NULL }, 512u, 1198u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[11]; } vader_data_8_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 11u, 11u, 806u, 0u, { 0u, 0u, 0u },
    {
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_8_e0 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_8_e1 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_8_e2 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_8_e3 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_8_e4 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_8_e5 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_8_e6 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_8_e7 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_8_e8 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_8_e9 },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_8_e10,
            },
        },
    },
};
const vader_array_t vader_data_8 = {
    { 73u, 0u, 0u, 0u, NULL }, 11u, 11u, 0u, (vader_array_buf_t*) &vader_data_8_buf,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e0 = {
    { 806u, 0u, 0u, 0u, NULL }, 656u, 2369u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e1 = {
    { 806u, 0u, 0u, 0u, NULL }, 657u, 1597u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e2 = {
    { 806u, 0u, 0u, 0u, NULL }, 658u, 2634u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e3 = {
    { 806u, 0u, 0u, 0u, NULL }, 659u, 2440u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e4 = {
    { 806u, 0u, 0u, 0u, NULL }, 660u, 1998u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e5 = {
    { 806u, 0u, 0u, 0u, NULL }, 661u, 2360u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e6 = {
    { 806u, 0u, 0u, 0u, NULL }, 662u, 1619u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e7 = {
    { 806u, 0u, 0u, 0u, NULL }, 663u, 1620u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e8 = {
    { 806u, 0u, 0u, 0u, NULL }, 664u, 1662u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e9 = {
    { 806u, 0u, 0u, 0u, NULL }, 665u, 1865u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e10 = {
    { 806u, 0u, 0u, 0u, NULL }, 666u, 2041u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e11 = {
    { 806u, 0u, 0u, 0u, NULL }, 667u, 2446u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e12 = {
    { 806u, 0u, 0u, 0u, NULL }, 668u, 1142u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e13 = {
    { 806u, 0u, 0u, 0u, NULL }, 669u, 1153u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e14 = {
    { 806u, 0u, 0u, 0u, NULL }, 670u, 2070u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e15 = {
    { 806u, 0u, 0u, 0u, NULL }, 671u, 2265u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e16 = {
    { 806u, 0u, 0u, 0u, NULL }, 672u, 1482u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e17 = {
    { 806u, 0u, 0u, 0u, NULL }, 673u, 1705u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e18 = {
    { 806u, 0u, 0u, 0u, NULL }, 674u, 1731u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e19 = {
    { 806u, 0u, 0u, 0u, NULL }, 675u, 1500u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e20 = {
    { 806u, 0u, 0u, 0u, NULL }, 676u, 2460u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e21 = {
    { 806u, 0u, 0u, 0u, NULL }, 677u, 1710u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e22 = {
    { 806u, 0u, 0u, 0u, NULL }, 678u, 2016u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e23 = {
    { 806u, 0u, 0u, 0u, NULL }, 679u, 2368u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e24 = {
    { 806u, 0u, 0u, 0u, NULL }, 680u, 2437u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e25 = {
    { 806u, 0u, 0u, 0u, NULL }, 681u, 1424u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e26 = {
    { 806u, 0u, 0u, 0u, NULL }, 682u, 1560u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e27 = {
    { 806u, 0u, 0u, 0u, NULL }, 683u, 1562u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e28 = {
    { 806u, 0u, 0u, 0u, NULL }, 684u, 1539u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e29 = {
    { 806u, 0u, 0u, 0u, NULL }, 685u, 1239u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e30 = {
    { 806u, 0u, 0u, 0u, NULL }, 686u, 1863u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e31 = {
    { 806u, 0u, 0u, 0u, NULL }, 687u, 2124u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e32 = {
    { 806u, 0u, 0u, 0u, NULL }, 688u, 2378u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e33 = {
    { 806u, 0u, 0u, 0u, NULL }, 689u, 1804u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e34 = {
    { 806u, 0u, 0u, 0u, NULL }, 690u, 2000u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e35 = {
    { 806u, 0u, 0u, 0u, NULL }, 691u, 1660u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e36 = {
    { 806u, 0u, 0u, 0u, NULL }, 692u, 1128u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e37 = {
    { 806u, 0u, 0u, 0u, NULL }, 693u, 2314u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e38 = {
    { 806u, 0u, 0u, 0u, NULL }, 694u, 1430u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e39 = {
    { 806u, 0u, 0u, 0u, NULL }, 695u, 1427u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e40 = {
    { 806u, 0u, 0u, 0u, NULL }, 697u, 1862u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e41 = {
    { 806u, 0u, 0u, 0u, NULL }, 698u, 1120u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e42 = {
    { 806u, 0u, 0u, 0u, NULL }, 699u, 1614u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e43 = {
    { 806u, 0u, 0u, 0u, NULL }, 700u, 1706u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e44 = {
    { 806u, 0u, 0u, 0u, NULL }, 701u, 1229u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e45 = {
    { 806u, 0u, 0u, 0u, NULL }, 702u, 1450u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e46 = {
    { 806u, 0u, 0u, 0u, NULL }, 696u, 2065u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e47 = {
    { 806u, 0u, 0u, 0u, NULL }, 703u, 1199u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e48 = {
    { 806u, 0u, 0u, 0u, NULL }, 711u, 1844u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e49 = {
    { 806u, 0u, 0u, 0u, NULL }, 704u, 1200u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e50 = {
    { 806u, 0u, 0u, 0u, NULL }, 705u, 1158u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e51 = {
    { 806u, 0u, 0u, 0u, NULL }, 706u, 1145u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e52 = {
    { 806u, 0u, 0u, 0u, NULL }, 707u, 2640u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e53 = {
    { 806u, 0u, 0u, 0u, NULL }, 708u, 1184u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e54 = {
    { 806u, 0u, 0u, 0u, NULL }, 709u, 1309u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e55 = {
    { 806u, 0u, 0u, 0u, NULL }, 710u, 1140u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e56 = {
    { 806u, 0u, 0u, 0u, NULL }, 712u, 1143u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e57 = {
    { 806u, 0u, 0u, 0u, NULL }, 713u, 1102u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e58 = {
    { 806u, 0u, 0u, 0u, NULL }, 714u, 1425u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e59 = {
    { 806u, 0u, 0u, 0u, NULL }, 715u, 1428u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e60 = {
    { 806u, 0u, 0u, 0u, NULL }, 716u, 2345u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e61 = {
    { 806u, 0u, 0u, 0u, NULL }, 717u, 2338u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e62 = {
    { 806u, 0u, 0u, 0u, NULL }, 718u, 2342u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e63 = {
    { 806u, 0u, 0u, 0u, NULL }, 719u, 1223u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e64 = {
    { 806u, 0u, 0u, 0u, NULL }, 720u, 1178u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e65 = {
    { 806u, 0u, 0u, 0u, NULL }, 721u, 1207u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e66 = {
    { 806u, 0u, 0u, 0u, NULL }, 722u, 1210u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e67 = {
    { 806u, 0u, 0u, 0u, NULL }, 723u, 2341u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e68 = {
    { 806u, 0u, 0u, 0u, NULL }, 724u, 1512u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e69 = {
    { 806u, 0u, 0u, 0u, NULL }, 725u, 1416u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e70 = {
    { 806u, 0u, 0u, 0u, NULL }, 726u, 2590u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e71 = {
    { 806u, 0u, 0u, 0u, NULL }, 727u, 2044u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e72 = {
    { 806u, 0u, 0u, 0u, NULL }, 728u, 2045u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e73 = {
    { 806u, 0u, 0u, 0u, NULL }, 729u, 1561u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e74 = {
    { 806u, 0u, 0u, 0u, NULL }, 730u, 2596u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e75 = {
    { 806u, 0u, 0u, 0u, NULL }, 731u, 1222u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e76 = {
    { 806u, 0u, 0u, 0u, NULL }, 732u, 1243u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e77 = {
    { 806u, 0u, 0u, 0u, NULL }, 733u, 2591u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e78 = {
    { 806u, 0u, 0u, 0u, NULL }, 734u, 1930u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e79 = {
    { 806u, 0u, 0u, 0u, NULL }, 735u, 1254u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e80 = {
    { 806u, 0u, 0u, 0u, NULL }, 736u, 1214u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e81 = {
    { 806u, 0u, 0u, 0u, NULL }, 737u, 1258u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e82 = {
    { 806u, 0u, 0u, 0u, NULL }, 738u, 1215u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e83 = {
    { 806u, 0u, 0u, 0u, NULL }, 739u, 1252u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e84 = {
    { 806u, 0u, 0u, 0u, NULL }, 740u, 1253u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e85 = {
    { 806u, 0u, 0u, 0u, NULL }, 741u, 1190u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e86 = {
    { 806u, 0u, 0u, 0u, NULL }, 742u, 1221u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e87 = {
    { 806u, 0u, 0u, 0u, NULL }, 743u, 1205u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e88 = {
    { 806u, 0u, 0u, 0u, NULL }, 744u, 1189u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_9_e89 = {
    { 806u, 0u, 0u, 0u, NULL }, 745u, 1661u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[90]; } vader_data_9_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 90u, 90u, 806u, 0u, { 0u, 0u, 0u },
    {
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e0 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e1 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e2 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e3 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e4 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e5 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e6 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e7 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e8 },
        },
        {
            806u, 0u,
            { .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e9 },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e10,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e11,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e12,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e13,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e14,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e15,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e16,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e17,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e18,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e19,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e20,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e21,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e22,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e23,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e24,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e25,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e26,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e27,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e28,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e29,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e30,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e31,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e32,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e33,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e34,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e35,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e36,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e37,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e38,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e39,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e40,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e41,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e42,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e43,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e44,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e45,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e46,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e47,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e48,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e49,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e50,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e51,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e52,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e53,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e54,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e55,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e56,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e57,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e58,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e59,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e60,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e61,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e62,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e63,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e64,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e65,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e66,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e67,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e68,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e69,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e70,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e71,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e72,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e73,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e74,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e75,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e76,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e77,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e78,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e79,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e80,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e81,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e82,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e83,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e84,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e85,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e86,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e87,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e88,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_9_e89,
            },
        },
    },
};
const vader_array_t vader_data_9 = {
    { 73u, 0u, 0u, 0u, NULL }, 90u, 90u, 0u, (vader_array_buf_t*) &vader_data_9_buf,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_10_e0 = {
    { 806u, 0u, 0u, 0u, NULL }, 543u, 1696u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_10_e1 = {
    { 806u, 0u, 0u, 0u, NULL }, 544u, 1920u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_10_e2 = {
    { 806u, 0u, 0u, 0u, NULL }, 545u, 1965u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_10_e3 = {
    { 806u, 0u, 0u, 0u, NULL }, 546u, 1129u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_10_e4 = {
    { 806u, 0u, 0u, 0u, NULL }, 547u, 1856u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_10_e5 = {
    { 806u, 0u, 0u, 0u, NULL }, 548u, 1978u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_10_e6 = {
    { 806u, 0u, 0u, 0u, NULL }, 549u, 1796u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_10_e7 = {
    { 806u, 0u, 0u, 0u, NULL }, 550u, 1139u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_10_e8 = {
    { 806u, 0u, 0u, 0u, NULL }, 551u, 1112u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[9]; } vader_data_10_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 9u, 9u, 806u, 0u, { 0u, 0u, 0u },
    {
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_10_e0,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_10_e1,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_10_e2,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_10_e3,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_10_e4,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_10_e5,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_10_e6,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_10_e7,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_10_e8,
            },
        },
    },
};
const vader_array_t vader_data_10 = {
    { 73u, 0u, 0u, 0u, NULL }, 9u, 9u, 0u, (vader_array_buf_t*) &vader_data_10_buf,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_11_e0 = {
    { 806u, 0u, 0u, 0u, NULL }, 529u, 2431u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_11_e1 = {
    { 806u, 0u, 0u, 0u, NULL }, 530u, 2458u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_11_e2 = {
    { 806u, 0u, 0u, 0u, NULL }, 531u, 2453u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_11_e3 = {
    { 806u, 0u, 0u, 0u, NULL }, 532u, 1868u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_11_e4 = {
    { 806u, 0u, 0u, 0u, NULL }, 533u, 1866u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_11_e5 = {
    { 806u, 0u, 0u, 0u, NULL }, 534u, 1962u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_11_e6 = {
    { 806u, 0u, 0u, 0u, NULL }, 535u, 2260u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_11_e7 = {
    { 806u, 0u, 0u, 0u, NULL }, 536u, 2175u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_11_e8 = {
    { 806u, 0u, 0u, 0u, NULL }, 537u, 1860u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_11_e9 = {
    { 806u, 0u, 0u, 0u, NULL }, 538u, 1850u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_11_e10 = {
    { 806u, 0u, 0u, 0u, NULL }, 539u, 1845u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[11]; } vader_data_11_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 11u, 11u, 806u, 0u, { 0u, 0u, 0u },
    {
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_11_e0,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_11_e1,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_11_e2,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_11_e3,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_11_e4,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_11_e5,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_11_e6,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_11_e7,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_11_e8,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_11_e9,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_11_e10,
            },
        },
    },
};
const vader_array_t vader_data_11 = {
    { 73u, 0u, 0u, 0u, NULL }, 11u, 11u, 0u, (vader_array_buf_t*) &vader_data_11_buf,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e0 = {
    { 806u, 0u, 0u, 0u, NULL }, 566u, 2433u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e1 = {
    { 806u, 0u, 0u, 0u, NULL }, 567u, 1606u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e2 = {
    { 806u, 0u, 0u, 0u, NULL }, 568u, 1596u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e3 = {
    { 806u, 0u, 0u, 0u, NULL }, 569u, 1593u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e4 = {
    { 806u, 0u, 0u, 0u, NULL }, 570u, 1595u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e5 = {
    { 806u, 0u, 0u, 0u, NULL }, 571u, 1590u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e6 = {
    { 806u, 0u, 0u, 0u, NULL }, 572u, 1592u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e7 = {
    { 806u, 0u, 0u, 0u, NULL }, 573u, 1598u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e8 = {
    { 806u, 0u, 0u, 0u, NULL }, 574u, 2355u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e9 = {
    { 806u, 0u, 0u, 0u, NULL }, 575u, 2040u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e10 = {
    { 806u, 0u, 0u, 0u, NULL }, 576u, 2285u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e11 = {
    { 806u, 0u, 0u, 0u, NULL }, 577u, 1995u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e12 = {
    { 806u, 0u, 0u, 0u, NULL }, 578u, 1581u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e13 = {
    { 806u, 0u, 0u, 0u, NULL }, 579u, 2436u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e14 = {
    { 806u, 0u, 0u, 0u, NULL }, 580u, 1540u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e15 = {
    { 806u, 0u, 0u, 0u, NULL }, 581u, 1591u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e16 = {
    { 806u, 0u, 0u, 0u, NULL }, 582u, 1996u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e17 = {
    { 806u, 0u, 0u, 0u, NULL }, 583u, 2371u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e18 = {
    { 806u, 0u, 0u, 0u, NULL }, 584u, 1090u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e19 = {
    { 806u, 0u, 0u, 0u, NULL }, 585u, 1622u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e20 = {
    { 806u, 0u, 0u, 0u, NULL }, 586u, 346u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e21 = {
    { 806u, 0u, 0u, 0u, NULL }, 587u, 1203u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e22 = {
    { 806u, 0u, 0u, 0u, NULL }, 588u, 2349u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e23 = {
    { 806u, 0u, 0u, 0u, NULL }, 589u, 1144u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e24 = {
    { 806u, 0u, 0u, 0u, NULL }, 590u, 1870u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e25 = {
    { 806u, 0u, 0u, 0u, NULL }, 591u, 1621u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e26 = {
    { 806u, 0u, 0u, 0u, NULL }, 592u, 2139u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e27 = {
    { 806u, 0u, 0u, 0u, NULL }, 593u, 1048u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e28 = {
    { 806u, 0u, 0u, 0u, NULL }, 594u, 2635u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e29 = {
    { 806u, 0u, 0u, 0u, NULL }, 595u, 1509u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e30 = {
    { 806u, 0u, 0u, 0u, NULL }, 596u, 1466u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e31 = {
    { 806u, 0u, 0u, 0u, NULL }, 597u, 1204u,
};
const struct vader_struct_vader_diagnostics_CodeInfo_t vader_data_12_e32 = {
    { 806u, 0u, 0u, 0u, NULL }, 598u, 1086u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[33]; } vader_data_12_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 33u, 33u, 806u, 0u, { 0u, 0u, 0u },
    {
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e0,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e1,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e2,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e3,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e4,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e5,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e6,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e7,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e8,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e9,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e10,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e11,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e12,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e13,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e14,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e15,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e16,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e17,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e18,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e19,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e20,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e21,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e22,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e23,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e24,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e25,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e26,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e27,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e28,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e29,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e30,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e31,
            },
        },
        {
            806u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_diagnostics_CodeInfo_t*) &vader_data_12_e32,
            },
        },
    },
};
const vader_array_t vader_data_12 = {
    { 73u, 0u, 0u, 0u, NULL }, 33u, 33u, 0u, (vader_array_buf_t*) &vader_data_12_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[2]; } vader_data_13_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 243u, 0u, { 0u, 0u, 0u },
    { { 243u, 0u, { .s = 647u } }, { 243u, 0u, { .s = 2367u } } },
};
const vader_array_t vader_data_13 = {
    { 13u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_13_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[0]; } vader_data_14_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 0u, 0u, 1043u, 0u, { 0u, 0u, 0u }, { },
};
const vader_array_t vader_data_14 = {
    { 138u, 0u, 0u, 0u, NULL }, 0u, 0u, 0u, (vader_array_buf_t*) &vader_data_14_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[0]; } vader_data_15_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 0u, 0u, 1044u, 0u, { 0u, 0u, 0u }, { },
};
const vader_array_t vader_data_15 = {
    { 139u, 0u, 0u, 0u, NULL }, 0u, 0u, 0u, (vader_array_buf_t*) &vader_data_15_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[0]; } vader_data_16_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 0u, 0u, 204u, 0u, { 0u, 0u, 0u }, { },
};
const vader_array_t vader_data_16 = {
    { 10u, 0u, 0u, 0u, NULL }, 0u, 0u, 0u, (vader_array_buf_t*) &vader_data_16_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[0]; } vader_data_17_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 0u, 0u, 1535u, 0u, { 0u, 0u, 0u }, { },
};
const vader_array_t vader_data_17 = {
    { 204u, 0u, 0u, 0u, NULL }, 0u, 0u, 0u, (vader_array_buf_t*) &vader_data_17_buf,
};
const struct vader_struct_vader_types_PrimitiveType_t vader_data_18_e0 = {
    { 1086u, 0u, 0u, 0u, NULL }, 2050u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_18_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1086u, 0u, { 0u, 0u, 0u },
    {
        {
            1086u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveType_t*) &vader_data_18_e0 },
        },
    },
};
const vader_array_t vader_data_18 = {
    { 160u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_18_buf,
};
const struct vader_struct_vader_types_PrimitiveType_t vader_data_19_e0 = {
    { 1086u, 0u, 0u, 0u, NULL }, 2604u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_19_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1086u, 0u, { 0u, 0u, 0u },
    {
        {
            1086u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveType_t*) &vader_data_19_e0 },
        },
    },
};
const vader_array_t vader_data_19 = {
    { 160u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_19_buf,
};
const struct vader_struct_vader_types_AnyType_t vader_data_20_e0 = { { 1076u, 0u, 0u, 0u, NULL } };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_20_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1076u, 0u, { 0u, 0u, 0u },
    {
        {
            1076u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_AnyType_t*) &vader_data_20_e0 },
        },
    },
};
const vader_array_t vader_data_20 = {
    { 154u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_20_buf,
};
const struct vader_struct_vader_types_PrimitiveType_t vader_data_21_e0 = {
    { 1086u, 0u, 0u, 0u, NULL }, 1334u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_21_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1086u, 0u, { 0u, 0u, 0u },
    {
        {
            1086u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveType_t*) &vader_data_21_e0 },
        },
    },
};
const vader_array_t vader_data_21 = {
    { 160u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_21_buf,
};
const struct vader_struct_vader_types_UnresolvedType_t vader_data_22_e0 = {
    { 1094u, 0u, 0u, 0u, NULL },
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_22_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1094u, 0u, { 0u, 0u, 0u },
    {
        {
            1094u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_types_UnresolvedType_t*) &vader_data_22_e0,
            },
        },
    },
};
const vader_array_t vader_data_22 = {
    { 165u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_22_buf,
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e0 = {
    { 1085u, 0u, 0u, 0u, NULL }, 1793u, (int64_t) UINT64_C(1), (uint8_t) UINT64_C(1),
    (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e1 = {
    { 1085u, 0u, 0u, 0u, NULL }, 1748u, (int64_t) UINT64_C(2), (uint8_t) UINT64_C(1),
    (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e2 = {
    { 1085u, 0u, 0u, 0u, NULL }, 1749u, (int64_t) UINT64_C(4), (uint8_t) UINT64_C(1),
    (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e3 = {
    { 1085u, 0u, 0u, 0u, NULL }, 1771u, (int64_t) UINT64_C(8), (uint8_t) UINT64_C(1),
    (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e4 = {
    { 1085u, 0u, 0u, 0u, NULL }, 1876u, (int64_t) UINT64_C(8), (uint8_t) UINT64_C(1),
    (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e5 = {
    { 1085u, 0u, 0u, 0u, NULL }, 2420u, (int64_t) UINT64_C(1), (uint8_t) UINT64_C(1),
    (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e6 = {
    { 1085u, 0u, 0u, 0u, NULL }, 2399u, (int64_t) UINT64_C(2), (uint8_t) UINT64_C(1),
    (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e7 = {
    { 1085u, 0u, 0u, 0u, NULL }, 2400u, (int64_t) UINT64_C(4), (uint8_t) UINT64_C(1),
    (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e8 = {
    { 1085u, 0u, 0u, 0u, NULL }, 2410u, (int64_t) UINT64_C(8), (uint8_t) UINT64_C(1),
    (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e9 = {
    { 1085u, 0u, 0u, 0u, NULL }, 2463u, (int64_t) UINT64_C(8), (uint8_t) UINT64_C(1),
    (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e10 = {
    { 1085u, 0u, 0u, 0u, NULL }, 1628u, (int64_t) UINT64_C(4), (uint8_t) UINT64_C(0),
    (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e11 = {
    { 1085u, 0u, 0u, 0u, NULL }, 1630u, (int64_t) UINT64_C(8), (uint8_t) UINT64_C(0),
    (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e12 = {
    { 1085u, 0u, 0u, 0u, NULL }, 1334u, (int64_t) UINT64_C(1), (uint8_t) UINT64_C(0),
    (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e13 = {
    { 1085u, 0u, 0u, 0u, NULL }, 1443u, (int64_t) UINT64_C(4), (uint8_t) UINT64_C(0),
    (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e14 = {
    { 1085u, 0u, 0u, 0u, NULL }, 2261u, (int64_t) UINT64_C(4), (uint8_t) UINT64_C(0),
    (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(1),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e15 = {
    { 1085u, 0u, 0u, 0u, NULL }, 2604u, (int64_t) UINT64_C(0), (uint8_t) UINT64_C(0),
    (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e16 = {
    { 1085u, 0u, 0u, 0u, NULL }, 2050u, (int64_t) UINT64_C(0), (uint8_t) UINT64_C(0),
    (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_23_e17 = {
    { 1085u, 0u, 0u, 0u, NULL }, 455u, (int64_t) UINT64_C(8), (uint8_t) UINT64_C(0),
    (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(1),
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[18]; } vader_data_23_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 18u, 18u, 1085u, 0u, { 0u, 0u, 0u },
    {
        {
            1085u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e0 },
        },
        {
            1085u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e1 },
        },
        {
            1085u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e2 },
        },
        {
            1085u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e3 },
        },
        {
            1085u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e4 },
        },
        {
            1085u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e5 },
        },
        {
            1085u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e6 },
        },
        {
            1085u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e7 },
        },
        {
            1085u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e8 },
        },
        {
            1085u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e9 },
        },
        {
            1085u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e10,
            },
        },
        {
            1085u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e11,
            },
        },
        {
            1085u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e12,
            },
        },
        {
            1085u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e13,
            },
        },
        {
            1085u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e14,
            },
        },
        {
            1085u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e15,
            },
        },
        {
            1085u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e16,
            },
        },
        {
            1085u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_23_e17,
            },
        },
    },
};
const vader_array_t vader_data_23 = {
    { 159u, 0u, 0u, 0u, NULL }, 18u, 18u, 0u, (vader_array_buf_t*) &vader_data_23_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[2]; } vader_data_24_e0_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 0u, { 0u, 0u, 0u },
    { { 243u, 0u, { .s = 1836u } }, { 243u, 0u, { .s = 1749u } } },
};
const vader_array_t vader_data_24_e0 = {
    { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_24_e0_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[2]; } vader_data_24_e1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 0u, { 0u, 0u, 0u },
    { { 243u, 0u, { .s = 1948u } }, { 243u, 0u, { .s = 1771u } } },
};
const vader_array_t vader_data_24_e1 = {
    { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_24_e1_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[2]; } vader_data_24_e2_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 0u, { 0u, 0u, 0u },
    { { 243u, 0u, { .s = 1682u } }, { 243u, 0u, { .s = 1628u } } },
};
const vader_array_t vader_data_24_e2 = {
    { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_24_e2_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[2]; } vader_data_24_e3_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 0u, { 0u, 0u, 0u },
    { { 243u, 0u, { .s = 1535u } }, { 243u, 0u, { .s = 1630u } } },
};
const vader_array_t vader_data_24_e3 = {
    { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_24_e3_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[2]; } vader_data_24_e4_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 0u, { 0u, 0u, 0u },
    { { 243u, 0u, { .s = 1375u } }, { 243u, 0u, { .s = 2420u } } },
};
const vader_array_t vader_data_24_e4 = {
    { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_24_e4_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[5]; } vader_data_24_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 5u, 5u, 13u, 0u, { 0u, 0u, 0u },
    {
        { 13u, 0u, { .obj = (void*) (vader_array_t*) &vader_data_24_e0 } },
        { 13u, 0u, { .obj = (void*) (vader_array_t*) &vader_data_24_e1 } },
        { 13u, 0u, { .obj = (void*) (vader_array_t*) &vader_data_24_e2 } },
        { 13u, 0u, { .obj = (void*) (vader_array_t*) &vader_data_24_e3 } },
        { 13u, 0u, { .obj = (void*) (vader_array_t*) &vader_data_24_e4 } },
    },
};
const vader_array_t vader_data_24 = {
    { 1u, 0u, 0u, 0u, NULL }, 5u, 5u, 0u, (vader_array_buf_t*) &vader_data_24_buf,
};
const struct vader_struct_vader_types_TypeMetaType_t vader_data_25_e0 = {
    { 1091u, 0u, 0u, 0u, NULL },
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_25_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1091u, 0u, { 0u, 0u, 0u },
    {
        {
            1091u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_TypeMetaType_t*) &vader_data_25_e0 },
        },
    },
};
const vader_array_t vader_data_25 = {
    { 164u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_25_buf,
};
const struct vader_struct_vader_types_SelfType_t vader_data_26_e0 = { { 1087u, 0u, 0u, 0u, NULL } };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_26_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1087u, 0u, { 0u, 0u, 0u },
    {
        {
            1087u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_SelfType_t*) &vader_data_26_e0 },
        },
    },
};
const vader_array_t vader_data_26 = {
    { 161u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_26_buf,
};
const struct vader_struct_vader_types_PrimitiveType_t vader_data_27_e0 = {
    { 1086u, 0u, 0u, 0u, NULL }, 2261u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_27_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1086u, 0u, { 0u, 0u, 0u },
    {
        {
            1086u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveType_t*) &vader_data_27_e0 },
        },
    },
};
const vader_array_t vader_data_27 = {
    { 160u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_27_buf,
};
const struct vader_struct_vader_types_FreeCharType_t vader_data_28_e0 = {
    { 1081u, 0u, 0u, 0u, NULL },
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_28_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1081u, 0u, { 0u, 0u, 0u },
    {
        {
            1081u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_FreeCharType_t*) &vader_data_28_e0 },
        },
    },
};
const vader_array_t vader_data_28 = {
    { 155u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_28_buf,
};
const struct vader_struct_vader_types_FreeFloatType_t vader_data_29_e0 = {
    { 1082u, 0u, 0u, 0u, NULL },
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_29_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1082u, 0u, { 0u, 0u, 0u },
    {
        {
            1082u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_FreeFloatType_t*) &vader_data_29_e0 },
        },
    },
};
const vader_array_t vader_data_29 = {
    { 156u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_29_buf,
};
const struct vader_struct_vader_types_FreeIntType_t vader_data_30_e0 = {
    { 1083u, 0u, 0u, 0u, NULL },
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_30_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1083u, 0u, { 0u, 0u, 0u },
    {
        {
            1083u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_FreeIntType_t*) &vader_data_30_e0 },
        },
    },
};
const vader_array_t vader_data_30 = {
    { 157u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_30_buf,
};
const struct vader_struct_vader_types_NeverType_t vader_data_31_e0 = {
    { 1084u, 0u, 0u, 0u, NULL },
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_31_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1084u, 0u, { 0u, 0u, 0u },
    {
        {
            1084u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_NeverType_t*) &vader_data_31_e0 },
        },
    },
};
const vader_array_t vader_data_31 = {
    { 158u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_31_buf,
};
const struct vader_struct_vader_types_PrimitiveType_t vader_data_32_e0 = {
    { 1086u, 0u, 0u, 0u, NULL }, 455u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_32_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1086u, 0u, { 0u, 0u, 0u },
    {
        {
            1086u, 0u,
            { .obj = (void*) (struct vader_struct_vader_types_PrimitiveType_t*) &vader_data_32_e0 },
        },
    },
};
const vader_array_t vader_data_32 = {
    { 160u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_32_buf,
};
const struct vader_struct_vader_comptime_NullValue_t vader_data_33_e0 = {
    { 799u, 0u, 0u, 0u, NULL },
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_33_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 799u, 0u, { 0u, 0u, 0u },
    {
        {
            799u, 0u,
            { .obj = (void*) (struct vader_struct_vader_comptime_NullValue_t*) &vader_data_33_e0 },
        },
    },
};
const vader_array_t vader_data_33 = {
    { 71u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_33_buf,
};
const struct vader_struct_vader_comptime_BoolValue_t vader_data_34_e0 = {
    { 785u, 0u, 0u, 0u, NULL }, (uint8_t) UINT64_C(1),
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_34_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 785u, 0u, { 0u, 0u, 0u },
    {
        {
            785u, 0u,
            { .obj = (void*) (struct vader_struct_vader_comptime_BoolValue_t*) &vader_data_34_e0 },
        },
    },
};
const vader_array_t vader_data_34 = {
    { 68u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_34_buf,
};
const struct vader_struct_vader_comptime_BoolValue_t vader_data_35_e0 = {
    { 785u, 0u, 0u, 0u, NULL }, (uint8_t) UINT64_C(0),
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_35_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 785u, 0u, { 0u, 0u, 0u },
    {
        {
            785u, 0u,
            { .obj = (void*) (struct vader_struct_vader_comptime_BoolValue_t*) &vader_data_35_e0 },
        },
    },
};
const vader_array_t vader_data_35 = {
    { 68u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_35_buf,
};
const struct vader_struct_vader_lower_CfMentionKinds_t vader_data_36_e0 = {
    { 822u, 0u, 0u, 0u, NULL }, (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_36_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 822u, 0u, { 0u, 0u, 0u },
    {
        {
            822u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_lower_CfMentionKinds_t*) &vader_data_36_e0,
            },
        },
    },
};
const vader_array_t vader_data_36 = {
    { 80u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_36_buf,
};
const struct vader_struct_vader_lower_CfMentionKinds_t vader_data_37_e0 = {
    { 822u, 0u, 0u, 0u, NULL }, (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(1),
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_37_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 822u, 0u, { 0u, 0u, 0u },
    {
        {
            822u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_lower_CfMentionKinds_t*) &vader_data_37_e0,
            },
        },
    },
};
const vader_array_t vader_data_37 = {
    { 80u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_37_buf,
};
const struct vader_struct_vader_lower_CfMentionKinds_t vader_data_38_e0 = {
    { 822u, 0u, 0u, 0u, NULL }, (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(1),
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_38_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 822u, 0u, { 0u, 0u, 0u },
    {
        {
            822u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_lower_CfMentionKinds_t*) &vader_data_38_e0,
            },
        },
    },
};
const vader_array_t vader_data_38 = {
    { 80u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_38_buf,
};
const struct vader_struct_vader_lower_SplicedLanding_t vader_data_39_e0 = {
    { 908u, 0u, 0u, 0u, NULL }, (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0),
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_39_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 908u, 0u, { 0u, 0u, 0u },
    {
        {
            908u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_lower_SplicedLanding_t*) &vader_data_39_e0,
            },
        },
    },
};
const vader_array_t vader_data_39 = {
    { 100u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_39_buf,
};
const struct vader_struct_vader_lower_SplicedLanding_t vader_data_40_e0 = {
    { 908u, 0u, 0u, 0u, NULL }, (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(1),
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_40_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 908u, 0u, { 0u, 0u, 0u },
    {
        {
            908u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_lower_SplicedLanding_t*) &vader_data_40_e0,
            },
        },
    },
};
const vader_array_t vader_data_40 = {
    { 100u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_40_buf,
};
const struct vader_struct_vader_bytecode_BcRef_t vader_data_41_e0 = {
    { 558u, 0u, 0u, 0u, NULL }, 0u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_41_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 558u, 0u, { 0u, 0u, 0u },
    {
        {
            558u, 0u,
            { .obj = (void*) (struct vader_struct_vader_bytecode_BcRef_t*) &vader_data_41_e0 },
        },
    },
};
const vader_array_t vader_data_41 = {
    { 47u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_41_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[44]; } vader_data_42_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 44u, 44u, 243u, 0u, { 0u, 0u, 0u },
    {
        { 243u, 0u, { .s = 1316u } },
        { 243u, 0u, { .s = 1348u } },
        { 243u, 0u, { .s = 1435u } },
        { 243u, 0u, { .s = 1443u } },
        { 243u, 0u, { .s = 1484u } },
        { 243u, 0u, { .s = 1492u } },
        { 243u, 0u, { .s = 1514u } },
        { 243u, 0u, { .s = 1531u } },
        { 243u, 0u, { .s = 1535u } },
        { 243u, 0u, { .s = 1547u } },
        { 243u, 0u, { .s = 1559u } },
        { 243u, 0u, { .s = 1623u } },
        { 243u, 0u, { .s = 1682u } },
        { 243u, 0u, { .s = 1692u } },
        { 243u, 0u, { .s = 1735u } },
        { 243u, 0u, { .s = 1798u } },
        { 243u, 0u, { .s = 1828u } },
        { 243u, 0u, { .s = 1836u } },
        { 243u, 0u, { .s = 1948u } },
        { 243u, 0u, { .s = 2133u } },
        { 243u, 0u, { .s = 2143u } },
        { 243u, 0u, { .s = 2148u } },
        { 243u, 0u, { .s = 2177u } },
        { 243u, 0u, { .s = 2181u } },
        { 243u, 0u, { .s = 2187u } },
        { 243u, 0u, { .s = 2206u } },
        { 243u, 0u, { .s = 2281u } },
        { 243u, 0u, { .s = 2298u } },
        { 243u, 0u, { .s = 2392u } },
        { 243u, 0u, { .s = 2434u } },
        { 243u, 0u, { .s = 2451u } },
        { 243u, 0u, { .s = 2604u } },
        { 243u, 0u, { .s = 2607u } },
        { 243u, 0u, { .s = 2618u } },
        { 243u, 0u, { .s = 806u } },
        { 243u, 0u, { .s = 807u } },
        { 243u, 0u, { .s = 808u } },
        { 243u, 0u, { .s = 809u } },
        { 243u, 0u, { .s = 810u } },
        { 243u, 0u, { .s = 811u } },
        { 243u, 0u, { .s = 812u } },
        { 243u, 0u, { .s = 813u } },
        { 243u, 0u, { .s = 814u } },
        { 243u, 0u, { .s = 816u } },
    },
};
const vader_array_t vader_data_42 = {
    { 13u, 0u, 0u, 0u, NULL }, 44u, 44u, 0u, (vader_array_buf_t*) &vader_data_42_buf,
};
struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; int32_t slots[2]; } vader_data_43_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 246u, 7u, { 0u, 0u, 0u },
    { (int32_t) UINT64_C(18446744073709551615), (int32_t) UINT64_C(18446744073709551615) },
};
vader_array_t vader_data_43 = {
    { 14u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_43_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_44_e0_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(1) },
};
const vader_array_t vader_data_44_e0_f1 = {
    { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_44_e0_f1_buf,
};
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_44_e0 = {
    { 990u, 0u, 0u, 0u, NULL }, 2183u, (void*) (vader_array_t*) &vader_data_44_e0_f1, 2463u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_44_e1_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) },
};
const vader_array_t vader_data_44_e1_f1 = {
    { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_44_e1_f1_buf,
};
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_44_e1 = {
    { 990u, 0u, 0u, 0u, NULL }, 1234u, (void*) (vader_array_t*) &vader_data_44_e1_f1, 2463u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_44_e2_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) },
};
const vader_array_t vader_data_44_e2_f1 = {
    { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_44_e2_f1_buf,
};
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_44_e2 = {
    { 990u, 0u, 0u, 0u, NULL }, 2388u, (void*) (vader_array_t*) &vader_data_44_e2_f1, 2261u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_44_e3_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) },
};
const vader_array_t vader_data_44_e3_f1 = {
    { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_44_e3_f1_buf,
};
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_44_e3 = {
    { 990u, 0u, 0u, 0u, NULL }, 2386u, (void*) (vader_array_t*) &vader_data_44_e3_f1, 2261u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_44_e4_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) },
};
const vader_array_t vader_data_44_e4_f1 = {
    { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_44_e4_f1_buf,
};
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_44_e4 = {
    { 990u, 0u, 0u, 0u, NULL }, 1668u, (void*) (vader_array_t*) &vader_data_44_e4_f1, 2463u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_44_e5_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) },
};
const vader_array_t vader_data_44_e5_f1 = {
    { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_44_e5_f1_buf,
};
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_44_e5 = {
    { 990u, 0u, 0u, 0u, NULL }, 2599u, (void*) (vader_array_t*) &vader_data_44_e5_f1, 2463u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[2]; } vader_data_44_e6_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(1) },
};
const vader_array_t vader_data_44_e6_f1 = {
    { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_44_e6_f1_buf,
};
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_44_e6 = {
    { 990u, 0u, 0u, 0u, NULL }, 1670u, (void*) (vader_array_t*) &vader_data_44_e6_f1, 2463u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[2]; } vader_data_44_e7_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0) },
};
const vader_array_t vader_data_44_e7_f1 = {
    { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_44_e7_f1_buf,
};
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_44_e7 = {
    { 990u, 0u, 0u, 0u, NULL }, 2163u, (void*) (vader_array_t*) &vader_data_44_e7_f1, 1334u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_44_e8_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(1) },
};
const vader_array_t vader_data_44_e8_f1 = {
    { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_44_e8_f1_buf,
};
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_44_e8 = {
    { 990u, 0u, 0u, 0u, NULL }, 1676u, (void*) (vader_array_t*) &vader_data_44_e8_f1, 2261u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_44_e9_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(1) },
};
const vader_array_t vader_data_44_e9_f1 = {
    { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_44_e9_f1_buf,
};
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_44_e9 = {
    { 990u, 0u, 0u, 0u, NULL }, 2390u, (void*) (vader_array_t*) &vader_data_44_e9_f1, 2367u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_44_e10_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) },
};
const vader_array_t vader_data_44_e10_f1 = {
    { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_44_e10_f1_buf,
};
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_44_e10 = {
    { 990u, 0u, 0u, 0u, NULL }, 1675u, (void*) (vader_array_t*) &vader_data_44_e10_f1, 1667u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_44_e11_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) },
};
const vader_array_t vader_data_44_e11_f1 = {
    { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_44_e11_f1_buf,
};
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_44_e11 = {
    { 990u, 0u, 0u, 0u, NULL }, 2381u, (void*) (vader_array_t*) &vader_data_44_e11_f1, 2382u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[2]; } vader_data_44_e12_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(1) },
};
const vader_array_t vader_data_44_e12_f1 = {
    { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_44_e12_f1_buf,
};
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_44_e12 = {
    { 990u, 0u, 0u, 0u, NULL }, 1657u, (void*) (vader_array_t*) &vader_data_44_e12_f1, 2463u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[13]; } vader_data_44_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 13u, 13u, 990u, 0u, { 0u, 0u, 0u },
    {
        {
            990u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_44_e0,
            },
        },
        {
            990u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_44_e1,
            },
        },
        {
            990u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_44_e2,
            },
        },
        {
            990u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_44_e3,
            },
        },
        {
            990u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_44_e4,
            },
        },
        {
            990u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_44_e5,
            },
        },
        {
            990u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_44_e6,
            },
        },
        {
            990u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_44_e7,
            },
        },
        {
            990u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_44_e8,
            },
        },
        {
            990u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_44_e9,
            },
        },
        {
            990u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_44_e10,
            },
        },
        {
            990u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_44_e11,
            },
        },
        {
            990u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_44_e12,
            },
        },
    },
};
const vader_array_t vader_data_44 = {
    { 115u, 0u, 0u, 0u, NULL }, 13u, 13u, 0u, (vader_array_buf_t*) &vader_data_44_buf,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e0 = {
    { 1021u, 0u, 0u, 0u, NULL }, 1684u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e1 = {
    { 1021u, 0u, 0u, 0u, NULL }, 2281u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e2 = {
    { 1021u, 0u, 0u, 0u, NULL }, 1559u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e3 = {
    { 1021u, 0u, 0u, 0u, NULL }, 2356u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e4 = {
    { 1021u, 0u, 0u, 0u, NULL }, 1803u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e5 = {
    { 1021u, 0u, 0u, 0u, NULL }, 2375u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e6 = {
    { 1021u, 0u, 0u, 0u, NULL }, 1484u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e7 = {
    { 1021u, 0u, 0u, 0u, NULL }, 1813u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e8 = {
    { 1021u, 0u, 0u, 0u, NULL }, 2083u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e9 = {
    { 1021u, 0u, 0u, 0u, NULL }, 2376u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e10 = {
    { 1021u, 0u, 0u, 0u, NULL }, 1939u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e11 = {
    { 1021u, 0u, 0u, 0u, NULL }, 1324u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e12 = {
    { 1021u, 0u, 0u, 0u, NULL }, 1373u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e13 = {
    { 1021u, 0u, 0u, 0u, NULL }, 1372u,
};
const struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t vader_data_45_e14 = {
    { 1021u, 0u, 0u, 0u, NULL }, 2301u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[15]; } vader_data_45_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 15u, 15u, 1021u, 0u, { 0u, 0u, 0u },
    {
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e0,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e1,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e2,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e3,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e4,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e5,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e6,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e7,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e8,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e9,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e10,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e11,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e12,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e13,
            },
        },
        {
            1021u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) &vader_data_45_e14,
            },
        },
    },
};
const vader_array_t vader_data_45 = {
    { 126u, 0u, 0u, 0u, NULL }, 15u, 15u, 0u, (vader_array_buf_t*) &vader_data_45_buf,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[7]; } vader_data_46_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 7u, 7u, 243u, 0u, { 0u, 0u, 0u },
    {
        { 243u, 0u, { .s = 1749u } },
        { 243u, 0u, { .s = 1771u } },
        { 243u, 0u, { .s = 1630u } },
        { 243u, 0u, { .s = 1334u } },
        { 243u, 0u, { .s = 1443u } },
        { 243u, 0u, { .s = 2050u } },
        { 243u, 0u, { .s = 2127u } },
    },
};
const vader_array_t vader_data_46 = {
    { 13u, 0u, 0u, 0u, NULL }, 7u, 7u, 0u, (vader_array_buf_t*) &vader_data_46_buf,
};
const struct vader_struct_vader_vm_NullVal_t vader_data_47_e0 = { { 1107u, 0u, 0u, 0u, NULL } };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_47_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 1107u, 0u, { 0u, 0u, 0u },
    {
        {
            1107u, 0u,
            { .obj = (void*) (struct vader_struct_vader_vm_NullVal_t*) &vader_data_47_e0 },
        },
    },
};
const vader_array_t vader_data_47 = {
    { 171u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_47_buf,
};
const struct vader_struct_vader_c_emit_c_ast_CUnsized_t vader_data_48_e0 = {
    { 780u, 0u, 0u, 0u, NULL },
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_48_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 780u, 0u, { 0u, 0u, 0u },
    {
        {
            780u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_CUnsized_t*) &vader_data_48_e0,
            },
        },
    },
};
const vader_array_t vader_data_48 = {
    { 66u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_48_buf,
};
const struct vader_struct_vader_c_emit_c_ast_CNumber_t vader_data_49_e0 = {
    { 762u, 0u, 0u, 0u, NULL }, (int64_t) UINT64_C(0), (uint8_t) UINT64_C(1),
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_49_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 762u, 0u, { 0u, 0u, 0u },
    {
        {
            762u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_CNumber_t*) &vader_data_49_e0,
            },
        },
    },
};
const vader_array_t vader_data_49 = {
    { 62u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_49_buf,
};
const struct vader_struct_vader_c_emit_c_ast_CVerbatim_t vader_data_50_e0 = {
    { 781u, 0u, 0u, 0u, NULL }, 560u,
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[1]; } vader_data_50_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 781u, 0u, { 0u, 0u, 0u },
    {
        {
            781u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_CVerbatim_t*) &vader_data_50_e0,
            },
        },
    },
};
const vader_array_t vader_data_50 = {
    { 67u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_50_buf,
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e0 = {
    { 763u, 0u, 0u, 0u, NULL }, 268u, (int32_t) UINT64_C(10),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e1 = {
    { 763u, 0u, 0u, 0u, NULL }, 332u, (int32_t) UINT64_C(10),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e2 = {
    { 763u, 0u, 0u, 0u, NULL }, 209u, (int32_t) UINT64_C(10),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e3 = {
    { 763u, 0u, 0u, 0u, NULL }, 272u, (int32_t) UINT64_C(9),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e4 = {
    { 763u, 0u, 0u, 0u, NULL }, 293u, (int32_t) UINT64_C(9),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e5 = {
    { 763u, 0u, 0u, 0u, NULL }, 383u, (int32_t) UINT64_C(8),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e6 = {
    { 763u, 0u, 0u, 0u, NULL }, 406u, (int32_t) UINT64_C(8),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e7 = {
    { 763u, 0u, 0u, 0u, NULL }, 382u, (int32_t) UINT64_C(7),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e8 = {
    { 763u, 0u, 0u, 0u, NULL }, 384u, (int32_t) UINT64_C(7),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e9 = {
    { 763u, 0u, 0u, 0u, NULL }, 404u, (int32_t) UINT64_C(7),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e10 = {
    { 763u, 0u, 0u, 0u, NULL }, 405u, (int32_t) UINT64_C(7),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e11 = {
    { 763u, 0u, 0u, 0u, NULL }, 401u, (int32_t) UINT64_C(6),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e12 = {
    { 763u, 0u, 0u, 0u, NULL }, 175u, (int32_t) UINT64_C(6),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e13 = {
    { 763u, 0u, 0u, 0u, NULL }, 211u, (int32_t) UINT64_C(5),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e14 = {
    { 763u, 0u, 0u, 0u, NULL }, 802u, (int32_t) UINT64_C(4),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e15 = {
    { 763u, 0u, 0u, 0u, NULL }, 2649u, (int32_t) UINT64_C(3),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e16 = {
    { 763u, 0u, 0u, 0u, NULL }, 212u, (int32_t) UINT64_C(2),
};
const struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t vader_data_51_e17 = {
    { 763u, 0u, 0u, 0u, NULL }, 2650u, (int32_t) UINT64_C(1),
};
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[18]; } vader_data_51_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 18u, 18u, 763u, 0u, { 0u, 0u, 0u },
    {
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e0,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e1,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e2,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e3,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e4,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e5,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e6,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e7,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e8,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e9,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e10,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e11,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e12,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e13,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e14,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e15,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e16,
            },
        },
        {
            763u, 0u,
            {
                .obj = (void*) (struct vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) &vader_data_51_e17,
            },
        },
    },
};
const vader_array_t vader_data_51 = {
    { 63u, 0u, 0u, 0u, NULL }, 18u, 18u, 0u, (vader_array_buf_t*) &vader_data_51_buf,
};
vader_array_t* vader_global_const_arrays[] = { &vader_data_43 };
void* vader_global_const_objs[] = { &vader_data_43 };
vader_gc_frame_t vader_global_const_frame = {
    NULL, 0u, 0u, NULL, NULL, 1u, vader_global_const_objs,
};

static const uint16_t vader_fn_ptr_offsets[] = { offsetof(vader_fn_t, env) };
static const uint16_t vader_array_ptr_offsets[] = { offsetof(vader_array_t, buf) };

const vader_type_info_t vader_type_info_table[1669] = {
    [1] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [2] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [3] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [4] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [5] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [6] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [7] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [8] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [9] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [10] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [11] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [12] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [13] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [14] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [15] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [16] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [17] = { .slot_size = 16 },
    [18] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [19] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [20] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [21] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [22] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [23] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [24] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [25] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [26] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [27] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [28] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [29] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [30] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [31] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [32] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [33] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [34] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [35] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [36] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [37] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [38] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [39] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [40] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [41] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [42] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [43] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [44] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [45] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [46] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [47] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [48] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [49] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [50] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [51] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [52] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [53] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [54] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [55] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [56] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [57] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [58] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [59] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [60] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [61] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [62] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [63] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [64] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [65] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [66] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [67] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [68] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [69] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [70] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [71] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [72] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [73] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [74] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [75] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [76] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [77] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [78] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [79] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [80] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [81] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [82] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [83] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [84] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [85] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [86] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [87] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [88] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [89] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [90] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [91] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [92] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [93] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [94] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [95] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [96] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [97] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [98] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [99] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [100] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [101] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [102] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [103] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [104] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [105] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [106] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [107] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [108] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [109] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [110] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [111] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [112] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [113] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [114] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [115] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [116] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [117] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [118] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [119] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [120] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [121] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [122] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [123] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [124] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [125] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [126] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [127] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [128] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [129] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [130] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [131] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [132] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [133] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [134] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [135] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [136] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [137] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [138] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [139] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [140] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [141] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [142] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [143] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [144] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [145] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [146] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [147] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [148] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [149] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [150] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [151] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [152] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [153] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [154] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [155] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [156] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [157] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [158] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [159] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [160] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [161] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [162] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [163] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [164] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [165] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [166] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [167] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [168] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [169] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [170] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [171] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [172] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [173] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [174] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [175] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [176] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [177] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [178] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [179] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [180] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [181] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [182] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [183] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [184] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [185] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [186] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [187] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [188] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [189] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [190] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [191] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [192] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [193] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [194] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [195] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [196] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [197] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [198] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [199] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [200] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [201] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [202] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [203] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [204] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [205] = {
        .kind = VADER_TYPE_KIND_ARRAY, .size = sizeof(vader_array_t), .slot_size = 8,
        .ptr_offsets = vader_array_ptr_offsets, .ptr_count = 1,
    },
    [206] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [207] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [208] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [209] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [210] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [211] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [212] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [213] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [214] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [215] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [216] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [217] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [218] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [219] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [220] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [221] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [222] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [223] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [224] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [225] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [226] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [227] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [228] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [229] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [230] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [231] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [232] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [233] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [234] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [235] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [236] = {
        .kind = VADER_TYPE_KIND_FN, .size = sizeof(vader_fn_t), .slot_size = 8,
        .ptr_offsets = vader_fn_ptr_offsets, .ptr_count = 1,
    },
    [237] = { .slot_size = 1 },
    [238] = { .slot_size = 2 },
    [239] = { .slot_size = 4 },
    [240] = { .slot_size = 8 },
    [241] = { .slot_size = 1 },
    [242] = { .slot_size = 4 },
    [243] = { .slot_size = 16 },
    [245] = { .slot_size = 8 },
    [246] = { .slot_size = 4 },
    [247] = { .slot_size = 8 },
    [248] = { .slot_size = 8 },
    [249] = { .slot_size = 1 },
    [250] = { .slot_size = 2 },
    [251] = { .slot_size = 4 },
    [252] = { .slot_size = 8 },
    [253] = { .slot_size = 8 },
    [254] = { .slot_size = 16 },
    [255] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct__Cell_bool_t), .slot_size = 8,
    },
    [256] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct___Tuple_Array_u32_u32_6fc96a7e_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___Tuple_Array_u32_u32_6fc96a7e_t, f__0) },
        .ref_count = 1,
    },
    [257] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___Tuple_u64_u64_u64_2d035edd_t),
        .slot_size = 8,
    },
    [258] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___defer_env_std_io_1_t),
        .slot_size = 8,
    },
    [259] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct___lambda_env_vader_bytecode_1_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_bytecode_1_t, f_cap_0) },
        .ref_count = 1,
    },
    [260] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct___lambda_env_vader_bytecode_3_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_bytecode_3_t, f_cap_0) },
        .ref_count = 1,
    },
    [261] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_c_emit_1_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_c_emit_1_t, f_cap_0) },
        .ref_count = 1,
    },
    [262] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct___lambda_env_vader_c_emit_c_ast_1_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_c_emit_c_ast_1_t, f_cap_0) },
        .ref_count = 1,
    },
    [263] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_lower_1_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_lower_1_t, f_cap_0), offsetof(vader_struct___lambda_env_vader_lower_1_t, f_cap_1), offsetof(vader_struct___lambda_env_vader_lower_1_t, f_cap_2), offsetof(vader_struct___lambda_env_vader_lower_1_t, f_cap_3), offsetof(vader_struct___lambda_env_vader_lower_1_t, f_cap_4) },
        .ref_count = 5,
    },
    [264] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_lower_11_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_lower_11_t, f_cap_1) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_lower_11_t, f_cap_0) },
        .ref_count = 1,
    },
    [265] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_lower_13_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_lower_13_t, f_cap_0) },
        .ptr_count = 1,
    },
    [266] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_lower_15_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_lower_15_t, f_cap_0), offsetof(vader_struct___lambda_env_vader_lower_15_t, f_cap_1) },
        .ref_count = 2,
    },
    [267] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_lower_3_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_lower_3_t, f_cap_0), offsetof(vader_struct___lambda_env_vader_lower_3_t, f_cap_1) },
        .ref_count = 2,
    },
    [268] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_lower_5_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_lower_5_t, f_cap_0), offsetof(vader_struct___lambda_env_vader_lower_5_t, f_cap_1) },
        .ref_count = 2,
    },
    [269] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_lower_7_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_lower_7_t, f_cap_2) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_lower_7_t, f_cap_0), offsetof(vader_struct___lambda_env_vader_lower_7_t, f_cap_1) },
        .ref_count = 2,
    },
    [270] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_midir_1_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_midir_1_t, f_cap_1) },
        .ref_count = 1,
    },
    [271] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_midir_10_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_midir_10_t, f_cap_0), offsetof(vader_struct___lambda_env_vader_midir_10_t, f_cap_1) },
        .ref_count = 2,
    },
    [272] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_midir_12_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_midir_12_t, f_cap_0), offsetof(vader_struct___lambda_env_vader_midir_12_t, f_cap_1) },
        .ref_count = 2,
    },
    [273] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_midir_16_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_midir_16_t, f_cap_0) },
        .ref_count = 1,
    },
    [274] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_midir_19_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_midir_19_t, f_cap_0) },
        .ref_count = 1,
    },
    [275] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_midir_3_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_midir_3_t, f_cap_1) },
        .ref_count = 1,
    },
    [276] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_midir_5_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_midir_5_t, f_cap_0) },
        .ref_count = 1,
    },
    [277] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_midir_7_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_midir_7_t, f_cap_1) },
        .ref_count = 1,
    },
    [278] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct___lambda_env_vader_typecheck_1_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_typecheck_1_t, f_cap_0) },
        .ref_count = 1,
    },
    [279] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct___lambda_env_vader_typecheck_10_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_typecheck_10_t, f_cap_0) },
        .ref_count = 1,
    },
    [280] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct___lambda_env_vader_typecheck_12_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_typecheck_12_t, f_cap_0) },
        .ref_count = 1,
    },
    [281] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct___lambda_env_vader_typecheck_14_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_typecheck_14_t, f_cap_0) },
        .ref_count = 1,
    },
    [282] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct___lambda_env_vader_typecheck_18_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_typecheck_18_t, f_cap_0) },
        .ref_count = 1,
    },
    [283] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct___lambda_env_vader_typecheck_21_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_typecheck_21_t, f_cap_0) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_typecheck_21_t, f_cap_1) },
        .ref_count = 1,
    },
    [284] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct___lambda_env_vader_typecheck_5_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_typecheck_5_t, f_cap_1) },
        .ref_count = 1,
    },
    [285] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct___lambda_env_vader_typecheck_7_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_typecheck_7_t, f_cap_0), offsetof(vader_struct___lambda_env_vader_typecheck_7_t, f_cap_1) },
        .ref_count = 2,
    },
    [286] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct___lambda_env_vader_vm_2_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct___lambda_env_vader_vm_2_t, f_cap_0) },
        .ref_count = 1,
    },
    [287] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_json_JsonArray_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_json_JsonArray_t, f_items) },
        .ref_count = 1,
    },
    [288] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_json_JsonBool_t),
        .slot_size = 8,
    },
    [289] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_json_JsonError_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_json_JsonError_t, f_msg) },
        .string_count = 1,
    },
    [290] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_json_JsonNull_t),
        .slot_size = 8,
    },
    [291] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_json_JsonNumber_t),
        .slot_size = 8,
    },
    [292] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_json_JsonObject_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_json_JsonObject_t, f_entries) },
        .ref_count = 1,
    },
    [293] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_json_JsonString_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_json_JsonString_t, f_value) },
        .string_count = 1,
    },
    [294] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_json_Parser_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_json_Parser_t, f_src) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_json_Parser_t, f_bytes) },
        .ref_count = 1,
    },
    [295] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__Any_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__Any_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__Any_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__Any_t, f_index) },
        .ref_count = 3,
    },
    [296] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_index) },
        .ref_count = 3,
    },
    [297] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__Any___t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__Any___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__Any___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__Any___t, f_index) },
        .ref_count = 3,
    },
    [298] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__ArgBound___t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__ArgBound___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ArgBound___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ArgBound___t, f_index) },
        .ref_count = 3,
    },
    [299] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__ArrayClear___ArrayCopy___ArrayGet___ArrayLen___ArrayNew___ArrayPush___ArrayPushAll___ArrayRemoveLast___ArrayRepeat___ArraySet___ArraySlice___BitsToF32___BitsToF64___Block___BoolAnd___BoolConst___BoolEq___BoolNe___BoolNot___BoolOr___Branch___BranchIf___BufferNew___BufferToString___BufferWriteString___Call___CallImport___CallIndirect___CharConst___Convert___DataConst___DeferPopExec___DeferPush___Drop___Else___End___F32ToBits___F64Add___F64Const___F64Div___F64Eq___F64Ge___F64Gt___F64Le___F64Lt___F64Mul___F64Ne___F64Neg___F64Sub___F64ToBits___FnAddr___FnRef___I32Add___I32BitAnd___I32BitNot___I32BitOr___I32BitXor___I32Const___I32Div___I32Eq___I32Ge___I32Gt___I32Le___I32Lt___I32Mod___I32Mul___I32Ne___I32Neg___I32Shl___I32Shr___I32ShrU___I32Sub___I64Add___I64BitAnd___I64BitNot___I64BitOr___I64BitXor___I64Const___I64Div___I64Eq___I64Ge___I64Gt___I64Le___I64Lt___I64Mod___I64Mul___I64Ne___I64Neg___I64Shl___I64Shr___I64ShrU___I64Sub___If___LoadF64___LoadI32___LoadI64___LoadSlotF64___LoadSlotI32___LoadSlotI64___LoadU8___LocalField___LocalGet___LocalSet___LocalTee___Loop___MakeClosure___MemoryCopy___NullConst___RefCast___RefEq___RefNe___Retag___Return___ReturnLit___SizeOfType___StoreF64___StoreI32___StoreI64___StoreSlotF64___StoreSlotI32___StoreSlotI64___StoreU8___StringCompare___StringConst___StringEq___StringNe___StringSliceCodepoints___StructGet___StructNew___StructSet___TypeCheck___TypeConst___U32Div___U32Ge___U32Gt___U32Le___U32Lt___U32Mod___U64Div___U64Ge___U64Gt___U64Le___U64Lt___U64Mod___Unreachable___VirtualCall_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__ArrayClear___ArrayCopy___ArrayGet___ArrayLen___ArrayNew___ArrayPush___ArrayPushAll___ArrayRemoveLast___ArrayRepeat___ArraySet___ArraySlice___BitsToF32___BitsToF64___Block___BoolAnd___BoolConst___BoolEq___BoolNe___BoolNot___BoolOr___Branch___BranchIf___BufferNew___BufferToString___BufferWriteString___Call___CallImport___CallIndirect___CharConst___Convert___DataConst___DeferPopExec___DeferPush___Drop___Else___End___F32ToBits___F64Add___F64Const___F64Div___F64Eq___F64Ge___F64Gt___F64Le___F64Lt___F64Mul___F64Ne___F64Neg___F64Sub___F64ToBits___FnAddr___FnRef___I32Add___I32BitAnd___I32BitNot___I32BitOr___I32BitXor___I32Const___I32Div___I32Eq___I32Ge___I32Gt___I32Le___I32Lt___I32Mod___I32Mul___I32Ne___I32Neg___I32Shl___I32Shr___I32ShrU___I32Sub___I64Add___I64BitAnd___I64BitNot___I64BitOr___I64BitXor___I64Const___I64Div___I64Eq___I64Ge___I64Gt___I64Le___I64Lt___I64Mod___I64Mul___I64Ne___I64Neg___I64Shl___I64Shr___I64ShrU___I64Sub___If___LoadF64___LoadI32___LoadI64___LoadSlotF64___LoadSlotI32___LoadSlotI64___LoadU8___LocalField___LocalGet___LocalSet___LocalTee___Loop___MakeClosure___MemoryCopy___NullConst___RefCast___RefEq___RefNe___Retag___Return___ReturnLit___SizeOfType___StoreF64___StoreI32___StoreI64___StoreSlotF64___StoreSlotI32___StoreSlotI64___StoreU8___StringCompare___StringConst___StringEq___StringNe___StringSliceCodepoints___StructGet___StructNew___StructSet___TypeCheck___TypeConst___U32Div___U32Ge___U32Gt___U32Le___U32Lt___U32Mod___U64Div___U64Ge___U64Gt___U64Le___U64Lt___U64Mod___Unreachable___VirtualCall_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ArrayClear___ArrayCopy___ArrayGet___ArrayLen___ArrayNew___ArrayPush___ArrayPushAll___ArrayRemoveLast___ArrayRepeat___ArraySet___ArraySlice___BitsToF32___BitsToF64___Block___BoolAnd___BoolConst___BoolEq___BoolNe___BoolNot___BoolOr___Branch___BranchIf___BufferNew___BufferToString___BufferWriteString___Call___CallImport___CallIndirect___CharConst___Convert___DataConst___DeferPopExec___DeferPush___Drop___Else___End___F32ToBits___F64Add___F64Const___F64Div___F64Eq___F64Ge___F64Gt___F64Le___F64Lt___F64Mul___F64Ne___F64Neg___F64Sub___F64ToBits___FnAddr___FnRef___I32Add___I32BitAnd___I32BitNot___I32BitOr___I32BitXor___I32Const___I32Div___I32Eq___I32Ge___I32Gt___I32Le___I32Lt___I32Mod___I32Mul___I32Ne___I32Neg___I32Shl___I32Shr___I32ShrU___I32Sub___I64Add___I64BitAnd___I64BitNot___I64BitOr___I64BitXor___I64Const___I64Div___I64Eq___I64Ge___I64Gt___I64Le___I64Lt___I64Mod___I64Mul___I64Ne___I64Neg___I64Shl___I64Shr___I64ShrU___I64Sub___If___LoadF64___LoadI32___LoadI64___LoadSlotF64___LoadSlotI32___LoadSlotI64___LoadU8___LocalField___LocalGet___LocalSet___LocalTee___Loop___MakeClosure___MemoryCopy___NullConst___RefCast___RefEq___RefNe___Retag___Return___ReturnLit___SizeOfType___StoreF64___StoreI32___StoreI64___StoreSlotF64___StoreSlotI32___StoreSlotI64___StoreU8___StringCompare___StringConst___StringEq___StringNe___StringSliceCodepoints___StructGet___StructNew___StructSet___TypeCheck___TypeConst___U32Div___U32Ge___U32Gt___U32Le___U32Lt___U32Mod___U64Div___U64Ge___U64Gt___U64Le___U64Lt___U64Mod___Unreachable___VirtualCall_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ArrayClear___ArrayCopy___ArrayGet___ArrayLen___ArrayNew___ArrayPush___ArrayPushAll___ArrayRemoveLast___ArrayRepeat___ArraySet___ArraySlice___BitsToF32___BitsToF64___Block___BoolAnd___BoolConst___BoolEq___BoolNe___BoolNot___BoolOr___Branch___BranchIf___BufferNew___BufferToString___BufferWriteString___Call___CallImport___CallIndirect___CharConst___Convert___DataConst___DeferPopExec___DeferPush___Drop___Else___End___F32ToBits___F64Add___F64Const___F64Div___F64Eq___F64Ge___F64Gt___F64Le___F64Lt___F64Mul___F64Ne___F64Neg___F64Sub___F64ToBits___FnAddr___FnRef___I32Add___I32BitAnd___I32BitNot___I32BitOr___I32BitXor___I32Const___I32Div___I32Eq___I32Ge___I32Gt___I32Le___I32Lt___I32Mod___I32Mul___I32Ne___I32Neg___I32Shl___I32Shr___I32ShrU___I32Sub___I64Add___I64BitAnd___I64BitNot___I64BitOr___I64BitXor___I64Const___I64Div___I64Eq___I64Ge___I64Gt___I64Le___I64Lt___I64Mod___I64Mul___I64Ne___I64Neg___I64Shl___I64Shr___I64ShrU___I64Sub___If___LoadF64___LoadI32___LoadI64___LoadSlotF64___LoadSlotI32___LoadSlotI64___LoadU8___LocalField___LocalGet___LocalSet___LocalTee___Loop___MakeClosure___MemoryCopy___NullConst___RefCast___RefEq___RefNe___Retag___Return___ReturnLit___SizeOfType___StoreF64___StoreI32___StoreI64___StoreSlotF64___StoreSlotI32___StoreSlotI64___StoreU8___StringCompare___StringConst___StringEq___StringNe___StringSliceCodepoints___StructGet___StructNew___StructSet___TypeCheck___TypeConst___U32Div___U32Ge___U32Gt___U32Le___U32Lt___U32Mod___U64Div___U64Ge___U64Gt___U64Le___U64Lt___U64Mod___Unreachable___VirtualCall_t, f_index) },
        .ref_count = 3,
    },
    [300] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_index) },
        .ref_count = 3,
    },
    [301] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t, f_index) },
        .ref_count = 3,
    },
    [302] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__ClosureAlias_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__ClosureAlias_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ClosureAlias_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ClosureAlias_t, f_index) },
        .ref_count = 3,
    },
    [303] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__ConstDecl_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__ConstDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ConstDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ConstDecl_t, f_index) },
        .ref_count = 3,
    },
    [304] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__ConstFnWrap_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__ConstFnWrap_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ConstFnWrap_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ConstFnWrap_t, f_index) },
        .ref_count = 3,
    },
    [305] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__EnvSlot_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__EnvSlot_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__EnvSlot_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__EnvSlot_t, f_index) },
        .ref_count = 3,
    },
    [306] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__FnDecl_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__FnDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__FnDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__FnDecl_t, f_index) },
        .ref_count = 3,
    },
    [307] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__ImportInfo_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__ImportInfo_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ImportInfo_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ImportInfo_t, f_index) },
        .ref_count = 3,
    },
    [308] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t, f_index) },
        .ref_count = 3,
    },
    [309] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t, f_index) },
        .ref_count = 3,
    },
    [310] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__LoweredFnDecl_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__LoweredFnDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredFnDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredFnDecl_t, f_index) },
        .ref_count = 3,
    },
    [311] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__LoweredIdent_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__LoweredIdent_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredIdent_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredIdent_t, f_index) },
        .ref_count = 3,
    },
    [312] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t, f_index) },
        .ref_count = 3,
    },
    [313] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t, f_index) },
        .ref_count = 3,
    },
    [314] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t, f_index) },
        .ref_count = 3,
    },
    [315] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t, f_index) },
        .ref_count = 3,
    },
    [316] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t, f_index) },
        .ref_count = 3,
    },
    [317] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__MutableSet_usize__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_usize__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_usize__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_usize__t, f_index) },
        .ref_count = 3,
    },
    [318] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__NarrowSlot_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__NarrowSlot_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__NarrowSlot_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__NarrowSlot_t, f_index) },
        .ref_count = 3,
    },
    [319] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__ResolvedModule_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__ResolvedModule_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ResolvedModule_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ResolvedModule_t, f_index) },
        .ref_count = 3,
    },
    [320] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__StructDecl_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__StructDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__StructDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__StructDecl_t, f_index) },
        .ref_count = 3,
    },
    [321] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__StructType___t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__StructType___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__StructType___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__StructType___t, f_index) },
        .ref_count = 3,
    },
    [322] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__Symbol_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__Symbol_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__Symbol_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__Symbol_t, f_index) },
        .ref_count = 3,
    },
    [323] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__SymbolTarget_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__SymbolTarget_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__SymbolTarget_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__SymbolTarget_t, f_index) },
        .ref_count = 3,
    },
    [324] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__Symbol___t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__Symbol___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__Symbol___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__Symbol___t, f_index) },
        .ref_count = 3,
    },
    [325] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__TraitDecl_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__TraitDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__TraitDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__TraitDecl_t, f_index) },
        .ref_count = 3,
    },
    [326] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__TypeAliasDecl_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__TypeAliasDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__TypeAliasDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__TypeAliasDecl_t, f_index) },
        .ref_count = 3,
    },
    [327] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__TypeParamBound_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__TypeParamBound_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__TypeParamBound_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__TypeParamBound_t, f_index) },
        .ref_count = 3,
    },
    [328] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__bool_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__bool_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__bool_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__bool_t, f_index) },
        .ref_count = 3,
    },
    [329] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__i32_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__i32_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__i32_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__i32_t, f_index) },
        .ref_count = 3,
    },
    [330] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__i32___t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__i32___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__i32___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__i32___t, f_index) },
        .ref_count = 3,
    },
    [331] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__string_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__string_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__string_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__string_t, f_index) },
        .ref_count = 3,
    },
    [332] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__string___t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__string___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__string___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__string___t, f_index) },
        .ref_count = 3,
    },
    [333] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i32__usize_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i32__usize_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__usize_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__usize_t, f_index) },
        .ref_count = 3,
    },
    [334] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__i64__bool_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__i64__bool_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i64__bool_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i64__bool_t, f_index) },
        .ref_count = 3,
    },
    [335] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__Any_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__Any_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__Any_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__Any_t, f_index) },
        .ref_count = 3,
    },
    [336] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_index) },
        .ref_count = 3,
    },
    [337] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__Any___t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__Any___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__Any___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__Any___t, f_index) },
        .ref_count = 3,
    },
    [338] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__Any_____t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__Any_____t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__Any_____t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__Any_____t, f_index) },
        .ref_count = 3,
    },
    [339] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__ArrayMemberUse_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__ArrayMemberUse_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__ArrayMemberUse_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__ArrayMemberUse_t, f_index) },
        .ref_count = 3,
    },
    [340] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_index) },
        .ref_count = 3,
    },
    [341] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t, f_index) },
        .ref_count = 3,
    },
    [342] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__CFGModule_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__CFGModule_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__CFGModule_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__CFGModule_t, f_index) },
        .ref_count = 3,
    },
    [343] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__Capture___t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__Capture___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__Capture___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__Capture___t, f_index) },
        .ref_count = 3,
    },
    [344] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__DefaultThunk_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__DefaultThunk_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__DefaultThunk_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__DefaultThunk_t, f_index) },
        .ref_count = 3,
    },
    [345] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__DiscoveredModule_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__DiscoveredModule_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__DiscoveredModule_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__DiscoveredModule_t, f_index) },
        .ref_count = 3,
    },
    [346] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__EvaluatedProgram_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__EvaluatedProgram_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__EvaluatedProgram_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__EvaluatedProgram_t, f_index) },
        .ref_count = 3,
    },
    [347] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__FileScope_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__FileScope_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__FileScope_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__FileScope_t, f_index) },
        .ref_count = 3,
    },
    [348] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__FnCandidate___t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__FnCandidate___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__FnCandidate___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__FnCandidate___t, f_index) },
        .ref_count = 3,
    },
    [349] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__FnDecl_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__FnDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__FnDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__FnDecl_t, f_index) },
        .ref_count = 3,
    },
    [350] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__FnDecl___t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__FnDecl___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__FnDecl___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__FnDecl___t, f_index) },
        .ref_count = 3,
    },
    [351] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__GenericFnInstance_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__GenericFnInstance_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__GenericFnInstance_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__GenericFnInstance_t, f_index) },
        .ref_count = 3,
    },
    [352] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__GenericInstance_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__GenericInstance_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__GenericInstance_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__GenericInstance_t, f_index) },
        .ref_count = 3,
    },
    [353] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__ImplEntry___t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__ImplEntry___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__ImplEntry___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__ImplEntry___t, f_index) },
        .ref_count = 3,
    },
    [354] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__ImplMethod___t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__ImplMethod___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__ImplMethod___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__ImplMethod___t, f_index) },
        .ref_count = 3,
    },
    [355] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__ImplShape___t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__ImplShape___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__ImplShape___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__ImplShape___t, f_index) },
        .ref_count = 3,
    },
    [356] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__JsonArray___JsonBool___JsonNull___JsonNumber___JsonObject___JsonString_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__JsonArray___JsonBool___JsonNull___JsonNumber___JsonObject___JsonString_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__JsonArray___JsonBool___JsonNull___JsonNumber___JsonObject___JsonString_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__JsonArray___JsonBool___JsonNull___JsonNumber___JsonObject___JsonString_t, f_index) },
        .ref_count = 3,
    },
    [357] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__LoadedModule_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__LoadedModule_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__LoadedModule_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__LoadedModule_t, f_index) },
        .ref_count = 3,
    },
    [358] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t, f_index) },
        .ref_count = 3,
    },
    [359] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__LoweredFnDecl_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__LoweredFnDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__LoweredFnDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__LoweredFnDecl_t, f_index) },
        .ref_count = 3,
    },
    [360] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__LoweredModule_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__LoweredModule_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__LoweredModule_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__LoweredModule_t, f_index) },
        .ref_count = 3,
    },
    [361] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__LoweredStructDecl_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__LoweredStructDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__LoweredStructDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__LoweredStructDecl_t, f_index) },
        .ref_count = 3,
    },
    [362] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__MarkedLevel_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__MarkedLevel_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MarkedLevel_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MarkedLevel_t, f_index) },
        .ref_count = 3,
    },
    [363] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any__t, f_index) },
        .ref_count = 3,
    },
    [364] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any____t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any____t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any____t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any____t, f_index) },
        .ref_count = 3,
    },
    [365] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any______t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any______t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any______t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any______t, f_index) },
        .ref_count = 3,
    },
    [366] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t, f_index) },
        .ref_count = 3,
    },
    [367] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t, f_index) },
        .ref_count = 3,
    },
    [368] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t, f_index) },
        .ref_count = 3,
    },
    [369] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t, f_index) },
        .ref_count = 3,
    },
    [370] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t, f_index) },
        .ref_count = 3,
    },
    [371] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t, f_index) },
        .ref_count = 3,
    },
    [372] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_u64__BoundedImpl__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_u64__BoundedImpl__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_u64__BoundedImpl__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_u64__BoundedImpl__t, f_index) },
        .ref_count = 3,
    },
    [373] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_u64__Symbol__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_u64__Symbol__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_u64__Symbol__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_u64__Symbol__t, f_index) },
        .ref_count = 3,
    },
    [374] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__MutableSet_i32__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__MutableSet_i32__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableSet_i32__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableSet_i32__t, f_index) },
        .ref_count = 3,
    },
    [375] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__NarrowSlot_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__NarrowSlot_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__NarrowSlot_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__NarrowSlot_t, f_index) },
        .ref_count = 3,
    },
    [376] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__Span_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__Span_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__Span_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__Span_t, f_index) },
        .ref_count = 3,
    },
    [377] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__Symbol_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__Symbol_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__Symbol_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__Symbol_t, f_index) },
        .ref_count = 3,
    },
    [378] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__Symbol___t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__Symbol___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__Symbol___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__Symbol___t, f_index) },
        .ref_count = 3,
    },
    [379] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__TypedProgram_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__TypedProgram_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__TypedProgram_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__TypedProgram_t, f_index) },
        .ref_count = 3,
    },
    [380] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__ValType___t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__ValType___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__ValType___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__ValType___t, f_index) },
        .ref_count = 3,
    },
    [381] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______t, f_index) },
        .ref_count = 3,
    },
    [382] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string___AssertDecl___ConstDecl___EnumDecl___FnDecl___ImplDecl___ImportDecl___StructDecl___TraitDecl___TypeAliasDecl____t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string___AssertDecl___ConstDecl___EnumDecl___FnDecl___ImplDecl___ImportDecl___StructDecl___TraitDecl___TypeAliasDecl____t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string___AssertDecl___ConstDecl___EnumDecl___FnDecl___ImplDecl___ImportDecl___StructDecl___TraitDecl___TypeAliasDecl____t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string___AssertDecl___ConstDecl___EnumDecl___FnDecl___ImplDecl___ImportDecl___StructDecl___TraitDecl___TypeAliasDecl____t, f_index) },
        .ref_count = 3,
    },
    [383] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__bool_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__bool_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__bool_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__bool_t, f_index) },
        .ref_count = 3,
    },
    [384] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__i32_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__i32_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__i32_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__i32_t, f_index) },
        .ref_count = 3,
    },
    [385] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__i32___t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__i32___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__i32___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__i32___t, f_index) },
        .ref_count = 3,
    },
    [386] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__i64_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__i64_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__i64_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__i64_t, f_index) },
        .ref_count = 3,
    },
    [387] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__string_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__string_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__string_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__string_t, f_index) },
        .ref_count = 3,
    },
    [388] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__string___t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__string___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__string___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__string___t, f_index) },
        .ref_count = 3,
    },
    [389] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__string__usize_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__string__usize_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__usize_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__usize_t, f_index) },
        .ref_count = 3,
    },
    [390] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__Any_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__Any_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__Any_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__Any_t, f_index) },
        .ref_count = 3,
    },
    [391] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_index) },
        .ref_count = 3,
    },
    [392] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__Any___t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__Any___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__Any___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__Any___t, f_index) },
        .ref_count = 3,
    },
    [393] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__ArgEdge___t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__ArgEdge___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__ArgEdge___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__ArgEdge___t, f_index) },
        .ref_count = 3,
    },
    [394] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_index) },
        .ref_count = 3,
    },
    [395] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__BoundedImpl_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__BoundedImpl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__BoundedImpl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__BoundedImpl_t, f_index) },
        .ref_count = 3,
    },
    [396] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__ConstDecl_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__ConstDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__ConstDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__ConstDecl_t, f_index) },
        .ref_count = 3,
    },
    [397] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__ConstState_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__ConstState_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__ConstState_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__ConstState_t, f_index) },
        .ref_count = 3,
    },
    [398] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__ConsumerShape_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__ConsumerShape_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__ConsumerShape_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__ConsumerShape_t, f_index) },
        .ref_count = 3,
    },
    [399] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__GeneratorState_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__GeneratorState_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__GeneratorState_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__GeneratorState_t, f_index) },
        .ref_count = 3,
    },
    [400] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__ImplEntry_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__ImplEntry_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__ImplEntry_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__ImplEntry_t, f_index) },
        .ref_count = 3,
    },
    [401] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__InferableSlot_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__InferableSlot_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__InferableSlot_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__InferableSlot_t, f_index) },
        .ref_count = 3,
    },
    [402] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__MutableSet_Any__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__MutableSet_Any__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__MutableSet_Any__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__MutableSet_Any__t, f_index) },
        .ref_count = 3,
    },
    [403] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__MutableSet_i32__t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__MutableSet_i32__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__MutableSet_i32__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__MutableSet_i32__t, f_index) },
        .ref_count = 3,
    },
    [404] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__RootedEdge___t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__RootedEdge___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__RootedEdge___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__RootedEdge___t, f_index) },
        .ref_count = 3,
    },
    [405] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__Symbol_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__Symbol_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__Symbol_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__Symbol_t, f_index) },
        .ref_count = 3,
    },
    [406] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__bool_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__bool_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__bool_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__bool_t, f_index) },
        .ref_count = 3,
    },
    [407] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__i32_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__i32_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__i32_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__i32_t, f_index) },
        .ref_count = 3,
    },
    [408] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__u64__usize_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__u64__usize_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__usize_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__usize_t, f_index) },
        .ref_count = 3,
    },
    [409] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__Any_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__Any_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__Any_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__Any_t, f_index) },
        .ref_count = 3,
    },
    [410] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_index) },
        .ref_count = 3,
    },
    [411] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__Any___t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__Any___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__Any___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__Any___t, f_index) },
        .ref_count = 3,
    },
    [412] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__FnCandidate_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__FnCandidate_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__FnCandidate_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__FnCandidate_t, f_index) },
        .ref_count = 3,
    },
    [413] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__FnDeclRef___t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__FnDeclRef___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__FnDeclRef___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__FnDeclRef___t, f_index) },
        .ref_count = 3,
    },
    [414] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__ImplMethod_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__ImplMethod_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__ImplMethod_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__ImplMethod_t, f_index) },
        .ref_count = 3,
    },
    [415] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__ImplMethod___t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__ImplMethod___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__ImplMethod___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__ImplMethod___t, f_index) },
        .ref_count = 3,
    },
    [416] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t, f_index) },
        .ref_count = 3,
    },
    [417] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__NodeRecord_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__NodeRecord_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__NodeRecord_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__NodeRecord_t, f_index) },
        .ref_count = 3,
    },
    [418] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__Span_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__Span_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__Span_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__Span_t, f_index) },
        .ref_count = 3,
    },
    [419] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__StaticMember_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__StaticMember_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__StaticMember_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__StaticMember_t, f_index) },
        .ref_count = 3,
    },
    [420] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType____t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType____t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType____t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType____t, f_index) },
        .ref_count = 3,
    },
    [421] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__bool_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__bool_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__bool_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__bool_t, f_index) },
        .ref_count = 3,
    },
    [422] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__i32_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__i32_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__i32_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__i32_t, f_index) },
        .ref_count = 3,
    },
    [423] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__string_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__string_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__string_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__string_t, f_index) },
        .ref_count = 3,
    },
    [424] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableMap__usize__usize_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableMap__usize__usize_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__usize_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__usize_t, f_index) },
        .ref_count = 3,
    },
    [425] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableSet__i32_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableSet__i32_t, f_inner) },
        .ref_count = 1,
    },
    [426] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableSet__i64_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableSet__i64_t, f_inner) },
        .ref_count = 1,
    },
    [427] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableSet__string_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableSet__string_t, f_inner) },
        .ref_count = 1,
    },
    [428] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableSet__u64_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableSet__u64_t, f_inner) },
        .ref_count = 1,
    },
    [429] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_collections_MutableSet__usize_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_collections_MutableSet__usize_t, f_inner) },
        .ref_count = 1,
    },
    [430] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_std_core_Buffer_t),
        .slot_size = 8,
    },
    [431] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_std_core_Dec64_t),
        .slot_size = 8,
    },
    [432] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_std_core_DecimalParts_t),
        .slot_size = 8,
    },
    [433] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_std_core_FloatDec32_t),
        .slot_size = 8,
    },
    [434] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_std_core_SlowParts_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_core_SlowParts_t, f_d) },
        .ref_count = 1,
    },
    [435] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_std_io_IOError_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_std_io_IOError_t, f_msg) },
        .string_count = 1,
    },
    [436] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_std_string_ParseError_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_std_string_ParseError_t, f_msg) },
        .string_count = 1,
    },
    [437] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_std_string_StringChars_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_string_StringChars_t, f_bytes) },
        .ref_count = 1,
    },
    [438] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_std_string_builder_StringBuilder_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_std_string_builder_StringBuilder_t, f_parts) },
        .ref_count = 1,
    },
    [439] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ArrayTypeExpr_t, f_element) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span) },
        .ref_count = 1,
    },
    [440] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_AsBinding_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_AsBinding_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_AsBinding_t, f_span) },
        .ref_count = 1,
    },
    [441] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_AssertDecl_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_AssertDecl_t, f_condition), offsetof(vader_struct_toolchain_ast_AssertDecl_t, f_message) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_AssertDecl_t, f_span), offsetof(vader_struct_toolchain_ast_AssertDecl_t, f_decorators) },
        .ref_count = 2,
    },
    [442] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_AssignStmt_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_AssignStmt_t, f_target), offsetof(vader_struct_toolchain_ast_AssignStmt_t, f_value) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_AssignStmt_t, f_span) },
        .ref_count = 1,
    },
    [443] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_AwaitExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_AwaitExpr_t, f_inner) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_AwaitExpr_t, f_span) },
        .ref_count = 1,
    },
    [444] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_BinaryExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_BinaryExpr_t, f_left), offsetof(vader_struct_toolchain_ast_BinaryExpr_t, f_right), offsetof(vader_struct_toolchain_ast_BinaryExpr_t, f_bind_as) },
        .ptr_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_BinaryExpr_t, f_span) },
        .ref_count = 1,
    },
    [445] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_BlockExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_BlockExpr_t, f_trailing) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_BlockExpr_t, f_span), offsetof(vader_struct_toolchain_ast_BlockExpr_t, f_stmts) },
        .ref_count = 2,
    },
    [446] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_BoolLitExpr_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_BoolLitExpr_t, f_span) },
        .ref_count = 1,
    },
    [447] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_BreakStmt_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_BreakStmt_t, f_label) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_BreakStmt_t, f_span) },
        .ref_count = 1,
    },
    [448] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_CallArg_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_CallArg_t, f_name), offsetof(vader_struct_toolchain_ast_CallArg_t, f_value) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_CallArg_t, f_span) },
        .ref_count = 1,
    },
    [449] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_CallExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_CallExpr_t, f_callee) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_CallExpr_t, f_span), offsetof(vader_struct_toolchain_ast_CallExpr_t, f_args) },
        .ref_count = 2,
    },
    [450] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_CastExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_CastExpr_t, f_target), offsetof(vader_struct_toolchain_ast_CastExpr_t, f_value) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_CastExpr_t, f_span) },
        .ref_count = 1,
    },
    [451] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_CharLitExpr_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_CharLitExpr_t, f_span) },
        .ref_count = 1,
    },
    [452] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_ConstDecl_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_ty), offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_value), offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_comptime_body) },
        .ptr_count = 3,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_span), offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_name_span), offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_decorators) },
        .ref_count = 3,
    },
    [453] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_ContinueStmt_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ContinueStmt_t, f_label) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ContinueStmt_t, f_span) },
        .ref_count = 1,
    },
    [454] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_Decorator_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_Decorator_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_Decorator_t, f_span), offsetof(vader_struct_toolchain_ast_Decorator_t, f_args) },
        .ref_count = 2,
    },
    [455] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_DeferBlockBody_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_DeferBlockBody_t, f_block) },
        .ref_count = 1,
    },
    [456] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_DeferStmt_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_DeferStmt_t, f_body) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_DeferStmt_t, f_span) },
        .ref_count = 1,
    },
    [457] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_DeferStmtBody_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_DeferStmtBody_t, f_stmt) },
        .ptr_count = 1,
    },
    [458] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_toolchain_ast_DestructureAssignStmt_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_DestructureAssignStmt_t, f_value) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_DestructureAssignStmt_t, f_span), offsetof(vader_struct_toolchain_ast_DestructureAssignStmt_t, f_targets) },
        .ref_count = 2,
    },
    [459] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_toolchain_ast_DestructureImport_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_DestructureImport_t, f_names) },
        .ref_count = 1,
    },
    [460] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_DestructureVar_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_DestructureVar_t, f_pattern) },
        .ptr_count = 1,
    },
    [461] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_DiscardVar_t),
        .slot_size = 8,
    },
    [462] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_DotVariantExpr_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_DotVariantExpr_t, f_variant) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_DotVariantExpr_t, f_span), offsetof(vader_struct_toolchain_ast_DotVariantExpr_t, f_variant_span) },
        .ref_count = 2,
    },
    [463] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_EnumDecl_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_EnumDecl_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_EnumDecl_t, f_span), offsetof(vader_struct_toolchain_ast_EnumDecl_t, f_name_span), offsetof(vader_struct_toolchain_ast_EnumDecl_t, f_header), offsetof(vader_struct_toolchain_ast_EnumDecl_t, f_variants), offsetof(vader_struct_toolchain_ast_EnumDecl_t, f_decorators) },
        .ref_count = 5,
    },
    [464] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_EnumVariant_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_EnumVariant_t, f_value), offsetof(vader_struct_toolchain_ast_EnumVariant_t, f_value_span), offsetof(vader_struct_toolchain_ast_EnumVariant_t, f_data) },
        .ptr_count = 3,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_EnumVariant_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_EnumVariant_t, f_span) },
        .ref_count = 1,
    },
    [465] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_toolchain_ast_EnumVariantPattern_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_EnumVariantPattern_t, f_variant) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_EnumVariantPattern_t, f_span) },
        .ref_count = 1,
    },
    [466] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_ExprStmt_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ExprStmt_t, f_expr) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ExprStmt_t, f_span) },
        .ref_count = 1,
    },
    [467] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_FieldExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_FieldExpr_t, f_target) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_FieldExpr_t, f_field) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_FieldExpr_t, f_span), offsetof(vader_struct_toolchain_ast_FieldExpr_t, f_field_span) },
        .ref_count = 2,
    },
    [468] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_FloatLitExpr_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_FloatLitExpr_t, f_span) },
        .ref_count = 1,
    },
    [469] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_FnDecl_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_FnDecl_t, f_return_type), offsetof(vader_struct_toolchain_ast_FnDecl_t, f_body) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_FnDecl_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_FnDecl_t, f_span), offsetof(vader_struct_toolchain_ast_FnDecl_t, f_name_span), offsetof(vader_struct_toolchain_ast_FnDecl_t, f_type_params), offsetof(vader_struct_toolchain_ast_FnDecl_t, f_params), offsetof(vader_struct_toolchain_ast_FnDecl_t, f_decorators) },
        .ref_count = 5,
    },
    [470] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_FnParam_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_FnParam_t, f_ty), offsetof(vader_struct_toolchain_ast_FnParam_t, f_default_value) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_FnParam_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_FnParam_t, f_span), offsetof(vader_struct_toolchain_ast_FnParam_t, f_decorators) },
        .ref_count = 2,
    },
    [471] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_FnTypeExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_FnTypeExpr_t, f_return_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_FnTypeExpr_t, f_span), offsetof(vader_struct_toolchain_ast_FnTypeExpr_t, f_params), offsetof(vader_struct_toolchain_ast_FnTypeExpr_t, f_params_mutable) },
        .ref_count = 3,
    },
    [472] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_ForStmt_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ForStmt_t, f_label), offsetof(vader_struct_toolchain_ast_ForStmt_t, f_form) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ForStmt_t, f_span), offsetof(vader_struct_toolchain_ast_ForStmt_t, f_body) },
        .ref_count = 2,
    },
    [473] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_toolchain_ast_GenericInstExpr_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_GenericInstExpr_t, f_callee) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_GenericInstExpr_t, f_span), offsetof(vader_struct_toolchain_ast_GenericInstExpr_t, f_type_args) },
        .ref_count = 2,
    },
    [474] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_IdentExpr_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_IdentExpr_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_IdentExpr_t, f_span) },
        .ref_count = 1,
    },
    [475] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_IfElseBlock_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_IfElseBlock_t, f_block) },
        .ref_count = 1,
    },
    [476] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_IfElseIf_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_IfElseIf_t, f_branch) },
        .ref_count = 1,
    },
    [477] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_IfExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_IfExpr_t, f_cond), offsetof(vader_struct_toolchain_ast_IfExpr_t, f_else_branch) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_IfExpr_t, f_span), offsetof(vader_struct_toolchain_ast_IfExpr_t, f_then_block) },
        .ref_count = 2,
    },
    [478] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_ImplDecl_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_for_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_trait_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_span), offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_type_params), offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_trait_name_span), offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_trait_args), offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_members), offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_decorators) },
        .ref_count = 6,
    },
    [479] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_ImportDecl_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ImportDecl_t, f_binding) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ImportDecl_t, f_path) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ImportDecl_t, f_span), offsetof(vader_struct_toolchain_ast_ImportDecl_t, f_decorators) },
        .ref_count = 2,
    },
    [480] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_ImportName_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ImportName_t, f_alias) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ImportName_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ImportName_t, f_span) },
        .ref_count = 1,
    },
    [481] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_InFor_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_InFor_t, f_loop_var), offsetof(vader_struct_toolchain_ast_InFor_t, f_iter) },
        .ptr_count = 2,
    },
    [482] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_IndexExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_IndexExpr_t, f_target), offsetof(vader_struct_toolchain_ast_IndexExpr_t, f_index) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_IndexExpr_t, f_span) },
        .ref_count = 1,
    },
    [483] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_InfiniteFor_t),
        .slot_size = 8,
    },
    [484] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_IntLitExpr_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_IntLitExpr_t, f_span) },
        .ref_count = 1,
    },
    [485] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_toolchain_ast_IntrinsicCallExpr_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_IntrinsicCallExpr_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_IntrinsicCallExpr_t, f_span), offsetof(vader_struct_toolchain_ast_IntrinsicCallExpr_t, f_name_span), offsetof(vader_struct_toolchain_ast_IntrinsicCallExpr_t, f_args) },
        .ref_count = 3,
    },
    [486] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_IsPattern_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_IsPattern_t, f_ty), offsetof(vader_struct_toolchain_ast_IsPattern_t, f_inner) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_IsPattern_t, f_span) },
        .ref_count = 1,
    },
    [487] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_LambdaExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_LambdaExpr_t, f_return_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_LambdaExpr_t, f_span), offsetof(vader_struct_toolchain_ast_LambdaExpr_t, f_params), offsetof(vader_struct_toolchain_ast_LambdaExpr_t, f_body) },
        .ref_count = 3,
    },
    [488] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_LetStmt_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_LetStmt_t, f_binding), offsetof(vader_struct_toolchain_ast_LetStmt_t, f_ty), offsetof(vader_struct_toolchain_ast_LetStmt_t, f_value) },
        .ptr_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_LetStmt_t, f_span) },
        .ref_count = 1,
    },
    [489] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_LiteralPattern_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_LiteralPattern_t, f_value) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_LiteralPattern_t, f_span) },
        .ref_count = 1,
    },
    [490] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_MatchArm_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_MatchArm_t, f_pattern), offsetof(vader_struct_toolchain_ast_MatchArm_t, f_guard), offsetof(vader_struct_toolchain_ast_MatchArm_t, f_body) },
        .ptr_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_MatchArm_t, f_span) },
        .ref_count = 1,
    },
    [491] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_MatchExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_MatchExpr_t, f_scrutinee), offsetof(vader_struct_toolchain_ast_MatchExpr_t, f_bind_as) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_MatchExpr_t, f_span), offsetof(vader_struct_toolchain_ast_MatchExpr_t, f_arms) },
        .ref_count = 2,
    },
    [492] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_ModuleDecl_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ModuleDecl_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ModuleDecl_t, f_span), offsetof(vader_struct_toolchain_ast_ModuleDecl_t, f_name_span) },
        .ref_count = 2,
    },
    [493] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_toolchain_ast_MutableTypeExpr_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_MutableTypeExpr_t, f_inner) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_MutableTypeExpr_t, f_span) },
        .ref_count = 1,
    },
    [494] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_toolchain_ast_NamedNamespaceImport_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_NamedNamespaceImport_t, f_name) },
        .string_count = 1,
    },
    [495] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_NamedVar_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_NamedVar_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_NamedVar_t, f_span) },
        .ref_count = 1,
    },
    [496] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_toolchain_ast_NullCoalesceExpr_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_NullCoalesceExpr_t, f_left), offsetof(vader_struct_toolchain_ast_NullCoalesceExpr_t, f_fallback) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_NullCoalesceExpr_t, f_span) },
        .ref_count = 1,
    },
    [497] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_NullLitExpr_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_NullLitExpr_t, f_span) },
        .ref_count = 1,
    },
    [498] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_OrPattern_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_OrPattern_t, f_span), offsetof(vader_struct_toolchain_ast_OrPattern_t, f_patterns) },
        .ref_count = 2,
    },
    [499] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_PatternBinding_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_PatternBinding_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_PatternBinding_t, f_span) },
        .ref_count = 1,
    },
    [500] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_PatternLiteral_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_PatternLiteral_t, f_value) },
        .ptr_count = 1,
    },
    [501] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_PlaceTarget_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_PlaceTarget_t, f_place) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_PlaceTarget_t, f_span) },
        .ref_count = 1,
    },
    [502] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_Program_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_Program_t, f_module) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_Program_t, f_file) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_Program_t, f_span), offsetof(vader_struct_toolchain_ast_Program_t, f_decls) },
        .ref_count = 2,
    },
    [503] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_RangeExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_RangeExpr_t, f_lower), offsetof(vader_struct_toolchain_ast_RangeExpr_t, f_upper) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_RangeExpr_t, f_span) },
        .ref_count = 1,
    },
    [504] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_RangePattern_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_RangePattern_t, f_lower), offsetof(vader_struct_toolchain_ast_RangePattern_t, f_upper) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_RangePattern_t, f_span) },
        .ref_count = 1,
    },
    [505] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_RestBinding_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_RestBinding_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_RestBinding_t, f_span), offsetof(vader_struct_toolchain_ast_RestBinding_t, f_name_span) },
        .ref_count = 2,
    },
    [506] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_RestTarget_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_RestTarget_t, f_place) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_RestTarget_t, f_span) },
        .ref_count = 1,
    },
    [507] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_ReturnStmt_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ReturnStmt_t, f_value) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_ReturnStmt_t, f_span) },
        .ref_count = 1,
    },
    [508] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_SeqLitExpr_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_SeqLitExpr_t, f_span), offsetof(vader_struct_toolchain_ast_SeqLitExpr_t, f_elements) },
        .ref_count = 2,
    },
    [509] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_SimpleBinding_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_SimpleBinding_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_SimpleBinding_t, f_span), offsetof(vader_struct_toolchain_ast_SimpleBinding_t, f_name_span) },
        .ref_count = 2,
    },
    [510] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_StringLitExpr_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StringLitExpr_t, f_span), offsetof(vader_struct_toolchain_ast_StringLitExpr_t, f_parts) },
        .ref_count = 2,
    },
    [511] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_toolchain_ast_StringLitInterp_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StringLitInterp_t, f_expr) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StringLitInterp_t, f_span) },
        .ref_count = 1,
    },
    [512] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_StringLitText_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StringLitText_t, f_value) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StringLitText_t, f_span) },
        .ref_count = 1,
    },
    [513] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_StructDecl_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructDecl_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructDecl_t, f_span), offsetof(vader_struct_toolchain_ast_StructDecl_t, f_name_span), offsetof(vader_struct_toolchain_ast_StructDecl_t, f_type_params), offsetof(vader_struct_toolchain_ast_StructDecl_t, f_fields), offsetof(vader_struct_toolchain_ast_StructDecl_t, f_decorators) },
        .ref_count = 5,
    },
    [514] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_StructField_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructField_t, f_ty), offsetof(vader_struct_toolchain_ast_StructField_t, f_default_v) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructField_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructField_t, f_span) },
        .ref_count = 1,
    },
    [515] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_StructLitExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructLitExpr_t, f_type_name) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructLitExpr_t, f_span), offsetof(vader_struct_toolchain_ast_StructLitExpr_t, f_items) },
        .ref_count = 2,
    },
    [516] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_StructLitField_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructLitField_t, f_value) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructLitField_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructLitField_t, f_span), offsetof(vader_struct_toolchain_ast_StructLitField_t, f_name_span) },
        .ref_count = 2,
    },
    [517] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_toolchain_ast_StructLitSpread_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructLitSpread_t, f_expr) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructLitSpread_t, f_span) },
        .ref_count = 1,
    },
    [518] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_StructPattern_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructPattern_t, f_span), offsetof(vader_struct_toolchain_ast_StructPattern_t, f_fields) },
        .ref_count = 2,
    },
    [519] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_toolchain_ast_StructPatternField_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructPatternField_t, f_value) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructPatternField_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_StructPatternField_t, f_span), offsetof(vader_struct_toolchain_ast_StructPatternField_t, f_name_span) },
        .ref_count = 2,
    },
    [520] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_TraitDecl_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_requires) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_span), offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_name_span), offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_type_params), offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_members), offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_decorators) },
        .ref_count = 5,
    },
    [521] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_TupleBinding_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_TupleBinding_t, f_span), offsetof(vader_struct_toolchain_ast_TupleBinding_t, f_elements) },
        .ref_count = 2,
    },
    [522] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_TypeAliasDecl_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_TypeAliasDecl_t, f_aliased) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_TypeAliasDecl_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_TypeAliasDecl_t, f_span), offsetof(vader_struct_toolchain_ast_TypeAliasDecl_t, f_name_span), offsetof(vader_struct_toolchain_ast_TypeAliasDecl_t, f_type_params), offsetof(vader_struct_toolchain_ast_TypeAliasDecl_t, f_decorators) },
        .ref_count = 4,
    },
    [523] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_TypeParam_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_TypeParam_t, f_bound), offsetof(vader_struct_toolchain_ast_TypeParam_t, f_default_v) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_TypeParam_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_TypeParam_t, f_span) },
        .ref_count = 1,
    },
    [524] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_UnaryExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_UnaryExpr_t, f_operand) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_UnaryExpr_t, f_span) },
        .ref_count = 1,
    },
    [525] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_WhileFor_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_WhileFor_t, f_cond) },
        .ptr_count = 1,
    },
    [526] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_toolchain_ast_WildcardBinding_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_WildcardBinding_t, f_span) },
        .ref_count = 1,
    },
    [527] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_WildcardImport_t),
        .slot_size = 8,
    },
    [528] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_toolchain_ast_WildcardPattern_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_WildcardPattern_t, f_span) },
        .ref_count = 1,
    },
    [529] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_WildcardTarget_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_WildcardTarget_t, f_span) },
        .ref_count = 1,
    },
    [530] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_ast_YieldStmt_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_YieldStmt_t, f_value) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_ast_YieldStmt_t, f_span) },
        .ref_count = 1,
    },
    [531] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_span_Position_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_span_Position_t, f_file) },
        .string_count = 1,
    },
    [532] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_toolchain_span_Span_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_toolchain_span_Span_t, f_start), offsetof(vader_struct_toolchain_span_Span_t, f_end) },
        .ref_count = 2,
    },
    [533] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bootstrap_CfgBytecode_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bootstrap_CfgBytecode_t, f_entry) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bootstrap_CfgBytecode_t, f_pre_diags), offsetof(vader_struct_vader_bootstrap_CfgBytecode_t, f_lower_diags), offsetof(vader_struct_vader_bootstrap_CfgBytecode_t, f_module) },
        .ref_count = 3,
    },
    [534] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_bootstrap_EvaluatedPipeline_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bootstrap_EvaluatedPipeline_t, f_loaded), offsetof(vader_struct_vader_bootstrap_EvaluatedPipeline_t, f_typed), offsetof(vader_struct_vader_bootstrap_EvaluatedPipeline_t, f_evaluated), offsetof(vader_struct_vader_bootstrap_EvaluatedPipeline_t, f_resolver_diags), offsetof(vader_struct_vader_bootstrap_EvaluatedPipeline_t, f_typecheck_diags), offsetof(vader_struct_vader_bootstrap_EvaluatedPipeline_t, f_comptime_diags) },
        .ref_count = 6,
    },
    [535] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bootstrap_LoweredEntry_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bootstrap_LoweredEntry_t, f_entry) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bootstrap_LoweredEntry_t, f_lowered), offsetof(vader_struct_vader_bootstrap_LoweredEntry_t, f_pre_diags), offsetof(vader_struct_vader_bootstrap_LoweredEntry_t, f_lower_diags) },
        .ref_count = 3,
    },
    [536] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_ArrayClear_t),
        .slot_size = 8,
    },
    [537] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_ArrayCopy_t),
        .slot_size = 8,
    },
    [538] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_ArrayGet_t),
        .slot_size = 8,
    },
    [539] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_ArrayLen_t),
        .slot_size = 8,
    },
    [540] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_ArrayNew_t),
        .slot_size = 8,
    },
    [541] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_ArrayPush_t),
        .slot_size = 8,
    },
    [542] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_ArrayPushAll_t),
        .slot_size = 8,
    },
    [543] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_bytecode_ArrayRemoveLast_t), .slot_size = 8,
    },
    [544] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_ArrayRepeat_t),
        .slot_size = 8,
    },
    [545] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_ArraySet_t),
        .slot_size = 8,
    },
    [546] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_ArraySlice_t),
        .slot_size = 8,
    },
    [547] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_bytecode_BcAggregateData_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcAggregateData_t, f_element_type_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcAggregateData_t, f_elements) },
        .ref_count = 1,
    },
    [548] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcArray_t),
        .slot_size = 8,
    },
    [549] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcExport_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcExport_t, f_extern_name) },
        .string_count = 1,
    },
    [550] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcField_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcField_t, f_name) },
        .string_count = 1,
    },
    [551] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcFn_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcFn_t, f_params) },
        .ref_count = 1,
    },
    [552] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcFunction_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcFunction_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcFunction_t, f_signature), offsetof(vader_struct_vader_bytecode_BcFunction_t, f_locals), offsetof(vader_struct_vader_bytecode_BcFunction_t, f_body), offsetof(vader_struct_vader_bytecode_BcFunction_t, f_debug), offsetof(vader_struct_vader_bytecode_BcFunction_t, f_jump_table), offsetof(vader_struct_vader_bytecode_BcFunction_t, f_source_pc) },
        .ref_count = 6,
    },
    [553] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcImport_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcImport_t, f_extern_name), offsetof(vader_struct_vader_bytecode_BcImport_t, f_mangled_name), offsetof(vader_struct_vader_bytecode_BcImport_t, f_c_header), offsetof(vader_struct_vader_bytecode_BcImport_t, f_c_library) },
        .string_count = 4,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcImport_t, f_signature) },
        .ref_count = 1,
    },
    [554] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcLocal_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcLocal_t, f_name) },
        .string_count = 1,
    },
    [555] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcPeepholeOut_t, f_body), offsetof(vader_struct_vader_bytecode_BcPeepholeOut_t, f_jump_table), offsetof(vader_struct_vader_bytecode_BcPeepholeOut_t, f_debug) },
        .ref_count = 3,
    },
    [556] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcPrimData_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcPrimData_t, f_items) },
        .ref_count = 1,
    },
    [557] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcPrimitive_t),
        .slot_size = 8,
    },
    [558] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcRef_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcRef_t, f_trait_name) },
        .string_count = 1,
    },
    [559] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcSignature_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcSignature_t, f_params), offsetof(vader_struct_vader_bytecode_BcSignature_t, f_results), offsetof(vader_struct_vader_bytecode_BcSignature_t, f_param_types), offsetof(vader_struct_vader_bytecode_BcSignature_t, f_result_types), offsetof(vader_struct_vader_bytecode_BcSignature_t, f_param_names), offsetof(vader_struct_vader_bytecode_BcSignature_t, f_param_mutable), offsetof(vader_struct_vader_bytecode_BcSignature_t, f_param_by_address) },
        .ref_count = 7,
    },
    [560] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcStrData_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcStrData_t, f_values) },
        .ref_count = 1,
    },
    [561] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcStruct_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcStruct_t, f_name), offsetof(vader_struct_vader_bytecode_BcStruct_t, f_c_name) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcStruct_t, f_fields) },
        .ref_count = 1,
    },
    [562] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcUnion_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcUnion_t, f_variants) },
        .ref_count = 1,
    },
    [563] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcValArray_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcValArray_t, f_element_type_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcValArray_t, f_elements) },
        .ref_count = 1,
    },
    [564] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcValPrim_t),
        .slot_size = 8,
    },
    [565] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcValStr_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcValStr_t, f_value) },
        .string_count = 1,
    },
    [566] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BcValStruct_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BcValStruct_t, f_fields) },
        .ref_count = 1,
    },
    [567] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BitsToF32_t),
        .slot_size = 8,
    },
    [568] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BitsToF64_t),
        .slot_size = 8,
    },
    [569] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_Block_t),
        .slot_size = 8,
    },
    [570] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BoolAnd_t),
        .slot_size = 8,
    },
    [571] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BoolConst_t),
        .slot_size = 8,
    },
    [572] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BoolEq_t),
        .slot_size = 8,
    },
    [573] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BoolNe_t),
        .slot_size = 8,
    },
    [574] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BoolNot_t),
        .slot_size = 8,
    },
    [575] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BoolOr_t),
        .slot_size = 8,
    },
    [576] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_Branch_t),
        .slot_size = 8,
    },
    [577] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BranchIf_t),
        .slot_size = 8,
    },
    [578] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_BufferNew_t),
        .slot_size = 8,
    },
    [579] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_bytecode_BufferToString_t), .slot_size = 8,
    },
    [580] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_bytecode_BufferWriteString_t), .slot_size = 8,
    },
    [581] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_bytecode_BytecodeModule_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_types), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_strings), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_data_pool), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_functions), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_imports), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_exports), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_impl_table), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_vtables) },
        .ref_count = 8,
    },
    [582] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_CLayout_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_CLayout_t, f_unknown_field) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_CLayout_t, f_offsets) },
        .ref_count = 1,
    },
    [583] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_Call_t),
        .slot_size = 8,
    },
    [584] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_CallImport_t),
        .slot_size = 8,
    },
    [585] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_CallIndirect_t),
        .slot_size = 8,
    },
    [586] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_CharConst_t),
        .slot_size = 8,
    },
    [587] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_Convert_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_Convert_t, f_from_name) },
        .string_count = 1,
    },
    [588] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_DataConst_t),
        .slot_size = 8,
    },
    [589] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_DebugPos_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_DebugPos_t, f_file) },
        .string_count = 1,
    },
    [590] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_DeferPopExec_t),
        .slot_size = 8,
    },
    [591] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_DeferPush_t),
        .slot_size = 8,
    },
    [592] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_Drop_t),
        .slot_size = 8,
    },
    [593] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_Else_t),
        .slot_size = 8,
    },
    [594] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_EmitOptions_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_EmitOptions_t, f_keep_mangles) },
        .ref_count = 1,
    },
    [595] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_EmitterCtx_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_types), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_type_key), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_type_hash), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_type_by_slot), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_strings), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_string_key), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_functions), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_function_index_by_symbol_id), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_function_index_by_mangle), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_imports), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_import_index_by_symbol_id), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_import_index_by_mangle), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_exports), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_pinned_types), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_pinned_types_by_fn) },
        .ref_count = 15,
    },
    [596] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_End_t),
        .slot_size = 8,
    },
    [597] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F32ToBits_t),
        .slot_size = 8,
    },
    [598] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F64Add_t),
        .slot_size = 8,
    },
    [599] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F64Const_t),
        .slot_size = 8,
    },
    [600] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F64Div_t),
        .slot_size = 8,
    },
    [601] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F64Eq_t),
        .slot_size = 8,
    },
    [602] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F64Ge_t),
        .slot_size = 8,
    },
    [603] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F64Gt_t),
        .slot_size = 8,
    },
    [604] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F64Le_t),
        .slot_size = 8,
    },
    [605] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F64Lt_t),
        .slot_size = 8,
    },
    [606] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F64Mul_t),
        .slot_size = 8,
    },
    [607] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F64Ne_t),
        .slot_size = 8,
    },
    [608] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F64Neg_t),
        .slot_size = 8,
    },
    [609] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F64Sub_t),
        .slot_size = 8,
    },
    [610] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_F64ToBits_t),
        .slot_size = 8,
    },
    [611] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_FnAddr_t),
        .slot_size = 8,
    },
    [612] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_FnRef_t),
        .slot_size = 8,
    },
    [613] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Add_t),
        .slot_size = 8,
    },
    [614] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32BitAnd_t),
        .slot_size = 8,
    },
    [615] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32BitNot_t),
        .slot_size = 8,
    },
    [616] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32BitOr_t),
        .slot_size = 8,
    },
    [617] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32BitXor_t),
        .slot_size = 8,
    },
    [618] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Const_t),
        .slot_size = 8,
    },
    [619] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Div_t),
        .slot_size = 8,
    },
    [620] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Eq_t),
        .slot_size = 8,
    },
    [621] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Ge_t),
        .slot_size = 8,
    },
    [622] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Gt_t),
        .slot_size = 8,
    },
    [623] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Le_t),
        .slot_size = 8,
    },
    [624] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Lt_t),
        .slot_size = 8,
    },
    [625] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Mod_t),
        .slot_size = 8,
    },
    [626] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Mul_t),
        .slot_size = 8,
    },
    [627] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Ne_t),
        .slot_size = 8,
    },
    [628] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Neg_t),
        .slot_size = 8,
    },
    [629] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Shl_t),
        .slot_size = 8,
    },
    [630] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Shr_t),
        .slot_size = 8,
    },
    [631] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32ShrU_t),
        .slot_size = 8,
    },
    [632] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I32Sub_t),
        .slot_size = 8,
    },
    [633] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Add_t),
        .slot_size = 8,
    },
    [634] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64BitAnd_t),
        .slot_size = 8,
    },
    [635] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64BitNot_t),
        .slot_size = 8,
    },
    [636] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64BitOr_t),
        .slot_size = 8,
    },
    [637] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64BitXor_t),
        .slot_size = 8,
    },
    [638] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Const_t),
        .slot_size = 8,
    },
    [639] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Div_t),
        .slot_size = 8,
    },
    [640] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Eq_t),
        .slot_size = 8,
    },
    [641] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Ge_t),
        .slot_size = 8,
    },
    [642] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Gt_t),
        .slot_size = 8,
    },
    [643] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Le_t),
        .slot_size = 8,
    },
    [644] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Lt_t),
        .slot_size = 8,
    },
    [645] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Mod_t),
        .slot_size = 8,
    },
    [646] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Mul_t),
        .slot_size = 8,
    },
    [647] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Ne_t),
        .slot_size = 8,
    },
    [648] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Neg_t),
        .slot_size = 8,
    },
    [649] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Shl_t),
        .slot_size = 8,
    },
    [650] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Shr_t),
        .slot_size = 8,
    },
    [651] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64ShrU_t),
        .slot_size = 8,
    },
    [652] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_I64Sub_t),
        .slot_size = 8,
    },
    [653] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_If_t),
        .slot_size = 8,
    },
    [654] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_ImplEntry_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_ImplEntry_t, f_trait_name) },
        .string_count = 1,
    },
    [655] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_LoadF64_t),
        .slot_size = 8,
    },
    [656] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_LoadI32_t),
        .slot_size = 8,
    },
    [657] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_LoadI64_t),
        .slot_size = 8,
    },
    [658] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_LoadSlotF64_t),
        .slot_size = 8,
    },
    [659] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_LoadSlotI32_t),
        .slot_size = 8,
    },
    [660] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_LoadSlotI64_t),
        .slot_size = 8,
    },
    [661] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_LoadU8_t),
        .slot_size = 8,
    },
    [662] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_LocalField_t),
        .slot_size = 8,
    },
    [663] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_LocalGet_t),
        .slot_size = 8,
    },
    [664] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_LocalSet_t),
        .slot_size = 8,
    },
    [665] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_LocalTee_t),
        .slot_size = 8,
    },
    [666] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_Loop_t),
        .slot_size = 8,
    },
    [667] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_MakeClosure_t),
        .slot_size = 8,
    },
    [668] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_MemoryCopy_t),
        .slot_size = 8,
    },
    [669] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_NullConst_t),
        .slot_size = 8,
    },
    [670] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_OperandRef_t),
        .slot_size = 8,
    },
    [671] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_RefCast_t),
        .slot_size = 8,
    },
    [672] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_RefEq_t),
        .slot_size = 8,
    },
    [673] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_RefNe_t),
        .slot_size = 8,
    },
    [674] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_Retag_t),
        .slot_size = 8,
    },
    [675] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_Return_t),
        .slot_size = 8,
    },
    [676] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_ReturnLit_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_ReturnLit_t, f_value) },
        .ptr_count = 1,
    },
    [677] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_SizeOfType_t),
        .slot_size = 8,
    },
    [678] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_SlotRange_t),
        .slot_size = 8,
    },
    [679] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StoreF64_t),
        .slot_size = 8,
    },
    [680] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StoreI32_t),
        .slot_size = 8,
    },
    [681] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StoreI64_t),
        .slot_size = 8,
    },
    [682] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StoreSlotF64_t),
        .slot_size = 8,
    },
    [683] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StoreSlotI32_t),
        .slot_size = 8,
    },
    [684] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StoreSlotI64_t),
        .slot_size = 8,
    },
    [685] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StoreU8_t),
        .slot_size = 8,
    },
    [686] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StringCompare_t),
        .slot_size = 8,
    },
    [687] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StringConst_t),
        .slot_size = 8,
    },
    [688] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StringEq_t),
        .slot_size = 8,
    },
    [689] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StringNe_t),
        .slot_size = 8,
    },
    [690] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_bytecode_StringSliceCodepoints_t), .slot_size = 8,
    },
    [691] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StructGet_t),
        .slot_size = 8,
    },
    [692] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StructNew_t),
        .slot_size = 8,
    },
    [693] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_StructSet_t),
        .slot_size = 8,
    },
    [694] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_TypeCheck_t),
        .slot_size = 8,
    },
    [695] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_TypeConst_t),
        .slot_size = 8,
    },
    [696] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_U32Div_t),
        .slot_size = 8,
    },
    [697] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_U32Ge_t),
        .slot_size = 8,
    },
    [698] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_U32Gt_t),
        .slot_size = 8,
    },
    [699] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_U32Le_t),
        .slot_size = 8,
    },
    [700] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_U32Lt_t),
        .slot_size = 8,
    },
    [701] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_U32Mod_t),
        .slot_size = 8,
    },
    [702] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_U64Div_t),
        .slot_size = 8,
    },
    [703] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_U64Ge_t),
        .slot_size = 8,
    },
    [704] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_U64Gt_t),
        .slot_size = 8,
    },
    [705] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_U64Le_t),
        .slot_size = 8,
    },
    [706] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_U64Lt_t),
        .slot_size = 8,
    },
    [707] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_U64Mod_t),
        .slot_size = 8,
    },
    [708] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_Unreachable_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_Unreachable_t, f_reason) },
        .string_count = 1,
    },
    [709] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_VirtualCall_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_VirtualCall_t, f_vtable_key) },
        .string_count = 1,
    },
    [710] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_VtableEntry_t),
        .slot_size = 8,
    },
    [711] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_bytecode_VtableRow_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_VtableRow_t, f_key) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_bytecode_VtableRow_t, f_entries) },
        .ref_count = 1,
    },
    [712] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_BoundArray_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_BoundArray_t, f_pointer) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_BoundArray_t, f_name) },
        .string_count = 1,
    },
    [713] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_BranchTargets_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_BranchTargets_t, f_continue_targets), offsetof(vader_struct_vader_c_emit_BranchTargets_t, f_break_targets) },
        .ref_count = 2,
    },
    [714] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_CProgram_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_CProgram_t, f_header), offsetof(vader_struct_vader_c_emit_CProgram_t, f_imports), offsetof(vader_struct_vader_c_emit_CProgram_t, f_globals) },
        .string_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_CProgram_t, f_units), offsetof(vader_struct_vader_c_emit_CProgram_t, f_unit_names) },
        .ref_count = 2,
    },
    [715] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_EmitCtx_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_EmitCtx_t, f_module), offsetof(vader_struct_vader_c_emit_EmitCtx_t, f_struct_c_names), offsetof(vader_struct_vader_c_emit_EmitCtx_t, f_atom_ids), offsetof(vader_struct_vader_c_emit_EmitCtx_t, f_atom_table), offsetof(vader_struct_vader_c_emit_EmitCtx_t, f_may_alloc), offsetof(vader_struct_vader_c_emit_EmitCtx_t, f_import_may_collect), offsetof(vader_struct_vader_c_emit_EmitCtx_t, f_internal_fns) },
        .ref_count = 7,
    },
    [716] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_EmitOptions_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_EmitOptions_t, f_entry_mangled) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_EmitOptions_t, f_atom_universe) },
        .ref_count = 1,
    },
    [717] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_FnState_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_FnState_t, f_ctx), offsetof(vader_struct_vader_c_emit_FnState_t, f_function), offsetof(vader_struct_vader_c_emit_FnState_t, f_root), offsetof(vader_struct_vader_c_emit_FnState_t, f_stack), offsetof(vader_struct_vader_c_emit_FnState_t, f_temporaries), offsetof(vader_struct_vader_c_emit_FnState_t, f_scopes), offsetof(vader_struct_vader_c_emit_FnState_t, f_continue_targets), offsetof(vader_struct_vader_c_emit_FnState_t, f_break_targets), offsetof(vader_struct_vader_c_emit_FnState_t, f_push_caches), offsetof(vader_struct_vader_c_emit_FnState_t, f_bound_arrays), offsetof(vader_struct_vader_c_emit_FnState_t, f_stack_storages), offsetof(vader_struct_vader_c_emit_FnState_t, f_open_nodes) },
        .ref_count = 12,
    },
    [718] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_FnValueUsage_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_FnValueUsage_t, f_fn_ref_type), offsetof(vader_struct_vader_c_emit_FnValueUsage_t, f_is_closure) },
        .ref_count = 2,
    },
    [719] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_ForwardedResult_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_ForwardedResult_t, f_capture), offsetof(vader_struct_vader_c_emit_ForwardedResult_t, f_settle), offsetof(vader_struct_vader_c_emit_ForwardedResult_t, f_returned) },
        .ptr_count = 3,
    },
    [720] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_PoolArray_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_PoolArray_t, f_name) },
        .string_count = 1,
    },
    [721] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_PushCache_t),
        .slot_size = 8,
    },
    [722] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_ScopeInfo_t),
        .slot_size = 8,
    },
    [723] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_SlotFill_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_SlotFill_t, f_cty) },
        .string_count = 1,
    },
    [724] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_StackExpr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_StackExpr_t, f_expression) },
        .ptr_count = 1,
    },
    [725] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_StackLit_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_StackLit_t, f_expression) },
        .ptr_count = 1,
    },
    [726] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_StackLocalRef_t),
        .slot_size = 8,
    },
    [727] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_StackStorage_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_StackStorage_t, f_cname), offsetof(vader_struct_vader_c_emit_StackStorage_t, f_storage) },
        .string_count = 2,
    },
    [728] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_StackTemporary_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_StackTemporary_t, f_temporary) },
        .ref_count = 1,
    },
    [729] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_StructOffsets_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_StructOffsets_t, f_ptr_offsets), offsetof(vader_struct_vader_c_emit_StructOffsets_t, f_str_offsets), offsetof(vader_struct_vader_c_emit_StructOffsets_t, f_ref_offsets) },
        .ref_count = 3,
    },
    [730] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CAddressOf_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CAddressOf_t, f_operand) },
        .ptr_count = 1,
    },
    [731] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CAssign_t, f_target), offsetof(vader_struct_vader_c_emit_c_ast_CAssign_t, f_value), offsetof(vader_struct_vader_c_emit_c_ast_CAssign_t, f_operator) },
        .ptr_count = 3,
    },
    [732] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CBinary_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CBinary_t, f_left), offsetof(vader_struct_vader_c_emit_c_ast_CBinary_t, f_right) },
        .ptr_count = 2,
    },
    [733] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CBlock_t, f_body) },
        .ref_count = 1,
    },
    [734] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CBreak_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CBreak_t, f_condition) },
        .ptr_count = 1,
    },
    [735] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CCall_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CCall_t, f_callee) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CCall_t, f_arguments) },
        .ref_count = 1,
    },
    [736] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CCase_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CCase_t, f_value) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CCase_t, f_body) },
        .ref_count = 1,
    },
    [737] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CCast_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CCast_t, f_value) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CCast_t, f_types) },
        .ref_count = 1,
    },
    [738] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t, f_model), offsetof(vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t, f_value) },
        .ptr_count = 2,
    },
    [739] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t, f_type) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t, f_elements) },
        .ref_count = 1,
    },
    [740] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CConditional_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CConditional_t, f_condition), offsetof(vader_struct_vader_c_emit_c_ast_CConditional_t, f_then_value), offsetof(vader_struct_vader_c_emit_c_ast_CConditional_t, f_else_value) },
        .ptr_count = 3,
    },
    [741] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CContinue_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CContinue_t, f_condition) },
        .ptr_count = 1,
    },
    [742] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CDeclaration_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CDeclaration_t, f_type) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CDeclaration_t, f_declarators) },
        .ref_count = 1,
    },
    [743] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CDeclarator_t, f_length), offsetof(vader_struct_vader_c_emit_c_ast_CDeclarator_t, f_value) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CDeclarator_t, f_name) },
        .string_count = 1,
    },
    [744] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CDefine_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CDefine_t, f_value) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CDefine_t, f_name) },
        .string_count = 1,
    },
    [745] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CDesignated_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CDesignated_t, f_value) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CDesignated_t, f_designator) },
        .string_count = 1,
    },
    [746] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CDirective_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CDirective_t, f_text) },
        .string_count = 1,
    },
    [747] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t, f_expression) },
        .ptr_count = 1,
    },
    [748] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CField_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CField_t, f_type), offsetof(vader_struct_vader_c_emit_c_ast_CField_t, f_name) },
        .string_count = 2,
    },
    [749] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CFor_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CFor_t, f_label), offsetof(vader_struct_vader_c_emit_c_ast_CFor_t, f_end_label) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CFor_t, f_body) },
        .ref_count = 1,
    },
    [750] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CFunction_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CFunction_t, f_signature), offsetof(vader_struct_vader_c_emit_c_ast_CFunction_t, f_prologue), offsetof(vader_struct_vader_c_emit_c_ast_CFunction_t, f_body) },
        .ref_count = 3,
    },
    [751] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CFunctionPointerTypedef_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CFunctionPointerTypedef_t, f_result), offsetof(vader_struct_vader_c_emit_c_ast_CFunctionPointerTypedef_t, f_name) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CFunctionPointerTypedef_t, f_parameters) },
        .ref_count = 1,
    },
    [752] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CGlobal_t, f_type) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CGlobal_t, f_declarator) },
        .ref_count = 1,
    },
    [753] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CGoto_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CGoto_t, f_condition) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CGoto_t, f_label) },
        .string_count = 1,
    },
    [754] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CIf_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CIf_t, f_condition), offsetof(vader_struct_vader_c_emit_c_ast_CIf_t, f_else_block) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CIf_t, f_end_label) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CIf_t, f_then_block) },
        .ref_count = 1,
    },
    [755] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CInclude_t, f_path) },
        .string_count = 1,
    },
    [756] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CIndex_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CIndex_t, f_base), offsetof(vader_struct_vader_c_emit_c_ast_CIndex_t, f_index) },
        .ptr_count = 2,
    },
    [757] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CInitializerList_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CInitializerList_t, f_elements) },
        .ref_count = 1,
    },
    [758] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t), .slot_size = 8,
    },
    [759] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CLocal_t),
        .slot_size = 8,
    },
    [760] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CMacroStatement_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CMacroStatement_t, f_call) },
        .ref_count = 1,
    },
    [761] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CMember_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CMember_t, f_base) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CMember_t, f_member) },
        .string_count = 1,
    },
    [762] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t),
        .slot_size = 8,
    },
    [763] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_COperatorInfo_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_COperatorInfo_t, f_spelling) },
        .string_count = 1,
    },
    [764] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CParameter_t, f_type), offsetof(vader_struct_vader_c_emit_c_ast_CParameter_t, f_name) },
        .string_count = 2,
    },
    [765] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CParenthesized_t, f_inner) },
        .ptr_count = 1,
    },
    [766] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CPrinter_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CPrinter_t, f_out) },
        .ref_count = 1,
    },
    [767] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CPrototype_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CPrototype_t, f_signature) },
        .ref_count = 1,
    },
    [768] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CReturn_t, f_value) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CReturn_t, f_snapshot_type) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CReturn_t, f_stores) },
        .ref_count = 1,
    },
    [769] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CScope_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CScope_t, f_label), offsetof(vader_struct_vader_c_emit_c_ast_CScope_t, f_end_label) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CScope_t, f_body) },
        .ref_count = 1,
    },
    [770] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CSection_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CSection_t, f_comment), offsetof(vader_struct_vader_c_emit_c_ast_CSection_t, f_items) },
        .ref_count = 2,
    },
    [771] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CSequence_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CSequence_t, f_parts) },
        .ref_count = 1,
    },
    [772] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CSignature_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CSignature_t, f_result), offsetof(vader_struct_vader_c_emit_c_ast_CSignature_t, f_name) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CSignature_t, f_parameters) },
        .ref_count = 1,
    },
    [773] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CStaticAssert_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CStaticAssert_t, f_condition) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CStaticAssert_t, f_message) },
        .ref_count = 1,
    },
    [774] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CStringLiterals_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CStringLiterals_t, f_literals) },
        .ref_count = 1,
    },
    [775] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CStructDefinition_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CStructDefinition_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CStructDefinition_t, f_fields) },
        .ref_count = 1,
    },
    [776] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CStructForward_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CStructForward_t, f_name) },
        .string_count = 1,
    },
    [777] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CSwitch_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CSwitch_t, f_subject), offsetof(vader_struct_vader_c_emit_c_ast_CSwitch_t, f_default_body) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CSwitch_t, f_cases) },
        .ref_count = 1,
    },
    [778] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_CTemporary_t), .slot_size = 8,
    },
    [779] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CUnary_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CUnary_t, f_operand) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CUnary_t, f_operator) },
        .string_count = 1,
    },
    [780] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CUnsized_t),
        .slot_size = 8,
    },
    [781] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CVerbatim_t, f_text) },
        .string_count = 1,
    },
    [782] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_c_emit_c_ast_CWhile_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CWhile_t, f_condition) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CWhile_t, f_label), offsetof(vader_struct_vader_c_emit_c_ast_CWhile_t, f_end_label) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_CWhile_t, f_body) },
        .ref_count = 1,
    },
    [783] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_c_emit_c_ast_TemporaryUsage_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_c_emit_c_ast_TemporaryUsage_t, f_uses), offsetof(vader_struct_vader_c_emit_c_ast_TemporaryUsage_t, f_first), offsetof(vader_struct_vader_c_emit_c_ast_TemporaryUsage_t, f_last) },
        .ref_count = 3,
    },
    [784] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_ArrayValue_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_ArrayValue_t, f_element_type_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_ArrayValue_t, f_elements) },
        .ref_count = 1,
    },
    [785] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_BoolValue_t),
        .slot_size = 8,
    },
    [786] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_CharValue_t),
        .slot_size = 8,
    },
    [787] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_comptime_ComptimeContext_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_ComptimeContext_t, f_typed), offsetof(vader_struct_vader_comptime_ComptimeContext_t, f_bindings) },
        .ref_count = 2,
    },
    [788] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_ComptimeOrder_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_ComptimeOrder_t, f_order), offsetof(vader_struct_vader_comptime_ComptimeOrder_t, f_cycle_diags) },
        .ref_count = 2,
    },
    [789] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_EvalResult_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_EvalResult_t, f_value), offsetof(vader_struct_vader_comptime_EvalResult_t, f_diag) },
        .ptr_count = 2,
    },
    [790] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_comptime_EvaluatedProgram_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_EvaluatedProgram_t, f_typed), offsetof(vader_struct_vader_comptime_EvaluatedProgram_t, f_comptime_decls) },
        .ref_count = 2,
    },
    [791] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_comptime_EvaluatedProject_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_EvaluatedProject_t, f_typed), offsetof(vader_struct_vader_comptime_EvaluatedProject_t, f_modules), offsetof(vader_struct_vader_comptime_EvaluatedProject_t, f_file_baked_consts), offsetof(vader_struct_vader_comptime_EvaluatedProject_t, f_file_exprs), offsetof(vader_struct_vader_comptime_EvaluatedProject_t, f_instances), offsetof(vader_struct_vader_comptime_EvaluatedProject_t, f_vm_required) },
        .ref_count = 6,
    },
    [792] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_FloatValue_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_FloatValue_t, f_type_name) },
        .string_count = 1,
    },
    [793] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_comptime_GenericInstance_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_GenericInstance_t, f_display_key) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_GenericInstance_t, f_symbol), offsetof(vader_struct_vader_comptime_GenericInstance_t, f_args) },
        .ref_count = 2,
    },
    [794] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_comptime_InstanceRegistry_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_InstanceRegistry_t, f_by_key), offsetof(vader_struct_vader_comptime_InstanceRegistry_t, f_order) },
        .ref_count = 2,
    },
    [795] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_IntValue_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_IntValue_t, f_type_name) },
        .string_count = 1,
    },
    [796] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_MonoEntry_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_MonoEntry_t, f_decl), offsetof(vader_struct_vader_comptime_MonoEntry_t, f_symbol), offsetof(vader_struct_vader_comptime_MonoEntry_t, f_module), offsetof(vader_struct_vader_comptime_MonoEntry_t, f_vtable_slot) },
        .ptr_count = 4,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_MonoEntry_t, f_mangled) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_MonoEntry_t, f_subst), offsetof(vader_struct_vader_comptime_MonoEntry_t, f_type_arguments) },
        .ref_count = 2,
    },
    [797] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_NodeRecord_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_NodeRecord_t, f_decl), offsetof(vader_struct_vader_comptime_NodeRecord_t, f_dependency_ids) },
        .ref_count = 2,
    },
    [798] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_Nodes_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_Nodes_t, f_by_id), offsetof(vader_struct_vader_comptime_Nodes_t, f_order), offsetof(vader_struct_vader_comptime_Nodes_t, f_by_symbol) },
        .ref_count = 3,
    },
    [799] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_NullValue_t),
        .slot_size = 8,
    },
    [800] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_StringValue_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_StringValue_t, f_value) },
        .string_count = 1,
    },
    [801] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_StructValue_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_StructValue_t, f_type_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_StructValue_t, f_fields) },
        .ref_count = 1,
    },
    [802] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_TypeValue_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_TypeValue_t, f_value) },
        .ptr_count = 1,
    },
    [803] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_comptime_VmRequiredDecl_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_VmRequiredDecl_t, f_decl_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_VmRequiredDecl_t, f_module_id), offsetof(vader_struct_vader_comptime_VmRequiredDecl_t, f_callee_name) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_VmRequiredDecl_t, f_span) },
        .ref_count = 1,
    },
    [804] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_VoidValue_t),
        .slot_size = 8,
    },
    [805] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_comptime_VtableSlot_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_comptime_VtableSlot_t, f_trait_key), offsetof(vader_struct_vader_comptime_VtableSlot_t, f_method) },
        .string_count = 2,
    },
    [806] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_diagnostics_CodeInfo_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_diagnostics_CodeInfo_t, f_id), offsetof(vader_struct_vader_diagnostics_CodeInfo_t, f_message) },
        .string_count = 2,
    },
    [807] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_diagnostics_Diagnostic_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_diagnostics_Diagnostic_t, f_detail) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_diagnostics_Diagnostic_t, f_code), offsetof(vader_struct_vader_diagnostics_Diagnostic_t, f_primary) },
        .ref_count = 2,
    },
    [808] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lexer_InterpFrame_t),
        .slot_size = 8,
    },
    [809] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lexer_Lexer_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lexer_Lexer_t, f_pending_newline) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lexer_Lexer_t, f_src), offsetof(vader_struct_vader_lexer_Lexer_t, f_file) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lexer_Lexer_t, f_bytes), offsetof(vader_struct_vader_lexer_Lexer_t, f_tokens), offsetof(vader_struct_vader_lexer_Lexer_t, f_errors), offsetof(vader_struct_vader_lexer_Lexer_t, f_interp_stack) },
        .ref_count = 4,
    },
    [810] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lexer_Token_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lexer_Token_t, f_value) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lexer_Token_t, f_text) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lexer_Token_t, f_span) },
        .ref_count = 1,
    },
    [811] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_AggregateDataPoolEntry_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_AggregateDataPoolEntry_t, f_element_type_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_AggregateDataPoolEntry_t, f_literal) },
        .ref_count = 1,
    },
    [812] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_AnalyzeCtx_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_AnalyzeCtx_t, f_aliases), offsetof(vader_struct_vader_lower_AnalyzeCtx_t, f_closures), offsetof(vader_struct_vader_lower_AnalyzeCtx_t, f_escaped), offsetof(vader_struct_vader_lower_AnalyzeCtx_t, f_bound) },
        .ref_count = 4,
    },
    [813] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_ArrayMemberUse_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_ArrayMemberUse_t, f_element) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_ArrayMemberUse_t, f_member_span) },
        .ref_count = 1,
    },
    [814] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_BcePurityCtx_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_BcePurityCtx_t, f_by_mangle), offsetof(vader_struct_vader_lower_BcePurityCtx_t, f_by_symid), offsetof(vader_struct_vader_lower_BcePurityCtx_t, f_memo) },
        .ref_count = 3,
    },
    [815] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_BlockCtx_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_BlockCtx_t, f_loop_id) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_BlockCtx_t, f_defers) },
        .ref_count = 1,
    },
    [816] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_BodyTemplate_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_BodyTemplate_t, f_element_type), offsetof(vader_struct_vader_lower_BodyTemplate_t, f_pattern) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_BodyTemplate_t, f_binding_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_BodyTemplate_t, f_binding_symbol), offsetof(vader_struct_vader_lower_BodyTemplate_t, f_user_body) },
        .ref_count = 2,
    },
    [817] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_BveCtx_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_BveCtx_t, f_usize_ty), offsetof(vader_struct_vader_lower_BveCtx_t, f_u8_ty) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_BveCtx_t, f_byte_len_sym), offsetof(vader_struct_vader_lower_BveCtx_t, f_byte_at_sym), offsetof(vader_struct_vader_lower_BveCtx_t, f_candidates), offsetof(vader_struct_vader_lower_BveCtx_t, f_disq), offsetof(vader_struct_vader_lower_BveCtx_t, f_bound), offsetof(vader_struct_vader_lower_BveCtx_t, f_reassigned) },
        .ref_count = 6,
    },
    [818] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_CallTarget_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_CallTarget_t, f_callee), offsetof(vader_struct_vader_lower_CallTarget_t, f_owner), offsetof(vader_struct_vader_lower_CallTarget_t, f_decl), offsetof(vader_struct_vader_lower_CallTarget_t, f_args) },
        .ref_count = 4,
    },
    [819] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_Capture_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_Capture_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_Capture_t, f_symbol) },
        .ref_count = 1,
    },
    [820] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_CellInit_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_CellInit_t, f_value), offsetof(vader_struct_vader_lower_CellInit_t, f_slot_type) },
        .ptr_count = 2,
    },
    [821] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_CfAppend_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_CfAppend_t, f_span), offsetof(vader_struct_vader_lower_CfAppend_t, f_target), offsetof(vader_struct_vader_lower_CfAppend_t, f_args) },
        .ref_count = 3,
    },
    [822] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_CfMentionKinds_t),
        .slot_size = 8,
    },
    [823] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_ClosureAlias_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_ClosureAlias_t, f_env_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_ClosureAlias_t, f_fn_sym) },
        .ref_count = 1,
    },
    [824] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_ClosureAnalysis_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_ClosureAnalysis_t, f_cell_symbols), offsetof(vader_struct_vader_lower_ClosureAnalysis_t, f_lambda_captures), offsetof(vader_struct_vader_lower_ClosureAnalysis_t, f_defer_captures) },
        .ref_count = 3,
    },
    [825] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_ConstFnWrap_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_ConstFnWrap_t, f_call_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_ConstFnWrap_t, f_fn_symbol) },
        .ref_count = 1,
    },
    [826] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_ConsumerCall_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_ConsumerCall_t, f_target), offsetof(vader_struct_vader_lower_ConsumerCall_t, f_signature), offsetof(vader_struct_vader_lower_ConsumerCall_t, f_shape), offsetof(vader_struct_vader_lower_ConsumerCall_t, f_subst), offsetof(vader_struct_vader_lower_ConsumerCall_t, f_chain), offsetof(vader_struct_vader_lower_ConsumerCall_t, f_instance) },
        .ref_count = 6,
    },
    [827] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_ConsumerShape_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_ConsumerShape_t, f_symbol), offsetof(vader_struct_vader_lower_ConsumerShape_t, f_type_params) },
        .ref_count = 2,
    },
    [828] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_CountedLoop_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_CountedLoop_t, f_body), offsetof(vader_struct_vader_lower_CountedLoop_t, f_turns) },
        .ref_count = 2,
    },
    [829] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_DefaultThunk_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_DefaultThunk_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_DefaultThunk_t, f_symbol) },
        .ref_count = 1,
    },
    [830] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_EntryTypes_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_EntryTypes_t, f_typed), offsetof(vader_struct_vader_lower_EntryTypes_t, f_subst) },
        .ref_count = 2,
    },
    [831] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_EnumTable_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_EnumTable_t, f_enum_type), offsetof(vader_struct_vader_lower_EnumTable_t, f_symbol) },
        .ref_count = 2,
    },
    [832] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_EnvSlot_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_EnvSlot_t, f_value_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_EnvSlot_t, f_field) },
        .string_count = 1,
    },
    [833] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_FluentCombinator_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_FluentCombinator_t, f_receiver), offsetof(vader_struct_vader_lower_FluentCombinator_t, f_fn_arg) },
        .ptr_count = 2,
    },
    [834] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_FnLowerCtx_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_return_type), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_lifted_context), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_gen_inline_sink), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_instance), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_inline_consumer) },
        .ptr_count = 5,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_project), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_entry), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_typed), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_subst), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_types), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_blocks), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_comptime_bindings), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_bound_operands), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_pending_awaits), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_jump_frames) },
        .ref_count = 10,
    },
    [835] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_GenBuild_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_GenBuild_t, f_state_ty), offsetof(vader_struct_vader_lower_GenBuild_t, f_i32_ty), offsetof(vader_struct_vader_lower_GenBuild_t, f_step), offsetof(vader_struct_vader_lower_GenBuild_t, f_result_ty), offsetof(vader_struct_vader_lower_GenBuild_t, f_suspended_ty), offsetof(vader_struct_vader_lower_GenBuild_t, f_async_any_ty), offsetof(vader_struct_vader_lower_GenBuild_t, f_resume_erased_ty) },
        .ptr_count = 7,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_GenBuild_t, f_self_sym), offsetof(vader_struct_vader_lower_GenBuild_t, f_span), offsetof(vader_struct_vader_lower_GenBuild_t, f_states), offsetof(vader_struct_vader_lower_GenBuild_t, f_field_map), offsetof(vader_struct_vader_lower_GenBuild_t, f_fields), offsetof(vader_struct_vader_lower_GenBuild_t, f_loop_stack), offsetof(vader_struct_vader_lower_GenBuild_t, f_fn_ctx) },
        .ref_count = 7,
    },
    [836] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_GenComboLayer_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_GenComboLayer_t, f_arg_sym), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_arg_expr), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_arg_slot), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_output_elem) },
        .ptr_count = 4,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_GenComboLayer_t, f_decl), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_subst), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_owner), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_loopvar), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_inner), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_instance), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_prelude), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_extra_sources) },
        .ref_count = 8,
    },
    [837] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_GenInlineSink_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_GenInlineSink_t, f_element_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_GenInlineSink_t, f_binding_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_GenInlineSink_t, f_binding_symbol), offsetof(vader_struct_vader_lower_GenInlineSink_t, f_body) },
        .ref_count = 2,
    },
    [838] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_GenSourceBinding_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_GenSourceBinding_t, f_source), offsetof(vader_struct_vader_lower_GenSourceBinding_t, f_loopvar), offsetof(vader_struct_vader_lower_GenSourceBinding_t, f_inner), offsetof(vader_struct_vader_lower_GenSourceBinding_t, f_prelude) },
        .ref_count = 4,
    },
    [839] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_GenSourceCall_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_GenSourceCall_t, f_decl), offsetof(vader_struct_vader_lower_GenSourceCall_t, f_owner), offsetof(vader_struct_vader_lower_GenSourceCall_t, f_signature), offsetof(vader_struct_vader_lower_GenSourceCall_t, f_subst), offsetof(vader_struct_vader_lower_GenSourceCall_t, f_args), offsetof(vader_struct_vader_lower_GenSourceCall_t, f_instance) },
        .ref_count = 6,
    },
    [840] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_GenSourceLoop_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_GenSourceLoop_t, f_loopvar_span), offsetof(vader_struct_vader_lower_GenSourceLoop_t, f_inner), offsetof(vader_struct_vader_lower_GenSourceLoop_t, f_prelude) },
        .ref_count = 3,
    },
    [841] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_GenericFnInstance_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_GenericFnInstance_t, f_mangled), offsetof(vader_struct_vader_lower_GenericFnInstance_t, f_owner_module) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_GenericFnInstance_t, f_fn_symbol), offsetof(vader_struct_vader_lower_GenericFnInstance_t, f_type_args) },
        .ref_count = 2,
    },
    [842] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_ImplMemberMatch_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_ImplMemberMatch_t, f_entry), offsetof(vader_struct_vader_lower_ImplMemberMatch_t, f_member) },
        .ref_count = 2,
    },
    [843] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_InlineConsumer_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_InlineConsumer_t, f_result_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_InlineConsumer_t, f_param), offsetof(vader_struct_vader_lower_InlineConsumer_t, f_chain), offsetof(vader_struct_vader_lower_InlineConsumer_t, f_result) },
        .ref_count = 3,
    },
    [844] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_InlineInstance_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_InlineInstance_t, f_label_suffix) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_InlineInstance_t, f_clones) },
        .ref_count = 1,
    },
    [845] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_IterChain_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_IterChain_t, f_range_lower), offsetof(vader_struct_vader_lower_IterChain_t, f_range_upper), offsetof(vader_struct_vader_lower_IterChain_t, f_element_type), offsetof(vader_struct_vader_lower_IterChain_t, f_array_expr), offsetof(vader_struct_vader_lower_IterChain_t, f_source), offsetof(vader_struct_vader_lower_IterChain_t, f_gen_layer), offsetof(vader_struct_vader_lower_IterChain_t, f_gen_source), offsetof(vader_struct_vader_lower_IterChain_t, f_iter_expr), offsetof(vader_struct_vader_lower_IterChain_t, f_bound_lower), offsetof(vader_struct_vader_lower_IterChain_t, f_bound_upper), offsetof(vader_struct_vader_lower_IterChain_t, f_bound_source) },
        .ptr_count = 11,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_IterChain_t, f_span) },
        .ref_count = 1,
    },
    [846] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_JumpFrame_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_JumpFrame_t, f_exit), offsetof(vader_struct_vader_lower_JumpFrame_t, f_resume) },
        .ptr_count = 2,
    },
    [847] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LiftedFnContext_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LiftedFnContext_t, f_env_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LiftedFnContext_t, f_env_symbol), offsetof(vader_struct_vader_lower_LiftedFnContext_t, f_captures) },
        .ref_count = 2,
    },
    [848] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoopBinding_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoopBinding_t, f_pattern) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoopBinding_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoopBinding_t, f_symbol) },
        .ref_count = 1,
    },
    [849] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoopFrame_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoopFrame_t, f_label) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoopFrame_t, f_step) },
        .ref_count = 1,
    },
    [850] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoopTurns_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoopTurns_t, f_start), offsetof(vader_struct_vader_lower_LoopTurns_t, f_bound) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoopTurns_t, f_counter) },
        .ref_count = 1,
    },
    [851] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LowerProjectCtx_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_evaluated), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_loaded), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_typed), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_impls), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_opt_misses), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_instance_bindings), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_inlining_callees), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_clone_origins), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_consumers), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_non_consumers), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_core_symbols), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_core_enum_types), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_module_symbol_cache), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_comptime_value_by_symbol_id), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_local_symbol_indices), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_closures), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_synth_decls), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_concat_fn_syms), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_entry_decls), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_default_thunks), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_expanding_defaults), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_enum_data_consts), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_enum_value_consts), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_enum_table_order), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_lambda_seq), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_fn_instances), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_fn_instances_order), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_seen_mangled), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_nongeneric_imported_fns), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_nongeneric_imported_order), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_nongeneric_imported_consts), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_nongeneric_imported_const_order), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_materialized_impl_keys), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_materialized_struct_mangles), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_referenced_impl_mangles), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_virtually_dispatched_traits), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_constructed_struct_symbols), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_array_member_uses), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_pending_generic_impl_recv), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_seen_generic_impl_recv), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_generic_collected), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_generic_processed), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_diags) },
        .ref_count = 43,
    },
    [852] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredArrayLen_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredArrayLen_t, f_type), offsetof(vader_struct_vader_lower_LoweredArrayLen_t, f_target) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredArrayLen_t, f_span) },
        .ref_count = 1,
    },
    [853] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredArrayLit_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredArrayLit_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredArrayLit_t, f_span), offsetof(vader_struct_vader_lower_LoweredArrayLit_t, f_elements) },
        .ref_count = 2,
    },
    [854] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredArrayPush_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredArrayPush_t, f_type), offsetof(vader_struct_vader_lower_LoweredArrayPush_t, f_target), offsetof(vader_struct_vader_lower_LoweredArrayPush_t, f_value) },
        .ptr_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredArrayPush_t, f_span) },
        .ref_count = 1,
    },
    [855] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_LoweredArraySlice_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredArraySlice_t, f_type), offsetof(vader_struct_vader_lower_LoweredArraySlice_t, f_target), offsetof(vader_struct_vader_lower_LoweredArraySlice_t, f_lo), offsetof(vader_struct_vader_lower_LoweredArraySlice_t, f_hi) },
        .ptr_count = 4,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredArraySlice_t, f_span) },
        .ref_count = 1,
    },
    [856] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredAssign_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredAssign_t, f_target), offsetof(vader_struct_vader_lower_LoweredAssign_t, f_value) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredAssign_t, f_span) },
        .ref_count = 1,
    },
    [857] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredAwait_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredAwait_t, f_target_type), offsetof(vader_struct_vader_lower_LoweredAwait_t, f_awaited) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredAwait_t, f_span), offsetof(vader_struct_vader_lower_LoweredAwait_t, f_target) },
        .ref_count = 2,
    },
    [858] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredBinary_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredBinary_t, f_type), offsetof(vader_struct_vader_lower_LoweredBinary_t, f_left), offsetof(vader_struct_vader_lower_LoweredBinary_t, f_right) },
        .ptr_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredBinary_t, f_span) },
        .ref_count = 1,
    },
    [859] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredBlock_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredBlock_t, f_type), offsetof(vader_struct_vader_lower_LoweredBlock_t, f_trailing) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredBlock_t, f_span), offsetof(vader_struct_vader_lower_LoweredBlock_t, f_stmts) },
        .ref_count = 2,
    },
    [860] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredBoolLit_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredBoolLit_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredBoolLit_t, f_span) },
        .ref_count = 1,
    },
    [861] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredBreak_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredBreak_t, f_label) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredBreak_t, f_span) },
        .ref_count = 1,
    },
    [862] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredCall_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredCall_t, f_type), offsetof(vader_struct_vader_lower_LoweredCall_t, f_callee) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredCall_t, f_span), offsetof(vader_struct_vader_lower_LoweredCall_t, f_args) },
        .ref_count = 2,
    },
    [863] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredCast_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredCast_t, f_type), offsetof(vader_struct_vader_lower_LoweredCast_t, f_value) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredCast_t, f_span) },
        .ref_count = 1,
    },
    [864] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredCellGet_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredCellGet_t, f_type), offsetof(vader_struct_vader_lower_LoweredCellGet_t, f_target), offsetof(vader_struct_vader_lower_LoweredCellGet_t, f_value_type) },
        .ptr_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredCellGet_t, f_span) },
        .ref_count = 1,
    },
    [865] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredCellNew_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredCellNew_t, f_type), offsetof(vader_struct_vader_lower_LoweredCellNew_t, f_value), offsetof(vader_struct_vader_lower_LoweredCellNew_t, f_value_type) },
        .ptr_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredCellNew_t, f_span) },
        .ref_count = 1,
    },
    [866] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredCellSet_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredCellSet_t, f_target), offsetof(vader_struct_vader_lower_LoweredCellSet_t, f_value), offsetof(vader_struct_vader_lower_LoweredCellSet_t, f_value_type) },
        .ptr_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredCellSet_t, f_span) },
        .ref_count = 1,
    },
    [867] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredCharLit_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredCharLit_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredCharLit_t, f_span) },
        .ref_count = 1,
    },
    [868] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredConstDecl_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredConstDecl_t, f_type), offsetof(vader_struct_vader_lower_LoweredConstDecl_t, f_value) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredConstDecl_t, f_mangled) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredConstDecl_t, f_origin) },
        .ref_count = 1,
    },
    [869] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredContinue_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredContinue_t, f_label) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredContinue_t, f_span) },
        .ref_count = 1,
    },
    [870] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredDataConst_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredDataConst_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredDataConst_t, f_span) },
        .ref_count = 1,
    },
    [871] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_LoweredDeferPopExec_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredDeferPopExec_t, f_span) },
        .ref_count = 1,
    },
    [872] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredDeferPush_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredDeferPush_t, f_thunk) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredDeferPush_t, f_span) },
        .ref_count = 1,
    },
    [873] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredExprStmt_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredExprStmt_t, f_expr) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredExprStmt_t, f_span) },
        .ref_count = 1,
    },
    [874] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_LoweredFieldAccess_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredFieldAccess_t, f_type), offsetof(vader_struct_vader_lower_LoweredFieldAccess_t, f_target) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredFieldAccess_t, f_field) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredFieldAccess_t, f_span) },
        .ref_count = 1,
    },
    [875] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredFloatLit_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredFloatLit_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredFloatLit_t, f_span) },
        .ref_count = 1,
    },
    [876] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredFnDecl_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredFnDecl_t, f_return_type), offsetof(vader_struct_vader_lower_LoweredFnDecl_t, f_body) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredFnDecl_t, f_mangled) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredFnDecl_t, f_params), offsetof(vader_struct_vader_lower_LoweredFnDecl_t, f_origin) },
        .ref_count = 2,
    },
    [877] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredIdent_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredIdent_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredIdent_t, f_span), offsetof(vader_struct_vader_lower_LoweredIdent_t, f_symbol) },
        .ref_count = 2,
    },
    [878] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredIf_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredIf_t, f_type), offsetof(vader_struct_vader_lower_LoweredIf_t, f_cond), offsetof(vader_struct_vader_lower_LoweredIf_t, f_else_block) },
        .ptr_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredIf_t, f_span), offsetof(vader_struct_vader_lower_LoweredIf_t, f_then_block) },
        .ref_count = 2,
    },
    [879] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredIndex_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredIndex_t, f_type), offsetof(vader_struct_vader_lower_LoweredIndex_t, f_target), offsetof(vader_struct_vader_lower_LoweredIndex_t, f_index) },
        .ptr_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredIndex_t, f_span) },
        .ref_count = 1,
    },
    [880] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredIntLit_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredIntLit_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredIntLit_t, f_span) },
        .ref_count = 1,
    },
    [881] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_LoweredIntrinsicCall_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredIntrinsicCall_t, f_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredIntrinsicCall_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredIntrinsicCall_t, f_span), offsetof(vader_struct_vader_lower_LoweredIntrinsicCall_t, f_args) },
        .ref_count = 2,
    },
    [882] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_LoweredLabelledBlock_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredLabelledBlock_t, f_label) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredLabelledBlock_t, f_span), offsetof(vader_struct_vader_lower_LoweredLabelledBlock_t, f_body) },
        .ref_count = 2,
    },
    [883] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredLet_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredLet_t, f_type), offsetof(vader_struct_vader_lower_LoweredLet_t, f_value) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredLet_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredLet_t, f_span), offsetof(vader_struct_vader_lower_LoweredLet_t, f_symbol) },
        .ref_count = 2,
    },
    [884] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredLoop_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredLoop_t, f_label), offsetof(vader_struct_vader_lower_LoweredLoop_t, f_cond), offsetof(vader_struct_vader_lower_LoweredLoop_t, f_turns) },
        .ptr_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredLoop_t, f_span), offsetof(vader_struct_vader_lower_LoweredLoop_t, f_body), offsetof(vader_struct_vader_lower_LoweredLoop_t, f_step) },
        .ref_count = 3,
    },
    [885] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_LoweredMakeClosure_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredMakeClosure_t, f_type), offsetof(vader_struct_vader_lower_LoweredMakeClosure_t, f_env) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredMakeClosure_t, f_span), offsetof(vader_struct_vader_lower_LoweredMakeClosure_t, f_fn_symbol) },
        .ref_count = 2,
    },
    [886] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredModule_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredModule_t, f_module_id), offsetof(vader_struct_vader_lower_LoweredModule_t, f_display_path) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredModule_t, f_decls) },
        .ref_count = 1,
    },
    [887] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredNullLit_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredNullLit_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredNullLit_t, f_span) },
        .ref_count = 1,
    },
    [888] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredParam_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredParam_t, f_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredParam_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredParam_t, f_symbol) },
        .ref_count = 1,
    },
    [889] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredProject_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredProject_t, f_entry) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredProject_t, f_modules), offsetof(vader_struct_vader_lower_LoweredProject_t, f_vtable_entries), offsetof(vader_struct_vader_lower_LoweredProject_t, f_data_pool), offsetof(vader_struct_vader_lower_LoweredProject_t, f_const_fn_wrap), offsetof(vader_struct_vader_lower_LoweredProject_t, f_const_inline), offsetof(vader_struct_vader_lower_LoweredProject_t, f_trait_membership) },
        .ref_count = 6,
    },
    [890] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredReturn_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredReturn_t, f_value) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredReturn_t, f_span) },
        .ref_count = 1,
    },
    [891] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredStringLit_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredStringLit_t, f_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredStringLit_t, f_value) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredStringLit_t, f_span) },
        .ref_count = 1,
    },
    [892] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_LoweredStringSlice_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredStringSlice_t, f_type), offsetof(vader_struct_vader_lower_LoweredStringSlice_t, f_target), offsetof(vader_struct_vader_lower_LoweredStringSlice_t, f_lo), offsetof(vader_struct_vader_lower_LoweredStringSlice_t, f_hi) },
        .ptr_count = 4,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredStringSlice_t, f_span) },
        .ref_count = 1,
    },
    [893] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_LoweredStructDecl_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredStructDecl_t, f_mangled) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredStructDecl_t, f_fields), offsetof(vader_struct_vader_lower_LoweredStructDecl_t, f_origin) },
        .ref_count = 2,
    },
    [894] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_LoweredStructField_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredStructField_t, f_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredStructField_t, f_name) },
        .string_count = 1,
    },
    [895] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredStructLit_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredStructLit_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredStructLit_t, f_span), offsetof(vader_struct_vader_lower_LoweredStructLit_t, f_fields) },
        .ref_count = 2,
    },
    [896] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_LoweredStructLitField_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredStructLitField_t, f_value) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredStructLitField_t, f_name) },
        .string_count = 1,
    },
    [897] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredTypeCheck_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredTypeCheck_t, f_type), offsetof(vader_struct_vader_lower_LoweredTypeCheck_t, f_value), offsetof(vader_struct_vader_lower_LoweredTypeCheck_t, f_check_type) },
        .ptr_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredTypeCheck_t, f_span) },
        .ref_count = 1,
    },
    [898] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredTypeConst_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredTypeConst_t, f_type), offsetof(vader_struct_vader_lower_LoweredTypeConst_t, f_value) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredTypeConst_t, f_span) },
        .ref_count = 1,
    },
    [899] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredUnary_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredUnary_t, f_type), offsetof(vader_struct_vader_lower_LoweredUnary_t, f_operand) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredUnary_t, f_span) },
        .ref_count = 1,
    },
    [900] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_LoweredUnreachable_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredUnreachable_t, f_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredUnreachable_t, f_reason) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredUnreachable_t, f_span) },
        .ref_count = 1,
    },
    [901] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_LoweredVirtualCall_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredVirtualCall_t, f_type), offsetof(vader_struct_vader_lower_LoweredVirtualCall_t, f_receiver) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredVirtualCall_t, f_trait_name), offsetof(vader_struct_vader_lower_LoweredVirtualCall_t, f_method) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredVirtualCall_t, f_span), offsetof(vader_struct_vader_lower_LoweredVirtualCall_t, f_args), offsetof(vader_struct_vader_lower_LoweredVirtualCall_t, f_param_types) },
        .ref_count = 3,
    },
    [902] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_LoweredVtableEntry_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredVtableEntry_t, f_struct_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredVtableEntry_t, f_trait_name), offsetof(vader_struct_vader_lower_LoweredVtableEntry_t, f_method_name) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredVtableEntry_t, f_fn_symbol) },
        .ref_count = 1,
    },
    [903] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_LoweredYield_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredYield_t, f_value) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_LoweredYield_t, f_span) },
        .ref_count = 1,
    },
    [904] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_OpTraitInfo_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_OpTraitInfo_t, f_trait_key), offsetof(vader_struct_vader_lower_OpTraitInfo_t, f_method_name) },
        .string_count = 2,
    },
    [905] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_OptMiss_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_OptMiss_t, f_pass), offsetof(vader_struct_vader_lower_OptMiss_t, f_note) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_OptMiss_t, f_span) },
        .ref_count = 1,
    },
    [906] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_PendingFnInstance_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_PendingFnInstance_t, f_module_id), offsetof(vader_struct_vader_lower_PendingFnInstance_t, f_key) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_PendingFnInstance_t, f_decl) },
        .ref_count = 1,
    },
    [907] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_lower_PrimDataPoolEntry_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_PrimDataPoolEntry_t, f_element_type_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_PrimDataPoolEntry_t, f_items) },
        .ref_count = 1,
    },
    [908] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_SplicedLanding_t),
        .slot_size = 8,
    },
    [909] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_StepShape_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_StepShape_t, f_type), offsetof(vader_struct_vader_lower_StepShape_t, f_element), offsetof(vader_struct_vader_lower_StepShape_t, f_cont) },
        .ptr_count = 3,
    },
    [910] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_StrDataPoolEntry_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_StrDataPoolEntry_t, f_values) },
        .ref_count = 1,
    },
    [911] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_UfcsMember_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_UfcsMember_t, f_symbol), offsetof(vader_struct_vader_lower_UfcsMember_t, f_arg_types) },
        .ref_count = 2,
    },
    [912] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_ValueAbiSite_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_ValueAbiSite_t, f_fn_name), offsetof(vader_struct_vader_lower_ValueAbiSite_t, f_position), offsetof(vader_struct_vader_lower_ValueAbiSite_t, f_type_name) },
        .string_count = 3,
    },
    [913] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_WalkCtx_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_WalkCtx_t, f_typed), offsetof(vader_struct_vader_lower_WalkCtx_t, f_symbol_index), offsetof(vader_struct_vader_lower_WalkCtx_t, f_analysis), offsetof(vader_struct_vader_lower_WalkCtx_t, f_empty_captures) },
        .ref_count = 4,
    },
    [914] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_lower_WrapResult_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_lower_WrapResult_t, f_iter), offsetof(vader_struct_vader_lower_WrapResult_t, f_iter_type) },
        .ptr_count = 2,
    },
    [915] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_AnnotatedProject_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_AnnotatedProject_t, f_project), offsetof(vader_struct_vader_midir_AnnotatedProject_t, f_stats) },
        .ref_count = 2,
    },
    [916] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_BasicBlock_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_BasicBlock_t, f_terminator) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_BasicBlock_t, f_instructions), offsetof(vader_struct_vader_midir_BasicBlock_t, f_span) },
        .ref_count = 2,
    },
    [917] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_CFGExternDecl_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_return_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_mangled), offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_extern_name), offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_c_header), offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_c_library) },
        .string_count = 4,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_params), offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_origin) },
        .ref_count = 2,
    },
    [918] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_CFGFunction_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGFunction_t, f_return_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGFunction_t, f_mangled), offsetof(vader_struct_vader_midir_CFGFunction_t, f_extern_name) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGFunction_t, f_params), offsetof(vader_struct_vader_midir_CFGFunction_t, f_locals), offsetof(vader_struct_vader_midir_CFGFunction_t, f_blocks), offsetof(vader_struct_vader_midir_CFGFunction_t, f_origin), offsetof(vader_struct_vader_midir_CFGFunction_t, f_scalarised_results) },
        .ref_count = 5,
    },
    [919] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_CFGLocal_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGLocal_t, f_type), offsetof(vader_struct_vader_midir_CFGLocal_t, f_symbol) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGLocal_t, f_name) },
        .string_count = 1,
    },
    [920] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_CFGModule_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGModule_t, f_module_id), offsetof(vader_struct_vader_midir_CFGModule_t, f_display_path) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGModule_t, f_functions), offsetof(vader_struct_vader_midir_CFGModule_t, f_externs), offsetof(vader_struct_vader_midir_CFGModule_t, f_struct_decls) },
        .ref_count = 3,
    },
    [921] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_CFGParam_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGParam_t, f_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGParam_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGParam_t, f_symbol) },
        .ref_count = 1,
    },
    [922] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_CFGProject_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGProject_t, f_modules), offsetof(vader_struct_vader_midir_CFGProject_t, f_vtable_entries), offsetof(vader_struct_vader_midir_CFGProject_t, f_strings), offsetof(vader_struct_vader_midir_CFGProject_t, f_data_pool), offsetof(vader_struct_vader_midir_CFGProject_t, f_trait_membership) },
        .ref_count = 5,
    },
    [923] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_CFGStructDecl_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGStructDecl_t, f_mangled) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGStructDecl_t, f_fields), offsetof(vader_struct_vader_midir_CFGStructDecl_t, f_origin) },
        .ref_count = 2,
    },
    [924] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_CFGStructField_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGStructField_t, f_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_CFGStructField_t, f_name) },
        .string_count = 1,
    },
    [925] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_CondReach_t),
        .slot_size = 8,
    },
    [926] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_ConstBool_t),
        .slot_size = 8,
    },
    [927] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_ConstChar_t),
        .slot_size = 8,
    },
    [928] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_ConstFloat_t),
        .slot_size = 8,
    },
    [929] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_ConstInt_t),
        .slot_size = 8,
    },
    [930] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_ConstNull_t),
        .slot_size = 8,
    },
    [931] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_ConstString_t),
        .slot_size = 8,
    },
    [932] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_DirectCallTarget_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_DirectCallTarget_t, f_op) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_DirectCallTarget_t, f_signature) },
        .ref_count = 1,
    },
    [933] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_EscapeResult_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_EscapeResult_t, f_escaping), offsetof(vader_struct_vader_midir_EscapeResult_t, f_alias_of), offsetof(vader_struct_vader_midir_EscapeResult_t, f_alias_from) },
        .ref_count = 3,
    },
    [934] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_EscapeSite_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_EscapeSite_t, f_kind), offsetof(vader_struct_vader_midir_EscapeSite_t, f_type_name) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_EscapeSite_t, f_span) },
        .ref_count = 1,
    },
    [935] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_EscapeStats_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_EscapeStats_t, f_heap_sites) },
        .ref_count = 1,
    },
    [936] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_FnCtx_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_FnCtx_t, f_return_type), offsetof(vader_struct_vader_midir_FnCtx_t, f_current) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_FnCtx_t, f_mangled) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_FnCtx_t, f_project), offsetof(vader_struct_vader_midir_FnCtx_t, f_origin), offsetof(vader_struct_vader_midir_FnCtx_t, f_params), offsetof(vader_struct_vader_midir_FnCtx_t, f_locals), offsetof(vader_struct_vader_midir_FnCtx_t, f_local_by_sym_id), offsetof(vader_struct_vader_midir_FnCtx_t, f_blocks), offsetof(vader_struct_vader_midir_FnCtx_t, f_loop_stack) },
        .ref_count = 7,
    },
    [937] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_FnEmitCfg_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_fn_), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_pinned_types_bucket), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_slot), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_project), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_string_index_map), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_local_to_slot), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_scopes), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_pending), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_hints) },
        .ref_count = 9,
    },
    [938] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_FnMetadata_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_FnMetadata_t, f_extern_name), offsetof(vader_struct_vader_midir_FnMetadata_t, f_c_library), offsetof(vader_struct_vader_midir_FnMetadata_t, f_c_header) },
        .string_count = 3,
    },
    [939] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrArrayGet_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrArrayGet_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrArrayGet_t, f_span) },
        .ref_count = 1,
    },
    [940] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrArrayLen_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrArrayLen_t, f_span) },
        .ref_count = 1,
    },
    [941] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrArrayNew_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrArrayNew_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrArrayNew_t, f_span), offsetof(vader_struct_vader_midir_InstrArrayNew_t, f_elements) },
        .ref_count = 2,
    },
    [942] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrArrayPush_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrArrayPush_t, f_span) },
        .ref_count = 1,
    },
    [943] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrArraySet_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrArraySet_t, f_span) },
        .ref_count = 1,
    },
    [944] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrArraySlice_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrArraySlice_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrArraySlice_t, f_span) },
        .ref_count = 1,
    },
    [945] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrBinOp_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrBinOp_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrBinOp_t, f_span) },
        .ref_count = 1,
    },
    [946] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrCall_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrCall_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrCall_t, f_span), offsetof(vader_struct_vader_midir_InstrCall_t, f_dsts), offsetof(vader_struct_vader_midir_InstrCall_t, f_callee), offsetof(vader_struct_vader_midir_InstrCall_t, f_args) },
        .ref_count = 4,
    },
    [947] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_midir_InstrCallIndirect_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrCallIndirect_t, f_dst), offsetof(vader_struct_vader_midir_InstrCallIndirect_t, f_fn_type), offsetof(vader_struct_vader_midir_InstrCallIndirect_t, f_type) },
        .ptr_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrCallIndirect_t, f_span), offsetof(vader_struct_vader_midir_InstrCallIndirect_t, f_args) },
        .ref_count = 2,
    },
    [948] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrCast_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrCast_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrCast_t, f_span) },
        .ref_count = 1,
    },
    [949] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrCellGet_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrCellGet_t, f_value_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrCellGet_t, f_span) },
        .ref_count = 1,
    },
    [950] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrCellNew_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrCellNew_t, f_value_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrCellNew_t, f_span) },
        .ref_count = 1,
    },
    [951] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrCellSet_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrCellSet_t, f_value_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrCellSet_t, f_span) },
        .ref_count = 1,
    },
    [952] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrConst_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrConst_t, f_value), offsetof(vader_struct_vader_midir_InstrConst_t, f_type) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrConst_t, f_span) },
        .ref_count = 1,
    },
    [953] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrDataConst_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrDataConst_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrDataConst_t, f_span) },
        .ref_count = 1,
    },
    [954] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_midir_InstrDeferPopExec_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrDeferPopExec_t, f_span) },
        .ref_count = 1,
    },
    [955] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrDeferPush_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrDeferPush_t, f_span) },
        .ref_count = 1,
    },
    [956] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrFieldGet_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrFieldGet_t, f_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrFieldGet_t, f_field) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrFieldGet_t, f_span) },
        .ref_count = 1,
    },
    [957] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrFieldSet_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrFieldSet_t, f_field) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrFieldSet_t, f_span) },
        .ref_count = 1,
    },
    [958] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrFnAddr_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrFnAddr_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrFnAddr_t, f_span), offsetof(vader_struct_vader_midir_InstrFnAddr_t, f_fn_symbol) },
        .ref_count = 2,
    },
    [959] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrFnRef_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrFnRef_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrFnRef_t, f_span), offsetof(vader_struct_vader_midir_InstrFnRef_t, f_fn_symbol) },
        .ref_count = 2,
    },
    [960] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrIntrinsic_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrIntrinsic_t, f_dst) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrIntrinsic_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrIntrinsic_t, f_span), offsetof(vader_struct_vader_midir_InstrIntrinsic_t, f_args) },
        .ref_count = 2,
    },
    [961] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrMakeClosure_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrMakeClosure_t, f_env_type), offsetof(vader_struct_vader_midir_InstrMakeClosure_t, f_type) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrMakeClosure_t, f_span), offsetof(vader_struct_vader_midir_InstrMakeClosure_t, f_fn_symbol) },
        .ref_count = 2,
    },
    [962] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrMove_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrMove_t, f_span) },
        .ref_count = 1,
    },
    [963] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrStringSlice_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrStringSlice_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrStringSlice_t, f_span) },
        .ref_count = 1,
    },
    [964] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrStructNew_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrStructNew_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrStructNew_t, f_span), offsetof(vader_struct_vader_midir_InstrStructNew_t, f_fields) },
        .ref_count = 2,
    },
    [965] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrTypeCheck_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrTypeCheck_t, f_check_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrTypeCheck_t, f_span) },
        .ref_count = 1,
    },
    [966] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrTypeConst_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrTypeConst_t, f_type), offsetof(vader_struct_vader_midir_InstrTypeConst_t, f_value_type) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrTypeConst_t, f_span) },
        .ref_count = 1,
    },
    [967] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrUnOp_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrUnOp_t, f_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrUnOp_t, f_span) },
        .ref_count = 1,
    },
    [968] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_InstrVirtualCall_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrVirtualCall_t, f_dst), offsetof(vader_struct_vader_midir_InstrVirtualCall_t, f_type) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrVirtualCall_t, f_trait_name), offsetof(vader_struct_vader_midir_InstrVirtualCall_t, f_method) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_InstrVirtualCall_t, f_span), offsetof(vader_struct_vader_midir_InstrVirtualCall_t, f_args), offsetof(vader_struct_vader_midir_InstrVirtualCall_t, f_param_types) },
        .ref_count = 3,
    },
    [969] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_Liveness_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_Liveness_t, f_live_in), offsetof(vader_struct_vader_midir_Liveness_t, f_live_out) },
        .ref_count = 2,
    },
    [970] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_LoopFrame_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_LoopFrame_t, f_label) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_LoopFrame_t, f_step) },
        .ref_count = 1,
    },
    [971] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_MutableBlock_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_MutableBlock_t, f_terminator) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_MutableBlock_t, f_instructions), offsetof(vader_struct_vader_midir_MutableBlock_t, f_span) },
        .ref_count = 2,
    },
    [972] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_OperandEdges_t),
        .slot_size = 8,
    },
    [973] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_PendingBranch_t),
        .slot_size = 8,
    },
    [974] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_ProjectCtx_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_ProjectCtx_t, f_strings), offsetof(vader_struct_vader_midir_ProjectCtx_t, f_string_index), offsetof(vader_struct_vader_midir_ProjectCtx_t, f_const_fn_wrap), offsetof(vader_struct_vader_midir_ProjectCtx_t, f_const_inline), offsetof(vader_struct_vader_midir_ProjectCtx_t, f_extern_callbacks), offsetof(vader_struct_vader_midir_ProjectCtx_t, f_diags) },
        .ref_count = 6,
    },
    [975] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_ScheduleHints_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_ScheduleHints_t, f_skip_set), offsetof(vader_struct_vader_midir_ScheduleHints_t, f_skip_first_get), offsetof(vader_struct_vader_midir_ScheduleHints_t, f_skip_terminator_get) },
        .ref_count = 3,
    },
    [976] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_ScopeFrame_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_ScopeFrame_t, f_kind) },
        .string_count = 1,
    },
    [977] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_StructureShape_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_StructureShape_t, f_rpo_index), offsetof(vader_struct_vader_midir_StructureShape_t, f_loop_header), offsetof(vader_struct_vader_midir_StructureShape_t, f_merge), offsetof(vader_struct_vader_midir_StructureShape_t, f_merges), offsetof(vader_struct_vader_midir_StructureShape_t, f_exits), offsetof(vader_struct_vader_midir_StructureShape_t, f_copied) },
        .ref_count = 6,
    },
    [978] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_TermBranch_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_TermBranch_t, f_span) },
        .ref_count = 1,
    },
    [979] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_TermCondBranch_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_TermCondBranch_t, f_span) },
        .ref_count = 1,
    },
    [980] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_TermReturn_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_TermReturn_t, f_span), offsetof(vader_struct_vader_midir_TermReturn_t, f_values) },
        .ref_count = 2,
    },
    [981] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_midir_TermUnreachable_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_TermUnreachable_t, f_reason) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_midir_TermUnreachable_t, f_span) },
        .ref_count = 1,
    },
    [982] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_parser_CommaList__Any_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_CommaList__Any_t, f_items) },
        .ref_count = 1,
    },
    [983] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_parser_CommaList__CallArg_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_CommaList__CallArg_t, f_items) },
        .ref_count = 1,
    },
    [984] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_parser_CommaList__ImportName_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_CommaList__ImportName_t, f_items) },
        .ref_count = 1,
    },
    [985] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t, f_items) },
        .ref_count = 1,
    },
    [986] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_parser_CompoundOpResult_t), .slot_size = 8,
    },
    [987] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_parser_FnBodyTail_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_FnBodyTail_t, f_body) },
        .ptr_count = 1,
    },
    [988] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_parser_FnSignature_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_FnSignature_t, f_params), offsetof(vader_struct_vader_parser_FnSignature_t, f_type_params) },
        .ref_count = 2,
    },
    [989] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_parser_InfixOpDescr_t),
        .slot_size = 8,
    },
    [990] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_parser_IntrinsicSpec_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_IntrinsicSpec_t, f_name), offsetof(vader_struct_vader_parser_IntrinsicSpec_t, f_result) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_IntrinsicSpec_t, f_args) },
        .ref_count = 1,
    },
    [991] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_parser_ModuleHeader_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_ModuleHeader_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_ModuleHeader_t, f_name_span) },
        .ref_count = 1,
    },
    [992] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_parser_NodeIdFactory_t),
        .slot_size = 8,
    },
    [993] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_parser_ParsedSource_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_ParsedSource_t, f_program), offsetof(vader_struct_vader_parser_ParsedSource_t, f_tokens), offsetof(vader_struct_vader_parser_ParsedSource_t, f_errors), offsetof(vader_struct_vader_parser_ParsedSource_t, f_id_factory) },
        .ref_count = 4,
    },
    [994] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_parser_Parser_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_Parser_t, f_shr_pending_half) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_Parser_t, f_file) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_Parser_t, f_tokens), offsetof(vader_struct_vader_parser_Parser_t, f_errors), offsetof(vader_struct_vader_parser_Parser_t, f_pending_decls) },
        .ref_count = 3,
    },
    [995] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_parser_StringLitInfo_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_StringLitInfo_t, f_text) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_parser_StringLitInfo_t, f_span) },
        .ref_count = 1,
    },
    [996] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_resolver_CollectedModule_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_CollectedModule_t, f_symbols), offsetof(vader_struct_vader_resolver_CollectedModule_t, f_fn_overloads), offsetof(vader_struct_vader_resolver_CollectedModule_t, f_imports), offsetof(vader_struct_vader_resolver_CollectedModule_t, f_import_paths), offsetof(vader_struct_vader_resolver_CollectedModule_t, f_files) },
        .ref_count = 5,
    },
    [997] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_resolver_DiscoveredModule_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_DiscoveredModule_t, f_name), offsetof(vader_struct_vader_resolver_DiscoveredModule_t, f_folder) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_DiscoveredModule_t, f_files) },
        .ref_count = 1,
    },
    [998] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_FileImports_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_FileImports_t, f_file) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_FileImports_t, f_paths), offsetof(vader_struct_vader_resolver_FileImports_t, f_excludes), offsetof(vader_struct_vader_resolver_FileImports_t, f_bindings) },
        .ref_count = 3,
    },
    [999] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_FileScope_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_FileScope_t, f_root), offsetof(vader_struct_vader_resolver_FileScope_t, f_ambiguous) },
        .ref_count = 2,
    },
    [1000] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_FolderBucket_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_FolderBucket_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_FolderBucket_t, f_first_decl_span), offsetof(vader_struct_vader_resolver_FolderBucket_t, f_files) },
        .ref_count = 2,
    },
    [1001] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_ImportInfo_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_ImportInfo_t, f_imported_name) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_ImportInfo_t, f_path), offsetof(vader_struct_vader_resolver_ImportInfo_t, f_local) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_ImportInfo_t, f_binding_span) },
        .ref_count = 1,
    },
    [1002] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_resolver_ImportTargetTable_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_ImportTargetTable_t, f_symbol_targets), offsetof(vader_struct_vader_resolver_ImportTargetTable_t, f_namespace_targets), offsetof(vader_struct_vader_resolver_ImportTargetTable_t, f_missing) },
        .ref_count = 3,
    },
    [1003] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_IncludePath_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_IncludePath_t, f_dir), offsetof(vader_struct_vader_resolver_IncludePath_t, f_prefix) },
        .string_count = 2,
    },
    [1004] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_LoadedModule_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_LoadedModule_t, f_module), offsetof(vader_struct_vader_resolver_LoadedModule_t, f_collected), offsetof(vader_struct_vader_resolver_LoadedModule_t, f_node_id_factory), offsetof(vader_struct_vader_resolver_LoadedModule_t, f_discarded_bodies) },
        .ref_count = 4,
    },
    [1005] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_LoadedProject_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_LoadedProject_t, f_project_root) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_LoadedProject_t, f_entry) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_LoadedProject_t, f_modules), offsetof(vader_struct_vader_resolver_LoadedProject_t, f_factory), offsetof(vader_struct_vader_resolver_LoadedProject_t, f_diags) },
        .ref_count = 3,
    },
    [1006] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_Manifest_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_Manifest_t, f_include_paths) },
        .ref_count = 1,
    },
    [1007] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_Module_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_Module_t, f_id), offsetof(vader_struct_vader_resolver_Module_t, f_display_path), offsetof(vader_struct_vader_resolver_Module_t, f_module_name) },
        .string_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_Module_t, f_files) },
        .ref_count = 1,
    },
    [1008] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_MutableDecl_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_MutableDecl_t, f_syms), offsetof(vader_struct_vader_resolver_MutableDecl_t, f_span) },
        .ref_count = 2,
    },
    [1009] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_ResolveState_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_ResolveState_t, f_lambda_frame) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_ResolveState_t, f_module_path) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_ResolveState_t, f_idents), offsetof(vader_struct_vader_resolver_ResolveState_t, f_immutable_locals), offsetof(vader_struct_vader_resolver_ResolveState_t, f_immutable_borrows), offsetof(vader_struct_vader_resolver_ResolveState_t, f_type_param_bounds), offsetof(vader_struct_vader_resolver_ResolveState_t, f_mutable_decls), offsetof(vader_struct_vader_resolver_ResolveState_t, f_reassigned), offsetof(vader_struct_vader_resolver_ResolveState_t, f_declared_locals), offsetof(vader_struct_vader_resolver_ResolveState_t, f_rebind_log), offsetof(vader_struct_vader_resolver_ResolveState_t, f_loop_rebinds), offsetof(vader_struct_vader_resolver_ResolveState_t, f_closure_rebound), offsetof(vader_struct_vader_resolver_ResolveState_t, f_diags), offsetof(vader_struct_vader_resolver_ResolveState_t, f_scope), offsetof(vader_struct_vader_resolver_ResolveState_t, f_factory), offsetof(vader_struct_vader_resolver_ResolveState_t, f_ambiguous), offsetof(vader_struct_vader_resolver_ResolveState_t, f_file_scopes) },
        .ref_count = 15,
    },
    [1010] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_ResolvedFile_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_idents), offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_immutable_locals), offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_immutable_borrows), offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_rebind_free), offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_loop_rebinds), offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_closure_rebound), offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_type_param_bounds), offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_diags) },
        .ref_count = 8,
    },
    [1011] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_resolver_ResolvedModule_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_path), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_display_path) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_symbols), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_import_bindings), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_idents), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_immutable_locals), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_immutable_borrows), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_rebind_free), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_loop_rebinds), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_closure_rebound), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_fn_overloads), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_imports_to), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_alias_types), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_alias_decls), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_type_param_bounds), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_diags), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_deprecated_messages), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_namespace_member_types), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_namespace_private_members) },
        .ref_count = 17,
    },
    [1012] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_Scope_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_Scope_t, f_frames) },
        .ref_count = 1,
    },
    [1013] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_SearchRoots_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_SearchRoots_t, f_project_root), offsetof(vader_struct_vader_resolver_SearchRoots_t, f_entry) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_SearchRoots_t, f_paths) },
        .ref_count = 1,
    },
    [1014] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_SourceFile_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_SourceFile_t, f_path), offsetof(vader_struct_vader_resolver_SourceFile_t, f_content) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_SourceFile_t, f_program), offsetof(vader_struct_vader_resolver_SourceFile_t, f_id_factory) },
        .ref_count = 2,
    },
    [1015] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_StampCtx_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_StampCtx_t, f_file) },
        .string_count = 1,
    },
    [1016] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_Subst_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_Subst_t, f_entries) },
        .ref_count = 1,
    },
    [1017] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_SymbolTarget_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_SymbolTarget_t, f_module_id) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_SymbolTarget_t, f_symbol) },
        .ref_count = 1,
    },
    [1018] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_resolver_TargetSelectors_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_TargetSelectors_t, f_os) },
        .ref_count = 1,
    },
    [1019] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_resolver_symbol_Symbol_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_symbol_Symbol_t, f_defined_at) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_symbol_Symbol_t, f_name), offsetof(vader_struct_vader_resolver_symbol_Symbol_t, f_module), offsetof(vader_struct_vader_resolver_symbol_Symbol_t, f_module_name) },
        .string_count = 3,
    },
    [1020] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_resolver_symbol_SymbolFactory_t), .slot_size = 8,
    },
    [1021] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_resolver_symbol_SymbolKindInfo_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_resolver_symbol_SymbolKindInfo_t, f_label) },
        .string_count = 1,
    },
    [1022] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_target_AllTargets_t),
        .slot_size = 8,
    },
    [1023] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_target_Target_t),
        .slot_size = 8,
    },
    [1024] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_ArgBound_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ArgBound_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ArgBound_t, f_traits) },
        .ref_count = 1,
    },
    [1025] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_ArgEdge_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ArgEdge_t, f_root), offsetof(vader_struct_vader_typecheck_ArgEdge_t, f_arg_ty) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ArgEdge_t, f_callee) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ArgEdge_t, f_call) },
        .ref_count = 1,
    },
    [1026] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_ArgPick_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ArgPick_t, f_best), offsetof(vader_struct_vader_typecheck_ArgPick_t, f_rival) },
        .ptr_count = 2,
    },
    [1027] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_BlockNarrow_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_BlockNarrow_t, f_static_ty), offsetof(vader_struct_vader_typecheck_BlockNarrow_t, f_else_ty) },
        .ptr_count = 2,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_BlockNarrow_t, f_field_key) },
        .string_count = 1,
    },
    [1028] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_BoundedImpl_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_BoundedImpl_t, f_trait_key) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_BoundedImpl_t, f_bounds) },
        .ref_count = 1,
    },
    [1029] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_CheckResult_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_CheckResult_t, f_typed), offsetof(vader_struct_vader_typecheck_CheckResult_t, f_impls), offsetof(vader_struct_vader_typecheck_CheckResult_t, f_others), offsetof(vader_struct_vader_typecheck_CheckResult_t, f_all_modules) },
        .ref_count = 4,
    },
    [1030] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_ConstTyping_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ConstTyping_t, f_decl) },
        .ref_count = 1,
    },
    [1031] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_ConstWalk_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ConstWalk_t, f_decls), offsetof(vader_struct_vader_typecheck_ConstWalk_t, f_states), offsetof(vader_struct_vader_typecheck_ConstWalk_t, f_typing), offsetof(vader_struct_vader_typecheck_ConstWalk_t, f_diags) },
        .ref_count = 4,
    },
    [1032] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_DeadDecl_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_DeadDecl_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_DeadDecl_t, f_name_span) },
        .ref_count = 1,
    },
    [1033] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_DefaultFill_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_DefaultFill_t, f_filling), offsetof(vader_struct_vader_typecheck_DefaultFill_t, f_filled), offsetof(vader_struct_vader_typecheck_DefaultFill_t, f_consts) },
        .ref_count = 3,
    },
    [1034] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_typecheck_DependencyFrame_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_DependencyFrame_t, f_decl), offsetof(vader_struct_vader_typecheck_DependencyFrame_t, f_reads) },
        .ref_count = 2,
    },
    [1035] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_typecheck_EnclosingLoop_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_EnclosingLoop_t, f_binding), offsetof(vader_struct_vader_typecheck_EnclosingLoop_t, f_label) },
        .ptr_count = 2,
    },
    [1036] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_EnumHeader_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_EnumHeader_t, f_repr), offsetof(vader_struct_vader_typecheck_EnumHeader_t, f_data) },
        .ptr_count = 2,
    },
    [1037] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_typecheck_FieldChainStatic_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_FieldChainStatic_t, f_static_ty) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_FieldChainStatic_t, f_field_key) },
        .string_count = 1,
    },
    [1038] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_typecheck_FillingDefault_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_FillingDefault_t, f_field) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_FillingDefault_t, f_decl), offsetof(vader_struct_vader_typecheck_FillingDefault_t, f_span) },
        .ref_count = 2,
    },
    [1039] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_FnCandidate_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_FnCandidate_t, f_decl) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_FnCandidate_t, f_ty), offsetof(vader_struct_vader_typecheck_FnCandidate_t, f_symbol) },
        .ref_count = 2,
    },
    [1040] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_FnContext_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_FnContext_t, f_return_type), offsetof(vader_struct_vader_typecheck_FnContext_t, f_self_type), offsetof(vader_struct_vader_typecheck_FnContext_t, f_yield_type), offsetof(vader_struct_vader_typecheck_FnContext_t, f_inferred_return) },
        .ptr_count = 4,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_FnContext_t, f_type_params_in_scope) },
        .ref_count = 1,
    },
    [1041] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_FnDeclRef_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_FnDeclRef_t, f_module) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_FnDeclRef_t, f_decl) },
        .ref_count = 1,
    },
    [1042] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_typecheck_GeneratorState_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_GeneratorState_t, f_element) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_GeneratorState_t, f_symbol) },
        .ref_count = 1,
    },
    [1043] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_ImplEntry_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ImplEntry_t, f_for_type) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ImplEntry_t, f_module), offsetof(vader_struct_vader_typecheck_ImplEntry_t, f_trait_key), offsetof(vader_struct_vader_typecheck_ImplEntry_t, f_target), offsetof(vader_struct_vader_typecheck_ImplEntry_t, f_overload_suffix) },
        .string_count = 4,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ImplEntry_t, f_decl), offsetof(vader_struct_vader_typecheck_ImplEntry_t, f_trait_symbol), offsetof(vader_struct_vader_typecheck_ImplEntry_t, f_trait_args) },
        .ref_count = 3,
    },
    [1044] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_ImplMethod_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ImplMethod_t, f_ty), offsetof(vader_struct_vader_typecheck_ImplMethod_t, f_decl), offsetof(vader_struct_vader_typecheck_ImplMethod_t, f_trait_symbol) },
        .ptr_count = 3,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ImplMethod_t, f_trait_key) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ImplMethod_t, f_trait_args) },
        .ref_count = 1,
    },
    [1045] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_ImplRegistry_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ImplRegistry_t, f_by_target), offsetof(vader_struct_vader_typecheck_ImplRegistry_t, f_by_decl), offsetof(vader_struct_vader_typecheck_ImplRegistry_t, f_all), offsetof(vader_struct_vader_typecheck_ImplRegistry_t, f_by_base), offsetof(vader_struct_vader_typecheck_ImplRegistry_t, f_specialized_args), offsetof(vader_struct_vader_typecheck_ImplRegistry_t, f_overloaded_bases) },
        .ref_count = 6,
    },
    [1046] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_ImplShape_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ImplShape_t, f_for_ty) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ImplShape_t, f_args), offsetof(vader_struct_vader_typecheck_ImplShape_t, f_span) },
        .ref_count = 2,
    },
    [1047] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_typecheck_ImportedFnSig_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ImportedFnSig_t, f_local), offsetof(vader_struct_vader_typecheck_ImportedFnSig_t, f_key) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ImportedFnSig_t, f_span) },
        .ref_count = 1,
    },
    [1048] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_typecheck_InferableSlot_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_InferableSlot_t, f_owner) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_InferableSlot_t, f_name), offsetof(vader_struct_vader_typecheck_InferableSlot_t, f_module), offsetof(vader_struct_vader_typecheck_InferableSlot_t, f_fn_name) },
        .string_count = 3,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_InferableSlot_t, f_span), offsetof(vader_struct_vader_typecheck_InferableSlot_t, f_written) },
        .ref_count = 2,
    },
    [1049] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_IsNarrow_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_IsNarrow_t, f_static_ty), offsetof(vader_struct_vader_typecheck_IsNarrow_t, f_then_ty), offsetof(vader_struct_vader_typecheck_IsNarrow_t, f_else_ty) },
        .ptr_count = 3,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_IsNarrow_t, f_field_key) },
        .string_count = 1,
    },
    [1050] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_LevelGap_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_LevelGap_t, f_want) },
        .ptr_count = 1,
    },
    [1051] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_LeverWalk_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_LeverWalk_t, f_typed), offsetof(vader_struct_vader_typecheck_LeverWalk_t, f_roots) },
        .ref_count = 2,
    },
    [1052] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_MarkCause_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_MarkCause_t, f_what), offsetof(vader_struct_vader_typecheck_MarkCause_t, f_via) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_MarkCause_t, f_span) },
        .ref_count = 1,
    },
    [1053] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_MarkedLevel_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_MarkedLevel_t, f_path), offsetof(vader_struct_vader_typecheck_MarkedLevel_t, f_cause) },
        .ref_count = 2,
    },
    [1054] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_typecheck_NamedDeclLookup_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_NamedDeclLookup_t, f_trait_decl) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_NamedDeclLookup_t, f_other_kind) },
        .string_count = 1,
    },
    [1055] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_typecheck_NamedDeclRefs_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_NamedDeclRefs_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_NamedDeclRefs_t, f_name_span), offsetof(vader_struct_vader_typecheck_NamedDeclRefs_t, f_decorators), offsetof(vader_struct_vader_typecheck_NamedDeclRefs_t, f_refs) },
        .ref_count = 3,
    },
    [1056] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_NarrowSlot_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_NarrowSlot_t, f_ty) },
        .ptr_count = 1,
    },
    [1057] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_NarrowState_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_NarrowState_t, f_bindings), offsetof(vader_struct_vader_typecheck_NarrowState_t, f_fields), offsetof(vader_struct_vader_typecheck_NarrowState_t, f_kill_gens), offsetof(vader_struct_vader_typecheck_NarrowState_t, f_field_kill_gens), offsetof(vader_struct_vader_typecheck_NarrowState_t, f_calling_right_operands), offsetof(vader_struct_vader_typecheck_NarrowState_t, f_binding_scrutinee) },
        .ref_count = 6,
    },
    [1058] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_typecheck_ParamInference_t), .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ParamInference_t, f_slots), offsetof(vader_struct_vader_typecheck_ParamInference_t, f_pending), offsetof(vader_struct_vader_typecheck_ParamInference_t, f_needs), offsetof(vader_struct_vader_typecheck_ParamInference_t, f_edges), offsetof(vader_struct_vader_typecheck_ParamInference_t, f_by_root), offsetof(vader_struct_vader_typecheck_ParamInference_t, f_marks) },
        .ref_count = 6,
    },
    [1059] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_PendingNeed_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_PendingNeed_t, f_want) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_PendingNeed_t, f_cause) },
        .ref_count = 1,
    },
    [1060] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_PushedNarrow_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_PushedNarrow_t, f_prev) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_PushedNarrow_t, f_field_key) },
        .string_count = 1,
    },
    [1061] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_ReprRange_t),
        .slot_size = 8,
    },
    [1062] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_RootedEdge_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_RootedEdge_t, f_edge) },
        .ref_count = 1,
    },
    [1063] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_SlotRoot_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_SlotRoot_t, f_holder) },
        .ptr_count = 1,
    },
    [1064] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_StaticMember_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_StaticMember_t, f_owner) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_StaticMember_t, f_trait_key) },
        .string_count = 1,
    },
    [1065] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_Substitution_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_Substitution_t, f_self_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_Substitution_t, f_type_params) },
        .ref_count = 1,
    },
    [1066] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_TagMember_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_TagMember_t, f_self_hazard) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_TagMember_t, f_member) },
        .ref_count = 1,
    },
    [1067] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_TypeMember_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_TypeMember_t, f_ty) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_TypeMember_t, f_trait_key) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_TypeMember_t, f_decl), offsetof(vader_struct_vader_typecheck_TypeMember_t, f_trait_args) },
        .ref_count = 2,
    },
    [1068] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_typecheck_TypeParamBound_t), .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_TypeParamBound_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_TypeParamBound_t, f_traits) },
        .ref_count = 1,
    },
    [1069] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_TypedProgram_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_import_targets), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_range_symbol), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_field_symbol), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_async_symbol), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_equals_symbol), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_run_async_main_symbol), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_current_fn_ctx), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_param_inference) },
        .ptr_count = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_resolved), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_expr_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_into_coercions), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_local_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_empty_array_inits), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_decl_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_impl_method_decl_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_param_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_type_expr_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_struct_decls), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_trait_decls), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_fn_decls), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_trait_decl_owners), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_impl_methods), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_narrow), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_expr_kinds), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_external_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_namespace_exports), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_namespace_export_decls), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_imported_fn_overloads), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_iter_element_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_index_target_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_index_key_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_index_set_key_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_index_set_value_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_ufcs_receiver_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_chosen_fns), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_chosen_impl_methods), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_overloaded_members), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_picked_impl_members), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_picked_index_writes), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_static_members), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_type_param_bound_traits), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_struct_bounds), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_impl_method_traits), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_struct_field_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_struct_implemented_traits), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_impl_bounds), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_struct_traits_by_sym), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_struct_trait_args), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_instance_impl_bases), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_node_spans), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_generator_states), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_extern_symbols), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_let_type_aliases), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_local_init_source), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_loop_var_iterable), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_local_annotation), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_const_decls), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_bounded_dispatch_trait), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_bounded_dispatch_args), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_fn_needs_concrete_instances), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_fn_observes_type_params), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_type_param_forwards), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_fn_display_dispatches), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_overload_result_callees), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_enum_data_reads), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_loop_stack), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_loop_target_labels), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_jump_labels), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_jump_targets), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_const_walk), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_local_bound_to) },
        .ref_count = 63,
    },
    [1070] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_TypedProject_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_TypedProject_t, f_modules) },
        .ref_count = 1,
    },
    [1071] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_UfcsResult_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_UfcsResult_t, f_curried), offsetof(vader_struct_vader_typecheck_UfcsResult_t, f_rival) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_UfcsResult_t, f_winner) },
        .ref_count = 1,
    },
    [1072] = {
        .kind = VADER_TYPE_KIND_STRUCT,
        .size = sizeof(vader_struct_vader_typecheck_UnionLeftover_t), .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_UnionLeftover_t, f_pattern), offsetof(vader_struct_vader_typecheck_UnionLeftover_t, f_actual) },
        .ptr_count = 2,
    },
    [1073] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_UnmetBound_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_UnmetBound_t, f_arg) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_UnmetBound_t, f_reason) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_UnmetBound_t, f_bound), offsetof(vader_struct_vader_typecheck_UnmetBound_t, f_required) },
        .ref_count = 2,
    },
    [1074] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_ValueReads_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_ValueReads_t, f_consts), offsetof(vader_struct_vader_typecheck_ValueReads_t, f_literals) },
        .ref_count = 2,
    },
    [1075] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_typecheck_WrittenMark_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_typecheck_WrittenMark_t, f_path), offsetof(vader_struct_vader_typecheck_WrittenMark_t, f_bang) },
        .ref_count = 2,
    },
    [1076] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_AnyType_t),
        .slot_size = 8,
    },
    [1077] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_ArrayType_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_ArrayType_t, f_element) },
        .ptr_count = 1,
    },
    [1078] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_DistinctType_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_DistinctType_t, f_backing) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_DistinctType_t, f_symbol) },
        .ref_count = 1,
    },
    [1079] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_EnumType_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_EnumType_t, f_data) },
        .ptr_count = 1,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_EnumType_t, f_repr) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_EnumType_t, f_symbol), offsetof(vader_struct_vader_types_EnumType_t, f_indices), offsetof(vader_struct_vader_types_EnumType_t, f_values) },
        .ref_count = 3,
    },
    [1080] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_FnType_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_FnType_t, f_return_type) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_FnType_t, f_params), offsetof(vader_struct_vader_types_FnType_t, f_params_mutable) },
        .ref_count = 2,
    },
    [1081] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_FreeCharType_t),
        .slot_size = 8,
    },
    [1082] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_FreeFloatType_t),
        .slot_size = 8,
    },
    [1083] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_FreeIntType_t),
        .slot_size = 8,
    },
    [1084] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_NeverType_t),
        .slot_size = 8,
    },
    [1085] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_PrimitiveMeta_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_PrimitiveMeta_t, f_name) },
        .string_count = 1,
    },
    [1086] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_PrimitiveType_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_PrimitiveType_t, f_name) },
        .string_count = 1,
    },
    [1087] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_SelfType_t),
        .slot_size = 8,
    },
    [1088] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_StructType_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_StructType_t, f_symbol), offsetof(vader_struct_vader_types_StructType_t, f_args) },
        .ref_count = 2,
    },
    [1089] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_TraitType_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_TraitType_t, f_symbol), offsetof(vader_struct_vader_types_TraitType_t, f_args) },
        .ref_count = 2,
    },
    [1090] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_TupleType_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_TupleType_t, f_elements) },
        .ref_count = 1,
    },
    [1091] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_TypeMetaType_t),
        .slot_size = 8,
    },
    [1092] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_TypeParamType_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_TypeParamType_t, f_symbol) },
        .ref_count = 1,
    },
    [1093] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_UnionType_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_types_UnionType_t, f_variants) },
        .ref_count = 1,
    },
    [1094] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_types_UnresolvedType_t),
        .slot_size = 8,
    },
    [1095] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_ArrayVal_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_ArrayVal_t, f_raw) },
        .ptr_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_ArrayVal_t, f_elements) },
        .ref_count = 1,
    },
    [1096] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_Blocks_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_Blocks_t, f_leaders), offsetof(vader_struct_vader_vm_Blocks_t, f_block_at), offsetof(vader_struct_vader_vm_Blocks_t, f_entry_depth), offsetof(vader_struct_vader_vm_Blocks_t, f_entry), offsetof(vader_struct_vader_vm_Blocks_t, f_work), offsetof(vader_struct_vader_vm_Blocks_t, f_queued) },
        .ref_count = 6,
    },
    [1097] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_DebugController_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_DebugController_t, f_output_sink), offsetof(vader_struct_vader_vm_DebugController_t, f_breakpoints), offsetof(vader_struct_vader_vm_DebugController_t, f_on_pause) },
        .ref_count = 3,
    },
    [1098] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_DebugSession_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_DebugSession_t, f_controller) },
        .ref_count = 1,
    },
    [1099] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_ErrorVal_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_ErrorVal_t, f_message) },
        .string_count = 1,
    },
    [1100] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_FnVal_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_FnVal_t, f_env) },
        .ptr_count = 1,
    },
    [1101] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_Frame_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_Frame_t, f_stack), offsetof(vader_struct_vader_vm_Frame_t, f_payload), offsetof(vader_struct_vader_vm_Frame_t, f_tag) },
        .ref_count = 3,
    },
    [1102] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_FunctionTags_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_FunctionTags_t, f_depth), offsetof(vader_struct_vader_vm_FunctionTags_t, f_stack) },
        .ref_count = 2,
    },
    [1103] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_FusedBranch_t),
        .slot_size = 8,
    },
    [1104] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_HostOk_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_HostOk_t, f_value) },
        .ptr_count = 1,
    },
    [1105] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_LentArray_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_LentArray_t, f_target) },
        .ref_count = 1,
    },
    [1106] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_LentStruct_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_LentStruct_t, f_target), offsetof(vader_struct_vader_vm_LentStruct_t, f_fields) },
        .ref_count = 2,
    },
    [1107] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_NullVal_t),
        .slot_size = 8,
    },
    [1108] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_ObjVal_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_ObjVal_t, f_bytes), offsetof(vader_struct_vader_vm_ObjVal_t, f_slots) },
        .ref_count = 2,
    },
    [1109] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_Ok_t), .slot_size = 8,
    },
    [1110] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_PauseCtx_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_PauseCtx_t, f_reason) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_PauseCtx_t, f_frames) },
        .ref_count = 1,
    },
    [1111] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_PauseFrame_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_PauseFrame_t, f_function_name), offsetof(vader_struct_vader_vm_PauseFrame_t, f_file) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_PauseFrame_t, f_locals) },
        .ref_count = 1,
    },
    [1112] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_PauseVar_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_PauseVar_t, f_name), offsetof(vader_struct_vader_vm_PauseVar_t, f_value) },
        .string_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_PauseVar_t, f_children) },
        .ref_count = 1,
    },
    [1113] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_Pending_t),
        .slot_size = 8,
    },
    [1114] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_RegFunction_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_RegFunction_t, f_name) },
        .string_count = 1,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_RegFunction_t, f_ops), offsetof(vader_struct_vader_vm_RegFunction_t, f_words), offsetof(vader_struct_vader_vm_RegFunction_t, f_origin), offsetof(vader_struct_vader_vm_RegFunction_t, f_consts), offsetof(vader_struct_vader_vm_RegFunction_t, f_const_tags), offsetof(vader_struct_vader_vm_RegFunction_t, f_values), offsetof(vader_struct_vader_vm_RegFunction_t, f_boxed), offsetof(vader_struct_vader_vm_RegFunction_t, f_virtuals), offsetof(vader_struct_vader_vm_RegFunction_t, f_virtual_rows), offsetof(vader_struct_vader_vm_RegFunction_t, f_texts) },
        .ref_count = 10,
    },
    [1115] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_RegMachine_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_RegMachine_t, f_debug), offsetof(vader_struct_vader_vm_RegMachine_t, f_null_value) },
        .ptr_count = 2,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_RegMachine_t, f_bits), offsetof(vader_struct_vader_vm_RegMachine_t, f_tags), offsetof(vader_struct_vader_vm_RegMachine_t, f_refs), offsetof(vader_struct_vader_vm_RegMachine_t, f_run), offsetof(vader_struct_vader_vm_RegMachine_t, f_scratch), offsetof(vader_struct_vader_vm_RegMachine_t, f_frame_code), offsetof(vader_struct_vader_vm_RegMachine_t, f_frame_base), offsetof(vader_struct_vader_vm_RegMachine_t, f_frame_return), offsetof(vader_struct_vader_vm_RegMachine_t, f_defers) },
        .ref_count = 9,
    },
    [1116] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_RegModule_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_RegModule_t, f_functions) },
        .ref_count = 1,
    },
    [1117] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_RunHost_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_RunHost_t, f_gc_state), offsetof(vader_struct_vader_vm_RunHost_t, f_sched_state), offsetof(vader_struct_vader_vm_RunHost_t, f_obj_handles) },
        .ref_count = 3,
    },
    [1118] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_Scalar_t),
        .slot_size = 8,
    },
    [1119] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_StackEffect_t),
        .slot_size = 8,
    },
    [1120] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_StructVal_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_StructVal_t, f_fields) },
        .ref_count = 1,
    },
    [1121] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_TagContext_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_TagContext_t, f_module), offsetof(vader_struct_vader_vm_TagContext_t, f_type_tags), offsetof(vader_struct_vader_vm_TagContext_t, f_virtual_results) },
        .ref_count = 3,
    },
    [1122] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_Translation_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_Translation_t, f_code), offsetof(vader_struct_vader_vm_Translation_t, f_operands), offsetof(vader_struct_vader_vm_Translation_t, f_stack), offsetof(vader_struct_vader_vm_Translation_t, f_jumps), offsetof(vader_struct_vader_vm_Translation_t, f_source_pc) },
        .ref_count = 5,
    },
    [1123] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_Trap_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_Trap_t, f_message) },
        .string_count = 1,
    },
    [1124] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_TypeVal_t),
        .slot_size = 8,
    },
    [1125] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_ValueOk_t),
        .slot_size = 8,
        .ptr_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_ValueOk_t, f_value) },
        .ptr_count = 1,
    },
    [1126] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_VerifyError_t),
        .slot_size = 8,
        .string_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_VerifyError_t, f_function), offsetof(vader_struct_vader_vm_VerifyError_t, f_message) },
        .string_count = 2,
    },
    [1127] = {
        .kind = VADER_TYPE_KIND_STRUCT, .size = sizeof(vader_struct_vader_vm_VmState_t),
        .slot_size = 8,
        .ref_offsets = (const uint16_t[]){ offsetof(vader_struct_vader_vm_VmState_t, f_bc), offsetof(vader_struct_vader_vm_VmState_t, f_data_pool), offsetof(vader_struct_vader_vm_VmState_t, f_fn_index_by_name), offsetof(vader_struct_vader_vm_VmState_t, f_import_ids), offsetof(vader_struct_vader_vm_VmState_t, f_reg) },
        .ref_count = 5,
    },
    [1128] = { .slot_size = 16 },
    [1129] = { .slot_size = 16 },
    [1130] = { .slot_size = 16 },
    [1131] = { .slot_size = 16 },
    [1132] = { .slot_size = 16 },
    [1133] = { .slot_size = 16 },
    [1134] = { .slot_size = 16 },
    [1135] = { .slot_size = 16 },
    [1136] = { .slot_size = 16 },
    [1137] = { .slot_size = 16 },
    [1138] = { .slot_size = 16 },
    [1139] = { .slot_size = 16 },
    [1140] = { .slot_size = 16 },
    [1141] = { .slot_size = 16 },
    [1142] = { .slot_size = 16 },
    [1143] = { .slot_size = 16 },
    [1144] = { .slot_size = 16 },
    [1145] = { .slot_size = 16 },
    [1146] = { .slot_size = 16 },
    [1147] = { .slot_size = 16 },
    [1148] = { .slot_size = 16 },
    [1149] = { .slot_size = 16 },
    [1150] = { .slot_size = 16 },
    [1151] = { .slot_size = 16 },
    [1152] = { .slot_size = 16 },
    [1153] = { .slot_size = 16 },
    [1154] = { .slot_size = 16 },
    [1155] = { .slot_size = 16 },
    [1156] = { .slot_size = 16 },
    [1157] = { .slot_size = 16 },
    [1158] = { .slot_size = 16 },
    [1159] = { .slot_size = 16 },
    [1160] = { .slot_size = 16 },
    [1161] = { .slot_size = 16 },
    [1162] = { .slot_size = 16 },
    [1163] = { .slot_size = 16 },
    [1164] = { .slot_size = 16 },
    [1165] = { .slot_size = 16 },
    [1166] = { .slot_size = 16 },
    [1167] = { .slot_size = 16 },
    [1168] = { .slot_size = 16 },
    [1169] = { .slot_size = 16 },
    [1170] = { .slot_size = 16 },
    [1171] = { .slot_size = 16 },
    [1172] = { .slot_size = 16 },
    [1173] = { .slot_size = 16 },
    [1174] = { .slot_size = 16 },
    [1175] = { .slot_size = 16 },
    [1176] = { .slot_size = 16 },
    [1177] = { .slot_size = 16 },
    [1178] = { .slot_size = 16 },
    [1179] = { .slot_size = 16 },
    [1180] = { .slot_size = 16 },
    [1181] = { .slot_size = 16 },
    [1182] = { .slot_size = 16 },
    [1183] = { .slot_size = 16 },
    [1184] = { .slot_size = 16 },
    [1185] = { .slot_size = 16 },
    [1186] = { .slot_size = 16 },
    [1187] = { .slot_size = 16 },
    [1188] = { .slot_size = 16 },
    [1189] = { .slot_size = 16 },
    [1190] = { .slot_size = 16 },
    [1191] = { .slot_size = 16 },
    [1192] = { .slot_size = 16 },
    [1193] = { .slot_size = 16 },
    [1194] = { .slot_size = 16 },
    [1195] = { .slot_size = 16 },
    [1196] = { .slot_size = 16 },
    [1197] = { .slot_size = 16 },
    [1198] = { .slot_size = 16 },
    [1199] = { .slot_size = 16 },
    [1200] = { .slot_size = 16 },
    [1201] = { .slot_size = 16 },
    [1202] = { .slot_size = 16 },
    [1203] = { .slot_size = 16 },
    [1204] = { .slot_size = 16 },
    [1205] = { .slot_size = 16 },
    [1206] = { .slot_size = 16 },
    [1207] = { .slot_size = 16 },
    [1208] = { .slot_size = 16 },
    [1209] = { .slot_size = 16 },
    [1210] = { .slot_size = 16 },
    [1211] = { .slot_size = 16 },
    [1212] = { .slot_size = 16 },
    [1213] = { .slot_size = 16 },
    [1214] = { .slot_size = 16 },
    [1215] = { .slot_size = 16 },
    [1216] = { .slot_size = 16 },
    [1217] = { .slot_size = 16 },
    [1218] = { .slot_size = 16 },
    [1219] = { .slot_size = 16 },
    [1220] = { .slot_size = 16 },
    [1221] = { .slot_size = 16 },
    [1222] = { .slot_size = 16 },
    [1223] = { .slot_size = 16 },
    [1224] = { .slot_size = 16 },
    [1225] = { .slot_size = 16 },
    [1226] = { .slot_size = 16 },
    [1227] = { .slot_size = 16 },
    [1228] = { .slot_size = 16 },
    [1229] = { .slot_size = 16 },
    [1230] = { .slot_size = 16 },
    [1231] = { .slot_size = 16 },
    [1232] = { .slot_size = 16 },
    [1233] = { .slot_size = 16 },
    [1234] = { .slot_size = 16 },
    [1235] = { .slot_size = 16 },
    [1236] = { .slot_size = 16 },
    [1237] = { .slot_size = 16 },
    [1238] = { .slot_size = 16 },
    [1239] = { .slot_size = 16 },
    [1240] = { .slot_size = 16 },
    [1241] = { .slot_size = 16 },
    [1242] = { .slot_size = 16 },
    [1243] = { .slot_size = 16 },
    [1244] = { .slot_size = 16 },
    [1245] = { .slot_size = 16 },
    [1246] = { .slot_size = 16 },
    [1247] = { .slot_size = 16 },
    [1248] = { .slot_size = 16 },
    [1249] = { .slot_size = 16 },
    [1250] = { .slot_size = 16 },
    [1251] = { .slot_size = 16 },
    [1252] = { .slot_size = 16 },
    [1253] = { .slot_size = 16 },
    [1254] = { .slot_size = 16 },
    [1255] = { .slot_size = 16 },
    [1256] = { .slot_size = 16 },
    [1257] = { .slot_size = 16 },
    [1258] = { .slot_size = 16 },
    [1259] = { .slot_size = 16 },
    [1260] = { .slot_size = 16 },
    [1261] = { .slot_size = 16 },
    [1262] = { .slot_size = 16 },
    [1263] = { .slot_size = 16 },
    [1264] = { .slot_size = 16 },
    [1265] = { .slot_size = 16 },
    [1266] = { .slot_size = 16 },
    [1267] = { .slot_size = 16 },
    [1268] = { .slot_size = 16 },
    [1269] = { .slot_size = 16 },
    [1270] = { .slot_size = 16 },
    [1271] = { .slot_size = 16 },
    [1272] = { .slot_size = 16 },
    [1273] = { .slot_size = 16 },
    [1274] = { .slot_size = 16 },
    [1275] = { .slot_size = 16 },
    [1276] = { .slot_size = 16 },
    [1277] = { .slot_size = 16 },
    [1278] = { .slot_size = 16 },
    [1279] = { .slot_size = 16 },
    [1280] = { .slot_size = 16 },
    [1281] = { .slot_size = 16 },
    [1282] = { .slot_size = 16 },
    [1283] = { .slot_size = 16 },
    [1284] = { .slot_size = 16 },
    [1285] = { .slot_size = 16 },
    [1286] = { .slot_size = 16 },
    [1287] = { .slot_size = 16 },
    [1288] = { .slot_size = 16 },
    [1289] = { .slot_size = 16 },
    [1290] = { .slot_size = 16 },
    [1291] = { .slot_size = 16 },
    [1292] = { .slot_size = 16 },
    [1293] = { .slot_size = 16 },
    [1294] = { .slot_size = 16 },
    [1295] = { .slot_size = 16 },
    [1296] = { .slot_size = 16 },
    [1297] = { .slot_size = 16 },
    [1298] = { .slot_size = 16 },
    [1299] = { .slot_size = 16 },
    [1300] = { .slot_size = 16 },
    [1301] = { .slot_size = 16 },
    [1302] = { .slot_size = 16 },
    [1303] = { .slot_size = 16 },
    [1304] = { .slot_size = 16 },
    [1305] = { .slot_size = 16 },
    [1306] = { .slot_size = 16 },
    [1307] = { .slot_size = 16 },
    [1308] = { .slot_size = 16 },
    [1309] = { .slot_size = 16 },
    [1310] = { .slot_size = 16 },
    [1311] = { .slot_size = 16 },
    [1312] = { .slot_size = 16 },
    [1313] = { .slot_size = 16 },
    [1314] = { .slot_size = 16 },
    [1315] = { .slot_size = 16 },
    [1316] = { .slot_size = 16 },
    [1317] = { .slot_size = 16 },
    [1318] = { .slot_size = 16 },
    [1319] = { .slot_size = 16 },
    [1320] = { .slot_size = 16 },
    [1321] = { .slot_size = 16 },
    [1322] = { .slot_size = 16 },
    [1323] = { .slot_size = 16 },
    [1324] = { .slot_size = 16 },
    [1325] = { .slot_size = 16 },
    [1326] = { .slot_size = 16 },
    [1327] = { .slot_size = 16 },
    [1328] = { .slot_size = 16 },
    [1329] = { .slot_size = 16 },
    [1330] = { .slot_size = 16 },
    [1331] = { .slot_size = 16 },
    [1332] = { .slot_size = 16 },
    [1333] = { .slot_size = 16 },
    [1334] = { .slot_size = 16 },
    [1335] = { .slot_size = 16 },
    [1336] = { .slot_size = 16 },
    [1337] = { .slot_size = 16 },
    [1338] = { .slot_size = 16 },
    [1339] = { .slot_size = 16 },
    [1340] = { .slot_size = 16 },
    [1341] = { .slot_size = 16 },
    [1342] = { .slot_size = 16 },
    [1343] = { .slot_size = 16 },
    [1344] = { .slot_size = 16 },
    [1345] = { .slot_size = 16 },
    [1346] = { .slot_size = 16 },
    [1347] = { .slot_size = 16 },
    [1348] = { .slot_size = 16 },
    [1349] = { .slot_size = 16 },
    [1350] = { .slot_size = 16 },
    [1351] = { .slot_size = 16 },
    [1352] = { .slot_size = 16 },
    [1353] = { .slot_size = 16 },
    [1354] = { .slot_size = 16 },
    [1355] = { .slot_size = 16 },
    [1356] = { .slot_size = 16 },
    [1357] = { .slot_size = 16 },
    [1358] = { .slot_size = 16 },
    [1359] = { .slot_size = 16 },
    [1360] = { .slot_size = 16 },
    [1361] = { .slot_size = 16 },
    [1362] = { .slot_size = 16 },
    [1363] = { .slot_size = 16 },
    [1364] = { .slot_size = 16 },
    [1365] = { .slot_size = 16 },
    [1366] = { .slot_size = 16 },
    [1367] = { .slot_size = 16 },
    [1368] = { .slot_size = 16 },
    [1369] = { .slot_size = 16 },
    [1370] = { .slot_size = 16 },
    [1371] = { .slot_size = 16 },
    [1372] = { .slot_size = 16 },
    [1373] = { .slot_size = 16 },
    [1374] = { .slot_size = 16 },
    [1375] = { .slot_size = 16 },
    [1376] = { .slot_size = 16 },
    [1377] = { .slot_size = 16 },
    [1378] = { .slot_size = 16 },
    [1379] = { .slot_size = 16 },
    [1380] = { .slot_size = 16 },
    [1381] = { .slot_size = 16 },
    [1382] = { .slot_size = 16 },
    [1383] = { .slot_size = 16 },
    [1384] = { .slot_size = 16 },
    [1385] = { .slot_size = 16 },
    [1386] = { .slot_size = 16 },
    [1387] = { .slot_size = 16 },
    [1388] = { .slot_size = 16 },
    [1389] = { .slot_size = 16 },
    [1390] = { .slot_size = 16 },
    [1391] = { .slot_size = 16 },
    [1392] = { .slot_size = 16 },
    [1393] = { .slot_size = 16 },
    [1394] = { .slot_size = 16 },
    [1395] = { .slot_size = 16 },
    [1396] = { .slot_size = 16 },
    [1397] = { .slot_size = 16 },
    [1398] = { .slot_size = 16 },
    [1399] = { .slot_size = 16 },
    [1400] = { .slot_size = 16 },
    [1401] = { .slot_size = 16 },
    [1402] = { .slot_size = 16 },
    [1403] = { .slot_size = 16 },
    [1404] = { .slot_size = 16 },
    [1405] = { .slot_size = 16 },
    [1406] = { .slot_size = 16 },
    [1407] = { .slot_size = 16 },
    [1408] = { .slot_size = 16 },
    [1409] = { .slot_size = 16 },
    [1410] = { .slot_size = 16 },
    [1411] = { .slot_size = 16 },
    [1412] = { .slot_size = 16 },
    [1413] = { .slot_size = 16 },
    [1414] = { .slot_size = 16 },
    [1415] = { .slot_size = 16 },
    [1416] = { .slot_size = 16 },
    [1417] = { .slot_size = 16 },
    [1418] = { .slot_size = 16 },
    [1419] = { .slot_size = 16 },
    [1420] = { .slot_size = 16 },
    [1421] = { .slot_size = 16 },
    [1422] = { .slot_size = 16 },
    [1423] = { .slot_size = 16 },
    [1424] = { .slot_size = 16 },
    [1425] = { .slot_size = 16 },
    [1426] = { .slot_size = 16 },
    [1427] = { .slot_size = 16 },
    [1428] = { .slot_size = 16 },
    [1429] = { .slot_size = 16 },
    [1430] = { .slot_size = 16 },
    [1431] = { .slot_size = 16 },
    [1432] = { .slot_size = 16 },
    [1433] = { .slot_size = 16 },
    [1434] = { .slot_size = 16 },
    [1435] = { .slot_size = 16 },
    [1436] = { .slot_size = 16 },
    [1437] = { .slot_size = 16 },
    [1438] = { .slot_size = 16 },
    [1439] = { .slot_size = 16 },
    [1440] = { .slot_size = 16 },
    [1441] = { .slot_size = 16 },
    [1442] = { .slot_size = 16 },
    [1443] = { .slot_size = 16 },
    [1444] = { .slot_size = 16 },
    [1445] = { .slot_size = 16 },
    [1446] = { .slot_size = 16 },
    [1447] = { .slot_size = 16 },
    [1448] = { .slot_size = 16 },
    [1449] = { .slot_size = 16 },
    [1450] = { .slot_size = 16 },
    [1451] = { .slot_size = 16 },
    [1452] = { .slot_size = 16 },
    [1453] = { .slot_size = 16 },
    [1454] = { .slot_size = 16 },
    [1455] = { .slot_size = 16 },
    [1456] = { .slot_size = 16 },
    [1457] = { .slot_size = 16 },
    [1458] = { .slot_size = 16 },
    [1459] = { .slot_size = 16 },
    [1460] = { .slot_size = 16 },
    [1461] = { .slot_size = 16 },
    [1462] = { .slot_size = 16 },
    [1463] = { .slot_size = 16 },
    [1464] = { .slot_size = 16 },
    [1465] = { .slot_size = 16 },
    [1466] = { .slot_size = 16 },
    [1467] = { .slot_size = 16 },
    [1468] = { .slot_size = 16 },
    [1469] = { .slot_size = 16 },
    [1470] = { .slot_size = 16 },
    [1471] = { .slot_size = 16 },
    [1472] = { .slot_size = 16 },
    [1473] = { .slot_size = 16 },
    [1474] = { .slot_size = 16 },
    [1475] = { .slot_size = 16 },
    [1476] = { .slot_size = 16 },
    [1477] = { .slot_size = 16 },
    [1478] = { .slot_size = 16 },
    [1479] = { .slot_size = 16 },
    [1480] = { .slot_size = 16 },
    [1481] = { .slot_size = 16 },
    [1482] = { .slot_size = 16 },
    [1483] = { .slot_size = 16 },
    [1484] = { .slot_size = 16 },
    [1485] = { .slot_size = 16 },
    [1486] = { .slot_size = 16 },
    [1487] = { .slot_size = 16 },
    [1488] = { .slot_size = 16 },
    [1489] = { .slot_size = 16 },
    [1490] = { .slot_size = 16 },
    [1491] = { .slot_size = 16 },
    [1492] = { .slot_size = 16 },
    [1493] = { .slot_size = 16 },
    [1494] = { .slot_size = 16 },
    [1495] = { .slot_size = 16 },
    [1496] = { .slot_size = 16 },
    [1497] = { .slot_size = 16 },
    [1498] = { .slot_size = 16 },
    [1499] = { .slot_size = 16 },
    [1500] = { .slot_size = 16 },
    [1501] = { .slot_size = 16 },
    [1502] = { .slot_size = 16 },
    [1503] = { .slot_size = 16 },
    [1504] = { .slot_size = 16 },
    [1505] = { .slot_size = 16 },
    [1506] = { .slot_size = 16 },
    [1507] = { .slot_size = 16 },
    [1508] = { .slot_size = 16 },
    [1509] = { .slot_size = 16 },
    [1510] = { .slot_size = 16 },
    [1511] = { .slot_size = 16 },
    [1512] = { .slot_size = 16 },
    [1513] = { .slot_size = 16 },
    [1514] = { .slot_size = 16 },
    [1515] = { .slot_size = 16 },
    [1516] = { .slot_size = 16 },
    [1517] = { .slot_size = 16 },
    [1518] = { .slot_size = 16 },
    [1519] = { .slot_size = 16 },
    [1520] = { .slot_size = 16 },
    [1521] = { .slot_size = 16 },
    [1522] = { .slot_size = 16 },
    [1523] = { .slot_size = 16 },
    [1524] = { .slot_size = 16 },
    [1525] = { .slot_size = 16 },
    [1526] = { .slot_size = 16 },
    [1527] = { .slot_size = 16 },
    [1528] = { .slot_size = 16 },
    [1529] = { .slot_size = 16 },
    [1530] = { .slot_size = 16 },
    [1531] = { .slot_size = 16 },
    [1532] = { .slot_size = 16 },
    [1533] = { .slot_size = 16 },
    [1534] = { .slot_size = 16 },
    [1535] = { .slot_size = 16 },
    [1536] = { .slot_size = 16 },
    [1537] = { .slot_size = 16 },
    [1538] = { .slot_size = 16 },
    [1539] = { .slot_size = 16 },
    [1540] = { .slot_size = 16 },
    [1541] = { .slot_size = 16 },
    [1542] = { .slot_size = 16 },
    [1543] = { .slot_size = 16 },
    [1544] = { .slot_size = 16 },
    [1545] = { .slot_size = 16 },
    [1546] = { .slot_size = 16 },
    [1547] = { .slot_size = 16 },
    [1548] = { .slot_size = 16 },
    [1549] = { .slot_size = 16 },
    [1550] = { .slot_size = 16 },
    [1551] = { .slot_size = 16 },
    [1552] = { .slot_size = 16 },
    [1553] = { .slot_size = 16 },
    [1554] = { .slot_size = 16 },
    [1555] = { .slot_size = 16 },
    [1556] = { .slot_size = 16 },
    [1557] = { .slot_size = 16 },
    [1558] = { .slot_size = 16 },
    [1559] = { .slot_size = 16 },
    [1560] = { .slot_size = 16 },
    [1561] = { .slot_size = 16 },
    [1562] = { .slot_size = 16 },
    [1563] = { .slot_size = 16 },
    [1564] = { .slot_size = 16 },
    [1565] = { .slot_size = 16 },
    [1566] = { .slot_size = 16 },
    [1567] = { .slot_size = 16 },
    [1568] = { .slot_size = 16 },
    [1569] = { .slot_size = 16 },
    [1570] = { .slot_size = 16 },
    [1571] = { .slot_size = 16 },
    [1572] = { .slot_size = 16 },
    [1573] = { .slot_size = 16 },
    [1574] = { .slot_size = 16 },
    [1575] = { .slot_size = 16 },
    [1576] = { .slot_size = 16 },
    [1577] = { .slot_size = 16 },
    [1578] = { .slot_size = 16 },
    [1579] = { .slot_size = 16 },
    [1580] = { .slot_size = 16 },
    [1581] = { .slot_size = 16 },
    [1582] = { .slot_size = 16 },
    [1583] = { .slot_size = 16 },
    [1584] = { .slot_size = 16 },
    [1585] = { .slot_size = 16 },
    [1586] = { .slot_size = 16 },
    [1587] = { .slot_size = 16 },
    [1588] = { .slot_size = 16 },
    [1589] = { .slot_size = 16 },
    [1590] = { .slot_size = 16 },
    [1591] = { .slot_size = 16 },
    [1592] = { .slot_size = 16 },
    [1593] = { .slot_size = 16 },
    [1594] = { .slot_size = 16 },
    [1595] = { .slot_size = 16 },
    [1596] = { .slot_size = 16 },
    [1597] = { .slot_size = 16 },
    [1598] = { .slot_size = 16 },
    [1599] = { .slot_size = 16 },
    [1600] = { .slot_size = 16 },
    [1601] = { .slot_size = 16 },
    [1602] = { .slot_size = 16 },
    [1603] = { .slot_size = 16 },
    [1604] = { .slot_size = 16 },
    [1605] = { .slot_size = 16 },
    [1606] = { .slot_size = 16 },
    [1607] = { .slot_size = 16 },
    [1608] = { .slot_size = 16 },
    [1609] = { .slot_size = 16 },
    [1610] = { .slot_size = 16 },
    [1611] = { .slot_size = 16 },
    [1612] = { .slot_size = 16 },
    [1613] = { .slot_size = 16 },
    [1614] = { .slot_size = 16 },
    [1615] = { .slot_size = 16 },
    [1616] = { .slot_size = 16 },
    [1617] = { .slot_size = 16 },
    [1618] = { .slot_size = 16 },
    [1619] = { .slot_size = 16 },
    [1620] = { .slot_size = 16 },
    [1621] = { .slot_size = 16 },
    [1622] = { .slot_size = 16 },
    [1623] = { .slot_size = 16 },
    [1624] = { .slot_size = 16 },
    [1625] = { .slot_size = 16 },
    [1626] = { .slot_size = 16 },
    [1627] = { .slot_size = 16 },
    [1628] = { .slot_size = 16 },
    [1629] = { .slot_size = 16 },
    [1630] = { .slot_size = 16 },
    [1631] = { .slot_size = 16 },
    [1632] = { .slot_size = 16 },
    [1633] = { .slot_size = 16 },
    [1634] = { .slot_size = 16 },
    [1635] = { .slot_size = 16 },
    [1636] = { .slot_size = 16 },
    [1637] = { .slot_size = 16 },
    [1638] = { .slot_size = 16 },
    [1639] = { .slot_size = 16 },
    [1640] = { .slot_size = 16 },
    [1641] = { .slot_size = 16 },
    [1642] = { .slot_size = 16 },
    [1643] = { .slot_size = 16 },
    [1644] = { .slot_size = 16 },
    [1645] = { .slot_size = 16 },
    [1646] = { .slot_size = 16 },
    [1647] = { .slot_size = 16 },
    [1648] = { .slot_size = 16 },
    [1649] = { .slot_size = 16 },
    [1650] = { .slot_size = 16 },
    [1651] = { .slot_size = 16 },
    [1652] = { .slot_size = 16 },
    [1653] = { .slot_size = 16 },
    [1654] = { .slot_size = 16 },
    [1655] = { .slot_size = 16 },
    [1656] = { .slot_size = 16 },
    [1657] = { .slot_size = 16 },
    [1658] = { .slot_size = 16 },
    [1659] = { .slot_size = 16 },
    [1660] = { .slot_size = 16 },
    [1661] = { .slot_size = 16 },
    [1662] = { .slot_size = 16 },
    [1663] = { .slot_size = 16 },
    [1664] = { .slot_size = 16 },
    [1665] = { .slot_size = 16 },
    [1666] = { .slot_size = 16 },
    [1667] = { .slot_size = 16 },
    [1668] = { .slot_size = 16 },
};
const size_t vader_type_info_count = 1669;
