#include "create_new_agents.h"

char *mx_strcpy(char *dst, const char *src) {
	int i = 0;
	while (src[i]) {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return dst;
}
