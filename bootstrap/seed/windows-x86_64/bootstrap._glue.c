#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_std_console$stderr_is_console$keep(void* env) {
    (void) env;
    std_console$stderr_is_console$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_std_console$stderr_is_console$keep = {
    VADER_STATIC_HEADER(476u), (void*) &vader_fn_tramp_std_console$stderr_is_console$keep, NULL,
};

vader_box_t vader_fn_tramp_std_console$stdout_is_console$keep(void* env) {
    (void) env;
    std_console$stdout_is_console$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_std_console$stdout_is_console$keep = {
    VADER_STATIC_HEADER(476u), (void*) &vader_fn_tramp_std_console$stdout_is_console$keep, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_path_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, __lambda_std_path_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_path_0 = {
    VADER_STATIC_HEADER(493u), (void*) &vader_fn_tramp___lambda_std_path_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_path_1(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, __lambda_std_path_1(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_path_1 = {
    VADER_STATIC_HEADER(493u), (void*) &vader_fn_tramp___lambda_std_path_1, NULL,
};

vader_box_t vader_fn_tramp_std_string$compare_ascending(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, std_string$compare_ascending(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static_std_string$compare_ascending = {
    VADER_STATIC_HEADER(495u), (void*) &vader_fn_tramp_std_string$compare_ascending, NULL,
};

vader_box_t vader_fn_tramp_toolchain_diagnostics$diag_less_with_file(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, toolchain_diagnostics$diag_less_with_file(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_toolchain_diagnostics$diag_less_with_file = {
    VADER_STATIC_HEADER(511u), (void*) &vader_fn_tramp_toolchain_diagnostics$diag_less_with_file,
    NULL,
};

vader_box_t vader_fn_tramp_toolchain_diagnostics$diag_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, toolchain_diagnostics$diag_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_toolchain_diagnostics$diag_less = {
    VADER_STATIC_HEADER(511u), (void*) &vader_fn_tramp_toolchain_diagnostics$diag_less, NULL,
};

vader_box_t vader_fn_tramp_vader_front_resolver$declared_roots$keep(void* env) {
    (void) env;
    vader_front_resolver$declared_roots$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_vader_front_resolver$declared_roots$keep = {
    VADER_STATIC_HEADER(476u), (void*) &vader_fn_tramp_vader_front_resolver$declared_roots$keep,
    NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_5(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_resolver_5());
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_5 = {
    VADER_STATIC_HEADER(458u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_6(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_front_resolver_6(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_6 = {
    VADER_STATIC_HEADER(513u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_6, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_14(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_resolver_14());
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_14 = {
    VADER_STATIC_HEADER(462u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_14, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_4(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_4());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_4 = {
    VADER_STATIC_HEADER(482u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_4, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_11(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_11());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_11 = {
    VADER_STATIC_HEADER(461u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_12(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_12());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_12 = {
    VADER_STATIC_HEADER(479u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_12, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_13(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_13());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_13 = {
    VADER_STATIC_HEADER(457u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_13, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_18(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_18());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_18 = {
    VADER_STATIC_HEADER(468u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_18, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_21(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_21());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_21 = {
    VADER_STATIC_HEADER(471u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_21, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_26(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_26());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_26 = {
    VADER_STATIC_HEADER(469u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_26, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_31(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_31());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_31 = {
    VADER_STATIC_HEADER(467u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_31, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_32(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_32());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_32 = {
    VADER_STATIC_HEADER(470u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_32, NULL,
};

vader_box_t vader_fn_tramp_vader_front_typecheck$check_in(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_front_typecheck$check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_front_typecheck$check_in = {
    VADER_STATIC_HEADER(510u), (void*) &vader_fn_tramp_vader_front_typecheck$check_in, NULL,
};

vader_box_t vader_fn_tramp_vader_front_typecheck$check_integral(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_front_typecheck$check_integral(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_front_typecheck$check_integral = {
    VADER_STATIC_HEADER(510u), (void*) &vader_fn_tramp_vader_front_typecheck$check_integral, NULL,
};

vader_box_t vader_fn_tramp_vader_front_typecheck$check_compare(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_front_typecheck$check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_front_typecheck$check_compare = {
    VADER_STATIC_HEADER(510u), (void*) &vader_fn_tramp_vader_front_typecheck$check_compare, NULL,
};

vader_box_t vader_fn_tramp_vader_front_typecheck$check_arith(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_front_typecheck$check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_front_typecheck$check_arith = {
    VADER_STATIC_HEADER(510u), (void*) &vader_fn_tramp_vader_front_typecheck$check_arith, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_76(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_front_typecheck_76(a0));
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_76 = {
    VADER_STATIC_HEADER(528u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_76, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_78(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_front_typecheck_78(a0));
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_78 = {
    VADER_STATIC_HEADER(528u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_78, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_79(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_79());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_79 = {
    VADER_STATIC_HEADER(458u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_79, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_80(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_80());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_80 = {
    VADER_STATIC_HEADER(458u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_80, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_lower_2(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_lower_2());
}

vader_fn_t vader_fn_static___lambda_vader_lower_2 = {
    VADER_STATIC_HEADER(483u), (void*) &vader_fn_tramp___lambda_vader_lower_2, NULL,
};

vader_box_t vader_fn_tramp_vader_lower$pending_fn_instance_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, vader_lower$pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_lower$pending_fn_instance_less = {
    VADER_STATIC_HEADER(518u), (void*) &vader_fn_tramp_vader_lower$pending_fn_instance_less, NULL,
};

vader_box_t vader_fn_tramp_vader_lower$is_defer(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, vader_lower$is_defer(a0));
}

vader_fn_t vader_fn_static_vader_lower$is_defer = {
    VADER_STATIC_HEADER(527u), (void*) &vader_fn_tramp_vader_lower$is_defer, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_lower_dce_2(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_lower_dce_2());
}

vader_fn_t vader_fn_static___lambda_vader_lower_dce_2 = {
    VADER_STATIC_HEADER(472u), (void*) &vader_fn_tramp___lambda_vader_lower_dce_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_emit_bytecode_14(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_emit_bytecode_14());
}

vader_fn_t vader_fn_static___lambda_vader_emit_bytecode_14 = {
    VADER_STATIC_HEADER(484u), (void*) &vader_fn_tramp___lambda_vader_emit_bytecode_14, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_support_profile_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_support_profile_0());
}

vader_fn_t vader_fn_static___lambda_vader_support_profile_0 = {
    VADER_STATIC_HEADER(489u), (void*) &vader_fn_tramp___lambda_vader_support_profile_0, NULL,
};

vader_box_t vader_fn_tramp_vader_support_profile$profiling$keep(void* env) {
    (void) env;
    vader_support_profile$profiling$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_vader_support_profile$profiling$keep = {
    VADER_STATIC_HEADER(476u), (void*) &vader_fn_tramp_vader_support_profile$profiling$keep, NULL,
};

vader_box_t vader_fn_tramp_vader_support_profile$profiler$keep(void* env) {
    (void) env;
    vader_support_profile$profiler$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_vader_support_profile$profiler$keep = {
    VADER_STATIC_HEADER(476u), (void*) &vader_fn_tramp_vader_support_profile$profiler$keep, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_project_1(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, __lambda_toolchain_project_1(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_toolchain_project_1 = {
    VADER_STATIC_HEADER(493u), (void*) &vader_fn_tramp___lambda_toolchain_project_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_emit_c_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_emit_c_0());
}

vader_fn_t vader_fn_static___lambda_vader_emit_c_0 = {
    VADER_STATIC_HEADER(459u), (void*) &vader_fn_tramp___lambda_vader_emit_c_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_emit_c_5(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_emit_c_5(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_emit_c_5 = {
    VADER_STATIC_HEADER(495u), (void*) &vader_fn_tramp___lambda_vader_emit_c_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_2(void* env) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_vm_2());
}

vader_fn_t vader_fn_static___lambda_vader_vm_2 = {
    VADER_STATIC_HEADER(474u), (void*) &vader_fn_tramp___lambda_vader_vm_2, NULL,
};

vader_box_t vader_fn_tramp_vader_vm$guest_threads$keep(void* env) {
    (void) env;
    vader_vm$guest_threads$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_vader_vm$guest_threads$keep = {
    VADER_STATIC_HEADER(476u), (void*) &vader_fn_tramp_vader_vm$guest_threads$keep, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_8(void* env) {
    (void) env;
    return __lambda_vader_vm_8();
}

vader_fn_t vader_fn_static___lambda_vader_vm_8 = {
    VADER_STATIC_HEADER(491u), (void*) &vader_fn_tramp___lambda_vader_vm_8, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_11(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_vm_11(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_vm_11 = {
    VADER_STATIC_HEADER(520u), (void*) &vader_fn_tramp___lambda_vader_vm_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_14(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_14(((int64_t) a0.payload.i));
    return vader_box_null();
}

vader_fn_t vader_fn_static___lambda_vader_vm_14 = {
    VADER_STATIC_HEADER(504u), (void*) &vader_fn_tramp___lambda_vader_vm_14, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_15(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_15(((int64_t) a0.payload.i));
    return vader_box_null();
}

vader_fn_t vader_fn_static___lambda_vader_vm_15 = {
    VADER_STATIC_HEADER(504u), (void*) &vader_fn_tramp___lambda_vader_vm_15, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_16(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_16(((int64_t) a0.payload.i));
    return vader_box_null();
}

vader_fn_t vader_fn_static___lambda_vader_vm_16 = {
    VADER_STATIC_HEADER(504u), (void*) &vader_fn_tramp___lambda_vader_vm_16, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_17(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_17(((int64_t) a0.payload.i));
    return vader_box_null();
}

vader_fn_t vader_fn_static___lambda_vader_vm_17 = {
    VADER_STATIC_HEADER(504u), (void*) &vader_fn_tramp___lambda_vader_vm_17, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_18(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_18(((int64_t) a0.payload.i));
    return vader_box_null();
}

vader_fn_t vader_fn_static___lambda_vader_vm_18 = {
    VADER_STATIC_HEADER(504u), (void*) &vader_fn_tramp___lambda_vader_vm_18, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_19(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_19(((int64_t) a0.payload.i));
    return vader_box_null();
}

vader_fn_t vader_fn_static___lambda_vader_vm_19 = {
    VADER_STATIC_HEADER(504u), (void*) &vader_fn_tramp___lambda_vader_vm_19, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_mul(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(540u, vader_front_comptime$op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_mul = {
    VADER_STATIC_HEADER(506u), (void*) &vader_fn_tramp_vader_front_comptime$op_mul, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_sub(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(540u, vader_front_comptime$op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_sub = {
    VADER_STATIC_HEADER(506u), (void*) &vader_fn_tramp_vader_front_comptime$op_sub, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_add(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(540u, vader_front_comptime$op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_add = {
    VADER_STATIC_HEADER(506u), (void*) &vader_fn_tramp_vader_front_comptime$op_add, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, vader_front_comptime$op_or(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_or = {
    VADER_STATIC_HEADER(492u), (void*) &vader_fn_tramp_vader_front_comptime$op_or, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, vader_front_comptime$op_and(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_and = {
    VADER_STATIC_HEADER(492u), (void*) &vader_fn_tramp_vader_front_comptime$op_and, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_bit_xor(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(540u, vader_front_comptime$op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_bit_xor = {
    VADER_STATIC_HEADER(506u), (void*) &vader_fn_tramp_vader_front_comptime$op_bit_xor, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_bit_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(540u, vader_front_comptime$op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_bit_or = {
    VADER_STATIC_HEADER(506u), (void*) &vader_fn_tramp_vader_front_comptime$op_bit_or, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_bit_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(540u, vader_front_comptime$op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_bit_and = {
    VADER_STATIC_HEADER(506u), (void*) &vader_fn_tramp_vader_front_comptime$op_bit_and, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_shr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(540u, vader_front_comptime$op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_shr = {
    VADER_STATIC_HEADER(506u), (void*) &vader_fn_tramp_vader_front_comptime$op_shr, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_shl(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(540u, vader_front_comptime$op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_shl = {
    VADER_STATIC_HEADER(506u), (void*) &vader_fn_tramp_vader_front_comptime$op_shl, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_mod(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(540u, vader_front_comptime$op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_mod = {
    VADER_STATIC_HEADER(506u), (void*) &vader_fn_tramp_vader_front_comptime$op_mod, NULL,
};

vader_box_t vader_fn_tramp_std_tty$no_color_set$keep(void* env) {
    (void) env;
    std_tty$no_color_set$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_std_tty$no_color_set$keep = {
    VADER_STATIC_HEADER(476u), (void*) &vader_fn_tramp_std_tty$no_color_set$keep, NULL,
};

vader_box_t vader_fn_tramp_std_tty$stderr_is_tty$keep(void* env) {
    (void) env;
    std_tty$stderr_is_tty$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_std_tty$stderr_is_tty$keep = {
    VADER_STATIC_HEADER(476u), (void*) &vader_fn_tramp_std_tty$stderr_is_tty$keep, NULL,
};

vader_box_t vader_fn_tramp_std_tty$stdout_is_tty$keep(void* env) {
    (void) env;
    std_tty$stdout_is_tty$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_std_tty$stdout_is_tty$keep = {
    VADER_STATIC_HEADER(476u), (void*) &vader_fn_tramp_std_tty$stdout_is_tty$keep, NULL,
};

vader_box_t vader_fn_tramp_toolchain_ast$ignore_node(void* env, vader_box_t a0) {
    (void) env;
    toolchain_ast$ignore_node(a0);
    return vader_box_null();
}

vader_fn_t vader_fn_static_toolchain_ast$ignore_node = {
    VADER_STATIC_HEADER(523u), (void*) &vader_fn_tramp_toolchain_ast$ignore_node, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_parser_4(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, __lambda_toolchain_parser_4(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_toolchain_parser_4 = {
    VADER_STATIC_HEADER(493u), (void*) &vader_fn_tramp___lambda_toolchain_parser_4, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_parser_5(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_string(536u, __lambda_toolchain_parser_5(a0.payload.s));
}

vader_fn_t vader_fn_static___lambda_toolchain_parser_5 = {
    VADER_STATIC_HEADER(494u), (void*) &vader_fn_tramp___lambda_toolchain_parser_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_parser_6(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_string(536u, __lambda_toolchain_parser_6(a0.payload.s));
}

vader_fn_t vader_fn_static___lambda_toolchain_parser_6 = {
    VADER_STATIC_HEADER(494u), (void*) &vader_fn_tramp___lambda_toolchain_parser_6, NULL,
};

vader_box_t vader_fn_tramp_vader_core_types$mk_struct(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_core_types$mk_struct(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static_vader_core_types$mk_struct = {
    VADER_STATIC_HEADER(512u), (void*) &vader_fn_tramp_vader_core_types$mk_struct, NULL,
};

vader_box_t vader_fn_tramp_vader_core_types$mk_trait(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_core_types$mk_trait(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static_vader_core_types$mk_trait = {
    VADER_STATIC_HEADER(512u), (void*) &vader_fn_tramp_vader_core_types$mk_trait, NULL,
};

vader_box_t vader_fn_tramp_vader_core_types$is_free_numeric(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, vader_core_types$is_free_numeric(a0));
}

vader_fn_t vader_fn_static_vader_core_types$is_free_numeric = {
    VADER_STATIC_HEADER(528u), (void*) &vader_fn_tramp_vader_core_types$is_free_numeric, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_core_types_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_core_types_0(a0));
}

vader_fn_t vader_fn_static___lambda_vader_core_types_0 = {
    VADER_STATIC_HEADER(528u), (void*) &vader_fn_tramp___lambda_vader_core_types_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_core_types_3(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_core_types_3(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_core_types_3 = {
    VADER_STATIC_HEADER(505u), (void*) &vader_fn_tramp___lambda_vader_core_types_3, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_core_types_6(void* env) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_core_types_6());
}

vader_fn_t vader_fn_static___lambda_vader_core_types_6 = {
    VADER_STATIC_HEADER(474u), (void*) &vader_fn_tramp___lambda_vader_core_types_6, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_stage_2(void* env) {
    (void) env;
    return vader_ref_box(__lambda_toolchain_stage_2());
}

vader_fn_t vader_fn_static___lambda_toolchain_stage_2 = {
    VADER_STATIC_HEADER(460u), (void*) &vader_fn_tramp___lambda_toolchain_stage_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_stage_3(void* env) {
    (void) env;
    return vader_ref_box(__lambda_toolchain_stage_3());
}

vader_fn_t vader_fn_static___lambda_toolchain_stage_3 = {
    VADER_STATIC_HEADER(458u), (void*) &vader_fn_tramp___lambda_toolchain_stage_3, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_stage_4(void* env) {
    (void) env;
    return vader_ref_box(__lambda_toolchain_stage_4());
}

vader_fn_t vader_fn_static___lambda_toolchain_stage_4 = {
    VADER_STATIC_HEADER(460u), (void*) &vader_fn_tramp___lambda_toolchain_stage_4, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_stage_5(void* env) {
    (void) env;
    return vader_ref_box(__lambda_toolchain_stage_5());
}

vader_fn_t vader_fn_static___lambda_toolchain_stage_5 = {
    VADER_STATIC_HEADER(458u), (void*) &vader_fn_tramp___lambda_toolchain_stage_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_stage_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_toolchain_stage_0());
}

vader_fn_t vader_fn_static___lambda_toolchain_stage_0 = {
    VADER_STATIC_HEADER(460u), (void*) &vader_fn_tramp___lambda_toolchain_stage_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_stage_1(void* env) {
    (void) env;
    return vader_ref_box(__lambda_toolchain_stage_1());
}

vader_fn_t vader_fn_static___lambda_toolchain_stage_1 = {
    VADER_STATIC_HEADER(458u), (void*) &vader_fn_tramp___lambda_toolchain_stage_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_support_fixpoint_0(void* env) {
    (void) env;
    return vader_box_i32(539u, __lambda_vader_support_fixpoint_0());
}

vader_fn_t vader_fn_static___lambda_vader_support_fixpoint_0 = {
    VADER_STATIC_HEADER(477u), (void*) &vader_fn_tramp___lambda_vader_support_fixpoint_0, NULL,
};

vader_box_t vader_fn_tramp_vader_midir$instruction_runs_code(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, vader_midir$instruction_runs_code(a0));
}

vader_fn_t vader_fn_static_vader_midir$instruction_runs_code = {
    VADER_STATIC_HEADER(531u), (void*) &vader_fn_tramp_vader_midir$instruction_runs_code, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_10(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_10());
}

vader_fn_t vader_fn_static___lambda_vader_midir_10 = {
    VADER_STATIC_HEADER(459u), (void*) &vader_fn_tramp___lambda_vader_midir_10, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_11(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_11());
}

vader_fn_t vader_fn_static___lambda_vader_midir_11 = {
    VADER_STATIC_HEADER(459u), (void*) &vader_fn_tramp___lambda_vader_midir_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_ranges_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_midir_ranges_0(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_midir_ranges_0 = {
    VADER_STATIC_HEADER(509u), (void*) &vader_fn_tramp___lambda_vader_midir_ranges_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_ranges_3(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_midir_ranges_3(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_midir_ranges_3 = {
    VADER_STATIC_HEADER(519u), (void*) &vader_fn_tramp___lambda_vader_midir_ranges_3, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_ranges_6(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_midir_ranges_6(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_midir_ranges_6 = {
    VADER_STATIC_HEADER(505u), (void*) &vader_fn_tramp___lambda_vader_midir_ranges_6, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_numbers_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, __lambda_std_numbers_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_numbers_0 = {
    VADER_STATIC_HEADER(493u), (void*) &vader_fn_tramp___lambda_std_numbers_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_0());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_0 = {
    VADER_STATIC_HEADER(485u), (void*) &vader_fn_tramp___lambda_vader_front_effects_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_1(void* env) {
    (void) env;
    return vader_box_i64(540u, __lambda_vader_front_effects_1());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_1 = {
    VADER_STATIC_HEADER(478u), (void*) &vader_fn_tramp___lambda_vader_front_effects_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_2(void* env) {
    (void) env;
    return vader_box_i64(540u, __lambda_vader_front_effects_2());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_2 = {
    VADER_STATIC_HEADER(478u), (void*) &vader_fn_tramp___lambda_vader_front_effects_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_8(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_8());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_8 = {
    VADER_STATIC_HEADER(487u), (void*) &vader_fn_tramp___lambda_vader_front_effects_8, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_9(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_9());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_9 = {
    VADER_STATIC_HEADER(466u), (void*) &vader_fn_tramp___lambda_vader_front_effects_9, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_12(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_12());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_12 = {
    VADER_STATIC_HEADER(485u), (void*) &vader_fn_tramp___lambda_vader_front_effects_12, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_13(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_13());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_13 = {
    VADER_STATIC_HEADER(485u), (void*) &vader_fn_tramp___lambda_vader_front_effects_13, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_14(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_14());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_14 = {
    VADER_STATIC_HEADER(465u), (void*) &vader_fn_tramp___lambda_vader_front_effects_14, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_17(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_17());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_17 = {
    VADER_STATIC_HEADER(459u), (void*) &vader_fn_tramp___lambda_vader_front_effects_17, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_18(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_18());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_18 = {
    VADER_STATIC_HEADER(460u), (void*) &vader_fn_tramp___lambda_vader_front_effects_18, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_19(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_19());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_19 = {
    VADER_STATIC_HEADER(464u), (void*) &vader_fn_tramp___lambda_vader_front_effects_19, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_20(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_20());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_20 = {
    VADER_STATIC_HEADER(486u), (void*) &vader_fn_tramp___lambda_vader_front_effects_20, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_21(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_21());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_21 = {
    VADER_STATIC_HEADER(459u), (void*) &vader_fn_tramp___lambda_vader_front_effects_21, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_31(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_31());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_31 = {
    VADER_STATIC_HEADER(463u), (void*) &vader_fn_tramp___lambda_vader_front_effects_31, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_38(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_front_effects_38(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_38 = {
    VADER_STATIC_HEADER(515u), (void*) &vader_fn_tramp___lambda_vader_front_effects_38, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_49(void* env, vader_box_t a0) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_49(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_49 = {
    VADER_STATIC_HEADER(516u), (void*) &vader_fn_tramp___lambda_vader_front_effects_49, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_50(void* env, vader_box_t a0) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_50(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_50 = {
    VADER_STATIC_HEADER(516u), (void*) &vader_fn_tramp___lambda_vader_front_effects_50, NULL,
};

vader_box_t vader_fn_tramp_vader_front_effects$is_kept(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, vader_front_effects$is_kept(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_front_effects$is_kept = {
    VADER_STATIC_HEADER(514u), (void*) &vader_fn_tramp_vader_front_effects$is_kept, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_59(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_front_effects_59(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_59 = {
    VADER_STATIC_HEADER(514u), (void*) &vader_fn_tramp___lambda_vader_front_effects_59, NULL,
};

vader_box_t vader_fn_tramp_vader_front_effects$modifies(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, vader_front_effects$modifies(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_front_effects$modifies = {
    VADER_STATIC_HEADER(514u), (void*) &vader_fn_tramp_vader_front_effects$modifies, NULL,
};

vader_box_t vader_fn_tramp_vader_front_effects$is_unknown(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, vader_front_effects$is_unknown(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_front_effects$is_unknown = {
    VADER_STATIC_HEADER(514u), (void*) &vader_fn_tramp_vader_front_effects$is_unknown, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_101(void* env, vader_box_t a0) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_101(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_101 = {
    VADER_STATIC_HEADER(516u), (void*) &vader_fn_tramp___lambda_vader_front_effects_101, NULL,
};

vader_box_t vader_fn_tramp_vader_front_effects$escapes(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(534u, vader_front_effects$escapes(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_front_effects$escapes = {
    VADER_STATIC_HEADER(514u), (void*) &vader_fn_tramp_vader_front_effects$escapes, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_146(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(534u, __lambda_vader_front_effects_146(((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_146 = {
    VADER_STATIC_HEADER(500u), (void*) &vader_fn_tramp___lambda_vader_front_effects_146, NULL,
};

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_0(void* env) {
    return vader_ref_box(__lambda_vader_front_typecheck_0(env));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_2(void* env) {
    return vader_ref_box(__lambda_vader_front_typecheck_2(env));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_5(void* env) {
    return vader_ref_box(__lambda_vader_front_typecheck_5(env));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_7(void* env) {
    return vader_ref_box(__lambda_vader_front_typecheck_7(env));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_9(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_9(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_16(void* env, vader_box_t a0) {
    return vader_box_i32(541u, (int32_t)(uint32_t) __lambda_vader_front_typecheck_16(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_24(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_24(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_27(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_27(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_29(void* env, vader_box_t a0) {
    return vader_box_i32(541u, (int32_t)(uint32_t) __lambda_vader_front_typecheck_29(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_33(void* env) {
    return __lambda_vader_front_typecheck_33(env);
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_35(void* env) {
    return __lambda_vader_front_typecheck_35(env);
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_38(void* env, vader_box_t a0) {
    return vader_box_i32(541u, (int32_t)(uint32_t) __lambda_vader_front_typecheck_38(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_40(void* env, vader_box_t a0) {
    return vader_box_i32(541u, (int32_t)(uint32_t) __lambda_vader_front_typecheck_40(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_42(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_front_typecheck_42(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_51(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_51(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_53(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_53(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_67(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_front_typecheck_67(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_lower_0(void* env, vader_box_t a0) {
    __lambda_vader_lower_0(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_8(void* env) {
    return vader_box_string(536u, __lambda_vader_lower_8(env));
}

vader_box_t vader_fn_lift___lambda_vader_lower_10(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_lower_10(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_lower_12(void* env, vader_box_t a0) {
    return vader_box_i32(541u, (int32_t)(uint32_t) __lambda_vader_lower_12(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_lower_14(void* env, vader_box_t a0) {
    __lambda_vader_lower_14(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_17(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_lower_17(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_lower_19(void* env) {
    return vader_ref_box(__lambda_vader_lower_19(env));
}

vader_box_t vader_fn_lift___lambda_vader_lower_23(void* env) {
    return vader_ref_box(__lambda_vader_lower_23(env));
}

vader_box_t vader_fn_lift___lambda_vader_lower_dce_0(void* env, vader_box_t a0) {
    __lambda_vader_lower_dce_0(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_dce_3(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_vader_lower_dce_3(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_dce_5(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_vader_lower_dce_5(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_dce_7(void* env, vader_box_t a0) {
    __lambda_vader_lower_dce_7(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_ir_0(void* env, vader_box_t a0) {
    __lambda_vader_lower_ir_0(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_ir_2(void* env, vader_box_t a0) {
    __lambda_vader_lower_ir_2(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___defer_std_fs_0(void* env) {
    __defer_std_fs_0(env);
    return vader_box_null();
}

vader_box_t vader_fn_lift___defer_std_fs_2(void* env) {
    __defer_std_fs_2(env);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_emit_c_1(void* env, vader_box_t a0) {
    return vader_ref_box(__lambda_vader_emit_c_1(env, ((int64_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_emit_c_3(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(534u, __lambda_vader_emit_c_3(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_vm_6(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(534u, __lambda_vader_vm_6(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_vm_9(void* env) {
    return vader_ref_box(__lambda_vader_vm_9(env));
}

vader_box_t vader_fn_lift___lambda_vader_vm_12(void* env) {
    return vader_ref_box(__lambda_vader_vm_12(env));
}

vader_box_t vader_fn_lift___lambda_vader_vm_20(void* env) {
    __lambda_vader_vm_20(env);
    return vader_box_null();
}

vader_box_t vader_fn_lift___defer_vader_vm_22(void* env) {
    __defer_vader_vm_22(env);
    return vader_box_null();
}

vader_box_t vader_fn_lift___defer_vader_vm_24(void* env) {
    __defer_vader_vm_24(env);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_front_comptime_2(void* env, vader_box_t a0) {
    return vader_box_i32(541u, (int32_t)(uint32_t) __lambda_vader_front_comptime_2(env, a0));
}

vader_box_t vader_fn_lift___lambda_toolchain_ast_2(void* env, vader_box_t a0) {
    return vader_box_i32(541u, (int32_t)(uint32_t) __lambda_toolchain_ast_2(env, a0));
}

vader_box_t vader_fn_lift___lambda_toolchain_parser_0(void* env, vader_box_t a0) {
    return vader_box_string(536u, __lambda_toolchain_parser_0(env, a0.payload.s));
}

vader_box_t vader_fn_lift___lambda_toolchain_parser_2(void* env, vader_box_t a0) {
    return vader_box_string(536u, __lambda_toolchain_parser_2(env, a0.payload.s));
}

vader_box_t vader_fn_lift___lambda_vader_core_types_1(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(534u, __lambda_vader_core_types_1(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_front_reach_0(void* env, vader_box_t a0) {
    return vader_box_i32(541u, (int32_t)(uint32_t) __lambda_vader_front_reach_0(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_support_fixpoint_1(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_support_fixpoint_1(env, ((int32_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_lower_optimise_0(void* env, vader_box_t a0) {
    __lambda_vader_lower_optimise_0(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_optimise_2(void* env, vader_box_t a0) {
    __lambda_vader_lower_optimise_2(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_0(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_midir_0(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_midir_4(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_midir_4(env, ((int64_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_midir_6(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_midir_6(env, ((int64_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_midir_8(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_midir_8(env, ((int64_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_midir_12(void* env, vader_box_t a0) {
    __lambda_vader_midir_12(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_14(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2) {
    __lambda_vader_midir_14(env, ((int32_t) a0.payload.i), a1.payload.obj, a2.payload.s);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_16(void* env, vader_box_t a0) {
    __lambda_vader_midir_16(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_18(void* env, vader_box_t a0) {
    __lambda_vader_midir_18(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_21(void* env, vader_box_t a0) {
    __lambda_vader_midir_21(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_23(void* env, vader_box_t a0) {
    __lambda_vader_midir_23(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_optimise_0(void* env, vader_box_t a0) {
    __lambda_vader_midir_optimise_0(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_optimise_2(void* env, vader_box_t a0) {
    __lambda_vader_midir_optimise_2(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___defer_std_runtime_scheduler_0(void* env) {
    __defer_std_runtime_scheduler_0(env);
    return vader_box_null();
}

vader_box_t vader_fn_lift___defer_std_runtime_scheduler_2(void* env) {
    __defer_std_runtime_scheduler_2(env);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_emit_c_ast_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(534u, __lambda_vader_emit_c_ast_0(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_3(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_front_effects_3(env, ((int32_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_36(void* env, vader_box_t a0) {
    return vader_box_i32(541u, (int32_t)(uint32_t) __lambda_vader_front_effects_36(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_45(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_front_effects_45(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_53(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_front_effects_53(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_57(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_front_effects_57(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_103(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_front_effects_103(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_132(void* env, vader_box_t a0) {
    return vader_box_bool(534u, __lambda_vader_front_effects_132(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_142(void* env, vader_box_t a0) {
    return vader_box_i32(541u, (int32_t)(uint32_t) __lambda_vader_front_effects_142(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_144(void* env, vader_box_t a0) {
    __lambda_vader_front_effects_144(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_front_dead__code_3(void* env, vader_box_t a0) {
    return vader_box_i32(541u, (int32_t)(uint32_t) __lambda_vader_front_dead__code_3(env, a0));
}

/* vtable dispatchers */
vader_box_t std_core$Iterator$next$$dispatch(vader_box_t recv) {
    switch (recv.tag) {
        case 942u: return std_core$Range$Iterator$next__i64(recv.payload.obj);
        case 951u: return std_string$StringChars$std_core$Iterator$next(recv.payload.obj);
        case 953u: return toolchain_ast$$genstate_decorator_sites$Iterator$next(recv.payload.obj);
        default: vader_unreachable("vtable miss in std_core$Iterator.next");
    }
    vader_unreachable("vtable miss in std_core$Iterator.next");
}

uint64_t std_core$Hash$hash$$dispatch(vader_box_t recv) {
    switch (recv.tag) {
        case 532u: return std_core$i8$Hash$hash(((int8_t) recv.payload.i));
        case 533u: return std_core$i16$Hash$hash(((int16_t) recv.payload.i));
        case 539u: return std_core$i32$Hash$hash(((int32_t) recv.payload.i));
        case 540u: return std_core$i64$Hash$hash(((int64_t) recv.payload.i));
        case 541u: return std_core$u8$Hash$hash(((uint8_t) recv.payload.i));
        case 542u: return std_core$u16$Hash$hash(((uint16_t) recv.payload.i));
        case 543u: return std_core$u32$Hash$hash(((uint32_t) recv.payload.i));
        case 544u: return std_core$u64$Hash$hash(((uint64_t) recv.payload.i));
        case 535u: return std_core$char$Hash$hash(((uint32_t) recv.payload.i));
        case 536u: return std_core$string$Hash$hash(recv.payload.s);
        case 1856u: return vader_vm$Scalar$std_core$Hash$hash(recv.payload.obj);
        case 1076u: return toolchain_span$Span$std_core$Hash$hash(recv.payload.obj);
        default: vader_unreachable("vtable miss in std_core$Hash.hash");
    }
    vader_unreachable("vtable miss in std_core$Hash.hash");
}

bool std_core$Equals$equals$$dispatch(vader_box_t recv, vader_box_t a0) {
    switch (recv.tag) {
        case 532u: return std_core$i8$Equals$equals$guard(((int8_t) recv.payload.i), a0);
        case 533u: return std_core$i16$Equals$equals$guard(((int16_t) recv.payload.i), a0);
        case 539u: return std_core$i32$Equals$equals$guard(((int32_t) recv.payload.i), a0);
        case 540u: return std_core$i64$Equals$equals$guard(((int64_t) recv.payload.i), a0);
        case 541u: return std_core$u8$Equals$equals$guard(((uint8_t) recv.payload.i), a0);
        case 542u: return std_core$u16$Equals$equals$guard(((uint16_t) recv.payload.i), a0);
        case 543u: return std_core$u32$Equals$equals$guard(((uint32_t) recv.payload.i), a0);
        case 544u: return std_core$u64$Equals$equals$guard(((uint64_t) recv.payload.i), a0);
        case 545u: return std_core$f32$Equals$equals$guard(((float) recv.payload.f), a0);
        case 546u: return std_core$f64$Equals$equals$guard(((double) recv.payload.f), a0);
        case 534u: return std_core$bool$Equals$equals$guard(recv.payload.b, a0);
        case 535u: return std_core$char$Equals$equals$guard(((uint32_t) recv.payload.i), a0);
        case 536u: return std_core$string$Equals$equals$guard(recv.payload.s, a0);
        case 1826u: return vader_support_target$Target$std_core$Equals$equals$guard(recv.payload.obj, a0);
        case 1856u: return vader_vm$Scalar$std_core$Equals$equals$guard(recv.payload.obj, a0);
        case 1076u: return toolchain_span$Span$std_core$Equals$equals$guard(recv.payload.obj, a0);
        default: vader_unreachable("vtable miss in std_core$Equals.equals");
    }
    vader_unreachable("vtable miss in std_core$Equals.equals");
}

vader_box_t toolchain_stage$Stage$describe$$dispatch(vader_box_t recv) {
    switch (recv.tag) {
        case 1476u: return vader_ref_box(vader_front_resolver$DisplayableStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1289u: return vader_ref_box(vader_emit_bytecode$CoalesceStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1290u: return vader_ref_box(vader_emit_bytecode$ConstFoldStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1291u: return vader_ref_box(vader_emit_bytecode$DeadStoresStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1296u: return vader_ref_box(vader_emit_bytecode$PeepholeStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1298u: return vader_ref_box(vader_emit_bytecode$PropagateStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1299u: return vader_ref_box(vader_emit_bytecode$ReturnLitStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1303u: return vader_ref_box(vader_emit_bytecode$StripSelfCopiesStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1806u: return vader_ref_box(vader_pipeline_check$DeadCode$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1807u: return vader_ref_box(vader_pipeline_check$DeepCopies$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1808u: return vader_ref_box(vader_pipeline_check$Frozen$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1811u: return vader_ref_box(vader_pipeline_check$TaskFaults$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1812u: return vader_ref_box(vader_pipeline_check$UnusedExports$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1813u: return vader_ref_box(vader_pipeline_check$UnusedImports$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1814u: return vader_ref_box(vader_pipeline_check$Widening$toolchain_stage$Stage$describe(recv.payload.obj));
        default: vader_unreachable("vtable miss in toolchain_stage$Stage.describe");
    }
    vader_unreachable("vtable miss in toolchain_stage$Stage.describe");
}

vader_box_t toolchain_stage$Stage$run$$dispatch(vader_box_t recv, vader_box_t a0) {
    switch (recv.tag) {
        case 1476u: return vader_ref_box(vader_front_resolver$DisplayableStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1289u: return vader_ref_box(vader_emit_bytecode$CoalesceStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1290u: return vader_ref_box(vader_emit_bytecode$ConstFoldStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1291u: return vader_ref_box(vader_emit_bytecode$DeadStoresStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1296u: return vader_ref_box(vader_emit_bytecode$PeepholeStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1298u: return vader_ref_box(vader_emit_bytecode$PropagateStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1299u: return vader_ref_box(vader_emit_bytecode$ReturnLitStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1303u: return vader_ref_box(vader_emit_bytecode$StripSelfCopiesStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1806u: return vader_ref_box(vader_pipeline_check$DeadCode$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1807u: return vader_ref_box(vader_pipeline_check$DeepCopies$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1808u: return vader_ref_box(vader_pipeline_check$Frozen$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1811u: return vader_ref_box(vader_pipeline_check$TaskFaults$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1812u: return vader_ref_box(vader_pipeline_check$UnusedExports$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1813u: return vader_ref_box(vader_pipeline_check$UnusedImports$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1814u: return vader_ref_box(vader_pipeline_check$Widening$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        default: vader_unreachable("vtable miss in toolchain_stage$Stage.run");
    }
    vader_unreachable("vtable miss in toolchain_stage$Stage.run");
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    vader_gc_top = &vader_global_frame;
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 26u, 536u);
    return vader_scheduler_exit((int) vader_bootstrap$main(__args));
}
