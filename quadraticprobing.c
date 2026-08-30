#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
void insert(int key)
{
    int index, i;
    index = key % SIZE;
    for (i = 0; i < SIZE; i++)
    {
        int pos = (index + i * i) % SIZE;

        if (hashTable[pos] == -1)
        {
            hashTable[pos] = key;
            return;
        }
    }
   printf("Hash table is full\n");
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
