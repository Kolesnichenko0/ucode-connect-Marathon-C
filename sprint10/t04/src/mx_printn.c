#include "header.h"

void mx_printn(int string, int word, int ch, int check, char *argv) {
	mx_printchar('\t');
	mx_printint(string);
	mx_printchar('\t');
	mx_printint(word);
	mx_printchar('\t');
	mx_printint(ch);
	if (check == 0)
		mx_printstr(" total\n");
	else if (check == 1) {
		mx_printchar(' ');
		mx_printstr(argv);
		mx_printchar('\n');
	}
	else
		mx_printchar('\n');
}
