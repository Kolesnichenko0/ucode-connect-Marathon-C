#include "header.h"

int mx_count_agents(char *src) {
	int count = 0;
	if (src) {
		while (mx_strstr(src, "agent {")) {
			src = mx_strstr(src, "agent {");
			src += 7;
			while (mx_isspace(src[0]))
				src++;
			if (!mx_strncmp(src, "name:", 5)) {
				src = mx_strchr(src, '\n');
				while (mx_isspace(src[0]))
					src++;
				if (!mx_strncmp(src, "power:", 6)) {
					src = mx_strchr(src, '\n');
					while (mx_isspace(src[0]))
						src++;
					if(!mx_strncmp(src , "strength:", 9)) {
						src = mx_strchr(src, '\n');
						while (mx_isspace(src[0]))
							src++;
						if(src[0] == '}')
							count++;
						else
							return -1;
					}
					else
						return -1;
				}
				else
					return -1;
			}
			else
				return -1;
		}
		src++;
		while (mx_isspace(src[0]))
			src++;
		if(src[0] != '\0')
			return -1;
		return count;
	}
	return -1;
}

