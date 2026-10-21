#include "bootstrap.split.h"

static bool std_collections_MutableMap_std_core_Contains_contains__Any__bool(void* l0, vader_box_t l1);
static bool std_collections_MutableMap_std_core_Contains_contains__i32__bool(void* l0, int32_t l1);
static bool std_collections_MutableMap_std_core_Contains_contains__i64__bool(void* l0, int64_t l1);
static bool std_collections_MutableMap_std_core_Contains_contains__string__bool(void* l0, vader_string_t l1);
static bool std_collections_MutableMap_std_core_Contains_contains__u64__bool(void* l0, uint64_t l1);
static void std_collections_MutableMap_std_core_IndexSet_set_at__Any__bool(void* l0, vader_box_t l1, bool l2);
static void std_collections_MutableMap_std_core_IndexSet_set_at__u64__bool(void* l0, uint64_t l1, bool l2);
static void std_collections_clear__i32__bool(void* l0);
static bool std_collections_contains_key__Any__bool(void* l0, vader_box_t l1);
static bool std_collections_contains_key__i32__Any(void* l0, int32_t l1);
static bool std_collections_contains_key__i32__bool(void* l0, int32_t l1);
static bool std_collections_contains_key__i64__Any(void* l0, int64_t l1);
static bool std_collections_contains_key__i64__bool(void* l0, int64_t l1);
static bool std_collections_contains_key__i64__i64(void* l0, int64_t l1);
static bool std_collections_contains_key__string__Any(void* l0, vader_string_t l1);
static bool std_collections_contains_key__string__bool(void* l0, vader_string_t l1);
static bool std_collections_contains_key__u64__bool(void* l0, uint64_t l1);
static bool std_collections_contains_key__u64__vader_typecheck_ConstState(void* l0, uint64_t l1);
static void std_collections_ensure_index__Any__bool(void* l0);
static void std_collections_ensure_index__i32__Any(void* l0);
static void std_collections_ensure_index__i32__bool(void* l0);
static void std_collections_ensure_index__i32__i32(void* l0);
static void std_collections_ensure_index__i32__i64(void* l0);
static void std_collections_ensure_index__i32__std_collections_MutableMap_string__bool_(void* l0);
static void std_collections_ensure_index__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0);
static void std_collections_ensure_index__i32__string(void* l0);
static void std_collections_ensure_index__i32__string__(void* l0);
static void std_collections_ensure_index__i32__vader_comptime_ComptimeRoute(void* l0);
static void std_collections_ensure_index__i32__vader_resolver_ConstLocal(void* l0);
static void std_collections_ensure_index__i64__Any(void* l0);
static void std_collections_ensure_index__i64__bool(void* l0);
static void std_collections_ensure_index__i64__i32(void* l0);
static void std_collections_ensure_index__i64__i64(void* l0);
static void std_collections_ensure_index__i64__string(void* l0);
static void std_collections_ensure_index__string__Any(void* l0);
static void std_collections_ensure_index__string__bool(void* l0);
static void std_collections_ensure_index__string__i32(void* l0);
static void std_collections_ensure_index__string__i64(void* l0);
static void std_collections_ensure_index__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(void* l0);
static void std_collections_ensure_index__string__std_collections_MutableMap_string__bool_(void* l0);
static void std_collections_ensure_index__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(void* l0);
static void std_collections_ensure_index__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(void* l0);
static void std_collections_ensure_index__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(void* l0);
static void std_collections_ensure_index__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0);
static void std_collections_ensure_index__string__string(void* l0);
static void std_collections_ensure_index__string__string__(void* l0);
static void std_collections_ensure_index__u64__Any(void* l0);
static void std_collections_ensure_index__u64__bool(void* l0);
static void std_collections_ensure_index__u64__i32(void* l0);
static void std_collections_ensure_index__u64__i64(void* l0);
static void std_collections_ensure_index__u64__vader_typecheck_ConstState(void* l0);
static int64_t std_collections_first_slot(uint64_t l0, int64_t l1);
static vader_box_t std_collections_get__i32__Any(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__bool(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__i32(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__i64(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__std_collections_MutableMap_string__bool_(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__string(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__string__(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__vader_resolver_ConstLocal(void* l0, int32_t l1);
static vader_box_t std_collections_get__i64__Any(void* l0, int64_t l1);
static vader_box_t std_collections_get__i64__bool(void* l0, int64_t l1);
static vader_box_t std_collections_get__i64__i32(void* l0, int64_t l1);
static vader_box_t std_collections_get__i64__i64(void* l0, int64_t l1);
static vader_box_t std_collections_get__i64__string(void* l0, int64_t l1);
static vader_box_t std_collections_get__string__Any(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__bool(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__i32(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__i64(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__std_collections_MutableMap_string__bool_(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__string(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__string__(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__u64__Any(void* l0, uint64_t l1);
static vader_box_t std_collections_get__u64__i32(void* l0, uint64_t l1);
static vader_box_t std_collections_get__u64__i64(void* l0, uint64_t l1);
static vader_box_t std_collections_get__u64__vader_typecheck_ConstState(void* l0, uint64_t l1);
static int64_t std_collections_next_slot(int64_t l0, uint64_t l1, int64_t l2);
static void std_collections_put__Any__bool(void* l0, vader_box_t l1, bool l2);
static void std_collections_put__i32__Any(void* l0, int32_t l1, vader_box_t l2);
static void std_collections_put__i32__bool(void* l0, int32_t l1, bool l2);
static void std_collections_put__i32__i32(void* l0, int32_t l1, int32_t l2);
static void std_collections_put__i32__i64(void* l0, int32_t l1, int64_t l2);
static void std_collections_put__i32__std_collections_MutableMap_string__bool_(void* l0, int32_t l1, void* l2);
static void std_collections_put__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, int32_t l1, void* l2);
static void std_collections_put__i32__string(void* l0, int32_t l1, vader_string_t l2);
static void std_collections_put__i32__string__(void* l0, int32_t l1, void* l2);
static void std_collections_put__i32__vader_comptime_ComptimeRoute(void* l0, int32_t l1, uint8_t l2);
static void std_collections_put__i32__vader_resolver_ConstLocal(void* l0, int32_t l1, uint8_t l2);
static void std_collections_put__i64__Any(void* l0, int64_t l1, vader_box_t l2);
static void std_collections_put__i64__bool(void* l0, int64_t l1, bool l2);
static void std_collections_put__i64__i32(void* l0, int64_t l1, int32_t l2);
static void std_collections_put__i64__i64(void* l0, int64_t l1, int64_t l2);
static void std_collections_put__i64__string(void* l0, int64_t l1, vader_string_t l2);
static void std_collections_put__string__Any(void* l0, vader_string_t l1, vader_box_t l2);
static void std_collections_put__string__bool(void* l0, vader_string_t l1, bool l2);
static void std_collections_put__string__i32(void* l0, vader_string_t l1, int32_t l2);
static void std_collections_put__string__i64(void* l0, vader_string_t l1, int64_t l2);
static void std_collections_put__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__std_collections_MutableMap_string__bool_(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__string(void* l0, vader_string_t l1, vader_string_t l2);
static void std_collections_put__string__string__(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__u64__Any(void* l0, uint64_t l1, vader_box_t l2);
static void std_collections_put__u64__bool(void* l0, uint64_t l1, bool l2);
static void std_collections_put__u64__i32(void* l0, uint64_t l1, int32_t l2);
static void std_collections_put__u64__i64(void* l0, uint64_t l1, int64_t l2);
static void std_collections_put__u64__vader_typecheck_ConstState(void* l0, uint64_t l1, uint8_t l2);
static void std_collections_rehash__Any__bool(void* l0, int64_t l1);
static void std_collections_rehash__i32__Any(void* l0, int64_t l1);
static void std_collections_rehash__i32__bool(void* l0, int64_t l1);
static void std_collections_rehash__i32__i32(void* l0, int64_t l1);
static void std_collections_rehash__i32__i64(void* l0, int64_t l1);
static void std_collections_rehash__i32__std_collections_MutableMap_string__bool_(void* l0, int64_t l1);
static void std_collections_rehash__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, int64_t l1);
static void std_collections_rehash__i32__string(void* l0, int64_t l1);
static void std_collections_rehash__i32__string__(void* l0, int64_t l1);
static void std_collections_rehash__i32__vader_comptime_ComptimeRoute(void* l0, int64_t l1);
static void std_collections_rehash__i32__vader_resolver_ConstLocal(void* l0, int64_t l1);
static void std_collections_rehash__i64__Any(void* l0, int64_t l1);
static void std_collections_rehash__i64__bool(void* l0, int64_t l1);
static void std_collections_rehash__i64__i32(void* l0, int64_t l1);
static void std_collections_rehash__i64__i64(void* l0, int64_t l1);
static void std_collections_rehash__i64__string(void* l0, int64_t l1);
static void std_collections_rehash__string__Any(void* l0, int64_t l1);
static void std_collections_rehash__string__bool(void* l0, int64_t l1);
static void std_collections_rehash__string__i32(void* l0, int64_t l1);
static void std_collections_rehash__string__i64(void* l0, int64_t l1);
static void std_collections_rehash__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(void* l0, int64_t l1);
static void std_collections_rehash__string__std_collections_MutableMap_string__bool_(void* l0, int64_t l1);
static void std_collections_rehash__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(void* l0, int64_t l1);
static void std_collections_rehash__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(void* l0, int64_t l1);
static void std_collections_rehash__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(void* l0, int64_t l1);
static void std_collections_rehash__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, int64_t l1);
static void std_collections_rehash__string__string(void* l0, int64_t l1);
static void std_collections_rehash__string__string__(void* l0, int64_t l1);
static void std_collections_rehash__u64__Any(void* l0, int64_t l1);
static void std_collections_rehash__u64__bool(void* l0, int64_t l1);
static void std_collections_rehash__u64__i32(void* l0, int64_t l1);
static void std_collections_rehash__u64__i64(void* l0, int64_t l1);
static void std_collections_rehash__u64__vader_typecheck_ConstState(void* l0, int64_t l1);
static bool std_collections_remove__i32__bool(void* l0, int32_t l1);
static bool std_collections_remove__i64__bool(void* l0, int64_t l1);
static bool std_collections_remove__u64__bool(void* l0, uint64_t l1);
static int64_t std_collections_slot_holding__i32__bool(void* l0, int32_t l1, int32_t l2);
static int64_t std_collections_slot_holding__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall(void* l0, int32_t l1, int32_t l2);
static int64_t std_collections_slot_holding__i32__vader_typecheck_NarrowSlot(void* l0, int32_t l1, int32_t l2);
static int64_t std_collections_slot_holding__i64__bool(void* l0, int64_t l1, int32_t l2);
static int64_t std_collections_slot_holding__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall(void* l0, int64_t l1, int32_t l2);
static int64_t std_collections_slot_holding__string__vader_typecheck_NarrowSlot(void* l0, vader_string_t l1, int32_t l2);
static int64_t std_collections_slot_holding__u64__bool(void* l0, uint64_t l1, int32_t l2);
static void std_collections_write_entry__Any__bool(void* l0, vader_box_t l1, bool l2);
static void std_collections_write_entry__i32__Any(void* l0, int32_t l1, vader_box_t l2);
static void std_collections_write_entry__i32__bool(void* l0, int32_t l1, bool l2);
static void std_collections_write_entry__i32__i32(void* l0, int32_t l1, int32_t l2);
static void std_collections_write_entry__i32__i64(void* l0, int32_t l1, int64_t l2);
static void std_collections_write_entry__i32__std_collections_MutableMap_string__bool_(void* l0, int32_t l1, void* l2);
static void std_collections_write_entry__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, int32_t l1, void* l2);
static void std_collections_write_entry__i32__string(void* l0, int32_t l1, vader_string_t l2);
static void std_collections_write_entry__i32__string__(void* l0, int32_t l1, void* l2);
static void std_collections_write_entry__i32__vader_comptime_ComptimeRoute(void* l0, int32_t l1, uint8_t l2);
static void std_collections_write_entry__i32__vader_resolver_ConstLocal(void* l0, int32_t l1, uint8_t l2);
static void std_collections_write_entry__i64__Any(void* l0, int64_t l1, vader_box_t l2);
static void std_collections_write_entry__i64__bool(void* l0, int64_t l1, bool l2);
static void std_collections_write_entry__i64__i32(void* l0, int64_t l1, int32_t l2);
static void std_collections_write_entry__i64__i64(void* l0, int64_t l1, int64_t l2);
static void std_collections_write_entry__i64__string(void* l0, int64_t l1, vader_string_t l2);
static void std_collections_write_entry__string__Any(void* l0, vader_string_t l1, vader_box_t l2);
static void std_collections_write_entry__string__bool(void* l0, vader_string_t l1, bool l2);
static void std_collections_write_entry__string__i32(void* l0, vader_string_t l1, int32_t l2);
static void std_collections_write_entry__string__i64(void* l0, vader_string_t l1, int64_t l2);
static void std_collections_write_entry__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__std_collections_MutableMap_string__bool_(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__string(void* l0, vader_string_t l1, vader_string_t l2);
static void std_collections_write_entry__string__string__(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__u64__Any(void* l0, uint64_t l1, vader_box_t l2);
static void std_collections_write_entry__u64__bool(void* l0, uint64_t l1, bool l2);
static void std_collections_write_entry__u64__i32(void* l0, uint64_t l1, int32_t l2);
static void std_collections_write_entry__u64__i64(void* l0, uint64_t l1, int64_t l2);
static void std_collections_write_entry__u64__vader_typecheck_ConstState(void* l0, uint64_t l1, uint8_t l2);

static bool std_collections_MutableMap_std_core_Contains_contains__Any__bool(void* l0, vader_box_t l1) {
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_contains_key__Any__bool(l0, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool std_collections_MutableMap_std_core_Contains_contains__i32__Any(void* l0, int32_t l1) {
    bool t0;
    t0 = std_collections_contains_key__i32__Any(l0, l1);
    return t0;
}

static bool std_collections_MutableMap_std_core_Contains_contains__i32__bool(void* l0, int32_t l1) {
    bool t0;
    t0 = std_collections_contains_key__i32__bool(l0, l1);
    return t0;
}

bool std_collections_MutableMap_std_core_Contains_contains__i64__Any(void* l0, int64_t l1) {
    bool t0;
    t0 = std_collections_contains_key__i64__Any(l0, l1);
    return t0;
}

static bool std_collections_MutableMap_std_core_Contains_contains__i64__bool(void* l0, int64_t l1) {
    bool t0;
    t0 = std_collections_contains_key__i64__bool(l0, l1);
    return t0;
}

bool std_collections_MutableMap_std_core_Contains_contains__i64__i64(void* l0, int64_t l1) {
    bool t0;
    t0 = std_collections_contains_key__i64__i64(l0, l1);
    return t0;
}

bool std_collections_MutableMap_std_core_Contains_contains__string__Any(void* l0, vader_string_t l1) {
    bool t0;
    t0 = std_collections_contains_key__string__Any(l0, l1);
    return t0;
}

static bool std_collections_MutableMap_std_core_Contains_contains__string__bool(void* l0, vader_string_t l1) {
    bool t0;
    t0 = std_collections_contains_key__string__bool(l0, l1);
    return t0;
}

static bool std_collections_MutableMap_std_core_Contains_contains__u64__bool(void* l0, uint64_t l1) {
    bool t0;
    t0 = std_collections_contains_key__u64__bool(l0, l1);
    return t0;
}

bool std_collections_MutableMap_std_core_Contains_contains__u64__vader_typecheck_ConstState(void* l0, uint64_t l1) {
    bool t0;
    t0 = std_collections_contains_key__u64__vader_typecheck_ConstState(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i32__Any(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__Any(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i32__bool(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__bool(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i32__i32(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__i32(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i32__i64(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__i64(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i32__std_collections_MutableMap_string__bool_(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__std_collections_MutableMap_string__bool_(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i32__string(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__string(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i32__string__(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__string__(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i32__vader_resolver_ConstLocal(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__vader_resolver_ConstLocal(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i64__Any(void* l0, int64_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i64__Any(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i64__bool(void* l0, int64_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i64__bool(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i64__i32(void* l0, int64_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i64__i32(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i64__i64(void* l0, int64_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i64__i64(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__i64__string(void* l0, int64_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i64__string(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__string__Any(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__Any(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__string__bool(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__bool(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__string__i32(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__i32(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__string__i64(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__i64(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__string__std_collections_MutableMap_string__bool_(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__std_collections_MutableMap_string__bool_(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__string__string(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__string(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__string__string__(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__string__(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__u64__Any(void* l0, uint64_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__u64__Any(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__u64__i32(void* l0, uint64_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__u64__i32(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__u64__i64(void* l0, uint64_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__u64__i64(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_std_core_Index_at__u64__vader_typecheck_ConstState(void* l0, uint64_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__u64__vader_typecheck_ConstState(l0, l1);
    return t0;
}

static void std_collections_MutableMap_std_core_IndexSet_set_at__Any__bool(void* l0, vader_box_t l1, bool l2) {
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__Any__bool(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(void* l0, int32_t l1, vader_box_t l2) {
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__Any(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i32__bool(void* l0, int32_t l1, bool l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__bool(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i32__i32(void* l0, int32_t l1, int32_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__i32(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i32__i64(void* l0, int32_t l1, int64_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__i64(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i32__std_collections_MutableMap_string__bool_(void* l0, int32_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__std_collections_MutableMap_string__bool_(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, int32_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i32__string(void* l0, int32_t l1, vader_string_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__string(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i32__string__(void* l0, int32_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__string__(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i32__vader_comptime_ComptimeRoute(void* l0, int32_t l1, uint8_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__vader_comptime_ComptimeRoute(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i32__vader_resolver_ConstLocal(void* l0, int32_t l1, uint8_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__vader_resolver_ConstLocal(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i64__Any(void* l0, int64_t l1, vader_box_t l2) {
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i64__Any(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i64__bool(void* l0, int64_t l1, bool l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i64__bool(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i64__i32(void* l0, int64_t l1, int32_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i64__i32(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i64__i64(void* l0, int64_t l1, int64_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i64__i64(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__i64__string(void* l0, int64_t l1, vader_string_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__i64__string(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(void* l0, vader_string_t l1, vader_box_t l2) {
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__Any(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__string__bool(void* l0, vader_string_t l1, bool l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__bool(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(void* l0, vader_string_t l1, int32_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__i32(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__string__i64(void* l0, vader_string_t l1, int64_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__i64(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__string__std_collections_MutableMap_string__bool_(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__std_collections_MutableMap_string__bool_(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__string__string(void* l0, vader_string_t l1, vader_string_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__string(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__string__string__(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__string__(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__u64__Any(void* l0, uint64_t l1, vader_box_t l2) {
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__u64__Any(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_MutableMap_std_core_IndexSet_set_at__u64__bool(void* l0, uint64_t l1, bool l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__u64__bool(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__u64__i32(void* l0, uint64_t l1, int32_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__u64__i32(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__u64__i64(void* l0, uint64_t l1, int64_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__u64__i64(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_std_core_IndexSet_set_at__u64__vader_typecheck_ConstState(void* l0, uint64_t l1, uint8_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__u64__vader_typecheck_ConstState(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

bool std_collections_MutableSet_std_core_Contains_contains__i32(void* l0, int32_t l1) {
    bool t0;
    t0 = std_collections_MutableMap_std_core_Contains_contains__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner, l1);
    return t0;
}

bool std_collections_MutableSet_std_core_Contains_contains__i64(void* l0, int64_t l1) {
    bool t0;
    t0 = std_collections_MutableMap_std_core_Contains_contains__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) l0)->f_inner, l1);
    return t0;
}

bool std_collections_MutableSet_std_core_Contains_contains__string(void* l0, vader_string_t l1) {
    bool t0;
    t0 = std_collections_MutableMap_std_core_Contains_contains__string__bool(((vader_struct_std_collections_MutableSet__string_t*) l0)->f_inner, l1);
    return t0;
}

bool std_collections_MutableSet_std_core_Contains_contains__u64(void* l0, uint64_t l1) {
    bool t0;
    t0 = std_collections_MutableMap_std_core_Contains_contains__u64__bool(((vader_struct_std_collections_MutableSet__u64_t*) l0)->f_inner, l1);
    return t0;
}

bool std_collections_add__i32(void* l0, int32_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableMap_std_core_Contains_contains__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner, l1);
    if (!(t0)) {
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner, l1, true);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

bool std_collections_add__i64(void* l0, int64_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableMap_std_core_Contains_contains__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) l0)->f_inner, l1);
    if (!(t0)) {
        std_collections_MutableMap_std_core_IndexSet_set_at__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) l0)->f_inner, l1, true);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

bool std_collections_add__string(void* l0, vader_string_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableMap_std_core_Contains_contains__string__bool(((vader_struct_std_collections_MutableSet__string_t*) l0)->f_inner, l1);
    if (!(t0)) {
        std_collections_MutableMap_std_core_IndexSet_set_at__string__bool(((vader_struct_std_collections_MutableSet__string_t*) l0)->f_inner, l1, true);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

bool std_collections_add__toolchain_span_Span(void* l0, vader_box_t l1) {
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableMap_std_core_Contains_contains__Any__bool(((vader_struct_std_collections_MutableSet__Any_t*) l0)->f_inner, l1);
    if (!(t0)) {
        std_collections_MutableMap_std_core_IndexSet_set_at__Any__bool(((vader_struct_std_collections_MutableSet__Any_t*) l0)->f_inner, l1, true);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

bool std_collections_add__u64(void* l0, uint64_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableMap_std_core_Contains_contains__u64__bool(((vader_struct_std_collections_MutableSet__u64_t*) l0)->f_inner, l1);
    if (!(t0)) {
        std_collections_MutableMap_std_core_IndexSet_set_at__u64__bool(((vader_struct_std_collections_MutableSet__u64_t*) l0)->f_inner, l1, true);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void std_collections_clear__i32__bool(void* l0) {
    int64_t l1, l2;
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size = INT64_C(0);
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs = INT64_C(0);
    l1 = INT64_C(0);
    l2 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int32_t) INT32_C(0);
        l1 = (l1 + INT64_C(1));
    }
    return;
}

void std_collections_clear__string__Any(void* l0) {
    int64_t l1, l2;
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size = INT64_C(0);
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs = INT64_C(0);
    l1 = INT64_C(0);
    l2 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int32_t) INT32_C(0);
        l1 = (l1 + INT64_C(1));
    }
    return;
}

void std_collections_clear__vader_midir_LocalId(void* l0) {
    std_collections_clear__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner);
    return;
}

static bool std_collections_contains_key__Any__bool(void* l0, vader_box_t l1) {
    uint64_t l2;
    int64_t l3, l4, l6;
    vader_box_t l5 = vader_box_null();
    int64_t t0;
    int32_t t1;
    bool t2;
    vader_box_t* gc_roots[2] = { &l1, &l5 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = vader_vt_std_core_Hash__hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                l5 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
                t2 = vader_vt_std_core_Equals__equals(l5, l1);
                if (t2) {
                    { vader_gc_top = gc_frame.prev; return true; }
                }
            }
            l2 = (l2 >> INT64_C(5));
            l6 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l6);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool std_collections_contains_key__i32__Any(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return false;
}

static bool std_collections_contains_key__i32__bool(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return false;
}

static bool std_collections_contains_key__i64__Any(void* l0, int64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return false;
}

static bool std_collections_contains_key__i64__bool(void* l0, int64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return false;
}

static bool std_collections_contains_key__i64__i64(void* l0, int64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return false;
}

static bool std_collections_contains_key__string__Any(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return false;
}

static bool std_collections_contains_key__string__bool(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return false;
}

static bool std_collections_contains_key__u64__bool(void* l0, uint64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return false;
}

static bool std_collections_contains_key__u64__vader_typecheck_ConstState(void* l0, uint64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return false;
}

static void std_collections_ensure_index__Any__bool(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__Any__bool_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__Any(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__Any_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__bool(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__i32(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__i32_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__i64(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__i64_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__std_collections_MutableMap_string__bool_(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__string(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__string_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__string__(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__string___t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__vader_comptime_ComptimeRoute(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__vader_resolver_ConstLocal(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i64__Any(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__Any_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i64__bool(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__bool_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i64__i32(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__i32_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i64__i64(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__i64_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i64__string(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__string_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__Any(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__Any_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__bool(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__bool_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__i32(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i32_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__i64(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i64_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__std_collections_MutableMap_string__bool_(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__string(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__string__(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string___t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__u64__Any(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__Any_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__u64__bool(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__bool_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__u64__i32(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__i32_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__u64__i64(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__i64_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__u64__vader_typecheck_ConstState(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = INT64_C(0);
        vader_array_t* _pc11_hdr = (vader_array_t*) l1;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l2 < INT64_C(16))) {
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (INT32_C(0));
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    _pc11_hdr = (vader_array_t*) l1;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                l2 = (l2 + INT64_C(1));
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0);
        l2 = INT64_C(15);
        ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int64_t std_collections_first_slot(uint64_t l0, int64_t l1) {
    return (((int64_t) (uint64_t) l0) & l1);
}

static vader_box_t std_collections_get__i32__Any(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return t2;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i32__bool(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    bool t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_box_bool(285u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4]);
                    t3 = t2.payload.b;
                    return vader_box_bool(285u, t3);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i32__i32(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    return vader_box_i32(290u, t1);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i32__i64(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    return vader_box_i64(291u, t0);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i32__std_collections_MutableMap_string__bool_(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    void* t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t2);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    void* t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t2);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i32__string(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
                    t3 = t2.payload.s;
                    return vader_box_string(287u, t3);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i32__string__(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    void* t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t2);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i32__vader_resolver_ConstLocal(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2, t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l4, 292u);
                    t3 = t2;
                    return t3;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i64__Any(void* l0, int64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return t2;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i64__bool(void* l0, int64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    bool t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_box_bool(285u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4]);
                    t3 = t2.payload.b;
                    return vader_box_bool(285u, t3);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i64__i32(void* l0, int64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    return vader_box_i32(290u, t1);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i64__i64(void* l0, int64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    return vader_box_i64(291u, t0);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i64__string(void* l0, int64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
                    t3 = t2.payload.s;
                    return vader_box_string(287u, t3);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__Any(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return t2;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__bool(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    bool t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_box_bool(285u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4]);
                    t4 = t2.payload.b;
                    return vader_box_bool(285u, t4);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__i32(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    return vader_box_i32(290u, t1);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__i64(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    return vader_box_i64(291u, t0);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    void* t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t4);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__std_collections_MutableMap_string__bool_(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    void* t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t4);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    void* t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t4);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    void* t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t4);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    void* t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t4);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    void* t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t4);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__string(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
                    t3 = t2.payload.s;
                    return vader_box_string(287u, t3);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__string__(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    void* t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t4);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__u64__Any(void* l0, uint64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return t2;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__u64__i32(void* l0, uint64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    return vader_box_i32(290u, t1);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__u64__i64(void* l0, uint64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    return vader_box_i64(291u, t0);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__u64__vader_typecheck_ConstState(void* l0, uint64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5;
    int64_t t0;
    int32_t t1;
    vader_box_t t2, t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l4, 292u);
                    t3 = t2;
                    return t3;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

bool std_collections_is_empty__i32(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__i32__Any(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__i32__bool(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__i64__Any(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__string(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__string__bool_t*) ((vader_struct_std_collections_MutableSet__string_t*) l0)->f_inner)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__string__Any(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__string__i64(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__u64__Any(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    return t0 == INT64_C(0);
}

void* std_collections_keys__i32__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    int32_t l4;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__i32__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l0)->f_size;
    vader_array_t* _pc14_hdr = (vader_array_t*) l1;
    size_t _pc14_len = _pc14_hdr->length;
    size_t _pc14_cap = (_pc14_hdr->offset == 0 && !vader_array_is_borrowed(_pc14_hdr) && _pc14_hdr->length >= _pc14_hdr->buf->length) ? _pc14_hdr->capacity : (size_t) 0;
    void* _pc14_slots = _pc14_hdr->buf->slots;
    for (;;) {
        if ((l2 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l0)->f_ekeys);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
            l4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l2];
            if (VADER_LIKELY(_pc14_len < _pc14_cap)) {
                ((int32_t*) _pc14_slots)[_pc14_len] = (int32_t) (l4);
                _pc14_len += 1;
            } else {
                _pc14_hdr->length = _pc14_len;
                if (_pc14_hdr->buf->length < _pc14_len) {
                    _pc14_hdr->buf->length = _pc14_len;
                }
                vader_array_push_i32((vader_array_t*) l1, l4);
                _pc14_hdr = (vader_array_t*) l1;
                _pc14_len = _pc14_hdr->length;
                _pc14_cap = (_pc14_hdr->offset == 0 && !vader_array_is_borrowed(_pc14_hdr) && _pc14_hdr->length >= _pc14_hdr->buf->length) ? _pc14_hdr->capacity : (size_t) 0;
                _pc14_slots = _pc14_hdr->buf->slots;
            }
            l2 = (l2 + INT64_C(1));
            continue;
        }
        _pc14_hdr->length = _pc14_len;
        if (_pc14_hdr->buf->length < _pc14_len) {
            _pc14_hdr->buf->length = _pc14_len;
        }
        break;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_keys__string___toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl___(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 287u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string___toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl____t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections_MutableMap__string___toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl____t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string___toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl____t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l2];
        l4 = t0.payload.s;
        vader_array_push((vader_array_t*) l1, vader_box_string(287u, l4));
        l2 = (l2 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_keys__string__vader_comptime_ArrayValue___vader_comptime_BoolValue___vader_comptime_CharValue___vader_comptime_FloatValue___vader_comptime_IntValue___vader_comptime_NullValue___vader_comptime_StringValue___vader_comptime_StructValue___vader_comptime_TypeValue___vader_comptime_VoidValue(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 287u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__vader_comptime_ArrayValue___vader_comptime_BoolValue___vader_comptime_CharValue___vader_comptime_FloatValue___vader_comptime_IntValue___vader_comptime_NullValue___vader_comptime_StringValue___vader_comptime_StructValue___vader_comptime_TypeValue___vader_comptime_VoidValue_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections_MutableMap__string__vader_comptime_ArrayValue___vader_comptime_BoolValue___vader_comptime_CharValue___vader_comptime_FloatValue___vader_comptime_IntValue___vader_comptime_NullValue___vader_comptime_StringValue___vader_comptime_StructValue___vader_comptime_TypeValue___vader_comptime_VoidValue_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__vader_comptime_ArrayValue___vader_comptime_BoolValue___vader_comptime_CharValue___vader_comptime_FloatValue___vader_comptime_IntValue___vader_comptime_NullValue___vader_comptime_StringValue___vader_comptime_StructValue___vader_comptime_TypeValue___vader_comptime_VoidValue_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l2];
        l4 = t0.payload.s;
        vader_array_push((vader_array_t*) l1, vader_box_string(287u, l4));
        l2 = (l2 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_keys__string__vader_lower_LoweredModule(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 287u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__vader_lower_LoweredModule_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections_MutableMap__string__vader_lower_LoweredModule_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__vader_lower_LoweredModule_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l2];
        l4 = t0.payload.s;
        vader_array_push((vader_array_t*) l1, vader_box_string(287u, l4));
        l2 = (l2 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_keys__string__vader_typecheck_TypedProgram(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 287u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l2];
        l4 = t0.payload.s;
        vader_array_push((vader_array_t*) l1, vader_box_string(287u, l4));
        l2 = (l2 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t std_collections_len__i32(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner)->f_size;
    return t0;
}

int64_t std_collections_len__i32__Any(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    return t0;
}

int64_t std_collections_len__i32__bool(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    return t0;
}

int64_t std_collections_len__i64(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) ((vader_struct_std_collections_MutableSet__i64_t*) l0)->f_inner)->f_size;
    return t0;
}

int64_t std_collections_len__i64__Any(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
    return t0;
}

int64_t std_collections_len__string(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__string__bool_t*) ((vader_struct_std_collections_MutableSet__string_t*) l0)->f_inner)->f_size;
    return t0;
}

int64_t std_collections_len__string__i64(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    return t0;
}

static int64_t std_collections_next_slot(int64_t l0, uint64_t l1, int64_t l2) {
    int64_t l3, l4;
    l3 = (l0 * INT64_C(5));
    l4 = ((int64_t) (uint64_t) l1);
    return (((l3 + l4) + INT64_C(1)) & l2);
}

static void std_collections_put__Any__bool(void* l0, vader_box_t l1, bool l2) {
    int64_t l3, l4, l5, l8;
    uint64_t l6;
    vader_box_t l7 = vader_box_null();
    void* l9 = NULL;
    int32_t l10;
    int64_t t0, t1;
    int32_t t2;
    bool t3;
    vader_box_t* gc_roots[2] = { &l1, &l7 };
    void** gc_raw_roots[2] = { &l0, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__Any__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__Any__bool(l0, l3);
    }
    l6 = vader_vt_std_core_Hash__hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
                t3 = vader_vt_std_core_Equals__equals(l7, l1);
                if (t3) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l8 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l8);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__Any__bool(l0, l1, l2);
    l9 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l10 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l9);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l10;
    t0 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__Any(void* l0, int32_t l1, vader_box_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__Any(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i32__Any(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__Any(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__bool(void* l0, int32_t l1, bool l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i32__bool(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__bool(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__i32(void* l0, int32_t l1, int32_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__i32(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i32__i32(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (int32_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__i32(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__i64(void* l0, int32_t l1, int64_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__i64(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i32__i64(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (int64_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__i64(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__std_collections_MutableMap_string__bool_(void* l0, int32_t l1, void* l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__std_collections_MutableMap_string__bool_(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i32__std_collections_MutableMap_string__bool_(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__std_collections_MutableMap_string__bool_(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, int32_t l1, void* l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__string(void* l0, int32_t l1, vader_string_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__string(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i32__string(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5] = vader_box_string(287u, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__string(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__string__(void* l0, int32_t l1, void* l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__string__(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i32__string__(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__string__(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__vader_comptime_ComptimeRoute(void* l0, int32_t l1, uint8_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__vader_comptime_ComptimeRoute(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i32__vader_comptime_ComptimeRoute(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (uint8_t) (int32_t) (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__vader_comptime_ComptimeRoute(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__vader_resolver_ConstLocal(void* l0, int32_t l1, uint8_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__vader_resolver_ConstLocal(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i32__vader_resolver_ConstLocal(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (uint8_t) (int32_t) (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__vader_resolver_ConstLocal(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i64__Any(void* l0, int64_t l1, vader_box_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i64__Any(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i64__Any(l0, l3);
    }
    l6 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i64__Any(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i64__bool(void* l0, int64_t l1, bool l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i64__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i64__bool(l0, l3);
    }
    l6 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i64__bool(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i64__i32(void* l0, int64_t l1, int32_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i64__i32(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i64__i32(l0, l3);
    }
    l6 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (int32_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i64__i32(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i64__i64(void* l0, int64_t l1, int64_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i64__i64(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i64__i64(l0, l3);
    }
    l6 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (int64_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i64__i64(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i64__string(void* l0, int64_t l1, vader_string_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i64__string(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__i64__string(l0, l3);
    }
    l6 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5] = vader_box_string(287u, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i64__string(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__Any(void* l0, vader_string_t l1, vader_box_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[2] = { &l2, &t3 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__Any(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__string__Any(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__Any(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__bool(void* l0, vader_string_t l1, bool l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__string__bool(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__bool(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__i32(void* l0, vader_string_t l1, int32_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__i32(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__string__i32(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (int32_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__i32(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__i64(void* l0, vader_string_t l1, int64_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__i64(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__string__i64(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (int64_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__i64(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__std_collections_MutableMap_string__bool_(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__std_collections_MutableMap_string__bool_(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__string__std_collections_MutableMap_string__bool_(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__std_collections_MutableMap_string__bool_(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__string(void* l0, vader_string_t l1, vader_string_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__string(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__string__string(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5] = vader_box_string(287u, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__string(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__string__(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__string__(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__string__string__(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__string__(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__u64__Any(void* l0, uint64_t l1, vader_box_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__u64__Any(l0);
    l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__u64__Any(l0, l3);
    }
    l6 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__u64__Any(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__u64__bool(void* l0, uint64_t l1, bool l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__u64__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__u64__bool(l0, l3);
    }
    l6 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__u64__bool(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__u64__i32(void* l0, uint64_t l1, int32_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__u64__i32(l0);
    l3 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__u64__i32(l0, l3);
    }
    l6 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (int32_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__u64__i32(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__u64__i64(void* l0, uint64_t l1, int64_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__u64__i64(l0);
    l3 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__u64__i64(l0, l3);
    }
    l6 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (int64_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__u64__i64(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__u64__vader_typecheck_ConstState(void* l0, uint64_t l1, uint8_t l2) {
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__u64__vader_typecheck_ConstState(l0);
    l3 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_tombs;
    t0 = vader_chk_add(i64, l3, l4);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l3 = vader_chk_mul(i64, t1, INT64_C(4));
    t0 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_mask;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l4 = vader_chk_mul(i64, t1, INT64_C(3));
    if ((l3 > l4)) {
        l3 = INT64_C(16);
        for (;;) {
            t0 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_size;
            t1 = vader_chk_add(i64, t0, INT64_C(1));
            l4 = vader_chk_mul(i64, t1, INT64_C(4));
            l5 = vader_chk_mul(i64, l3, INT64_C(3));
            if ((l4 > l5)) {
                l3 = vader_chk_mul(i64, l3, INT64_C(2));
                continue;
            }
            break;
        }
        std_collections_rehash__u64__vader_typecheck_ConstState(l0, l3);
    }
    l6 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l4 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t2 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t2 == INT32_C(-1)) {
                if ((l4 < INT64_C(0))) {
                    l4 = l3;
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                l5 = vader_chk_sub(i64, ((int64_t) (int32_t) t2), INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5] = (uint8_t) (int32_t) (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l7 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l7);
            continue;
        }
        break;
    }
    if ((l4 >= INT64_C(0))) {
        l5 = l4;
    } else {
        l5 = l3;
    }
    if ((l4 >= INT64_C(0))) {
        t0 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_tombs;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__u64__vader_typecheck_ConstState(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_index;
    t0 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_size;
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l9;
    t0 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_size;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__Any__bool(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l6 = vader_vt_std_core_Hash__hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t1 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t2 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t2);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__Any__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__Any(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t0 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t0 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__bool(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t0 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t0 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__i32(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t0 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t0 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__i64(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t0 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t0 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__i64_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__std_collections_MutableMap_string__bool_(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t0 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t0 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t0 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t0 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__string(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t0 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t0 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__string_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__string__(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t0 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t0 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__string___t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__vader_comptime_ComptimeRoute(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t0 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t0 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__vader_resolver_ConstLocal(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t0 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t0 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i64__Any(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i64_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t1 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t0 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t0);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i64__bool(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i64_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t1 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t0 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t0);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i64__i32(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i64_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t1 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t0 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t0);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i64__i64(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i64_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t1 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t0 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t0);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__i64_t*) l0);
    ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i64__string(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i64_Hash_hash(t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t1 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t0 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t0);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__string_t*) l0);
    ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__Any(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        l6 = std_core_string_Hash_hash_vt(t1);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t2 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t3 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t3);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__bool(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        l6 = std_core_string_Hash_hash_vt(t1);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t2 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t3 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t3);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__i32(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        l6 = std_core_string_Hash_hash_vt(t1);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t2 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t3 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t3);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__i64(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        l6 = std_core_string_Hash_hash_vt(t1);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t2 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t3 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t3);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i64_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        l6 = std_core_string_Hash_hash_vt(t1);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t2 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t3 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t3);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0);
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__std_collections_MutableMap_string__bool_(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        l6 = std_core_string_Hash_hash_vt(t1);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t2 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t3 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t3);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0);
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        l6 = std_core_string_Hash_hash_vt(t1);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t2 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t3 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t3);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0);
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        l6 = std_core_string_Hash_hash_vt(t1);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t2 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t3 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t3);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0);
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        l6 = std_core_string_Hash_hash_vt(t1);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t2 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t3 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t3);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0);
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        l6 = std_core_string_Hash_hash_vt(t1);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t2 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t3 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t3);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0);
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__string(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        l6 = std_core_string_Hash_hash_vt(t1);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t2 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t3 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t3);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__string__(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        l6 = std_core_string_Hash_hash_vt(t1);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t2 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t3 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t3);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string___t*) l0);
    ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__u64__Any(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_u64_Hash_hash((uint64_t) (int64_t) t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t1 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t0 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t0);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__u64__bool(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_u64_Hash_hash((uint64_t) (int64_t) t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t1 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t0 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t0);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__u64__i32(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_u64_Hash_hash((uint64_t) (int64_t) t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t1 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t0 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t0);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__u64__i64(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_u64_Hash_hash((uint64_t) (int64_t) t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t1 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t0 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t0);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__i64_t*) l0);
    ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__u64__vader_typecheck_ConstState(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l2;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(0));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc18_hdr = (vader_array_t*) l2;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_u64_Hash_hash((uint64_t) (int64_t) t0);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t1 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t0 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t0);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0);
    ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_tombs = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

bool std_collections_remove__i32(void* l0, int32_t l1) {
    bool t0;
    t0 = std_collections_remove__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner, l1);
    return t0;
}

static bool std_collections_remove__i32__bool(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5, l8, l15, l16, l17;
    int32_t l6, l7, l10, l14;
    void* l9;
    void* l11;
    void* l13;
    bool l12;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
                    l5 = vader_chk_sub(i64, t0, INT64_C(1));
                    if (l4 != l5) {
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                        l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                        t0 = vader_chk_add(i64, l5, INT64_C(1));
                        l7 = ((int32_t) (int64_t) t0);
                        l8 = std_collections_slot_holding__i32__bool(l0, l6, l7);
                        l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
                        l10 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                        ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4] = (int32_t) l10;
                        l11 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                        t2 = vader_box_bool(285u, ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5]);
                        l12 = t2.payload.b;
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                        ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (uint8_t) l12;
                        l13 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index;
                        t0 = vader_chk_add(i64, l4, INT64_C(1));
                        l14 = ((int32_t) (int64_t) t0);
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
                        ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8] = (int32_t) l14;
                    }
                    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs;
                    l15 = vader_chk_add(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs = l15;
                    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
                    l16 = vader_chk_sub(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size = l16;
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l17 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l17);
            continue;
        }
        break;
    }
    return false;
}

bool std_collections_remove__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5, l8, l15, l16, l17;
    int32_t l6, l7, l10, l14;
    void* l9;
    void* l11;
    void* l13;
    vader_box_t l12;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    t0 = ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_size;
                    l5 = vader_chk_sub(i64, t0, INT64_C(1));
                    if (l4 != l5) {
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                        l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                        t0 = vader_chk_add(i64, l5, INT64_C(1));
                        l7 = ((int32_t) (int64_t) t0);
                        l8 = std_collections_slot_holding__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall(l0, l6, l7);
                        l9 = ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_ekeys;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_ekeys);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
                        l10 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                        ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4] = (int32_t) l10;
                        l11 = ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_evals;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_evals);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                        l12 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                        vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4, l12.payload.obj);
                        VADER_WRITE_BARRIER(_a5_slotarr->buf);
                        l13 = ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_index;
                        t0 = vader_chk_add(i64, l4, INT64_C(1));
                        l14 = ((int32_t) (int64_t) t0);
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
                        ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8] = (int32_t) l14;
                    }
                    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_index);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                    t0 = ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_tombs;
                    l15 = vader_chk_add(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_tombs = l15;
                    t0 = ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_size;
                    l16 = vader_chk_sub(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_size = l16;
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l17 = ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l17);
            continue;
        }
        break;
    }
    return false;
}

bool std_collections_remove__i32__vader_typecheck_NarrowSlot(void* l0, int32_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5, l8, l15, l16, l17;
    int32_t l6, l7, l10, l14;
    void* l9;
    void* l11;
    void* l12;
    void* l13;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    t0 = ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_size;
                    l5 = vader_chk_sub(i64, t0, INT64_C(1));
                    if (l4 != l5) {
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                        l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                        t0 = vader_chk_add(i64, l5, INT64_C(1));
                        l7 = ((int32_t) (int64_t) t0);
                        l8 = std_collections_slot_holding__i32__vader_typecheck_NarrowSlot(l0, l6, l7);
                        l9 = ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_ekeys;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_ekeys);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
                        l10 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                        ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4] = (int32_t) l10;
                        l11 = ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_evals;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_evals);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                        l12 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                        vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4, l12);
                        VADER_WRITE_BARRIER(_a5_slotarr->buf);
                        l13 = ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_index;
                        t0 = vader_chk_add(i64, l4, INT64_C(1));
                        l14 = ((int32_t) (int64_t) t0);
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
                        ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8] = (int32_t) l14;
                    }
                    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_index);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                    t0 = ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_tombs;
                    l15 = vader_chk_add(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_tombs = l15;
                    t0 = ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_size;
                    l16 = vader_chk_sub(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_size = l16;
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l17 = ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l17);
            continue;
        }
        break;
    }
    return false;
}

bool std_collections_remove__i64(void* l0, int64_t l1) {
    bool t0;
    t0 = std_collections_remove__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) l0)->f_inner, l1);
    return t0;
}

static bool std_collections_remove__i64__bool(void* l0, int64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5, l6, l8, l10, l15, l16, l17;
    int32_t l7, l14;
    void* l9;
    void* l11;
    void* l13;
    bool l12;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    t0 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
                    l5 = vader_chk_sub(i64, t0, INT64_C(1));
                    if (l4 != l5) {
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                        l6 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                        t0 = vader_chk_add(i64, l5, INT64_C(1));
                        l7 = ((int32_t) (int64_t) t0);
                        l8 = std_collections_slot_holding__i64__bool(l0, l6, l7);
                        l9 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
                        l10 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                        ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4] = (int64_t) l10;
                        l11 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_evals;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_evals);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                        t2 = vader_box_bool(285u, ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5]);
                        l12 = t2.payload.b;
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                        ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (uint8_t) l12;
                        l13 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index;
                        t0 = vader_chk_add(i64, l4, INT64_C(1));
                        l14 = ((int32_t) (int64_t) t0);
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
                        ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8] = (int32_t) l14;
                    }
                    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                    t0 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs;
                    l15 = vader_chk_add(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs = l15;
                    t0 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
                    l16 = vader_chk_sub(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size = l16;
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l17 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l17);
            continue;
        }
        break;
    }
    return false;
}

bool std_collections_remove__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall(void* l0, int64_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5, l6, l8, l10, l15, l16, l17;
    int32_t l7, l14;
    void* l9;
    void* l11;
    void* l13;
    vader_box_t l12;
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    t0 = ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_size;
                    l5 = vader_chk_sub(i64, t0, INT64_C(1));
                    if (l4 != l5) {
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                        l6 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                        t0 = vader_chk_add(i64, l5, INT64_C(1));
                        l7 = ((int32_t) (int64_t) t0);
                        l8 = std_collections_slot_holding__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall(l0, l6, l7);
                        l9 = ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_ekeys;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_ekeys);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
                        l10 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                        ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4] = (int64_t) l10;
                        l11 = ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_evals;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_evals);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                        l12 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                        vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4, l12.payload.obj);
                        VADER_WRITE_BARRIER(_a5_slotarr->buf);
                        l13 = ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_index;
                        t0 = vader_chk_add(i64, l4, INT64_C(1));
                        l14 = ((int32_t) (int64_t) t0);
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
                        ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8] = (int32_t) l14;
                    }
                    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_index);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                    t0 = ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_tombs;
                    l15 = vader_chk_add(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_tombs = l15;
                    t0 = ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_size;
                    l16 = vader_chk_sub(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_size = l16;
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l17 = ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l17);
            continue;
        }
        break;
    }
    return false;
}

bool std_collections_remove__string__vader_typecheck_NarrowSlot(void* l0, vader_string_t l1) {
    uint64_t l2;
    int64_t l3, l4, l5, l8, l15, l16, l17;
    vader_string_t l6, l10;
    int32_t l7, l14;
    void* l9;
    void* l11;
    void* l12;
    void* l13;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t3 = t2.payload.s;
                if (t3 == l1) {
                    t0 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_size;
                    l5 = vader_chk_sub(i64, t0, INT64_C(1));
                    if (l4 != l5) {
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                        t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l5];
                        l6 = t2.payload.s;
                        t0 = vader_chk_add(i64, l5, INT64_C(1));
                        l7 = ((int32_t) (int64_t) t0);
                        l8 = std_collections_slot_holding__string__vader_typecheck_NarrowSlot(l0, l6, l7);
                        l9 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_ekeys;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_ekeys);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
                        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l5];
                        l10 = t2.payload.s;
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                        vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4] = vader_box_string(287u, l10);
                        VADER_WRITE_BARRIER(_a3_slotarr->buf);
                        l11 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_evals;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_evals);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                        l12 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                        vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4, l12);
                        VADER_WRITE_BARRIER(_a5_slotarr->buf);
                        l13 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_index;
                        t0 = vader_chk_add(i64, l4, INT64_C(1));
                        l14 = ((int32_t) (int64_t) t0);
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
                        ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8] = (int32_t) l14;
                    }
                    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_index);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                    t0 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_tombs;
                    l15 = vader_chk_add(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_tombs = l15;
                    t0 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_size;
                    l16 = vader_chk_sub(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_size = l16;
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l17 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l17);
            continue;
        }
        break;
    }
    return false;
}

bool std_collections_remove__u64(void* l0, uint64_t l1) {
    bool t0;
    t0 = std_collections_remove__u64__bool(((vader_struct_std_collections_MutableSet__u64_t*) l0)->f_inner, l1);
    return t0;
}

static bool std_collections_remove__u64__bool(void* l0, uint64_t l1) {
    uint64_t l2, l6, l10;
    int64_t l3, l4, l5, l8, l15, l16, l17;
    int32_t l7, l14;
    void* l9;
    void* l11;
    void* l13;
    bool l12;
    int64_t t0;
    int32_t t1;
    vader_box_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                l4 = vader_chk_sub(i64, ((int64_t) (int32_t) t1), INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    t0 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
                    l5 = vader_chk_sub(i64, t0, INT64_C(1));
                    if (l4 != l5) {
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                        t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                        l6 = (uint64_t) (int64_t) t0;
                        t0 = vader_chk_add(i64, l5, INT64_C(1));
                        l7 = ((int32_t) (int64_t) t0);
                        l8 = std_collections_slot_holding__u64__bool(l0, l6, l7);
                        l9 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
                        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                        l10 = (uint64_t) (int64_t) t0;
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                        ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4] = (int64_t) (int64_t) (uint64_t) l10;
                        l11 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_evals;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_evals);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                        t2 = vader_box_bool(285u, ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5]);
                        l12 = t2.payload.b;
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                        ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (uint8_t) l12;
                        l13 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index;
                        t0 = vader_chk_add(i64, l4, INT64_C(1));
                        l14 = ((int32_t) (int64_t) t0);
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
                        ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8] = (int32_t) l14;
                    }
                    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                    t0 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_tombs;
                    l15 = vader_chk_add(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_tombs = l15;
                    t0 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
                    l16 = vader_chk_sub(i64, t0, INT64_C(1));
                    ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size = l16;
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l17 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l17);
            continue;
        }
        break;
    }
    return false;
}

static int64_t std_collections_slot_holding__i32__bool(void* l0, int32_t l1, int32_t l2) {
    uint64_t l3;
    int64_t l4, l5;
    int32_t t0;
    int64_t t1;
    l3 = std_core_i32_Hash_hash(l1);
    l4 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    l4 = std_collections_first_slot(l3, l4);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        if (t0 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
            if (t0 == l2) {
                return l4;
            }
            l3 = (l3 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
            l4 = std_collections_next_slot(l4, l3, l5);
            continue;
        }
        break;
    }
    t1 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    return t1;
}

static int64_t std_collections_slot_holding__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall(void* l0, int32_t l1, int32_t l2) {
    uint64_t l3;
    int64_t l4, l5;
    int32_t t0;
    int64_t t1;
    l3 = std_core_i32_Hash_hash(l1);
    l4 = ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_mask;
    l4 = std_collections_first_slot(l3, l4);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        if (t0 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
            if (t0 == l2) {
                return l4;
            }
            l3 = (l3 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_mask;
            l4 = std_collections_next_slot(l4, l3, l5);
            continue;
        }
        break;
    }
    t1 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_index)->length;
    return t1;
}

static int64_t std_collections_slot_holding__i32__vader_typecheck_NarrowSlot(void* l0, int32_t l1, int32_t l2) {
    uint64_t l3;
    int64_t l4, l5;
    int32_t t0;
    int64_t t1;
    l3 = std_core_i32_Hash_hash(l1);
    l4 = ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_mask;
    l4 = std_collections_first_slot(l3, l4);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        if (t0 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
            if (t0 == l2) {
                return l4;
            }
            l3 = (l3 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_mask;
            l4 = std_collections_next_slot(l4, l3, l5);
            continue;
        }
        break;
    }
    t1 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_typecheck_NarrowSlot_t*) l0)->f_index)->length;
    return t1;
}

static int64_t std_collections_slot_holding__i64__bool(void* l0, int64_t l1, int32_t l2) {
    uint64_t l3;
    int64_t l4, l5;
    int32_t t0;
    int64_t t1;
    l3 = std_core_i64_Hash_hash(l1);
    l4 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
    l4 = std_collections_first_slot(l3, l4);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        if (t0 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
            if (t0 == l2) {
                return l4;
            }
            l3 = (l3 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
            l4 = std_collections_next_slot(l4, l3, l5);
            continue;
        }
        break;
    }
    t1 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index)->length;
    return t1;
}

static int64_t std_collections_slot_holding__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall(void* l0, int64_t l1, int32_t l2) {
    uint64_t l3;
    int64_t l4, l5;
    int32_t t0;
    int64_t t1;
    l3 = std_core_i64_Hash_hash(l1);
    l4 = ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_mask;
    l4 = std_collections_first_slot(l3, l4);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        if (t0 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
            if (t0 == l2) {
                return l4;
            }
            l3 = (l3 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_mask;
            l4 = std_collections_next_slot(l4, l3, l5);
            continue;
        }
        break;
    }
    t1 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__vader_lower_LoweredArrayLen___vader_lower_LoweredArrayLit___vader_lower_LoweredArrayPush___vader_lower_LoweredArraySlice___vader_lower_LoweredBinary___vader_lower_LoweredBlock___vader_lower_LoweredBoolLit___vader_lower_LoweredCall___vader_lower_LoweredCast___vader_lower_LoweredCellGet___vader_lower_LoweredCellNew___vader_lower_LoweredCharLit___vader_lower_LoweredDataConst___vader_lower_LoweredFieldAccess___vader_lower_LoweredFloatLit___vader_lower_LoweredGlobalGet___vader_lower_LoweredIdent___vader_lower_LoweredIf___vader_lower_LoweredIndex___vader_lower_LoweredIntLit___vader_lower_LoweredIntrinsicCall___vader_lower_LoweredMakeClosure___vader_lower_LoweredNullLit___vader_lower_LoweredStringLit___vader_lower_LoweredStructLit___vader_lower_LoweredTypeCheck___vader_lower_LoweredTypeConst___vader_lower_LoweredUnary___vader_lower_LoweredUnionField___vader_lower_LoweredUnreachable___vader_lower_LoweredVirtualCall_t*) l0)->f_index)->length;
    return t1;
}

static int64_t std_collections_slot_holding__string__vader_typecheck_NarrowSlot(void* l0, vader_string_t l1, int32_t l2) {
    uint64_t l3;
    int64_t l4, l5;
    int32_t t0;
    int64_t t1;
    l3 = std_core_string_Hash_hash_vt(l1);
    l4 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_mask;
    l4 = std_collections_first_slot(l3, l4);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        if (t0 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
            if (t0 == l2) {
                return l4;
            }
            l3 = (l3 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_mask;
            l4 = std_collections_next_slot(l4, l3, l5);
            continue;
        }
        break;
    }
    t1 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__vader_typecheck_NarrowSlot_t*) l0)->f_index)->length;
    return t1;
}

static int64_t std_collections_slot_holding__u64__bool(void* l0, uint64_t l1, int32_t l2) {
    uint64_t l3;
    int64_t l4, l5;
    int32_t t0;
    int64_t t1;
    l3 = std_core_u64_Hash_hash(l1);
    l4 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask;
    l4 = std_collections_first_slot(l3, l4);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        if (t0 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
            if (t0 == l2) {
                return l4;
            }
            l3 = (l3 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask;
            l4 = std_collections_next_slot(l4, l3, l5);
            continue;
        }
        break;
    }
    t1 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index)->length;
    return t1;
}

void* std_collections_values__i32__vader_lower_ConstFnWrap(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int64_t l2, l3;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(111u, 0u, 13u, 965u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__i32__vader_lower_ConstFnWrap_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__vader_lower_ConstFnWrap_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_lower_ConstFnWrap_t*) l0)->f_evals);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
        vader_array_push((vader_array_t*) l1, vader_ref_box(l4));
        l2 = (l2 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_values__i64__vader_typecheck_BoundMember___vader_typecheck_Builtin___vader_typecheck_DirectFn___vader_typecheck_EachOf___vader_typecheck_ErroneousCallee___vader_typecheck_FnValue___vader_typecheck_TraitMember___vader_typecheck_UnsettledCallee(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_box_t l4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(245u, 0u, 13u, 1787u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__i64__vader_typecheck_BoundMember___vader_typecheck_Builtin___vader_typecheck_DirectFn___vader_typecheck_EachOf___vader_typecheck_ErroneousCallee___vader_typecheck_FnValue___vader_typecheck_TraitMember___vader_typecheck_UnsettledCallee_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections_MutableMap__i64__vader_typecheck_BoundMember___vader_typecheck_Builtin___vader_typecheck_DirectFn___vader_typecheck_EachOf___vader_typecheck_ErroneousCallee___vader_typecheck_FnValue___vader_typecheck_TraitMember___vader_typecheck_UnsettledCallee_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__vader_typecheck_BoundMember___vader_typecheck_Builtin___vader_typecheck_DirectFn___vader_typecheck_EachOf___vader_typecheck_ErroneousCallee___vader_typecheck_FnValue___vader_typecheck_TraitMember___vader_typecheck_UnsettledCallee_t*) l0)->f_evals);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        l4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
        vader_array_push((vader_array_t*) l1, l4);
        l2 = (l2 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_values__string__i64(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3, l4;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 8u, 291u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    vader_array_t* _pc14_hdr = (vader_array_t*) l1;
    size_t _pc14_len = _pc14_hdr->length;
    size_t _pc14_cap = (_pc14_hdr->offset == 0 && !vader_array_is_borrowed(_pc14_hdr) && _pc14_hdr->length >= _pc14_hdr->buf->length) ? _pc14_hdr->capacity : (size_t) 0;
    void* _pc14_slots = _pc14_hdr->buf->slots;
    for (;;) {
        if ((l2 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_evals);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
            l4 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l2];
            if (VADER_LIKELY(_pc14_len < _pc14_cap)) {
                ((int64_t*) _pc14_slots)[_pc14_len] = (int64_t) (l4);
                _pc14_len += 1;
            } else {
                _pc14_hdr->length = _pc14_len;
                if (_pc14_hdr->buf->length < _pc14_len) {
                    _pc14_hdr->buf->length = _pc14_len;
                }
                vader_array_push_i64((vader_array_t*) l1, l4);
                _pc14_hdr = (vader_array_t*) l1;
                _pc14_len = _pc14_hdr->length;
                _pc14_cap = (_pc14_hdr->offset == 0 && !vader_array_is_borrowed(_pc14_hdr) && _pc14_hdr->length >= _pc14_hdr->buf->length) ? _pc14_hdr->capacity : (size_t) 0;
                _pc14_slots = _pc14_hdr->buf->slots;
            }
            l2 = (l2 + INT64_C(1));
            continue;
        }
        _pc14_hdr->length = _pc14_len;
        if (_pc14_hdr->buf->length < _pc14_len) {
            _pc14_hdr->buf->length = _pc14_len;
        }
        break;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_values__string__vader_resolver_symbol_Symbol(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int64_t l2, l3;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(158u, 0u, 13u, 1183u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__vader_resolver_symbol_Symbol_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections_MutableMap__string__vader_resolver_symbol_Symbol_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__vader_resolver_symbol_Symbol_t*) l0)->f_evals);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
        vader_array_push((vader_array_t*) l1, vader_ref_box(l4));
        l2 = (l2 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_values__string__vader_typecheck_TypedProgram(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int64_t l2, l3;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1250u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l0)->f_evals);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
        vader_array_push((vader_array_t*) l1, vader_ref_box(l4));
        l2 = (l2 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void std_collections_write_entry__Any__bool(void* l0, vader_box_t l1, bool l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_ref_store_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_ekeys, l1);
    vader_array_push_bool((vader_array_t*) ((vader_struct_std_collections_MutableMap__Any__bool_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i32__Any(void* l0, int32_t l1, vader_box_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys, l1);
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i32__bool(void* l0, int32_t l1, bool l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys, l1);
    vader_array_push_bool((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i32__i32(void* l0, int32_t l1, int32_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int32_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys, l1);
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i32__i64(void* l0, int32_t l1, int64_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_ekeys, l1);
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i64_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i32__std_collections_MutableMap_string__bool_(void* l0, int32_t l1, void* l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_ekeys, l1);
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__bool__t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, int32_t l1, void* l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_ekeys, l1);
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i32__string(void* l0, int32_t l1, vader_string_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3] = vader_box_string(287u, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys, l1);
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_evals, vader_box_string(287u, l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i32__string__(void* l0, int32_t l1, void* l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_ekeys, l1);
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i32__vader_comptime_ComptimeRoute(void* l0, int32_t l1, uint8_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) (int32_t) (uint8_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_ekeys, l1);
    vader_array_push_u8((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) l0)->f_evals, (int32_t) (uint8_t) l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i32__vader_resolver_ConstLocal(void* l0, int32_t l1, uint8_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) (int32_t) (uint8_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_ekeys, l1);
    vader_array_push_u8((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__vader_resolver_ConstLocal_t*) l0)->f_evals, (int32_t) (uint8_t) l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i64__Any(void* l0, int64_t l1, vader_box_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_ekeys, l1);
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i64__bool(void* l0, int64_t l1, bool l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys, l1);
    vader_array_push_bool((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i64__i32(void* l0, int64_t l1, int32_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int32_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_ekeys, l1);
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i64__i64(void* l0, int64_t l1, int64_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_ekeys, l1);
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i64_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i64__string(void* l0, int64_t l1, vader_string_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3] = vader_box_string(287u, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_ekeys, l1);
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__string_t*) l0)->f_evals, vader_box_string(287u, l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__Any(void* l0, vader_string_t l1, vader_box_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(287u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys, vader_box_string(287u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__bool(void* l0, vader_string_t l1, bool l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(287u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys, vader_box_string(287u, l1));
    vader_array_push_bool((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__i32(void* l0, vader_string_t l1, int32_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(287u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int32_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys, vader_box_string(287u, l1));
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__i64(void* l0, vader_string_t l1, int64_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(287u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys, vader_box_string(287u, l1));
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType______(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(287u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_ekeys, vader_box_string(287u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string___vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_______t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__std_collections_MutableMap_string__bool_(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(287u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_ekeys, vader_box_string(287u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__bool__t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__std_collections_MutableMap_string__toolchain_ast_FnDecl_(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(287u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_ekeys, vader_box_string(287u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__toolchain_ast_FnDecl__t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__std_collections_MutableMap_string__vader_lower_MismatchPair_(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(287u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_ekeys, vader_box_string(287u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_lower_MismatchPair__t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate___(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(287u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_ekeys, vader_box_string(287u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_typecheck_FnCandidate____t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(287u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_ekeys, vader_box_string(287u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType__t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__string(void* l0, vader_string_t l1, vader_string_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(287u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3] = vader_box_string(287u, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys, vader_box_string(287u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_evals, vader_box_string(287u, l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__string__(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(287u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_ekeys, vader_box_string(287u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__u64__Any(void* l0, uint64_t l1, vader_box_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (uint64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys, (int64_t) (uint64_t) l1);
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__u64__bool(void* l0, uint64_t l1, bool l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (uint64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys, (int64_t) (uint64_t) l1);
    vader_array_push_bool((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__u64__i32(void* l0, uint64_t l1, int32_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (uint64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int32_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_ekeys, (int64_t) (uint64_t) l1);
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__u64__i64(void* l0, uint64_t l1, int64_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (uint64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_ekeys, (int64_t) (uint64_t) l1);
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i64_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__u64__vader_typecheck_ConstState(void* l0, uint64_t l1, uint8_t l2) {
    int64_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (uint64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) (int32_t) (uint8_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_ekeys, (int64_t) (uint64_t) l1);
    vader_array_push_u8((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__vader_typecheck_ConstState_t*) l0)->f_evals, (int32_t) (uint8_t) l2);
    { vader_gc_top = gc_frame.prev; return; }
}
