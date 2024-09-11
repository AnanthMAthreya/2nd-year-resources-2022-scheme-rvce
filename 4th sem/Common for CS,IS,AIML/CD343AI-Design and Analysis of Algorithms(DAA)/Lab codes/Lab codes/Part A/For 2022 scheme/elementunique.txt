#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int s;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int uniqueness(int arr[]) {
    for (int i = 0; i < s - 1; i++) {
        if (arr[i] == arr[i + 1])
            return 1;
    }
    return 0;  // Only return 0 if you've checked the entire array and found no duplicates
}

int main() {
    double time;
    clock_t start, end;

    printf("Enter size of array:");
    scanf("%d", &s);
    int arr[s];
    printf("Enter elements:\n");
    for (int i = 0; i < s; i++) {
        scanf("%d", &arr[i]);
    }

    start = clock();
    quickSort(arr, 0, s - 1);
    end = clock();

    printf("Sorted array: \n");
    for (int i = 0; i < s; i++)
        printf("%d ", arr[i]);

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime: %lf", time);

    int a = uniqueness(arr);
    if (a == 1)
        printf("\nNot unique\n");
    else
        printf("\nUnique\n");
    return 0;
}
