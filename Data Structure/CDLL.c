#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *left,*right;
};
void insert_end(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *newer;
	newer=(struct node*)malloc(sizeof(struct node));
	if(start->right==NULL)
	{
		start->right=temp;
		start->left=temp;
		temp->left=start;
		temp->right=start;
		temp->info=data;
		return;
	}
	temp->right=start->right;
	while(temp->right!=start)
	{
		temp=temp->right;
	}
	newer->right=start;
	newer->left=temp;
	start->left=newer;
	temp->right=newer;
	newer->info=data;
}
void insert_begin(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *newer;
	newer=(struct node*)malloc(sizeof(struct node));
	if(start->right==NULL)
	{
		start->right=temp;
		start->left=temp;
		temp->left=start;
		temp->right=start;
		temp->info=data;
		return;
	}
	temp->right=start->right;
	while(temp->right!=start)
    {
        temp=temp->right;
    }
    newer->right=start->right;
    newer->left=start;
    start->right=newer;
    start->left=temp;
    newer->info=data;
}
void delete_x(struct node *start,int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *next;
	next=(struct node*)malloc(sizeof(struct node));
	if(start->right==NULL)
	{
		printf("list empty");
		return;
	}
	temp->right=start->right;
	while(temp->right->right!=start && temp->right->info!=x)
	{
		temp=temp->right;
	}
	if(temp->right->right==start && temp->right->info!=x)
	{
		printf("element %d not found in link.\n",x);
		return;
	}
	next=temp->right->right;
	temp->right=next;
	if(start->right->info==x)
		start->right=next;
}
void traverse(struct node *start)
{
    struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->right=start->right;
	while(temp->right!=start)
	{
		printf(" %d <=>",temp->right->info);
		temp=temp->right;
	}
	printf(" START\n");
}
void insert_after(struct node *start,int x,int y)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *next;
	next=(struct node*)malloc(sizeof(struct node));
	temp->right=start->right;
	while(temp->right!=start && temp->info!=y)
		temp=temp->right;
	if(temp->right==start && temp->info!=y)
	{
		printf("element %d not found",y);
		return;
	}
	next->right=temp->right;
	next->left=temp->right;
	temp->right->right->left=next;
	temp->right=next;
	next->info=x;
}
void delete_before(struct node *start,int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *next;
	next=(struct node*)malloc(sizeof(struct node));
	temp->right=start->right;
	while(temp->right!=start && temp->right->right->info!=y)
		temp=temp->right;
	if(temp->right==start && temp->info!=y)
	{
		printf("element %d not found",y);
		return;
	}
	

}
int main()
{
	int choice=1,data;
	struct node *start;
	start=(struct node*)malloc(sizeof(struct node));
	start->info=0;
	start->right=NULL;
	start->left=NULL;
	while(choice)
	{
		printf("\nenter\n1->insert_end\n2->delete_x\n3->insert_begin\n4->traverse\n5->insert_after\n0->exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: system("cls");
					printf("\nenter element:\n");
					scanf("%d",&data);
					insert_end(start,data);
					break;
			case 2: system("cls");
					printf("\nenter element:\n");
					scanf("%d",&data);
					printf("\ndeleting...\n");
					delete_x(start,data);
					break;
			case 3: system("cls");
					printf("\nenter element:\n");
					scanf("%d",&data);
					insert_begin(start,data);
					break;
			case 4: printf("\ndisplaying...\n");
					traverse(start);
					break;
			case 5: printf("\nenter after which you want to enter an element:\n");
					scanf("%d",&choice);
					printf("\nenter element to be added:\n");
					scanf("%d",&data);
					insert_after(start,data,choice);
					break;
		}
	}
}
