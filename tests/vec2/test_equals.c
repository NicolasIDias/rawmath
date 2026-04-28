#include <assert.h>
#include <math.h>
#include <rawmath/vec2.h>
#include <stdio.h>

int main(void)
{
    vec2_t a = vec2_create(1.0f, 2.0f);
    vec2_t b = vec2_create(1.0f, 2.0f);
    vec2_t c = vec2_create(2.0f, 3.0f);

    assert(vec2_equals(a, b));
    assert(!vec2_equals(a, c));

    printf("equals_test passed!\n");
    return 0;
}
