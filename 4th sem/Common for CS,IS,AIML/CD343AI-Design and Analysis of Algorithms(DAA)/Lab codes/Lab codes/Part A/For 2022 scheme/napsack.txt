#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    
    return K[n][W]; // Return the maximum value
}

int main() {
    int val[10], wt[10], val_count, W;
    
    printf("Enter value count (up to 10): ");
    scanf("%d", &val_count);
    
    if (val_count <= 0 || val_count > 10) {
        printf("Invalid input for value count. It should be between 1 and 10.\n");
        return 1; // Exit with an error code
    }

    for (int i = 0; i < val_count; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &val[i], &wt[i]);
    }

    printf("Enter the maximum weight (W): ");
    scanf("%d", &W);

    int result = knapsack(W, wt, val, val_count);

    printf("Maximum value: %d\n", result);

    return 0;
}
