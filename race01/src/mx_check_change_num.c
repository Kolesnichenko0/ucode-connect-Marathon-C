#include "../inc/header.h"

char* mx_check_change_num(char *s) {
	s = mx_strtrim(s);
	for (int i = 0; i < mx_strlen(s); i++) {
		if (!mx_isdigit(s[i]) && s[i] != '?' && s[i] != '+' && s[i] != '-')
			return NULL;
	}
	return s;
}

