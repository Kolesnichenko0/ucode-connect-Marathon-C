#include "hex_to_nbr.h"

unsigned long mx_hex_to_nbr(const char *hex) {
	if(hex == NULL)
		return 0;
	unsigned long long temp = 0;
	long long base = 1;
	int size = 0;
	for(int i = 0; hex[i] != '\0'; i++)
		size++;
	for(int i = size - 1; i >= 0 ; i--) {
		if(!mx_isalpha(hex[i]) && !mx_isdigit(hex[i]))
			return 0;
		if(mx_isdigit(hex[i]))
			temp += (hex[i] - 48) * base;
		else if(mx_islower(hex[i]))
			temp += (hex[i] - 87) * base;
		else if(mx_isupper(hex[i]))
			temp += (hex[i] - 55) * base;
		base *= 16;
	}
	return (unsigned long)temp;
}

