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
    char id[11];
    char phone_no[12];
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
            printf("Invalid input.");
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

void signIn()
{
    char temp_pass1[16], temp_pass2[16];
    FILE *profiles;

    profiles = fopen("profiles.txt", "a+");

    if (profiles) {
        printf("Please enter your information below:\n\n");

        node = malloc(sizeof(user));
        if (node) {
            printf("Surname: ");
            gets(node->name);
            fputs(node->name, profiles);
            
            printf("Last Name: ");
            fgets(node->family, 20, stdin);
            fputs(node->family, profiles);
            
            printf("ID: ");
            fgets(node->id, 11, stdin);
            fputs(node->id, profiles);
            
            printf("Phone Number: ");
            fgets(node->phone_no, 20, stdin);
            fputs(node->phone_no, profiles);
            
            printf("Email: ");
            fgets(node->email, 20, stdin);
            fputs(node->email, profiles);
            
            printf("Username: "); // TODO: the word before username
            fgets(node->username, 20, stdin);
            fputs(node->username, profiles);
            
            while (1) {
                printf("Password: ");
                fgets(temp_pass1, 20, stdin);

                printf("Confirm Your Password: ");
                fgets(temp_pass2, 20, stdin);

                if (strcmp(temp_pass1, temp_pass2) == 0) {
                    strcpy(node->password, temp_pass1);
                    fputs(node->password, profiles);
                    break;
                }

                printf("Passwords don't match.");
            }
        }
        else
            printf("Your computer is low on memory.");
    }
    else
        printf("Could not access profiles. Please try again later.");

    printf("hi");
    printf("hhd");
}

void logIn()
{

}
