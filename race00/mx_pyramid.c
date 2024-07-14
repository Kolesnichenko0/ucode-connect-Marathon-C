#include <unistd.h>
void mx_printchar(char c);

void mx_pyramid(int n) {
	if(n <= 1)
		return;
	if(n % 2 == 1) {
		write(1, "\n", 1);
		return;
	}
	for(int i = 0; i < n / 2; i++) {
		for(int j = i; j < n - 1; j++)
			mx_printchar(' ');
		mx_printchar('/');
		for(int j = 1; j < 2 * i; j++)
			mx_printchar(' ');
		mx_printchar('\\');
		for(int j = 0; j < i; j++)
			mx_printchar(' ');
		if(i >= 1)
			mx_printchar('\\');
		mx_printchar('\n');
	}
	for(int i = n / 2; i < n - 1; i++) {
		for(int j = i; j < n - 1; j++)
			mx_printchar(' ');
		mx_printchar('/');
		for(int j = 1; j < 2 * i; j++)
			mx_printchar(' ');
		mx_printchar('\\');
		for(int j = i ; j < n - 1; j++)
			mx_printchar(' ');
		mx_printchar('|');
		mx_printchar('\n');
	}
	mx_printchar('/');
	for(int i = 0; i < 2 * n - 3; i++)
		mx_printchar('_');
	mx_printchar('\\');
	mx_printchar('|');
	mx_printchar('\n');
}
