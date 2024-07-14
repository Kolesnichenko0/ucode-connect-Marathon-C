void mx_printchar(char c);
void mx_printstr(const char *s);
char *mx_strchr(const char *s, int c);
int mx_strlen(const char *s);

int main(int argc, char* argv[]) {
	if(argc > 0) {
		char *t = argv[0];
		while(mx_strchr(t, '/')) {
			mx_strchr(t, '/');
			t++;
		}
		mx_printstr(t);
		mx_printchar('\n');
	}
	return 0;
}
