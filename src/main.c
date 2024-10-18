#include <stdio.h>

void cleanBuffer();
int showMenu();
void pause() {
    getchar();
}


int showMenu() {
    int option;
    printf("\033[2J\033[H");
    printf("\nSHON\n\n");
    printf("1. Create user\n");
    printf("2. List users\n");
    printf("3. Update user\n");
    printf("4. Delete user\n");
    printf("5. Exit\n");

    printf("\nChoose an option: ");
    scanf("%d", &option);
    cleanBuffer();
    return option;
}

void cleanBuffer() {
    while (getchar() != '\n');
}

int main() {
    int option;
    do {
        option = showMenu();
        switch(option) {
            case 1:
                printf("Creating user...\n");
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

    return 0;
}