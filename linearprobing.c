#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
void insert(int key)
{
    int index = key % SIZE;
    while (hashTable[index] != -1)
        index = (index + 1) % SIZE;
    hashTable[index] = key;
}
void display()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}
int main()
{
    int i, n, key;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }
    printf("Hash Table:\n");
    display();
    return 0;
}
