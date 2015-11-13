SRC = $(wildcard ./src/*.c)
OBJ = $(patsubst ./src/%.c,./obj/%.o,$(SRC))

.PHONY: all staticlib dynamiclib clean

all: staticlib dynamiclib

$(OBJ): $(SRC)
	@mkdir -p ./obj
	gcc -std=c11 -Wall -Wconversion -Werror -Wextra -Wformat -c -o $@ $<

staticlib: $(OBJ)
	@mkdir -p ./lib
	ar crS ./lib/liblowgm.a $?
	ranlib ./lib/liblowgm.a

dynamiclib: $(OBJ)
	@mkdir -p ./lib
	gcc -shared -Wl,-soname,liblowgm.so -o ./lib/liblowgm.so

clean:
	rm -fr ./obj ./lib
