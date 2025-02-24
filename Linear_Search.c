#include<stdio.h>
void main()
{
int a[10],n,i,key,flag=0;
printf("enter the array size");
scanf("%d",&n);
printf("enter the array element");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("enter the element to be searched");
scanf("%d",&key);
for(i=0;i<n;i++)
{
if(a[i]==key)
{flag=1;
break;
}
}
if(flag==1)
printf("%d is preesnt at location %d",key,i);
else
printf("element notfound");
}


