#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    vec3_t a = vec3_create(5.0f, 5.0f, 5.0f);
    vec3_t b = vec3_create(2.0f, 7.0f, 0.0f);
    vec3_t r = vec3_sub(a, b);

    assert(r.x == 3.0f);
    assert(r.y == -2.0f);
    assert(r.z == 5.0f);

    printf("sub_test passed!\n");
    return 0;
}