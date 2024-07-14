#include <unistd.h>

void mx_printerr(const char *s) {
	int size = 0;
	for (int i = 0; s[i] != '\0'; i++)
		size++;
	write(2, s, size);
}

