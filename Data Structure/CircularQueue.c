#include <stdio.h>
#include <stdlib.h>
#define MAX 200
int f=-1;
int r=-1;
int n;
int counter=0;
int q[MAX];
int item;

void insert(int a)
{
    if(counter==n)
    {
        printf("queue is full.\n");
    }
    else if(r==-1 && f==-1)
    {
        r++;
        f++;
        q[r]=a;
        counter++;
    }
    else
    {
        r++;
        if(r==n)
            r=0;
        q[r]=a;
        counter++;
    }

}

void delete()
{
    if(f==-1)
    {
        printf("queue is empty.\n");
        return;
    }
    else if(f==r)
    {
        item=q[f];
        f=-1;
        r=-1;
        counter--;
    }
    else
    {
        item=q[f];
        f++;
        if(f==n)
        {
            f=0;
        }
        counter--;
    }
}

void display()
{
    int i,j;
    printf("\n displaying...\n");
    for(i=0,j=f;i<counter;i++,j++)
    {
        if(j==n)
            j=0;
        printf("\n  %d  \n",q[j]);
    }
}

int main()
{
    int i,temp;
    int k=0;
    printf("enter the size of queue: \n");
    scanf("%d",&n);
    do
    {
        printf("\n1 ---> insert \n2 ---> delete \n3 ---> display \n4 ---> exit\n");
        scanf("%d",&temp);
        switch(temp)
        {
            case 1: printf("enter element: \n");
                    int a;
                    scanf("%d",&a);
                    insert(a);
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: k=-100;
                    break;
        }
    }while(k!=-100);
    return 0;
}
