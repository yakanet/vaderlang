#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_std_console$stderr_is_console$keep(void* env) {
    (void) env;
    std_console$stderr_is_console$keep();
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_std_console$stderr_is_console$keep = {
    VADER_STATIC_HEADER(529u), (void*) &vader_fn_tramp_std_console$stderr_is_console$keep, NULL,
};

vader_box_t vader_fn_tramp_std_console$stdout_is_console$keep(void* env) {
    (void) env;
    std_console$stdout_is_console$keep();
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_std_console$stdout_is_console$keep = {
    VADER_STATIC_HEADER(529u), (void*) &vader_fn_tramp_std_console$stdout_is_console$keep, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_path_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, __lambda_std_path_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_path_0 = {
    VADER_STATIC_HEADER(547u), (void*) &vader_fn_tramp___lambda_std_path_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_path_1(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, __lambda_std_path_1(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_path_1 = {
    VADER_STATIC_HEADER(547u), (void*) &vader_fn_tramp___lambda_std_path_1, NULL,
};

vader_box_t vader_fn_tramp_std_string$compare_ascending(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, std_string$compare_ascending(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static_std_string$compare_ascending = {
    VADER_STATIC_HEADER(550u), (void*) &vader_fn_tramp_std_string$compare_ascending, NULL,
};

vader_box_t vader_fn_tramp_toolchain_diagnostics$diag_less_with_file(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, toolchain_diagnostics$diag_less_with_file(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_toolchain_diagnostics$diag_less_with_file = {
    VADER_STATIC_HEADER(568u), (void*) &vader_fn_tramp_toolchain_diagnostics$diag_less_with_file,
    NULL,
};

vader_box_t vader_fn_tramp_toolchain_diagnostics$diag_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, toolchain_diagnostics$diag_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_toolchain_diagnostics$diag_less = {
    VADER_STATIC_HEADER(568u), (void*) &vader_fn_tramp_toolchain_diagnostics$diag_less, NULL,
};

vader_box_t vader_fn_tramp_vader_front_resolver$toolchain_runtime$keep(void* env) {
    (void) env;
    vader_front_resolver$toolchain_runtime$keep();
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_vader_front_resolver$toolchain_runtime$keep = {
    VADER_STATIC_HEADER(529u), (void*) &vader_fn_tramp_vader_front_resolver$toolchain_runtime$keep,
    NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_5(void* env, vader_box_t a0) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_resolver_5(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_5 = {
    VADER_STATIC_HEADER(604u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_5, NULL,
};

vader_box_t vader_fn_tramp_vader_front_resolver$declared_roots$keep(void* env) {
    (void) env;
    vader_front_resolver$declared_roots$keep();
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_vader_front_resolver$declared_roots$keep = {
    VADER_STATIC_HEADER(529u), (void*) &vader_fn_tramp_vader_front_resolver$declared_roots$keep,
    NULL,
};

vader_box_t vader_fn_tramp_vader_front_resolver$driver_stages$keep(void* env) {
    (void) env;
    vader_front_resolver$driver_stages$keep();
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_vader_front_resolver$driver_stages$keep = {
    VADER_STATIC_HEADER(529u), (void*) &vader_fn_tramp_vader_front_resolver$driver_stages$keep,
    NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_20(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_front_resolver_20(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_20 = {
    VADER_STATIC_HEADER(599u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_20, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_28(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_resolver_28());
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_28 = {
    VADER_STATIC_HEADER(511u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_28, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_30(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_resolver_30());
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_30 = {
    VADER_STATIC_HEADER(515u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_30, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_10(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_10());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_10 = {
    VADER_STATIC_HEADER(536u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_10, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_13(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_13());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_13 = {
    VADER_STATIC_HEADER(514u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_13, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_14(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_14());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_14 = {
    VADER_STATIC_HEADER(533u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_14, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_15(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_15());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_15 = {
    VADER_STATIC_HEADER(510u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_15, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_22(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_22());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_22 = {
    VADER_STATIC_HEADER(521u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_22, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_23(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_23());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_23 = {
    VADER_STATIC_HEADER(524u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_23, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_28(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_28());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_28 = {
    VADER_STATIC_HEADER(522u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_28, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_31(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_31());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_31 = {
    VADER_STATIC_HEADER(520u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_31, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_32(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_32());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_32 = {
    VADER_STATIC_HEADER(523u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_32, NULL,
};

vader_box_t vader_fn_tramp_vader_front_typecheck$check_in(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_front_typecheck$check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_front_typecheck$check_in = {
    VADER_STATIC_HEADER(567u), (void*) &vader_fn_tramp_vader_front_typecheck$check_in, NULL,
};

vader_box_t vader_fn_tramp_vader_front_typecheck$check_integral(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_front_typecheck$check_integral(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_front_typecheck$check_integral = {
    VADER_STATIC_HEADER(567u), (void*) &vader_fn_tramp_vader_front_typecheck$check_integral, NULL,
};

vader_box_t vader_fn_tramp_vader_front_typecheck$check_compare(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_front_typecheck$check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_front_typecheck$check_compare = {
    VADER_STATIC_HEADER(567u), (void*) &vader_fn_tramp_vader_front_typecheck$check_compare, NULL,
};

vader_box_t vader_fn_tramp_vader_front_typecheck$check_arith(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_front_typecheck$check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_front_typecheck$check_arith = {
    VADER_STATIC_HEADER(567u), (void*) &vader_fn_tramp_vader_front_typecheck$check_arith, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_82(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_front_typecheck_82(a0));
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_82 = {
    VADER_STATIC_HEADER(618u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_82, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_84(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_front_typecheck_84(a0));
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_84 = {
    VADER_STATIC_HEADER(618u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_84, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_85(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_85());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_85 = {
    VADER_STATIC_HEADER(511u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_85, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_typecheck_86(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_typecheck_86());
}

vader_fn_t vader_fn_static___lambda_vader_front_typecheck_86 = {
    VADER_STATIC_HEADER(511u), (void*) &vader_fn_tramp___lambda_vader_front_typecheck_86, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_lower_2(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_lower_2());
}

vader_fn_t vader_fn_static___lambda_vader_lower_2 = {
    VADER_STATIC_HEADER(537u), (void*) &vader_fn_tramp___lambda_vader_lower_2, NULL,
};

vader_box_t vader_fn_tramp_vader_lower$pending_fn_instance_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, vader_lower$pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_lower$pending_fn_instance_less = {
    VADER_STATIC_HEADER(608u), (void*) &vader_fn_tramp_vader_lower$pending_fn_instance_less, NULL,
};

vader_box_t vader_fn_tramp_vader_lower$is_defer(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, vader_lower$is_defer(a0));
}

vader_fn_t vader_fn_static_vader_lower$is_defer = {
    VADER_STATIC_HEADER(617u), (void*) &vader_fn_tramp_vader_lower$is_defer, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_lower_dce_2(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_lower_dce_2());
}

vader_fn_t vader_fn_static___lambda_vader_lower_dce_2 = {
    VADER_STATIC_HEADER(525u), (void*) &vader_fn_tramp___lambda_vader_lower_dce_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_emit_bytecode_19(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_emit_bytecode_19());
}

vader_fn_t vader_fn_static___lambda_vader_emit_bytecode_19 = {
    VADER_STATIC_HEADER(538u), (void*) &vader_fn_tramp___lambda_vader_emit_bytecode_19, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_support_profile_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_support_profile_0());
}

vader_fn_t vader_fn_static___lambda_vader_support_profile_0 = {
    VADER_STATIC_HEADER(543u), (void*) &vader_fn_tramp___lambda_vader_support_profile_0, NULL,
};

vader_box_t vader_fn_tramp_vader_support_profile$profiler$keep(void* env) {
    (void) env;
    vader_support_profile$profiler$keep();
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_vader_support_profile$profiler$keep = {
    VADER_STATIC_HEADER(529u), (void*) &vader_fn_tramp_vader_support_profile$profiler$keep, NULL,
};

vader_box_t vader_fn_tramp_vader_support_profile$profiling$keep(void* env) {
    (void) env;
    vader_support_profile$profiling$keep();
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_vader_support_profile$profiling$keep = {
    VADER_STATIC_HEADER(529u), (void*) &vader_fn_tramp_vader_support_profile$profiling$keep, NULL,
};

vader_box_t vader_fn_tramp_vader_support_profile$build_log$keep(void* env) {
    (void) env;
    vader_support_profile$build_log$keep();
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_vader_support_profile$build_log$keep = {
    VADER_STATIC_HEADER(529u), (void*) &vader_fn_tramp_vader_support_profile$build_log$keep, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_project_1(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, __lambda_toolchain_project_1(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_toolchain_project_1 = {
    VADER_STATIC_HEADER(547u), (void*) &vader_fn_tramp___lambda_toolchain_project_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_emit_c_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_emit_c_0());
}

vader_fn_t vader_fn_static___lambda_vader_emit_c_0 = {
    VADER_STATIC_HEADER(512u), (void*) &vader_fn_tramp___lambda_vader_emit_c_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_emit_c_5(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_emit_c_5(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_emit_c_5 = {
    VADER_STATIC_HEADER(550u), (void*) &vader_fn_tramp___lambda_vader_emit_c_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_2(void* env) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_vm_2());
}

vader_fn_t vader_fn_static___lambda_vader_vm_2 = {
    VADER_STATIC_HEADER(527u), (void*) &vader_fn_tramp___lambda_vader_vm_2, NULL,
};

vader_box_t vader_fn_tramp_vader_vm$guest_threads$keep(void* env) {
    (void) env;
    vader_vm$guest_threads$keep();
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_vader_vm$guest_threads$keep = {
    VADER_STATIC_HEADER(529u), (void*) &vader_fn_tramp_vader_vm$guest_threads$keep, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_8(void* env) {
    (void) env;
    return __lambda_vader_vm_8();
}

vader_fn_t vader_fn_static___lambda_vader_vm_8 = {
    VADER_STATIC_HEADER(545u), (void*) &vader_fn_tramp___lambda_vader_vm_8, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_11(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_vm_11(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_vm_11 = {
    VADER_STATIC_HEADER(610u), (void*) &vader_fn_tramp___lambda_vader_vm_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_14(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_14(((int64_t) a0.payload.i));
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static___lambda_vader_vm_14 = {
    VADER_STATIC_HEADER(559u), (void*) &vader_fn_tramp___lambda_vader_vm_14, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_15(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_15(((int64_t) a0.payload.i));
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static___lambda_vader_vm_15 = {
    VADER_STATIC_HEADER(559u), (void*) &vader_fn_tramp___lambda_vader_vm_15, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_16(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_16(((int64_t) a0.payload.i));
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static___lambda_vader_vm_16 = {
    VADER_STATIC_HEADER(559u), (void*) &vader_fn_tramp___lambda_vader_vm_16, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_17(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_17(((int64_t) a0.payload.i));
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static___lambda_vader_vm_17 = {
    VADER_STATIC_HEADER(559u), (void*) &vader_fn_tramp___lambda_vader_vm_17, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_18(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_18(((int64_t) a0.payload.i));
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static___lambda_vader_vm_18 = {
    VADER_STATIC_HEADER(559u), (void*) &vader_fn_tramp___lambda_vader_vm_18, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_19(void* env, vader_box_t a0) {
    (void) env;
    __lambda_vader_vm_19(((int64_t) a0.payload.i));
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static___lambda_vader_vm_19 = {
    VADER_STATIC_HEADER(559u), (void*) &vader_fn_tramp___lambda_vader_vm_19, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_comptime_4(void* env, vader_box_t a0) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_comptime_4(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_comptime_4 = {
    VADER_STATIC_HEADER(607u), (void*) &vader_fn_tramp___lambda_vader_front_comptime_4, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_comptime_7(void* env, vader_box_t a0) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_comptime_7(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_comptime_7 = {
    VADER_STATIC_HEADER(607u), (void*) &vader_fn_tramp___lambda_vader_front_comptime_7, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$resolved_interface(void* env, vader_box_t a0) {
    (void) env;
    return vader_front_comptime$resolved_interface(a0);
}

vader_fn_t vader_fn_static_vader_front_comptime$resolved_interface = {
    VADER_STATIC_HEADER(620u), (void*) &vader_fn_tramp_vader_front_comptime$resolved_interface,
    NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_mul(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(633u, vader_front_comptime$op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_mul = {
    VADER_STATIC_HEADER(561u), (void*) &vader_fn_tramp_vader_front_comptime$op_mul, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_sub(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(633u, vader_front_comptime$op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_sub = {
    VADER_STATIC_HEADER(561u), (void*) &vader_fn_tramp_vader_front_comptime$op_sub, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_add(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(633u, vader_front_comptime$op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_add = {
    VADER_STATIC_HEADER(561u), (void*) &vader_fn_tramp_vader_front_comptime$op_add, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, vader_front_comptime$op_or(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_or = {
    VADER_STATIC_HEADER(546u), (void*) &vader_fn_tramp_vader_front_comptime$op_or, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, vader_front_comptime$op_and(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_and = {
    VADER_STATIC_HEADER(546u), (void*) &vader_fn_tramp_vader_front_comptime$op_and, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_bit_xor(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(633u, vader_front_comptime$op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_bit_xor = {
    VADER_STATIC_HEADER(561u), (void*) &vader_fn_tramp_vader_front_comptime$op_bit_xor, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_bit_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(633u, vader_front_comptime$op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_bit_or = {
    VADER_STATIC_HEADER(561u), (void*) &vader_fn_tramp_vader_front_comptime$op_bit_or, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_bit_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(633u, vader_front_comptime$op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_bit_and = {
    VADER_STATIC_HEADER(561u), (void*) &vader_fn_tramp_vader_front_comptime$op_bit_and, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_shr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(633u, vader_front_comptime$op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_shr = {
    VADER_STATIC_HEADER(561u), (void*) &vader_fn_tramp_vader_front_comptime$op_shr, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_shl(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(633u, vader_front_comptime$op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_shl = {
    VADER_STATIC_HEADER(561u), (void*) &vader_fn_tramp_vader_front_comptime$op_shl, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_mod(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(633u, vader_front_comptime$op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_mod = {
    VADER_STATIC_HEADER(561u), (void*) &vader_fn_tramp_vader_front_comptime$op_mod, NULL,
};

vader_box_t vader_fn_tramp_std_task$started$keep(void* env) {
    (void) env;
    std_task$started$keep();
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_std_task$started$keep = {
    VADER_STATIC_HEADER(529u), (void*) &vader_fn_tramp_std_task$started$keep, NULL,
};

vader_box_t vader_fn_tramp_std_tty$no_color_set$keep(void* env) {
    (void) env;
    std_tty$no_color_set$keep();
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_std_tty$no_color_set$keep = {
    VADER_STATIC_HEADER(529u), (void*) &vader_fn_tramp_std_tty$no_color_set$keep, NULL,
};

vader_box_t vader_fn_tramp_std_tty$stderr_is_tty$keep(void* env) {
    (void) env;
    std_tty$stderr_is_tty$keep();
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_std_tty$stderr_is_tty$keep = {
    VADER_STATIC_HEADER(529u), (void*) &vader_fn_tramp_std_tty$stderr_is_tty$keep, NULL,
};

vader_box_t vader_fn_tramp_std_tty$stdout_is_tty$keep(void* env) {
    (void) env;
    std_tty$stdout_is_tty$keep();
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_std_tty$stdout_is_tty$keep = {
    VADER_STATIC_HEADER(529u), (void*) &vader_fn_tramp_std_tty$stdout_is_tty$keep, NULL,
};

vader_box_t vader_fn_tramp_toolchain_ast$ignore_node(void* env, vader_box_t a0) {
    (void) env;
    toolchain_ast$ignore_node(a0);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_ast$ignore_node = {
    VADER_STATIC_HEADER(613u), (void*) &vader_fn_tramp_toolchain_ast$ignore_node, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_parser_4(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, __lambda_toolchain_parser_4(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_toolchain_parser_4 = {
    VADER_STATIC_HEADER(547u), (void*) &vader_fn_tramp___lambda_toolchain_parser_4, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_parser_5(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_string(629u, __lambda_toolchain_parser_5(a0.payload.s));
}

vader_fn_t vader_fn_static___lambda_toolchain_parser_5 = {
    VADER_STATIC_HEADER(549u), (void*) &vader_fn_tramp___lambda_toolchain_parser_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_parser_6(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_string(629u, __lambda_toolchain_parser_6(a0.payload.s));
}

vader_fn_t vader_fn_static___lambda_toolchain_parser_6 = {
    VADER_STATIC_HEADER(549u), (void*) &vader_fn_tramp___lambda_toolchain_parser_6, NULL,
};

vader_box_t vader_fn_tramp_vader_core_types$mk_struct(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_core_types$mk_struct(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static_vader_core_types$mk_struct = {
    VADER_STATIC_HEADER(598u), (void*) &vader_fn_tramp_vader_core_types$mk_struct, NULL,
};

vader_box_t vader_fn_tramp_vader_core_types$mk_trait(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_core_types$mk_trait(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static_vader_core_types$mk_trait = {
    VADER_STATIC_HEADER(598u), (void*) &vader_fn_tramp_vader_core_types$mk_trait, NULL,
};

vader_box_t vader_fn_tramp_vader_core_types$is_free_numeric(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, vader_core_types$is_free_numeric(a0));
}

vader_fn_t vader_fn_static_vader_core_types$is_free_numeric = {
    VADER_STATIC_HEADER(618u), (void*) &vader_fn_tramp_vader_core_types$is_free_numeric, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_core_types_1(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_core_types_1(a0));
}

vader_fn_t vader_fn_static___lambda_vader_core_types_1 = {
    VADER_STATIC_HEADER(618u), (void*) &vader_fn_tramp___lambda_vader_core_types_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_core_types_5(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_core_types_5(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_core_types_5 = {
    VADER_STATIC_HEADER(560u), (void*) &vader_fn_tramp___lambda_vader_core_types_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_core_types_8(void* env) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_core_types_8());
}

vader_fn_t vader_fn_static___lambda_vader_core_types_8 = {
    VADER_STATIC_HEADER(527u), (void*) &vader_fn_tramp___lambda_vader_core_types_8, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_stage_4(void* env) {
    (void) env;
    return vader_ref_box(__lambda_toolchain_stage_4());
}

vader_fn_t vader_fn_static___lambda_toolchain_stage_4 = {
    VADER_STATIC_HEADER(513u), (void*) &vader_fn_tramp___lambda_toolchain_stage_4, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_stage_5(void* env) {
    (void) env;
    return vader_ref_box(__lambda_toolchain_stage_5());
}

vader_fn_t vader_fn_static___lambda_toolchain_stage_5 = {
    VADER_STATIC_HEADER(511u), (void*) &vader_fn_tramp___lambda_toolchain_stage_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_stage_2(void* env) {
    (void) env;
    return vader_ref_box(__lambda_toolchain_stage_2());
}

vader_fn_t vader_fn_static___lambda_toolchain_stage_2 = {
    VADER_STATIC_HEADER(513u), (void*) &vader_fn_tramp___lambda_toolchain_stage_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_stage_3(void* env) {
    (void) env;
    return vader_ref_box(__lambda_toolchain_stage_3());
}

vader_fn_t vader_fn_static___lambda_toolchain_stage_3 = {
    VADER_STATIC_HEADER(511u), (void*) &vader_fn_tramp___lambda_toolchain_stage_3, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_stage_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_toolchain_stage_0());
}

vader_fn_t vader_fn_static___lambda_toolchain_stage_0 = {
    VADER_STATIC_HEADER(513u), (void*) &vader_fn_tramp___lambda_toolchain_stage_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_toolchain_stage_1(void* env) {
    (void) env;
    return vader_ref_box(__lambda_toolchain_stage_1());
}

vader_fn_t vader_fn_static___lambda_toolchain_stage_1 = {
    VADER_STATIC_HEADER(511u), (void*) &vader_fn_tramp___lambda_toolchain_stage_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_numbers_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, __lambda_std_numbers_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_numbers_0 = {
    VADER_STATIC_HEADER(547u), (void*) &vader_fn_tramp___lambda_std_numbers_0, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_decl(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_decl(a0.payload.obj, a1);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_decl = {
    VADER_STATIC_HEADER(588u), (void*) &vader_fn_tramp_toolchain_protocol$write_decl, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_decorator(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_decorator(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_decorator = {
    VADER_STATIC_HEADER(573u), (void*) &vader_fn_tramp_toolchain_protocol$write_decorator, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_span(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_span(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_span = {
    VADER_STATIC_HEADER(586u), (void*) &vader_fn_tramp_toolchain_protocol$write_span, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_import_name(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_import_name(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_import_name = {
    VADER_STATIC_HEADER(579u), (void*) &vader_fn_tramp_toolchain_protocol$write_import_name, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_expr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_expr(a0.payload.obj, a1);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_expr = {
    VADER_STATIC_HEADER(587u), (void*) &vader_fn_tramp_toolchain_protocol$write_expr, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_variant(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_variant(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_variant = {
    VADER_STATIC_HEADER(574u), (void*) &vader_fn_tramp_toolchain_protocol$write_variant, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_function(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_function(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_function = {
    VADER_STATIC_HEADER(576u), (void*) &vader_fn_tramp_toolchain_protocol$write_function, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_struct_field(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_struct_field(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_struct_field = {
    VADER_STATIC_HEADER(582u), (void*) &vader_fn_tramp_toolchain_protocol$write_struct_field, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_spread(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_spread(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_spread = {
    VADER_STATIC_HEADER(584u), (void*) &vader_fn_tramp_toolchain_protocol$write_spread, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_call_args(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_call_args(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_call_args = {
    VADER_STATIC_HEADER(569u), (void*) &vader_fn_tramp_toolchain_protocol$write_call_args, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_qualifier(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_qualifier(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_qualifier = {
    VADER_STATIC_HEADER(578u), (void*) &vader_fn_tramp_toolchain_protocol$write_qualifier, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_struct_items(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_struct_items(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_struct_items = {
    VADER_STATIC_HEADER(570u), (void*) &vader_fn_tramp_toolchain_protocol$write_struct_items, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_type_param(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_type_param(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_type_param = {
    VADER_STATIC_HEADER(585u), (void*) &vader_fn_tramp_toolchain_protocol$write_type_param, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_call_arg(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_call_arg(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_call_arg = {
    VADER_STATIC_HEADER(572u), (void*) &vader_fn_tramp_toolchain_protocol$write_call_arg, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_struct_item(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_struct_item(a0.payload.obj, a1);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_struct_item = {
    VADER_STATIC_HEADER(594u), (void*) &vader_fn_tramp_toolchain_protocol$write_struct_item, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_param(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_param(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_param = {
    VADER_STATIC_HEADER(577u), (void*) &vader_fn_tramp_toolchain_protocol$write_param, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_stmt(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_stmt(a0.payload.obj, a1);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_stmt = {
    VADER_STATIC_HEADER(589u), (void*) &vader_fn_tramp_toolchain_protocol$write_stmt, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_match_arm(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_match_arm(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_match_arm = {
    VADER_STATIC_HEADER(580u), (void*) &vader_fn_tramp_toolchain_protocol$write_match_arm, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_fallback_clause(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_fallback_clause(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_fallback_clause = {
    VADER_STATIC_HEADER(575u), (void*) &vader_fn_tramp_toolchain_protocol$write_fallback_clause,
    NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_string_part(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_string_part(a0.payload.obj, a1);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_string_part = {
    VADER_STATIC_HEADER(593u), (void*) &vader_fn_tramp_toolchain_protocol$write_string_part, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_target(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_target(a0.payload.obj, a1);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_target = {
    VADER_STATIC_HEADER(591u), (void*) &vader_fn_tramp_toolchain_protocol$write_target, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_binding(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_binding(a0.payload.obj, a1);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_binding = {
    VADER_STATIC_HEADER(592u), (void*) &vader_fn_tramp_toolchain_protocol$write_binding, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_pattern(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_pattern(a0.payload.obj, a1);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_pattern = {
    VADER_STATIC_HEADER(590u), (void*) &vader_fn_tramp_toolchain_protocol$write_pattern, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_simple_binding(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_simple_binding(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_simple_binding = {
    VADER_STATIC_HEADER(581u), (void*) &vader_fn_tramp_toolchain_protocol$write_simple_binding,
    NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_struct_pattern_field(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    toolchain_protocol$write_struct_pattern_field(a0.payload.obj, a1.payload.obj);
    return vader_box_obj(630u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_struct_pattern_field = {
    VADER_STATIC_HEADER(583u),
    (void*) &vader_fn_tramp_toolchain_protocol$write_struct_pattern_field, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_support_fixpoint_0(void* env) {
    (void) env;
    return vader_box_i32(632u, __lambda_vader_support_fixpoint_0());
}

vader_fn_t vader_fn_static___lambda_vader_support_fixpoint_0 = {
    VADER_STATIC_HEADER(530u), (void*) &vader_fn_tramp___lambda_vader_support_fixpoint_0, NULL,
};

vader_box_t vader_fn_tramp_vader_midir$instruction_runs_code(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, vader_midir$instruction_runs_code(a0));
}

vader_fn_t vader_fn_static_vader_midir$instruction_runs_code = {
    VADER_STATIC_HEADER(624u), (void*) &vader_fn_tramp_vader_midir$instruction_runs_code, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_10(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_10());
}

vader_fn_t vader_fn_static___lambda_vader_midir_10 = {
    VADER_STATIC_HEADER(512u), (void*) &vader_fn_tramp___lambda_vader_midir_10, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_11(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_11());
}

vader_fn_t vader_fn_static___lambda_vader_midir_11 = {
    VADER_STATIC_HEADER(512u), (void*) &vader_fn_tramp___lambda_vader_midir_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_ranges_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_midir_ranges_0(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_midir_ranges_0 = {
    VADER_STATIC_HEADER(566u), (void*) &vader_fn_tramp___lambda_vader_midir_ranges_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_ranges_3(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_midir_ranges_3(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_midir_ranges_3 = {
    VADER_STATIC_HEADER(609u), (void*) &vader_fn_tramp___lambda_vader_midir_ranges_3, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_ranges_6(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_midir_ranges_6(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_midir_ranges_6 = {
    VADER_STATIC_HEADER(560u), (void*) &vader_fn_tramp___lambda_vader_midir_ranges_6, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_0());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_0 = {
    VADER_STATIC_HEADER(539u), (void*) &vader_fn_tramp___lambda_vader_front_effects_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_1(void* env) {
    (void) env;
    return vader_box_i64(633u, __lambda_vader_front_effects_1());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_1 = {
    VADER_STATIC_HEADER(531u), (void*) &vader_fn_tramp___lambda_vader_front_effects_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_2(void* env) {
    (void) env;
    return vader_box_i64(633u, __lambda_vader_front_effects_2());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_2 = {
    VADER_STATIC_HEADER(531u), (void*) &vader_fn_tramp___lambda_vader_front_effects_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_8(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_8());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_8 = {
    VADER_STATIC_HEADER(541u), (void*) &vader_fn_tramp___lambda_vader_front_effects_8, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_9(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_9());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_9 = {
    VADER_STATIC_HEADER(519u), (void*) &vader_fn_tramp___lambda_vader_front_effects_9, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_10(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_10());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_10 = {
    VADER_STATIC_HEADER(539u), (void*) &vader_fn_tramp___lambda_vader_front_effects_10, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_11(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_11());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_11 = {
    VADER_STATIC_HEADER(539u), (void*) &vader_fn_tramp___lambda_vader_front_effects_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_12(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_12());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_12 = {
    VADER_STATIC_HEADER(518u), (void*) &vader_fn_tramp___lambda_vader_front_effects_12, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_15(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_15());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_15 = {
    VADER_STATIC_HEADER(512u), (void*) &vader_fn_tramp___lambda_vader_front_effects_15, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_16(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_16());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_16 = {
    VADER_STATIC_HEADER(513u), (void*) &vader_fn_tramp___lambda_vader_front_effects_16, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_17(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_17());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_17 = {
    VADER_STATIC_HEADER(517u), (void*) &vader_fn_tramp___lambda_vader_front_effects_17, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_18(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_18());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_18 = {
    VADER_STATIC_HEADER(540u), (void*) &vader_fn_tramp___lambda_vader_front_effects_18, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_19(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_19());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_19 = {
    VADER_STATIC_HEADER(512u), (void*) &vader_fn_tramp___lambda_vader_front_effects_19, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_35(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_35());
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_35 = {
    VADER_STATIC_HEADER(516u), (void*) &vader_fn_tramp___lambda_vader_front_effects_35, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_42(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_front_effects_42(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_42 = {
    VADER_STATIC_HEADER(602u), (void*) &vader_fn_tramp___lambda_vader_front_effects_42, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_51(void* env, vader_box_t a0) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_51(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_51 = {
    VADER_STATIC_HEADER(603u), (void*) &vader_fn_tramp___lambda_vader_front_effects_51, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_52(void* env, vader_box_t a0) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_52(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_52 = {
    VADER_STATIC_HEADER(603u), (void*) &vader_fn_tramp___lambda_vader_front_effects_52, NULL,
};

vader_box_t vader_fn_tramp_vader_front_effects$is_kept(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, vader_front_effects$is_kept(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_front_effects$is_kept = {
    VADER_STATIC_HEADER(601u), (void*) &vader_fn_tramp_vader_front_effects$is_kept, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_62(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_front_effects_62(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_62 = {
    VADER_STATIC_HEADER(601u), (void*) &vader_fn_tramp___lambda_vader_front_effects_62, NULL,
};

vader_box_t vader_fn_tramp_vader_front_effects$modifies(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, vader_front_effects$modifies(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_front_effects$modifies = {
    VADER_STATIC_HEADER(601u), (void*) &vader_fn_tramp_vader_front_effects$modifies, NULL,
};

vader_box_t vader_fn_tramp_vader_front_effects$is_unknown(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, vader_front_effects$is_unknown(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_front_effects$is_unknown = {
    VADER_STATIC_HEADER(601u), (void*) &vader_fn_tramp_vader_front_effects$is_unknown, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_103(void* env, vader_box_t a0) {
    (void) env;
    return vader_ref_box(__lambda_vader_front_effects_103(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_103 = {
    VADER_STATIC_HEADER(603u), (void*) &vader_fn_tramp___lambda_vader_front_effects_103, NULL,
};

vader_box_t vader_fn_tramp_vader_front_effects$escapes(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(627u, vader_front_effects$escapes(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_front_effects$escapes = {
    VADER_STATIC_HEADER(601u), (void*) &vader_fn_tramp_vader_front_effects$escapes, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_effects_150(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(627u, __lambda_vader_front_effects_150(((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_front_effects_150 = {
    VADER_STATIC_HEADER(555u), (void*) &vader_fn_tramp___lambda_vader_front_effects_150, NULL,
};

vader_box_t vader_fn_lift___lambda_vader_pipeline_0(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_pipeline_0(env, a0.payload.s));
}

vader_box_t vader_fn_lift___lambda_vader_front_resolver_0(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_front_resolver_0(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_resolver_3(void* env) {
    return vader_ref_box(__lambda_vader_front_resolver_3(env));
}

vader_box_t vader_fn_lift___lambda_vader_front_resolver_44(void* env, vader_box_t a0) {
    return __lambda_vader_front_resolver_44(env, a0.payload.obj);
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_2(void* env) {
    return vader_ref_box(__lambda_vader_front_typecheck_2(env));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_4(void* env) {
    return vader_ref_box(__lambda_vader_front_typecheck_4(env));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_6(void* env) {
    return vader_ref_box(__lambda_vader_front_typecheck_6(env));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_8(void* env) {
    return vader_ref_box(__lambda_vader_front_typecheck_8(env));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_11(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_11(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_18(void* env, vader_box_t a0) {
    return vader_box_i32(634u, (int32_t)(uint32_t) __lambda_vader_front_typecheck_18(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_26(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_26(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_29(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_29(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_33(void* env, vader_box_t a0) {
    return vader_box_i32(634u, (int32_t)(uint32_t) __lambda_vader_front_typecheck_33(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_35(void* env) {
    return __lambda_vader_front_typecheck_35(env);
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_37(void* env) {
    return __lambda_vader_front_typecheck_37(env);
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_40(void* env, vader_box_t a0) {
    return vader_box_i32(634u, (int32_t)(uint32_t) __lambda_vader_front_typecheck_40(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_42(void* env, vader_box_t a0) {
    return vader_box_i32(634u, (int32_t)(uint32_t) __lambda_vader_front_typecheck_42(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_44(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_front_typecheck_44(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_53(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_53(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_57(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_57(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_59(void* env, vader_box_t a0) {
    __lambda_vader_front_typecheck_59(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_front_typecheck_73(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_front_typecheck_73(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_lower_0(void* env, vader_box_t a0) {
    __lambda_vader_lower_0(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_lower_12(void* env) {
    return vader_box_string(629u, __lambda_vader_lower_12(env));
}

vader_box_t vader_fn_lift___lambda_vader_lower_14(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_lower_14(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_lower_16(void* env, vader_box_t a0) {
    return vader_box_i32(634u, (int32_t)(uint32_t) __lambda_vader_lower_16(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_lower_18(void* env, vader_box_t a0) {
    __lambda_vader_lower_18(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_lower_21(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_lower_21(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_lower_23(void* env) {
    return vader_ref_box(__lambda_vader_lower_23(env));
}

vader_box_t vader_fn_lift___lambda_vader_lower_27(void* env) {
    return vader_ref_box(__lambda_vader_lower_27(env));
}

vader_box_t vader_fn_lift___lambda_vader_lower_dce_0(void* env, vader_box_t a0) {
    __lambda_vader_lower_dce_0(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_lower_dce_3(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_vader_lower_dce_3(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_lower_dce_5(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_vader_lower_dce_5(env, a0.payload.s, a1.payload.s);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_lower_dce_7(void* env, vader_box_t a0) {
    __lambda_vader_lower_dce_7(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_lower_ir_0(void* env, vader_box_t a0) {
    __lambda_vader_lower_ir_0(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_lower_ir_2(void* env, vader_box_t a0) {
    __lambda_vader_lower_ir_2(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_std_fs_0(void* env) {
    __defer_std_fs_0(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_std_fs_2(void* env) {
    __defer_std_fs_2(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_emit_c_1(void* env, vader_box_t a0) {
    return vader_ref_box(__lambda_vader_emit_c_1(env, ((int64_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_emit_c_3(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(627u, __lambda_vader_emit_c_3(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_vm_6(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(627u, __lambda_vader_vm_6(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_vm_9(void* env) {
    return vader_ref_box(__lambda_vader_vm_9(env));
}

vader_box_t vader_fn_lift___lambda_vader_vm_12(void* env) {
    return vader_ref_box(__lambda_vader_vm_12(env));
}

vader_box_t vader_fn_lift___lambda_vader_vm_20(void* env) {
    __lambda_vader_vm_20(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_vader_vm_22(void* env) {
    __defer_vader_vm_22(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_vader_vm_24(void* env) {
    __defer_vader_vm_24(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_front_comptime_2(void* env, vader_box_t a0) {
    return __lambda_vader_front_comptime_2(env, a0);
}

vader_box_t vader_fn_lift___lambda_vader_front_comptime_0(void* env, vader_box_t a0) {
    return __lambda_vader_front_comptime_0(env, a0.payload.obj);
}

vader_box_t vader_fn_lift___lambda_vader_front_comptime_5(void* env, vader_box_t a0) {
    return __lambda_vader_front_comptime_5(env, a0.payload.obj);
}

vader_box_t vader_fn_lift___lambda_vader_front_comptime_10(void* env, vader_box_t a0) {
    return vader_box_i32(634u, (int32_t)(uint32_t) __lambda_vader_front_comptime_10(env, a0));
}

vader_box_t vader_fn_lift___lambda_std_task_0(void* env) {
    __lambda_std_task_0(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_std_task_8(void* env) {
    __defer_std_task_8(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_std_task_12(void* env) {
    __defer_std_task_12(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_std_task_14(void* env) {
    __defer_std_task_14(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_std_task_10(void* env) {
    __defer_std_task_10(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_std_task_2(void* env) {
    __defer_std_task_2(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_std_task_4(void* env) {
    __defer_std_task_4(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_std_task_6(void* env) {
    __defer_std_task_6(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_toolchain_ast_2(void* env, vader_box_t a0) {
    return vader_box_i32(634u, (int32_t)(uint32_t) __lambda_toolchain_ast_2(env, a0));
}

vader_box_t vader_fn_lift___lambda_toolchain_parser_0(void* env, vader_box_t a0) {
    return vader_box_string(629u, __lambda_toolchain_parser_0(env, a0.payload.s));
}

vader_box_t vader_fn_lift___lambda_toolchain_parser_2(void* env, vader_box_t a0) {
    return vader_box_string(629u, __lambda_toolchain_parser_2(env, a0.payload.s));
}

vader_box_t vader_fn_lift___lambda_vader_core_types_3(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(627u, __lambda_vader_core_types_3(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_front_reach_0(void* env, vader_box_t a0) {
    return vader_box_i32(634u, (int32_t)(uint32_t) __lambda_vader_front_reach_0(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_support_fixpoint_1(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_support_fixpoint_1(env, ((int32_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_lower_optimise_0(void* env, vader_box_t a0) {
    __lambda_vader_lower_optimise_0(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_lower_optimise_2(void* env, vader_box_t a0) {
    __lambda_vader_lower_optimise_2(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_midir_0(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_midir_0(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_midir_4(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_midir_4(env, ((int64_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_midir_6(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_midir_6(env, ((int64_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_midir_8(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_midir_8(env, ((int64_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_midir_12(void* env, vader_box_t a0) {
    __lambda_vader_midir_12(env, ((int32_t) a0.payload.i));
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_midir_14(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2) {
    __lambda_vader_midir_14(env, ((int32_t) a0.payload.i), a1.payload.obj, a2.payload.s);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_midir_16(void* env, vader_box_t a0) {
    __lambda_vader_midir_16(env, ((int32_t) a0.payload.i));
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_midir_18(void* env, vader_box_t a0) {
    __lambda_vader_midir_18(env, ((int32_t) a0.payload.i));
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_midir_21(void* env, vader_box_t a0) {
    __lambda_vader_midir_21(env, ((int32_t) a0.payload.i));
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_midir_23(void* env, vader_box_t a0) {
    __lambda_vader_midir_23(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_midir_optimise_0(void* env, vader_box_t a0) {
    __lambda_vader_midir_optimise_0(env, ((int32_t) a0.payload.i));
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_midir_optimise_2(void* env, vader_box_t a0) {
    __lambda_vader_midir_optimise_2(env, ((int32_t) a0.payload.i));
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_std_runtime_scheduler_0(void* env) {
    __defer_std_runtime_scheduler_0(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_std_runtime_scheduler_2(void* env) {
    __defer_std_runtime_scheduler_2(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___defer_std_runtime_scheduler_4(void* env) {
    __defer_std_runtime_scheduler_4(env);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_emit_c_ast_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(627u, __lambda_vader_emit_c_ast_0(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_3(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_front_effects_3(env, ((int32_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_40(void* env, vader_box_t a0) {
    return vader_box_i32(634u, (int32_t)(uint32_t) __lambda_vader_front_effects_40(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_53(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_front_effects_53(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_56(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_front_effects_56(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_60(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_front_effects_60(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_106(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_front_effects_106(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_136(void* env, vader_box_t a0) {
    return vader_box_bool(627u, __lambda_vader_front_effects_136(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_146(void* env, vader_box_t a0) {
    return vader_box_i32(634u, (int32_t)(uint32_t) __lambda_vader_front_effects_146(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_effects_148(void* env, vader_box_t a0) {
    __lambda_vader_front_effects_148(env, a0);
    return vader_box_obj(630u, NULL);
}

vader_box_t vader_fn_lift___lambda_vader_front_dead__code_3(void* env, vader_box_t a0) {
    return vader_box_i32(634u, (int32_t)(uint32_t) __lambda_vader_front_dead__code_3(env, a0));
}

/* vtable dispatchers */
vader_box_t std_core$Iterator$next$$dispatch(vader_box_t recv) {
    switch (recv.tag) {
        case 1101u: return std_core$__gen_state_std_core_0$Iterator$next(recv.payload.obj);
        case 1102u: return std_core$__gen_state_std_core_1$Iterator$next(recv.payload.obj);
        case 1095u: return std_core$Range$Iterator$next__i64(recv.payload.obj);
        case 1115u: return std_string$StringChars$std_core$Iterator$next(recv.payload.obj);
        case 1109u: return std_iter$$genstate_filter$Iterator$next(recv.payload.obj);
        case 1110u: return std_iter$__gen_state_std_iter_0$Iterator$next(recv.payload.obj);
        case 1122u: return toolchain_ast$$genstate_decorator_sites$Iterator$next(recv.payload.obj);
        default: vader_unreachable("vtable miss in std_core$Iterator.next");
    }
    vader_unreachable("vtable miss in std_core$Iterator.next");
}

uint64_t std_core$Hash$hash$$dispatch(vader_box_t recv) {
    switch (recv.tag) {
        case 625u: return std_core$i8$Hash$hash(((int8_t) recv.payload.i));
        case 626u: return std_core$i16$Hash$hash(((int16_t) recv.payload.i));
        case 632u: return std_core$i32$Hash$hash(((int32_t) recv.payload.i));
        case 633u: return std_core$i64$Hash$hash(((int64_t) recv.payload.i));
        case 634u: return std_core$u8$Hash$hash(((uint8_t) recv.payload.i));
        case 635u: return std_core$u16$Hash$hash(((uint16_t) recv.payload.i));
        case 636u: return std_core$u32$Hash$hash(((uint32_t) recv.payload.i));
        case 637u: return std_core$u64$Hash$hash(((uint64_t) recv.payload.i));
        case 628u: return std_core$char$Hash$hash(((uint32_t) recv.payload.i));
        case 629u: return std_core$string$Hash$hash(recv.payload.s);
        case 2145u: return vader_vm$Scalar$std_core$Hash$hash(recv.payload.obj);
        case 1266u: return toolchain_span$Span$std_core$Hash$hash(recv.payload.obj);
        default: vader_unreachable("vtable miss in std_core$Hash.hash");
    }
    vader_unreachable("vtable miss in std_core$Hash.hash");
}

bool std_core$Equals$equals$$dispatch(vader_box_t recv, vader_box_t a0) {
    switch (recv.tag) {
        case 625u: return std_core$i8$Equals$equals$guard(((int8_t) recv.payload.i), a0);
        case 626u: return std_core$i16$Equals$equals$guard(((int16_t) recv.payload.i), a0);
        case 632u: return std_core$i32$Equals$equals$guard(((int32_t) recv.payload.i), a0);
        case 633u: return std_core$i64$Equals$equals$guard(((int64_t) recv.payload.i), a0);
        case 634u: return std_core$u8$Equals$equals$guard(((uint8_t) recv.payload.i), a0);
        case 635u: return std_core$u16$Equals$equals$guard(((uint16_t) recv.payload.i), a0);
        case 636u: return std_core$u32$Equals$equals$guard(((uint32_t) recv.payload.i), a0);
        case 637u: return std_core$u64$Equals$equals$guard(((uint64_t) recv.payload.i), a0);
        case 638u: return std_core$f32$Equals$equals$guard(((float) recv.payload.f), a0);
        case 639u: return std_core$f64$Equals$equals$guard(((double) recv.payload.f), a0);
        case 627u: return std_core$bool$Equals$equals$guard(recv.payload.b, a0);
        case 628u: return std_core$char$Equals$equals$guard(((uint32_t) recv.payload.i), a0);
        case 629u: return std_core$string$Equals$equals$guard(recv.payload.s, a0);
        case 2115u: return vader_support_target$Target$std_core$Equals$equals$guard(recv.payload.obj, a0);
        case 2145u: return vader_vm$Scalar$std_core$Equals$equals$guard(recv.payload.obj, a0);
        case 1266u: return toolchain_span$Span$std_core$Equals$equals$guard(recv.payload.obj, a0);
        case 1119u: return std_task$Task$std_core$Equals$equals__Any(recv.payload.obj, a0.payload.obj);
        default: vader_unreachable("vtable miss in std_core$Equals.equals");
    }
    vader_unreachable("vtable miss in std_core$Equals.equals");
}

vader_box_t toolchain_stage$Stage$describe$$dispatch(vader_box_t recv) {
    switch (recv.tag) {
        case 1743u: return vader_ref_box(vader_front_resolver$DisplayableStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1772u: return vader_ref_box(vader_front_resolver$ReplayedBodyStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1773u: return vader_ref_box(vader_front_resolver$ReplayedStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1783u: return vader_ref_box(vader_front_resolver$TestsStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1786u: return vader_ref_box(vader_front_resolver$WitStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1549u: return vader_ref_box(vader_emit_bytecode$CoalesceStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1550u: return vader_ref_box(vader_emit_bytecode$ConstFoldStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1551u: return vader_ref_box(vader_emit_bytecode$DeadStoresStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1556u: return vader_ref_box(vader_emit_bytecode$PeepholeStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1558u: return vader_ref_box(vader_emit_bytecode$PropagateStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1559u: return vader_ref_box(vader_emit_bytecode$ReturnLitStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 1563u: return vader_ref_box(vader_emit_bytecode$StripSelfCopiesStage$toolchain_stage$Stage$describe(recv.payload.obj));
        case 2091u: return vader_ref_box(vader_pipeline_check$DeadCode$toolchain_stage$Stage$describe(recv.payload.obj));
        case 2092u: return vader_ref_box(vader_pipeline_check$DeepCopies$toolchain_stage$Stage$describe(recv.payload.obj));
        case 2093u: return vader_ref_box(vader_pipeline_check$Frozen$toolchain_stage$Stage$describe(recv.payload.obj));
        case 2097u: return vader_ref_box(vader_pipeline_check$TaskFaults$toolchain_stage$Stage$describe(recv.payload.obj));
        case 2098u: return vader_ref_box(vader_pipeline_check$UnusedExports$toolchain_stage$Stage$describe(recv.payload.obj));
        case 2099u: return vader_ref_box(vader_pipeline_check$UnusedImports$toolchain_stage$Stage$describe(recv.payload.obj));
        case 2100u: return vader_ref_box(vader_pipeline_check$Widening$toolchain_stage$Stage$describe(recv.payload.obj));
        default: vader_unreachable("vtable miss in toolchain_stage$Stage.describe");
    }
    vader_unreachable("vtable miss in toolchain_stage$Stage.describe");
}

vader_box_t toolchain_stage$Stage$run$$dispatch(vader_box_t recv, vader_box_t a0) {
    switch (recv.tag) {
        case 1743u: return vader_ref_box(vader_front_resolver$DisplayableStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1772u: return vader_ref_box(vader_front_resolver$ReplayedBodyStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1773u: return vader_ref_box(vader_front_resolver$ReplayedStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1783u: return vader_ref_box(vader_front_resolver$TestsStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1786u: return vader_front_resolver$WitStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj);
        case 1549u: return vader_ref_box(vader_emit_bytecode$CoalesceStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1550u: return vader_ref_box(vader_emit_bytecode$ConstFoldStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1551u: return vader_ref_box(vader_emit_bytecode$DeadStoresStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1556u: return vader_ref_box(vader_emit_bytecode$PeepholeStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1558u: return vader_ref_box(vader_emit_bytecode$PropagateStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1559u: return vader_ref_box(vader_emit_bytecode$ReturnLitStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 1563u: return vader_ref_box(vader_emit_bytecode$StripSelfCopiesStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 2091u: return vader_ref_box(vader_pipeline_check$DeadCode$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 2092u: return vader_ref_box(vader_pipeline_check$DeepCopies$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 2093u: return vader_ref_box(vader_pipeline_check$Frozen$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 2097u: return vader_ref_box(vader_pipeline_check$TaskFaults$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 2098u: return vader_ref_box(vader_pipeline_check$UnusedExports$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 2099u: return vader_ref_box(vader_pipeline_check$UnusedImports$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        case 2100u: return vader_ref_box(vader_pipeline_check$Widening$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
        default: vader_unreachable("vtable miss in toolchain_stage$Stage.run");
    }
    vader_unreachable("vtable miss in toolchain_stage$Stage.run");
}

vader_box_t toolchain_stage$BuildFiles$read_text$$dispatch(vader_box_t recv, vader_box_t a0) {
    switch (recv.tag) {
        case 1759u: return vader_front_resolver$LoadFiles$toolchain_stage$BuildFiles$read_text(recv.payload.obj, a0.payload.s);
        default: vader_unreachable("vtable miss in toolchain_stage$BuildFiles.read_text");
    }
    vader_unreachable("vtable miss in toolchain_stage$BuildFiles.read_text");
}

vader_box_t toolchain_stage$BuildFiles$list_folder$$dispatch(vader_box_t recv, vader_box_t a0) {
    switch (recv.tag) {
        case 1759u: return vader_front_resolver$LoadFiles$toolchain_stage$BuildFiles$list_folder(recv.payload.obj, a0.payload.s);
        default: vader_unreachable("vtable miss in toolchain_stage$BuildFiles.list_folder");
    }
    vader_unreachable("vtable miss in toolchain_stage$BuildFiles.list_folder");
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    vader_gc_top = &vader_global_frame;
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 28u, 629u);
    return vader_scheduler_exit((int) vader_bootstrap$main(__args));
}
