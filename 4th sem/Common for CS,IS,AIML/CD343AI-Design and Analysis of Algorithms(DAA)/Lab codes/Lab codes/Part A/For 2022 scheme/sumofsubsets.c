#include<stdio.h>
#include<stdlib.h>

int w[10], x[10], d;

void sum_subset(int s, int k, int r);

int main()
{
    int n, i, sum = 0;
    printf("Read no.of elements: ");
    scanf("%d", &n);
    
    printf("Read elements in increasing order\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    
    printf("Read the subset max value: ");
    scanf("%d", &d);
    
    if(sum < d || w[0] > d)
    {
        printf("No solutions\n");
        exit(0);
    }
    
    sum_subset(0, 0, sum);  // Start with the first element
    return 0;
}

void sum_subset(int s, int k, int r)
{
    int i;
    static int b = 1;
    
    if(s + w[k] == d)
    {
        printf("Subset %d: ", b++);
        for(i = 0; i <= k; i++)
            if(x[i] == 1)
                printf("%d\t", w[i]);
        printf("%d\n", w[k]);  // Include the current element
    }
    else if(s + w[k] + w[k+1] <= d)
    {
        x[k] = 1;
        sum_subset(s + w[k], k + 1, r - w[k]);
        x[k] = 0;  // Backtrack
    }
    
    if((s + r - w[k] >= d) && (s + w[k+1] <= d))
    {
        x[k] = 0;
        sum_subset(s, k + 1, r - w[k]);
    }
}
