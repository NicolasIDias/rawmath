#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    vec3_t a = vec3_create(1.0f, 2.0f, 3.0f);
    vec3_t b = vec3_create(4.0f, -1.0f, 2.0f);
    vec3_t r = vec3_add(a, b);

    assert(r.x == 5.0f);
    assert(r.y == 1.0f);
    assert(r.z == 5.0f);

    printf("add_test passed!\n");
    return 0;
}