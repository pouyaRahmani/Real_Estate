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