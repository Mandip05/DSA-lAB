#include <stdio.h>

// Function to perform Insertion Sort on the array
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1] that are greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    // Example list of customer IDs
    int customerIDs[] = {1084, 1000, 1066, 5069, 3045};
    int n = sizeof(customerIDs) / sizeof(customerIDs[0]);

    printf("Original Customer IDs:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", customerIDs[i]);
    }
    printf("\n");

    // Sort the customer IDs using Insertion Sort
    insertionSort(customerIDs, n);

    printf("Sorted Customer IDs (Ascending Order):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", customerIDs[i]);
    }
    printf("\n");

    return 0;
}
