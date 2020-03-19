#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
void insert_end(struct node *start,int item)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	if(start->link==NULL)
	{
		temp->info=item;
		temp->link=NULL;
		start->link=temp;
		return;
	}
	temp=start;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	new->info=item;
	new->link=NULL;
	temp->link=new;
}
void delete_end(struct node *start)
{
	if(start->link==NULL)
	{
		printf("\nempty list.\n");
		return;
	}
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	if(start->link->link==NULL)
	{
		printf("delete last");
		temp->link=start->link;
		free(temp);
		start->link=NULL;
		return;
	}
	else
	{
		temp->link=start->link;
		while(temp->link->link!=NULL)
		{
			temp=temp->link;
		}
		new->link=temp->link;
		temp->link=NULL;
		free(new);
	}
}
void insert_front(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(start->link==NULL)
	{
		temp->info=data;
		temp->link=NULL;
		start->link=temp;
		return;
	}
	temp->link=start->link;
	temp->info=data;
	start->link=temp;
}
void delete_front(struct node *start)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(start->link==NULL)
	{
		printf("\nlist is empty.\n");
		return;
	}	
	temp->link=start->link;
	start->link=start->link->link;
	free(temp);
}
void traverse(struct node *start)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=start->link;
	while(temp!=NULL)
	{
		printf(" %d =>>",temp->info);
		temp=temp->link;
	}
	printf(" NULL\n");
}
void insert_order(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	if(start->link==NULL)
	{
		temp->info=data;
		temp->link=NULL;
		start->link=temp;
		return;
	}
	if(data<start->link->info)
	{
		insert_front(start,data);
		return;
	}
	temp->link=start->link;
	while(data>=temp->link->info & temp->link->link!=NULL)
	{
		temp=temp->link;
	}
	if(temp->link->link==NULL && data>temp->link->info)
		temp=temp->link;
	new->link=temp->link;
	temp->link=new;
	new->info=data;
}

void insert_after(struct node *start,int x,int y)
{
	int flag=0;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	if(start->link==NULL)
	{
		printf("list empty,%d is not present in list.\n",y);
		return;
	}
	temp->link=start->link;
	temp=temp->link;
	while(temp->info!=y)
	{
		if(temp->link==NULL)
		{
			printf("%d is not present in list.\n",y);
			flag=1;
			break;
		}
		temp=temp->link;
	}
	if(!flag)
	{
		new->info=x;
		if(temp->link!=NULL)
		new->link=temp->link;
		else
		new->link=NULL;
		temp->link=new;
	}
}

void insert_before(struct node *start,int x,int y)
{
	int flag=0;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	if(start->link==NULL)
	{
		printf("list empty,%d can not be present in list.\n",y);
		return;
	}
	temp->link=start->link;
	if(start->link->info==y)
	{
		insert_front(start,x);
		return;
	}
	temp=temp->link;
	while(temp->link->info!=y)
	{
		if(temp->link->link==NULL && temp->link->info!=y)
		{
			printf("traversed list; %d is not present in list.\n",y);
			flag=1;
			break;
		}
		temp=temp->link;
	}
	if(!flag)
	{
		new->info=x;
		new->link=temp->link;
		temp->link=new;
	}
}
int main()
{
	int data,choice=1;;
	struct node *start;
	start=(struct node*)malloc(sizeof(struct node));
	start->info=0;
	start->link=NULL;
	while(choice)
	{
		printf("\nenter\n1->insert_end\n2->delete_end\n3->insert_front\n4->delete_front\n5->traverse\n6->insert_order\n7->insert_after\n8->insert_before\n0->exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nenter element:\n");
					scanf("%d",&data);
					insert_end(start,data);
					break;
			case 2: printf("\ndeleting...\n");
					delete_end(start);
					break;
			case 3: printf("\nenter element:\n");
					scanf("%d",&data);
					insert_front(start,data);
					break;
			case 4: printf("\ndeleting...\n");
					delete_front(start);
					break;
			case 5: printf("\ndisplaying...\n");
					traverse(start);
					break;
			case 6: printf("\nenter element:\n");
					scanf("%d",&data);
					insert_order(start,data);
					break;
			case 7: printf("\nenter element after which you want to enter data:\n");
					scanf("%d",&choice);
					printf("enter element to be added after %d:\n",choice);
					scanf("%d",&data);
					insert_after(start,data,choice);
					break;
			case 8: printf("\nenter element before which you want to enter data:\n");
					scanf("%d",&choice);
					printf("enter element to be added before %d:\n",choice);
					scanf("%d",&data);
					insert_before(start,data,choice);
					break;
		}
	}
}