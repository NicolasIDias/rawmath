#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec2.h>
#include <stdio.h>

int main(void)
{
    vec2_t a = vec2_create(1.0f, 2.0f);
    vec2_t b = vec2_create(3.0f, 4.0f);
    float dot = vec2_dot_product(a, b);

    assert(fabsf(dot - 11.0f) < VEC2_EPSILON);

    printf("dot_product_test passed!\n");
    return 0;
}
