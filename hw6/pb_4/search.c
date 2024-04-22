#include <stdio.h>
#include <string.h>
#include <assert.h>

int search(char *text, char *keyword, int *count) {

    if (text == NULL || keyword == NULL || count == NULL) return -1;

    int i, a;
    *count = 0;

    for (i = 0; text[i] != '\0'; i++) {
        
        for (a = 0; keyword[a] != '\0' && text[i + a] != '\0'; a++) {
            
            if (text[i + a] != keyword[a]) {
                break;
            }
        }
        
        // Check for terminator to see if word has been found
        if (keyword[a] == '\0') {
            (*count)++;
        }
    }

  return 0;
}

int main() {

    int count; 

    char *text = "In a hole in the ground there lived a hobbit. Not a nasty, dirty, wet hole, filled with the ends of worms and an oozy smell, nor yet a dry, bare, sandy hole with nothing in it to sit down on or to eat: it was a hobbit-hole, and that means comfort.";

    assert(search(text,"hole",&count) == 0); assert(count == 4);

    assert(search(text,"hobbit",&count) == 0); assert(count == 2);

    assert(search(text,"hobbit ",&count) == 0); assert(count == 0); //note the difference from the previous case: there is a space at the end of the word. There is no occurrence of the word hobbit followed by a space. 

    assert(search(text,"a",&count) == 0); assert(count == 15);

    assert(search(text,"at",&count) == 0); assert(count == 2);
}