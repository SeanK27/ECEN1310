#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void divisibleby3(int lower, int upper) {
	
	// The output is a series of print statements due to recursion.
	if (upper % 3 == 0) {
		printf("%d ", upper);
	}
	
	// Recursively iterate through every number until lower is equal to upper.
	if (lower < upper) {
		divisibleby3(lower, upper-1);
	}	
}

int main() {
    printf("Test cases:\n");

    printf("\nLower: 5, Upper: 3\n");
    divisibleby3(5, 3);

    printf("\nLower: 6, Upper: 6\n");
    divisibleby3(6, 6);

    printf("\nLower: 3, Upper: 9\n");
    divisibleby3(3, 9);

    printf("\nLower: 4, Upper: 7\n");
    divisibleby3(4, 7);

    printf("\nLower: 1, Upper: 100\n");
    divisibleby3(1, 100);

    printf("\n");
}