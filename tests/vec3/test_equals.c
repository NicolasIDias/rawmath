#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main(void)
{
    vec3_t a = vec3_create(1.0f, 2.0f, 3.0f);
    vec3_t b = vec3_create(1.0f, 2.0f, 3.0f);
    vec3_t c = vec3_create(1.0f, 9.0f, 3.0f);

    assert(vec3_equals(a, b));
    assert(!vec3_equals(a, c));
    printf("equals_test passed!\n");
    return 0;
}