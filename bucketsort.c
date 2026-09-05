#include <stdio.h>
int main()
{
    int a[100], bucket[100][100], count[100] = {0};
    int n, i, j, k, b, max;
	printf("enter no.of elements\n");
    scanf("%d", &n);
    printf("enter %d elements\n",n); 
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    b = max + 1;
    for (i = 0; i < n; i++)
        bucket[a[i]][count[a[i]]++] = a[i];
    k = 0;
    for (i = 0; i < b; i++)
    {
        for (j = 0; j < count[i]; j++)
            a[k++] = bucket[i][j];
    }
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
