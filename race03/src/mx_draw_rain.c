#include "header.h"

void mx_draw_rain(){
	for(int i = 0; i < Screen.width; i++){
		Character *ch = Screen.dots[0][i];
		if(ch->symbol == ' '){
			if(rand() % 50 == 0){
				ch->symbol = (rand() % 93 + 33);
				ch->color = 1;
			}
		}
		else{
			if(rand() % 10 == 0){
				ch->symbol = ' ';
				ch->color = 0;
			}
		}
	}
	
	for(int i = 0; i < Screen.width; i++)
		for(int j = 1; j < Screen.height; j++){
			Character *current = Screen.dots[j][i];
			Character *up = Screen.dots[j - 1][i];
			if(up->symbol == ' '){
				if(current->symbol != ' '){
					current->symbol = ' ';
					current->color = 0;
					if(j + 1 < Screen.height)
						j++;
					while(j + 1 < Screen.height && Screen.dots[j][i]->symbol != ' ')
						j++;
					j--;
				}
			}
			if(up->symbol != ' '){
				if(current->symbol == ' '){
					up->color = Settings.color;
					current->color = 1;
					current->symbol = (rand() % 93 + 33);
					if(j + 1 < Screen.height && Screen.dots[j][i]->symbol != ' ')
						j++;
				}
			}
		}
}
