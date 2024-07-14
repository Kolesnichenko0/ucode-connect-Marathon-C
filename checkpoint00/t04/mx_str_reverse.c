void mx_str_reverse(char *s) {
	int counter = 0;
	for(int i = 0; s[i] != '\0'; i++)
		counter++;
	for(int i = 0; i < counter / 2; i++ ) {
		char t = s[i];
		s[i] = s[counter - i - 1];
		s[counter - i - 1] = t;
	}
}
