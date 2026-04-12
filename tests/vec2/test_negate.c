#include <rawmath/vec2.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main(void)
{
    vec2_t v = vec2_create(1.0f, -2.0f);

    vec2_negate(&v);

    assert(fabsf(v.x + 1.0f) < VEC2_EPSILON);
    assert(fabsf(v.y - 2.0f) < VEC2_EPSILON);

    printf("negate_test passed!\n");
    return 0;
}
