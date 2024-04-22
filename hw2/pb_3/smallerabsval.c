#include <assert.h>

// Used stdlib.h for the abs() function.
#include <stdlib.h>

int smallerabsval(int x, int y) {

	// Start by testing equivalency of value and absolute value. Then tested for smallest value.
	if (x == y) {
		return x;
	}

	if (abs(x) == abs(y)) {
		if (x > y) {
			return x;
		}
		return y;
	}

	if (abs(x) < abs(y)) {
		return x;
	}
	else {
		return y;
	}
}

int main() {
	
	// If the numbers are different then it will return the smallest absolute value number which is 3.
	assert(smallerabsval(-5, 3) == 3);

	// If the numbers are 0 and 0 it will return 0.
	assert(smallerabsval(0, 0) == 0);

	// If the numbers are equal it will return the number.
	assert(smallerabsval(-3, -3) == -3);

	// If the absolute values are equal it will return the positive number.
	assert(smallerabsval(-3, 3) == 3);
}
