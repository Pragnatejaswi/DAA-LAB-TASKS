#include <stdio.h>
#define SIZE 100
int main()
{
    int n, i, j, index;
    int a[SIZE], freq[SIZE];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        freq[i] = 1;
    for (i = 0; i < n; i++)
    {
        if (freq[i] == 0)
            continue;
        for (j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                freq[i]++;
                freq[j] = 0;
            }
        }
    }
    printf("Frequency of elements:\n");
    for (i = 0; i < n; i++)
    {
        if (freq[i] != 0)
            printf("%d : %d\n", a[i], freq[i]);
    }
    return 0;
}
