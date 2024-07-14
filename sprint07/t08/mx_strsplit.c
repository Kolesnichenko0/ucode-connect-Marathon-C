#include <stddef.h>
#include <stdlib.h>

int mx_count_words(const char *str, char delimiter);
char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char **str);

char **mx_strsplit(char const *s, char c) {
	if (s == NULL)
		return NULL;
	int count = mx_count_words(s, c);
	char **result =(char **)mx_strnew(count);
	int i = 0;
	while (s[i] == c)
		i++;
	for (int counter = 0; counter < count; counter++) {
		int size = 0;
		int start = i;
		while(s[i] != c && s[i] != '\0') {
			size++;
			i++;
		}
		result[counter] = mx_strnew(size);
		mx_strncpy(result[counter], &s[start], size);
		while(s[i] == c)
			i++;
	}
	result[count] = NULL;
	return result;
}

