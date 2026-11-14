#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_std_console$stderr_is_console$keep(void* env) {
    (void) env;
    std_console$stderr_is_console$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_std_console$stderr_is_console$keep = {
    VADER_STATIC_HEADER(444u), (void*) &vader_fn_tramp_std_console$stderr_is_console$keep, NULL,
};

vader_box_t vader_fn_tramp_std_console$stdout_is_console$keep(void* env) {
    (void) env;
    std_console$stdout_is_console$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_std_console$stdout_is_console$keep = {
    VADER_STATIC_HEADER(444u), (void*) &vader_fn_tramp_std_console$stdout_is_console$keep, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_path_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, __lambda_std_path_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_path_0 = {
    VADER_STATIC_HEADER(461u), (void*) &vader_fn_tramp___lambda_std_path_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_path_1(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, __lambda_std_path_1(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_path_1 = {
    VADER_STATIC_HEADER(461u), (void*) &vader_fn_tramp___lambda_std_path_1, NULL,
};

vader_box_t vader_fn_tramp_std_string$compare_ascending(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, std_string$compare_ascending(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static_std_string$compare_ascending = {
    VADER_STATIC_HEADER(463u), (void*) &vader_fn_tramp_std_string$compare_ascending, NULL,
};

vader_box_t vader_fn_tramp_vader_support_diagnostics$diag_less_with_file(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, vader_support_diagnostics$diag_less_with_file(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_support_diagnostics$diag_less_with_file = {
    VADER_STATIC_HEADER(487u),
    (void*) &vader_fn_tramp_vader_support_diagnostics$diag_less_with_file, NULL,
};

vader_box_t vader_fn_tramp_vader_support_diagnostics$diag_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, vader_support_diagnostics$diag_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_support_diagnostics$diag_less = {
    VADER_STATIC_HEADER(487u), (void*) &vader_fn_tramp_vader_support_diagnostics$diag_less, NULL,
};

vader_box_t vader_fn_tramp_vader_front_resolver$declared_roots$keep(void* env) {
    (void) env;
    vader_front_resolver$declared_roots$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_vader_front_resolver$declared_roots$keep = {
    VADER_STATIC_HEADER(444u), (void*) &vader_fn_tramp_vader_front_resolver$declared_roots$keep,
    NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_resolver_0());
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_0 = {
    VADER_STATIC_HEADER(426u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_1(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_front_resolver_1(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_1 = {
    VADER_STATIC_HEADER(480u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_1, NULL,
};

vader_box_t vader_fn_tramp_vader_front_resolver$registered_toolchain$keep(void* env) {
    (void) env;
    vader_front_resolver$registered_toolchain$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_vader_front_resolver$registered_toolchain$keep = {
    VADER_STATIC_HEADER(444u),
    (void*) &vader_fn_tramp_vader_front_resolver$registered_toolchain$keep, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_6(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_resolver_6());
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_6 = {
    VADER_STATIC_HEADER(430u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_6, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_7(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_front_resolver_7(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_7 = {
    VADER_STATIC_HEADER(461u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_7, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_4(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_4());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_4 = {
    VADER_STATIC_HEADER(450u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_4, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_9(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_9());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_9 = {
    VADER_STATIC_HEADER(429u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_9, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_10(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_10());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_10 = {
    VADER_STATIC_HEADER(447u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_10, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_11(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_11());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_11 = {
    VADER_STATIC_HEADER(425u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_16(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_16());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_16 = {
    VADER_STATIC_HEADER(436u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_16, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_19(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_19());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_19 = {
    VADER_STATIC_HEADER(439u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_19, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_24(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_24());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_24 = {
    VADER_STATIC_HEADER(437u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_24, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_29(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_29());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_29 = {
    VADER_STATIC_HEADER(435u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_29, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_30(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_30());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_30 = {
    VADER_STATIC_HEADER(438u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_30, NULL,
};

vader_box_t vader_fn_tramp_vader_front_typecheck$check_in(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_front_typecheck$check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_front_typecheck$check_in = {
    VADER_STATIC_HEADER(478u), (void*) &vader_fn_tramp_vader_front_typecheck$check_in, NULL,
};

vader_box_t vader_fn_tramp_vader_front_typecheck$check_integral(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_front_typecheck$check_integral(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_front_typecheck$check_integral = {
    VADER_STATIC_HEADER(478u), (void*) &vader_fn_tramp_vader_front_typecheck$check_integral, NULL,
};

vader_box_t vader_fn_tramp_vader_front_typecheck$check_compare(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_front_typecheck$check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_front_typecheck$check_compare = {
    VADER_STATIC_HEADER(478u), (void*) &vader_fn_tramp_vader_front_typecheck$check_compare, NULL,
};

vader_box_t vader_fn_tramp_vader_front_typecheck$check_arith(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_front_typecheck$check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_front_typecheck$check_arith = {
    VADER_STATIC_HEADER(478u), (void*) &vader_fn_tramp_vader_front_typecheck$check_arith, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_67(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_front_typecheck_67(a0));
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_67 = {
    VADER_STATIC_HEADER(495u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_67, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_69(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_front_typecheck_69(a0));
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_69 = {
    VADER_STATIC_HEADER(495u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_69, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_70(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_70());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_70 = {
    VADER_STATIC_HEADER(426u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_70, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_71(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_71());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_71 = {
    VADER_STATIC_HEADER(426u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_71, NULL,
};

vader_box_t vader_fn_tramp_vader_core_types$mk_struct(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_core_types$mk_struct(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static_vader_core_types$mk_struct = {
    VADER_STATIC_HEADER(479u), (void*) &vader_fn_tramp_vader_core_types$mk_struct, NULL,
};

vader_box_t vader_fn_tramp_vader_core_types$mk_trait(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_core_types$mk_trait(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static_vader_core_types$mk_trait = {
    VADER_STATIC_HEADER(479u), (void*) &vader_fn_tramp_vader_core_types$mk_trait, NULL,
};

vader_box_t vader_fn_tramp_vader_core_types$is_free_numeric(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, vader_core_types$is_free_numeric(a0));
}

vader_fn_t vader_fn_static_vader_core_types$is_free_numeric = {
    VADER_STATIC_HEADER(495u), (void*) &vader_fn_tramp_vader_core_types$is_free_numeric, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_core_types_2(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_core_types_2(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_core_types_2 = {
    VADER_STATIC_HEADER(473u), (void*) &vader_fn_tramp___lambda_vader_core_types_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_core_types_5(void* env) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_core_types_5());
}

vader_fn_t vader_fn_static___lambda_vader_core_types_5 = {
    VADER_STATIC_HEADER(442u), (void*) &vader_fn_tramp___lambda_vader_core_types_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_lower_2(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_lower_2());
}

vader_fn_t vader_fn_static___lambda_vader_lower_2 = {
    VADER_STATIC_HEADER(451u), (void*) &vader_fn_tramp___lambda_vader_lower_2, NULL,
};

vader_box_t vader_fn_tramp_vader_lower$pending_fn_instance_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, vader_lower$pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_lower$pending_fn_instance_less = {
    VADER_STATIC_HEADER(485u), (void*) &vader_fn_tramp_vader_lower$pending_fn_instance_less, NULL,
};

vader_box_t vader_fn_tramp_vader_lower$is_defer(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, vader_lower$is_defer(a0));
}

vader_fn_t vader_fn_static_vader_lower$is_defer = {
    VADER_STATIC_HEADER(494u), (void*) &vader_fn_tramp_vader_lower$is_defer, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_lower_dce_2(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_lower_dce_2());
}

vader_fn_t vader_fn_static___lambda_vader_lower_dce_2 = {
    VADER_STATIC_HEADER(440u), (void*) &vader_fn_tramp___lambda_vader_lower_dce_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_emit_bytecode_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_emit_bytecode_0());
}

vader_fn_t vader_fn_static___lambda_vader_emit_bytecode_0 = {
    VADER_STATIC_HEADER(452u), (void*) &vader_fn_tramp___lambda_vader_emit_bytecode_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_support_profile_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_support_profile_0());
}

vader_fn_t vader_fn_static___lambda_vader_support_profile_0 = {
    VADER_STATIC_HEADER(457u), (void*) &vader_fn_tramp___lambda_vader_support_profile_0, NULL,
};

vader_box_t vader_fn_tramp_vader_support_profile$profiling$keep(void* env) {
    (void) env;
    vader_support_profile$profiling$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_vader_support_profile$profiling$keep = {
    VADER_STATIC_HEADER(444u), (void*) &vader_fn_tramp_vader_support_profile$profiling$keep, NULL,
};

vader_box_t vader_fn_tramp_vader_support_profile$profiler$keep(void* env) {
    (void) env;
    vader_support_profile$profiler$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_vader_support_profile$profiler$keep = {
    VADER_STATIC_HEADER(444u), (void*) &vader_fn_tramp_vader_support_profile$profiler$keep, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_emit_c_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_emit_c_0());
}

vader_fn_t vader_fn_static___lambda_vader_emit_c_0 = {
    VADER_STATIC_HEADER(427u), (void*) &vader_fn_tramp___lambda_vader_emit_c_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_emit_c_5(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_emit_c_5(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_emit_c_5 = {
    VADER_STATIC_HEADER(463u), (void*) &vader_fn_tramp___lambda_vader_emit_c_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_2(void* env) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_vm_2());
}

vader_fn_t vader_fn_static___lambda_vader_vm_2 = {
    VADER_STATIC_HEADER(442u), (void*) &vader_fn_tramp___lambda_vader_vm_2, NULL,
};

vader_box_t vader_fn_tramp_vader_vm$guest_threads$keep(void* env) {
    (void) env;
    vader_vm$guest_threads$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_vader_vm$guest_threads$keep = {
    VADER_STATIC_HEADER(444u), (void*) &vader_fn_tramp_vader_vm$guest_threads$keep, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_8(void* env) {
    (void) env;
    return __lambda_vader_vm_8();
}

vader_fn_t vader_fn_static___lambda_vader_vm_8 = {
    VADER_STATIC_HEADER(459u), (void*) &vader_fn_tramp___lambda_vader_vm_8, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_11(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_vm_11(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_vm_11 = {
    VADER_STATIC_HEADER(488u), (void*) &vader_fn_tramp___lambda_vader_vm_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_14(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_14(((int64_t) a0.payload.i));
    return vader_box_null();
}

vader_fn_t vader_fn_static___lambda_vader_vm_14 = {
    VADER_STATIC_HEADER(472u), (void*) &vader_fn_tramp___lambda_vader_vm_14, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_15(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_15(((int64_t) a0.payload.i));
    return vader_box_null();
}

vader_fn_t vader_fn_static___lambda_vader_vm_15 = {
    VADER_STATIC_HEADER(472u), (void*) &vader_fn_tramp___lambda_vader_vm_15, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_16(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_16(((int64_t) a0.payload.i));
    return vader_box_null();
}

vader_fn_t vader_fn_static___lambda_vader_vm_16 = {
    VADER_STATIC_HEADER(472u), (void*) &vader_fn_tramp___lambda_vader_vm_16, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_17(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_17(((int64_t) a0.payload.i));
    return vader_box_null();
}

vader_fn_t vader_fn_static___lambda_vader_vm_17 = {
    VADER_STATIC_HEADER(472u), (void*) &vader_fn_tramp___lambda_vader_vm_17, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_18(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_18(((int64_t) a0.payload.i));
    return vader_box_null();
}

vader_fn_t vader_fn_static___lambda_vader_vm_18 = {
    VADER_STATIC_HEADER(472u), (void*) &vader_fn_tramp___lambda_vader_vm_18, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_19(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_19(((int64_t) a0.payload.i));
    return vader_box_null();
}

vader_fn_t vader_fn_static___lambda_vader_vm_19 = {
    VADER_STATIC_HEADER(472u), (void*) &vader_fn_tramp___lambda_vader_vm_19, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_mul(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(507u, vader_front_comptime$op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_mul = {
    VADER_STATIC_HEADER(474u), (void*) &vader_fn_tramp_vader_front_comptime$op_mul, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_sub(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(507u, vader_front_comptime$op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_sub = {
    VADER_STATIC_HEADER(474u), (void*) &vader_fn_tramp_vader_front_comptime$op_sub, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_add(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(507u, vader_front_comptime$op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_add = {
    VADER_STATIC_HEADER(474u), (void*) &vader_fn_tramp_vader_front_comptime$op_add, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, vader_front_comptime$op_or(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_or = {
    VADER_STATIC_HEADER(460u), (void*) &vader_fn_tramp_vader_front_comptime$op_or, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, vader_front_comptime$op_and(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_and = {
    VADER_STATIC_HEADER(460u), (void*) &vader_fn_tramp_vader_front_comptime$op_and, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_bit_xor(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(507u, vader_front_comptime$op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_bit_xor = {
    VADER_STATIC_HEADER(474u), (void*) &vader_fn_tramp_vader_front_comptime$op_bit_xor, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_bit_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(507u, vader_front_comptime$op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_bit_or = {
    VADER_STATIC_HEADER(474u), (void*) &vader_fn_tramp_vader_front_comptime$op_bit_or, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_bit_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(507u, vader_front_comptime$op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_bit_and = {
    VADER_STATIC_HEADER(474u), (void*) &vader_fn_tramp_vader_front_comptime$op_bit_and, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_shr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(507u, vader_front_comptime$op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_shr = {
    VADER_STATIC_HEADER(474u), (void*) &vader_fn_tramp_vader_front_comptime$op_shr, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_shl(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(507u, vader_front_comptime$op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_shl = {
    VADER_STATIC_HEADER(474u), (void*) &vader_fn_tramp_vader_front_comptime$op_shl, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_mod(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(507u, vader_front_comptime$op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_mod = {
    VADER_STATIC_HEADER(474u), (void*) &vader_fn_tramp_vader_front_comptime$op_mod, NULL,
};

vader_box_t vader_fn_tramp_std_tty$no_color_set$keep(void* env) {
    (void) env;
    std_tty$no_color_set$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_std_tty$no_color_set$keep = {
    VADER_STATIC_HEADER(444u), (void*) &vader_fn_tramp_std_tty$no_color_set$keep, NULL,
};

vader_box_t vader_fn_tramp_std_tty$stderr_is_tty$keep(void* env) {
    (void) env;
    std_tty$stderr_is_tty$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_std_tty$stderr_is_tty$keep = {
    VADER_STATIC_HEADER(444u), (void*) &vader_fn_tramp_std_tty$stderr_is_tty$keep, NULL,
};

vader_box_t vader_fn_tramp_std_tty$stdout_is_tty$keep(void* env) {
    (void) env;
    std_tty$stdout_is_tty$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_std_tty$stdout_is_tty$keep = {
    VADER_STATIC_HEADER(444u), (void*) &vader_fn_tramp_std_tty$stdout_is_tty$keep, NULL,
};

vader_box_t vader_fn_tramp_toolchain_ast$ignore_node(void* env, vader_box_t a0) {
    (void) env;
    toolchain_ast$ignore_node(a0);
    return vader_box_null();
}

vader_fn_t vader_fn_static_toolchain_ast$ignore_node = {
    VADER_STATIC_HEADER(491u), (void*) &vader_fn_tramp_toolchain_ast$ignore_node, NULL,
};

vader_box_t vader_fn_tramp_vader_front_parser$specs_by_name$keep(void* env) {
    (void) env;
    vader_front_parser$specs_by_name$keep();
    return vader_box_null();
}

vader_fn_t vader_fn_static_vader_front_parser$specs_by_name$keep = {
    VADER_STATIC_HEADER(444u), (void*) &vader_fn_tramp_vader_front_parser$specs_by_name$keep, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_parser_4(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_string(503u, __lambda_vader_front_parser_4(a0.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_front_parser_4 = {
    VADER_STATIC_HEADER(462u), (void*) &vader_fn_tramp___lambda_vader_front_parser_4, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_parser_5(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_string(503u, __lambda_vader_front_parser_5(a0.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_front_parser_5 = {
    VADER_STATIC_HEADER(462u), (void*) &vader_fn_tramp___lambda_vader_front_parser_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_support_fixpoint_0(void* env) {
    (void) env;
    return vader_box_i32(506u, __lambda_vader_support_fixpoint_0());
}

vader_fn_t vader_fn_static___lambda_vader_support_fixpoint_0 = {
    VADER_STATIC_HEADER(445u), (void*) &vader_fn_tramp___lambda_vader_support_fixpoint_0, NULL,
};

vader_box_t vader_fn_tramp_vader_midir$instruction_runs_code(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, vader_midir$instruction_runs_code(a0));
}

vader_fn_t vader_fn_static_vader_midir$instruction_runs_code = {
    VADER_STATIC_HEADER(498u), (void*) &vader_fn_tramp_vader_midir$instruction_runs_code, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_10(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_10());
}

vader_fn_t vader_fn_static___lambda_vader_midir_10 = {
    VADER_STATIC_HEADER(427u), (void*) &vader_fn_tramp___lambda_vader_midir_10, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_11(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_11());
}

vader_fn_t vader_fn_static___lambda_vader_midir_11 = {
    VADER_STATIC_HEADER(427u), (void*) &vader_fn_tramp___lambda_vader_midir_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_ranges_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_midir_ranges_0(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_midir_ranges_0 = {
    VADER_STATIC_HEADER(477u), (void*) &vader_fn_tramp___lambda_vader_midir_ranges_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_ranges_3(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_midir_ranges_3(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_midir_ranges_3 = {
    VADER_STATIC_HEADER(486u), (void*) &vader_fn_tramp___lambda_vader_midir_ranges_3, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_ranges_6(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_midir_ranges_6(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_midir_ranges_6 = {
    VADER_STATIC_HEADER(473u), (void*) &vader_fn_tramp___lambda_vader_midir_ranges_6, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_numbers_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, __lambda_std_numbers_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_numbers_0 = {
    VADER_STATIC_HEADER(461u), (void*) &vader_fn_tramp___lambda_std_numbers_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_0());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_0 = {
    VADER_STATIC_HEADER(453u), (void*) &vader_fn_tramp___lambda_vader_front_effects_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_1(void* env) {
    (void) env;
    return vader_box_i64(507u, __lambda_vader_front_effects_1());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_1 = {
    VADER_STATIC_HEADER(446u), (void*) &vader_fn_tramp___lambda_vader_front_effects_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_2(void* env) {
    (void) env;
    return vader_box_i64(507u, __lambda_vader_front_effects_2());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_2 = {
    VADER_STATIC_HEADER(446u), (void*) &vader_fn_tramp___lambda_vader_front_effects_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_8(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_8());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_8 = {
    VADER_STATIC_HEADER(455u), (void*) &vader_fn_tramp___lambda_vader_front_effects_8, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_9(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_9());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_9 = {
    VADER_STATIC_HEADER(434u), (void*) &vader_fn_tramp___lambda_vader_front_effects_9, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_12(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_12());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_12 = {
    VADER_STATIC_HEADER(453u), (void*) &vader_fn_tramp___lambda_vader_front_effects_12, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_13(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_13());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_13 = {
    VADER_STATIC_HEADER(453u), (void*) &vader_fn_tramp___lambda_vader_front_effects_13, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_14(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_14());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_14 = {
    VADER_STATIC_HEADER(433u), (void*) &vader_fn_tramp___lambda_vader_front_effects_14, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_17(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_17());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_17 = {
    VADER_STATIC_HEADER(427u), (void*) &vader_fn_tramp___lambda_vader_front_effects_17, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_18(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_18());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_18 = {
    VADER_STATIC_HEADER(428u), (void*) &vader_fn_tramp___lambda_vader_front_effects_18, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_19(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_19());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_19 = {
    VADER_STATIC_HEADER(432u), (void*) &vader_fn_tramp___lambda_vader_front_effects_19, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_20(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_20());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_20 = {
    VADER_STATIC_HEADER(454u), (void*) &vader_fn_tramp___lambda_vader_front_effects_20, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_21(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_21());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_21 = {
    VADER_STATIC_HEADER(427u), (void*) &vader_fn_tramp___lambda_vader_front_effects_21, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_32(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_32());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_32 = {
    VADER_STATIC_HEADER(431u), (void*) &vader_fn_tramp___lambda_vader_front_effects_32, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_39(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_front_effects_39(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_39 = {
    VADER_STATIC_HEADER(482u), (void*) &vader_fn_tramp___lambda_vader_front_effects_39, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_50(void* env, vader_box_t a0) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_50(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_50 = {
    VADER_STATIC_HEADER(483u), (void*) &vader_fn_tramp___lambda_vader_front_effects_50, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_51(void* env, vader_box_t a0) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_51(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_51 = {
    VADER_STATIC_HEADER(483u), (void*) &vader_fn_tramp___lambda_vader_front_effects_51, NULL,
};

vader_box_t vader_fn_tramp_vader_front_effects$is_kept(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, vader_front_effects$is_kept(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_front_effects$is_kept = {
    VADER_STATIC_HEADER(481u), (void*) &vader_fn_tramp_vader_front_effects$is_kept, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_60(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_front_effects_60(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_60 = {
    VADER_STATIC_HEADER(481u), (void*) &vader_fn_tramp___lambda_vader_front_effects_60, NULL,
};

vader_box_t vader_fn_tramp_vader_front_effects$modifies(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, vader_front_effects$modifies(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_front_effects$modifies = {
    VADER_STATIC_HEADER(481u), (void*) &vader_fn_tramp_vader_front_effects$modifies, NULL,
};

vader_box_t vader_fn_tramp_vader_front_effects$is_unknown(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, vader_front_effects$is_unknown(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_front_effects$is_unknown = {
    VADER_STATIC_HEADER(481u), (void*) &vader_fn_tramp_vader_front_effects$is_unknown, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_102(void* env, vader_box_t a0) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_102(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_102 = {
    VADER_STATIC_HEADER(483u), (void*) &vader_fn_tramp___lambda_vader_front_effects_102, NULL,
};

vader_box_t vader_fn_tramp_vader_front_effects$escapes(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(501u, vader_front_effects$escapes(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_front_effects$escapes = {
    VADER_STATIC_HEADER(481u), (void*) &vader_fn_tramp_vader_front_effects$escapes, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_147(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(501u, __lambda_vader_front_effects_147(((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_147 = {
    VADER_STATIC_HEADER(468u), (void*) &vader_fn_tramp___lambda_vader_front_effects_147, NULL,
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

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_14(void* env, vader_box_t a0) {
    return vader_box_i32(508u, (int32_t)(uint32_t) __lambda_vader_front_typecheck_14(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_22(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_22(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_25(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_25(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_27(void* env, vader_box_t a0) {
    return vader_box_i32(508u, (int32_t)(uint32_t) __lambda_vader_front_typecheck_27(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_31(void* env) {
    return __lambda_vader_front_typecheck_31(env);
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_33(void* env) {
    return __lambda_vader_front_typecheck_33(env);
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_36(void* env, vader_box_t a0) {
    return vader_box_i32(508u, (int32_t)(uint32_t) __lambda_vader_front_typecheck_36(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_38(void* env, vader_box_t a0) {
    return vader_box_i32(508u, (int32_t)(uint32_t) __lambda_vader_front_typecheck_38(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_40(void* env, vader_box_t a0) {
    return vader_box_bool(501u, __lambda_vader_front_typecheck_40(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_43(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_43(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_45(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_45(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_58(void* env, vader_box_t a0) {
    return vader_box_bool(501u, __lambda_vader_front_typecheck_58(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_core_types_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(501u, __lambda_vader_core_types_0(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_lower_0(void* env, vader_box_t a0) {
    __lambda_vader_lower_0(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_6(void* env) {
    return vader_box_string(503u, __lambda_vader_lower_6(env));
}

vader_box_t vader_fn_lift___lambda_vader_lower_8(void* env, vader_box_t a0) {
    return vader_box_i32(508u, (int32_t)(uint32_t) __lambda_vader_lower_8(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_lower_11(void* env, vader_box_t a0) {
    return vader_box_bool(501u, __lambda_vader_lower_11(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_lower_13(void* env) {
    return vader_ref_box(__lambda_vader_lower_13(env));
}

vader_box_t vader_fn_lift___lambda_vader_lower_15(void* env) {
    return vader_ref_box(__lambda_vader_lower_15(env));
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
    return vader_box_bool(501u, __lambda_vader_emit_c_3(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_vm_6(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(501u, __lambda_vader_vm_6(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
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

vader_box_t vader_fn_lift___lambda_vader_front_comptime_0(void* env, vader_box_t a0) {
    return vader_box_i32(508u, (int32_t)(uint32_t) __lambda_vader_front_comptime_0(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_parser_0(void* env, vader_box_t a0) {
    return vader_box_string(503u, __lambda_vader_front_parser_0(env, a0.payload.s));
}

vader_box_t vader_fn_lift___lambda_vader_front_parser_2(void* env, vader_box_t a0) {
    return vader_box_string(503u, __lambda_vader_front_parser_2(env, a0.payload.s));
}

vader_box_t vader_fn_lift___lambda_vader_front_reach_0(void* env, vader_box_t a0) {
    return vader_box_i32(508u, (int32_t)(uint32_t) __lambda_vader_front_reach_0(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_support_fixpoint_1(void* env, vader_box_t a0) {
    return vader_box_bool(501u, __lambda_vader_support_fixpoint_1(env, ((int32_t) a0.payload.i)));
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
    return vader_box_bool(501u, __lambda_vader_midir_0(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_midir_4(void* env, vader_box_t a0) {
    return vader_box_bool(501u, __lambda_vader_midir_4(env, ((int64_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_midir_6(void* env, vader_box_t a0) {
    return vader_box_bool(501u, __lambda_vader_midir_6(env, ((int64_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_midir_8(void* env, vader_box_t a0) {
    return vader_box_bool(501u, __lambda_vader_midir_8(env, ((int64_t) a0.payload.i)));
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
    return vader_box_bool(501u, __lambda_vader_emit_c_ast_0(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_front_dead__code_2(void* env, vader_box_t a0) {
    return vader_box_i32(508u, (int32_t)(uint32_t) __lambda_vader_front_dead__code_2(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_3(void* env, vader_box_t a0) {
    return vader_box_bool(501u, __lambda_vader_front_effects_3(env, ((int32_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_37(void* env, vader_box_t a0) {
    return vader_box_i32(508u, (int32_t)(uint32_t) __lambda_vader_front_effects_37(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_46(void* env, vader_box_t a0) {
    return vader_box_bool(501u, __lambda_vader_front_effects_46(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_54(void* env, vader_box_t a0) {
    return vader_box_bool(501u, __lambda_vader_front_effects_54(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_58(void* env, vader_box_t a0) {
    return vader_box_bool(501u, __lambda_vader_front_effects_58(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_104(void* env, vader_box_t a0) {
    return vader_box_bool(501u, __lambda_vader_front_effects_104(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_133(void* env, vader_box_t a0) {
    return vader_box_bool(501u, __lambda_vader_front_effects_133(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_143(void* env, vader_box_t a0) {
    return vader_box_i32(508u, (int32_t)(uint32_t) __lambda_vader_front_effects_143(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_145(void* env, vader_box_t a0) {
    __lambda_vader_front_effects_145(env, a0);
    return vader_box_null();
}

/* vtable dispatchers */
uint64_t std_core$Hash$hash$$dispatch(vader_box_t recv) {
    switch (recv.tag) {
        case 503u: return std_core$string$Hash$hash$$wrapper(recv.payload.s);
        case 499u: return std_core$i8$Hash$hash(((int8_t) recv.payload.i));
        case 500u: return std_core$i16$Hash$hash(((int16_t) recv.payload.i));
        case 506u: return std_core$i32$Hash$hash(((int32_t) recv.payload.i));
        case 507u: return std_core$i64$Hash$hash(((int64_t) recv.payload.i));
        case 508u: return std_core$u8$Hash$hash(((uint8_t) recv.payload.i));
        case 509u: return std_core$u16$Hash$hash(((uint16_t) recv.payload.i));
        case 510u: return std_core$u32$Hash$hash(((uint32_t) recv.payload.i));
        case 511u: return std_core$u64$Hash$hash(((uint64_t) recv.payload.i));
        case 502u: return std_core$char$Hash$hash(((uint32_t) recv.payload.i));
        case 1745u: return vader_vm$Scalar$std_core$Hash$hash(recv.payload.obj);
        case 977u: return toolchain_span$Span$std_core$Hash$hash(recv.payload.obj);
        default: vader_unreachable("vtable miss in std_core$Hash.hash");
    }
    vader_unreachable("vtable miss in std_core$Hash.hash");
}

bool std_core$Equals$equals$$dispatch(vader_box_t recv, vader_box_t a0) {
    switch (recv.tag) {
        case 499u: return std_core$i8$Equals$equals$guard(((int8_t) recv.payload.i), a0);
        case 500u: return std_core$i16$Equals$equals$guard(((int16_t) recv.payload.i), a0);
        case 506u: return std_core$i32$Equals$equals$guard(((int32_t) recv.payload.i), a0);
        case 507u: return std_core$i64$Equals$equals$guard(((int64_t) recv.payload.i), a0);
        case 508u: return std_core$u8$Equals$equals$guard(((uint8_t) recv.payload.i), a0);
        case 509u: return std_core$u16$Equals$equals$guard(((uint16_t) recv.payload.i), a0);
        case 510u: return std_core$u32$Equals$equals$guard(((uint32_t) recv.payload.i), a0);
        case 511u: return std_core$u64$Equals$equals$guard(((uint64_t) recv.payload.i), a0);
        case 512u: return std_core$f32$Equals$equals$guard(((float) recv.payload.f), a0);
        case 513u: return std_core$f64$Equals$equals$guard(((double) recv.payload.f), a0);
        case 501u: return std_core$bool$Equals$equals$guard(recv.payload.b, a0);
        case 502u: return std_core$char$Equals$equals$guard(((uint32_t) recv.payload.i), a0);
        case 503u: return std_core$string$Equals$equals$guard(recv.payload.s, a0);
        case 1715u: return vader_support_target$Target$std_core$Equals$equals$guard(recv.payload.obj, a0);
        case 1745u: return vader_vm$Scalar$std_core$Equals$equals$guard(recv.payload.obj, a0);
        case 977u: return toolchain_span$Span$std_core$Equals$equals$guard(recv.payload.obj, a0);
        default: vader_unreachable("vtable miss in std_core$Equals.equals");
    }
    vader_unreachable("vtable miss in std_core$Equals.equals");
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    vader_gc_top = &vader_global_frame;
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 26u, 503u);
    return vader_scheduler_exit((int) vader_bootstrap$main(__args));
}
