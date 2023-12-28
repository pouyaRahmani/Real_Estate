#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct u { // TODO: add date
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

user *start_user = NULL, *end_user, *User;

void firstMenu();
void signIn();
void logIn();

void main()
{
    int choice;

    while (1) {
        firstMenu();
        scanf("%d", &choice);
        getchar(); // To avoid extra \n (enter) in the buffer
        system("cls"); // Clear screen for better ui

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


// Function to display main menu
void firstMenu()
{
    printf("\n\n");

    printf("1. Sign Up\n");
    printf("2. Log In\n");
    printf("3. Exit\n\n");

    printf("Choose an action from above menu: ");
}

// Function to do the sign in proccess
void signIn() // TODO: check validation
{
    char temp_pass1[16], temp_pass2[16], ch;
    FILE *profiles;
    int index = 0;

    profiles = fopen("profiles.txt", "a");

    if (profiles) {
        printf("Please enter your information below:\n\n");

        // Allocate a structure, get information from user and save it to "profiles.txt" file
        User = malloc(sizeof(user));
        if (User) {
            printf("Surname: ");
            fgets(User->name, 20, stdin);
            fputs(User->name, profiles);
            
            printf("Last Name: ");
            fgets(User->family, 20, stdin);
            fputs(User->family, profiles);
            
            printf("ID: ");
            fgets(User->id, 12, stdin);
            fputs(User->id, profiles);
            
            printf("Phone Number: ");
            fgets(User->phone_no, 13, stdin);
            fputs(User->phone_no, profiles);
            
            printf("Email: ");
            fgets(User->email, 50, stdin);
            fputs(User->email, profiles);
            
            printf("Username: "); // TODO: the word before username
            fgets(User->username, 20, stdin);
            fputs(User->username, profiles);
            
            // Get the password twice to avoid typing mistakes
            while (1) {
                printf("Password: ");
                // Loop until user press enter
                do {
                    ch = getch();
                    putchar('*'); // display * instead of password for better security
                    temp_pass1[index] = ch;
                    index++;
                } while (ch != 13); 

                temp_pass1[index] = '\0'; // initialize the last character ro \0 manually
                printf("\n");
                index = 0;

                printf("Confirm Your Password: ");
                // Loop until user press enter
                do {
                    ch = getch();
                    putchar('*'); // display * instead of password for better security
                    temp_pass2[index] = ch;
                    index++;
                } while (ch != 13);

                temp_pass2[index] = '\0'; // initialize the last character ro \0 manually
                printf("\n");

                // If two passwords are same saves it and breaks
                if (strcmp(temp_pass1, temp_pass2) == 0) {
                    strcpy(User->password, temp_pass1);
                    fputs(User->password, profiles); // TODO: encryption
                    break;
                }

                printf("Passwords don't match.");
            }

            fputs("0\n", profiles);

            printf("You have been signed up successfully. Enter a key to go back to main menu...");
            getch(); // Wait for a key press before clearing screen
            system("cls");
            free(User);
        }
        else
            printf("Your computer is low on memory.");

        fclose(profiles);
    }
    else
        printf("Could not access profiles. Please try again later.");
}

void logIn() // FIXME: fix
{
    FILE *profiles;
    char admin_pass[16], estate[16];

    profiles = fopen("profiles.txt", "r");
    fgets(admin_pass, 16, profiles);
    fgets(admin_pass, 16, profiles);

    if (profiles) {
        while (!feof(profiles)) {
            User = malloc(sizeof(user));

            if (start_user == NULL) {
                start_user = User;
                end_user = User;
                start_user->next = NULL;

                fgets(start_user->name, 20, profiles);
                fgets(start_user->family, 20, profiles);
                fgets(start_user->id, 12, profiles);
                fgets(start_user->phone_no, 13, profiles);
                fgets(start_user->email, 50, profiles);
                fgets(start_user->username, 20, profiles);
                fgets(start_user->password, 16, profiles);
                fgets(estate, 16, profiles);
                start_user->estates = atoi(estate);
            }
            else {
                end_user->next = User;
                end_user = User;
                end_user->next = NULL;

                fgets(end_user->name, 20, profiles);
                fgets(end_user->family, 20, profiles);
                fgets(end_user->id, 12, profiles);
                fgets(end_user->phone_no, 13, profiles);
                fgets(end_user->email, 50, profiles);
                fgets(end_user->username, 20, profiles);
                fgets(end_user->password, 16, profiles);
                fgets(estate, 16, profiles);
                end_user->estates = atoi(estate);
            }
        }

        User = start_user;
        while (User) {
            puts(User->name);
            puts(User->family);
            puts(User->id);
            puts(User->phone_no);
            puts(User->email);
            puts(User->username);
            puts(User->password);
            printf("%d\n", User->estates);
                
            User = User->next;
        }
    }
}
