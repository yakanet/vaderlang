#include "bootstrap.split.h"

/* vtable dispatchers */
vader_box_t std_core$Iterator$next$$dispatch(vader_box_t recv) {
	switch (recv.tag) {
		case 1107u: return std_core$__gen_state_std_core_0$Iterator$next(recv.payload.obj);
		case 1108u: return std_core$__gen_state_std_core_1$Iterator$next(recv.payload.obj);
		case 1101u: return std_core$Range$Iterator$next__i64(recv.payload.obj);
		case 1121u: return std_string$StringChars$std_core$Iterator$next(recv.payload.obj);
		case 1115u: return std_iter$$genstate_filter$Iterator$next(recv.payload.obj);
		case 1116u: return std_iter$__gen_state_std_iter_0$Iterator$next(recv.payload.obj);
		case 1128u: return toolchain_ast$$genstate_decorator_sites$Iterator$next(recv.payload.obj);
		default: vader_unreachable("vtable miss in std_core$Iterator.next");
	}
	vader_unreachable("vtable miss in std_core$Iterator.next");
}

uint64_t std_core$Hash$hash$$dispatch(vader_box_t recv) {
	switch (recv.tag) {
		case 626u: return std_core$i8$Hash$hash(((int8_t) recv.payload.i));
		case 627u: return std_core$i16$Hash$hash(((int16_t) recv.payload.i));
		case 633u: return std_core$i32$Hash$hash(((int32_t) recv.payload.i));
		case 634u: return std_core$i64$Hash$hash(((int64_t) recv.payload.i));
		case 635u: return std_core$u8$Hash$hash(((uint8_t) recv.payload.i));
		case 636u: return std_core$u16$Hash$hash(((uint16_t) recv.payload.i));
		case 637u: return std_core$u32$Hash$hash(((uint32_t) recv.payload.i));
		case 638u: return std_core$u64$Hash$hash(((uint64_t) recv.payload.i));
		case 629u: return std_core$char$Hash$hash(((uint32_t) recv.payload.i));
		case 630u: return std_core$string$Hash$hash(recv.payload.s);
		case 2153u: return vader_vm$Scalar$std_core$Hash$hash(recv.payload.obj);
		case 1272u: return toolchain_span$Span$std_core$Hash$hash(recv.payload.obj);
		default: vader_unreachable("vtable miss in std_core$Hash.hash");
	}
	vader_unreachable("vtable miss in std_core$Hash.hash");
}

bool std_core$Equals$equals$$dispatch(vader_box_t recv, vader_box_t a0) {
	switch (recv.tag) {
		case 626u: return std_core$i8$Equals$equals$guard(((int8_t) recv.payload.i), a0);
		case 627u: return std_core$i16$Equals$equals$guard(((int16_t) recv.payload.i), a0);
		case 633u: return std_core$i32$Equals$equals$guard(((int32_t) recv.payload.i), a0);
		case 634u: return std_core$i64$Equals$equals$guard(((int64_t) recv.payload.i), a0);
		case 635u: return std_core$u8$Equals$equals$guard(((uint8_t) recv.payload.i), a0);
		case 636u: return std_core$u16$Equals$equals$guard(((uint16_t) recv.payload.i), a0);
		case 637u: return std_core$u32$Equals$equals$guard(((uint32_t) recv.payload.i), a0);
		case 638u: return std_core$u64$Equals$equals$guard(((uint64_t) recv.payload.i), a0);
		case 639u: return std_core$f32$Equals$equals$guard(((float) recv.payload.f), a0);
		case 640u: return std_core$f64$Equals$equals$guard(((double) recv.payload.f), a0);
		case 628u: return std_core$bool$Equals$equals$guard(recv.payload.b, a0);
		case 629u: return std_core$char$Equals$equals$guard(((uint32_t) recv.payload.i), a0);
		case 630u: return std_core$string$Equals$equals$guard(recv.payload.s, a0);
		case 2123u: return vader_support_target$Target$std_core$Equals$equals$guard(recv.payload.obj, a0);
		case 2153u: return vader_vm$Scalar$std_core$Equals$equals$guard(recv.payload.obj, a0);
		case 1272u: return toolchain_span$Span$std_core$Equals$equals$guard(recv.payload.obj, a0);
		case 1125u: return std_task$Task$std_core$Equals$equals__Any(recv.payload.obj, a0.payload.obj);
		default: vader_unreachable("vtable miss in std_core$Equals.equals");
	}
	vader_unreachable("vtable miss in std_core$Equals.equals");
}

vader_box_t toolchain_stage$Stage$describe$$dispatch(vader_box_t recv) {
	switch (recv.tag) {
		case 1751u: return vader_ref_box(vader_front_resolver$DisplayableStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1780u: return vader_ref_box(vader_front_resolver$ReplayedBodyStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1781u: return vader_ref_box(vader_front_resolver$ReplayedStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1791u: return vader_ref_box(vader_front_resolver$TestsStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1794u: return vader_ref_box(vader_front_resolver$WitStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1555u: return vader_ref_box(vader_emit_bytecode$CoalesceStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1556u: return vader_ref_box(vader_emit_bytecode$ConstFoldStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1557u: return vader_ref_box(vader_emit_bytecode$DeadStoresStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1562u: return vader_ref_box(vader_emit_bytecode$PeepholeStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1564u: return vader_ref_box(vader_emit_bytecode$PropagateStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1565u: return vader_ref_box(vader_emit_bytecode$ReturnLitStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 1569u: return vader_ref_box(vader_emit_bytecode$StripSelfCopiesStage$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2099u: return vader_ref_box(vader_pipeline_check$DeadCode$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2100u: return vader_ref_box(vader_pipeline_check$DeepCopies$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2101u: return vader_ref_box(vader_pipeline_check$Frozen$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2105u: return vader_ref_box(vader_pipeline_check$TaskFaults$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2106u: return vader_ref_box(vader_pipeline_check$UnusedExports$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2107u: return vader_ref_box(vader_pipeline_check$UnusedImports$toolchain_stage$Stage$describe(recv.payload.obj));
		case 2108u: return vader_ref_box(vader_pipeline_check$Widening$toolchain_stage$Stage$describe(recv.payload.obj));
		default: vader_unreachable("vtable miss in toolchain_stage$Stage.describe");
	}
	vader_unreachable("vtable miss in toolchain_stage$Stage.describe");
}

vader_box_t toolchain_stage$Stage$run$$dispatch(vader_box_t recv, vader_box_t a0) {
	switch (recv.tag) {
		case 1751u: return vader_ref_box(vader_front_resolver$DisplayableStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1780u: return vader_ref_box(vader_front_resolver$ReplayedBodyStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1781u: return vader_ref_box(vader_front_resolver$ReplayedStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1791u: return vader_ref_box(vader_front_resolver$TestsStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1794u: return vader_front_resolver$WitStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj);
		case 1555u: return vader_ref_box(vader_emit_bytecode$CoalesceStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1556u: return vader_ref_box(vader_emit_bytecode$ConstFoldStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1557u: return vader_ref_box(vader_emit_bytecode$DeadStoresStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1562u: return vader_ref_box(vader_emit_bytecode$PeepholeStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1564u: return vader_ref_box(vader_emit_bytecode$PropagateStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1565u: return vader_ref_box(vader_emit_bytecode$ReturnLitStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 1569u: return vader_ref_box(vader_emit_bytecode$StripSelfCopiesStage$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2099u: return vader_ref_box(vader_pipeline_check$DeadCode$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2100u: return vader_ref_box(vader_pipeline_check$DeepCopies$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2101u: return vader_ref_box(vader_pipeline_check$Frozen$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2105u: return vader_ref_box(vader_pipeline_check$TaskFaults$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2106u: return vader_ref_box(vader_pipeline_check$UnusedExports$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2107u: return vader_ref_box(vader_pipeline_check$UnusedImports$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		case 2108u: return vader_ref_box(vader_pipeline_check$Widening$toolchain_stage$Stage$run(recv.payload.obj, a0.payload.obj));
		default: vader_unreachable("vtable miss in toolchain_stage$Stage.run");
	}
	vader_unreachable("vtable miss in toolchain_stage$Stage.run");
}

vader_box_t toolchain_stage$BuildFiles$read_text$$dispatch(vader_box_t recv, vader_box_t a0) {
	switch (recv.tag) {
		case 1767u: return vader_front_resolver$LoadFiles$toolchain_stage$BuildFiles$read_text(recv.payload.obj, a0.payload.s);
		default: vader_unreachable("vtable miss in toolchain_stage$BuildFiles.read_text");
	}
	vader_unreachable("vtable miss in toolchain_stage$BuildFiles.read_text");
}

vader_box_t toolchain_stage$BuildFiles$list_folder$$dispatch(vader_box_t recv, vader_box_t a0) {
	switch (recv.tag) {
		case 1767u: return vader_front_resolver$LoadFiles$toolchain_stage$BuildFiles$list_folder(recv.payload.obj, a0.payload.s);
		default: vader_unreachable("vtable miss in toolchain_stage$BuildFiles.list_folder");
	}
	vader_unreachable("vtable miss in toolchain_stage$BuildFiles.list_folder");
}

int main(int argc, char** argv) {
	vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
	vader_gc_top = &vader_global_frame;
	atexit(vader_atom_shutdown);
	atexit(vader_gc_shutdown);
	void* __args = (void*) vader_runtime_argv(argc, argv, 28u, 630u);
	return vader_scheduler_exit((int) vader_bootstrap$main(__args));
}
