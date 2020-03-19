#include<stdio.h>
#include<math.h>
#define ERROR 0.000000000001
#define dx 0.00001
int coef[1000];
int A=1;
int deg;
double f(double x,int degree)
{
	int i;
	double poly=0.0;

	for(i=0;i<=degree;i++)
	{
		if(A==1)
		{
		scanf("%d",&coef[i]);
		}
		poly=poly+(pow(x,i)*coef[i]);
	}
	A++;
	return poly;
}
double df(double x)
{
	return ((f(x+dx,deg)-f(x,deg))/dx);
}


int main()
{
	double x0=0,x1;
	printf("degree: ");
	scanf("%d",&deg);
	while(df(x0)==0)
	{
		x0+=0.1;
	}
	while(f(x1,deg)>ERROR || f(x1,deg)<-ERROR)
	{
		x1=x0-(f(x0,deg)/df(x0));
		x0=x1;
	}
	printf(" root of the fuction is:%lf \n f(%lf)=%lf \n\n",x1,x1,f(x1,deg));
	return 0;
}
