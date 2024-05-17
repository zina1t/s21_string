#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

char *int_to_str(int num, char *str) {
  char *p = str;
  int temp_num = num;
  int length = 0;
  int is_negative = 0;
  if (num == 0) {
    *p++ = '0';
    *p = '\0';
    return str;
  }
  if (num < 0) {
    is_negative = 1;
    num = -num;
  }
  temp_num = num;  // Reset temp_num to num for length calculation
  while (temp_num) {
    temp_num /= 10;
    length++;
  }
  if (is_negative) {
    length++;  // Add space for the negative sign
  }
  str[length] = '\0';
  while (num) {
    str[--length] = (num % 10) + '0';
    num /= 10;
  }
  if (is_negative) {
    str[0] = '-';
  }
  return str;
}

char *float_to_str(double num, char *str, int precision) {
  if (num < 0) {
    *str++ = '-';
    num = -num;
  }
  long int_part = (long)num;
  str += s21_sprintf(str, "%d", int_part);

  *str++ = '.';

  double fractional_part = num - int_part;
  for (int i = 0; i < precision; i++) {
    fractional_part *= 10;
    int digit = (int)fractional_part;
    *str++ = '0' + digit;
    fractional_part -= digit;
  }
  *str = '\0';
  return str;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  char *p = str;
  const char *f = format;
  char buffer[100];
  while (*f) {
    if (*f == '%') {
      f++;
      if (*f == '%') {
        *p++ = '%';
      }
      if (*f == 'f') {
        double d = va_arg(args, double);
        char num_str[40];
        float_to_str(d, num_str, 3);
        char *num_p = num_str;
        while (*num_p) {
          *p++ = *num_p++;
        }
      }

      if (*f == 'd') {
        int i = va_arg(args, int);
        char num_str[20];
        int_to_str(i, num_str);
        char *num_p = num_str;
        while (*num_p) {
          *p++ = *num_p++;
        }
      }
      if (*f == 's') {
        char *s = va_arg(args, char *);
        while (*s) {
          *p++ = *s++;
        }
      }
      if (*f == 'c') {
        char c = (char)va_arg(args, int);
        *p++ = c;
      }
      if (*f == 'u') {
        unsigned int i = va_arg(args, unsigned int);
        char num_str[20];
        int_to_str(i, num_str);
        char *num_p = num_str;
        while (*num_p) {
          *p++ = *num_p++;
        }
      }
    } else {
      *p++ = *f;
    }
    f++;
  }
  *p = '\0';

  va_end(args);
  return p - str;  // Return the length of the string written
}

int main() {
  char buffer[100];
  s21_sprintf(buffer, "Hi %s, your score is %d%c %u%% %f", "Ali", -95, '!', 273,
              -1244.2);
  printf("%s\n", buffer);  // print: "Hello Ali, your score is -95! 273"
  return 0;
}
