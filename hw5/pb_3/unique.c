#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int unique(int x[], int len, int *p) {
    
    // Need variable sized array on heap
	int * charlist;
	charlist = calloc(len, sizeof(int));

	int freepos = 0;
	*p = 0;

	for (int i=0; i<len; i++){
		charlist[i] = -1;
	}


	for (int i = 0; i < len; i++) {
		bool unique = true;
		for (int a = 0; a < len; a++) {
			if (charlist[a] == -1){
				break;
			}
			if (x[i] == charlist[a]) {
				unique = false;
			}
		}

		if (unique == true){
			*p += 1;
			charlist[freepos] = x[i];
		}
	}

	return 0;
}

int main() {
	int input[7] = {1, 2, 5, 5, 6, 7, 7};
	int out;

	unique(input, 7, &out);

	printf("%d\n", out);
}
