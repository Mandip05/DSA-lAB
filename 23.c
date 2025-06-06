#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000  // Define array size

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge function for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to generate a random array
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr1 = (int*)malloc(SIZE * sizeof(int));
    int *arr2 = (int*)malloc(SIZE * sizeof(int));
    srand(time(0));

    generateRandomArray(arr1, SIZE);
    for (int i = 0; i < SIZE; i++) {
        arr2[i] = arr1[i];
    }

    clock_t start, end;
    double quickSortTime, mergeSortTime;

    start = clock();
    quickSort(arr1, 0, SIZE - 1);
    end = clock();
    quickSortTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort Execution Time: %f seconds\n", quickSortTime);

    start = clock();
    mergeSort(arr2, 0, SIZE - 1);
    end = clock();
    mergeSortTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort Execution Time: %f seconds\n", mergeSortTime);

    printf("Sorted Array (Quick Sort first 10 elements): ");
    printArray(arr1, 10);

    printf("Sorted Array (Merge Sort first 10 elements): ");
    printArray(arr2, 10);

    free(arr1);
    free(arr2);
    getchar();
    getchar();
    return 0;
}
