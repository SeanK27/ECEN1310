#include <stdio.h>

int anagramcheck(char *string1, char *string2) {
	if (string1 == NULL || string2 == NULL) return -1;
	
	// char temparr[] = string1;

	for (int i = 0; string1[i] != '\0'; i++) {
		
		for (int a = 0; string2[a] != '\0'; a++) {
			
			if (string2[a] == string1[i]) {
				string1[i] = 0;
			}
		}
	}

	for (int i = 0; string1[i] != '\0'; i++) {
		if (string1[i] != 0) return 0;
	}

	return 1;
}

int main() {
	char in1[] = "says";
	char in2[] = "yasssss";

	int returnval = anagramcheck(in1, in2);

	printf("%d\n", returnval);
}
