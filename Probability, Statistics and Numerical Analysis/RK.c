#include<stdio.h>
double func(double x,double y)
{
	return((y*y-x*x)/(y*y+x*x));                                   //change the return value here to get required function
}
int main()
{
	double i,initial,yinitial,x,y,step,k1,k2,k3,k4;
	printf("enter initial value of x:\n");
	scanf("%lf",&initial);
	printf("enter y(%ld):\n",initial);
	scanf("%lf",&yinitial);
	printf("enter value of x for which y is required:\n");
	scanf("%lf",&x);
	printf("enter step-length(/h)\n");
	scanf("%lf",&step);
	y=yinitial;
	for(i=initial;i<x;)
	{
		k1=step*func(i,y);
		printf("\n%lf\n",k1);
		k2=step*func((i+step/2),(y+k1/2));
		printf("%lf\n",k2);
		k3=step*func((i+step/2),(y+k2/2));
		printf("%lf\n",k3);
		k4=step*func((i+step),(y+k3));
		printf("%lf\n",k4);
		y=y+(k1+2*k2+2*k3+k4)/6;
		printf("y:%lf\n",y);
		i=i+step;
	}
	printf("\n******************** final ans:%lf *******************\n",y);
}
