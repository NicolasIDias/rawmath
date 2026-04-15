#include <rawmath/mat4.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

#ifndef EPSILON
#define EPSILON 1e-5f
#endif
int main(void)
{
    mat4_t result;

    assert(mat4_perspective(&result, M_PI / 4.0f, 16.0f / 9.0f, 0.1f, 100.0f) == 1);
    assert(fabsf(result.m[MAT_IDX(0, 0)]) > EPSILON);
    assert(fabsf(result.m[MAT_IDX(1, 1)]) > EPSILON);
    assert(result.m[MAT_IDX(2, 2)] < -EPSILON);
    assert(fabsf(result.m[MAT_IDX(3, 2)] + 1.0f) < EPSILON);

    mat4_perspective(&result, M_PI / 2.0f, 1.0f, 1.0f, 10.0f);

    assert(fabsf(result.m[MAT_IDX(0, 0)]) > EPSILON);
    assert(fabsf(result.m[MAT_IDX(1, 1)]) > EPSILON);
    assert(result.m[MAT_IDX(2, 2)] < -EPSILON);
    assert(fabsf(result.m[MAT_IDX(3, 2)] + 1.0f) < EPSILON);

    assert(mat4_perspective(&result, M_PI / 6.0f, 21.0f / 9.0f, 0.01f, 1000.0f) == 1);

    assert(fabsf(result.m[MAT_IDX(0, 0)]) > EPSILON);
    assert(fabsf(result.m[MAT_IDX(1, 1)]) > EPSILON);
    assert(result.m[MAT_IDX(2, 2)] < -EPSILON);
    assert(fabsf(result.m[MAT_IDX(3, 2)] + 1.0f) < EPSILON);

    assert(mat4_perspective(&result, 0.0f, 16.0f / 9.0f, 0.1f, 100.0f) == 0);
    assert(mat4_perspective(&result, M_PI, 16.0f / 9.0f, 0.1f, 100.0f) == 0);
    assert(mat4_perspective(&result, M_PI / 4.0f, 0.0f, 0.1f, 100.0f) == 0);
    assert(mat4_perspective(&result, M_PI / 4.0f, 16.0f / 9.0f, 0.1f, 0.1f) == 0);

    printf("perspective_test passed!\n");
    return 0;
}
