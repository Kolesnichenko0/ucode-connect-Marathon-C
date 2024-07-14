#include "header.h"

void mx_on_key_press(){
	switch(getch()){
		case '-':
			Settings.speed += 5;
			if(Settings.speed > MAX_SPEED)
				Settings.speed = MAX_SPEED;
		break;
		case '+':
			Settings.speed -= 5;
			if(Settings.speed < MIN_SPEED)
				Settings.speed = MIN_SPEED;
		break;
		case '<':
			Settings.color--;
			if(Settings.color == 2)
				Settings.color = 7;
		break;
		case '>':
			Settings.color++;
			if(Settings.color == 8)
				Settings.color = 2;
		break;
		case 'q':
			echo();
			curs_set(TRUE);
			endwin();
			exit(0);
		break;
	}
}
