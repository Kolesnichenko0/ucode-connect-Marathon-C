#include "header.h"

int main(int argc, char* argv[]) {
	int n_read;
	if(argc == 1) {
		char elem;
		while((n_read = read(0, &elem, 1)) != 0) {
			if(n_read == -1) {
				mx_printerr(strerror(errno));
				mx_printerr("\n");
				exit(1);
			}
			write(1, &elem, 1);
		}
		exit(0);
	}
	for(int i = 1; i < argc; i++) {
		int fd = open(argv[i], O_RDONLY);
		char buf[1];
		if(fd == -1) {
			mx_printerr("mx_cat: ");
			mx_printerr(argv[i]);
			mx_printerr(": ");
			mx_printerr(strerror(errno));
			mx_printerr("\n");
			exit(1);
		}
		while((n_read = read(fd, buf, 1)) != 0) {
			if(n_read == -1) {
				mx_printerr(strerror(errno));
				mx_printerr("\n");
				exit(1);
			}
			write(1, buf, 1);
		}
		if(close(fd) == -1) {
			mx_printerr(strerror(errno));
			mx_printerr("\n");
			exit(1);
		}
	}
	exit(0);
}
