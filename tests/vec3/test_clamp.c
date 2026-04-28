#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec3.h>
#include <stdio.h>

int main(void)
{
    float min = 0.0f;
    float max = 100.0f;

    assert(fabsf(vec3_clamp(-50.0f, min, max) - 0.0f) < VEC3_EPSILON);

    assert(fabsf(vec3_clamp(150.0f, min, max) - 100.0f) < VEC3_EPSILON);

    assert(fabsf(vec3_clamp(42.5f, min, max) - 42.5f) < VEC3_EPSILON);

    assert(fabsf(vec3_clamp(0.0f, min, max) - 0.0f) < VEC3_EPSILON);

    assert(fabsf(vec3_clamp(100.0f, min, max) - 100.0f) < VEC3_EPSILON);

    printf("test_clamp passed!\n");
    return 0;
}