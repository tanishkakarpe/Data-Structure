#include<stdio.h>
void main()
{
int arr[10],i,n,key,low,mid,high;
printf("enter the no of elements in array \n");
scanf("%d",&n);
printf("enter the array elements\n");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("enter the element to be searched\n");
scanf("%d",&key);
low=0;
high=n-1;
mid=(low+high)/2;
while(low<=high)
{ if (arr[mid]<key)
low=mid+1;
else if(arr[mid]==key)
{printf("%d at location %d /n",key,mid);
break;
}
else
high=mid-1;
mid=(low+high)/2;
}
if(low>high)
printf("not found %d is not in the array\n",key);
}
