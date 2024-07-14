#pragma once

#define _XOPEN_SOURCE   600
#define _POSIX_C_SOURCE 200112L

#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <stddef.h>

#define MIN_SPEED 0
#define MAX_SPEED 50
#define DEFAULT_SPEED 25
#define DEFAULT_COLOR 2

struct sSettings{
	int speed;
	int color;
}	Settings;

typedef
struct sCharacter{
	char symbol;
	int color;
}	Character;

struct sScreen{
	int width;
	int height;
	Character ***dots;
}	Screen;

int mx_strcmp(const char *s1, const char *s2);
void mx_printerr(char *str);
int mx_strlen(char *s);

void mx_draw_run(void (*action)(void));
void mx_draw_intro();
void mx_draw_rain();
void mx_init();
void mx_init_colors();
void mx_on_key_press();
