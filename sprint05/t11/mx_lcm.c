int mx_gcd(int a, int b);

int mx_lcm(int a , int b) {
	if(a < 0)
		a *= -1;
	if(b < 0)
		b *= -1;
	if ((unsigned int)(a * b) / mx_gcd(a, b) > 2147483647)
		return 0;
	return (a * b) / mx_gcd(a, b);
}
