#include <math.h>
#include <stdio.h>
void main ()
{int a[10]; 
int n;
    int i, key, j;
    int inc=0; 
    printf("enter the totl number of array: ");
    scanf("%d",&n);
    printf("enter the elements in array:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for (i =1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        inc++;
    }
    printf("\nsorted array is:");
    for(i=0;i<n;i++)
    {
    printf("%d\t",a[i]);
}
printf("\nthe total number of passes is %d",inc);

}
