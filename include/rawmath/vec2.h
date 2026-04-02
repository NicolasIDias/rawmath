#pragma once

#define VEC2_ZERO (vec2_t){0.0f, 0.0f}
#define VEC2_ONE (vec2_t){1.0f, 1.0f}
#define VEC2_UP (vec2_t){0.0f, 1.0f}
#define VEC2_DOWN (vec2_t){0.0f, -1.0f}
#define VEC2_LEFT (vec2_t){-1.0f, 0.0f}
#define VEC2_RIGHT (vec2_t){1.0f, 0.0f}

typedef struct vec2
{

    float x;
    float y;

} vec2_t;

vec2_t vec2_create(float x, float y);
vec2_t vec2_from_scalar(float s);
vec2_t vec2_add(vec2_t a, vec2_t b);
vec2_t vec2_sub(vec2_t a, vec2_t b);
float vec2_clamp_float(float val, float min, float max);