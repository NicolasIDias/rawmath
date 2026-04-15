#pragma once


typedef struct vec3
{
    float x;
    float y;
    float z;
} vec3_t;

vec3_t vec3_create(float x, float y, float z);
vec3_t vec3_add(vec3_t a, vec3_t b);
vec3_t vec3_sub(vec3_t a, vec3_t b);
float vec3_dot_product(const vec3_t u, const vec3_t v);
vec3_t vec3_cross_product(const vec3_t a, const vec3_t b);
float vec3_triple_product(const vec3_t a, const vec3_t b, const vec3_t c);
float vec3_magnitude(const vec3_t v);
int vec3_equals(vec3_t a, vec3_t b);
void vec3_print(vec3_t v, const char *txt);
void vec3_scale(float scalar, vec3_t *v);
void vec3_negate(vec3_t *v);
void vec3_reflect(vec3_t *r, const vec3_t a, const vec3_t b);
void vec3_normalize(vec3_t *v);
vec3_t vec3_lerp(vec3_t a, vec3_t b, float t);
float vec3_magnitude_sq(vec3_t v);
float vec3_clamp(float val, float min, float max);
vec3_t vec3_mul(const vec3_t a, const vec3_t b);
