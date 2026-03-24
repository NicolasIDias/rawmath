#include <gaal/vec3.h>
#include <stdio.h>
#include <math.h>

vec3_t vec3_create(float x, float y, float z)
{
    vec3_t vec = {x, y, z};
    return vec;
}

vec3_t vec3_add(vec3_t a, vec3_t b)
{
    return vec3_create(a.x + b.x, a.y + b.y, a.z + b.z);
}
vec3_t vec3_sub(vec3_t a, vec3_t b)
{
    return vec3_create(a.x - b.x, a.y - b.y, a.z - b.z);
}

float vec3_dot_product(const vec3_t *u, const vec3_t *v)
{
    return (u->x * v->x) + (u->y * v->y) + (u->z * v->z);
}

vec3_t vec3_cross_product(vec3_t *a, vec3_t *b)
{
    vec3_t v;
    v.x = (a->y * b->z) - (a->z * b->y);
    v.y = (a->z * b->x) - (a->x * b->z);
    v.z = (a->x * b->y) - (a->y * b->x);
    return v;
}

void vec3_scale(float scalar, vec3_t *v)
{
    v->x *= scalar;
    v->y *= scalar;
    v->z *= scalar;
}

int vec3_equals(vec3_t *a, vec3_t *b)
{
    return (
               (fabsf(a->x - b->x) < VEC3_EPSILON) &&
               (fabsf(a->y - b->y) < VEC3_EPSILON) &&
               (fabsf(a->z - b->z) < VEC3_EPSILON))
               ? 1
               : 0;
}

void vec3_negate(vec3_t *v)
{
    v->x *= -1;
    v->y *= -1;
    v->z *= -1;
}

void vec3_reflect(vec3_t *r, const vec3_t *a, const vec3_t *b)
{
    float p = 2.f * vec3_dot_product(a, b);
    
    r->x = a->x - p*b->x;
    r->y = a->y - p*b->y;
    r->z = a->z - p*b->z;
}

void vec3_print(vec3_t *v, const char *txt)
{
    printf("%s: (%.2f, %.2f, %.2f)\n", txt, v->x, v->y, v->z);
}
