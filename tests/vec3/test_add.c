#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec3.h>
#include <stdio.h>

int main(void)
{
    vec3_t a = vec3_create(1.0f, 2.0f, 3.0f);
    vec3_t b = vec3_create(4.0f, -1.0f, 2.0f);
    vec3_t r = vec3_add(a, b);

    assert(fabsf(r.x - 5.0f) < VEC3_EPSILON);
    assert(fabsf(r.y - 1.0f) < VEC3_EPSILON);
    assert(fabsf(r.z - 5.0f) < VEC3_EPSILON);

    printf("add_test passed!\n");
    return 0;
}