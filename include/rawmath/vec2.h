#pragma once

#define VEC2_ZERO (vec2_t){0.0f, 0.0f}
#define VEC2_ONE (vec2_t){1.0f, 1.0f}
#define VEC2_UP (vec2_t){0.0f, 1.0f}
#define VEC2_DOWN (vec2_t){0.0f, -1.0f}
#define VEC2_LEFT (vec2_t){-1.0f, 0.0f}
#define VEC2_RIGHT (vec2_t){1.0f, 0.0f}

#define VEC2_EPSILON 1e-5f

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
vec2_t vec2_mul(vec2_t a, vec2_t b);
float vec2_dot_product(vec2_t a, vec2_t b);
float vec2_magnitude(vec2_t a);
float vec2_magnitude_sq(vec2_t a);
int vec2_equals(vec2_t a, vec2_t b);
void vec2_print(vec2_t v, const char *txt);
void vec2_scale(float scalar, vec2_t *v);
void vec2_negate(vec2_t *v);
void vec2_reflect(vec2_t *r, const vec2_t a, const vec2_t b);
void vec2_normalize(vec2_t *v);
vec2_t vec2_lerp(vec2_t a, vec2_t b, float t);
