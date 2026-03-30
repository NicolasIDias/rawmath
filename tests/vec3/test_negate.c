#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    vec3_t v = vec3_create(1.0f, -2.0f, 3.0f);

    vec3_negate(&v);

    assert(v.x == -1.0f);
    assert(v.y == 2.0f);
    assert(v.z == -3.0f);

    printf("negate_test passed!\n");
    return 0;
}