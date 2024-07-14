int mx_factorial_rec(int n) {
	if(n < 0 || n > 12)
		return 0;
	if(n == 0)
		return 1;
	int mult = n;
	return mult *= mx_factorial_rec(n - 1);
}
