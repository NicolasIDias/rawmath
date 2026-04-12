#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main(void)
{
    vec3_t incident = vec3_create(1.0f, -1.0f, 0.0f);
    vec3_t normal = vec3_create(0.0f, 1.0f, 0.0f);
    vec3_t reflection;

    vec3_reflect(&reflection, incident, normal);

    assert(fabsf(reflection.x - 1.0f) < VEC3_EPSILON);
    assert(fabsf(reflection.y - 1.0f) < VEC3_EPSILON);
    assert(fabsf(reflection.z - 0.0f) < VEC3_EPSILON);

    printf("reflect_test passed!\n");
    return 0;
}