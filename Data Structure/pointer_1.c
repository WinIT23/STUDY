#include <stdio.h>

int main()
{
    int i,j,ele;
    int **p =(int **) malloc(5*sizeof(int *));	 //allocating memory for pointers which are going to point rows of 2D array
    printf("enter elements row-wise for 5*5 array: \n");
    for(i=0;i<5;i++)
    {
        *(p+i) = (int *)malloc(5*sizeof(int));	 //allocating memory for each elements(5 elements) for every row(5 rows) 
        for(j=0;j<5;j++)
        {
            scanf("%d",&ele);	//scanning elements of 2D array from user
            *(*(p+i)+j) = ele;
        }
    }

    *(*(p+3)+3) = 99999;      	//updation
    p=realloc(p,24);
    *(p+5) = (int *)malloc(20);

    for(i=0;i<5;i++)     //insertion
    *(*(p+5)+i)=i;

    for(i=0;i<6;i++)
    {
    	for(j=0;j<5;j++)
    	printf("%d ",p[i][j]);	 //final array after applying these functions
    	printf("\n");
    }

    return 0;
}
