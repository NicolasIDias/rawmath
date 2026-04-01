#pragma once
#define MAT_IDX(row, col) ((col) * 4 + (row))
#include <rawmath/vec3.h>

typedef struct mat4
{

    float m[16];

} mat4_t;

void mat4_identity(mat4_t *dest);
void mat4_mul(mat4_t *dest, const mat4_t *a, const mat4_t *b);
void mat4_add(mat4_t *dest, const mat4_t *a, const mat4_t *b);
void mat4_sub(mat4_t *dest, const mat4_t *a, const mat4_t *b);

void mat4_transpose(const mat4_t *restrict a, mat4_t *restrict dest);
void mat4_scale(mat4_t *dest, const mat4_t *a, float sx, float sy, float sz);
void mat4_translate(mat4_t *dest, const mat4_t *a, float tx, float ty, float tz);
void mat4_rotate(mat4_t *dest, const mat4_t *a, vec3_t axis, float angle_rad);
void mat4_perspective(mat4_t *dest, float fov_y_rad, float aspect, float near, float far);

void mat4_print(const mat4_t *mat);
