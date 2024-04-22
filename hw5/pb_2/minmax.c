#include <stdio.h>

int minmax(int x[], int len, int *min, int *max) {
	
	//Malformed input checking.
	if (len < 1 || min == NULL || max == NULL) return -1;

	// Initialize min and max
	*max = x[0];
	*min = x[0];

	// Iterate through x and compare values for a max
	for (int i = 1; i < len; i++) {
		if (*max < x[i]){
			*max = x[i];
		}
	}
	
	// Iterate through x and compare values for a min
	for (int i = 1; i < len; i++) {
		if (*min > x[i]){
			*min = x[i];
		}
	}

	return 0;
}

int main(){
	int x[8] = {6, 1, 3, 5, 6, 2, 10, 23};
	int minimum;
	int maximum;

	minmax(x, 8, &minimum, &maximum);

	printf("Minimum is: %d; Maximum is: %d\n", minimum, maximum);
}

