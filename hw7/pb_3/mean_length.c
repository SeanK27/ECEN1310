#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {
    int total_length = 0;
    int num_strings = 0;
    int character;

    for (int i = 1; i < argc; ++i) {
        total_length += strlen(argv[i]);
        num_strings++;
    }

    while ((character = getchar()) != EOF) {
        int string_length = 0;
        if (character != '\n') {
            while (character != '\n' && character != EOF) {
                string_length++;
                character = getchar();
            }
        }
        if (string_length > 0) {
            total_length += string_length;
            num_strings++;
        }
    }

    int mean = (int)(total_length / num_strings);
    printf("%d\n", mean);

    return 0;
}