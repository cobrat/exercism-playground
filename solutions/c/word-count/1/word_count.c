#include "word_count.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// void print_words(word_count_word_t *words, size_t n){
//     for(size_t i = 0; i < n; i++) {
//         printf("[%s, %d] ", words[i].text, words[i].count);
//     }
//     printf("\n");
// }

int count_words(const char *sentence, word_count_word_t *words) {
    memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);
    int unique_words = 0;

    const char *p = sentence;
    char current_word[MAX_WORD_LENGTH + 1];
    int length = 0;

    // printf("==== Input: %s ====\n", p);

    while (*p) {
    //     printf("Processing char: %c\n", *p);

        if (isalnum(*p) || (*p == '\'' && length > 0 && isalnum(*(p + 1)))) {
            if (length < MAX_WORD_LENGTH) {
                current_word[length++] = (char)tolower(*p);
    //             printf("%c\n", current_word[length - 1]);
            }
        } else if (length > 0) {
            if (current_word[length - 1] == '\'' ) {
                length--;
            }
            current_word[length] = '\0';

            bool found = false;
            for (int i = 0; i < unique_words; i++) {
                if (strcmp(current_word, words[i].text) == 0) {
                    words[i].count++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                if (unique_words >= MAX_WORDS) return -1;
                strcpy(words[unique_words].text, current_word);
                words[unique_words].count = 1;
                unique_words++;
            }
            length = 0;

    //         printf("---- Output word: %s ----\n", current_word);
            // print_words(words, (size_t)unique_words);
        }
        
        p++;
    }

    if (length > 0) {
        if (current_word[length - 1] == '\'')
            length--;
        current_word[length] = '\0';

        bool found = false;
        for (int i = 0; i < unique_words; i++) {
            if (strcmp(current_word, words[i].text) == 0) {
                words[i].count++;
                found = true;
                break;
            }
        }

        if (!found) {
            if (unique_words >= MAX_WORDS)
                return -1;
            strcpy(words[unique_words].text, current_word);
            words[unique_words].count = 1;
            unique_words++;
        }
    }

    return unique_words;
}

// int main(void) {
//     int result = 0;
//     word_count_word_t output[MAX_WORDS];
//     // result = count_words("hello", output);
//     result = count_words("\'that's ok\'", output);
//     return 0;
// }
