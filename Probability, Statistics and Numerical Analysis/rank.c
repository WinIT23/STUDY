#include<stdio.h>
int main()
{
	int N,x[100][5],i,j,count=1;
	double r=0;
    int key,index=0,min=0;
    double sum=0;
	printf("enter total no. of set: \n");
	scanf("%d",&N);

	for (i = 0; i < N; ++i)
	{
        printf("enter x%d and y%d : ",i+1,i+1);
		scanf("%d%d",&x[i][0],&x[i][1]);
	}
        for (i = 0; i < N; ++i)
		{
            key=99999;
			for (j = 0; j < N; ++j)
			{
				if(x[j][0]<=key && x[j][0]>min)
				{
					index=j;
					key=x[j][0];
				}
			}
			x[index][2]=count;
			count++;
			min=x[index][0];
		}

		count=1;
		index=0;
		min=0;

        for (i = 0; i < N; ++i)
		{
            key=99999;
			for (j = 0; j < N; ++j)
			{
				if(x[j][1]<=key && x[j][1]>min)
				{
					index=j;
					key=x[j][1];
				}
			}
			x[index][3]=count;
			count++;
			min=x[index][1];
		}

    for (i = 0; i < N; ++i)
	{
		x[i][4]=x[i][3]-x[i][2];
		x[i][4]*=x[i][4];
		sum+=x[i][4];
	}
	r=1-((6*sum)/(N*(N*N-1)));


    printf("\ncorrelation coefficient r= %lf",r);
}
