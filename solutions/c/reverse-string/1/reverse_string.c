#include "reverse_string.h"
#include <string.h>

char *reverse(const char *value) {
    if (value == NULL) {
        return NULL;
    }

    size_t n = strlen(value);
    char *result = strdup(value);

    if (n == 0) {
        return result;
    }

    size_t left = 0;
    size_t right = n - 1;

    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++;
        right--;
    }

    return result;
}
