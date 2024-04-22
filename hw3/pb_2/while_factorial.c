#include <stdio.h>
#include <assert.h>

int while_factorial(int n, int *factorial) {
	if (factorial == NULL) return -1;

	int count = n;
	*factorial = 1;

	while (count > 0) {
		*factorial = *factorial * count;
		count = count - 1;
	}

	return 0;
}

int main() {
	int result;

    // Test valid inputs
    assert(while_factorial(0, &result) == 0 && result == 1);
    assert(while_factorial(5, &result) == 0 && result == 120);
    assert(while_factorial(10, &result) == 0 && result == 3628800);

    // Test invalid input
    assert(while_factorial(5, NULL) == -1);

    printf("All test cases passed\n");

}
