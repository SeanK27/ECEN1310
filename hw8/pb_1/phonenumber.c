#include <stdio.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

int isPhoneNumber (char *phn) {
        
    if (isdigit(*phn)) {
        for (int i = 0; i < 3; i++) {
            if (!isdigit(*phn)) return 0;
            phn++;
        }
    
        if (*phn == '-') {
            phn++;
        }

    }
    
    
    else if (*phn == '(') {
        phn++;
        
        for (int i = 0; i < 3; i++) {
            if (!isdigit(*phn)) return 0;
            phn++;
        }
        
        if (*phn != ')') return 0;
        phn++;
        if (*phn != '-') return 0;
        phn++;
    }
    
    
    else {
        return 0;
    }
    
    
    for (int i = 0; i < 4; i++) {
        if (!isdigit( * phn)) return 0;
        phn++;
    }
    if ( * phn != '\0') return 0;
    return 1;
}

int main(int argc, char *argv) {
    
    char st[100];
    printf("Enter Phone Number: ");
    fgets(st, sizeof(st), stdin);
    st[strcspn(st, "\n")] = '\0';
    printf("You typed: '%s'\n", str);
    
    if (isPhoneNumber(st)) {
        printf("%s is a valid phone number.\n", st);
    }
    else {
        printf("Invalid phone number. Format as: (XXX) XXX-XXXX or XXX-XXX-XXXX\n");
    }    
}
