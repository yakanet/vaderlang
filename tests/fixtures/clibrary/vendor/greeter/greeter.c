/* Compiled into `lib/<os>-<arch>/libgreeter.a` by the test. */
#include <stdlib.h>

#include "greeter.h"

int greeter_add(int a, int b) {
    return a + b;
}

const char* greeter_name(void) {
    return "hello from C";
}

GreeterPoint greeter_scale(GreeterPoint p, float k) {
    GreeterPoint scaled = { p.x * k, p.y * k };
    return scaled;
}

GreeterBox greeter_box(int value) {
    GreeterBox box = { malloc(sizeof(int)), 1 };
    *box.data = value;
    return box;
}

int greeter_unbox(GreeterBox box) {
    int value = *box.data;
    free(box.data);
    return value;
}
