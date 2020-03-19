#include<stdio.h>

double fx(int x)
{
	return ((x*x)-(7*x)+12);
}
int main()
{
	int x1=0;
	int t;
	int x2;
	int x3=-1000;
	double fx1,fx3;
	double fx2=-10.1010;
	fx1=fx(x1);
	if(fx1<0)
	{
	    int i;
		for(i=0;i<20;i++)
		{
			fx2=fx(i);
			if(fx2>0)
			{
				x2=i;
				break;
			}
			if(fx2==0)
			{
				x3=i;
				break;
			}
		}
        int j;
		for(j=0;j>-20;j--)
		{
			fx2=fx(j);
			if(fx2>0)
			{
				x2=j;
				break;
			}
			if(fx2==0)
			{
				x3=j;
				break;
			}
		}
	}
	else if(fx1>0)
	{
	    int i;
		for(i=0;i<20;i++)
		{
			fx2=fx(i);
			if(fx2<0)
			{
				x2=i;
				break;
			}
			if(fx2==0)
			{
				x3=i;
				break;
			}
		}
        int j;
		for(j=0;j>-20;j--)
		{
			fx2=fx(j);
			if(fx2<0)
			{
				x2=j;
				break;
			}
			if(fx2==0)
			{
				x3=j;
				break;
			}
		}
	}
	if(x1>x2)
	{
		t=x1;
		x1=x2;
		x2=t;
	}
	if(x3==-1000)
	{
		x3=(x1+x2)/2;
		while((fx(x3)>0.01 || fx(x3)<-0.01))
		{
			if(fx1>fx2)
			{
				if(fx(x3)>0)
					x1=x3;
				else if(fx(x3)<0)
					x2=x3;
			}
			else if(fx2>fx1)
			{
				if(fx(x3)>0)
					x2=x3;
				else if(fx(x3)<0)
					x1=x3;
			}
			x3=(x1+x2)/2;
		}
	}
	printf("one of the root is %d",x3);
	return 0;
}
