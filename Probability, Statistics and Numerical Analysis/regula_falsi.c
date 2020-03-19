#include<stdio.h>
double f(double x)
{
	return (x*x+60*x+8);
}
int main()
{
	double x0=0,x1=1,x2,temp;
	while(f(x0)*f(x1)>0)
	{
		x0-=.1;
		x1-=.1;
	}
	if(f(x0)<0)
    {
        temp=x0;
        x0=x1;
        x1=temp;
    }
	do
	{
		x2=(x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
		if(f(x2)>0)
        x0=x2;
        else if(f(x2)<0)
        x1=x2;
        printf("x2: %.20lf \n",x2);

	}while(-0.000000000000001>f(x2) || f(x2)>0.0000000000000001);

	printf("root of the function: %.20lf ",x2);
}
