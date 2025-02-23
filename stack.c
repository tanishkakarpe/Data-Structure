#include<stdio.h>
#include<stdlib.h>
int a[10],top=-1,n,z,i;
void main()
{
int choice,ch,i;
printf("enter the stack size:");
scanf("%d",&n);
do
{
printf("\n 1.Push \n2.Pop \n3.Display \n4.Exit");
printf("\nenter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
  push();
break;
case 2:
  pop();
break;
case 3:
  display();
break;
case 4:
exit(0);
break;
}
printf("\nDo you want to continue(1/0)\n");
scanf("%d",&ch);
}
while(ch==1);
}
//Code for push function 
void push()
{
if(top==n-1)
{
printf("stack overflow");
}
else
{
top++;
printf("enter element ");
scanf("%d",&z);
a[top]=z;
}
}
//Code for pop function 
void pop()
{
if (top==-1)
printf("stack underflow");
else
{
printf("the element is %d ",a[top]);
top--;
}
}
//Code for display function 
void display()
{
if(top==-1)
printf("stack is empty");
else 
for(i=top;i>=0;i--)
printf("%d ",a[i]);
}
