#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char ch;
    int freq;
    struct Node *left, *right;
};
struct Node *newNode(char ch, int freq)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->ch = ch;
    temp->freq = freq;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void sort(struct Node *arr[], int n)
{
    int i, j;
    struct Node *temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j]->freq > arr[j + 1]->freq)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void printCodes(struct Node *root, int code[], int top)
{
    int i;
    if (root->left != NULL)
    {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }
    if (root->right != NULL)
    {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }
    if (root->left == NULL && root->right == NULL)
    {
        printf("%c: ", root->ch);
        for (i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}
int main()
{
    struct Node *arr[100];
    struct Node *left, *right, *parent;
    int freq[100], n, i, code[100];
    char ch[100];
    printf("Enter number of characters: ");
    scanf("%d", &n);
    printf("Enter characters and their frequencies:\n");
    for (i = 0; i < n; i++)
    {
        scanf(" %c %d", &ch[i], &freq[i]);
        arr[i] = newNode(ch[i], freq[i]);
    }
    while (n > 1)
    {
        sort(arr, n);
        left = arr[0];
        right = arr[1];
        parent = newNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        for (i = 2; i < n; i++)
            arr[i - 2] = arr[i];
        arr[n - 2] = parent;
        n--;
    }
    printf("\nHuffman Codes:\n");
    printCodes(arr[0], code, 0);
    return 0;
}
