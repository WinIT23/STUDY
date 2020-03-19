#include<stdio.h>
float matrix[200][200];
float ans[200];
void row_op(int r1,int r2,float coef,int i)
{
	int z;
	for(z=0;z<=i;z++)
	matrix[r1-1][z]=matrix[r1-1][z]-(coef*matrix[r2-1][z]);
}
void row_div(int r1,float coef,int i)
{
	int z;
	if(coef==0)
    {
        printf("cant divide by 0\n");
    }
    else
    {
        for(z=0;z<=i;z++)
        matrix[r1-1][z]=(matrix[r1-1][z]/coef);
    }
}
void row_swap(int r1,int r2,int i)
{
	int z=0;
	int temp;
	for(z=0;z<=i;z++)
	{
		temp=matrix[r1][z];
		matrix[r1][z]=matrix[r2][z];
		matrix[r2][z]=temp;
	}
}

int main()
{
	int i,j,k,x,y;
	int large=0;
	int temp=0;
	printf("enter no. of variable: ");
	scanf("%d",&i);
	for(j=0;j<i;j++)
	for(k=0;k<=i;k++)
	scanf("%f",&matrix[j][k]);

	for(j=0;j<i;j++)
	{
		for(k=i-1;k>=j-1;k--)
		{
			if(matrix[k][j]>large)
			{
				large=matrix[k][j];
				temp=k;
			}
		}
		row_swap(temp,j,i);
	}

	for(x=1;x<=i;x++)
	{
		row_div(x,matrix[x-1][x-1],i);
		for(y=1;y<=i;y++)
		{
			if(y<=x)
			continue;
			else
			row_op(y,x,matrix[y-1][x-1],i);
		}
	}

	for(j=0;j<i;j++)
    {
        for(k=0;k<=i;k++)
        {
            printf("%.4f ",matrix[j][k]);
        }
        printf("\n");
    }


    for(j=0;j<i;j++)
    {
        ans[j]=matrix[j][i];
    }


    for(j=i-1;j>=0;j--)
    {
        ans[j]=matrix[j][i];
        for(k=j+1;k<i;k++)
        {
            ans[j]-=(ans[k]*matrix[j][k]);
        }
    }

    for(j=0;j<i;j++)
    {
        printf("%.4f \n",ans[j]);
    }
}
