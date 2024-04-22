#include <stdio.h>
#include <stddef.h>
#include <assert.h>

int factorialfn(int n) {

	// Recursively iterate through the input number by multiplying it by the previous number in a function call.
	if (n > 1) {

		return n * factorialfn(n-1);

	}
	else {
		return 1;
	}
}

int factorial(int n, int *fact) {
	
    // Malformed input checking
	if (n <= 0 || fact == NULL) return -1;
    
    if (n == 0) {
        *fact = 0;
        return 0;
    }

	*fact = factorialfn(n);

	return 0;
}

int main() {
    printf("Test cases:\n");

    int fact;

    factorial(5, &fact);
    printf("Factorial of 5: %d\n", fact);
    
    fact = 0;

    factorial(0, &fact);
    printf("Factorial of 0: %d\n", fact);

    if (factorial(-2, &fact) == -1) {
       printf("Error: Invalid input\n");
    }

    if (factorial(3, NULL) == -1) {
       printf("Error: Invalid input\n");
    }
}
