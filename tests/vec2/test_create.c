#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec2.h>
#include <stdio.h>

int main(void)
{
    vec2_t v = vec2_create(1.0f, 2.0f);
    assert(fabsf(v.x - 1.0f) < VEC2_EPSILON);
    assert(fabsf(v.y - 2.0f) < VEC2_EPSILON);

    vec2_t s = vec2_from_scalar(3.5f);
    assert(fabsf(s.x - 3.5f) < VEC2_EPSILON);
    assert(fabsf(s.y - 3.5f) < VEC2_EPSILON);

    printf("create_test passed!\n");
    return 0;
}
