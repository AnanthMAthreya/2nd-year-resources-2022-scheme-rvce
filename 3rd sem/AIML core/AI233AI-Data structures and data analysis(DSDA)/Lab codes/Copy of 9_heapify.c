#include <stdio.h>
void Insert(int H[], int n)
{
    int i = n, temp;
    temp = H[i];
    while (i > 1 && temp > H[i / 2])
    {
        H[i] = H[i / 2];
        i = i / 2;
    }
    H[i] = temp;
}
int main()
{
    // int H[10] = {0, 14, 15, 5, 20, 30, 8, 40};
    int n, i;
    int H[10];
    H[0] = 0;
    printf("Enter number of elements ");
    scanf("%d", &n);

    printf("enter numbers now");

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &H[i]);
    }
    for (i = 2; i <= n; i++)
        Insert(H, i);

    for (i = 1; i <= n; i++)
        printf("%d ", H[i]);
    printf("\n");

    return 0;
}