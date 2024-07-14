#include "header.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		mx_printerr("usage: ./read_file [file_path]\n");
		return -1;
	}
	int fd = open(argv[1],O_RDONLY);
	if (fd == -1) {
		mx_printerr("error\n");
		return -1;
	}
	char buf[1];
	int n_read;
	while ((n_read = read(fd, buf, 1)) != 0) {
		if (n_read == -1) {
			mx_printerr("error\n");
			return -1;
		}
		write(1, buf, 1);
	}
	if (close(fd) == -1) {
		mx_printerr("error\n");
		return -1;
	}
	return 0;
}

