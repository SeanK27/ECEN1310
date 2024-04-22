#include <stdio.h>
#include <assert.h>

int for_factorial(int n, int *factorial) {
	
    // Check for invalid inputs
	if (factorial == NULL) return -1;
	
	*factorial = 1;

    //Iterate through n
	for (int i = n; i > 1; i--) {
		*factorial = *factorial * i;
	}

	return 0;
}

int main() {
	int result;

    // Test valid inputs
    assert(for_factorial(0, &result) == 0 && result == 1);
    assert(for_factorial(5, &result) == 0 && result == 120);
    assert(for_factorial(10, &result) == 0 && result == 3628800);

    // Test invalid input
    assert(for_factorial(5, NULL) == -1);

    printf("All test cases passed\n");

}
