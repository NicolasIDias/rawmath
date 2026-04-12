#include <rawmath/vec2.h>
#include <math.h>
#include <stdio.h>

vec2_t vec2_create(float x, float y)
{
    return (vec2_t){
        x, y};
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
    return (a.x * b.x) * (a.y * b.y);
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
    return (
               (fabsf(a.x - b.x) < VEC2_EPSILON) &&
               (fabsf(a.y - b.y) < VEC2_EPSILON))
               ? 1
               : 0;
}

void vec2_print(vec2_t v, const char *txt)
{
    printf("%s: (%.2f, %.2f)\n", txt, (double)v.x, (double)v.y);
}
