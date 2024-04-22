#include <stdio.h>
#include <ctype.h>

int anagramcheck(char *string1, char *string2) {
    if (string1 == NULL || string2 == NULL) return -1;
    
	int count1[256] = { 0 };
    int count2[256] = { 0 };
    
    for (int i = 0; string1[i] && string2[i]; i++) {
        count1[tolower(string1[i])]++;
        count2[tolower(string2[i])]++;
    }
    
    for (int i = 0; i < 256; i++){
        if (count1[i] != count2[i]){
            return 0;
        }
    }
    return 1;
}

int main() {
    char string1[] = "gLeAn";
    char string2[] = "AngeL";
    
    printf("%d\n", anagramcheck(string1, string2));
}