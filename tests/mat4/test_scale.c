#include <rawmath/mat4.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main(void)
{
    mat4_t mat, result;

    mat4_identity(&mat);
    mat4_scale(&result, &mat, 2.0f, 3.0f, 4.0f);

    assert(fabsf(result.m[MAT_IDX(0, 0)] - 2.0f) < 1e-5f);
    assert(fabsf(result.m[MAT_IDX(1, 1)] - 3.0f) < 1e-5f);
    assert(fabsf(result.m[MAT_IDX(2, 2)] - 4.0f) < 1e-5f);
    assert(fabsf(result.m[MAT_IDX(3, 3)] - 1.0f) < 1e-5f);

    mat4_identity(&mat);
    mat4_scale(&result, &mat, 5.0f, 5.0f, 5.0f);

    assert(fabsf(result.m[MAT_IDX(0, 0)] - 5.0f) < 1e-5f);
    assert(fabsf(result.m[MAT_IDX(1, 1)] - 5.0f) < 1e-5f);
    assert(fabsf(result.m[MAT_IDX(2, 2)] - 5.0f) < 1e-5f);

    mat4_identity(&mat);
    mat4_scale(&result, &mat, 1.0f, 1.0f, 1.0f);

    assert(fabsf(result.m[MAT_IDX(0, 0)] - 1.0f) < 1e-6f);
    assert(fabsf(result.m[MAT_IDX(1, 1)] - 1.0f) < 1e-6f);
    assert(fabsf(result.m[MAT_IDX(2, 2)] - 1.0f) < 1e-6f);
    assert(fabsf(result.m[MAT_IDX(3, 3)] - 1.0f) < 1e-6f);

    printf("scale_test passed!\n");
    return 0;
}
