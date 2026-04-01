#include <rawmath/mat4.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    mat4_t mat;
    mat4_identity(&mat);

    assert(mat.m[MAT_IDX(0, 0)] == 1.0f);
    assert(mat.m[MAT_IDX(1, 1)] == 1.0f);
    assert(mat.m[MAT_IDX(2, 2)] == 1.0f);
    assert(mat.m[MAT_IDX(3, 3)] == 1.0f);

    assert(mat.m[MAT_IDX(0, 1)] == 0.0f);
    assert(mat.m[MAT_IDX(0, 2)] == 0.0f);
    assert(mat.m[MAT_IDX(0, 3)] == 0.0f);
    assert(mat.m[MAT_IDX(1, 0)] == 0.0f);
    assert(mat.m[MAT_IDX(1, 2)] == 0.0f);
    assert(mat.m[MAT_IDX(1, 3)] == 0.0f);
    assert(mat.m[MAT_IDX(2, 0)] == 0.0f);
    assert(mat.m[MAT_IDX(2, 1)] == 0.0f);
    assert(mat.m[MAT_IDX(2, 3)] == 0.0f);
    assert(mat.m[MAT_IDX(3, 0)] == 0.0f);
    assert(mat.m[MAT_IDX(3, 1)] == 0.0f);
    assert(mat.m[MAT_IDX(3, 2)] == 0.0f);

    printf("identity_test passed!\n");
    return 0;
}
