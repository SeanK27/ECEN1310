#include <stddef.h>
#include <assert.h>

int minmax(int a, int b, int c, int* min, int* max) {
	if (min == NULL || max == NULL) return -1;
	
	int maxx, minn;

	maxx = 0;
	minn = 0;

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
	
	int minimum, maximum;
	minimum = 0;
	maximum = 0;

	minmax(1, 2, 3, &minimum, &maximum);

	assert(minimum == 1);
	assert(maximum == 3);


}
