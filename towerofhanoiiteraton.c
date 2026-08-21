#include <stdio.h>
int main()
{
    int n, i, j, k, temp;
    int a[20], b[20], c[20];
    int topa = -1, topb = -1, topc = -1;
    int moves;
    printf("Enter no.of disks\n");
    scanf("%d", &n);
    for(i = n; i >= 1; i--)
        a[++topa] = i;
    moves = (1 << n) - 1;
    for(i = 1; i <= moves; i++)
    {
        if(i % 3 == 1)
        {
            if(topc == -1 || (topa != -1 && a[topa] < c[topc]))
            {
                temp = a[topa--];
                c[++topc] = temp;
                printf("Move disk %d from A to C\n", temp);
            }
            else
            {
                temp = c[topc--];
                a[++topa] = temp;
                printf("Move disk %d from C to A\n", temp);
            }
        }
        else if(i % 3 == 2)
        {
            if(topb == -1 || (topa != -1 && a[topa] < b[topb]))
            {
                temp = a[topa--];
                b[++topb] = temp;
                printf("Move disk %d from A to B\n", temp);
            }
            else
            {
                temp = b[topb--];
                a[++topa] = temp;
                printf("Move disk %d from B to A\n", temp);
            }
        }
        else
        {
            if(topc == -1 || (topb != -1 && b[topb] < c[topc]))
            {
                temp = b[topb--];
                c[++topc] = temp;
                printf("Move disk %d from B to C\n", temp);
            }
            else
            {
                temp = c[topc--];
                b[++topb] = temp;
                printf("Move disk %d from C to B\n", temp);
            }
        }
    }
    return 0;
}
