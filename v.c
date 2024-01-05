typedef struct sale_house { // Structure to represent a house for sale
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

typedef struct sale_office { // Structure to represent an office for sale
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
 
typedef struct sale_land { // Structure to represent a land for sale
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
 
typedef struct rent_house { // Structure to represent a house for rent
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

typedef struct rent_office { // Structure to represent an office for rent
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
 
typedef struct rent_land { // Structure to represent a land for rent
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