#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info,x,y,z;
	struct node *link;
};

// void insert_front(struct node *start,int data,int xp,int yp,int zp)
// {
// 	struct node *temp;
// 	temp=(struct node*)malloc(sizeof(struct node));
// 	if(start->link==NULL)
// 	{
// 		temp->info=data;
// 		temp->link=NULL;
// 		start->link=temp;
// 		return;
// 	}
// 	temp->link=start->link;
// 	temp->info=data;
// 	start->link=temp;
// }

void insert_order1(struct node *start,int data,int xp,int yp,int zp)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	if(start->link==NULL)
	{
		temp->x=xp;
		temp->y=yp;
		temp->z=zp;
		temp->link=NULL;
		start->link=temp;
		temp->info=data;
		return;
	}

	temp->link=start->link;
	while(temp->link->x<xp  && temp->link->link!=NULL)
	{
		temp=temp->link;
	}
	if(temp->link->x==xp)
	while(temp->link->y<yp  && temp->link->link!=NULL)
	{
		if(temp->link->x!=xp)
			break;
		temp=temp->link;
	}
	if(temp->link->y==yp)	
	while(temp->link->z<zp  && temp->link->link!=NULL)
	{
		if(temp->link->x!=xp)
			break;
		temp=temp->link;
	}

	if(temp->link->x==xp && temp->link->y==yp && temp->link->z==zp)
	{
		temp->link->info+=data;
		return;
	}


	if(temp->link->link==NULL && (xp>temp->link->x || yp>temp->link->y || zp>temp->link->z))
		temp=temp->link;
	new->link=temp->link;
	temp->link=new;
	new->x=xp;
	new->y=yp;
	new->z=zp;
	new->info=data;
}
void traverse(struct node *start)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=start->link;
	while(temp!=NULL)
	{
		printf(" %d(%d,%d,%d) =>>",temp->info,temp->x,temp->y,temp->z);
		temp=temp->link;
	}
	printf(" NULL\n");
}

int main()
{
	int coef,x,y,z;
	struct node *start;
	start=(struct node *)malloc(sizeof(struct node));
	start->link=NULL;
	while(1)
	{
		printf("enter co-efficient of polynomial: \n");
		scanf("%d",&coef);
		printf("enter power of x: \n");
		scanf("%d",&x);
		printf("enter power of y: \n");
		scanf("%d",&y);
		printf("enter power of z: \n");
		scanf("%d",&z);
		insert_order1(start,coef,x,y,z);
		traverse(start);
		printf("any other number to carry on & enter 1 to exit: \n");
		scanf("%d",&coef);
		if(coef==1)
			break;
	}
}
