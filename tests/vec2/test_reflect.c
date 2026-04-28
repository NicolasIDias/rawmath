#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec2.h>
#include <stdio.h>

int main(void)
{
    vec2_t incident = vec2_create(1.0f, -1.0f);
    vec2_t normal = vec2_create(0.0f, 1.0f);
    vec2_t reflection;

    vec2_reflect(&reflection, incident, normal);

    assert(fabsf(reflection.x - 1.0f) < VEC2_EPSILON);
    assert(fabsf(reflection.y - 1.0f) < VEC2_EPSILON);

    printf("reflect_test passed!\n");
    return 0;
}
