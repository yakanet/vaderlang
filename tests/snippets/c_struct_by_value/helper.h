/* Foreign half of `c_struct_by_value`: structs a C library passes and returns
 * by value. Each one travels differently under the ABIs we build for: four bytes
 * in one integer register, two floats in vector registers, two of those held
 * inline, and twenty bytes, past what any of them passes in registers. */
#ifndef C_STRUCT_BY_VALUE_HELPER_H
#define C_STRUCT_BY_VALUE_HELPER_H

typedef struct Rgba {
    unsigned char r, g, b, a;
} Rgba;

typedef struct Vec2 {
    float x, y;
} Vec2;

typedef struct Box2 {
    Vec2 origin;
    Vec2 extent;
} Box2;

/* The shape of raylib's `Texture`. */
typedef struct Texture {
    unsigned int id;
    int width;
    int height;
    int mipmaps;
    int format;
} Texture;

Rgba rgba_invert(Rgba c);
int rgba_sum(Rgba c);
Vec2 vec2_scale(Vec2 v, float k);
Box2 box2_grow(Box2 b, float by);
float box2_area(Box2 b);
Texture texture_load(unsigned int id);
int texture_checksum(Texture t);

#endif
