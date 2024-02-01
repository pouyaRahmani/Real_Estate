#include <stdio.h>

void main()
{
    FILE *fp;
    int a;
    char b[20];

    fp = fopen("number_of_users.txt", "r+");
    fscanf(fp, "%d\n", &a);

    while (!feof(fp)) {
        fscanf(fp, "%s\n", b);
        puts(b);
    }
    rewind(fp);

    fp = freopen("number_of_users.txt", "a+", fp);

    fprintf(fp, "%s\n", "hi");
}