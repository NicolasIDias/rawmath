#include <rawmath/mat4.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define EPSILON 1e-5f

int main()
{
    mat4_t mat, result;
    vec3_t axis;

    mat4_identity(&mat);
    axis = vec3_create(0.0f, 0.0f, 1.0f);
    mat4_rotate(&mat, &result, axis, 0.0f);

    assert(fabsf(result.m[MAT_IDX(0, 0)] - 1.0f) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(1, 1)] - 1.0f) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(2, 2)] - 1.0f) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(3, 3)] - 1.0f) < EPSILON);

    mat4_identity(&mat);
    axis = vec3_create(0.0f, 0.0f, 1.0f);
    mat4_rotate(&mat, &result, axis, M_PI / 2.0f);

    assert(fabsf(result.m[MAT_IDX(0, 0)]) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(1, 1)]) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(2, 2)] - 1.0f) < EPSILON);

    mat4_identity(&mat);
    axis = vec3_create(1.0f, 0.0f, 0.0f);
    mat4_rotate(&mat, &result, axis, M_PI);

    assert(fabsf(result.m[MAT_IDX(0, 0)] - 1.0f) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(1, 1)] + 1.0f) < EPSILON);
    assert(fabsf(result.m[MAT_IDX(2, 2)] + 1.0f) < EPSILON);

    printf("rotate_test passed!\n");
    return 0;
}
