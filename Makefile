CC      := gcc
CFLAGS  := -Wall -Wextra -I./include
LDFLAGS := -lm

SRC_DIR   := src
TEST_DIR  := tests

SRC_VEC   := $(SRC_DIR)/vec3.c
SRC_MAT   := $(SRC_DIR)/mat4.c
SRC_OBJS  := $(SRC_DIR)/vec3.o $(SRC_DIR)/mat4.o

TEST_SRCS := $(wildcard $(TEST_DIR)/vec3/test_*.c) $(wildcard $(TEST_DIR)/mat4/test_*.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)
TESTS     := $(TEST_SRCS:.c=)

.PHONY: all test clean

all: test

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(SRC_OBJS)
	@echo "---- Iniciando testes ----"
	@for src in $(TEST_SRCS); do \
		obj=$${src%.c}.o; \
		exe=$${src%.c}; \
		$(CC) $(CFLAGS) -c "$$src" -o "$$obj"; \
		$(CC) $(CFLAGS) "$$obj" $(SRC_OBJS) -o "$$exe" $(LDFLAGS); \
		echo "---- Executando $$exe ----"; \
		"$$exe" || exit $$?; \
	done
	@echo "---- Testes finalizados ----"

clean:
	rm -f $(TESTS) $(TEST_OBJS) $(SRC_OBJS)
