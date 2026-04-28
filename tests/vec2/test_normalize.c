#include <assert.h>
#include <math.h>
#include <rawmath/vec2.h>
#include <stdio.h>

int main(void)
{
    vec2_t v1 = vec2_create(1.0f, 0.0f);
    vec2_normalize(&v1);
    assert(vec2_equals(v1, vec2_create(1.0f, 0.0f)));

    vec2_t v2 = vec2_create(0.0f, 5.0f);
    vec2_normalize(&v2);
    assert(vec2_equals(v2, vec2_create(0.0f, 1.0f)));

    vec2_t v3 = vec2_create(1.0f, 1.0f);
    vec2_normalize(&v3);
    float inv_sqrt2 = 1.0f / sqrtf(2.0f);
    assert(vec2_equals(v3, vec2_create(inv_sqrt2, inv_sqrt2)));

    vec2_t v4 = vec2_create(0.0f, 0.0f);
    vec2_normalize(&v4);
    assert(vec2_equals(v4, vec2_create(0.0f, 0.0f)));

    printf("normalize_test passed!\n");
    return 0;
}
