#include<stdio.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}
int maxCrossingSum(int arr[],int low,int mid,int high)
{
    int leftSum=-999999;
    int sum=0;
    int i;
    for(i=mid;i>=low;i--)
    {
        sum=sum+arr[i];

        if(sum>leftSum)
            leftSum=sum;
    }
    int rightSum=-999999;
    sum=0;
    for(i=mid+1;i<=high;i++)
    {
        sum=sum+arr[i];
        if(sum>rightSum)
            rightSum=sum;
    }
    return leftSum+rightSum;
}
int maxSubArray(int arr[],int low,int high)
{
    if(low==high)
        return arr[low];
    int mid=(low+high)/2;
    int leftMax=maxSubArray(arr,low,mid);
    int rightMax=maxSubArray(arr,mid+1,high);
    int crossMax=maxCrossingSum(arr,low,mid,high);
    return max(max(leftMax,rightMax),crossMax);
}
int main()
{
    int i,n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int result=maxSubArray(arr,0,n-1);
    printf("Maximum subarray sum = %d\n",result);
    return 0;
}
