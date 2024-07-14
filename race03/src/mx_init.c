#include "header.h"

void mx_init(){
	initscr();
	noecho();
	curs_set(FALSE);
	cbreak();
	timeout(0);
	Settings.color = DEFAULT_COLOR;
	Settings.speed = DEFAULT_SPEED;  
    getmaxyx(stdscr, Screen.height, Screen.width);
	Screen.height++;
	Screen.width++;
	Screen.dots = malloc(sizeof(Character *) * Screen.height);
	for(int i = 0; i < Screen.height; i++){
		Screen.dots[i] = malloc(sizeof(Character) * Screen.width);
		for(int j = 0; j < Screen.width; j++){
			Screen.dots[i][j] = malloc(sizeof(Character));
			Screen.dots[i][j]->symbol = ' ';
			Screen.dots[i][j]->color = 0;
		}
	}
	mx_init_colors();
}
