/* vader_adapter: the slot readers of a unit of FFI adapters, which includes it
 * after `vader.h` (for the mirrors' typedefs) and links nothing of the runtime.
 *
 * The interpreter calls a foreign function through a trampoline written ahead
 * of time, one per shape of signature (`vader_ffi.h`). A call no trampoline
 * covers (a struct by value, a `float`, floating and integer arguments mixed,
 * a symbol in a static archive) goes through an ADAPTER instead:
 * `vader/c_emit/adapters.vader` writes one per such `@extern`, `vader run`
 * compiles them with the library into a shared library, and the VM calls them
 * through `vader_ffi_call_frame`.
 *
 * An adapter is a function of the call's frame alone: eight-byte slots, one per
 * argument in order, a lent address already resolved in its slot. It writes its
 * result over the first slot, or, for a struct, into the block the slot after
 * the arguments addresses.
 */

#ifndef VADER_ADAPTER_H
#define VADER_ADAPTER_H

#include <stdint.h>
#include <string.h>

#ifdef _WIN32
#  define VADER_ADAPTER __declspec(dllexport)
#else
#  define VADER_ADAPTER __attribute__((visibility("default")))
#endif

static inline int64_t vader_adapter_word(const unsigned char* frame, int slot) {
    int64_t word;
    memcpy(&word, frame + 8 * slot, sizeof word);
    return word;
}

static inline double vader_adapter_double(const unsigned char* frame, int slot) {
    double value;
    memcpy(&value, frame + 8 * slot, sizeof value);
    return value;
}

static inline void* vader_adapter_address(const unsigned char* frame, int slot) {
    return (void*) (intptr_t) vader_adapter_word(frame, slot);
}

static inline void vader_adapter_return_word(unsigned char* frame, int64_t word) {
    memcpy(frame, &word, sizeof word);
}

static inline void vader_adapter_return_double(unsigned char* frame, double value) {
    memcpy(frame, &value, sizeof value);
}

#endif /* VADER_ADAPTER_H */
