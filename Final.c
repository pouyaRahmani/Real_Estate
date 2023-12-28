#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct u {
    char username[20];
    char password[16];
    char name[20];
    char family[20];
    char id[12];
    char phone_no[13];
    char email[50];
    int estates;
    struct u *next;
} user;

user *start = NULL, *end, *node;

void mainMenu();
void signIn();
void logIn();

void main()
{
    int choice;

    while (1) {
        mainMenu();
        scanf("%d", &choice);
        getchar(); // TODO: add comment
        system("cls");

        switch (choice)
        {
        case 1:
            signIn();
            break;

        case 2:
            logIn();
            break;

        case 3:
            exit(0);
            break;
        
        default:
            printf("Invalid input.\n");
            continue;
            break;
        }
    }
}

void mainMenu()
{
    printf("\n\n");

    printf("1. Sign Up\n");
    printf("2. Log In\n");
    printf("3. Exit\n\n");

    printf("Choose an action from above menu: ");
}

void signIn() // TODO: check validation
{
    char temp_pass1[16], temp_pass2[16], ch;
    FILE *profiles;
    int index = 0;

    profiles = fopen("profiles.txt", "a");

    if (profiles) {
        printf("Please enter your information below:\n\n");

        node = malloc(sizeof(user));
        if (node) {
            printf("Surname: ");
            fgets(node->name, 20, stdin);
            fputs(node->name, profiles);
            
            printf("Last Name: ");
            fgets(node->family, 20, stdin);
            fputs(node->family, profiles);
            
            printf("ID: ");
            fgets(node->id, 12, stdin);
            fputs(node->id, profiles);
            
            printf("Phone Number: ");
            fgets(node->phone_no, 13, stdin);
            fputs(node->phone_no, profiles);
            
            printf("Email: ");
            fgets(node->email, 50, stdin);
            fputs(node->email, profiles);
            
            printf("Username: "); // TODO: the word before username
            fgets(node->username, 20, stdin);
            fputs(node->username, profiles);
            
            while (1) {
                printf("Password: ");
                do {
                    ch = getch();
                    putchar('*');
                    temp_pass1[index] = ch;
                    index++;
                } while (ch != 13);

                temp_pass1[index] = '\0';
                printf("\n");
                index = 0;

                printf("Confirm Your Password: ");
                do {
                    ch = getch();
                    putchar('*');
                    temp_pass2[index] = ch;
                    index++;
                } while (ch != 13);

                temp_pass2[index] = '\0';
                printf("\n");

                if (strcmp(temp_pass1, temp_pass2) == 0) {
                    strcpy(node->password, temp_pass1);
                    fputs(node->password, profiles);
                    break;
                }

                printf("Passwords don't match.");
            }

            free(node);
        }
        else
            printf("Your computer is low on memory.");

        fclose(profiles);
    }
    else
        printf("Could not access profiles. Please try again later.");

    printf("hi");
    printf("hhd");
}

void logIn()
{

}
