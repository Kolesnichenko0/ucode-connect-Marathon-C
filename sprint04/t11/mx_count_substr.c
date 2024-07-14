char *mx_strchr(const char *s, int c);
int mx_strlen(const char *s);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char *sub) {
	int count = 0;
	int side = mx_strlen(str);
	for(int i = 0; i < side; i++) {
		str = mx_strstr(str, sub);
		if(str != 0) {
			str += mx_strlen(sub);
			count++;
		}
		else
			break;
	}
	return count;
}
