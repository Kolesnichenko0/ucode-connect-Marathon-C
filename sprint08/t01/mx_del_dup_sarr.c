#include "duplicate.h"

t_intarr *mx_del_dup_sarr(t_intarr *src) {
	if (src->arr == NULL)
		return NULL;
	t_intarr temp;
	temp.size = src->size;
	temp.arr = (int *)malloc(sizeof(int) * temp.size);
	if (temp.arr == NULL)
		return NULL;
	int new_size = 0;
	for (int i = 0; i < src->size; i++) {
		int check = 0;
		for (int j = 0; j < i; j++)
			if(src->arr[i] == src->arr[j])
				check = 1;
		if (check == 0) {
			temp.arr[new_size] = src->arr[i];
			new_size++;
		}
	}
	t_intarr *result = (t_intarr *)malloc(sizeof(t_intarr*));
	result->size = new_size;
	result->arr = mx_copy_int_arr(temp.arr, result->size);
	free(temp.arr);
	return result;
}

