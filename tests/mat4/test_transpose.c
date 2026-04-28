#include <assert.h>
#include <math.h>
#include <rawmath/mat4.h>
#include <stdio.h>

int main(void)
{
    mat4_t mat, result;

    mat4_identity(&mat);
    mat4_transpose(&result, &mat);

    assert(fabsf(result.m[MAT_IDX(0, 0)] - 1.0f) < 1e-6f);
    assert(fabsf(result.m[MAT_IDX(1, 1)] - 1.0f) < 1e-6f);
    assert(fabsf(result.m[MAT_IDX(2, 2)] - 1.0f) < 1e-6f);
    assert(fabsf(result.m[MAT_IDX(3, 3)] - 1.0f) < 1e-6f);

    for (int i = 0; i < 16; i++)
    {
        mat.m[i] = (float)(i + 1);
    }

    mat4_transpose(&mat, &result);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            assert(fabsf(result.m[MAT_IDX(i, j)] - mat.m[MAT_IDX(j, i)]) < 1e-6f);
        }
    }

    mat4_transpose(&mat, &result);

    printf("transpose_test passed!\n");
    return 0;
}
