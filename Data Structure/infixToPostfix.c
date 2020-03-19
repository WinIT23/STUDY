#include<stdio.h>
#include<string.h>
#define MAX 10
int tos=-1;
char stack_ele[MAX];
int d=0;
char a[MAX];
char polish[MAX];
void push(char a)
{
	if(tos>=(MAX-1))
		printf("stack is in over-flow condition \ncan't push any element!!");
	else
	stack_ele[++tos]=a;
}
char pop()
{
	if(tos==-1)
	{
		printf("stack is in under-flow condition \ncan't pop any element!!");
		return 0;
	}
	else
	return(stack_ele[tos--]);
}
int prein(char a)
{
	switch(a)
	{
		case '+':
		case '-': return(1);
			  break;
		case '*':
		case '/': return(3);
			  break;
		case '^': return(6);
			  break;
		case '(': return(9);
			  break;
		case ')': return(0);
			  break;
		default:  return(7);
			  break;
	}
}

int preout(char a)
{
	switch(a)
	{
		case '+':
		case '-': return(2);
			  break;
		case '*':
		case '/': return(4);
			  break;
		case '^': return(5);
			  break;
		case '(': return(0);
			  break;
		case ')': return(0);
			  break;
		default:  return(8);
			  break;
	}
}

int rank(char a)
{
	switch(a)
	{
		case '+':
		case '-': 
		case '*':
		case '/':
		case '^': return(-1);
			  break;
		case '(': return(0);
			  break;
		case ')': return(0);
			  break;
		default:  return(1);
			  break;
	}
}

int main()
{
	int k;
	printf("enter infix expression.\n");
	gets(a);
	push('(');
	a[strlen(a)]=')';
	for(k=0;k<strlen(a);k++)
	{
			a:
			{
			if(prein(a[k])>=preout(stack_ele[tos]))
			push(a[k]);
			else
			{
				char x;
				x=pop();
				polish[d]=x;
				d++;
				goto a;
			}
			}
	}
	for(k=0;k<strlen(a);k++)
	printf("%c",polish[k]);
	
}

