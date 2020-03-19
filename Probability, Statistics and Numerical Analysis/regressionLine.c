#include<stdio.h>
#include<math.h>
int main()
{
	int N,x[100][7];
	double a,b;
	int i,j;
    double sigmaxy=0,sigmax2=0,sigmax=0,sigmay=0;
	printf("enter total no. of set: \n");
	scanf("%d",&N);

	for (i = 0; i < N; ++i)
	{
        printf("enter x%d and y%d : ",i+1,i+1);
		scanf("%d%d",&x[i][0],&x[i][1]);
        sigmax+=x[i][0];
        sigmay+=x[i][1];
	}

	for (i = 0; i < N; ++i)
	{
        x[i][2]=x[i][0]*x[i][0];  //(x)^2
        x[i][3]=x[i][0]*x[i][1];  //(x)*(y)
	}
    for (i = 0; i < N; ++i)
    {
        sigmax2+=x[i][2];
        sigmaxy+=x[i][3];
    }

    b=sigmay-(sigmaxy*sigmax/sigmax2);
    b/=(sigmax*sigmax/sigmax2+N);
    a=(sigmaxy-b*sigmax)/sigmax2;
    printf("\n a=%lf b=%lf",a,b);
}
