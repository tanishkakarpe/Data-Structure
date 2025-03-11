#include<stdio.h>
#include<stdlib.h>
int a[10],top=-1;
void decimalTobinary(int no);
void pop();
void push(int no);
void main()
{
    int no;
printf("Enter the decimal no");
scanf("%d",&no);
 decimalTobinary(no);
}
void decimalTobinary(int no)
{
    if(no==0)
    return;
    while(no>0)
    {
        push(no%2);
        no=no/2;
    }
    while(top!=-1)
    {
        printf("%d",a[top]);
        pop();
    }
    
}
void push (int no)
{
    top++;
    a[top]=no;
}
void pop()
{
    top--;
}
