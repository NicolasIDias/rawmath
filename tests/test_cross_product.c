#include <gaal/vec3.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    vec3_t incident = vec3_create(1.0f, -1.0f, 0.0f);
    vec3_t normal = vec3_create(0.0f, 1.0f, 0.0f);
    vec3_t reflection;

    vec3_reflect(&reflection, incident, normal);

    assert(reflection.x == 1.0f);
    assert(reflection.y == 1.0f);
    assert(reflection.z == 0.0f);

    printf("reflect_test passed!\n");
    return 0;
}