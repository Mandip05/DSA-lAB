#include <stdio.h>

// Recursive function to compute GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;  // Base case: if b is zero, GCD is a
    else
        return gcd(b, a % b);  // Recursive call with b and remainder of a divided by b
}

int main() {
    int a, b;
    
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    printf("The GCD of %d and %d is: %d\n", a, b, gcd(a, b));
    
    return 0;
}
