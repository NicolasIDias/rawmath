#include <rawmath/vec2.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main(void)
{
    vec2_t a = vec2_create(0.0f, 0.0f);
    vec2_t b = vec2_create(10.0f, 10.0f);

    vec2_t res0 = vec2_lerp(a, b, 0.0f);
    vec2_t res1 = vec2_lerp(a, b, 1.0f);
    vec2_t res_mid = vec2_lerp(a, b, 0.5f);
    vec2_t res_neg = vec2_lerp(a, b, -1.0f);
    vec2_t expected_mid = vec2_create(5.0f, 5.0f);
    vec2_t expected_neg = vec2_create(-10.0f, -10.0f);

    assert(vec2_equals(res0, a));
    assert(vec2_equals(res1, b));
    assert(vec2_equals(res_mid, expected_mid));
    assert(vec2_equals(res_neg, expected_neg));

    printf("lerp_test passed!\n");
    return 0;
}
