#include <stdio.h>
#include <string.h>

int vowelfree(char *in, char *out) {
	if (in == NULL || out == NULL) return -1;
	
	int arrpos = 0;

	for (int i = 0; in[i] != '\0'; i++) {

		if (in[i]!='a' && in[i] != 'e' && in[i] != 'i' && in[i] != 'o' && in[i] != 'u' && in[i] != 'A' && in[i] != 'E' && in[i] != 'I' && in[i] != 'O' && in[i] != 'U') {
			out[arrpos] = in[i];
			arrpos++;
		}
	}
	return 0;
}

int main() {
	char input[] = "ooga booga";
	char output[10];

	vowelfree(input, output);
	
	printf("%s\n", output);
}
