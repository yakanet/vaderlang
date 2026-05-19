# Build harness for the erasure POC. See ./README.md.
#
# Targets:
#   make            — build everything, run the bench
#   make bench      — build + run the bench binary
#   make sizes      — build, report per-TU object size and cc -O3 wall-time
#   make clean      — wipe build artefacts

CC      ?= cc
CFLAGS  ?= -O3 -std=c11 -Wall -Wextra -Wpedantic
INCS     = -I. -I../../runtime/c
RUNTIME  = ../../runtime/c/vader_runtime.c

# Per-TU object files — built separately so we can time each cc invocation
# independently and compare TU compile cost (criterion #3).
OBJS_SHARED  = shared.o
OBJS_MONO    = mono_map.o
OBJS_ERASED  = erased_map.o erased_map_inline_vt.o
OBJS_BENCH   = bench.o

all: bench

# Build the unified bench binary.
bench: $(OBJS_SHARED) $(OBJS_MONO) $(OBJS_ERASED) $(OBJS_BENCH) $(RUNTIME)
	$(CC) $(CFLAGS) $(INCS) $^ -o bench

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Per-TU compile-time measurements — runs cc -O3 on each implementation
# alone, captures wall-time + object size.
sizes:
	@echo "--- mono_map.c ---"
	@/usr/bin/time -p $(CC) $(CFLAGS) $(INCS) -c mono_map.c -o mono_map.size.o 2>&1
	@ls -la mono_map.size.o | awk '{ printf "  obj size = %s bytes\n", $$5 }'
	@echo "--- erased_map.c ---"
	@/usr/bin/time -p $(CC) $(CFLAGS) $(INCS) -c erased_map.c -o erased_map.size.o 2>&1
	@ls -la erased_map.size.o | awk '{ printf "  obj size = %s bytes\n", $$5 }'
	@rm -f mono_map.size.o erased_map.size.o

# Multi-instantiation cc -O3 stress — informs criterion #3. Compiles the
# burst files at varying instantiation counts and prints wall-time + obj
# size for each. Mono grows with N; erased stays flat (one body shared).
burst:
	@for n in 1 4 16 32 45 ; do \
	  echo "=== BURST_N=$$n ===" ; \
	  echo "  mono ($$n instantiations):" ; \
	  /usr/bin/time -p $(CC) $(CFLAGS) $(INCS) -DBURST_N=$$n -c gen_mono_burst.c -o mono_burst.o 2>&1 | sed 's/^/    /' ; \
	  ls -la mono_burst.o | awk '{ printf "    obj size = %s bytes\n", $$5 }' ; \
	  echo "  erased (1 shared body + $$n vtables):" ; \
	  /usr/bin/time -p $(CC) $(CFLAGS) $(INCS) -DBURST_N=$$n -c gen_erased_burst.c -o erased_burst.o 2>&1 | sed 's/^/    /' ; \
	  ls -la erased_burst.o | awk '{ printf "    obj size = %s bytes\n", $$5 }' ; \
	done ; \
	rm -f mono_burst.o erased_burst.o

# Convenience: build + run.
run: bench
	./bench

clean:
	rm -f *.o *.size.o bench vtable_emit_test vtable_emit_test.c

# Phase 0 P0-6 exit-criterion validation. Compiles a minimal Vader file
# with a user-defined trait impl, then verifies the emitted C contains
# the expected vtable structure and the binary runs correctly. Passing
# this target closes Phase 0.
verify:
	@echo "--- compile vtable_emit_test.vader ---"
	@bun ../../src/index.ts build vtable_emit_test.vader \
	    --target=native --release --out=vtable_emit_test
	@echo "--- grep emitted C for vtable section ---"
	@grep -q "static const vader_vtable_t vt_"        vtable_emit_test.c \
	    && echo "  ok: per-tag vtable struct emitted"
	@grep -q "const vader_vtable_t. const vader_vtable_table\[" vtable_emit_test.c \
	    && echo "  ok: vader_vtable_table[] emitted"
	@grep -q "const size_t vader_vtable_count = "     vtable_emit_test.c \
	    && echo "  ok: vader_vtable_count emitted"
	@grep -q "Greet.greet"                             vtable_emit_test.c \
	    && echo "  ok: trait.method comment present"
	@grep -q "\[8\] = (void\*)"                        vtable_emit_test.c \
	    && echo "  ok: slot 8 populated (first user slot)"
	@echo "--- run binary, expect 'vader' ---"
	@out=$$(./vtable_emit_test) ; \
	    test "$$out" = "vader" \
	    && echo "  ok: binary runs and prints 'vader'" \
	    || (echo "  FAIL: binary printed '$$out'" && exit 1)
	@echo "Phase 0 P0-6 verify: PASS"

.PHONY: all sizes run clean verify
