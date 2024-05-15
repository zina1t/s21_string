#include <string.h>

#include "s21_string.h"

int main() {
  char *string1 = "e";
  char *string2 = "love loxve";

  printf("%ld", strcspn(string2, string1));
  printf("\n");
  printf("%lld", s21_strcspn(string2, string1));
  return 0;
}