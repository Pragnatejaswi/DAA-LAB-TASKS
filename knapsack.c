#include <stdio.h>
struct Item
{
    int weight;
    int profit;
    float ratio;
};
int main()
{
    int n,capacity;
    int i,j;
    float maxProfit = 0;
    struct Item item[20];
    struct Item temp;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("\nEnter weight and profit of each item:\n");
    for(i=0;i<n;i++)
    {
        printf("Item %d: ",i+1);
        scanf("%d %d", &item[i].weight, &item[i].profit);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }
    printf("\nEnter capacity of knapsack: ");
    scanf("%d", &capacity);
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(item[i].ratio<item[j].ratio)
            {
                temp=item[i];
                item[i]=item[j];
                item[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(capacity>=item[i].weight)
        {
            capacity=capacity-item[i].weight;
            maxProfit=maxProfit+item[i].profit;
        }
        else
        {
            maxProfit=maxProfit+item[i].ratio*capacity;
            capacity=0;
            break;
        }
    }
    printf("\nMaximum Profit = %.2f\n", maxProfit);
    return 0;
}
