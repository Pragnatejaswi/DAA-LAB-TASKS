#include <stdio.h>
int main()
{
    int a[100],n,key,beg,end,mid,i;
    printf("enter no. of elemnts\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter key:");
    scanf("%d",&key);
    beg=0;
    end=n-1;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(a[mid]==key)
        {
            printf("Element found at position %d",mid+1);
            return 0;
        }
        else if(a[mid]<key)
        {
            beg=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    printf("Element not found");
    return 0;
}
