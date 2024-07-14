#include "list.h"

int mx_count_words(const char *str, char delimiter) {
	int count = 0;
	int flag = 0;
	int counter = 0;
	for(int i = 0; str[i] != '\0';i++) {
		if((str[0] == delimiter && flag == 0) || (str[i] == delimiter && (i - counter) == 0)) {
			flag = 1;
			counter++;
		}
		else if(str[i] != delimiter) {
			if(str[i + 1] == delimiter || str[i + 1] == '\0')
				count++;
		}
	}
	return count;
}
