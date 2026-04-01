#include <rawmath/mat4.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main()
{
    mat4_t mat, result;

    mat4_identity(&mat);
    mat4_translate(&mat, &result, 5.0f, 10.0f, 15.0f);

    assert(fabsf(result.m[MAT_IDX(0, 3)] - 5.0f) < 1e-5f);
    assert(fabsf(result.m[MAT_IDX(1, 3)] - 10.0f) < 1e-5f);
    assert(fabsf(result.m[MAT_IDX(2, 3)] - 15.0f) < 1e-5f);

    mat4_identity(&mat);
    mat4_translate(&mat, &result, 0.0f, 0.0f, 0.0f);

    assert(result.m[MAT_IDX(0, 0)] == 1.0f);
    assert(result.m[MAT_IDX(1, 1)] == 1.0f);
    assert(result.m[MAT_IDX(2, 2)] == 1.0f);
    assert(result.m[MAT_IDX(3, 3)] == 1.0f);

    mat4_identity(&mat);
    mat4_translate(&mat, &result, -2.0f, -3.0f, -4.0f);

    assert(fabsf(result.m[MAT_IDX(0, 3)] - (-2.0f)) < 1e-5f);
    assert(fabsf(result.m[MAT_IDX(1, 3)] - (-3.0f)) < 1e-5f);
    assert(fabsf(result.m[MAT_IDX(2, 3)] - (-4.0f)) < 1e-5f);

    printf("translate_test passed!\n");
    return 0;
}
