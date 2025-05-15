#include <stdio.h>

int main() {
    int n, i;
    float sum = 0, num, average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%f", &num);
        sum += num;
    }

    average = sum / n;

    printf("\nSum = %.2f\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
