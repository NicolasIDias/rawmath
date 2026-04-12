# rawmath

Lightweight C math lib for 3D graphics, providing `vec3` and `mat4` with
operations with column-major layout (OpenGL-compatible).

## Features

- `vec3` — add, sub, mul, dot, cross, normalize, lerp, reflect, magnitude...
- `mat4` — identity, multiply, transpose, scale, add, sub...
- Column-major memory layout (compatible with `glUniformMatrix4fv`)
- No external dependencies except for `<math.h>`


## Usage

```c
#include <rawmath/mat4.h>
#include <rawmath/vec3.h>

mat4_t model;
mat4_identity(&model);
mat4_scale(&model, &model, 2.0f, 2.0f, 2.0f);
```

## API

### vec3

| Function | Description |
|---|---|
| `vec3_create(x, y, z)` | Creates a new vec3 |
| `vec3_add(a, b)` | Returns a + b |
| `vec3_sub(a, b)` | Returns a - b |
| `vec3_dot_product(a, b)` | Dot product |
| `vec3_cross_product(a, b)` | Cross product |
| `vec3_normalize(v)` | Normalizes in-place |
| `vec3_magnitude(v)` | Returns the length |
| `vec3_lerp(a, b, t)` | Linear interpolation |
| `vec3_reflect(r, a, n)` | Reflection (n must be normalized) |

### mat4

| Function | Description |
|---|---|
| `mat4_identity(dest)` | Sets identity matrix |
| `mat4_mul(dest, a, b)` | Matrix multiplication |
| `mat4_scale(dest, a, sx, sy, sz)` | Scale transformation |
| `mat4_transpose(dest, a)` | Transpose |
| `mat4_add(dest, a, b)` | Element-wise addition |
| `mat4_sub(dest, a, b)` | Element-wise subtraction |
| `mat4_translate(dest, a, tx, ty, tz)` | Matrix translation |
| `mat4_rotate(dest, a, axis, angle_rad)` | Matrix rotation |
| `mat4_perspective(dest, fov_y_rad, aspect, near, far)` | Builds perspective projection |
| `mat4_look_at(dest, eye, center, up)` | Builds view matrix |

## Memory Layout

Matrices are stored in **column-major** order, matching OpenGL convention.

```c
// MAT_IDX macro:
#define MAT_IDX(row, col) ((col) * 4 + (row))
```

## Roadmap

- [ ] `vec2` support
- [ ] `vec4` support
- [ ] quaternion utilities
- [ ] `mat3` support
- [ ] update examples / docs
- [ ] publicar v1.0.0

## License

MIT