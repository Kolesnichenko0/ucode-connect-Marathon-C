double mx_pow_rec(double n, unsigned int pow) {
	double num = n;
	if(pow == 0)
		return 1;
	return num *= mx_pow_rec(n, pow - 1);
}
