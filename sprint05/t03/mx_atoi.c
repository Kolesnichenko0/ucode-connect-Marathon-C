#include <stdbool.h>
bool mx_isspace(char c);
bool mx_isdigit(int c);

int mx_atoi(const char *str) {
	long long n = 0;
	int minus = 1;
	int check = 0;
	int check2 = 0;
	for(int i = 0 ; check != 1; i++) {
		if((str[0] == '-' || str[0] == '+') && check2 == 0) {
			if(str[0] == '-')
				minus = -1;
			check2 = 1;
		}
		else if(mx_isdigit(str[i]))
			n = (n * 10) + (str[i] - '0');
		else if(str[i] == '\0')
			check = 1;
		else
			return 0;
	}
	if((unsigned long long int)n > 9223372036854775807)
                return 0;
	n = n * minus;
	return (int)n;
}
