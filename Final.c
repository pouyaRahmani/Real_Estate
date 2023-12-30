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
    char address[500];
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
    struct sale_house *next;    
} sale_house;

typedef struct sale_office { // TODO: complete it
    char registrar[20];
    char deleter[20];
    char area[3];
    char address[500];
    char type[20];
    char age[3];
    char infrastructure[5];
    char floor[3];
    char land[5];
    char owner_phone_no[13];
    char rooms[3];
    char price[9];
    char tot_price[9];
    char date[9];
    struct sale_office *next;    
} sale_office;
 
typedef struct sale_land { // TODO: complete it
    char registrar[20];
    char deleter[20];
    char area[3];
    char address[500];
    char type[10];
    char land[6];
    char owner_phone_no[13];
    char price[9];
    char tot_price[9];
    char date[9];
    struct sale_land *next;    
} sale_land;
 
typedef struct rent_house { // TODO: complete it
    char registrar[20];
    char deleter[20];
    char area[3];
    char address[500];
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
    struct rent_house *next;    
} rent_house;

typedef struct rent_office { // TODO: complete it
    char registrar[20];
    char deleter[20];
    char area[3];
    char address[500];
    char type[20];
    char age[3];
    char infrastructure[5];
    char floor[3];
    char land[5];
    char owner_phone_no[13];
    char rooms[3];
    char rent[9];
    char mortgage[9];
    char date[9];
    struct rent_office *next;    
} rent_office;
 
typedef struct rent_land { // TODO: complete it
    char registrar[20];
    char deleter[20];
    char area[3];
    char address[500];
    char type[10];
    char land[6];
    char owner_phone_no[13];
    char rent[9];
    char mortgage[9];
    char date[9];
    struct rent_land *next;    
} rent_land;
 
user *start_user = NULL, *end_user, *User, *admin;
sale_house *start_sale_house = NULL, *end_sale_house, *Sale_house;
sale_office *start_sale_office = NULL, *end_sale_office, *Sale_office;
sale_land *start_sale_land = NULL, *end_sale_land, *Sale_land;

void firstMenu();
void signUn();
void logIn();
void mainMenu(user *a);
void Register(user *a);
void Delete(user *a);
void report(user *a);
void settings(user *a);
void readProfiles();
void sale(user *a);
void rent(user *a);
void saleEstate(user *a, char *type);
void rentEstate(user *a, char *type);
double unitPicker(double a);

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
            signUp();
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
void signUp() // TODO: check validation
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
            printf("ERROR: Your computer is low on memory.");

        fclose(profiles);
    }
    else
        printf("ERROR: Could not access profiles. Please try again later.");
}

void logIn() // TODO: 2-step verification
{
    char username[20], password[16], ch;
    int index;

    admin = malloc(sizeof(user));
    if (admin) {
        strcpy(admin->username, "admin");
        strcpy(admin->password, "admin");
        strcpy(admin->name, "admin");
        strcpy(admin->family, "");
    }
    else
        printf("ERROR: Your computer is low on memory.");
    
    readProfiles(); // Read information from file
    printf("Username: ");
    gets(username);

    // Loop throw users to match username and password
    User = start_user;
    while (User->next) {
        index = 0;
        // Checks if user is admin
        if (!strcmp(username, admin->username)) {
            while (1) {
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
                else
                    printf("\nERROR: Wrong password!! Please try agin.\n");
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
                    printf("\nERROR: Wrong password!! Please try agin.\n"); // TODO: add comments
            }
        }
        else if (!User->next->next) {
            printf("Username you entered wasn't found.\n");
            printf("Do you want to sign up (Y/N)?\n");

            // Checks if user wants to sign up or not
            if (toupper(getche()) == 'Y') {
                system("cls");
                signUp();
            }
            else {
                system("cls");
                printf("Username: ");
                gets(username);
                User = start_user;
            }
        }
        else
            User = User->next;
    }
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
                printf("ERROR: Your computer is low on memory.");
        }

        fclose(profiles);
    }
    else
        printf("ERROR: Could not access profiles. Please try again later.");
}

void mainMenu(user *a) // TODO: better name
{
    char choice;

    User = start_user;
    while (User->next) {
        free (User);
        User = User->next;
    }

    free(start_user);
    free(admin);

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
            printf("ERROR: Invalid input.\n");
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
        printf("ERROR: Invalid input.\n");
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
        saleEstate(a, "house");
        break;
        
    case '2':
        saleEstate(a, "office");
        break;
        
    case '3':
        saleEstate(a, "land");
        break;

    case '4':
        return;
        break;
        
    default:
        printf("ERROR: Invalid input.\n");
        break;
    }
}

void rent(user *a)
{

}

static char unit;

void saleEstate(user *a, char *type) // TODO: update user estates
{
    double price_temp, tot_temp;
    time_t t;
    struct tm *local; // pointer to structure of tm

    local = malloc(sizeof(struct tm));

    if (!strcmp(type, "house")) {
        FILE *house;

        house = fopen("houses_sale.hex", "ab+");
        if (house) {
            printf("Enter the information of estate, below:\n\n");

            Sale_house = malloc(sizeof(sale_house));
            if (Sale_house) {
                printf("Municipality area: ");
                gets(Sale_house->area);
                
                printf("Full address: ");
                gets(Sale_house->address);
                
                printf("Type (Apartment/Villa): ");
                gets(Sale_house->type);
                
                printf("Age: ");
                gets(Sale_house->age);
                
                printf("Infrastructure (House Area): ");
                gets(Sale_house->infrastructure);
                
                printf("On which floor: ");
                gets(Sale_house->floor);
                
                printf("Base area: ");
                gets(Sale_house->land);
                
                printf("Owner phone number: ");
                gets(Sale_house->owner_phone_no);
                
                printf("The amount of rooms: ");
                gets(Sale_house->rooms);
                
                printf("Price per meter: ");
                scanf("%lf", &price_temp);
                getchar(); // Avoid extra enter
                tot_temp = price_temp * atoi(Sale_house->infrastructure);

                price_temp = unitPicker(price_temp);
                sprintf(Sale_house->price, "%.3lf %c", price_temp, unit);

                tot_temp = unitPicker(tot_temp);
                sprintf(Sale_house->tot_price, "%.3lf %c", tot_temp, unit);
                
                printf("Does it have parking? (Y/N): ");
                Sale_house->parking = toupper(getche());
                   
                printf("\nDoes it have warehouse? (Y/N): ");
                Sale_house->warehouse = toupper(getche());
                   
                printf("\nDoes it have elevator? (Y/N): ");
                Sale_house->elevator = toupper(getche());
                   
                printf("\nDoes it have telephone? (Y/N): ");
                Sale_house->telephone = toupper(getche());
                
                // Save the register date
                t = time(NULL);
                local = localtime(&t);
                sprintf(Sale_house->date, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);

                strcpy(Sale_house->registrar, a->username);
                strcpy(Sale_house->deleter, "0");

                fwrite(Sale_house, sizeof(sale_house), 1, house); // Write the information in file
                printf("\nRegister was successful. Press any key to go back to main menu...");
                getch();
                system("cls");

                fclose(house);
                return;
            }
            else
                printf("ERROR: Your computer is low on memory."); 
        }
        else
            printf("ERROR: Could not access Estates. Please try again later.");
    }
    else if (!strcmp(type, "office")) {
        FILE *office;

        office = fopen("offices_sale.hex", "ab+");
        if (office) {
            printf("Enter the information of estate, below:\n\n");

            Sale_office = malloc(sizeof(sale_house));
            if (Sale_office) {
                printf("Municipality area: ");
                gets(Sale_office->area);
                
                printf("Full address: ");
                gets(Sale_office->address);
                
                printf("Type (Official document/Position): ");
                gets(Sale_office->type);

                printf("Age: ");
                gets(Sale_office->age);
                
                printf("Infrastructure (Office Area): ");
                gets(Sale_office->infrastructure);
                
                printf("On which floor: ");
                gets(Sale_office->floor);
                
                printf("Base area: ");
                gets(Sale_office->land);
                
                printf("Owner phone number: ");
                gets(Sale_office->owner_phone_no);
                
                printf("The amount of rooms: ");
                gets(Sale_office->rooms);
                
                printf("Price per meter: ");
                scanf("%lf", &price_temp);
                getchar(); // Avoid extra enter
                tot_temp = price_temp * atoi(Sale_office->infrastructure);

                price_temp = unitPicker(price_temp);
                sprintf(Sale_office->price, "%.3lf %c", price_temp, unit);

                tot_temp = unitPicker(tot_temp);
                sprintf(Sale_office->tot_price, "%.3lf %c", tot_temp, unit);
                
                // Save the register date
                t = time(NULL);
                local = localtime(&t);
                sprintf(Sale_office->date, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);

                strcpy(Sale_office->registrar, a->username);
                strcpy(Sale_office->deleter, "0");

                fwrite(Sale_office, sizeof(sale_office), 1, office); // Write the information in file
                printf("\nRegister was successful. Press any key to go back to main menu...");
                getch();
                system("cls");

                fclose(office);
                return;
            }
            else
                printf("ERROR: Your computer is low on memory."); 
        }
        else
            printf("ERROR: Could not access Estates. Please try again later.");
    }
    else {
        FILE *land;

        land = fopen("lands_sale.hex", "ab+");
        if (land) {
            printf("Enter the information of estate, below:\n\n");

            Sale_land = malloc(sizeof(sale_house));
            if (Sale_land) {
                printf("Municipality area: ");
                gets(Sale_land->area);
                
                printf("Full address: ");
                gets(Sale_land->address);
                
                printf("Type (Farming/City): ");
                gets(Sale_land->type);
                
                printf("Base area: ");
                gets(Sale_land->land);
                
                printf("Owner phone number: ");
                gets(Sale_land->owner_phone_no);
                
                printf("Price per meter: ");
                scanf("%lf", &price_temp);
                getchar(); // Avoid extra enter
                tot_temp = price_temp * atoi(Sale_land->land);

                price_temp = unitPicker(price_temp);
                sprintf(Sale_land->price, "%.3lf %c", price_temp, unit);

                tot_temp = unitPicker(tot_temp);
                sprintf(Sale_land->tot_price, "%.3lf %c", tot_temp, unit);
                
                // Save the register date
                t = time(NULL);
                local = localtime(&t);
                sprintf(Sale_land->date, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);

                strcpy(Sale_land->registrar, a->username);
                strcpy(Sale_land->deleter, "0");

                fwrite(Sale_land, sizeof(sale_land), 1, land); // Write the information in file
                printf("\nRegister was successful. Press any key to go back to main menu...");
                getch();
                system("cls");

                fclose(land);
                return;
            }
            else
                printf("ERROR: Your computer is low on memory."); 
        }
        else
            printf("ERROR: Could not access Estates. Please try again later.");
    }
}

void rentEstate(user *a, char *type)
{

}

double unitPicker(double price)
{
    int counter;

    while (price > 1000) {
        price = price / 1000;
        counter++;
    }

    switch (counter)
    {
    case 0:
        unit = ' ';
        break;
                
    case 1:
        unit = 'K';
        break;
                
    case 2:
        unit = 'M';
        break;
        
    default:
        unit = 'B';
       break;
    }

    return price;
}
