#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec3.h>
#include <stdio.h>

int main(void)
{
    vec3_t v = vec3_create(2.0f, -3.0f, 4.0f);

    vec3_scale(2.5f, &v);

    assert(fabsf(v.x - 5.0f) < VEC3_EPSILON);
    assert(fabsf(v.y - -7.5f) < VEC3_EPSILON);
    assert(fabsf(v.z - 10.0f) < VEC3_EPSILON);

    printf("scale_test passed!\n");
    return 0;
}