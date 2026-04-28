#include <assert.h>
#include <math.h>
#include <rawmath/common.h>
#include <rawmath/vec2.h>
#include <stdio.h>

int main(void)
{
    vec2_t v = vec2_create(2.0f, -3.0f);

    vec2_scale(2.5f, &v);

    assert(fabsf(v.x - 5.0f) < VEC2_EPSILON);
    assert(fabsf(v.y + 7.5f) < VEC2_EPSILON);

    printf("scale_test passed!\n");
    return 0;
}
