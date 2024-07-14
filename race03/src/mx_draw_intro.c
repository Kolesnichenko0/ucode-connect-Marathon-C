#include "header.h"

void mx_draw_intro(){
	char *intro[] = {
		"Wake up , Neo..",
		"The Matrix has you..",
		"Follow the white rabbit",
		"Knock, knock, Neo"
	};
	for(int i = 0; i < 4; i++){
		usleep(250000);
		for(int j = 0; j < mx_strlen(intro[i]); j++){
			mvaddch(4, 2 + j, intro[i][j] | COLOR_PAIR(2));
			refresh();
			if(getch() == 'q'){
				echo();
				curs_set(TRUE);
				endwin();
				exit(0);
			}
			usleep(250000);
		}
		clear();
	}
}
