#include<stdio.h>
int min,max;
void findMinMax(int a[],int low,int high)
{
    int mid;
    if(low==high)
    {
        min=max=a[low];
    }
    else if(low==high-1)
    {
        if(a[low]<a[high])
        {
            min=a[low];
            max=a[high];
        }
        else
        {
            min=a[high];
            max=a[low];
        }
    }
    else
    {
        mid=(low+high)/2;
        findMinMax(a,low,mid);
        int leftMin=min;
        int leftMax=max;
        findMinMax(a,mid+1,high);
        int rightMin=min;
        int rightMax=max;
        min=(leftMin<rightMin)?leftMin:rightMin;
        max=(leftMax>rightMax)?leftMax:rightMax;
    }
}
int main()
{
    int n,i;
    int a[100];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    findMinMax(a,0,n-1);
    printf("Minimum element=%d\n",min);
    printf("Maximum element=%d\n",max);
    return 0;
}
