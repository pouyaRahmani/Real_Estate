#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct u {
    char name[20];
    char family[20];
    char id[11];
    char phone_no[12];
    char email[50];
    char username[20];
    char password[16];
    char enter[9];
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
    char enter[9];
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
    char enter[9];
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
    char enter[9];
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
    char enter[9];
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
    char enter[9];
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
    char enter[9];
    char isDelete;
    struct rent_land *next;    
} rent_land;
 
user *start_user = NULL, *end_user, *User;

void firstMenu();
void signIn();
void logIn();
void mainMenu();
void Register();
void Delete();
void report();
void settings();

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
    struct tm *local;
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

                printf("Confirm Your Password: ");
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

                // If two passwords are same saves it and breaks
                if (strcmp(temp_pass1, temp_pass2) == 0) {
                    strcpy(User->password, temp_pass1);
                    break;
                }

                printf("\nPasswords don't match.\n");
            }
            
            t = time(NULL);
            local = localtime(&t);
            sprintf(User->enter, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);
            strcpy(User->estates, "0");
            fwrite(User, sizeof(user), 1, profiles);

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

void logIn()
{
    char username[20], password[16];
    
    readProfiles();



        /*User = start_user;
        while (User->next) {
            puts(User->name);
            puts(User->family);
            puts(User->id);
            puts(User->phone_no);
            puts(User->email);
            puts(User->username);
            puts(User->password);
            puts(User->enter);
            puts(User->estates);
                
            User = User->next;
        }*/
}

void readProfiles()
{
    FILE *profiles;
    char admin_pass[16];
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
                fgets(start_user->enter, 9, profiles);
                fgetc(profiles);
                fgets(start_user->estates, 3, profiles);     
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
                fgets(end_user->enter, 9, profiles);
                fgetc(profiles);
                fgets(end_user->estates, 3, profiles);
            }
        }
    }
    else
        printf("Could not access profiles. Please try again later.");
}

void mainMenu()
{
    int choice;

    printf("What do you want to do?\n\n");

    printf("1. Register New Estate\n");
    printf("2. Delete Estate\n");
    printf("3. Reports\n");
    printf("4. Account Settings\n");
    printf("5. Log Out\n");
    printf("6. Exit App\n\n");

    printf("Choose an action from above menu: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        Register();
        break;
    
    case 2:
        Delete();
        break;
    
    case 3:
        report();
        break;
    
    case 4:
        settings();
        break;
    
    case 5:
        system("cls");
        return;
        break;
    
    case 6:
        exit(0);
        break;
    
    default:
        printf("Invalid input.\n");
        break;
    }
}

void Delete()
{

}

void Register()
{

}

void settings()
{

}

void report()
{

}

