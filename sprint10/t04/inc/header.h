#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>

void mx_printerr(const char *s);
int mx_strlen(const char *s);
void mx_printstr(const char *s);
void mx_printn(int string, int word, int ch, int check, char *argv);
void mx_printint(int n);
void mx_printchar(char c);
bool mx_isspace(char c);

#endif
