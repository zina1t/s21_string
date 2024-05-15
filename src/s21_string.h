#ifndef INIT_H
#define INIT_H

#define s21_size_t unsigned long long
#define s21_NULL (void *)0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
s21_size_t s21_strlen(const char *str);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
s21_size_t s21_strcspn(const char *str1, const char *str2);
#endif