#include <stddef.h>
#include <assert.h>

int minmax(int a, int b, int c, int* min, int* max) {

	// Checking for NULL Pointers
	if (min == NULL || max == NULL) return -1;
	
	int maxx, minn;
	
	// maxx and minn will represent the true maximum and minimum values by the end of the function.
	maxx = 0;
	minn = 0;

	// Update maxx and minn according to given instructions.
	if (a > b) {
		maxx = a;
		minn = b;
	}
	else {
		maxx = b;
		minn = a;
	}

	if (c > maxx) {
		maxx = c;
	}

	if (c < minn) {
		minn = c;
	}

	*max = maxx;
	*min = minn;

	return 0;
}

int main() {
	
	int minimum = 0, maximum = 0;

	// Test Cases
    
    //----------------------------------------------------------
	minmax(1, 2, 3, &minimum, &maximum);

	assert(minimum == 1);
	assert(maximum == 3);
    

	minmax(2, 2, 2, &minimum, &maximum);
    
    assert(minimum == 2);
	assert(maximum == 2);
    
    
    minmax(-5, -2, -1, &minimum, &maximum);
    
    assert(minimum == -5);
	assert(maximum == -1);
    
    
    minmax(0, 0, 0, &minimum, &maximum);
    
    assert(minimum == 0);
	assert(maximum == 0);
    
    
    minmax(-1, -1, -1, &minimum, &maximum);
    
    assert(minimum == -1);
	assert(maximum == -1);
    //----------------------------------------------------------

}
