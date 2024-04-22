#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	
	int vowelcount[5] = {0};

	if (argc <= 1) return -1;

	for (int i = 0; i < argc; i++) {
		char *instring = argv[i];
		while (*instring) {
			char ch = tolower(*instring);
			switch (ch) {
				case 'a': vowelcount[0]++; break;
				case 'e': vowelcount[1]++; break;
				case 'i': vowelcount[2]++; break;
				case 'o': vowelcount[3]++; break;
				case 'u': vowelcount[4]++; break;
			}
			instring++;
		}
}

printf("a/A: %d\n", vowelcount[0]);
printf("e/E: %d\n", vowelcount[1]);
printf("i/I: %d\n", vowelcount[2]);
printf("o/O: %d\n", vowelcount[3]);
printf("u/U: %d\n", vowelcount[4]);
}
