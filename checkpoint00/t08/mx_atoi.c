int mx_atoi(const char *str) {
	int check = 0;
	long n = 0;
	int minus = 1;
	int counter = 0;
	int counter2 = -1;
	for(int i = 0; check != 1 ; i++) {
		if(str[0] == '-' && minus == 1) {
			counter = i;
			minus = -1;
		}
		else if(str[i] >= 48 && str[i] <= 57 && n == 0) {
			n = (n * 10) + (str[i] - '0');
			counter2 = i;
		}
		else if(str[i] >= 48 && str[i] <= 57)
			n = (n * 10) + (str[i] - '0');
		else if (str[i] == '\0') 
			check = 1;
		else
			check = 1;
	}
	if(counter2 == -1)
		return 0;
	if(counter < counter2)
		n = n * minus;
	return (int)n;
}
