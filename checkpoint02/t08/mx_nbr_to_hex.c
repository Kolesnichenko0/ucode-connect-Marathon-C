#include <stdlib.h>

char *mx_nbr_to_hex(unsigned long nbr) {
	unsigned long num = nbr;
	if((long long)nbr < 0 || nbr == 0) {
		char *result = (char *)malloc(1);
		result[0] = '0';
		return result;
	}
	int size = 0;
	for(int i = 0; num != 0; i++) {
		num /= 16;
		size++;
	}
	char *result = (char *)malloc(size * sizeof(char));
	for(int i = size - 1; i >= 0; i--) {
		if(nbr % 16 < 10)
			result[i] = nbr % 16 + 48;
		else
			result[i] = nbr % 16 + 87;
		nbr /= 16;
	}
	return result;
}

