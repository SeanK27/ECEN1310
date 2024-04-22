#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

void printDistribution1(int * nOccur , int sz , int nTrials) {
    if (!nOccur) return;
    
    for (int i = 0; i < sz; ++i) {
        int percent = (100 * nOccur [ i ]) / nTrials;
        printf("%2d %3d ", i, nOccur[i]);
        for (int j = 0; j < percent; ++j) printf("*");
        printf("\n");
    }
}

void printDistribution(int * nOccur, int sz,  int nTrials/*, int max_count*/) {
    char *colstr = getenv("COLUMNS");
    int   columns = atoi(colstr);
//    printf("COLS: %d\n", columns);
    
    if (!nOccur) return;
    
    for (int i = 0; i < sz; ++i) {
        int percent = (columns * nOccur [ i ]) / nTrials;
        printf("%2d %3d ", i, nOccur[i]);
        for (int j = 0; j < percent; ++j) printf("*");
        printf("\n");
    }
}

int main() {
    int word_lengths[33] = {0};
    
    int c;
    int word_length = 0;
    // Signal Variable
    int in_word = 0;
    int num_words = 0;
    int max_count = 0;
    
    while ((c = getchar()) != EOF) {
        if (isspace(c)) {
            if (in_word) {
                // Check over 32 length
                if (word_length >= 32) {
                    word_length = 32;
                }
                word_lengths[word_length]++;
                
if (word_lengths[word_length] > max_count)
    max_count = word_lengths[word_length];
                
printf(" <- len: %d\n", word_length);
                word_length = 0;
                num_words++;
            }
            in_word = 0;
        }
        else {
putchar(c);
            in_word = 1;
            word_length++;
        }
    }
    
    if (in_word) {
        if (word_length >= 32) {
            word_lengths[32]++;
        }
        else {
            word_lengths[32]++;
        }
        num_words++;
    }
    
    printDistribution(word_lengths, 33, num_words);
}