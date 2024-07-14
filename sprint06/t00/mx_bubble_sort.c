int mx_strcmp(const char *s1, const char *s2);

int mx_bubble_sort(char **arr, int size) {
	int check = 0;
	int counter = 0;
	while(check == 0) {
		check = 1;
		for(int i = 0; i < size - 1; i++)
			if(mx_strcmp(arr[i], arr[i + 1]) > 0) {
				check = 0;
				char *t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
				counter++;
			}
	}
	return counter;
}
