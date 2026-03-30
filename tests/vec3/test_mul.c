#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    vec3_t a = vec3_create(2.0f, 3.0f, 4.0f);
    vec3_t b = vec3_create(5.0f, 6.0f, 7.0f);
    vec3_t res1 = vec3_mul(a, b);
    vec3_t exp1 = vec3_create(10.0f, 18.0f, 28.0f);
    assert(vec3_equals(res1, exp1) == 1);

    vec3_t c = vec3_create(1.0f, 0.0f, -5.0f);
    vec3_t d = vec3_create(0.0f, 10.0f, 2.0f);
    vec3_t res2 = vec3_mul(c, d);
    vec3_t exp2 = vec3_create(0.0f, 0.0f, -10.0f);
    assert(vec3_equals(res2, exp2) == 1);

    vec3_t ones = vec3_create(1.0f, 1.0f, 1.0f);
    vec3_t res3 = vec3_mul(a, ones);
    assert(vec3_equals(res3, a) == 1);

    vec3_t e = vec3_create(-2.0f, 3.0f, -4.0f);
    vec3_t f = vec3_create(2.0f, -3.0f, -4.0f);
    vec3_t res4 = vec3_mul(e, f);
    vec3_t exp4 = vec3_create(-4.0f, -9.0f, 16.0f);
    assert(vec3_equals(res4, exp4) == 1);

    printf("test_mul passed!\n");
    return 0;
}