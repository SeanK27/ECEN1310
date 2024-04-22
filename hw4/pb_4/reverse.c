#include <stdio.h>
#include <stddef.h>
#include <assert.h>

int reversefn(int n) {

	if (n == 0) {
		return 0;
	}
	
	else {
		int tens_power = 0;
		int temp = n;
		if (n < 10){
		}
		else{
			while (temp >= 10){
				tens_power++;
				temp = temp / 10;
			}
		}

		if (tens_power == 0){
			return ((n % 10) * 1);
		}
		else{
			int to_multiply = 1;
			for (int i=0; i<tens_power; i++){
				to_multiply *= 10;
			}
			return ((n % 10) * to_multiply) + reversefn(n/10);
		}
	}
}

int reverse(int n, int *n_reversed) {
	if (n <= 0 || n_reversed == NULL) return -1;
	
	int reversed_num =  reversefn(n);

	*n_reversed = reversed_num;

	return 0;
}

int main() {
	int reversed;

	// reverse(54321, &reversed);

	// printf("%d\n", reversed);

	reverse(23452, &reversed);

	printf("Old: 23452\n New: %d\n", reversed);
}
