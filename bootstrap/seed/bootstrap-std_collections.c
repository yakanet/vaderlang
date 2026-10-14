#include "bootstrap.split.h"

static bool std_collections_MutableMap_Contains_contains__i32__bool(void* l0, int32_t l1);
static bool std_collections_MutableMap_Contains_contains__i64__bool(void* l0, int64_t l1);
static bool std_collections_MutableMap_Contains_contains__string__bool(void* l0, vader_string_t l1);
static bool std_collections_MutableMap_Contains_contains__u64__bool(void* l0, uint64_t l1);
static bool std_collections_MutableMap_Contains_contains__usize__bool(void* l0, size_t l1);
static void std_collections_MutableMap_IndexSet_set_at__i64__bool(void* l0, int64_t l1, bool l2);
static void std_collections_MutableMap_IndexSet_set_at__u64__bool(void* l0, uint64_t l1, bool l2);
static void std_collections_clear__i32__bool(void* l0);
static bool std_collections_contains_key__i32__Any(void* l0, int32_t l1);
static bool std_collections_contains_key__i32__bool(void* l0, int32_t l1);
static bool std_collections_contains_key__i64__bool(void* l0, int64_t l1);
static bool std_collections_contains_key__string__Any(void* l0, vader_string_t l1);
static bool std_collections_contains_key__string__bool(void* l0, vader_string_t l1);
static bool std_collections_contains_key__u64__Any(void* l0, uint64_t l1);
static bool std_collections_contains_key__u64__bool(void* l0, uint64_t l1);
static bool std_collections_contains_key__usize__Any(void* l0, size_t l1);
static bool std_collections_contains_key__usize__bool(void* l0, size_t l1);
static bool std_collections_contains_key__usize__usize(void* l0, size_t l1);
static void std_collections_ensure_index__i32__Any(void* l0);
static void std_collections_ensure_index__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0);
static void std_collections_ensure_index__i32__MutableMap_string__bool_(void* l0);
static void std_collections_ensure_index__i32__bool(void* l0);
static void std_collections_ensure_index__i32__i32(void* l0);
static void std_collections_ensure_index__i32__string(void* l0);
static void std_collections_ensure_index__i32__string__(void* l0);
static void std_collections_ensure_index__i32__usize(void* l0);
static void std_collections_ensure_index__i64__bool(void* l0);
static void std_collections_ensure_index__i64__i32(void* l0);
static void std_collections_ensure_index__string__Any(void* l0);
static void std_collections_ensure_index__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0);
static void std_collections_ensure_index__string__MutableMap_string__FnCandidate___(void* l0);
static void std_collections_ensure_index__string__MutableMap_string__FnDecl_(void* l0);
static void std_collections_ensure_index__string__MutableMap_string__MismatchPair_(void* l0);
static void std_collections_ensure_index__string__MutableMap_string__Symbol_(void* l0);
static void std_collections_ensure_index__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(void* l0);
static void std_collections_ensure_index__string__MutableMap_string__bool_(void* l0);
static void std_collections_ensure_index__string__bool(void* l0);
static void std_collections_ensure_index__string__i32(void* l0);
static void std_collections_ensure_index__string__i64(void* l0);
static void std_collections_ensure_index__string__string(void* l0);
static void std_collections_ensure_index__string__string__(void* l0);
static void std_collections_ensure_index__string__usize(void* l0);
static void std_collections_ensure_index__u64__Any(void* l0);
static void std_collections_ensure_index__u64__bool(void* l0);
static void std_collections_ensure_index__u64__i32(void* l0);
static void std_collections_ensure_index__u64__usize(void* l0);
static void std_collections_ensure_index__usize__Any(void* l0);
static void std_collections_ensure_index__usize__bool(void* l0);
static void std_collections_ensure_index__usize__i32(void* l0);
static void std_collections_ensure_index__usize__string(void* l0);
static void std_collections_ensure_index__usize__usize(void* l0);
static size_t std_collections_first_slot(uint64_t l0, size_t l1);
static vader_box_t std_collections_get__i32__Any(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__MutableMap_string__bool_(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__bool(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__i32(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__string(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__string__(void* l0, int32_t l1);
static vader_box_t std_collections_get__i32__usize(void* l0, int32_t l1);
static vader_box_t std_collections_get__i64__i32(void* l0, int64_t l1);
static vader_box_t std_collections_get__string__Any(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__MutableMap_string__FnCandidate___(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__MutableMap_string__FnDecl_(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__MutableMap_string__MismatchPair_(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__MutableMap_string__Symbol_(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__MutableMap_string__bool_(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__bool(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__i32(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__i64(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__string(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__string__(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__string__usize(void* l0, vader_string_t l1);
static vader_box_t std_collections_get__u64__Any(void* l0, uint64_t l1);
static vader_box_t std_collections_get__u64__i32(void* l0, uint64_t l1);
static vader_box_t std_collections_get__u64__usize(void* l0, uint64_t l1);
static vader_box_t std_collections_get__usize__Any(void* l0, size_t l1);
static vader_box_t std_collections_get__usize__bool(void* l0, size_t l1);
static vader_box_t std_collections_get__usize__i32(void* l0, size_t l1);
static vader_box_t std_collections_get__usize__string(void* l0, size_t l1);
static vader_box_t std_collections_get__usize__usize(void* l0, size_t l1);
static size_t std_collections_next_slot(size_t l0, uint64_t l1, size_t l2);
static void std_collections_put__i32__Any(void* l0, int32_t l1, vader_box_t l2);
static void std_collections_put__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, int32_t l1, void* l2);
static void std_collections_put__i32__MutableMap_string__bool_(void* l0, int32_t l1, void* l2);
static void std_collections_put__i32__bool(void* l0, int32_t l1, bool l2);
static void std_collections_put__i32__i32(void* l0, int32_t l1, int32_t l2);
static void std_collections_put__i32__string(void* l0, int32_t l1, vader_string_t l2);
static void std_collections_put__i32__string__(void* l0, int32_t l1, void* l2);
static void std_collections_put__i32__usize(void* l0, int32_t l1, size_t l2);
static void std_collections_put__i64__bool(void* l0, int64_t l1, bool l2);
static void std_collections_put__i64__i32(void* l0, int64_t l1, int32_t l2);
static void std_collections_put__string__Any(void* l0, vader_string_t l1, vader_box_t l2);
static void std_collections_put__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__MutableMap_string__FnCandidate___(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__MutableMap_string__FnDecl_(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__MutableMap_string__MismatchPair_(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__MutableMap_string__Symbol_(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__MutableMap_string__bool_(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__bool(void* l0, vader_string_t l1, bool l2);
static void std_collections_put__string__i32(void* l0, vader_string_t l1, int32_t l2);
static void std_collections_put__string__i64(void* l0, vader_string_t l1, int64_t l2);
static void std_collections_put__string__string(void* l0, vader_string_t l1, vader_string_t l2);
static void std_collections_put__string__string__(void* l0, vader_string_t l1, void* l2);
static void std_collections_put__string__usize(void* l0, vader_string_t l1, size_t l2);
static void std_collections_put__u64__Any(void* l0, uint64_t l1, vader_box_t l2);
static void std_collections_put__u64__bool(void* l0, uint64_t l1, bool l2);
static void std_collections_put__u64__i32(void* l0, uint64_t l1, int32_t l2);
static void std_collections_put__u64__usize(void* l0, uint64_t l1, size_t l2);
static void std_collections_put__usize__Any(void* l0, size_t l1, vader_box_t l2);
static void std_collections_put__usize__bool(void* l0, size_t l1, bool l2);
static void std_collections_put__usize__i32(void* l0, size_t l1, int32_t l2);
static void std_collections_put__usize__string(void* l0, size_t l1, vader_string_t l2);
static void std_collections_put__usize__usize(void* l0, size_t l1, size_t l2);
static void std_collections_rehash__i32__Any(void* l0, size_t l1);
static void std_collections_rehash__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, size_t l1);
static void std_collections_rehash__i32__MutableMap_string__bool_(void* l0, size_t l1);
static void std_collections_rehash__i32__bool(void* l0, size_t l1);
static void std_collections_rehash__i32__i32(void* l0, size_t l1);
static void std_collections_rehash__i32__string(void* l0, size_t l1);
static void std_collections_rehash__i32__string__(void* l0, size_t l1);
static void std_collections_rehash__i32__usize(void* l0, size_t l1);
static void std_collections_rehash__i64__bool(void* l0, size_t l1);
static void std_collections_rehash__i64__i32(void* l0, size_t l1);
static void std_collections_rehash__string__Any(void* l0, size_t l1);
static void std_collections_rehash__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, size_t l1);
static void std_collections_rehash__string__MutableMap_string__FnCandidate___(void* l0, size_t l1);
static void std_collections_rehash__string__MutableMap_string__FnDecl_(void* l0, size_t l1);
static void std_collections_rehash__string__MutableMap_string__MismatchPair_(void* l0, size_t l1);
static void std_collections_rehash__string__MutableMap_string__Symbol_(void* l0, size_t l1);
static void std_collections_rehash__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(void* l0, size_t l1);
static void std_collections_rehash__string__MutableMap_string__bool_(void* l0, size_t l1);
static void std_collections_rehash__string__bool(void* l0, size_t l1);
static void std_collections_rehash__string__i32(void* l0, size_t l1);
static void std_collections_rehash__string__i64(void* l0, size_t l1);
static void std_collections_rehash__string__string(void* l0, size_t l1);
static void std_collections_rehash__string__string__(void* l0, size_t l1);
static void std_collections_rehash__string__usize(void* l0, size_t l1);
static void std_collections_rehash__u64__Any(void* l0, size_t l1);
static void std_collections_rehash__u64__bool(void* l0, size_t l1);
static void std_collections_rehash__u64__i32(void* l0, size_t l1);
static void std_collections_rehash__u64__usize(void* l0, size_t l1);
static void std_collections_rehash__usize__Any(void* l0, size_t l1);
static void std_collections_rehash__usize__bool(void* l0, size_t l1);
static void std_collections_rehash__usize__i32(void* l0, size_t l1);
static void std_collections_rehash__usize__string(void* l0, size_t l1);
static void std_collections_rehash__usize__usize(void* l0, size_t l1);
static bool std_collections_remove__i32__bool(void* l0, int32_t l1);
static bool std_collections_remove__i64__bool(void* l0, int64_t l1);
static bool std_collections_remove__u64__bool(void* l0, uint64_t l1);
static size_t std_collections_slot_holding__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall(void* l0, int32_t l1, int32_t l2);
static size_t std_collections_slot_holding__i32__NarrowSlot(void* l0, int32_t l1, int32_t l2);
static size_t std_collections_slot_holding__i32__bool(void* l0, int32_t l1, int32_t l2);
static size_t std_collections_slot_holding__i64__bool(void* l0, int64_t l1, int32_t l2);
static size_t std_collections_slot_holding__string__NarrowSlot(void* l0, vader_string_t l1, int32_t l2);
static size_t std_collections_slot_holding__u64__bool(void* l0, uint64_t l1, int32_t l2);
static void std_collections_write_entry__i32__Any(void* l0, int32_t l1, vader_box_t l2);
static void std_collections_write_entry__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, int32_t l1, void* l2);
static void std_collections_write_entry__i32__MutableMap_string__bool_(void* l0, int32_t l1, void* l2);
static void std_collections_write_entry__i32__bool(void* l0, int32_t l1, bool l2);
static void std_collections_write_entry__i32__i32(void* l0, int32_t l1, int32_t l2);
static void std_collections_write_entry__i32__string(void* l0, int32_t l1, vader_string_t l2);
static void std_collections_write_entry__i32__string__(void* l0, int32_t l1, void* l2);
static void std_collections_write_entry__i32__usize(void* l0, int32_t l1, size_t l2);
static void std_collections_write_entry__i64__bool(void* l0, int64_t l1, bool l2);
static void std_collections_write_entry__i64__i32(void* l0, int64_t l1, int32_t l2);
static void std_collections_write_entry__string__Any(void* l0, vader_string_t l1, vader_box_t l2);
static void std_collections_write_entry__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__MutableMap_string__FnCandidate___(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__MutableMap_string__FnDecl_(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__MutableMap_string__MismatchPair_(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__MutableMap_string__Symbol_(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__MutableMap_string__bool_(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__bool(void* l0, vader_string_t l1, bool l2);
static void std_collections_write_entry__string__i32(void* l0, vader_string_t l1, int32_t l2);
static void std_collections_write_entry__string__i64(void* l0, vader_string_t l1, int64_t l2);
static void std_collections_write_entry__string__string(void* l0, vader_string_t l1, vader_string_t l2);
static void std_collections_write_entry__string__string__(void* l0, vader_string_t l1, void* l2);
static void std_collections_write_entry__string__usize(void* l0, vader_string_t l1, size_t l2);
static void std_collections_write_entry__u64__Any(void* l0, uint64_t l1, vader_box_t l2);
static void std_collections_write_entry__u64__bool(void* l0, uint64_t l1, bool l2);
static void std_collections_write_entry__u64__i32(void* l0, uint64_t l1, int32_t l2);
static void std_collections_write_entry__u64__usize(void* l0, uint64_t l1, size_t l2);
static void std_collections_write_entry__usize__Any(void* l0, size_t l1, vader_box_t l2);
static void std_collections_write_entry__usize__bool(void* l0, size_t l1, bool l2);
static void std_collections_write_entry__usize__i32(void* l0, size_t l1, int32_t l2);
static void std_collections_write_entry__usize__string(void* l0, size_t l1, vader_string_t l2);
static void std_collections_write_entry__usize__usize(void* l0, size_t l1, size_t l2);

bool std_collections_MutableMap_Contains_contains__i32__Any(void* l0, int32_t l1) {
    bool t0;
    t0 = std_collections_contains_key__i32__Any(l0, l1);
    return t0;
}

static bool std_collections_MutableMap_Contains_contains__i32__bool(void* l0, int32_t l1) {
    bool t0;
    t0 = std_collections_contains_key__i32__bool(l0, l1);
    return t0;
}

static bool std_collections_MutableMap_Contains_contains__i64__bool(void* l0, int64_t l1) {
    bool t0;
    t0 = std_collections_contains_key__i64__bool(l0, l1);
    return t0;
}

bool std_collections_MutableMap_Contains_contains__string__Any(void* l0, vader_string_t l1) {
    bool t0;
    t0 = std_collections_contains_key__string__Any(l0, l1);
    return t0;
}

static bool std_collections_MutableMap_Contains_contains__string__bool(void* l0, vader_string_t l1) {
    bool t0;
    t0 = std_collections_contains_key__string__bool(l0, l1);
    return t0;
}

bool std_collections_MutableMap_Contains_contains__u64__Any(void* l0, uint64_t l1) {
    bool t0;
    t0 = std_collections_contains_key__u64__Any(l0, l1);
    return t0;
}

static bool std_collections_MutableMap_Contains_contains__u64__bool(void* l0, uint64_t l1) {
    bool t0;
    t0 = std_collections_contains_key__u64__bool(l0, l1);
    return t0;
}

bool std_collections_MutableMap_Contains_contains__usize__Any(void* l0, size_t l1) {
    bool t0;
    t0 = std_collections_contains_key__usize__Any(l0, l1);
    return t0;
}

static bool std_collections_MutableMap_Contains_contains__usize__bool(void* l0, size_t l1) {
    bool t0;
    t0 = std_collections_contains_key__usize__bool(l0, l1);
    return t0;
}

bool std_collections_MutableMap_Contains_contains__usize__usize(void* l0, size_t l1) {
    bool t0;
    t0 = std_collections_contains_key__usize__usize(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__i32__Any(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__Any(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__i32__MutableMap_string__bool_(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__MutableMap_string__bool_(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__i32__bool(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__bool(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__i32__i32(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__i32(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__i32__string(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__string(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__i32__string__(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__string__(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__i32__usize(void* l0, int32_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i32__usize(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__i64__i32(void* l0, int64_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__i64__i32(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__Any(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__Any(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__MutableMap_string__FnCandidate___(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__MutableMap_string__FnCandidate___(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__MutableMap_string__FnDecl_(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__MutableMap_string__FnDecl_(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__MutableMap_string__MismatchPair_(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__MutableMap_string__MismatchPair_(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__MutableMap_string__Symbol_(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__MutableMap_string__Symbol_(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__MutableMap_string__bool_(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__MutableMap_string__bool_(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__bool(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__bool(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__i32(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__i32(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__i64(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__i64(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__string(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__string(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__string__(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__string__(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__string__usize(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__string__usize(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__u64__Any(void* l0, uint64_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__u64__Any(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__u64__i32(void* l0, uint64_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__u64__i32(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__u64__usize(void* l0, uint64_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__u64__usize(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__usize__Any(void* l0, size_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__usize__Any(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__usize__bool(void* l0, size_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__usize__bool(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__usize__i32(void* l0, size_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__usize__i32(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__usize__string(void* l0, size_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__usize__string(l0, l1);
    return t0;
}

vader_box_t std_collections_MutableMap_Index_at__usize__usize(void* l0, size_t l1) {
    vader_box_t t0;
    t0 = std_collections_get__usize__usize(l0, l1);
    return t0;
}

void std_collections_MutableMap_IndexSet_set_at__i32__Any(void* l0, int32_t l1, vader_box_t l2) {
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__Any(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, int32_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__i32__MutableMap_string__bool_(void* l0, int32_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__MutableMap_string__bool_(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__i32__bool(void* l0, int32_t l1, bool l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__bool(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__i32__i32(void* l0, int32_t l1, int32_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__i32(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__i32__string(void* l0, int32_t l1, vader_string_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__string(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__i32__string__(void* l0, int32_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__string__(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__i32__usize(void* l0, int32_t l1, size_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i32__usize(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_MutableMap_IndexSet_set_at__i64__bool(void* l0, int64_t l1, bool l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i64__bool(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__i64__i32(void* l0, int64_t l1, int32_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__i64__i32(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__string__Any(void* l0, vader_string_t l1, vader_box_t l2) {
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

void std_collections_MutableMap_IndexSet_set_at__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__string__MutableMap_string__FnCandidate___(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__MutableMap_string__FnCandidate___(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__string__MutableMap_string__FnDecl_(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__MutableMap_string__FnDecl_(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__string__MutableMap_string__MismatchPair_(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__MutableMap_string__MismatchPair_(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__string__MutableMap_string__Symbol_(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__MutableMap_string__Symbol_(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__string__MutableMap_string__bool_(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__MutableMap_string__bool_(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__string__bool(void* l0, vader_string_t l1, bool l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__bool(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__string__i32(void* l0, vader_string_t l1, int32_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__i32(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__string__i64(void* l0, vader_string_t l1, int64_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__i64(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__string__string(void* l0, vader_string_t l1, vader_string_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__string(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__string__string__(void* l0, vader_string_t l1, void* l2) {
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__string__(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__string__usize(void* l0, vader_string_t l1, size_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__string__usize(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__u64__Any(void* l0, uint64_t l1, vader_box_t l2) {
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__u64__Any(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_MutableMap_IndexSet_set_at__u64__bool(void* l0, uint64_t l1, bool l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__u64__bool(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__u64__i32(void* l0, uint64_t l1, int32_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__u64__i32(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__u64__usize(void* l0, uint64_t l1, size_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__u64__usize(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__usize__Any(void* l0, size_t l1, vader_box_t l2) {
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__usize__Any(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__usize__bool(void* l0, size_t l1, bool l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__usize__bool(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__usize__i32(void* l0, size_t l1, int32_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__usize__i32(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__usize__string(void* l0, size_t l1, vader_string_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_put__usize__string(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_collections_MutableMap_IndexSet_set_at__usize__usize(void* l0, size_t l1, size_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_put__usize__usize(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

bool std_collections_MutableSet_Contains_contains__i32(void* l0, int32_t l1) {
    bool t0;
    t0 = std_collections_MutableMap_Contains_contains__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner, l1);
    return t0;
}

bool std_collections_MutableSet_Contains_contains__i64(void* l0, int64_t l1) {
    bool t0;
    t0 = std_collections_MutableMap_Contains_contains__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) l0)->f_inner, l1);
    return t0;
}

bool std_collections_MutableSet_Contains_contains__string(void* l0, vader_string_t l1) {
    bool t0;
    t0 = std_collections_MutableMap_Contains_contains__string__bool(((vader_struct_std_collections_MutableSet__string_t*) l0)->f_inner, l1);
    return t0;
}

bool std_collections_MutableSet_Contains_contains__u64(void* l0, uint64_t l1) {
    bool t0;
    t0 = std_collections_MutableMap_Contains_contains__u64__bool(((vader_struct_std_collections_MutableSet__u64_t*) l0)->f_inner, l1);
    return t0;
}

bool std_collections_MutableSet_Contains_contains__usize(void* l0, size_t l1) {
    bool t0;
    t0 = std_collections_MutableMap_Contains_contains__usize__bool(((vader_struct_std_collections_MutableSet__usize_t*) l0)->f_inner, l1);
    return t0;
}

bool std_collections_add__i32(void* l0, int32_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableMap_Contains_contains__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner, l1);
    if (!(t0)) {
        std_collections_MutableMap_IndexSet_set_at__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner, l1, true);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

bool std_collections_add__i64(void* l0, int64_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableMap_Contains_contains__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) l0)->f_inner, l1);
    if (!(t0)) {
        std_collections_MutableMap_IndexSet_set_at__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) l0)->f_inner, l1, true);
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
    t0 = std_collections_MutableMap_Contains_contains__string__bool(((vader_struct_std_collections_MutableSet__string_t*) l0)->f_inner, l1);
    if (!(t0)) {
        std_collections_MutableMap_IndexSet_set_at__string__bool(((vader_struct_std_collections_MutableSet__string_t*) l0)->f_inner, l1, true);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

bool std_collections_add__u64(void* l0, uint64_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableMap_Contains_contains__u64__bool(((vader_struct_std_collections_MutableSet__u64_t*) l0)->f_inner, l1);
    if (!(t0)) {
        std_collections_MutableMap_IndexSet_set_at__u64__bool(((vader_struct_std_collections_MutableSet__u64_t*) l0)->f_inner, l1, true);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

bool std_collections_add__usize(void* l0, size_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableMap_Contains_contains__usize__bool(((vader_struct_std_collections_MutableSet__usize_t*) l0)->f_inner, l1);
    if (!(t0)) {
        std_collections_MutableMap_IndexSet_set_at__usize__bool(((vader_struct_std_collections_MutableSet__usize_t*) l0)->f_inner, l1, true);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void std_collections_clear__i32__bool(void* l0) {
    size_t l1, l2;
    int64_t t0;
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size = (size_t) 0;
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs = (size_t) 0;
    l1 = (size_t) 0;
    l2 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int32_t) INT32_C(0);
        t0 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t0;
    }
    return;
}

void std_collections_clear__string__Any(void* l0) {
    size_t l1, l2;
    int64_t t0;
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size = (size_t) 0;
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs = (size_t) 0;
    l1 = (size_t) 0;
    l2 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int32_t) INT32_C(0);
        t0 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t0;
    }
    return;
}

void std_collections_clear__u64__Any(void* l0) {
    size_t l1, l2;
    int64_t t0;
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size = (size_t) 0;
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_tombs = (size_t) 0;
    l1 = (size_t) 0;
    l2 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int32_t) INT32_C(0);
        t0 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t0;
    }
    return;
}

void std_collections_clear__vader_midir_LocalId(void* l0) {
    std_collections_clear__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner);
    return;
}

static bool std_collections_contains_key__i32__Any(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
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
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
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

static bool std_collections_contains_key__i64__bool(void* l0, int64_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
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

static bool std_collections_contains_key__string__Any(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
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
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
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

static bool std_collections_contains_key__u64__Any(void* l0, uint64_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return false;
}

static bool std_collections_contains_key__u64__bool(void* l0, uint64_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
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

static bool std_collections_contains_key__usize__Any(void* l0, size_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_usize_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return false;
}

static bool std_collections_contains_key__usize__bool(void* l0, size_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_usize_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return false;
}

static bool std_collections_contains_key__usize__usize(void* l0, size_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_usize_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return false;
}

static void std_collections_ensure_index__i32__Any(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__MutableMap_string__bool_(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__bool(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__i32(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__string(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__string__(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i32__usize(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__usize_t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i64__bool(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__i64__i32(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__Any(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__MutableMap_string__FnCandidate___(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__MutableMap_string__FnDecl_(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__MutableMap_string__MismatchPair_(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__MutableMap_string__Symbol_(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__MutableMap_string__bool_(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__bool(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__i32(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__i64(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__string(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__string__(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__string__usize(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__usize_t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__u64__Any(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__u64__bool(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__u64__i32(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
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
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__u64__usize(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__usize_t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__usize__Any(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__Any_t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__usize__bool(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__bool_t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__usize__i32(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__i32_t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__usize__string(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__string_t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_ensure_index__usize__usize(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) INT64_C(16));
        l1 = (void*) _a1_arr;
        l2 = (size_t) 0;
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
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
        ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__usize_t*) l0);
        l2 = (size_t) 15;
        ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_mask = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static size_t std_collections_first_slot(uint64_t l0, size_t l1) {
    return (size_t) (int64_t) (((int64_t) (uint64_t) l0) & l1);
}

static vader_box_t std_collections_get__i32__Any(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return t3;
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

static vader_box_t std_collections_get__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    void* t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t3);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i32__MutableMap_string__bool_(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    void* t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t3);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i32__bool(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    bool t4;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = vader_box_bool(280u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4]);
                    t4 = t3.payload.b;
                    t3 = vader_box_bool(280u, t4);
                    return t3;
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
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    t3 = vader_box_i32(285u, t1);
                    return t3;
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

static vader_box_t std_collections_get__i32__string(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
                    t4 = t3.payload.s;
                    t3 = vader_box_string(282u, t4);
                    return t3;
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
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    void* t3;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t3);
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

static vader_box_t std_collections_get__i32__usize(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    t3 = vader_box_i64(292u, t2);
                    return t3;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__i64__i32(void* l0, int64_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    t3 = vader_box_i32(285u, t1);
                    return t3;
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

static vader_box_t std_collections_get__string__Any(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return t3;
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

static vader_box_t std_collections_get__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
    void* t5;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t5);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__MutableMap_string__FnCandidate___(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
    void* t5;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t5);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__MutableMap_string__FnDecl_(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
    void* t5;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t5);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__MutableMap_string__MismatchPair_(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
    void* t5;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t5);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__MutableMap_string__Symbol_(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
    void* t5;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t5);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
    void* t5;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t5);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__MutableMap_string__bool_(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
    void* t5;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t5);
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__string__bool(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
    bool t5;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = vader_box_bool(280u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4]);
                    t5 = t3.payload.b;
                    t3 = vader_box_bool(280u, t5);
                    return t3;
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
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    t3 = vader_box_i32(285u, t1);
                    return t3;
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
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    t3 = vader_box_i64(286u, t2);
                    return t3;
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

static vader_box_t std_collections_get__string__string(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
                    t4 = t3.payload.s;
                    t3 = vader_box_string(282u, t4);
                    return t3;
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
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
    void* t5;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return vader_ref_box(t5);
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

static vader_box_t std_collections_get__string__usize(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    t3 = vader_box_i64(292u, t2);
                    return t3;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__u64__Any(void* l0, uint64_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return t3;
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
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    t3 = vader_box_i32(285u, t1);
                    return t3;
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

static vader_box_t std_collections_get__u64__usize(void* l0, uint64_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    t3 = vader_box_i64(292u, t2);
                    return t3;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__usize__Any(void* l0, size_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_usize_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    return t3;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__usize__bool(void* l0, size_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    bool t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_usize_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = vader_box_bool(280u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4]);
                    t4 = t3.payload.b;
                    t3 = vader_box_bool(280u, t4);
                    return t3;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__usize__i32(void* l0, size_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_usize_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    t3 = vader_box_i32(285u, t1);
                    return t3;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__usize__string(void* l0, size_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_usize_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
                    t4 = t3.payload.s;
                    t3 = vader_box_string(282u, t4);
                    return t3;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t std_collections_get__usize__usize(void* l0, size_t l1) {
    uint64_t l2;
    size_t l3, l4, l5;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = std_core_usize_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t2 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    t3 = vader_box_i64(292u, t2);
                    return t3;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l5);
            continue;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

bool std_collections_is_empty__i32(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__i32__Any(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__i32__bool(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__string(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__string__bool_t*) ((vader_struct_std_collections_MutableSet__string_t*) l0)->f_inner)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__string__Any(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__u64__Any(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__usize__Any(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
    return t0 == INT64_C(0);
}

bool std_collections_is_empty__usize__usize(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_size;
    return t0 == INT64_C(0);
}

void* std_collections_keys__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(void* l0) {
    void* l1 = NULL;
    size_t l2, l3;
    int32_t l4;
    int64_t t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = ((vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l0)->f_size;
    vader_array_t* _pc14_hdr = (vader_array_t*) l1;
    size_t _pc14_len = _pc14_hdr->length;
    size_t _pc14_cap = (_pc14_hdr->offset == 0 && !vader_array_is_borrowed(_pc14_hdr) && _pc14_hdr->length >= _pc14_hdr->buf->length) ? _pc14_hdr->capacity : (size_t) 0;
    void* _pc14_slots = _pc14_hdr->buf->slots;
    for (;;) {
        if ((l2 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l0)->f_ekeys);
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
            t0 = (l2 + INT64_C(1));
            l2 = (size_t) (int64_t) t0;
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

void* std_collections_keys__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue(void* l0) {
    void* l1 = NULL;
    size_t l2, l3;
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 282u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = ((vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l2];
        l4 = t0.payload.s;
        vader_array_push((vader_array_t*) l1, vader_box_string(282u, l4));
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_keys__string__LoweredModule(void* l0) {
    void* l1 = NULL;
    size_t l2, l3;
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 282u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l2];
        l4 = t0.payload.s;
        vader_array_push((vader_array_t*) l1, vader_box_string(282u, l4));
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_keys__string__TypedProgram(void* l0) {
    void* l1 = NULL;
    size_t l2, l3;
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 282u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l2];
        l4 = t0.payload.s;
        vader_array_push((vader_array_t*) l1, vader_box_string(282u, l4));
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_keys__string___AssertDecl___ConstDecl___EnumDecl___FnDecl___ImplDecl___ImportDecl___StructDecl___TraitDecl___TypeAliasDecl___(void* l0) {
    void* l1 = NULL;
    size_t l2, l3;
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 282u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string___AssertDecl___ConstDecl___EnumDecl___FnDecl___ImplDecl___ImportDecl___StructDecl___TraitDecl___TypeAliasDecl____t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = ((vader_struct_std_collections_MutableMap__string___AssertDecl___ConstDecl___EnumDecl___FnDecl___ImplDecl___ImportDecl___StructDecl___TraitDecl___TypeAliasDecl____t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string___AssertDecl___ConstDecl___EnumDecl___FnDecl___ImplDecl___ImportDecl___StructDecl___TraitDecl___TypeAliasDecl____t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l2];
        l4 = t0.payload.s;
        vader_array_push((vader_array_t*) l1, vader_box_string(282u, l4));
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

size_t std_collections_len__i32(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner)->f_size;
    return t0;
}

size_t std_collections_len__i32__Any(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    return t0;
}

size_t std_collections_len__i32__bool(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    return t0;
}

size_t std_collections_len__string(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__string__bool_t*) ((vader_struct_std_collections_MutableSet__string_t*) l0)->f_inner)->f_size;
    return t0;
}

size_t std_collections_len__string__Any(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    return t0;
}

size_t std_collections_len__string__i64(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    return t0;
}

size_t std_collections_len__usize(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) ((vader_struct_std_collections_MutableSet__usize_t*) l0)->f_inner)->f_size;
    return t0;
}

size_t std_collections_len__usize__Any(void* l0) {
    size_t t0;
    t0 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
    return t0;
}

static size_t std_collections_next_slot(size_t l0, uint64_t l1, size_t l2) {
    size_t l3, l4;
    int64_t t0;
    t0 = (l0 * INT64_C(5));
    l3 = (size_t) (int64_t) t0;
    t0 = ((int64_t) (uint64_t) l1);
    l4 = (size_t) (int64_t) t0;
    return (size_t) (int64_t) (((l3 + l4) + INT64_C(1)) & l2);
}

static void std_collections_put__i32__Any(void* l0, int32_t l1, vader_box_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__Any(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__i32__Any(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t3 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__Any(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, int32_t l1, void* l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t3 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__MutableMap_string__bool_(void* l0, int32_t l1, void* l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__MutableMap_string__bool_(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__i32__MutableMap_string__bool_(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t3 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__MutableMap_string__bool_(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__bool(void* l0, int32_t l1, bool l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__i32__bool(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t3 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__bool(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__i32(void* l0, int32_t l1, int32_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__i32(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__i32__i32(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t3 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int32_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__i32(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__string(void* l0, int32_t l1, vader_string_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__string(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__i32__string(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t3 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4] = vader_box_string(282u, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__string(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__string__(void* l0, int32_t l1, void* l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__string__(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__i32__string__(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t3 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__string__(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i32__usize(void* l0, int32_t l1, size_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__usize(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__i32__usize(l0, l3);
    }
    l6 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t3 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int64_t) (int64_t) (size_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i32__usize(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i64__bool(void* l0, int64_t l1, bool l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i64__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__i64__bool(l0, l3);
    }
    l6 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i64__bool(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__i64__i32(void* l0, int64_t l1, int32_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i64__i32(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__i64__i32(l0, l3);
    }
    l6 = std_core_i64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int32_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__i64__i32(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__Any(void* l0, vader_string_t l1, vader_box_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[2] = { &l2, &t4 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__Any(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__Any(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__Any(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__MutableMap_string__FnCandidate___(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__MutableMap_string__FnCandidate___(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__MutableMap_string__FnCandidate___(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__MutableMap_string__FnCandidate___(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__MutableMap_string__FnDecl_(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__MutableMap_string__FnDecl_(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__MutableMap_string__FnDecl_(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__MutableMap_string__FnDecl_(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__MutableMap_string__MismatchPair_(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__MutableMap_string__MismatchPair_(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__MutableMap_string__MismatchPair_(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__MutableMap_string__MismatchPair_(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__MutableMap_string__Symbol_(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__MutableMap_string__Symbol_(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__MutableMap_string__Symbol_(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__MutableMap_string__Symbol_(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__MutableMap_string__bool_(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__MutableMap_string__bool_(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__MutableMap_string__bool_(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__MutableMap_string__bool_(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__bool(void* l0, vader_string_t l1, bool l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__bool(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__bool(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__i32(void* l0, vader_string_t l1, int32_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__i32(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__i32(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int32_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__i32(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__i64(void* l0, vader_string_t l1, int64_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__i64(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__i64(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int64_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__i64(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__string(void* l0, vader_string_t l1, vader_string_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__string(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__string(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4] = vader_box_string(282u, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__string(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__string__(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__string__(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__string__(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__string__(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__string__usize(void* l0, vader_string_t l1, size_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__usize(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__string__usize(l0, l3);
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t4 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t5 = t4.payload.s;
                if (t5 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int64_t) (int64_t) (size_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__string__usize(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__u64__Any(void* l0, uint64_t l1, vader_box_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__u64__Any(l0);
    l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__u64__Any(l0, l3);
    }
    l6 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__u64__Any(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__u64__bool(void* l0, uint64_t l1, bool l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__u64__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__u64__bool(l0, l3);
    }
    l6 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__u64__bool(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__u64__i32(void* l0, uint64_t l1, int32_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__u64__i32(l0);
    l3 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__u64__i32(l0, l3);
    }
    l6 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int32_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__u64__i32(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__u64__usize(void* l0, uint64_t l1, size_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__u64__usize(l0);
    l3 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__u64__usize(l0, l3);
    }
    l6 = std_core_u64_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int64_t) (int64_t) (size_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__u64__usize(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__usize__Any(void* l0, size_t l1, vader_box_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__usize__Any(l0);
    l3 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__usize__Any(l0, l3);
    }
    l6 = std_core_usize_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__usize__Any(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__usize__bool(void* l0, size_t l1, bool l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__usize__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__usize__bool(l0, l3);
    }
    l6 = std_core_usize_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__usize__bool(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__usize__i32(void* l0, size_t l1, int32_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__usize__i32(l0);
    l3 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__usize__i32(l0, l3);
    }
    l6 = std_core_usize_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int32_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__usize__i32(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__usize__string(void* l0, size_t l1, vader_string_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__usize__string(l0);
    l3 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__usize__string(l0, l3);
    }
    l6 = std_core_usize_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4] = vader_box_string(282u, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__usize__string(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_put__usize__usize(void* l0, size_t l1, size_t l2) {
    size_t l3, l4, l5;
    uint64_t l6;
    int64_t l7;
    void* l8 = NULL;
    int32_t l9;
    int64_t t0, t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__usize__usize(l0);
    l3 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_tombs;
    t0 = vader_chk_add(usize, l3, l4);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    t0 = vader_chk_mul(usize, t1, INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t2 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_mask;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    t1 = vader_chk_mul(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        l3 = (size_t) 16;
        for (;;) {
            t2 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_size;
            t0 = vader_chk_add(usize, t2, INT64_C(1));
            t1 = vader_chk_mul(usize, t0, INT64_C(4));
            l4 = (size_t) (int64_t) t1;
            t0 = vader_chk_mul(usize, l3, INT64_C(3));
            l5 = (size_t) (int64_t) t0;
            if ((l4 > l5)) {
                t0 = vader_chk_mul(usize, l3, INT64_C(2));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            break;
        }
        std_collections_rehash__usize__usize(l0, l3);
    }
    l6 = std_core_usize_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l6, l3);
    l7 = INT64_C(-1);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t3 != INT32_C(0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_index);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            if (t3 == INT32_C(-1)) {
                if ((l7 < INT64_C(0))) {
                    l7 = ((int64_t) (size_t) l3);
                }
            } else {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_index);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = vader_chk_sub(usize, ((int64_t) (int32_t) t3), INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_evals);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int64_t) (int64_t) (size_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 >> INT64_C(5));
            l5 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l6, l5);
            continue;
        }
        break;
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t2 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_tombs;
        t0 = vader_chk_sub(usize, t2, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_tombs = l3;
    }
    std_collections_write_entry__usize__usize(l0, l1, l2);
    l8 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_index;
    t2 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l9 = ((int32_t) (int64_t) t0);
    vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l9;
    t2 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_size;
    t0 = vader_chk_add(usize, t2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_size = l3;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__Any(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t2);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t2);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__MutableMap_string__bool_(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t2);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__bool(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t2);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__i32(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t2);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__string(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t2);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__string_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__string__(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t2);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__string___t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__string___t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i32__usize(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i32_Hash_hash(t2);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__usize_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i64__bool(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i64_Hash_hash(t1);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__i64__i32(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_i64_Hash_hash(t1);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__i64__i32_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__Any(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0);
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__MutableMap_string__FnCandidate___(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0);
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__MutableMap_string__FnDecl_(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0);
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__MutableMap_string__MismatchPair_(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0);
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__MutableMap_string__Symbol_(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0);
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0);
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__MutableMap_string__bool_(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0);
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__bool(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__i32(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__i64(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i64_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__string(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__string__(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string___t*) l0);
    ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__string__usize(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
        t3 = t2.payload.s;
        l6 = std_core_string_Hash_hash_vt(t3);
        l7 = std_collections_first_slot(l6, l3);
        for (;;) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            if (t4 != INT32_C(0)) {
                l6 = (l6 >> INT64_C(5));
                l7 = std_collections_next_slot(l7, l6, l3);
                continue;
            }
            break;
        }
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__usize_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__u64__Any(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_u64_Hash_hash((uint64_t) (int64_t) t1);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__u64__bool(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_u64_Hash_hash((uint64_t) (int64_t) t1);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__u64__i32(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_u64_Hash_hash((uint64_t) (int64_t) t1);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__u64__i32_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__u64__usize(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_u64_Hash_hash((uint64_t) (int64_t) t1);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__usize_t*) l0);
    ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__usize__Any(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_usize_Hash_hash((size_t) (int64_t) t1);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__usize__bool(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_usize_Hash_hash((size_t) (int64_t) t1);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__usize__i32(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_usize_Hash_hash((size_t) (int64_t) t1);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__usize__string(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_usize_Hash_hash((size_t) (int64_t) t1);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__string_t*) l0);
    ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_rehash__usize__usize(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l7;
    uint64_t l6;
    int32_t l8;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l2;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l3 < l1)) {
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(0));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc6_hdr = (vader_array_t*) l2;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    t1 = vader_chk_sub(usize, l1, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) 0;
    l5 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_ekeys);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l6 = std_core_usize_Hash_hash((size_t) (int64_t) t1);
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
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__usize_t*) l0);
    ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_mask = l3;
    ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_tombs = (size_t) 0;
    { vader_gc_top = gc_frame.prev; return; }
}

bool std_collections_remove__i32(void* l0, int32_t l1) {
    bool t0;
    t0 = std_collections_remove__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner, l1);
    return t0;
}

bool std_collections_remove__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l8, l15, l16, l17;
    int32_t l6, l7, l10, l14;
    void* l9;
    void* l11;
    void* l13;
    vader_box_t l12;
    size_t t0;
    int32_t t1;
    int64_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    t0 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_size;
                    t2 = vader_chk_sub(usize, t0, INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    if (l4 != l5) {
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                        l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                        t2 = vader_chk_add(usize, l5, INT64_C(1));
                        l7 = ((int32_t) (int64_t) t2);
                        l8 = std_collections_slot_holding__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall(l0, l6, l7);
                        l9 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_ekeys;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_ekeys);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
                        l10 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                        ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4] = (int32_t) l10;
                        l11 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_evals;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_evals);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                        l12 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                        vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4, l12.payload.obj);
                        VADER_WRITE_BARRIER(_a5_slotarr->buf);
                        l13 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_index;
                        t2 = vader_chk_add(usize, l4, INT64_C(1));
                        l14 = ((int32_t) (int64_t) t2);
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
                        ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8] = (int32_t) l14;
                    }
                    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_index);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                    t0 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_tombs;
                    t2 = vader_chk_add(usize, t0, INT64_C(1));
                    l15 = (size_t) (int64_t) t2;
                    ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_tombs = l15;
                    t0 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_size;
                    t2 = vader_chk_sub(usize, t0, INT64_C(1));
                    l16 = (size_t) (int64_t) t2;
                    ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_size = l16;
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l17 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l17);
            continue;
        }
        break;
    }
    return false;
}

bool std_collections_remove__i32__NarrowSlot(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l8, l15, l16, l17;
    int32_t l6, l7, l10, l14;
    void* l9;
    void* l11;
    void* l12;
    void* l13;
    size_t t0;
    int32_t t1;
    int64_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_i32_Hash_hash(l1);
    l3 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    t0 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_size;
                    t2 = vader_chk_sub(usize, t0, INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    if (l4 != l5) {
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                        l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                        t2 = vader_chk_add(usize, l5, INT64_C(1));
                        l7 = ((int32_t) (int64_t) t2);
                        l8 = std_collections_slot_holding__i32__NarrowSlot(l0, l6, l7);
                        l9 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_ekeys;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_ekeys);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
                        l10 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                        ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4] = (int32_t) l10;
                        l11 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_evals;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_evals);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                        l12 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                        vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4, l12);
                        VADER_WRITE_BARRIER(_a5_slotarr->buf);
                        l13 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_index;
                        t2 = vader_chk_add(usize, l4, INT64_C(1));
                        l14 = ((int32_t) (int64_t) t2);
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
                        ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8] = (int32_t) l14;
                    }
                    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_index);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                    t0 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_tombs;
                    t2 = vader_chk_add(usize, t0, INT64_C(1));
                    l15 = (size_t) (int64_t) t2;
                    ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_tombs = l15;
                    t0 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_size;
                    t2 = vader_chk_sub(usize, t0, INT64_C(1));
                    l16 = (size_t) (int64_t) t2;
                    ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_size = l16;
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l17 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_mask;
            l3 = std_collections_next_slot(l3, l2, l17);
            continue;
        }
        break;
    }
    return false;
}

static bool std_collections_remove__i32__bool(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l8, l15, l16, l17;
    int32_t l6, l7, l10, l14;
    void* l9;
    void* l11;
    void* l13;
    bool l12;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t1 == l1) {
                    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
                    t2 = vader_chk_sub(usize, t0, INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    if (l4 != l5) {
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                        l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                        t2 = vader_chk_add(usize, l5, INT64_C(1));
                        l7 = ((int32_t) (int64_t) t2);
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
                        t3 = vader_box_bool(280u, ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5]);
                        l12 = t3.payload.b;
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                        ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (uint8_t) l12;
                        l13 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index;
                        t2 = vader_chk_add(usize, l4, INT64_C(1));
                        l14 = ((int32_t) (int64_t) t2);
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
                    t2 = vader_chk_add(usize, t0, INT64_C(1));
                    l15 = (size_t) (int64_t) t2;
                    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs = l15;
                    t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
                    t2 = vader_chk_sub(usize, t0, INT64_C(1));
                    l16 = (size_t) (int64_t) t2;
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

bool std_collections_remove__i64(void* l0, int64_t l1) {
    bool t0;
    t0 = std_collections_remove__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) l0)->f_inner, l1);
    return t0;
}

static bool std_collections_remove__i64__bool(void* l0, int64_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l8, l15, l16, l17;
    int64_t l6, l10;
    int32_t l7, l14;
    void* l9;
    void* l11;
    void* l13;
    bool l12;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    t0 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
                    t2 = vader_chk_sub(usize, t0, INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    if (l4 != l5) {
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                        l6 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                        t2 = vader_chk_add(usize, l5, INT64_C(1));
                        l7 = ((int32_t) (int64_t) t2);
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
                        t3 = vader_box_bool(280u, ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5]);
                        l12 = t3.payload.b;
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                        ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (uint8_t) l12;
                        l13 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index;
                        t2 = vader_chk_add(usize, l4, INT64_C(1));
                        l14 = ((int32_t) (int64_t) t2);
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
                    t2 = vader_chk_add(usize, t0, INT64_C(1));
                    l15 = (size_t) (int64_t) t2;
                    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs = l15;
                    t0 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
                    t2 = vader_chk_sub(usize, t0, INT64_C(1));
                    l16 = (size_t) (int64_t) t2;
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

bool std_collections_remove__string__NarrowSlot(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l8, l15, l16, l17;
    vader_string_t l6, l10;
    int32_t l7, l14;
    void* l9;
    void* l11;
    void* l12;
    void* l13;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_string_t t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_mask;
    l3 = std_collections_first_slot(l2, l3);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        if (t1 != INT32_C(0)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(-1)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    t0 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_size;
                    t2 = vader_chk_sub(usize, t0, INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    if (l4 != l5) {
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                        t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l5];
                        l6 = t3.payload.s;
                        t2 = vader_chk_add(usize, l5, INT64_C(1));
                        l7 = ((int32_t) (int64_t) t2);
                        l8 = std_collections_slot_holding__string__NarrowSlot(l0, l6, l7);
                        l9 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_ekeys;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_ekeys);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
                        t3 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l5];
                        l10 = t3.payload.s;
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                        vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4] = vader_box_string(282u, l10);
                        VADER_WRITE_BARRIER(_a3_slotarr->buf);
                        l11 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_evals;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_evals);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                        l12 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                        vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4, l12);
                        VADER_WRITE_BARRIER(_a5_slotarr->buf);
                        l13 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index;
                        t2 = vader_chk_add(usize, l4, INT64_C(1));
                        l14 = ((int32_t) (int64_t) t2);
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
                        ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8] = (int32_t) l14;
                    }
                    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                    t0 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_tombs;
                    t2 = vader_chk_add(usize, t0, INT64_C(1));
                    l15 = (size_t) (int64_t) t2;
                    ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_tombs = l15;
                    t0 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_size;
                    t2 = vader_chk_sub(usize, t0, INT64_C(1));
                    l16 = (size_t) (int64_t) t2;
                    ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_size = l16;
                    return true;
                }
            }
            l2 = (l2 >> INT64_C(5));
            l17 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_mask;
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
    size_t l3, l4, l5, l8, l15, l16, l17;
    int32_t l7, l14;
    void* l9;
    void* l11;
    void* l13;
    bool l12;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
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
                t2 = vader_chk_sub(usize, ((int64_t) (int32_t) t1), INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    t0 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
                    t2 = vader_chk_sub(usize, t0, INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    if (l4 != l5) {
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                        t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                        l6 = (uint64_t) (int64_t) t2;
                        t2 = vader_chk_add(usize, l5, INT64_C(1));
                        l7 = ((int32_t) (int64_t) t2);
                        l8 = std_collections_slot_holding__u64__bool(l0, l6, l7);
                        l9 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_ekeys);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
                        t2 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                        l10 = (uint64_t) (int64_t) t2;
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                        ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4] = (int64_t) (int64_t) (uint64_t) l10;
                        l11 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_evals;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_evals);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                        t3 = vader_box_bool(280u, ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5]);
                        l12 = t3.payload.b;
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                        ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (uint8_t) l12;
                        l13 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_index;
                        t2 = vader_chk_add(usize, l4, INT64_C(1));
                        l14 = ((int32_t) (int64_t) t2);
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
                    t2 = vader_chk_add(usize, t0, INT64_C(1));
                    l15 = (size_t) (int64_t) t2;
                    ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_tombs = l15;
                    t0 = ((vader_struct_std_collections_MutableMap__u64__bool_t*) l0)->f_size;
                    t2 = vader_chk_sub(usize, t0, INT64_C(1));
                    l16 = (size_t) (int64_t) t2;
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

static size_t std_collections_slot_holding__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall(void* l0, int32_t l1, int32_t l2) {
    uint64_t l3;
    size_t l4, l5;
    int32_t t0;
    size_t t1;
    l3 = std_core_i32_Hash_hash(l1);
    l4 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_mask;
    l4 = std_collections_first_slot(l3, l4);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_index);
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
            l5 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_mask;
            l4 = std_collections_next_slot(l4, l3, l5);
            continue;
        }
        break;
    }
    t1 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_index)->length;
    return t1;
}

static size_t std_collections_slot_holding__i32__NarrowSlot(void* l0, int32_t l1, int32_t l2) {
    uint64_t l3;
    size_t l4, l5;
    int32_t t0;
    size_t t1;
    l3 = std_core_i32_Hash_hash(l1);
    l4 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_mask;
    l4 = std_collections_first_slot(l3, l4);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_index);
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
            l5 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_mask;
            l4 = std_collections_next_slot(l4, l3, l5);
            continue;
        }
        break;
    }
    t1 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_index)->length;
    return t1;
}

static size_t std_collections_slot_holding__i32__bool(void* l0, int32_t l1, int32_t l2) {
    uint64_t l3;
    size_t l4, l5;
    int32_t t0;
    size_t t1;
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

static size_t std_collections_slot_holding__i64__bool(void* l0, int64_t l1, int32_t l2) {
    uint64_t l3;
    size_t l4, l5;
    int32_t t0;
    size_t t1;
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

static size_t std_collections_slot_holding__string__NarrowSlot(void* l0, vader_string_t l1, int32_t l2) {
    uint64_t l3;
    size_t l4, l5;
    int32_t t0;
    size_t t1;
    l3 = std_core_string_Hash_hash_vt(l1);
    l4 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_mask;
    l4 = std_collections_first_slot(l3, l4);
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index);
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
            l5 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_mask;
            l4 = std_collections_next_slot(l4, l3, l5);
            continue;
        }
        break;
    }
    t1 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index)->length;
    return t1;
}

static size_t std_collections_slot_holding__u64__bool(void* l0, uint64_t l1, int32_t l2) {
    uint64_t l3;
    size_t l4, l5;
    int32_t t0;
    size_t t1;
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

void* std_collections_values__i32__ConstFnWrap(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    size_t l2, l3;
    int64_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(106u, 0u, 13u, 918u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__i32__ConstFnWrap_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = ((vader_struct_std_collections_MutableMap__i32__ConstFnWrap_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__ConstFnWrap_t*) l0)->f_evals);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
        vader_array_push((vader_array_t*) l1, vader_ref_box(l4));
        t0 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t0;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_values__string__Symbol(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    size_t l2, l3;
    int64_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(151u, 0u, 13u, 1119u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l0)->f_evals);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
        vader_array_push((vader_array_t*) l1, vader_ref_box(l4));
        t0 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t0;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_values__string__TypedProgram(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    size_t l2, l3;
    int64_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(179u, 0u, 13u, 1178u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l0)->f_evals);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
        vader_array_push((vader_array_t*) l1, vader_ref_box(l4));
        t0 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t0;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_collections_values__string__i64(void* l0) {
    void* l1 = NULL;
    size_t l2, l3;
    int64_t l4;
    int64_t t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(17u, 0u, 8u, 286u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
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
            t0 = (l2 + INT64_C(1));
            l2 = (size_t) (int64_t) t0;
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

void* std_collections_values__u64__Symbol(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    size_t l2, l3;
    int64_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(151u, 0u, 13u, 1119u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__u64__Symbol_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = ((vader_struct_std_collections_MutableMap__u64__Symbol_t*) l0)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Symbol_t*) l0)->f_evals);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
        vader_array_push((vader_array_t*) l1, vader_ref_box(l4));
        t0 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t0;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void std_collections_write_entry__i32__Any(void* l0, int32_t l1, vader_box_t l2) {
    size_t l3, l4;
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

static void std_collections_write_entry__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, int32_t l1, void* l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_ekeys, l1);
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i32__MutableMap_string__bool_(void* l0, int32_t l1, void* l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_ekeys, l1);
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__MutableMap_string__bool__t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i32__bool(void* l0, int32_t l1, bool l2) {
    size_t l3, l4;
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
    size_t l3, l4;
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

static void std_collections_write_entry__i32__string(void* l0, int32_t l1, vader_string_t l2) {
    size_t l3, l4;
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
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3] = vader_box_string(282u, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys, l1);
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_evals, vader_box_string(282u, l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i32__string__(void* l0, int32_t l1, void* l2) {
    size_t l3, l4;
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

static void std_collections_write_entry__i32__usize(void* l0, int32_t l1, size_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_ekeys, l1);
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_evals, (int64_t) (size_t) l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__i64__bool(void* l0, int64_t l1, bool l2) {
    size_t l3, l4;
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
    size_t l3, l4;
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

static void std_collections_write_entry__string__Any(void* l0, vader_string_t l1, vader_box_t l2) {
    size_t l3, l4;
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
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
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
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType__t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__MutableMap_string__FnCandidate___(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnCandidate____t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__MutableMap_string__FnDecl_(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__FnDecl__t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__MutableMap_string__MismatchPair_(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__MismatchPair__t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__MutableMap_string__Symbol_(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__Symbol__t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType______(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string___AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_______t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__MutableMap_string__bool_(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__MutableMap_string__bool__t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__bool(void* l0, vader_string_t l1, bool l2) {
    size_t l3, l4;
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
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push_bool((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__i32(void* l0, vader_string_t l1, int32_t l2) {
    size_t l3, l4;
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
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int32_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__i64(void* l0, vader_string_t l1, int64_t l2) {
    size_t l3, l4;
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
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__string(void* l0, vader_string_t l1, vader_string_t l2) {
    size_t l3, l4;
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
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3] = vader_box_string(282u, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_evals, vader_box_string(282u, l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__string__(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4;
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
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
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
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string___t*) l0)->f_evals, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__string__usize(void* l0, vader_string_t l1, size_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(282u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_ekeys, vader_box_string(282u, l1));
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_evals, (int64_t) (size_t) l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__u64__Any(void* l0, uint64_t l1, vader_box_t l2) {
    size_t l3, l4;
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
    size_t l3, l4;
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
    size_t l3, l4;
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

static void std_collections_write_entry__u64__usize(void* l0, uint64_t l1, size_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (uint64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_ekeys, (int64_t) (uint64_t) l1);
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_evals, (int64_t) (size_t) l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__usize__Any(void* l0, size_t l1, vader_box_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_ref_store_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_ekeys, (int64_t) (size_t) l1);
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__usize__bool(void* l0, size_t l1, bool l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_ekeys, (int64_t) (size_t) l1);
    vader_array_push_bool((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__usize__i32(void* l0, size_t l1, int32_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int32_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_ekeys, (int64_t) (size_t) l1);
    vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_evals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__usize__string(void* l0, size_t l1, vader_string_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3] = vader_box_string(282u, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_ekeys, (int64_t) (size_t) l1);
    vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_evals, vader_box_string(282u, l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_collections_write_entry__usize__usize(void* l0, size_t l1, size_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_ekeys, (int64_t) (size_t) l1);
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__usize_t*) l0)->f_evals, (int64_t) (size_t) l2);
    { vader_gc_top = gc_frame.prev; return; }
}
