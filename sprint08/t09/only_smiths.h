#ifndef ONLY_SMITHS_H
#define ONLY_SMITHS_H

#include <stdlib.h>
#include <stddef.h>
#include "agent.h"

typedef struct s_agent t_agent;

t_agent **mx_only_smiths(t_agent **agents, int strength);
t_agent *mx_create_agent(char *name, int power, int strength);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
int mx_strcmp(const char *s1, const char *s2);
void mx_exterminate_agents(t_agent ***agents);

#endif
