#include <stdio.h>
#include <stdlib.h>
int tree[2050], i, j, k;
void segmentalloc(int, int);
void makedivided(int);
void makefree(int);
void printing(int, int);
int place(int);
int power(int, int);

int main()
{
    int totsize, req, ch;
    printf("Enter the total memory size available \n");
    scanf("%d", &totsize);
    while (1)
    {
        printf("1. ALLOCATE MEMORY  2. FREE MEMORY   3. TREE MAP STRUCTURE   4. EXIT \n");
        printf("enter your choice \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("MEMORY ALLOCATION \n");
            printf("enter the size of memory to be allocated \n");
            scanf("%d", &req);
            segmentalloc(totsize, req);
            break;
        case 2:
            printf("enter the size to be delted \n");
            scanf("%d", &req);
            makefree(req);
            break;
        case 3:
            printf("display the tree \n");
            printing(totsize, 0);
            break;
        default:
            exit(0);
        }
    }
}
void segmentalloc(int totsize, int req)
{
    int i;
    int size = totsize, flevel = 0;
    if (req > size)
    {
        printf("not enough memory \n");
        return;
    }
    while (1)
    {
        if (req < size && req > size / 2)
            break;
        else
        {
            size = size / 2;
            flevel++;
        }
    }
    for (i = power(2, flevel) - 1; i <= power(2, flevel + 1) - 2; i++)
    {
        if (tree[i] == 0 && place(i))
        {
            tree[i] = req;
            makedivided(i);
            printf("successful allocation \n");
            break;
        }
        if (i == power(2, flevel + 1) - 1)
        {
            printf("doesnt have enough memory \n");
        }
    }
}
void makedivided(int node)
{
    while (node != 0)
    {
        node = (node % 2 == 0) ? (node - 1) / 2 : node / 2;
        tree[node] = 1;
    }
}
int place(int node)
{
    while (node != 0)
    {
        node = (node % 2 == 0) ? (node - 1) / 2 : node / 2;
        if (tree[node] > 1)
            return 0;
    }
    return 1;
}

void makefree(int req)
{
    int node = 0;
    while (1)
    {
        if (tree[node] == req)
            break;
        else
            node++;
    }
    tree[node] = 0;
    while (node != 0)
    {

        if (tree[node] == 0 && tree[(node % 2 == 0) ? (node - 1) : (node + 1)] == 0)
        {
            tree[(node % 2 == 0) ? (node - 1) / 2 : node / 2] = 0;
            node = (node % 2 == 0) ? (node - 1) / 2 : node / 2;
        }
        else
            break;
    }
}
int power(int x, int y)
{
    int ans = 1;
    for (i = 0; i < y; i++)
        ans *= x; // u had put i in place of x. x^y find karna hai. factorial nahi
    return ans;
}
void printing(int tot, int node)
{
    int llimit, ullimit, perm = 0, tab;
    if (node == 0)
        perm = 1;
    else if (node % 2 == 0)
        perm = (tree[(node - 1) / 2] == 1) ? 1 : 0;
    else
        perm = (tree[node / 2] == 1) ? 1 : 0;
    if (perm)
    {
        llimit = ullimit = tab = 0;
        while (1)
        {
            if (node >= llimit && node <= ullimit)
                break;
            else
            {
                tab++;
                printf(" ");
                llimit = ullimit + 1;
                ullimit = 2 * ullimit + 2;
            }
        }
        printf("%d \n", tot / power(2, tab));
        if (tree[node] > 1)
            printf("---> ALLOCATES  %d", tree[node]);
        else if (tree[node] == 1)
            printf("---> DIVIDED ");
        else
            printf("---> FREE ");
        printing(tot, 2 * node + 1);
        printing(tot, 2 * node + 2);
    }
}
