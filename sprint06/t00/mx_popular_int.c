int mx_popular_int(const int *arr, int size) {
	int counter = 0;
	int n;
	for(int i = 0; i < size; i++) {
		int counter2 = 0;
		for(int j = 0; j < size; j++ )
			if(arr[i] == arr[j])
				counter2++;
		if(counter2 > counter) {
			counter = counter2;
			n = arr[i];
		}
	}
	return n;
}
