#include<stdio.h>
#define degree 100
#define subscript 100
double delta[degree][subscript];
int N;
double fact(int n)
{
	if(n==1)
		return 1.000000;
	else
		return (n*fact(n-1));
}
double coef(int d,double p)
{
	double ans=1;
	int i;
	for(i=0;i<=d;i++)
	{
		ans*=(p+i);
	}
	ans/=fact(d+1);
	ans*=delta[d][N-1];
	return(ans);
}
int main()
{
	int i,j;
	double p,h,xu,ya;
	double x[100],y[100];
	printf("enter total number of dataset to be given in input: \n");
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		printf("enter x: & corresponding y: ");
		scanf("%lf%lf",&x[i],&y[i]);
	}
	for(i=N-1;i>0;i--)
	{
		delta[0][i]=y[i]-y[i-1];
	}
	for(j=1;j<N-1;j++)
	{
		for(i=N-1;i>j;i--)
		{
			delta[j][i]=delta[j-1][i]-delta[j-1][i-1];
			printf(" %lf \n",delta[j][i]);
		}
	}
	printf("enter x for which you want f(x): \n");
	scanf("%lf",&xu);
	h=x[1]-x[0];
	p=(xu-x[N-1])/h;
	ya=y[N-1];
	for(i=0;i<N-1;i++)
	{
		ya+=coef(i,p);
	}
	printf("for x=%lf f(x)=%lf :",xu,ya);

}
