#include <stdbool.h>
void mx_printchar(char c);
bool mx_isspace(char c);
bool mx_isdigit(int c);
void mx_printint(int n);
int mx_atoi(const char *str);
int mx_strlen(const char *s);

int main(int argc, char* argv[]) {
	if(argc != 3)
		return 0;
	int m = mx_atoi(argv[1]);
	int n = mx_atoi(argv[2]);
	if (m > 9 || m < 0 || n > 9 || n < 0)
		return 0;
	if(m > n) {
		int t = m;
		m = n;
		n = t;
	}
	for(int i = m; i <= n; i++) {
		for(int j = m; j <= n; j++) {
			mx_printint(i * j);
			if(j < n)
				mx_printchar('\t');
		}
	mx_printchar('\n');
	}
	return 0;
}
