#include <unistd.h>

void mx_printchar(char c);

void mx_str_separate(const char *str, char delim) {
	for(int i = 0; str[i] != '\0'; i++) {
		if(str[i] == delim) {
			while(str[i] == str[i + 1]) {
				i++;
			}
			write(1, "\n", 1);
		}
		else {
			mx_printchar(str[i]);
		}
	}
	write(1, "\n", 1);
}
