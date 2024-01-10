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
    struct u *next;
} user;