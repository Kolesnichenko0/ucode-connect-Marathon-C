#include <stdbool.h>

void mx_sort(int *arr, int size, bool (*f)(int, int)) {
	if(size < 1 || !arr || !f)
		return;
	int check = 0;
	while (check == 0) {
		check = 1;
		for (int i = 0; i < size - 1; i++) {
			if (f(arr[i], arr[i + 1])) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				check = 0;
			}
		}
	}
	return;
}

