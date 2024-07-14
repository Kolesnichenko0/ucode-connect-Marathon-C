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

typedef struct s_agent
{
	char *name;
	int power;
	int strength;
}		t_agent;

void mx_sort_agents(t_agent ***agent_kit, char *flag, int count);
char *mx_strcpy(char *dst, const char *src);
char *mx_strdup(const char *str);
t_agent *mx_create_agent(char *name, int power, int strength);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
char *mx_strncpy(char *dst, const char *src, int len);
t_agent **mx_parse_agents(char *src, int count);
void mx_printerr(const char *s);
int mx_strlen(const char *s);
void mx_printstr(const char *s);
void mx_printint(int n);
void mx_printchar(char c);
bool mx_isspace(char c);
char *mx_file_to_str(const char *filename);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strnew(const int size);
int mx_count_agents(char *src);
char *mx_strchr(const char *s, int c);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strstr(const char *s1, const char *s2);

#endif
