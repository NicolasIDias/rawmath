#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main(void)
{
    vec3_t a = vec3_create(1.0f, 2.0f, 3.0f);
    vec3_t b = vec3_create(4.0f, -1.0f, 2.0f);
    vec3_t c = vec3_create(7.0f, -9.0f, 10.0f);
    float r = vec3_triple_product(a, b, c);

    assert(fabsf(r - -131.0f) < VEC3_EPSILON);

    printf("add_test passed!\n");
    return 0;
}