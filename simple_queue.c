#include<stdio.h>
#define size 5
int que[size],rear=-1,front=-1;
int x,choice,ch,i;
void main()
{
do
{
printf("menu");
printf("\n1.INSERTION\n2.DELETION\n3.DISPLAY\n4.exit");
printf("\nenter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
enqueue();
break;
case 2:
deque();
break;
case 3:
display();
break;
case 4:
exit(0);
break;
}
printf(" do you want to continue(1/0)");
scanf("%d",&choice);
}
while(choice==1);
}


void enqueue()
{
if(rear==size-1)
printf("queue is full");
else
{
printf("enter the element");
scanf("%d",&x);
rear++;
que[rear]=x;
}
}


void deque()
{
if(rear==front)
{
printf("queue is empty");
}
else
{
front++;
printf("element deleted is %d",que[front]);
}
}


void display()
{
if(rear==front)
printf("queue is empty");
else
{
for(i=front+1;i<=rear;i++)
printf("%d\t",que[i]);
}
}
