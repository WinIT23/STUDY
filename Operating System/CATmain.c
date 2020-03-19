#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1;
    FILE *f2;
    char S1[100];
    char c;
    printf("Enter Filename to be added: ");
    gets(&S1);
    f1 = fopen(S1,"r");
    if(f1==NULL)
    {
        printf(" File Not Found!");
        exit(0);
    }
    printf("Enter Original Filename: ");
    gets(&S1);
    f2 = fopen(S1,"r");
    if(f2==NULL)
    {
        printf(" File Not Found!");
        exit(0);
    }

    c = fgetc(f1);
    while (c != EOF)
    {
        printf("%c",c);
        c = fgetc(f1);
    }
    c = fgetc(f2);
    while (c != EOF)
    {
        printf("%c",c);
        c = fgetc(f2);
    }
    fclose(f1);
    fclose(f2);
}
