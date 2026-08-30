#include <stdio.h>
#define SIZE 100
int hashTable[SIZE];
int hash(int key)
{
    if (key < 0)
        key = -key;
    return key % SIZE;
}
int main()
{
    int n, T, i, x, index, found = 0;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter target value: ");
    scanf("%d", &T);
    for (i = 0; i < n; i++)
    {
        x = T - a[i];
        index = hash(x);
        if (hashTable[index] == x)
        {
            found = 1;
            break;
        }
        index = hash(a[i]);
        while (hashTable[index] != -1 && hashTable[index] != a[i])
            index = (index + 1) % SIZE;
        hashTable[index] = a[i];
    }
    if (found)
        printf("Pair exists\n");
    else
        printf("Pair does not exist\n");
    return 0;
}
