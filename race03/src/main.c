#include "header.h"

int main(int argc, char *argv[]){
	if(argc == 2){
		if(mx_strcmp(argv[1], "-s") == 0){
			mx_init();
			mx_draw_run(mx_draw_rain);
		}
		else
			mx_printerr("usage:2 ./matrix_rain [-s]\n");
	}
	else if(argc == 1 || argc == 0){
		mx_init();
		mx_draw_intro();
		mx_draw_run(mx_draw_rain);
	}
	else
		mx_printerr("usage:1 ./matrix_rain [-s]\n");
	return 0;
}
