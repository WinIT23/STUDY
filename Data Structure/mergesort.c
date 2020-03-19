#include<stdio.h>
#include<stdlib.h>
int size;
void Merge(int A[],int l,int u,int m)
{
	int temp[size];
	int i,j,k;
	i=l;
	j=m+1;
	k=0;

	while(i<=m && j<=u)
	{
		if(A[i]<A[j]) temp[k++]=A[i++];
		else temp[k++]=A[j++];
	}
	while(i<=m)
		temp[k++]=A[i++];
	while(j<=u)
		temp[k++]=A[j++];

	for(i=l,j=0;i<=u;i++,j++)
		A[i]=temp[j];
}
void MergeSort(int A[],int l,int u)
{
	int m;
	if(l<u)
	{
		m=(l+u)/2;
		MergeSort(A,l,m);
		MergeSort(A,m+1,u);
		Merge(A,l,u,m);
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
	MergeSort(A,0,size-1);
	printf("Sorted array is:\n");
	for(i=0;i<size;i++)
		printf("%d ",A[i]);
}
