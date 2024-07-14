#include "list.h"

char *mx_strcat(char *s1, const char *s2) {
	int side_s1 = mx_strlen(s1);
	for(int i = 0; i < mx_strlen(s2); i++)
		s1[side_s1++] = s2[i];
	s1[side_s1] = '\0';
	return s1;
}
