#include <stdio.h>
void main()
{
int a[10],n,i,j=0,temp,min,count=0;
printf("enter total count of array");
scanf("%d",&n);
printf("enter array element ");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
if(a[j]<a[min])
{
min=j;
temp=a[min];
a[min]=a[i];
a[i]=temp;
 }
}
count=i;
}
printf("sorted array is ");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]); 
}
printf("No. of passes is %d",count);
}
