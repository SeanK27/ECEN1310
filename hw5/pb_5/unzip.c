#include <stdio.h>

int unzip(int* a, int* b, int* c, int n) {

	//Malformed input checking
	if (a == NULL || b == NULL || c == NULL || n < 1) return -1;

	// iterate through array c skipping every other index then store into subsequent index in array a
	for (int i = 0; i < 2*n-1; i = i + 2) {
		*a++ = c[i];
	}

	// iterate through array c skipping every other index then store into subsequent index in array b
	for (int i = 1; i < 2*n; i = i + 2) {
		*b++ = c[i];
	}
	return 0;
}

int main() {
	int aarr[3];
	int barr[3];
	int input[6] = {1, 2, 3, 4, 5, 6};

	unzip(aarr, barr, input, 3);

	for (int i = 0; i < 3; i++) {
		printf("%d", aarr[i]);
	}
	printf("\n");

	for (int i = 0; i < 3; i++) {
		printf("%d", barr[i]);
	}
	printf("\n");
}
