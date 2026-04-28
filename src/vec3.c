#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec3.h>
#include <stdio.h>

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

vec3_t vec3_mul(const vec3_t a, const vec3_t b)
{
    return vec3_create(a.x * b.x, a.y * b.y, a.z * b.z);
}

float vec3_dot_product(const vec3_t u, const vec3_t v)
{
    return (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
}

vec3_t vec3_cross_product(const vec3_t a, const vec3_t b)
{
    vec3_t v;
    v.x = (a.y * b.z) - (a.z * b.y);
    v.y = (a.z * b.x) - (a.x * b.z);
    v.z = (a.x * b.y) - (a.y * b.x);
    return v;
}

void vec3_scale(float scalar, vec3_t *v)
{
    v->x *= scalar;
    v->y *= scalar;
    v->z *= scalar;
}

int vec3_equals(vec3_t a, vec3_t b)
{
    return ((fabsf(a.x - b.x) < VEC3_EPSILON) && (fabsf(a.y - b.y) < VEC3_EPSILON) && (fabsf(a.z - b.z) < VEC3_EPSILON))
               ? 1
               : 0;
}

void vec3_negate(vec3_t *v)
{
    v->x *= -1;
    v->y *= -1;
    v->z *= -1;
}

void vec3_reflect(vec3_t *r, const vec3_t a, const vec3_t b)
{
    vec3_t normal = b;
    vec3_normalize(&normal);
    float p = 2.f * vec3_dot_product(a, normal);
    r->x = a.x - p * normal.x;
    r->y = a.y - p * normal.y;
    r->z = a.z - p * normal.z;
}
float vec3_triple_product(const vec3_t a, const vec3_t b, const vec3_t c)
{
    vec3_t cross_product = vec3_cross_product(b, c);
    return vec3_dot_product(a, cross_product);
}

float vec3_magnitude(const vec3_t v)
{
    float p1 = v.x * v.x;
    float p2 = v.y * v.y;
    float p3 = v.z * v.z;

    return sqrtf(p1 + p2 + p3);
}

float vec3_magnitude_sq(vec3_t v)
{
    return (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
}

vec3_t vec3_lerp(vec3_t a, vec3_t b, float t)
{
    return vec3_create(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t);
}

void vec3_normalize(vec3_t *v)
{
    float magnitude = vec3_magnitude(*v);
    if (magnitude > VEC3_EPSILON)
    {
        float inv_magnitude = 1.0f / magnitude;
        v->x *= inv_magnitude;
        v->y *= inv_magnitude;
        v->z *= inv_magnitude;
    }
}

float vec3_clamp(float val, float min, float max)
{
    if (val < min)
    {
        val = min;
    }
    else if (val > max)
    {
        val = max;
    }
    return val;
}

void vec3_print(vec3_t v, const char *txt)
{
    printf("%s: (%.2f, %.2f, %.2f)\n", txt, (double)v.x, (double)v.y, (double)v.z);
}
