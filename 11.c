#include <stdio.h>

// Tail recursive function to find the largest element in an array
int findMaxTailRec(int arr[], int n, int currentMax, int index) {
    if (index == n)
        return currentMax;
    if (arr[index] > currentMax)
        currentMax = arr[index];
    return findMaxTailRec(arr, n, currentMax, index + 1);
}

int main() {
    int arr[] = {8, 5, 1, 9, 2, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int max = findMaxTailRec(arr, n, arr[0], 1);
    printf("The largest element is: %d\n", max);
    
    return 0;
}
