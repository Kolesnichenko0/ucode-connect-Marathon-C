#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define E_OPERATION "Invalid operation: "
#define E_OPERAND "Invalid operand: "
#define E_RESULT "Invalid result: "
#define E_USAGE "usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]"

char *mx_itoa(long long num);
long long mx_atoi(const char *str);
long long mx_pow(long long n, unsigned int pow);
int mx_strlen(const char *s);
void mx_printerr(const char *s);
void mx_printchar(char c);
void mx_printstr(const char *s);
void mx_printnum(long long n);
void mx_strdel(char **str);
char *mx_strnew(const int size);
bool mx_isspace(char c);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strtrim(const char *str);
char *mx_del_extra_whitespaces(const char *str);
void mx_error(char *e, char *argv);
bool mx_isdigit(int c);
void mx_compute(char *operand1, char *operand2, char *result, char operation);
char* mx_check_change_num(char *s);
char mx_check_find_operation(char *s);

#endif

