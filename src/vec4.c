#include <math.h>
#include <rawmath/common.h>
#include <stdio.h>

vec4_t vec4_create(float x, float y, float z, float w)
{

    vec4_t vec = {x, y, z, w};
    return vec;
}
