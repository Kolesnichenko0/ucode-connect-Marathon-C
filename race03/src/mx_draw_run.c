#include "header.h"

void mx_draw_run(void (*action)(void)){
	while(true){
		for(int i = 0; i < Screen.height; i++)
			for(int j = 0; j < Screen.width; j++)
				mvaddch(i, j, Screen.dots[i][j]->symbol | COLOR_PAIR(Screen.dots[i][j]->color));
		action();
		timeout(Settings.speed);
		mx_on_key_press();
		refresh();
		usleep(1000000/60);
	}
}
