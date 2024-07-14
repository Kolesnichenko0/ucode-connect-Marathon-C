#include "get_address.h"

char *mx_get_address(void *p) {
	char *temp_str = mx_nbr_to_hex((unsigned long)&p);
	char *result = mx_strnew(mx_strlen(temp_str) + 2);
	result[0] = '0';
	result[1] = 'x';
	mx_strcpy(&result[2], temp_str);
	free(temp_str);
	return result;
}

