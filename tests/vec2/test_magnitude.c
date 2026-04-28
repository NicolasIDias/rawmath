#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec2.h>
#include <stdio.h>

int main(void)
{
    vec2_t v1 = vec2_create(3.0f, 4.0f);
    assert(fabsf(vec2_magnitude(v1) - 5.0f) < VEC2_EPSILON);

    vec2_t v2 = vec2_create(0.0f, 0.0f);
    assert(fabsf(vec2_magnitude(v2) - 0.0f) < VEC2_EPSILON);

    printf("magnitude_test passed!\n");
    return 0;
}
