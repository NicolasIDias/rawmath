#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    vec3_t a = vec3_create(1.0f, 2.0f, 3.0f);
    vec3_t b = vec3_create(4.0f, -5.0f, 6.0f);

    float dot = vec3_dot_product(a, b);
    assert(dot == 12.0f);

    printf("dot_product_test passed!\n");
    return 0;
}