#include<stdio.h>
int main()
{
    int x,n;
    int sum=0,power=1;
    printf("Enter X: ");
    scanf("%d",&x);
    printf("Enter n: ");
    scanf("%d",&n);
    int i;
    for(i=0;i<=n;i++)
	{
        sum=sum+power;
        power=power*x;
    }
    printf("Sum = %d\n",sum);
    return 0;
}
