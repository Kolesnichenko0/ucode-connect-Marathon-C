#include "../../../../sprint10/dkolesnych/t03/file_to_str.h"

char *mx_file_to_str(const char *filename) {
	if (filename == NULL)
		return NULL;
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
		return NULL;
	int size = 0;
	int n_read;
	char ch;
	while((n_read = read(fd, &ch, 1)) != 0) {
		if (n_read == -1)
			return NULL;
		size++;
	}
	if (size == 0)
		return NULL;
	if(close(fd) == -1)
		return NULL;
	fd = open(filename, O_RDONLY);
	if(fd == -1)
		return NULL;
	char *str = mx_strnew(size);
	int i = 0;
	while((n_read = read(fd, &ch, 1)) != 0) {
		if (n_read == -1)
			return NULL;
		str[i] = ch;
		i++;
	}
	if (close(fd) == -1)
		return NULL;
	str[i] = '\0';
	return str;
}

