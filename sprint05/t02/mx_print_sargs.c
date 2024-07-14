int mx_strcmp(const char *s1, const char *s2);
void mx_printchar(char c);
void mx_printstr(const char *s);
int mx_strlen(const char *s);

int main(int argc, char* argv[]) {
	int check = 1;
	while(check == 1) {
		check = 0;
		for(int i = 1; i < argc - 1; i++) {
			if(mx_strcmp(argv[i], argv[i + 1]) > 0) {
				check = 1;
				char* t = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = t;
			}
		}
	}
	for(int i = 1; i < argc; i++) {
		mx_printstr(argv[i]);
		mx_printchar('\n');
	}
	return 0;
}
