#include <stdio.h>
#include <stddef.h>

int fibonaccifn(int n) {
	
	if (n==1) return 0;
	if (n==2) return 1;
	// printf("%d\n",n);
	return fibonaccifn(n-1) + fibonaccifn(n-2);
}

int fibonacci(int n, int *fibo_n) {
    
    // Check for malformed input
	if (n <= 0 || fibo_n == NULL) return -1;

	*fibo_n = fibonaccifn(n);

	return 0;
}

int main() {
    printf("Test cases:\n");

    int fibo;

    fibonacci(5, &fibo);
    printf("Fibonacci of 5: %d\n", fibo);

    fibonacci(9, &fibo);
    printf("Fibonacci of 9: %d\n", fibo);
    
    fibonacci(30, &fibo);
    printf("Fibonacci of 30: %d\n", fibo);

    if (fibonacci(-2, &fibo) == -1) {
        printf("Error: Invalid input\n");
    }

    if (fibonacci(3, NULL) == -1) {
        printf("Error: Invalid input\n");
    }
}
