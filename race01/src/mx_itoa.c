#include "../inc/header.h"

char *mx_itoa(long long num) {
	char *str = NULL;
	if (num == 0) {
		str = mx_strnew(1);
		str[0] = '0';
		return str;
	}
	int size = 0;
	long long num_copy = num;
	if (num_copy < 0) {
		size++;
		num_copy *= -1;
	}
	while (num_copy != 0) {
		num_copy = num_copy / 10;
		size++;
	}
	str = mx_strnew(size);
	if (num < 0) {
		str[0] = '-';
		num *= -1;
	}
	str[size--] = '\0';
	while ((num != 0 && size >= 0) && str[size] != '-') {
		str[size--] = (num % 10) + '0';
		num /= 10;
	}
	return str;
}

