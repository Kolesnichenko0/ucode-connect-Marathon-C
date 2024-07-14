#include <stdlib.h>
#include <stddef.h>

int *mx_copy_int_arr(const int *src, int size) {
	int *arr = (int *)malloc(sizeof(int) * size);
	if (src == NULL || size < 1 || arr == NULL)
		return NULL;
	for (int i = 0; i < size; i++)
		arr[i] = src[i];
	return arr;
}

