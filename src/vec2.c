#include <rawmath/vec2.h>

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