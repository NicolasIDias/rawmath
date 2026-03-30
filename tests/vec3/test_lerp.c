#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    vec3_t a = vec3_create(0.0f, 0.0f, 0.0f);
    vec3_t b = vec3_create(10.0f, 20.0f, 30.0f);

    vec3_t res0 = vec3_lerp(a, b, 0.0f);
    assert(vec3_equals(res0, a) == 1);

    vec3_t res1 = vec3_lerp(a, b, 1.0f);
    assert(vec3_equals(res1, b) == 1);

    vec3_t res_mid = vec3_lerp(a, b, 0.5f);
    vec3_t expected_mid = vec3_create(5.0f, 10.0f, 15.0f);
    assert(vec3_equals(res_mid, expected_mid) == 1);

    vec3_t res_extra = vec3_lerp(a, b, 1.5f);
    vec3_t expected_extra = vec3_create(15.0f, 30.0f, 45.0f);
    assert(vec3_equals(res_extra, expected_extra) == 1);

    vec3_t res_neg = vec3_lerp(a, b, -0.5f);
    vec3_t expected_neg = vec3_create(-5.0f, -10.0f, -15.0f);
    assert(vec3_equals(res_neg, expected_neg) == 1);

    printf("test_lerp passed!\n");
    return 0;
}