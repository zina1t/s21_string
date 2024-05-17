#include "s21_string.h"

struct {
  int align;
  int plus;
  int minus;
  int space;
  int hash;
  int zero;
  int width;
  int precision;
  char length;
} specs;

char* int_to_str(int num, char* str) {
  char* p = str;
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

char* float_to_str(double num, char* str, int precision) {
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

char* handle_int(char* p, va_list args) {
  int i = va_arg(args, int);
  char num_str[20];
  int_to_str(i, num_str);
  char* num_p = num_str;
  while (*num_p) {
    *p++ = *num_p++;
  }
  return p;
}

char* handle_float(char* p, va_list args) {
  double d = va_arg(args, double);
  char num_str[40];
  float_to_str(d, num_str, 3);
  char* num_p = num_str;
  while (*num_p) {
    *p++ = *num_p++;
  }
  return p;
}

char* handle_string(char* p, va_list args) {
  char* s = va_arg(args, char*);
  while (*s) {
    *p++ = *s++;
  }
  return p;
}

char* handle_char(char* p, va_list args) {
  char c = (char)va_arg(args, int);
  *p++ = c;
  return p;
}

char* handle_unsigned_int(char* p, va_list args) {
  unsigned int i = va_arg(args, unsigned int);
  char num_str[20];
  int_to_str(i, num_str);
  char* num_p = num_str;
  while (*num_p) {
    *p++ = *num_p++;
  }
  return p;
}

void init_specs() {
  specs.align = 0;
  specs.plus = 0;
  specs.minus = 0;
  specs.space = 0;
  specs.hash = 0;
  specs.zero = 0;
  specs.width = 0;
  specs.precision = 0;
  specs.length = '\0';
}

int s21_sprintf(char* str, const char* format, ...) {
  init_specs();
  va_list args;
  va_start(args, format);
  char* p = str;
  const char* f = format;
  while (*f) {
    if (*f == '%') {
      f++;

      while (*f == '-' || *f == '+' || *f == ' ') {
        if (*f == '-')
          specs.minus = 1;
        else if (*f == '+')
          specs.plus = 1;
        else if (*f == ' ')
          specs.space = 1;
        f++;
      }

      // Width description
      if (*f >= '0' && *f <= '9') {
        while (*f >= '0' && *f <= '9') {
          specs.width = specs.width * 10 + (*f - '0');
          f++;
        }
      }

      // Precision description
      if (*f == '.') {
        f++;
        while (*f >= '0' && *f <= '9') {
          specs.precision = specs.precision * 10 + (*f - '0');
          f++;
        }
      }

      // Length description
      if (*f == 'h' || *f == 'l') {
        specs.length = *f;
        f++;
      }

      switch (*f) {
        case 'd':
          p = handle_int(p, args);
          break;
        case 'f':
          p = handle_float(p, args);
          break;
        case 's':
          p = handle_string(p, args);
          break;
        case 'c':
          p = handle_char(p, args);
          break;
        case 'u':
          p = handle_unsigned_int(p, args);
          break;
        default:
          *p++ = *f;
          break;
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