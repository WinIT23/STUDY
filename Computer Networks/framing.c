#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int* binaryNum;
    int k,j=0;
    FILE *fp,*fp2;
    char c;
    int n,l,i=0;
    int N,len=0;
    int flagno=0;
    int temp,count;
    int answer[400];
    int final[800];
    int text[400];
    int write[400];
    int random[4];


    
    int flag[8]={9,1,1,1,1,1,1,9};



    for (int i = 0; i < 4; ++i)
    {
        random[i]=rand()%11+5;
        printf("%d\n",random[i]);
    }

    fp2=fopen("C:/Users/Lenovo/Desktop/b.txt","w");
    if (fp2 == NULL)
    {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
    }

    fp=fopen("C:/Users/Lenovo/Desktop/a.txt","r");
    binaryNum=(int *)malloc(sizeof(int)*8);


    if (fp == NULL)
    {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
    }


    while((c=fgetc(fp))!= EOF)
    {
        len++;
        i=0;
        n=(int)c;
        while (n > 0)
        {
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }

        while(i<8)
        {
            binaryNum[i]=0;
            i++;
        }


        for (i = 0; i < 4; i++)
        {
            temp=binaryNum[i];
            binaryNum[i]=binaryNum[8-i-1];
            binaryNum[8-i-1]=temp;
        }


        for(i=0;i<8;i++,j++)
        {
            if(binaryNum[i]==1)
                count++;
            else
                count=0;

            answer[j]=binaryNum[i];
            if(count==4)
            {
                count=0;
                j++;
                answer[j]=0;
            }
        }

        for(i=0;i<8;i++)
            printf("%d",binaryNum[i]);
        printf("\n");


    }
    N=j;

    for(i=0;i<j;i++)
        printf("%d",answer[i]);
    printf("\n");

    for(i=0;i<8;i++)
        final[i]=flag[i];

    for(i=0,j=8,k=0;i!=N;i++,j++,k++)
    {
        if(k<4)
        {
            l=0;
            while(l<random[k])
            {
                final[j]=answer[i];
                l++;i++;j++;
            }
            for(l=0;l<8;l++,j++)
                final[j]=flag[l];
        }
        final[j]=answer[i];
    }
    for(i=0;i<8;i++,j++)
        final[j]=flag[i];

    for(i=0;i<j;i++)
        printf("%d",final[i]);
    
    printf("\n%d\n",len);

    for (i = 0,l = 0; i < j-1; i++,l++)
    {
        flagno=0;
        for(k=0;k<8;k++)
        {
            if(final[i+k]==flag[k])
                flagno++;
        }
        if(flagno==8)
            i=i+8;
        
        text[l]=final[i];
    }
        
    count=0;
    for(i=0,k=0;i<l-1;i++,k++)
        {
            if(count==4)
            {
                i++;
                count=0;
            }
            if(text[i]==1)
                count++;
            else
                count=0;

            write[k]=text[i];
        }

    for (i = 0; i < k; ++i)
    {
        if(i%8==0)
            printf("\n");
        printf("%d",write[i]);
    }

    temp=0;

    for(j=0;j<k;)
    {
        temp=0;
        for (i = 7; i >= 0; i--)
        {
            temp=temp+((int)write[(7-i)+j]*pow(2,i));
        }
        printf("\n%d",temp);
        fprintf(fp2,"%c",temp);
        j=j+8;
    }    

}