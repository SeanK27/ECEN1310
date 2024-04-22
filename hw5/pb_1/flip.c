#include <stdio.h>

int flip(int x[], int y[], int len) {
	// Create counter to increment the destination index.
	int counter = 0;

	// Iterate backwards through initial array, then insert forwards into destination array.
	for (int i = len-1; i > 0; i--) {
		y[counter] = x[i];
		counter++;
	}

	return 0;
}

int main() {
	int inputarr[6] = {0, 1, 2, 3, 4, 5};
	int outputarr[6];

	flip(inputarr, outputarr, 6);

	for (int a = 0; a < 6; a++) {
		printf("%d", outputarr[a]);
	}
	printf("\n");

}
