#include <unistd.h>

void mx_printstr(const char *s) {
	int i =0;
	for (; s[i] != '\0'; i++) {};
	
	write(1, s, i);
}
