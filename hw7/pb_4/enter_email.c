#include <stdio.h>
#include <string.h>

int is_valid_email(const char * email) {
    // check @
    int has_at = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            has_at = 1;
            break;
        }
    }

    // check for >= 1 char after @
    if (email[0] == '@' || email[strlen(email) - 1] == '@') {
        return 0;
    }

    // check for . and one more char
    int has_dot = 0;
    for (int i = has_at ? has_at + 1 : 0; email[i] != '\0'; i++) {
        if (email[i] == '.') {
            has_dot = 1;
            if (email[i + 1] == '\0') {
                return 0;
            }
            break;
        }
    }
    
    return has_at && has_dot;
}

int main(int argc, char * argv[]) {
    if (argc != 2) {
        // Invalid in
        return 1;
    }

    const char * email = argv[1];
    int valid = is_valid_email(email);
    if (valid) {
        printf("%s\n", email);
    } else {
        printf("Invalid email format. Write in this format next time: username@domain.tld\n");
    }

    return 0;
}