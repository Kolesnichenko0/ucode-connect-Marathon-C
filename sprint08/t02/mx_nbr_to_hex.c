#include "nbr_to_hex.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	if ( (long long)nbr < 0 || nbr == 0) {
		char *result = mx_strnew(1);
		result[0] = '0';
		return result;
	}
	char *t = mx_strnew(50);
	int size = 0;
	for(int i = 0; nbr != 0; i++) {
		if(nbr % 16 < 10)
			t[i] = nbr % 16 + 48;
		else
			t[i] = nbr % 16 + 87;
		nbr /= 16;
		size++;
	}
	char *result = mx_strnew(size);
	for(int i = 0; i < size; i++)
		result[i] = t[size - 1 - i];
	return result;
}

