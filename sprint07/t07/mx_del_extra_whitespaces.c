#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

void mx_strdel(char **str);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
bool mx_isspace(char c);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strtrim(const char *str);

char *mx_del_extra_whitespaces(const char *str) {
	char *t = mx_strtrim(str);
	if(str == NULL || t == NULL)
		return NULL;
	int counter = 0;
	for(int i = 0; i < mx_strlen(t) - 1; i++)
		if(mx_isspace(t[i]) && mx_isspace(t[i + 1]))
			counter++;
	char *result = mx_strnew(mx_strlen(t) - counter);
	int j = 0;
	for(int i = 0; i < mx_strlen(t); i++) {
		if(mx_isspace(t[i]) && !mx_isspace(t[i + 1])) {
			result[j] = ' ';
			j++;
		}
		else if(!mx_isspace(t[i])) {
			result[j] = t[i];
			j++;
		}
	}
	mx_strdel(&t);
	return result;
}

