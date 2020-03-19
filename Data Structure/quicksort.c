#include<stdio.h>
#include<stdlib.h>
int size;
void exchange(int* x,int* y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int position(int A[],int l,int u)
{
	int i=l-1;
	int j;
	int key=A[u];
	for(j=l;j<u;j++)
	{
		if(A[j]<=key)
		{
			i++;
			exchange(&A[i],&A[j]);
		}
	}
	exchange(&A[i+1],&A[u]);
	return (i+1);
}
void quicksort(int A[],int l,int u)
{
	if(l<u)
	{
		int p=position(A,l,u);
		quicksort(A,l,p-1);
		quicksort(A,p+1,u);
	}
}
void main()
{
	int i;
	printf("Enter size of array : ");
	scanf("%d",&size);
	printf("Enter elements of array:\n");
	int* A=(int *)malloc(size*sizeof(int));
	for(i=0;i<size;i++)
		scanf("%d",&A[i]);
	quicksort(A,0,size-1);
	printf("Sorted array is:\n");
	for(i=0;i<size;i++)
		printf("%d ",A[i]);
}
