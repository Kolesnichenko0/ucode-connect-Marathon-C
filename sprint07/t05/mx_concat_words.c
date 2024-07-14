#include <stdlib.h>
#include <stddef.h>

void mx_strdel(char **str);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strcat(char *s1, const char *s2);
char *mx_strjoin(char const *s1, char const *s2);

char *mx_concat_words(char **words) {
	if (words == NULL)
		return NULL;
	char *sen = mx_strdup(words[0]);
	for (int i = 1; words[i] != NULL; i++) {
		char *t = mx_strjoin(sen, " ");
		mx_strdel(&sen);
		sen = mx_strjoin(t, words[i]);
		mx_strdel(&t);
	}
	return sen;
}

