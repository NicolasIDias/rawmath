#include <stdio.h>
#include <rawmath/common.h>
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

void mat4_mul(mat4_t *dest, const mat4_t *a, const mat4_t *b)
{
    mat4_t temp;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            float sum = 0.0f;
            for (int k = 0; k < 4; k++)
                sum += a->m[MAT_IDX(i, k)] * b->m[MAT_IDX(k, j)];
            temp.m[MAT_IDX(i, j)] = sum;
        }
    *dest = temp;
}

void mat4_add(mat4_t *dest, const mat4_t *a, const mat4_t *b)
{
    for (int i = 0; i < 16; ++i)
        dest->m[i] = a->m[i] + b->m[i];
}

void mat4_sub(mat4_t *dest, const mat4_t *a, const mat4_t *b)
{
    for (int i = 0; i < 16; ++i)
        dest->m[i] = a->m[i] - b->m[i];
}

// Nao e inplace
void mat4_transpose(mat4_t *restrict dest, const mat4_t *restrict a)
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

    mat4_mul(dest, a, &mat);
}

void mat4_translate(mat4_t *dest, const mat4_t *a, float tx, float ty, float tz)
{
    if (dest != a)
    {
        *dest = *a;
    }

    dest->m[MAT_IDX(0, 3)] = a->m[MAT_IDX(0, 0)] * tx + a->m[MAT_IDX(0, 1)] * ty + a->m[MAT_IDX(0, 2)] * tz + a->m[MAT_IDX(0, 3)];
    dest->m[MAT_IDX(1, 3)] = a->m[MAT_IDX(1, 0)] * tx + a->m[MAT_IDX(1, 1)] * ty + a->m[MAT_IDX(1, 2)] * tz + a->m[MAT_IDX(1, 3)];
    dest->m[MAT_IDX(2, 3)] = a->m[MAT_IDX(2, 0)] * tx + a->m[MAT_IDX(2, 1)] * ty + a->m[MAT_IDX(2, 2)] * tz + a->m[MAT_IDX(2, 3)];
    dest->m[MAT_IDX(3, 3)] = a->m[MAT_IDX(3, 0)] * tx + a->m[MAT_IDX(3, 1)] * ty + a->m[MAT_IDX(3, 2)] * tz + a->m[MAT_IDX(3, 3)];
}

void mat4_rotate(mat4_t *dest, const mat4_t *a, vec3_t axis, float angle_rad)
{
    vec3_normalize(&axis);

    float c = cosf(angle_rad);
    float s = sinf(angle_rad);
    float t = 1.0f - c;

    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    mat4_t mat;

    mat4_identity(&mat);
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

    mat4_mul(dest, a, &mat);
}

void mat4_perspective(mat4_t *dest, float fov_y_rad, float aspect, float near, float far)
{
    if (fov_y_rad <= 0.0f || fov_y_rad >= RM_PI || aspect <= 0.0f || near <= 0.0f || far <= near)
    {
        *dest = (mat4_t){0};
        return;
    }

    float t = tanf(fov_y_rad / 2);
    float top = near * t;
    float right = top * aspect;

    float far_sub_near = 1.0f / (far - near);

    float A_x = near / right;
    float A_y = near / top;
    float A_z = -(far + near) * far_sub_near;
    float B_z = -(2 * far * near) * far_sub_near;

    mat4_t mat = {0};
    mat.m[MAT_IDX(0, 0)] = A_x;
    mat.m[MAT_IDX(1, 1)] = A_y;
    mat.m[MAT_IDX(2, 2)] = A_z;
    mat.m[MAT_IDX(2, 3)] = B_z;
    mat.m[MAT_IDX(3, 2)] = -1.0f;

    *dest = mat;
}

void mat4_look_at(mat4_t *dest, vec3_t eye, vec3_t center, vec3_t up)
{
    vec3_t F = vec3_sub(center, eye);
    if (vec3_magnitude_sq(F) <= (VEC3_EPSILON * VEC3_EPSILON))
    {
        *dest = (mat4_t){0};
        return;
    }

    vec3_normalize(&F);

    vec3_t R = vec3_cross_product(F, up);
    if (vec3_magnitude_sq(R) <= (VEC3_EPSILON * VEC3_EPSILON))
    {
        *dest = (mat4_t){0};
        return;
    }

    vec3_normalize(&R);
    vec3_t U = vec3_cross_product(R, F);

    dest->m[MAT_IDX(0, 0)] = R.x;
    dest->m[MAT_IDX(0, 1)] = R.y;
    dest->m[MAT_IDX(0, 2)] = R.z;
    dest->m[MAT_IDX(0, 3)] = -vec3_dot_product(R, eye);
    dest->m[MAT_IDX(1, 0)] = U.x;
    dest->m[MAT_IDX(1, 1)] = U.y;
    dest->m[MAT_IDX(1, 2)] = U.z;
    dest->m[MAT_IDX(1, 3)] = -vec3_dot_product(U, eye);
    dest->m[MAT_IDX(2, 0)] = -F.x;
    dest->m[MAT_IDX(2, 1)] = -F.y;
    dest->m[MAT_IDX(2, 2)] = -F.z;
    dest->m[MAT_IDX(2, 3)] = vec3_dot_product(F, eye);
    dest->m[MAT_IDX(3, 0)] = 0;
    dest->m[MAT_IDX(3, 1)] = 0;
    dest->m[MAT_IDX(3, 2)] = 0;
    dest->m[MAT_IDX(3, 3)] = 1.0f;
}

void mat4_print(const mat4_t *mat)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%8.2f", (double)mat->m[MAT_IDX(i, j)]);
        printf("\n");
    }
    printf("\n");
}