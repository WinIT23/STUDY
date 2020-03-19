#include<stdio.h>
int N;
double x[100],y[100];
double term(double xgiven,double xn,double yn)
{
    int i;
    double ans=1;
    double ansd=1;
	for(i=0;i<N;i++)
	{
		if(x[i]!=xn)
		ans*=(xgiven-x[i]);
		if(x[i]!=xn)
		ansd*=(xn-x[i]);
	}
	ans/=ansd;
	ans*=yn;
	return ans;
}
int main()
{
	int i;
	double xgiven,yans=0;
	printf("enter the number of x to be given:\n");
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		printf("enter x & corresponding y: \n");
		scanf("%lf%lf",&x[i],&y[i]);
	}
	printf("enter x for which f(x) is required:\n");
	scanf("%lf",&xgiven);
	for(i=0;i<N;i++)
	{
		yans+=term(xgiven,x[i],y[i]);
	}
	printf("for x=%lf ; f(x)=%lf.\n",xgiven,yans);
}
