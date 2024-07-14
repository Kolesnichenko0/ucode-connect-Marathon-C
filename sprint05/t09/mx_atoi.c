#include <stdbool.h>
#include <stddef.h>
bool mx_isspace(char c);
bool mx_isdigit(int c);

int mx_atoi(const char *str) {
	int check = 0;
	long long n = 0;
	int minus = 1;
	int counter2 = -1;
	int counter3 = 0;
	int check2 = 1;
	for(int i = 0 ; check != 1; i++) {
		if(mx_isspace(str[i]) && (i - counter3) == 0)
			counter3++;
		else if((str[i] == '-' || str[i] == '+') && check2 != 0) {
			if(str[i] == '-')
				minus = -1;
			check2 = 0;
		}
		else if(mx_isdigit(str[i]) && n == 0) {
			n = (n * 10) + (str[i] - '0');
			counter2 = i;
			check2 = 0;
		}
		else if(mx_isdigit(str[i]))
			n = (n * 10) + (str[i] - '0');
		else if(str[i] == '\0')
			check = 1;
		else 
			return 0;
	}
	if(counter2 == -1)
		return 0;
	n = n * minus;
	return (int)n;
}
