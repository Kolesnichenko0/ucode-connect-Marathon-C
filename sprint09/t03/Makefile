OBJS_FOLDER = obj
FUNC = src/*.c
OBJS = obj/*.o
RESULT = minilibmx.a

all: MINILIBMX

MINILIBMX:
	mkdir -p $(OBJS_FOLDER)
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c $(FUNC)
	mv *.o $(OBJS_FOLDER)
	ar -src $(RESULT) $(OBJS)

uninstall: clean
	rm -f $(RESULT)

clean:
	rm -rf $(OBJS_FOLDER)

reinstall: uninstall all

