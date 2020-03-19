#include<stdio.h>
#define MAX 10
int tos=-1;
int stack_ele[MAX];
void push(int a)
{
	if(tos>=(MAX-1))
		printf("stack is in over-flow condition \ncan't push any element!!");
	else
	stack_ele[++tos]=a;
}
int pop()
{
	if(tos==-1)
	{
		printf("stack is in under-flow condition \ncan't pop any element!!");
		return 0;
	}
	else
	return(stack_ele[tos--]);
}
void peep(int l)
{
	if(stack_ele[tos-l+1]!='\0')
		printf("element at given location: %d",stack_ele[tos-l+1]);
	else{
		printf("element is not present at given index: \n");
	}
}
void change(int l,int element)
{
	if(stack_ele[tos-l+1]!='\0')
		stack_ele[tos-l+1]=element;
	else
		printf("no element present at given index: \n");
}

int main()
{
	int i=0;
	int choice;
	printf("enter elements of stack: \n \"press '-100' to quit\"\n");
	do
	{
		scanf("%d",&stack_ele[i]);
		if(stack_ele[i]==-100)
			break;
		i++;
		tos++;
	}while(i<MAX);
	int k=0;
	do
	{
		printf("enter \n1.push \n2.pop \n3.peep \n4.change \n5.exit \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter element: \n");
					int a;
					scanf("%d",&a);
					push(a);
					break;
			case 2: printf("poppiong element\n");
                    			int c;
					c=pop();
					printf("popped elemet: %d\n",c);
					break;
			case 3: printf("enter index from top: \n");
					int x;
					scanf("%d",&x);
					peep(x);
					break;
			case 4: printf("enter the element index & new element: \n");
					int index,elem;
					scanf("%d%d",&index,&elem);
					change(index,elem);
					break;
			case 5: k=1;
					break;
        }
        printf("\nupdated stack: \n");
        int z;
        for(z=0;z<=tos;z++)
            printf("%d\n",stack_ele[z]);
    }while(k==0);
}

