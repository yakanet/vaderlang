/* The C half of the `greeter` binding. */
#ifndef GREETER_H
#define GREETER_H

typedef struct {
    float x;
    float y;
} GreeterPoint;

typedef struct {
    int* data;
    int size;
} GreeterBox;

int greeter_add(int a, int b);
const char* greeter_name(void);
GreeterPoint greeter_scale(GreeterPoint p, float k);
GreeterBox greeter_box(int value);
int greeter_unbox(GreeterBox box);

#endif
