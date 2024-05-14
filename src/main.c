#include <string.h>

#include "init.h"

int main() {
  char *string1 = "";
  char *string2 = "love loxve";

  printf("%s", strstr(string2, string1));
  printf("\n");
  printf("%s", s21_strstr(string2, string1));
  return 0;
}