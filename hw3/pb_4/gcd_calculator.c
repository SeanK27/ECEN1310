#include <stdio.h>
#include <assert.h>

int gcd_calculator(int a, int b, int *gcd) {
    // Error Checking
	if (a < 0 || b < 0 || gcd == NULL) return -1;
    
    int smallest = 0;
    
    // Check for smallest value for efficiency.
    if (a < b) {
        smallest = a;
    }
    else {
        smallest = b;
    }
    
    // Itereate through the smallest number backwards to find gcd
    for (int i = smallest; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            *gcd = i;
            return 0;
        }
    }
    
    // Both numbers are zero case
    if (a == 0 && b == 0) {
        *gcd = 0;
        return 0;
    }
    else {
        return -1;
    }
    
    return -1;
}

int main() {
    int gcd;

    // Basic functionality tests
    assert(gcd_calculator(10, 15, &gcd) == 0 && gcd == 5);
    assert(gcd_calculator(8, 12, &gcd) == 0 && gcd == 4);
    assert(gcd_calculator(25, 35, &gcd) == 0 && gcd == 5);
    assert(gcd_calculator(72, 108, &gcd) == 0 && gcd == 36);

    // Edge cases tests
    assert(gcd_calculator(0, 0, &gcd) == 0 && gcd == 0);
    assert(gcd_calculator(-5, 8, &gcd) == -1);
    assert(gcd_calculator(10, -12, &gcd) == -1);
    assert(gcd_calculator(10, 15, NULL) == -1);

    // Large numbers tests
    assert(gcd_calculator(123456, 987654, &gcd) == 0 && gcd == 6);
    assert(gcd_calculator(999999999, 888888888, &gcd) == 0 && gcd == 111111111);

    printf("\nAll tests passed\n");
}
