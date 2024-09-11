#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x[20];

int place(int k, int i) {
    int j;
    for (j = 1; j <= k - 1; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

void printQueen(int n) {
    int i, j;
    static int count = 1;
    printf("\n\nSolution %d is - \n\n", count++);
    for (i = 1; i <= n; ++i)
        printf("\t%d", i);
    for (i = 1; i <= n; ++i) {
        printf("\n\n%d", i);
        for (j = 1; j <= n; ++j) {
            if (x[i] == j)
                printf("\tQ");
            else
                printf("\t-");
        }
    }
}

void NQueen(int k, int n) {
    int i;
    for (i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                printQueen(n);
            } else {
                NQueen(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("\nN-QUEEN PROBLEM\n");
    printf("\nEnter the number of queens to be placed - ");
    scanf("%d", &n);
    
    if (n < 4) {
        printf("\nNo solutions possible for N < 4.\n");
        return 0;
    }

    NQueen(1, n);
    return 0;
}
