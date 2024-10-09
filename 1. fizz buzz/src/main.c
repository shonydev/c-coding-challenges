#include <stdio.h>
#include "utils/print.c"

int is_multiple_of_three(int number);
int is_multiple_of_five(int number);
int is_multiple_of_three_and_five(int number);
int is_true();
int is_false();

int main() {
  int count = 1;
  while (count <= 100) {
    if (is_multiple_of_three_and_five(count)) {
      printf("fizzbuzz\n");
    } else if (is_multiple_of_three(count)) {
      printf("fizz\n");
    } else if (is_multiple_of_five(count)) {
      printf("buzz\n");
    } else {
      printf("%d\n", count);
    }

    count++;
  }
  print("shon");
  return 0;
}
int is_multiple_of_three_and_five(int number) {
  int output = is_false();
  if (is_multiple_of_three(number) && is_multiple_of_five(number)) {
    output = is_true();
  }
  return output;
}

int is_multiple_of_three(int number) {
  int output = is_false();
  if (number % 3 == 0) {
    output = is_true();
  }
  return output;
}
int is_multiple_of_five(int number) {
  int output = is_false();
  if (number % 5 == 0) {
    output = is_true();
  }
  return output;
}

int is_true() {
  return 1;
}

int is_false() {
  return 0;
}