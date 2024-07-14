#include <stdbool.h>

double mx_pow(double n, unsigned int pow) ;

bool mx_is_narcissistic(int num) {
	if(num < 0)
		return 0;
	unsigned int counter = 0;
	for(int i = num; i != 0; i = (i - (i % 10)) / 10) {
		counter++;
	}
	int t = num;
	double sum = 0;
	for(unsigned int i = 0; i < counter; i++) {
		sum += mx_pow(t % 10, counter);
		t = (t - (t % 10)) / 10;
	}
	return sum == num;
}
