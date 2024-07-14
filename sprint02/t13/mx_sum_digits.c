int mx_sum_digits(int num) {
	if(num < 0)
		num *= -1;
	int sum = 0;
	while(num != 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
