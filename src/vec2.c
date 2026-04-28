#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec2.h>
#include <stdio.h>

vec2_t vec2_create(float x, float y)
{
    return (vec2_t){x, y};
}

vec2_t vec2_from_scalar(float s)
{
    return vec2_create(s, s);
}

vec2_t vec2_add(vec2_t a, vec2_t b)
{
    return vec2_create(a.x + b.x, a.y + b.y);
}

vec2_t vec2_sub(vec2_t a, vec2_t b)
{
    return vec2_create(a.x - b.x, a.y - b.y);
}

float vec2_clamp_float(float val, float min, float max)
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

vec2_t vec2_mul(vec2_t a, vec2_t b)
{
    return vec2_create(a.x * b.x, a.y * b.y);
}

float vec2_dot_product(vec2_t a, vec2_t b)
{
    return (a.x * b.x) + (a.y * b.y);
}

float vec2_magnitude(vec2_t a)
{
    return sqrtf((a.x * a.x) + (a.y * a.y));
}

float vec2_magnitude_sq(vec2_t a)
{
    return (a.x * a.x) + (a.y * a.y);
}

int vec2_equals(vec2_t a, vec2_t b)
{
    return ((fabsf(a.x - b.x) < VEC2_EPSILON) && (fabsf(a.y - b.y) < VEC2_EPSILON)) ? 1 : 0;
}

void vec2_negate(vec2_t *v)
{
    v->x *= -1;
    v->y *= -1;
}

void vec2_reflect(vec2_t *r, const vec2_t a, const vec2_t b)
{
    vec2_t normal = b;
    vec2_normalize(&normal);
    float p = 2.f * vec2_dot_product(a, normal);

    r->x = a.x - p * normal.x;
    r->y = a.y - p * normal.y;
}

vec2_t vec2_lerp(vec2_t a, vec2_t b, float t)
{
    return vec2_create(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
}

void vec2_normalize(vec2_t *v)
{
    float magnitude = vec2_magnitude(*v);
    if (magnitude > VEC2_EPSILON)
    {
        float inv_magnitude = 1.0f / magnitude;
        v->x *= inv_magnitude;
        v->y *= inv_magnitude;
    }
}

void vec2_scale(float scalar, vec2_t *v)
{
    v->x *= scalar;
    v->y *= scalar;
}

void vec2_print(vec2_t v, const char *txt)
{
    printf("%s: (%.2f, %.2f)\n", txt, (double)v.x, (double)v.y);
}
