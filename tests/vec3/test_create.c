#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    vec3_t v = vec3_create(1.0f, 2.0f, 3.5f);

    assert(v.x == 1.0f);
    assert(v.y == 2.0f);
    assert(v.z == 3.5f);

    printf("create_test passed!\n");
    return 0;
}