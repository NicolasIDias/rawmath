#include <rawmath/mat4.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main(void)
{
    mat4_t a, b, result;

    for (int i = 0; i < 16; i++)
    {
        a.m[i] = 5.0f;
        b.m[i] = 2.0f;
    }

    mat4_sub(&result, &a, &b);

    for (int i = 0; i < 16; i++)
    {
        assert(fabsf(result.m[i] - 3.0f) < 1e-6f);
    }

    mat4_identity(&a);
    for (int i = 0; i < 16; i++)
    {
        b.m[i] = 0.0f;
    }

    mat4_sub(&result, &a, &b);

    assert(fabsf(result.m[MAT_IDX(0, 0)] - 1.0f) < 1e-6f);
    assert(fabsf(result.m[MAT_IDX(1, 1)] - 1.0f) < 1e-6f);
    assert(fabsf(result.m[MAT_IDX(2, 2)] - 1.0f) < 1e-6f);
    assert(fabsf(result.m[MAT_IDX(3, 3)] - 1.0f) < 1e-6f);

    for (int i = 0; i < 16; i++)
    {
        a.m[i] = 1.0f;
        b.m[i] = 3.0f;
    }

    mat4_sub(&result, &a, &b);

    for (int i = 0; i < 16; i++)
    {
        assert(fabsf(result.m[i] - -2.0f) < 1e-6f);
    }

    printf("sub_test passed!\n");
    return 0;
}
