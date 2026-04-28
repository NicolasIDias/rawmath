#include <assert.h>
#include <math.h>
#include <rawmath/mat4.h>
#include <rawmath/vec3.h>
#include <stdio.h>

#ifndef EPSILON
#define EPSILON 1e-5f
#endif

int main(void)
{
    mat4_t result;
    vec3_t eye, center, up;

    eye = vec3_create(0.0f, 5.0f, 0.0f);
    center = vec3_create(0.0f, 0.0f, 0.0f);
    up = vec3_create(0.0f, 0.0f, 1.0f);

    assert(mat4_look_at(&result, eye, center, up) == 1);

    assert(fabsf(result.m[MAT_IDX(3, 0)]) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(3, 1)]) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(3, 2)]) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(3, 3)] - 1.0f) < EPSILON);

    eye = vec3_create(10.0f, 0.0f, 0.0f);
    center = vec3_create(0.0f, 0.0f, 0.0f);
    up = vec3_create(0.0f, 1.0f, 0.0f);

    assert(mat4_look_at(&result, eye, center, up) == 1);

    assert(fabsf(result.m[MAT_IDX(3, 0)]) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(3, 1)]) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(3, 2)]) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(3, 3)] - 1.0f) < EPSILON);

    eye = vec3_create(0.0f, 0.0f, 10.0f);
    center = vec3_create(0.0f, 0.0f, 0.0f);
    up = vec3_create(0.0f, 1.0f, 0.0f);

    assert(mat4_look_at(&result, eye, center, up) == 1);

    assert(fabsf(result.m[MAT_IDX(3, 0)]) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(3, 1)]) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(3, 2)]) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(3, 3)] - 1.0f) < EPSILON);

    float col0_len_sq = result.m[MAT_IDX(0, 0)] * result.m[MAT_IDX(0, 0)] +
                        result.m[MAT_IDX(1, 0)] * result.m[MAT_IDX(1, 0)] +
                        result.m[MAT_IDX(2, 0)] * result.m[MAT_IDX(2, 0)];
    float col1_len_sq = result.m[MAT_IDX(0, 1)] * result.m[MAT_IDX(0, 1)] +
                        result.m[MAT_IDX(1, 1)] * result.m[MAT_IDX(1, 1)] +
                        result.m[MAT_IDX(2, 1)] * result.m[MAT_IDX(2, 1)];
    float col2_len_sq = result.m[MAT_IDX(0, 2)] * result.m[MAT_IDX(0, 2)] +
                        result.m[MAT_IDX(1, 2)] * result.m[MAT_IDX(1, 2)] +
                        result.m[MAT_IDX(2, 2)] * result.m[MAT_IDX(2, 2)];

    assert(fabsf(col0_len_sq - 1.0f) < EPSILON);
    assert(fabsf(col1_len_sq - 1.0f) < EPSILON);
    assert(fabsf(col2_len_sq - 1.0f) < EPSILON);
    eye = vec3_create(0.0f, 0.0f, 0.0f);
    center = vec3_create(0.0f, 0.0f, 0.0f);
    up = vec3_create(0.0f, 1.0f, 0.0f);

    assert(mat4_look_at(&result, eye, center, up) == 0);

    eye = vec3_create(0.0f, 0.0f, 10.0f);
    center = vec3_create(0.0f, 0.0f, 0.0f);
    up = vec3_create(0.0f, 0.0f, 0.0f);

    assert(mat4_look_at(&result, eye, center, up) == 0);
    printf("look_at_test passed!\n");
    return 0;
}
