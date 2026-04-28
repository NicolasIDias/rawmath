#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec2.h>
#include <stdio.h>

int main(void)
{
    vec2_t v = vec2_create(3.0f, 4.0f);
    assert(fabsf(vec2_magnitude_sq(v) - 25.0f) < VEC2_EPSILON);

    printf("magnitude_sq_test passed!\n");
    return 0;
}
