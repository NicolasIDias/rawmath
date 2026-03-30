#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    vec3_t v = vec3_create(2.0f, -3.0f, 4.0f);

    vec3_scale(2.5f, &v);

    assert(v.x == 5.0f);
    assert(v.y == -7.5f);
    assert(v.z == 10.0f);

    printf("scale_test passed!\n");
    return 0;
}