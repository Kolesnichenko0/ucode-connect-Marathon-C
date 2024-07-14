#include "header.h"

int main(int argc, char* argv[]) {
	if(argc != 3) {
		mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
		exit(1);
	}
	int fd_src = open(argv[1], O_RDONLY);
	if(fd_src == -1) {
		mx_printerr("mx_cp: ");
		mx_printerr(argv[1]);
		mx_printerr(": ");
		mx_printerr(strerror(errno));
		mx_printerr("\n");
		exit(1);
	}
	int fd_dst = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, S_IWUSR | S_IRUSR);
	if(fd_dst == -1)
		exit(1);
	char buf[1];
	int n_read;
	while((n_read = read(fd_src, buf, 1)) != 0) {
		if(n_read == -1) {
			mx_printerr(strerror(errno));
			mx_printerr("\n");
			exit(1);
		}
		write(fd_dst, buf, 1);
	}
	if(close(fd_src) == -1) {
		mx_printerr(strerror(errno));
		mx_printerr("\n");
		exit(1);
	}
	if(close(fd_dst) == -1) {
		mx_printerr(strerror(errno));
		mx_printerr("\n");
		exit(1);
	}
	exit(0);
}
