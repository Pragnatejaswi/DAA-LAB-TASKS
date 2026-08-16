#include<stdio.h>
int power(long long x,int n)
{
    long long result = 1;
    while(n>0)
	{
        if(n%2==1)
		{
            result=result*x;
        }
        x=x*x;
        n=n/2;
    }
    return result;
}
int main()
{
    int x,sum;
    int n;
    printf("Enter X: ");
    scanf("%d",&x);
    printf("Enter n: ");
    scanf("%d",&n);
    if(x==1)
	{
        sum=n+1;
    }
	else
	{
        int p=power(x,n+1);
        sum=(p-1)/(x-1);
    }
    printf("Sum = %d\n", sum);
    return 0;
}
