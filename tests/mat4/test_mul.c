#include <rawmath/mat4.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main()
{
    mat4_t a, b, result;

    mat4_identity(&a);
    mat4_identity(&b);
    mat4_mul(&a, &b, &result);

    assert(result.m[MAT_IDX(0, 0)] == 1.0f);
    assert(result.m[MAT_IDX(1, 1)] == 1.0f);
    assert(result.m[MAT_IDX(2, 2)] == 1.0f);
    assert(result.m[MAT_IDX(3, 3)] == 1.0f);

    for (int i = 0; i < 16; i++) {
        a.m[i] = i + 1;
    }
    mat4_identity(&b);
    mat4_mul(&a, &b, &result);

    for (int i = 0; i < 16; i++) {
        assert(fabsf(result.m[i] - (float)(i + 1)) < 1e-5f);
    }

    for (int i = 0; i < 16; i++) {
        a.m[i] = 1.0f;
        b.m[i] = 1.0f;
    }
    mat4_mul(&a, &b, &result);

    for (int i = 0; i < 16; i++) {
        assert(fabsf(result.m[i] - 4.0f) < 1e-5f);
    }

    printf("mul_test passed!\n");
    return 0;
}
