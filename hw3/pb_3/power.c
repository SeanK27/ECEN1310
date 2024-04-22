#include <stdio.h>
#include <assert.h>

int power(int a, int n, int* p) {
    
    // Check for invalid inputs
	if (a < 0 || n < 0 || p == NULL) return -1;

	*p = 1;

    // Check for zero edge case
	if (n == 0) {
		*p = 1;
        return 0;
	}

    // Iterate through n
	for (int i = 0; i < n; i++) {
		*p = *p * a;
	}

	return 0;
}

int main() {
	int result;

    // Test valid inputs
    assert(power(2, 3, &result) == 0 && result == 8);
    assert(power(3, 2, &result) == 0 && result == 9);
    assert(power(1, 0, &result) == 0 && result == 1);

    // Test invalid inputs
    assert(power(-2, -3, &result) == -1);
    assert(power(0, 4, NULL) == -1);

    printf("All test cases passed\n");
}
