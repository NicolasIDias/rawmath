CC = gcc
CFLAGS = -Wall -Wextra -I./include

SRC_VEC = src/vec3.c

LDFLAGS = -lm

all: test

test_create: tests/test_create.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_create.c $(SRC_VEC) -o test_create $(LDFLAGS)

test_add: tests/test_add.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_add.c $(SRC_VEC) -o test_add $(LDFLAGS)

test_sub: tests/test_sub.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_sub.c $(SRC_VEC) -o test_sub $(LDFLAGS)

test_dot_product: tests/test_dot_product.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_dot_product.c $(SRC_VEC) -o test_dot_product $(LDFLAGS)

test_cross_product: tests/test_cross_product.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_cross_product.c $(SRC_VEC) -o test_cross_product $(LDFLAGS)

test_equals: tests/test_equals.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_equals.c $(SRC_VEC) -o test_equals $(LDFLAGS)

test_negate: tests/test_negate.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_negate.c $(SRC_VEC) -o test_negate $(LDFLAGS)

test_scale: tests/test_scale.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_scale.c $(SRC_VEC) -o test_scale $(LDFLAGS)

test_reflect: tests/test_reflect.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_reflect.c $(SRC_VEC) -o test_reflect $(LDFLAGS)

test_triple_product: tests/test_triple_product.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_triple_product.c $(SRC_VEC) -o test_triple_product $(LDFLAGS)

test_magnitude: tests/test_magnitude.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_magnitude.c $(SRC_VEC) -o test_magnitude $(LDFLAGS)

test_normalize: tests/test_normalize.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_normalize.c $(SRC_VEC) -o test_normalize $(LDFLAGS)

test_lerp: tests/test_lerp.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_lerp.c $(SRC_VEC) -o test_lerp $(LDFLAGS)

test_clamp: tests/test_clamp.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_clamp.c $(SRC_VEC) -o test_clamp $(LDFLAGS)

test_mul: tests/test_mul.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_mul.c $(SRC_VEC) -o test_mul $(LDFLAGS)


test: test_create test_add test_sub test_dot_product test_cross_product test_equals test_negate test_scale test_reflect test_triple_product test_magnitude test_normalize test_lerp test_clamp test_mul
	@echo "---- Iniciando testes ----"
	./test_create
	./test_add
	./test_sub
	./test_dot_product
	./test_cross_product
	./test_equals
	./test_negate
	./test_scale
	./test_reflect
	./test_triple_product
	./test_magnitude
	./test_normalize
	./test_lerp
	./test_clamp
	./test_mul
	@echo "---- Testes finalizados ----"

clean:
	rm -f test_create test_add test_sub test_dot_product test_cross_product test_equals test_negate test_scale test_reflect test_triple_product test_magnitude test_normalize test_lerp test_clamp test_mul