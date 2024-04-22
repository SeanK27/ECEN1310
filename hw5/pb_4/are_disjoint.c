#include <stdio.h>

int are_disjoint(int x[], int y[], int lx, int ly) {
	
	// Iterate through array x to set a value for comparison
	for (int i = 0; i < lx; i++) {

		// Take the value and compare it with every index in array y
		for (int a = 0; a < ly; a++) {
			if (y[a] == x[i]) return 1;
		}
	}

	return 0;
}

int main() {
	int xarr[3] = {7, 8, 9};
	int yarr[6] = {0, 1, 6, 7, 10, 11};
	int out;

	out = are_disjoint(xarr, yarr, 3, 6);

	printf("%d\n", out);
}
