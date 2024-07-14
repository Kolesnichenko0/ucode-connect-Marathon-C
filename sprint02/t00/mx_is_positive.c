#include <unistd.h>
#include <stdio.h>

void mx_printstr(const char *s);

void mx_is_positive(int i) {
	if (i > 0)
		mx_printstr("positive");
	else if (i < 0)
		mx_printstr("negative");
	else
		mx_printstr("zero");
	write(1, "\n", 1);
}
