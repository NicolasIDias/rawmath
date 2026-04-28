#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec3.h>
#include <stdio.h>

int main(void)
{
    vec3_t v1 = vec3_create(3.0f, 4.0f, 0.0f);
    assert(fabsf(vec3_magnitude(v1) - 5.0f) < VEC3_EPSILON);

    vec3_t v2 = vec3_create(2.0f, 3.0f, 6.0f);
    assert(fabsf(vec3_magnitude(v2) - 7.0f) < VEC3_EPSILON);

    vec3_t v3 = vec3_create(0.0f, 0.0f, 0.0f);
    assert(fabsf(vec3_magnitude(v3) - 0.0f) < VEC3_EPSILON);

    vec3_t v4 = vec3_create(-2.0f, -3.0f, -6.0f);
    assert(fabsf(vec3_magnitude(v4) - 7.0f) < VEC3_EPSILON);

    printf("magnitude_test passed!\n");
    return 0;
}