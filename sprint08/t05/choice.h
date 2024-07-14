#ifndef CHOICE_H
#define CHOICE_H

#define MX_RED_PILL 1
#define MX_BLUE_PILL 2

#define MX_SUCCESS_PHRASE "Follow me!"
#define MX_FAIL_PHRASE "Perhaps I was wrong about you, Neo."
#define MX_UNDEFINED_PHRASE "Are you sure about that?"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef char t_phrase;

t_phrase *choice(int pill);

char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);

#endif

