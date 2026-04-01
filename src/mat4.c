#include <stdio.h>
#include <rawmath/mat4.h>
#include <rawmath/vec3.h>
#include <math.h>

void mat4_identity(mat4_t *dest)
{
    mat4_t mat = {0};

    mat.m[MAT_IDX(0, 0)] = 1.0f;
    mat.m[MAT_IDX(1, 1)] = 1.0f;
    mat.m[MAT_IDX(2, 2)] = 1.0f;
    mat.m[MAT_IDX(3, 3)] = 1.0f;

    *dest = mat;
}

void mat4_mul(const mat4_t *a, const mat4_t *b, mat4_t *dest)
{
    mat4_t temp;

    temp.m[MAT_IDX(0, 0)] = (a->m[MAT_IDX(0, 0)] * b->m[MAT_IDX(0, 0)]) + (a->m[MAT_IDX(0, 1)] * b->m[MAT_IDX(1, 0)]) + (a->m[MAT_IDX(0, 2)] * b->m[MAT_IDX(2, 0)]) + (a->m[MAT_IDX(0, 3)] * b->m[MAT_IDX(3, 0)]);
    temp.m[MAT_IDX(1, 0)] = (a->m[MAT_IDX(1, 0)] * b->m[MAT_IDX(0, 0)]) + (a->m[MAT_IDX(1, 1)] * b->m[MAT_IDX(1, 0)]) + (a->m[MAT_IDX(1, 2)] * b->m[MAT_IDX(2, 0)]) + (a->m[MAT_IDX(1, 3)] * b->m[MAT_IDX(3, 0)]);
    temp.m[MAT_IDX(2, 0)] = (a->m[MAT_IDX(2, 0)] * b->m[MAT_IDX(0, 0)]) + (a->m[MAT_IDX(2, 1)] * b->m[MAT_IDX(1, 0)]) + (a->m[MAT_IDX(2, 2)] * b->m[MAT_IDX(2, 0)]) + (a->m[MAT_IDX(2, 3)] * b->m[MAT_IDX(3, 0)]);
    temp.m[MAT_IDX(3, 0)] = (a->m[MAT_IDX(3, 0)] * b->m[MAT_IDX(0, 0)]) + (a->m[MAT_IDX(3, 1)] * b->m[MAT_IDX(1, 0)]) + (a->m[MAT_IDX(3, 2)] * b->m[MAT_IDX(2, 0)]) + (a->m[MAT_IDX(3, 3)] * b->m[MAT_IDX(3, 0)]);

    temp.m[MAT_IDX(0, 1)] = (a->m[MAT_IDX(0, 0)] * b->m[MAT_IDX(0, 1)]) + (a->m[MAT_IDX(0, 1)] * b->m[MAT_IDX(1, 1)]) + (a->m[MAT_IDX(0, 2)] * b->m[MAT_IDX(2, 1)]) + (a->m[MAT_IDX(0, 3)] * b->m[MAT_IDX(3, 1)]);
    temp.m[MAT_IDX(1, 1)] = (a->m[MAT_IDX(1, 0)] * b->m[MAT_IDX(0, 1)]) + (a->m[MAT_IDX(1, 1)] * b->m[MAT_IDX(1, 1)]) + (a->m[MAT_IDX(1, 2)] * b->m[MAT_IDX(2, 1)]) + (a->m[MAT_IDX(1, 3)] * b->m[MAT_IDX(3, 1)]);
    temp.m[MAT_IDX(2, 1)] = (a->m[MAT_IDX(2, 0)] * b->m[MAT_IDX(0, 1)]) + (a->m[MAT_IDX(2, 1)] * b->m[MAT_IDX(1, 1)]) + (a->m[MAT_IDX(2, 2)] * b->m[MAT_IDX(2, 1)]) + (a->m[MAT_IDX(2, 3)] * b->m[MAT_IDX(3, 1)]);
    temp.m[MAT_IDX(3, 1)] = (a->m[MAT_IDX(3, 0)] * b->m[MAT_IDX(0, 1)]) + (a->m[MAT_IDX(3, 1)] * b->m[MAT_IDX(1, 1)]) + (a->m[MAT_IDX(3, 2)] * b->m[MAT_IDX(2, 1)]) + (a->m[MAT_IDX(3, 3)] * b->m[MAT_IDX(3, 1)]);

    temp.m[MAT_IDX(0, 2)] = (a->m[MAT_IDX(0, 0)] * b->m[MAT_IDX(0, 2)]) + (a->m[MAT_IDX(0, 1)] * b->m[MAT_IDX(1, 2)]) + (a->m[MAT_IDX(0, 2)] * b->m[MAT_IDX(2, 2)]) + (a->m[MAT_IDX(0, 3)] * b->m[MAT_IDX(3, 2)]);
    temp.m[MAT_IDX(1, 2)] = (a->m[MAT_IDX(1, 0)] * b->m[MAT_IDX(0, 2)]) + (a->m[MAT_IDX(1, 1)] * b->m[MAT_IDX(1, 2)]) + (a->m[MAT_IDX(1, 2)] * b->m[MAT_IDX(2, 2)]) + (a->m[MAT_IDX(1, 3)] * b->m[MAT_IDX(3, 2)]);
    temp.m[MAT_IDX(2, 2)] = (a->m[MAT_IDX(2, 0)] * b->m[MAT_IDX(0, 2)]) + (a->m[MAT_IDX(2, 1)] * b->m[MAT_IDX(1, 2)]) + (a->m[MAT_IDX(2, 2)] * b->m[MAT_IDX(2, 2)]) + (a->m[MAT_IDX(2, 3)] * b->m[MAT_IDX(3, 2)]);
    temp.m[MAT_IDX(3, 2)] = (a->m[MAT_IDX(3, 0)] * b->m[MAT_IDX(0, 2)]) + (a->m[MAT_IDX(3, 1)] * b->m[MAT_IDX(1, 2)]) + (a->m[MAT_IDX(3, 2)] * b->m[MAT_IDX(2, 2)]) + (a->m[MAT_IDX(3, 3)] * b->m[MAT_IDX(3, 2)]);

    temp.m[MAT_IDX(0, 3)] = (a->m[MAT_IDX(0, 0)] * b->m[MAT_IDX(0, 3)]) + (a->m[MAT_IDX(0, 1)] * b->m[MAT_IDX(1, 3)]) + (a->m[MAT_IDX(0, 2)] * b->m[MAT_IDX(2, 3)]) + (a->m[MAT_IDX(0, 3)] * b->m[MAT_IDX(3, 3)]);
    temp.m[MAT_IDX(1, 3)] = (a->m[MAT_IDX(1, 0)] * b->m[MAT_IDX(0, 3)]) + (a->m[MAT_IDX(1, 1)] * b->m[MAT_IDX(1, 3)]) + (a->m[MAT_IDX(1, 2)] * b->m[MAT_IDX(2, 3)]) + (a->m[MAT_IDX(1, 3)] * b->m[MAT_IDX(3, 3)]);
    temp.m[MAT_IDX(2, 3)] = (a->m[MAT_IDX(2, 0)] * b->m[MAT_IDX(0, 3)]) + (a->m[MAT_IDX(2, 1)] * b->m[MAT_IDX(1, 3)]) + (a->m[MAT_IDX(2, 2)] * b->m[MAT_IDX(2, 3)]) + (a->m[MAT_IDX(2, 3)] * b->m[MAT_IDX(3, 3)]);
    temp.m[MAT_IDX(3, 3)] = (a->m[MAT_IDX(3, 0)] * b->m[MAT_IDX(0, 3)]) + (a->m[MAT_IDX(3, 1)] * b->m[MAT_IDX(1, 3)]) + (a->m[MAT_IDX(3, 2)] * b->m[MAT_IDX(2, 3)]) + (a->m[MAT_IDX(3, 3)] * b->m[MAT_IDX(3, 3)]);

    *dest = temp;
}

void mat4_add(const mat4_t *a, const mat4_t *b, mat4_t *dest)
{
    dest->m[MAT_IDX(0, 0)] = a->m[MAT_IDX(0, 0)] + b->m[MAT_IDX(0, 0)];
    dest->m[MAT_IDX(0, 1)] = a->m[MAT_IDX(0, 1)] + b->m[MAT_IDX(0, 1)];
    dest->m[MAT_IDX(0, 2)] = a->m[MAT_IDX(0, 2)] + b->m[MAT_IDX(0, 2)];
    dest->m[MAT_IDX(0, 3)] = a->m[MAT_IDX(0, 3)] + b->m[MAT_IDX(0, 3)];
    dest->m[MAT_IDX(1, 0)] = a->m[MAT_IDX(1, 0)] + b->m[MAT_IDX(1, 0)];
    dest->m[MAT_IDX(1, 1)] = a->m[MAT_IDX(1, 1)] + b->m[MAT_IDX(1, 1)];
    dest->m[MAT_IDX(1, 2)] = a->m[MAT_IDX(1, 2)] + b->m[MAT_IDX(1, 2)];
    dest->m[MAT_IDX(1, 3)] = a->m[MAT_IDX(1, 3)] + b->m[MAT_IDX(1, 3)];
    dest->m[MAT_IDX(2, 0)] = a->m[MAT_IDX(2, 0)] + b->m[MAT_IDX(2, 0)];
    dest->m[MAT_IDX(2, 1)] = a->m[MAT_IDX(2, 1)] + b->m[MAT_IDX(2, 1)];
    dest->m[MAT_IDX(2, 2)] = a->m[MAT_IDX(2, 2)] + b->m[MAT_IDX(2, 2)];
    dest->m[MAT_IDX(2, 3)] = a->m[MAT_IDX(2, 3)] + b->m[MAT_IDX(2, 3)];
    dest->m[MAT_IDX(3, 0)] = a->m[MAT_IDX(3, 0)] + b->m[MAT_IDX(3, 0)];
    dest->m[MAT_IDX(3, 1)] = a->m[MAT_IDX(3, 1)] + b->m[MAT_IDX(3, 1)];
    dest->m[MAT_IDX(3, 2)] = a->m[MAT_IDX(3, 2)] + b->m[MAT_IDX(3, 2)];
    dest->m[MAT_IDX(3, 3)] = a->m[MAT_IDX(3, 3)] + b->m[MAT_IDX(3, 3)];
}

void mat4_sub(const mat4_t *a, const mat4_t *b, mat4_t *dest)
{
    dest->m[MAT_IDX(0, 0)] = a->m[MAT_IDX(0, 0)] - b->m[MAT_IDX(0, 0)];
    dest->m[MAT_IDX(0, 1)] = a->m[MAT_IDX(0, 1)] - b->m[MAT_IDX(0, 1)];
    dest->m[MAT_IDX(0, 2)] = a->m[MAT_IDX(0, 2)] - b->m[MAT_IDX(0, 2)];
    dest->m[MAT_IDX(0, 3)] = a->m[MAT_IDX(0, 3)] - b->m[MAT_IDX(0, 3)];
    dest->m[MAT_IDX(1, 0)] = a->m[MAT_IDX(1, 0)] - b->m[MAT_IDX(1, 0)];
    dest->m[MAT_IDX(1, 1)] = a->m[MAT_IDX(1, 1)] - b->m[MAT_IDX(1, 1)];
    dest->m[MAT_IDX(1, 2)] = a->m[MAT_IDX(1, 2)] - b->m[MAT_IDX(1, 2)];
    dest->m[MAT_IDX(1, 3)] = a->m[MAT_IDX(1, 3)] - b->m[MAT_IDX(1, 3)];
    dest->m[MAT_IDX(2, 0)] = a->m[MAT_IDX(2, 0)] - b->m[MAT_IDX(2, 0)];
    dest->m[MAT_IDX(2, 1)] = a->m[MAT_IDX(2, 1)] - b->m[MAT_IDX(2, 1)];
    dest->m[MAT_IDX(2, 2)] = a->m[MAT_IDX(2, 2)] - b->m[MAT_IDX(2, 2)];
    dest->m[MAT_IDX(2, 3)] = a->m[MAT_IDX(2, 3)] - b->m[MAT_IDX(2, 3)];
    dest->m[MAT_IDX(3, 0)] = a->m[MAT_IDX(3, 0)] - b->m[MAT_IDX(3, 0)];
    dest->m[MAT_IDX(3, 1)] = a->m[MAT_IDX(3, 1)] - b->m[MAT_IDX(3, 1)];
    dest->m[MAT_IDX(3, 2)] = a->m[MAT_IDX(3, 2)] - b->m[MAT_IDX(3, 2)];
    dest->m[MAT_IDX(3, 3)] = a->m[MAT_IDX(3, 3)] - b->m[MAT_IDX(3, 3)];
}

// Nao e inplace
void mat4_transpose(const mat4_t *restrict a, mat4_t *restrict dest)
{
    dest->m[MAT_IDX(0, 0)] = a->m[MAT_IDX(0, 0)];
    dest->m[MAT_IDX(0, 1)] = a->m[MAT_IDX(1, 0)];
    dest->m[MAT_IDX(0, 2)] = a->m[MAT_IDX(2, 0)];
    dest->m[MAT_IDX(0, 3)] = a->m[MAT_IDX(3, 0)];
    dest->m[MAT_IDX(1, 0)] = a->m[MAT_IDX(0, 1)];
    dest->m[MAT_IDX(1, 1)] = a->m[MAT_IDX(1, 1)];
    dest->m[MAT_IDX(1, 2)] = a->m[MAT_IDX(2, 1)];
    dest->m[MAT_IDX(1, 3)] = a->m[MAT_IDX(3, 1)];
    dest->m[MAT_IDX(2, 0)] = a->m[MAT_IDX(0, 2)];
    dest->m[MAT_IDX(2, 1)] = a->m[MAT_IDX(1, 2)];
    dest->m[MAT_IDX(2, 2)] = a->m[MAT_IDX(2, 2)];
    dest->m[MAT_IDX(2, 3)] = a->m[MAT_IDX(3, 2)];
    dest->m[MAT_IDX(3, 0)] = a->m[MAT_IDX(0, 3)];
    dest->m[MAT_IDX(3, 1)] = a->m[MAT_IDX(1, 3)];
    dest->m[MAT_IDX(3, 2)] = a->m[MAT_IDX(2, 3)];
    dest->m[MAT_IDX(3, 3)] = a->m[MAT_IDX(3, 3)];
}

void mat4_scale(mat4_t *dest, const mat4_t *a, float sx, float sy, float sz)
{
    mat4_t mat = {0};

    mat.m[MAT_IDX(0, 0)] = sx;
    mat.m[MAT_IDX(1, 1)] = sy;
    mat.m[MAT_IDX(2, 2)] = sz;
    mat.m[MAT_IDX(3, 3)] = 1.0f;

    mat4_mul(a, &mat, dest);
}

void mat4_translate(const mat4_t *a, mat4_t *dest, float tx, float ty, float tz)
{
    mat4_t mat = {0};
    mat4_identity(&mat);

    mat.m[MAT_IDX(0, 3)] = tx;
    mat.m[MAT_IDX(1, 3)] = ty;
    mat.m[MAT_IDX(2, 3)] = tz;

    mat4_mul(a, &mat, dest);
}

void mat4_rotate(const mat4_t *a, mat4_t *dest, vec3_t axis, float angle_rad)
{
    vec3_normalize(&axis);

    float c = cosf(angle_rad);
    float s = sinf(angle_rad);
    float t = 1.0f - c;

    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    mat4_t mat = {0};

    // Formula do rodrigues
    mat.m[MAT_IDX(0, 0)] = t * x * x + c;
    mat.m[MAT_IDX(0, 1)] = t * x * y - s * z;
    mat.m[MAT_IDX(0, 2)] = t * x * z + s * y;
    mat.m[MAT_IDX(1, 0)] = t * x * y + s * z;
    mat.m[MAT_IDX(1, 1)] = t * y * y + c;
    mat.m[MAT_IDX(1, 2)] = t * y * z - s * x;
    mat.m[MAT_IDX(2, 0)] = t * x * z - s * y;
    mat.m[MAT_IDX(2, 1)] = t * y * z + s * x;
    mat.m[MAT_IDX(2, 2)] = t * z * z + c;

    mat.m[MAT_IDX(3, 3)] = 1.0f;

    mat4_mul(a, &mat, dest);
}

void mat4_perspective(mat4_t *dest, float fov_y_rad, float aspect, float near, float far)
{
    float t = tan(fov_y_rad / 2);
    float top = near * t;
    float right = top * aspect;

    float far_sub_near = 1 / (far - near);

    float A_x = near / right;
    float A_y = near / top;
    float A_z = -(far + near) * far_sub_near;
    float B_z = -(2 * far * near) * far_sub_near;

    mat4_t mat = {0};
    mat.m[MAT_IDX(0, 0)] = A_x;
    mat.m[MAT_IDX(1, 1)] = A_y;
    mat.m[MAT_IDX(2, 2)] = A_z;
    mat.m[MAT_IDX(2, 3)] = -1;
    mat.m[MAT_IDX(3, 2)] = B_z;

    *dest = mat;
}

void mat4_print(const mat4_t *mat)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%8.2f", mat->m[MAT_IDX(i, j)]);
        printf("\n");
    }
    printf("\n");
}
