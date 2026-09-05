#include <stdio.h>
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int i = low, j = high;
        int pivot = a[low];
        while (i < j)
        {
            while (a[i] <= pivot && i < high)
                i++;
            while (a[j] > pivot)
                j--;
            if (i < j)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        a[low] = a[j];
        a[j] = pivot;
        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}
int main()
{
   int a[100], n, i;
    printf("enter no.of elements\n");
    scanf("%d", &n);
    printf("enter %d elements\n",n); 
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quickSort(a, 0, n - 1);
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
