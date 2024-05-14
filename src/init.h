#ifndef INIT_H
#define INIT_H

#define s21_size_t unsigned long long
#define s21_NULL (void *)0
#include <stdio.h>
#include <stdlib.h>
s21_size_t s21_strlen(const char *str);
int s21_strcmp(char *str1, char *str2, s21_size_t n);
char *s21_strchr(const char *str, int c);
#endif