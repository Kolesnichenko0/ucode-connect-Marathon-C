#include "header.h"

char *mx_strstr(const char *s1, const char *s2) {
	if(mx_strlen(s1) < mx_strlen(s2))
		return 0;
	for(int i = 0; i < mx_strlen(s1); i++) {
		if(mx_strncmp(&s1[i], s2, mx_strlen(s2)) == 0) {
			return mx_strchr(&s1[i], s2[0]);
		}
	}
	return 0;
}
