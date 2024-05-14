#include "init.h"

char *s21_strchr(const char *str, int c) {
  for (; *str && *str != c; str++);
  return (char *)str;
}