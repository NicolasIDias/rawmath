#include <gaal/vec3.h>
#include <stdio.h>
#include <assert.h>

int main() {
    vec3_t a = vec3_create(1.0f, 2.0f, 3.0f);
    vec3_t b = vec3_create(1.0f, 2.0f, 3.0f);
    vec3_t c = vec3_create(1.0f, 9.0f, 3.0f);

    assert(vec3_equals(&a, &b) == 1); // Should be equal
    assert(vec3_equals(&a, &c) == 0); // Should not be equal
    
    printf("equals_test passed!\n");
    return 0;
}