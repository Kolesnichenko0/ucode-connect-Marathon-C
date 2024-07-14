#include <stdbool.h>
void mx_printchar(char c);
bool mx_isspace(char c);
bool mx_isdigit(int c);
void mx_printint(int n);
int mx_atoi(const char *str);

int main(int argc, char* argv[]) {
	int sum = 0;
	for(int i = 1; i < argc; i++)
		sum += mx_atoi(argv[i]);
	mx_printint(sum);
	mx_printchar('\n');
	return 0;
}
