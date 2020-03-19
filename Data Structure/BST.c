#include<stdio.h>
struct node
{
	int info;
	struct node *left,*right;
};

insert(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(start==NULL)
	{
	    start=temp;
		start->info=data;
		start->right=NULL;
		start->left=NULL;
		return;
	}
	temp=start;
	while(temp->right!=NULL || temp->left!=NULL)
	{
		if(temp->info>data)
			temp=temp->left;
		else if(temp->info>data)
			temp=temp->right;
	}
	if(temp->info>data)
			temp->right=data;
    else if(temp->info>data)
			temp->left=data;
}

traverse(struct node *start)
{
	if(start==NULL)
		return;
	traverse(start->left);
	printf("%d",start->info);
	traverse(start->right);
}
int main()
{
	struct node *start;
	start=(struct node *)malloc(sizeof(struct node));
	insert(start,0);
	insert(start,1);
	insert(start,2);
	insert(start,3);
	insert(start,4);
	printf("sdfg");
	traverse(start);
}
