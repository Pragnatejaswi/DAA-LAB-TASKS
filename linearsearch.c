#include<stdio.h>
int main()
{
    int arr[100],size,i,searchKey,found=0;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&size);
    printf("Enter %d integers:\n",size);
    for (i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the value to search for: ");
    scanf("%d",&searchKey);
    for (i=0;i<size;i++)
    {
        if(arr[i]==searchKey)
        {
            printf("Element %d found at index %d (Position %d)\n",searchKey,i,i+1);
            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("Element %d is not present in the array\n",searchKey);
    }
    return 0;
}
