#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    vec3_t v1 = vec3_create(3.0f, 4.0f, 0.0f);
    assert(vec3_magnitude(v1) == 5.0f);

    vec3_t v2 = vec3_create(2.0f, 3.0f, 6.0f);
    assert(vec3_magnitude(v2) == 7.0f);

    vec3_t v3 = vec3_create(0.0f, 0.0f, 0.0f);
    assert(vec3_magnitude(v3) == 0.0f);

    vec3_t v4 = vec3_create(-2.0f, -3.0f, -6.0f);
    assert(vec3_magnitude(v4) == 7.0f);

    printf("magnitude_test passed!\n");
    return 0;
}