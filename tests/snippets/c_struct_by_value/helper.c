/* Foreign half of `c_struct_by_value`. Every struct is taken and returned by
 * value; `helper.h` owns the types. */
#include "helper.h"

Rgba rgba_invert(Rgba c) {
    Rgba out = { (unsigned char) (255 - c.r), (unsigned char) (255 - c.g),
                 (unsigned char) (255 - c.b), c.a };
    return out;
}

int rgba_sum(Rgba c) {
    return c.r + c.g + c.b + c.a;
}

Vec2 vec2_scale(Vec2 v, float k) {
    Vec2 out = { v.x * k, v.y * k };
    return out;
}

Box2 box2_grow(Box2 b, float by) {
    Box2 out = { { b.origin.x - by, b.origin.y - by },
                 { b.extent.x + 2 * by, b.extent.y + 2 * by } };
    return out;
}

float box2_area(Box2 b) {
    return b.extent.x * b.extent.y;
}

Texture texture_load(unsigned int id) {
    Texture t = { id, 64, 32, 1, 7 };
    return t;
}

int texture_checksum(Texture t) {
    return (int) t.id * 10000 + t.width * 100 + t.height + t.mipmaps * 7 + t.format;
}
