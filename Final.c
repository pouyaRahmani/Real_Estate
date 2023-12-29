#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Defining some structures 
typedef struct u {
    char name[20];
    char family[20];
    char id[11];
    char phone_no[12];
    char email[50];
    char username[20];
    char password[16];
    char date[9];
    char estates[3];
    struct u *next;
} user;

typedef struct sale_house { // TODO: complete it
    char registrar[20];
    char deleter[20];
    char area[3];
    char address[300];
    char type[10];
    char age[3];
    char infrastructure[5];
    char floor[3];
    char land[5];
    char owner_phone_no[13];
    char rooms[3];
    char price[9];
    char tot_price[9];
    char parking;
    char warehouse;
    char elevator;
    char telephone;
    char date[9];
    char isDelete;
    struct sale_house *next;    
} sale_house;

typedef struct sale_office { // TODO: complete it
    char registrar[20];
    char deleter[20];
    char area[3];
    char address[300];
    char type[10];
    char age[3];
    char infrastructure[5];
    char floor[3];
    char land[5];
    char owner_phone_no[13];
    char rooms[3];
    char price[9];
    char tot_price[9];
    char date[9];
    char isDelete;
    struct sale_office *next;    
} sale_office;
 
typedef struct sale_land { // TODO: complete it
    char registrar[20];
    char deleter[20];
    char area[3];
    char address[300];
    char type[10];
    char land[5];
    char owner_phone_no[13];
    char price[9];
    char tot_price[9];
    char date[9];
    char isDelete;
    struct sale_land *next;    
} sale_land;
 
typedef struct rent_house { // TODO: complete it
    char registrar[20];
    char deleter[20];
    char area[3];
    char address[300];
    char type[10];
    char age[3];
    char infrastructure[5];
    char floor[3];
    char land[5];
    char owner_phone_no[13];
    char rooms[3];
    char rent[9];
    char mortgage[9];
    char parking;
    char warehouse;
    char elevator;
    char telephone;
    char date[9];
    char isDelete;
    struct rent_house *next;    
} rent_house;

typedef struct rent_office { // TODO: complete it
    char registrar[20];
    char deleter[20];
    char area[3];
    char address[300];
    char type[10];
    char age[3];
    char infrastructure[5];
    char floor[3];
    char land[5];
    char owner_phone_no[13];
    char rooms[3];
    char rent[9];
    char mortgage[9];
    char date[9];
    char isDelete;
    struct rent_office *next;    
} rent_office;
 
typedef struct rent_land { // TODO: complete it
    char registrar[20];
    char deleter[20];
    char area[3];
    char address[300];
    char type[10];
    char land[5];
    char owner_phone_no[13];
    char rent[9];
    char mortgage[9];
    char date[9];
    char isDelete;
    struct rent_land *next;    
} rent_land;
 
user *start_user = NULL, *end_user, *User, *admin;

void firstMenu();
void signIn();
void logIn();
void mainMenu(user *a);
void Register(user *a);
void Delete(user *a);
void report(user *a);
void settings(user *a);
void readProfiles();
void sale(user *a);
void rent(user *a);

void main()
{
    char choice;

    while (1) {
        firstMenu();
        choice = getchar();
        getchar(); // Avoid exta enter
        system("cls"); // Clear screen for better ui

        switch (choice)
        {
        case '1':
            signIn();
            break;

        case '2':
            logIn();
            break;

        case '3':
            exit(0);
            break;
        
        default:
            printf("Invalid input.\n");
            continue;
            break;
        }
    }
}


// Function to display first menu
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
    time_t t;
    struct tm *local; // pointer to structure of tm
    char temp_pass1[16], temp_pass2[16], ch;
    FILE *profiles;
    int index = 0;

    profiles = fopen("profiles.hex", "ab+");

    if (profiles) {
        printf("Please enter your information below:\n\n");

        // Allocate a structure, get information from user and save it to "profiles.txt" file
        User = malloc(sizeof(user));
        if (User) {
            printf("Surname: ");
            gets(User->name);
            
            printf("Last Name: ");
            gets(User->family);
            
            printf("ID: ");
            gets(User->id);
            
            printf("Phone Number: ");
            gets(User->phone_no);
            
            printf("Email: ");
            gets(User->email);
            
            printf("Username: "); // TODO: the word before username
            gets(User->username);
            
            // Get the password twice to avoid typing mistakes
            while (1) {
                printf("Password: ");
                // Loop until user press enter
                do {
                    ch = getch();

                    if (ch == 13)
                        break;
                    else if (ch == 8) {
                        printf("\b \b");
                        index--;
                        continue;
                    }

                    putchar('*'); // display * instead of password for better security
                    temp_pass1[index] = ch;
                    index++;
                } while (1); 

                temp_pass1[index] = '\0'; // Initialize the last character to \0 manually
                index = 0;

                printf("\nConfirm Your Password: ");
                // Loop until user press enter
                do {
                    ch = getch();

                    if (ch == 13)
                        break;
                    else if (ch == 8) {
                        printf("\b \b");
                        index--;
                        continue;
                    }
                    
                    putchar('*'); // display * instead of password for better security
                    temp_pass2[index] = ch;
                    index++;
                } while (1);

                temp_pass2[index] = '\0'; // Initialize the last character to \0 manually
                printf("\n");

                // If two passwords are same, save it and break
                if (strcmp(temp_pass1, temp_pass2) == 0) {
                    strcpy(User->password, temp_pass1);
                    break;
                }

                printf("\nPasswords don't match.\n");
            }
            
            // Save the sign up date
            t = time(NULL);
            local = localtime(&t);
            sprintf(User->date, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);
            strcpy(User->estates, "0"); // At first user haven't register any estates
            fwrite(User, sizeof(user), 1, profiles); // Write the information in file

            printf("\nYou have been signed up successfully. Enter a key to go back to log-in menu...");
            getch(); // Wait for a key press before clearing screen
            free(User);
            system("cls");
        }
        else
            printf("Your computer is low on memory.");

        fclose(profiles);
    }
    else
        printf("Could not access profiles. Please try again later.");
}

void logIn() // TODO: 2-step verification
{
    char username[20], password[16], ch;
    int index;

    admin = malloc(sizeof(user));
    strcpy(admin->username, "admin");
    strcpy(admin->password, "admin");
    strcpy(admin->name, "admin");
    strcpy(admin->family, "");
    
    readProfiles(); // Read information from file
    printf("Username: ");
    gets(username);

    // Loop throw users to match username and password
    User = start_user;
    while (User->next) {
        index = 0;
        // Checks if user is admin
        if (!strcmp(username, admin->username)) {
            printf("Admin password: ");
            
            // Loop until user press enter
            do {
                ch = getch();

                if (ch == 13)
                    break;
                else if (ch == 8) {
                    printf("\b \b");
                    index--;
                    continue;
                }

                putchar('*'); // display * instead of password for better security
                password[index] = ch;
                index++;
            } while (1);
            password[index] = '\0'; // Initialize the last character to \0 manually

            if (!strcmp(password, admin->password)) {
                system("cls");
                mainMenu(admin);
                break;
            }
        }
        else if (!strcmp(username, User->username)) {
            while (1) {
                printf("Password: ");

                // Loop until user press enter
                do {
                    ch = getch();

                    if (ch == 13)
                        break;
                    else if (ch == 8) {
                        printf("\b \b");
                        index--;
                        continue;
                    }

                    putchar('*'); // display * instead of password for better security
                    password[index] = ch;
                    index++;
                } while (1);
                password[index] = '\0'; // Initialize the last character to \0 manually

                if (!strcmp(password, User->password)) {
                    system("cls");
                    mainMenu(User);
                    break;
                }
                else
                    printf("\nWrong password!! Please try agin.\n"); // TODO: add comments
            }
        }
        else if (!User->next->next) {
            printf("Username you entered wasn't found.\n");
            printf("Do you want to sign in (Y/N)?\n");

            if (toupper(getche()) == 'Y') {
                system("cls");
                signIn();
            }
            else {
                system("cls");
                printf("Username: ");
                gets(username);
                User = start_user;
            }
        }

        User = User->next;
    }

    free(start_user);
    free(end_user);
}

void readProfiles() // TODO: add comments
{
    FILE *profiles;

    profiles = fopen("profiles.hex", "rb");
    if (profiles) {
        while (!feof(profiles)) {
            User = malloc(sizeof(user));
            if (User) {

                if (start_user == NULL) {
                    start_user = User;
                    end_user = User;
                    start_user->next = NULL;

                    fread(start_user, sizeof(user), 1, profiles);   
                }
                else {
                    end_user->next = User;
                    end_user = User;
                    end_user->next = NULL;

                    fread(end_user, sizeof(user), 1, profiles);
                }
            }
            else
                printf("Your computer is low on memory.");
        }

        fclose(profiles);
    }
    else
        printf("Could not access profiles. Please try again later.");
}

void mainMenu(user *a) // TODO: better name
{
    char choice;

    while (1) {
        printf("Welcome back %s %s\n", a->name, a->family);
        printf("What do you want to do?\n\n");

        printf("1. Register New Estate\n");
        printf("2. Delete Estate\n");
        printf("3. Reports\n");
        printf("4. Account Settings\n");
        printf("5. Log Out\n");
        printf("6. Exit App\n\n");

        printf("Choose an action from above menu: ");
        choice = getchar();
        getchar(); // Avoid exta enter
        system("cls");

        switch (choice)
        {
        case '1':
            Register(a);
            break;
        
        case '2':
            Delete(a);
            break;
        
        case '3':
            report(a);
            break;
        
        case '4':
            settings(a);
            break;
        
        case '5': // FIXME: fix
            return;
            break;
        
        case '6':
            exit(0);
            break;
        
        default:
            printf("Invalid input.\n");
            break;
        }
    }
}

void Delete(user *a)
{

}

void Register(user *a)
{
    char choice;

    printf("What do you want to register?\n\n");

    printf("1. Sales registration\n");
    printf("2. Rent registration\n");
    printf("3. Return back\n\n");

    printf("Enter your choice: ");
    choice = getchar();
    getchar(); // Avoid exta enter
    system("cls");

    switch (choice)
    {
    case '1':
        sale(a);
        break;
        
    case '2':
        rent(a);
        break;
        
    case '3':
        return;
        break;
        
    default:
        printf("Invalid input.\n");
        break;
    }
}

void settings(user *a)
{

}

void report(user *a)
{

}

void sale(user *a)
{
    char choice;

    printf("What type of estate do you want to register?\n\n");

    printf("1. Residential property (for live)\n");
    printf("2. Office property (for work)\n");
    printf("3. Land property\n");
    printf("4. Return back\n\n");

    printf("Enter your choice: ");
    choice = getchar();
    getchar(); // Avoid exta enter
    system("cls");

    switch (choice)
    {
    case '1':
        sale(a);
        break;
        
    case '2':
        rent(a);
        break;
        
    case '3':
        return;
        break;

    case '4':
        return;
        break;
        
    default:
        printf("Invalid input.\n");
        break;
    }
}

void rent(user *a)
{

}
