#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec2.h>
#include <stdio.h>

int main(void)
{
    vec2_t a = vec2_create(1.0f, 2.0f);
    vec2_t b = vec2_create(4.0f, -1.0f);
    vec2_t r = vec2_add(a, b);

    assert(fabsf(r.x - 5.0f) < VEC2_EPSILON);
    assert(fabsf(r.y - 1.0f) < VEC2_EPSILON);

    printf("add_test passed!\n");
    return 0;
}
