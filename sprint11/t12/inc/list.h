#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_list
{
	void *data;
	struct s_list *next;
}		t_list;

typedef struct s_song
{
    char *artist;
    char *name;
}              t_song;

void mx_write_to_file(t_list *list, char *filename);
int mx_tolower(int c);
bool mx_compare_name(void *a, void *b);
bool mx_compare_artist(void *a, void *b);
char *mx_strcpy(char *dst, const char *src);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
void mx_printerr(const char *s);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strdup(const char *str);
t_list *mx_create_node(void *data);
void mx_push_back(t_list **list, void *data);
t_list *mx_createPlaylist(char *filename);
char *mx_file_to_str(const char *filename);
char *mx_strcat(char *s1, const char *s2);
int mx_count_words(const char *str, char delimiter);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char **str);
char **mx_strsplit(char const *s, char c);
void mx_clear_list(t_list **list);
bool mx_isspace(char c);
bool mx_isdigit(int c);
int mx_atoi(const char *str);
void mx_pop_index(t_list **list, int index);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b));
void mx_printPlaylist(t_list *list);
void mx_pop_front(t_list **list);
void mx_pop_back(t_list **list);
void mx_push_index(t_list **list, void *data, int index);
void mx_push_front(t_list **list, void *data);

#endif
