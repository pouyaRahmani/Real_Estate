#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void mainMenu();
void signIn();
void logIn();

void main()
{
    int choice;

    while (1)
    {
        mainMenu();
        scanf("%d", &choice);
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
    printf
}

void logIn()
{

}
