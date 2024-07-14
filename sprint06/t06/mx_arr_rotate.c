void mx_arr_rotate(int *arr, int size, int shift) {
	int count = shift % size;
	int t[size];
	int k = 0;
	if(count > 0) {
		for(int i = size - count; i < size; i++) {
			t[k] = arr[i];
			k++;
		}
		for(int i = 0; i < size - count; i++ ) {
			t[k] = arr[i];
			k++;
		}
		for(int i = 0; i < size; i++)
			arr[i] = t[i];
	}
	else if(count < 0) {
		count *= -1;
		for(int i = count; i < size; i++) {
			t[k] = arr[i];
			k++;
		}
		for(int i = 0; i < count; i++) {
			t[k] = arr[i];
			k++;
		}
		for(int i = 0; i < size; i++)
			arr[i] = t[i];
	}
}
