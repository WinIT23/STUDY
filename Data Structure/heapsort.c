#include<stdio.h>
#include<stdlib.h>
int size;
void exchange(int* x,int* y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void heapify(int A[],int n,int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if (l<n && A[l]>A[largest])
		largest=l;
	if (r<n && A[r]>A[largest])
		largest=r;
	if (largest!=i)
	{
		exchange(&A[i],&A[largest]);
		heapify(A,n,largest);
	}
}

void HeapSort(int A[], int n)
{
	int i;
	for (i=((n/2)-1);i>=0;i--)
		heapify(A, n, i);
	for (i=n-1;i>=0;i--)
	{
		exchange(&A[0],&A[i]);
		heapify(A,i,0);
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
	HeapSort(A,size);
	printf("Sorted array is:\n");
	for(i=0;i<size;i++)
		printf("%d ",A[i]);
}
