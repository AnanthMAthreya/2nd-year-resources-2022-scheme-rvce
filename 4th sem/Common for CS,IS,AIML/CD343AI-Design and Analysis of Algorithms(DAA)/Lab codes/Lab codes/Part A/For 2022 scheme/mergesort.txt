#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void splitmerge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *ln = (int *)malloc(n1 * sizeof(int));
    int *rn = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) {
        ln[i] = arr[l + i];
    }
    for (i = 0; i < n2; i++) {
        rn[i] = arr[m + 1 + i];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (ln[i] <= rn[j]) {
            arr[k] = ln[i];
            i++;
        } else {
            arr[k] = rn[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = ln[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rn[j];
        j++;
        k++;
    }

    free(ln);
    free(rn);
}

void sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        sort(arr, l, m);
        sort(arr, m + 1, r);

        splitmerge(arr, l, m, r);
    }
}

int main() {
    double time;
    clock_t start, end;
    int size;
    printf("Enter size of array:");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    start = clock();
    sort(arr, 0, size - 1);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime: %lf", time);

    return 0;
}
