#include<stdio.h>
#define MAX 100
int size=10;
struct data
{
	int rollno;
	double marks;
};
void update_mark(struct data *p,int roll,double mark)
{
    (*(p+(roll-1))).marks=mark;
}
void update_roll(struct data *p,int original_roll,int new_roll)
{
    (*(p+(original_roll-1))).rollno=new_roll;
}
void insert(struct data *p,int index,double mark,int roll)
{
    int i;
    for(i=0;i<(10-index);i++)
        (*(p+(10-i)+1))=(*(p+(10-i)));

    (*(p+index+1)).marks=mark;
    (*(p+index+1)).rollno=roll;
    size++;
}
void deletion(struct data *p,int index)
{
    int i;
    for(i=index;i<(11-index);i++)
        (*(p+index))=(*(p+index+1));
}
int main()
{
    struct data s[MAX];
    struct data *p;
    p=&s;
    int i=0;
    while(i<10)
    {
        (*(p+i)).rollno=i+1;
        (*(p+i)).marks=100/(i+1);
        i++;
    }
    i=0;
    update_mark(p,5,999);
    update_roll(p,5,456);
    insert(p,7,78979,20);
    insert(p,4,34534,45);
    insert(p,1,9999,99);
    while(i<size)
    {
        printf("rollno: %d marks: %lf\n",(*(p+i)).rollno,(*(p+i)).marks);
        i++;
    }
}
