int mx_strcmp(const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
	int low = 0;
	int high = size - 1;
	int mid = (low + high) / 2;
	while(low <= high) {
		*count = *count + 1;
		if(mx_strcmp(arr[mid], s) > 0) {
			high = mid - 1;
			mid = (low + high) / 2;
		}
		else if(mx_strcmp(arr[mid], s) < 0) {
			low = mid + 1;
			mid = (high + low) / 2;
		}
		else {
			return mid;
		}
	}
	*count = 0;
	return -1;
}
