#include<stdio.h>
void main()
{
int a[10], i,j, temp,n,passes=0;
 printf("enter total count of array:");
scanf("%d",&n);
printf("\n Enter array the element:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
{
 for(i=0;i<n-1;i++)
 {
   for(j=0;j<n-i-1;j++)
  { 
     if(a[j]>a[j+1])
     {
       temp=a[j];
       a[j]=a[j+1];
       a[j+1]=temp;
     }
    }
passes++;
 }
}
printf("\nThe sorted array is:");
for(i=0;i<n;i++)
{
    printf("%d\t",a[i]);
}
printf("\nThe number of passes required to sort the array %d",passes);
}
