#ifndef CREATE_NEW_AGENTS_H
#define CREATE_NEW_AGENTS_H

#include <stdlib.h>
#include <stddef.h>
#include "agent.h"

typedef struct s_agent t_agent;

t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count);
t_agent *mx_create_agent(char *name, int power, int strength);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);

#endif

