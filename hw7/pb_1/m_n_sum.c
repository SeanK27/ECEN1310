#include <stdio.h>

int main(int argc, char *argv[]) {
	int m, n;

    if (argc != 3) {
        printf("Invalid Input\n");
        return 1;
    }
    
    if (sscanf(argv[1], "%d", &m) != 1 || sscanf(argv[2], "%d", &n) != 1) {
        printf("Invalid Input\n");
        return 1;
    }

	int sum = (m + n) * (n - m + 1) / 2;

	printf("Output: %d\n", sum);

	return 0;
}