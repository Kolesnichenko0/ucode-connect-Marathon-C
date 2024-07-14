#include <stdbool.h>

bool mx_is_prime(int num);
double mx_pow(double n, unsigned int pow);

bool mx_is_mersenne(int n) {
	if(!mx_is_prime(n))
		return 0;
	int num = 0;
	for(unsigned int i = 2; num <=n; i++) {
		num = mx_pow(2, i) - 1;
		if(n == num)
			return 1;
	}
	return 0;
}
