#include "../inc/header.h"

char *mx_strtrim(const char *str) {
	if(str == NULL)
		return NULL;
	char *t = mx_strnew(mx_strlen(str));
	mx_strncpy(t, str, mx_strlen(str));
	int a = 0;
	int b = 0;
	for(int i = 0; mx_isspace(str[i]) && str[i] != '\0'; i++)
		a++;
	if(a != mx_strlen(str))
		for(int i = mx_strlen(str) - 1; mx_isspace(str[i]) ; i--)
			b++;
	int size_result = mx_strlen(str) - a - b;
	char *result = mx_strnew(size_result);
	for(int i = 0; i < size_result; i++) {
		result[i] = t[a];
		a++;
	}
	mx_strdel(&t);
	return result;
}

