#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Defining some structures 
typedef struct u { // Structure to represent an user
    char name[20];
    char family[20];
    char id[11];
    char phone_no[12];
    char email[50];
    char username[20];
    char password[20];
    char date[9];
    char estates[3];
    char last_activity[9];
    char two_step_verification;
    struct u *next;
} user;

typedef struct sale_house { // Structure to represent a house for sale
    char registrar[20];
    char deleteDate[20];
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

typedef struct sale_office { // Structure to represent an office for sale
    char registrar[20];
    char deleteDate[20];
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
 
typedef struct sale_land { // Structure to represent a land for sale
    char registrar[20];
    char deleteDate[20];
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
 
typedef struct rent_house { // Structure to represent a house for rent
    char registrar[20];
    char deleteDate[20];
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

typedef struct rent_office { // Structure to represent an office for rent
    char registrar[20];
    char deleteDate[20];
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
 
typedef struct rent_land { // Structure to represent a land for rent
    char registrar[20];
    char deleteDate[20];
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

// Some pointers for every structure to make linked list
user *start_user = NULL, *end_user, *User, *admin, *temp;

sale_house *start_sale_house = NULL, *end_sale_house, *Sale_house, *temp_sale_house;
sale_office *start_sale_office = NULL, *end_sale_office, *Sale_office, *temp_sale_office;
sale_land *start_sale_land = NULL, *end_sale_land, *Sale_land, *temp_sale_land;

rent_house *start_rent_house = NULL, *end_rent_house, *Rent_house, *temp_rent_house;
rent_office *start_rent_office = NULL, *end_rent_office, *Rent_office, *temp_rent_office;
rent_land *start_rent_land = NULL, *end_rent_land, *Rent_land, *temp_rent_land;

int Sale = 1, Rent = 1;

// Prototypes of functions
void red();
int validEmail(char *email);
void deleteRent();
void green();
int validName(char *name);
void municipalityArea();
void DeleteRent(char *type);
void valueEstate();
user *swap(user *usr1, user *usr2);
void signUp();
void mainMenu(user *a);
void logIn();
void Register(user *a);
void ageEstate();
void takePass(char *password);
void Delete();
void report(user *a);
int readSales();
void settings(user *a);
int readProfiles();
void sale(user *a);
int readRents();
void rent(user *a);
void countReport();
void saleEstate(user *a, char *type);
void infrastructureEstate();
void rentEstate(user *a, char *type);
void totalPriceEstate();
double unitPicker(double a);
void meterPriceEstate();
double unitConverter(char *price);
void valueEstate();
int availableUser(char *user);
void RentEstate();
int datecmp(char *date);
void DeleteEstate();
void updateUserEstate(user *a);
void userActivity();
void changePass(user *a);
void freeUsers();
void changeEmail(user *a);
void floorEstate();
void changePhone(user *a);
void userSortRegister();
void bubbleSort(user **head, int count);
void monthRentEstate();
int validID(char *id);
void dateEstate();
int validPhone(char *phone);
void deleteSale();
int validPass(char *pass, int size);
void roomsEstate();
void DeleteSale(char *type);
void freeEstates();
void changeVerification(user *a);
void reset();

void main()
{
    int choice;

    // Create admin user dynamically
    admin = malloc(sizeof(user));
    if (admin) {
        strcpy(admin->username, "admin");
        strcpy(admin->password, "admin");
        strcpy(admin->name, "admin");
        strcpy(admin->family, "");
        strcpy(admin->estates, "0");
    }
    else {
        red();
        printf("ERROR: Your computer is low on memory.");
        reset();
    }

    system("color 0b");
    while (1) {
        printf("%38s---=== Welcome to Real-Estate software ===---\n\n", " ");

        printf("1. Sign Up\n");
        printf("2. Log In\n");
        printf("3. Exit\n\n");

        printf("Choose an action from above menu: ");
        scanf("%d", &choice);
        getchar(); // Avoid exta enter
        system("cls"); // Clear screen for better ui

        switch (choice)
        {
        case 1:
            signUp();
            break;

        case 2:
            logIn();
            break;

        case 3:
            exit(0);
            break;
        
        default:
            red();
            printf("ERROR: Invalid input.\n");
            reset();
            break;
        }
    }
}

// Function to do the sign in proccess
void signUp()
{
    time_t t; // Variable to store time
    struct tm *local; // pointer to structure of tm
    char temp_pass1[20], temp_pass2[20], choice;
    FILE *profiles, *number;
    int users;

    local = malloc(sizeof(struct tm));
    profiles = fopen("profiles.hex", "ab+");
    number = fopen("number_of_users.txt", "r+");

    printf("%50s--== Sign Up ==--\n", " ");
    if (profiles && number) {
        printf("Please enter your information below:\n\n");

        // Allocate a structure, get information from user and save it to "profiles.hex" file
        temp = malloc(sizeof(user));
        if (temp) {
            // Promote user to enter specific information
            while (1) {
                printf("Surname: ");
                gets(temp->name);

                if (validName(temp->name))
                    break;

                printf("This Surname is not valid!!!\n\n");
            }
            
            while (1) {
                printf("\nLast name: ");
                gets(temp->family);

                if (validName(temp->family))
                    break;

                printf("This Last name is not valid!!!\n\n");
            }
            
            while (1) {
                printf("\nID: ");
                gets(temp->id);

                if (validID(temp->id))
                    break;

                printf("This ID is taken by another user or it's not valid!!!\n\n");
            }

            while (1) {
                printf("\nPhone Number: ");
            
                gets(temp->phone_no);
                
                if (validPhone(temp->phone_no))
                    break;

                printf("This phone number is taken by another user or it's not valid!!!\n\n");
            }
            
            while (1) {
                printf("\nEmail: ");
                gets(temp->email);

                if (validEmail(temp->email))
                    break;

                printf("This email address is taken by another user or it's not valid!!!\n\n");  
            }
            
            while (1) {
                printf("\nUsername: ");
                gets(temp->username);

                if (availableUser(temp->username))
                    break;

                printf("Username is taken!!!\n\n");
            }
            
            // Get the password twice to avoid typing mistakes
            while (1) {
                while (1) {
                    printf("\nPassword: ");
                    takePass(temp_pass1);

                    if (validPass(temp_pass1, strlen(temp_pass1)))
                        break;

                    printf("\n\nPassword must have below conditions:\n\n");

                    printf("1. More than 8 characters.\n");
                    printf("2. Atleast one capital letter, one lowercase letter and one special character.\n");
                    printf("3. No spaces!!\n\n");
                }

                printf("\nConfirm Your Password: ");
                // Loop until user press enter
                takePass(temp_pass2);
                printf("\n");

                // If two passwords are same, save it and break
                if (!strcmp(temp_pass1, temp_pass2)) {
                    strcpy(temp->password, temp_pass2);
                    break;
                }

                printf("\nPasswords don't match.\n");
            }

            printf("\n\nDo you want to enable 2 step verification for your account (Y/N)? ");
            choice = getche();

            if (toupper(choice) == 'Y') {
                printf("\n\n1. National ID\n");
                printf("2. Phone Number\n");
                printf("3. Email\n");
                
                while (1) {
                    printf("\nWhat do you want to be your identity validator: ");
                    scanf("%c", &choice);
                    getchar();

                    if (!isdigit(choice) || choice > '3') {
                        red();
                        printf("ERROR: Invalid input.\n");
                        reset();
                    }
                    else {
                        temp->two_step_verification = choice;
                        break;
                    }
                }
            }
            else
                temp->two_step_verification = '0';
            
            // Save the sign up date
            t = time(NULL);
            local = localtime(&t);
            sprintf(temp->date, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);
            sprintf(temp->last_activity, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);
            strcpy(temp->estates, "0"); // At first user haven't registered any estates
            fwrite(temp, sizeof(user), 1, profiles); // Write the information in file

            fscanf(number, "%d", &users);
            users++;
            rewind(number);
            fprintf(number, "%d", users);
            number = freopen("number_of_users.txt", "a+", number);
            fprintf(number, "%s\n", temp->username);

            green();
            printf("\nYou have been signed up successfully. Enter a key to go back to log-in menu...");
            reset();
            getch(); // Wait for a key press before clearing screen
            free(temp);
            system("cls"); // Clear screen for better ui
        }
        else {
            red();
            printf("ERROR: Your computer is low on memory.");
            reset();
        }

        fclose(profiles);
        fclose(number);
    }
    else {
        red();
        printf("ERROR: Could not access profiles. Please try again later.");
        reset();
    }
}

// Function to do log in proccess
void logIn()
{
    FILE *profiles;
    time_t t; // Variable to store time
    struct tm *local; // pointer to structure of tm
    char username[20], password[20], ch;
    int attempts = 1;

    printf("%50s--== Log In ==--\n\n", " ");
    
    // Read information from file
    if (readProfiles())
        return;

    printf("Username: ");
    gets(username);

    // Checks if user is admin
    if (!strcmp(username, admin->username)) {
        while (1) {
            printf("Admin password: ");
            takePass(password);

            if (!strcmp(password, admin->password)) {
                system("cls"); // Clear screen for better ui
                mainMenu(admin);
                break;
            }
            else {
                red();
                printf("\nERROR: Wrong password!! Please try agin.\n");
                reset();
            }
        }
    }
    else {
        // Loop throw users to match username and password
        User = start_user;
        while (User) {
            if (!strcmp(username, User->username)) {
                for (int i = 0; i < 5; i++) {
                    printf("\nPassword: ");
                    takePass(password);

                    if (!strcmp(password, User->password)) {
                        char temp_verification[50];
                        
                        switch (User->two_step_verification)
                        {
                        case '1':
                            do {
                                printf("\nPlease enter your national ID for 2-step verification: ");
                                gets(temp_verification);

                                if (!strcmp(temp_verification, User->id))
                                    break;
                                
                                printf("\nNational ID does not match!!!\n");
                            } while (1);

                            break;
                        
                        case '2':
                            do {
                                printf("\nPlease enter your phone number for 2-step verification: ");
                                gets(temp_verification);

                                if (!strcmp(temp_verification, User->phone_no))
                                    break;
                                
                                printf("\nPhone number does not match!!!\n");
                            } while (1);

                            break;
                        
                        case '3':
                            do {
                                printf("\nPlease enter your email for 2-step verification: ");
                                gets(temp_verification);

                                if (!strcmp(temp_verification, User->email))
                                    break;
                                
                                printf("\nEmail does not match!!!\n");
                            } while (1);

                            break;
                        
                        default:
                            break;
                        }
                        
                        system("cls"); // Clear screen for better ui
                        t = time(NULL);
                        local = localtime(&t);
                        sprintf(User->last_activity, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday); // Update User last activity

                        // Apply Updates and save to file
                        profiles = fopen("profiles.hex", "wb");

                        if (profiles) {
                            for (temp = start_user; temp; temp = temp->next)
                                fwrite (temp, sizeof(user), 1, profiles);

                            fclose(profiles);
                        }
                        else {
                            red();
                            printf("ERROR: Could not access profiles. Please try again later.");
                            reset();
                        }

                        mainMenu(User);
                        return;
                    }

                    if (attempts > 1) {
                        red();
                        printf("ERROR: Wrong password!!\nForgot password (Y/N)? ");
                        reset();
                        ch = getche();

                        if (toupper(ch) == 'Y') {
                            char temp_id[11];

                            while (1) {
                                printf("\nPlease enter your ID to validate your identity: ");
                                gets(temp_id);

                                if (!strcmp(temp_id, User->id)) {
                                    changePass(User);
                                    attempts = 0;
                                    break;
                                }

                                printf("ID does not match!!\n");
                            }
                        }
                    }
                    else {
                        red();
                        printf("\nERROR: Wrong password!! Please try agin.");
                        reset();
                    }
                    
                    attempts++;
                }
            }
            else if (!User->next) {
                printf("Username you entered wasn't found.\n");
                printf("Do you want to sign up (Y/N)?\n");

                // Checks if user wants to sign up or not
                if (toupper(getche()) == 'Y') {
                    system("cls"); // Clear screen for better ui
                    signUp();
                }
                else {
                    system("cls"); // Clear screen for better ui
                    printf("Username: ");
                    gets(username);
                    User = start_user;
                }
            }
            else
                User = User->next;
        }
    }
}

// Function to read user profiles
int readProfiles()
{
    FILE *profiles, *number;
    int users, garbage;
    char usernames[20];

    // Open the profiles file in binary read mode
    profiles = fopen("profiles.hex", "rb");
    
    // Open the file containing the number of users
    number = fopen("number_of_users.txt", "r");

    // Check if both files are successfully opened
    if (profiles && number) {
        // Read the number of users from the file
        fscanf(number, "%d\n", &users);

        // Seek through the file to extract user information
        while (users) {
            User = malloc(sizeof(user));

            // Check if memory allocation was successful
            if (User) {
                // Read user information from the profiles file
                fread(User, sizeof(user), 1, profiles);

                while (!feof(number)) {
                    fscanf(number, "%s\n", usernames);
                    if (!strcmp(User->username, usernames)) {
                        // Check if the linked list is empty
                        if (start_user == NULL) {
                            start_user = User;
                            end_user = User;
                            end_user->next = NULL;
                        }
                        else {
                            end_user->next = User;
                            end_user = User;
                            end_user->next = NULL;
                        }

                        users--;
                    }
                }

                rewind(number);
                fscanf(number, "%d\n", &garbage);
            }
            else {
                // Display an error message if memory allocation fails
                red();
                printf("ERROR: Your computer is low on memory.");
                getch(); // Wait for a key press before clearing the screen
                reset();
                return 1; // Return 1 to indicate an error
            }
        }

        // Close both files
        fclose(profiles);
        fclose(number);

        return 0; // Return 0 to indicate success
    }
    else {
        // Display an error message if file opening fails
        red();
        printf("ERROR: Could not access profiles. Please try again later.");
        getch();
        reset();
        return 1; // Return 1 to indicate an error
    }
}

// Main menu function to display options for user interaction
void mainMenu(user *a)
{
    int choice;

    // Infinite loop for continuous menu display
    while (1) {
        // Display welcome message with user's name
        printf("%40s--== Welcome back %s %s ==--\n\n", " ", a->name, a->family);
        printf("What do you want to do?\n\n");

        // Display menu options
        printf("1. Register New Estate\n");
        printf("2. Delete Estate\n");
        printf("3. Reports\n");
        printf("4. Account Settings\n");
        printf("5. Log Out\n");
        printf("6. Exit App\n\n");

        // Prompt user to choose an action
        printf("Choose an action from above menu: ");
        scanf("%d", &choice);
        getchar(); // Avoid extra enter
        system("cls"); // Clear screen for better UI

        // Switch case to execute selected action
        switch (choice) {
            case 1:
                Register(a);
                break;
            
            case 2:
                Delete();
                break;
            
            case 3:
                report(a);
                break;
            
            case 4:
                settings(a);
                break;
            
            case 5:
                return; // Return to caller function
                break;
            
            case 6:
                freeUsers(); // Free allocated memory for users
                exit(0); // Exit the application
                break;
            
            default:
                red();
                printf("ERROR: Invalid input.\n");
                reset();
                break;
        }
    }
}

void freeUsers()
{
    User = start_user;
    while (User) {
        temp = User->next;
        free(User);
        User = temp;
    }
}

void freeEstates()
{
    for (Sale_house = start_sale_house; Sale_house; Sale_house = temp_sale_house) {
        temp_sale_house = Sale_house->next;
        free(Sale_house);
    }

    for (Sale_office = start_sale_office; Sale_office; Sale_office = temp_sale_office) {
        temp_sale_office = Sale_office->next;
        free(Sale_office);
    }

    for (Sale_land = start_sale_land; Sale_land; Sale_land = temp_sale_land) {
        temp_sale_land = Sale_land->next;
        free(Sale_land);
    }

    for (Rent_house = start_rent_house; Rent_house; Rent_house = temp_rent_house) {
        temp_rent_house = Rent_house->next;
        free(Rent_house);
    }

    for (Rent_office = start_rent_office; Rent_office; Rent_office = temp_rent_office) {
        temp_rent_office = Rent_office->next;
        free(Rent_office);
    }

    for (Rent_land = start_rent_land; Rent_land; Rent_land = temp_rent_land) {
        temp_rent_land = Rent_land->next;
        free(Rent_land);
    }
}

void Delete()
{
    int choice;

    while (1) {
        printf("%53s--== Delete ==--\n\n", " ");

        // Promote menu of deletion
        printf("What do you want to delete?\n\n");

        printf("1. Sales estate\n");
        printf("2. Rent estate\n");
        printf("3. Return back\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        system("cls"); // Clear screen for better ui

        switch (choice)
        {
        case 1:
            deleteSale();
            break;
        
        case 2:
            deleteRent();
            break;
        
        case 3:
            freeEstates();
            return;
            break;
        
        default:
            red();
            printf("ERROR: Invalid input.\n");
            reset();
            break;
        }
    }
}

void deleteSale()
{
    int choice;

    if (readSales())
        return;

    printf("What do you want to delete?\n\n");

    printf("1. Residential property (for live)\n");
    printf("2. Office property (for work)\n");
    printf("3. Land property\n");
    printf("4. Return back\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Avoid exta enter
    system("cls"); // Clear screen for better ui

    switch (choice)
    {
    case 1:
        DeleteSale("house");
        break;
        
    case 2:
        DeleteSale("office");
        break;
        
    case 3:
        DeleteSale("land");
        break;

    case 4:
        return;
        break;
        
    default:
        red();
        printf("ERROR: Invalid input.\n");
        reset();
        break;
    }
}

void DeleteSale(char *type)
{
    char temp_address[500];
    time_t t;
    struct tm *local;

    for (Sale_house = start_sale_house; Sale_house; Sale_house = Sale_house->next) {
        puts(Sale_house->address);
    }

    printf("Enter the address of property you want to delete: ");
    gets(temp_address);

    if (!strcmp(type, "house")) {
        Sale_house = start_sale_house;
        while (Sale_house) {
            if (!strcmp(Sale_house->address, temp_address)) {
                t = time(NULL);
                local = localtime(&t);
                sprintf(Sale_house->deleteDate, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);
                break;
            }

            Sale_house = Sale_house->next;
        }

        FILE *houses = fopen("houses_sale.hex", "wb");

        if (houses) {
            for (Sale_house = start_sale_house; Sale_house; Sale_house = Sale_house->next)
                fwrite (Sale_house, sizeof(sale_house), 1, houses);

            fclose(houses);
        }
        else {
            red();
            printf("ERROR: Could not access houses. Please try again later.");
            reset();
        }
    }
    else if (!strcmp(type, "office")) {
        Sale_office = start_sale_office;
        while (Sale_office) {
            if (!strcmp(Sale_office->address, temp_address)){
                t = time(NULL);
                local = localtime(&t);
                sprintf(Sale_office->deleteDate, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);
                break;
            }

            Sale_office = Sale_office->next;
        }

        FILE *offices = fopen("offices_sale.hex", "wb");

        if (offices) {
            for (Sale_office = start_sale_office; Sale_office; Sale_office = Sale_office->next)
                fwrite (Sale_office, sizeof(sale_office), 1, offices);

            fclose(offices);
        }
        else
            printf("ERROR: Could not access offices. Please try again later.");
    }
    else {
        Sale_land = start_sale_land;
        while (Sale_land) {
            if (!strcmp(Sale_land->address, temp_address)){
                t = time(NULL);
                local = localtime(&t);
                sprintf(Sale_land->deleteDate, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);
                break;
            }

            Sale_land = Sale_land->next;
        }

        FILE *lands = fopen("lands_sale.hex", "wb");

        if (lands) {
            for (Sale_land = start_sale_land; Sale_land; Sale_land = Sale_land->next)
                fwrite (Sale_land, sizeof(sale_land), 1, lands);

            fclose(lands);
        }
        else
            printf("ERROR: Could not access lands. Please try again later.");
    }

    green();
    printf("Dedicated estate have been deleted successfully.\n");
    getch();
    reset();
}

void deleteRent()
{
    int choice;

    if (readRents())
        return;

    printf("What do you want to delete?\n\n");

    printf("1. Residential property (for live)\n");
    printf("2. Office property (for work)\n");
    printf("3. Land property\n");
    printf("4. Return back\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Avoid exta enter
    system("cls"); // Clear screen for better ui

    switch (choice)
    {
    case 1:
        DeleteRent("house");
        break;
        
    case 2:
        DeleteRent("office");
        break;
        
    case 3:
        DeleteRent("land");
        break;

    case 4:
        return;
        break;
        
    default:
        red();
        printf("ERROR: Invalid input.\n");
        reset();
        break;
    }
}

void DeleteRent(char *type)
{
    char temp_address[500];
    time_t t;
    struct tm *local;

    printf("Enter the address of property you want to delete: ");
    gets(temp_address);

    if (!strcmp(type, "house")) {
        Rent_house = start_rent_house;
        while (Rent_house) {
            if (!strcmp(Rent_house->address, temp_address)){
                t = time(NULL);
                local = localtime(&t);
                sprintf(Rent_house->deleteDate, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);
                break;
            }

            Rent_house = Rent_house->next;
        }

        FILE *houses = fopen("houses_rent.hex", "wb");

        if (houses) {
            for (Rent_house = start_rent_house; Rent_house; Rent_house = Rent_house->next)
                fwrite (Rent_house, sizeof(rent_house), 1, houses);

            fclose(houses);
        }
        else
            printf("ERROR: Could not access houses. Please try again later.");
    }
    else if (!strcmp(type, "office")) {
        Rent_office = start_rent_office;
        while (Rent_office) {
            if (!strcmp(Rent_office->address, temp_address)){
                t = time(NULL);
                local = localtime(&t);
                sprintf(Rent_office->deleteDate, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);
                break;
            }

            Rent_office = Rent_office->next;
        }

        FILE *offices = fopen("offices_rent.hex", "wb");

        if (offices) {
            for (Rent_office = start_rent_office; Rent_office; Rent_office = Rent_office->next)
                fwrite (Rent_office, sizeof(rent_office), 1, offices);

            fclose(offices);
        }
        else
            printf("ERROR: Could not access offices. Please try again later.");
    }
    else {
        Rent_land = start_rent_land;
        while (Rent_land) {
            if (!strcmp(Rent_land->address, temp_address)){
                t = time(NULL);
                local = localtime(&t);
                sprintf(Rent_land->deleteDate, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);
                break;
            }

            Rent_land = Rent_land->next;
        }

        FILE *lands = fopen("lands_rent.hex", "wb");

        if (lands) {
            for (Rent_land = start_rent_land; Rent_land; Rent_land = Rent_land->next)
                fwrite (Rent_land, sizeof(rent_land), 1, lands);

            fclose(lands);
        }
        else
            printf("ERROR: Could not access lands. Please try again later.");
    }

    green();
    printf("Dedicated estate have been deleted successfully.\n");
    getch();
    reset();
}

void Register(user *a)
{
    char choice;

    while (1) {
        printf("%50s--== Registration ==--\n\n", " ");

        printf("What do you want to register?\n\n");

        printf("1. Sales registration\n");
        printf("2. Rent registration\n");
        printf("3. Return back\n\n");

        printf("Enter your choice: ");
        choice = getchar();
        getchar(); // Avoid exta enter
        system("cls"); // Clear screen for better ui

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
            red();
            printf("ERROR: Invalid input.\n");
            reset();
            break;
        }
    }
}

void settings(user *a)
{
    int choice;

    printf("%46s--== Settings ==--\n\n", " ");

    printf("1. Rerun back\n");
    printf("2. Change password\n");
    printf("3. Change email\n");
    printf("4. Change phone number\n");

    if (strcmp(a->username, admin->username))
        printf("5. Enable\\Disable 2-step verification\n\n");

    printf("Choose an action from above menu: ");
    scanf("%d", &choice);
    getchar();
    system("cls"); // Clear screen for better ui

    if (choice > 4 && !strcmp(admin->username, a->username)) {
        red();
        printf("ERROR: Invalid input.\n");
        reset();
    }

    switch (choice)
    {
    case 1:
        return;
        break;

    case 2:
        changePass(a);
        break;
    
    case 3:
        changeEmail(a);
        break;
    
    case 4:
        changePhone(a);
        break;
    }

    if (strcmp(a->username, admin->username)) {
        switch (choice)
        {
        case 5:
            changeVerification(a);
            break;
    
        default:
            red();
            printf("ERROR: Invalid input.\n");
            reset();
            break;
    }
    }
}

void changePass(user *a)
{
    char temp_pass1[20], temp_pass2[20];
    FILE *profiles;

    while (1) {
        while (1) {
            printf("New Password: ");
            takePass(temp_pass1);

            if (strcmp(temp_pass1, a->password)) {
                if (validPass(temp_pass1, strlen(temp_pass1)))
                    break;
                else {
                    printf("\n\nPassword must have below conditions:\n\n");

                    printf("1. More than 8 characters.\n");
                    printf("2. Atleast one capital letter, one lowercase letter and one special character.\n");
                    printf("3. No spaces!!\n\n");
                }
            }
            else
                printf("\nNew password cannot be as last one!!!\n\n");
        }

        printf("\nConfirm Your Password: ");
        takePass(temp_pass2);
        printf("\n");

        // If two passwords are same, save it and break
        if (!strcmp(temp_pass1, temp_pass2)) {
            strcpy(a->password, temp_pass1);
            break;
        }

        printf("\nPasswords don't match.\n\n");
    }

    profiles = fopen("profiles.hex", "wb");

    if (profiles) {
        for (temp = start_user; temp; temp = temp->next)
            fwrite (temp, sizeof(user), 1, profiles);

        green();
        printf("\nYour password have been changed successfully...");
        getch();
        reset();
        system("cls"); // Clear screen for better ui

        fclose(profiles);
    }
    else
        printf("ERROR: Could not access profiles. Please try again later.");
}

void changeEmail(user *a) 
{
    char temp_email[50];
    FILE *profiles;

    while (1) {
        printf("New email: ");
        gets(temp_email);

        if (validEmail(temp_email)) {
            strcpy(a->email, temp_email);
            break;
        }

        printf("\nNew email cannot be as last one!!\n\n");
    }

    profiles = fopen("profiles.hex", "wb");

    if (profiles) {
        for (temp = start_user; temp; temp = temp->next)
            fwrite (temp, sizeof(user), 1, profiles);

        green();
        printf("\nYour email have been changed successfully...");
        getch();
        reset();
        system("cls"); // Clear screen for better ui

        fclose(profiles);
    }
    else
        printf("ERROR: Could not access profiles. Please try again later.");
}

void changePhone(user *a)
{
    char temp_phone[12];
    FILE *profiles;

    while (1) {
        printf("New phone number: ");
        gets(temp_phone);

        if (validPhone(temp_phone)) {
            strcpy(a->phone_no, temp_phone);
            break;
        }

        printf("\nNew phone number cannot be as last one, or is taken by another user.\n\n");
    }

    profiles = fopen("profiles.hex", "wb");

    if (profiles) {
        for (temp = start_user; temp; temp = temp->next)
            fwrite (temp, sizeof(user), 1, profiles);

        green();
        printf("\nYour phone number have been changed successfully...");
        getch();
        reset();
        system("cls"); // Clear screen for better ui

        fclose(profiles);
    }
    else
        printf("ERROR: Could not access profiles. Please try again later.");
}

void changeVerification(user *a)
{
    char temp_verification[50], choice;
    FILE *profiles;

    if (a->two_step_verification == '0') {
        printf("For enabling 2-step verification choose a method first\n\n");

        printf("\n1. National ID\n");
        printf("2. Phone Number\n");
        printf("3. Email\n");
                
        while (1) {
            printf("\nWhat do you want to be your identity validator: ");
            scanf("%c", &choice);
            getchar();

            switch (choice)
            {
            case '1':
                do {
                    printf("\nPlease enter your national ID for 2-step verification: ");
                    gets(temp_verification);

                    if (!strcmp(temp_verification, a->id))
                        break;
                                
                    printf("\nNational ID does not match!!!\n");
                } while (1);

                break;
                        
            case '2':
                do {
                    printf("\nPlease enter your phone number for 2-step verification: ");
                    gets(temp_verification);

                    if (!strcmp(temp_verification, a->phone_no))
                        break;
                                
                    printf("\nPhone number does not match!!!\n");
                } while (1);

                break;
                        
            case '3':
                do {
                    printf("\nPlease enter your email for 2-step verification: ");
                    gets(temp_verification);

                    if (!strcmp(temp_verification, a->email))
                        break;
                            
                    printf("\nEmail does not match!!!\n");
                } while (1);

                break;
                        
            default:
                red();
                printf("ERROR: Invalid input.\n");
                reset();
                break;
            }

            if (isdigit(choice) && choice < '3')
                a->two_step_verification = choice;
                break;
        }
    }
    else {
        printf("\n0. Disable 2-step verification\n");
        printf("1. National ID\n");
        printf("2. Phone Number\n");
        printf("3. Email\n");
                
        while (1) {
            printf("\nWhat do you want to be your identity validator: ");
            scanf("%c", &choice);
            getchar();

            switch (choice)
            {
            case '0':
                break;
            
            case '1':
                do {
                    printf("\nPlease enter your national ID for 2-step verification: ");
                    gets(temp_verification);

                    if (!strcmp(temp_verification, a->id))
                        break;
                                
                    printf("\nNational ID does not match!!!\n");
                } while (1);

                break;
                        
            case '2':
                do {
                    printf("\nPlease enter your phone number for 2-step verification: ");
                    gets(temp_verification);

                    if (!strcmp(temp_verification, a->phone_no))
                        break;
                                
                    printf("\nPhone number does not match!!!\n");
                } while (1);

                break;
                        
            case '3':
                do {
                    printf("\nPlease enter your email for 2-step verification: ");
                    gets(temp_verification);

                    if (!strcmp(temp_verification, a->email))
                        break;
                            
                    printf("\nEmail does not match!!!\n");
                } while (1);

                break;
                        
            default:
                red();
                printf("ERROR: Invalid input.\n");
                reset();
                break;
            }

            if (isdigit(choice) && choice < '3')
                a->two_step_verification = choice;
                break;
        }
    }

    profiles = fopen("profiles.hex", "wb");

    if (profiles) {
        for (temp = start_user; temp; temp = temp->next)
            fwrite (temp, sizeof(user), 1, profiles);

        printf("\nYour 2-step verification have been changed successfully...");
        getch();
        system("cls"); // Clear screen for better ui

        fclose(profiles);
    }
    else
        printf("ERROR: Could not access profiles. Please try again later.");
}

void report(user *a)
{
    if (readRents() || readSales())
        return;

    int choice, i = 1;

    while (1) {
        printf("%50s--== Reports ==--\n", " ");

        printf("What do you want to do %s %s?\n\n", a->name, a->family);

        printf("%2d. return back\n", i++);
        printf("%2d. Count of Estates in system\n", i++);
        printf("%2d. Estates in system by municipality area\n", i++);
        printf("%2d. Estates in system by age range\n", i++);
        printf("%2d. Estates in system by infrastructure range (house area)\n", i++);
        printf("%2d. Estates in system by specific total price range\n", i++);
        printf("%2d. Estates in system by specific meter price range\n", i++);
        printf("%2d. Houses in system by number of rooms\n", i++);
        printf("%2d. Estates in system by mortgage and rent range\n", i++);
        printf("%2d. Apartments in system by floor\n", i++);

        if (!strcmp(a->username, admin->username)) {
            printf("%2d. Total value of Estates\n", i++);
            printf("%2d. All users in sort of estate registration\n", i++);
            printf("%2d. Estates in system by registration date\n", i++);
            printf("%2d. Deleted estates by period of time\n", i++);
            printf("%2d. All users and their last activity\n", i++);
        }

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Avoid exta enter
        system("cls"); // Clear screen for better ui

        if (choice > 10 && strcmp(admin->username, a->username)) {
            red();
            printf("ERROR: Invalid input.\n");
            reset();
        }

        switch (choice)
        {
        case 1:
            return;
            break;

        case 2:
            countReport();
            break;
            
        case 3:
            municipalityArea();
            break;
            
        case 4:
            ageEstate();
            break;
            
        case 5:
            infrastructureEstate();
            break;
            
        case 6:
            totalPriceEstate();
            break;
            
        case 7:
            meterPriceEstate();
            break;
            
        case 8:
            roomsEstate();
            break;
            
        case 9:
            RentEstate();
            break;
            
        case 10:
            floorEstate();
            break;
        }

        if (!strcmp(admin->username, a->username)) {
            switch (choice)
            {
            case 11:
                valueEstate();
                break;
            
            case 12:
                userSortRegister();
                break;
            
            case 13:
                dateEstate();
                break;

            case 14:
                DeleteEstate();
                break;

            case 15:
                userActivity();
                break;
            
            default:
                red();
                printf("ERROR: Invalid input.\n");
                reset();
                break;
            }
        }

        i = 1;
    }
}

void countReport()
{
    int sale_house = 0, sale_office = 0, sale_land = 0, rent_house = 0, rent_office = 0, rent_land = 0;

    Sale_house = start_sale_house;
    while (Sale_house) {
        if (!strcmp(Sale_house->deleteDate, "0"))
            sale_house++;

        Sale_house = Sale_house->next;
    }
            
    Sale_office = start_sale_office;
    while (Sale_office) {
        if (!strcmp(Sale_office->deleteDate, "0"))
            sale_office++;

        Sale_office = Sale_office->next;
    }

    Sale_land = start_sale_land;
    while (Sale_land) {
        if (!strcmp(Sale_land->deleteDate, "0"))
            sale_land++;

        Sale_land = Sale_land->next;
    }

    Rent_house = start_rent_house;
    while (Rent_house) {
        if (!strcmp(Rent_house->deleteDate, "0"))
            rent_house++;

        Rent_house = Rent_house->next;
    }

    Rent_office = start_rent_office;
    while (Rent_office) {
        if (!strcmp(Rent_office->deleteDate, "0"))
            rent_office++;

        Rent_office = Rent_office->next;
    }

    Rent_land = start_rent_land;
    while (Rent_land) {
        if (!strcmp(Rent_land->deleteDate, "0"))
            rent_land++;

        Rent_land = Rent_land->next;
    }

    printf("%43s--== Count of Estates ==--\n\n", " ");

    printf("    | %s | %s | %s | %s | %s | %s |\n", "Houses for sale", "Offices for sale", "Lands for sale",
                                                "Houses for rent", "Offices for rent", "Lands for rent");
    printf("    |-----------------|------------------|----------------|-----------------|------------------|----------------|\n");
    printf("    | %8d%7s | %8d%8s | %7d%7s | %8d%7s | %8d%8s | %7d%7s |\n", sale_house, " ", sale_office, " ", sale_land, " ",
                                                                      rent_house, " ", rent_office, " ", rent_land, " ");
    getch();
    system("cls"); // Clear screen for better ui
}

void userActivity()
{
    printf("%70sUsers and their last activity\n\n", " ");

    printf("| %25s%16s | %6s     |%s | %27s%22s | %14s       | %s |\n", "Full Name", " ", "ID", "Phone number", "email", " ", "username", "Last activity");
    printf("|-------------------------------------------|------------|-------------|---------------------------------------------------|----------------------|---------------|\n");

    temp = start_user;
    while (temp) {
        printf("| %s %-*s | %s | %s | %-49s | %-20s |  %9s    |\n", temp->name, 40-strlen(temp->name), temp->family, temp->id, temp->phone_no, temp->email, temp->username, temp->last_activity);

        temp = temp->next;
    }

    printf("\nPress any key to go back to reports menu...");
    getch();
    system("cls"); // Clear screen for better ui
}

void updateUserEstate(user *a)
{
    FILE *profiles;
    int estates;

    profiles = fopen("profiles.hex", "rb+");

    if (profiles) {
        while (!feof(profiles)) {
            temp = malloc(sizeof(user));

            if (temp) {
                fread(temp, sizeof(user), 1, profiles);

                if (!strcmp(temp->username, a->username)) {
                    estates = atoi(temp->estates);
                    estates++;
                    sprintf(temp->estates, "%d", estates);

                    fseek(profiles, -sizeof(user), SEEK_CUR);
                    fwrite(temp, sizeof(user), 1, profiles);
                    free(temp);
                    break;
                }

                free(temp);
            }
            else {
                printf("ERROR: Your computer is low on memory.");
                getch();
                return;
            }
        }

        fclose(profiles);
    }
    else {
        printf("ERROR: Could not access profiles. Please try again later.");
        getch(); // Wait for a key press before clearing screen
        return;
    }

}

void userSortRegister()
{
    FILE *number;
    int users;

    number = fopen("number_of_users.txt", "r");

    if (number)
        fscanf(number, "%d", &users); 
    else
        printf("ERROR: Could not access profiles. Please try again later.");

    bubbleSort(&start_user, users);

    printf("%65sUsers in sort of estate registration\n\n", " ");

    printf("| %25s%16s | %6s     |%s | %27s%22s | %14s       | %s |\n", "Full Name", " ", "ID", "Phone number", "email", " ", "username", "number of registered estates");
    printf("|-------------------------------------------|------------|-------------|---------------------------------------------------|----------------------|------------------------------|\n");

    temp = start_user;
    while (temp) {
        printf("| %s %-*s | %s | %s | %-49s | %-20s |  %*s%*s |\n", temp->name, 40-strlen(temp->name), temp->family, temp->id, temp->phone_no, temp->email, temp->username, 13 - strlen(temp->estates)/2, temp->estates, 14 - strlen(temp->estates)/2, " ");

        temp = temp->next;
    }

    printf("\nPress any key to go back to reports menu...");
    getch();
    system("cls"); // Clear screen for better ui
}

user *swap(user *usr1, user *usr2)
{
    temp = usr2->next;
    usr2->next = usr1;
    usr1->next = temp;

    return usr2;
}
 
// Function to sort the linked list 
void bubbleSort(user **head, int count)
{
    user **current;
    int checker = 0;
 
    for (int i = 0; i <= count; i++) { 
        current = head;
 
        for (int j = 0; j < count - i - 1; j++) {
            user *user1 = *current;
            user *user2 = user1->next;
 
            if (atoi(user1->estates) < atoi(user2->estates)) {
                // update the link after swapping
                *current = swap(user1, user2);
                checker = 0;
            }
 
            current = &((*current)->next);
        }

        if (checker)
            break;
    }
}

// Function to take password from input
void takePass(char *password)
{
    int index = 0;
    char ch;

    // Loop until user press enter
    do {
        ch = getch();

        if (ch == 13)
            break;
        // If user press backspace key, remove last character
        else if (ch == 8) {
            printf("\b \b");
            index--;
            continue;
        }

        putchar('*'); // display * instead of password for better security
        password[index++] = ch;
    } while (1);

    password[index] = '\0'; // Initialize the last character to \0 manually
}

void red ()
{
    printf("\033[1;31m");
}

void green()
{
    printf("\033[0;32m");
}

void reset ()
{
    printf("\033[0;36m");
}

static char parking[4], warehouse[4], elevator[4], telephone[4];

void municipalityArea()
{
    char area[3];

    printf("Enter dedicated municipality area: ");
    gets(area);
    system("cls"); // Clear screen for better ui

    printf("%38sHouses for sale in municipality area %s\n\n", " ", area);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|---------|-----------|----------|-----------|\n");

    Sale_house = start_sale_house;
    while (Sale_house) {
        if (!strcmp(area, Sale_house->area) && !strcmp(Sale_house->deleteDate, "0")) {
            if (Sale_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Sale_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Sale_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Sale_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s | %-7s | %-9s | %-8s | %-9s |\n", Sale_house->type, Sale_house->age, Sale_house->infrastructure,
                                                                                        Sale_house->floor, Sale_house->land, Sale_house->owner_phone_no, Sale_house->rooms,
                                                                                        Sale_house->price, Sale_house->tot_price, parking, warehouse, elevator, telephone);
        }

        Sale_house = Sale_house->next;
    }

    printf("\n%38sOffices for sale in municipality area %s\n\n", " ", area);

    printf("| %11s       | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price");
    printf("|-------------------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|\n");
            
    Sale_office = start_sale_office;
    while (Sale_office) {
        if (!strcmp(area, Sale_office->area) && !strcmp(Sale_office->deleteDate, "0"))
            printf("| %-17s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s |\n", Sale_office->type, Sale_office->age, Sale_office->infrastructure,
                                                                                        Sale_office->floor, Sale_office->land, Sale_office->owner_phone_no, Sale_office->rooms,
                                                                                        Sale_office->price, Sale_office->tot_price);
        Sale_office = Sale_office->next;
    }

    printf("\n%40sLands for sale in municipality area %s\n\n", " ", area);

    printf("%10s | %6s  | %s | %s | %s | %s |\n", " ", "Type", "Base area", "Owner phone number", "Price per meter", "Total price");
    printf("%10s |---------|-----------|--------------------|-----------------|-------------|\n", " ");

    Sale_land = start_sale_land;
    while (Sale_land) {
        if (!strcmp(area, Sale_land->area) && !strcmp(Sale_land->deleteDate, "0"))
            printf("%10s | %-7s | %-9s | %-18s | %-15s | %-11s |\n", " ", Sale_land->type, Sale_land->land, Sale_land->owner_phone_no, Sale_land->price, Sale_land->tot_price);

        Sale_land = Sale_land->next;
    }

    printf("\n%38sHouses for Rent in municipality area %s\n\n", " ", area);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %-9s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|---------|-----------|----------|-----------|\n");

    Rent_house = start_rent_house;
    while (Rent_house) {
        if (!strcmp(area, Rent_house->area) && !strcmp(Rent_house->deleteDate, "0")) {
            if (Rent_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Rent_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Rent_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Rent_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14.9s | %-9.9s | %-7s | %-9s | %-8s | %-9s |\n", Rent_house->type, Rent_house->age, Rent_house->infrastructure,
                                                                                        Rent_house->floor, Rent_house->land, Rent_house->owner_phone_no, Rent_house->rooms,
                                                                                        Rent_house->rent, Rent_house->mortgage, parking, warehouse, elevator, telephone);
        }

        Rent_house = Rent_house->next;
    }

    printf("\n%38sOffices for rent in municipality area %s\n\n", " ", area);

    printf("| %11s       | %s | %s | %s | %s | %s | %s | %s | %s  |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage");
    printf("|-------------------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|\n");

    Rent_office = start_rent_office;
    while (Rent_office) {
        if (!strcmp(area, Rent_office->area) && !strcmp(Rent_office->deleteDate, "0"))
            printf("| %-17s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14s | %-8.9s |\n", Rent_office->type, Rent_office->age, Rent_office->infrastructure,
                                                                                        Rent_office->floor, Rent_office->land, Rent_office->owner_phone_no, Rent_office->rooms,
                                                                                        Rent_office->rent, Rent_office->mortgage);
        Rent_office = Rent_office->next;
    }

    printf("\n%40sLands for rent in municipality area %s\n\n", " ", area);

    printf("%10s | %6s  | %s | %s | %s | %s |\n", " ", "Type", "Base area", "Owner phone number", "Rent per month", " Mortgage");
    printf("%10s |---------|-----------|--------------------|----------------|-----------|\n", " ");

    Rent_land = start_rent_land;
    while (Rent_land) {
        if (!strcmp(area, Rent_land->area) && !strcmp(Rent_land->deleteDate, "0"))
            printf("%10s | %-7s | %-9s | %-18s | %-14s | %-9s |\n", " ", Rent_land->type, Rent_land->land, Rent_land->owner_phone_no, Rent_land->rent, Rent_land->mortgage);

        Rent_land = Rent_land->next;
    }

    printf("\nPress any key to go back to reports menu...");
    getch();
    system("cls"); // Clear screen for better ui
}

void ageEstate()
{
    int from_age, to_age, temp;

    printf("Enter dedicated age range (n-m): ");
    scanf("%d%*c%d", &from_age, &to_age);
    getchar();

    if (to_age < from_age) {
        temp = to_age;
        to_age = from_age;
        from_age = temp;
    }

    system("cls"); // Clear screen for better ui

    printf("%38sHouses for sale in age rang from %d to %d\n\n", " ", from_age, to_age);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|---------|-----------|----------|-----------|\n");

    Sale_house = start_sale_house;
    while (Sale_house) {
        if (atoi(Sale_house->age) <= to_age && atoi(Sale_house->age) >= from_age && !strcmp(Sale_house->deleteDate, "0")) {
            if (Sale_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Sale_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Sale_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Sale_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s | %-7s | %-9s | %-8s | %-9s |\n", Sale_house->type, Sale_house->age, Sale_house->infrastructure,
                                                                                        Sale_house->floor, Sale_house->land, Sale_house->owner_phone_no, Sale_house->rooms,
                                                                                        Sale_house->price, Sale_house->tot_price, parking, warehouse, elevator, telephone);
        }

        Sale_house = Sale_house->next;
    }

    printf("\n%38sOffices for sale in age rang from %d to %d\n\n", " ", from_age, to_age);

    printf("| %11s       | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price");
    printf("|-------------------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|\n");
            
    Sale_office = start_sale_office;
    while (Sale_office) {
        if (atoi(Sale_office->age) <= to_age && atoi(Sale_office->age) >= from_age && !strcmp(Sale_office->deleteDate, "0"))
            printf("| %-17s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s |\n", Sale_office->type, Sale_office->age, Sale_office->infrastructure,
                                                                                        Sale_office->floor, Sale_office->land, Sale_office->owner_phone_no, Sale_office->rooms,
                                                                                        Sale_office->price, Sale_office->tot_price);
        Sale_office = Sale_office->next;
    }

    printf("\n%38sHouses for Rent in age rang from %d to %d\n\n", " ", from_age, to_age);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %-9s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|---------|-----------|----------|-----------|\n");

    Rent_house = start_rent_house;
    while (Rent_house) {
        if (atoi(Rent_house->age) <= to_age && atoi(Rent_house->age) >= from_age && !strcmp(Rent_house->deleteDate, "0")) {
            if (Rent_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Rent_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Rent_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Rent_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14.9s | %-9.9s | %-7s | %-9s | %-8s | %-9s |\n", Rent_house->type, Rent_house->age, Rent_house->infrastructure,
                                                                                        Rent_house->floor, Rent_house->land, Rent_house->owner_phone_no, Rent_house->rooms,
                                                                                        Rent_house->rent, Rent_house->mortgage, parking, warehouse, elevator, telephone);
        }

        Rent_house = Rent_house->next;
    }

    printf("\n%38sOffices for rent in age rang from %d to %d\n\n", " ", from_age, to_age);

    printf("| %11s       | %s | %s | %s | %s | %s | %s | %s | %s  |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage");
    printf("|-------------------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|\n");

    Rent_office = start_rent_office;
    while (Rent_office) {
        if (atoi(Rent_office->age) <= to_age && atoi(Rent_office->age) >= from_age && !strcmp(Rent_office->deleteDate, "0"))
            printf("| %-17s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14s | %-8.9s |\n", Rent_office->type, Rent_office->age, Rent_office->infrastructure,
                                                                                        Rent_office->floor, Rent_office->land, Rent_office->owner_phone_no, Rent_office->rooms,
                                                                                        Rent_office->rent, Rent_office->mortgage);
        Rent_office = Rent_office->next;
    }

    printf("\nPress any key to go back to reports menu...");
    getch();
    system("cls"); // Clear screen for better ui
}

void infrastructureEstate()
{
    int from_infrastructure, to_infrastructure, temp;

    printf("Enter dedicated infrastructure range (n-m): ");
    scanf("%d%*c%d", &from_infrastructure, &to_infrastructure);
    getchar();

    if (to_infrastructure < from_infrastructure) {
        temp = to_infrastructure;
        to_infrastructure = from_infrastructure;
        from_infrastructure = temp;
    }

    system("cls"); // Clear screen for better ui

    printf("%38sHouses for sale in infrastructure rang from %d to %d\n\n", " ", from_infrastructure, to_infrastructure);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|---------|-----------|----------|-----------|\n");

    Sale_house = start_sale_house;
    while (Sale_house) {
        if (atoi(Sale_house->infrastructure) <= to_infrastructure && atoi(Sale_house->infrastructure) >= from_infrastructure && !strcmp(Sale_house->deleteDate, "0")) {
            if (Sale_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Sale_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Sale_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Sale_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s | %-7s | %-9s | %-8s | %-9s |\n", Sale_house->type, Sale_house->age, Sale_house->infrastructure,
                                                                                        Sale_house->floor, Sale_house->land, Sale_house->owner_phone_no, Sale_house->rooms,
                                                                                        Sale_house->price, Sale_house->tot_price, parking, warehouse, elevator, telephone);
        }

        Sale_house = Sale_house->next;
    }

    printf("\n%38sOffices for sale in infrastructure rang from %d to %d\n\n", " ", from_infrastructure, to_infrastructure);

    printf("| %11s       | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price");
    printf("|-------------------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|\n");
            
    Sale_office = start_sale_office;
    while (Sale_office) {
        if (atoi(Sale_office->infrastructure) <= to_infrastructure && atoi(Sale_office->infrastructure) >= from_infrastructure && !strcmp(Sale_office->deleteDate, "0"))
            printf("| %-17s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s |\n", Sale_office->type, Sale_office->age, Sale_office->infrastructure,
                                                                                        Sale_office->floor, Sale_office->land, Sale_office->owner_phone_no, Sale_office->rooms,
                                                                                        Sale_office->price, Sale_office->tot_price);
        Sale_office = Sale_office->next;
    }

    printf("\n%38sHouses for Rent in infrastructure rang from %d to %d\n\n", " ", from_infrastructure, to_infrastructure);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %-9s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|---------|-----------|----------|-----------|\n");

    Rent_house = start_rent_house;
    while (Rent_house) {
        if (atoi(Rent_house->infrastructure) <= to_infrastructure && atoi(Rent_house->infrastructure) >= from_infrastructure && !strcmp(Rent_house->deleteDate, "0")) {
            if (Rent_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Rent_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Rent_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Rent_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14.9s | %-9.9s | %-7s | %-9s | %-8s | %-9s |\n", Rent_house->type, Rent_house->age, Rent_house->infrastructure,
                                                                                        Rent_house->floor, Rent_house->land, Rent_house->owner_phone_no, Rent_house->rooms,
                                                                                        Rent_house->rent, Rent_house->mortgage, parking, warehouse, elevator, telephone);
        }

        Rent_house = Rent_house->next;
    }

    printf("\n%38sOffices for rent in infrastructure rang from %d to %d\n\n", " ", from_infrastructure, to_infrastructure);

    printf("| %11s       | %s | %s | %s | %s | %s | %s | %s | %s  |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage");
    printf("|-------------------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|\n");

    Rent_office = start_rent_office;
    while (Rent_office) {
        if (atoi(Rent_office->infrastructure) <= to_infrastructure && atoi(Rent_office->infrastructure) >= from_infrastructure && !strcmp(Rent_office->deleteDate, "0"))
            printf("| %-17s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14s | %-8.9s |\n", Rent_office->type, Rent_office->age, Rent_office->infrastructure,
                                                                                        Rent_office->floor, Rent_office->land, Rent_office->owner_phone_no, Rent_office->rooms,
                                                                                        Rent_office->rent, Rent_office->mortgage);
        Rent_office = Rent_office->next;
    }

    printf("\nPress any key to go back to reports menu...");
    getch();
    system("cls"); // Clear screen for better ui
}

void totalPriceEstate()
{
    long long int from_price, to_price, temp;

    printf("Enter dedicated total price range (n-m): ");
    scanf("%lld%*c%lld", &from_price, &to_price);
    getchar();

    if (to_price < from_price) {
        temp = to_price;
        to_price = from_price;
        from_price = temp;
    }

    system("cls"); // Clear screen for better ui

    printf("%38sHouses for sale in total price rang from %lld to %lld\n\n", " ", from_price, to_price);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|---------|-----------|----------|-----------|\n");

    Sale_house = start_sale_house;
    while (Sale_house) {
        if (unitConverter(Sale_house->tot_price) <= to_price && unitConverter(Sale_house->tot_price) >= from_price && !strcmp(Sale_house->deleteDate, "0")) {
            if (Sale_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Sale_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Sale_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Sale_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s | %-7s | %-9s | %-8s | %-9s |\n", Sale_house->type, Sale_house->age, Sale_house->infrastructure,
                                                                                        Sale_house->floor, Sale_house->land, Sale_house->owner_phone_no, Sale_house->rooms,
                                                                                        Sale_house->price, Sale_house->tot_price, parking, warehouse, elevator, telephone);
        }

        Sale_house = Sale_house->next;
    }

    printf("\n%38sOffices for sale in total price rang from %lld to %lld\n\n", " ", from_price, to_price);

    printf("| %11s       | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price");
    printf("|-------------------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|\n");
            
    Sale_office = start_sale_office;
    while (Sale_office) {
        if (unitConverter(Sale_office->tot_price) <= to_price && unitConverter(Sale_office->tot_price) >= from_price && !strcmp(Sale_office->deleteDate, "0"))
            printf("| %-17s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s |\n", Sale_office->type, Sale_office->age, Sale_office->infrastructure,
                                                                                        Sale_office->floor, Sale_office->land, Sale_office->owner_phone_no, Sale_office->rooms,
                                                                                        Sale_office->price, Sale_office->tot_price);
        Sale_office = Sale_office->next;
    }

    printf("\n%40sLands for sale in total price rang from %lld to %lld\n\n", " ", from_price, to_price);

    printf("%10s | %6s  | %s | %s | %s | %s |\n", " ", "Type", "Base area", "Owner phone number", "Price per meter", "Total price");
    printf("%10s |---------|-----------|--------------------|-----------------|-------------|\n", " ");

    Sale_land = start_sale_land;
    while (Sale_land) {
        if (unitConverter(Sale_land->tot_price) <= to_price && unitConverter(Sale_land->tot_price) >= from_price && !strcmp(Sale_land->deleteDate, "0"))
            printf("%10s | %-7s | %-9s | %-18s | %-15s | %-11s |\n", " ", Sale_land->type, Sale_land->land, Sale_land->owner_phone_no, Sale_land->price, Sale_land->tot_price);

        Sale_land = Sale_land->next;
    }

    printf("\nPress any key to go back to reports menu...");
    getch();
    system("cls"); // Clear screen for better ui
}

void meterPriceEstate()
{
    int from_price, to_price, temp;

    printf("Enter dedicated price per meter range (n-m): ");
    scanf("%d%*c%d", &from_price, &to_price);
    getchar();

    if (to_price < from_price) {
        temp = to_price;
        to_price = from_price;
        from_price = temp;
    }

    system("cls"); // Clear screen for better ui

    printf("%38sHouses for sale in price per meter rang from %d to %d\n\n", " ", from_price, to_price);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|---------|-----------|----------|-----------|\n");

    Sale_house = start_sale_house;
    while (Sale_house) {
        if (unitConverter(Sale_house->price) <= to_price && unitConverter(Sale_house->price) >= from_price && !strcmp(Sale_house->deleteDate, "0")) {
            if (Sale_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Sale_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Sale_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Sale_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s | %-7s | %-9s | %-8s | %-9s |\n", Sale_house->type, Sale_house->age, Sale_house->infrastructure,
                                                                                        Sale_house->floor, Sale_house->land, Sale_house->owner_phone_no, Sale_house->rooms,
                                                                                        Sale_house->price, Sale_house->tot_price, parking, warehouse, elevator, telephone);
        }

        Sale_house = Sale_house->next;
    }

    printf("\n%38sOffices for sale in price per meter rang from %d to %d\n\n", " ", from_price, to_price);

    printf("| %11s       | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price");
    printf("|-------------------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|\n");
            
    Sale_office = start_sale_office;
    while (Sale_office) {
        if (unitConverter(Sale_office->price) <= to_price && unitConverter(Sale_office->price) >= from_price && !strcmp(Sale_office->deleteDate, "0"))
            printf("| %-17s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s |\n", Sale_office->type, Sale_office->age, Sale_office->infrastructure,
                                                                                        Sale_office->floor, Sale_office->land, Sale_office->owner_phone_no, Sale_office->rooms,
                                                                                        Sale_office->price, Sale_office->tot_price);
        Sale_office = Sale_office->next;
    }

    printf("\n%40sLands for sale in price per meter rang from %d to %d\n\n", " ", from_price, to_price);

    printf("%10s | %6s  | %s | %s | %s | %s |\n", " ", "Type", "Base area", "Owner phone number", "Price per meter", "Total price");
    printf("%10s |---------|-----------|--------------------|-----------------|-------------|\n", " ");

    Sale_land = start_sale_land;
    while (Sale_land) {
        if (unitConverter(Sale_land->price) <= to_price && unitConverter(Sale_land->price) >= from_price && !strcmp(Sale_land->deleteDate, "0"))
            printf("%10s | %-7s | %-9s | %-18s | %-15s | %-11s |\n", " ", Sale_land->type, Sale_land->land, Sale_land->owner_phone_no, Sale_land->price, Sale_land->tot_price);

        Sale_land = Sale_land->next;
    }

    printf("\nPress any key to go back to reports menu...");
    getch();
    system("cls"); // Clear screen for better ui
}

void RentEstate()
{
    int from_mortgage, to_mortgage, from_rent, to_rent, temp;

    printf("Enter dedicated mortgage range (n-m): ");
    scanf("%d%*c%d", &from_mortgage, &to_mortgage);
    printf("Enter dedicated monthly rent range (n-m): ");
    scanf("%d%*c%d", &from_rent, &to_rent);
    getchar();

    if (from_mortgage > to_mortgage) {
        temp = to_mortgage;
        to_mortgage = from_mortgage;
        from_mortgage = temp;
    }

    if (from_rent > to_rent) {
        temp = to_rent;
        to_rent = from_rent;
        from_rent = temp;
    }

    system("cls"); // Clear screen for better ui
    
    printf("\n%38sHouses for Rent in mortgage range from %d to %d and monthly rent range from %d to %d\n\n", " ", from_mortgage, to_mortgage, from_rent, to_rent);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %-9s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|---------|-----------|----------|-----------|\n");

    Rent_house = start_rent_house;
    while (Rent_house) {
        if (unitConverter(Rent_house->mortgage) <= to_mortgage && unitConverter(Rent_house->mortgage) >= from_mortgage &&
            unitConverter(Rent_house->rent) <= to_rent && unitConverter(Rent_house->rent) >= from_rent && !strcmp(Rent_house->deleteDate, "0")) {
            if (Rent_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Rent_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Rent_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Rent_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14.9s | %-9.9s | %-7s | %-9s | %-8s | %-9s |\n", Rent_house->type, Rent_house->age, Rent_house->infrastructure,
                                                                                        Rent_house->floor, Rent_house->land, Rent_house->owner_phone_no, Rent_house->rooms,
                                                                                        Rent_house->rent, Rent_house->mortgage, parking, warehouse, elevator, telephone);
        }

        Rent_house = Rent_house->next;
    }

    printf("\n%38sOffices for rent in mortgage range from %d to %d and monthly rent range from %d to %d\n\n", " ", from_mortgage, to_mortgage, from_rent, to_rent);

    printf("| %11s       | %s | %s | %s | %s | %s | %s | %s | %s  |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage");
    printf("|-------------------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|\n");

    Rent_office = start_rent_office;
    while (Rent_office) {
        if (unitConverter(Rent_office->mortgage) <= to_mortgage && unitConverter(Rent_office->mortgage) >= from_mortgage &&
            unitConverter(Rent_office->rent) <= to_rent && unitConverter(Rent_office->rent) >= from_rent && !strcmp(Rent_office->deleteDate, "0"))
            printf("| %-17s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14s | %-8.9s |\n", Rent_office->type, Rent_office->age, Rent_office->infrastructure,
                                                                                        Rent_office->floor, Rent_office->land, Rent_office->owner_phone_no, Rent_office->rooms,
                                                                                        Rent_office->rent, Rent_office->mortgage);
        Rent_office = Rent_office->next;
    }

    printf("\n%40sLands for rent in mortgage range from %d to %d and monthly rent range from %d to %d\n\n", " ", from_mortgage, to_mortgage, from_rent, to_rent);

    printf("%10s | %6s  | %s | %s | %s | %s |\n", " ", "Type", "Base area", "Owner phone number", "Rent per month", " Mortgage");
    printf("%10s |---------|-----------|--------------------|----------------|-----------|\n", " ");

    Rent_land = start_rent_land;
    while (Rent_land) {
        if (unitConverter(Rent_land->mortgage) <= to_mortgage && unitConverter(Rent_land->mortgage) >= from_mortgage &&
            unitConverter(Rent_land->rent) <= to_rent && unitConverter(Rent_land->rent) >= from_rent && !strcmp(Rent_land->deleteDate, "0"))
            printf("%10s | %-7s | %-9s | %-18s | %-14s | %-9s |\n", " ", Rent_land->type, Rent_land->land, Rent_land->owner_phone_no, Rent_land->rent, Rent_land->mortgage);

        Rent_land = Rent_land->next;
    }

    printf("\nPress any key to go back to reports menu...");
    getch();
    system("cls"); // Clear screen for better ui
}

void floorEstate() 
{
    int floor;

    printf("Enter dedicated floor: ");
    scanf("%d", &floor);
    getchar();

    system("cls"); // Clear screen for better ui

    printf("%38sHouses for sale on %d floor\n\n", " ", floor);

    printf("| %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|---------|-----------|----------|-----------|\n");

    Sale_house = start_sale_house;
    while (Sale_house) {
        if (!strcmp(strlwr(Sale_house->type), "apartment") && !strcmp(Rent_house->deleteDate, "0")) {
            if (Sale_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Sale_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Sale_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Sale_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s | %-7s | %-9s | %-8s | %-9s |\n", Sale_house->age, Sale_house->infrastructure,
                                                                                        Sale_house->floor, Sale_house->land, Sale_house->owner_phone_no, Sale_house->rooms,
                                                                                        Sale_house->price, Sale_house->tot_price, parking, warehouse, elevator, telephone);
        }

        Sale_house = Sale_house->next;
    }

    printf("\n%38sHouses for Rent on %d floor\n\n", " ", floor);

    printf("| %s | %s | %s | %s | %s | %s | %s | %-9s | %s | %s | %s | %s |\n", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|---------|-----------|----------|-----------|\n");

    Rent_house = start_rent_house;
    while (Rent_house) {
        if (!strcmp(strlwr(Rent_house->type), "apartment") && !strcmp(Rent_house->deleteDate, "0")) {
            if (Rent_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Rent_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Rent_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Rent_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14.9s | %-9.9s | %-7s | %-9s | %-8s | %-9s |\n", Rent_house->age, Rent_house->infrastructure,
                                                                                        Rent_house->floor, Rent_house->land, Rent_house->owner_phone_no, Rent_house->rooms,
                                                                                        Rent_house->rent, Rent_house->mortgage, parking, warehouse, elevator, telephone);
        }

        Rent_house = Rent_house->next;
    }
}

void roomsEstate()
{
    int rooms;

    printf("Enter dedicated rooms number: ");
    scanf("%d", &rooms);
    system("cls"); // Clear screen for better ui

    printf("%73sHouses for sale with %d rooms\n\n", " ", rooms);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|---------|-----------|----------|-----------|\n");

    Sale_house = start_sale_house;
    while (Sale_house) {
        if (atoi(Sale_house->rooms) == rooms && !strcmp(Rent_house->deleteDate, "0")) {
            if (Sale_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Sale_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Sale_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Sale_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s | %-7s | %-9s | %-8s | %-9s |\n", Sale_house->type, Sale_house->age, Sale_house->infrastructure,
                                                                                        Sale_house->floor, Sale_house->land, Sale_house->owner_phone_no, Sale_house->rooms,
                                                                                        Sale_house->price, Sale_house->tot_price, parking, warehouse, elevator, telephone);
        }

        Sale_house = Sale_house->next;
    }

    printf("\n%73sHouses for Rent with %d rooms\n\n", " ", rooms);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %-9s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|---------|-----------|----------|-----------|\n");

    Rent_house = start_rent_house;
    while (Rent_house) {
        if (atoi(Rent_house->rooms) == rooms && !strcmp(Rent_house->deleteDate, "0")) {
            if (Rent_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Rent_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Rent_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Rent_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14.9s | %-9.9s | %-7s | %-9s | %-8s | %-9s |\n", Rent_house->type, Rent_house->age, Rent_house->infrastructure,
                                                                                        Rent_house->floor, Rent_house->land, Rent_house->owner_phone_no, Rent_house->rooms,
                                                                                        Rent_house->rent, Rent_house->mortgage, parking, warehouse, elevator, telephone);
        }

        Rent_house = Rent_house->next;
    }

    printf("\nPress any key to go back to reports menu...");
    getch();
    system("cls"); // Clear screen for better ui
}

int readSales()
{
    FILE *estate;

    if (Sale) {
        Sale = 0;
        estate = fopen("houses_sale.hex", "rb");

        if (estate) {
            while (!feof(estate)) {
                Sale_house = malloc(sizeof(sale_house));

                if (Sale_house) {
                    fread(Sale_house, sizeof(sale_house), 1, estate);
        
                    if (start_sale_house == NULL) {
                        start_sale_house =Sale_house;
                        end_sale_house = Sale_house;
                        Sale_house->next = NULL;
                    }
                    else {
                        end_sale_house->next = Sale_house;
                        end_sale_house = Sale_house;
                        Sale_house->next = NULL;
                    }
                }
                else {
                    printf("ERROR: Your computer is low on memory.");
                    getch();
                    return 1;
                }
            }
        }
        else {
            printf("ERROR: Could not access profiles. Please try again later.");
            getch();
            return 1;
        }

        estate = fopen("offices_sale.hex", "rb");

        if (estate) {
            while (!feof(estate)) {
                Sale_office = malloc(sizeof(sale_office));

                if (Sale_office) {
                    fread(Sale_office, sizeof(sale_office), 1, estate);

                    if (start_sale_office == NULL) {
                        start_sale_office = Sale_office;
                        end_sale_office = start_sale_office;
                        start_sale_office->next = NULL;
                    }
                    else {
                        end_sale_office->next = Sale_office;
                        end_sale_office = Sale_office;
                        Sale_office->next = NULL;
                    }
                }
                else {
                    printf("ERROR: Your computer is low on memory.");
                    getch();
                    return 1;
                }
            }
        }
        else {
            printf("ERROR: Could not access profiles. Please try again later.");
            getch();
            return 1;
        }
        
        estate = fopen("lands_sale.hex", "rb");

        if (estate) {
            while (!feof(estate)) {
                Sale_land = malloc(sizeof(sale_land));

                if (Sale_house) {
                    fread(Sale_land, sizeof(sale_land), 1, estate);

                    if (start_sale_land == NULL) {
                        start_sale_land = Sale_land;
                        end_sale_land = start_sale_land;
                        start_sale_land->next = NULL;
                    }
                    else {
                        end_sale_land->next = Sale_land;
                        end_sale_land = Sale_land;
                        end_sale_land->next = NULL;
                    }
                }
                else {
                    printf("ERROR: Your computer is low on memory.");
                    getch();
                    return 1;
                }
            }
        }
        else {
            printf("ERROR: Could not access profiles. Please try again later.");
            getch();
            return 1;
        }
    }

    return 0;
}

int readRents()
{
    FILE *estate;

    if (Rent) {
        Rent = 0;
        estate = fopen("houses_rent.hex", "rb");

        if (estate) {
            while (!feof(estate)) {
                Rent_house = malloc(sizeof(rent_house));

                if (Rent_house) {
                    fread(Rent_house, sizeof(rent_house), 1, estate);

                    if (start_rent_house == NULL) {
                        start_rent_house = Rent_house;
                        end_rent_house = Rent_house;
                        Rent_house->next = NULL;
                    }
                    else {
                        end_rent_house->next = Rent_house;
                        end_rent_house = Rent_house;
                        Rent_house->next = NULL;
                    }
                }
                else {
                    printf("ERROR: Your computer is low on memory.");
                    getch();
                    return 1;
                }
            }
        }
        else {
            printf("ERROR: Could not access profiles. Please try again later.");
            getch();
            return 1;
        }

        estate = fopen("offices_rent.hex", "rb");

        if (estate) {
            while (!feof(estate)) {
                Rent_office = malloc(sizeof(rent_office));

                if (Rent_office) {
                    fread(Rent_office, sizeof(rent_office), 1, estate);

                    if (start_rent_office == NULL) {
                        start_rent_office = Rent_office;
                        end_rent_office = start_rent_office;
                        start_rent_office->next = NULL;
                    }
                    else {
                        end_rent_office->next = Rent_office;
                        end_rent_office = Rent_office;
                        end_rent_office->next = NULL;
                    }
                }
                else {
                    printf("ERROR: Your computer is low on memory.");
                    getch();
                    return 1;
                }
            }
        }
        else {
            printf("ERROR: Could not access profiles. Please try again later.");
            getch();
            return 1;
        }
        
        estate = fopen("lands_rent.hex", "rb");

        if (estate) {
            while (!feof(estate)) {
                Rent_land = malloc(sizeof(rent_land));

                if (Rent_land) {
                    fread(Rent_land, sizeof(rent_land), 1, estate);

                    if (start_rent_land == NULL) {
                        start_rent_land = Rent_land;
                        end_rent_land = start_rent_land;
                        start_rent_land->next = NULL;
                    }
                    else {
                        end_rent_land->next = Rent_land;
                        end_rent_land = Rent_land;
                        end_rent_land->next = NULL;
                    }
                }
                else { 
                    printf("ERROR: Your computer is low on memory.");
                    getch();
                    return 1;
                }
            }
        }
        else {
            printf("ERROR: Could not access profiles. Please try again later.");
            getch();
            return 1;
        }
    }

    return 0;
}

void sale(user *a)
{
    int choice;

    printf("%45s--== Sale Registration ==--\n\n", " ");

    printf("What type of estate do you want to register?\n\n");

    printf("1. Residential property (for live)\n");
    printf("2. Office property (for work)\n");
    printf("3. Land property\n");
    printf("4. Return back\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Avoid exta enter
    system("cls"); // Clear screen for better ui

    switch (choice)
    {
    case 1:
        saleEstate(a, "house");
        break;
        
    case 2:
        saleEstate(a, "office");
        break;
        
    case 3:
        saleEstate(a, "land");
        break;

    case 4:
        return;
        break;
        
    default:
        red();
        printf("ERROR: Invalid input.\n");
        reset();
        break;
    }
}

void rent(user *a)
{
    int choice;

    printf("%45s--== Rent Registration ==--\n\n", " ");

    printf("What type of estate do you want to register?\n\n");

    printf("1. Residential property (for live)\n");
    printf("2. Office property (for work)\n");
    printf("3. Land property\n");
    printf("4. Return back\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Avoid exta enter
    system("cls"); // Clear screen for better ui

    switch (choice)
    {
    case 1:
        rentEstate(a, "house");
        break;
        
    case 2:
        rentEstate(a, "office");
        break;
        
    case 3:
        rentEstate(a, "land");
        break;

    case 4:
        return;
        break;
        
    default:
        red();
        printf("ERROR: Invalid input.\n");
        reset();
        break;
    }
}

int validID(char *id)
{
    if (strlen(id) != 10)
        return 0;

    for (int digit = 0; digit < 10; digit++)
        if (!isdigit(id[digit]))
            return 0;

    if (readProfiles())
        return 0;

    for (User = start_user; User; User = User->next)
        if (!strcmp(User->id, id))
            return 0;

    return 1;
}

int validPhone(char *phone)
{
    if (strlen(phone) != 11 || phone[0] != '0' || phone[1] != '9')
        return 0;

    for (int digit = 2; digit < 11; digit++)
        if (!isdigit(phone[digit]))
            return 0;

    for (User = start_user; User; User = User->next)
        if (!strcmp(User->phone_no, phone))
            return 0;

    return 1;
}

int availableUser(char *username)
{
    if (!strcmp(admin->username, username))
        return 0; // Username is taken

    for (User = start_user; User; User = User->next)
        if (!strcmp(User->username, username))
            return 0; // Username is taken

    return 1; // Username is not taken
}

int validPass(char *pass, int size)
{
    int cap = 0, low = 0, special = 0, space = 0, num = 0;

    if (size < 8)
        return 0;

    for (int ch = 0; ch < size; ch++) {
        if (islower(pass[ch]))
            low = 1;
        else if (isupper(pass[ch]))
            cap = 1;
        else if (ispunct(pass[ch]))
            special = 1;
        else if(isspace(pass[ch]))
            space = 1;
        else if (isdigit(pass[ch]))
            num = 1;
    }

    if (low == 1 && cap == 1 && special == 1 && num == 1 && space == 0)
        return 1;
    else
        return 0;
}

int validEmail(char *email)
{
    int adSign_count = 0, dot_count = 0;
    int adSign_index;

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@'){
            if (i == 0)
                return 0;
            else
                adSign_index = i;

            adSign_count++;
            if (adSign_count > 1)
                return 0;
        }
        else if (email[i] == '.') {
            if (email[i+1] == '\0')
                return 0;
            else
                dot_count++;
        }
    }

    if (adSign_count != 1 || dot_count <= 0)
        return 0;
    
    for (User = start_user; User; User = User->next)
        if (!strcmp(User->email, email))
            return 0;

    return 1;
}

int validName(char *name)
{
    for (int i = 0; name[i] != '\0'; i++)
        if (!isalpha(name[i]) && !isspace(name[i]))
            return 0;

    return 1;
}

static int from_year, from_month, from_day;
static int to_year, to_month, to_day;

void dateEstate()
{
    printf("Enter the start date (YY/MM/DD): ");
    scanf("%d%*c%d%*c%d", &from_year, &from_month, &from_day);

    printf("Enter the finish date (YY/MM/DD): ");
    scanf("%d%*c%d%*c%d", &to_year, &to_month, &to_day);

    printf("%63sHouses for sale between %d/%d/%d and %d/%d/%d\n\n", " ", from_year, from_month, from_day, to_year, to_month, to_day);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|---------|-----------|----------|-----------|\n");

    Sale_house = start_sale_house;
    while (Sale_house) {
        if (datecmp(Sale_house->date) && !strcmp(Sale_house->deleteDate, "0")) {
            if (Sale_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Sale_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Sale_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Sale_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s | %-7s | %-9s | %-8s | %-9s |\n", Sale_house->type, Sale_house->age, Sale_house->infrastructure,
                                                                                        Sale_house->floor, Sale_house->land, Sale_house->owner_phone_no, Sale_house->rooms,
                                                                                        Sale_house->price, Sale_house->tot_price, parking, warehouse, elevator, telephone);
        }

        Sale_house = Sale_house->next;
    }

    printf("\n%60sOffices for sale between %d/%d/%d and %d/%d/%d\n\n", " ", from_year, from_month, from_day, to_year, to_month, to_day);

    printf("%18s| %11s       | %s | %s | %s | %s | %s | %s | %s | %s |\n", " ", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price");
    printf("%18s|-------------------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|\n", " ");
            
    Sale_office = start_sale_office;
    while (Sale_office) {
        if (datecmp(Sale_office->date) && !strcmp(Sale_office->deleteDate, "0"))
            printf("%18s| %-17s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s |\n", " ", Sale_office->type, Sale_office->age, Sale_office->infrastructure,
                                                                                        Sale_office->floor, Sale_office->land, Sale_office->owner_phone_no, Sale_office->rooms,
                                                                                        Sale_office->price, Sale_office->tot_price);
        Sale_office = Sale_office->next;
    }

    printf("\n%40sLands for sale between %d/%d/%d and %d/%d/%d\n\n", " ", from_year, from_month, from_day, to_year, to_month, to_day);

    printf("%10s | %6s  | %s | %s | %s | %s |\n", " ", "Type", "Base area", "Owner phone number", "Price per meter", "Total price");
    printf("%10s |---------|-----------|--------------------|-----------------|-------------|\n", " ");

    Sale_land = start_sale_land;
    while (Sale_land) {
        if (datecmp(Sale_land->date) && !strcmp(Sale_land->deleteDate, "0"))
            printf("%10s | %-7s | %-9s | %-18s | %-15s | %-11s |\n", " ", Sale_land->type, Sale_land->land, Sale_land->owner_phone_no, Sale_land->price, Sale_land->tot_price);

        Sale_land = Sale_land->next;
    }

    printf("%73sHouses for rent between %d/%d/%d and %d/%d/%d\n\n", " ", from_year, from_month, from_day, to_year, to_month, to_day);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %-9s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|---------|-----------|----------|-----------|\n");

    Rent_house = start_rent_house;
    while (Rent_house) {
        if (datecmp(Rent_house->date) && !strcmp(Rent_house->deleteDate, "0")) {
            if (Rent_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Rent_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Rent_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Rent_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14.9s | %-9.9s | %-7s | %-9s | %-8s | %-9s |\n", Rent_house->type, Rent_house->age, Rent_house->infrastructure,
                                                                                        Rent_house->floor, Rent_house->land, Rent_house->owner_phone_no, Rent_house->rooms,
                                                                                        Rent_house->rent, Rent_house->mortgage, parking, warehouse, elevator, telephone);
        }

        Rent_house = Rent_house->next;
    }

    printf("\n%38sOffices for rent between %d/%d/%d and %d/%d/%d\n\n", " ", from_year, from_month, from_day, to_year, to_month, to_day);

    printf("| %11s       | %s | %s | %s | %s | %s | %s | %s | %s  |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage");
    printf("|-------------------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|\n");

    Rent_office = start_rent_office;
    while (Rent_office) {
        if (datecmp(Rent_office->date) && !strcmp(Rent_office->deleteDate, "0"))
            printf("| %-17s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14s | %-8.9s |\n", Rent_office->type, Rent_office->age, Rent_office->infrastructure,
                                                                                        Rent_office->floor, Rent_office->land, Rent_office->owner_phone_no, Rent_office->rooms,
                                                                                        Rent_office->rent, Rent_office->mortgage);
        Rent_office = Rent_office->next;
    }

    printf("\n%40sLands for rent between %d/%d/%d and %d/%d/%d\n\n", " ", from_year, from_month, from_day, to_year, to_month, to_day);

    printf("%10s | %6s  | %s | %s | %s | %s |\n", " ", "Type", "Base area", "Owner phone number", "Rent per month", " Mortgage");
    printf("%10s |---------|-----------|--------------------|----------------|-----------|\n", " ");

    Rent_land = start_rent_land;
    while (Rent_land) {
        if (datecmp(Rent_land->date) && !strcmp(Rent_land->deleteDate, "0"))
            printf("%10s | %-7s | %-9s | %-18s | %-14s | %-9s |\n", " ", Rent_land->type, Rent_land->land, Rent_land->owner_phone_no, Rent_land->rent, Rent_land->mortgage);

        Rent_land = Rent_land->next;
    }

    printf("\nPress any key to go back to reports menu...");
    getch();
    system("cls"); // Clear screen for better ui
}

void DeleteEstate()
{
    printf("Enter the start date (YY/MM/DD): ");
    scanf("%d%*c%d%*c%d", &from_year, &from_month, &from_day);

    printf("Enter the finish date (YY/MM/DD): ");
    scanf("%d%*c%d%*c%d", &to_year, &to_month, &to_day);

    printf("%73sHouses for sale between %d/%d/%d and %d/%d/%d\n\n", " ", from_year, from_month, from_day, to_year, to_month, to_day);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|---------|-----------|----------|-----------|\n");

    Sale_house = start_sale_house;
    while (Sale_house) {
        if (datecmp(Sale_house->deleteDate) && strcmp(Sale_house->deleteDate, "0")) {
            if (Sale_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Sale_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Sale_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Sale_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s | %-7s | %-9s | %-8s | %-9s |\n", Sale_house->type, Sale_house->age, Sale_house->infrastructure,
                                                                                        Sale_house->floor, Sale_house->land, Sale_house->owner_phone_no, Sale_house->rooms,
                                                                                        Sale_house->price, Sale_house->tot_price, parking, warehouse, elevator, telephone);
        }

        Sale_house = Sale_house->next;
    }

    printf("\n%38sOffices for sale between %d/%d/%d and %d/%d/%d\n\n", " ", from_year, from_month, from_day, to_year, to_month, to_day);

    printf("| %11s       | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Price per meter",
                                                                                    "Total price");
    printf("|-------------------|-----|----------------|-------|-----------|--------------------|-----------------|-----------------|-------------|\n");
            
    Sale_office = start_sale_office;
    while (Sale_office) {
        if (datecmp(Sale_office->deleteDate) && strcmp(Sale_office->deleteDate, "0"))
            printf("| %-17s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-15s | %-11s |\n", Sale_office->type, Sale_office->age, Sale_office->infrastructure,
                                                                                        Sale_office->floor, Sale_office->land, Sale_office->owner_phone_no, Sale_office->rooms,
                                                                                        Sale_office->price, Sale_office->tot_price);
        Sale_office = Sale_office->next;
    }

    printf("\n%40sLands for sale between %d/%d/%d and %d/%d/%d\n\n", " ", from_year, from_month, from_day, to_year, to_month, to_day);

    printf("%10s | %6s  | %s | %s | %s | %s |\n", " ", "Type", "Base area", "Owner phone number", "Price per meter", "Total price");
    printf("%10s |---------|-----------|--------------------|-----------------|-------------|\n", " ");

    Sale_land = start_sale_land;
    while (Sale_land) {
        if (datecmp(Sale_land->deleteDate) && strcmp(Sale_land->deleteDate, "0"))
            printf("%10s | %-7s | %-9s | %-18s | %-15s | %-11s |\n", " ", Sale_land->type, Sale_land->land, Sale_land->owner_phone_no, Sale_land->price, Sale_land->tot_price);

        Sale_land = Sale_land->next;
    }

    printf("%73sHouses for rent between %d/%d/%d and %d/%d/%d\n\n", " ", from_year, from_month, from_day, to_year, to_month, to_day);

    printf("| %7s   | %s | %s | %s | %s | %s | %s | %s | %-9s | %s | %s | %s | %s |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage", "Parking", "Warehouse", "Elevator", "Telephone");
    printf("|-----------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|---------|-----------|----------|-----------|\n");

    Rent_house = start_rent_house;
    while (Rent_house) {
        if (datecmp(Rent_house->deleteDate) && strcmp(Rent_house->deleteDate, "0")) {
            if (Rent_house->parking == 'Y')
                strcpy(parking, "Yes");
            else
                strcpy(parking, "No");
                
            if (Rent_house->warehouse == 'Y')
                strcpy(warehouse, "Yes");
            else
                strcpy(warehouse, "No");

            if (Rent_house->elevator == 'Y')
                strcpy(elevator, "Yes");
            else
                strcpy(elevator, "No");

            if (Rent_house->telephone == 'Y')
                strcpy(telephone, "Yes");
            else
                strcpy(telephone, "No");

            printf("| %9s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14.9s | %-9.9s | %-7s | %-9s | %-8s | %-9s |\n", Rent_house->type, Rent_house->age, Rent_house->infrastructure,
                                                                                        Rent_house->floor, Rent_house->land, Rent_house->owner_phone_no, Rent_house->rooms,
                                                                                        Rent_house->rent, Rent_house->mortgage, parking, warehouse, elevator, telephone);
        }

        Rent_house = Rent_house->next;
    }

    printf("\n%38sOffices for rent between %d/%d/%d and %d/%d/%d\n\n", " ", from_year, from_month, from_day, to_year, to_month, to_day);

    printf("| %11s       | %s | %s | %s | %s | %s | %s | %s | %s  |\n", "Type", "Age", "Infrastructure", "Floor", "Base area",
                                                                                    "Owner phone number", "Amount of rooms", "Rent per month",
                                                                                    "Mortgage");
    printf("|-------------------|-----|----------------|-------|-----------|--------------------|-----------------|----------------|-----------|\n");

    Rent_office = start_rent_office;
    while (Rent_office) {
        if (datecmp(Rent_office->deleteDate) && strcmp(Rent_office->deleteDate, "0"))
            printf("| %-17s | %-3s | %-14s | %-5s | %-9s | %-18s | %-15s | %-14s | %-8.9s |\n", Rent_office->type, Rent_office->age, Rent_office->infrastructure,
                                                                                        Rent_office->floor, Rent_office->land, Rent_office->owner_phone_no, Rent_office->rooms,
                                                                                        Rent_office->rent, Rent_office->mortgage);
        Rent_office = Rent_office->next;
    }

    printf("\n%40sLands for rent between %d/%d/%d and %d/%d/%d\n\n", " ", from_year, from_month, from_day, to_year, to_month, to_day);

    printf("%10s | %6s  | %s | %s | %s | %s |\n", " ", "Type", "Base area", "Owner phone number", "Rent per month", " Mortgage");
    printf("%10s |---------|-----------|--------------------|----------------|-----------|\n", " ");

    Rent_land = start_rent_land;
    while (Rent_land) {
        if (datecmp(Rent_land->deleteDate) && strcmp(Rent_land->deleteDate, "0"))
            printf("%10s | %-7s | %-9s | %-18s | %-14s | %-9s |\n", " ", Rent_land->type, Rent_land->land, Rent_land->owner_phone_no, Rent_land->rent, Rent_land->mortgage);

        Rent_land = Rent_land->next;
    }

    printf("\nPress any key to go back to reports menu...");
    getch();
    system("cls"); // Clear screen for better ui
}

int datecmp(char *date_str)
{
    int year, month, day;
    int date, to_date, from_date;
    
    sscanf(date_str, "%d/%d/%d", &year, &month, &day);
    date = (year * 12 + month) * 30 + day;
    to_date = (to_year * 12 + to_month) * 30 + to_day;
    from_date = (from_year * 12 + from_month) * 30 + from_day;

    if (date <= to_date && date >= from_date)
        return 1; // Return 1 as True
    else 
        return 0; // Return 0 as false
}

static char unit;

void valueEstate()
{
    if (readSales())
        return;

    long long int value = 0;

    Sale_house = start_sale_house;
    while (Sale_house) {
        value += unitConverter(Sale_house->tot_price);
        free(Sale_house);
        Sale_house = Sale_house->next;
    }

    Sale_office = start_sale_office;
    while (Sale_office) {
        value += unitConverter(Sale_office->tot_price);
        free(Sale_office);
        Sale_office = Sale_office->next;
    }

    Sale_land = start_sale_land;
    while (Sale_land) {
        value += unitConverter(Sale_land->tot_price);
        free(Sale_land);
        Sale_land = Sale_land->next;
    }

    printf("Total value of all Estates for sale: %.0lf %c", unitPicker((double)value), unit);
    getch();
    system("cls"); // Clear screen for better ui
}

void saleEstate(user *a, char *type)
{
    double price_temp, tot_temp;
    time_t t;
    struct tm *local; // pointer to structure of tm

    local = malloc(sizeof(struct tm));

    // Check the type of estate to be registered (house, office, land)
    if (!strcmp(type, "house")) {
        FILE *house;

        // Open the file for storing information about houses for sale
        house = fopen("houses_sale.hex", "ab+");
        if (house) {
            printf("Enter the information of estate, below:\n\n");
            
            // Get details of the house from the user
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
                tot_temp = price_temp * atoi(Sale_house->infrastructure); // Calculate the total price based on the area and price per meter

                // Format and store the prices with appropriate units
                price_temp = unitPicker(price_temp);
                sprintf(Sale_house->price, "%.3lf %c", price_temp, unit);

                tot_temp = unitPicker(tot_temp);
                sprintf(Sale_house->tot_price, "%.3lf %c", tot_temp, unit);
                
                // Prompt the user for additional features (parking, warehouse, elevator, telephone)
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
                strcpy(Sale_house->deleteDate, "0");
                updateUserEstate(a);

                fwrite(Sale_house, sizeof(sale_house), 1, house); // Write the information in file

                green();
                printf("\nRegister was successful. Press any key to go back to main menu...");
                getch(); // Wait for a key press before clearing screen
                reset();
                system("cls"); // Clear screen for better ui

                free(Sale_house);
                fclose(house);
            }
            else
                printf("ERROR: Your computer is low on memory."); 
        }
        else
            printf("ERROR: Could not access Estates. Please try again later.");
    }
    else if (!strcmp(type, "office")) {
        FILE *office;

        // Open the file for storing information about offices for sale
        office = fopen("offices_sale.hex", "ab+");
        if (office) {
            printf("Enter the information of estate, below:\n\n");

            Sale_office = malloc(sizeof(sale_office));
            if (Sale_office) {
                // Get details of the house from the user
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
                tot_temp = price_temp * atoi(Sale_office->infrastructure); // Calculate the total price based on the area and price per meter
                // Format and store the prices with appropriate units
                price_temp = unitPicker(price_temp);
                sprintf(Sale_office->price, "%.3lf %c", price_temp, unit);

                tot_temp = unitPicker(tot_temp);
                sprintf(Sale_office->tot_price, "%.3lf %c", tot_temp, unit);
                
                // Save the register date
                t = time(NULL);
                local = localtime(&t);
                sprintf(Sale_office->date, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);

                strcpy(Sale_office->registrar, a->username);
                strcpy(Sale_office->deleteDate, "0");
                updateUserEstate(a);

                fwrite(Sale_office, sizeof(sale_office), 1, office); // Write the information in file
                green();
                printf("\nRegister was successful. Press any key to go back to main menu...");
                getch(); // Wait for a key press before clearing screen
                reset();
                system("cls"); // Clear screen for better ui

                free(Sale_office);
                fclose(office);
            }
            else
                printf("ERROR: Your computer is low on memory."); 
        }
        else
            printf("ERROR: Could not access Estates. Please try again later.");
    }
    else {
        FILE *land;

        // Open the file for storing information about lands for sale
        land = fopen("lands_sale.hex", "ab+");
        if (land) {
            printf("Enter the information of estate, below:\n\n");

            Sale_land = malloc(sizeof(sale_land));
            if (Sale_land) {
                // Get details of the house from the user
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
                tot_temp = price_temp * atoi(Sale_land->land); // Calculate the total price based on the area and price per meter

                // Format and store the prices with appropriate units
                price_temp = unitPicker(price_temp);
                sprintf(Sale_land->price, "%.3lf %c", price_temp, unit);

                tot_temp = unitPicker(tot_temp);
                sprintf(Sale_land->tot_price, "%.3lf %c", tot_temp, unit);
                
                // Save the register date
                t = time(NULL);
                local = localtime(&t);
                sprintf(Sale_land->date, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);

                strcpy(Sale_land->registrar, a->username);
                strcpy(Sale_land->deleteDate, "0");
                updateUserEstate(a);

                fwrite(Sale_land, sizeof(sale_land), 1, land); // Write the information in file
                green();
                printf("\nRegister was successful. Press any key to go back to main menu...");
                getch(); // Wait for a key press before clearing screen
                reset();
                system("cls"); // Clear screen for better ui

                free(Sale_land);
                fclose(land);
            }
            else
                printf("ERROR: Your computer is low on memory."); 
        }
        else
            printf("ERROR: Could not access Estates. Please try again later.");
    }

    free(local);
}

void rentEstate(user *a, char *type)
{
    double rent_temp, mor_temp;
    time_t t;
    struct tm *local; // pointer to structure of tm

    local = malloc(sizeof(struct tm));

    // Check the type of estate to be registered (house, office, land)
    if (!strcmp(type, "house")) {
        FILE *house;

        // Open the file for storing information about houses for sale
        house = fopen("houses_rent.hex", "ab+");
        if (house) {
            printf("Enter the information of estate, below:\n\n");
            
            // Get details of the house from the user
            Rent_house = malloc(sizeof(rent_house));
            if (Rent_house) {
                printf("Municipality area: ");
                gets(Rent_house->area);
                
                printf("Full address: ");
                gets(Rent_house->address);
                
                printf("Type (Apartment/Villa): ");
                gets(Rent_house->type);
                
                printf("Age: ");
                gets(Rent_house->age);
                
                printf("Infrastructure (House Area): ");
                gets(Rent_house->infrastructure);
                
                printf("On which floor: ");
                gets(Rent_house->floor);
                
                printf("Base area: ");
                gets(Rent_house->land);
                
                printf("Owner phone number: ");
                gets(Rent_house->owner_phone_no);
                
                printf("The amount of rooms: ");
                gets(Rent_house->rooms);
                
                printf("Mortgage: ");
                scanf("%lf", &mor_temp);
                getchar(); // Avoid extra enter
                mor_temp = unitPicker(mor_temp); // Format and store the prices with appropriate units
                sprintf(Rent_house->mortgage, "%.3lf %c", mor_temp, unit);

                printf("Monthly rent: ");
                scanf("%lf", &rent_temp);
                getchar(); // Avoid extra enter
                rent_temp = unitPicker(rent_temp); // Format and store the prices with appropriate units
                sprintf(Rent_house->rent, "%.3lf %c", rent_temp, unit);
                
                // Prompt the user for additional features (parking, warehouse, elevator, telephone)
                printf("Does it have parking? (Y/N): ");
                Rent_house->parking = toupper(getche());
                   
                printf("\nDoes it have warehouse? (Y/N): ");
                Rent_house->warehouse = toupper(getche());
                   
                printf("\nDoes it have elevator? (Y/N): ");
                Rent_house->elevator = toupper(getche());
                   
                printf("\nDoes it have telephone? (Y/N): ");
                Rent_house->telephone = toupper(getche());
                
                // Save the register date
                t = time(NULL);
                local = localtime(&t);
                sprintf(Rent_house->date, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);

                strcpy(Rent_house->registrar, a->username);
                strcpy(Rent_house->deleteDate, "0");
                updateUserEstate(a);

                fwrite(Rent_house, sizeof(rent_house), 1, house); // Write the information in file
                green();
                printf("\nRegister was successful. Press any key to go back to main menu...");
                getch(); // Wait for a key press before clearing screen
                reset();
                system("cls"); // Clear screen for better ui

                free(Rent_house);
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

        // Open the file for storing information about offices for sale
        office = fopen("offices_rent.hex", "ab+");
        if (office) {
            printf("Enter the information of estate, below:\n\n");

            Rent_office = malloc(sizeof(rent_office));
            if (Rent_office) {
                // Get details of the house from the user
                printf("Municipality area: ");
                gets(Rent_office->area);
                
                printf("Full address: ");
                gets(Rent_office->address);
                
                printf("Type (Official document/Position): ");
                gets(Rent_office->type);

                printf("Age: ");
                gets(Rent_office->age);
                
                printf("Infrastructure (Office Area): ");
                gets(Rent_office->infrastructure);
                
                printf("On which floor: ");
                gets(Rent_office->floor);
                
                printf("Base area: ");
                gets(Rent_office->land);
                
                printf("Owner phone number: ");
                gets(Rent_office->owner_phone_no);
                
                printf("The amount of rooms: ");
                gets(Rent_office->rooms);
                
                printf("Mortgage: ");
                scanf("%lf", &mor_temp);
                getchar(); // Avoid extra enter
                mor_temp = unitPicker(mor_temp); // Format and store the prices with appropriate units
                sprintf(Rent_office->mortgage, "%.3lf %c", mor_temp, unit);

                printf("Monthly rent: ");
                scanf("%lf", &rent_temp);
                getchar(); // Avoid extra enter
                rent_temp = unitPicker(rent_temp); // Format and store the prices with appropriate units
                sprintf(Rent_office->rent, "%.3lf %c", rent_temp, unit);
                
                // Save the register date
                t = time(NULL);
                local = localtime(&t);
                sprintf(Rent_office->date, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);

                strcpy(Rent_office->registrar, a->username);
                strcpy(Rent_office->deleteDate, "0");
                updateUserEstate(a);

                fwrite(Rent_office, sizeof(rent_office), 1, office); // Write the information in file
                green();
                printf("\nRegister was successful. Press any key to go back to main menu...");
                getch(); // Wait for a key press before clearing screen
                reset();
                system("cls"); // Clear screen for better ui

                free(Rent_office);
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

        // Open the file for storing information about lands for sale
        land = fopen("lands_rent.hex", "ab+");
        if (land) {
            printf("Enter the information of estate, below:\n\n");

            Rent_land = malloc(sizeof(rent_land));
            if (Rent_land) {
                // Get details of the house from the user
                printf("Municipality area: ");
                gets(Rent_land->area);
                
                printf("Full address: ");
                gets(Rent_land->address);
                
                printf("Type (Farming/City): ");
                gets(Rent_land->type);
                
                printf("Base area: ");
                gets(Rent_land->land);
                
                printf("Owner phone number: ");
                gets(Rent_land->owner_phone_no);
                
                printf("Mortgage: ");
                scanf("%lf", &mor_temp);
                getchar(); // Avoid extra enter
                mor_temp = unitPicker(mor_temp); // Format and store the prices with appropriate units
                sprintf(Rent_land->mortgage, "%.3lf %c", mor_temp, unit);

                printf("Monthly rent: ");
                scanf("%lf", &rent_temp);
                getchar(); // Avoid extra enter
                rent_temp = unitPicker(rent_temp); // Format and store the prices with appropriate units
                sprintf(Rent_land->rent, "%.3lf %c", rent_temp, unit);
                
                // Save the register date
                t = time(NULL);
                local = localtime(&t);
                sprintf(Rent_land->date, "%0d/%0d/%0d", local->tm_year-100, local->tm_mon+1, local->tm_mday);

                strcpy(Rent_land->registrar, a->username);
                strcpy(Rent_land->deleteDate, "0");
                updateUserEstate(a);

                fwrite(Rent_land, sizeof(rent_land), 1, land); // Write the information in file
                green();
                printf("\nRegister was successful. Press any key to go back to main menu...");
                getch(); // Wait for a key press before clearing screen
                reset();
                system("cls"); // Clear screen for better ui

                free(Rent_land);
                fclose(land);
                return;
            }
            else
                printf("ERROR: Your computer is low on memory."); 
        }
        else
            printf("ERROR: Could not access Estates. Please try again later.");
    }

    free(local);
}

double unitPicker(double price)
{
    int counter = 0;

    // Loop to determine the appropriate unit and reduce the price
    while (price >= 1000) {
        price = price / 1000;
        counter++;
    }

    // Set the unit based on the counter value
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

    return price; // Return the converted price
}

double unitConverter(char *price)
{
    double result;
    sscanf(price, "%lf %c", &result, &unit);

    switch (unit)
    {
    case ' ':
        return result;
        break;
    
    case 'K':
        return result * 1000;
        break;
    
    case 'M':
        return result * 1000 * 1000;
        break;
    
    default:
        return result * 1000 * 1000 * 1000;
        break;
    }
}