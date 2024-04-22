#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

int encrypt(char *in, char key, char *enc) {
    
    if (in == NULL || enc == NULL) return -1;

    int i = 0;
    while (in[i] != '\0') {
        char upperstring = toupper(in[i]);
        
        if (isalpha(upperstring)) {
            enc[i] = (upperstring - 'A' + key) % 26 + 'A'; // Encoding algorithm
        } 
        
        else {
            enc[i] = upperstring;
        }
        i++;
    }
    enc[i] = '\0';  // Add string terminator for the output
    return 0;
}

int decrypt(char *enc, char key, char *out) {
    
    if (enc == NULL || out == NULL) return -1;

    int i = 0;
    while (enc[i] != '\0') {
        char encoded = enc[i];
        
        if (isalpha(encoded)) {
            out[i] = (encoded - 'A' - key + 26) % 26 + 'A'; // Decoding algorithm
        }
        
        else {
            out[i] = encoded;
        }
        i++;
    }
    out[i] = '\0';  // Add string terminator for the ouptut
    return 0;
}

int main() {
    char in[] = "ATTACK THE EAST WALL OF THE CASTLE AT DAWN"; 
    char enc[50];
    char out[50];
    char key = 19;

    assert(encrypt(in,key,enc) == 0);
    
    printf("%s\n", enc);
    
    assert(decrypt(enc,key,out) == 0);
    
    printf("%s\n", out);
    
    assert(strcmp(in,out) == 0); //strcmp returns 0 if both strings are equal
}
