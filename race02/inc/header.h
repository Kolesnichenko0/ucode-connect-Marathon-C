#ifndef HEADER_H
#define HEADER_H

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct str {
    char sym;
    int label;
}              s_struct;

void mx_building_path(int x2, int y2, int height, int width, s_struct map[height][width], int dist);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_printerr(const char *s);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_strdel(char **str);
int mx_strlen(const char *s);
int mx_atoi(const char *str);

#endif
