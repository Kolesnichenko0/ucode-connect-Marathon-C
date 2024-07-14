
all: MINILIBMX

MINILIBMX:
	mkdir -p obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c src/mx_atoi.c -o obj/mx_atoi.o
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c src/mx_isdigit.c -o obj/mx_isdigit.o
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c src/mx_isspace.c -o obj/mx_isspace.o
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c src/mx_printchar.c -o obj/mx_printchar.o
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c src/mx_printint.c -o obj/mx_printint.o
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c src/mx_printstr.c -o obj/mx_printstr.o
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c src/mx_strcmp.c -o obj/mx_strcmp.o
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c src/mx_strcpy.c -o obj/mx_strcpy.o
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c src/mx_strlen.c -o obj/mx_strlen.o
	ar -src minilibmx.a obj/mx_atoi.o obj/mx_isdigit.o obj/mx_isspace.o \
	obj/mx_printchar.o obj/mx_printint.o obj/mx_printstr.o obj/mx_strcmp.o \
	obj/mx_strcpy.o obj/mx_strlen.o

uninstall: clean
	rm -f minilibmx.a

clean:
	rm -rf obj

reinstall: uninstall all

