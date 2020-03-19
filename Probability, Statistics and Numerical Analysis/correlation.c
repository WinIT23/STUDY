#include<stdio.h>
#include<math.h>
int main()
{
	int N,x[100][7];
    double xbar=0,ybar=0;
	double r;
    double sigmaxy=0,sigmax2=0,sigmay2=0;
	printf("enter total no. of set: \n");
	scanf("%d",&N);

	for (int i = 0; i < N; ++i)
	{
        printf("enter x%d and y%d : ",i+1,i+1);
		scanf("%d%d",&x[i][0],&x[i][1]);
	}


	for (int i = 0; i < N; ++i)
	{
	    xbar+=x[i][0];
        ybar+=x[i][1];
	}
    xbar/=N;
    ybar/=N;

	for (int i = 0; i < N; ++i)
	{
		x[i][2]=x[i][0]-xbar;     //x-x'
        x[i][3]=x[i][1]-ybar;     //y-y'
        x[i][4]=x[i][2]*x[i][2];  //(x-x')^2
        x[i][5]=x[i][3]*x[i][3];  //(y-y')^2
        x[i][6]=x[i][2]*x[i][3];  //(x-x')*(y-y')
	}
    for (int i = 0; i < N; ++i)
    {
        sigmax2+=x[i][4];
        sigmay2+=x[i][5];
        sigmaxy+=x[i][6];
    }
    r=sigmaxy/(sqrt(sigmax2)*sqrt(sigmay2));
    printf("\ncorrelation coefficient r= %lf",r);
}
