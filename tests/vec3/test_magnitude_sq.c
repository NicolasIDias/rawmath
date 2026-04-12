#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main(void)
{
    vec3_t v = vec3_create(3.0f, 4.0f, 12.0f);
    assert(fabsf(vec3_magnitude_sq(v) - 169.0f) < VEC3_EPSILON);

    vec3_t zero = vec3_create(0.0f, 0.0f, 0.0f);
    assert(fabsf(vec3_magnitude_sq(zero) - 0.0f) < VEC3_EPSILON);

    printf("magnitude_sq_test passed!\n");
    return 0;
}
