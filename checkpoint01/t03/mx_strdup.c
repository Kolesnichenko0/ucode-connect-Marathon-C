#include <stdlib.h>
#include <stddef.h>

char *mx_strdup(const char *str) {
	if (str == NULL)
		return NULL;
	int size = 0;
	for (int i = 0; str[i] != '\0'; i++)
		size++;
	char *temp = (char*)malloc((size + 1) * sizeof(char));
	for (int i = 0; i < size; i++)
		temp[i] = str[i];
	temp[size] = '\0';
	return temp;
}

