#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	FILE *fp,*fp2,*fp3;
	char c;

	fp=fopen("C:/Users/Lenovo/Desktop/a.txt","r");
    if (fp == NULL)
    {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
    }
	fp2=fopen("C:/Users/Lenovo/Desktop/b.txt","r+");
    if (fp2 == NULL)
    {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
    }
    fp3=fopen("C:/Users/Lenovo/Desktop/c.txt","w");
    if (fp3 == NULL)
    {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
    }


    
    fputc('F',fp2);
    while((c=fgetc(fp))!= EOF)
    {   
        if(c=='F' || c=='E')
        	fputc('E',fp2);
        fputc(c,fp2);
    }
    fputc('F',fp2);

    fseek(fp2, 0, SEEK_SET); 
    while((c=fgetc(fp2))!= EOF)
    {   
        if(c=='F' || c=='E')
        	c=fgetc(fp2);
        if(c!=EOF)
        	fputc(c,fp3);
    }

}