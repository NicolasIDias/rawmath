#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec3.h>
#include <stdio.h>

int main(void)
{
    vec3_t a = vec3_create(1.0f, 2.0f, 3.0f);
    vec3_t b = vec3_create(4.0f, -5.0f, 6.0f);

    float dot = vec3_dot_product(a, b);
    assert(fabsf(dot - 12.0f) < VEC3_EPSILON);

    printf("dot_product_test passed!\n");
    return 0;
}