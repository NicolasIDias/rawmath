#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec2.h>
#include <stdio.h>

int main(void)
{
    vec2_t a = vec2_create(5.0f, 5.0f);
    vec2_t b = vec2_create(2.0f, 7.0f);
    vec2_t r = vec2_sub(a, b);

    assert(fabsf(r.x - 3.0f) < VEC2_EPSILON);
    assert(fabsf(r.y - -2.0f) < VEC2_EPSILON);

    printf("sub_test passed!\n");
    return 0;
}
