#include <stdlib.h>
#include <stddef.h>

int *mx_copy_int_arr(const int *src, int size) {
	if (src == NULL || size < 1)
		return NULL;
	int *arr = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		arr[i] = src[i];
	return arr;
}

