#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main()
{
    vec3_t v1 = vec3_create(1.0f, 0.0f, 0.0f);
    vec3_normalize(&v1);
    vec3_t expected_v1 = vec3_create(1.0f, 0.0f, 0.0f);
    assert(vec3_equals(v1, expected_v1) == 1);

    vec3_t v2 = vec3_create(0.0f, 5.0f, 0.0f);
    vec3_normalize(&v2);
    vec3_t expected_v2 = vec3_create(0.0f, 1.0f, 0.0f);
    assert(vec3_equals(v2, expected_v2) == 1);

    vec3_t v3 = vec3_create(1.0f, 2.0f, 2.0f);
    vec3_normalize(&v3);
    vec3_t expected_v3 = vec3_create(1.0f / 3.0f, 2.0f / 3.0f, 2.0f / 3.0f);
    assert(vec3_equals(v3, expected_v3) == 1);

    assert(fabsf(vec3_magnitude(v3) - 1.0f) < VEC3_EPSILON);

    vec3_t v4 = vec3_create(0.0f, 0.0f, 0.0f);
    vec3_normalize(&v4);
    vec3_t expected_v4 = vec3_create(0.0f, 0.0f, 0.0f);
    assert(vec3_equals(v4, expected_v4) == 1);

    printf("normalize_test passed!\n");
    return 0;
}