#include "binary.h"
#include <string.h>

int convert(const char *input) {
    if (input == NULL || *input == '\0') {
        return INVALID;
    }

    size_t n = strlen(input);
    int dex_sum = 0;

    for (size_t i = 0; i < n; i++) {
        char c = input[i];
        if (c != '0' && c != '1') {
            return INVALID;
        }
        dex_sum = (dex_sum << 1) | (c - '0');
    }

    return dex_sum;
}
