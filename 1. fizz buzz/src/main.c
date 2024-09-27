#include <stdio.h>

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
    } else if (is_multiple_of_three(count) == is_true()) {
      printf("fizz\n");
    } else if (is_multiple_of_five(count) == is_true()) {
      printf("buzz\n");
    } else {
      printf("%d\n", count);
    }

    count++;
  }
  return 0;
}
int is_multiple_of_three_and_five(int number) {
  int output = is_false();
  if (is_multiple_of_three(number) == is_true() && is_multiple_of_five(number) == is_true()) {
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