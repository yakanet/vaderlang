#include "bootstrap.split.h"

/* vtable dispatchers */
vader_box_t std_core$Iterator$next$$dispatch(vader_box_t recv) {
	switch (recv.tag) {
		case 1124u: return std_core$__gen_state_std_core_0$Iterator$next(recv.payload.obj);
		case 1125u: return std_core$__gen_state_std_core_1$Iterator$next(recv.payload.obj);
		case 1118u: return std_core$Range$Iterator$next__i64(recv.payload.obj);
		case 1138u: return std_string$StringChars$std_core$Iterator$next(recv.payload.obj);
		case 1132u: return std_iter$$genstate_filter$Iterator$next(recv.payload.obj);
		case 1133u: return std_iter$__gen_state_std_iter_0$Iterator$next(recv.payload.obj);
		case 1145u: return toolchain_ast$$genstate_decorator_sites$Iterator$next(recv.payload.obj);
		default: vader_unreachable("vtable miss in std_core$Iterator.next");
	}
	vader_unreachable("vtable miss in std_core$Iterator.next");
}

uint64_t std_core$Hash$hash$$dispatch(vader_box_t recv) {
	switch (recv.tag) {
		case 638u: return std_core$i8$Hash$hash(((int8_t) recv.payload.i));
		case 639u: return std_core$i16$Hash$hash(((int16_t) recv.payload.i));
		case 645u: return std_core$i32$Hash$hash(((int32_t) recv.payload.i));
		case 646u: return std_core$i64$Hash$hash(((int64_t) recv.payload.i));
		case 647u: return std_core$u8$Hash$hash(((uint8_t) recv.payload.i));
		case 648u: return std_core$u16$Hash$hash(((uint16_t) recv.payload.i));
		case 649u: return std_core$u32$Hash$hash(((uint32_t) recv.payload.i));
		case 650u: return std_core$u64$Hash$hash(((uint64_t) recv.payload.i));
		case 641u: return std_core$char$Hash$hash(((uint32_t) recv.payload.i));
		case 642u: return std_core$string$Hash$hash(recv.payload.s);
		case 2182u: return vader_vm$Scalar$std_core$Hash$hash(recv.payload.obj);
		case 1289u: return toolchain_span$Span$std_core$Hash$hash(recv.payload.obj);
		default: vader_unreachable("vtable miss in std_core$Hash.hash");
	}
	vader_unreachable("vtable miss in std_core$Hash.hash");
}

bool std_core$Equals$equals$$dispatch(vader_box_t recv, vader_box_t a0) {
	switch (recv.tag) {
		case 638u: return std_core$i8$Equals$equals$guard(((int8_t) recv.payload.i), a0);
		case 639u: return std_core$i16$Equals$equals$guard(((int16_t) recv.payload.i), a0);
		case 645u: return std_core$i32$Equals$equals$guard(((int32_t) recv.payload.i), a0);
		case 646u: return std_core$i64$Equals$equals$guard(((int64_t) recv.payload.i), a0);
		case 647u: return std_core$u8$Equals$equals$guard(((uint8_t) recv.payload.i), a0);
		case 648u: return std_core$u16$Equals$equals$guard(((uint16_t) recv.payload.i), a0);
		case 649u: return std_core$u32$Equals$equals$guard(((uint32_t) recv.payload.i), a0);
		case 650u: return std_core$u64$Equals$equals$guard(((uint64_t) recv.payload.i), a0);
		case 651u: return std_core$f32$Equals$equals$guard(((float) recv.payload.f), a0);
		case 652u: return std_core$f64$Equals$equals$guard(((double) recv.payload.f), a0);
		case 640u: return std_core$bool$Equals$equals$guard(recv.payload.b, a0);
		case 641u: return std_core$char$Equals$equals$guard(((uint32_t) recv.payload.i), a0);
		case 642u: return std_core$string$Equals$equals$guard(recv.payload.s, a0);
		case 2152u: return vader_support_target$Target$std_core$Equals$equals$guard(recv.payload.obj, a0);
		case 2182u: return vader_vm$Scalar$std_core$Equals$equals$guard(recv.payload.obj, a0);
		case 1289u: return toolchain_span$Span$std_core$Equals$equals$guard(recv.payload.obj, a0);
		case 1142u: return std_task$Task$std_core$Equals$equals__Any(recv.payload.obj, a0.payload.obj);
		default: vader_unreachable("vtable miss in std_core$Equals.equals");
	}
	vader_unreachable("vtable miss in std_core$Equals.equals");
}

vader_box_t toolchain_stage$Stage$describe$$dispatch(vader_box_t recv) {
	switch (recv.tag) {
		case 1778u: return vader_ref_box(vader_front_resolver$DisplayableStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1807u: return vader_ref_box(vader_front_resolver$ReplayedBodyStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1808u: return vader_ref_box(vader_front_resolver$ReplayedStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1818u: return vader_ref_box(vader_front_resolver$TestsStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1822u: return vader_ref_box(vader_front_resolver$WitStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1577u: return vader_ref_box(vader_emit_bytecode$CoalesceStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1578u: return vader_ref_box(vader_emit_bytecode$ConstFoldStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1579u: return vader_ref_box(vader_emit_bytecode$DeadStoresStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1584u: return vader_ref_box(vader_emit_bytecode$PeepholeStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1586u: return vader_ref_box(vader_emit_bytecode$PropagateStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1587u: return vader_ref_box(vader_emit_bytecode$ReturnLitStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1591u: return vader_ref_box(vader_emit_bytecode$StripSelfCopiesStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2127u: return vader_ref_box(vader_pipeline_check$DeadCode$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2128u: return vader_ref_box(vader_pipeline_check$DeepCopies$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2129u: return vader_ref_box(vader_pipeline_check$Frozen$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2133u: return vader_ref_box(vader_pipeline_check$TaskFaults$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2134u: return vader_ref_box(vader_pipeline_check$UncoveredUses$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2135u: return vader_ref_box(vader_pipeline_check$UnusedExports$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2136u: return vader_ref_box(vader_pipeline_check$UnusedImports$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2137u: return vader_ref_box(vader_pipeline_check$Widening$toolchain_stage$Stage$describe(recv.payload.obj));
		default: vader_unreachable("vtable miss in toolchain_stage$Stage.describe");
	}
	vader_unreachable("vtable miss in toolchain_stage$Stage.describe");
}

vader_box_t toolchain_stage$Stage$run$$dispatch(vader_box_t recv, vader_box_t a0) {
	switch (recv.tag) {
		case 1778u: return vader_ref_box(vader_front_resolver$DisplayableStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1807u: return vader_ref_box(vader_front_resolver$ReplayedBodyStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1808u: return vader_ref_box(vader_front_resolver$ReplayedStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1818u: return vader_ref_box(vader_front_resolver$TestsStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1822u: return vader_front_resolver$WitStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj);
		case 1577u: return vader_ref_box(vader_emit_bytecode$CoalesceStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1578u: return vader_ref_box(vader_emit_bytecode$ConstFoldStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1579u: return vader_ref_box(vader_emit_bytecode$DeadStoresStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1584u: return vader_ref_box(vader_emit_bytecode$PeepholeStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1586u: return vader_ref_box(vader_emit_bytecode$PropagateStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1587u: return vader_ref_box(vader_emit_bytecode$ReturnLitStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1591u: return vader_ref_box(vader_emit_bytecode$StripSelfCopiesStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2127u: return vader_ref_box(vader_pipeline_check$DeadCode$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2128u: return vader_ref_box(vader_pipeline_check$DeepCopies$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2129u: return vader_ref_box(vader_pipeline_check$Frozen$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2133u: return vader_ref_box(vader_pipeline_check$TaskFaults$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2134u: return vader_ref_box(vader_pipeline_check$UncoveredUses$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2135u: return vader_ref_box(vader_pipeline_check$UnusedExports$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2136u: return vader_ref_box(vader_pipeline_check$UnusedImports$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2137u: return vader_ref_box(vader_pipeline_check$Widening$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		default: vader_unreachable("vtable miss in toolchain_stage$Stage.run");
	}
	vader_unreachable("vtable miss in toolchain_stage$Stage.run");
}

vader_box_t toolchain_stage$BuildFiles$read_text$$dispatch(vader_box_t recv, vader_box_t a0) {
	switch (recv.tag) {
		case 1794u: return vader_front_resolver$LoadFiles$toolchain_stage$BuildFiles$read_text(recv.payload.obj, a0.payload.s);
		default: vader_unreachable("vtable miss in toolchain_stage$BuildFiles.read_text");
	}
	vader_unreachable("vtable miss in toolchain_stage$BuildFiles.read_text");
}

vader_box_t toolchain_stage$BuildFiles$list_folder$$dispatch(vader_box_t recv, vader_box_t a0) {
	switch (recv.tag) {
		case 1794u: return vader_front_resolver$LoadFiles$toolchain_stage$BuildFiles$list_folder(recv.payload.obj, a0.payload.s);
		default: vader_unreachable("vtable miss in toolchain_stage$BuildFiles.list_folder");
	}
	vader_unreachable("vtable miss in toolchain_stage$BuildFiles.list_folder");
}

int main(int argc, char** argv) {
	vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
	vader_gc_top = &vader_global_frame;
	atexit(vader_atom_shutdown);
	atexit(vader_gc_shutdown);
	void* __args = (void*) vader_runtime_argv(argc, argv, 28u, 642u);
	return vader_scheduler_exit((int) vader_bootstrap$main(__args));
}
