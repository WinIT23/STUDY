#include<stdio.h>
int main()
{
	int N,h,x[100][6],initial;
	int t=0,q=0,r=0;
	double mean,median,mode;
	printf("enter total no. of set: \n");
	scanf("%d",&N);
	printf("enter initial x & gap: \n");
	scanf("%d%d",&initial,&h);
	x[0][0]=initial;
	x[0][1]=initial+h;

	for (int i = 1; i < N; ++i)
	{
		x[i][0]=x[i-1][1];
		x[i][1]=x[i][0]+h;
	}

	printf("enter %d frequencies: ",N);
	for (int i = 0; i < N; ++i)
	{
	    t=0;
		scanf("%d",&x[i][2]);                   //f
		for(int j=i;j>=0;j--)
        {
            t+=x[j][2];
        }
        x[i][3]=t;                              //cf
        x[i][4]=(x[i][0]+x[i][1])/2;            //mid
        x[i][5]=x[i][4]*x[i][2];                //m*f
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			printf(" %d ",x[i][j]);
		}
		printf("\n");
	}
	t=0;
	for (int i = 0; i < N; ++i)
	{
		t+=x[i][5];
		q+=x[i][2];
	}

	mean=t/(double)q;
	printf("mean is %lf\n",mean);
	int i;
	if(N%2==0)
    {
        t=((q/2) + (q+1)/2)/2;
        for (i = 0; i < N; ++i)
        {
        	if(x[i][3]>t)
        		break;
        }
        t=x[i][2];
        r=x[i-1][3];
        initial=x[i][0];
    }
    else
    {
    	t=(q+1)/2;
    	for (int i = 0; i < N; ++i)
        {
        	if(x[i][3]>t)
        		break;
        }
        t=x[i][2];
        r=x[i-1][3];
        initial=x[i][0];
    }
    median=initial+((double)q/2-r)/(double)t*h;
    printf("median: %lf\n",median);

    int j;
    for (i = 0; i < N; ++i)
    {
    	t=x[i][2];
    	for (j = i+1; j < N; ++j)
    	{
    		if(x[j][2]>t)
    			q=j;
    			t=x[j][2];
    	}
    }
    initial=x[q][0];
    mode=initial+h*(x[q][2]-x[q-1][2])/(double)(2*(double)x[q][2]-x[q-1][2]-x[q+1][2]);
    printf("mode is: %lf",mode);



}
