CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -pedantic -std=c99 -I./include \
           -Wshadow -Wformat=2 -Wconversion -Wstrict-prototypes  \
           -Wmissing-prototypes -Wnull-dereference                \
           -Wdouble-promotion -Wundef -Wwrite-strings             \
           -Wfloat-equal -Wcast-qual -Wpointer-arith              \
           -fstack-protector-strong -fno-common -ffast-math
LDFLAGS := -lm
VALGRIND := valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=1

SRC_DIR   := src
TEST_DIR  := tests

SRC_VEC3   := $(SRC_DIR)/vec3.c
SRC_MAT4   := $(SRC_DIR)/mat4.c
SRC_VEC2   := $(SRC_DIR)/vec2.c

SRC_OBJS  := $(SRC_DIR)/vec2.o $(SRC_DIR)/vec3.o $(SRC_DIR)/mat4.o

TEST_SRCS := $(wildcard $(TEST_DIR)/vec2/test_*.c) $(wildcard $(TEST_DIR)/vec3/test_*.c) $(wildcard $(TEST_DIR)/mat4/test_*.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)
TESTS     := $(TEST_SRCS:.c=)

.PHONY: all test valgrind clean

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

valgrind: test
	@echo "---- Iniciando Valgrind ----"
	@for exe in $(TESTS); do \
		echo "---- VALGRIND $$exe ----"; \
		$(VALGRIND) "$$exe"; \
	done

format:
	@echo "---- Formatting code in microsoft style----"
	@find include -name "*.h" -exec clang-format -i -style=Microsoft {} +
	@find src -name "*.c" -exec clang-format -i -style=Microsoft {} +
	@find tests -name "*.c" -exec clang-format -i -style=Microsoft {} +
	@echo "---- Formatting completed ----"

clean:
	rm -f $(TESTS) $(TEST_OBJS) $(SRC_OBJS)

compile:
	$(CC) $(CFLAGS) -c src/vec2.c -o src/vec2.o
	$(CC) $(CFLAGS) -c src/mat4.c -o src/mat4.o
	$(CC) $(CFLAGS) -c src/vec3.c -o src/vec3.o
