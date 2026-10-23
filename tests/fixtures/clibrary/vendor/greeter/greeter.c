/* Compiled into `lib/<os>-<arch>/libgreeter.a` by the test. */
#include "greeter.h"

int greeter_add(int a, int b) {
    return a + b;
}

const char* greeter_name(void) {
    return "hello from C";
}
