#include<stdio.h>

double func(double x)
{
	double y = x*x + 60*x + 8;
	return y;
}

int main(int argc, char const *argv[])
{
	double x = 0, y = 10000000000 , d = .000000000000001;
	double z;

	do
	{
		z = (x*func(y)-y*func(x))/(func(y)-func(x));
		x = y;
		y = z;
		if (func(z)<d&&func(z)>-d)
		{
			break;
		}

	}while(1);
	printf("%.15lf\n",z );
	return 0;
}
