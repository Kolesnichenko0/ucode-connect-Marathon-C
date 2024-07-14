#include "header.h"

int main(int argc, char *argv[]) {
	int total_string = 0;
	int total_word = 0;
	int total_ch = 0;
	if (argc == 1) {	
		int string = 0;
		int word = 0;
		int ch = 0;
		char temp;
		char elem = ' ';
		int n_read;
		while((n_read = read(0, &temp, 1))) {
			if (n_read == -1) {
				mx_printerr(strerror(errno));
				mx_printerr("\n");
				exit(1);
			}
			if(mx_isspace(temp) && !mx_isspace(elem))
				word++;
			if(temp == '\n')
				string++;
			ch++;
			elem = temp;
		}
		mx_printn(string, word, ch, 2, argv[0]);
		exit(0);
	}
	for (int i = 1; i < argc; i++) {
		int fd = open(argv[i], O_RDONLY);
		if (fd == -1) {
			mx_printerr("mx_wc: ");
			mx_printerr(argv[i]);
			mx_printerr(": open: ");
			mx_printerr(strerror(errno));
			mx_printerr("\n");
			exit(1);
		}
		char temp;
		char elem = ' ';
		if (read(fd, &temp, 1) == -1 && errno == EISDIR) {
			mx_printerr("mx_wc: ");
			mx_printerr(argv[i]);
			mx_printerr(": read: ");
			mx_printerr(strerror(errno));
			mx_printerr("\n");
			exit(1);
		}
		if (close(fd) == -1) {
			mx_printerr(strerror(errno));
			exit(1);
		}
		fd = open(argv[i], O_RDONLY);
		if (fd == -1) {
			mx_printerr(strerror(errno));
			exit(1);
		}
		int string = 0;
		int word = 0;
		int ch = 0;
		int n_read;
		while ((n_read = read(fd, &temp, 1)) != 0) {
			if(n_read == -1) {
				mx_printerr(strerror(errno));
				exit(1);
			}
			if (mx_isspace(temp) && !mx_isspace(elem)) {
				word++;
				total_word++;
			}
			if (temp == '\n') {
				string++;
				total_string++;
			}
			ch++;
			total_ch++;
			elem = temp;
		}
		if (close(fd) == -1) {
			mx_printerr(strerror(errno));
			exit(1);
		}
		mx_printn(string, word, ch, 1, argv[i]);
	}
	if (argc == 2)
		exit(0);
	else
		mx_printn(total_string, total_word, total_ch, 0, argv[0]);
	exit(0);
}
