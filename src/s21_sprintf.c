#include "s21_string.h"

int main() {
  char buffer[100];
  s21_sprintf(buffer, "Hi %s, your score is %d%c %u%% %f", "Ali", -95, '!', 273,
              -1244.2);
  printf("%s\n", buffer);  // print: "Hello Ali, your score is -95! 273"
  return 0;
}
