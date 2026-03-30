#include <rawmath/vec3.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    float min = 0.0f;
    float max = 100.0f;

    assert(vec3_clamp(-50.0f, min, max) == 0.0f);

    assert(vec3_clamp(150.0f, min, max) == 100.0f);

    assert(vec3_clamp(42.5f, min, max) == 42.5f);

    assert(vec3_clamp(0.0f, min, max) == 0.0f);

    assert(vec3_clamp(100.0f, min, max) == 100.0f);

    printf("test_clamp passed!\n");
    return 0;
}