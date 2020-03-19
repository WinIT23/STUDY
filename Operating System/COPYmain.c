#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1;
    FILE *f2;
    char S1[100];
    char S2[100];
    char c;
    printf("Enter Filename to be copied: ");
    gets(&S1);
    f1 = fopen(S1,"r");
    if(f1==NULL)
    {
        puts(S1);
        printf(" File Not Found!");
        exit(0);
    }
    printf("Enter Original Filename: ");
    gets(&S2);
    f2 = fopen(S2,"w");
    fseek(f2,0,SEEK_END);
    c = fgetc(f1);
    while (c != EOF)
    {
        fprintf (f2,"%c",c);
        c = fgetc(f1);
    }
    fclose(f1);
    fclose(f2);
}
