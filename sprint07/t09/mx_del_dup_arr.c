#include <stddef.h>
#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size);

int *mx_del_dup_arr(int *src, int src_size, int *dst_size) {
	if(src == NULL)
		return NULL;
	int arr[src_size];
	int new_size = 0;
	for(int i = 0; i < src_size; i++) {
		int check = 0;
		for(int j = 0; j < i; j++)
			if(src[i] == src[j])
				check = 1;
		if(check == 0) {
			arr[new_size] = src[i];
			new_size++;
		}
	}
	int t[new_size];
	for(int i = 0; i < new_size; i++)
		t[i] = arr[i];
	*dst_size = new_size;
	return mx_copy_int_arr(t, new_size);
}

