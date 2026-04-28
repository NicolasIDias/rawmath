#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec2.h>
#include <stdio.h>

int main(void)
{
    vec2_t a = vec2_create(2.0f, -3.0f);
    vec2_t b = vec2_create(4.0f, 0.5f);
    vec2_t r = vec2_mul(a, b);

    assert(fabsf(r.x - 8.0f) < VEC2_EPSILON);
    assert(fabsf(r.y - -1.5f) < VEC2_EPSILON);

    printf("mul_test passed!\n");
    return 0;
}
