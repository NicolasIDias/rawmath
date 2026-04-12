#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main(void)
{
    vec3_t v = vec3_create(1.0f, 2.0f, 3.5f);

    assert(fabsf(v.x - 1.0f) < VEC3_EPSILON);
    assert(fabsf(v.y - 2.0f) < VEC3_EPSILON);
    assert(fabsf(v.z - 3.5f) < VEC3_EPSILON);

    printf("create_test passed!\n");
    return 0;
}