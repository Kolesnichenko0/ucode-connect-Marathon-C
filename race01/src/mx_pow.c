#include "../inc/header.h"

long long mx_pow(long long n, unsigned int pow) {
	long long t = n;
	for(unsigned int i = 1 ; i < pow; i++) {
		n *= t;
	}
	if(pow == 0) {
		return 1;
	}
	return n;
}
