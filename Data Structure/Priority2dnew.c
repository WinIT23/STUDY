#include<stdio.h>
#include<stdlib.h>
int flag=0;
int P;
int *r,*f,*n;
int **a;
void insert(int item,int prio)
{
	if(*(r+prio)==-1)
	{
		(*(r+prio))=(*(f+prio))=0;
		*(*(a+prio)+(*(r+prio)))=item;
	}
	else
	{
		if(*(r+prio)==*(n+prio)-1)
		{
			 *(a+prio)=(int *)realloc(*(a+prio),(*(n+prio)+1)*sizeof(char));
			(*(n+prio))+=1;
			flag++;
			(*(r+prio))+=1;
		}
		if(!flag)
		(*(r+prio))+=1;
		*(*(a+prio)+(*(r+prio)))=item;
		flag=0;
	}
}

void delete()
{
	int i,cout=0;
	for(i=P-1;i>=0;i--)
	{
		if(*(f+i)==-1)
        {
            cout++;
            continue;
        }
		else
		{
			if(*(f+i)==*(r+i))
			{
				*(f+i)=-1;
				*(r+i)=-1;
				break;
			}
			else
			{
				*(f+i)+=1;
				break;
			}
			printf("An element deleted.\n");
		}

	}
	if(cout==P)
        {
            printf("queue is empty.\n");
        }

}

void display()
{
	int i,j,couter=0;
	for(i=0;i<P;i++)
	{
		if(*(f+i)==-1)
		{
			couter++;
			continue;
		}
		else
		for(j=*(f+i);j<=*(r+i);j++)
		printf(" %d  f:%d r:%d P:%d \n",*(*(a+i)+j),*(f+i),*(r+i),i);
	}
	if(couter==P)
        {
            printf("queue is empty,nothing to print ;-).\n");
        }
}
int main()
{
	int N,i,choice,k=0;
	printf("enter the number of total queue: \n");
	scanf("%d",&P);
	printf("enter the no of elements required in each queue \n");
	scanf("%d",&N);
	a =malloc(P*sizeof(int *));	 //allocating memory for pointers which are going to point rows of 2D array
  	r =malloc(P*sizeof(int));
	f =malloc(P*sizeof(int));
	n =malloc(P*sizeof(int));
    	for(i=0;i<P;i++)
    	{
    	    *(a+i) = (int *)malloc(N*sizeof(char));	 //allocating memory for each elements for every row
	    (*(f+i))=(*(r+i))=-1;
	    (*(n+i))=N;
    	}

    	do
	{
		printf("\n	1.insert \n	2.delete \n	3.display \n	4.exit \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter element: & priority: respectively \n");
					int a,b;
					scanf("%d%d",&a,&b);
					insert(a,b);
					break;
			case 2: delete();
					break;
			case 3: display();
					break;
			case 4: k=1;
					break;
		}
    }while(k==0);

}
