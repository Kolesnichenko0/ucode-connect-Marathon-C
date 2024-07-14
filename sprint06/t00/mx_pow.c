double mx_pow(double n, unsigned int pow) {
	double t = n;
	for(unsigned int i = 1 ; i < pow; i++) {
		n *= t;
	}
	if(pow == 0) {
		return 1;
	}
	return n;
}
