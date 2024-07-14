#include "list.h"

void mx_printstr(const char *s) {
	for(int i = 0; s[i] != '\0'; i++)
		write(1, &s[i], 1);
}

