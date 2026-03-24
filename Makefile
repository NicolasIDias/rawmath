CC = gcc
CFLAGS = -Wall -Wextra -I./include

SRC_VEC = src/vec3.c

all: test

test_create: tests/test_create.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_create.c $(SRC_VEC) -o test_create

test_add: tests/test_add.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_add.c $(SRC_VEC) -o test_add

test_sub: tests/test_sub.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_sub.c $(SRC_VEC) -o test_sub

test_dot_product: tests/test_dot_product.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_dot_product.c $(SRC_VEC) -o test_dot_product

test_cross_product: tests/test_cross_product.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_cross_product.c $(SRC_VEC) -o test_cross_product

test_equals: tests/test_equals.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_equals.c $(SRC_VEC) -o test_equals

test_negate: tests/test_negate.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_negate.c $(SRC_VEC) -o test_negate

test_scale: tests/test_scale.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_scale.c $(SRC_VEC) -o test_scale

test_reflect: tests/test_reflect.c $(SRC_VEC)
	$(CC) $(CFLAGS) tests/test_reflect.c $(SRC_VEC) -o test_reflect


test: test_create test_add test_sub test_dot_product test_cross_product test_equals test_negate test_scale test_reflect
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
	@echo "---- Testes finalizados ----"

clean:
	rm -f test_create test_add test_sub test_dot_product test_cross_product test_equals test_negate test_scale test_reflect