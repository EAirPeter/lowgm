SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))

.PHONY: all lib clean

all: lib

$(OBJ): $(SRC)
	@mkdir -p ./obj
	gcc -std=c11 -Wall -Wconversion -Werror -Wextra -Wformat -c -o $@ $(patsubst obj/%.o,src/%.c,$@)

lib: $(OBJ)
	@mkdir -p ./lib
	ar -rcs ./lib/liblowgm.a $?

clean:
	rm -fr ./obj ./lib

