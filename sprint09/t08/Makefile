OBJS_FOLDER = obj
FUNC = src/*.c
OBJS = obj/*.o
LIB = minilibmx.a

all: CALC

CALC:
	mkdir -p $(OBJS_FOLDER)
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c $(FUNC)
	mv *.o $(OBJS_FOLDER)
	ar -src $(LIB) $(OBJS)
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o calc $(LIB)

uninstall: clean
	rm -f calc
	rm -f $(LIB)

clean:
	rm -rf $(OBJS_FOLDER)

reinstall: uninstall all

