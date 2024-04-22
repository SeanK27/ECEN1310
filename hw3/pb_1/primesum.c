#include <stdio.h>
#include <assert.h>
#define true  1
#define false 0
#if DEBUG > 0
   #define PRINTF(...)  printf(__VA_ARGS__)
#else
   #define PRINTF(...)  
#endif

int primesum(int n, int *sum) {
	if (sum == NULL) return -1;
	*sum = 0;

	for (int j=2; j <= n; j++) {
		// Is i prime?
		int	isPrime = true;

		PRINTF("Testing %d\n", j);

		for (int i = 2; i < j ; i++) {
			if (j % i == 0) {
				isPrime = false;
				break;
			}
				
		}

		if (isPrime) {
		 	PRINTF("%d is PRIME\n", j);
			*sum += j;
		}
	}
    return 0;
}


int main()
{
	int result;

    // Test valid inputs
    assert(primesum(10, &result) == 0 && result == 17);
    assert(primesum(50, &result) == 0 && result == 328);
    assert(primesum(100, &result) == 0 && result == 1060);

    // Test null pointer
    assert(primesum(10, NULL) == -1);

    printf("All test cases passed!\n");
    return 0;
}
