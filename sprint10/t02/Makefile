SRC = src/*.c
OBJS = obj/*.o
INC = inc
LIB = minilibmx.a
NAME = mx_cat
OBJS_FOLDER = obj
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

.PHONY: all clean uninstall reinstall

all: MX_CAT

MX_CAT: $(INC) $(SRC)
	@mkdir -p $(OBJS_FOLDER)
	@$(CC) $(CFLAGS) -I $(INC) -c $(SRC)
	@mv *.o $(OBJS_FOLDER)
	@ar -src $(LIB) $(OBJS)
	@$(CC) $(CFALGS) -o $(NAME) $(LIB)
	@rm -f $(LIB)

uninstall: clean
	@rm -f $(NAME)

clean:
	@rm -rf $(OBJS_FOLDER)

reinstall: uninstall all
