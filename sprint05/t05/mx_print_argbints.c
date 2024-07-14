#include <stdbool.h>
void mx_printchar(char c);
bool mx_isspace(char c);
bool mx_isdigit(int c);
void mx_printint(int n);
int mx_atoi(const char *str);

int main(int argc, char* argv[]) {
	for(int i = 1; i < argc; i++) {
		int n = mx_atoi(argv[i]);
		int b, t;
		for (b = 31; b >= 0; b--) {
			t = n >> b;
			if(t & 1)
				mx_printint(1);
			else
				mx_printint(0);
		}
		mx_printchar('\n');
	}
	return 0;
}
		
