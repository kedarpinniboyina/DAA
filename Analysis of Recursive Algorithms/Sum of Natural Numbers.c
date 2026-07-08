#include <stdio.h>

// Recursive function to find the sum of first n natural numbers
int getSum(int n) {
    // Base Case
    if (n == 0) {
        return 0;
    }
    // Recursive Case
    return n + getSum(n - 1);
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Sum of first %d natural numbers = %d\n", num, getSum(num));
    }
    return 0;
}