#ifndef INIT_H
#define INIT_H

#define s21_size_t unsigned long long
#define s21_NULL (void *)0
#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
s21_size_t s21_strlen(const char *str);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
s21_size_t s21_strcspn(const char *str1, const char *str2);
int s21_sprintf(char *str, const char *format, ...);
#endif