#include "../inc/header.h"

void mx_error(char *e, char *argv) {
	mx_printerr(e);
	mx_printerr(argv);
	mx_printerr("\n");
	exit(-1);
}

