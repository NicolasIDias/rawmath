#include <rawmath/mat4.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main()
{
    mat4_t mat, result;

    mat4_identity(&mat);
    mat4_transpose(&mat, &result);

    assert(result.m[MAT_IDX(0, 0)] == 1.0f);
    assert(result.m[MAT_IDX(1, 1)] == 1.0f);
    assert(result.m[MAT_IDX(2, 2)] == 1.0f);
    assert(result.m[MAT_IDX(3, 3)] == 1.0f);

    for (int i = 0; i < 16; i++) {
        mat.m[i] = i + 1;
    }

    mat4_transpose(&mat, &result);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            assert(result.m[MAT_IDX(i, j)] == mat.m[MAT_IDX(j, i)]);
        }
    }

    mat4_transpose(&result, &mat);

    for (int i = 0; i < 16; i++) {
        assert(fabsf(mat.m[i] - (float)(i + 1)) < 1e-5f);
    }

    printf("transpose_test passed!\n");
    return 0;
}
