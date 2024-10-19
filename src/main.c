#include <stdio.h>
#include <string.h>

struct User {
  int id;
  char name[50];
  int age;
};

int id_counter = 1;

int show_menu();

void start();
void pause();
void create_user();
void clean_buffer();
void clean_screen();
void create_header();

int show_menu() {
  clean_screen();

  int option;

  printf("\nSHON\n\n");

  printf("1. Create user\n");
  printf("2. List users\n");
  printf("3. Update user\n");
  printf("4. Delete user\n");
  printf("5. Exit\n");

  printf("\nChoose an option: ");
  scanf("%d", & option);
  clean_buffer();
  return option;
}

void start() {
  int option;
  do {
    option = show_menu();
    switch (option) {
    case 1:
      printf("Creating user...\n");
      create_user();
      id_counter += 1;
      pause();
      break;
    case 2:
      printf("Listing users...\n");
      pause();
      break;
    case 3:
      printf("Updating user...\n");
      pause();
      break;
    case 4:
      printf("Deleting user...\n");
      pause();
      break;
    case 5:
      printf("Exiting...\n");
      printf("Press Enter to continue...");
      pause();
      break;
    default:
      printf("Invalid option. Please try again.\n");
      pause();
    }
  } while (option != 5);
}
void pause() {
  getchar();
}
void create_user() {
  char name[40] = "shon";
  int age = 26;
  struct User user;
  user.id = id_counter;
  strcpy(user.name, name);
  user.age = age;
  char buffer[100];
  FILE * file;
  file = fopen("users.csv", "r");
  if (file == NULL) {
    printf("Error al abrir el archivo.\n");
    file = fopen("users.csv", "a");
    create_header(file);
  } else {
    fgets(buffer, 100, file);
    printf("%s", buffer);

    if (strcmp(buffer, "id,name,age")) {
      printf("es idugual:");
      file = fopen("users.csv", "a+");

      fseek(file, 0, SEEK_END);
      fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(file);
  }
  pause();
}

void clean_buffer() {
  while (getchar() != '\n');
}
void clean_screen() {
  printf("\033[2J\033[H");
}
void create_header(FILE * file) {
  fprintf(file, "id,name,age\n");
}
int main() {
  start();
  return 0;
}