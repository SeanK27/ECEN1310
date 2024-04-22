#include <stdio.h>
#include <assert.h>

int lcm_calculator(int a, int b, int *lcm) {
    // Error Handling
    if (a < 0 || b < 0 || lcm == NULL) return -1;

    // Handle zero cases
    if (a == 0 || b == 0) {
        *lcm = 0;
        return 0;
    }

    // Make lcm the largest number
    
    if (a > b) {
        *lcm = a;
    }
    else {
        *lcm = b;
    }

    // Iterate until LCM is found
    while (*lcm % a != 0 || *lcm % b != 0) {
        
        if (a > b) {
            *lcm = *lcm + a;
        }
        else {
            *lcm = *lcm + b;
        }
    }

    return 0;
}

int main() {
    int lcm;

    // Basic functionality tests
    assert(lcm_calculator(10, 15, &lcm) == 0 && lcm == 30);
    assert(lcm_calculator(8, 12, &lcm) == 0 && lcm == 24);
    assert(lcm_calculator(25, 35, &lcm) == 0 && lcm == 175);
    assert(lcm_calculator(72, 108, &lcm) == 0 && lcm == 216);

    // Edge cases tests
    assert(lcm_calculator(0, 0, &lcm) == 0 && lcm == 0);
    assert(lcm_calculator(-5, 8, &lcm) == -1);
    assert(lcm_calculator(10, -12, &lcm) == -1);
    assert(lcm_calculator(10, 15, NULL) == -1);

    // Large numbers tests
    assert(lcm_calculator(1234, 9876, &lcm) == 0 && lcm == 6093492);
    assert(lcm_calculator(99999, 88888, &lcm) == 0 && lcm == 799992);
    
    printf("\nAll tests passed\n");
}
