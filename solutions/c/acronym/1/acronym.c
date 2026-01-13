#include "acronym.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase) {
    if (phrase == NULL || *phrase == '\0')
        return NULL;

    size_t n = strlen(phrase);
    char *result = malloc(n + 1);
    if (result == NULL)
        return NULL;

    size_t j = 0;
    int new_word = 1;

    for (size_t i = 0; phrase[i] != '\0'; i++) {
        char c = phrase[i];
        if (isspace((unsigned char)c) || c == '-') {
            new_word = 1;
        } else {
            if (new_word && isalpha((unsigned char)c)) {
                result[j++] = toupper((unsigned char)c);
                new_word = 0;
            }
        }
    }

    result[j] = '\0';

    char *shrunk = realloc(result, j + 1);
    return shrunk ? shrunk : result;
}
