#include <assert.h>
#include <stdio.h>

int multipleof3(int n) {
	// Check if remainder is 0 and return 1 if remainder. 
	if (!(n % 3)) {
		return 0;
	}
	return 1;
}

int main() {
	// Expected to return 0 because 9/3 has no remainder.
	assert(!(multipleof3(9)));

	// Expected to return 1 because 10/3 has a remainder of 1.
	assert(multipleof3(10));

	// Expected to return 2 because -4%3 returns 2.
	assert(multipleof3(-4));
	
	// Expected to return 0 because 0%3 returns 0.
	assert(!(multipleof3(0)));

	printf("Tests Successful!\n");
}
