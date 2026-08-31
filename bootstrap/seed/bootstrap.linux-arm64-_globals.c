#include "bootstrap.split.h"

/* Compile-time atom table — see docs/ATOM_INTERNING.md. */
const char vader_atom_blob[] =
    "\n" "\0"
    "\n# Diagnostics" "\0"
    "\n/* ----------------------------------------------- vtable dispatchers */\n" "\0"
    "\n/* ----------------------------------------------- vtable forwards */\n" "\0"
    "\x1b[" "\0"
    " " "\0"
    "    " "\0"
    "        case " "\0"
    "        default: vader_unreachable(\"vtable miss in " "\0"
    "    (void) env;\n" "\0"
    "    (void)argc; (void)argv;\n" "\0"
    "    (void)argc; (void)argv; vader_trap(\"main(argv): missing [string] type\"); return 1;\n" "\0"
    "    [" "\0"
    "    atexit(vader_atom_shutdown);\n" "\0"
    "    atexit(vader_gc_shutdown);\n" "\0"
    "    return " "\0"
    "    return (int) " "\0"
    "    return 0;\n" "\0"
    "    return vader_box_null();\n" "\0"
    "    switch (recv.tag) {\n" "\0"
    "    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);\n" "\0"
    "    vader_atom_roots_register(vader_global_const_arrays, " "\0"
    "    vader_box_t __args = vader_box_obj(" "\0"
    "    vader_box_t* gc_roots[" "\0"
    "    vader_gc_frame_t gc_frame = { vader_gc_top, " "\0"
    "    vader_gc_top = &gc_frame;\n" "\0"
    "    vader_gc_top = &vader_global_const_frame;\n" "\0"
    "    vader_gc_top = gc_frame.prev;\n" "\0"
    "    vader_obj_header_t header;\n" "\0"
    "    vader_unreachable(\"vtable miss in " "\0"
    "    void* " "\0"
    "    void* __args = (void*) vader_runtime_argv(argc, argv, " "\0"
    "    void* gc_stack_objs[" "\0"
    "    void** gc_raw_roots[" "\0"
    "    {" "\0"
    "    { " "\0"
    "    { 0u, 0u, " "\0"
    "    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, " "\0"
    "    }\n" "\0"
    " \"\\0\"" "\0"
    " &vader_data_" "\0"
    " (" "\0"
    " (+" "\0"
    " (bad bytecode)" "\0"
    " (depth " "\0"
    " (got " "\0"
    " (incl. env)" "\0"
    " (jump_table=" "\0"
    " (only null + primitive operands)" "\0"
    " (std/core must be force-loaded)" "\0"
    " * Out-of-arena pointers are immortal to the GC (it never copies /\n" "\0"
    " * relocates them), so `data.const` boxes a zero-copy view. */\n" "\0"
    " : " "\0"
    " : give it a marked type (`" "\0"
    " : no inlinable Into<[...]> coercion" "\0"
    " : the level that differs is the element" "\0"
    " ; a `[...]` pattern requires a tuple or array" "\0"
    " = " "\0"
    " = &" "\0"
    " = (" "\0"
    " = ((" "\0"
    " = (a" "\0"
    " = (vader_fn_t*) " "\0"
    " = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));" "\0"
    " = (void*) " "\0"
    " = (void*) &vader_data_" "\0"
    " = (void*) &vader_fn_static_" "\0"
    " = (void*) vader_buffer_new((size_t) " "\0"
    " = NULL;\n" "\0"
    " = a" "\0"
    " = vader_array_box_slots(" "\0"
    " = vader_array_bytes((vader_array_t*) a" "\0"
    " = vader_array_new(" "\0"
    " = vader_array_read_u8(" "\0"
    " = vader_array_remove_last((vader_array_t*) " "\0"
    " = vader_array_repeat((vader_array_t*) " "\0"
    " = vader_array_slice((vader_array_t*) " "\0"
    " = vader_box_null()" "\0"
    " = vader_string_to_cstr(a" "\0"
    " = { " "\0"
    " = { { " "\0"
    " = {0};\n" "\0"
    " == " "\0"
    " >= " "\0"
    " __vret = " "\0"
    " `" "\0"
    " a" "\0"
    " already used by `" "\0"
    " and " "\0"
    " arg" "\0"
    " arg 0" "\0"
    " arg 1" "\0"
    " arg(s) + fn-ref but stack has " "\0"
    " arg(s) but stack has " "\0"
    " argument(s), got " "\0"
    " as f64" "\0"
    " as numeric" "\0"
    " at pc=" "\0"
    " but '" "\0"
    " bytes=" "\0"
    " does not fit in `" "\0"
    " element(s)), got " "\0"
    " elements" "\0"
    " exceeds the argument array" "\0"
    " exceeds the buffer" "\0"
    " expects " "\0"
    " f_" "\0"
    " field " "\0"
    " field value(s) but stack has " "\0"
    " fields) at pc=" "\0"
    " for " "\0"
    " function " "\0"
    " has no type id at pc=" "\0"
    " implements Into<" "\0"
    " in '" "\0"
    " initial element(s) but stack has " "\0"
    " is " "\0"
    " is ambiguous between traits: " "\0"
    " is negative at pc=" "\0"
    " is not a fn type at pc=" "\0"
    " is not a struct" "\0"
    " is not a struct at pc=" "\0"
    " is not assignable to " "\0"
    " is not covered" "\0"
    " is not indexable" "\0"
    " is not valid in a character literal" "\0"
    " l" "\0"
    " lacks a type" "\0"
    " levels deep" "\0"
    " more diagnostic(s)" "\0"
    " needs " "\0"
    " needs object + offset on stack at pc=" "\0"
    " nested levels)" "\0"
    " nested more than " "\0"
    " not in [" "\0"
    " not in the module type table" "\0"
    " not supported at pc=" "\0"
    " of " "\0"
    " of `" "\0"
    " offset" "\0"
    " offset " "\0"
    " on " "\0"
    " out of bounds (len=" "\0"
    " out of range (struct has " "\0"
    " out of range at pc=" "\0"
    " p" "\0"
    " param(s)" "\0"
    " param(s) but call site supplied " "\0"
    " parameter(s) at " "\0"
    " r = " "\0"
    " receiver" "\0"
    " required methods" "\0"
    " requires a wildcard arm" "\0"
    " slots=" "\0"
    " slots[" "\0"
    " steps (non-terminating @comptime?)" "\0"
    " tag absent */" "\0"
    " to " "\0"
    " to a slot of type " "\0"
    " type=" "\0"
    " unresolved" "\0"
    " value, which cannot yet be baked into a comptime constant" "\0"
    " {\n" "\0"
    " { " "\0"
    " { const char* c0 = vader_string_to_cstr(a0); void* r = vader_ffi_open(c0); vader_cstr_free_for(a0, c0); return (size_t) (uintptr_t) r; }" "\0"
    " { const char* c1 = vader_string_to_cstr(a1); void* r = vader_ffi_symbol((void*) (uintptr_t) a0, c1); vader_cstr_free_for(a1, c1); return (size_t) (uintptr_t) r; }" "\0"
    " { return (int32_t) vader_gc_get_stats().bytes_used; }" "\0"
    " { return (int32_t) vader_gc_get_stats().total_collections; }" "\0"
    " { return (int32_t) vader_gc_get_stats().total_copied; }" "\0"
    " { return (void*) vader_string_bytes_view(a0, " "\0"
    " { return vader_clock_monotonic_ns(); }" "\0"
    " { return vader_clock_realtime_ms(); }" "\0"
    " { return vader_current_arch(); }" "\0"
    " { return vader_current_executable_location(); }" "\0"
    " { return vader_current_os(); }" "\0"
    " { return vader_current_working_directory(); }" "\0"
    " { return vader_exists(a0); }" "\0"
    " { return vader_get_env(a0, " "\0"
    " { return vader_is_dir(a0); }" "\0"
    " { return vader_is_tty(a0); }" "\0"
    " { return vader_math_ceil(a0); }" "\0"
    " { return vader_math_cos(a0); }" "\0"
    " { return vader_math_floor(a0); }" "\0"
    " { return vader_math_pow(a0, a1); }" "\0"
    " { return vader_math_round(a0); }" "\0"
    " { return vader_math_sin(a0); }" "\0"
    " { return vader_math_sqrt(a0); }" "\0"
    " { return vader_math_tan(a0); }" "\0"
    " { return vader_poll_stdin(a0); }" "\0"
    " { return vader_sched_now(); }" "\0"
    " { return vader_sched_park(); }" "\0"
    " { return vader_spawn_poll(a0); }" "\0"
    " { return vader_spawn_start((vader_array_t*) a0); }" "\0"
    " { return vader_spawn_take_stderr(a0); }" "\0"
    " { return vader_spawn_take_stdout(a0); }" "\0"
    " { return vader_string_as_string((vader_array_t*) a0); }" "\0"
    " { return vader_string_byte_at(a0, a1); }" "\0"
    " { return vader_string_byte_len(a0); }" "\0"
    " { return vader_string_codepoint_at(a0, a1); }" "\0"
    " { return vader_string_hash(a0); }" "\0"
    " { return vader_temp_dir(); }" "\0"
    " { return vader_terminal_columns(); }" "\0"
    " { return vader_terminal_raw_begin(); }" "\0"
    " { return vader_terminal_read_keys(a0); }" "\0"
    " { vader_gc_collect(); }" "\0"
    " { vader_panic(a0); }" "\0"
    " { vader_sched_arm(a0); }" "\0"
    " { vader_set_stdin_unbuffered(); }" "\0"
    " { vader_slice_t s1 = vader_array_bytes((vader_array_t*) a1); return vader_ffi_call_f64((void*) (uintptr_t) a0, (const int64_t*) s1.ptr, a2); }" "\0"
    " { vader_slice_t s1 = vader_array_bytes((vader_array_t*) a1); return vader_ffi_call_int((void*) (uintptr_t) a0, (const int64_t*) s1.ptr, a2); }" "\0"
    " { vader_slice_t s1 = vader_array_bytes((vader_array_t*) a1); return vader_ffi_call_int_bytes((void*) (uintptr_t) a0, (const int64_t*) s1.ptr, a2, a3, a4); }" "\0"
    " { vader_slice_t s1 = vader_array_bytes((vader_array_t*) a1); vader_ffi_call_void((void*) (uintptr_t) a0, (const int64_t*) s1.ptr, a2); }" "\0"
    " { vader_spawn_kill(a0); }" "\0"
    " { vader_terminal_raw_end(); }" "\0"
    " { vader_trap(\"bytes: no u8 type\"); }" "\0"
    " { vader_trap(\"bytes: no u8[] type\"); }" "\0"
    " { vader_trap(\"io intrinsic: IOError struct absent from type table\"); }" "\0"
    " { vader_trap(\"read_dir: no [string] type\"); }" "\0"
    " { vader_trap(\"read_dir: no string type\"); }" "\0"
    " { vader_trap(\"read_file_bytes: no u8 type\"); }" "\0"
    " { vader_trap(\"read_file_bytes: no u8[] type\"); }" "\0"
    " { vader_trap(\"unbound import: " "\0"
    " | " "\0"
    " || " "\0"
    " }" "\0"
    " }\n" "\0"
    " }\n};\n" "\0"
    " } }" "\0"
    " }).__vb)" "\0"
    " }).__vu)" "\0"
    " },\n" "\0"
    " };\n" "\0"
    " \xe2\x80\x94 @comptime evaluation must be reproducible" "\0"
    " \xe2\x80\x94 `" "\0"
    " \xe2\x80\x94 `@target` groups are keyed by name alone, so a name cannot carry two overloads" "\0"
    " \xe2\x80\x94 annotate `" "\0"
    " \xe2\x80\x94 annotate the return of `" "\0"
    " \xe2\x80\x94 its elements come from `" "\0"
    " \xe2\x80\x94 neither type nor trait is owned by this module" "\0"
    " \xe2\x80\x94 qualify it with a namespace import (`Ns :: import \"\xe2\x80\xa6\"` then `Ns." "\0"
    " \xe2\x86\x92 " "\0"
    "!" "\0"
    "!=" "\0"
    "!`" "\0"
    "!` at " "\0"
    "\"" "\0"
    "\"\n\n" "\0"
    "\"\"\"" "\0"
    "\");" "\0"
    "\");\n" "\0"
    "\"); }" "\0"
    "\"` (a module's folder must match its declared name)" "\0"
    "#" "\0"
    "#define VADER_COMPTIME_ATOM_COUNT " "\0"
    "#define VADER_COMPTIME_ATOM_COUNT 0u\n" "\0"
    "#include " "\0"
    "#include \"" "\0"
    "#include \"vader.h\"\n" "\0"
    "#include \"vader.h\"\n\n" "\0"
    "#include <stddef.h>\n" "\0"
    "#include <stdlib.h>\n" "\0"
    "#include <string.h>\n" "\0"
    "#line " "\0"
    "$" "\0"
    "$Add$add" "\0"
    "$Cell<" "\0"
    "$Cell_" "\0"
    "$Display$to_string" "\0"
    "$Div$div" "\0"
    "$Equals$equals" "\0"
    "$Equals$not_equals" "\0"
    "$Mul$mul" "\0"
    "$Sub$sub" "\0"
    "$[]$" "\0"
    "$main" "\0"
    "${" "\0"
    "%" "\0"
    "%=" "\0"
    "&" "\0"
    "&&" "\0"
    "&l" "\0"
    "&p" "\0"
    "&vader_data_" "\0"
    "'" "\0"
    "' (id=" "\0"
    "' : impl '" "\0"
    "' : no impl for type " "\0"
    "' : receiver tag " "\0"
    "' at pc=" "\0"
    "' declares " "\0"
    "' during defer drain" "\0"
    "' expects " "\0"
    "' must take exactly one env param at pc=" "\0"
    "' needs " "\0"
    "' \xe2\x80\x94 a method reference on a primitive isn't a first-class value ; call it directly or wrap it in a lambda" "\0"
    "' \xe2\x80\x94 field-set target isn't a real struct member ; upstream lowering bug" "\0"
    "' \xe2\x80\x94 impl-member/for-in materialisation gap (GATE B1)" "\0"
    "' \xe2\x80\x94 no dedicated Op ; add a case to intrinsic_op_for_name" "\0"
    "'\\u" "\0"
    "(" "\0"
    "((" "\0"
    "(((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(" "\0"
    "(((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(" "\0"
    "((double) " "\0"
    "((float) " "\0"
    "((int16_t) " "\0"
    "((int32_t) " "\0"
    "((int64_t) " "\0"
    "((int8_t) " "\0"
    "((ptrdiff_t) " "\0"
    "((size_t) " "\0"
    "((uint16_t) " "\0"
    "((uint32_t) " "\0"
    "((uint64_t) " "\0"
    "((uint8_t) " "\0"
    "((vader_array_t*) " "\0"
    "((vader_fn_erased_sig_" "\0"
    "((vader_obj_header_t*) " "\0"
    "((void) 0)" "\0"
    "((void*) (intptr_t) " "\0"
    "((void**) " "\0"
    "()" "\0"
    "(-__builtin_inf())" "\0"
    "(...)`" "\0"
    "(double)" "\0"
    "(int32_t)" "\0"
    "(int32_t)(((union { float __vf; uint32_t __vb; }){ .__vf = " "\0"
    "(int64_t)" "\0"
    "(int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = " "\0"
    "(none)" "\0"
    "(struct " "\0"
    "(uint8_t)" "\0"
    "(vader_array_t*) &" "\0"
    "(vader_buffer_t*) " "\0"
    "(void*) " "\0"
    "(void*) &" "\0"
    "(void*) s" "\0"
    ")" "\0"
    ") " "\0"
    ") (" "\0"
    ") -> " "\0"
    ") UINT64_C(" "\0"
    ") at function '" "\0"
    ") at pc=" "\0"
    ") does not fit in `" "\0"
    ") exceeds " "\0"
    ") exceeds object byte length " "\0"
    ") goto " "\0"
    ") in '" "\0"
    ") {" "\0"
    ") {\n" "\0"
    ") }).__vd)" "\0"
    ") }).__vf)" "\0"
    ") \xe2\x80\x94 a value escaped a scope boundary ; coalesce.vader's live-range invariant is violated" "\0"
    ") \xe2\x80\x94 fn-as-value materialisation gap (GATE B1)" "\0"
    ") \xe2\x80\x94 make-closure materialisation gap (GATE B1)" "\0"
    "));" "\0"
    "), " "\0"
    ")->" "\0"
    ")->f_" "\0"
    ")->type_index" "\0"
    ");" "\0"
    ");\n" "\0"
    "); }" "\0"
    ")`" "\0"
    "*" "\0"
    "* " "\0"
    "* e = (" "\0"
    "*) " "\0"
    "*) &" "\0"
    "*) vader_gc_alloc(sizeof(" "\0"
    "*=" "\0"
    "+" "\0"
    "+=" "\0"
    "+env>" "\0"
    "," "\0"
    ", " "\0"
    ", (int64_t) (intptr_t) r);" "\0"
    ", (size_t) " "\0"
    ", (vader_array_t*) " "\0"
    ", ." "\0"
    ", ... " "\0"
    ", NULL };\n" "\0"
    ", c" "\0"
    ", f_" "\0"
    ", found " "\0"
    ", got " "\0"
    ", have=" "\0"
    ", not a function" "\0"
    ", vader_box_t a" "\0"
    ", which the VM cannot pass yet (it works natively)" "\0"
    "-" "\0"
    "-(" "\0"
    "-0.0" "\0"
    "-=" "\0"
    "->" "\0"
    "->buf != NULL && " "\0"
    "->buf = vader_array_buf_forward(" "\0"
    "->buf);" "\0"
    "->buf); }" "\0"
    "->buf)[" "\0"
    "->buf, " "\0"
    "->buf->header.forward != NULL) { " "\0"
    "->buf->slots)[" "\0"
    "->code = (void*) &vader_fn_lift_" "\0"
    "->code)(" "\0"
    "->env" "\0"
    "->env = " "\0"
    "->env, " "\0"
    "->f_" "\0"
    "->length) { vader_trap(\"array index out of bounds\"); }" "\0"
    "->length;" "\0"
    "->offset + " "\0"
    "->offset + (size_t) " "\0"
    "-entry table" "\0"
    "-inf" "\0"
    "." "\0"
    "..." "\0"
    "../" "\0"
    "..<" "\0"
    "..=" "\0"
    "./" "\0"
    ".0" "\0"
    ".c" "\0"
    ".imports.h" "\0"
    ".payload.b" "\0"
    ".payload.f)" "\0"
    ".payload.i)" "\0"
    ".payload.i;" "\0"
    ".payload.obj" "\0"
    ".payload.obj]" "\0"
    ".payload.s" "\0"
    ".ptr" "\0"
    ".split.g.c" "\0"
    ".split.h" "\0"
    ".tag" "\0"
    ".tag == VADER_BOX_TAG_NULL) ? NULL : (void*) (intptr_t) a" "\0"
    ".vader" "\0"
    "/" "\0"
    "/* Compile-time atom table \xe2\x80\x94 see docs/ATOM_INTERNING.md. */\n" "\0"
    "/* Comptime data pool \xe2\x80\x94 read-only arrays in `.rodata`.\n" "\0"
    "/* Generated by vader \xe2\x80\x94 do not edit. Foreign imports. */\n" "\0"
    "/* Generated by vader \xe2\x80\x94 do not edit. Shared declarations. */\n" "\0"
    "// Generated per build by `vader/target/baked` \xe2\x80\x94 never on disk, never edited." "\0"
    "// Headers named by `@c_header` \xe2\x80\x94 they own the prototypes below.\n" "\0"
    "// The compilation target, baked. See `std/target::current_os` for the OTHER" "\0"
    "// User @extern foreign symbols \xe2\x80\x94 resolved by the linker.\n" "\0"
    "// question: the platform this program is RUNNING on." "\0"
    "/// The architecture this build is FOR. Parameterises values; selects nothing." "\0"
    "/// The operating system this build is FOR. Selects code through `@target`." "\0"
    "/=" "\0"
    "0" "\0"
    "0." "\0"
    "0.0" "\0"
    "0u /* " "\0"
    "1" "\0"
    "1-tuple types are not allowed" "\0"
    "2" "\0"
    "3" "\0"
    "31" "\0"
    "33" "\0"
    "4" "\0"
    "5" "\0"
    "6" "\0"
    "7" "\0"
    "8" "\0"
    "9" "\0"
    ":" "\0"
    ": " "\0"
    ": ;" "\0"
    ": <type>!` instead" "\0"
    ": T[]!: \xe2\x80\xa6`)" "\0"
    ": a `f32` result is not covered" "\0"
    ": a lent array with a floating result is not covered" "\0"
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
    ": expected numeric operand, got " "\0"
    ": expected object, got " "\0"
    ": expected string, got " "\0"
    ": expected struct, got " "\0"
    ": more than 8 arguments" "\0"
    ": nargs " "\0"
    ": negative slot" "\0"
    ": only a byte array can be lent on the VM, element " "\0"
    ": only one array can be lent per call" "\0"
    ": symbol not found" "\0"
    ": {" "\0"
    "::" "\0"
    "::into::" "\0"
    ":=" "\0"
    ";" "\0"
    ";\n" "\0"
    "; return;\n" "\0"
    "; vader_gc_top = gc_frame.prev; return __vret; }" "\0"
    "<" "\0"
    "<<" "\0"
    "<=" "\0"
    "<baked>/std/target/baked" "\0"
    "<baked>/std/target/baked/baked.vader" "\0"
    "<builtin>" "\0"
    "<callee>" "\0"
    "<clone>:" "\0"
    "<error: " "\0"
    "<fn " "\0"
    "<materialized>" "\0"
    "<obj#" "\0"
    "<synthetic>" "\0"
    "<type " "\0"
    "<unknown>" "\0"
    "<vader-vm>" "\0"
    "=" "\0"
    "==" "\0"
    "=>" "\0"
    ">" "\0"
    ">=" "\0"
    ">>" "\0"
    ">` \xe2\x80\x94 source and target must differ" "\0"
    "?" "\0"
    "??" "\0"
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
    "Add" "\0"
    "Any" "\0"
    "Arm64" "\0"
    "Array<" "\0"
    "ArrayIterator" "\0"
    "ArrayTypeExpr" "\0"
    "Async" "\0"
    "AwaitExpr" "\0"
    "BinaryExpr" "\0"
    "BinaryOp.In" "\0"
    "BinaryOp.Is" "\0"
    "BinaryOp.NotIn" "\0"
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
    "Contains" "\0"
    "Darwin" "\0"
    "Display" "\0"
    "Div" "\0"
    "DotVariantExpr" "\0"
    "E:" "\0"
    "ENV access requires `--allow-env`" "\0"
    "Equals" "\0"
    "Error" "\0"
    "Expr" "\0"
    "F:(" "\0"
    "F<" "\0"
    "FC" "\0"
    "FF" "\0"
    "FI" "\0"
    "Fc:" "\0"
    "Ff:" "\0"
    "Fi:" "\0"
    "Field" "\0"
    "FieldExpr" "\0"
    "FloatLitExpr" "\0"
    "Fn(" "\0"
    "FnTypeExpr" "\0"
    "GenericInstExpr" "\0"
    "Hash" "\0"
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
    "Range" "\0"
    "RangeExpr" "\0"
    "Rem" "\0"
    "S" "\0"
    "S:" "\0"
    "Self" "\0"
    "SeqLitExpr" "\0"
    "Sf:" "\0"
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
    "T:" "\0"
    "T<" "\0"
    "Trait#" "\0"
    "Tup" "\0"
    "Tuple<" "\0"
    "U:(" "\0"
    "U<" "\0"
    "UnaryExpr" "\0"
    "Union<" "\0"
    "Ur:" "\0"
    "VADER_HOME" "\0"
    "VADER_WRITE_BARRIER(" "\0"
    "VADER_WRITE_BARRIER((" "\0"
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
    "Wasi" "\0"
    "Wasm32" "\0"
    "Windows" "\0"
    "X86_64" "\0"
    "X:" "\0"
    "Y:" "\0"
    "Yield" "\0"
    "[" "\0"
    "[]" "\0"
    "[]::" "\0"
    "]" "\0"
    "] " "\0"
    "] = " "\0"
    "] = (" "\0"
    "] = {\n" "\0"
    "] = { " "\0"
    "] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_" "\0"
    "] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_" "\0"
    "] = { VADER_TYPE_KIND_STRUCT, sizeof(" "\0"
    "] for `" "\0"
    "] },\n" "\0"
    "];" "\0"
    "]; } " "\0"
    "]; } vader_data_" "\0"
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
    "_Thread_local" "\0"
    "__" "\0"
    "__Any" "\0"
    "__Tuple" "\0"
    "__Tuple_" "\0"
    "__args" "\0"
    "__async_" "\0"
    "__asyncstate_" "\0"
    "__builtin_inf()" "\0"
    "__builtin_nan(\"\")" "\0"
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
    "_a" "\0"
    "_arr" "\0"
    "_buf" "\0"
    "_buf = {\n" "\0"
    "_buf };\n" "\0"
    "_e" "\0"
    "_f" "\0"
    "_glue" "\0"
    "_ptrs" "\0"
    "_ptrs, 1, 0, NULL, 0, NULL },\n" "\0"
    "_ptrs[] = { " "\0"
    "_ptrs[] = { offsetof(vader_array_t, buf) };\n" "\0"
    "_ptrs[] = { offsetof(vader_fn_t, env) };\n" "\0"
    "_refs" "\0"
    "_refs[] = { " "\0"
    "_root" "\0"
    "_strs" "\0"
    "_strs[] = { " "\0"
    "_t" "\0"
    "_t) " "\0"
    "_t)(" "\0"
    "_v" "\0"
    "_vt" "\0"
    "_write" "\0"
    "_x" "\0"
    "`" "\0"
    "` " "\0"
    "` (required by type parameter `" "\0"
    "` : annotate that element type at " "\0"
    "` after prune_unused_types \xe2\x80\x94 the table is final by then, so the slot would survive as an orphan `ref` and panic at the first field access. Look the type up and skip the entry instead, as `build_impl_table_from_vtable` does." "\0"
    "` against non-enum context type" "\0"
    "` against unresolved type" "\0"
    "` already declared in a sibling file of this module" "\0"
    "` already declared in this module" "\0"
    "` already has a body for `." "\0"
    "` already implements `" "\0"
    "` already provided in this struct literal" "\0"
    "` and no general body ; " "\0"
    "` arg " "\0"
    "` at " "\0"
    "` at pc=" "\0"
    "` byte" "\0"
    "` cannot be inferred" "\0"
    "` cannot decorate a parameter \xe2\x80\x94 only `@c_pointer` can" "\0"
    "` cannot have a body \xe2\x80\x94 drop the `= ...` / `{ ... }`" "\0"
    "` declared here, but `" "\0"
    "` does not apply to a struct field ; only `@internal` does" "\0"
    "` does not fit in u64" "\0"
    "` does not implement `" "\0"
    "` expects an enum-typed slot, got " "\0"
    "` for " "\0"
    "` from `" "\0"
    "` has " "\0"
    "` has no bare `@target` declaration in this module" "\0"
    "` has no body for `" "\0"
    "` has no field named `" "\0"
    "` has no interior to mutate \xe2\x80\x94 drop the `!`" "\0"
    "` has the same signature as an imported function of the same name" "\0"
    "` here \xe2\x80\x94 the body binds by POSITION, so a reordered name silently " "\0"
    "` imports `" "\0"
    "` in '" "\0"
    "` in a " "\0"
    "` instead of a label" "\0"
    "` is `" "\0"
    "` is `@internal` to module `" "\0"
    "` is a " "\0"
    "` is a body ; the bare `@target` declaration carries `export`" "\0"
    "` is already a type parameter" "\0"
    "` is already declared at " "\0"
    "` is already defined with the same signature in this module" "\0"
    "` is bodyless and otherwise unbound at runtime ; for a function-*type*, spell the `fn(...)` type inline at its use sites rather than as a named bodyless declaration" "\0"
    "` is declared `" "\0"
    "` is declared with `::` \xe2\x80\x94 use `:=` to allow mutation" "\0"
    "` is exported by " "\0"
    "` is frozen by the module-const default at " "\0"
    "` is never a value of `" "\0"
    "` is never used" "\0"
    "` is no longer supported \xe2\x80\x94 the literal coerces from context" "\0"
    "` is not a struct" "\0"
    "` is not a type" "\0"
    "` is not a variant of " "\0"
    "` is not allowed in expression position" "\0"
    "` is not an enclosing loop's iteration variable or label" "\0"
    "` is not wired into intrinsic_manifest \xe2\x80\x94 add it to `intrinsic_id_for` (+ its `vm/host.vader::dispatch_import` and `c_emit/host.vader::import_shim` arms), or give it a dedicated op in `intrinsic_op_for_mangled`" "\0"
    "` is reached through an immutable path" "\0"
    "` is read-only, but this slot is declared `" "\0"
    "` is shipped under the library root, so it cannot import `" "\0"
    "` lends out read-only \xe2\x80\x94 drop the `!`, or mark the slot's parameter `!` to allow it" "\0"
    "` lists `." "\0"
    "` may" "\0"
    "` must be prefixed with `$`" "\0"
    "` must be written `$" "\0"
    "` must precede a `match` expression" "\0"
    "` mutates a parameter that `" "\0"
    "` mutates its receiver (declared `self!`), but this receiver is immutable" "\0"
    "` names no operating system" "\0"
    "` not defined for " "\0"
    "` not found" "\0"
    "` of `" "\0"
    "` on " "\0"
    "` on `" "\0"
    "` on non-struct type " "\0"
    "` or make `" "\0"
    "` overload accepts a receiver of type `" "\0"
    "` private" "\0"
    "` requires method `" "\0"
    "` takes " "\0"
    "` twice in the same `@target`" "\0"
    "` values are not ordered (no Comparable impl); only == and != are valid at comptime" "\0"
    "` was already supplied" "\0"
    "` was declared earlier in this folder" "\0"
    "` without context" "\0"
    "` would write the same file" "\0"
    "` yields but returns " "\0"
    "` \xe2\x80\x94 already declared on `" "\0"
    "` \xe2\x80\x94 annotate the result slot, or pass the type argument explicitly" "\0"
    "` \xe2\x80\x94 enumerate its variants or mark the match `@partial`" "\0"
    "` \xe2\x80\x94 its folder declares `module \"" "\0"
    "` \xe2\x80\x94 narrow the union with `if`/`match` first (a value combinator handles a single unhappy variant, `T | null` or `T | Error`, not both)" "\0"
    "` \xe2\x80\x94 not provided in this impl block" "\0"
    "` \xe2\x80\x94 only `" "\0"
    "` \xe2\x80\x94 only an ARRAY of value elements can be a mutable " "\0"
    "` \xe2\x80\x94 only one impl per (type, trait) is allowed" "\0"
    "` \xe2\x80\x94 the marker belongs on the ARRAY level only : its " "\0"
    "` \xe2\x80\x94 the marker belongs on the ARRAY level, which is the " "\0"
    "` \xe2\x80\x94 write `" "\0"
    "`!` already applies to this type level" "\0"
    "`!` belongs on the type, not the parameter name" "\0"
    "`!` requires bool" "\0"
    "`&&` / `||` require `bool` operands, got " "\0"
    "`(` after `@" "\0"
    "`(` after `fn` in function type" "\0"
    "`(` after function name" "\0"
    "`(` after generic argument list" "\0"
    "`)" "\0"
    "`) or destructure the one you mean" "\0"
    "`)` after decorator arguments" "\0"
    "`)` after enum backing type" "\0"
    "`)` after function parameter types" "\0"
    "`)` to close `@" "\0"
    "`)` to close argument list" "\0"
    "`)` to close parameter list" "\0"
    "`)` to close parenthesised expression" "\0"
    "`)` to close parenthesised type" "\0"
    "`)` to close type parameter list" "\0"
    "`, closing an import cycle" "\0"
    "`, which is not exported from its module ; export `" "\0"
    "`->` between lambda params and body" "\0"
    "`->` between pattern and arm body" "\0"
    "`->` to introduce a SAM impl body" "\0"
    "`-` requires numeric" "\0"
    "`." "\0"
    "`.` before struct literal field name" "\0"
    "`: " "\0"
    "`: type` bound is redundant; write `$T` instead" "\0"
    "`:=`, `::`, or `:` after destructure pattern" "\0"
    "`:` after field name" "\0"
    "`:` between type annotation and value" "\0"
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
    "`@c_pointer` only means something on an `@extern` declaration" "\0"
    "`@c_pointer` takes no argument \xe2\x80\x94 the `!` on the type says whether C writes" "\0"
    "`@comptime for` binding not resolved" "\0"
    "`@comptime for` cannot be unrolled" "\0"
    "`@comptime for` does not support `[k, v]` destructure" "\0"
    "`@comptime for` exceeds the unroll cap (256)" "\0"
    "`@comptime for` requires a compile-time-known array literal" "\0"
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
    "`]` to close index" "\0"
    "`]` to close seq literal" "\0"
    "`]` to close tuple pattern" "\0"
    "`as` binding not allowed after `!is`: the binding would have no live then-branch since the type-check is negated" "\0"
    "`as` binding not allowed in a `&&` condition" "\0"
    "`await` in a short-circuit operand or loop condition is not yet supported" "\0"
    "`await` is not allowed inside a nested lambda (a lambda cannot be an async coroutine)" "\0"
    "`break` / `continue` only allowed inside a loop" "\0"
    "`break` / `continue` target must be an enclosing loop's iteration variable or label" "\0"
    "`const` was removed from the language" "\0"
    "`defer` is not yet supported inside a generator" "\0"
    "`for x in iter` requires an Iterator impl on " "\0"
    "`implements` keyword" "\0"
    "`in` / `not in` lowering deferred" "\0"
    "`in` after for-loop binding" "\0"
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
    "`~` requires int" "\0"
    "a" "\0"
    "a `!` that grants nothing" "\0"
    "a `@target` selector must be an operating-system variant, " "\0"
    "a bodyless function must be `@intrinsic` (host-provided) or `@extern` (foreign symbol)" "\0"
    "a constant \xe2\x80\x94 use `VADER_OS`, which is a value" "\0"
    "a cyclic or non-terminating comptime expression (exceeded " "\0"
    "a function that `yield`s must return `Iterator<T>`" "\0"
    "a generator produces values via `yield`; `return` with a value is not allowed (use a bare `return` to stop)" "\0"
    "a mutable module const needs a flat element type" "\0"
    "a plain name in an `import \"p\" { \xe2\x80\xa6 }` modifier list \xe2\x80\x94 use `x as _` (exclude) or `x as y` (rename)" "\0"
    "a read-only value cannot fill a slot that promises mutation" "\0"
    "a shipped library must not import the compiler" "\0"
    "a struct" "\0"
    "a trait" "\0"
    "a union mixes the same type at two mutabilities" "\0"
    "a written type is read-only by default \xe2\x80\x94 drop `const`, and write `!` where mutation is needed" "\0"
    "a:<" "\0"
    "ac(" "\0"
    "acc" "\0"
    "access to a struct field marked `@internal` from outside its declaring module" "\0"
    "add" "\0"
    "alias" "\0"
    "alias after `as`" "\0"
    "align_of" "\0"
    "align_of: argument is not a type" "\0"
    "all" "\0"
    "allow_unused" "\0"
    "am(" "\0"
    "ambiguous overload resolution" "\0"
    "amp" "\0"
    "an `as` binding cannot appear in a `&&` condition ; narrow the variable in place (`if x is T && \xe2\x80\xa6`) or nest the checks (`if x is T as a { if \xe2\x80\xa6 }`)" "\0"
    "an `implements` block" "\0"
    "an `is` test compares the shape \xe2\x80\x94 mutability has no runtime representation, " "\0"
    "an enum" "\0"
    "an impl member" "\0"
    "and" "\0"
    "and_and" "\0"
    "and_res" "\0"
    "any" "\0"
    "arg" "\0"
    "argument for `" "\0"
    "arm64" "\0"
    "arr" "\0"
    "arr_blanket::" "\0"
    "array" "\0"
    "array index must be an integer, got " "\0"
    "array.clear" "\0"
    "array.clear on empty stack at pc=" "\0"
    "array.clear receiver" "\0"
    "array.copy" "\0"
    "array.copy destination range out of bounds (dst must already be long enough) at pc=" "\0"
    "array.copy dst" "\0"
    "array.copy dst_start" "\0"
    "array.copy len" "\0"
    "array.copy needs src + src_start + dst + dst_start + len on stack at pc=" "\0"
    "array.copy source range out of bounds at pc=" "\0"
    "array.copy src" "\0"
    "array.copy src_start" "\0"
    "array.get index" "\0"
    "array.get index " "\0"
    "array.get needs array + index on stack at pc=" "\0"
    "array.get receiver" "\0"
    "array.len on empty stack at pc=" "\0"
    "array.len receiver" "\0"
    "array.new length " "\0"
    "array.new type " "\0"
    "array.push needs array + value on stack at pc=" "\0"
    "array.push receiver" "\0"
    "array.push_all" "\0"
    "array.push_all needs dst + src on stack at pc=" "\0"
    "array.push_all receiver" "\0"
    "array.push_all source" "\0"
    "array.remove_last" "\0"
    "array.remove_last on empty stack at pc=" "\0"
    "array.remove_last receiver" "\0"
    "array.repeat" "\0"
    "array.repeat count" "\0"
    "array.repeat needs array + count on stack at pc=" "\0"
    "array.repeat receiver" "\0"
    "array.set index" "\0"
    "array.set index " "\0"
    "array.set needs array + index + value on stack at pc=" "\0"
    "array.set receiver" "\0"
    "array.slice hi" "\0"
    "array.slice lo" "\0"
    "array.slice needs array + lo + hi on stack at pc=" "\0"
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
    "auto" "\0"
    "await" "\0"
    "await outside an async coroutine" "\0"
    "awaited" "\0"
    "bang" "\0"
    "binary op not allowed in type position" "\0"
    "binding" "\0"
    "binding name after `as`" "\0"
    "binding name in destructure pattern" "\0"
    "bitand" "\0"
    "bitor" "\0"
    "bits_to_f32" "\0"
    "bits_to_f32 needs a value on the stack at pc=" "\0"
    "bits_to_f64" "\0"
    "bits_to_f64 needs a value on the stack at pc=" "\0"
    "bitxor" "\0"
    "block" "\0"
    "bool" "\0"
    "bool.and" "\0"
    "bool.eq" "\0"
    "bool.ne" "\0"
    "bool.not" "\0"
    "bool.not on empty stack at pc=" "\0"
    "bool.or" "\0"
    "bootstrap: cannot write `" "\0"
    "boundimpl::" "\0"
    "br (pc " "\0"
    "br has no jump target at pc=" "\0"
    "br_if (pc " "\0"
    "br_if has no jump target at pc=" "\0"
    "br_if on empty stack at pc=" "\0"
    "break" "\0"
    "breakpoint" "\0"
    "browser" "\0"
    "buf" "\0"
    "buffer.new needs size on stack at pc=" "\0"
    "buffer.new size" "\0"
    "buffer.new size " "\0"
    "buffer_to_string" "\0"
    "buffer_to_string len" "\0"
    "buffer_to_string needs object + len on stack at pc=" "\0"
    "buffer_to_string receiver" "\0"
    "buffer_write_string needs object + off + string on stack at pc=" "\0"
    "buffer_write_string negative offset at pc=" "\0"
    "buffer_write_string off" "\0"
    "buffer_write_string range [" "\0"
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
    "byte" "\0"
    "byte index out of bounds" "\0"
    "byte_at" "\0"
    "byte_at index" "\0"
    "byte_at receiver" "\0"
    "byte_len" "\0"
    "bytecode emit: bodyless `@intrinsic` host `" "\0"
    "bytecode/emit_ctx: intern_type would mint `" "\0"
    "bytes" "\0"
    "bytes receiver" "\0"
    "bytes_to_string byte" "\0"
    "bytes_to_string receiver" "\0"
    "c" "\0"
    "c_emit: baked struct symbol_id " "\0"
    "c_emit: operand stack not empty at " "\0"
    "c_header" "\0"
    "c_pointer" "\0"
    "call" "\0"
    "call stack overflow (depth > " "\0"
    "call to '" "\0"
    "call.import " "\0"
    "call.import '" "\0"
    "call.indirect" "\0"
    "call.indirect arity mismatch at pc=" "\0"
    "call.indirect needs " "\0"
    "call.indirect on non-fn type " "\0"
    "call.indirect receiver" "\0"
    "call.indirect type " "\0"
    "call_ind" "\0"
    "callee has type " "\0"
    "cancel" "\0"
    "cannot assign a value of type " "\0"
    "cannot cast " "\0"
    "cannot destructure a value of type " "\0"
    "cannot infer enum type for `." "\0"
    "cannot infer enum type from context" "\0"
    "cannot infer type argument \xe2\x80\x94 nothing at this call site binds the type parameter" "\0"
    "cannot mutate `" "\0"
    "cannot mutate an immutable array" "\0"
    "cannot mutate through an immutable access path" "\0"
    "cannot reassign a constant binding" "\0"
    "cap_" "\0"
    "caret" "\0"
    "case" "\0"
    "cast" "\0"
    "ceil" "\0"
    "cell" "\0"
    "cell_get" "\0"
    "chained `" "\0"
    "chained `!in`" "\0"
    "chained `!is`" "\0"
    "char" "\0"
    "char_literal" "\0"
    "character literal (codepoint " "\0"
    "character literal cannot be empty" "\0"
    "character literal must contain exactly one codepoint" "\0"
    "character literal's codepoint does not fit the target integer type" "\0"
    "chars" "\0"
    "clear" "\0"
    "closure" "\0"
    "coalesce" "\0"
    "code after a divergent statement" "\0"
    "codepoint escape must have 1\xe2\x80\x93""6 hex digits" "\0"
    "codepoint exceeds U+10FFFF" "\0"
    "collect" "\0"
    "colon" "\0"
    "comma" "\0"
    "compare" "\0"
    "comparison operand kinds disagree" "\0"
    "comparison operator" "\0"
    "compile-time assertion failed" "\0"
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
    "const char vader_atom_blob[] =\n" "\0"
    "const char*" "\0"
    "const char* c" "\0"
    "const size_t vader_type_info_count = " "\0"
    "const size_t vader_type_size[" "\0"
    "const struct " "\0"
    "const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; " "\0"
    "const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[" "\0"
    "const uint16_t vader_type_" "\0"
    "const vader_array_t " "\0"
    "const vader_atom_entry_t vader_atom_comptime_table[1] = { { 0u, 0u, 0u, 0u, 0u, \"\" } };\n" "\0"
    "const vader_atom_entry_t vader_atom_comptime_table[] = {\n" "\0"
    "const vader_type_info_t vader_type_info_table[" "\0"
    "const void*" "\0"
    "const_init" "\0"
    "contains" "\0"
    "continue" "\0"
    "convert at pc=" "\0"
    "convert on empty stack at pc=" "\0"
    "copy_to" "\0"
    "cos" "\0"
    "count" "\0"
    "cp_slice" "\0"
    "create_dir" "\0"
    "cursor" "\0"
    "cyclic type alias" "\0"
    "d" "\0"
    "darwin" "\0"
    "data.const pool_index " "\0"
    "data_const" "\0"
    "decl_const" "\0"
    "decl_var" "\0"
    "declaration is never used in its module" "\0"
    "decorator arguments must be string literals at comptime" "\0"
    "decorator name after `@`" "\0"
    "decorator not allowed on this parameter" "\0"
    "decorator unknown to the compiler" "\0"
    "default" "\0"
    "defer" "\0"
    "defer thunk '" "\0"
    "defer.pop_exec" "\0"
    "defer.pop_exec entry" "\0"
    "defer.pop_exec underflow (count=" "\0"
    "defer.push on empty stack at pc=" "\0"
    "deprecated" "\0"
    "destructure of " "\0"
    "div" "\0"
    "do" "\0"
    "dollar" "\0"
    "dot" "\0"
    "dotdotdot" "\0"
    "double" "\0"
    "drop on empty stack at pc=" "\0"
    "duplicate `@extern` C symbol `" "\0"
    "duplicate bare `@target` declaration" "\0"
    "duplicate enum variant value" "\0"
    "duplicate field name in struct literal" "\0"
    "duplicate import binding" "\0"
    "duplicate non-fn declaration across files of the same module" "\0"
    "duplicate top-level symbol in module" "\0"
    "e" "\0"
    "e->f_msg = r.payload.s;" "\0"
    "ekeys" "\0"
    "elem" "\0"
    "elements are emitted as read-only statics, and keeping the element type " "\0"
    "else" "\0"
    "else has no jump target at pc=" "\0"
    "emit_branch: unresolved target at pc " "\0"
    "emit_end: no scope ends at pc " "\0"
    "empty `[]` is not a valid type" "\0"
    "empty input" "\0"
    "empty modifier list on an import \xe2\x80\x94 `import \"p\" {}` is just a wildcard, write `import \"p\"`" "\0"
    "end" "\0"
    "end of file" "\0"
    "end_" "\0"
    "entered unreachable code: " "\0"
    "entry file's folder declares no module" "\0"
    "enum" "\0"
    "enum backing type must be a primitive integer" "\0"
    "enum variant value out of range for backing type" "\0"
    "env" "\0"
    "eof" "\0"
    "eq" "\0"
    "equals" "\0"
    "error" "\0"
    "error value" "\0"
    "escape \\" "\0"
    "escape \\' is not valid in a string literal" "\0"
    "evals" "\0"
    "exec_fn_value: no function named '" "\0"
    "executable statement at top level (only declarations allowed)" "\0"
    "exists" "\0"
    "expected " "\0"
    "expected '{' after \\u" "\0"
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
    "expected member declaration `name :: fn(...)` (got " "\0"
    "expected parameter name (got " "\0"
    "expected token" "\0"
    "explicit `import \"std/core\"` is redundant (prelude already in scope)" "\0"
    "exponent has no digits" "\0"
    "export" "\0"
    "export VADER_ARCH: Arch: Arch." "\0"
    "export VADER_OS: Os: Os." "\0"
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
    "extern const size_t vader_type_size[];\n" "\0"
    "extern const vader_atom_entry_t vader_atom_comptime_table[];\n" "\0"
    "extern vader_fn_t vader_fn_static_" "\0"
    "extern: a `string` result is not covered on the VM" "\0"
    "f32" "\0"
    "f32_to_bits" "\0"
    "f32_to_bits needs a value on the stack at pc=" "\0"
    "f64" "\0"
    "f64.add" "\0"
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
    "f64_to_bits needs a value on the stack at pc=" "\0"
    "f:(" "\0"
    "false" "\0"
    "fat_arrow" "\0"
    "feature not yet implemented" "\0"
    "ffi_call arg " "\0"
    "ffi_call args" "\0"
    "ffi_call at pc=" "\0"
    "ffi_call fn" "\0"
    "ffi_call nargs" "\0"
    "ffi_call_int_bytes at pc=" "\0"
    "ffi_call_int_bytes byte" "\0"
    "ffi_call_int_bytes bytes" "\0"
    "ffi_call_int_bytes slot" "\0"
    "ffi_open name" "\0"
    "ffi_symbol lib" "\0"
    "ffi_symbol name" "\0"
    "field" "\0"
    "field `" "\0"
    "field already provided in struct literal" "\0"
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
    "files in the same folder declare different module names" "\0"
    "find" "\0"
    "finish_buffer" "\0"
    "float" "\0"
    "float_literal" "\0"
    "floor" "\0"
    "fn" "\0"
    "fn(" "\0"
    "fn.ref" "\0"
    "fn_ref" "\0"
    "fnobj" "\0"
    "for" "\0"
    "for-in needs std/core::Yield" "\0"
    "for-in receiver has no `Iterator` impl" "\0"
    "for_arr" "\0"
    "for_discard" "\0"
    "for_elem" "\0"
    "for_hi" "\0"
    "for_i" "\0"
    "for_len" "\0"
    "for_pat" "\0"
    "function body returns a value incompatible with its declared return type" "\0"
    "function defined more than once with the same signature in a module" "\0"
    "function is not callable in comptime context" "\0"
    "function reference" "\0"
    "function signature must be fully annotated" "\0"
    "fuse_arr" "\0"
    "fuse_i" "\0"
    "fuse_iter" "\0"
    "fuse_len" "\0"
    "fuse_step" "\0"
    "gc_raw_roots" "\0"
    "gc_roots" "\0"
    "gc_stack_objs" "\0"
    "gen_elem" "\0"
    "generator block-split: gb_compile_ctrl on a leaf stmt" "\0"
    "generator block-split: unresolved loop label in break/continue" "\0"
    "generator lowering: `Yield` core type not found" "\0"
    "generic argument count mismatch" "\0"
    "generic instance discovery did not converge" "\0"
    "generic-inst expression not lowered" "\0"
    "get_env name" "\0"
    "got " "\0"
    "goto" "\0"
    "goto " "\0"
    "gt" "\0"
    "gte" "\0"
    "hash" "\0"
    "hash receiver" "\0"
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
    "i32.div" "\0"
    "i32.div by zero at pc=" "\0"
    "i32.eq" "\0"
    "i32.ge" "\0"
    "i32.gt" "\0"
    "i32.le" "\0"
    "i32.lt" "\0"
    "i32.mod" "\0"
    "i32.mod by zero at pc=" "\0"
    "i32.mul" "\0"
    "i32.ne" "\0"
    "i32.neg" "\0"
    "i32.shl" "\0"
    "i32.shr" "\0"
    "i32.shru" "\0"
    "i32.sub" "\0"
    "i64" "\0"
    "i64.add" "\0"
    "i64.bitand" "\0"
    "i64.bitnot" "\0"
    "i64.bitor" "\0"
    "i64.bitxor" "\0"
    "i64.div" "\0"
    "i64.div by zero at pc=" "\0"
    "i64.eq" "\0"
    "i64.ge" "\0"
    "i64.gt" "\0"
    "i64.le" "\0"
    "i64.lt" "\0"
    "i64.mod" "\0"
    "i64.mul" "\0"
    "i64.ne" "\0"
    "i64.neg" "\0"
    "i64.rem by zero at pc=" "\0"
    "i64.shl" "\0"
    "i64.shr" "\0"
    "i64.shru" "\0"
    "i64.sub" "\0"
    "i8" "\0"
    "id" "\0"
    "ident" "\0"
    "idx" "\0"
    "if" "\0"
    "if (" "\0"
    "if ((size_t) " "\0"
    "if (r.tag == " "\0"
    "if condition must be `bool`, got " "\0"
    "if has no jump target at pc=" "\0"
    "if on empty stack at pc=" "\0"
    "if open" "\0"
    "if_res" "\0"
    "impl" "\0"
    "impl block missing required trait method" "\0"
    "implements" "\0"
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
    "includePaths" "\0"
    "inclusive" "\0"
    "incomplete escape sequence" "\0"
    "index past the end of a " "\0"
    "inf" "\0"
    "info" "\0"
    "inline" "\0"
    "inner" "\0"
    "inside string literal" "\0"
    "int" "\0"
    "int main(int argc, char** argv) {\n" "\0"
    "int main(int argc, char** argv) { (void)argc; (void)argv; return 0; }\n" "\0"
    "int16_t" "\0"
    "int32_t" "\0"
    "int64_t" "\0"
    "int8_t" "\0"
    "int_literal" "\0"
    "integer literal " "\0"
    "integer literal after `=`" "\0"
    "integer literal does not fit the target integer type" "\0"
    "integer literal exceeds the u64 range" "\0"
    "internal" "\0"
    "interp_close" "\0"
    "interp_open" "\0"
    "interpolation expression must follow `${`" "\0"
    "interpolation not allowed in import path" "\0"
    "into" "\0"
    "intrinsic" "\0"
    "intrinsic not implemented by the lowerer" "\0"
    "intrinsic size_of.type on empty stack at pc=" "\0"
    "intrinsic size_of.type: expected type value, got " "\0"
    "intrinsic size_of.type: type " "\0"
    "invalid Unicode codepoint escape" "\0"
    "invalid \\u escape" "\0"
    "invalid `@extern` declaration" "\0"
    "invalid `main` signature" "\0"
    "invalid cast" "\0"
    "invalid character literal" "\0"
    "invalid digit" "\0"
    "invalid escape sequence" "\0"
    "invalid hex digit in codepoint escape" "\0"
    "invalid module name (does not match `[a-z][a-z0-9_]*(/[a-z][a-z0-9_]*)*` grammar)" "\0"
    "invalid number" "\0"
    "is" "\0"
    "is impure and cannot run at comptime" "\0"
    "is_dir" "\0"
    "is_tty stream" "\0"
    "isize" "\0"
    "iter" "\0"
    "iter_ekeys" "\0"
    "iter_evals" "\0"
    "iter_pos" "\0"
    "iter_size" "\0"
    "iter_src" "\0"
    "its `@target` bodies cover " "\0"
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
    "let destructure requires at least 2 elements" "\0"
    "level the data pool can make writable" "\0"
    "lib" "\0"
    "linux" "\0"
    "load_f64" "\0"
    "load_i32" "\0"
    "load_i64" "\0"
    "load_slot index" "\0"
    "load_slot index " "\0"
    "load_slot needs array + index on stack at pc=" "\0"
    "load_slot receiver" "\0"
    "load_u8" "\0"
    "local" "\0"
    "local binding shadows an outer local or parameter of the same name" "\0"
    "local.field" "\0"
    "local.field slot " "\0"
    "local.get slot " "\0"
    "local.set on empty stack at pc=" "\0"
    "local.set slot " "\0"
    "local.tee on empty stack at pc=" "\0"
    "local.tee slot " "\0"
    "logical operator requires bool operands" "\0"
    "long" "\0"
    "loop" "\0"
    "loop_" "\0"
    "lower_string_lit: " "\0"
    "lparen" "\0"
    "lt" "\0"
    "lte" "\0"
    "m" "\0"
    "main" "\0"
    "main must return i32" "\0"
    "main takes either no parameters or a single `[string]` argument" "\0"
    "make_closure" "\0"
    "make_closure needs env on stack at pc=" "\0"
    "malformed numeric literal" "\0"
    "match" "\0"
    "match arm is unreachable after lowering" "\0"
    "match on non-union " "\0"
    "match-arm guard must be `bool`, got " "\0"
    "maximum nesting depth exceeded" "\0"
    "memory_copy dest range [" "\0"
    "memory_copy dst" "\0"
    "memory_copy dst_off" "\0"
    "memory_copy n" "\0"
    "memory_copy needs dst + dst_off + src + src_off + n on stack at pc=" "\0"
    "memory_copy negative length/offset at pc=" "\0"
    "memory_copy source range [" "\0"
    "memory_copy src" "\0"
    "memory_copy src_off" "\0"
    "method call lacks a resolvable `self` receiver" "\0"
    "midir/emit: no field `" "\0"
    "midir/emit: unhandled Instruction reached emit_instr \xe2\x80\x94 a variant has no emitter" "\0"
    "midir/emit: unhandled intrinsic `" "\0"
    "midir/emit: unresolved callee '" "\0"
    "midir/emit: unresolved closure fn '" "\0"
    "midir/emit: unresolved fn-ref '" "\0"
    "midir: coroutine marker (LoweredYield/LoweredAwait) reached build_stmt \xe2\x80\x94 lower_coroutine should have consumed it" "\0"
    "midir: lowered_to_bc_value reached a non-primitive leaf \xe2\x80\x94 is_bakeable/converter drift" "\0"
    "minus" "\0"
    "minus_assign" "\0"
    "missing function body" "\0"
    "missing newline between top-level declarations" "\0"
    "missing required " "\0"
    "missing required argument" "\0"
    "missing required argument `" "\0"
    "missing required field in struct literal" "\0"
    "missing terminator" "\0"
    "mod" "\0"
    "module" "\0"
    "module \"" "\0"
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
    "named argument duplicates a positional one" "\0"
    "nan" "\0"
    "narrow" "\0"
    "negative literal does not fit unsigned `" "\0"
    "neq" "\0"
    "never" "\0"
    "new_byte_buffer" "\0"
    "newline" "\0"
    "next" "\0"
    "no Iterator impl on " "\0"
    "no `" "\0"
    "no `@target` body covers the target being built" "\0"
    "no entry function (index=" "\0"
    "no parameter named `" "\0"
    "no_return" "\0"
    "non-associative operator chained" "\0"
    "non-exhaustive match" "\0"
    "non-exhaustive match (T3013 should have caught this)" "\0"
    "not yet implemented: " "\0"
    "not_equals" "\0"
    "null" "\0"
    "obj" "\0"
    "object" "\0"
    "off" "\0"
    "offsetof(" "\0"
    "on both sides, or pin the slot's type" "\0"
    "operand kinds disagree for arithmetic op" "\0"
    "operand kinds disagree for bit / mod / shift op" "\0"
    "operand type does not implement the trait this operator requires" "\0"
    "operator " "\0"
    "operator ==" "\0"
    "operator not defined for " "\0"
    "operator not defined for these operand types" "\0"
    "or" "\0"
    "or_or" "\0"
    "or_res" "\0"
    "orphan impl forbidden" "\0"
    "overflow" "\0"
    "p" "\0"
    "p:" "\0"
    "panic" "\0"
    "panic unwind defer" "\0"
    "param" "\0"
    "parameter " "\0"
    "parse_float: invalid float `" "\0"
    "partial" "\0"
    "percent" "\0"
    "percent_assign" "\0"
    "pipe" "\0"
    "plus" "\0"
    "plus_assign" "\0"
    "pointer" "\0"
    "positional argument after a named argument" "\0"
    "pow" "\0"
    "prefer targeting this loop by its iteration variable over a label ; a label is only needed for a `while` / infinite loop that has no variable" "\0"
    "primitive" "\0"
    "ptrdiff_t" "\0"
    "push" "\0"
    "push_all" "\0"
    "question_question" "\0"
    "r:" "\0"
    "range_excl" "\0"
    "range_incl" "\0"
    "rbrace" "\0"
    "rbracket" "\0"
    "reached unreachable: " "\0"
    "read-only is what makes the writable slots safe" "\0"
    "read_dir" "\0"
    "read_file_bytes" "\0"
    "read_keys max" "\0"
    "recursive expression-bodied function requires an explicit `-> Type` annotation" "\0"
    "recv" "\0"
    "redeclaration of a name already bound in this block" "\0"
    "ref" "\0"
    "ref.eq" "\0"
    "ref.eq needs 2 values on stack at pc=" "\0"
    "ref.ne" "\0"
    "ref.ne needs 2 values on stack at pc=" "\0"
    "register" "\0"
    "relative import (`./` / `../`) is not part of the language" "\0"
    "rem" "\0"
    "remove_file" "\0"
    "remove_last" "\0"
    "repeated `!` on the same type level" "\0"
    "rest-binding (`...name`) lowering deferred" "\0"
    "rest-binding only valid inside tuple destructure" "\0"
    "restrict" "\0"
    "resume" "\0"
    "resumed" "\0"
    "return" "\0"
    "return " "\0"
    "return from main" "\0"
    "return r == NULL ? vader_box_null() : vader_box_i64(" "\0"
    "return r;" "\0"
    "return vader_box_obj(" "\0"
    "return.lit from main" "\0"
    "return.lit string.const index " "\0"
    "return;" "\0"
    "returns" "\0"
    "root" "\0"
    "round" "\0"
    "rparen" "\0"
    "run_async_main" "\0"
    "s" "\0"
    "s:" "\0"
    "satisfies" "\0"
    "sched_arm deadline" "\0"
    "scope end (pc " "\0"
    "scope open (pc " "\0"
    "scrut" "\0"
    "self" "\0"
    "self only valid as the first parameter of a method" "\0"
    "self-import: file imports its own module" "\0"
    "set_at" "\0"
    "shebang only allowed on first line" "\0"
    "shl" "\0"
    "short" "\0"
    "short impl form requires a trait with exactly one method" "\0"
    "shr" "\0"
    "signed" "\0"
    "sin" "\0"
    "size" "\0"
    "size_of" "\0"
    "size_of.type" "\0"
    "size_of: argument is not a type" "\0"
    "size_t" "\0"
    "sizeof" "\0"
    "slash" "\0"
    "slash_assign" "\0"
    "slice" "\0"
    "slice_r" "\0"
    "slotarr" "\0"
    "so drop the `!` (the narrowed binding keeps the scrutinee's own mutability)" "\0"
    "spawn_kill handle" "\0"
    "spawn_poll handle" "\0"
    "spawn_start argv" "\0"
    "spawn_start argv element" "\0"
    "spawn_take_stderr handle" "\0"
    "spawn_take_stdout handle" "\0"
    "split: two units named `" "\0"
    "spread" "\0"
    "spread source must be assignable to " "\0"
    "sqrt" "\0"
    "star" "\0"
    "star_assign" "\0"
    "start" "\0"
    "state" "\0"
    "static" "\0"
    "static " "\0"
    "static inline " "\0"
    "static vader_array_t* vader_global_const_arrays[] = {" "\0"
    "static vader_gc_frame_t vader_global_const_frame = " "\0"
    "static void* vader_global_const_objs[] = {" "\0"
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
    "std_core" "\0"
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
    "std_core$i32$Equals$equals" "\0"
    "std_core$i64$Equals$equals" "\0"
    "std_core$string$Equals$equals" "\0"
    "std_core$string$Equals$not_equals" "\0"
    "std_core$u32$Bits32Float$from_bits" "\0"
    "std_core$u64$BitsFloat$from_bits" "\0"
    "std_core$usize$BufferAlloc$new_buffer" "\0"
    "std_env$get_env" "\0"
    "std_io$IOError" "\0"
    "std_io$create_dir" "\0"
    "std_io$current_executable_location" "\0"
    "std_io$current_working_directory" "\0"
    "std_io$exists" "\0"
    "std_io$is_dir" "\0"
    "std_io$poll_stdin" "\0"
    "std_io$read_dir" "\0"
    "std_io$read_file_bytes" "\0"
    "std_io$read_line" "\0"
    "std_io$read_stdin" "\0"
    "std_io$remove_file" "\0"
    "std_io$set_stdin_unbuffered" "\0"
    "std_io$temp_dir" "\0"
    "std_io$write_file_bytes" "\0"
    "std_math$ceil" "\0"
    "std_math$cos" "\0"
    "std_math$floor" "\0"
    "std_math$pow" "\0"
    "std_math$round" "\0"
    "std_math$sin" "\0"
    "std_math$sqrt" "\0"
    "std_math$tan" "\0"
    "std_process$spawn_kill" "\0"
    "std_process$spawn_poll" "\0"
    "std_process$spawn_start" "\0"
    "std_process$spawn_take_stderr" "\0"
    "std_process$spawn_take_stdout" "\0"
    "std_runtime$bytes_copied" "\0"
    "std_runtime$bytes_used" "\0"
    "std_runtime$collect" "\0"
    "std_runtime$collections" "\0"
    "std_runtime$sched_arm" "\0"
    "std_runtime$sched_now" "\0"
    "std_runtime$sched_park" "\0"
    "std_target$current_arch" "\0"
    "std_target$current_os" "\0"
    "std_time$monotonic_ns" "\0"
    "std_time$now_unix_ms" "\0"
    "std_tty$columns" "\0"
    "std_tty$is_tty" "\0"
    "std_tty$raw_mode_begin" "\0"
    "std_tty$raw_mode_end" "\0"
    "std_tty$read_keys" "\0"
    "step" "\0"
    "storage" "\0"
    "store_f64" "\0"
    "store_f64 needs object + offset + value on stack at pc=" "\0"
    "store_f64 value" "\0"
    "store_i32" "\0"
    "store_i32 needs object + offset + value on stack at pc=" "\0"
    "store_i32 value" "\0"
    "store_i64" "\0"
    "store_i64 needs object + offset + value on stack at pc=" "\0"
    "store_i64 value" "\0"
    "store_slot index" "\0"
    "store_slot index " "\0"
    "store_slot needs array + index + value on stack at pc=" "\0"
    "store_slot receiver" "\0"
    "store_u8" "\0"
    "store_u8 needs object + offset + value on stack at pc=" "\0"
    "store_u8 value" "\0"
    "stray backslash (Vader has no line continuation)" "\0"
    "string" "\0"
    "string + non-string" "\0"
    "string codepoint index out of bounds" "\0"
    "string index must be an integer, got " "\0"
    "string interpolation expression must implement `Display`" "\0"
    "string.const index " "\0"
    "string.eq" "\0"
    "string.ne" "\0"
    "string.slice_codepoints hi" "\0"
    "string.slice_codepoints lo" "\0"
    "string.slice_codepoints needs string + lo + hi on stack at pc=" "\0"
    "string.slice_codepoints receiver" "\0"
    "string[] index" "\0"
    "string[] receiver" "\0"
    "string_begin" "\0"
    "string_end" "\0"
    "string_part" "\0"
    "struct" "\0"
    "struct " "\0"
    "struct field access on non-struct type " "\0"
    "struct literal field name" "\0"
    "struct literal not allowed at the top level of a control-flow condition" "\0"
    "struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; " "\0"
    "struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[" "\0"
    "struct.get" "\0"
    "struct.get on empty stack at pc=" "\0"
    "struct.new on non-struct type " "\0"
    "struct.new type " "\0"
    "struct.set field " "\0"
    "struct.set needs receiver + value on stack at pc=" "\0"
    "struct.set on non-struct type " "\0"
    "struct.set receiver" "\0"
    "sub" "\0"
    "surfaced::" "\0"
    "switch" "\0"
    "symbol is not exported from its module" "\0"
    "synthetic" "\0"
    "sys_write at pc=" "\0"
    "sys_write buf" "\0"
    "sys_write byte" "\0"
    "sys_write count" "\0"
    "sys_write fd" "\0"
    "t" "\0"
    "takes a parameter of type" "\0"
    "tan" "\0"
    "target" "\0"
    "target this loop by its variable `" "\0"
    "test" "\0"
    "test can never match \xe2\x80\x94 operands have no overlapping values" "\0"
    "the `import \"...\" as name` form was removed ; write `name :: import \"...\"` instead" "\0"
    "the collection" "\0"
    "the entry is `" "\0"
    "the running process" "\0"
    "the same path is imported both bare (wildcard) and with `{ \xe2\x80\xa6 }` (destructure)" "\0"
    "the scoped `name :: import \"...\" { a, b }` form was removed ; use `name :: import \"...\"` for a namespace or `import \"...\" { a, b }` to destructure" "\0"
    "this argument is immutable, but the parameter is declared `!` (the callee may mutate it)" "\0"
    "this argument is immutable, but the parameter is declared `!` \xe2\x80\x94 the callee may mutate it" "\0"
    "this body takes " "\0"
    "this element is reached through an immutable path" "\0"
    "this free function is only in scope through its namespace alias" "\0"
    "this function mutates a parameter the target slot lends out read-only" "\0"
    "this method mutates its receiver (`self!`), but the receiver is immutable" "\0"
    "tilde" "\0"
    "to_string" "\0"
    "too many arguments : expected " "\0"
    "toolchain/build" "\0"
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
    "tuple pattern requires at least 2 elements" "\0"
    "two `@target` bodies cover the same platform" "\0"
    "two folders declare the same module name globally" "\0"
    "type" "\0"
    "type does not have generic parameters" "\0"
    "type mismatch" "\0"
    "type parameter must be prefixed with `$`" "\0"
    "type parameter name" "\0"
    "type parameter name after `$`" "\0"
    "type value" "\0"
    "type-alias" "\0"
    "type-param" "\0"
    "type-param name" "\0"
    "type-valued slot is not yet supported in this position" "\0"
    "type-valued slot not lowered" "\0"
    "type.const type " "\0"
    "type_args" "\0"
    "type_array" "\0"
    "type_check" "\0"
    "type_check on empty stack at pc=" "\0"
    "type_check type " "\0"
    "type_const" "\0"
    "type_kind" "\0"
    "type_kind: argument is not a type" "\0"
    "type_name" "\0"
    "type_name: argument is not a type" "\0"
    "type_of" "\0"
    "typed numeric suffix `" "\0"
    "typedef" "\0"
    "typedef struct " "\0"
    "typedef vader_box_t (*vader_fn_erased_sig_" "\0"
    "u" "\0"
    "u\n" "\0"
    "u\n\n" "\0"
    "u ? " "\0"
    "u } }" "\0"
    "u)" "\0"
    "u) {" "\0"
    "u));\n" "\0"
    "u);" "\0"
    "u);\n" "\0"
    "u); }" "\0"
    "u,\n" "\0"
    "u, " "\0"
    "u, (double) " "\0"
    "u, (int32_t) " "\0"
    "u, (int32_t)(uint32_t) " "\0"
    "u, (int64_t) " "\0"
    "u, (int64_t) (intptr_t) " "\0"
    "u, (int64_t)(uint64_t) " "\0"
    "u, (void*)(uintptr_t)" "\0"
    "u, 0u, (vader_array_buf_t*) &" "\0"
    "u, 0u, (vader_array_buf_t*) &vader_data_" "\0"
    "u, 0u, 0u, 0u, NULL }" "\0"
    "u, 0u, 0u, 0u, NULL }, " "\0"
    "u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_" "\0"
    "u, 0u, { .obj = (void*) " "\0"
    "u, 0u, { .s = " "\0"
    "u, NULL)" "\0"
    "u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[" "\0"
    "u, e);" "\0"
    "u, vader_global_const_objs };\n" "\0"
    "u, vader_runtime_argv(argc, argv, " "\0"
    "u, { 0u, 0u, 0u },\n" "\0"
    "u16" "\0"
    "u32" "\0"
    "u32.div" "\0"
    "u32.div by zero at pc=" "\0"
    "u32.ge" "\0"
    "u32.gt" "\0"
    "u32.le" "\0"
    "u32.lt" "\0"
    "u32.mod" "\0"
    "u32.rem by zero at pc=" "\0"
    "u64" "\0"
    "u64.div" "\0"
    "u64.div by zero at pc=" "\0"
    "u64.ge" "\0"
    "u64.gt" "\0"
    "u64.le" "\0"
    "u64.lt" "\0"
    "u64.mod" "\0"
    "u64.rem by zero at pc=" "\0"
    "u8" "\0"
    "u: " "\0"
    "u: return " "\0"
    "u:<" "\0"
    "u] = " "\0"
    "u] = (" "\0"
    "uint16_t" "\0"
    "uint32_t" "\0"
    "uint64_t" "\0"
    "uint8_t" "\0"
    "unary `" "\0"
    "unbound host import '" "\0"
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
    "vader.json" "\0"
    "vader.json malformed or unreadable" "\0"
    "vader/" "\0"
    "vader: panic \xe2\x80\x94 " "\0"
    "vader_" "\0"
    "vader_array_box_slots(" "\0"
    "vader_array_clear((vader_array_t*) " "\0"
    "vader_array_copy((vader_array_t*) " "\0"
    "vader_array_push((vader_array_t*) " "\0"
    "vader_array_push_all((vader_array_t*) " "\0"
    "vader_array_push_bool((vader_array_t*) " "\0"
    "vader_array_push_f32((vader_array_t*) " "\0"
    "vader_array_push_f64((vader_array_t*) " "\0"
    "vader_array_push_i16((vader_array_t*) " "\0"
    "vader_array_push_i32((vader_array_t*) " "\0"
    "vader_array_push_i64((vader_array_t*) " "\0"
    "vader_array_push_i8((vader_array_t*) " "\0"
    "vader_array_push_u16((vader_array_t*) " "\0"
    "vader_array_push_u8((vader_array_t*) " "\0"
    "vader_array_ref_load_box" "\0"
    "vader_array_ref_load_obj" "\0"
    "vader_array_ref_store(" "\0"
    "vader_array_ref_store_box(" "\0"
    "vader_array_t vader_data_" "\0"
    "vader_array_t* " "\0"
    "vader_box_bool(" "\0"
    "vader_box_f64(" "\0"
    "vader_box_i32(" "\0"
    "vader_box_i64(" "\0"
    "vader_box_null()" "\0"
    "vader_box_obj(" "\0"
    "vader_box_string(" "\0"
    "vader_box_t" "\0"
    "vader_box_t a" "\0"
    "vader_box_t r = " "\0"
    "vader_box_t recv" "\0"
    "vader_box_t vader_fn_lift_" "\0"
    "vader_box_t vader_fn_tramp_" "\0"
    "vader_buffer_intern_string(" "\0"
    "vader_buffer_load_f64" "\0"
    "vader_buffer_load_i32" "\0"
    "vader_buffer_load_i64" "\0"
    "vader_buffer_load_u8" "\0"
    "vader_buffer_memory_copy(" "\0"
    "vader_buffer_store_f64" "\0"
    "vader_buffer_store_i32" "\0"
    "vader_buffer_store_i64" "\0"
    "vader_buffer_store_u8" "\0"
    "vader_buffer_write_string(" "\0"
    "vader_create_dir(a0" "\0"
    "vader_cstr_free_for(a" "\0"
    "vader_data_" "\0"
    "vader_defer_pop_exec(" "\0"
    "vader_defer_push(" "\0"
    "vader_fn_t vader_fn_static_" "\0"
    "vader_fn_t* " "\0"
    "vader_host_" "\0"
    "vader_obj_header_init(" "\0"
    "vader_obj_header_init(e, " "\0"
    "vader_profile$vader_prof_begin" "\0"
    "vader_profile$vader_prof_dump" "\0"
    "vader_profile$vader_prof_end" "\0"
    "vader_read_dir(a0, " "\0"
    "vader_read_file_bytes(a0, " "\0"
    "vader_read_line(" "\0"
    "vader_read_stdin(a0, " "\0"
    "vader_ref_box(" "\0"
    "vader_remove_file(a0" "\0"
    "vader_slice_t s" "\0"
    "vader_string_slice_codepoints(" "\0"
    "vader_string_t" "\0"
    "vader_struct_" "\0"
    "vader_type_" "\0"
    "vader_type_size[(int32_t)(uintptr_t)" "\0"
    "vader_unreachable(" "\0"
    "vader_unreachable(\"no vtable for " "\0"
    "vader_unreachable(\"unreachable return in " "\0"
    "vader_vm$ffi_call_f64" "\0"
    "vader_vm$ffi_call_int" "\0"
    "vader_vm$ffi_call_int_bytes" "\0"
    "vader_vm$ffi_call_void" "\0"
    "vader_vm$ffi_open" "\0"
    "vader_vm$ffi_symbol" "\0"
    "vader_vt_" "\0"
    "vader_write_file_bytes(a0, (vader_array_t*) a1" "\0"
    "value" "\0"
    "value " "\0"
    "value-position expression not allowed in a type slot" "\0"
    "variant " "\0"
    "variant ." "\0"
    "variant name" "\0"
    "variant name after `.`" "\0"
    "variant_count" "\0"
    "variant_count: argument is not a type" "\0"
    "vcall" "\0"
    "virtual.call '" "\0"
    "void" "\0"
    "void*" "\0"
    "void* env" "\0"
    "void* env, " "\0"
    "void* p" "\0"
    "void* r = " "\0"
    "volatile" "\0"
    "warning" "\0"
    "wasi" "\0"
    "wasm32" "\0"
    "while" "\0"
    "while condition must be `bool`, got " "\0"
    "wildcard arm on a closed union silences exhaustiveness checking ; enumerate the variants or mark the match `@partial`" "\0"
    "wildcard arm on closed union `" "\0"
    "windows" "\0"
    "write" "\0"
    "write `" "\0"
    "write_bool" "\0"
    "write_file_bytes byte" "\0"
    "write_file_bytes content" "\0"
    "write_file_bytes path" "\0"
    "write_int" "\0"
    "write_string" "\0"
    "write_string_at" "\0"
    "write_unsigned" "\0"
    "written `.Linux`, `.Darwin`, `.Windows`, `.Wasi` or `.Browser`" "\0"
    "wrong number of arguments" "\0"
    "x86_64" "\0"
    "xor" "\0"
    "yield" "\0"
    "yield outside a generator body" "\0"
    "yielded value type does not match the generator's element type" "\0"
    "{" "\0"
    "{ " "\0"
    "{ NULL, 0u, 0u, NULL, NULL, " "\0"
    "{ vader_gc_top = gc_frame.prev; " "\0"
    "{char}" "\0"
    "{float}" "\0"
    "{integer}" "\0"
    "|" "\0"
    "||" "\0"
    "}" "\0"
    "}\n" "\0"
    "} else {" "\0"
    "} end_" "\0"
    "};\n" "\0"
    "~" "\0"
    "\xe2\x80\xa6" "\0"
    "\xe2\x80\xa6 and " "\0"
;

const vader_atom_entry_t vader_atom_comptime_table[] = {
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[0] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2] },
    { 0u, 0u, 74u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17] },
    { 0u, 0u, 71u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[92] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[164] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[167] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[169] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[174] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[188] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[240] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[257] },
    { 0u, 0u, 87u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[286] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[374] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[380] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[414] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[446] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[458] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[476] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[491] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[521] },
    { 0u, 0u, 89u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[546] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[636] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[694] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[734] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[761] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[810] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[841] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[888] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[923] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[955] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[994] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1005] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1064] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1089] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1114] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1120] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1127] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1142] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1197] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1204] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1210] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1224] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1227] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1231] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1247] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1256] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1263] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1276] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1290] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1324] },
    { 0u, 0u, 67u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1357] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1425] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1489] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1493] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1521] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1558] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1599] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1646] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1650] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1655] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1660] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1666] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1672] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1690] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1743] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1755] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1779] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1808] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1846] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1856] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1861] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1887] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1927] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1947] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[1971] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2016] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2056] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2095] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2115] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2141] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2147] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2155] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2164] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2169] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2174] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2185] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2188] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2191] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2210] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2216] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2221] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2228] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2235] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2267] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2290] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2309] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2317] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2329] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2337] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2344] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2352] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2371] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2390] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2400] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2428] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2448] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2458] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2462] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2470] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2501] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2517] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2523] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2534] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2557] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2575] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2581] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2616] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2621] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2652] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2672] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2697] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2714] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2738] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2761] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2777] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2795] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2832] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2835] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2849] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2862] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2882] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2890] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2929] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2945] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2964] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[2974] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3004] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3026] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3031] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3037] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3045] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3054] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3059] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3080] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3107] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3128] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3131] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3141] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3175] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3193] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3199] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3209] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3227] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3252] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3260] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3268] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3304] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3319] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3324] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3344] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3351] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3363] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3422] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3426] },
    { 0u, 0u, 137u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3430] },
    { 0u, 0u, 163u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3568] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3732] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3787] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3849] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3906] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3953] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[3993] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4032] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4066] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4115] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4147] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4194] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4224] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4253] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4283] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4313] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4346] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4378] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4412] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4448] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4482] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4514] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4547] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4579] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4613] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4644] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4676] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4710] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4762] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4803] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4844] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4901] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4943] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[4982] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5029] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5064] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5094] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5132] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5172] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5214] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5239] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5261] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5287] },
    { 0u, 0u, 143u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5322] },
    { 0u, 0u, 143u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5466] },
    { 0u, 0u, 157u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5610] },
    { 0u, 0u, 137u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5768] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5906] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5933] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[5964] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6002] },
    { 0u, 0u, 71u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6042] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6114] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6161] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6206] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6254] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6304] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6336] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6340] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6345] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6348] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6352] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6359] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6364] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6374] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6384] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6389] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6394] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6441] },
    { 0u, 0u, 83u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6448] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6532] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6548] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6578] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6608] },
    { 0u, 0u, 71u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6660] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6732] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6738] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6740] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6743] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6746] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6753] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6755] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6759] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6763] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6767] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6772] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6778] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6830] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6832] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6867] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6905] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6915] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6926] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6946] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6967] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[6988] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7009] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7030] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7037] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7039] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7048] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7055] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7062] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7081] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7090] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7105] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7124] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7133] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7142] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7147] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7153] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7156] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7158] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7161] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7163] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7166] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7169] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7172] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7185] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7187] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7194] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7205] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7227] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7245] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7254] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7266] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7287] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7298] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7339] },
    { 0u, 0u, 107u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7348] },
    { 0u, 0u, 73u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7456] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7530] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7585] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7645] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7649] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7651] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7654] },
    { 0u, 0u, 62u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7716] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7779] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7790] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7800] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7812] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7824] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7836] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7847] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7861] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7872] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7885] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7898] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7911] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7923] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7942] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7965] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[7989] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8000] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8021] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8032] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8035] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8054] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8061] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8070] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8080] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8140] },
    { 0u, 0u, 60u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8150] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8211] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8218] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8227] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8237] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8256] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8275] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8284] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8294] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8304] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8306] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8309] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8313] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8319] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8331] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8347] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8356] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8376] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8387] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8417] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8425] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8432] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8436] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8441] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8452] },
    { 0u, 0u, 90u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8463] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8554] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8602] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8651] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8655] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8659] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8663] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8669] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8683] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8686] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8690] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8695] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8698] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8700] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8703] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8711] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8715] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8720] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8746] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8749] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8751] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8754] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8760] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8762] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8765] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8792] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8804] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8824] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8828] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8835] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8846] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8850] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8855] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8864] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8871] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8879] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8896] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8912] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8963] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8965] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8968] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8973] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8976] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8979] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[8997] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9030] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9038] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9048] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9056] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9064] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9098] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9113] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9146] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9155] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9161] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9170] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9178] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9183] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9238] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9248] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9260] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9281] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9294] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9299] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9301] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9305] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9309] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9313] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9317] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9320] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9323] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9326] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9337] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9348] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9360] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9372] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9384] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9397] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9411] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9422] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9427] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9438] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9447] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9452] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9510] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9517] },
    { 0u, 0u, 62u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9519] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9582] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9640] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9700] },
    { 0u, 0u, 79u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9764] },
    { 0u, 0u, 67u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9844] },
    { 0u, 0u, 76u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9912] },
    { 0u, 0u, 60u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[9989] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10050] },
    { 0u, 0u, 78u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10104] },
    { 0u, 0u, 75u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10183] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10259] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10262] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10264] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10267] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10271] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10278] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10280] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10310] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10312] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10314] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10317] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10320] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10322] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10324] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10326] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10328] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10330] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10332] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10334] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10337] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10341] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10360] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10374] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10406] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10459] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10471] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10490] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10505] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10520] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10529] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10552] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10574] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10595] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10615] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10636] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10657] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10688] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10721] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10745] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10769] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10793] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10817] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10826] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10842] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10894] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10932] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10951] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10955] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10958] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10967] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10970] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10972] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10975] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[10986] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11035] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11037] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11040] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11043] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11068] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11105] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11115] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11124] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11133] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11142] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11147] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11162] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11168] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11180] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11187] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11197] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11208] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11210] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11213] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11216] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11218] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11221] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11224] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11261] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11263] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11266] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11268] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11298] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11330] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11367] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11398] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11435] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11482] },
    { 0u, 0u, 73u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11511] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11585] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11587] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11590] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11594] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11598] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11604] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11611] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11625] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11639] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11645] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11655] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11666] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11678] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11690] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11705] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11715] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11727] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11735] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11741] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11747] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11753] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11759] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11765] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11771] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11777] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11783] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11789] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11795] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11801] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11807] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11813] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11819] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11825] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11831] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11840] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11849] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11875] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11923] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11951] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[11981] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12010] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12042] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12070] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12102] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12111] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12123] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12134] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12143] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12150] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12158] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12162] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12177] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12180] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12214] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12221] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12227] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12232] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12236] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12239] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12242] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12245] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12248] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12252] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12256] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12260] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12266] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12276] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12289] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12293] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12304] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12320] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12325] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12334] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12344] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12353] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12363] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12373] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12385] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12408] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12415] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12421] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12431] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12440] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12451] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12456] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12474] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12483] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12489] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12495] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12501] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12507] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12513] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12519] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12525] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12531] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12537] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12543] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12549] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12560] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12566] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12568] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12574] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12580] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12586] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12592] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12598] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12604] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12610] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12616] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12619] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12629] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12633] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12644] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12655] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12671] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12675] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12684] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12689] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12706] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12718] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12722] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12724] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12730] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12736] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12742] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12748] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12754] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12760] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12766] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12772] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12778] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12784] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12790] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12796] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12802] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12808] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12814] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12820] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12826] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12832] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12838] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12844] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12850] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12856] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12862] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12868] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12874] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12880] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12886] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12892] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12895] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12901] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12907] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12913] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12919] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12925] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12931] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12937] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12943] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12949] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12955] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12961] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12967] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12973] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12979] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12985] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12991] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[12997] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13003] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13009] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13015] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13021] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13027] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13033] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13039] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13045] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13051] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13057] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13063] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13069] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13075] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13081] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13087] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13093] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13099] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13105] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13111] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13117] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13123] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13129] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13135] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13141] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13147] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13157] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13161] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13163] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13166] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13171] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13182] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13186] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13200] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13208] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13222] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13226] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13236] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13242] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13248] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13254] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13260] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13266] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13272] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13278] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13284] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13290] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13296] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13302] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13308] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13314] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13320] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13326] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13332] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13338] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13344] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13350] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13356] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13362] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13368] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13374] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13380] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13386] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13392] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13398] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13404] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13410] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13416] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13422] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13428] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13434] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13440] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13446] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13452] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13458] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13464] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13470] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13476] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13482] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13488] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13494] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13500] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13506] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13512] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13518] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13524] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13530] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13536] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13542] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13548] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13554] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13560] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13566] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13572] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13578] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13584] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13590] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13596] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13602] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13608] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13614] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13620] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13626] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13632] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13638] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13644] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13650] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13653] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13656] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13663] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13667] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13674] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13678] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13681] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13691] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13698] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13702] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13713] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13734] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13756] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13762] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13768] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13774] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13780] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13786] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13792] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13798] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13804] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13810] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13816] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13821] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13828] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13836] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13843] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13846] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13849] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13855] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13857] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13860] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13865] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13867] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13870] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13875] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13881] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13888] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13895] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[13959] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14017] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14055] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14063] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14069] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14072] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14078] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14095] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14097] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14099] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14102] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14105] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14114] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14123] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14131] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14137] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14146] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14155] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14166] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14176] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14191] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14205] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14208] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14214] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14222] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14231] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14238] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14247] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14261] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14277] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14295] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14307] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14316] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14325] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14338] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14347] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14354] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14367] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14379] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14389] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14403] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14406] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14411] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14416] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14426] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14435] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14438] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14441] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14447] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14453] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14484] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14497] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14542] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14584] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14590] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14603] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14609] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14615] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14628] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14631] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14636] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14641] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14644] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14648] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14655] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14658] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14660] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14663] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14695] },
    { 0u, 0u, 225u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14730] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14956] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[14988] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15014] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15066] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15100] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15128] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15151] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15193] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15218] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15225] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15231] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15240] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15247] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15268] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15324] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15378] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15401] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15460] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15482] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15505] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15540] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15547] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15556] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15563] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15614] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15634] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15657] },
    { 0u, 0u, 65u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15702] },
    { 0u, 0u, 68u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15768] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15837] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15849] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15856] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15864] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15885] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15892] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15921] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15929] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[15991] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16021] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16047] },
    { 0u, 0u, 164u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16107] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16272] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16288] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16343] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16361] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16405] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16429] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16445] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16507] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16525] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16541] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16564] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16604] },
    { 0u, 0u, 211u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16661] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16873] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16912] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[16956] },
    { 0u, 0u, 84u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17015] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17100] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17111] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17117] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17145] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17166] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17202] },
    { 0u, 0u, 73u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17231] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17305] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17333] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17352] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17364] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17371] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17377] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17384] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17406] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17418] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17458] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17468] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17488] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17497] },
    { 0u, 0u, 83u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17527] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17611] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17634] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17672] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17690] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17718] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17740] },
    { 0u, 0u, 68u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17768] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17837] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17895] },
    { 0u, 0u, 137u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[17931] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18069] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18107] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18120] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18176] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18225] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18281] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18340] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18354] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18393] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18441] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18459] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18501] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18514] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18546] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18570] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18602] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18605] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18640] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18670] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18698] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18733] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18749] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18776] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18804] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18842] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18874] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18907] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18934] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[18986] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19022] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19056] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19090] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19111] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19114] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19151] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19155] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19203] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19248] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19269] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19307] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19343] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19376] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19411] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19440] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19463] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19483] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19547] },
    { 0u, 0u, 82u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19550] },
    { 0u, 0u, 68u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19633] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19702] },
    { 0u, 0u, 76u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19764] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19841] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19878] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19913] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[19967] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20012] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20072] },
    { 0u, 0u, 68u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20127] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20196] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20239] },
    { 0u, 0u, 91u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20254] },
    { 0u, 0u, 88u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20346] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20435] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20467] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20524] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20562] },
    { 0u, 0u, 71u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20620] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20692] },
    { 0u, 0u, 84u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20726] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20811] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20839] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20872] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20891] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20916] },
    { 0u, 0u, 112u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[20943] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21056] },
    { 0u, 0u, 73u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21101] },
    { 0u, 0u, 85u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21175] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21261] },
    { 0u, 0u, 83u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21309] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21393] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21431] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21479] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21525] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21546] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21580] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21608] },
    { 0u, 0u, 65u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21647] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21713] },
    { 0u, 0u, 181u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21763] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[21945] },
    { 0u, 0u, 86u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22000] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22087] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22105] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22127] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22150] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22174] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22201] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22224] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22243] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22266] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22289] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22314] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22333] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22358] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22386] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22414] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22438] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22455] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22457] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22483] },
    { 0u, 0u, 86u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22542] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22629] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22677] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22736] },
    { 0u, 0u, 107u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22787] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22895] },
    { 0u, 0u, 101u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[22944] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23046] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23106] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23153] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23162] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23170] },
    { 0u, 0u, 95u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23218] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23314] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23318] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23322] },
    { 0u, 0u, 77u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23326] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23404] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23408] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23414] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23431] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23440] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23473] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23477] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23490] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23494] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23524] },
    { 0u, 0u, 150u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23528] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23679] },
    { 0u, 0u, 78u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23701] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23780] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23788] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23803] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23807] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23815] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23823] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23827] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23831] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23846] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23852] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23856] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23870] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23876] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23913] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23925] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23959] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23980] },
    { 0u, 0u, 83u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[23991] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24075] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24090] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24111] },
    { 0u, 0u, 72u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24126] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24199] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24244] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24259] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24280] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24296] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24313] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24359] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24378] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24410] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24429] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24447] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24463] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24510] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24530] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24545] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24592] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24616] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24638] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24656] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24696] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24723] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24736] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24755] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24804] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24826] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24842] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24859] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24913] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24932] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24947] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[24962] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25012] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25033] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25039] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25042] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25049] },
    { 0u, 0u, 69u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25056] },
    { 0u, 0u, 79u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25126] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25206] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25250] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25295] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25343] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25346] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25351] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25357] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25390] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25398] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25403] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25442] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25450] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25474] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25510] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25517] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25523] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25535] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25581] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25593] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25639] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25646] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25652] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25657] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25666] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25674] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25682] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25691] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25722] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25730] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25756] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25768] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25776] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25805] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25816] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25848] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25876] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25882] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25893] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25901] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25905] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25943] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25959] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25976] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[25993] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26014] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26066] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26092] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26156] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26199] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26223] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26251] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26280] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26307] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26313] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26371] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26387] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26426] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26467] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26519] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26530] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26543] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26548] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26573] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26581] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26595] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26612] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26621] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26665] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26709] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26715] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26730] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26751] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26776] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26778] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26810] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26846] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26855] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26865] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26870] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26900] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26910] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26923] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26937] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26951] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[26987] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27008] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27038] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27061] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27081] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27090] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27107] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27114] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27145] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27158] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27194] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27224] },
    { 0u, 0u, 81u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27260] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27342] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27358] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27391] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27438] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27473] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27478] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27484] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27489] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27494] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27499] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27504] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27513] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27523] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27537] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27551] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27556] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27569] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27599] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27633] },
    { 0u, 0u, 66u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27686] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27753] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27759] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27765] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27773] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27782] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27815] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27859] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27886] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27894] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27900] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27906] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27914] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27948] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27968] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[27998] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28007] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28031] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28060] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28086] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28124] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28154] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28183] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28218] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28247] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28285] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28322] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28342] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28366] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28374] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28379] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28404] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28445] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28451] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28458] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28490] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28502] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28516] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28554] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28584] },
    { 0u, 0u, 135u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28598] },
    { 0u, 0u, 153u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28734] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28888] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28915] },
    { 0u, 0u, 88u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[28936] },
    { 0u, 0u, 57u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29025] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29083] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29130] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29142] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29153] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29162] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29171] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29186] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29216] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29224] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29228] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29234] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29243] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29254] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29261] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29279] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29281] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29288] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29311] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29322] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29333] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29342] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29382] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29438] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29463] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29503] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29537] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29545] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29551] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29565] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29580] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29601] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29634] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29667] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29678] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29694] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29698] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29701] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29708] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29712] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29722] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29729] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29756] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29787] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29824] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29853] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29892] },
    { 0u, 0u, 60u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29917] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[29978] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30015] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30017] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30041] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30047] },
    { 0u, 0u, 72u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30052] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30125] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30130] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30161] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30199] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30230] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30261] },
    { 0u, 0u, 91u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30273] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30365] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30369] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30381] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30386] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30413] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30452] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30457] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30503] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30552] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30556] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30560] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30563] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30570] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30576] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30588] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30597] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30640] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30646] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30681] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30743] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30750] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30760] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30782] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30802] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30822] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30871] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30887] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30914] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30937] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30970] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[30989] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31010] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31056] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31072] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31095] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31134] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31157] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31172] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31197] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31224] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31258] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31310] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31340] },
    { 0u, 0u, 68u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31355] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31424] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31447] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31454] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31485] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31510] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31521] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31585] },
    { 0u, 0u, 59u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31634] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31694] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31718] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31729] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31776] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31803] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31831] },
    { 0u, 0u, 70u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31859] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31930] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31937] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31945] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31954] },
    { 0u, 0u, 61u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[31994] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32056] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32091] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32142] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32146] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32158] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32204] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32208] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32216] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32224] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32231] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32238] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32245] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32252] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32259] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32267] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32274] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32282] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32290] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32302] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32348] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32352] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32358] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32368] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32396] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32410] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32424] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32440] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32452] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32467] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32493] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32517] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32542] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32566] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32580] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32595] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32611] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32617] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32625] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32666] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32700] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32711] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32732] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32771] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32800] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32812] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32824] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32860] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32872] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32887] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32943] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[32985] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33023] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33030] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33035] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33091] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33096] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33110] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33116] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33130] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33136] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33139] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33143] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33150] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33157] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33163] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33167] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33196] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33235] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33243] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33255] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33264] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33271] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33277] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33285] },
    { 0u, 0u, 72u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33293] },
    { 0u, 0u, 67u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33366] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33434] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33479] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33498] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33541] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33550] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33557] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33567] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33576] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33586] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33599] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33608] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33622] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33631] },
    { 0u, 0u, 62u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33685] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33748] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33796] },
    { 0u, 0u, 43u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33828] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33872] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33908] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33921] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33926] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33931] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33937] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33940] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33944] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33949] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33963] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33987] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33992] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[33999] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34001] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34005] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34009] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34017] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34028] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34039] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34049] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34060] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34068] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34091] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34098] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34105] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34112] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34119] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34126] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34134] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34157] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34165] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34172] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34180] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34188] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34196] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34205] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34213] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34217] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34225] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34236] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34247] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34257] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34268] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34276] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34299] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34306] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34313] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34320] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34327] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34334] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34342] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34350] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34357] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34365] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34388] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34396] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34404] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34413] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34421] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34424] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34427] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34433] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34437] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34440] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34445] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34459] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34473] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34507] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34536] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34561] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34569] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34576] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34581] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34622] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34633] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34640] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34660] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34682] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34694] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34715] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34730] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34744] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34781] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34815] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34844] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34847] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34860] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34870] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34897] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34922] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34926] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34931] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34938] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34944] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34966] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[34970] },
    { 0u, 0u, 70u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35005] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35076] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35084] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35092] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35100] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35107] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35119] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35136] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35162] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35215] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35253] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35262] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35275] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35287] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35329] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35370] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35375] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35385] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35426] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35471] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35521] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35551] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35584] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35602] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35632] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35657] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35670] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35696] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35710] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35734] },
    { 0u, 0u, 81u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35772] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35854] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35869] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35872] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35909] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35916] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35930] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35936] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35941] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35952] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35963] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35972] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35982] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[35991] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36019] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36021] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36027] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36036] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36045] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36054] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36066] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36075] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36083] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36091] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36101] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36110] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36116] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36123] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36129] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36143] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36153] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36159] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36165] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36174] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36182] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36192] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36200] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36210] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36219] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36227] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36236] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36238] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36293] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36312] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36319] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36328] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36358] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36362] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36407] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36445] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36449] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36455] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36464] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36473] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36482] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36498] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36515] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36561] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36580] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36588] },
    { 0u, 0u, 66u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36594] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36661] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36673] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36691] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36707] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36739] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36755] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36787] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36803] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36843] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36848] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36853] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36859] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36878] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36885] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36888] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36892] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36894] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36899] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36920] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36984] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[36997] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37036] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37062] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37068] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37108] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37128] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37165] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37196] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37221] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37237] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37257] },
    { 0u, 0u, 67u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37271] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37339] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37381] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37408] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37424] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37444] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37491] },
    { 0u, 0u, 81u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37514] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37596] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37630] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37662] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37698] },
    { 0u, 0u, 114u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37730] },
    { 0u, 0u, 87u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37845] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37933] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37939] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37952] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[37974] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38021] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38039] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38065] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38093] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38134] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38153] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38157] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38164] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38173] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38227] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38280] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38321] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38333] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38350] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38400] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38404] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38409] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38449] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38503] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38546] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38550] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38557] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38598] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38602] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38608] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38624] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38632] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38637] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38658] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38663] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38711] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38737] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38758] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38768] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38801] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38822] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38875] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38897] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38908] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38913] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38917] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38924] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38928] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38938] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[38976] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39017] },
    { 0u, 0u, 64u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39065] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39130] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39140] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39152] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39178] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39223] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39226] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39232] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39239] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39261] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39270] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39272] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39275] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39281] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39300] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39306] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39317] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39346] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39354] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39362] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39377] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39382] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39387] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39399] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39407] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39450] },
    { 0u, 0u, 141u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39454] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39596] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39606] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39616] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39621] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39630] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39648] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39651] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39662] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39673] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39680] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39689] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39711] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39759] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39768] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39784] },
    { 0u, 0u, 78u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39798] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39877] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39882] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39934] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39938] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39945] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39983] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[39990] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40028] },
    { 0u, 0u, 58u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40037] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40096] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40100] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40112] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40124] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40160] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40203] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40252] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40261] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40268] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40276] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40283] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40291] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40308] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40361] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40371] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40393] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40414] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40445] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40453] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40461] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40466] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40472] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40479] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40494] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40496] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40499] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40509] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40528] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40543] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40559] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40565] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40570] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40621] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40662] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40669] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40704] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40708] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40714] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40771] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40775] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40782] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40786] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40791] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40799] },
    { 0u, 0u, 31u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40812] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40844] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40851] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40858] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40864] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40877] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40883] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40891] },
    { 0u, 0u, 75u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40899] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40975] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[40993] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41011] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41028] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41053] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41078] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41103] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41128] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41135] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41172] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41177] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41182] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41194] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41200] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41206] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41213] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41221] },
    { 0u, 0u, 53u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41236] },
    { 0u, 0u, 51u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41290] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41342] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41385] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41395] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41411] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41427] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41436] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41451] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41467] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41486] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41497] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41514] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41530] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41539] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41549] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41590] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41625] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41664] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41700] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41740] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41757] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41775] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41790] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41815] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41848] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41879] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41906] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41933] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41963] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[41997] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42032] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42065] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42103] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42119] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42134] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42152] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42187] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42220] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42234] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42248] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42266] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42282] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42305] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42322] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42340] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42359] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42387] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42403] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42427] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42441] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42454] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42469] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42482] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42497] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42510] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42524] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42537] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42560] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42583] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42607] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42637] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42667] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42692] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42715] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42735] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42759] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42781] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42803] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42826] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42850] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42872] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42894] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42915] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42931] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42946] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42969] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[42990] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43008] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43013] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43021] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43031] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43087] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43103] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43113] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43169] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43185] },
    { 0u, 0u, 55u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43195] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43251] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43267] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43284] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43302] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43357] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43377] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43386] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43441] },
    { 0u, 0u, 48u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43456] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43505] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43512] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43532] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43569] },
    { 0u, 0u, 56u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43607] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43664] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43684] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43694] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43704] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43731] },
    { 0u, 0u, 62u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43758] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43821] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43854] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43869] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43887] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43900] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43911] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43923] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43930] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43938] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[43978] },
    { 0u, 0u, 71u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44004] },
    { 0u, 0u, 129u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44076] },
    { 0u, 0u, 147u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44206] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44354] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44365] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44398] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44429] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44446] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44464] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44514] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44545] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44565] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44569] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44580] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44587] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44626] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44636] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44653] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44667] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44682] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44698] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44711] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44713] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44739] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44743] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44750] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44785] },
    { 0u, 0u, 60u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44790] },
    { 0u, 0u, 82u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44851] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44934] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44949] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44964] },
    { 0u, 0u, 79u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[44984] },
    { 0u, 0u, 146u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45064] },
    { 0u, 0u, 88u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45211] },
    { 0u, 0u, 90u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45300] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45391] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45408] },
    { 0u, 0u, 63u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45458] },
    { 0u, 0u, 69u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45522] },
    { 0u, 0u, 73u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45592] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45666] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45672] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45682] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45713] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45729] },
    { 0u, 0u, 50u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45766] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45817] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45823] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45831] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45842] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45879] },
    { 0u, 0u, 97u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45899] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[45997] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46002] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46006] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46012] },
    { 0u, 0u, 44u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46055] },
    { 0u, 0u, 49u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46100] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46150] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46155] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46193] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46207] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46248] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46268] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46298] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46309] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46320] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46331] },
    { 0u, 0u, 54u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46347] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46402] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46431] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46448] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46458] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46469] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46480] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46513] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46530] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46541] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46551] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46585] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46595] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46629] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46637] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46660] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46668] },
    { 0u, 0u, 42u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46684] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46727] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46729] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46732] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46736] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46741] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46747] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46750] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46755] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46761] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46765] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46770] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46776] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46780] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46784] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46797] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46811] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46835] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46849] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46874] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46898] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46920] },
    { 0u, 0u, 40u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46950] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[46991] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47013] },
    { 0u, 0u, 47u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47037] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47085] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47110] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47125] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47134] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47181] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47188] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47219] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47254] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47274] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47278] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47282] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47290] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47313] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47320] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47327] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47334] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47341] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47349] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47372] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47376] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47384] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47407] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47414] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47421] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47428] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47435] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47443] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47466] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47469] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47473] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47484] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47488] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47494] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47501] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47510] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47519] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47528] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47536] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47544] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47566] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47594] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47615] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47639] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47656] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47662] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47670] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47698] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47719] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47734] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47751] },
    { 0u, 0u, 23u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47774] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47798] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47816] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47821] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47833] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47850] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47872] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47890] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47912] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47933] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47942] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47961] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[47988] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48019] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48039] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48059] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48079] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48107] },
    { 0u, 0u, 45u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48154] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48200] },
    { 0u, 0u, 73u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48230] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48304] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48310] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48321] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48356] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48363] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48381] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48388] },
    { 0u, 0u, 35u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48411] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48447] },
    { 0u, 0u, 34u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48482] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48517] },
    { 0u, 0u, 39u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48556] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48596] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48635] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48674] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48713] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48752] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48791] },
    { 0u, 0u, 38u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48829] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48868] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48906] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48931] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48956] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[48979] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49006] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49032] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49048] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49064] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49079] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49094] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49109] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49126] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49141] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49159] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49171] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49185] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49202] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49219] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49246] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49274] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49302] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49324] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49346] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49368] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49389] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49415] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49438] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49461] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49484] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49506] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49533] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49553] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49575] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49587] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49609] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49627] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49655] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49668] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49680] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49703] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49729] },
    { 0u, 0u, 29u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49760] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49790] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49819] },
    { 0u, 0u, 26u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49839] },
    { 0u, 0u, 16u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49866] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49883] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49905] },
    { 0u, 0u, 20u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49920] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49941] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49957] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[49988] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50003] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50017] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50029] },
    { 0u, 0u, 18u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50066] },
    { 0u, 0u, 33u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50085] },
    { 0u, 0u, 41u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50119] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50161] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50183] },
    { 0u, 0u, 27u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50205] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50233] },
    { 0u, 0u, 17u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50256] },
    { 0u, 0u, 19u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50274] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50294] },
    { 0u, 0u, 46u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50304] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50351] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50357] },
    { 0u, 0u, 52u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50364] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50417] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50426] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50436] },
    { 0u, 0u, 22u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50449] },
    { 0u, 0u, 13u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50472] },
    { 0u, 0u, 37u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50486] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50524] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50530] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50545] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50550] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50556] },
    { 0u, 0u, 11u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50566] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50578] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50586] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50597] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50606] },
    { 0u, 0u, 4u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50614] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50619] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50626] },
    { 0u, 0u, 36u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50632] },
    { 0u, 0u, 117u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50669] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50787] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50818] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50826] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50832] },
    { 0u, 0u, 10u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50840] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50851] },
    { 0u, 0u, 24u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50873] },
    { 0u, 0u, 21u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50898] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50920] },
    { 0u, 0u, 12u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50930] },
    { 0u, 0u, 15u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50943] },
    { 0u, 0u, 14u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50959] },
    { 0u, 0u, 62u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[50974] },
    { 0u, 0u, 25u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51037] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51063] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51070] },
    { 0u, 0u, 5u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51074] },
    { 0u, 0u, 30u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51080] },
    { 0u, 0u, 62u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51111] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51174] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51176] },
    { 0u, 0u, 28u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51179] },
    { 0u, 0u, 32u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51208] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51241] },
    { 0u, 0u, 7u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51248] },
    { 0u, 0u, 9u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51256] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51266] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51268] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51271] },
    { 0u, 0u, 2u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51273] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51276] },
    { 0u, 0u, 6u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51285] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51292] },
    { 0u, 0u, 1u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51296] },
    { 0u, 0u, 3u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51298] },
    { 0u, 0u, 8u, VADER_ATOM_FLAG_PERM, 0u, &vader_atom_blob[51302] },
};

#define VADER_COMPTIME_ATOM_COUNT 2441u

/* Comptime data pool — read-only arrays in `.rodata`.
 * Out-of-arena pointers are immortal to the GC (it never copies /
 * relocates them), so `data.const` boxes a zero-copy view. */
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint64_t slots[1302]; } vader_data_0_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1302u, 1302u, 170u, 4u, { 0u, 0u, 0u },
    { (uint64_t) UINT64_C(17218479456385750618), (uint64_t) UINT64_C(1242899115359157055), (uint64_t) UINT64_C(10761549660241094136), (uint64_t) UINT64_C(5388497965526861063), (uint64_t) UINT64_C(13451937075301367670), (uint64_t) UINT64_C(6735622456908576329), (uint64_t) UINT64_C(16814921344126709587), (uint64_t) UINT64_C(17642900107990496220), (uint64_t) UINT64_C(10509325840079193492), (uint64_t) UINT64_C(8720969558280366185), (uint64_t) UINT64_C(13136657300098991865), (uint64_t) UINT64_C(10901211947850457732), (uint64_t) UINT64_C(16420821625123739831), (uint64_t) UINT64_C(18238200953240460069), (uint64_t) UINT64_C(10263013515702337394), (uint64_t) UINT64_C(18316404623416369399), (uint64_t) UINT64_C(12828766894627921743), (uint64_t) UINT64_C(13672133742415685941), (uint64_t) UINT64_C(16035958618284902179), (uint64_t) UINT64_C(12478481159592219522), (uint64_t) UINT64_C(10022474136428063862), (uint64_t) UINT64_C(5493207715531443249), (uint64_t) UINT64_C(12528092670535079827), (uint64_t) UINT64_C(16089881681269079869), (uint64_t) UINT64_C(15660115838168849784), (uint64_t) UINT64_C(15500666083158961933), (uint64_t) UINT64_C(9787572398855531115), (uint64_t) UINT64_C(9687916301974351208), (uint64_t) UINT64_C(12234465498569413894), (uint64_t) UINT64_C(7498209359040551106), (uint64_t) UINT64_C(15293081873211767368), (uint64_t) UINT64_C(149389661945913074), (uint64_t) UINT64_C(9558176170757354605), (uint64_t) UINT64_C(93368538716195671), (uint64_t) UINT64_C(11947720213446693256), (uint64_t) UINT64_C(4728396691822632493), (uint64_t) UINT64_C(14934650266808366570), (uint64_t) UINT64_C(5910495864778290617), (uint64_t) UINT64_C(9334156416755229106), (uint64_t) UINT64_C(8305745933913819539), (uint64_t) UINT64_C(11667695520944036383), (uint64_t) UINT64_C(1158810380537498616), (uint64_t) UINT64_C(14584619401180045478), (uint64_t) UINT64_C(15283571030954036982), (uint64_t) UINT64_C(18230774251475056848), (uint64_t) UINT64_C(9881091751837770420), (uint64_t) UINT64_C(11394233907171910530), (uint64_t) UINT64_C(6175682344898606512), (uint64_t) UINT64_C(14242792383964888162), (uint64_t) UINT64_C(16942974967978033949), (uint64_t) UINT64_C(17803490479956110203), (uint64_t) UINT64_C(11955346673117766628), (uint64_t) UINT64_C(11127181549972568877), (uint64_t) UINT64_C(5166248661484910190), (uint64_t) UINT64_C(13908976937465711096), (uint64_t) UINT64_C(11069496845283525642), (uint64_t) UINT64_C(17386221171832138870), (uint64_t) UINT64_C(13836871056604407053), (uint64_t) UINT64_C(10866388232395086794), (uint64_t) UINT64_C(4036358391950366504), (uint64_t) UINT64_C(13582985290493858492), (uint64_t) UINT64_C(14268820026792733938), (uint64_t) UINT64_C(16978731613117323115), (uint64_t) UINT64_C(17836025033490917422), (uint64_t) UINT64_C(10611707258198326947), (uint64_t) UINT64_C(8841672636718129437), (uint64_t) UINT64_C(13264634072747908684), (uint64_t) UINT64_C(6440404777470273892), (uint64_t) UINT64_C(16580792590934885855), (uint64_t) UINT64_C(8050505971837842365), (uint64_t) UINT64_C(10362995369334303659), (uint64_t) UINT64_C(11949095260039733334), (uint64_t) UINT64_C(12953744211667879574), (uint64_t) UINT64_C(10324683056622278764), (uint64_t) UINT64_C(16192180264584849468), (uint64_t) UINT64_C(3682481783923072647), (uint64_t) UINT64_C(10120112665365530917), (uint64_t) UINT64_C(11524923151806696212), (uint64_t) UINT64_C(12650140831706913647), (uint64_t) UINT64_C(571095884476206553), (uint64_t) UINT64_C(15812676039633642058), (uint64_t) UINT64_C(14548927910877421904), (uint64_t) UINT64_C(9882922524771026286), (uint64_t) UINT64_C(13704765962725776594), (uint64_t) UINT64_C(12353653155963782858), (uint64_t) UINT64_C(7907585416552444934), (uint64_t) UINT64_C(15442066444954728573), (uint64_t) UINT64_C(661109733835780360), (uint64_t) UINT64_C(9651291528096705358), (uint64_t) UINT64_C(2719036592861056677), (uint64_t) UINT64_C(12064114410120881697), (uint64_t) UINT64_C(12622167777931096654), (uint64_t) UINT64_C(15080143012651102122), (uint64_t) UINT64_C(1942651667131707105), (uint64_t) UINT64_C(9425089382906938826), (uint64_t) UINT64_C(5825843310384704845), (uint64_t) UINT64_C(11781361728633673532), (uint64_t) UINT64_C(16505676174835656864), (uint64_t) UINT64_C(14726702160792091916), (uint64_t) UINT64_C(2185351144835019464), (uint64_t) UINT64_C(18408377700990114895), (uint64_t) UINT64_C(2731688931043774330), (uint64_t) UINT64_C(11505236063118821809), (uint64_t) UINT64_C(8624834609543440812), (uint64_t) UINT64_C(14381545078898527261), (uint64_t) UINT64_C(15392729280356688919), (uint64_t) UINT64_C(17976931348623159077), (uint64_t) UINT64_C(5405853545163697437), (uint64_t) UINT64_C(11235582092889474423), (uint64_t) UINT64_C(5684501474941004850), (uint64_t) UINT64_C(14044477616111843029), (uint64_t) UINT64_C(2493940825248868159), (uint64_t) UINT64_C(17555597020139803786), (uint64_t) UINT64_C(7729112049988473103), (uint64_t) UINT64_C(10972248137587377366), (uint64_t) UINT64_C(9442381049670183593), (uint64_t) UINT64_C(13715310171984221708), (uint64_t) UINT64_C(2579604275232953683), (uint64_t) UINT64_C(17144137714980277135), (uint64_t) UINT64_C(3224505344041192104), (uint64_t) UINT64_C(10715086071862673209), (uint64_t) UINT64_C(8932844867666826921), (uint64_t) UINT64_C(13393857589828341511), (uint64_t) UINT64_C(15777742103010921555), (uint64_t) UINT64_C(16742321987285426889), (uint64_t) UINT64_C(15110491610336264040), (uint64_t) UINT64_C(10463951242053391806), (uint64_t) UINT64_C(2526528228819083169), (uint64_t) UINT64_C(13079939052566739757), (uint64_t) UINT64_C(12381532322878629770), (uint64_t) UINT64_C(16349923815708424697), (uint64_t) UINT64_C(1641857348316123500), (uint64_t) UINT64_C(10218702384817765435), (uint64_t) UINT64_C(12555375888766046947), (uint64_t) UINT64_C(12773377981022206794), (uint64_t) UINT64_C(11082533842530170780), (uint64_t) UINT64_C(15966722476277758493), (uint64_t) UINT64_C(4629795266307937667), (uint64_t) UINT64_C(9979201547673599058), (uint64_t) UINT64_C(5199465050656154994), (uint64_t) UINT64_C(12474001934591998822), (uint64_t) UINT64_C(15722703350174969551), (uint64_t) UINT64_C(15592502418239998528), (uint64_t) UINT64_C(10430007150863936130), (uint64_t) UINT64_C(9745314011399999080), (uint64_t) UINT64_C(6518754469289960081), (uint64_t) UINT64_C(12181642514249998850), (uint64_t) UINT64_C(8148443086612450102), (uint64_t) UINT64_C(15227053142812498563), (uint64_t) UINT64_C(962181821410786819), (uint64_t) UINT64_C(9516908214257811601), (uint64_t) UINT64_C(16742264702877599426), (uint64_t) UINT64_C(11896135267822264502), (uint64_t) UINT64_C(7092772823314835570), (uint64_t) UINT64_C(14870169084777830627), (uint64_t) UINT64_C(18089338065998320271), (uint64_t) UINT64_C(9293855677986144142), (uint64_t) UINT64_C(8999993282035256217), (uint64_t) UINT64_C(11617319597482680178), (uint64_t) UINT64_C(2026619565689294464), (uint64_t) UINT64_C(14521649496853350222), (uint64_t) UINT64_C(11756646493966393888), (uint64_t) UINT64_C(18152061871066687778), (uint64_t) UINT64_C(5472436080603216552), (uint64_t) UINT64_C(11345038669416679861), (uint64_t) UINT64_C(8031958568804398249), (uint64_t) UINT64_C(14181298336770849826), (uint64_t) UINT64_C(14651634229432885715), (uint64_t) UINT64_C(17726622920963562283), (uint64_t) UINT64_C(9091170749936331336), (uint64_t) UINT64_C(11079139325602226427), (uint64_t) UINT64_C(3376138709496513133), (uint64_t) UINT64_C(13848924157002783033), (uint64_t) UINT64_C(18055231442152805128), (uint64_t) UINT64_C(17311155196253478792), (uint64_t) UINT64_C(8733981247408842698), (uint64_t) UINT64_C(10819471997658424245), (uint64_t) UINT64_C(5458738279630526686), (uint64_t) UINT64_C(13524339997073030306), (uint64_t) UINT64_C(11435108867965546262), (uint64_t) UINT64_C(16905424996341287883), (uint64_t) UINT64_C(5070514048102157020), (uint64_t) UINT64_C(10565890622713304927), (uint64_t) UINT64_C(863228270850154185), (uint64_t) UINT64_C(13207363278391631158), (uint64_t) UINT64_C(14914093393844856443), (uint64_t) UINT64_C(16509204097989538948), (uint64_t) UINT64_C(9419244705451294746), (uint64_t) UINT64_C(10318252561243461842), (uint64_t) UINT64_C(15110399977761835024), (uint64_t) UINT64_C(12897815701554327303), (uint64_t) UINT64_C(9664627935347517973), (uint64_t) UINT64_C(16122269626942909129), (uint64_t) UINT64_C(7469098900757009562), (uint64_t) UINT64_C(10076418516839318205), (uint64_t) UINT64_C(16197401859041600736), (uint64_t) UINT64_C(12595523146049147757), (uint64_t) UINT64_C(6411694268519837208), (uint64_t) UINT64_C(15744403932561434696), (uint64_t) UINT64_C(12626303854077184414), (uint64_t) UINT64_C(9840252457850896685), (uint64_t) UINT64_C(7891439908798240259), (uint64_t) UINT64_C(12300315572313620856), (uint64_t) UINT64_C(14475985904425188227), (uint64_t) UINT64_C(15375394465392026070), (uint64_t) UINT64_C(18094982380531485284), (uint64_t) UINT64_C(9609621540870016294), (uint64_t) UINT64_C(6697677969404790399), (uint64_t) UINT64_C(12012026926087520367), (uint64_t) UINT64_C(17595469498610763806), (uint64_t) UINT64_C(15015033657609400459), (uint64_t) UINT64_C(17382650854836066854), (uint64_t) UINT64_C(9384396036005875287), (uint64_t) UINT64_C(8558313775058847832), (uint64_t) UINT64_C(11730495045007344109), (uint64_t) UINT64_C(6086206200396171886), (uint64_t) UINT64_C(14663118806259180136), (uint64_t) UINT64_C(12219443768922602761), (uint64_t) UINT64_C(18328898507823975170), (uint64_t) UINT64_C(15274304711153253452), (uint64_t) UINT64_C(11455561567389984481), (uint64_t) UINT64_C(14158126462898171311), (uint64_t) UINT64_C(14319451959237480602), (uint64_t) UINT64_C(3862600023340550427), (uint64_t) UINT64_C(17899314949046850752), (uint64_t) UINT64_C(14051622066030463842), (uint64_t) UINT64_C(11187071843154281720), (uint64_t) UINT64_C(8782263791269039901), (uint64_t) UINT64_C(13983839803942852150), (uint64_t) UINT64_C(10977829739086299876), (uint64_t) UINT64_C(17479799754928565188), (uint64_t) UINT64_C(4498915137003099037), (uint64_t) UINT64_C(10924874846830353242), (uint64_t) UINT64_C(12035193997481712706), (uint64_t) UINT64_C(13656093558537941553), (uint64_t) UINT64_C(5820620459997365075), (uint64_t) UINT64_C(17070116948172426941), (uint64_t) UINT64_C(11887461593424094248), (uint64_t) UINT64_C(10668823092607766838), (uint64_t) UINT64_C(9735506505103752857), (uint64_t) UINT64_C(13336028865759708548), (uint64_t) UINT64_C(2946011094524915263), (uint64_t) UINT64_C(16670036082199635685), (uint64_t) UINT64_C(3682513868156144079), (uint64_t) UINT64_C(10418772551374772303), (uint64_t) UINT64_C(4607414176811284001), (uint64_t) UINT64_C(13023465689218465379), (uint64_t) UINT64_C(1147581702586717097), (uint64_t) UINT64_C(16279332111523081723), (uint64_t) UINT64_C(15269535183515560084), (uint64_t) UINT64_C(10174582569701926077), (uint64_t) UINT64_C(7237616480483531100), (uint64_t) UINT64_C(12718228212127407596), (uint64_t) UINT64_C(13658706619031801779), (uint64_t) UINT64_C(15897785265159259495), (uint64_t) UINT64_C(17073383273789752224), (uint64_t) UINT64_C(9936115790724537184), (uint64_t) UINT64_C(17588393573759676996), (uint64_t) UINT64_C(12420144738405671481), (uint64_t) UINT64_C(3538747893490044629), (uint64_t) UINT64_C(15525180923007089351), (uint64_t) UINT64_C(9035120885289943691), (uint64_t) UINT64_C(9703238076879430844), (uint64_t) UINT64_C(12564479580947296663), (uint64_t) UINT64_C(12129047596099288555), (uint64_t) UINT64_C(15705599476184120828), (uint64_t) UINT64_C(15161309495124110694), (uint64_t) UINT64_C(15020313326802763131), (uint64_t) UINT64_C(9475818434452569184), (uint64_t) UINT64_C(4776009810824339053), (uint64_t) UINT64_C(11844773043065711480), (uint64_t) UINT64_C(5970012263530423816), (uint64_t) UINT64_C(14805966303832139350), (uint64_t) UINT64_C(7462515329413029771), (uint64_t) UINT64_C(9253728939895087094), (uint64_t) UINT64_C(52386062455755702), (uint64_t) UINT64_C(11567161174868858867), (uint64_t) UINT64_C(9288854614924470436), (uint64_t) UINT64_C(14458951468586073584), (uint64_t) UINT64_C(6999382250228200141), (uint64_t) UINT64_C(18073689335732591980), (uint64_t) UINT64_C(8749227812785250177), (uint64_t) UINT64_C(11296055834832869987), (uint64_t) UINT64_C(14691639419845557168), (uint64_t) UINT64_C(14120069793541087484), (uint64_t) UINT64_C(13752863256379558556), (uint64_t) UINT64_C(17650087241926359355), (uint64_t) UINT64_C(17191079070474448196), (uint64_t) UINT64_C(11031304526203974597), (uint64_t) UINT64_C(8438581409832836170), (uint64_t) UINT64_C(13789130657754968246), (uint64_t) UINT64_C(15159912780718433117), (uint64_t) UINT64_C(17236413322193710308), (uint64_t) UINT64_C(9726518939043265588), (uint64_t) UINT64_C(10772758326371068942), (uint64_t) UINT64_C(15302446373756816800), (uint64_t) UINT64_C(13465947907963836178), (uint64_t) UINT64_C(9904685930341245193), (uint64_t) UINT64_C(16832434884954795223), (uint64_t) UINT64_C(3157485376071780683), (uint64_t) UINT64_C(10520271803096747014), (uint64_t) UINT64_C(8890957387685944783), (uint64_t) UINT64_C(13150339753870933768), (uint64_t) UINT64_C(1890324697752655170), (uint64_t) UINT64_C(16437924692338667210), (uint64_t) UINT64_C(2362905872190818963), (uint64_t) UINT64_C(10273702932711667006), (uint64_t) UINT64_C(6088502188546649756), (uint64_t) UINT64_C(12842128665889583757), (uint64_t) UINT64_C(16833999772538088003), (uint64_t) UINT64_C(16052660832361979697), (uint64_t) UINT64_C(7207441660390446292), (uint64_t) UINT64_C(10032913020226237310), (uint64_t) UINT64_C(16033866083812498692), (uint64_t) UINT64_C(12541141275282796638), (uint64_t) UINT64_C(10818960567910847557), (uint64_t) UINT64_C(15676426594103495798), (uint64_t) UINT64_C(4300328673033783639), (uint64_t) UINT64_C(9797766621314684873), (uint64_t) UINT64_C(16522763475928278486), (uint64_t) UINT64_C(12247208276643356092), (uint64_t) UINT64_C(6818396289628184396), (uint64_t) UINT64_C(15309010345804195115), (uint64_t) UINT64_C(8522995362035230495), (uint64_t) UINT64_C(9568131466127621947), (uint64_t) UINT64_C(3021029092058325107), (uint64_t) UINT64_C(11960164332659527433), (uint64_t) UINT64_C(17611344420355070096), (uint64_t) UINT64_C(14950205415824409292), (uint64_t) UINT64_C(8179122470161673908), (uint64_t) UINT64_C(9343878384890255807), (uint64_t) UINT64_C(14335323580705822000), (uint64_t) UINT64_C(11679847981112819759), (uint64_t) UINT64_C(13307468457454889596), (uint64_t) UINT64_C(14599809976391024699), (uint64_t) UINT64_C(12022649553391224092), (uint64_t) UINT64_C(18249762470488780874), (uint64_t) UINT64_C(10416625923311642211), (uint64_t) UINT64_C(11406101544055488046), (uint64_t) UINT64_C(11122077220497164286), (uint64_t) UINT64_C(14257626930069360058), (uint64_t) UINT64_C(4679224488766679549), (uint64_t) UINT64_C(17822033662586700072), (uint64_t) UINT64_C(15072402647813125244), (uint64_t) UINT64_C(11138771039116687545), (uint64_t) UINT64_C(9420251654883203278), (uint64_t) UINT64_C(13923463798895859431), (uint64_t) UINT64_C(16387000587031392001), (uint64_t) UINT64_C(17404329748619824289), (uint64_t) UINT64_C(15872064715361852097), (uint64_t) UINT64_C(10877706092887390181), (uint64_t) UINT64_C(3002511419460075705), (uint64_t) UINT64_C(13597132616109237726), (uint64_t) UINT64_C(8364825292752482535), (uint64_t) UINT64_C(16996415770136547158), (uint64_t) UINT64_C(1232659579085827361), (uint64_t) UINT64_C(10622759856335341973), (uint64_t) UINT64_C(14605470292210805812), (uint64_t) UINT64_C(13278449820419177467), (uint64_t) UINT64_C(4421779809981343554), (uint64_t) UINT64_C(16598062275523971834), (uint64_t) UINT64_C(915538744049291538), (uint64_t) UINT64_C(10373788922202482396), (uint64_t) UINT64_C(5183897733458195115), (uint64_t) UINT64_C(12967236152753102995), (uint64_t) UINT64_C(6479872166822743894), (uint64_t) UINT64_C(16209045190941378744), (uint64_t) UINT64_C(3488154190101041964), (uint64_t) UINT64_C(10130653244338361715), (uint64_t) UINT64_C(2180096368813151227), (uint64_t) UINT64_C(12663316555422952143), (uint64_t) UINT64_C(16560178516298602746), (uint64_t) UINT64_C(15829145694278690179), (uint64_t) UINT64_C(16088537126945865529), (uint64_t) UINT64_C(9893216058924181362), (uint64_t) UINT64_C(7749492695127472003), (uint64_t) UINT64_C(12366520073655226703), (uint64_t) UINT64_C(463493832054564196), (uint64_t) UINT64_C(15458150092069033378), (uint64_t) UINT64_C(14414425345350368957), (uint64_t) UINT64_C(9661343807543145861), (uint64_t) UINT64_C(13620701859271368502), (uint64_t) UINT64_C(12076679759428932327), (uint64_t) UINT64_C(3190819268807046916), (uint64_t) UINT64_C(15095849699286165408), (uint64_t) UINT64_C(17823582141290972357), (uint64_t) UINT64_C(9434906062053853380), (uint64_t) UINT64_C(11139738838306857723), (uint64_t) UINT64_C(11793632577567316725), (uint64_t) UINT64_C(13924673547883572154), (uint64_t) UINT64_C(14742040721959145907), (uint64_t) UINT64_C(3570783879572301480), (uint64_t) UINT64_C(18427550902448932383), (uint64_t) UINT64_C(18298537904747540562), (uint64_t) UINT64_C(11517219314030582739), (uint64_t) UINT64_C(18354115218108294707), (uint64_t) UINT64_C(14396524142538228424), (uint64_t) UINT64_C(18330958004207980480), (uint64_t) UINT64_C(17995655178172785531), (uint64_t) UINT64_C(4466953431550423984), (uint64_t) UINT64_C(11247284486357990957), (uint64_t) UINT64_C(486002885505321038), (uint64_t) UINT64_C(14059105607947488696), (uint64_t) UINT64_C(5219189625309039202), (uint64_t) UINT64_C(17573882009934360870), (uint64_t) UINT64_C(6523987031636299002), (uint64_t) UINT64_C(10983676256208975543), (uint64_t) UINT64_C(17912549950054850588), (uint64_t) UINT64_C(13729595320261219429), (uint64_t) UINT64_C(17779001419141175331), (uint64_t) UINT64_C(17161994150326524287), (uint64_t) UINT64_C(8388693718644305452), (uint64_t) UINT64_C(10726246343954077679), (uint64_t) UINT64_C(12160462601793772764), (uint64_t) UINT64_C(13407807929942597099), (uint64_t) UINT64_C(10588892233814828051), (uint64_t) UINT64_C(16759759912428246374), (uint64_t) UINT64_C(8624429273841147159), (uint64_t) UINT64_C(10474849945267653984), (uint64_t) UINT64_C(778582277723329070), (uint64_t) UINT64_C(13093562431584567480), (uint64_t) UINT64_C(973227847154161338), (uint64_t) UINT64_C(16366953039480709350), (uint64_t) UINT64_C(1216534808942701673), (uint64_t) UINT64_C(10229345649675443343), (uint64_t) UINT64_C(14595392310871352257), (uint64_t) UINT64_C(12786682062094304179), (uint64_t) UINT64_C(13632554370161802418), (uint64_t) UINT64_C(15983352577617880224), (uint64_t) UINT64_C(12429006944274865118), (uint64_t) UINT64_C(9989595361011175140), (uint64_t) UINT64_C(7768129340171790699), (uint64_t) UINT64_C(12486994201263968925), (uint64_t) UINT64_C(9710161675214738374), (uint64_t) UINT64_C(15608742751579961156), (uint64_t) UINT64_C(16749388112445810871), (uint64_t) UINT64_C(9755464219737475723), (uint64_t) UINT64_C(1244995533423855986), (uint64_t) UINT64_C(12194330274671844653), (uint64_t) UINT64_C(15391302472061983695), (uint64_t) UINT64_C(15242912843339805817), (uint64_t) UINT64_C(5404070034795315907), (uint64_t) UINT64_C(9526820527087378635), (uint64_t) UINT64_C(14906758817815542202), (uint64_t) UINT64_C(11908525658859223294), (uint64_t) UINT64_C(14021762503842039848), (uint64_t) UINT64_C(14885657073574029118), (uint64_t) UINT64_C(8303831092947774002), (uint64_t) UINT64_C(9303535670983768199), (uint64_t) UINT64_C(578208414664970847), (uint64_t) UINT64_C(11629419588729710248), (uint64_t) UINT64_C(14557818573613377271), (uint64_t) UINT64_C(14536774485912137810), (uint64_t) UINT64_C(18197273217016721589), (uint64_t) UINT64_C(18170968107390172263), (uint64_t) UINT64_C(13523219484416126178), (uint64_t) UINT64_C(11356855067118857664), (uint64_t) UINT64_C(15369541205401160717), (uint64_t) UINT64_C(14196068833898572081), (uint64_t) UINT64_C(765182433041899281), (uint64_t) UINT64_C(17745086042373215101), (uint64_t) UINT64_C(5568164059729762005), (uint64_t) UINT64_C(11090678776483259438), (uint64_t) UINT64_C(5785945546544795205), (uint64_t) UINT64_C(13863348470604074297), (uint64_t) UINT64_C(16455803970035769814), (uint64_t) UINT64_C(17329185588255092872), (uint64_t) UINT64_C(6734696907262548556), (uint64_t) UINT64_C(10830740992659433045), (uint64_t) UINT64_C(4209185567039092847), (uint64_t) UINT64_C(13538426240824291306), (uint64_t) UINT64_C(9873167977226253963), (uint64_t) UINT64_C(16923032801030364133), (uint64_t) UINT64_C(3118087934678041646), (uint64_t) UINT64_C(10576895500643977583), (uint64_t) UINT64_C(4254647968387469981), (uint64_t) UINT64_C(13221119375804971979), (uint64_t) UINT64_C(706623942056949572), (uint64_t) UINT64_C(16526399219756214973), (uint64_t) UINT64_C(14718337982853350677), (uint64_t) UINT64_C(10328999512347634358), (uint64_t) UINT64_C(11504804248497038125), (uint64_t) UINT64_C(12911249390434542948), (uint64_t) UINT64_C(5157633273766521849), (uint64_t) UINT64_C(16139061738043178685), (uint64_t) UINT64_C(6447041592208152311), (uint64_t) UINT64_C(10086913586276986678), (uint64_t) UINT64_C(6335244004343789146), (uint64_t) UINT64_C(12608641982846233347), (uint64_t) UINT64_C(17142427042284512241), (uint64_t) UINT64_C(15760802478557791684), (uint64_t) UINT64_C(16816347784428252397), (uint64_t) UINT64_C(9850501549098619803), (uint64_t) UINT64_C(1286845328412881940), (uint64_t) UINT64_C(12313126936373274753), (uint64_t) UINT64_C(15443614715798266137), (uint64_t) UINT64_C(15391408670466593442), (uint64_t) UINT64_C(5469460339465668959), (uint64_t) UINT64_C(9619630419041620901), (uint64_t) UINT64_C(8030098730593431003), (uint64_t) UINT64_C(12024538023802026126), (uint64_t) UINT64_C(14649309431669176658), (uint64_t) UINT64_C(15030672529752532658), (uint64_t) UINT64_C(9088264752731695015), (uint64_t) UINT64_C(9394170331095332911), (uint64_t) UINT64_C(10291851488884697288), (uint64_t) UINT64_C(11742712913869166139), (uint64_t) UINT64_C(8253128342678483706), (uint64_t) UINT64_C(14678391142336457674), (uint64_t) UINT64_C(5704724409920716729), (uint64_t) UINT64_C(18347988927920572092), (uint64_t) UINT64_C(16354277549255671720), (uint64_t) UINT64_C(11467493079950357558), (uint64_t) UINT64_C(998051431430019017), (uint64_t) UINT64_C(14334366349937946947), (uint64_t) UINT64_C(10470936326142299579), (uint64_t) UINT64_C(17917957937422433684), (uint64_t) UINT64_C(8476984389250486570), (uint64_t) UINT64_C(11198723710889021052), (uint64_t) UINT64_C(14521487280136329914), (uint64_t) UINT64_C(13998404638611276315), (uint64_t) UINT64_C(18151859100170412392), (uint64_t) UINT64_C(17498005798264095394), (uint64_t) UINT64_C(18078137856785627587), (uint64_t) UINT64_C(10936253623915059621), (uint64_t) UINT64_C(15910522178918405146), (uint64_t) UINT64_C(13670317029893824527), (uint64_t) UINT64_C(6053094668365842720), (uint64_t) UINT64_C(17087896287367280659), (uint64_t) UINT64_C(2954682317029915496), (uint64_t) UINT64_C(10679935179604550411), (uint64_t) UINT64_C(17987577512639554849), (uint64_t) UINT64_C(13349918974505688014), (uint64_t) UINT64_C(17872785872372055657), (uint64_t) UINT64_C(16687398718132110018), (uint64_t) UINT64_C(13117610303610293764), (uint64_t) UINT64_C(10429624198832568761), (uint64_t) UINT64_C(12810192458183821506), (uint64_t) UINT64_C(13037030248540710952), (uint64_t) UINT64_C(2177682517447613171), (uint64_t) UINT64_C(16296287810675888690), (uint64_t) UINT64_C(2722103146809516464), (uint64_t) UINT64_C(10185179881672430431), (uint64_t) UINT64_C(6313000485183335694), (uint64_t) UINT64_C(12731474852090538039), (uint64_t) UINT64_C(3279564588051781713), (uint64_t) UINT64_C(15914343565113172548), (uint64_t) UINT64_C(17934513790346890853), (uint64_t) UINT64_C(9946464728195732843), (uint64_t) UINT64_C(1985699082112030975), (uint64_t) UINT64_C(12433080910244666053), (uint64_t) UINT64_C(16317181907922202431), (uint64_t) UINT64_C(15541351137805832567), (uint64_t) UINT64_C(6561419329620589327), (uint64_t) UINT64_C(9713344461128645354), (uint64_t) UINT64_C(11018416108653950185), (uint64_t) UINT64_C(12141680576410806693), (uint64_t) UINT64_C(4549648098962661924), (uint64_t) UINT64_C(15177100720513508366), (uint64_t) UINT64_C(10298746142130715309), (uint64_t) UINT64_C(9485687950320942729), (uint64_t) UINT64_C(1825030320404309164), (uint64_t) UINT64_C(11857109937901178411), (uint64_t) UINT64_C(6892973918932774359), (uint64_t) UINT64_C(14821387422376473014), (uint64_t) UINT64_C(4004531380238580045), (uint64_t) UINT64_C(9263367138985295633), (uint64_t) UINT64_C(16337890167931276240), (uint64_t) UINT64_C(11579208923731619542), (uint64_t) UINT64_C(6587304654631931588), (uint64_t) UINT64_C(14474011154664524427), (uint64_t) UINT64_C(17457502855144690293), (uint64_t) UINT64_C(18092513943330655534), (uint64_t) UINT64_C(17210192550503474962), (uint64_t) UINT64_C(11307821214581659709), (uint64_t) UINT64_C(6144684325637283947), (uint64_t) UINT64_C(14134776518227074636), (uint64_t) UINT64_C(12292541425473992838), (uint64_t) UINT64_C(17668470647783843295), (uint64_t) UINT64_C(15365676781842491048), (uint64_t) UINT64_C(11042794154864902059), (uint64_t) UINT64_C(16521077016292638761), (uint64_t) UINT64_C(13803492693581127574), (uint64_t) UINT64_C(16039660251938410547), (uint64_t) UINT64_C(17254365866976409468), (uint64_t) UINT64_C(10826203278068237376), (uint64_t) UINT64_C(10783978666860255917), (uint64_t) UINT64_C(15989749085647424168), (uint64_t) UINT64_C(13479973333575319897), (uint64_t) UINT64_C(6152128301777116498), (uint64_t) UINT64_C(16849966666969149871), (uint64_t) UINT64_C(12301846395648783526), (uint64_t) UINT64_C(10531229166855718669), (uint64_t) UINT64_C(14606183024921571560), (uint64_t) UINT64_C(13164036458569648337), (uint64_t) UINT64_C(4422670725869800738), (uint64_t) UINT64_C(16455045573212060421), (uint64_t) UINT64_C(10140024425764638826), (uint64_t) UINT64_C(10284403483257537763), (uint64_t) UINT64_C(8643358275316593218), (uint64_t) UINT64_C(12855504354071922204), (uint64_t) UINT64_C(6192511825718353619), (uint64_t) UINT64_C(16069380442589902755), (uint64_t) UINT64_C(7740639782147942024), (uint64_t) UINT64_C(10043362776618689222), (uint64_t) UINT64_C(2532056854628769813), (uint64_t) UINT64_C(12554203470773361527), (uint64_t) UINT64_C(12388443105140738074), (uint64_t) UINT64_C(15692754338466701909), (uint64_t) UINT64_C(10873867862998534689), (uint64_t) UINT64_C(9807971461541688693), (uint64_t) UINT64_C(9102010423587778132), (uint64_t) UINT64_C(12259964326927110866), (uint64_t) UINT64_C(15989199047912110569), (uint64_t) UINT64_C(15324955408658888583), (uint64_t) UINT64_C(10763126773035362404), (uint64_t) UINT64_C(9578097130411805364), (uint64_t) UINT64_C(13644483260788183358), (uint64_t) UINT64_C(11972621413014756705), (uint64_t) UINT64_C(17055604075985229198), (uint64_t) UINT64_C(14965776766268445882), (uint64_t) UINT64_C(7484447039699372786), (uint64_t) UINT64_C(9353610478917778676), (uint64_t) UINT64_C(9289465418239495895), (uint64_t) UINT64_C(11692013098647223345), (uint64_t) UINT64_C(11611831772799369869), (uint64_t) UINT64_C(14615016373309029182), (uint64_t) UINT64_C(679731660717048624), (uint64_t) UINT64_C(18268770466636286477), (uint64_t) UINT64_C(10073036612751086588), (uint64_t) UINT64_C(11417981541647679048), (uint64_t) UINT64_C(8601490892183123070), (uint64_t) UINT64_C(14272476927059598810), (uint64_t) UINT64_C(10751863615228903838), (uint64_t) UINT64_C(17840596158824498513), (uint64_t) UINT64_C(4216457482181353989), (uint64_t) UINT64_C(11150372599265311570), (uint64_t) UINT64_C(14164500972431816003), (uint64_t) UINT64_C(13937965749081639463), (uint64_t) UINT64_C(8482254178684994196), (uint64_t) UINT64_C(17422457186352049329), (uint64_t) UINT64_C(5991131704928854841), (uint64_t) UINT64_C(10889035741470030830), (uint64_t) UINT64_C(15273672361649004036), (uint64_t) UINT64_C(13611294676837538538), (uint64_t) UINT64_C(9868718415206479237), (uint64_t) UINT64_C(17014118346046923173), (uint64_t) UINT64_C(3112525982153323238), (uint64_t) UINT64_C(10633823966279326983), (uint64_t) UINT64_C(4251171748059520976), (uint64_t) UINT64_C(13292279957849158729), (uint64_t) UINT64_C(702278666647013315), (uint64_t) UINT64_C(16615349947311448411), (uint64_t) UINT64_C(5489534351736154548), (uint64_t) UINT64_C(10384593717069655257), (uint64_t) UINT64_C(1125115960621402641), (uint64_t) UINT64_C(12980742146337069071), (uint64_t) UINT64_C(6018080969204141205), (uint64_t) UINT64_C(16225927682921336339), (uint64_t) UINT64_C(2910915193077788602), (uint64_t) UINT64_C(10141204801825835211), (uint64_t) UINT64_C(17960223060169475540), (uint64_t) UINT64_C(12676506002282294014), (uint64_t) UINT64_C(17838592806784456521), (uint64_t) UINT64_C(15845632502852867518), (uint64_t) UINT64_C(13074868971625794844), (uint64_t) UINT64_C(9903520314283042199), (uint64_t) UINT64_C(3560107088838733873), (uint64_t) UINT64_C(12379400392853802748), (uint64_t) UINT64_C(18285191916330581054), (uint64_t) UINT64_C(15474250491067253436), (uint64_t) UINT64_C(4409745821703674701), (uint64_t) UINT64_C(9671406556917033397), (uint64_t) UINT64_C(11979463175419572496), (uint64_t) UINT64_C(12089258196146291747), (uint64_t) UINT64_C(1139270913992301908), (uint64_t) UINT64_C(15111572745182864683), (uint64_t) UINT64_C(15259146697772541097), (uint64_t) UINT64_C(9444732965739290427), (uint64_t) UINT64_C(7231123676894144234), (uint64_t) UINT64_C(11805916207174113034), (uint64_t) UINT64_C(4427218577690292388), (uint64_t) UINT64_C(14757395258967641292), (uint64_t) UINT64_C(14757395258967641293), (uint64_t) UINT64_C(9223372036854775808), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(11529215046068469760), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(14411518807585587200), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(18014398509481984000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(11258999068426240000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(14073748835532800000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(17592186044416000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(10995116277760000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(13743895347200000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(17179869184000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(10737418240000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(13421772800000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(16777216000000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(10485760000000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(13107200000000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(16384000000000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(10240000000000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(12800000000000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(16000000000000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(10000000000000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(12500000000000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(15625000000000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(9765625000000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(12207031250000000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(15258789062500000000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(9536743164062500000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(11920928955078125000), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(14901161193847656250), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(9313225746154785156), (uint64_t) UINT64_C(4611686018427387904), (uint64_t) UINT64_C(11641532182693481445), (uint64_t) UINT64_C(5764607523034234880), (uint64_t) UINT64_C(14551915228366851806), (uint64_t) UINT64_C(11817445422220181504), (uint64_t) UINT64_C(18189894035458564758), (uint64_t) UINT64_C(5548434740920451072), (uint64_t) UINT64_C(11368683772161602973), (uint64_t) UINT64_C(17302829768357445632), (uint64_t) UINT64_C(14210854715202003717), (uint64_t) UINT64_C(7793479155164643328), (uint64_t) UINT64_C(17763568394002504646), (uint64_t) UINT64_C(14353534962383192064), (uint64_t) UINT64_C(11102230246251565404), (uint64_t) UINT64_C(4359273333062107136), (uint64_t) UINT64_C(13877787807814456755), (uint64_t) UINT64_C(5449091666327633920), (uint64_t) UINT64_C(17347234759768070944), (uint64_t) UINT64_C(2199678564482154496), (uint64_t) UINT64_C(10842021724855044340), (uint64_t) UINT64_C(1374799102801346560), (uint64_t) UINT64_C(13552527156068805425), (uint64_t) UINT64_C(1718498878501683200), (uint64_t) UINT64_C(16940658945086006781), (uint64_t) UINT64_C(6759809616554491904), (uint64_t) UINT64_C(10587911840678754238), (uint64_t) UINT64_C(6530724019560251392), (uint64_t) UINT64_C(13234889800848442797), (uint64_t) UINT64_C(17386777061305090048), (uint64_t) UINT64_C(16543612251060553497), (uint64_t) UINT64_C(7898413271349198848), (uint64_t) UINT64_C(10339757656912845935), (uint64_t) UINT64_C(16465723340661719040), (uint64_t) UINT64_C(12924697071141057419), (uint64_t) UINT64_C(15970468157399760896), (uint64_t) UINT64_C(16155871338926321774), (uint64_t) UINT64_C(15351399178322313216), (uint64_t) UINT64_C(10097419586828951109), (uint64_t) UINT64_C(4982938468024057856), (uint64_t) UINT64_C(12621774483536188886), (uint64_t) UINT64_C(10840359103457460224), (uint64_t) UINT64_C(15777218104420236108), (uint64_t) UINT64_C(4327076842467049472), (uint64_t) UINT64_C(9860761315262647567), (uint64_t) UINT64_C(11927795063396681728), (uint64_t) UINT64_C(12325951644078309459), (uint64_t) UINT64_C(10298057810818464256), (uint64_t) UINT64_C(15407439555097886824), (uint64_t) UINT64_C(8260886245095692416), (uint64_t) UINT64_C(9629649721936179265), (uint64_t) UINT64_C(5163053903184807760), (uint64_t) UINT64_C(12037062152420224081), (uint64_t) UINT64_C(11065503397408397604), (uint64_t) UINT64_C(15046327690525280101), (uint64_t) UINT64_C(18443565265187884909), (uint64_t) UINT64_C(9403954806578300063), (uint64_t) UINT64_C(13833071299956122020), (uint64_t) UINT64_C(11754943508222875079), (uint64_t) UINT64_C(12679653106517764621), (uint64_t) UINT64_C(14693679385278593849), (uint64_t) UINT64_C(11237880364719817872), (uint64_t) UINT64_C(18367099231598242312), (uint64_t) UINT64_C(212292400617608628), (uint64_t) UINT64_C(11479437019748901445), (uint64_t) UINT64_C(132682750386005392), (uint64_t) UINT64_C(14349296274686126806), (uint64_t) UINT64_C(4777539456409894645), (uint64_t) UINT64_C(17936620343357658507), (uint64_t) UINT64_C(15195296357367144114), (uint64_t) UINT64_C(11210387714598536567), (uint64_t) UINT64_C(7191217214140771119), (uint64_t) UINT64_C(14012984643248170709), (uint64_t) UINT64_C(4377335499248575995), (uint64_t) UINT64_C(17516230804060213386), (uint64_t) UINT64_C(10083355392488107898), (uint64_t) UINT64_C(10947644252537633366), (uint64_t) UINT64_C(10913783138732455340), (uint64_t) UINT64_C(13684555315672041708), (uint64_t) UINT64_C(4418856886560793367), (uint64_t) UINT64_C(17105694144590052135), (uint64_t) UINT64_C(5523571108200991709), (uint64_t) UINT64_C(10691058840368782584), (uint64_t) UINT64_C(10369760970266701674), (uint64_t) UINT64_C(13363823550460978230), (uint64_t) UINT64_C(12962201212833377092), (uint64_t) UINT64_C(16704779438076222788), (uint64_t) UINT64_C(6979379479186945558), (uint64_t) UINT64_C(10440487148797639242), (uint64_t) UINT64_C(13585484211346616781), (uint64_t) UINT64_C(13050608935997049053), (uint64_t) UINT64_C(7758483227328495169), (uint64_t) UINT64_C(16313261169996311316), (uint64_t) UINT64_C(14309790052588006865), (uint64_t) UINT64_C(10195788231247694572), (uint64_t) UINT64_C(18166990819722280098), (uint64_t) UINT64_C(12744735289059618216), (uint64_t) UINT64_C(4261994450943298507), (uint64_t) UINT64_C(15930919111324522770), (uint64_t) UINT64_C(5327493063679123134), (uint64_t) UINT64_C(9956824444577826731), (uint64_t) UINT64_C(7941369183226839863), (uint64_t) UINT64_C(12446030555722283414), (uint64_t) UINT64_C(5315025460606161924), (uint64_t) UINT64_C(15557538194652854267), (uint64_t) UINT64_C(15867153862612478214), (uint64_t) UINT64_C(9723461371658033917), (uint64_t) UINT64_C(7611128154919104931), (uint64_t) UINT64_C(12154326714572542396), (uint64_t) UINT64_C(14125596212076269068), (uint64_t) UINT64_C(15192908393215677995), (uint64_t) UINT64_C(17656995265095336336), (uint64_t) UINT64_C(9495567745759798747), (uint64_t) UINT64_C(8729779031470891258), (uint64_t) UINT64_C(11869459682199748434), (uint64_t) UINT64_C(6300537770911226168), (uint64_t) UINT64_C(14836824602749685542), (uint64_t) UINT64_C(17099044250493808518), (uint64_t) UINT64_C(9273015376718553464), (uint64_t) UINT64_C(6075216638131242420), (uint64_t) UINT64_C(11591269220898191830), (uint64_t) UINT64_C(7594020797664053025), (uint64_t) UINT64_C(14489086526122739788), (uint64_t) UINT64_C(269153960225290473), (uint64_t) UINT64_C(18111358157653424735), (uint64_t) UINT64_C(336442450281613091), (uint64_t) UINT64_C(11319598848533390459), (uint64_t) UINT64_C(7127805559067090038), (uint64_t) UINT64_C(14149498560666738074), (uint64_t) UINT64_C(4298070930406474644), (uint64_t) UINT64_C(17686873200833422592), (uint64_t) UINT64_C(14595960699862869113), (uint64_t) UINT64_C(11054295750520889120), (uint64_t) UINT64_C(9122475437414293195), (uint64_t) UINT64_C(13817869688151111400), (uint64_t) UINT64_C(11403094296767866494), (uint64_t) UINT64_C(17272337110188889250), (uint64_t) UINT64_C(14253867870959833118), (uint64_t) UINT64_C(10795210693868055781), (uint64_t) UINT64_C(13520353437777283602), (uint64_t) UINT64_C(13494013367335069727), (uint64_t) UINT64_C(3065383741939440791), (uint64_t) UINT64_C(16867516709168837158), (uint64_t) UINT64_C(17666787732706464701), (uint64_t) UINT64_C(10542197943230523224), (uint64_t) UINT64_C(6430056314514152534), (uint64_t) UINT64_C(13177747429038154030), (uint64_t) UINT64_C(8037570393142690668), (uint64_t) UINT64_C(16472184286297692538), (uint64_t) UINT64_C(823590954573587527), (uint64_t) UINT64_C(10295115178936057836), (uint64_t) UINT64_C(5126430365035880108), (uint64_t) UINT64_C(12868893973670072295), (uint64_t) UINT64_C(6408037956294850135), (uint64_t) UINT64_C(16086117467087590369), (uint64_t) UINT64_C(3398361426941174765), (uint64_t) UINT64_C(10053823416929743980), (uint64_t) UINT64_C(13653190937906703988), (uint64_t) UINT64_C(12567279271162179975), (uint64_t) UINT64_C(17066488672383379985), (uint64_t) UINT64_C(15709099088952724969), (uint64_t) UINT64_C(16721424822051837077), (uint64_t) UINT64_C(9818186930595453106), (uint64_t) UINT64_C(3533361486141316317), (uint64_t) UINT64_C(12272733663244316382), (uint64_t) UINT64_C(13640073894531421205), (uint64_t) UINT64_C(15340917079055395478), (uint64_t) UINT64_C(7826720331309500698), (uint64_t) UINT64_C(9588073174409622174), (uint64_t) UINT64_C(280014188641050032), (uint64_t) UINT64_C(11985091468012027717), (uint64_t) UINT64_C(9573389772656088348), (uint64_t) UINT64_C(14981364335015034646), (uint64_t) UINT64_C(16578423234247498339), (uint64_t) UINT64_C(9363352709384396654), (uint64_t) UINT64_C(5749828502977298558), (uint64_t) UINT64_C(11704190886730495817), (uint64_t) UINT64_C(16410657665576399005), (uint64_t) UINT64_C(14630238608413119772), (uint64_t) UINT64_C(6678264026688335045), (uint64_t) UINT64_C(18287798260516399715), (uint64_t) UINT64_C(8347830033360418806), (uint64_t) UINT64_C(11429873912822749822), (uint64_t) UINT64_C(2911550761636567802), (uint64_t) UINT64_C(14287342391028437277), (uint64_t) UINT64_C(12862810488900485560), (uint64_t) UINT64_C(17859177988785546597), (uint64_t) UINT64_C(2243455055843443238), (uint64_t) UINT64_C(11161986242990966623), (uint64_t) UINT64_C(3708002419115845976), (uint64_t) UINT64_C(13952482803738708279), (uint64_t) UINT64_C(23317005467419566), (uint64_t) UINT64_C(17440603504673385348), (uint64_t) UINT64_C(13864204312116438170), (uint64_t) UINT64_C(10900377190420865842), (uint64_t) UINT64_C(17888499731927549664), (uint64_t) UINT64_C(13625471488026082303), (uint64_t) UINT64_C(13137252628054661272), (uint64_t) UINT64_C(17031839360032602879), (uint64_t) UINT64_C(11809879766640938686), (uint64_t) UINT64_C(10644899600020376799), (uint64_t) UINT64_C(14298703881791668535), (uint64_t) UINT64_C(13306124500025470999), (uint64_t) UINT64_C(13261693833812197764), (uint64_t) UINT64_C(16632655625031838749), (uint64_t) UINT64_C(11965431273837859301), (uint64_t) UINT64_C(10395409765644899218), (uint64_t) UINT64_C(9784237555362356015), (uint64_t) UINT64_C(12994262207056124023), (uint64_t) UINT64_C(3006924907348169211), (uint64_t) UINT64_C(16242827758820155028), (uint64_t) UINT64_C(17593714189467375226), (uint64_t) UINT64_C(10151767349262596893), (uint64_t) UINT64_C(1772699331562333708), (uint64_t) UINT64_C(12689709186578246116), (uint64_t) UINT64_C(6827560182880305039), (uint64_t) UINT64_C(15862136483222807645), (uint64_t) UINT64_C(8534450228600381299), (uint64_t) UINT64_C(9913835302014254778), (uint64_t) UINT64_C(7639874402088932264), (uint64_t) UINT64_C(12392294127517818473), (uint64_t) UINT64_C(326470965756389522), (uint64_t) UINT64_C(15490367659397273091), (uint64_t) UINT64_C(5019774725622874806), (uint64_t) UINT64_C(9681479787123295682), (uint64_t) UINT64_C(831516194300602802), (uint64_t) UINT64_C(12101849733904119602), (uint64_t) UINT64_C(10262767279730529310), (uint64_t) UINT64_C(15127312167380149503), (uint64_t) UINT64_C(3605087062808385830), (uint64_t) UINT64_C(9454570104612593439), (uint64_t) UINT64_C(9170708441896323000), (uint64_t) UINT64_C(11818212630765741799), (uint64_t) UINT64_C(6851699533943015846), (uint64_t) UINT64_C(14772765788457177249), (uint64_t) UINT64_C(3952938399001381903), (uint64_t) UINT64_C(9232978617785735780), (uint64_t) UINT64_C(13999801545444333449), (uint64_t) UINT64_C(11541223272232169725), (uint64_t) UINT64_C(17499751931805416812), (uint64_t) UINT64_C(14426529090290212157), (uint64_t) UINT64_C(8039631859474607303), (uint64_t) UINT64_C(18033161362862765196), (uint64_t) UINT64_C(14661225842770647033), (uint64_t) UINT64_C(11270725851789228247), (uint64_t) UINT64_C(18386638188586430203), (uint64_t) UINT64_C(14088407314736535309), (uint64_t) UINT64_C(18371611717305649850), (uint64_t) UINT64_C(17610509143420669137), (uint64_t) UINT64_C(9129456591349898601), (uint64_t) UINT64_C(11006568214637918210), (uint64_t) UINT64_C(17235125415662156385), (uint64_t) UINT64_C(13758210268297397763), (uint64_t) UINT64_C(12320534732722919674), (uint64_t) UINT64_C(17197762835371747204), (uint64_t) UINT64_C(10788982397476261688), (uint64_t) UINT64_C(10748601772107342002), (uint64_t) UINT64_C(15966486035277439363), (uint64_t) UINT64_C(13435752215134177503), (uint64_t) UINT64_C(10734735507242023396), (uint64_t) UINT64_C(16794690268917721879), (uint64_t) UINT64_C(8806733365625141341), (uint64_t) UINT64_C(10496681418073576174), (uint64_t) UINT64_C(12421737381156795194), (uint64_t) UINT64_C(13120851772591970218), (uint64_t) UINT64_C(6303799689591218185), (uint64_t) UINT64_C(16401064715739962772), (uint64_t) UINT64_C(17103121648843798539), (uint64_t) UINT64_C(10250665447337476733), (uint64_t) UINT64_C(1466078993672598279), (uint64_t) UINT64_C(12813331809171845916), (uint64_t) UINT64_C(6444284760518135752), (uint64_t) UINT64_C(16016664761464807395), (uint64_t) UINT64_C(8055355950647669691), (uint64_t) UINT64_C(10010415475915504622), (uint64_t) UINT64_C(2728754459941099604), (uint64_t) UINT64_C(12513019344894380777), (uint64_t) UINT64_C(12634315111781150314), (uint64_t) UINT64_C(15641274181117975972), (uint64_t) UINT64_C(1957835834444274180), (uint64_t) UINT64_C(9775796363198734982), (uint64_t) UINT64_C(10447019433382447170), (uint64_t) UINT64_C(12219745453998418728), (uint64_t) UINT64_C(3835402254873283155), (uint64_t) UINT64_C(15274681817498023410), (uint64_t) UINT64_C(4794252818591603944), (uint64_t) UINT64_C(9546676135936264631), (uint64_t) UINT64_C(7608094030047140369), (uint64_t) UINT64_C(11933345169920330789), (uint64_t) UINT64_C(4898431519131537557), (uint64_t) UINT64_C(14916681462400413486), (uint64_t) UINT64_C(10734725417341809851), (uint64_t) UINT64_C(9322925914000258429), (uint64_t) UINT64_C(2097517367411243253), (uint64_t) UINT64_C(11653657392500323036), (uint64_t) UINT64_C(7233582727691441970), (uint64_t) UINT64_C(14567071740625403795), (uint64_t) UINT64_C(9041978409614302462), (uint64_t) UINT64_C(18208839675781754744), (uint64_t) UINT64_C(6690786993590490174), (uint64_t) UINT64_C(11380524797363596715), (uint64_t) UINT64_C(4181741870994056359), (uint64_t) UINT64_C(14225655996704495894), (uint64_t) UINT64_C(615491320315182544), (uint64_t) UINT64_C(17782069995880619867), (uint64_t) UINT64_C(9992736187248753989), (uint64_t) UINT64_C(11113793747425387417), (uint64_t) UINT64_C(3939617107816777291), (uint64_t) UINT64_C(13892242184281734271), (uint64_t) UINT64_C(9536207403198359517), (uint64_t) UINT64_C(17365302730352167839), (uint64_t) UINT64_C(7308573235570561493), (uint64_t) UINT64_C(10853314206470104899), (uint64_t) UINT64_C(11485387299872682789), (uint64_t) UINT64_C(13566642758087631124), (uint64_t) UINT64_C(9745048106413465582), (uint64_t) UINT64_C(16958303447609538905), (uint64_t) UINT64_C(12181310133016831978), (uint64_t) UINT64_C(10598939654755961816), (uint64_t) UINT64_C(695789805494438130), (uint64_t) UINT64_C(13248674568444952270), (uint64_t) UINT64_C(869737256868047663), (uint64_t) UINT64_C(16560843210556190337), (uint64_t) UINT64_C(10310543607939835386), (uint64_t) UINT64_C(10350527006597618960), (uint64_t) UINT64_C(17973304801030866876), (uint64_t) UINT64_C(12938158758247023701), (uint64_t) UINT64_C(4019886927579031980), (uint64_t) UINT64_C(16172698447808779626), (uint64_t) UINT64_C(9636544677901177879), (uint64_t) UINT64_C(10107936529880487266), (uint64_t) UINT64_C(10634526442115624078), (uint64_t) UINT64_C(12634920662350609083), (uint64_t) UINT64_C(4069786015789754290), (uint64_t) UINT64_C(15793650827938261354), (uint64_t) UINT64_C(475546501309804958), (uint64_t) UINT64_C(9871031767461413346), (uint64_t) UINT64_C(4908902581746016003), (uint64_t) UINT64_C(12338789709326766682), (uint64_t) UINT64_C(15359500264037295811), (uint64_t) UINT64_C(15423487136658458353), (uint64_t) UINT64_C(9976003293191843956), (uint64_t) UINT64_C(9639679460411536470), (uint64_t) UINT64_C(17764217104313372233), (uint64_t) UINT64_C(12049599325514420588), (uint64_t) UINT64_C(12981899343536939483), (uint64_t) UINT64_C(15061999156893025735), (uint64_t) UINT64_C(16227374179421174354), (uint64_t) UINT64_C(9413749473058141084), (uint64_t) UINT64_C(17059637889779315827), (uint64_t) UINT64_C(11767186841322676356), (uint64_t) UINT64_C(2877803288514593168), (uint64_t) UINT64_C(14708983551653345445), (uint64_t) UINT64_C(3597254110643241460), (uint64_t) UINT64_C(18386229439566681806), (uint64_t) UINT64_C(9108253656731439729), (uint64_t) UINT64_C(11491393399729176129), (uint64_t) UINT64_C(1080972517029761926), (uint64_t) UINT64_C(14364241749661470161), (uint64_t) UINT64_C(5962901664714590312), (uint64_t) UINT64_C(17955302187076837701), (uint64_t) UINT64_C(12065313099320625794), (uint64_t) UINT64_C(11222063866923023563), (uint64_t) UINT64_C(9846663696289085073), (uint64_t) UINT64_C(14027579833653779454), (uint64_t) UINT64_C(7696643601933968437), (uint64_t) UINT64_C(17534474792067224318), (uint64_t) UINT64_C(397432465562684739), (uint64_t) UINT64_C(10959046745042015198), (uint64_t) UINT64_C(14083453346258841674), (uint64_t) UINT64_C(13698808431302518998), (uint64_t) UINT64_C(8380944645968776284), (uint64_t) UINT64_C(17123510539128148748), (uint64_t) UINT64_C(1252808770606194547), (uint64_t) UINT64_C(10702194086955092967), (uint64_t) UINT64_C(10006377518483647400), (uint64_t) UINT64_C(13377742608693866209), (uint64_t) UINT64_C(7896285879677171346), (uint64_t) UINT64_C(16722178260867332761), (uint64_t) UINT64_C(14482043368023852087), (uint64_t) UINT64_C(10451361413042082976), (uint64_t) UINT64_C(2133748077373825698), (uint64_t) UINT64_C(13064201766302603720), (uint64_t) UINT64_C(2667185096717282123), (uint64_t) UINT64_C(16330252207878254650), (uint64_t) UINT64_C(3333981370896602653), (uint64_t) UINT64_C(10206407629923909156), (uint64_t) UINT64_C(6695424375237764562), (uint64_t) UINT64_C(12758009537404886445), (uint64_t) UINT64_C(8369280469047205703), (uint64_t) UINT64_C(15947511921756108056), (uint64_t) UINT64_C(15073286604736395033), (uint64_t) UINT64_C(9967194951097567535), (uint64_t) UINT64_C(9420804127960246895), (uint64_t) UINT64_C(12458993688871959419), (uint64_t) UINT64_C(7164319141522920715), (uint64_t) UINT64_C(15573742111089949274), (uint64_t) UINT64_C(4343712908476262990), (uint64_t) UINT64_C(9733588819431218296), (uint64_t) UINT64_C(7326506586225052273), (uint64_t) UINT64_C(12166986024289022870), (uint64_t) UINT64_C(9158133232781315341), (uint64_t) UINT64_C(15208732530361278588), (uint64_t) UINT64_C(2224294504121868368), (uint64_t) UINT64_C(9505457831475799117), (uint64_t) UINT64_C(10613556101930943538), (uint64_t) UINT64_C(11881822289344748896), (uint64_t) UINT64_C(17878631145841067327), (uint64_t) UINT64_C(14852277861680936121), (uint64_t) UINT64_C(3901544858591782542), (uint64_t) UINT64_C(9282673663550585075), (uint64_t) UINT64_C(13967680582688333849), (uint64_t) UINT64_C(11603342079438231344), (uint64_t) UINT64_C(12847914709933029407), (uint64_t) UINT64_C(14504177599297789180), (uint64_t) UINT64_C(16059893387416286759), (uint64_t) UINT64_C(18130221999122236476), (uint64_t) UINT64_C(1628122660560806833), (uint64_t) UINT64_C(11331388749451397797), (uint64_t) UINT64_C(10240948699705280078), (uint64_t) UINT64_C(14164235936814247246), (uint64_t) UINT64_C(17412871893058988002), (uint64_t) UINT64_C(17705294921017809058), (uint64_t) UINT64_C(12542717829468959195), (uint64_t) UINT64_C(11065809325636130661), (uint64_t) UINT64_C(12450884661845487401), (uint64_t) UINT64_C(13832261657045163327), (uint64_t) UINT64_C(1728547772024695539), (uint64_t) UINT64_C(17290327071306454158), (uint64_t) UINT64_C(15995742770313033136), (uint64_t) UINT64_C(10806454419566533849), (uint64_t) UINT64_C(5385653213018257806), (uint64_t) UINT64_C(13508068024458167311), (uint64_t) UINT64_C(11343752534700210161), (uint64_t) UINT64_C(16885085030572709139), (uint64_t) UINT64_C(9568004649947874797), (uint64_t) UINT64_C(10553178144107943212), (uint64_t) UINT64_C(3674159897003727796), (uint64_t) UINT64_C(13191472680134929015), (uint64_t) UINT64_C(4592699871254659745), (uint64_t) UINT64_C(16489340850168661269), (uint64_t) UINT64_C(1129188820640936778), (uint64_t) UINT64_C(10305838031355413293), (uint64_t) UINT64_C(3011586022114279438), (uint64_t) UINT64_C(12882297539194266616), (uint64_t) UINT64_C(8376168546070237202), (uint64_t) UINT64_C(16102871923992833270), (uint64_t) UINT64_C(10470210682587796502), (uint64_t) UINT64_C(10064294952495520794), (uint64_t) UINT64_C(1932195658189984910), (uint64_t) UINT64_C(12580368690619400992), (uint64_t) UINT64_C(11638616609592256945), (uint64_t) UINT64_C(15725460863274251240), (uint64_t) UINT64_C(14548270761990321182), (uint64_t) UINT64_C(9828413039546407025), (uint64_t) UINT64_C(9092669226243950738), (uint64_t) UINT64_C(12285516299433008781), (uint64_t) UINT64_C(15977522551232326327), (uint64_t) UINT64_C(15356895374291260977), (uint64_t) UINT64_C(6136845133758244197), (uint64_t) UINT64_C(9598059608932038110), (uint64_t) UINT64_C(15364743254667372383), (uint64_t) UINT64_C(11997574511165047638), (uint64_t) UINT64_C(9982557031479439671), (uint64_t) UINT64_C(14996968138956309548), (uint64_t) UINT64_C(3254824252494523781), (uint64_t) UINT64_C(9373105086847693467), (uint64_t) UINT64_C(11257637194663853171), (uint64_t) UINT64_C(11716381358559616834), (uint64_t) UINT64_C(9460360474902428559), (uint64_t) UINT64_C(14645476698199521043), (uint64_t) UINT64_C(2602078556773259891), (uint64_t) UINT64_C(18306845872749401303), (uint64_t) UINT64_C(17087656251248738576), (uint64_t) UINT64_C(11441778670468375814), (uint64_t) UINT64_C(17597314184671543466), (uint64_t) UINT64_C(14302223338085469768), (uint64_t) UINT64_C(12773270693984653525), (uint64_t) UINT64_C(17877779172606837210), (uint64_t) UINT64_C(15966588367480816906), (uint64_t) UINT64_C(11173611982879273256), (uint64_t) UINT64_C(14590803748102898470), (uint64_t) UINT64_C(13967014978599091570), (uint64_t) UINT64_C(18238504685128623088), (uint64_t) UINT64_C(17458768723248864463), (uint64_t) UINT64_C(13574758819556003052), (uint64_t) UINT64_C(10911730452030540289), (uint64_t) UINT64_C(15401753289863583763), (uint64_t) UINT64_C(13639663065038175362), (uint64_t) UINT64_C(5417133557047315992), (uint64_t) UINT64_C(17049578831297719202), (uint64_t) UINT64_C(15994788983163920798), (uint64_t) UINT64_C(10655986769561074501), (uint64_t) UINT64_C(14608429132904838403), (uint64_t) UINT64_C(13319983461951343127), (uint64_t) UINT64_C(4425478360848884291), (uint64_t) UINT64_C(16649979327439178909), (uint64_t) UINT64_C(920161932633717460), (uint64_t) UINT64_C(10406237079649486818), (uint64_t) UINT64_C(2880944217109767365), (uint64_t) UINT64_C(13007796349561858522), (uint64_t) UINT64_C(12824552308241985014), (uint64_t) UINT64_C(16259745436952323153), (uint64_t) UINT64_C(6807318348447705459), (uint64_t) UINT64_C(10162340898095201970), (uint64_t) UINT64_C(15783789013848285672), (uint64_t) UINT64_C(12702926122619002463), (uint64_t) UINT64_C(10506364230455581282), (uint64_t) UINT64_C(15878657653273753079), (uint64_t) UINT64_C(8521269269642088699), (uint64_t) UINT64_C(9924161033296095674), (uint64_t) UINT64_C(12243322321167387293), (uint64_t) UINT64_C(12405201291620119593), (uint64_t) UINT64_C(6080780864604458308), (uint64_t) UINT64_C(15506501614525149491), (uint64_t) UINT64_C(12212662099182960789), (uint64_t) UINT64_C(9691563509078218432), (uint64_t) UINT64_C(5327070802775656541), (uint64_t) UINT64_C(12114454386347773040), (uint64_t) UINT64_C(6658838503469570676), (uint64_t) UINT64_C(15143067982934716300), (uint64_t) UINT64_C(8323548129336963345), (uint64_t) UINT64_C(9464417489334197687), (uint64_t) UINT64_C(14425589617690377899), (uint64_t) UINT64_C(11830521861667747109), (uint64_t) UINT64_C(13420301003685584469), (uint64_t) UINT64_C(14788152327084683887), (uint64_t) UINT64_C(2940318199324816875), (uint64_t) UINT64_C(9242595204427927429), (uint64_t) UINT64_C(8755227902219092403), (uint64_t) UINT64_C(11553244005534909286), (uint64_t) UINT64_C(15555720896201253407), (uint64_t) UINT64_C(14441555006918636608), (uint64_t) UINT64_C(10221279083396790951), (uint64_t) UINT64_C(18051943758648295760), (uint64_t) UINT64_C(12776598854245988689), (uint64_t) UINT64_C(11282464849155184850), (uint64_t) UINT64_C(7985374283903742931), (uint64_t) UINT64_C(14103081061443981063), (uint64_t) UINT64_C(758345818024902856), (uint64_t) UINT64_C(17628851326804976328), (uint64_t) UINT64_C(14782990327813292282), (uint64_t) UINT64_C(11018032079253110205), (uint64_t) UINT64_C(9239368954883307676), (uint64_t) UINT64_C(13772540099066387756), (uint64_t) UINT64_C(16160897212031522499), (uint64_t) UINT64_C(17215675123832984696), (uint64_t) UINT64_C(1754377441329851508), (uint64_t) UINT64_C(10759796952395615435), (uint64_t) UINT64_C(1096485900831157192), (uint64_t) UINT64_C(13449746190494519293), (uint64_t) UINT64_C(15205665431321110202), (uint64_t) UINT64_C(16812182738118149117), (uint64_t) UINT64_C(5172023733869224041), (uint64_t) UINT64_C(10507614211323843198), (uint64_t) UINT64_C(5538357842881958977), (uint64_t) UINT64_C(13134517764154803997), (uint64_t) UINT64_C(16146319340457224530), (uint64_t) UINT64_C(16418147205193504997), (uint64_t) UINT64_C(6347841120289366950), (uint64_t) UINT64_C(10261342003245940623), (uint64_t) UINT64_C(6273243709394548296) }
};
const vader_array_t vader_data_0 = { { 13u, 0u, 0u, 0u, NULL }, 1302u, 1302u, 0u, (vader_array_buf_t*) &vader_data_0_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint64_t slots[342]; } vader_data_1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 342u, 342u, 170u, 4u, { 0u, 0u, 0u },
    { (uint64_t) UINT64_C(1), (uint64_t) UINT64_C(11068046444225730970), (uint64_t) UINT64_C(5165088340638674453), (uint64_t) UINT64_C(7821419487252849886), (uint64_t) UINT64_C(8824922364862649494), (uint64_t) UINT64_C(7059937891890119595), (uint64_t) UINT64_C(13026647942995916322), (uint64_t) UINT64_C(9774590264567735146), (uint64_t) UINT64_C(11509021026396098440), (uint64_t) UINT64_C(16585914450600699399), (uint64_t) UINT64_C(15469416676735388068), (uint64_t) UINT64_C(16064882156130220778), (uint64_t) UINT64_C(9162556910162266299), (uint64_t) UINT64_C(7281393426775805432), (uint64_t) UINT64_C(16893161185646375315), (uint64_t) UINT64_C(2446482504291369283), (uint64_t) UINT64_C(7603720821608101175), (uint64_t) UINT64_C(2393627842544570617), (uint64_t) UINT64_C(16672297533003297786), (uint64_t) UINT64_C(11918280793837635165), (uint64_t) UINT64_C(5845275820328197809), (uint64_t) UINT64_C(15744267100488289217), (uint64_t) UINT64_C(3054734472329800808), (uint64_t) UINT64_C(17201182836831481939), (uint64_t) UINT64_C(6382248639981364905), (uint64_t) UINT64_C(2832900194486363201), (uint64_t) UINT64_C(5955668970331000884), (uint64_t) UINT64_C(1075186361522890384), (uint64_t) UINT64_C(12788344622662355584), (uint64_t) UINT64_C(13920024512871794791), (uint64_t) UINT64_C(3757321980813615186), (uint64_t) UINT64_C(10384555214134712795), (uint64_t) UINT64_C(5547241898389809503), (uint64_t) UINT64_C(4437793518711847602), (uint64_t) UINT64_C(10928932444453298728), (uint64_t) UINT64_C(17486291911125277965), (uint64_t) UINT64_C(6610335899416401726), (uint64_t) UINT64_C(12666966349016942027), (uint64_t) UINT64_C(12888448528943286597), (uint64_t) UINT64_C(17689456452638449924), (uint64_t) UINT64_C(14151565162110759939), (uint64_t) UINT64_C(7885109000409574610), (uint64_t) UINT64_C(9997436015069570011), (uint64_t) UINT64_C(7997948812055656009), (uint64_t) UINT64_C(12796718099289049614), (uint64_t) UINT64_C(2858676849947419045), (uint64_t) UINT64_C(13354987924183666206), (uint64_t) UINT64_C(17678631863951955605), (uint64_t) UINT64_C(3074859046935833515), (uint64_t) UINT64_C(13527933681774397782), (uint64_t) UINT64_C(10576647446613305481), (uint64_t) UINT64_C(15840015586774465031), (uint64_t) UINT64_C(8982663654677661702), (uint64_t) UINT64_C(18061610662226169046), (uint64_t) UINT64_C(10759939715039024913), (uint64_t) UINT64_C(12297300586773130254), (uint64_t) UINT64_C(15986332124095098083), (uint64_t) UINT64_C(9099716884534168143), (uint64_t) UINT64_C(14658471137111155161), (uint64_t) UINT64_C(4348079280205103483), (uint64_t) UINT64_C(14335624477811986218), (uint64_t) UINT64_C(7779150767507678651), (uint64_t) UINT64_C(2533971799264232598), (uint64_t) UINT64_C(15122401323048503126), (uint64_t) UINT64_C(12097921058438802501), (uint64_t) UINT64_C(5988988032009131678), (uint64_t) UINT64_C(16961078480698431330), (uint64_t) UINT64_C(13568862784558745064), (uint64_t) UINT64_C(7165741412905085728), (uint64_t) UINT64_C(11465186260648137165), (uint64_t) UINT64_C(16550846638002330379), (uint64_t) UINT64_C(16930026125143774626), (uint64_t) UINT64_C(4951948911778577463), (uint64_t) UINT64_C(272210314680951647), (uint64_t) UINT64_C(3907117066486671641), (uint64_t) UINT64_C(6251387306378674625), (uint64_t) UINT64_C(16069156289328670670), (uint64_t) UINT64_C(9165976216721026213), (uint64_t) UINT64_C(7286864317269821294), (uint64_t) UINT64_C(16897537898041588005), (uint64_t) UINT64_C(13518030318433270404), (uint64_t) UINT64_C(6871453250525591353), (uint64_t) UINT64_C(9186511415162383406), (uint64_t) UINT64_C(11038557946871817048), (uint64_t) UINT64_C(10282995085511086630), (uint64_t) UINT64_C(8226396068408869304), (uint64_t) UINT64_C(13959814484210916090), (uint64_t) UINT64_C(11267656730511734774), (uint64_t) UINT64_C(5324776569667477496), (uint64_t) UINT64_C(7949170070475892320), (uint64_t) UINT64_C(17427382500606444826), (uint64_t) UINT64_C(5747719112518849781), (uint64_t) UINT64_C(15666221734240810795), (uint64_t) UINT64_C(12532977387392648636), (uint64_t) UINT64_C(5295368560860596524), (uint64_t) UINT64_C(4236294848688477220), (uint64_t) UINT64_C(7078384693692692099), (uint64_t) UINT64_C(11325415509908307358), (uint64_t) UINT64_C(9060332407926645887), (uint64_t) UINT64_C(14626963555825137356), (uint64_t) UINT64_C(12335095245094488799), (uint64_t) UINT64_C(9868076196075591040), (uint64_t) UINT64_C(15273158586344293478), (uint64_t) UINT64_C(13369007293925138595), (uint64_t) UINT64_C(7005857020398200553), (uint64_t) UINT64_C(16672732060544291412), (uint64_t) UINT64_C(11918976037903224966), (uint64_t) UINT64_C(5845832015580669650), (uint64_t) UINT64_C(12055363241948356366), (uint64_t) UINT64_C(841837113407818570), (uint64_t) UINT64_C(4362818505468165179), (uint64_t) UINT64_C(14558301248600263113), (uint64_t) UINT64_C(12225235553534690011), (uint64_t) UINT64_C(2401490813343931363), (uint64_t) UINT64_C(1921192650675145090), (uint64_t) UINT64_C(17831303500047873437), (uint64_t) UINT64_C(6886345170554478103), (uint64_t) UINT64_C(1819727321701672159), (uint64_t) UINT64_C(16213177116328979020), (uint64_t) UINT64_C(14873036941900635463), (uint64_t) UINT64_C(15587778368262418694), (uint64_t) UINT64_C(8780873879868024632), (uint64_t) UINT64_C(2981351763563108441), (uint64_t) UINT64_C(13453127855076217722), (uint64_t) UINT64_C(7073153469319063855), (uint64_t) UINT64_C(11317045550910502167), (uint64_t) UINT64_C(12742985255470312057), (uint64_t) UINT64_C(10194388204376249646), (uint64_t) UINT64_C(1553625868034358140), (uint64_t) UINT64_C(8621598323911307159), (uint64_t) UINT64_C(17965325103354776697), (uint64_t) UINT64_C(13987124906400001422), (uint64_t) UINT64_C(121653480894270168), (uint64_t) UINT64_C(97322784715416134), (uint64_t) UINT64_C(14913111714512307107), (uint64_t) UINT64_C(8241140556867935363), (uint64_t) UINT64_C(17660958889720079260), (uint64_t) UINT64_C(17189487779326395846), (uint64_t) UINT64_C(13751590223461116677), (uint64_t) UINT64_C(18379969808252713988), (uint64_t) UINT64_C(14650556434236701088), (uint64_t) UINT64_C(652398703163629901), (uint64_t) UINT64_C(11589965406756634890), (uint64_t) UINT64_C(7475898206584884855), (uint64_t) UINT64_C(2291369750525997561), (uint64_t) UINT64_C(9211793429904618695), (uint64_t) UINT64_C(18428218302589300235), (uint64_t) UINT64_C(7363877012587619542), (uint64_t) UINT64_C(13269799239553916280), (uint64_t) UINT64_C(10615839391643133024), (uint64_t) UINT64_C(2227947767661371545), (uint64_t) UINT64_C(16539753473096738529), (uint64_t) UINT64_C(13231802778477390823), (uint64_t) UINT64_C(6413489186596184024), (uint64_t) UINT64_C(16198837793502678189), (uint64_t) UINT64_C(5580372605318321905), (uint64_t) UINT64_C(8928596168509315048), (uint64_t) UINT64_C(18210923379033183008), (uint64_t) UINT64_C(7190041073742725760), (uint64_t) UINT64_C(436019273762630246), (uint64_t) UINT64_C(7727513048493924843), (uint64_t) UINT64_C(9871359253537050198), (uint64_t) UINT64_C(4726128361433549347), (uint64_t) UINT64_C(7470251503888749801), (uint64_t) UINT64_C(13354898832594820487), (uint64_t) UINT64_C(13989140502667892133), (uint64_t) UINT64_C(14880661216876224029), (uint64_t) UINT64_C(11904528973500979224), (uint64_t) UINT64_C(4289851098633925465), (uint64_t) UINT64_C(18189276137874781665), (uint64_t) UINT64_C(3483374466074094362), (uint64_t) UINT64_C(1884050330976640656), (uint64_t) UINT64_C(5196589079523222848), (uint64_t) UINT64_C(15225317707844309248), (uint64_t) UINT64_C(5913764258841343181), (uint64_t) UINT64_C(8420360221814984868), (uint64_t) UINT64_C(17804334621677718864), (uint64_t) UINT64_C(17932816512084085415), (uint64_t) UINT64_C(10245762345624985047), (uint64_t) UINT64_C(4507261061758077715), (uint64_t) UINT64_C(7295157664148372495), (uint64_t) UINT64_C(7982903447895485668), (uint64_t) UINT64_C(10075671573058298858), (uint64_t) UINT64_C(4371188443704728763), (uint64_t) UINT64_C(14372599139411386667), (uint64_t) UINT64_C(15187428126271019657), (uint64_t) UINT64_C(15839291315758726049), (uint64_t) UINT64_C(3206773216762499739), (uint64_t) UINT64_C(13633465017635730761), (uint64_t) UINT64_C(14596120828850494932), (uint64_t) UINT64_C(4907049252451240275), (uint64_t) UINT64_C(236290587219081897), (uint64_t) UINT64_C(14946427728742906810), (uint64_t) UINT64_C(16535586736504830250), (uint64_t) UINT64_C(5849771759720043554), (uint64_t) UINT64_C(15747863852001765813), (uint64_t) UINT64_C(10439186904235184007), (uint64_t) UINT64_C(15730047152871967852), (uint64_t) UINT64_C(12584037722297574282), (uint64_t) UINT64_C(9066413911450387881), (uint64_t) UINT64_C(10942479943902220628), (uint64_t) UINT64_C(8753983955121776503), (uint64_t) UINT64_C(10317025513452932081), (uint64_t) UINT64_C(874922781278525018), (uint64_t) UINT64_C(8078635854506640661), (uint64_t) UINT64_C(13841606313089133175), (uint64_t) UINT64_C(14767872471458792434), (uint64_t) UINT64_C(746251532941302978), (uint64_t) UINT64_C(597001226353042382), (uint64_t) UINT64_C(15712597221132509104), (uint64_t) UINT64_C(8880728962164096960), (uint64_t) UINT64_C(10793931984473187891), (uint64_t) UINT64_C(17270291175157100626), (uint64_t) UINT64_C(2748186495899949531), (uint64_t) UINT64_C(2198549196719959625), (uint64_t) UINT64_C(18275073973719576693), (uint64_t) UINT64_C(10930710364233751031), (uint64_t) UINT64_C(12433917106128911148), (uint64_t) UINT64_C(8826220925580526867), (uint64_t) UINT64_C(7060976740464421494), (uint64_t) UINT64_C(16716827836597268165), (uint64_t) UINT64_C(11989529279587987770), (uint64_t) UINT64_C(9591623423670390216), (uint64_t) UINT64_C(15051996368420132820), (uint64_t) UINT64_C(13015147745246481542), (uint64_t) UINT64_C(3033420566713364587), (uint64_t) UINT64_C(6116085268112601993), (uint64_t) UINT64_C(9785736428980163188), (uint64_t) UINT64_C(15207286772667951197), (uint64_t) UINT64_C(1097782973908629988), (uint64_t) UINT64_C(1756452758253807981), (uint64_t) UINT64_C(5094511021344956708), (uint64_t) UINT64_C(4075608817075965366), (uint64_t) UINT64_C(6520974107321544586), (uint64_t) UINT64_C(1527430471115325346), (uint64_t) UINT64_C(12289990821117991246), (uint64_t) UINT64_C(17210690286378213644), (uint64_t) UINT64_C(9090360384495590213), (uint64_t) UINT64_C(18340334751822203140), (uint64_t) UINT64_C(14672267801457762512), (uint64_t) UINT64_C(16096930852848599373), (uint64_t) UINT64_C(1809498238053148529), (uint64_t) UINT64_C(12515645034668249793), (uint64_t) UINT64_C(1578287981759648052), (uint64_t) UINT64_C(12330676829633449412), (uint64_t) UINT64_C(13553890278448669853), (uint64_t) UINT64_C(3239480371808320148), (uint64_t) UINT64_C(17348979556414297411), (uint64_t) UINT64_C(6500486015647617283), (uint64_t) UINT64_C(10400777625036187652), (uint64_t) UINT64_C(15699319729512770768), (uint64_t) UINT64_C(16248804598352126938), (uint64_t) UINT64_C(7551343283653851484), (uint64_t) UINT64_C(6041074626923081187), (uint64_t) UINT64_C(12211557331022285596), (uint64_t) UINT64_C(1091747655926105338), (uint64_t) UINT64_C(4562746939482794594), (uint64_t) UINT64_C(7339546366328145998), (uint64_t) UINT64_C(8053925371383123274), (uint64_t) UINT64_C(6443140297106498619), (uint64_t) UINT64_C(12533209867169019542), (uint64_t) UINT64_C(5295740528502789974), (uint64_t) UINT64_C(15304638867027962949), (uint64_t) UINT64_C(4865013464138549713), (uint64_t) UINT64_C(14960057215536570740), (uint64_t) UINT64_C(9178696285890871890), (uint64_t) UINT64_C(14721654658196518159), (uint64_t) UINT64_C(4398626097073393881), (uint64_t) UINT64_C(7037801755317430209), (uint64_t) UINT64_C(5630241404253944167), (uint64_t) UINT64_C(814844308661245011), (uint64_t) UINT64_C(1303750893857992017), (uint64_t) UINT64_C(15800395974054034906), (uint64_t) UINT64_C(5261619149759407279), (uint64_t) UINT64_C(12107939454356961969), (uint64_t) UINT64_C(5997002748743659252), (uint64_t) UINT64_C(8486951013736837725), (uint64_t) UINT64_C(2511075177753209390), (uint64_t) UINT64_C(13076906586428298482), (uint64_t) UINT64_C(14150874083884549109), (uint64_t) UINT64_C(4194654460505726958), (uint64_t) UINT64_C(18113118827372222859), (uint64_t) UINT64_C(3422448617672047318), (uint64_t) UINT64_C(16543964232501006678), (uint64_t) UINT64_C(9545822571258895019), (uint64_t) UINT64_C(15015355686490936662), (uint64_t) UINT64_C(5577825024675947042), (uint64_t) UINT64_C(11840957649224578280), (uint64_t) UINT64_C(16851463748863483271), (uint64_t) UINT64_C(12204946739213931940), (uint64_t) UINT64_C(13453306206113055875), (uint64_t) UINT64_C(3383947335406624054), (uint64_t) UINT64_C(16482362180876329456), (uint64_t) UINT64_C(9496540929959153242), (uint64_t) UINT64_C(11286581558709232917), (uint64_t) UINT64_C(5339916432225476010), (uint64_t) UINT64_C(4854517476818851293), (uint64_t) UINT64_C(3883613981455081034), (uint64_t) UINT64_C(14174937629389795797), (uint64_t) UINT64_C(11611853762797942306), (uint64_t) UINT64_C(5600134195496443521), (uint64_t) UINT64_C(15548153800622885787), (uint64_t) UINT64_C(6430302007287065643), (uint64_t) UINT64_C(16212288050055383484), (uint64_t) UINT64_C(12969830440044306787), (uint64_t) UINT64_C(9683682259845159889), (uint64_t) UINT64_C(15125643437359948558), (uint64_t) UINT64_C(8411165935146048523), (uint64_t) UINT64_C(17147214310975587960), (uint64_t) UINT64_C(10028422634038560045), (uint64_t) UINT64_C(8022738107230848036), (uint64_t) UINT64_C(9147032156827446534), (uint64_t) UINT64_C(11006974540203867551), (uint64_t) UINT64_C(5116230817421183718), (uint64_t) UINT64_C(15564666937357714594), (uint64_t) UINT64_C(1383687105660440706), (uint64_t) UINT64_C(12174996128754083534), (uint64_t) UINT64_C(8411947361780802685), (uint64_t) UINT64_C(6729557889424642148), (uint64_t) UINT64_C(5383646311539713719), (uint64_t) UINT64_C(1235136468979721303), (uint64_t) UINT64_C(15745504434151418335), (uint64_t) UINT64_C(16285752362063044992), (uint64_t) UINT64_C(5649904260166615347), (uint64_t) UINT64_C(5350498001524674232), (uint64_t) UINT64_C(591049586477829062), (uint64_t) UINT64_C(11540886113407994219), (uint64_t) UINT64_C(18673707743239135), (uint64_t) UINT64_C(14772334225162232601), (uint64_t) UINT64_C(8128518565387875758), (uint64_t) UINT64_C(1937583260394870242), (uint64_t) UINT64_C(8928764237799716840), (uint64_t) UINT64_C(14521709019723594119), (uint64_t) UINT64_C(8477339172590109297), (uint64_t) UINT64_C(17849917782297818407), (uint64_t) UINT64_C(6901236596354434079), (uint64_t) UINT64_C(18420676183650915173), (uint64_t) UINT64_C(3668494502695001169), (uint64_t) UINT64_C(10313493231639821582), (uint64_t) UINT64_C(9122891541139893884), (uint64_t) UINT64_C(14677010862395735754), (uint64_t) UINT64_C(673562245690857633) }
};
const vader_array_t vader_data_1 = { { 13u, 0u, 0u, 0u, NULL }, 342u, 342u, 0u, (vader_array_buf_t*) &vader_data_1_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint64_t slots[342]; } vader_data_2_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 342u, 342u, 170u, 4u, { 0u, 0u, 0u },
    { (uint64_t) UINT64_C(2305843009213693952), (uint64_t) UINT64_C(1844674407370955161), (uint64_t) UINT64_C(1475739525896764129), (uint64_t) UINT64_C(1180591620717411303), (uint64_t) UINT64_C(1888946593147858085), (uint64_t) UINT64_C(1511157274518286468), (uint64_t) UINT64_C(1208925819614629174), (uint64_t) UINT64_C(1934281311383406679), (uint64_t) UINT64_C(1547425049106725343), (uint64_t) UINT64_C(1237940039285380274), (uint64_t) UINT64_C(1980704062856608439), (uint64_t) UINT64_C(1584563250285286751), (uint64_t) UINT64_C(1267650600228229401), (uint64_t) UINT64_C(2028240960365167042), (uint64_t) UINT64_C(1622592768292133633), (uint64_t) UINT64_C(1298074214633706907), (uint64_t) UINT64_C(2076918743413931051), (uint64_t) UINT64_C(1661534994731144841), (uint64_t) UINT64_C(1329227995784915872), (uint64_t) UINT64_C(2126764793255865396), (uint64_t) UINT64_C(1701411834604692317), (uint64_t) UINT64_C(1361129467683753853), (uint64_t) UINT64_C(2177807148294006166), (uint64_t) UINT64_C(1742245718635204932), (uint64_t) UINT64_C(1393796574908163946), (uint64_t) UINT64_C(2230074519853062314), (uint64_t) UINT64_C(1784059615882449851), (uint64_t) UINT64_C(1427247692705959881), (uint64_t) UINT64_C(2283596308329535809), (uint64_t) UINT64_C(1826877046663628647), (uint64_t) UINT64_C(1461501637330902918), (uint64_t) UINT64_C(1169201309864722334), (uint64_t) UINT64_C(1870722095783555735), (uint64_t) UINT64_C(1496577676626844588), (uint64_t) UINT64_C(1197262141301475670), (uint64_t) UINT64_C(1915619426082361072), (uint64_t) UINT64_C(1532495540865888858), (uint64_t) UINT64_C(1225996432692711086), (uint64_t) UINT64_C(1961594292308337738), (uint64_t) UINT64_C(1569275433846670190), (uint64_t) UINT64_C(1255420347077336152), (uint64_t) UINT64_C(2008672555323737844), (uint64_t) UINT64_C(1606938044258990275), (uint64_t) UINT64_C(1285550435407192220), (uint64_t) UINT64_C(2056880696651507552), (uint64_t) UINT64_C(1645504557321206042), (uint64_t) UINT64_C(1316403645856964833), (uint64_t) UINT64_C(2106245833371143733), (uint64_t) UINT64_C(1684996666696914987), (uint64_t) UINT64_C(1347997333357531989), (uint64_t) UINT64_C(2156795733372051183), (uint64_t) UINT64_C(1725436586697640946), (uint64_t) UINT64_C(1380349269358112757), (uint64_t) UINT64_C(2208558830972980411), (uint64_t) UINT64_C(1766847064778384329), (uint64_t) UINT64_C(1413477651822707463), (uint64_t) UINT64_C(2261564242916331941), (uint64_t) UINT64_C(1809251394333065553), (uint64_t) UINT64_C(1447401115466452442), (uint64_t) UINT64_C(1157920892373161954), (uint64_t) UINT64_C(1852673427797059126), (uint64_t) UINT64_C(1482138742237647301), (uint64_t) UINT64_C(1185710993790117841), (uint64_t) UINT64_C(1897137590064188545), (uint64_t) UINT64_C(1517710072051350836), (uint64_t) UINT64_C(1214168057641080669), (uint64_t) UINT64_C(1942668892225729070), (uint64_t) UINT64_C(1554135113780583256), (uint64_t) UINT64_C(1243308091024466605), (uint64_t) UINT64_C(1989292945639146568), (uint64_t) UINT64_C(1591434356511317254), (uint64_t) UINT64_C(1273147485209053803), (uint64_t) UINT64_C(2037035976334486086), (uint64_t) UINT64_C(1629628781067588869), (uint64_t) UINT64_C(1303703024854071095), (uint64_t) UINT64_C(2085924839766513752), (uint64_t) UINT64_C(1668739871813211001), (uint64_t) UINT64_C(1334991897450568801), (uint64_t) UINT64_C(2135987035920910082), (uint64_t) UINT64_C(1708789628736728065), (uint64_t) UINT64_C(1367031702989382452), (uint64_t) UINT64_C(2187250724783011924), (uint64_t) UINT64_C(1749800579826409539), (uint64_t) UINT64_C(1399840463861127631), (uint64_t) UINT64_C(2239744742177804210), (uint64_t) UINT64_C(1791795793742243368), (uint64_t) UINT64_C(1433436634993794694), (uint64_t) UINT64_C(2293498615990071511), (uint64_t) UINT64_C(1834798892792057209), (uint64_t) UINT64_C(1467839114233645767), (uint64_t) UINT64_C(1174271291386916613), (uint64_t) UINT64_C(1878834066219066582), (uint64_t) UINT64_C(1503067252975253265), (uint64_t) UINT64_C(1202453802380202612), (uint64_t) UINT64_C(1923926083808324180), (uint64_t) UINT64_C(1539140867046659344), (uint64_t) UINT64_C(1231312693637327475), (uint64_t) UINT64_C(1970100309819723960), (uint64_t) UINT64_C(1576080247855779168), (uint64_t) UINT64_C(1260864198284623334), (uint64_t) UINT64_C(2017382717255397335), (uint64_t) UINT64_C(1613906173804317868), (uint64_t) UINT64_C(1291124939043454294), (uint64_t) UINT64_C(2065799902469526871), (uint64_t) UINT64_C(1652639921975621497), (uint64_t) UINT64_C(1322111937580497197), (uint64_t) UINT64_C(2115379100128795516), (uint64_t) UINT64_C(1692303280103036413), (uint64_t) UINT64_C(1353842624082429130), (uint64_t) UINT64_C(2166148198531886609), (uint64_t) UINT64_C(1732918558825509287), (uint64_t) UINT64_C(1386334847060407429), (uint64_t) UINT64_C(2218135755296651887), (uint64_t) UINT64_C(1774508604237321510), (uint64_t) UINT64_C(1419606883389857208), (uint64_t) UINT64_C(2271371013423771532), (uint64_t) UINT64_C(1817096810739017226), (uint64_t) UINT64_C(1453677448591213781), (uint64_t) UINT64_C(1162941958872971024), (uint64_t) UINT64_C(1860707134196753639), (uint64_t) UINT64_C(1488565707357402911), (uint64_t) UINT64_C(1190852565885922329), (uint64_t) UINT64_C(1905364105417475727), (uint64_t) UINT64_C(1524291284333980581), (uint64_t) UINT64_C(1219433027467184465), (uint64_t) UINT64_C(1951092843947495144), (uint64_t) UINT64_C(1560874275157996115), (uint64_t) UINT64_C(1248699420126396892), (uint64_t) UINT64_C(1997919072202235028), (uint64_t) UINT64_C(1598335257761788022), (uint64_t) UINT64_C(1278668206209430417), (uint64_t) UINT64_C(2045869129935088668), (uint64_t) UINT64_C(1636695303948070935), (uint64_t) UINT64_C(1309356243158456748), (uint64_t) UINT64_C(2094969989053530796), (uint64_t) UINT64_C(1675975991242824637), (uint64_t) UINT64_C(1340780792994259709), (uint64_t) UINT64_C(2145249268790815535), (uint64_t) UINT64_C(1716199415032652428), (uint64_t) UINT64_C(1372959532026121942), (uint64_t) UINT64_C(2196735251241795108), (uint64_t) UINT64_C(1757388200993436087), (uint64_t) UINT64_C(1405910560794748869), (uint64_t) UINT64_C(2249456897271598191), (uint64_t) UINT64_C(1799565517817278553), (uint64_t) UINT64_C(1439652414253822842), (uint64_t) UINT64_C(2303443862806116547), (uint64_t) UINT64_C(1842755090244893238), (uint64_t) UINT64_C(1474204072195914590), (uint64_t) UINT64_C(1179363257756731672), (uint64_t) UINT64_C(1886981212410770676), (uint64_t) UINT64_C(1509584969928616540), (uint64_t) UINT64_C(1207667975942893232), (uint64_t) UINT64_C(1932268761508629172), (uint64_t) UINT64_C(1545815009206903337), (uint64_t) UINT64_C(1236652007365522670), (uint64_t) UINT64_C(1978643211784836272), (uint64_t) UINT64_C(1582914569427869017), (uint64_t) UINT64_C(1266331655542295214), (uint64_t) UINT64_C(2026130648867672343), (uint64_t) UINT64_C(1620904519094137874), (uint64_t) UINT64_C(1296723615275310299), (uint64_t) UINT64_C(2074757784440496479), (uint64_t) UINT64_C(1659806227552397183), (uint64_t) UINT64_C(1327844982041917746), (uint64_t) UINT64_C(2124551971267068394), (uint64_t) UINT64_C(1699641577013654715), (uint64_t) UINT64_C(1359713261610923772), (uint64_t) UINT64_C(2175541218577478036), (uint64_t) UINT64_C(1740432974861982428), (uint64_t) UINT64_C(1392346379889585943), (uint64_t) UINT64_C(2227754207823337509), (uint64_t) UINT64_C(1782203366258670007), (uint64_t) UINT64_C(1425762693006936005), (uint64_t) UINT64_C(2281220308811097609), (uint64_t) UINT64_C(1824976247048878087), (uint64_t) UINT64_C(1459980997639102469), (uint64_t) UINT64_C(1167984798111281975), (uint64_t) UINT64_C(1868775676978051161), (uint64_t) UINT64_C(1495020541582440929), (uint64_t) UINT64_C(1196016433265952743), (uint64_t) UINT64_C(1913626293225524389), (uint64_t) UINT64_C(1530901034580419511), (uint64_t) UINT64_C(1224720827664335609), (uint64_t) UINT64_C(1959553324262936974), (uint64_t) UINT64_C(1567642659410349579), (uint64_t) UINT64_C(1254114127528279663), (uint64_t) UINT64_C(2006582604045247462), (uint64_t) UINT64_C(1605266083236197969), (uint64_t) UINT64_C(1284212866588958375), (uint64_t) UINT64_C(2054740586542333401), (uint64_t) UINT64_C(1643792469233866721), (uint64_t) UINT64_C(1315033975387093376), (uint64_t) UINT64_C(2104054360619349402), (uint64_t) UINT64_C(1683243488495479522), (uint64_t) UINT64_C(1346594790796383617), (uint64_t) UINT64_C(2154551665274213788), (uint64_t) UINT64_C(1723641332219371030), (uint64_t) UINT64_C(1378913065775496824), (uint64_t) UINT64_C(2206260905240794919), (uint64_t) UINT64_C(1765008724192635935), (uint64_t) UINT64_C(1412006979354108748), (uint64_t) UINT64_C(2259211166966573997), (uint64_t) UINT64_C(1807368933573259198), (uint64_t) UINT64_C(1445895146858607358), (uint64_t) UINT64_C(1156716117486885886), (uint64_t) UINT64_C(1850745787979017418), (uint64_t) UINT64_C(1480596630383213935), (uint64_t) UINT64_C(1184477304306571148), (uint64_t) UINT64_C(1895163686890513836), (uint64_t) UINT64_C(1516130949512411069), (uint64_t) UINT64_C(1212904759609928855), (uint64_t) UINT64_C(1940647615375886168), (uint64_t) UINT64_C(1552518092300708935), (uint64_t) UINT64_C(1242014473840567148), (uint64_t) UINT64_C(1987223158144907436), (uint64_t) UINT64_C(1589778526515925949), (uint64_t) UINT64_C(1271822821212740759), (uint64_t) UINT64_C(2034916513940385215), (uint64_t) UINT64_C(1627933211152308172), (uint64_t) UINT64_C(1302346568921846537), (uint64_t) UINT64_C(2083754510274954460), (uint64_t) UINT64_C(1667003608219963568), (uint64_t) UINT64_C(1333602886575970854), (uint64_t) UINT64_C(2133764618521553367), (uint64_t) UINT64_C(1707011694817242694), (uint64_t) UINT64_C(1365609355853794155), (uint64_t) UINT64_C(2184974969366070648), (uint64_t) UINT64_C(1747979975492856518), (uint64_t) UINT64_C(1398383980394285215), (uint64_t) UINT64_C(2237414368630856344), (uint64_t) UINT64_C(1789931494904685075), (uint64_t) UINT64_C(1431945195923748060), (uint64_t) UINT64_C(2291112313477996896), (uint64_t) UINT64_C(1832889850782397517), (uint64_t) UINT64_C(1466311880625918013), (uint64_t) UINT64_C(1173049504500734410), (uint64_t) UINT64_C(1876879207201175057), (uint64_t) UINT64_C(1501503365760940045), (uint64_t) UINT64_C(1201202692608752036), (uint64_t) UINT64_C(1921924308174003258), (uint64_t) UINT64_C(1537539446539202607), (uint64_t) UINT64_C(1230031557231362085), (uint64_t) UINT64_C(1968050491570179337), (uint64_t) UINT64_C(1574440393256143469), (uint64_t) UINT64_C(1259552314604914775), (uint64_t) UINT64_C(2015283703367863641), (uint64_t) UINT64_C(1612226962694290912), (uint64_t) UINT64_C(1289781570155432730), (uint64_t) UINT64_C(2063650512248692368), (uint64_t) UINT64_C(1650920409798953894), (uint64_t) UINT64_C(1320736327839163115), (uint64_t) UINT64_C(2113178124542660985), (uint64_t) UINT64_C(1690542499634128788), (uint64_t) UINT64_C(1352433999707303030), (uint64_t) UINT64_C(2163894399531684849), (uint64_t) UINT64_C(1731115519625347879), (uint64_t) UINT64_C(1384892415700278303), (uint64_t) UINT64_C(2215827865120445285), (uint64_t) UINT64_C(1772662292096356228), (uint64_t) UINT64_C(1418129833677084982), (uint64_t) UINT64_C(2269007733883335972), (uint64_t) UINT64_C(1815206187106668777), (uint64_t) UINT64_C(1452164949685335022), (uint64_t) UINT64_C(1161731959748268017), (uint64_t) UINT64_C(1858771135597228828), (uint64_t) UINT64_C(1487016908477783062), (uint64_t) UINT64_C(1189613526782226450), (uint64_t) UINT64_C(1903381642851562320), (uint64_t) UINT64_C(1522705314281249856), (uint64_t) UINT64_C(1218164251424999885), (uint64_t) UINT64_C(1949062802279999816), (uint64_t) UINT64_C(1559250241823999852), (uint64_t) UINT64_C(1247400193459199882), (uint64_t) UINT64_C(1995840309534719811), (uint64_t) UINT64_C(1596672247627775849), (uint64_t) UINT64_C(1277337798102220679), (uint64_t) UINT64_C(2043740476963553087), (uint64_t) UINT64_C(1634992381570842469), (uint64_t) UINT64_C(1307993905256673975), (uint64_t) UINT64_C(2092790248410678361), (uint64_t) UINT64_C(1674232198728542688), (uint64_t) UINT64_C(1339385758982834151), (uint64_t) UINT64_C(2143017214372534641), (uint64_t) UINT64_C(1714413771498027713), (uint64_t) UINT64_C(1371531017198422170), (uint64_t) UINT64_C(2194449627517475473), (uint64_t) UINT64_C(1755559702013980378), (uint64_t) UINT64_C(1404447761611184302), (uint64_t) UINT64_C(2247116418577894884), (uint64_t) UINT64_C(1797693134862315907), (uint64_t) UINT64_C(1438154507889852726), (uint64_t) UINT64_C(2301047212623764361), (uint64_t) UINT64_C(1840837770099011489), (uint64_t) UINT64_C(1472670216079209191), (uint64_t) UINT64_C(1178136172863367353), (uint64_t) UINT64_C(1885017876581387765), (uint64_t) UINT64_C(1508014301265110212), (uint64_t) UINT64_C(1206411441012088169), (uint64_t) UINT64_C(1930258305619341071), (uint64_t) UINT64_C(1544206644495472857), (uint64_t) UINT64_C(1235365315596378285), (uint64_t) UINT64_C(1976584504954205257), (uint64_t) UINT64_C(1581267603963364205), (uint64_t) UINT64_C(1265014083170691364), (uint64_t) UINT64_C(2024022533073106183), (uint64_t) UINT64_C(1619218026458484946), (uint64_t) UINT64_C(1295374421166787957), (uint64_t) UINT64_C(2072599073866860731), (uint64_t) UINT64_C(1658079259093488585), (uint64_t) UINT64_C(1326463407274790868), (uint64_t) UINT64_C(2122341451639665389), (uint64_t) UINT64_C(1697873161311732311), (uint64_t) UINT64_C(1358298529049385849), (uint64_t) UINT64_C(2173277646479017358), (uint64_t) UINT64_C(1738622117183213887), (uint64_t) UINT64_C(1390897693746571109), (uint64_t) UINT64_C(2225436309994513775), (uint64_t) UINT64_C(1780349047995611020), (uint64_t) UINT64_C(1424279238396488816), (uint64_t) UINT64_C(2278846781434382106), (uint64_t) UINT64_C(1823077425147505684), (uint64_t) UINT64_C(1458461940118004547), (uint64_t) UINT64_C(1166769552094403638), (uint64_t) UINT64_C(1866831283351045821), (uint64_t) UINT64_C(1493465026680836657), (uint64_t) UINT64_C(1194772021344669325), (uint64_t) UINT64_C(1911635234151470921), (uint64_t) UINT64_C(1529308187321176736), (uint64_t) UINT64_C(1223446549856941389), (uint64_t) UINT64_C(1957514479771106223), (uint64_t) UINT64_C(1566011583816884978), (uint64_t) UINT64_C(1252809267053507982), (uint64_t) UINT64_C(2004494827285612772), (uint64_t) UINT64_C(1603595861828490217), (uint64_t) UINT64_C(1282876689462792174), (uint64_t) UINT64_C(2052602703140467478), (uint64_t) UINT64_C(1642082162512373983), (uint64_t) UINT64_C(1313665730009899186), (uint64_t) UINT64_C(2101865168015838698), (uint64_t) UINT64_C(1681492134412670958), (uint64_t) UINT64_C(1345193707530136767) }
};
const vader_array_t vader_data_2 = { { 13u, 0u, 0u, 0u, NULL }, 342u, 342u, 0u, (vader_array_buf_t*) &vader_data_2_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint64_t slots[326]; } vader_data_3_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 326u, 326u, 170u, 4u, { 0u, 0u, 0u },
    { (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(0), (uint64_t) UINT64_C(4611686018427387904), (uint64_t) UINT64_C(9799832789158199296), (uint64_t) UINT64_C(12249790986447749120), (uint64_t) UINT64_C(15312238733059686400), (uint64_t) UINT64_C(14528612397897220096), (uint64_t) UINT64_C(13692068767113150464), (uint64_t) UINT64_C(12503399940464050176), (uint64_t) UINT64_C(15629249925580062720), (uint64_t) UINT64_C(9768281203487539200), (uint64_t) UINT64_C(7598665485932036096), (uint64_t) UINT64_C(274959820560269312), (uint64_t) UINT64_C(9395221924704944128), (uint64_t) UINT64_C(2520655369026404352), (uint64_t) UINT64_C(12374191248137781248), (uint64_t) UINT64_C(14651398557727195136), (uint64_t) UINT64_C(13702562178731606016), (uint64_t) UINT64_C(3293144668132343808), (uint64_t) UINT64_C(18199116482078572544), (uint64_t) UINT64_C(8913837547316051968), (uint64_t) UINT64_C(15753982952572452864), (uint64_t) UINT64_C(12152082354571476992), (uint64_t) UINT64_C(15190102943214346240), (uint64_t) UINT64_C(9764256642163156992), (uint64_t) UINT64_C(17631875447420442880), (uint64_t) UINT64_C(8204786253993389888), (uint64_t) UINT64_C(1032610780636961552), (uint64_t) UINT64_C(2951224747111794922), (uint64_t) UINT64_C(3689030933889743652), (uint64_t) UINT64_C(13834660704216955373), (uint64_t) UINT64_C(17870034976990372916), (uint64_t) UINT64_C(17725857702810578241), (uint64_t) UINT64_C(3710578054803671186), (uint64_t) UINT64_C(26536550077201078), (uint64_t) UINT64_C(11545800389866720434), (uint64_t) UINT64_C(14432250487333400542), (uint64_t) UINT64_C(8816941072311974870), (uint64_t) UINT64_C(17039803216263454053), (uint64_t) UINT64_C(12076381983474541759), (uint64_t) UINT64_C(5872105442488401391), (uint64_t) UINT64_C(15199280947623720629), (uint64_t) UINT64_C(9775729147674874978), (uint64_t) UINT64_C(16831347453020981627), (uint64_t) UINT64_C(1296220121283337709), (uint64_t) UINT64_C(15455333206886335848), (uint64_t) UINT64_C(10095794471753144002), (uint64_t) UINT64_C(6309871544845715001), (uint64_t) UINT64_C(12499025449484531656), (uint64_t) UINT64_C(11012095793428276666), (uint64_t) UINT64_C(11494245889320060820), (uint64_t) UINT64_C(532749306367912313), (uint64_t) UINT64_C(5277622651387278295), (uint64_t) UINT64_C(7910200175544436838), (uint64_t) UINT64_C(14499436237857933952), (uint64_t) UINT64_C(8900923260467641632), (uint64_t) UINT64_C(12480606065433357876), (uint64_t) UINT64_C(10989071563364309441), (uint64_t) UINT64_C(9124653435777998898), (uint64_t) UINT64_C(8008751406574943263), (uint64_t) UINT64_C(5399253239791291175), (uint64_t) UINT64_C(15972438586593889776), (uint64_t) UINT64_C(759402079766405302), (uint64_t) UINT64_C(14784310654990170340), (uint64_t) UINT64_C(9257016281882937117), (uint64_t) UINT64_C(16182956370781059300), (uint64_t) UINT64_C(7808504722524468110), (uint64_t) UINT64_C(5148944884728197234), (uint64_t) UINT64_C(1824495087482858639), (uint64_t) UINT64_C(1140309429676786649), (uint64_t) UINT64_C(1425386787095983311), (uint64_t) UINT64_C(6393419502297367043), (uint64_t) UINT64_C(13219259225790630210), (uint64_t) UINT64_C(16524074032238287762), (uint64_t) UINT64_C(16043406521870471799), (uint64_t) UINT64_C(803757039314269066), (uint64_t) UINT64_C(14839754354425000045), (uint64_t) UINT64_C(4714634887749086344), (uint64_t) UINT64_C(9864175832484260821), (uint64_t) UINT64_C(16941905809032713930), (uint64_t) UINT64_C(2730638187581340797), (uint64_t) UINT64_C(10930020904093113806), (uint64_t) UINT64_C(18274212148543780162), (uint64_t) UINT64_C(4396021111970173586), (uint64_t) UINT64_C(5053356204195052443), (uint64_t) UINT64_C(15540067292098591362), (uint64_t) UINT64_C(14813398096695851299), (uint64_t) UINT64_C(13870059828862294966), (uint64_t) UINT64_C(12725888767650480803), (uint64_t) UINT64_C(15907360959563101004), (uint64_t) UINT64_C(14553786618154326031), (uint64_t) UINT64_C(4357175217410743827), (uint64_t) UINT64_C(10058155040190817688), (uint64_t) UINT64_C(7961007781811134206), (uint64_t) UINT64_C(14199001900486734687), (uint64_t) UINT64_C(13137066357181030455), (uint64_t) UINT64_C(11809646928048900164), (uint64_t) UINT64_C(16604401366885338411), (uint64_t) UINT64_C(16143815690179285109), (uint64_t) UINT64_C(10956397575869330579), (uint64_t) UINT64_C(6847748484918331612), (uint64_t) UINT64_C(17783057643002690323), (uint64_t) UINT64_C(17617136035325974999), (uint64_t) UINT64_C(17928239049719816230), (uint64_t) UINT64_C(17798612793722382384), (uint64_t) UINT64_C(13024893955298202172), (uint64_t) UINT64_C(5834715712847682405), (uint64_t) UINT64_C(16516766677914378815), (uint64_t) UINT64_C(11422586310538197711), (uint64_t) UINT64_C(11750802462513761473), (uint64_t) UINT64_C(10076817059714813937), (uint64_t) UINT64_C(12596021324643517422), (uint64_t) UINT64_C(5566670318688504437), (uint64_t) UINT64_C(2346651879933242642), (uint64_t) UINT64_C(7545000868343941206), (uint64_t) UINT64_C(4715625542714963254), (uint64_t) UINT64_C(5894531928393704067), (uint64_t) UINT64_C(16591536947346905892), (uint64_t) UINT64_C(17287239619732898039), (uint64_t) UINT64_C(16997363506238734644), (uint64_t) UINT64_C(2799960309088866689), (uint64_t) UINT64_C(10973347230035317489), (uint64_t) UINT64_C(13716684037544146861), (uint64_t) UINT64_C(12534169028502795672), (uint64_t) UINT64_C(11056025267201106687), (uint64_t) UINT64_C(18439230838069161439), (uint64_t) UINT64_C(13825666510731675991), (uint64_t) UINT64_C(3447025083132431277), (uint64_t) UINT64_C(6766076695385157452), (uint64_t) UINT64_C(8457595869231446815), (uint64_t) UINT64_C(10571994836539308519), (uint64_t) UINT64_C(6607496772837067824), (uint64_t) UINT64_C(17482743002901110588), (uint64_t) UINT64_C(17241742735199000331), (uint64_t) UINT64_C(15387775227926763111), (uint64_t) UINT64_C(5399660979626290177), (uint64_t) UINT64_C(11361262242960250625), (uint64_t) UINT64_C(11712474920277544544), (uint64_t) UINT64_C(10028907631919542777), (uint64_t) UINT64_C(7924448521472040567), (uint64_t) UINT64_C(14176152362774801162), (uint64_t) UINT64_C(3885132398186337741), (uint64_t) UINT64_C(9468101516160310080), (uint64_t) UINT64_C(15140935484454969608), (uint64_t) UINT64_C(479425281859160394), (uint64_t) UINT64_C(5210967620751338397), (uint64_t) UINT64_C(17091912818251750210), (uint64_t) UINT64_C(12141518985959911954), (uint64_t) UINT64_C(15176898732449889943), (uint64_t) UINT64_C(11791404716994875166), (uint64_t) UINT64_C(10127569877816206054), (uint64_t) UINT64_C(8047776328842869663), (uint64_t) UINT64_C(836348374198811271), (uint64_t) UINT64_C(7440246761515338900), (uint64_t) UINT64_C(13911994470321561530), (uint64_t) UINT64_C(8166621051047176104), (uint64_t) UINT64_C(2798295147690791113), (uint64_t) UINT64_C(17332926989895652603), (uint64_t) UINT64_C(17054472718942177850), (uint64_t) UINT64_C(8353202440125167204), (uint64_t) UINT64_C(10441503050156459005), (uint64_t) UINT64_C(3828506775840797949), (uint64_t) UINT64_C(86973725686804766), (uint64_t) UINT64_C(13943775212390669669), (uint64_t) UINT64_C(3594660960206173375), (uint64_t) UINT64_C(2246663100128858359), (uint64_t) UINT64_C(12031700912015848757), (uint64_t) UINT64_C(5816254103165035138), (uint64_t) UINT64_C(5941001823691840913), (uint64_t) UINT64_C(7426252279614801142), (uint64_t) UINT64_C(4671129331091113523), (uint64_t) UINT64_C(5225298841145639904), (uint64_t) UINT64_C(6531623551432049880), (uint64_t) UINT64_C(3552843420862674446), (uint64_t) UINT64_C(16055585193321335241), (uint64_t) UINT64_C(10846109454796893243), (uint64_t) UINT64_C(18169322836923504458), (uint64_t) UINT64_C(11355826773077190286), (uint64_t) UINT64_C(9583097447919099954), (uint64_t) UINT64_C(11978871809898874942), (uint64_t) UINT64_C(14973589762373593678), (uint64_t) UINT64_C(2440964573842414192), (uint64_t) UINT64_C(3051205717303017741), (uint64_t) UINT64_C(13037379183483547984), (uint64_t) UINT64_C(8148361989677217490), (uint64_t) UINT64_C(14797138505523909766), (uint64_t) UINT64_C(13884737113477499304), (uint64_t) UINT64_C(15595489723564518921), (uint64_t) UINT64_C(14882676136028260747), (uint64_t) UINT64_C(9379973133180550126), (uint64_t) UINT64_C(17391698254306313589), (uint64_t) UINT64_C(3292878744173340370), (uint64_t) UINT64_C(4116098430216675462), (uint64_t) UINT64_C(266718509671728212), (uint64_t) UINT64_C(333398137089660265), (uint64_t) UINT64_C(5028433689789463235), (uint64_t) UINT64_C(10060300083759496378), (uint64_t) UINT64_C(12575375104699370472), (uint64_t) UINT64_C(1884160825592049379), (uint64_t) UINT64_C(17318501580490888525), (uint64_t) UINT64_C(7813068920331446945), (uint64_t) UINT64_C(5154650131986920777), (uint64_t) UINT64_C(915813323278131534), (uint64_t) UINT64_C(14979824709379828129), (uint64_t) UINT64_C(9501408849870009354), (uint64_t) UINT64_C(12855909558809837702), (uint64_t) UINT64_C(2234828893230133415), (uint64_t) UINT64_C(2793536116537666769), (uint64_t) UINT64_C(8663489100477123587), (uint64_t) UINT64_C(1605989338741628675), (uint64_t) UINT64_C(11230858710281811652), (uint64_t) UINT64_C(9426887369424876662), (uint64_t) UINT64_C(12809333633531629769), (uint64_t) UINT64_C(16011667041914537212), (uint64_t) UINT64_C(6179525747111007803), (uint64_t) UINT64_C(13085575628799155685), (uint64_t) UINT64_C(16356969535998944606), (uint64_t) UINT64_C(15834525901571292854), (uint64_t) UINT64_C(2979049660840976177), (uint64_t) UINT64_C(17558870131333383934), (uint64_t) UINT64_C(8113529608884566205), (uint64_t) UINT64_C(9682642023980241782), (uint64_t) UINT64_C(16714988548402690132), (uint64_t) UINT64_C(11670363648648586857), (uint64_t) UINT64_C(11905663298832754689), (uint64_t) UINT64_C(1047021068258779650), (uint64_t) UINT64_C(15143834390605638274), (uint64_t) UINT64_C(4853210475701136017), (uint64_t) UINT64_C(1454827076199032118), (uint64_t) UINT64_C(1818533845248790147), (uint64_t) UINT64_C(3442426662494187794), (uint64_t) UINT64_C(13526405364972510550), (uint64_t) UINT64_C(3072948650933474476), (uint64_t) UINT64_C(15755650962115585259), (uint64_t) UINT64_C(15082877684217093670), (uint64_t) UINT64_C(9630225068416591280), (uint64_t) UINT64_C(8324733676974063502), (uint64_t) UINT64_C(5794231077790191473), (uint64_t) UINT64_C(7242788847237739342), (uint64_t) UINT64_C(18276858095901949986), (uint64_t) UINT64_C(16034722328366106645), (uint64_t) UINT64_C(1596658836748081690), (uint64_t) UINT64_C(6607509564362490017), (uint64_t) UINT64_C(1823850468512862308), (uint64_t) UINT64_C(6891499104068465790), (uint64_t) UINT64_C(17837745916940358045), (uint64_t) UINT64_C(4231062170446641922), (uint64_t) UINT64_C(5288827713058302403), (uint64_t) UINT64_C(6611034641322878003), (uint64_t) UINT64_C(13355268687681574560), (uint64_t) UINT64_C(16694085859601968200), (uint64_t) UINT64_C(11644235287647684442), (uint64_t) UINT64_C(4971804045566108824), (uint64_t) UINT64_C(6214755056957636030), (uint64_t) UINT64_C(3156757802769657134), (uint64_t) UINT64_C(6584659645158423613), (uint64_t) UINT64_C(17454196593302805324), (uint64_t) UINT64_C(17206059723201118751), (uint64_t) UINT64_C(6142101308573311315), (uint64_t) UINT64_C(3065940617289251240), (uint64_t) UINT64_C(8444111790038951954), (uint64_t) UINT64_C(665883850346957067), (uint64_t) UINT64_C(832354812933696334), (uint64_t) UINT64_C(10263815553021896226), (uint64_t) UINT64_C(17944099766707154901), (uint64_t) UINT64_C(13206752671529167818), (uint64_t) UINT64_C(16508440839411459773), (uint64_t) UINT64_C(12623618533845856310), (uint64_t) UINT64_C(15779523167307320387), (uint64_t) UINT64_C(1277659885424598868), (uint64_t) UINT64_C(1597074856780748586), (uint64_t) UINT64_C(5609857803915355770), (uint64_t) UINT64_C(16235694291748970521), (uint64_t) UINT64_C(1847873790976661535), (uint64_t) UINT64_C(12684136165428883219), (uint64_t) UINT64_C(11243484188358716120), (uint64_t) UINT64_C(219297180166231438), (uint64_t) UINT64_C(7054589765244976505), (uint64_t) UINT64_C(13429923224983608535), (uint64_t) UINT64_C(12175718012802122765), (uint64_t) UINT64_C(14527352785642408584), (uint64_t) UINT64_C(13547504963625622826), (uint64_t) UINT64_C(12322695186104640628), (uint64_t) UINT64_C(16925056528170176201), (uint64_t) UINT64_C(7321262604930556539), (uint64_t) UINT64_C(18374950293017971482), (uint64_t) UINT64_C(4566814905495150320), (uint64_t) UINT64_C(14931890668723713708), (uint64_t) UINT64_C(9441491299049866327), (uint64_t) UINT64_C(1289246043478778550), (uint64_t) UINT64_C(6223243572775861092), (uint64_t) UINT64_C(3167368447542438461), (uint64_t) UINT64_C(1979605279714024038), (uint64_t) UINT64_C(7086192618069917952), (uint64_t) UINT64_C(18081112809442173248), (uint64_t) UINT64_C(13606538515115052232), (uint64_t) UINT64_C(7784801107039039482), (uint64_t) UINT64_C(507629346944023544), (uint64_t) UINT64_C(5246222702107417334), (uint64_t) UINT64_C(3278889188817135834), (uint64_t) UINT64_C(8710297504448807696) }
};
const vader_array_t vader_data_3 = { { 13u, 0u, 0u, 0u, NULL }, 326u, 326u, 0u, (vader_array_buf_t*) &vader_data_3_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint64_t slots[326]; } vader_data_4_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 326u, 326u, 170u, 4u, { 0u, 0u, 0u },
    { (uint64_t) UINT64_C(1152921504606846976), (uint64_t) UINT64_C(1441151880758558720), (uint64_t) UINT64_C(1801439850948198400), (uint64_t) UINT64_C(2251799813685248000), (uint64_t) UINT64_C(1407374883553280000), (uint64_t) UINT64_C(1759218604441600000), (uint64_t) UINT64_C(2199023255552000000), (uint64_t) UINT64_C(1374389534720000000), (uint64_t) UINT64_C(1717986918400000000), (uint64_t) UINT64_C(2147483648000000000), (uint64_t) UINT64_C(1342177280000000000), (uint64_t) UINT64_C(1677721600000000000), (uint64_t) UINT64_C(2097152000000000000), (uint64_t) UINT64_C(1310720000000000000), (uint64_t) UINT64_C(1638400000000000000), (uint64_t) UINT64_C(2048000000000000000), (uint64_t) UINT64_C(1280000000000000000), (uint64_t) UINT64_C(1600000000000000000), (uint64_t) UINT64_C(2000000000000000000), (uint64_t) UINT64_C(1250000000000000000), (uint64_t) UINT64_C(1562500000000000000), (uint64_t) UINT64_C(1953125000000000000), (uint64_t) UINT64_C(1220703125000000000), (uint64_t) UINT64_C(1525878906250000000), (uint64_t) UINT64_C(1907348632812500000), (uint64_t) UINT64_C(1192092895507812500), (uint64_t) UINT64_C(1490116119384765625), (uint64_t) UINT64_C(1862645149230957031), (uint64_t) UINT64_C(1164153218269348144), (uint64_t) UINT64_C(1455191522836685180), (uint64_t) UINT64_C(1818989403545856475), (uint64_t) UINT64_C(2273736754432320594), (uint64_t) UINT64_C(1421085471520200371), (uint64_t) UINT64_C(1776356839400250464), (uint64_t) UINT64_C(2220446049250313080), (uint64_t) UINT64_C(1387778780781445675), (uint64_t) UINT64_C(1734723475976807094), (uint64_t) UINT64_C(2168404344971008868), (uint64_t) UINT64_C(1355252715606880542), (uint64_t) UINT64_C(1694065894508600678), (uint64_t) UINT64_C(2117582368135750847), (uint64_t) UINT64_C(1323488980084844279), (uint64_t) UINT64_C(1654361225106055349), (uint64_t) UINT64_C(2067951531382569187), (uint64_t) UINT64_C(1292469707114105741), (uint64_t) UINT64_C(1615587133892632177), (uint64_t) UINT64_C(2019483917365790221), (uint64_t) UINT64_C(1262177448353618888), (uint64_t) UINT64_C(1577721810442023610), (uint64_t) UINT64_C(1972152263052529513), (uint64_t) UINT64_C(1232595164407830945), (uint64_t) UINT64_C(1540743955509788682), (uint64_t) UINT64_C(1925929944387235853), (uint64_t) UINT64_C(1203706215242022408), (uint64_t) UINT64_C(1504632769052528010), (uint64_t) UINT64_C(1880790961315660012), (uint64_t) UINT64_C(1175494350822287507), (uint64_t) UINT64_C(1469367938527859384), (uint64_t) UINT64_C(1836709923159824231), (uint64_t) UINT64_C(2295887403949780289), (uint64_t) UINT64_C(1434929627468612680), (uint64_t) UINT64_C(1793662034335765850), (uint64_t) UINT64_C(2242077542919707313), (uint64_t) UINT64_C(1401298464324817070), (uint64_t) UINT64_C(1751623080406021338), (uint64_t) UINT64_C(2189528850507526673), (uint64_t) UINT64_C(1368455531567204170), (uint64_t) UINT64_C(1710569414459005213), (uint64_t) UINT64_C(2138211768073756516), (uint64_t) UINT64_C(1336382355046097823), (uint64_t) UINT64_C(1670477943807622278), (uint64_t) UINT64_C(2088097429759527848), (uint64_t) UINT64_C(1305060893599704905), (uint64_t) UINT64_C(1631326116999631131), (uint64_t) UINT64_C(2039157646249538914), (uint64_t) UINT64_C(1274473528905961821), (uint64_t) UINT64_C(1593091911132452277), (uint64_t) UINT64_C(1991364888915565346), (uint64_t) UINT64_C(1244603055572228341), (uint64_t) UINT64_C(1555753819465285426), (uint64_t) UINT64_C(1944692274331606783), (uint64_t) UINT64_C(1215432671457254239), (uint64_t) UINT64_C(1519290839321567799), (uint64_t) UINT64_C(1899113549151959749), (uint64_t) UINT64_C(1186945968219974843), (uint64_t) UINT64_C(1483682460274968554), (uint64_t) UINT64_C(1854603075343710692), (uint64_t) UINT64_C(1159126922089819183), (uint64_t) UINT64_C(1448908652612273978), (uint64_t) UINT64_C(1811135815765342473), (uint64_t) UINT64_C(2263919769706678091), (uint64_t) UINT64_C(1414949856066673807), (uint64_t) UINT64_C(1768687320083342259), (uint64_t) UINT64_C(2210859150104177824), (uint64_t) UINT64_C(1381786968815111140), (uint64_t) UINT64_C(1727233711018888925), (uint64_t) UINT64_C(2159042138773611156), (uint64_t) UINT64_C(1349401336733506972), (uint64_t) UINT64_C(1686751670916883715), (uint64_t) UINT64_C(2108439588646104644), (uint64_t) UINT64_C(1317774742903815403), (uint64_t) UINT64_C(1647218428629769253), (uint64_t) UINT64_C(2059023035787211567), (uint64_t) UINT64_C(1286889397367007229), (uint64_t) UINT64_C(1608611746708759036), (uint64_t) UINT64_C(2010764683385948796), (uint64_t) UINT64_C(1256727927116217997), (uint64_t) UINT64_C(1570909908895272496), (uint64_t) UINT64_C(1963637386119090621), (uint64_t) UINT64_C(1227273366324431638), (uint64_t) UINT64_C(1534091707905539547), (uint64_t) UINT64_C(1917614634881924434), (uint64_t) UINT64_C(1198509146801202771), (uint64_t) UINT64_C(1498136433501503464), (uint64_t) UINT64_C(1872670541876879330), (uint64_t) UINT64_C(1170419088673049581), (uint64_t) UINT64_C(1463023860841311977), (uint64_t) UINT64_C(1828779826051639971), (uint64_t) UINT64_C(2285974782564549964), (uint64_t) UINT64_C(1428734239102843727), (uint64_t) UINT64_C(1785917798878554659), (uint64_t) UINT64_C(2232397248598193324), (uint64_t) UINT64_C(1395248280373870827), (uint64_t) UINT64_C(1744060350467338534), (uint64_t) UINT64_C(2180075438084173168), (uint64_t) UINT64_C(1362547148802608230), (uint64_t) UINT64_C(1703183936003260287), (uint64_t) UINT64_C(2128979920004075359), (uint64_t) UINT64_C(1330612450002547099), (uint64_t) UINT64_C(1663265562503183874), (uint64_t) UINT64_C(2079081953128979843), (uint64_t) UINT64_C(1299426220705612402), (uint64_t) UINT64_C(1624282775882015502), (uint64_t) UINT64_C(2030353469852519378), (uint64_t) UINT64_C(1268970918657824611), (uint64_t) UINT64_C(1586213648322280764), (uint64_t) UINT64_C(1982767060402850955), (uint64_t) UINT64_C(1239229412751781847), (uint64_t) UINT64_C(1549036765939727309), (uint64_t) UINT64_C(1936295957424659136), (uint64_t) UINT64_C(1210184973390411960), (uint64_t) UINT64_C(1512731216738014950), (uint64_t) UINT64_C(1890914020922518687), (uint64_t) UINT64_C(1181821263076574179), (uint64_t) UINT64_C(1477276578845717724), (uint64_t) UINT64_C(1846595723557147156), (uint64_t) UINT64_C(1154122327223216972), (uint64_t) UINT64_C(1442652909029021215), (uint64_t) UINT64_C(1803316136286276519), (uint64_t) UINT64_C(2254145170357845649), (uint64_t) UINT64_C(1408840731473653530), (uint64_t) UINT64_C(1761050914342066913), (uint64_t) UINT64_C(2201313642927583642), (uint64_t) UINT64_C(1375821026829739776), (uint64_t) UINT64_C(1719776283537174720), (uint64_t) UINT64_C(2149720354421468400), (uint64_t) UINT64_C(1343575221513417750), (uint64_t) UINT64_C(1679469026891772187), (uint64_t) UINT64_C(2099336283614715234), (uint64_t) UINT64_C(1312085177259197021), (uint64_t) UINT64_C(1640106471573996277), (uint64_t) UINT64_C(2050133089467495346), (uint64_t) UINT64_C(1281333180917184591), (uint64_t) UINT64_C(1601666476146480739), (uint64_t) UINT64_C(2002083095183100924), (uint64_t) UINT64_C(1251301934489438077), (uint64_t) UINT64_C(1564127418111797597), (uint64_t) UINT64_C(1955159272639746996), (uint64_t) UINT64_C(1221974545399841872), (uint64_t) UINT64_C(1527468181749802341), (uint64_t) UINT64_C(1909335227187252926), (uint64_t) UINT64_C(1193334516992033078), (uint64_t) UINT64_C(1491668146240041348), (uint64_t) UINT64_C(1864585182800051685), (uint64_t) UINT64_C(1165365739250032303), (uint64_t) UINT64_C(1456707174062540379), (uint64_t) UINT64_C(1820883967578175474), (uint64_t) UINT64_C(2276104959472719343), (uint64_t) UINT64_C(1422565599670449589), (uint64_t) UINT64_C(1778206999588061986), (uint64_t) UINT64_C(2222758749485077483), (uint64_t) UINT64_C(1389224218428173427), (uint64_t) UINT64_C(1736530273035216783), (uint64_t) UINT64_C(2170662841294020979), (uint64_t) UINT64_C(1356664275808763112), (uint64_t) UINT64_C(1695830344760953890), (uint64_t) UINT64_C(2119787930951192363), (uint64_t) UINT64_C(1324867456844495227), (uint64_t) UINT64_C(1656084321055619033), (uint64_t) UINT64_C(2070105401319523792), (uint64_t) UINT64_C(1293815875824702370), (uint64_t) UINT64_C(1617269844780877962), (uint64_t) UINT64_C(2021587305976097453), (uint64_t) UINT64_C(1263492066235060908), (uint64_t) UINT64_C(1579365082793826135), (uint64_t) UINT64_C(1974206353492282669), (uint64_t) UINT64_C(1233878970932676668), (uint64_t) UINT64_C(1542348713665845835), (uint64_t) UINT64_C(1927935892082307294), (uint64_t) UINT64_C(1204959932551442058), (uint64_t) UINT64_C(1506199915689302573), (uint64_t) UINT64_C(1882749894611628216), (uint64_t) UINT64_C(1176718684132267635), (uint64_t) UINT64_C(1470898355165334544), (uint64_t) UINT64_C(1838622943956668180), (uint64_t) UINT64_C(2298278679945835225), (uint64_t) UINT64_C(1436424174966147016), (uint64_t) UINT64_C(1795530218707683770), (uint64_t) UINT64_C(2244412773384604712), (uint64_t) UINT64_C(1402757983365377945), (uint64_t) UINT64_C(1753447479206722431), (uint64_t) UINT64_C(2191809349008403039), (uint64_t) UINT64_C(1369880843130251899), (uint64_t) UINT64_C(1712351053912814874), (uint64_t) UINT64_C(2140438817391018593), (uint64_t) UINT64_C(1337774260869386620), (uint64_t) UINT64_C(1672217826086733276), (uint64_t) UINT64_C(2090272282608416595), (uint64_t) UINT64_C(1306420176630260372), (uint64_t) UINT64_C(1633025220787825465), (uint64_t) UINT64_C(2041281525984781831), (uint64_t) UINT64_C(1275800953740488644), (uint64_t) UINT64_C(1594751192175610805), (uint64_t) UINT64_C(1993438990219513507), (uint64_t) UINT64_C(1245899368887195941), (uint64_t) UINT64_C(1557374211108994927), (uint64_t) UINT64_C(1946717763886243659), (uint64_t) UINT64_C(1216698602428902287), (uint64_t) UINT64_C(1520873253036127858), (uint64_t) UINT64_C(1901091566295159823), (uint64_t) UINT64_C(1188182228934474889), (uint64_t) UINT64_C(1485227786168093612), (uint64_t) UINT64_C(1856534732710117015), (uint64_t) UINT64_C(1160334207943823134), (uint64_t) UINT64_C(1450417759929778918), (uint64_t) UINT64_C(1813022199912223647), (uint64_t) UINT64_C(2266277749890279559), (uint64_t) UINT64_C(1416423593681424724), (uint64_t) UINT64_C(1770529492101780905), (uint64_t) UINT64_C(2213161865127226132), (uint64_t) UINT64_C(1383226165704516332), (uint64_t) UINT64_C(1729032707130645415), (uint64_t) UINT64_C(2161290883913306769), (uint64_t) UINT64_C(1350806802445816731), (uint64_t) UINT64_C(1688508503057270913), (uint64_t) UINT64_C(2110635628821588642), (uint64_t) UINT64_C(1319147268013492901), (uint64_t) UINT64_C(1648934085016866126), (uint64_t) UINT64_C(2061167606271082658), (uint64_t) UINT64_C(1288229753919426661), (uint64_t) UINT64_C(1610287192399283327), (uint64_t) UINT64_C(2012858990499104158), (uint64_t) UINT64_C(1258036869061940099), (uint64_t) UINT64_C(1572546086327425124), (uint64_t) UINT64_C(1965682607909281405), (uint64_t) UINT64_C(1228551629943300878), (uint64_t) UINT64_C(1535689537429126097), (uint64_t) UINT64_C(1919611921786407622), (uint64_t) UINT64_C(1199757451116504763), (uint64_t) UINT64_C(1499696813895630954), (uint64_t) UINT64_C(1874621017369538693), (uint64_t) UINT64_C(1171638135855961683), (uint64_t) UINT64_C(1464547669819952104), (uint64_t) UINT64_C(1830684587274940130), (uint64_t) UINT64_C(2288355734093675162), (uint64_t) UINT64_C(1430222333808546976), (uint64_t) UINT64_C(1787777917260683721), (uint64_t) UINT64_C(2234722396575854651), (uint64_t) UINT64_C(1396701497859909157), (uint64_t) UINT64_C(1745876872324886446), (uint64_t) UINT64_C(2182346090406108057), (uint64_t) UINT64_C(1363966306503817536), (uint64_t) UINT64_C(1704957883129771920), (uint64_t) UINT64_C(2131197353912214900), (uint64_t) UINT64_C(1331998346195134312), (uint64_t) UINT64_C(1664997932743917890), (uint64_t) UINT64_C(2081247415929897363), (uint64_t) UINT64_C(1300779634956185852), (uint64_t) UINT64_C(1625974543695232315), (uint64_t) UINT64_C(2032468179619040394), (uint64_t) UINT64_C(1270292612261900246), (uint64_t) UINT64_C(1587865765327375307), (uint64_t) UINT64_C(1984832206659219134), (uint64_t) UINT64_C(1240520129162011959), (uint64_t) UINT64_C(1550650161452514949), (uint64_t) UINT64_C(1938312701815643686), (uint64_t) UINT64_C(1211445438634777304), (uint64_t) UINT64_C(1514306798293471630), (uint64_t) UINT64_C(1892883497866839537), (uint64_t) UINT64_C(1183052186166774710), (uint64_t) UINT64_C(1478815232708468388), (uint64_t) UINT64_C(1848519040885585485), (uint64_t) UINT64_C(1155324400553490928), (uint64_t) UINT64_C(1444155500691863660), (uint64_t) UINT64_C(1805194375864829576), (uint64_t) UINT64_C(2256492969831036970), (uint64_t) UINT64_C(1410308106144398106), (uint64_t) UINT64_C(1762885132680497632), (uint64_t) UINT64_C(2203606415850622041), (uint64_t) UINT64_C(1377254009906638775), (uint64_t) UINT64_C(1721567512383298469), (uint64_t) UINT64_C(2151959390479123087), (uint64_t) UINT64_C(1344974619049451929), (uint64_t) UINT64_C(1681218273811814911), (uint64_t) UINT64_C(2101522842264768639), (uint64_t) UINT64_C(1313451776415480399), (uint64_t) UINT64_C(1641814720519350499), (uint64_t) UINT64_C(2052268400649188124), (uint64_t) UINT64_C(1282667750405742577), (uint64_t) UINT64_C(1603334688007178222), (uint64_t) UINT64_C(2004168360008972777), (uint64_t) UINT64_C(1252605225005607986), (uint64_t) UINT64_C(1565756531257009982), (uint64_t) UINT64_C(1957195664071262478), (uint64_t) UINT64_C(1223247290044539049), (uint64_t) UINT64_C(1529059112555673811), (uint64_t) UINT64_C(1911323890694592264), (uint64_t) UINT64_C(1194577431684120165), (uint64_t) UINT64_C(1493221789605150206), (uint64_t) UINT64_C(1866527237006437757), (uint64_t) UINT64_C(1166579523129023598), (uint64_t) UINT64_C(1458224403911279498), (uint64_t) UINT64_C(1822780504889099373), (uint64_t) UINT64_C(2278475631111374216), (uint64_t) UINT64_C(1424047269444608885), (uint64_t) UINT64_C(1780059086805761106) }
};
const vader_array_t vader_data_4 = { { 13u, 0u, 0u, 0u, NULL }, 326u, 326u, 0u, (vader_array_buf_t*) &vader_data_4_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[10]; } vader_data_5_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 10u, 10u, 162u, 0u, { 0u, 0u, 0u },
    { { 162u, 0u, { .s = 452u } }, { 162u, 0u, { .s = 456u } }, { 162u, 0u, { .s = 458u } }, { 162u, 0u, { .s = 459u } }, { 162u, 0u, { .s = 462u } }, { 162u, 0u, { .s = 463u } }, { 162u, 0u, { .s = 464u } }, { 162u, 0u, { .s = 465u } }, { 162u, 0u, { .s = 466u } }, { 162u, 0u, { .s = 467u } } }
};
const vader_array_t vader_data_5 = { { 8u, 0u, 0u, 0u, NULL }, 10u, 10u, 0u, (vader_array_buf_t*) &vader_data_5_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[2]; } vader_data_6_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 162u, 0u, { 0u, 0u, 0u },
    { { 162u, 0u, { .s = 735u } }, { 162u, 0u, { .s = 2172u } } }
};
const vader_array_t vader_data_6 = { { 8u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_6_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[44]; } vader_data_7_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 44u, 44u, 162u, 0u, { 0u, 0u, 0u },
    { { 162u, 0u, { .s = 1216u } }, { 162u, 0u, { .s = 1247u } }, { 162u, 0u, { .s = 1315u } }, { 162u, 0u, { .s = 1323u } }, { 162u, 0u, { .s = 1360u } }, { 162u, 0u, { .s = 1378u } }, { 162u, 0u, { .s = 1399u } }, { 162u, 0u, { .s = 1409u } }, { 162u, 0u, { .s = 1413u } }, { 162u, 0u, { .s = 1427u } }, { 162u, 0u, { .s = 1439u } }, { 162u, 0u, { .s = 1493u } }, { 162u, 0u, { .s = 1554u } }, { 162u, 0u, { .s = 1562u } }, { 162u, 0u, { .s = 1594u } }, { 162u, 0u, { .s = 1653u } }, { 162u, 0u, { .s = 1682u } }, { 162u, 0u, { .s = 1685u } }, { 162u, 0u, { .s = 1786u } }, { 162u, 0u, { .s = 1923u } }, { 162u, 0u, { .s = 1931u } }, { 162u, 0u, { .s = 1934u } }, { 162u, 0u, { .s = 1961u } }, { 162u, 0u, { .s = 1964u } }, { 162u, 0u, { .s = 1971u } }, { 162u, 0u, { .s = 1992u } }, { 162u, 0u, { .s = 2109u } }, { 162u, 0u, { .s = 2126u } }, { 162u, 0u, { .s = 2197u } }, { 162u, 0u, { .s = 2268u } }, { 162u, 0u, { .s = 2284u } }, { 162u, 0u, { .s = 2393u } }, { 162u, 0u, { .s = 2399u } }, { 162u, 0u, { .s = 2403u } }, { 162u, 0u, { .s = 863u } }, { 162u, 0u, { .s = 864u } }, { 162u, 0u, { .s = 865u } }, { 162u, 0u, { .s = 866u } }, { 162u, 0u, { .s = 867u } }, { 162u, 0u, { .s = 868u } }, { 162u, 0u, { .s = 869u } }, { 162u, 0u, { .s = 870u } }, { 162u, 0u, { .s = 871u } }, { 162u, 0u, { .s = 872u } } }
};
const vader_array_t vader_data_7 = { { 8u, 0u, 0u, 0u, NULL }, 44u, 44u, 0u, (vader_array_buf_t*) &vader_data_7_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_8_e0_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(1) }
};
const vader_array_t vader_data_8_e0_f1 = { { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_8_e0_f1_buf };
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_8_e0 = { { 855u, 0u, 0u, 0u, NULL }, 1967u, (void*) (vader_array_t*) &vader_data_8_e0_f1, 2296u };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_8_e1_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) }
};
const vader_array_t vader_data_8_e1_f1 = { { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_8_e1_f1_buf };
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_8_e1 = { { 855u, 0u, 0u, 0u, NULL }, 1142u, (void*) (vader_array_t*) &vader_data_8_e1_f1, 2296u };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_8_e2_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) }
};
const vader_array_t vader_data_8_e2_f1 = { { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_8_e2_f1_buf };
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_8_e2 = { { 855u, 0u, 0u, 0u, NULL }, 2193u, (void*) (vader_array_t*) &vader_data_8_e2_f1, 2092u };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_8_e3_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) }
};
const vader_array_t vader_data_8_e3_f1 = { { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_8_e3_f1_buf };
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_8_e3 = { { 855u, 0u, 0u, 0u, NULL }, 2191u, (void*) (vader_array_t*) &vader_data_8_e3_f1, 2092u };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_8_e4_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) }
};
const vader_array_t vader_data_8_e4_f1 = { { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_8_e4_f1_buf };
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_8_e4 = { { 855u, 0u, 0u, 0u, NULL }, 1542u, (void*) (vader_array_t*) &vader_data_8_e4_f1, 2296u };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_8_e5_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) }
};
const vader_array_t vader_data_8_e5_f1 = { { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_8_e5_f1_buf };
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_8_e5 = { { 855u, 0u, 0u, 0u, NULL }, 2389u, (void*) (vader_array_t*) &vader_data_8_e5_f1, 2296u };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[2]; } vader_data_8_e6_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(1) }
};
const vader_array_t vader_data_8_e6_f1 = { { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_8_e6_f1_buf };
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_8_e6 = { { 855u, 0u, 0u, 0u, NULL }, 1544u, (void*) (vader_array_t*) &vader_data_8_e6_f1, 2296u };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[2]; } vader_data_8_e7_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0) }
};
const vader_array_t vader_data_8_e7_f1 = { { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_8_e7_f1_buf };
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_8_e7 = { { 855u, 0u, 0u, 0u, NULL }, 1950u, (void*) (vader_array_t*) &vader_data_8_e7_f1, 1233u };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_8_e8_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(1) }
};
const vader_array_t vader_data_8_e8_f1 = { { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_8_e8_f1_buf };
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_8_e8 = { { 855u, 0u, 0u, 0u, NULL }, 1550u, (void*) (vader_array_t*) &vader_data_8_e8_f1, 2092u };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_8_e9_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(1) }
};
const vader_array_t vader_data_8_e9_f1 = { { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_8_e9_f1_buf };
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_8_e9 = { { 855u, 0u, 0u, 0u, NULL }, 2195u, (void*) (vader_array_t*) &vader_data_8_e9_f1, 2172u };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_8_e10_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) }
};
const vader_array_t vader_data_8_e10_f1 = { { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_8_e10_f1_buf };
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_8_e10 = { { 855u, 0u, 0u, 0u, NULL }, 1549u, (void*) (vader_array_t*) &vader_data_8_e10_f1, 1541u };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[1]; } vader_data_8_e11_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(0) }
};
const vader_array_t vader_data_8_e11_f1 = { { 0u, 0u, 0u, 0u, NULL }, 1u, 1u, 0u, (vader_array_buf_t*) &vader_data_8_e11_f1_buf };
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_8_e11 = { { 855u, 0u, 0u, 0u, NULL }, 2185u, (void*) (vader_array_t*) &vader_data_8_e11_f1, 2186u };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; uint8_t slots[2]; } vader_data_8_e12_f1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 1u, { 0u, 0u, 0u },
    { (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(1) }
};
const vader_array_t vader_data_8_e12_f1 = { { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_8_e12_f1_buf };
const struct vader_struct_vader_parser_IntrinsicSpec_t vader_data_8_e12 = { { 855u, 0u, 0u, 0u, NULL }, 1533u, (void*) (vader_array_t*) &vader_data_8_e12_f1, 2296u };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[13]; } vader_data_8_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 13u, 13u, 855u, 0u, { 0u, 0u, 0u },
    { { 855u, 0u, { .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_8_e0 } }, { 855u, 0u, { .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_8_e1 } }, { 855u, 0u, { .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_8_e2 } }, { 855u, 0u, { .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_8_e3 } }, { 855u, 0u, { .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_8_e4 } }, { 855u, 0u, { .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_8_e5 } }, { 855u, 0u, { .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_8_e6 } }, { 855u, 0u, { .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_8_e7 } }, { 855u, 0u, { .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_8_e8 } }, { 855u, 0u, { .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_8_e9 } }, { 855u, 0u, { .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_8_e10 } }, { 855u, 0u, { .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_8_e11 } }, { 855u, 0u, { .obj = (void*) (struct vader_struct_vader_parser_IntrinsicSpec_t*) &vader_data_8_e12 } } }
};
const vader_array_t vader_data_8 = { { 79u, 0u, 0u, 0u, NULL }, 13u, 13u, 0u, (vader_array_buf_t*) &vader_data_8_buf };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e0 = { { 915u, 0u, 0u, 0u, NULL }, 1649u, (int64_t) UINT64_C(1), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e1 = { { 915u, 0u, 0u, 0u, NULL }, 1604u, (int64_t) UINT64_C(2), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e2 = { { 915u, 0u, 0u, 0u, NULL }, 1605u, (int64_t) UINT64_C(4), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e3 = { { 915u, 0u, 0u, 0u, NULL }, 1627u, (int64_t) UINT64_C(8), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e4 = { { 915u, 0u, 0u, 0u, NULL }, 1723u, (int64_t) UINT64_C(8), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e5 = { { 915u, 0u, 0u, 0u, NULL }, 2252u, (int64_t) UINT64_C(1), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e6 = { { 915u, 0u, 0u, 0u, NULL }, 2233u, (int64_t) UINT64_C(2), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e7 = { { 915u, 0u, 0u, 0u, NULL }, 2234u, (int64_t) UINT64_C(4), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e8 = { { 915u, 0u, 0u, 0u, NULL }, 2243u, (int64_t) UINT64_C(8), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e9 = { { 915u, 0u, 0u, 0u, NULL }, 2296u, (int64_t) UINT64_C(8), (uint8_t) UINT64_C(1), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e10 = { { 915u, 0u, 0u, 0u, NULL }, 1500u, (int64_t) UINT64_C(4), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(1) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e11 = { { 915u, 0u, 0u, 0u, NULL }, 1503u, (int64_t) UINT64_C(8), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(1) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e12 = { { 915u, 0u, 0u, 0u, NULL }, 1233u, (int64_t) UINT64_C(1), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e13 = { { 915u, 0u, 0u, 0u, NULL }, 1323u, (int64_t) UINT64_C(4), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e14 = { { 915u, 0u, 0u, 0u, NULL }, 2092u, (int64_t) UINT64_C(16), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e15 = { { 915u, 0u, 0u, 0u, NULL }, 2393u, (int64_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e16 = { { 915u, 0u, 0u, 0u, NULL }, 1865u, (int64_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0) };
const struct vader_struct_vader_types_PrimitiveMeta_t vader_data_9_e17 = { { 915u, 0u, 0u, 0u, NULL }, 572u, (int64_t) UINT64_C(8), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0), (uint8_t) UINT64_C(0) };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[18]; } vader_data_9_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 18u, 18u, 915u, 0u, { 0u, 0u, 0u },
    { { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e0 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e1 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e2 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e3 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e4 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e5 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e6 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e7 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e8 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e9 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e10 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e11 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e12 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e13 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e14 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e15 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e16 } }, { 915u, 0u, { .obj = (void*) (struct vader_struct_vader_types_PrimitiveMeta_t*) &vader_data_9_e17 } } }
};
const vader_array_t vader_data_9 = { { 100u, 0u, 0u, 0u, NULL }, 18u, 18u, 0u, (vader_array_buf_t*) &vader_data_9_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[2]; } vader_data_10_e0_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 0u, { 0u, 0u, 0u },
    { { 0u, 0u, { .s = 1685u } }, { 0u, 0u, { .s = 1605u } } }
};
const vader_array_t vader_data_10_e0 = { { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_10_e0_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[2]; } vader_data_10_e1_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 0u, { 0u, 0u, 0u },
    { { 0u, 0u, { .s = 1786u } }, { 0u, 0u, { .s = 1627u } } }
};
const vader_array_t vader_data_10_e1 = { { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_10_e1_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[2]; } vader_data_10_e2_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 0u, { 0u, 0u, 0u },
    { { 0u, 0u, { .s = 1554u } }, { 0u, 0u, { .s = 1500u } } }
};
const vader_array_t vader_data_10_e2 = { { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_10_e2_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[2]; } vader_data_10_e3_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 0u, { 0u, 0u, 0u },
    { { 0u, 0u, { .s = 1413u } }, { 0u, 0u, { .s = 1503u } } }
};
const vader_array_t vader_data_10_e3 = { { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_10_e3_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[2]; } vader_data_10_e4_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, 0u, { 0u, 0u, 0u },
    { { 0u, 0u, { .s = 1272u } }, { 0u, 0u, { .s = 2252u } } }
};
const vader_array_t vader_data_10_e4 = { { 0u, 0u, 0u, 0u, NULL }, 2u, 2u, 0u, (vader_array_buf_t*) &vader_data_10_e4_buf };
const struct { vader_obj_header_t header; size_t capacity; size_t length; uint32_t element_tag; uint8_t element_kind; uint8_t _pad[3]; vader_box_t slots[5]; } vader_data_10_buf = {
    { VADER_TYPE_INDEX_ARRAY_BUF, 0u, 0u, 0u, NULL }, 5u, 5u, 8u, 0u, { 0u, 0u, 0u },
    { { 8u, 0u, { .obj = (void*) (vader_array_t*) &vader_data_10_e0 } }, { 8u, 0u, { .obj = (void*) (vader_array_t*) &vader_data_10_e1 } }, { 8u, 0u, { .obj = (void*) (vader_array_t*) &vader_data_10_e2 } }, { 8u, 0u, { .obj = (void*) (vader_array_t*) &vader_data_10_e3 } }, { 8u, 0u, { .obj = (void*) (vader_array_t*) &vader_data_10_e4 } } }
};
const vader_array_t vader_data_10 = { { 1u, 0u, 0u, 0u, NULL }, 5u, 5u, 0u, (vader_array_buf_t*) &vader_data_10_buf };

const uint16_t vader_type_1_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_2_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_3_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_4_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_5_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_6_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_7_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_8_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_9_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_10_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_11_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_12_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_13_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_14_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_15_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_16_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_17_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_18_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_19_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_20_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_21_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_22_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_23_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_24_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_25_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_26_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_27_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_28_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_29_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_30_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_31_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_32_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_33_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_34_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_35_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_36_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_37_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_38_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_39_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_40_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_41_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_42_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_43_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_44_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_45_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_46_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_47_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_48_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_49_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_50_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_51_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_52_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_53_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_54_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_55_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_56_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_57_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_58_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_59_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_60_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_61_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_62_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_63_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_64_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_65_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_66_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_67_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_68_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_69_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_70_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_71_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_72_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_73_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_74_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_75_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_76_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_77_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_78_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_79_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_80_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_81_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_82_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_83_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_84_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_85_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_86_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_87_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_88_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_89_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_90_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_91_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_92_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_93_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_94_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_95_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_96_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_97_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_98_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_99_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_100_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_101_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_102_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_103_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_104_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_105_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_106_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_107_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_108_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_109_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_110_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_111_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_112_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_113_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_114_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_115_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_116_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_117_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_118_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_119_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_120_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_121_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_122_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_123_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_124_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_125_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_126_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_127_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_128_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_129_ptrs[] = { offsetof(vader_array_t, buf) };
const uint16_t vader_type_130_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_131_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_132_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_133_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_134_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_135_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_136_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_137_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_138_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_139_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_140_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_141_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_142_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_143_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_144_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_145_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_146_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_147_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_148_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_149_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_150_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_151_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_152_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_153_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_154_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_155_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_156_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_157_ptrs[] = { offsetof(vader_fn_t, env) };
const uint16_t vader_type_173_refs[] = { offsetof(vader_struct__Cell_Array_Struct_vader_bytecode_module_vader_1754____t, f_value) };
const uint16_t vader_type_174_refs[] = { offsetof(vader_struct__Cell_Array_Struct_vader_diagnostics_diagnostic_vader_598____t, f_value) };
const uint16_t vader_type_175_refs[] = { offsetof(vader_struct__Cell_Array_Struct_vader_types_types_vader_598____t, f_value) };
const uint16_t vader_type_176_refs[] = { offsetof(vader_struct__Cell_Array_Union_Struct_vader_lower_lowered_ast_vader_6883___Struct_vader_lower_lowered_ast_vader_6538___Struct_vader_lower_lowered_ast_vader_6766_____t, f_value) };
const uint16_t vader_type_177_refs[] = { offsetof(vader_struct__Cell_Array_bool__t, f_value) };
const uint16_t vader_type_178_refs[] = { offsetof(vader_struct__Cell_Array_i32__t, f_value) };
const uint16_t vader_type_179_refs[] = { offsetof(vader_struct__Cell_Array_string__t, f_value) };
const uint16_t vader_type_180_refs[] = { offsetof(vader_struct__Cell_Fn_Union_Struct_lib_toolchain_ast_ast_vader_41069___Struct_lib_toolchain_ast_ast_vader_35146___Struct_lib_toolchain_ast_ast_vader_29535___Struct_lib_toolchain_ast_ast_vader_32672___Struct_lib_toolchain_ast_ast_vader_25426___Struct_lib_toolchain_ast_ast_vader_27472___Struct_lib_toolchain_ast_ast_vader_35435___Struct_lib_toolchain_ast_ast_vader_25803___Struct_lib_toolchain_ast_ast_vader_36443___Struct_lib_toolchain_ast_ast_vader_28300___Struct_lib_toolchain_ast_ast_vader_25296___Struct_lib_toolchain_ast_ast_vader_40242___Struct_lib_toolchain_ast_ast_vader_35618___Struct_lib_toolchain_ast_ast_vader_27070___Struct_lib_toolchain_ast_ast_vader_30827___Struct_lib_toolchain_ast_ast_vader_28661___Struct_lib_toolchain_ast_ast_vader_24920___Struct_lib_toolchain_ast_ast_vader_36102___Struct_lib_toolchain_ast_ast_vader_32925___Struct_lib_toolchain_ast_ast_vader_31377___Struct_lib_toolchain_ast_ast_vader_41788___Struct_lib_toolchain_ast_ast_vader_30399___Struct_lib_toolchain_ast_ast_vader_25554___Struct_lib_toolchain_ast_ast_vader_34731___Struct_lib_toolchain_ast_ast_vader_34404___Struct_lib_toolchain_ast_ast_vader_26144___Struct_lib_toolchain_ast_ast_vader_33406___Struct_lib_toolchain_ast_ast_vader_29020____Union_Struct_vader_types_types_vader_3956___Struct_vader_types_types_vader_3074___Struct_vader_types_types_vader_1850___Struct_vader_types_types_vader_998___Struct_vader_types_types_vader_2423___Struct_vader_types_types_vader_4584___Struct_vader_types_types_vader_4158___Struct_vader_types_types_vader_4054___Struct_vader_types_types_vader_4689___null_Struct_vader_types_types_vader_545___Struct_vader_types_types_vader_3549___Struct_vader_types_types_vader_598___Struct_vader_types_types_vader_2238___Struct_vader_types_types_vader_3218___Struct_vader_types_types_vader_3516___Struct_vader_types_types_vader_3461___Struct_vader_types_types_vader_2308___Struct_vader_types_types_vader_3578____Struct_vader_typecheck_typed_ast_vader_4821___Array_Struct_vader_diagnostics_diagnostic_vader_598______Union_Struct_vader_types_types_vader_3956___Struct_vader_types_types_vader_3074___Struct_vader_types_types_vader_1850___Struct_vader_types_types_vader_998___Struct_vader_types_types_vader_2423___Struct_vader_types_types_vader_4584___Struct_vader_types_types_vader_4158___Struct_vader_types_types_vader_4054___Struct_vader_types_types_vader_4689___Struct_vader_types_types_vader_545___Struct_vader_types_types_vader_3549___Struct_vader_types_types_vader_598___Struct_vader_types_types_vader_2238___Struct_vader_types_types_vader_3218___Struct_vader_types_types_vader_3516___Struct_vader_types_types_vader_3461___Struct_vader_types_types_vader_2308___Struct_vader_types_types_vader_3578____t, f_value) };
const uint16_t vader_type_181_refs[] = { offsetof(vader_struct__Cell_Fn_i32___void_t, f_value) };
const uint16_t vader_type_182_refs[] = { offsetof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_13537_i32__t, f_value) };
const uint16_t vader_type_183_refs[] = { offsetof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_13537_string__t, f_value) };
const uint16_t vader_type_184_refs[] = { offsetof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_i32_Union_Struct_vader_lower_lowered_ast_vader_6883___Struct_vader_lower_lowered_ast_vader_6538___Struct_vader_lower_lowered_ast_vader_6766_____t, f_value) };
const uint16_t vader_type_185_refs[] = { offsetof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_i32_bool__t, f_value) };
const uint16_t vader_type_186_refs[] = { offsetof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_i32_i32__t, f_value) };
const uint16_t vader_type_187_refs[] = { offsetof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_string_Union_Struct_vader_lower_lowered_ast_vader_6883___Struct_vader_lower_lowered_ast_vader_6538___Struct_vader_lower_lowered_ast_vader_6766_____t, f_value) };
const uint16_t vader_type_188_refs[] = { offsetof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_string_bool__t, f_value) };
const uint16_t vader_type_189_refs[] = { offsetof(vader_struct__Cell_Struct_vader_typecheck_typed_ast_vader_4821___t, f_value) };
const uint16_t vader_type_190_ptrs[] = { offsetof(vader_struct__Cell_Union_Struct_vader_types_types_vader_3956___Struct_vader_types_types_vader_3074___Struct_vader_types_types_vader_1850___Struct_vader_types_types_vader_998___Struct_vader_types_types_vader_2423___Struct_vader_types_types_vader_4584___Struct_vader_types_types_vader_4158___Struct_vader_types_types_vader_4054___Struct_vader_types_types_vader_4689___null_Struct_vader_types_types_vader_545___Struct_vader_types_types_vader_3549___Struct_vader_types_types_vader_598___Struct_vader_types_types_vader_2238___Struct_vader_types_types_vader_3218___Struct_vader_types_types_vader_3516___Struct_vader_types_types_vader_3461___Struct_vader_types_types_vader_2308___Struct_vader_types_types_vader_3578____t, f_value) };
const uint16_t vader_type_193_strs[] = { offsetof(vader_struct___Tuple_1135_t, f__0) };
const uint16_t vader_type_193_refs[] = { offsetof(vader_struct___Tuple_1135_t, f__1) };
const uint16_t vader_type_194_strs[] = { offsetof(vader_struct___Tuple_1137_t, f__0) };
const uint16_t vader_type_194_refs[] = { offsetof(vader_struct___Tuple_1137_t, f__1) };
const uint16_t vader_type_195_strs[] = { offsetof(vader_struct___Tuple_1139_t, f__0) };
const uint16_t vader_type_195_refs[] = { offsetof(vader_struct___Tuple_1139_t, f__1) };
const uint16_t vader_type_196_strs[] = { offsetof(vader_struct___Tuple_1140_t, f__0), offsetof(vader_struct___Tuple_1140_t, f__1) };
const uint16_t vader_type_197_refs[] = { offsetof(vader_struct___Tuple_1142_t, f__1) };
const uint16_t vader_type_198_strs[] = { offsetof(vader_struct___Tuple_1146_t, f__0) };
const uint16_t vader_type_198_refs[] = { offsetof(vader_struct___Tuple_1146_t, f__1) };
const uint16_t vader_type_199_strs[] = { offsetof(vader_struct___Tuple_1149_t, f__0) };
const uint16_t vader_type_199_refs[] = { offsetof(vader_struct___Tuple_1149_t, f__1) };
const uint16_t vader_type_200_ptrs[] = { offsetof(vader_struct___Tuple_1150_t, f__1) };
const uint16_t vader_type_201_refs[] = { offsetof(vader_struct___Tuple_1152_t, f__1) };
const uint16_t vader_type_202_refs[] = { offsetof(vader_struct___Tuple_1154_t, f__1) };
const uint16_t vader_type_203_strs[] = { offsetof(vader_struct___Tuple_1155_t, f__1) };
const uint16_t vader_type_204_refs[] = { offsetof(vader_struct___Tuple_1157_t, f__1) };
const uint16_t vader_type_205_refs[] = { offsetof(vader_struct___Tuple_1159_t, f__1) };
const uint16_t vader_type_206_refs[] = { offsetof(vader_struct___Tuple_1162_t, f__1) };
const uint16_t vader_type_207_refs[] = { offsetof(vader_struct___Tuple_1163_t, f__1) };
const uint16_t vader_type_208_ptrs[] = { offsetof(vader_struct___Tuple_1164_t, f__1) };
const uint16_t vader_type_208_strs[] = { offsetof(vader_struct___Tuple_1164_t, f__0) };
const uint16_t vader_type_209_strs[] = { offsetof(vader_struct___Tuple_1169_t, f__0) };
const uint16_t vader_type_209_refs[] = { offsetof(vader_struct___Tuple_1169_t, f__1) };
const uint16_t vader_type_210_strs[] = { offsetof(vader_struct___Tuple_1174_t, f__0) };
const uint16_t vader_type_211_refs[] = { offsetof(vader_struct___Tuple_1184_t, f__1) };
const uint16_t vader_type_212_strs[] = { offsetof(vader_struct___Tuple_1211_t, f__0) };
const uint16_t vader_type_212_refs[] = { offsetof(vader_struct___Tuple_1211_t, f__1) };
const uint16_t vader_type_213_ptrs[] = { offsetof(vader_struct___Tuple_1213_t, f__1) };
const uint16_t vader_type_214_ptrs[] = { offsetof(vader_struct___Tuple_1214_t, f__1) };
const uint16_t vader_type_215_strs[] = { offsetof(vader_struct___Tuple_1216_t, f__0) };
const uint16_t vader_type_215_refs[] = { offsetof(vader_struct___Tuple_1216_t, f__1) };
const uint16_t vader_type_216_ptrs[] = { offsetof(vader_struct___Tuple_1218_t, f__1) };
const uint16_t vader_type_217_strs[] = { offsetof(vader_struct___Tuple_1229_t, f__0) };
const uint16_t vader_type_217_refs[] = { offsetof(vader_struct___Tuple_1229_t, f__1) };
const uint16_t vader_type_218_refs[] = { offsetof(vader_struct___Tuple_1231_t, f__1) };
const uint16_t vader_type_219_strs[] = { offsetof(vader_struct___Tuple_1234_t, f__0) };
const uint16_t vader_type_219_refs[] = { offsetof(vader_struct___Tuple_1234_t, f__1) };
const uint16_t vader_type_220_strs[] = { offsetof(vader_struct___Tuple_1254_t, f__0) };
const uint16_t vader_type_220_refs[] = { offsetof(vader_struct___Tuple_1254_t, f__1) };
const uint16_t vader_type_221_refs[] = { offsetof(vader_struct___Tuple_1260_t, f__1) };
const uint16_t vader_type_222_ptrs[] = { offsetof(vader_struct___Tuple_1270_t, f__1) };
const uint16_t vader_type_225_strs[] = { offsetof(vader_struct___Tuple_1276_t, f__0) };
const uint16_t vader_type_226_refs[] = { offsetof(vader_struct___Tuple_1277_t, f__1) };
const uint16_t vader_type_227_strs[] = { offsetof(vader_struct___Tuple_1282_t, f__0) };
const uint16_t vader_type_227_refs[] = { offsetof(vader_struct___Tuple_1282_t, f__1) };
const uint16_t vader_type_230_refs[] = { offsetof(vader_struct___Tuple_49_t, f__0) };
const uint16_t vader_type_232_ptrs[] = { offsetof(vader_struct___lambda_env_1361_t, f_cap_0) };
const uint16_t vader_type_234_ptrs[] = { offsetof(vader_struct___lambda_env_1647_t, f_cap_0), offsetof(vader_struct___lambda_env_1647_t, f_cap_1) };
const uint16_t vader_type_236_ptrs[] = { offsetof(vader_struct___lambda_env_1772_t, f_cap_0), offsetof(vader_struct___lambda_env_1772_t, f_cap_1) };
const uint16_t vader_type_237_ptrs[] = { offsetof(vader_struct___lambda_env_1775_t, f_cap_0), offsetof(vader_struct___lambda_env_1775_t, f_cap_1) };
const uint16_t vader_type_242_ptrs[] = { offsetof(vader_struct___lambda_env_210_t, f_cap_0), offsetof(vader_struct___lambda_env_210_t, f_cap_1), offsetof(vader_struct___lambda_env_210_t, f_cap_2), offsetof(vader_struct___lambda_env_210_t, f_cap_3), offsetof(vader_struct___lambda_env_210_t, f_cap_4) };
const uint16_t vader_type_243_ptrs[] = { offsetof(vader_struct___lambda_env_213_t, f_cap_0), offsetof(vader_struct___lambda_env_213_t, f_cap_1) };
const uint16_t vader_type_245_ptrs[] = { offsetof(vader_struct___lambda_env_2703_t, f_cap_0) };
const uint16_t vader_type_246_ptrs[] = { offsetof(vader_struct___lambda_env_2849_t, f_cap_0) };
const uint16_t vader_type_247_ptrs[] = { offsetof(vader_struct___lambda_env_2858_t, f_cap_0), offsetof(vader_struct___lambda_env_2858_t, f_cap_1) };
const uint16_t vader_type_248_ptrs[] = { offsetof(vader_struct___lambda_env_2865_t, f_cap_0), offsetof(vader_struct___lambda_env_2865_t, f_cap_1) };
const uint16_t vader_type_249_ptrs[] = { offsetof(vader_struct___lambda_env_2868_t, f_cap_0), offsetof(vader_struct___lambda_env_2868_t, f_cap_1) };
const uint16_t vader_type_252_ptrs[] = { offsetof(vader_struct___lambda_env_2898_t, f_cap_0) };
const uint16_t vader_type_253_ptrs[] = { offsetof(vader_struct___lambda_env_2906_t, f_cap_0), offsetof(vader_struct___lambda_env_2906_t, f_cap_1) };
const uint16_t vader_type_254_ptrs[] = { offsetof(vader_struct___lambda_env_2909_t, f_cap_0), offsetof(vader_struct___lambda_env_2909_t, f_cap_1) };
const uint16_t vader_type_270_ptrs[] = { offsetof(vader_struct___lambda_env_5171_t, f_cap_0), offsetof(vader_struct___lambda_env_5171_t, f_cap_1), offsetof(vader_struct___lambda_env_5171_t, f_cap_2), offsetof(vader_struct___lambda_env_5171_t, f_cap_3) };
const uint16_t vader_type_273_refs[] = { offsetof(vader_struct_json_JsonArray_t, f_items) };
const uint16_t vader_type_275_strs[] = { offsetof(vader_struct_json_JsonError_t, f_msg) };
const uint16_t vader_type_278_refs[] = { offsetof(vader_struct_json_JsonObject_t, f_entries) };
const uint16_t vader_type_279_strs[] = { offsetof(vader_struct_json_JsonString_t, f_value) };
const uint16_t vader_type_280_strs[] = { offsetof(vader_struct_json_Parser_t, f_src) };
const uint16_t vader_type_280_refs[] = { offsetof(vader_struct_json_Parser_t, f_bytes) };
const uint16_t vader_type_281_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__Any_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__Any_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__Any_t, f_index) };
const uint16_t vader_type_282_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_index) };
const uint16_t vader_type_283_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__Any___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__Any___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__Any___t, f_index) };
const uint16_t vader_type_284_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__ArrayClear___ArrayCopy___ArrayGet___ArrayLen___ArrayNew___ArrayPush___ArrayPushAll___ArrayRemoveLast___ArrayRepeat___ArraySet___ArraySlice___BitsToF32___BitsToF64___Block___BoolAnd___BoolConst___BoolEq___BoolNe___BoolNot___BoolOr___Box___Branch___BranchIf___BufferNew___BufferToString___BufferWriteString___Call___CallImport___CallIndirect___CharConst___Convert___DataConst___DeferPopExec___DeferPush___Drop___Else___End___F32ToBits___F64Add___F64Const___F64Div___F64Eq___F64Ge___F64Gt___F64Le___F64Lt___F64Mul___F64Ne___F64Neg___F64Sub___F64ToBits___FnRef___I32Add___I32BitAnd___I32BitNot___I32BitOr___I32BitXor___I32Const___I32Div___I32Eq___I32Ge___I32Gt___I32Le___I32Lt___I32Mod___I32Mul___I32Ne___I32Neg___I32Shl___I32Shr___I32ShrU___I32Sub___I64Add___I64BitAnd___I64BitNot___I64BitOr___I64BitXor___I64Const___I64Div___I64Eq___I64Ge___I64Gt___I64Le___I64Lt___I64Mod___I64Mul___I64Ne___I64Neg___I64Shl___I64Shr___I64ShrU___I64Sub___If___LoadF64___LoadI32___LoadI64___LoadSlotF64___LoadSlotI32___LoadSlotI64___LoadU8___LocalField___LocalGet___LocalSet___LocalTee___Loop___MakeClosure___MemoryCopy___NullConst___RefCast___RefEq___RefNe___Return___ReturnLit___SizeOfType___StoreF64___StoreI32___StoreI64___StoreSlotF64___StoreSlotI32___StoreSlotI64___StoreU8___StringConst___StringEq___StringNe___StringSliceCodepoints___StructGet___StructNew___StructSet___TypeCheck___TypeConst___U32Div___U32Ge___U32Gt___U32Le___U32Lt___U32Mod___U64Div___U64Ge___U64Gt___U64Le___U64Lt___U64Mod___Unreachable___VirtualCall_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ArrayClear___ArrayCopy___ArrayGet___ArrayLen___ArrayNew___ArrayPush___ArrayPushAll___ArrayRemoveLast___ArrayRepeat___ArraySet___ArraySlice___BitsToF32___BitsToF64___Block___BoolAnd___BoolConst___BoolEq___BoolNe___BoolNot___BoolOr___Box___Branch___BranchIf___BufferNew___BufferToString___BufferWriteString___Call___CallImport___CallIndirect___CharConst___Convert___DataConst___DeferPopExec___DeferPush___Drop___Else___End___F32ToBits___F64Add___F64Const___F64Div___F64Eq___F64Ge___F64Gt___F64Le___F64Lt___F64Mul___F64Ne___F64Neg___F64Sub___F64ToBits___FnRef___I32Add___I32BitAnd___I32BitNot___I32BitOr___I32BitXor___I32Const___I32Div___I32Eq___I32Ge___I32Gt___I32Le___I32Lt___I32Mod___I32Mul___I32Ne___I32Neg___I32Shl___I32Shr___I32ShrU___I32Sub___I64Add___I64BitAnd___I64BitNot___I64BitOr___I64BitXor___I64Const___I64Div___I64Eq___I64Ge___I64Gt___I64Le___I64Lt___I64Mod___I64Mul___I64Ne___I64Neg___I64Shl___I64Shr___I64ShrU___I64Sub___If___LoadF64___LoadI32___LoadI64___LoadSlotF64___LoadSlotI32___LoadSlotI64___LoadU8___LocalField___LocalGet___LocalSet___LocalTee___Loop___MakeClosure___MemoryCopy___NullConst___RefCast___RefEq___RefNe___Return___ReturnLit___SizeOfType___StoreF64___StoreI32___StoreI64___StoreSlotF64___StoreSlotI32___StoreSlotI64___StoreU8___StringConst___StringEq___StringNe___StringSliceCodepoints___StructGet___StructNew___StructSet___TypeCheck___TypeConst___U32Div___U32Ge___U32Gt___U32Le___U32Lt___U32Mod___U64Div___U64Ge___U64Gt___U64Le___U64Lt___U64Mod___Unreachable___VirtualCall_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ArrayClear___ArrayCopy___ArrayGet___ArrayLen___ArrayNew___ArrayPush___ArrayPushAll___ArrayRemoveLast___ArrayRepeat___ArraySet___ArraySlice___BitsToF32___BitsToF64___Block___BoolAnd___BoolConst___BoolEq___BoolNe___BoolNot___BoolOr___Box___Branch___BranchIf___BufferNew___BufferToString___BufferWriteString___Call___CallImport___CallIndirect___CharConst___Convert___DataConst___DeferPopExec___DeferPush___Drop___Else___End___F32ToBits___F64Add___F64Const___F64Div___F64Eq___F64Ge___F64Gt___F64Le___F64Lt___F64Mul___F64Ne___F64Neg___F64Sub___F64ToBits___FnRef___I32Add___I32BitAnd___I32BitNot___I32BitOr___I32BitXor___I32Const___I32Div___I32Eq___I32Ge___I32Gt___I32Le___I32Lt___I32Mod___I32Mul___I32Ne___I32Neg___I32Shl___I32Shr___I32ShrU___I32Sub___I64Add___I64BitAnd___I64BitNot___I64BitOr___I64BitXor___I64Const___I64Div___I64Eq___I64Ge___I64Gt___I64Le___I64Lt___I64Mod___I64Mul___I64Ne___I64Neg___I64Shl___I64Shr___I64ShrU___I64Sub___If___LoadF64___LoadI32___LoadI64___LoadSlotF64___LoadSlotI32___LoadSlotI64___LoadU8___LocalField___LocalGet___LocalSet___LocalTee___Loop___MakeClosure___MemoryCopy___NullConst___RefCast___RefEq___RefNe___Return___ReturnLit___SizeOfType___StoreF64___StoreI32___StoreI64___StoreSlotF64___StoreSlotI32___StoreSlotI64___StoreU8___StringConst___StringEq___StringNe___StringSliceCodepoints___StructGet___StructNew___StructSet___TypeCheck___TypeConst___U32Div___U32Ge___U32Gt___U32Le___U32Lt___U32Mod___U64Div___U64Ge___U64Gt___U64Le___U64Lt___U64Mod___Unreachable___VirtualCall_t, f_index) };
const uint16_t vader_type_285_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_index) };
const uint16_t vader_type_286_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t, f_index) };
const uint16_t vader_type_287_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__ClosureAlias_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ClosureAlias_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ClosureAlias_t, f_index) };
const uint16_t vader_type_288_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__ConstDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ConstDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ConstDecl_t, f_index) };
const uint16_t vader_type_289_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__ConstFnWrap_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ConstFnWrap_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ConstFnWrap_t, f_index) };
const uint16_t vader_type_290_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__FnDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__FnDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__FnDecl_t, f_index) };
const uint16_t vader_type_291_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__ImportInfo_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ImportInfo_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ImportInfo_t, f_index) };
const uint16_t vader_type_292_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t, f_index) };
const uint16_t vader_type_293_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t, f_index) };
const uint16_t vader_type_294_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__LoweredFnDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredFnDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredFnDecl_t, f_index) };
const uint16_t vader_type_295_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__LoweredIdent_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredIdent_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__LoweredIdent_t, f_index) };
const uint16_t vader_type_296_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t, f_index) };
const uint16_t vader_type_297_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t, f_index) };
const uint16_t vader_type_298_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t, f_index) };
const uint16_t vader_type_299_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t, f_index) };
const uint16_t vader_type_300_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t, f_index) };
const uint16_t vader_type_301_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__NarrowSlot_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__NarrowSlot_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__NarrowSlot_t, f_index) };
const uint16_t vader_type_302_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__ResolvedModule_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__ResolvedModule_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__ResolvedModule_t, f_index) };
const uint16_t vader_type_303_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__StructDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__StructDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__StructDecl_t, f_index) };
const uint16_t vader_type_304_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__Symbol_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__Symbol_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__Symbol_t, f_index) };
const uint16_t vader_type_305_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__SymbolTarget_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__SymbolTarget_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__SymbolTarget_t, f_index) };
const uint16_t vader_type_306_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__TraitDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__TraitDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__TraitDecl_t, f_index) };
const uint16_t vader_type_307_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__TypeAliasDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__TypeAliasDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__TypeAliasDecl_t, f_index) };
const uint16_t vader_type_308_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__bool_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__bool_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__bool_t, f_index) };
const uint16_t vader_type_309_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__i32_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__i32_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__i32_t, f_index) };
const uint16_t vader_type_310_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__i32___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__i32___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__i32___t, f_index) };
const uint16_t vader_type_311_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__i32___null_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__i32___null_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__i32___null_t, f_index) };
const uint16_t vader_type_312_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__string_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__string_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__string_t, f_index) };
const uint16_t vader_type_313_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__string___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__string___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__string___t, f_index) };
const uint16_t vader_type_314_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i32__usize_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i32__usize_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i32__usize_t, f_index) };
const uint16_t vader_type_315_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i64__Any_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i64__Any_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i64__Any_t, f_index) };
const uint16_t vader_type_316_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i64__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i64__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i64__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_index) };
const uint16_t vader_type_317_refs[] = { offsetof(vader_struct_std_collections_MutableMap__i64__bool_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__i64__bool_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__i64__bool_t, f_index) };
const uint16_t vader_type_318_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__Any_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__Any_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__Any_t, f_index) };
const uint16_t vader_type_319_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_index) };
const uint16_t vader_type_320_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__Any___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__Any___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__Any___t, f_index) };
const uint16_t vader_type_321_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t, f_index) };
const uint16_t vader_type_322_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t, f_index) };
const uint16_t vader_type_323_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__CFGModule_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__CFGModule_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__CFGModule_t, f_index) };
const uint16_t vader_type_324_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__Capture___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__Capture___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__Capture___t, f_index) };
const uint16_t vader_type_325_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__DiscoveredModule_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__DiscoveredModule_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__DiscoveredModule_t, f_index) };
const uint16_t vader_type_326_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__EvaluatedProgram_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__EvaluatedProgram_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__EvaluatedProgram_t, f_index) };
const uint16_t vader_type_327_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__FnDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__FnDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__FnDecl_t, f_index) };
const uint16_t vader_type_328_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__FnDecl___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__FnDecl___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__FnDecl___t, f_index) };
const uint16_t vader_type_329_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__FnParam___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__FnParam___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__FnParam___t, f_index) };
const uint16_t vader_type_330_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__FnType___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__FnType___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__FnType___t, f_index) };
const uint16_t vader_type_331_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__GenericFnInstance_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__GenericFnInstance_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__GenericFnInstance_t, f_index) };
const uint16_t vader_type_332_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__GenericInstance_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__GenericInstance_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__GenericInstance_t, f_index) };
const uint16_t vader_type_333_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__ImplEntry_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__ImplEntry_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__ImplEntry_t, f_index) };
const uint16_t vader_type_334_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__ImplMethod_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__ImplMethod_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__ImplMethod_t, f_index) };
const uint16_t vader_type_335_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__InlineInfo_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__InlineInfo_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__InlineInfo_t, f_index) };
const uint16_t vader_type_336_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__JsonArray___JsonBool___JsonNull___JsonNumber___JsonObject___JsonString_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__JsonArray___JsonBool___JsonNull___JsonNumber___JsonObject___JsonString_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__JsonArray___JsonBool___JsonNull___JsonNumber___JsonObject___JsonString_t, f_index) };
const uint16_t vader_type_337_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__LoadedModule_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__LoadedModule_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__LoadedModule_t, f_index) };
const uint16_t vader_type_338_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t, f_index) };
const uint16_t vader_type_339_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__LoweredFnDecl_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__LoweredFnDecl_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__LoweredFnDecl_t, f_index) };
const uint16_t vader_type_340_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__LoweredModule_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__LoweredModule_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__LoweredModule_t, f_index) };
const uint16_t vader_type_341_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any__t, f_index) };
const uint16_t vader_type_342_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any____t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any____t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any____t, f_index) };
const uint16_t vader_type_343_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t, f_index) };
const uint16_t vader_type_344_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnParam____t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnParam____t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnParam____t, f_index) };
const uint16_t vader_type_345_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnType____t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnType____t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnType____t, f_index) };
const uint16_t vader_type_346_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t, f_index) };
const uint16_t vader_type_347_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_____t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_____t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_____t, f_index) };
const uint16_t vader_type_348_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t, f_index) };
const uint16_t vader_type_349_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_u64__Symbol__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_u64__Symbol__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableMap_u64__Symbol__t, f_index) };
const uint16_t vader_type_350_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__MutableSet_i32__t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__MutableSet_i32__t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__MutableSet_i32__t, f_index) };
const uint16_t vader_type_351_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__NarrowSlot_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__NarrowSlot_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__NarrowSlot_t, f_index) };
const uint16_t vader_type_352_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__Span_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__Span_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__Span_t, f_index) };
const uint16_t vader_type_353_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__Symbol_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__Symbol_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__Symbol_t, f_index) };
const uint16_t vader_type_354_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__Symbol___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__Symbol___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__Symbol___t, f_index) };
const uint16_t vader_type_355_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__TypedProgram_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__TypedProgram_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__TypedProgram_t, f_index) };
const uint16_t vader_type_356_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType____t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType____t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType____t, f_index) };
const uint16_t vader_type_357_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__bool_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__bool_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__bool_t, f_index) };
const uint16_t vader_type_358_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__i32_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__i32_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__i32_t, f_index) };
const uint16_t vader_type_359_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__i32___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__i32___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__i32___t, f_index) };
const uint16_t vader_type_360_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__i64_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__i64_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__i64_t, f_index) };
const uint16_t vader_type_361_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__string_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__string_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__string_t, f_index) };
const uint16_t vader_type_362_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__string___t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__string___t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__string___t, f_index) };
const uint16_t vader_type_363_refs[] = { offsetof(vader_struct_std_collections_MutableMap__string__usize_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__string__usize_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__string__usize_t, f_index) };
const uint16_t vader_type_364_refs[] = { offsetof(vader_struct_std_collections_MutableMap__u64__Any_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__Any_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__Any_t, f_index) };
const uint16_t vader_type_365_refs[] = { offsetof(vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_index) };
const uint16_t vader_type_366_refs[] = { offsetof(vader_struct_std_collections_MutableMap__u64__Symbol_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__Symbol_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__Symbol_t, f_index) };
const uint16_t vader_type_367_refs[] = { offsetof(vader_struct_std_collections_MutableMap__u64__usize_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__u64__usize_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__u64__usize_t, f_index) };
const uint16_t vader_type_368_refs[] = { offsetof(vader_struct_std_collections_MutableMap__usize__Any_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__Any_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__Any_t, f_index) };
const uint16_t vader_type_369_refs[] = { offsetof(vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t, f_index) };
const uint16_t vader_type_370_refs[] = { offsetof(vader_struct_std_collections_MutableMap__usize__NodeRecord_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__NodeRecord_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__NodeRecord_t, f_index) };
const uint16_t vader_type_371_refs[] = { offsetof(vader_struct_std_collections_MutableMap__usize__Span_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__Span_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__Span_t, f_index) };
const uint16_t vader_type_372_refs[] = { offsetof(vader_struct_std_collections_MutableMap__usize__bool_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__bool_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__bool_t, f_index) };
const uint16_t vader_type_373_refs[] = { offsetof(vader_struct_std_collections_MutableMap__usize__i32_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__i32_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__i32_t, f_index) };
const uint16_t vader_type_374_refs[] = { offsetof(vader_struct_std_collections_MutableMap__usize__string_t, f_ekeys), offsetof(vader_struct_std_collections_MutableMap__usize__string_t, f_evals), offsetof(vader_struct_std_collections_MutableMap__usize__string_t, f_index) };
const uint16_t vader_type_375_refs[] = { offsetof(vader_struct_std_collections_MutableSet__i32_t, f_inner) };
const uint16_t vader_type_376_refs[] = { offsetof(vader_struct_std_collections_MutableSet__i64_t, f_inner) };
const uint16_t vader_type_377_refs[] = { offsetof(vader_struct_std_collections_MutableSet__string_t, f_inner) };
const uint16_t vader_type_381_refs[] = { offsetof(vader_struct_std_core_SlowParts_t, f_d) };
const uint16_t vader_type_383_strs[] = { offsetof(vader_struct_std_io_IOError_t, f_msg) };
const uint16_t vader_type_384_strs[] = { offsetof(vader_struct_std_string_ParseError_t, f_msg) };
const uint16_t vader_type_385_refs[] = { offsetof(vader_struct_std_string_StringChars_t, f_bytes) };
const uint16_t vader_type_386_refs[] = { offsetof(vader_struct_std_string_builder_StringBuilder_t, f_parts) };
const uint16_t vader_type_387_ptrs[] = { offsetof(vader_struct_toolchain_ast_ArrayTypeExpr_t, f_element) };
const uint16_t vader_type_387_refs[] = { offsetof(vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span) };
const uint16_t vader_type_388_ptrs[] = { offsetof(vader_struct_toolchain_ast_AssertDecl_t, f_condition), offsetof(vader_struct_toolchain_ast_AssertDecl_t, f_message) };
const uint16_t vader_type_388_refs[] = { offsetof(vader_struct_toolchain_ast_AssertDecl_t, f_span), offsetof(vader_struct_toolchain_ast_AssertDecl_t, f_decorators) };
const uint16_t vader_type_389_ptrs[] = { offsetof(vader_struct_toolchain_ast_AssignStmt_t, f_target), offsetof(vader_struct_toolchain_ast_AssignStmt_t, f_value) };
const uint16_t vader_type_389_refs[] = { offsetof(vader_struct_toolchain_ast_AssignStmt_t, f_span) };
const uint16_t vader_type_390_ptrs[] = { offsetof(vader_struct_toolchain_ast_AwaitExpr_t, f_inner) };
const uint16_t vader_type_390_refs[] = { offsetof(vader_struct_toolchain_ast_AwaitExpr_t, f_span) };
const uint16_t vader_type_391_ptrs[] = { offsetof(vader_struct_toolchain_ast_BinaryExpr_t, f_left), offsetof(vader_struct_toolchain_ast_BinaryExpr_t, f_right) };
const uint16_t vader_type_391_strs[] = { offsetof(vader_struct_toolchain_ast_BinaryExpr_t, f_bind_as) };
const uint16_t vader_type_391_refs[] = { offsetof(vader_struct_toolchain_ast_BinaryExpr_t, f_span) };
const uint16_t vader_type_392_strs[] = { offsetof(vader_struct_toolchain_ast_BindingPattern_t, f_name) };
const uint16_t vader_type_392_refs[] = { offsetof(vader_struct_toolchain_ast_BindingPattern_t, f_span) };
const uint16_t vader_type_393_ptrs[] = { offsetof(vader_struct_toolchain_ast_BlockExpr_t, f_trailing) };
const uint16_t vader_type_393_refs[] = { offsetof(vader_struct_toolchain_ast_BlockExpr_t, f_span), offsetof(vader_struct_toolchain_ast_BlockExpr_t, f_stmts) };
const uint16_t vader_type_394_refs[] = { offsetof(vader_struct_toolchain_ast_BoolLitExpr_t, f_span) };
const uint16_t vader_type_395_ptrs[] = { offsetof(vader_struct_toolchain_ast_BreakStmt_t, f_label) };
const uint16_t vader_type_395_refs[] = { offsetof(vader_struct_toolchain_ast_BreakStmt_t, f_span) };
const uint16_t vader_type_396_ptrs[] = { offsetof(vader_struct_toolchain_ast_CallArg_t, f_name), offsetof(vader_struct_toolchain_ast_CallArg_t, f_value) };
const uint16_t vader_type_396_refs[] = { offsetof(vader_struct_toolchain_ast_CallArg_t, f_span) };
const uint16_t vader_type_397_ptrs[] = { offsetof(vader_struct_toolchain_ast_CallExpr_t, f_callee) };
const uint16_t vader_type_397_refs[] = { offsetof(vader_struct_toolchain_ast_CallExpr_t, f_span), offsetof(vader_struct_toolchain_ast_CallExpr_t, f_args) };
const uint16_t vader_type_398_ptrs[] = { offsetof(vader_struct_toolchain_ast_CastExpr_t, f_target), offsetof(vader_struct_toolchain_ast_CastExpr_t, f_value) };
const uint16_t vader_type_398_refs[] = { offsetof(vader_struct_toolchain_ast_CastExpr_t, f_span) };
const uint16_t vader_type_399_refs[] = { offsetof(vader_struct_toolchain_ast_CharLitExpr_t, f_span) };
const uint16_t vader_type_400_ptrs[] = { offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_ty), offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_value), offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_comptime_body) };
const uint16_t vader_type_400_strs[] = { offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_name) };
const uint16_t vader_type_400_refs[] = { offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_span), offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_name_span), offsetof(vader_struct_toolchain_ast_ConstDecl_t, f_decorators) };
const uint16_t vader_type_401_ptrs[] = { offsetof(vader_struct_toolchain_ast_ContinueStmt_t, f_label) };
const uint16_t vader_type_401_refs[] = { offsetof(vader_struct_toolchain_ast_ContinueStmt_t, f_span) };
const uint16_t vader_type_402_strs[] = { offsetof(vader_struct_toolchain_ast_Decorator_t, f_name) };
const uint16_t vader_type_402_refs[] = { offsetof(vader_struct_toolchain_ast_Decorator_t, f_span), offsetof(vader_struct_toolchain_ast_Decorator_t, f_args) };
const uint16_t vader_type_403_refs[] = { offsetof(vader_struct_toolchain_ast_DeferBlockBody_t, f_block) };
const uint16_t vader_type_404_ptrs[] = { offsetof(vader_struct_toolchain_ast_DeferStmt_t, f_body) };
const uint16_t vader_type_404_refs[] = { offsetof(vader_struct_toolchain_ast_DeferStmt_t, f_span) };
const uint16_t vader_type_405_ptrs[] = { offsetof(vader_struct_toolchain_ast_DeferStmtBody_t, f_stmt) };
const uint16_t vader_type_406_refs[] = { offsetof(vader_struct_toolchain_ast_DestructureImport_t, f_names) };
const uint16_t vader_type_407_ptrs[] = { offsetof(vader_struct_toolchain_ast_DestructureVar_t, f_pattern) };
const uint16_t vader_type_409_strs[] = { offsetof(vader_struct_toolchain_ast_DotVariantExpr_t, f_variant) };
const uint16_t vader_type_409_refs[] = { offsetof(vader_struct_toolchain_ast_DotVariantExpr_t, f_span), offsetof(vader_struct_toolchain_ast_DotVariantExpr_t, f_variant_span) };
const uint16_t vader_type_410_ptrs[] = { offsetof(vader_struct_toolchain_ast_EnumDecl_t, f_repr) };
const uint16_t vader_type_410_strs[] = { offsetof(vader_struct_toolchain_ast_EnumDecl_t, f_name) };
const uint16_t vader_type_410_refs[] = { offsetof(vader_struct_toolchain_ast_EnumDecl_t, f_span), offsetof(vader_struct_toolchain_ast_EnumDecl_t, f_name_span), offsetof(vader_struct_toolchain_ast_EnumDecl_t, f_variants), offsetof(vader_struct_toolchain_ast_EnumDecl_t, f_decorators) };
const uint16_t vader_type_411_ptrs[] = { offsetof(vader_struct_toolchain_ast_EnumVariant_t, f_value), offsetof(vader_struct_toolchain_ast_EnumVariant_t, f_value_span) };
const uint16_t vader_type_411_strs[] = { offsetof(vader_struct_toolchain_ast_EnumVariant_t, f_name) };
const uint16_t vader_type_411_refs[] = { offsetof(vader_struct_toolchain_ast_EnumVariant_t, f_span) };
const uint16_t vader_type_412_strs[] = { offsetof(vader_struct_toolchain_ast_EnumVariantPattern_t, f_variant) };
const uint16_t vader_type_412_refs[] = { offsetof(vader_struct_toolchain_ast_EnumVariantPattern_t, f_span) };
const uint16_t vader_type_413_ptrs[] = { offsetof(vader_struct_toolchain_ast_ExprStmt_t, f_expr) };
const uint16_t vader_type_413_refs[] = { offsetof(vader_struct_toolchain_ast_ExprStmt_t, f_span) };
const uint16_t vader_type_414_ptrs[] = { offsetof(vader_struct_toolchain_ast_FieldExpr_t, f_target) };
const uint16_t vader_type_414_strs[] = { offsetof(vader_struct_toolchain_ast_FieldExpr_t, f_field) };
const uint16_t vader_type_414_refs[] = { offsetof(vader_struct_toolchain_ast_FieldExpr_t, f_span), offsetof(vader_struct_toolchain_ast_FieldExpr_t, f_field_span) };
const uint16_t vader_type_415_refs[] = { offsetof(vader_struct_toolchain_ast_FloatLitExpr_t, f_span) };
const uint16_t vader_type_416_ptrs[] = { offsetof(vader_struct_toolchain_ast_FnDecl_t, f_return_type), offsetof(vader_struct_toolchain_ast_FnDecl_t, f_body) };
const uint16_t vader_type_416_strs[] = { offsetof(vader_struct_toolchain_ast_FnDecl_t, f_name) };
const uint16_t vader_type_416_refs[] = { offsetof(vader_struct_toolchain_ast_FnDecl_t, f_span), offsetof(vader_struct_toolchain_ast_FnDecl_t, f_name_span), offsetof(vader_struct_toolchain_ast_FnDecl_t, f_type_params), offsetof(vader_struct_toolchain_ast_FnDecl_t, f_params), offsetof(vader_struct_toolchain_ast_FnDecl_t, f_decorators) };
const uint16_t vader_type_417_ptrs[] = { offsetof(vader_struct_toolchain_ast_FnParam_t, f_ty), offsetof(vader_struct_toolchain_ast_FnParam_t, f_default_value) };
const uint16_t vader_type_417_strs[] = { offsetof(vader_struct_toolchain_ast_FnParam_t, f_name) };
const uint16_t vader_type_417_refs[] = { offsetof(vader_struct_toolchain_ast_FnParam_t, f_span), offsetof(vader_struct_toolchain_ast_FnParam_t, f_decorators) };
const uint16_t vader_type_418_ptrs[] = { offsetof(vader_struct_toolchain_ast_FnTypeExpr_t, f_return_type) };
const uint16_t vader_type_418_refs[] = { offsetof(vader_struct_toolchain_ast_FnTypeExpr_t, f_span), offsetof(vader_struct_toolchain_ast_FnTypeExpr_t, f_params), offsetof(vader_struct_toolchain_ast_FnTypeExpr_t, f_params_mutable) };
const uint16_t vader_type_419_ptrs[] = { offsetof(vader_struct_toolchain_ast_ForStmt_t, f_label), offsetof(vader_struct_toolchain_ast_ForStmt_t, f_form) };
const uint16_t vader_type_419_refs[] = { offsetof(vader_struct_toolchain_ast_ForStmt_t, f_span), offsetof(vader_struct_toolchain_ast_ForStmt_t, f_body) };
const uint16_t vader_type_420_ptrs[] = { offsetof(vader_struct_toolchain_ast_GenericInstExpr_t, f_callee) };
const uint16_t vader_type_420_refs[] = { offsetof(vader_struct_toolchain_ast_GenericInstExpr_t, f_span), offsetof(vader_struct_toolchain_ast_GenericInstExpr_t, f_type_args) };
const uint16_t vader_type_421_strs[] = { offsetof(vader_struct_toolchain_ast_IdentExpr_t, f_name) };
const uint16_t vader_type_421_refs[] = { offsetof(vader_struct_toolchain_ast_IdentExpr_t, f_span) };
const uint16_t vader_type_422_refs[] = { offsetof(vader_struct_toolchain_ast_IfElseBlock_t, f_block) };
const uint16_t vader_type_423_refs[] = { offsetof(vader_struct_toolchain_ast_IfElseIf_t, f_branch) };
const uint16_t vader_type_424_ptrs[] = { offsetof(vader_struct_toolchain_ast_IfExpr_t, f_cond), offsetof(vader_struct_toolchain_ast_IfExpr_t, f_else_branch) };
const uint16_t vader_type_424_refs[] = { offsetof(vader_struct_toolchain_ast_IfExpr_t, f_span), offsetof(vader_struct_toolchain_ast_IfExpr_t, f_then_block) };
const uint16_t vader_type_425_ptrs[] = { offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_for_type) };
const uint16_t vader_type_425_strs[] = { offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_trait_name) };
const uint16_t vader_type_425_refs[] = { offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_span), offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_type_params), offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_trait_name_span), offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_trait_args), offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_members), offsetof(vader_struct_toolchain_ast_ImplDecl_t, f_decorators) };
const uint16_t vader_type_426_ptrs[] = { offsetof(vader_struct_toolchain_ast_ImportDecl_t, f_binding) };
const uint16_t vader_type_426_strs[] = { offsetof(vader_struct_toolchain_ast_ImportDecl_t, f_path) };
const uint16_t vader_type_426_refs[] = { offsetof(vader_struct_toolchain_ast_ImportDecl_t, f_span), offsetof(vader_struct_toolchain_ast_ImportDecl_t, f_decorators) };
const uint16_t vader_type_427_ptrs[] = { offsetof(vader_struct_toolchain_ast_ImportName_t, f_alias) };
const uint16_t vader_type_427_strs[] = { offsetof(vader_struct_toolchain_ast_ImportName_t, f_name) };
const uint16_t vader_type_427_refs[] = { offsetof(vader_struct_toolchain_ast_ImportName_t, f_span) };
const uint16_t vader_type_428_ptrs[] = { offsetof(vader_struct_toolchain_ast_InFor_t, f_loop_var), offsetof(vader_struct_toolchain_ast_InFor_t, f_iter) };
const uint16_t vader_type_429_ptrs[] = { offsetof(vader_struct_toolchain_ast_IndexExpr_t, f_target), offsetof(vader_struct_toolchain_ast_IndexExpr_t, f_index) };
const uint16_t vader_type_429_refs[] = { offsetof(vader_struct_toolchain_ast_IndexExpr_t, f_span) };
const uint16_t vader_type_431_refs[] = { offsetof(vader_struct_toolchain_ast_IntLitExpr_t, f_span) };
const uint16_t vader_type_432_strs[] = { offsetof(vader_struct_toolchain_ast_IntrinsicCallExpr_t, f_name) };
const uint16_t vader_type_432_refs[] = { offsetof(vader_struct_toolchain_ast_IntrinsicCallExpr_t, f_span), offsetof(vader_struct_toolchain_ast_IntrinsicCallExpr_t, f_name_span), offsetof(vader_struct_toolchain_ast_IntrinsicCallExpr_t, f_args) };
const uint16_t vader_type_433_ptrs[] = { offsetof(vader_struct_toolchain_ast_IsPattern_t, f_ty), offsetof(vader_struct_toolchain_ast_IsPattern_t, f_inner), offsetof(vader_struct_toolchain_ast_IsPattern_t, f_bind_as) };
const uint16_t vader_type_433_refs[] = { offsetof(vader_struct_toolchain_ast_IsPattern_t, f_span) };
const uint16_t vader_type_434_ptrs[] = { offsetof(vader_struct_toolchain_ast_LambdaExpr_t, f_return_type) };
const uint16_t vader_type_434_refs[] = { offsetof(vader_struct_toolchain_ast_LambdaExpr_t, f_span), offsetof(vader_struct_toolchain_ast_LambdaExpr_t, f_params), offsetof(vader_struct_toolchain_ast_LambdaExpr_t, f_body) };
const uint16_t vader_type_435_ptrs[] = { offsetof(vader_struct_toolchain_ast_LetStmt_t, f_binding), offsetof(vader_struct_toolchain_ast_LetStmt_t, f_ty), offsetof(vader_struct_toolchain_ast_LetStmt_t, f_value) };
const uint16_t vader_type_435_refs[] = { offsetof(vader_struct_toolchain_ast_LetStmt_t, f_span) };
const uint16_t vader_type_436_ptrs[] = { offsetof(vader_struct_toolchain_ast_LiteralPattern_t, f_value) };
const uint16_t vader_type_436_refs[] = { offsetof(vader_struct_toolchain_ast_LiteralPattern_t, f_span) };
const uint16_t vader_type_437_ptrs[] = { offsetof(vader_struct_toolchain_ast_MatchArm_t, f_pattern), offsetof(vader_struct_toolchain_ast_MatchArm_t, f_guard), offsetof(vader_struct_toolchain_ast_MatchArm_t, f_body) };
const uint16_t vader_type_437_refs[] = { offsetof(vader_struct_toolchain_ast_MatchArm_t, f_span) };
const uint16_t vader_type_438_ptrs[] = { offsetof(vader_struct_toolchain_ast_MatchExpr_t, f_scrutinee) };
const uint16_t vader_type_438_refs[] = { offsetof(vader_struct_toolchain_ast_MatchExpr_t, f_span), offsetof(vader_struct_toolchain_ast_MatchExpr_t, f_arms) };
const uint16_t vader_type_439_strs[] = { offsetof(vader_struct_toolchain_ast_ModuleDecl_t, f_name) };
const uint16_t vader_type_439_refs[] = { offsetof(vader_struct_toolchain_ast_ModuleDecl_t, f_span), offsetof(vader_struct_toolchain_ast_ModuleDecl_t, f_name_span) };
const uint16_t vader_type_440_ptrs[] = { offsetof(vader_struct_toolchain_ast_MutableTypeExpr_t, f_inner) };
const uint16_t vader_type_440_refs[] = { offsetof(vader_struct_toolchain_ast_MutableTypeExpr_t, f_span) };
const uint16_t vader_type_441_strs[] = { offsetof(vader_struct_toolchain_ast_NamedNamespaceImport_t, f_name) };
const uint16_t vader_type_442_strs[] = { offsetof(vader_struct_toolchain_ast_NamedVar_t, f_name) };
const uint16_t vader_type_442_refs[] = { offsetof(vader_struct_toolchain_ast_NamedVar_t, f_span) };
const uint16_t vader_type_443_ptrs[] = { offsetof(vader_struct_toolchain_ast_NullCoalesceExpr_t, f_left), offsetof(vader_struct_toolchain_ast_NullCoalesceExpr_t, f_fallback) };
const uint16_t vader_type_443_refs[] = { offsetof(vader_struct_toolchain_ast_NullCoalesceExpr_t, f_span) };
const uint16_t vader_type_444_refs[] = { offsetof(vader_struct_toolchain_ast_NullLitExpr_t, f_span) };
const uint16_t vader_type_445_refs[] = { offsetof(vader_struct_toolchain_ast_OrPattern_t, f_span), offsetof(vader_struct_toolchain_ast_OrPattern_t, f_patterns) };
const uint16_t vader_type_446_strs[] = { offsetof(vader_struct_toolchain_ast_PatternBinding_t, f_name) };
const uint16_t vader_type_446_refs[] = { offsetof(vader_struct_toolchain_ast_PatternBinding_t, f_span) };
const uint16_t vader_type_447_ptrs[] = { offsetof(vader_struct_toolchain_ast_PatternLiteral_t, f_value) };
const uint16_t vader_type_448_ptrs[] = { offsetof(vader_struct_toolchain_ast_Program_t, f_module) };
const uint16_t vader_type_448_strs[] = { offsetof(vader_struct_toolchain_ast_Program_t, f_file) };
const uint16_t vader_type_448_refs[] = { offsetof(vader_struct_toolchain_ast_Program_t, f_span), offsetof(vader_struct_toolchain_ast_Program_t, f_decls) };
const uint16_t vader_type_449_ptrs[] = { offsetof(vader_struct_toolchain_ast_RangeExpr_t, f_lower), offsetof(vader_struct_toolchain_ast_RangeExpr_t, f_upper) };
const uint16_t vader_type_449_refs[] = { offsetof(vader_struct_toolchain_ast_RangeExpr_t, f_span) };
const uint16_t vader_type_450_ptrs[] = { offsetof(vader_struct_toolchain_ast_RangePattern_t, f_lower), offsetof(vader_struct_toolchain_ast_RangePattern_t, f_upper) };
const uint16_t vader_type_450_refs[] = { offsetof(vader_struct_toolchain_ast_RangePattern_t, f_span) };
const uint16_t vader_type_451_strs[] = { offsetof(vader_struct_toolchain_ast_RestBinding_t, f_name) };
const uint16_t vader_type_451_refs[] = { offsetof(vader_struct_toolchain_ast_RestBinding_t, f_span), offsetof(vader_struct_toolchain_ast_RestBinding_t, f_name_span) };
const uint16_t vader_type_452_ptrs[] = { offsetof(vader_struct_toolchain_ast_ReturnStmt_t, f_value) };
const uint16_t vader_type_452_refs[] = { offsetof(vader_struct_toolchain_ast_ReturnStmt_t, f_span) };
const uint16_t vader_type_453_refs[] = { offsetof(vader_struct_toolchain_ast_SeqLitExpr_t, f_span), offsetof(vader_struct_toolchain_ast_SeqLitExpr_t, f_elements) };
const uint16_t vader_type_454_strs[] = { offsetof(vader_struct_toolchain_ast_SimpleBinding_t, f_name) };
const uint16_t vader_type_454_refs[] = { offsetof(vader_struct_toolchain_ast_SimpleBinding_t, f_span), offsetof(vader_struct_toolchain_ast_SimpleBinding_t, f_name_span) };
const uint16_t vader_type_455_refs[] = { offsetof(vader_struct_toolchain_ast_StringLitExpr_t, f_span), offsetof(vader_struct_toolchain_ast_StringLitExpr_t, f_parts) };
const uint16_t vader_type_456_ptrs[] = { offsetof(vader_struct_toolchain_ast_StringLitInterp_t, f_expr) };
const uint16_t vader_type_456_refs[] = { offsetof(vader_struct_toolchain_ast_StringLitInterp_t, f_span) };
const uint16_t vader_type_457_strs[] = { offsetof(vader_struct_toolchain_ast_StringLitText_t, f_value) };
const uint16_t vader_type_457_refs[] = { offsetof(vader_struct_toolchain_ast_StringLitText_t, f_span) };
const uint16_t vader_type_458_strs[] = { offsetof(vader_struct_toolchain_ast_StructDecl_t, f_name) };
const uint16_t vader_type_458_refs[] = { offsetof(vader_struct_toolchain_ast_StructDecl_t, f_span), offsetof(vader_struct_toolchain_ast_StructDecl_t, f_name_span), offsetof(vader_struct_toolchain_ast_StructDecl_t, f_type_params), offsetof(vader_struct_toolchain_ast_StructDecl_t, f_fields), offsetof(vader_struct_toolchain_ast_StructDecl_t, f_decorators) };
const uint16_t vader_type_459_ptrs[] = { offsetof(vader_struct_toolchain_ast_StructField_t, f_ty), offsetof(vader_struct_toolchain_ast_StructField_t, f_default_v) };
const uint16_t vader_type_459_strs[] = { offsetof(vader_struct_toolchain_ast_StructField_t, f_name) };
const uint16_t vader_type_459_refs[] = { offsetof(vader_struct_toolchain_ast_StructField_t, f_span) };
const uint16_t vader_type_460_ptrs[] = { offsetof(vader_struct_toolchain_ast_StructLitExpr_t, f_type_name) };
const uint16_t vader_type_460_refs[] = { offsetof(vader_struct_toolchain_ast_StructLitExpr_t, f_span), offsetof(vader_struct_toolchain_ast_StructLitExpr_t, f_items) };
const uint16_t vader_type_461_ptrs[] = { offsetof(vader_struct_toolchain_ast_StructLitField_t, f_value) };
const uint16_t vader_type_461_strs[] = { offsetof(vader_struct_toolchain_ast_StructLitField_t, f_name) };
const uint16_t vader_type_461_refs[] = { offsetof(vader_struct_toolchain_ast_StructLitField_t, f_span), offsetof(vader_struct_toolchain_ast_StructLitField_t, f_name_span) };
const uint16_t vader_type_462_ptrs[] = { offsetof(vader_struct_toolchain_ast_StructLitSpread_t, f_expr) };
const uint16_t vader_type_462_refs[] = { offsetof(vader_struct_toolchain_ast_StructLitSpread_t, f_span) };
const uint16_t vader_type_463_refs[] = { offsetof(vader_struct_toolchain_ast_StructPattern_t, f_span), offsetof(vader_struct_toolchain_ast_StructPattern_t, f_fields) };
const uint16_t vader_type_464_ptrs[] = { offsetof(vader_struct_toolchain_ast_StructPatternField_t, f_value) };
const uint16_t vader_type_464_strs[] = { offsetof(vader_struct_toolchain_ast_StructPatternField_t, f_name) };
const uint16_t vader_type_464_refs[] = { offsetof(vader_struct_toolchain_ast_StructPatternField_t, f_span), offsetof(vader_struct_toolchain_ast_StructPatternField_t, f_name_span) };
const uint16_t vader_type_465_ptrs[] = { offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_requires) };
const uint16_t vader_type_465_strs[] = { offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_name) };
const uint16_t vader_type_465_refs[] = { offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_span), offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_name_span), offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_type_params), offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_members), offsetof(vader_struct_toolchain_ast_TraitDecl_t, f_decorators) };
const uint16_t vader_type_466_refs[] = { offsetof(vader_struct_toolchain_ast_TupleBinding_t, f_span), offsetof(vader_struct_toolchain_ast_TupleBinding_t, f_elements) };
const uint16_t vader_type_467_refs[] = { offsetof(vader_struct_toolchain_ast_TuplePattern_t, f_span), offsetof(vader_struct_toolchain_ast_TuplePattern_t, f_elements) };
const uint16_t vader_type_468_ptrs[] = { offsetof(vader_struct_toolchain_ast_TypeAliasDecl_t, f_aliased) };
const uint16_t vader_type_468_strs[] = { offsetof(vader_struct_toolchain_ast_TypeAliasDecl_t, f_name) };
const uint16_t vader_type_468_refs[] = { offsetof(vader_struct_toolchain_ast_TypeAliasDecl_t, f_span), offsetof(vader_struct_toolchain_ast_TypeAliasDecl_t, f_name_span), offsetof(vader_struct_toolchain_ast_TypeAliasDecl_t, f_type_params), offsetof(vader_struct_toolchain_ast_TypeAliasDecl_t, f_decorators) };
const uint16_t vader_type_469_ptrs[] = { offsetof(vader_struct_toolchain_ast_TypeParam_t, f_bound), offsetof(vader_struct_toolchain_ast_TypeParam_t, f_default_v) };
const uint16_t vader_type_469_strs[] = { offsetof(vader_struct_toolchain_ast_TypeParam_t, f_name) };
const uint16_t vader_type_469_refs[] = { offsetof(vader_struct_toolchain_ast_TypeParam_t, f_span) };
const uint16_t vader_type_470_ptrs[] = { offsetof(vader_struct_toolchain_ast_UnaryExpr_t, f_operand) };
const uint16_t vader_type_470_refs[] = { offsetof(vader_struct_toolchain_ast_UnaryExpr_t, f_span) };
const uint16_t vader_type_471_ptrs[] = { offsetof(vader_struct_toolchain_ast_WhileFor_t, f_cond) };
const uint16_t vader_type_472_refs[] = { offsetof(vader_struct_toolchain_ast_WildcardBinding_t, f_span) };
const uint16_t vader_type_474_refs[] = { offsetof(vader_struct_toolchain_ast_WildcardPattern_t, f_span) };
const uint16_t vader_type_475_ptrs[] = { offsetof(vader_struct_toolchain_ast_YieldStmt_t, f_value) };
const uint16_t vader_type_475_refs[] = { offsetof(vader_struct_toolchain_ast_YieldStmt_t, f_span) };
const uint16_t vader_type_476_strs[] = { offsetof(vader_struct_toolchain_span_Position_t, f_file) };
const uint16_t vader_type_477_refs[] = { offsetof(vader_struct_toolchain_span_Span_t, f_start), offsetof(vader_struct_toolchain_span_Span_t, f_end) };
const uint16_t vader_type_478_strs[] = { offsetof(vader_struct_vader_bootstrap_CfgBytecode_t, f_entry) };
const uint16_t vader_type_478_refs[] = { offsetof(vader_struct_vader_bootstrap_CfgBytecode_t, f_pre_diags), offsetof(vader_struct_vader_bootstrap_CfgBytecode_t, f_lower_diags), offsetof(vader_struct_vader_bootstrap_CfgBytecode_t, f_module) };
const uint16_t vader_type_479_refs[] = { offsetof(vader_struct_vader_bootstrap_EvaluatedPipeline_t, f_loaded), offsetof(vader_struct_vader_bootstrap_EvaluatedPipeline_t, f_typed), offsetof(vader_struct_vader_bootstrap_EvaluatedPipeline_t, f_evaluated), offsetof(vader_struct_vader_bootstrap_EvaluatedPipeline_t, f_resolver_diags), offsetof(vader_struct_vader_bootstrap_EvaluatedPipeline_t, f_typecheck_diags), offsetof(vader_struct_vader_bootstrap_EvaluatedPipeline_t, f_comptime_diags) };
const uint16_t vader_type_480_strs[] = { offsetof(vader_struct_vader_bootstrap_LoweredEntry_t, f_entry) };
const uint16_t vader_type_480_refs[] = { offsetof(vader_struct_vader_bootstrap_LoweredEntry_t, f_lowered), offsetof(vader_struct_vader_bootstrap_LoweredEntry_t, f_pre_diags), offsetof(vader_struct_vader_bootstrap_LoweredEntry_t, f_lower_diags) };
const uint16_t vader_type_492_strs[] = { offsetof(vader_struct_vader_bytecode_BcAggregateData_t, f_element_type_name) };
const uint16_t vader_type_492_refs[] = { offsetof(vader_struct_vader_bytecode_BcAggregateData_t, f_elements) };
const uint16_t vader_type_494_strs[] = { offsetof(vader_struct_vader_bytecode_BcExport_t, f_extern_name) };
const uint16_t vader_type_495_strs[] = { offsetof(vader_struct_vader_bytecode_BcField_t, f_name) };
const uint16_t vader_type_496_refs[] = { offsetof(vader_struct_vader_bytecode_BcFn_t, f_params) };
const uint16_t vader_type_497_strs[] = { offsetof(vader_struct_vader_bytecode_BcFunction_t, f_name) };
const uint16_t vader_type_497_refs[] = { offsetof(vader_struct_vader_bytecode_BcFunction_t, f_signature), offsetof(vader_struct_vader_bytecode_BcFunction_t, f_locals), offsetof(vader_struct_vader_bytecode_BcFunction_t, f_body), offsetof(vader_struct_vader_bytecode_BcFunction_t, f_debug), offsetof(vader_struct_vader_bytecode_BcFunction_t, f_jump_table) };
const uint16_t vader_type_498_strs[] = { offsetof(vader_struct_vader_bytecode_BcImport_t, f_extern_name), offsetof(vader_struct_vader_bytecode_BcImport_t, f_mangled_name), offsetof(vader_struct_vader_bytecode_BcImport_t, f_c_header), offsetof(vader_struct_vader_bytecode_BcImport_t, f_c_library) };
const uint16_t vader_type_498_refs[] = { offsetof(vader_struct_vader_bytecode_BcImport_t, f_signature) };
const uint16_t vader_type_499_strs[] = { offsetof(vader_struct_vader_bytecode_BcLocal_t, f_name) };
const uint16_t vader_type_500_refs[] = { offsetof(vader_struct_vader_bytecode_BcPeepholeOut_t, f_body), offsetof(vader_struct_vader_bytecode_BcPeepholeOut_t, f_jump_table), offsetof(vader_struct_vader_bytecode_BcPeepholeOut_t, f_debug) };
const uint16_t vader_type_501_refs[] = { offsetof(vader_struct_vader_bytecode_BcPrimData_t, f_items) };
const uint16_t vader_type_503_strs[] = { offsetof(vader_struct_vader_bytecode_BcRef_t, f_trait_name) };
const uint16_t vader_type_504_refs[] = { offsetof(vader_struct_vader_bytecode_BcSignature_t, f_params), offsetof(vader_struct_vader_bytecode_BcSignature_t, f_param_types), offsetof(vader_struct_vader_bytecode_BcSignature_t, f_param_names), offsetof(vader_struct_vader_bytecode_BcSignature_t, f_param_mutable), offsetof(vader_struct_vader_bytecode_BcSignature_t, f_param_by_address) };
const uint16_t vader_type_505_refs[] = { offsetof(vader_struct_vader_bytecode_BcStrData_t, f_values) };
const uint16_t vader_type_506_strs[] = { offsetof(vader_struct_vader_bytecode_BcStruct_t, f_name) };
const uint16_t vader_type_506_refs[] = { offsetof(vader_struct_vader_bytecode_BcStruct_t, f_fields) };
const uint16_t vader_type_507_refs[] = { offsetof(vader_struct_vader_bytecode_BcUnion_t, f_variants) };
const uint16_t vader_type_508_strs[] = { offsetof(vader_struct_vader_bytecode_BcValArray_t, f_element_type_name) };
const uint16_t vader_type_508_refs[] = { offsetof(vader_struct_vader_bytecode_BcValArray_t, f_elements) };
const uint16_t vader_type_510_strs[] = { offsetof(vader_struct_vader_bytecode_BcValStr_t, f_value) };
const uint16_t vader_type_511_refs[] = { offsetof(vader_struct_vader_bytecode_BcValStruct_t, f_fields) };
const uint16_t vader_type_527_strs[] = { offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_name) };
const uint16_t vader_type_527_refs[] = { offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_types), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_strings), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_data_pool), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_functions), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_imports), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_exports), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_impl_table), offsetof(vader_struct_vader_bytecode_BytecodeModule_t, f_vtables) };
const uint16_t vader_type_532_strs[] = { offsetof(vader_struct_vader_bytecode_Convert_t, f_from_name) };
const uint16_t vader_type_534_strs[] = { offsetof(vader_struct_vader_bytecode_DebugPos_t, f_file) };
const uint16_t vader_type_539_refs[] = { offsetof(vader_struct_vader_bytecode_EmitOptions_t, f_keep_mangles) };
const uint16_t vader_type_540_refs[] = { offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_types), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_type_key), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_strings), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_string_key), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_functions), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_function_index_by_symbol_id), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_function_index_by_mangle), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_imports), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_import_index_by_symbol_id), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_import_index_by_mangle), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_exports), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_pinned_types), offsetof(vader_struct_vader_bytecode_EmitterCtx_t, f_pinned_types_by_fn) };
const uint16_t vader_type_598_strs[] = { offsetof(vader_struct_vader_bytecode_ImplEntry_t, f_trait_name) };
const uint16_t vader_type_618_ptrs[] = { offsetof(vader_struct_vader_bytecode_ReturnLit_t, f_value) };
const uint16_t vader_type_649_strs[] = { offsetof(vader_struct_vader_bytecode_Unreachable_t, f_reason) };
const uint16_t vader_type_650_strs[] = { offsetof(vader_struct_vader_bytecode_VirtualCall_t, f_vtable_key) };
const uint16_t vader_type_652_strs[] = { offsetof(vader_struct_vader_bytecode_VtableRow_t, f_key) };
const uint16_t vader_type_652_refs[] = { offsetof(vader_struct_vader_bytecode_VtableRow_t, f_entries) };
const uint16_t vader_type_653_refs[] = { offsetof(vader_struct_vader_c_emit_BranchTargets_t, f_continue_targets), offsetof(vader_struct_vader_c_emit_BranchTargets_t, f_break_targets) };
const uint16_t vader_type_654_strs[] = { offsetof(vader_struct_vader_c_emit_CProgram_t, f_header), offsetof(vader_struct_vader_c_emit_CProgram_t, f_imports), offsetof(vader_struct_vader_c_emit_CProgram_t, f_globals) };
const uint16_t vader_type_654_refs[] = { offsetof(vader_struct_vader_c_emit_CProgram_t, f_units), offsetof(vader_struct_vader_c_emit_CProgram_t, f_unit_names) };
const uint16_t vader_type_655_strs[] = { offsetof(vader_struct_vader_c_emit_CoalesceResult_t, f_body) };
const uint16_t vader_type_655_refs[] = { offsetof(vader_struct_vader_c_emit_CoalesceResult_t, f_types) };
const uint16_t vader_type_656_strs[] = { offsetof(vader_struct_vader_c_emit_CopyLine_t, f_local) };
const uint16_t vader_type_657_strs[] = { offsetof(vader_struct_vader_c_emit_DefLine_t, f_indent), offsetof(vader_struct_vader_c_emit_DefLine_t, f_expr) };
const uint16_t vader_type_658_refs[] = { offsetof(vader_struct_vader_c_emit_EmitCtx_t, f_module), offsetof(vader_struct_vader_c_emit_EmitCtx_t, f_struct_c_names), offsetof(vader_struct_vader_c_emit_EmitCtx_t, f_atom_ids), offsetof(vader_struct_vader_c_emit_EmitCtx_t, f_atom_table), offsetof(vader_struct_vader_c_emit_EmitCtx_t, f_may_alloc), offsetof(vader_struct_vader_c_emit_EmitCtx_t, f_internal_fns) };
const uint16_t vader_type_659_strs[] = { offsetof(vader_struct_vader_c_emit_EmitOptions_t, f_entry_mangled) };
const uint16_t vader_type_659_refs[] = { offsetof(vader_struct_vader_c_emit_EmitOptions_t, f_atom_universe) };
const uint16_t vader_type_660_refs[] = { offsetof(vader_struct_vader_c_emit_FnState_t, f_ctx), offsetof(vader_struct_vader_c_emit_FnState_t, f_function), offsetof(vader_struct_vader_c_emit_FnState_t, f_out), offsetof(vader_struct_vader_c_emit_FnState_t, f_stack), offsetof(vader_struct_vader_c_emit_FnState_t, f_tmp_types), offsetof(vader_struct_vader_c_emit_FnState_t, f_scopes), offsetof(vader_struct_vader_c_emit_FnState_t, f_continue_targets), offsetof(vader_struct_vader_c_emit_FnState_t, f_break_targets), offsetof(vader_struct_vader_c_emit_FnState_t, f_resolved_arrays), offsetof(vader_struct_vader_c_emit_FnState_t, f_pinned_resolves), offsetof(vader_struct_vader_c_emit_FnState_t, f_stack_storages) };
const uint16_t vader_type_661_refs[] = { offsetof(vader_struct_vader_c_emit_FnValueUsage_t, f_fn_ref_type), offsetof(vader_struct_vader_c_emit_FnValueUsage_t, f_is_closure) };
const uint16_t vader_type_663_strs[] = { offsetof(vader_struct_vader_c_emit_SlotFill_t, f_cty) };
const uint16_t vader_type_665_strs[] = { offsetof(vader_struct_vader_c_emit_StackExpr_t, f_text) };
const uint16_t vader_type_666_strs[] = { offsetof(vader_struct_vader_c_emit_StackLit_t, f_text) };
const uint16_t vader_type_668_strs[] = { offsetof(vader_struct_vader_c_emit_StackStorage_t, f_cname), offsetof(vader_struct_vader_c_emit_StackStorage_t, f_storage) };
const uint16_t vader_type_669_strs[] = { offsetof(vader_struct_vader_c_emit_StackTmp_t, f_name) };
const uint16_t vader_type_670_refs[] = { offsetof(vader_struct_vader_c_emit_StructOffsets_t, f_ptr_offsets), offsetof(vader_struct_vader_c_emit_StructOffsets_t, f_str_offsets), offsetof(vader_struct_vader_c_emit_StructOffsets_t, f_ref_offsets) };
const uint16_t vader_type_671_strs[] = { offsetof(vader_struct_vader_comptime_ArrayValue_t, f_element_type_name) };
const uint16_t vader_type_671_refs[] = { offsetof(vader_struct_vader_comptime_ArrayValue_t, f_elements) };
const uint16_t vader_type_674_refs[] = { offsetof(vader_struct_vader_comptime_ComptimeContext_t, f_typed), offsetof(vader_struct_vader_comptime_ComptimeContext_t, f_bindings) };
const uint16_t vader_type_675_refs[] = { offsetof(vader_struct_vader_comptime_ComptimeOrder_t, f_order), offsetof(vader_struct_vader_comptime_ComptimeOrder_t, f_cycle_diags) };
const uint16_t vader_type_676_ptrs[] = { offsetof(vader_struct_vader_comptime_EvalResult_t, f_value), offsetof(vader_struct_vader_comptime_EvalResult_t, f_diag) };
const uint16_t vader_type_677_refs[] = { offsetof(vader_struct_vader_comptime_EvaluatedProgram_t, f_typed), offsetof(vader_struct_vader_comptime_EvaluatedProgram_t, f_comptime_decls) };
const uint16_t vader_type_678_refs[] = { offsetof(vader_struct_vader_comptime_EvaluatedProject_t, f_typed), offsetof(vader_struct_vader_comptime_EvaluatedProject_t, f_modules), offsetof(vader_struct_vader_comptime_EvaluatedProject_t, f_file_baked_consts), offsetof(vader_struct_vader_comptime_EvaluatedProject_t, f_file_exprs), offsetof(vader_struct_vader_comptime_EvaluatedProject_t, f_instances), offsetof(vader_struct_vader_comptime_EvaluatedProject_t, f_vm_required) };
const uint16_t vader_type_679_strs[] = { offsetof(vader_struct_vader_comptime_FloatValue_t, f_type_name) };
const uint16_t vader_type_680_strs[] = { offsetof(vader_struct_vader_comptime_GenericInstance_t, f_display_key) };
const uint16_t vader_type_680_refs[] = { offsetof(vader_struct_vader_comptime_GenericInstance_t, f_symbol), offsetof(vader_struct_vader_comptime_GenericInstance_t, f_args) };
const uint16_t vader_type_681_refs[] = { offsetof(vader_struct_vader_comptime_InstanceRegistry_t, f_by_key), offsetof(vader_struct_vader_comptime_InstanceRegistry_t, f_order) };
const uint16_t vader_type_682_strs[] = { offsetof(vader_struct_vader_comptime_IntValue_t, f_type_name) };
const uint16_t vader_type_683_ptrs[] = { offsetof(vader_struct_vader_comptime_MonoEntry_t, f_decl), offsetof(vader_struct_vader_comptime_MonoEntry_t, f_symbol), offsetof(vader_struct_vader_comptime_MonoEntry_t, f_module) };
const uint16_t vader_type_683_strs[] = { offsetof(vader_struct_vader_comptime_MonoEntry_t, f_mangled) };
const uint16_t vader_type_683_refs[] = { offsetof(vader_struct_vader_comptime_MonoEntry_t, f_subst), offsetof(vader_struct_vader_comptime_MonoEntry_t, f_type_arguments) };
const uint16_t vader_type_684_refs[] = { offsetof(vader_struct_vader_comptime_NodeRecord_t, f_decl), offsetof(vader_struct_vader_comptime_NodeRecord_t, f_dependency_ids) };
const uint16_t vader_type_685_refs[] = { offsetof(vader_struct_vader_comptime_Nodes_t, f_by_id), offsetof(vader_struct_vader_comptime_Nodes_t, f_order), offsetof(vader_struct_vader_comptime_Nodes_t, f_by_symbol) };
const uint16_t vader_type_687_strs[] = { offsetof(vader_struct_vader_comptime_StringValue_t, f_value) };
const uint16_t vader_type_688_strs[] = { offsetof(vader_struct_vader_comptime_StructValue_t, f_type_name) };
const uint16_t vader_type_688_refs[] = { offsetof(vader_struct_vader_comptime_StructValue_t, f_fields) };
const uint16_t vader_type_689_ptrs[] = { offsetof(vader_struct_vader_comptime_TypeValue_t, f_value) };
const uint16_t vader_type_690_ptrs[] = { offsetof(vader_struct_vader_comptime_VmRequiredDecl_t, f_decl_type) };
const uint16_t vader_type_690_strs[] = { offsetof(vader_struct_vader_comptime_VmRequiredDecl_t, f_module_id), offsetof(vader_struct_vader_comptime_VmRequiredDecl_t, f_callee_name) };
const uint16_t vader_type_690_refs[] = { offsetof(vader_struct_vader_comptime_VmRequiredDecl_t, f_span) };
const uint16_t vader_type_692_strs[] = { offsetof(vader_struct_vader_diagnostics_CodeInfo_t, f_id), offsetof(vader_struct_vader_diagnostics_CodeInfo_t, f_message) };
const uint16_t vader_type_693_strs[] = { offsetof(vader_struct_vader_diagnostics_Diagnostic_t, f_detail) };
const uint16_t vader_type_693_refs[] = { offsetof(vader_struct_vader_diagnostics_Diagnostic_t, f_code), offsetof(vader_struct_vader_diagnostics_Diagnostic_t, f_primary) };
const uint16_t vader_type_695_strs[] = { offsetof(vader_struct_vader_lexer_Lexer_t, f_src), offsetof(vader_struct_vader_lexer_Lexer_t, f_file) };
const uint16_t vader_type_695_refs[] = { offsetof(vader_struct_vader_lexer_Lexer_t, f_bytes), offsetof(vader_struct_vader_lexer_Lexer_t, f_tokens), offsetof(vader_struct_vader_lexer_Lexer_t, f_errors), offsetof(vader_struct_vader_lexer_Lexer_t, f_interp_stack) };
const uint16_t vader_type_696_ptrs[] = { offsetof(vader_struct_vader_lexer_Token_t, f_value) };
const uint16_t vader_type_696_strs[] = { offsetof(vader_struct_vader_lexer_Token_t, f_text) };
const uint16_t vader_type_696_refs[] = { offsetof(vader_struct_vader_lexer_Token_t, f_span) };
const uint16_t vader_type_697_strs[] = { offsetof(vader_struct_vader_lower_AggregateDataPoolEntry_t, f_element_type_name) };
const uint16_t vader_type_697_refs[] = { offsetof(vader_struct_vader_lower_AggregateDataPoolEntry_t, f_literal) };
const uint16_t vader_type_698_refs[] = { offsetof(vader_struct_vader_lower_AnalyzeCtx_t, f_aliases), offsetof(vader_struct_vader_lower_AnalyzeCtx_t, f_closures), offsetof(vader_struct_vader_lower_AnalyzeCtx_t, f_escaped), offsetof(vader_struct_vader_lower_AnalyzeCtx_t, f_bound) };
const uint16_t vader_type_699_refs[] = { offsetof(vader_struct_vader_lower_BcePurityCtx_t, f_by_mangle), offsetof(vader_struct_vader_lower_BcePurityCtx_t, f_by_symid), offsetof(vader_struct_vader_lower_BcePurityCtx_t, f_memo) };
const uint16_t vader_type_700_refs[] = { offsetof(vader_struct_vader_lower_BlockCtx_t, f_defers) };
const uint16_t vader_type_701_ptrs[] = { offsetof(vader_struct_vader_lower_BodyTemplate_t, f_element_type), offsetof(vader_struct_vader_lower_BodyTemplate_t, f_pattern) };
const uint16_t vader_type_701_strs[] = { offsetof(vader_struct_vader_lower_BodyTemplate_t, f_binding_name) };
const uint16_t vader_type_701_refs[] = { offsetof(vader_struct_vader_lower_BodyTemplate_t, f_binding_symbol), offsetof(vader_struct_vader_lower_BodyTemplate_t, f_user_body) };
const uint16_t vader_type_702_ptrs[] = { offsetof(vader_struct_vader_lower_BveCtx_t, f_usize_ty), offsetof(vader_struct_vader_lower_BveCtx_t, f_u8_ty) };
const uint16_t vader_type_702_refs[] = { offsetof(vader_struct_vader_lower_BveCtx_t, f_byte_len_sym), offsetof(vader_struct_vader_lower_BveCtx_t, f_byte_at_sym), offsetof(vader_struct_vader_lower_BveCtx_t, f_candidates), offsetof(vader_struct_vader_lower_BveCtx_t, f_disq), offsetof(vader_struct_vader_lower_BveCtx_t, f_bound), offsetof(vader_struct_vader_lower_BveCtx_t, f_reassigned) };
const uint16_t vader_type_703_ptrs[] = { offsetof(vader_struct_vader_lower_Capture_t, f_type) };
const uint16_t vader_type_703_refs[] = { offsetof(vader_struct_vader_lower_Capture_t, f_symbol) };
const uint16_t vader_type_704_ptrs[] = { offsetof(vader_struct_vader_lower_CellInit_t, f_value), offsetof(vader_struct_vader_lower_CellInit_t, f_slot_type) };
const uint16_t vader_type_705_ptrs[] = { offsetof(vader_struct_vader_lower_ClosureAlias_t, f_env_type) };
const uint16_t vader_type_705_refs[] = { offsetof(vader_struct_vader_lower_ClosureAlias_t, f_fn_sym) };
const uint16_t vader_type_706_refs[] = { offsetof(vader_struct_vader_lower_ClosureAnalysis_t, f_captured_symbols), offsetof(vader_struct_vader_lower_ClosureAnalysis_t, f_lambda_captures), offsetof(vader_struct_vader_lower_ClosureAnalysis_t, f_defer_captures) };
const uint16_t vader_type_707_strs[] = { offsetof(vader_struct_vader_lower_CollectCtx_t, f_self_mangle) };
const uint16_t vader_type_707_refs[] = { offsetof(vader_struct_vader_lower_CollectCtx_t, f_param_ids), offsetof(vader_struct_vader_lower_CollectCtx_t, f_counts) };
const uint16_t vader_type_708_ptrs[] = { offsetof(vader_struct_vader_lower_ConstFnWrap_t, f_call_type) };
const uint16_t vader_type_708_refs[] = { offsetof(vader_struct_vader_lower_ConstFnWrap_t, f_fn_symbol) };
const uint16_t vader_type_709_refs[] = { offsetof(vader_struct_vader_lower_EntryTypes_t, f_typed), offsetof(vader_struct_vader_lower_EntryTypes_t, f_subst) };
const uint16_t vader_type_710_ptrs[] = { offsetof(vader_struct_vader_lower_FluentCombinator_t, f_receiver), offsetof(vader_struct_vader_lower_FluentCombinator_t, f_fn_arg) };
const uint16_t vader_type_711_ptrs[] = { offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_return_type), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_lifted_context), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_gen_inline_sink) };
const uint16_t vader_type_711_refs[] = { offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_project), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_entry), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_typed), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_subst), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_types), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_blocks), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_comptime_bindings), offsetof(vader_struct_vader_lower_FnLowerCtx_t, f_pending_awaits) };
const uint16_t vader_type_712_ptrs[] = { offsetof(vader_struct_vader_lower_GenBuild_t, f_state_ty), offsetof(vader_struct_vader_lower_GenBuild_t, f_i32_ty), offsetof(vader_struct_vader_lower_GenBuild_t, f_yield_ty), offsetof(vader_struct_vader_lower_GenBuild_t, f_result_ty), offsetof(vader_struct_vader_lower_GenBuild_t, f_suspended_ty), offsetof(vader_struct_vader_lower_GenBuild_t, f_async_any_ty), offsetof(vader_struct_vader_lower_GenBuild_t, f_resume_erased_ty) };
const uint16_t vader_type_712_refs[] = { offsetof(vader_struct_vader_lower_GenBuild_t, f_self_sym), offsetof(vader_struct_vader_lower_GenBuild_t, f_span), offsetof(vader_struct_vader_lower_GenBuild_t, f_states), offsetof(vader_struct_vader_lower_GenBuild_t, f_field_map), offsetof(vader_struct_vader_lower_GenBuild_t, f_fields), offsetof(vader_struct_vader_lower_GenBuild_t, f_loop_stack), offsetof(vader_struct_vader_lower_GenBuild_t, f_fn_ctx) };
const uint16_t vader_type_713_ptrs[] = { offsetof(vader_struct_vader_lower_GenComboLayer_t, f_arg_sym), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_arg_expr), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_output_elem) };
const uint16_t vader_type_713_refs[] = { offsetof(vader_struct_vader_lower_GenComboLayer_t, f_decl), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_subst), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_owner), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_loopvar), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_inner), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_prelude), offsetof(vader_struct_vader_lower_GenComboLayer_t, f_extra_sources) };
const uint16_t vader_type_714_ptrs[] = { offsetof(vader_struct_vader_lower_GenInlineSink_t, f_element_type) };
const uint16_t vader_type_714_strs[] = { offsetof(vader_struct_vader_lower_GenInlineSink_t, f_binding_name) };
const uint16_t vader_type_714_refs[] = { offsetof(vader_struct_vader_lower_GenInlineSink_t, f_binding_symbol), offsetof(vader_struct_vader_lower_GenInlineSink_t, f_body) };
const uint16_t vader_type_715_refs[] = { offsetof(vader_struct_vader_lower_GenSourceBinding_t, f_source), offsetof(vader_struct_vader_lower_GenSourceBinding_t, f_loopvar), offsetof(vader_struct_vader_lower_GenSourceBinding_t, f_inner), offsetof(vader_struct_vader_lower_GenSourceBinding_t, f_prelude) };
const uint16_t vader_type_716_refs[] = { offsetof(vader_struct_vader_lower_GenSourceLoop_t, f_loopvar_span), offsetof(vader_struct_vader_lower_GenSourceLoop_t, f_inner), offsetof(vader_struct_vader_lower_GenSourceLoop_t, f_prelude) };
const uint16_t vader_type_717_strs[] = { offsetof(vader_struct_vader_lower_GenericFnInstance_t, f_mangled), offsetof(vader_struct_vader_lower_GenericFnInstance_t, f_owner_module) };
const uint16_t vader_type_717_refs[] = { offsetof(vader_struct_vader_lower_GenericFnInstance_t, f_fn_symbol), offsetof(vader_struct_vader_lower_GenericFnInstance_t, f_type_args) };
const uint16_t vader_type_718_refs[] = { offsetof(vader_struct_vader_lower_ImplMemberMatch_t, f_entry), offsetof(vader_struct_vader_lower_ImplMemberMatch_t, f_member) };
const uint16_t vader_type_719_strs[] = { offsetof(vader_struct_vader_lower_ImplTraitMethod_t, f_trait_name), offsetof(vader_struct_vader_lower_ImplTraitMethod_t, f_method) };
const uint16_t vader_type_720_ptrs[] = { offsetof(vader_struct_vader_lower_InlineInfo_t, f_body) };
const uint16_t vader_type_720_refs[] = { offsetof(vader_struct_vader_lower_InlineInfo_t, f_params), offsetof(vader_struct_vader_lower_InlineInfo_t, f_use_counts) };
const uint16_t vader_type_721_ptrs[] = { offsetof(vader_struct_vader_lower_IterChain_t, f_range_lower), offsetof(vader_struct_vader_lower_IterChain_t, f_range_upper), offsetof(vader_struct_vader_lower_IterChain_t, f_element_type), offsetof(vader_struct_vader_lower_IterChain_t, f_array_expr), offsetof(vader_struct_vader_lower_IterChain_t, f_source), offsetof(vader_struct_vader_lower_IterChain_t, f_gen_layer), offsetof(vader_struct_vader_lower_IterChain_t, f_iter_expr) };
const uint16_t vader_type_721_refs[] = { offsetof(vader_struct_vader_lower_IterChain_t, f_span) };
const uint16_t vader_type_722_ptrs[] = { offsetof(vader_struct_vader_lower_LiftedFnContext_t, f_env_type) };
const uint16_t vader_type_722_refs[] = { offsetof(vader_struct_vader_lower_LiftedFnContext_t, f_env_symbol), offsetof(vader_struct_vader_lower_LiftedFnContext_t, f_capture_fields) };
const uint16_t vader_type_723_ptrs[] = { offsetof(vader_struct_vader_lower_LoopBinding_t, f_pattern) };
const uint16_t vader_type_723_strs[] = { offsetof(vader_struct_vader_lower_LoopBinding_t, f_name) };
const uint16_t vader_type_723_refs[] = { offsetof(vader_struct_vader_lower_LoopBinding_t, f_symbol) };
const uint16_t vader_type_724_ptrs[] = { offsetof(vader_struct_vader_lower_LoopFrame_t, f_label) };
const uint16_t vader_type_725_refs[] = { offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_evaluated), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_loaded), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_typed), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_impls), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_core_symbols), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_module_symbol_cache), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_comptime_value_by_symbol_id), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_local_symbol_indices), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_closures), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_synth_decls), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_concat_fn_syms), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_concat_decls), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_fn_instances), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_fn_instances_order), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_seen_mangled), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_nongeneric_imported_fns), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_nongeneric_imported_order), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_nongeneric_imported_consts), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_nongeneric_imported_const_order), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_materialized_impl_keys), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_materialized_struct_mangles), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_referenced_impl_mangles), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_virtually_dispatched_traits), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_constructed_struct_symbols), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_array_blanket_elems), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_pending_generic_impl_recv), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_seen_generic_impl_recv), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_generic_collected), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_generic_processed), offsetof(vader_struct_vader_lower_LowerProjectCtx_t, f_diags) };
const uint16_t vader_type_726_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredArrayLen_t, f_type), offsetof(vader_struct_vader_lower_LoweredArrayLen_t, f_target) };
const uint16_t vader_type_726_refs[] = { offsetof(vader_struct_vader_lower_LoweredArrayLen_t, f_span) };
const uint16_t vader_type_727_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredArrayLit_t, f_type) };
const uint16_t vader_type_727_refs[] = { offsetof(vader_struct_vader_lower_LoweredArrayLit_t, f_span), offsetof(vader_struct_vader_lower_LoweredArrayLit_t, f_elements) };
const uint16_t vader_type_728_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredArrayPush_t, f_type), offsetof(vader_struct_vader_lower_LoweredArrayPush_t, f_target), offsetof(vader_struct_vader_lower_LoweredArrayPush_t, f_value) };
const uint16_t vader_type_728_refs[] = { offsetof(vader_struct_vader_lower_LoweredArrayPush_t, f_span) };
const uint16_t vader_type_729_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredArraySlice_t, f_type), offsetof(vader_struct_vader_lower_LoweredArraySlice_t, f_target), offsetof(vader_struct_vader_lower_LoweredArraySlice_t, f_lo), offsetof(vader_struct_vader_lower_LoweredArraySlice_t, f_hi) };
const uint16_t vader_type_729_refs[] = { offsetof(vader_struct_vader_lower_LoweredArraySlice_t, f_span) };
const uint16_t vader_type_730_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredAssign_t, f_target), offsetof(vader_struct_vader_lower_LoweredAssign_t, f_value) };
const uint16_t vader_type_730_refs[] = { offsetof(vader_struct_vader_lower_LoweredAssign_t, f_span) };
const uint16_t vader_type_731_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredAwait_t, f_target_type), offsetof(vader_struct_vader_lower_LoweredAwait_t, f_awaited) };
const uint16_t vader_type_731_refs[] = { offsetof(vader_struct_vader_lower_LoweredAwait_t, f_span), offsetof(vader_struct_vader_lower_LoweredAwait_t, f_target) };
const uint16_t vader_type_732_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredBinary_t, f_type), offsetof(vader_struct_vader_lower_LoweredBinary_t, f_left), offsetof(vader_struct_vader_lower_LoweredBinary_t, f_right) };
const uint16_t vader_type_732_refs[] = { offsetof(vader_struct_vader_lower_LoweredBinary_t, f_span) };
const uint16_t vader_type_733_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredBlock_t, f_type), offsetof(vader_struct_vader_lower_LoweredBlock_t, f_trailing) };
const uint16_t vader_type_733_refs[] = { offsetof(vader_struct_vader_lower_LoweredBlock_t, f_span), offsetof(vader_struct_vader_lower_LoweredBlock_t, f_stmts) };
const uint16_t vader_type_734_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredBoolLit_t, f_type) };
const uint16_t vader_type_734_refs[] = { offsetof(vader_struct_vader_lower_LoweredBoolLit_t, f_span) };
const uint16_t vader_type_735_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredBreak_t, f_label) };
const uint16_t vader_type_735_refs[] = { offsetof(vader_struct_vader_lower_LoweredBreak_t, f_span) };
const uint16_t vader_type_736_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredCall_t, f_type), offsetof(vader_struct_vader_lower_LoweredCall_t, f_callee) };
const uint16_t vader_type_736_refs[] = { offsetof(vader_struct_vader_lower_LoweredCall_t, f_span), offsetof(vader_struct_vader_lower_LoweredCall_t, f_args) };
const uint16_t vader_type_737_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredCast_t, f_type), offsetof(vader_struct_vader_lower_LoweredCast_t, f_value) };
const uint16_t vader_type_737_refs[] = { offsetof(vader_struct_vader_lower_LoweredCast_t, f_span) };
const uint16_t vader_type_738_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredCellGet_t, f_type), offsetof(vader_struct_vader_lower_LoweredCellGet_t, f_target), offsetof(vader_struct_vader_lower_LoweredCellGet_t, f_value_type) };
const uint16_t vader_type_738_refs[] = { offsetof(vader_struct_vader_lower_LoweredCellGet_t, f_span) };
const uint16_t vader_type_739_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredCellNew_t, f_type), offsetof(vader_struct_vader_lower_LoweredCellNew_t, f_value), offsetof(vader_struct_vader_lower_LoweredCellNew_t, f_value_type) };
const uint16_t vader_type_739_refs[] = { offsetof(vader_struct_vader_lower_LoweredCellNew_t, f_span) };
const uint16_t vader_type_740_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredCellSet_t, f_target), offsetof(vader_struct_vader_lower_LoweredCellSet_t, f_value), offsetof(vader_struct_vader_lower_LoweredCellSet_t, f_value_type) };
const uint16_t vader_type_740_refs[] = { offsetof(vader_struct_vader_lower_LoweredCellSet_t, f_span) };
const uint16_t vader_type_741_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredCharLit_t, f_type) };
const uint16_t vader_type_741_refs[] = { offsetof(vader_struct_vader_lower_LoweredCharLit_t, f_span) };
const uint16_t vader_type_742_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredConstDecl_t, f_type), offsetof(vader_struct_vader_lower_LoweredConstDecl_t, f_value) };
const uint16_t vader_type_742_strs[] = { offsetof(vader_struct_vader_lower_LoweredConstDecl_t, f_mangled) };
const uint16_t vader_type_742_refs[] = { offsetof(vader_struct_vader_lower_LoweredConstDecl_t, f_origin) };
const uint16_t vader_type_743_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredContinue_t, f_label) };
const uint16_t vader_type_743_refs[] = { offsetof(vader_struct_vader_lower_LoweredContinue_t, f_span) };
const uint16_t vader_type_744_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredDataConst_t, f_type) };
const uint16_t vader_type_744_refs[] = { offsetof(vader_struct_vader_lower_LoweredDataConst_t, f_span) };
const uint16_t vader_type_745_refs[] = { offsetof(vader_struct_vader_lower_LoweredDeferPopExec_t, f_span) };
const uint16_t vader_type_746_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredDeferPush_t, f_thunk) };
const uint16_t vader_type_746_refs[] = { offsetof(vader_struct_vader_lower_LoweredDeferPush_t, f_span) };
const uint16_t vader_type_747_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredExprStmt_t, f_expr) };
const uint16_t vader_type_747_refs[] = { offsetof(vader_struct_vader_lower_LoweredExprStmt_t, f_span) };
const uint16_t vader_type_748_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredFieldAccess_t, f_type), offsetof(vader_struct_vader_lower_LoweredFieldAccess_t, f_target) };
const uint16_t vader_type_748_strs[] = { offsetof(vader_struct_vader_lower_LoweredFieldAccess_t, f_field) };
const uint16_t vader_type_748_refs[] = { offsetof(vader_struct_vader_lower_LoweredFieldAccess_t, f_span) };
const uint16_t vader_type_749_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredFloatLit_t, f_type) };
const uint16_t vader_type_749_refs[] = { offsetof(vader_struct_vader_lower_LoweredFloatLit_t, f_span) };
const uint16_t vader_type_750_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredFnDecl_t, f_return_type), offsetof(vader_struct_vader_lower_LoweredFnDecl_t, f_body) };
const uint16_t vader_type_750_strs[] = { offsetof(vader_struct_vader_lower_LoweredFnDecl_t, f_mangled) };
const uint16_t vader_type_750_refs[] = { offsetof(vader_struct_vader_lower_LoweredFnDecl_t, f_params), offsetof(vader_struct_vader_lower_LoweredFnDecl_t, f_origin) };
const uint16_t vader_type_751_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredIdent_t, f_type) };
const uint16_t vader_type_751_refs[] = { offsetof(vader_struct_vader_lower_LoweredIdent_t, f_span), offsetof(vader_struct_vader_lower_LoweredIdent_t, f_symbol) };
const uint16_t vader_type_752_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredIf_t, f_type), offsetof(vader_struct_vader_lower_LoweredIf_t, f_cond), offsetof(vader_struct_vader_lower_LoweredIf_t, f_else_block) };
const uint16_t vader_type_752_refs[] = { offsetof(vader_struct_vader_lower_LoweredIf_t, f_span), offsetof(vader_struct_vader_lower_LoweredIf_t, f_then_block) };
const uint16_t vader_type_753_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredIndex_t, f_type), offsetof(vader_struct_vader_lower_LoweredIndex_t, f_target), offsetof(vader_struct_vader_lower_LoweredIndex_t, f_index) };
const uint16_t vader_type_753_refs[] = { offsetof(vader_struct_vader_lower_LoweredIndex_t, f_span) };
const uint16_t vader_type_754_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredIntLit_t, f_type) };
const uint16_t vader_type_754_refs[] = { offsetof(vader_struct_vader_lower_LoweredIntLit_t, f_span) };
const uint16_t vader_type_755_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredIntrinsicCall_t, f_type) };
const uint16_t vader_type_755_strs[] = { offsetof(vader_struct_vader_lower_LoweredIntrinsicCall_t, f_name) };
const uint16_t vader_type_755_refs[] = { offsetof(vader_struct_vader_lower_LoweredIntrinsicCall_t, f_span), offsetof(vader_struct_vader_lower_LoweredIntrinsicCall_t, f_args) };
const uint16_t vader_type_756_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredLet_t, f_type), offsetof(vader_struct_vader_lower_LoweredLet_t, f_value) };
const uint16_t vader_type_756_strs[] = { offsetof(vader_struct_vader_lower_LoweredLet_t, f_name) };
const uint16_t vader_type_756_refs[] = { offsetof(vader_struct_vader_lower_LoweredLet_t, f_span), offsetof(vader_struct_vader_lower_LoweredLet_t, f_symbol) };
const uint16_t vader_type_757_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredLoop_t, f_label), offsetof(vader_struct_vader_lower_LoweredLoop_t, f_cond) };
const uint16_t vader_type_757_refs[] = { offsetof(vader_struct_vader_lower_LoweredLoop_t, f_span), offsetof(vader_struct_vader_lower_LoweredLoop_t, f_body) };
const uint16_t vader_type_758_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredMakeClosure_t, f_type), offsetof(vader_struct_vader_lower_LoweredMakeClosure_t, f_env) };
const uint16_t vader_type_758_refs[] = { offsetof(vader_struct_vader_lower_LoweredMakeClosure_t, f_span), offsetof(vader_struct_vader_lower_LoweredMakeClosure_t, f_fn_symbol) };
const uint16_t vader_type_759_strs[] = { offsetof(vader_struct_vader_lower_LoweredModule_t, f_module_id), offsetof(vader_struct_vader_lower_LoweredModule_t, f_display_path) };
const uint16_t vader_type_759_refs[] = { offsetof(vader_struct_vader_lower_LoweredModule_t, f_decls) };
const uint16_t vader_type_760_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredNullLit_t, f_type) };
const uint16_t vader_type_760_refs[] = { offsetof(vader_struct_vader_lower_LoweredNullLit_t, f_span) };
const uint16_t vader_type_761_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredParam_t, f_type) };
const uint16_t vader_type_761_strs[] = { offsetof(vader_struct_vader_lower_LoweredParam_t, f_name) };
const uint16_t vader_type_761_refs[] = { offsetof(vader_struct_vader_lower_LoweredParam_t, f_symbol) };
const uint16_t vader_type_762_strs[] = { offsetof(vader_struct_vader_lower_LoweredProject_t, f_entry) };
const uint16_t vader_type_762_refs[] = { offsetof(vader_struct_vader_lower_LoweredProject_t, f_modules), offsetof(vader_struct_vader_lower_LoweredProject_t, f_vtable_entries), offsetof(vader_struct_vader_lower_LoweredProject_t, f_data_pool), offsetof(vader_struct_vader_lower_LoweredProject_t, f_const_fn_wrap), offsetof(vader_struct_vader_lower_LoweredProject_t, f_const_inline), offsetof(vader_struct_vader_lower_LoweredProject_t, f_trait_membership) };
const uint16_t vader_type_763_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredReturn_t, f_value) };
const uint16_t vader_type_763_refs[] = { offsetof(vader_struct_vader_lower_LoweredReturn_t, f_span) };
const uint16_t vader_type_764_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredStringLit_t, f_type) };
const uint16_t vader_type_764_strs[] = { offsetof(vader_struct_vader_lower_LoweredStringLit_t, f_value) };
const uint16_t vader_type_764_refs[] = { offsetof(vader_struct_vader_lower_LoweredStringLit_t, f_span) };
const uint16_t vader_type_765_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredStringSlice_t, f_type), offsetof(vader_struct_vader_lower_LoweredStringSlice_t, f_target), offsetof(vader_struct_vader_lower_LoweredStringSlice_t, f_lo), offsetof(vader_struct_vader_lower_LoweredStringSlice_t, f_hi) };
const uint16_t vader_type_765_refs[] = { offsetof(vader_struct_vader_lower_LoweredStringSlice_t, f_span) };
const uint16_t vader_type_766_strs[] = { offsetof(vader_struct_vader_lower_LoweredStructDecl_t, f_mangled) };
const uint16_t vader_type_766_refs[] = { offsetof(vader_struct_vader_lower_LoweredStructDecl_t, f_fields), offsetof(vader_struct_vader_lower_LoweredStructDecl_t, f_origin) };
const uint16_t vader_type_767_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredStructField_t, f_type) };
const uint16_t vader_type_767_strs[] = { offsetof(vader_struct_vader_lower_LoweredStructField_t, f_name) };
const uint16_t vader_type_768_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredStructLit_t, f_type) };
const uint16_t vader_type_768_refs[] = { offsetof(vader_struct_vader_lower_LoweredStructLit_t, f_span), offsetof(vader_struct_vader_lower_LoweredStructLit_t, f_fields) };
const uint16_t vader_type_769_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredStructLitField_t, f_value) };
const uint16_t vader_type_769_strs[] = { offsetof(vader_struct_vader_lower_LoweredStructLitField_t, f_name) };
const uint16_t vader_type_770_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredTypeCheck_t, f_type), offsetof(vader_struct_vader_lower_LoweredTypeCheck_t, f_value), offsetof(vader_struct_vader_lower_LoweredTypeCheck_t, f_check_type) };
const uint16_t vader_type_770_refs[] = { offsetof(vader_struct_vader_lower_LoweredTypeCheck_t, f_span) };
const uint16_t vader_type_771_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredTypeConst_t, f_type), offsetof(vader_struct_vader_lower_LoweredTypeConst_t, f_value) };
const uint16_t vader_type_771_refs[] = { offsetof(vader_struct_vader_lower_LoweredTypeConst_t, f_span) };
const uint16_t vader_type_772_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredUnary_t, f_type), offsetof(vader_struct_vader_lower_LoweredUnary_t, f_operand) };
const uint16_t vader_type_772_refs[] = { offsetof(vader_struct_vader_lower_LoweredUnary_t, f_span) };
const uint16_t vader_type_773_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredUnreachable_t, f_type) };
const uint16_t vader_type_773_strs[] = { offsetof(vader_struct_vader_lower_LoweredUnreachable_t, f_reason) };
const uint16_t vader_type_773_refs[] = { offsetof(vader_struct_vader_lower_LoweredUnreachable_t, f_span) };
const uint16_t vader_type_774_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredVirtualCall_t, f_type), offsetof(vader_struct_vader_lower_LoweredVirtualCall_t, f_receiver) };
const uint16_t vader_type_774_strs[] = { offsetof(vader_struct_vader_lower_LoweredVirtualCall_t, f_trait_name), offsetof(vader_struct_vader_lower_LoweredVirtualCall_t, f_method) };
const uint16_t vader_type_774_refs[] = { offsetof(vader_struct_vader_lower_LoweredVirtualCall_t, f_span), offsetof(vader_struct_vader_lower_LoweredVirtualCall_t, f_args) };
const uint16_t vader_type_775_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredVtableEntry_t, f_struct_type) };
const uint16_t vader_type_775_strs[] = { offsetof(vader_struct_vader_lower_LoweredVtableEntry_t, f_trait_name), offsetof(vader_struct_vader_lower_LoweredVtableEntry_t, f_method_name) };
const uint16_t vader_type_775_refs[] = { offsetof(vader_struct_vader_lower_LoweredVtableEntry_t, f_fn_symbol) };
const uint16_t vader_type_776_ptrs[] = { offsetof(vader_struct_vader_lower_LoweredYield_t, f_value) };
const uint16_t vader_type_776_refs[] = { offsetof(vader_struct_vader_lower_LoweredYield_t, f_span) };
const uint16_t vader_type_777_strs[] = { offsetof(vader_struct_vader_lower_OpTraitInfo_t, f_trait_name), offsetof(vader_struct_vader_lower_OpTraitInfo_t, f_method_name) };
const uint16_t vader_type_778_strs[] = { offsetof(vader_struct_vader_lower_PendingFnInstance_t, f_module_id), offsetof(vader_struct_vader_lower_PendingFnInstance_t, f_key) };
const uint16_t vader_type_778_refs[] = { offsetof(vader_struct_vader_lower_PendingFnInstance_t, f_decl) };
const uint16_t vader_type_779_strs[] = { offsetof(vader_struct_vader_lower_PrimDataPoolEntry_t, f_element_type_name) };
const uint16_t vader_type_779_refs[] = { offsetof(vader_struct_vader_lower_PrimDataPoolEntry_t, f_items) };
const uint16_t vader_type_780_refs[] = { offsetof(vader_struct_vader_lower_StrDataPoolEntry_t, f_values) };
const uint16_t vader_type_781_ptrs[] = { offsetof(vader_struct_vader_lower_TerminalPredCall_t, f_chain_arg), offsetof(vader_struct_vader_lower_TerminalPredCall_t, f_pred) };
const uint16_t vader_type_782_refs[] = { offsetof(vader_struct_vader_lower_TransformCtx_t, f_index), offsetof(vader_struct_vader_lower_TransformCtx_t, f_param_map) };
const uint16_t vader_type_783_refs[] = { offsetof(vader_struct_vader_lower_UfcsMember_t, f_symbol), offsetof(vader_struct_vader_lower_UfcsMember_t, f_arg_types) };
const uint16_t vader_type_784_refs[] = { offsetof(vader_struct_vader_lower_WalkCtx_t, f_typed), offsetof(vader_struct_vader_lower_WalkCtx_t, f_symbol_index), offsetof(vader_struct_vader_lower_WalkCtx_t, f_analysis), offsetof(vader_struct_vader_lower_WalkCtx_t, f_empty_captures) };
const uint16_t vader_type_785_ptrs[] = { offsetof(vader_struct_vader_lower_WrapResult_t, f_iter), offsetof(vader_struct_vader_lower_WrapResult_t, f_iter_type) };
const uint16_t vader_type_786_refs[] = { offsetof(vader_struct_vader_midir_AnnotatedProject_t, f_project), offsetof(vader_struct_vader_midir_AnnotatedProject_t, f_stats) };
const uint16_t vader_type_787_ptrs[] = { offsetof(vader_struct_vader_midir_BasicBlock_t, f_terminator) };
const uint16_t vader_type_787_refs[] = { offsetof(vader_struct_vader_midir_BasicBlock_t, f_instructions), offsetof(vader_struct_vader_midir_BasicBlock_t, f_span) };
const uint16_t vader_type_788_ptrs[] = { offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_return_type) };
const uint16_t vader_type_788_strs[] = { offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_mangled), offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_extern_name), offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_c_header), offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_c_library) };
const uint16_t vader_type_788_refs[] = { offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_params), offsetof(vader_struct_vader_midir_CFGExternDecl_t, f_origin) };
const uint16_t vader_type_789_ptrs[] = { offsetof(vader_struct_vader_midir_CFGFunction_t, f_return_type) };
const uint16_t vader_type_789_strs[] = { offsetof(vader_struct_vader_midir_CFGFunction_t, f_mangled), offsetof(vader_struct_vader_midir_CFGFunction_t, f_extern_name) };
const uint16_t vader_type_789_refs[] = { offsetof(vader_struct_vader_midir_CFGFunction_t, f_params), offsetof(vader_struct_vader_midir_CFGFunction_t, f_locals), offsetof(vader_struct_vader_midir_CFGFunction_t, f_blocks), offsetof(vader_struct_vader_midir_CFGFunction_t, f_origin) };
const uint16_t vader_type_790_ptrs[] = { offsetof(vader_struct_vader_midir_CFGLocal_t, f_type), offsetof(vader_struct_vader_midir_CFGLocal_t, f_symbol) };
const uint16_t vader_type_790_strs[] = { offsetof(vader_struct_vader_midir_CFGLocal_t, f_name) };
const uint16_t vader_type_791_strs[] = { offsetof(vader_struct_vader_midir_CFGModule_t, f_module_id), offsetof(vader_struct_vader_midir_CFGModule_t, f_display_path) };
const uint16_t vader_type_791_refs[] = { offsetof(vader_struct_vader_midir_CFGModule_t, f_functions), offsetof(vader_struct_vader_midir_CFGModule_t, f_externs), offsetof(vader_struct_vader_midir_CFGModule_t, f_struct_decls) };
const uint16_t vader_type_792_ptrs[] = { offsetof(vader_struct_vader_midir_CFGParam_t, f_type) };
const uint16_t vader_type_792_strs[] = { offsetof(vader_struct_vader_midir_CFGParam_t, f_name) };
const uint16_t vader_type_792_refs[] = { offsetof(vader_struct_vader_midir_CFGParam_t, f_symbol) };
const uint16_t vader_type_793_refs[] = { offsetof(vader_struct_vader_midir_CFGProject_t, f_modules), offsetof(vader_struct_vader_midir_CFGProject_t, f_vtable_entries), offsetof(vader_struct_vader_midir_CFGProject_t, f_strings), offsetof(vader_struct_vader_midir_CFGProject_t, f_data_pool), offsetof(vader_struct_vader_midir_CFGProject_t, f_trait_membership) };
const uint16_t vader_type_794_strs[] = { offsetof(vader_struct_vader_midir_CFGStructDecl_t, f_mangled) };
const uint16_t vader_type_794_refs[] = { offsetof(vader_struct_vader_midir_CFGStructDecl_t, f_fields), offsetof(vader_struct_vader_midir_CFGStructDecl_t, f_origin) };
const uint16_t vader_type_795_ptrs[] = { offsetof(vader_struct_vader_midir_CFGStructField_t, f_type) };
const uint16_t vader_type_795_strs[] = { offsetof(vader_struct_vader_midir_CFGStructField_t, f_name) };
const uint16_t vader_type_802_refs[] = { offsetof(vader_struct_vader_midir_EscapeResult_t, f_escaping), offsetof(vader_struct_vader_midir_EscapeResult_t, f_alias_of), offsetof(vader_struct_vader_midir_EscapeResult_t, f_alias_from) };
const uint16_t vader_type_804_ptrs[] = { offsetof(vader_struct_vader_midir_FnCtx_t, f_return_type), offsetof(vader_struct_vader_midir_FnCtx_t, f_current) };
const uint16_t vader_type_804_strs[] = { offsetof(vader_struct_vader_midir_FnCtx_t, f_mangled) };
const uint16_t vader_type_804_refs[] = { offsetof(vader_struct_vader_midir_FnCtx_t, f_project), offsetof(vader_struct_vader_midir_FnCtx_t, f_origin), offsetof(vader_struct_vader_midir_FnCtx_t, f_params), offsetof(vader_struct_vader_midir_FnCtx_t, f_locals), offsetof(vader_struct_vader_midir_FnCtx_t, f_local_by_sym_id), offsetof(vader_struct_vader_midir_FnCtx_t, f_blocks), offsetof(vader_struct_vader_midir_FnCtx_t, f_loop_stack) };
const uint16_t vader_type_805_refs[] = { offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_fn_), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_pinned_types_bucket), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_slot), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_project), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_string_index_map), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_local_to_slot), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_preds), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_idom), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_ipostdom), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_loop_exit), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_scopes), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_pending), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_wrapped_loop_headers), offsetof(vader_struct_vader_midir_FnEmitCfg_t, f_hints) };
const uint16_t vader_type_806_strs[] = { offsetof(vader_struct_vader_midir_FnMetadata_t, f_extern_name), offsetof(vader_struct_vader_midir_FnMetadata_t, f_c_library), offsetof(vader_struct_vader_midir_FnMetadata_t, f_c_header) };
const uint16_t vader_type_807_ptrs[] = { offsetof(vader_struct_vader_midir_InstrArrayGet_t, f_type) };
const uint16_t vader_type_807_refs[] = { offsetof(vader_struct_vader_midir_InstrArrayGet_t, f_span) };
const uint16_t vader_type_808_refs[] = { offsetof(vader_struct_vader_midir_InstrArrayLen_t, f_span) };
const uint16_t vader_type_809_ptrs[] = { offsetof(vader_struct_vader_midir_InstrArrayNew_t, f_type) };
const uint16_t vader_type_809_refs[] = { offsetof(vader_struct_vader_midir_InstrArrayNew_t, f_span), offsetof(vader_struct_vader_midir_InstrArrayNew_t, f_elements) };
const uint16_t vader_type_810_refs[] = { offsetof(vader_struct_vader_midir_InstrArrayPush_t, f_span) };
const uint16_t vader_type_811_refs[] = { offsetof(vader_struct_vader_midir_InstrArraySet_t, f_span) };
const uint16_t vader_type_812_ptrs[] = { offsetof(vader_struct_vader_midir_InstrArraySlice_t, f_type) };
const uint16_t vader_type_812_refs[] = { offsetof(vader_struct_vader_midir_InstrArraySlice_t, f_span) };
const uint16_t vader_type_813_ptrs[] = { offsetof(vader_struct_vader_midir_InstrBinOp_t, f_type) };
const uint16_t vader_type_813_refs[] = { offsetof(vader_struct_vader_midir_InstrBinOp_t, f_span) };
const uint16_t vader_type_814_ptrs[] = { offsetof(vader_struct_vader_midir_InstrCall_t, f_dst), offsetof(vader_struct_vader_midir_InstrCall_t, f_type) };
const uint16_t vader_type_814_refs[] = { offsetof(vader_struct_vader_midir_InstrCall_t, f_span), offsetof(vader_struct_vader_midir_InstrCall_t, f_callee), offsetof(vader_struct_vader_midir_InstrCall_t, f_args) };
const uint16_t vader_type_815_ptrs[] = { offsetof(vader_struct_vader_midir_InstrCallIndirect_t, f_dst), offsetof(vader_struct_vader_midir_InstrCallIndirect_t, f_fn_type), offsetof(vader_struct_vader_midir_InstrCallIndirect_t, f_type) };
const uint16_t vader_type_815_refs[] = { offsetof(vader_struct_vader_midir_InstrCallIndirect_t, f_span), offsetof(vader_struct_vader_midir_InstrCallIndirect_t, f_args) };
const uint16_t vader_type_816_ptrs[] = { offsetof(vader_struct_vader_midir_InstrCast_t, f_type) };
const uint16_t vader_type_816_refs[] = { offsetof(vader_struct_vader_midir_InstrCast_t, f_span) };
const uint16_t vader_type_817_ptrs[] = { offsetof(vader_struct_vader_midir_InstrCellGet_t, f_value_type) };
const uint16_t vader_type_817_refs[] = { offsetof(vader_struct_vader_midir_InstrCellGet_t, f_span) };
const uint16_t vader_type_818_ptrs[] = { offsetof(vader_struct_vader_midir_InstrCellNew_t, f_value_type) };
const uint16_t vader_type_818_refs[] = { offsetof(vader_struct_vader_midir_InstrCellNew_t, f_span) };
const uint16_t vader_type_819_ptrs[] = { offsetof(vader_struct_vader_midir_InstrCellSet_t, f_value_type) };
const uint16_t vader_type_819_refs[] = { offsetof(vader_struct_vader_midir_InstrCellSet_t, f_span) };
const uint16_t vader_type_820_ptrs[] = { offsetof(vader_struct_vader_midir_InstrConst_t, f_value), offsetof(vader_struct_vader_midir_InstrConst_t, f_type) };
const uint16_t vader_type_820_refs[] = { offsetof(vader_struct_vader_midir_InstrConst_t, f_span) };
const uint16_t vader_type_821_ptrs[] = { offsetof(vader_struct_vader_midir_InstrDataConst_t, f_type) };
const uint16_t vader_type_821_refs[] = { offsetof(vader_struct_vader_midir_InstrDataConst_t, f_span) };
const uint16_t vader_type_822_refs[] = { offsetof(vader_struct_vader_midir_InstrDeferPopExec_t, f_span) };
const uint16_t vader_type_823_refs[] = { offsetof(vader_struct_vader_midir_InstrDeferPush_t, f_span) };
const uint16_t vader_type_824_ptrs[] = { offsetof(vader_struct_vader_midir_InstrFieldGet_t, f_type) };
const uint16_t vader_type_824_strs[] = { offsetof(vader_struct_vader_midir_InstrFieldGet_t, f_field) };
const uint16_t vader_type_824_refs[] = { offsetof(vader_struct_vader_midir_InstrFieldGet_t, f_span) };
const uint16_t vader_type_825_strs[] = { offsetof(vader_struct_vader_midir_InstrFieldSet_t, f_field) };
const uint16_t vader_type_825_refs[] = { offsetof(vader_struct_vader_midir_InstrFieldSet_t, f_span) };
const uint16_t vader_type_826_ptrs[] = { offsetof(vader_struct_vader_midir_InstrFnRef_t, f_type) };
const uint16_t vader_type_826_refs[] = { offsetof(vader_struct_vader_midir_InstrFnRef_t, f_span), offsetof(vader_struct_vader_midir_InstrFnRef_t, f_fn_symbol) };
const uint16_t vader_type_827_ptrs[] = { offsetof(vader_struct_vader_midir_InstrIntrinsic_t, f_dst) };
const uint16_t vader_type_827_strs[] = { offsetof(vader_struct_vader_midir_InstrIntrinsic_t, f_name) };
const uint16_t vader_type_827_refs[] = { offsetof(vader_struct_vader_midir_InstrIntrinsic_t, f_span), offsetof(vader_struct_vader_midir_InstrIntrinsic_t, f_args) };
const uint16_t vader_type_828_ptrs[] = { offsetof(vader_struct_vader_midir_InstrMakeClosure_t, f_env_type), offsetof(vader_struct_vader_midir_InstrMakeClosure_t, f_type) };
const uint16_t vader_type_828_refs[] = { offsetof(vader_struct_vader_midir_InstrMakeClosure_t, f_span), offsetof(vader_struct_vader_midir_InstrMakeClosure_t, f_fn_symbol) };
const uint16_t vader_type_829_refs[] = { offsetof(vader_struct_vader_midir_InstrMove_t, f_span) };
const uint16_t vader_type_830_ptrs[] = { offsetof(vader_struct_vader_midir_InstrStringSlice_t, f_type) };
const uint16_t vader_type_830_refs[] = { offsetof(vader_struct_vader_midir_InstrStringSlice_t, f_span) };
const uint16_t vader_type_831_ptrs[] = { offsetof(vader_struct_vader_midir_InstrStructNew_t, f_type) };
const uint16_t vader_type_831_refs[] = { offsetof(vader_struct_vader_midir_InstrStructNew_t, f_span), offsetof(vader_struct_vader_midir_InstrStructNew_t, f_fields) };
const uint16_t vader_type_832_ptrs[] = { offsetof(vader_struct_vader_midir_InstrTypeCheck_t, f_check_type) };
const uint16_t vader_type_832_refs[] = { offsetof(vader_struct_vader_midir_InstrTypeCheck_t, f_span) };
const uint16_t vader_type_833_ptrs[] = { offsetof(vader_struct_vader_midir_InstrTypeConst_t, f_type), offsetof(vader_struct_vader_midir_InstrTypeConst_t, f_value_type) };
const uint16_t vader_type_833_refs[] = { offsetof(vader_struct_vader_midir_InstrTypeConst_t, f_span) };
const uint16_t vader_type_834_ptrs[] = { offsetof(vader_struct_vader_midir_InstrUnOp_t, f_type) };
const uint16_t vader_type_834_refs[] = { offsetof(vader_struct_vader_midir_InstrUnOp_t, f_span) };
const uint16_t vader_type_835_ptrs[] = { offsetof(vader_struct_vader_midir_InstrVirtualCall_t, f_dst), offsetof(vader_struct_vader_midir_InstrVirtualCall_t, f_type) };
const uint16_t vader_type_835_strs[] = { offsetof(vader_struct_vader_midir_InstrVirtualCall_t, f_trait_name), offsetof(vader_struct_vader_midir_InstrVirtualCall_t, f_method) };
const uint16_t vader_type_835_refs[] = { offsetof(vader_struct_vader_midir_InstrVirtualCall_t, f_span), offsetof(vader_struct_vader_midir_InstrVirtualCall_t, f_args) };
const uint16_t vader_type_836_refs[] = { offsetof(vader_struct_vader_midir_Liveness_t, f_live_in), offsetof(vader_struct_vader_midir_Liveness_t, f_live_out) };
const uint16_t vader_type_837_ptrs[] = { offsetof(vader_struct_vader_midir_LoopFrame_t, f_label) };
const uint16_t vader_type_838_ptrs[] = { offsetof(vader_struct_vader_midir_MutableBlock_t, f_terminator) };
const uint16_t vader_type_838_refs[] = { offsetof(vader_struct_vader_midir_MutableBlock_t, f_instructions), offsetof(vader_struct_vader_midir_MutableBlock_t, f_span) };
const uint16_t vader_type_840_refs[] = { offsetof(vader_struct_vader_midir_ProjectCtx_t, f_strings), offsetof(vader_struct_vader_midir_ProjectCtx_t, f_string_index), offsetof(vader_struct_vader_midir_ProjectCtx_t, f_const_fn_wrap), offsetof(vader_struct_vader_midir_ProjectCtx_t, f_const_inline) };
const uint16_t vader_type_841_refs[] = { offsetof(vader_struct_vader_midir_ScheduleHints_t, f_skip_set), offsetof(vader_struct_vader_midir_ScheduleHints_t, f_skip_first_get), offsetof(vader_struct_vader_midir_ScheduleHints_t, f_skip_terminator_get) };
const uint16_t vader_type_842_strs[] = { offsetof(vader_struct_vader_midir_ScopeFrame_t, f_kind) };
const uint16_t vader_type_843_refs[] = { offsetof(vader_struct_vader_midir_TermBranch_t, f_span) };
const uint16_t vader_type_844_refs[] = { offsetof(vader_struct_vader_midir_TermCondBranch_t, f_span) };
const uint16_t vader_type_845_ptrs[] = { offsetof(vader_struct_vader_midir_TermReturn_t, f_value) };
const uint16_t vader_type_845_refs[] = { offsetof(vader_struct_vader_midir_TermReturn_t, f_span) };
const uint16_t vader_type_846_strs[] = { offsetof(vader_struct_vader_midir_TermUnreachable_t, f_reason) };
const uint16_t vader_type_846_refs[] = { offsetof(vader_struct_vader_midir_TermUnreachable_t, f_span) };
const uint16_t vader_type_847_refs[] = { offsetof(vader_struct_vader_parser_CommaList__Any_t, f_items) };
const uint16_t vader_type_848_refs[] = { offsetof(vader_struct_vader_parser_CommaList__CallArg_t, f_items) };
const uint16_t vader_type_849_refs[] = { offsetof(vader_struct_vader_parser_CommaList__ImportName_t, f_items) };
const uint16_t vader_type_850_refs[] = { offsetof(vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t, f_items) };
const uint16_t vader_type_852_ptrs[] = { offsetof(vader_struct_vader_parser_FnBodyTail_t, f_body) };
const uint16_t vader_type_853_refs[] = { offsetof(vader_struct_vader_parser_FnSignature_t, f_params), offsetof(vader_struct_vader_parser_FnSignature_t, f_type_params) };
const uint16_t vader_type_855_strs[] = { offsetof(vader_struct_vader_parser_IntrinsicSpec_t, f_name), offsetof(vader_struct_vader_parser_IntrinsicSpec_t, f_result) };
const uint16_t vader_type_855_refs[] = { offsetof(vader_struct_vader_parser_IntrinsicSpec_t, f_args) };
const uint16_t vader_type_856_strs[] = { offsetof(vader_struct_vader_parser_ModuleHeader_t, f_name) };
const uint16_t vader_type_856_refs[] = { offsetof(vader_struct_vader_parser_ModuleHeader_t, f_name_span) };
const uint16_t vader_type_858_refs[] = { offsetof(vader_struct_vader_parser_ParsedSource_t, f_program), offsetof(vader_struct_vader_parser_ParsedSource_t, f_tokens), offsetof(vader_struct_vader_parser_ParsedSource_t, f_errors), offsetof(vader_struct_vader_parser_ParsedSource_t, f_id_factory) };
const uint16_t vader_type_859_ptrs[] = { offsetof(vader_struct_vader_parser_Parser_t, f_shr_pending_half) };
const uint16_t vader_type_859_strs[] = { offsetof(vader_struct_vader_parser_Parser_t, f_file) };
const uint16_t vader_type_859_refs[] = { offsetof(vader_struct_vader_parser_Parser_t, f_tokens), offsetof(vader_struct_vader_parser_Parser_t, f_errors), offsetof(vader_struct_vader_parser_Parser_t, f_pending_decls) };
const uint16_t vader_type_860_strs[] = { offsetof(vader_struct_vader_parser_StringLitInfo_t, f_text) };
const uint16_t vader_type_860_refs[] = { offsetof(vader_struct_vader_parser_StringLitInfo_t, f_span) };
const uint16_t vader_type_861_refs[] = { offsetof(vader_struct_vader_resolver_CollectedModule_t, f_symbols), offsetof(vader_struct_vader_resolver_CollectedModule_t, f_fn_overloads), offsetof(vader_struct_vader_resolver_CollectedModule_t, f_imports), offsetof(vader_struct_vader_resolver_CollectedModule_t, f_import_paths), offsetof(vader_struct_vader_resolver_CollectedModule_t, f_wildcards) };
const uint16_t vader_type_862_strs[] = { offsetof(vader_struct_vader_resolver_DiscoveredModule_t, f_name), offsetof(vader_struct_vader_resolver_DiscoveredModule_t, f_folder) };
const uint16_t vader_type_862_refs[] = { offsetof(vader_struct_vader_resolver_DiscoveredModule_t, f_files) };
const uint16_t vader_type_863_strs[] = { offsetof(vader_struct_vader_resolver_FileWildcards_t, f_file) };
const uint16_t vader_type_863_refs[] = { offsetof(vader_struct_vader_resolver_FileWildcards_t, f_paths), offsetof(vader_struct_vader_resolver_FileWildcards_t, f_excludes) };
const uint16_t vader_type_864_strs[] = { offsetof(vader_struct_vader_resolver_FolderBucket_t, f_name) };
const uint16_t vader_type_864_refs[] = { offsetof(vader_struct_vader_resolver_FolderBucket_t, f_first_decl_span), offsetof(vader_struct_vader_resolver_FolderBucket_t, f_files) };
const uint16_t vader_type_865_ptrs[] = { offsetof(vader_struct_vader_resolver_ImportInfo_t, f_imported_name) };
const uint16_t vader_type_865_strs[] = { offsetof(vader_struct_vader_resolver_ImportInfo_t, f_path), offsetof(vader_struct_vader_resolver_ImportInfo_t, f_local) };
const uint16_t vader_type_865_refs[] = { offsetof(vader_struct_vader_resolver_ImportInfo_t, f_binding_span) };
const uint16_t vader_type_866_refs[] = { offsetof(vader_struct_vader_resolver_ImportTargetTable_t, f_symbol_targets), offsetof(vader_struct_vader_resolver_ImportTargetTable_t, f_namespace_targets), offsetof(vader_struct_vader_resolver_ImportTargetTable_t, f_missing) };
const uint16_t vader_type_867_strs[] = { offsetof(vader_struct_vader_resolver_IncludePath_t, f_dir), offsetof(vader_struct_vader_resolver_IncludePath_t, f_prefix) };
const uint16_t vader_type_868_refs[] = { offsetof(vader_struct_vader_resolver_LoadedModule_t, f_module), offsetof(vader_struct_vader_resolver_LoadedModule_t, f_collected), offsetof(vader_struct_vader_resolver_LoadedModule_t, f_node_id_factory), offsetof(vader_struct_vader_resolver_LoadedModule_t, f_discarded_bodies) };
const uint16_t vader_type_869_ptrs[] = { offsetof(vader_struct_vader_resolver_LoadedProject_t, f_project_root) };
const uint16_t vader_type_869_strs[] = { offsetof(vader_struct_vader_resolver_LoadedProject_t, f_entry) };
const uint16_t vader_type_869_refs[] = { offsetof(vader_struct_vader_resolver_LoadedProject_t, f_modules), offsetof(vader_struct_vader_resolver_LoadedProject_t, f_factory), offsetof(vader_struct_vader_resolver_LoadedProject_t, f_diags) };
const uint16_t vader_type_870_refs[] = { offsetof(vader_struct_vader_resolver_Manifest_t, f_include_paths) };
const uint16_t vader_type_871_strs[] = { offsetof(vader_struct_vader_resolver_Module_t, f_id), offsetof(vader_struct_vader_resolver_Module_t, f_display_path), offsetof(vader_struct_vader_resolver_Module_t, f_module_name) };
const uint16_t vader_type_871_refs[] = { offsetof(vader_struct_vader_resolver_Module_t, f_files) };
const uint16_t vader_type_872_strs[] = { offsetof(vader_struct_vader_resolver_ResolveState_t, f_module_path) };
const uint16_t vader_type_872_refs[] = { offsetof(vader_struct_vader_resolver_ResolveState_t, f_idents), offsetof(vader_struct_vader_resolver_ResolveState_t, f_immutable_locals), offsetof(vader_struct_vader_resolver_ResolveState_t, f_immutable_borrows), offsetof(vader_struct_vader_resolver_ResolveState_t, f_type_param_bounds), offsetof(vader_struct_vader_resolver_ResolveState_t, f_diags), offsetof(vader_struct_vader_resolver_ResolveState_t, f_scope), offsetof(vader_struct_vader_resolver_ResolveState_t, f_factory), offsetof(vader_struct_vader_resolver_ResolveState_t, f_ambiguous) };
const uint16_t vader_type_873_refs[] = { offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_top_level), offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_idents), offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_immutable_locals), offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_immutable_borrows), offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_type_param_bounds), offsetof(vader_struct_vader_resolver_ResolvedFile_t, f_diags) };
const uint16_t vader_type_874_strs[] = { offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_path), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_display_path) };
const uint16_t vader_type_874_refs[] = { offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_symbols), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_idents), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_immutable_locals), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_immutable_borrows), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_fn_overloads), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_imports_to), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_alias_types), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_alias_decls), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_type_param_bounds), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_diags), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_deprecated_messages), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_namespace_member_types), offsetof(vader_struct_vader_resolver_ResolvedModule_t, f_namespace_private_members) };
const uint16_t vader_type_875_refs[] = { offsetof(vader_struct_vader_resolver_Scope_t, f_frames) };
const uint16_t vader_type_876_strs[] = { offsetof(vader_struct_vader_resolver_SourceFile_t, f_path), offsetof(vader_struct_vader_resolver_SourceFile_t, f_content) };
const uint16_t vader_type_876_refs[] = { offsetof(vader_struct_vader_resolver_SourceFile_t, f_program), offsetof(vader_struct_vader_resolver_SourceFile_t, f_id_factory) };
const uint16_t vader_type_877_strs[] = { offsetof(vader_struct_vader_resolver_StampCtx_t, f_file) };
const uint16_t vader_type_878_refs[] = { offsetof(vader_struct_vader_resolver_Subst_t, f_entries) };
const uint16_t vader_type_879_strs[] = { offsetof(vader_struct_vader_resolver_SymbolTarget_t, f_module_id) };
const uint16_t vader_type_879_refs[] = { offsetof(vader_struct_vader_resolver_SymbolTarget_t, f_symbol) };
const uint16_t vader_type_880_refs[] = { offsetof(vader_struct_vader_resolver_TargetSelectors_t, f_os) };
const uint16_t vader_type_881_ptrs[] = { offsetof(vader_struct_vader_resolver_symbol_Symbol_t, f_defined_at) };
const uint16_t vader_type_881_strs[] = { offsetof(vader_struct_vader_resolver_symbol_Symbol_t, f_name), offsetof(vader_struct_vader_resolver_symbol_Symbol_t, f_module) };
const uint16_t vader_type_885_ptrs[] = { offsetof(vader_struct_vader_typecheck_BlockNarrow_t, f_static_ty), offsetof(vader_struct_vader_typecheck_BlockNarrow_t, f_else_ty) };
const uint16_t vader_type_885_strs[] = { offsetof(vader_struct_vader_typecheck_BlockNarrow_t, f_field_key) };
const uint16_t vader_type_886_refs[] = { offsetof(vader_struct_vader_typecheck_CheckResult_t, f_typed), offsetof(vader_struct_vader_typecheck_CheckResult_t, f_impls), offsetof(vader_struct_vader_typecheck_CheckResult_t, f_others), offsetof(vader_struct_vader_typecheck_CheckResult_t, f_all_modules) };
const uint16_t vader_type_887_strs[] = { offsetof(vader_struct_vader_typecheck_DeadDecl_t, f_name) };
const uint16_t vader_type_887_refs[] = { offsetof(vader_struct_vader_typecheck_DeadDecl_t, f_name_span) };
const uint16_t vader_type_888_ptrs[] = { offsetof(vader_struct_vader_typecheck_DivergentNarrow_t, f_prev) };
const uint16_t vader_type_888_strs[] = { offsetof(vader_struct_vader_typecheck_DivergentNarrow_t, f_field_key) };
const uint16_t vader_type_889_ptrs[] = { offsetof(vader_struct_vader_typecheck_EnclosingLoop_t, f_binding), offsetof(vader_struct_vader_typecheck_EnclosingLoop_t, f_label) };
const uint16_t vader_type_890_ptrs[] = { offsetof(vader_struct_vader_typecheck_FieldChainStatic_t, f_static_ty) };
const uint16_t vader_type_890_strs[] = { offsetof(vader_struct_vader_typecheck_FieldChainStatic_t, f_field_key) };
const uint16_t vader_type_891_ptrs[] = { offsetof(vader_struct_vader_typecheck_FnContext_t, f_return_type), offsetof(vader_struct_vader_typecheck_FnContext_t, f_self_type), offsetof(vader_struct_vader_typecheck_FnContext_t, f_yield_type), offsetof(vader_struct_vader_typecheck_FnContext_t, f_inferred_return) };
const uint16_t vader_type_892_ptrs[] = { offsetof(vader_struct_vader_typecheck_GenStateEntry_t, f_element) };
const uint16_t vader_type_892_strs[] = { offsetof(vader_struct_vader_typecheck_GenStateEntry_t, f_name), offsetof(vader_struct_vader_typecheck_GenStateEntry_t, f_module) };
const uint16_t vader_type_893_ptrs[] = { offsetof(vader_struct_vader_typecheck_ImplEntry_t, f_for_symbol) };
const uint16_t vader_type_893_strs[] = { offsetof(vader_struct_vader_typecheck_ImplEntry_t, f_module) };
const uint16_t vader_type_893_refs[] = { offsetof(vader_struct_vader_typecheck_ImplEntry_t, f_decl), offsetof(vader_struct_vader_typecheck_ImplEntry_t, f_trait_symbol) };
const uint16_t vader_type_894_ptrs[] = { offsetof(vader_struct_vader_typecheck_ImplMethod_t, f_ty) };
const uint16_t vader_type_895_refs[] = { offsetof(vader_struct_vader_typecheck_ImplRegistry_t, f_user_index), offsetof(vader_struct_vader_typecheck_ImplRegistry_t, f_all) };
const uint16_t vader_type_896_ptrs[] = { offsetof(vader_struct_vader_typecheck_IsNarrow_t, f_static_ty), offsetof(vader_struct_vader_typecheck_IsNarrow_t, f_then_ty), offsetof(vader_struct_vader_typecheck_IsNarrow_t, f_else_ty) };
const uint16_t vader_type_896_strs[] = { offsetof(vader_struct_vader_typecheck_IsNarrow_t, f_field_key) };
const uint16_t vader_type_897_ptrs[] = { offsetof(vader_struct_vader_typecheck_NamedDeclLookup_t, f_trait_decl) };
const uint16_t vader_type_897_strs[] = { offsetof(vader_struct_vader_typecheck_NamedDeclLookup_t, f_other_kind) };
const uint16_t vader_type_898_strs[] = { offsetof(vader_struct_vader_typecheck_NamedDeclRefs_t, f_name) };
const uint16_t vader_type_898_refs[] = { offsetof(vader_struct_vader_typecheck_NamedDeclRefs_t, f_name_span), offsetof(vader_struct_vader_typecheck_NamedDeclRefs_t, f_decorators), offsetof(vader_struct_vader_typecheck_NamedDeclRefs_t, f_refs) };
const uint16_t vader_type_899_ptrs[] = { offsetof(vader_struct_vader_typecheck_NarrowSlot_t, f_ty) };
const uint16_t vader_type_900_ptrs[] = { offsetof(vader_struct_vader_typecheck_PushedNarrow_t, f_prev) };
const uint16_t vader_type_900_strs[] = { offsetof(vader_struct_vader_typecheck_PushedNarrow_t, f_field_key) };
const uint16_t vader_type_902_ptrs[] = { offsetof(vader_struct_vader_typecheck_Substitution_t, f_self_type) };
const uint16_t vader_type_902_refs[] = { offsetof(vader_struct_vader_typecheck_Substitution_t, f_type_params) };
const uint16_t vader_type_903_ptrs[] = { offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_import_targets), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_range_symbol), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_field_symbol), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_async_symbol), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_run_async_main_symbol), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_current_fn_ctx) };
const uint16_t vader_type_903_refs[] = { offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_resolved), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_expr_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_into_coercions), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_local_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_empty_array_inits), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_decl_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_impl_method_decl_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_param_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_type_expr_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_struct_decls), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_trait_decls), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_fn_decls), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_trait_decl_owners), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_impl_methods), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_narrowed_bindings), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_narrowed_fields), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_narrow_kill_gens), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_narrow_field_kill_gens), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_expr_kinds), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_external_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_namespace_exports), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_namespace_export_params), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_imported_fn_overloads), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_iter_element_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_index_target_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_index_key_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_index_set_value_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_ufcs_receiver_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_impl_method_traits), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_struct_field_types), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_struct_implemented_traits), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_struct_traits_by_sym), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_struct_trait_args), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_node_spans), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_generator_symbols), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_extern_symbols), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_let_type_aliases), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_local_init_callee), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_loop_var_iterable), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_local_annotation), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_local_init_index), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_narrow_binding_scrutinee), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_const_decls), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_bounded_dispatch_trait), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_fn_trait_dispatches), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_overload_result_callees), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_loop_stack), offsetof(vader_struct_vader_typecheck_TypedProgram_t, f_loop_target_labels) };
const uint16_t vader_type_904_refs[] = { offsetof(vader_struct_vader_typecheck_TypedProject_t, f_modules) };
const uint16_t vader_type_905_ptrs[] = { offsetof(vader_struct_vader_typecheck_UfcsResult_t, f_curried), offsetof(vader_struct_vader_typecheck_UfcsResult_t, f_first_param) };
const uint16_t vader_type_907_ptrs[] = { offsetof(vader_struct_vader_types_ArrayType_t, f_element) };
const uint16_t vader_type_908_ptrs[] = { offsetof(vader_struct_vader_types_DistinctType_t, f_backing) };
const uint16_t vader_type_908_refs[] = { offsetof(vader_struct_vader_types_DistinctType_t, f_symbol) };
const uint16_t vader_type_909_strs[] = { offsetof(vader_struct_vader_types_EnumType_t, f_repr) };
const uint16_t vader_type_909_refs[] = { offsetof(vader_struct_vader_types_EnumType_t, f_symbol), offsetof(vader_struct_vader_types_EnumType_t, f_indices) };
const uint16_t vader_type_910_ptrs[] = { offsetof(vader_struct_vader_types_FnType_t, f_return_type) };
const uint16_t vader_type_910_refs[] = { offsetof(vader_struct_vader_types_FnType_t, f_params), offsetof(vader_struct_vader_types_FnType_t, f_params_mutable) };
const uint16_t vader_type_915_strs[] = { offsetof(vader_struct_vader_types_PrimitiveMeta_t, f_name) };
const uint16_t vader_type_916_strs[] = { offsetof(vader_struct_vader_types_PrimitiveType_t, f_name) };
const uint16_t vader_type_918_refs[] = { offsetof(vader_struct_vader_types_StructType_t, f_symbol), offsetof(vader_struct_vader_types_StructType_t, f_args) };
const uint16_t vader_type_919_refs[] = { offsetof(vader_struct_vader_types_TraitType_t, f_symbol), offsetof(vader_struct_vader_types_TraitType_t, f_args) };
const uint16_t vader_type_920_refs[] = { offsetof(vader_struct_vader_types_TupleType_t, f_elements) };
const uint16_t vader_type_922_refs[] = { offsetof(vader_struct_vader_types_TypeParamType_t, f_symbol) };
const uint16_t vader_type_923_refs[] = { offsetof(vader_struct_vader_types_UnionType_t, f_variants) };
const uint16_t vader_type_925_refs[] = { offsetof(vader_struct_vader_vm_ArrayVal_t, f_elements) };
const uint16_t vader_type_928_refs[] = { offsetof(vader_struct_vader_vm_DebugController_t, f_output_sink), offsetof(vader_struct_vader_vm_DebugController_t, f_breakpoints), offsetof(vader_struct_vader_vm_DebugController_t, f_on_pause) };
const uint16_t vader_type_929_strs[] = { offsetof(vader_struct_vader_vm_ErrorVal_t, f_message) };
const uint16_t vader_type_931_refs[] = { offsetof(vader_struct_vader_vm_FfiCallArgs_t, f_args) };
const uint16_t vader_type_932_ptrs[] = { offsetof(vader_struct_vader_vm_FnVal_t, f_env) };
const uint16_t vader_type_933_refs[] = { offsetof(vader_struct_vader_vm_Frame_t, f_slots), offsetof(vader_struct_vader_vm_Frame_t, f_stack), offsetof(vader_struct_vader_vm_Frame_t, f_payload), offsetof(vader_struct_vader_vm_Frame_t, f_tag), offsetof(vader_struct_vader_vm_Frame_t, f_slot_payload), offsetof(vader_struct_vader_vm_Frame_t, f_slot_tag), offsetof(vader_struct_vader_vm_Frame_t, f_defers) };
const uint16_t vader_type_934_ptrs[] = { offsetof(vader_struct_vader_vm_HostOk_t, f_value) };
const uint16_t vader_type_938_refs[] = { offsetof(vader_struct_vader_vm_ObjVal_t, f_bytes), offsetof(vader_struct_vader_vm_ObjVal_t, f_slots) };
const uint16_t vader_type_940_strs[] = { offsetof(vader_struct_vader_vm_PauseCtx_t, f_reason) };
const uint16_t vader_type_940_refs[] = { offsetof(vader_struct_vader_vm_PauseCtx_t, f_frames) };
const uint16_t vader_type_941_strs[] = { offsetof(vader_struct_vader_vm_PauseFrame_t, f_function_name), offsetof(vader_struct_vader_vm_PauseFrame_t, f_file) };
const uint16_t vader_type_941_refs[] = { offsetof(vader_struct_vader_vm_PauseFrame_t, f_locals) };
const uint16_t vader_type_942_strs[] = { offsetof(vader_struct_vader_vm_PauseVar_t, f_name), offsetof(vader_struct_vader_vm_PauseVar_t, f_value) };
const uint16_t vader_type_942_refs[] = { offsetof(vader_struct_vader_vm_PauseVar_t, f_children) };
const uint16_t vader_type_943_strs[] = { offsetof(vader_struct_vader_vm_StringVal_t, f_value) };
const uint16_t vader_type_944_refs[] = { offsetof(vader_struct_vader_vm_StructVal_t, f_fields) };
const uint16_t vader_type_945_strs[] = { offsetof(vader_struct_vader_vm_Trap_t, f_message) };
const uint16_t vader_type_947_ptrs[] = { offsetof(vader_struct_vader_vm_ValueOk_t, f_value) };
const uint16_t vader_type_948_refs[] = { offsetof(vader_struct_vader_vm_VmState_t, f_bc), offsetof(vader_struct_vader_vm_VmState_t, f_data_pool), offsetof(vader_struct_vader_vm_VmState_t, f_fn_narrow), offsetof(vader_struct_vader_vm_VmState_t, f_fn_index_by_name) };

const vader_type_info_t vader_type_info_table[1244] = {
    [1] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_1_ptrs, 1, 0, NULL, 0, NULL },
    [2] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_2_ptrs, 1, 0, NULL, 0, NULL },
    [3] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_3_ptrs, 1, 0, NULL, 0, NULL },
    [4] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_4_ptrs, 1, 0, NULL, 0, NULL },
    [5] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_5_ptrs, 1, 0, NULL, 0, NULL },
    [6] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_6_ptrs, 1, 0, NULL, 0, NULL },
    [7] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_7_ptrs, 1, 0, NULL, 0, NULL },
    [8] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_8_ptrs, 1, 0, NULL, 0, NULL },
    [9] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_9_ptrs, 1, 0, NULL, 0, NULL },
    [10] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_10_ptrs, 1, 0, NULL, 0, NULL },
    [11] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_11_ptrs, 1, 0, NULL, 0, NULL },
    [12] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_12_ptrs, 1, 0, NULL, 0, NULL },
    [13] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_13_ptrs, 1, 0, NULL, 0, NULL },
    [14] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_14_ptrs, 1, 0, NULL, 0, NULL },
    [15] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_15_ptrs, 1, 0, NULL, 0, NULL },
    [16] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_16_ptrs, 1, 0, NULL, 0, NULL },
    [17] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_17_ptrs, 1, 0, NULL, 0, NULL },
    [18] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_18_ptrs, 1, 0, NULL, 0, NULL },
    [19] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_19_ptrs, 1, 0, NULL, 0, NULL },
    [20] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_20_ptrs, 1, 0, NULL, 0, NULL },
    [21] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_21_ptrs, 1, 0, NULL, 0, NULL },
    [22] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_22_ptrs, 1, 0, NULL, 0, NULL },
    [23] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_23_ptrs, 1, 0, NULL, 0, NULL },
    [24] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_24_ptrs, 1, 0, NULL, 0, NULL },
    [25] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_25_ptrs, 1, 0, NULL, 0, NULL },
    [26] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_26_ptrs, 1, 0, NULL, 0, NULL },
    [27] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_27_ptrs, 1, 0, NULL, 0, NULL },
    [28] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_28_ptrs, 1, 0, NULL, 0, NULL },
    [29] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_29_ptrs, 1, 0, NULL, 0, NULL },
    [30] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_30_ptrs, 1, 0, NULL, 0, NULL },
    [31] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_31_ptrs, 1, 0, NULL, 0, NULL },
    [32] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_32_ptrs, 1, 0, NULL, 0, NULL },
    [33] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_33_ptrs, 1, 0, NULL, 0, NULL },
    [34] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_34_ptrs, 1, 0, NULL, 0, NULL },
    [35] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_35_ptrs, 1, 0, NULL, 0, NULL },
    [36] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_36_ptrs, 1, 0, NULL, 0, NULL },
    [37] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_37_ptrs, 1, 0, NULL, 0, NULL },
    [38] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_38_ptrs, 1, 0, NULL, 0, NULL },
    [39] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_39_ptrs, 1, 0, NULL, 0, NULL },
    [40] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_40_ptrs, 1, 0, NULL, 0, NULL },
    [41] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_41_ptrs, 1, 0, NULL, 0, NULL },
    [42] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_42_ptrs, 1, 0, NULL, 0, NULL },
    [43] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_43_ptrs, 1, 0, NULL, 0, NULL },
    [44] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_44_ptrs, 1, 0, NULL, 0, NULL },
    [45] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_45_ptrs, 1, 0, NULL, 0, NULL },
    [46] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_46_ptrs, 1, 0, NULL, 0, NULL },
    [47] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_47_ptrs, 1, 0, NULL, 0, NULL },
    [48] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_48_ptrs, 1, 0, NULL, 0, NULL },
    [49] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_49_ptrs, 1, 0, NULL, 0, NULL },
    [50] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_50_ptrs, 1, 0, NULL, 0, NULL },
    [51] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_51_ptrs, 1, 0, NULL, 0, NULL },
    [52] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_52_ptrs, 1, 0, NULL, 0, NULL },
    [53] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_53_ptrs, 1, 0, NULL, 0, NULL },
    [54] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_54_ptrs, 1, 0, NULL, 0, NULL },
    [55] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_55_ptrs, 1, 0, NULL, 0, NULL },
    [56] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_56_ptrs, 1, 0, NULL, 0, NULL },
    [57] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_57_ptrs, 1, 0, NULL, 0, NULL },
    [58] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_58_ptrs, 1, 0, NULL, 0, NULL },
    [59] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_59_ptrs, 1, 0, NULL, 0, NULL },
    [60] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_60_ptrs, 1, 0, NULL, 0, NULL },
    [61] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_61_ptrs, 1, 0, NULL, 0, NULL },
    [62] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_62_ptrs, 1, 0, NULL, 0, NULL },
    [63] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_63_ptrs, 1, 0, NULL, 0, NULL },
    [64] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_64_ptrs, 1, 0, NULL, 0, NULL },
    [65] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_65_ptrs, 1, 0, NULL, 0, NULL },
    [66] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_66_ptrs, 1, 0, NULL, 0, NULL },
    [67] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_67_ptrs, 1, 0, NULL, 0, NULL },
    [68] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_68_ptrs, 1, 0, NULL, 0, NULL },
    [69] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_69_ptrs, 1, 0, NULL, 0, NULL },
    [70] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_70_ptrs, 1, 0, NULL, 0, NULL },
    [71] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_71_ptrs, 1, 0, NULL, 0, NULL },
    [72] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_72_ptrs, 1, 0, NULL, 0, NULL },
    [73] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_73_ptrs, 1, 0, NULL, 0, NULL },
    [74] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_74_ptrs, 1, 0, NULL, 0, NULL },
    [75] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_75_ptrs, 1, 0, NULL, 0, NULL },
    [76] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_76_ptrs, 1, 0, NULL, 0, NULL },
    [77] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_77_ptrs, 1, 0, NULL, 0, NULL },
    [78] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_78_ptrs, 1, 0, NULL, 0, NULL },
    [79] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_79_ptrs, 1, 0, NULL, 0, NULL },
    [80] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_80_ptrs, 1, 0, NULL, 0, NULL },
    [81] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_81_ptrs, 1, 0, NULL, 0, NULL },
    [82] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_82_ptrs, 1, 0, NULL, 0, NULL },
    [83] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_83_ptrs, 1, 0, NULL, 0, NULL },
    [84] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_84_ptrs, 1, 0, NULL, 0, NULL },
    [85] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_85_ptrs, 1, 0, NULL, 0, NULL },
    [86] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_86_ptrs, 1, 0, NULL, 0, NULL },
    [87] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_87_ptrs, 1, 0, NULL, 0, NULL },
    [88] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_88_ptrs, 1, 0, NULL, 0, NULL },
    [89] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_89_ptrs, 1, 0, NULL, 0, NULL },
    [90] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_90_ptrs, 1, 0, NULL, 0, NULL },
    [91] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_91_ptrs, 1, 0, NULL, 0, NULL },
    [92] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_92_ptrs, 1, 0, NULL, 0, NULL },
    [93] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_93_ptrs, 1, 0, NULL, 0, NULL },
    [94] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_94_ptrs, 1, 0, NULL, 0, NULL },
    [95] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_95_ptrs, 1, 0, NULL, 0, NULL },
    [96] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_96_ptrs, 1, 0, NULL, 0, NULL },
    [97] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_97_ptrs, 1, 0, NULL, 0, NULL },
    [98] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_98_ptrs, 1, 0, NULL, 0, NULL },
    [99] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_99_ptrs, 1, 0, NULL, 0, NULL },
    [100] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_100_ptrs, 1, 0, NULL, 0, NULL },
    [101] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_101_ptrs, 1, 0, NULL, 0, NULL },
    [102] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_102_ptrs, 1, 0, NULL, 0, NULL },
    [103] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_103_ptrs, 1, 0, NULL, 0, NULL },
    [104] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_104_ptrs, 1, 0, NULL, 0, NULL },
    [105] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_105_ptrs, 1, 0, NULL, 0, NULL },
    [106] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_106_ptrs, 1, 0, NULL, 0, NULL },
    [107] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_107_ptrs, 1, 0, NULL, 0, NULL },
    [108] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_108_ptrs, 1, 0, NULL, 0, NULL },
    [109] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_109_ptrs, 1, 0, NULL, 0, NULL },
    [110] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_110_ptrs, 1, 0, NULL, 0, NULL },
    [111] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_111_ptrs, 1, 0, NULL, 0, NULL },
    [112] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_112_ptrs, 1, 0, NULL, 0, NULL },
    [113] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_113_ptrs, 1, 0, NULL, 0, NULL },
    [114] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_114_ptrs, 1, 0, NULL, 0, NULL },
    [115] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_115_ptrs, 1, 0, NULL, 0, NULL },
    [116] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_116_ptrs, 1, 0, NULL, 0, NULL },
    [117] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_117_ptrs, 1, 0, NULL, 0, NULL },
    [118] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_118_ptrs, 1, 0, NULL, 0, NULL },
    [119] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_119_ptrs, 1, 0, NULL, 0, NULL },
    [120] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_120_ptrs, 1, 0, NULL, 0, NULL },
    [121] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_121_ptrs, 1, 0, NULL, 0, NULL },
    [122] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_122_ptrs, 1, 0, NULL, 0, NULL },
    [123] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_123_ptrs, 1, 0, NULL, 0, NULL },
    [124] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_124_ptrs, 1, 0, NULL, 0, NULL },
    [125] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_125_ptrs, 1, 0, NULL, 0, NULL },
    [126] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_126_ptrs, 1, 0, NULL, 0, NULL },
    [127] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_127_ptrs, 1, 0, NULL, 0, NULL },
    [128] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_128_ptrs, 1, 0, NULL, 0, NULL },
    [129] = { VADER_TYPE_KIND_ARRAY, sizeof(vader_array_t), vader_type_129_ptrs, 1, 0, NULL, 0, NULL },
    [130] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_130_ptrs, 1, 0, NULL, 0, NULL },
    [131] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_131_ptrs, 1, 0, NULL, 0, NULL },
    [132] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_132_ptrs, 1, 0, NULL, 0, NULL },
    [133] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_133_ptrs, 1, 0, NULL, 0, NULL },
    [134] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_134_ptrs, 1, 0, NULL, 0, NULL },
    [135] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_135_ptrs, 1, 0, NULL, 0, NULL },
    [136] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_136_ptrs, 1, 0, NULL, 0, NULL },
    [137] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_137_ptrs, 1, 0, NULL, 0, NULL },
    [138] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_138_ptrs, 1, 0, NULL, 0, NULL },
    [139] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_139_ptrs, 1, 0, NULL, 0, NULL },
    [140] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_140_ptrs, 1, 0, NULL, 0, NULL },
    [141] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_141_ptrs, 1, 0, NULL, 0, NULL },
    [142] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_142_ptrs, 1, 0, NULL, 0, NULL },
    [143] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_143_ptrs, 1, 0, NULL, 0, NULL },
    [144] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_144_ptrs, 1, 0, NULL, 0, NULL },
    [145] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_145_ptrs, 1, 0, NULL, 0, NULL },
    [146] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_146_ptrs, 1, 0, NULL, 0, NULL },
    [147] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_147_ptrs, 1, 0, NULL, 0, NULL },
    [148] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_148_ptrs, 1, 0, NULL, 0, NULL },
    [149] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_149_ptrs, 1, 0, NULL, 0, NULL },
    [150] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_150_ptrs, 1, 0, NULL, 0, NULL },
    [151] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_151_ptrs, 1, 0, NULL, 0, NULL },
    [152] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_152_ptrs, 1, 0, NULL, 0, NULL },
    [153] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_153_ptrs, 1, 0, NULL, 0, NULL },
    [154] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_154_ptrs, 1, 0, NULL, 0, NULL },
    [155] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_155_ptrs, 1, 0, NULL, 0, NULL },
    [156] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_156_ptrs, 1, 0, NULL, 0, NULL },
    [157] = { VADER_TYPE_KIND_FN, sizeof(vader_fn_t), vader_type_157_ptrs, 1, 0, NULL, 0, NULL },
    [173] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Array_Struct_vader_bytecode_module_vader_1754____t), NULL, 0, 0, NULL, 1, vader_type_173_refs },
    [174] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Array_Struct_vader_diagnostics_diagnostic_vader_598____t), NULL, 0, 0, NULL, 1, vader_type_174_refs },
    [175] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Array_Struct_vader_types_types_vader_598____t), NULL, 0, 0, NULL, 1, vader_type_175_refs },
    [176] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Array_Union_Struct_vader_lower_lowered_ast_vader_6883___Struct_vader_lower_lowered_ast_vader_6538___Struct_vader_lower_lowered_ast_vader_6766_____t), NULL, 0, 0, NULL, 1, vader_type_176_refs },
    [177] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Array_bool__t), NULL, 0, 0, NULL, 1, vader_type_177_refs },
    [178] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Array_i32__t), NULL, 0, 0, NULL, 1, vader_type_178_refs },
    [179] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Array_string__t), NULL, 0, 0, NULL, 1, vader_type_179_refs },
    [180] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Fn_Union_Struct_lib_toolchain_ast_ast_vader_41069___Struct_lib_toolchain_ast_ast_vader_35146___Struct_lib_toolchain_ast_ast_vader_29535___Struct_lib_toolchain_ast_ast_vader_32672___Struct_lib_toolchain_ast_ast_vader_25426___Struct_lib_toolchain_ast_ast_vader_27472___Struct_lib_toolchain_ast_ast_vader_35435___Struct_lib_toolchain_ast_ast_vader_25803___Struct_lib_toolchain_ast_ast_vader_36443___Struct_lib_toolchain_ast_ast_vader_28300___Struct_lib_toolchain_ast_ast_vader_25296___Struct_lib_toolchain_ast_ast_vader_40242___Struct_lib_toolchain_ast_ast_vader_35618___Struct_lib_toolchain_ast_ast_vader_27070___Struct_lib_toolchain_ast_ast_vader_30827___Struct_lib_toolchain_ast_ast_vader_28661___Struct_lib_toolchain_ast_ast_vader_24920___Struct_lib_toolchain_ast_ast_vader_36102___Struct_lib_toolchain_ast_ast_vader_32925___Struct_lib_toolchain_ast_ast_vader_31377___Struct_lib_toolchain_ast_ast_vader_41788___Struct_lib_toolchain_ast_ast_vader_30399___Struct_lib_toolchain_ast_ast_vader_25554___Struct_lib_toolchain_ast_ast_vader_34731___Struct_lib_toolchain_ast_ast_vader_34404___Struct_lib_toolchain_ast_ast_vader_26144___Struct_lib_toolchain_ast_ast_vader_33406___Struct_lib_toolchain_ast_ast_vader_29020____Union_Struct_vader_types_types_vader_3956___Struct_vader_types_types_vader_3074___Struct_vader_types_types_vader_1850___Struct_vader_types_types_vader_998___Struct_vader_types_types_vader_2423___Struct_vader_types_types_vader_4584___Struct_vader_types_types_vader_4158___Struct_vader_types_types_vader_4054___Struct_vader_types_types_vader_4689___null_Struct_vader_types_types_vader_545___Struct_vader_types_types_vader_3549___Struct_vader_types_types_vader_598___Struct_vader_types_types_vader_2238___Struct_vader_types_types_vader_3218___Struct_vader_types_types_vader_3516___Struct_vader_types_types_vader_3461___Struct_vader_types_types_vader_2308___Struct_vader_types_types_vader_3578____Struct_vader_typecheck_typed_ast_vader_4821___Array_Struct_vader_diagnostics_diagnostic_vader_598______Union_Struct_vader_types_types_vader_3956___Struct_vader_types_types_vader_3074___Struct_vader_types_types_vader_1850___Struct_vader_types_types_vader_998___Struct_vader_types_types_vader_2423___Struct_vader_types_types_vader_4584___Struct_vader_types_types_vader_4158___Struct_vader_types_types_vader_4054___Struct_vader_types_types_vader_4689___Struct_vader_types_types_vader_545___Struct_vader_types_types_vader_3549___Struct_vader_types_types_vader_598___Struct_vader_types_types_vader_2238___Struct_vader_types_types_vader_3218___Struct_vader_types_types_vader_3516___Struct_vader_types_types_vader_3461___Struct_vader_types_types_vader_2308___Struct_vader_types_types_vader_3578____t), NULL, 0, 0, NULL, 1, vader_type_180_refs },
    [181] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Fn_i32___void_t), NULL, 0, 0, NULL, 1, vader_type_181_refs },
    [182] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_13537_i32__t), NULL, 0, 0, NULL, 1, vader_type_182_refs },
    [183] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_13537_string__t), NULL, 0, 0, NULL, 1, vader_type_183_refs },
    [184] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_i32_Union_Struct_vader_lower_lowered_ast_vader_6883___Struct_vader_lower_lowered_ast_vader_6538___Struct_vader_lower_lowered_ast_vader_6766_____t), NULL, 0, 0, NULL, 1, vader_type_184_refs },
    [185] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_i32_bool__t), NULL, 0, 0, NULL, 1, vader_type_185_refs },
    [186] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_i32_i32__t), NULL, 0, 0, NULL, 1, vader_type_186_refs },
    [187] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_string_Union_Struct_vader_lower_lowered_ast_vader_6883___Struct_vader_lower_lowered_ast_vader_6538___Struct_vader_lower_lowered_ast_vader_6766_____t), NULL, 0, 0, NULL, 1, vader_type_187_refs },
    [188] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_string_bool__t), NULL, 0, 0, NULL, 1, vader_type_188_refs },
    [189] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Struct_vader_typecheck_typed_ast_vader_4821___t), NULL, 0, 0, NULL, 1, vader_type_189_refs },
    [190] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_Union_Struct_vader_types_types_vader_3956___Struct_vader_types_types_vader_3074___Struct_vader_types_types_vader_1850___Struct_vader_types_types_vader_998___Struct_vader_types_types_vader_2423___Struct_vader_types_types_vader_4584___Struct_vader_types_types_vader_4158___Struct_vader_types_types_vader_4054___Struct_vader_types_types_vader_4689___null_Struct_vader_types_types_vader_545___Struct_vader_types_types_vader_3549___Struct_vader_types_types_vader_598___Struct_vader_types_types_vader_2238___Struct_vader_types_types_vader_3218___Struct_vader_types_types_vader_3516___Struct_vader_types_types_vader_3461___Struct_vader_types_types_vader_2308___Struct_vader_types_types_vader_3578____t), vader_type_190_ptrs, 1, 0, NULL, 0, NULL },
    [191] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_i32_t), NULL, 0, 0, NULL, 0, NULL },
    [192] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct__Cell_usize_t), NULL, 0, 0, NULL, 0, NULL },
    [193] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1135_t), NULL, 0, 1, vader_type_193_strs, 1, vader_type_193_refs },
    [194] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1137_t), NULL, 0, 1, vader_type_194_strs, 1, vader_type_194_refs },
    [195] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1139_t), NULL, 0, 1, vader_type_195_strs, 1, vader_type_195_refs },
    [196] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1140_t), NULL, 0, 2, vader_type_196_strs, 0, NULL },
    [197] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1142_t), NULL, 0, 0, NULL, 1, vader_type_197_refs },
    [198] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1146_t), NULL, 0, 1, vader_type_198_strs, 1, vader_type_198_refs },
    [199] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1149_t), NULL, 0, 1, vader_type_199_strs, 1, vader_type_199_refs },
    [200] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1150_t), vader_type_200_ptrs, 1, 0, NULL, 0, NULL },
    [201] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1152_t), NULL, 0, 0, NULL, 1, vader_type_201_refs },
    [202] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1154_t), NULL, 0, 0, NULL, 1, vader_type_202_refs },
    [203] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1155_t), NULL, 0, 1, vader_type_203_strs, 0, NULL },
    [204] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1157_t), NULL, 0, 0, NULL, 1, vader_type_204_refs },
    [205] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1159_t), NULL, 0, 0, NULL, 1, vader_type_205_refs },
    [206] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1162_t), NULL, 0, 0, NULL, 1, vader_type_206_refs },
    [207] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1163_t), NULL, 0, 0, NULL, 1, vader_type_207_refs },
    [208] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1164_t), vader_type_208_ptrs, 1, 1, vader_type_208_strs, 0, NULL },
    [209] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1169_t), NULL, 0, 1, vader_type_209_strs, 1, vader_type_209_refs },
    [210] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1174_t), NULL, 0, 1, vader_type_210_strs, 0, NULL },
    [211] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1184_t), NULL, 0, 0, NULL, 1, vader_type_211_refs },
    [212] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1211_t), NULL, 0, 1, vader_type_212_strs, 1, vader_type_212_refs },
    [213] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1213_t), vader_type_213_ptrs, 1, 0, NULL, 0, NULL },
    [214] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1214_t), vader_type_214_ptrs, 1, 0, NULL, 0, NULL },
    [215] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1216_t), NULL, 0, 1, vader_type_215_strs, 1, vader_type_215_refs },
    [216] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1218_t), vader_type_216_ptrs, 1, 0, NULL, 0, NULL },
    [217] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1229_t), NULL, 0, 1, vader_type_217_strs, 1, vader_type_217_refs },
    [218] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1231_t), NULL, 0, 0, NULL, 1, vader_type_218_refs },
    [219] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1234_t), NULL, 0, 1, vader_type_219_strs, 1, vader_type_219_refs },
    [220] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1254_t), NULL, 0, 1, vader_type_220_strs, 1, vader_type_220_refs },
    [221] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1260_t), NULL, 0, 0, NULL, 1, vader_type_221_refs },
    [222] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1270_t), vader_type_222_ptrs, 1, 0, NULL, 0, NULL },
    [223] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1274_t), NULL, 0, 0, NULL, 0, NULL },
    [224] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1275_t), NULL, 0, 0, NULL, 0, NULL },
    [225] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1276_t), NULL, 0, 1, vader_type_225_strs, 0, NULL },
    [226] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1277_t), NULL, 0, 0, NULL, 1, vader_type_226_refs },
    [227] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_1282_t), NULL, 0, 1, vader_type_227_strs, 1, vader_type_227_refs },
    [228] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_253_t), NULL, 0, 0, NULL, 0, NULL },
    [229] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_45_t), NULL, 0, 0, NULL, 0, NULL },
    [230] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_49_t), NULL, 0, 0, NULL, 1, vader_type_230_refs },
    [231] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___Tuple_52_t), NULL, 0, 0, NULL, 0, NULL },
    [232] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_1361_t), vader_type_232_ptrs, 1, 0, NULL, 0, NULL },
    [233] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_1371_t), NULL, 0, 0, NULL, 0, NULL },
    [234] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_1647_t), vader_type_234_ptrs, 2, 0, NULL, 0, NULL },
    [235] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_175_t), NULL, 0, 0, NULL, 0, NULL },
    [236] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_1772_t), vader_type_236_ptrs, 2, 0, NULL, 0, NULL },
    [237] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_1775_t), vader_type_237_ptrs, 2, 0, NULL, 0, NULL },
    [238] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_1865_t), NULL, 0, 0, NULL, 0, NULL },
    [239] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_1883_t), NULL, 0, 0, NULL, 0, NULL },
    [240] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_1997_t), NULL, 0, 0, NULL, 0, NULL },
    [241] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_2047_t), NULL, 0, 0, NULL, 0, NULL },
    [242] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_210_t), vader_type_242_ptrs, 5, 0, NULL, 0, NULL },
    [243] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_213_t), vader_type_243_ptrs, 2, 0, NULL, 0, NULL },
    [244] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_2248_t), NULL, 0, 0, NULL, 0, NULL },
    [245] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_2703_t), vader_type_245_ptrs, 1, 0, NULL, 0, NULL },
    [246] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_2849_t), vader_type_246_ptrs, 1, 0, NULL, 0, NULL },
    [247] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_2858_t), vader_type_247_ptrs, 2, 0, NULL, 0, NULL },
    [248] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_2865_t), vader_type_248_ptrs, 2, 0, NULL, 0, NULL },
    [249] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_2868_t), vader_type_249_ptrs, 2, 0, NULL, 0, NULL },
    [250] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_2874_t), NULL, 0, 0, NULL, 0, NULL },
    [251] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_2877_t), NULL, 0, 0, NULL, 0, NULL },
    [252] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_2898_t), vader_type_252_ptrs, 1, 0, NULL, 0, NULL },
    [253] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_2906_t), vader_type_253_ptrs, 2, 0, NULL, 0, NULL },
    [254] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_2909_t), vader_type_254_ptrs, 2, 0, NULL, 0, NULL },
    [255] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_2968_t), NULL, 0, 0, NULL, 0, NULL },
    [256] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_3339_t), NULL, 0, 0, NULL, 0, NULL },
    [257] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_3342_t), NULL, 0, 0, NULL, 0, NULL },
    [258] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_3345_t), NULL, 0, 0, NULL, 0, NULL },
    [259] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_3348_t), NULL, 0, 0, NULL, 0, NULL },
    [260] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_3351_t), NULL, 0, 0, NULL, 0, NULL },
    [261] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_3354_t), NULL, 0, 0, NULL, 0, NULL },
    [262] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_3357_t), NULL, 0, 0, NULL, 0, NULL },
    [263] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_3360_t), NULL, 0, 0, NULL, 0, NULL },
    [264] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_3368_t), NULL, 0, 0, NULL, 0, NULL },
    [265] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_3371_t), NULL, 0, 0, NULL, 0, NULL },
    [266] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_3374_t), NULL, 0, 0, NULL, 0, NULL },
    [267] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_3377_t), NULL, 0, 0, NULL, 0, NULL },
    [268] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_3869_t), NULL, 0, 0, NULL, 0, NULL },
    [269] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_4343_t), NULL, 0, 0, NULL, 0, NULL },
    [270] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_5171_t), vader_type_270_ptrs, 4, 0, NULL, 0, NULL },
    [271] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_5372_t), NULL, 0, 0, NULL, 0, NULL },
    [272] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct___lambda_env_5946_t), NULL, 0, 0, NULL, 0, NULL },
    [273] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_json_JsonArray_t), NULL, 0, 0, NULL, 1, vader_type_273_refs },
    [274] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_json_JsonBool_t), NULL, 0, 0, NULL, 0, NULL },
    [275] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_json_JsonError_t), NULL, 0, 1, vader_type_275_strs, 0, NULL },
    [276] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_json_JsonNull_t), NULL, 0, 0, NULL, 0, NULL },
    [277] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_json_JsonNumber_t), NULL, 0, 0, NULL, 0, NULL },
    [278] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_json_JsonObject_t), NULL, 0, 0, NULL, 1, vader_type_278_refs },
    [279] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_json_JsonString_t), NULL, 0, 1, vader_type_279_strs, 0, NULL },
    [280] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_json_Parser_t), NULL, 0, 1, vader_type_280_strs, 1, vader_type_280_refs },
    [281] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__Any_t), NULL, 0, 0, NULL, 3, vader_type_281_refs },
    [282] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t), NULL, 0, 0, NULL, 3, vader_type_282_refs },
    [283] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__Any___t), NULL, 0, 0, NULL, 3, vader_type_283_refs },
    [284] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__ArrayClear___ArrayCopy___ArrayGet___ArrayLen___ArrayNew___ArrayPush___ArrayPushAll___ArrayRemoveLast___ArrayRepeat___ArraySet___ArraySlice___BitsToF32___BitsToF64___Block___BoolAnd___BoolConst___BoolEq___BoolNe___BoolNot___BoolOr___Box___Branch___BranchIf___BufferNew___BufferToString___BufferWriteString___Call___CallImport___CallIndirect___CharConst___Convert___DataConst___DeferPopExec___DeferPush___Drop___Else___End___F32ToBits___F64Add___F64Const___F64Div___F64Eq___F64Ge___F64Gt___F64Le___F64Lt___F64Mul___F64Ne___F64Neg___F64Sub___F64ToBits___FnRef___I32Add___I32BitAnd___I32BitNot___I32BitOr___I32BitXor___I32Const___I32Div___I32Eq___I32Ge___I32Gt___I32Le___I32Lt___I32Mod___I32Mul___I32Ne___I32Neg___I32Shl___I32Shr___I32ShrU___I32Sub___I64Add___I64BitAnd___I64BitNot___I64BitOr___I64BitXor___I64Const___I64Div___I64Eq___I64Ge___I64Gt___I64Le___I64Lt___I64Mod___I64Mul___I64Ne___I64Neg___I64Shl___I64Shr___I64ShrU___I64Sub___If___LoadF64___LoadI32___LoadI64___LoadSlotF64___LoadSlotI32___LoadSlotI64___LoadU8___LocalField___LocalGet___LocalSet___LocalTee___Loop___MakeClosure___MemoryCopy___NullConst___RefCast___RefEq___RefNe___Return___ReturnLit___SizeOfType___StoreF64___StoreI32___StoreI64___StoreSlotF64___StoreSlotI32___StoreSlotI64___StoreU8___StringConst___StringEq___StringNe___StringSliceCodepoints___StructGet___StructNew___StructSet___TypeCheck___TypeConst___U32Div___U32Ge___U32Gt___U32Le___U32Lt___U32Mod___U64Div___U64Ge___U64Gt___U64Le___U64Lt___U64Mod___Unreachable___VirtualCall_t), NULL, 0, 0, NULL, 3, vader_type_284_refs },
    [285] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t), NULL, 0, 0, NULL, 3, vader_type_285_refs },
    [286] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t), NULL, 0, 0, NULL, 3, vader_type_286_refs },
    [287] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__ClosureAlias_t), NULL, 0, 0, NULL, 3, vader_type_287_refs },
    [288] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__ConstDecl_t), NULL, 0, 0, NULL, 3, vader_type_288_refs },
    [289] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__ConstFnWrap_t), NULL, 0, 0, NULL, 3, vader_type_289_refs },
    [290] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__FnDecl_t), NULL, 0, 0, NULL, 3, vader_type_290_refs },
    [291] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__ImportInfo_t), NULL, 0, 0, NULL, 3, vader_type_291_refs },
    [292] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t), NULL, 0, 0, NULL, 3, vader_type_292_refs },
    [293] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t), NULL, 0, 0, NULL, 3, vader_type_293_refs },
    [294] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__LoweredFnDecl_t), NULL, 0, 0, NULL, 3, vader_type_294_refs },
    [295] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__LoweredIdent_t), NULL, 0, 0, NULL, 3, vader_type_295_refs },
    [296] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t), NULL, 0, 0, NULL, 3, vader_type_296_refs },
    [297] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t), NULL, 0, 0, NULL, 3, vader_type_297_refs },
    [298] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t), NULL, 0, 0, NULL, 3, vader_type_298_refs },
    [299] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t), NULL, 0, 0, NULL, 3, vader_type_299_refs },
    [300] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t), NULL, 0, 0, NULL, 3, vader_type_300_refs },
    [301] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__NarrowSlot_t), NULL, 0, 0, NULL, 3, vader_type_301_refs },
    [302] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__ResolvedModule_t), NULL, 0, 0, NULL, 3, vader_type_302_refs },
    [303] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__StructDecl_t), NULL, 0, 0, NULL, 3, vader_type_303_refs },
    [304] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__Symbol_t), NULL, 0, 0, NULL, 3, vader_type_304_refs },
    [305] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__SymbolTarget_t), NULL, 0, 0, NULL, 3, vader_type_305_refs },
    [306] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__TraitDecl_t), NULL, 0, 0, NULL, 3, vader_type_306_refs },
    [307] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__TypeAliasDecl_t), NULL, 0, 0, NULL, 3, vader_type_307_refs },
    [308] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__bool_t), NULL, 0, 0, NULL, 3, vader_type_308_refs },
    [309] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__i32_t), NULL, 0, 0, NULL, 3, vader_type_309_refs },
    [310] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__i32___t), NULL, 0, 0, NULL, 3, vader_type_310_refs },
    [311] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__i32___null_t), NULL, 0, 0, NULL, 3, vader_type_311_refs },
    [312] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__string_t), NULL, 0, 0, NULL, 3, vader_type_312_refs },
    [313] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__string___t), NULL, 0, 0, NULL, 3, vader_type_313_refs },
    [314] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i32__usize_t), NULL, 0, 0, NULL, 3, vader_type_314_refs },
    [315] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i64__Any_t), NULL, 0, 0, NULL, 3, vader_type_315_refs },
    [316] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i64__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t), NULL, 0, 0, NULL, 3, vader_type_316_refs },
    [317] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__i64__bool_t), NULL, 0, 0, NULL, 3, vader_type_317_refs },
    [318] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__Any_t), NULL, 0, 0, NULL, 3, vader_type_318_refs },
    [319] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t), NULL, 0, 0, NULL, 3, vader_type_319_refs },
    [320] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__Any___t), NULL, 0, 0, NULL, 3, vader_type_320_refs },
    [321] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__ArrayTypeExpr___AwaitExpr___BinaryExpr___BlockExpr___BoolLitExpr___CallExpr___CastExpr___CharLitExpr___DotVariantExpr___FieldExpr___FloatLitExpr___FnTypeExpr___GenericInstExpr___IdentExpr___IfExpr___IndexExpr___IntLitExpr___IntrinsicCallExpr___LambdaExpr___MatchExpr___MutableTypeExpr___NullCoalesceExpr___NullLitExpr___RangeExpr___SeqLitExpr___StringLitExpr___StructLitExpr___UnaryExpr_t), NULL, 0, 0, NULL, 3, vader_type_321_refs },
    [322] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t), NULL, 0, 0, NULL, 3, vader_type_322_refs },
    [323] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__CFGModule_t), NULL, 0, 0, NULL, 3, vader_type_323_refs },
    [324] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__Capture___t), NULL, 0, 0, NULL, 3, vader_type_324_refs },
    [325] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__DiscoveredModule_t), NULL, 0, 0, NULL, 3, vader_type_325_refs },
    [326] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__EvaluatedProgram_t), NULL, 0, 0, NULL, 3, vader_type_326_refs },
    [327] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__FnDecl_t), NULL, 0, 0, NULL, 3, vader_type_327_refs },
    [328] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__FnDecl___t), NULL, 0, 0, NULL, 3, vader_type_328_refs },
    [329] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__FnParam___t), NULL, 0, 0, NULL, 3, vader_type_329_refs },
    [330] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__FnType___t), NULL, 0, 0, NULL, 3, vader_type_330_refs },
    [331] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__GenericFnInstance_t), NULL, 0, 0, NULL, 3, vader_type_331_refs },
    [332] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__GenericInstance_t), NULL, 0, 0, NULL, 3, vader_type_332_refs },
    [333] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__ImplEntry_t), NULL, 0, 0, NULL, 3, vader_type_333_refs },
    [334] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__ImplMethod_t), NULL, 0, 0, NULL, 3, vader_type_334_refs },
    [335] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__InlineInfo_t), NULL, 0, 0, NULL, 3, vader_type_335_refs },
    [336] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__JsonArray___JsonBool___JsonNull___JsonNumber___JsonObject___JsonString_t), NULL, 0, 0, NULL, 3, vader_type_336_refs },
    [337] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__LoadedModule_t), NULL, 0, 0, NULL, 3, vader_type_337_refs },
    [338] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__LoweredConstDecl___LoweredFnDecl___LoweredStructDecl_t), NULL, 0, 0, NULL, 3, vader_type_338_refs },
    [339] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__LoweredFnDecl_t), NULL, 0, 0, NULL, 3, vader_type_339_refs },
    [340] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__LoweredModule_t), NULL, 0, 0, NULL, 3, vader_type_340_refs },
    [341] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any__t), NULL, 0, 0, NULL, 3, vader_type_341_refs },
    [342] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_Any__Any____t), NULL, 0, 0, NULL, 3, vader_type_342_refs },
    [343] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t), NULL, 0, 0, NULL, 3, vader_type_343_refs },
    [344] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnParam____t), NULL, 0, 0, NULL, 3, vader_type_344_refs },
    [345] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_string__FnType____t), NULL, 0, 0, NULL, 3, vader_type_345_refs },
    [346] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t), NULL, 0, 0, NULL, 3, vader_type_346_refs },
    [347] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_____t), NULL, 0, 0, NULL, 3, vader_type_347_refs },
    [348] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t), NULL, 0, 0, NULL, 3, vader_type_348_refs },
    [349] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__MutableMap_u64__Symbol__t), NULL, 0, 0, NULL, 3, vader_type_349_refs },
    [350] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__MutableSet_i32__t), NULL, 0, 0, NULL, 3, vader_type_350_refs },
    [351] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__NarrowSlot_t), NULL, 0, 0, NULL, 3, vader_type_351_refs },
    [352] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__Span_t), NULL, 0, 0, NULL, 3, vader_type_352_refs },
    [353] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__Symbol_t), NULL, 0, 0, NULL, 3, vader_type_353_refs },
    [354] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__Symbol___t), NULL, 0, 0, NULL, 3, vader_type_354_refs },
    [355] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__TypedProgram_t), NULL, 0, 0, NULL, 3, vader_type_355_refs },
    [356] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType____t), NULL, 0, 0, NULL, 3, vader_type_356_refs },
    [357] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__bool_t), NULL, 0, 0, NULL, 3, vader_type_357_refs },
    [358] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__i32_t), NULL, 0, 0, NULL, 3, vader_type_358_refs },
    [359] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__i32___t), NULL, 0, 0, NULL, 3, vader_type_359_refs },
    [360] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__i64_t), NULL, 0, 0, NULL, 3, vader_type_360_refs },
    [361] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__string_t), NULL, 0, 0, NULL, 3, vader_type_361_refs },
    [362] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__string___t), NULL, 0, 0, NULL, 3, vader_type_362_refs },
    [363] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__string__usize_t), NULL, 0, 0, NULL, 3, vader_type_363_refs },
    [364] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__u64__Any_t), NULL, 0, 0, NULL, 3, vader_type_364_refs },
    [365] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t), NULL, 0, 0, NULL, 3, vader_type_365_refs },
    [366] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__u64__Symbol_t), NULL, 0, 0, NULL, 3, vader_type_366_refs },
    [367] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__u64__usize_t), NULL, 0, 0, NULL, 3, vader_type_367_refs },
    [368] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__usize__Any_t), NULL, 0, 0, NULL, 3, vader_type_368_refs },
    [369] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t), NULL, 0, 0, NULL, 3, vader_type_369_refs },
    [370] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__usize__NodeRecord_t), NULL, 0, 0, NULL, 3, vader_type_370_refs },
    [371] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__usize__Span_t), NULL, 0, 0, NULL, 3, vader_type_371_refs },
    [372] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__usize__bool_t), NULL, 0, 0, NULL, 3, vader_type_372_refs },
    [373] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__usize__i32_t), NULL, 0, 0, NULL, 3, vader_type_373_refs },
    [374] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableMap__usize__string_t), NULL, 0, 0, NULL, 3, vader_type_374_refs },
    [375] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableSet__i32_t), NULL, 0, 0, NULL, 1, vader_type_375_refs },
    [376] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableSet__i64_t), NULL, 0, 0, NULL, 1, vader_type_376_refs },
    [377] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_collections_MutableSet__string_t), NULL, 0, 0, NULL, 1, vader_type_377_refs },
    [378] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_core_Buffer_t), NULL, 0, 0, NULL, 0, NULL },
    [379] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_core_Dec64_t), NULL, 0, 0, NULL, 0, NULL },
    [380] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_core_DecimalParts_t), NULL, 0, 0, NULL, 0, NULL },
    [381] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_core_SlowParts_t), NULL, 0, 0, NULL, 1, vader_type_381_refs },
    [382] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_core_Yield__char_t), NULL, 0, 0, NULL, 0, NULL },
    [383] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_io_IOError_t), NULL, 0, 1, vader_type_383_strs, 0, NULL },
    [384] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_string_ParseError_t), NULL, 0, 1, vader_type_384_strs, 0, NULL },
    [385] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_string_StringChars_t), NULL, 0, 0, NULL, 1, vader_type_385_refs },
    [386] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_std_string_builder_StringBuilder_t), NULL, 0, 0, NULL, 1, vader_type_386_refs },
    [387] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t), vader_type_387_ptrs, 1, 0, NULL, 1, vader_type_387_refs },
    [388] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_AssertDecl_t), vader_type_388_ptrs, 2, 0, NULL, 2, vader_type_388_refs },
    [389] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_AssignStmt_t), vader_type_389_ptrs, 2, 0, NULL, 1, vader_type_389_refs },
    [390] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_AwaitExpr_t), vader_type_390_ptrs, 1, 0, NULL, 1, vader_type_390_refs },
    [391] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_BinaryExpr_t), vader_type_391_ptrs, 2, 1, vader_type_391_strs, 1, vader_type_391_refs },
    [392] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_BindingPattern_t), NULL, 0, 1, vader_type_392_strs, 1, vader_type_392_refs },
    [393] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_BlockExpr_t), vader_type_393_ptrs, 1, 0, NULL, 2, vader_type_393_refs },
    [394] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_BoolLitExpr_t), NULL, 0, 0, NULL, 1, vader_type_394_refs },
    [395] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_BreakStmt_t), vader_type_395_ptrs, 1, 0, NULL, 1, vader_type_395_refs },
    [396] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_CallArg_t), vader_type_396_ptrs, 2, 0, NULL, 1, vader_type_396_refs },
    [397] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_CallExpr_t), vader_type_397_ptrs, 1, 0, NULL, 2, vader_type_397_refs },
    [398] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_CastExpr_t), vader_type_398_ptrs, 2, 0, NULL, 1, vader_type_398_refs },
    [399] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_CharLitExpr_t), NULL, 0, 0, NULL, 1, vader_type_399_refs },
    [400] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_ConstDecl_t), vader_type_400_ptrs, 3, 1, vader_type_400_strs, 3, vader_type_400_refs },
    [401] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_ContinueStmt_t), vader_type_401_ptrs, 1, 0, NULL, 1, vader_type_401_refs },
    [402] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_Decorator_t), NULL, 0, 1, vader_type_402_strs, 2, vader_type_402_refs },
    [403] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_DeferBlockBody_t), NULL, 0, 0, NULL, 1, vader_type_403_refs },
    [404] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_DeferStmt_t), vader_type_404_ptrs, 1, 0, NULL, 1, vader_type_404_refs },
    [405] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_DeferStmtBody_t), vader_type_405_ptrs, 1, 0, NULL, 0, NULL },
    [406] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_DestructureImport_t), NULL, 0, 0, NULL, 1, vader_type_406_refs },
    [407] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_DestructureVar_t), vader_type_407_ptrs, 1, 0, NULL, 0, NULL },
    [408] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_DiscardVar_t), NULL, 0, 0, NULL, 0, NULL },
    [409] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_DotVariantExpr_t), NULL, 0, 1, vader_type_409_strs, 2, vader_type_409_refs },
    [410] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_EnumDecl_t), vader_type_410_ptrs, 1, 1, vader_type_410_strs, 4, vader_type_410_refs },
    [411] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_EnumVariant_t), vader_type_411_ptrs, 2, 1, vader_type_411_strs, 1, vader_type_411_refs },
    [412] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_EnumVariantPattern_t), NULL, 0, 1, vader_type_412_strs, 1, vader_type_412_refs },
    [413] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_ExprStmt_t), vader_type_413_ptrs, 1, 0, NULL, 1, vader_type_413_refs },
    [414] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_FieldExpr_t), vader_type_414_ptrs, 1, 1, vader_type_414_strs, 2, vader_type_414_refs },
    [415] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_FloatLitExpr_t), NULL, 0, 0, NULL, 1, vader_type_415_refs },
    [416] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_FnDecl_t), vader_type_416_ptrs, 2, 1, vader_type_416_strs, 5, vader_type_416_refs },
    [417] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_FnParam_t), vader_type_417_ptrs, 2, 1, vader_type_417_strs, 2, vader_type_417_refs },
    [418] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_FnTypeExpr_t), vader_type_418_ptrs, 1, 0, NULL, 3, vader_type_418_refs },
    [419] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_ForStmt_t), vader_type_419_ptrs, 2, 0, NULL, 2, vader_type_419_refs },
    [420] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_GenericInstExpr_t), vader_type_420_ptrs, 1, 0, NULL, 2, vader_type_420_refs },
    [421] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_IdentExpr_t), NULL, 0, 1, vader_type_421_strs, 1, vader_type_421_refs },
    [422] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_IfElseBlock_t), NULL, 0, 0, NULL, 1, vader_type_422_refs },
    [423] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_IfElseIf_t), NULL, 0, 0, NULL, 1, vader_type_423_refs },
    [424] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_IfExpr_t), vader_type_424_ptrs, 2, 0, NULL, 2, vader_type_424_refs },
    [425] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_ImplDecl_t), vader_type_425_ptrs, 1, 1, vader_type_425_strs, 6, vader_type_425_refs },
    [426] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_ImportDecl_t), vader_type_426_ptrs, 1, 1, vader_type_426_strs, 2, vader_type_426_refs },
    [427] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_ImportName_t), vader_type_427_ptrs, 1, 1, vader_type_427_strs, 1, vader_type_427_refs },
    [428] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_InFor_t), vader_type_428_ptrs, 2, 0, NULL, 0, NULL },
    [429] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_IndexExpr_t), vader_type_429_ptrs, 2, 0, NULL, 1, vader_type_429_refs },
    [430] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_InfiniteFor_t), NULL, 0, 0, NULL, 0, NULL },
    [431] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_IntLitExpr_t), NULL, 0, 0, NULL, 1, vader_type_431_refs },
    [432] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_IntrinsicCallExpr_t), NULL, 0, 1, vader_type_432_strs, 3, vader_type_432_refs },
    [433] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_IsPattern_t), vader_type_433_ptrs, 3, 0, NULL, 1, vader_type_433_refs },
    [434] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_LambdaExpr_t), vader_type_434_ptrs, 1, 0, NULL, 3, vader_type_434_refs },
    [435] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_LetStmt_t), vader_type_435_ptrs, 3, 0, NULL, 1, vader_type_435_refs },
    [436] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_LiteralPattern_t), vader_type_436_ptrs, 1, 0, NULL, 1, vader_type_436_refs },
    [437] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_MatchArm_t), vader_type_437_ptrs, 3, 0, NULL, 1, vader_type_437_refs },
    [438] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_MatchExpr_t), vader_type_438_ptrs, 1, 0, NULL, 2, vader_type_438_refs },
    [439] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_ModuleDecl_t), NULL, 0, 1, vader_type_439_strs, 2, vader_type_439_refs },
    [440] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_MutableTypeExpr_t), vader_type_440_ptrs, 1, 0, NULL, 1, vader_type_440_refs },
    [441] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_NamedNamespaceImport_t), NULL, 0, 1, vader_type_441_strs, 0, NULL },
    [442] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_NamedVar_t), NULL, 0, 1, vader_type_442_strs, 1, vader_type_442_refs },
    [443] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_NullCoalesceExpr_t), vader_type_443_ptrs, 2, 0, NULL, 1, vader_type_443_refs },
    [444] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_NullLitExpr_t), NULL, 0, 0, NULL, 1, vader_type_444_refs },
    [445] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_OrPattern_t), NULL, 0, 0, NULL, 2, vader_type_445_refs },
    [446] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_PatternBinding_t), NULL, 0, 1, vader_type_446_strs, 1, vader_type_446_refs },
    [447] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_PatternLiteral_t), vader_type_447_ptrs, 1, 0, NULL, 0, NULL },
    [448] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_Program_t), vader_type_448_ptrs, 1, 1, vader_type_448_strs, 2, vader_type_448_refs },
    [449] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_RangeExpr_t), vader_type_449_ptrs, 2, 0, NULL, 1, vader_type_449_refs },
    [450] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_RangePattern_t), vader_type_450_ptrs, 2, 0, NULL, 1, vader_type_450_refs },
    [451] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_RestBinding_t), NULL, 0, 1, vader_type_451_strs, 2, vader_type_451_refs },
    [452] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_ReturnStmt_t), vader_type_452_ptrs, 1, 0, NULL, 1, vader_type_452_refs },
    [453] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_SeqLitExpr_t), NULL, 0, 0, NULL, 2, vader_type_453_refs },
    [454] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_SimpleBinding_t), NULL, 0, 1, vader_type_454_strs, 2, vader_type_454_refs },
    [455] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_StringLitExpr_t), NULL, 0, 0, NULL, 2, vader_type_455_refs },
    [456] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_StringLitInterp_t), vader_type_456_ptrs, 1, 0, NULL, 1, vader_type_456_refs },
    [457] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_StringLitText_t), NULL, 0, 1, vader_type_457_strs, 1, vader_type_457_refs },
    [458] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_StructDecl_t), NULL, 0, 1, vader_type_458_strs, 5, vader_type_458_refs },
    [459] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_StructField_t), vader_type_459_ptrs, 2, 1, vader_type_459_strs, 1, vader_type_459_refs },
    [460] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_StructLitExpr_t), vader_type_460_ptrs, 1, 0, NULL, 2, vader_type_460_refs },
    [461] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_StructLitField_t), vader_type_461_ptrs, 1, 1, vader_type_461_strs, 2, vader_type_461_refs },
    [462] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_StructLitSpread_t), vader_type_462_ptrs, 1, 0, NULL, 1, vader_type_462_refs },
    [463] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_StructPattern_t), NULL, 0, 0, NULL, 2, vader_type_463_refs },
    [464] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_StructPatternField_t), vader_type_464_ptrs, 1, 1, vader_type_464_strs, 2, vader_type_464_refs },
    [465] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_TraitDecl_t), vader_type_465_ptrs, 1, 1, vader_type_465_strs, 5, vader_type_465_refs },
    [466] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_TupleBinding_t), NULL, 0, 0, NULL, 2, vader_type_466_refs },
    [467] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_TuplePattern_t), NULL, 0, 0, NULL, 2, vader_type_467_refs },
    [468] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_TypeAliasDecl_t), vader_type_468_ptrs, 1, 1, vader_type_468_strs, 4, vader_type_468_refs },
    [469] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_TypeParam_t), vader_type_469_ptrs, 2, 1, vader_type_469_strs, 1, vader_type_469_refs },
    [470] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_UnaryExpr_t), vader_type_470_ptrs, 1, 0, NULL, 1, vader_type_470_refs },
    [471] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_WhileFor_t), vader_type_471_ptrs, 1, 0, NULL, 0, NULL },
    [472] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_WildcardBinding_t), NULL, 0, 0, NULL, 1, vader_type_472_refs },
    [473] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_WildcardImport_t), NULL, 0, 0, NULL, 0, NULL },
    [474] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_WildcardPattern_t), NULL, 0, 0, NULL, 1, vader_type_474_refs },
    [475] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_ast_YieldStmt_t), vader_type_475_ptrs, 1, 0, NULL, 1, vader_type_475_refs },
    [476] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_span_Position_t), NULL, 0, 1, vader_type_476_strs, 0, NULL },
    [477] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_toolchain_span_Span_t), NULL, 0, 0, NULL, 2, vader_type_477_refs },
    [478] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bootstrap_CfgBytecode_t), NULL, 0, 1, vader_type_478_strs, 3, vader_type_478_refs },
    [479] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bootstrap_EvaluatedPipeline_t), NULL, 0, 0, NULL, 6, vader_type_479_refs },
    [480] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bootstrap_LoweredEntry_t), NULL, 0, 1, vader_type_480_strs, 3, vader_type_480_refs },
    [481] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_ArrayClear_t), NULL, 0, 0, NULL, 0, NULL },
    [482] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_ArrayCopy_t), NULL, 0, 0, NULL, 0, NULL },
    [483] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_ArrayGet_t), NULL, 0, 0, NULL, 0, NULL },
    [484] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_ArrayLen_t), NULL, 0, 0, NULL, 0, NULL },
    [485] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_ArrayNew_t), NULL, 0, 0, NULL, 0, NULL },
    [486] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_ArrayPush_t), NULL, 0, 0, NULL, 0, NULL },
    [487] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_ArrayPushAll_t), NULL, 0, 0, NULL, 0, NULL },
    [488] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_ArrayRemoveLast_t), NULL, 0, 0, NULL, 0, NULL },
    [489] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_ArrayRepeat_t), NULL, 0, 0, NULL, 0, NULL },
    [490] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_ArraySet_t), NULL, 0, 0, NULL, 0, NULL },
    [491] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_ArraySlice_t), NULL, 0, 0, NULL, 0, NULL },
    [492] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcAggregateData_t), NULL, 0, 1, vader_type_492_strs, 1, vader_type_492_refs },
    [493] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcArray_t), NULL, 0, 0, NULL, 0, NULL },
    [494] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcExport_t), NULL, 0, 1, vader_type_494_strs, 0, NULL },
    [495] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcField_t), NULL, 0, 1, vader_type_495_strs, 0, NULL },
    [496] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcFn_t), NULL, 0, 0, NULL, 1, vader_type_496_refs },
    [497] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcFunction_t), NULL, 0, 1, vader_type_497_strs, 5, vader_type_497_refs },
    [498] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcImport_t), NULL, 0, 4, vader_type_498_strs, 1, vader_type_498_refs },
    [499] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcLocal_t), NULL, 0, 1, vader_type_499_strs, 0, NULL },
    [500] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t), NULL, 0, 0, NULL, 3, vader_type_500_refs },
    [501] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcPrimData_t), NULL, 0, 0, NULL, 1, vader_type_501_refs },
    [502] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcPrimitive_t), NULL, 0, 0, NULL, 0, NULL },
    [503] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcRef_t), NULL, 0, 1, vader_type_503_strs, 0, NULL },
    [504] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcSignature_t), NULL, 0, 0, NULL, 5, vader_type_504_refs },
    [505] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcStrData_t), NULL, 0, 0, NULL, 1, vader_type_505_refs },
    [506] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcStruct_t), NULL, 0, 1, vader_type_506_strs, 1, vader_type_506_refs },
    [507] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcUnion_t), NULL, 0, 0, NULL, 1, vader_type_507_refs },
    [508] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcValArray_t), NULL, 0, 1, vader_type_508_strs, 1, vader_type_508_refs },
    [509] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcValPrim_t), NULL, 0, 0, NULL, 0, NULL },
    [510] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcValStr_t), NULL, 0, 1, vader_type_510_strs, 0, NULL },
    [511] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BcValStruct_t), NULL, 0, 0, NULL, 1, vader_type_511_refs },
    [512] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BitsToF32_t), NULL, 0, 0, NULL, 0, NULL },
    [513] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BitsToF64_t), NULL, 0, 0, NULL, 0, NULL },
    [514] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_Block_t), NULL, 0, 0, NULL, 0, NULL },
    [515] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BoolAnd_t), NULL, 0, 0, NULL, 0, NULL },
    [516] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BoolConst_t), NULL, 0, 0, NULL, 0, NULL },
    [517] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BoolEq_t), NULL, 0, 0, NULL, 0, NULL },
    [518] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BoolNe_t), NULL, 0, 0, NULL, 0, NULL },
    [519] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BoolNot_t), NULL, 0, 0, NULL, 0, NULL },
    [520] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BoolOr_t), NULL, 0, 0, NULL, 0, NULL },
    [521] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_Box_t), NULL, 0, 0, NULL, 0, NULL },
    [522] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_Branch_t), NULL, 0, 0, NULL, 0, NULL },
    [523] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BranchIf_t), NULL, 0, 0, NULL, 0, NULL },
    [524] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BufferNew_t), NULL, 0, 0, NULL, 0, NULL },
    [525] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BufferToString_t), NULL, 0, 0, NULL, 0, NULL },
    [526] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BufferWriteString_t), NULL, 0, 0, NULL, 0, NULL },
    [527] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_BytecodeModule_t), NULL, 0, 1, vader_type_527_strs, 8, vader_type_527_refs },
    [528] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_Call_t), NULL, 0, 0, NULL, 0, NULL },
    [529] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_CallImport_t), NULL, 0, 0, NULL, 0, NULL },
    [530] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_CallIndirect_t), NULL, 0, 0, NULL, 0, NULL },
    [531] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_CharConst_t), NULL, 0, 0, NULL, 0, NULL },
    [532] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_Convert_t), NULL, 0, 1, vader_type_532_strs, 0, NULL },
    [533] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_DataConst_t), NULL, 0, 0, NULL, 0, NULL },
    [534] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_DebugPos_t), NULL, 0, 1, vader_type_534_strs, 0, NULL },
    [535] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_DeferPopExec_t), NULL, 0, 0, NULL, 0, NULL },
    [536] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_DeferPush_t), NULL, 0, 0, NULL, 0, NULL },
    [537] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_Drop_t), NULL, 0, 0, NULL, 0, NULL },
    [538] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_Else_t), NULL, 0, 0, NULL, 0, NULL },
    [539] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_EmitOptions_t), NULL, 0, 0, NULL, 1, vader_type_539_refs },
    [540] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_EmitterCtx_t), NULL, 0, 0, NULL, 13, vader_type_540_refs },
    [541] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_End_t), NULL, 0, 0, NULL, 0, NULL },
    [542] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F32ToBits_t), NULL, 0, 0, NULL, 0, NULL },
    [543] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F64Add_t), NULL, 0, 0, NULL, 0, NULL },
    [544] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F64Const_t), NULL, 0, 0, NULL, 0, NULL },
    [545] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F64Div_t), NULL, 0, 0, NULL, 0, NULL },
    [546] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F64Eq_t), NULL, 0, 0, NULL, 0, NULL },
    [547] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F64Ge_t), NULL, 0, 0, NULL, 0, NULL },
    [548] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F64Gt_t), NULL, 0, 0, NULL, 0, NULL },
    [549] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F64Le_t), NULL, 0, 0, NULL, 0, NULL },
    [550] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F64Lt_t), NULL, 0, 0, NULL, 0, NULL },
    [551] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F64Mul_t), NULL, 0, 0, NULL, 0, NULL },
    [552] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F64Ne_t), NULL, 0, 0, NULL, 0, NULL },
    [553] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F64Neg_t), NULL, 0, 0, NULL, 0, NULL },
    [554] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F64Sub_t), NULL, 0, 0, NULL, 0, NULL },
    [555] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_F64ToBits_t), NULL, 0, 0, NULL, 0, NULL },
    [556] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_FnRef_t), NULL, 0, 0, NULL, 0, NULL },
    [557] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Add_t), NULL, 0, 0, NULL, 0, NULL },
    [558] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32BitAnd_t), NULL, 0, 0, NULL, 0, NULL },
    [559] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32BitNot_t), NULL, 0, 0, NULL, 0, NULL },
    [560] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32BitOr_t), NULL, 0, 0, NULL, 0, NULL },
    [561] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32BitXor_t), NULL, 0, 0, NULL, 0, NULL },
    [562] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Const_t), NULL, 0, 0, NULL, 0, NULL },
    [563] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Div_t), NULL, 0, 0, NULL, 0, NULL },
    [564] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Eq_t), NULL, 0, 0, NULL, 0, NULL },
    [565] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Ge_t), NULL, 0, 0, NULL, 0, NULL },
    [566] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Gt_t), NULL, 0, 0, NULL, 0, NULL },
    [567] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Le_t), NULL, 0, 0, NULL, 0, NULL },
    [568] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Lt_t), NULL, 0, 0, NULL, 0, NULL },
    [569] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Mod_t), NULL, 0, 0, NULL, 0, NULL },
    [570] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Mul_t), NULL, 0, 0, NULL, 0, NULL },
    [571] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Ne_t), NULL, 0, 0, NULL, 0, NULL },
    [572] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Neg_t), NULL, 0, 0, NULL, 0, NULL },
    [573] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Shl_t), NULL, 0, 0, NULL, 0, NULL },
    [574] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Shr_t), NULL, 0, 0, NULL, 0, NULL },
    [575] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32ShrU_t), NULL, 0, 0, NULL, 0, NULL },
    [576] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I32Sub_t), NULL, 0, 0, NULL, 0, NULL },
    [577] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Add_t), NULL, 0, 0, NULL, 0, NULL },
    [578] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64BitAnd_t), NULL, 0, 0, NULL, 0, NULL },
    [579] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64BitNot_t), NULL, 0, 0, NULL, 0, NULL },
    [580] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64BitOr_t), NULL, 0, 0, NULL, 0, NULL },
    [581] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64BitXor_t), NULL, 0, 0, NULL, 0, NULL },
    [582] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Const_t), NULL, 0, 0, NULL, 0, NULL },
    [583] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Div_t), NULL, 0, 0, NULL, 0, NULL },
    [584] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Eq_t), NULL, 0, 0, NULL, 0, NULL },
    [585] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Ge_t), NULL, 0, 0, NULL, 0, NULL },
    [586] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Gt_t), NULL, 0, 0, NULL, 0, NULL },
    [587] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Le_t), NULL, 0, 0, NULL, 0, NULL },
    [588] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Lt_t), NULL, 0, 0, NULL, 0, NULL },
    [589] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Mod_t), NULL, 0, 0, NULL, 0, NULL },
    [590] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Mul_t), NULL, 0, 0, NULL, 0, NULL },
    [591] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Ne_t), NULL, 0, 0, NULL, 0, NULL },
    [592] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Neg_t), NULL, 0, 0, NULL, 0, NULL },
    [593] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Shl_t), NULL, 0, 0, NULL, 0, NULL },
    [594] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Shr_t), NULL, 0, 0, NULL, 0, NULL },
    [595] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64ShrU_t), NULL, 0, 0, NULL, 0, NULL },
    [596] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_I64Sub_t), NULL, 0, 0, NULL, 0, NULL },
    [597] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_If_t), NULL, 0, 0, NULL, 0, NULL },
    [598] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_ImplEntry_t), NULL, 0, 1, vader_type_598_strs, 0, NULL },
    [599] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_LoadF64_t), NULL, 0, 0, NULL, 0, NULL },
    [600] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_LoadI32_t), NULL, 0, 0, NULL, 0, NULL },
    [601] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_LoadI64_t), NULL, 0, 0, NULL, 0, NULL },
    [602] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_LoadSlotF64_t), NULL, 0, 0, NULL, 0, NULL },
    [603] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_LoadSlotI32_t), NULL, 0, 0, NULL, 0, NULL },
    [604] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_LoadSlotI64_t), NULL, 0, 0, NULL, 0, NULL },
    [605] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_LoadU8_t), NULL, 0, 0, NULL, 0, NULL },
    [606] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_LocalField_t), NULL, 0, 0, NULL, 0, NULL },
    [607] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_LocalGet_t), NULL, 0, 0, NULL, 0, NULL },
    [608] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_LocalSet_t), NULL, 0, 0, NULL, 0, NULL },
    [609] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_LocalTee_t), NULL, 0, 0, NULL, 0, NULL },
    [610] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_Loop_t), NULL, 0, 0, NULL, 0, NULL },
    [611] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_MakeClosure_t), NULL, 0, 0, NULL, 0, NULL },
    [612] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_MemoryCopy_t), NULL, 0, 0, NULL, 0, NULL },
    [613] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_NullConst_t), NULL, 0, 0, NULL, 0, NULL },
    [614] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_RefCast_t), NULL, 0, 0, NULL, 0, NULL },
    [615] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_RefEq_t), NULL, 0, 0, NULL, 0, NULL },
    [616] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_RefNe_t), NULL, 0, 0, NULL, 0, NULL },
    [617] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_Return_t), NULL, 0, 0, NULL, 0, NULL },
    [618] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_ReturnLit_t), vader_type_618_ptrs, 1, 0, NULL, 0, NULL },
    [619] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_SizeOfType_t), NULL, 0, 0, NULL, 0, NULL },
    [620] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_SlotRange_t), NULL, 0, 0, NULL, 0, NULL },
    [621] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StoreF64_t), NULL, 0, 0, NULL, 0, NULL },
    [622] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StoreI32_t), NULL, 0, 0, NULL, 0, NULL },
    [623] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StoreI64_t), NULL, 0, 0, NULL, 0, NULL },
    [624] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StoreSlotF64_t), NULL, 0, 0, NULL, 0, NULL },
    [625] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StoreSlotI32_t), NULL, 0, 0, NULL, 0, NULL },
    [626] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StoreSlotI64_t), NULL, 0, 0, NULL, 0, NULL },
    [627] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StoreU8_t), NULL, 0, 0, NULL, 0, NULL },
    [628] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StringConst_t), NULL, 0, 0, NULL, 0, NULL },
    [629] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StringEq_t), NULL, 0, 0, NULL, 0, NULL },
    [630] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StringNe_t), NULL, 0, 0, NULL, 0, NULL },
    [631] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StringSliceCodepoints_t), NULL, 0, 0, NULL, 0, NULL },
    [632] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StructGet_t), NULL, 0, 0, NULL, 0, NULL },
    [633] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StructNew_t), NULL, 0, 0, NULL, 0, NULL },
    [634] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_StructSet_t), NULL, 0, 0, NULL, 0, NULL },
    [635] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_TypeCheck_t), NULL, 0, 0, NULL, 0, NULL },
    [636] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_TypeConst_t), NULL, 0, 0, NULL, 0, NULL },
    [637] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_U32Div_t), NULL, 0, 0, NULL, 0, NULL },
    [638] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_U32Ge_t), NULL, 0, 0, NULL, 0, NULL },
    [639] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_U32Gt_t), NULL, 0, 0, NULL, 0, NULL },
    [640] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_U32Le_t), NULL, 0, 0, NULL, 0, NULL },
    [641] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_U32Lt_t), NULL, 0, 0, NULL, 0, NULL },
    [642] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_U32Mod_t), NULL, 0, 0, NULL, 0, NULL },
    [643] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_U64Div_t), NULL, 0, 0, NULL, 0, NULL },
    [644] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_U64Ge_t), NULL, 0, 0, NULL, 0, NULL },
    [645] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_U64Gt_t), NULL, 0, 0, NULL, 0, NULL },
    [646] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_U64Le_t), NULL, 0, 0, NULL, 0, NULL },
    [647] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_U64Lt_t), NULL, 0, 0, NULL, 0, NULL },
    [648] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_U64Mod_t), NULL, 0, 0, NULL, 0, NULL },
    [649] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_Unreachable_t), NULL, 0, 1, vader_type_649_strs, 0, NULL },
    [650] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_VirtualCall_t), NULL, 0, 1, vader_type_650_strs, 0, NULL },
    [651] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_VtableEntry_t), NULL, 0, 0, NULL, 0, NULL },
    [652] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_bytecode_VtableRow_t), NULL, 0, 1, vader_type_652_strs, 1, vader_type_652_refs },
    [653] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_BranchTargets_t), NULL, 0, 0, NULL, 2, vader_type_653_refs },
    [654] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_CProgram_t), NULL, 0, 3, vader_type_654_strs, 2, vader_type_654_refs },
    [655] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_CoalesceResult_t), NULL, 0, 1, vader_type_655_strs, 1, vader_type_655_refs },
    [656] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_CopyLine_t), NULL, 0, 1, vader_type_656_strs, 0, NULL },
    [657] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_DefLine_t), NULL, 0, 2, vader_type_657_strs, 0, NULL },
    [658] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_EmitCtx_t), NULL, 0, 0, NULL, 6, vader_type_658_refs },
    [659] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_EmitOptions_t), NULL, 0, 1, vader_type_659_strs, 1, vader_type_659_refs },
    [660] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_FnState_t), NULL, 0, 0, NULL, 11, vader_type_660_refs },
    [661] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_FnValueUsage_t), NULL, 0, 0, NULL, 2, vader_type_661_refs },
    [662] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_ScopeInfo_t), NULL, 0, 0, NULL, 0, NULL },
    [663] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_SlotFill_t), NULL, 0, 1, vader_type_663_strs, 0, NULL },
    [664] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_SlotToken_t), NULL, 0, 0, NULL, 0, NULL },
    [665] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_StackExpr_t), NULL, 0, 1, vader_type_665_strs, 0, NULL },
    [666] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_StackLit_t), NULL, 0, 1, vader_type_666_strs, 0, NULL },
    [667] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_StackLocalRef_t), NULL, 0, 0, NULL, 0, NULL },
    [668] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_StackStorage_t), NULL, 0, 2, vader_type_668_strs, 0, NULL },
    [669] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_StackTmp_t), NULL, 0, 1, vader_type_669_strs, 0, NULL },
    [670] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_c_emit_StructOffsets_t), NULL, 0, 0, NULL, 3, vader_type_670_refs },
    [671] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_ArrayValue_t), NULL, 0, 1, vader_type_671_strs, 1, vader_type_671_refs },
    [672] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_BoolValue_t), NULL, 0, 0, NULL, 0, NULL },
    [673] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_CharValue_t), NULL, 0, 0, NULL, 0, NULL },
    [674] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_ComptimeContext_t), NULL, 0, 0, NULL, 2, vader_type_674_refs },
    [675] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_ComptimeOrder_t), NULL, 0, 0, NULL, 2, vader_type_675_refs },
    [676] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_EvalResult_t), vader_type_676_ptrs, 2, 0, NULL, 0, NULL },
    [677] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_EvaluatedProgram_t), NULL, 0, 0, NULL, 2, vader_type_677_refs },
    [678] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_EvaluatedProject_t), NULL, 0, 0, NULL, 6, vader_type_678_refs },
    [679] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_FloatValue_t), NULL, 0, 1, vader_type_679_strs, 0, NULL },
    [680] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_GenericInstance_t), NULL, 0, 1, vader_type_680_strs, 2, vader_type_680_refs },
    [681] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_InstanceRegistry_t), NULL, 0, 0, NULL, 2, vader_type_681_refs },
    [682] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_IntValue_t), NULL, 0, 1, vader_type_682_strs, 0, NULL },
    [683] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_MonoEntry_t), vader_type_683_ptrs, 3, 1, vader_type_683_strs, 2, vader_type_683_refs },
    [684] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_NodeRecord_t), NULL, 0, 0, NULL, 2, vader_type_684_refs },
    [685] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_Nodes_t), NULL, 0, 0, NULL, 3, vader_type_685_refs },
    [686] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_NullValue_t), NULL, 0, 0, NULL, 0, NULL },
    [687] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_StringValue_t), NULL, 0, 1, vader_type_687_strs, 0, NULL },
    [688] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_StructValue_t), NULL, 0, 1, vader_type_688_strs, 1, vader_type_688_refs },
    [689] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_TypeValue_t), vader_type_689_ptrs, 1, 0, NULL, 0, NULL },
    [690] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_VmRequiredDecl_t), vader_type_690_ptrs, 1, 2, vader_type_690_strs, 1, vader_type_690_refs },
    [691] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_comptime_VoidValue_t), NULL, 0, 0, NULL, 0, NULL },
    [692] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_diagnostics_CodeInfo_t), NULL, 0, 2, vader_type_692_strs, 0, NULL },
    [693] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_diagnostics_Diagnostic_t), NULL, 0, 1, vader_type_693_strs, 2, vader_type_693_refs },
    [694] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lexer_InterpFrame_t), NULL, 0, 0, NULL, 0, NULL },
    [695] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lexer_Lexer_t), NULL, 0, 2, vader_type_695_strs, 4, vader_type_695_refs },
    [696] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lexer_Token_t), vader_type_696_ptrs, 1, 1, vader_type_696_strs, 1, vader_type_696_refs },
    [697] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_AggregateDataPoolEntry_t), NULL, 0, 1, vader_type_697_strs, 1, vader_type_697_refs },
    [698] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_AnalyzeCtx_t), NULL, 0, 0, NULL, 4, vader_type_698_refs },
    [699] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_BcePurityCtx_t), NULL, 0, 0, NULL, 3, vader_type_699_refs },
    [700] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_BlockCtx_t), NULL, 0, 0, NULL, 1, vader_type_700_refs },
    [701] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_BodyTemplate_t), vader_type_701_ptrs, 2, 1, vader_type_701_strs, 2, vader_type_701_refs },
    [702] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_BveCtx_t), vader_type_702_ptrs, 2, 0, NULL, 6, vader_type_702_refs },
    [703] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_Capture_t), vader_type_703_ptrs, 1, 0, NULL, 1, vader_type_703_refs },
    [704] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_CellInit_t), vader_type_704_ptrs, 2, 0, NULL, 0, NULL },
    [705] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_ClosureAlias_t), vader_type_705_ptrs, 1, 0, NULL, 1, vader_type_705_refs },
    [706] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_ClosureAnalysis_t), NULL, 0, 0, NULL, 3, vader_type_706_refs },
    [707] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_CollectCtx_t), NULL, 0, 1, vader_type_707_strs, 2, vader_type_707_refs },
    [708] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_ConstFnWrap_t), vader_type_708_ptrs, 1, 0, NULL, 1, vader_type_708_refs },
    [709] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_EntryTypes_t), NULL, 0, 0, NULL, 2, vader_type_709_refs },
    [710] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_FluentCombinator_t), vader_type_710_ptrs, 2, 0, NULL, 0, NULL },
    [711] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_FnLowerCtx_t), vader_type_711_ptrs, 3, 0, NULL, 8, vader_type_711_refs },
    [712] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_GenBuild_t), vader_type_712_ptrs, 7, 0, NULL, 7, vader_type_712_refs },
    [713] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_GenComboLayer_t), vader_type_713_ptrs, 3, 0, NULL, 7, vader_type_713_refs },
    [714] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_GenInlineSink_t), vader_type_714_ptrs, 1, 1, vader_type_714_strs, 2, vader_type_714_refs },
    [715] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_GenSourceBinding_t), NULL, 0, 0, NULL, 4, vader_type_715_refs },
    [716] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_GenSourceLoop_t), NULL, 0, 0, NULL, 3, vader_type_716_refs },
    [717] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_GenericFnInstance_t), NULL, 0, 2, vader_type_717_strs, 2, vader_type_717_refs },
    [718] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_ImplMemberMatch_t), NULL, 0, 0, NULL, 2, vader_type_718_refs },
    [719] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_ImplTraitMethod_t), NULL, 0, 2, vader_type_719_strs, 0, NULL },
    [720] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_InlineInfo_t), vader_type_720_ptrs, 1, 0, NULL, 2, vader_type_720_refs },
    [721] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_IterChain_t), vader_type_721_ptrs, 7, 0, NULL, 1, vader_type_721_refs },
    [722] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LiftedFnContext_t), vader_type_722_ptrs, 1, 0, NULL, 2, vader_type_722_refs },
    [723] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoopBinding_t), vader_type_723_ptrs, 1, 1, vader_type_723_strs, 1, vader_type_723_refs },
    [724] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoopFrame_t), vader_type_724_ptrs, 1, 0, NULL, 0, NULL },
    [725] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LowerProjectCtx_t), NULL, 0, 0, NULL, 30, vader_type_725_refs },
    [726] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredArrayLen_t), vader_type_726_ptrs, 2, 0, NULL, 1, vader_type_726_refs },
    [727] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredArrayLit_t), vader_type_727_ptrs, 1, 0, NULL, 2, vader_type_727_refs },
    [728] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredArrayPush_t), vader_type_728_ptrs, 3, 0, NULL, 1, vader_type_728_refs },
    [729] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredArraySlice_t), vader_type_729_ptrs, 4, 0, NULL, 1, vader_type_729_refs },
    [730] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredAssign_t), vader_type_730_ptrs, 2, 0, NULL, 1, vader_type_730_refs },
    [731] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredAwait_t), vader_type_731_ptrs, 2, 0, NULL, 2, vader_type_731_refs },
    [732] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredBinary_t), vader_type_732_ptrs, 3, 0, NULL, 1, vader_type_732_refs },
    [733] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredBlock_t), vader_type_733_ptrs, 2, 0, NULL, 2, vader_type_733_refs },
    [734] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredBoolLit_t), vader_type_734_ptrs, 1, 0, NULL, 1, vader_type_734_refs },
    [735] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredBreak_t), vader_type_735_ptrs, 1, 0, NULL, 1, vader_type_735_refs },
    [736] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredCall_t), vader_type_736_ptrs, 2, 0, NULL, 2, vader_type_736_refs },
    [737] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredCast_t), vader_type_737_ptrs, 2, 0, NULL, 1, vader_type_737_refs },
    [738] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredCellGet_t), vader_type_738_ptrs, 3, 0, NULL, 1, vader_type_738_refs },
    [739] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredCellNew_t), vader_type_739_ptrs, 3, 0, NULL, 1, vader_type_739_refs },
    [740] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredCellSet_t), vader_type_740_ptrs, 3, 0, NULL, 1, vader_type_740_refs },
    [741] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredCharLit_t), vader_type_741_ptrs, 1, 0, NULL, 1, vader_type_741_refs },
    [742] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredConstDecl_t), vader_type_742_ptrs, 2, 1, vader_type_742_strs, 1, vader_type_742_refs },
    [743] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredContinue_t), vader_type_743_ptrs, 1, 0, NULL, 1, vader_type_743_refs },
    [744] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredDataConst_t), vader_type_744_ptrs, 1, 0, NULL, 1, vader_type_744_refs },
    [745] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredDeferPopExec_t), NULL, 0, 0, NULL, 1, vader_type_745_refs },
    [746] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredDeferPush_t), vader_type_746_ptrs, 1, 0, NULL, 1, vader_type_746_refs },
    [747] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredExprStmt_t), vader_type_747_ptrs, 1, 0, NULL, 1, vader_type_747_refs },
    [748] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredFieldAccess_t), vader_type_748_ptrs, 2, 1, vader_type_748_strs, 1, vader_type_748_refs },
    [749] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredFloatLit_t), vader_type_749_ptrs, 1, 0, NULL, 1, vader_type_749_refs },
    [750] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredFnDecl_t), vader_type_750_ptrs, 2, 1, vader_type_750_strs, 2, vader_type_750_refs },
    [751] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredIdent_t), vader_type_751_ptrs, 1, 0, NULL, 2, vader_type_751_refs },
    [752] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredIf_t), vader_type_752_ptrs, 3, 0, NULL, 2, vader_type_752_refs },
    [753] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredIndex_t), vader_type_753_ptrs, 3, 0, NULL, 1, vader_type_753_refs },
    [754] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredIntLit_t), vader_type_754_ptrs, 1, 0, NULL, 1, vader_type_754_refs },
    [755] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredIntrinsicCall_t), vader_type_755_ptrs, 1, 1, vader_type_755_strs, 2, vader_type_755_refs },
    [756] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredLet_t), vader_type_756_ptrs, 2, 1, vader_type_756_strs, 2, vader_type_756_refs },
    [757] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredLoop_t), vader_type_757_ptrs, 2, 0, NULL, 2, vader_type_757_refs },
    [758] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredMakeClosure_t), vader_type_758_ptrs, 2, 0, NULL, 2, vader_type_758_refs },
    [759] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredModule_t), NULL, 0, 2, vader_type_759_strs, 1, vader_type_759_refs },
    [760] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredNullLit_t), vader_type_760_ptrs, 1, 0, NULL, 1, vader_type_760_refs },
    [761] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredParam_t), vader_type_761_ptrs, 1, 1, vader_type_761_strs, 1, vader_type_761_refs },
    [762] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredProject_t), NULL, 0, 1, vader_type_762_strs, 6, vader_type_762_refs },
    [763] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredReturn_t), vader_type_763_ptrs, 1, 0, NULL, 1, vader_type_763_refs },
    [764] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredStringLit_t), vader_type_764_ptrs, 1, 1, vader_type_764_strs, 1, vader_type_764_refs },
    [765] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredStringSlice_t), vader_type_765_ptrs, 4, 0, NULL, 1, vader_type_765_refs },
    [766] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredStructDecl_t), NULL, 0, 1, vader_type_766_strs, 2, vader_type_766_refs },
    [767] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredStructField_t), vader_type_767_ptrs, 1, 1, vader_type_767_strs, 0, NULL },
    [768] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredStructLit_t), vader_type_768_ptrs, 1, 0, NULL, 2, vader_type_768_refs },
    [769] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredStructLitField_t), vader_type_769_ptrs, 1, 1, vader_type_769_strs, 0, NULL },
    [770] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredTypeCheck_t), vader_type_770_ptrs, 3, 0, NULL, 1, vader_type_770_refs },
    [771] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredTypeConst_t), vader_type_771_ptrs, 2, 0, NULL, 1, vader_type_771_refs },
    [772] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredUnary_t), vader_type_772_ptrs, 2, 0, NULL, 1, vader_type_772_refs },
    [773] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredUnreachable_t), vader_type_773_ptrs, 1, 1, vader_type_773_strs, 1, vader_type_773_refs },
    [774] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredVirtualCall_t), vader_type_774_ptrs, 2, 2, vader_type_774_strs, 2, vader_type_774_refs },
    [775] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredVtableEntry_t), vader_type_775_ptrs, 1, 2, vader_type_775_strs, 1, vader_type_775_refs },
    [776] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_LoweredYield_t), vader_type_776_ptrs, 1, 0, NULL, 1, vader_type_776_refs },
    [777] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_OpTraitInfo_t), NULL, 0, 2, vader_type_777_strs, 0, NULL },
    [778] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_PendingFnInstance_t), NULL, 0, 2, vader_type_778_strs, 1, vader_type_778_refs },
    [779] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_PrimDataPoolEntry_t), NULL, 0, 1, vader_type_779_strs, 1, vader_type_779_refs },
    [780] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_StrDataPoolEntry_t), NULL, 0, 0, NULL, 1, vader_type_780_refs },
    [781] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_TerminalPredCall_t), vader_type_781_ptrs, 2, 0, NULL, 0, NULL },
    [782] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_TransformCtx_t), NULL, 0, 0, NULL, 2, vader_type_782_refs },
    [783] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_UfcsMember_t), NULL, 0, 0, NULL, 2, vader_type_783_refs },
    [784] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_WalkCtx_t), NULL, 0, 0, NULL, 4, vader_type_784_refs },
    [785] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_lower_WrapResult_t), vader_type_785_ptrs, 2, 0, NULL, 0, NULL },
    [786] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_AnnotatedProject_t), NULL, 0, 0, NULL, 2, vader_type_786_refs },
    [787] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_BasicBlock_t), vader_type_787_ptrs, 1, 0, NULL, 2, vader_type_787_refs },
    [788] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_CFGExternDecl_t), vader_type_788_ptrs, 1, 4, vader_type_788_strs, 2, vader_type_788_refs },
    [789] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_CFGFunction_t), vader_type_789_ptrs, 1, 2, vader_type_789_strs, 4, vader_type_789_refs },
    [790] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_CFGLocal_t), vader_type_790_ptrs, 2, 1, vader_type_790_strs, 0, NULL },
    [791] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_CFGModule_t), NULL, 0, 2, vader_type_791_strs, 3, vader_type_791_refs },
    [792] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_CFGParam_t), vader_type_792_ptrs, 1, 1, vader_type_792_strs, 1, vader_type_792_refs },
    [793] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_CFGProject_t), NULL, 0, 0, NULL, 5, vader_type_793_refs },
    [794] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_CFGStructDecl_t), NULL, 0, 1, vader_type_794_strs, 2, vader_type_794_refs },
    [795] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_CFGStructField_t), vader_type_795_ptrs, 1, 1, vader_type_795_strs, 0, NULL },
    [796] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_ConstBool_t), NULL, 0, 0, NULL, 0, NULL },
    [797] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_ConstChar_t), NULL, 0, 0, NULL, 0, NULL },
    [798] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_ConstFloat_t), NULL, 0, 0, NULL, 0, NULL },
    [799] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_ConstInt_t), NULL, 0, 0, NULL, 0, NULL },
    [800] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_ConstNull_t), NULL, 0, 0, NULL, 0, NULL },
    [801] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_ConstString_t), NULL, 0, 0, NULL, 0, NULL },
    [802] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_EscapeResult_t), NULL, 0, 0, NULL, 3, vader_type_802_refs },
    [803] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_EscapeStats_t), NULL, 0, 0, NULL, 0, NULL },
    [804] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_FnCtx_t), vader_type_804_ptrs, 2, 1, vader_type_804_strs, 7, vader_type_804_refs },
    [805] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_FnEmitCfg_t), NULL, 0, 0, NULL, 14, vader_type_805_refs },
    [806] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_FnMetadata_t), NULL, 0, 3, vader_type_806_strs, 0, NULL },
    [807] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrArrayGet_t), vader_type_807_ptrs, 1, 0, NULL, 1, vader_type_807_refs },
    [808] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrArrayLen_t), NULL, 0, 0, NULL, 1, vader_type_808_refs },
    [809] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrArrayNew_t), vader_type_809_ptrs, 1, 0, NULL, 2, vader_type_809_refs },
    [810] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrArrayPush_t), NULL, 0, 0, NULL, 1, vader_type_810_refs },
    [811] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrArraySet_t), NULL, 0, 0, NULL, 1, vader_type_811_refs },
    [812] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrArraySlice_t), vader_type_812_ptrs, 1, 0, NULL, 1, vader_type_812_refs },
    [813] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrBinOp_t), vader_type_813_ptrs, 1, 0, NULL, 1, vader_type_813_refs },
    [814] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrCall_t), vader_type_814_ptrs, 2, 0, NULL, 3, vader_type_814_refs },
    [815] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrCallIndirect_t), vader_type_815_ptrs, 3, 0, NULL, 2, vader_type_815_refs },
    [816] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrCast_t), vader_type_816_ptrs, 1, 0, NULL, 1, vader_type_816_refs },
    [817] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrCellGet_t), vader_type_817_ptrs, 1, 0, NULL, 1, vader_type_817_refs },
    [818] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrCellNew_t), vader_type_818_ptrs, 1, 0, NULL, 1, vader_type_818_refs },
    [819] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrCellSet_t), vader_type_819_ptrs, 1, 0, NULL, 1, vader_type_819_refs },
    [820] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrConst_t), vader_type_820_ptrs, 2, 0, NULL, 1, vader_type_820_refs },
    [821] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrDataConst_t), vader_type_821_ptrs, 1, 0, NULL, 1, vader_type_821_refs },
    [822] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrDeferPopExec_t), NULL, 0, 0, NULL, 1, vader_type_822_refs },
    [823] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrDeferPush_t), NULL, 0, 0, NULL, 1, vader_type_823_refs },
    [824] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrFieldGet_t), vader_type_824_ptrs, 1, 1, vader_type_824_strs, 1, vader_type_824_refs },
    [825] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrFieldSet_t), NULL, 0, 1, vader_type_825_strs, 1, vader_type_825_refs },
    [826] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrFnRef_t), vader_type_826_ptrs, 1, 0, NULL, 2, vader_type_826_refs },
    [827] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrIntrinsic_t), vader_type_827_ptrs, 1, 1, vader_type_827_strs, 2, vader_type_827_refs },
    [828] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrMakeClosure_t), vader_type_828_ptrs, 2, 0, NULL, 2, vader_type_828_refs },
    [829] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrMove_t), NULL, 0, 0, NULL, 1, vader_type_829_refs },
    [830] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrStringSlice_t), vader_type_830_ptrs, 1, 0, NULL, 1, vader_type_830_refs },
    [831] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrStructNew_t), vader_type_831_ptrs, 1, 0, NULL, 2, vader_type_831_refs },
    [832] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrTypeCheck_t), vader_type_832_ptrs, 1, 0, NULL, 1, vader_type_832_refs },
    [833] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrTypeConst_t), vader_type_833_ptrs, 2, 0, NULL, 1, vader_type_833_refs },
    [834] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrUnOp_t), vader_type_834_ptrs, 1, 0, NULL, 1, vader_type_834_refs },
    [835] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_InstrVirtualCall_t), vader_type_835_ptrs, 2, 2, vader_type_835_strs, 2, vader_type_835_refs },
    [836] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_Liveness_t), NULL, 0, 0, NULL, 2, vader_type_836_refs },
    [837] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_LoopFrame_t), vader_type_837_ptrs, 1, 0, NULL, 0, NULL },
    [838] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_MutableBlock_t), vader_type_838_ptrs, 1, 0, NULL, 2, vader_type_838_refs },
    [839] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_PendingBranch_t), NULL, 0, 0, NULL, 0, NULL },
    [840] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_ProjectCtx_t), NULL, 0, 0, NULL, 4, vader_type_840_refs },
    [841] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_ScheduleHints_t), NULL, 0, 0, NULL, 3, vader_type_841_refs },
    [842] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_ScopeFrame_t), NULL, 0, 1, vader_type_842_strs, 0, NULL },
    [843] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_TermBranch_t), NULL, 0, 0, NULL, 1, vader_type_843_refs },
    [844] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_TermCondBranch_t), NULL, 0, 0, NULL, 1, vader_type_844_refs },
    [845] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_TermReturn_t), vader_type_845_ptrs, 1, 0, NULL, 1, vader_type_845_refs },
    [846] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_midir_TermUnreachable_t), NULL, 0, 1, vader_type_846_strs, 1, vader_type_846_refs },
    [847] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_CommaList__Any_t), NULL, 0, 0, NULL, 1, vader_type_847_refs },
    [848] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_CommaList__CallArg_t), NULL, 0, 0, NULL, 1, vader_type_848_refs },
    [849] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_CommaList__ImportName_t), NULL, 0, 0, NULL, 1, vader_type_849_refs },
    [850] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t), NULL, 0, 0, NULL, 1, vader_type_850_refs },
    [851] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_CompoundOpResult_t), NULL, 0, 0, NULL, 0, NULL },
    [852] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_FnBodyTail_t), vader_type_852_ptrs, 1, 0, NULL, 0, NULL },
    [853] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_FnSignature_t), NULL, 0, 0, NULL, 2, vader_type_853_refs },
    [854] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_InfixOpDescr_t), NULL, 0, 0, NULL, 0, NULL },
    [855] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_IntrinsicSpec_t), NULL, 0, 2, vader_type_855_strs, 1, vader_type_855_refs },
    [856] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_ModuleHeader_t), NULL, 0, 1, vader_type_856_strs, 1, vader_type_856_refs },
    [857] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_NodeIdFactory_t), NULL, 0, 0, NULL, 0, NULL },
    [858] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_ParsedSource_t), NULL, 0, 0, NULL, 4, vader_type_858_refs },
    [859] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_Parser_t), vader_type_859_ptrs, 1, 1, vader_type_859_strs, 3, vader_type_859_refs },
    [860] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_parser_StringLitInfo_t), NULL, 0, 1, vader_type_860_strs, 1, vader_type_860_refs },
    [861] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_CollectedModule_t), NULL, 0, 0, NULL, 5, vader_type_861_refs },
    [862] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_DiscoveredModule_t), NULL, 0, 2, vader_type_862_strs, 1, vader_type_862_refs },
    [863] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_FileWildcards_t), NULL, 0, 1, vader_type_863_strs, 2, vader_type_863_refs },
    [864] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_FolderBucket_t), NULL, 0, 1, vader_type_864_strs, 2, vader_type_864_refs },
    [865] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_ImportInfo_t), vader_type_865_ptrs, 1, 2, vader_type_865_strs, 1, vader_type_865_refs },
    [866] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_ImportTargetTable_t), NULL, 0, 0, NULL, 3, vader_type_866_refs },
    [867] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_IncludePath_t), NULL, 0, 2, vader_type_867_strs, 0, NULL },
    [868] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_LoadedModule_t), NULL, 0, 0, NULL, 4, vader_type_868_refs },
    [869] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_LoadedProject_t), vader_type_869_ptrs, 1, 1, vader_type_869_strs, 3, vader_type_869_refs },
    [870] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_Manifest_t), NULL, 0, 0, NULL, 1, vader_type_870_refs },
    [871] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_Module_t), NULL, 0, 3, vader_type_871_strs, 1, vader_type_871_refs },
    [872] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_ResolveState_t), NULL, 0, 1, vader_type_872_strs, 8, vader_type_872_refs },
    [873] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_ResolvedFile_t), NULL, 0, 0, NULL, 6, vader_type_873_refs },
    [874] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_ResolvedModule_t), NULL, 0, 2, vader_type_874_strs, 13, vader_type_874_refs },
    [875] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_Scope_t), NULL, 0, 0, NULL, 1, vader_type_875_refs },
    [876] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_SourceFile_t), NULL, 0, 2, vader_type_876_strs, 2, vader_type_876_refs },
    [877] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_StampCtx_t), NULL, 0, 1, vader_type_877_strs, 0, NULL },
    [878] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_Subst_t), NULL, 0, 0, NULL, 1, vader_type_878_refs },
    [879] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_SymbolTarget_t), NULL, 0, 1, vader_type_879_strs, 1, vader_type_879_refs },
    [880] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_TargetSelectors_t), NULL, 0, 0, NULL, 1, vader_type_880_refs },
    [881] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_symbol_Symbol_t), vader_type_881_ptrs, 1, 2, vader_type_881_strs, 0, NULL },
    [882] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_resolver_symbol_SymbolFactory_t), NULL, 0, 0, NULL, 0, NULL },
    [883] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_target_AllTargets_t), NULL, 0, 0, NULL, 0, NULL },
    [884] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_target_Target_t), NULL, 0, 0, NULL, 0, NULL },
    [885] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_BlockNarrow_t), vader_type_885_ptrs, 2, 1, vader_type_885_strs, 0, NULL },
    [886] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_CheckResult_t), NULL, 0, 0, NULL, 4, vader_type_886_refs },
    [887] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_DeadDecl_t), NULL, 0, 1, vader_type_887_strs, 1, vader_type_887_refs },
    [888] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_DivergentNarrow_t), vader_type_888_ptrs, 1, 1, vader_type_888_strs, 0, NULL },
    [889] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_EnclosingLoop_t), vader_type_889_ptrs, 2, 0, NULL, 0, NULL },
    [890] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_FieldChainStatic_t), vader_type_890_ptrs, 1, 1, vader_type_890_strs, 0, NULL },
    [891] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_FnContext_t), vader_type_891_ptrs, 4, 0, NULL, 0, NULL },
    [892] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_GenStateEntry_t), vader_type_892_ptrs, 1, 2, vader_type_892_strs, 0, NULL },
    [893] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_ImplEntry_t), vader_type_893_ptrs, 1, 1, vader_type_893_strs, 2, vader_type_893_refs },
    [894] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_ImplMethod_t), vader_type_894_ptrs, 1, 0, NULL, 0, NULL },
    [895] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_ImplRegistry_t), NULL, 0, 0, NULL, 2, vader_type_895_refs },
    [896] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_IsNarrow_t), vader_type_896_ptrs, 3, 1, vader_type_896_strs, 0, NULL },
    [897] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_NamedDeclLookup_t), vader_type_897_ptrs, 1, 1, vader_type_897_strs, 0, NULL },
    [898] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_NamedDeclRefs_t), NULL, 0, 1, vader_type_898_strs, 3, vader_type_898_refs },
    [899] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_NarrowSlot_t), vader_type_899_ptrs, 1, 0, NULL, 0, NULL },
    [900] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_PushedNarrow_t), vader_type_900_ptrs, 1, 1, vader_type_900_strs, 0, NULL },
    [901] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_ReprRange_t), NULL, 0, 0, NULL, 0, NULL },
    [902] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_Substitution_t), vader_type_902_ptrs, 1, 0, NULL, 1, vader_type_902_refs },
    [903] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_TypedProgram_t), vader_type_903_ptrs, 6, 0, NULL, 48, vader_type_903_refs },
    [904] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_TypedProject_t), NULL, 0, 0, NULL, 1, vader_type_904_refs },
    [905] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_typecheck_UfcsResult_t), vader_type_905_ptrs, 2, 0, NULL, 0, NULL },
    [906] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_AnyType_t), NULL, 0, 0, NULL, 0, NULL },
    [907] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_ArrayType_t), vader_type_907_ptrs, 1, 0, NULL, 0, NULL },
    [908] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_DistinctType_t), vader_type_908_ptrs, 1, 0, NULL, 1, vader_type_908_refs },
    [909] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_EnumType_t), NULL, 0, 1, vader_type_909_strs, 2, vader_type_909_refs },
    [910] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_FnType_t), vader_type_910_ptrs, 1, 0, NULL, 2, vader_type_910_refs },
    [911] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_FreeCharType_t), NULL, 0, 0, NULL, 0, NULL },
    [912] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_FreeFloatType_t), NULL, 0, 0, NULL, 0, NULL },
    [913] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_FreeIntType_t), NULL, 0, 0, NULL, 0, NULL },
    [914] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_NeverType_t), NULL, 0, 0, NULL, 0, NULL },
    [915] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_PrimitiveMeta_t), NULL, 0, 1, vader_type_915_strs, 0, NULL },
    [916] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_PrimitiveType_t), NULL, 0, 1, vader_type_916_strs, 0, NULL },
    [917] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_SelfType_t), NULL, 0, 0, NULL, 0, NULL },
    [918] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_StructType_t), NULL, 0, 0, NULL, 2, vader_type_918_refs },
    [919] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_TraitType_t), NULL, 0, 0, NULL, 2, vader_type_919_refs },
    [920] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_TupleType_t), NULL, 0, 0, NULL, 1, vader_type_920_refs },
    [921] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_TypeMetaType_t), NULL, 0, 0, NULL, 0, NULL },
    [922] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_TypeParamType_t), NULL, 0, 0, NULL, 1, vader_type_922_refs },
    [923] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_UnionType_t), NULL, 0, 0, NULL, 1, vader_type_923_refs },
    [924] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_types_UnresolvedType_t), NULL, 0, 0, NULL, 0, NULL },
    [925] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_ArrayVal_t), NULL, 0, 0, NULL, 1, vader_type_925_refs },
    [926] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_BoolVal_t), NULL, 0, 0, NULL, 0, NULL },
    [927] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_CharVal_t), NULL, 0, 0, NULL, 0, NULL },
    [928] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_DebugController_t), NULL, 0, 0, NULL, 3, vader_type_928_refs },
    [929] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_ErrorVal_t), NULL, 0, 1, vader_type_929_strs, 0, NULL },
    [930] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_F64Val_t), NULL, 0, 0, NULL, 0, NULL },
    [931] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_FfiCallArgs_t), NULL, 0, 0, NULL, 1, vader_type_931_refs },
    [932] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_FnVal_t), vader_type_932_ptrs, 1, 0, NULL, 0, NULL },
    [933] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_Frame_t), NULL, 0, 0, NULL, 7, vader_type_933_refs },
    [934] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_HostOk_t), vader_type_934_ptrs, 1, 0, NULL, 0, NULL },
    [935] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_I32Val_t), NULL, 0, 0, NULL, 0, NULL },
    [936] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_I64Val_t), NULL, 0, 0, NULL, 0, NULL },
    [937] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_NullVal_t), NULL, 0, 0, NULL, 0, NULL },
    [938] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_ObjVal_t), NULL, 0, 0, NULL, 2, vader_type_938_refs },
    [939] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_Ok_t), NULL, 0, 0, NULL, 0, NULL },
    [940] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_PauseCtx_t), NULL, 0, 1, vader_type_940_strs, 1, vader_type_940_refs },
    [941] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_PauseFrame_t), NULL, 0, 2, vader_type_941_strs, 1, vader_type_941_refs },
    [942] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_PauseVar_t), NULL, 0, 2, vader_type_942_strs, 1, vader_type_942_refs },
    [943] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_StringVal_t), NULL, 0, 1, vader_type_943_strs, 0, NULL },
    [944] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_StructVal_t), NULL, 0, 0, NULL, 1, vader_type_944_refs },
    [945] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_Trap_t), NULL, 0, 1, vader_type_945_strs, 0, NULL },
    [946] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_TypeVal_t), NULL, 0, 0, NULL, 0, NULL },
    [947] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_ValueOk_t), vader_type_947_ptrs, 1, 0, NULL, 0, NULL },
    [948] = { VADER_TYPE_KIND_STRUCT, sizeof(vader_struct_vader_vm_VmState_t), NULL, 0, 0, NULL, 4, vader_type_948_refs },
};
const size_t vader_type_info_count = 1244;

const size_t vader_type_size[1244] = {
    [0] = 0u,
    [1] = 16u,
    [2] = 16u,
    [3] = 16u,
    [4] = 16u,
    [5] = 16u,
    [6] = 16u,
    [7] = 16u,
    [8] = 16u,
    [9] = 16u,
    [10] = 16u,
    [11] = 16u,
    [12] = 16u,
    [13] = 16u,
    [14] = 16u,
    [15] = 16u,
    [16] = 16u,
    [17] = 16u,
    [18] = 16u,
    [19] = 16u,
    [20] = 16u,
    [21] = 16u,
    [22] = 16u,
    [23] = 16u,
    [24] = 16u,
    [25] = 16u,
    [26] = 16u,
    [27] = 16u,
    [28] = 16u,
    [29] = 16u,
    [30] = 16u,
    [31] = 16u,
    [32] = 16u,
    [33] = 16u,
    [34] = 16u,
    [35] = 16u,
    [36] = 16u,
    [37] = 16u,
    [38] = 16u,
    [39] = 16u,
    [40] = 16u,
    [41] = 16u,
    [42] = 16u,
    [43] = 16u,
    [44] = 16u,
    [45] = 16u,
    [46] = 16u,
    [47] = 16u,
    [48] = 16u,
    [49] = 16u,
    [50] = 16u,
    [51] = 16u,
    [52] = 16u,
    [53] = 16u,
    [54] = 16u,
    [55] = 16u,
    [56] = 16u,
    [57] = 16u,
    [58] = 16u,
    [59] = 16u,
    [60] = 16u,
    [61] = 16u,
    [62] = 16u,
    [63] = 16u,
    [64] = 16u,
    [65] = 16u,
    [66] = 16u,
    [67] = 16u,
    [68] = 16u,
    [69] = 16u,
    [70] = 16u,
    [71] = 16u,
    [72] = 16u,
    [73] = 16u,
    [74] = 16u,
    [75] = 16u,
    [76] = 16u,
    [77] = 16u,
    [78] = 16u,
    [79] = 16u,
    [80] = 16u,
    [81] = 16u,
    [82] = 16u,
    [83] = 16u,
    [84] = 16u,
    [85] = 16u,
    [86] = 16u,
    [87] = 16u,
    [88] = 16u,
    [89] = 16u,
    [90] = 16u,
    [91] = 16u,
    [92] = 16u,
    [93] = 16u,
    [94] = 16u,
    [95] = 16u,
    [96] = 16u,
    [97] = 16u,
    [98] = 16u,
    [99] = 16u,
    [100] = 16u,
    [101] = 16u,
    [102] = 16u,
    [103] = 16u,
    [104] = 16u,
    [105] = 16u,
    [106] = 16u,
    [107] = 16u,
    [108] = 16u,
    [109] = 16u,
    [110] = 16u,
    [111] = 16u,
    [112] = 16u,
    [113] = 16u,
    [114] = 16u,
    [115] = 16u,
    [116] = 16u,
    [117] = 16u,
    [118] = 16u,
    [119] = 16u,
    [120] = 16u,
    [121] = 16u,
    [122] = 16u,
    [123] = 16u,
    [124] = 16u,
    [125] = 16u,
    [126] = 16u,
    [127] = 16u,
    [128] = 16u,
    [129] = 16u,
    [130] = 16u,
    [131] = 16u,
    [132] = 16u,
    [133] = 16u,
    [134] = 16u,
    [135] = 16u,
    [136] = 16u,
    [137] = 16u,
    [138] = 16u,
    [139] = 16u,
    [140] = 16u,
    [141] = 16u,
    [142] = 16u,
    [143] = 16u,
    [144] = 16u,
    [145] = 16u,
    [146] = 16u,
    [147] = 16u,
    [148] = 16u,
    [149] = 16u,
    [150] = 16u,
    [151] = 16u,
    [152] = 16u,
    [153] = 16u,
    [154] = 16u,
    [155] = 16u,
    [156] = 16u,
    [157] = 16u,
    [158] = 4u,
    [159] = 8u,
    [160] = 1u,
    [161] = 4u,
    [162] = 16u,
    [163] = 0u,
    [164] = 16u,
    [165] = 4u,
    [166] = 8u,
    [167] = 8u,
    [168] = 1u,
    [169] = 4u,
    [170] = 8u,
    [171] = 8u,
    [172] = 16u,
    [173] = 16u,
    [174] = 16u,
    [175] = 16u,
    [176] = 16u,
    [177] = 16u,
    [178] = 16u,
    [179] = 16u,
    [180] = 16u,
    [181] = 16u,
    [182] = 16u,
    [183] = 16u,
    [184] = 16u,
    [185] = 16u,
    [186] = 16u,
    [187] = 16u,
    [188] = 16u,
    [189] = 16u,
    [190] = 16u,
    [191] = 16u,
    [192] = 16u,
    [193] = 16u,
    [194] = 16u,
    [195] = 16u,
    [196] = 16u,
    [197] = 16u,
    [198] = 16u,
    [199] = 16u,
    [200] = 16u,
    [201] = 16u,
    [202] = 16u,
    [203] = 16u,
    [204] = 16u,
    [205] = 16u,
    [206] = 16u,
    [207] = 16u,
    [208] = 16u,
    [209] = 16u,
    [210] = 16u,
    [211] = 16u,
    [212] = 16u,
    [213] = 16u,
    [214] = 16u,
    [215] = 16u,
    [216] = 16u,
    [217] = 16u,
    [218] = 16u,
    [219] = 16u,
    [220] = 16u,
    [221] = 16u,
    [222] = 16u,
    [223] = 16u,
    [224] = 16u,
    [225] = 16u,
    [226] = 16u,
    [227] = 16u,
    [228] = 16u,
    [229] = 16u,
    [230] = 16u,
    [231] = 16u,
    [232] = 16u,
    [233] = 16u,
    [234] = 16u,
    [235] = 16u,
    [236] = 16u,
    [237] = 16u,
    [238] = 16u,
    [239] = 16u,
    [240] = 16u,
    [241] = 16u,
    [242] = 16u,
    [243] = 16u,
    [244] = 16u,
    [245] = 16u,
    [246] = 16u,
    [247] = 16u,
    [248] = 16u,
    [249] = 16u,
    [250] = 16u,
    [251] = 16u,
    [252] = 16u,
    [253] = 16u,
    [254] = 16u,
    [255] = 16u,
    [256] = 16u,
    [257] = 16u,
    [258] = 16u,
    [259] = 16u,
    [260] = 16u,
    [261] = 16u,
    [262] = 16u,
    [263] = 16u,
    [264] = 16u,
    [265] = 16u,
    [266] = 16u,
    [267] = 16u,
    [268] = 16u,
    [269] = 16u,
    [270] = 16u,
    [271] = 16u,
    [272] = 16u,
    [273] = 16u,
    [274] = 16u,
    [275] = 16u,
    [276] = 16u,
    [277] = 16u,
    [278] = 16u,
    [279] = 16u,
    [280] = 16u,
    [281] = 16u,
    [282] = 16u,
    [283] = 16u,
    [284] = 16u,
    [285] = 16u,
    [286] = 16u,
    [287] = 16u,
    [288] = 16u,
    [289] = 16u,
    [290] = 16u,
    [291] = 16u,
    [292] = 16u,
    [293] = 16u,
    [294] = 16u,
    [295] = 16u,
    [296] = 16u,
    [297] = 16u,
    [298] = 16u,
    [299] = 16u,
    [300] = 16u,
    [301] = 16u,
    [302] = 16u,
    [303] = 16u,
    [304] = 16u,
    [305] = 16u,
    [306] = 16u,
    [307] = 16u,
    [308] = 16u,
    [309] = 16u,
    [310] = 16u,
    [311] = 16u,
    [312] = 16u,
    [313] = 16u,
    [314] = 16u,
    [315] = 16u,
    [316] = 16u,
    [317] = 16u,
    [318] = 16u,
    [319] = 16u,
    [320] = 16u,
    [321] = 16u,
    [322] = 16u,
    [323] = 16u,
    [324] = 16u,
    [325] = 16u,
    [326] = 16u,
    [327] = 16u,
    [328] = 16u,
    [329] = 16u,
    [330] = 16u,
    [331] = 16u,
    [332] = 16u,
    [333] = 16u,
    [334] = 16u,
    [335] = 16u,
    [336] = 16u,
    [337] = 16u,
    [338] = 16u,
    [339] = 16u,
    [340] = 16u,
    [341] = 16u,
    [342] = 16u,
    [343] = 16u,
    [344] = 16u,
    [345] = 16u,
    [346] = 16u,
    [347] = 16u,
    [348] = 16u,
    [349] = 16u,
    [350] = 16u,
    [351] = 16u,
    [352] = 16u,
    [353] = 16u,
    [354] = 16u,
    [355] = 16u,
    [356] = 16u,
    [357] = 16u,
    [358] = 16u,
    [359] = 16u,
    [360] = 16u,
    [361] = 16u,
    [362] = 16u,
    [363] = 16u,
    [364] = 16u,
    [365] = 16u,
    [366] = 16u,
    [367] = 16u,
    [368] = 16u,
    [369] = 16u,
    [370] = 16u,
    [371] = 16u,
    [372] = 16u,
    [373] = 16u,
    [374] = 16u,
    [375] = 16u,
    [376] = 16u,
    [377] = 16u,
    [378] = 16u,
    [379] = 16u,
    [380] = 16u,
    [381] = 16u,
    [382] = 16u,
    [383] = 16u,
    [384] = 16u,
    [385] = 16u,
    [386] = 16u,
    [387] = 16u,
    [388] = 16u,
    [389] = 16u,
    [390] = 16u,
    [391] = 16u,
    [392] = 16u,
    [393] = 16u,
    [394] = 16u,
    [395] = 16u,
    [396] = 16u,
    [397] = 16u,
    [398] = 16u,
    [399] = 16u,
    [400] = 16u,
    [401] = 16u,
    [402] = 16u,
    [403] = 16u,
    [404] = 16u,
    [405] = 16u,
    [406] = 16u,
    [407] = 16u,
    [408] = 16u,
    [409] = 16u,
    [410] = 16u,
    [411] = 16u,
    [412] = 16u,
    [413] = 16u,
    [414] = 16u,
    [415] = 16u,
    [416] = 16u,
    [417] = 16u,
    [418] = 16u,
    [419] = 16u,
    [420] = 16u,
    [421] = 16u,
    [422] = 16u,
    [423] = 16u,
    [424] = 16u,
    [425] = 16u,
    [426] = 16u,
    [427] = 16u,
    [428] = 16u,
    [429] = 16u,
    [430] = 16u,
    [431] = 16u,
    [432] = 16u,
    [433] = 16u,
    [434] = 16u,
    [435] = 16u,
    [436] = 16u,
    [437] = 16u,
    [438] = 16u,
    [439] = 16u,
    [440] = 16u,
    [441] = 16u,
    [442] = 16u,
    [443] = 16u,
    [444] = 16u,
    [445] = 16u,
    [446] = 16u,
    [447] = 16u,
    [448] = 16u,
    [449] = 16u,
    [450] = 16u,
    [451] = 16u,
    [452] = 16u,
    [453] = 16u,
    [454] = 16u,
    [455] = 16u,
    [456] = 16u,
    [457] = 16u,
    [458] = 16u,
    [459] = 16u,
    [460] = 16u,
    [461] = 16u,
    [462] = 16u,
    [463] = 16u,
    [464] = 16u,
    [465] = 16u,
    [466] = 16u,
    [467] = 16u,
    [468] = 16u,
    [469] = 16u,
    [470] = 16u,
    [471] = 16u,
    [472] = 16u,
    [473] = 16u,
    [474] = 16u,
    [475] = 16u,
    [476] = 16u,
    [477] = 16u,
    [478] = 16u,
    [479] = 16u,
    [480] = 16u,
    [481] = 16u,
    [482] = 16u,
    [483] = 16u,
    [484] = 16u,
    [485] = 16u,
    [486] = 16u,
    [487] = 16u,
    [488] = 16u,
    [489] = 16u,
    [490] = 16u,
    [491] = 16u,
    [492] = 16u,
    [493] = 16u,
    [494] = 16u,
    [495] = 16u,
    [496] = 16u,
    [497] = 16u,
    [498] = 16u,
    [499] = 16u,
    [500] = 16u,
    [501] = 16u,
    [502] = 16u,
    [503] = 16u,
    [504] = 16u,
    [505] = 16u,
    [506] = 16u,
    [507] = 16u,
    [508] = 16u,
    [509] = 16u,
    [510] = 16u,
    [511] = 16u,
    [512] = 16u,
    [513] = 16u,
    [514] = 16u,
    [515] = 16u,
    [516] = 16u,
    [517] = 16u,
    [518] = 16u,
    [519] = 16u,
    [520] = 16u,
    [521] = 16u,
    [522] = 16u,
    [523] = 16u,
    [524] = 16u,
    [525] = 16u,
    [526] = 16u,
    [527] = 16u,
    [528] = 16u,
    [529] = 16u,
    [530] = 16u,
    [531] = 16u,
    [532] = 16u,
    [533] = 16u,
    [534] = 16u,
    [535] = 16u,
    [536] = 16u,
    [537] = 16u,
    [538] = 16u,
    [539] = 16u,
    [540] = 16u,
    [541] = 16u,
    [542] = 16u,
    [543] = 16u,
    [544] = 16u,
    [545] = 16u,
    [546] = 16u,
    [547] = 16u,
    [548] = 16u,
    [549] = 16u,
    [550] = 16u,
    [551] = 16u,
    [552] = 16u,
    [553] = 16u,
    [554] = 16u,
    [555] = 16u,
    [556] = 16u,
    [557] = 16u,
    [558] = 16u,
    [559] = 16u,
    [560] = 16u,
    [561] = 16u,
    [562] = 16u,
    [563] = 16u,
    [564] = 16u,
    [565] = 16u,
    [566] = 16u,
    [567] = 16u,
    [568] = 16u,
    [569] = 16u,
    [570] = 16u,
    [571] = 16u,
    [572] = 16u,
    [573] = 16u,
    [574] = 16u,
    [575] = 16u,
    [576] = 16u,
    [577] = 16u,
    [578] = 16u,
    [579] = 16u,
    [580] = 16u,
    [581] = 16u,
    [582] = 16u,
    [583] = 16u,
    [584] = 16u,
    [585] = 16u,
    [586] = 16u,
    [587] = 16u,
    [588] = 16u,
    [589] = 16u,
    [590] = 16u,
    [591] = 16u,
    [592] = 16u,
    [593] = 16u,
    [594] = 16u,
    [595] = 16u,
    [596] = 16u,
    [597] = 16u,
    [598] = 16u,
    [599] = 16u,
    [600] = 16u,
    [601] = 16u,
    [602] = 16u,
    [603] = 16u,
    [604] = 16u,
    [605] = 16u,
    [606] = 16u,
    [607] = 16u,
    [608] = 16u,
    [609] = 16u,
    [610] = 16u,
    [611] = 16u,
    [612] = 16u,
    [613] = 16u,
    [614] = 16u,
    [615] = 16u,
    [616] = 16u,
    [617] = 16u,
    [618] = 16u,
    [619] = 16u,
    [620] = 16u,
    [621] = 16u,
    [622] = 16u,
    [623] = 16u,
    [624] = 16u,
    [625] = 16u,
    [626] = 16u,
    [627] = 16u,
    [628] = 16u,
    [629] = 16u,
    [630] = 16u,
    [631] = 16u,
    [632] = 16u,
    [633] = 16u,
    [634] = 16u,
    [635] = 16u,
    [636] = 16u,
    [637] = 16u,
    [638] = 16u,
    [639] = 16u,
    [640] = 16u,
    [641] = 16u,
    [642] = 16u,
    [643] = 16u,
    [644] = 16u,
    [645] = 16u,
    [646] = 16u,
    [647] = 16u,
    [648] = 16u,
    [649] = 16u,
    [650] = 16u,
    [651] = 16u,
    [652] = 16u,
    [653] = 16u,
    [654] = 16u,
    [655] = 16u,
    [656] = 16u,
    [657] = 16u,
    [658] = 16u,
    [659] = 16u,
    [660] = 16u,
    [661] = 16u,
    [662] = 16u,
    [663] = 16u,
    [664] = 16u,
    [665] = 16u,
    [666] = 16u,
    [667] = 16u,
    [668] = 16u,
    [669] = 16u,
    [670] = 16u,
    [671] = 16u,
    [672] = 16u,
    [673] = 16u,
    [674] = 16u,
    [675] = 16u,
    [676] = 16u,
    [677] = 16u,
    [678] = 16u,
    [679] = 16u,
    [680] = 16u,
    [681] = 16u,
    [682] = 16u,
    [683] = 16u,
    [684] = 16u,
    [685] = 16u,
    [686] = 16u,
    [687] = 16u,
    [688] = 16u,
    [689] = 16u,
    [690] = 16u,
    [691] = 16u,
    [692] = 16u,
    [693] = 16u,
    [694] = 16u,
    [695] = 16u,
    [696] = 16u,
    [697] = 16u,
    [698] = 16u,
    [699] = 16u,
    [700] = 16u,
    [701] = 16u,
    [702] = 16u,
    [703] = 16u,
    [704] = 16u,
    [705] = 16u,
    [706] = 16u,
    [707] = 16u,
    [708] = 16u,
    [709] = 16u,
    [710] = 16u,
    [711] = 16u,
    [712] = 16u,
    [713] = 16u,
    [714] = 16u,
    [715] = 16u,
    [716] = 16u,
    [717] = 16u,
    [718] = 16u,
    [719] = 16u,
    [720] = 16u,
    [721] = 16u,
    [722] = 16u,
    [723] = 16u,
    [724] = 16u,
    [725] = 16u,
    [726] = 16u,
    [727] = 16u,
    [728] = 16u,
    [729] = 16u,
    [730] = 16u,
    [731] = 16u,
    [732] = 16u,
    [733] = 16u,
    [734] = 16u,
    [735] = 16u,
    [736] = 16u,
    [737] = 16u,
    [738] = 16u,
    [739] = 16u,
    [740] = 16u,
    [741] = 16u,
    [742] = 16u,
    [743] = 16u,
    [744] = 16u,
    [745] = 16u,
    [746] = 16u,
    [747] = 16u,
    [748] = 16u,
    [749] = 16u,
    [750] = 16u,
    [751] = 16u,
    [752] = 16u,
    [753] = 16u,
    [754] = 16u,
    [755] = 16u,
    [756] = 16u,
    [757] = 16u,
    [758] = 16u,
    [759] = 16u,
    [760] = 16u,
    [761] = 16u,
    [762] = 16u,
    [763] = 16u,
    [764] = 16u,
    [765] = 16u,
    [766] = 16u,
    [767] = 16u,
    [768] = 16u,
    [769] = 16u,
    [770] = 16u,
    [771] = 16u,
    [772] = 16u,
    [773] = 16u,
    [774] = 16u,
    [775] = 16u,
    [776] = 16u,
    [777] = 16u,
    [778] = 16u,
    [779] = 16u,
    [780] = 16u,
    [781] = 16u,
    [782] = 16u,
    [783] = 16u,
    [784] = 16u,
    [785] = 16u,
    [786] = 16u,
    [787] = 16u,
    [788] = 16u,
    [789] = 16u,
    [790] = 16u,
    [791] = 16u,
    [792] = 16u,
    [793] = 16u,
    [794] = 16u,
    [795] = 16u,
    [796] = 16u,
    [797] = 16u,
    [798] = 16u,
    [799] = 16u,
    [800] = 16u,
    [801] = 16u,
    [802] = 16u,
    [803] = 16u,
    [804] = 16u,
    [805] = 16u,
    [806] = 16u,
    [807] = 16u,
    [808] = 16u,
    [809] = 16u,
    [810] = 16u,
    [811] = 16u,
    [812] = 16u,
    [813] = 16u,
    [814] = 16u,
    [815] = 16u,
    [816] = 16u,
    [817] = 16u,
    [818] = 16u,
    [819] = 16u,
    [820] = 16u,
    [821] = 16u,
    [822] = 16u,
    [823] = 16u,
    [824] = 16u,
    [825] = 16u,
    [826] = 16u,
    [827] = 16u,
    [828] = 16u,
    [829] = 16u,
    [830] = 16u,
    [831] = 16u,
    [832] = 16u,
    [833] = 16u,
    [834] = 16u,
    [835] = 16u,
    [836] = 16u,
    [837] = 16u,
    [838] = 16u,
    [839] = 16u,
    [840] = 16u,
    [841] = 16u,
    [842] = 16u,
    [843] = 16u,
    [844] = 16u,
    [845] = 16u,
    [846] = 16u,
    [847] = 16u,
    [848] = 16u,
    [849] = 16u,
    [850] = 16u,
    [851] = 16u,
    [852] = 16u,
    [853] = 16u,
    [854] = 16u,
    [855] = 16u,
    [856] = 16u,
    [857] = 16u,
    [858] = 16u,
    [859] = 16u,
    [860] = 16u,
    [861] = 16u,
    [862] = 16u,
    [863] = 16u,
    [864] = 16u,
    [865] = 16u,
    [866] = 16u,
    [867] = 16u,
    [868] = 16u,
    [869] = 16u,
    [870] = 16u,
    [871] = 16u,
    [872] = 16u,
    [873] = 16u,
    [874] = 16u,
    [875] = 16u,
    [876] = 16u,
    [877] = 16u,
    [878] = 16u,
    [879] = 16u,
    [880] = 16u,
    [881] = 16u,
    [882] = 16u,
    [883] = 16u,
    [884] = 16u,
    [885] = 16u,
    [886] = 16u,
    [887] = 16u,
    [888] = 16u,
    [889] = 16u,
    [890] = 16u,
    [891] = 16u,
    [892] = 16u,
    [893] = 16u,
    [894] = 16u,
    [895] = 16u,
    [896] = 16u,
    [897] = 16u,
    [898] = 16u,
    [899] = 16u,
    [900] = 16u,
    [901] = 16u,
    [902] = 16u,
    [903] = 16u,
    [904] = 16u,
    [905] = 16u,
    [906] = 16u,
    [907] = 16u,
    [908] = 16u,
    [909] = 16u,
    [910] = 16u,
    [911] = 16u,
    [912] = 16u,
    [913] = 16u,
    [914] = 16u,
    [915] = 16u,
    [916] = 16u,
    [917] = 16u,
    [918] = 16u,
    [919] = 16u,
    [920] = 16u,
    [921] = 16u,
    [922] = 16u,
    [923] = 16u,
    [924] = 16u,
    [925] = 16u,
    [926] = 16u,
    [927] = 16u,
    [928] = 16u,
    [929] = 16u,
    [930] = 16u,
    [931] = 16u,
    [932] = 16u,
    [933] = 16u,
    [934] = 16u,
    [935] = 16u,
    [936] = 16u,
    [937] = 16u,
    [938] = 16u,
    [939] = 16u,
    [940] = 16u,
    [941] = 16u,
    [942] = 16u,
    [943] = 16u,
    [944] = 16u,
    [945] = 16u,
    [946] = 16u,
    [947] = 16u,
    [948] = 16u,
    [949] = 16u,
    [950] = 16u,
    [951] = 16u,
    [952] = 16u,
    [953] = 16u,
    [954] = 16u,
    [955] = 16u,
    [956] = 16u,
    [957] = 16u,
    [958] = 16u,
    [959] = 16u,
    [960] = 16u,
    [961] = 16u,
    [962] = 16u,
    [963] = 16u,
    [964] = 16u,
    [965] = 16u,
    [966] = 16u,
    [967] = 16u,
    [968] = 16u,
    [969] = 16u,
    [970] = 16u,
    [971] = 16u,
    [972] = 16u,
    [973] = 16u,
    [974] = 16u,
    [975] = 16u,
    [976] = 16u,
    [977] = 16u,
    [978] = 16u,
    [979] = 16u,
    [980] = 16u,
    [981] = 16u,
    [982] = 16u,
    [983] = 16u,
    [984] = 16u,
    [985] = 16u,
    [986] = 16u,
    [987] = 16u,
    [988] = 16u,
    [989] = 16u,
    [990] = 16u,
    [991] = 16u,
    [992] = 16u,
    [993] = 16u,
    [994] = 16u,
    [995] = 16u,
    [996] = 16u,
    [997] = 16u,
    [998] = 16u,
    [999] = 16u,
    [1000] = 16u,
    [1001] = 16u,
    [1002] = 16u,
    [1003] = 16u,
    [1004] = 16u,
    [1005] = 16u,
    [1006] = 16u,
    [1007] = 16u,
    [1008] = 16u,
    [1009] = 16u,
    [1010] = 16u,
    [1011] = 16u,
    [1012] = 16u,
    [1013] = 16u,
    [1014] = 16u,
    [1015] = 16u,
    [1016] = 16u,
    [1017] = 16u,
    [1018] = 16u,
    [1019] = 16u,
    [1020] = 16u,
    [1021] = 16u,
    [1022] = 16u,
    [1023] = 16u,
    [1024] = 16u,
    [1025] = 16u,
    [1026] = 16u,
    [1027] = 16u,
    [1028] = 16u,
    [1029] = 16u,
    [1030] = 16u,
    [1031] = 16u,
    [1032] = 16u,
    [1033] = 16u,
    [1034] = 16u,
    [1035] = 16u,
    [1036] = 16u,
    [1037] = 16u,
    [1038] = 16u,
    [1039] = 16u,
    [1040] = 16u,
    [1041] = 16u,
    [1042] = 16u,
    [1043] = 16u,
    [1044] = 16u,
    [1045] = 16u,
    [1046] = 16u,
    [1047] = 16u,
    [1048] = 16u,
    [1049] = 16u,
    [1050] = 16u,
    [1051] = 16u,
    [1052] = 16u,
    [1053] = 16u,
    [1054] = 16u,
    [1055] = 16u,
    [1056] = 16u,
    [1057] = 16u,
    [1058] = 16u,
    [1059] = 16u,
    [1060] = 16u,
    [1061] = 16u,
    [1062] = 16u,
    [1063] = 16u,
    [1064] = 16u,
    [1065] = 16u,
    [1066] = 16u,
    [1067] = 16u,
    [1068] = 16u,
    [1069] = 16u,
    [1070] = 16u,
    [1071] = 16u,
    [1072] = 16u,
    [1073] = 16u,
    [1074] = 16u,
    [1075] = 16u,
    [1076] = 16u,
    [1077] = 16u,
    [1078] = 16u,
    [1079] = 16u,
    [1080] = 16u,
    [1081] = 16u,
    [1082] = 16u,
    [1083] = 16u,
    [1084] = 16u,
    [1085] = 16u,
    [1086] = 16u,
    [1087] = 16u,
    [1088] = 16u,
    [1089] = 16u,
    [1090] = 16u,
    [1091] = 16u,
    [1092] = 16u,
    [1093] = 16u,
    [1094] = 16u,
    [1095] = 16u,
    [1096] = 16u,
    [1097] = 16u,
    [1098] = 16u,
    [1099] = 16u,
    [1100] = 16u,
    [1101] = 16u,
    [1102] = 16u,
    [1103] = 16u,
    [1104] = 16u,
    [1105] = 16u,
    [1106] = 16u,
    [1107] = 16u,
    [1108] = 16u,
    [1109] = 16u,
    [1110] = 16u,
    [1111] = 16u,
    [1112] = 16u,
    [1113] = 16u,
    [1114] = 16u,
    [1115] = 16u,
    [1116] = 16u,
    [1117] = 16u,
    [1118] = 16u,
    [1119] = 16u,
    [1120] = 16u,
    [1121] = 16u,
    [1122] = 16u,
    [1123] = 16u,
    [1124] = 16u,
    [1125] = 16u,
    [1126] = 16u,
    [1127] = 16u,
    [1128] = 16u,
    [1129] = 16u,
    [1130] = 16u,
    [1131] = 16u,
    [1132] = 16u,
    [1133] = 16u,
    [1134] = 16u,
    [1135] = 16u,
    [1136] = 16u,
    [1137] = 16u,
    [1138] = 16u,
    [1139] = 16u,
    [1140] = 16u,
    [1141] = 16u,
    [1142] = 16u,
    [1143] = 16u,
    [1144] = 16u,
    [1145] = 16u,
    [1146] = 16u,
    [1147] = 16u,
    [1148] = 16u,
    [1149] = 16u,
    [1150] = 16u,
    [1151] = 16u,
    [1152] = 16u,
    [1153] = 16u,
    [1154] = 16u,
    [1155] = 16u,
    [1156] = 16u,
    [1157] = 16u,
    [1158] = 16u,
    [1159] = 16u,
    [1160] = 16u,
    [1161] = 16u,
    [1162] = 16u,
    [1163] = 16u,
    [1164] = 16u,
    [1165] = 16u,
    [1166] = 16u,
    [1167] = 16u,
    [1168] = 16u,
    [1169] = 16u,
    [1170] = 16u,
    [1171] = 16u,
    [1172] = 16u,
    [1173] = 16u,
    [1174] = 16u,
    [1175] = 16u,
    [1176] = 16u,
    [1177] = 16u,
    [1178] = 16u,
    [1179] = 16u,
    [1180] = 16u,
    [1181] = 16u,
    [1182] = 16u,
    [1183] = 16u,
    [1184] = 16u,
    [1185] = 16u,
    [1186] = 16u,
    [1187] = 16u,
    [1188] = 16u,
    [1189] = 16u,
    [1190] = 16u,
    [1191] = 16u,
    [1192] = 16u,
    [1193] = 16u,
    [1194] = 16u,
    [1195] = 16u,
    [1196] = 16u,
    [1197] = 16u,
    [1198] = 16u,
    [1199] = 16u,
    [1200] = 16u,
    [1201] = 16u,
    [1202] = 16u,
    [1203] = 16u,
    [1204] = 16u,
    [1205] = 16u,
    [1206] = 16u,
    [1207] = 16u,
    [1208] = 16u,
    [1209] = 16u,
    [1210] = 16u,
    [1211] = 16u,
    [1212] = 16u,
    [1213] = 16u,
    [1214] = 16u,
    [1215] = 16u,
    [1216] = 16u,
    [1217] = 16u,
    [1218] = 16u,
    [1219] = 16u,
    [1220] = 16u,
    [1221] = 16u,
    [1222] = 16u,
    [1223] = 16u,
    [1224] = 16u,
    [1225] = 16u,
    [1226] = 16u,
    [1227] = 16u,
    [1228] = 16u,
    [1229] = 16u,
    [1230] = 16u,
    [1231] = 16u,
    [1232] = 16u,
    [1233] = 16u,
    [1234] = 16u,
    [1235] = 16u,
    [1236] = 16u,
    [1237] = 16u,
    [1238] = 16u,
    [1239] = 16u,
    [1240] = 16u,
    [1241] = 16u,
    [1242] = 16u,
    [1243] = 16u,
};

