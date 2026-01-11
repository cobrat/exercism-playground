#include "isogram.h"
#include <ctype.h>
#include <string.h>

// hash table count[key] = value
// if count[key] > 1 return false
// else return true
bool is_isogram(const char phrase[]) {
    if (phrase == NULL) {
        return false;
    }

    int counts[26] = {0};

    for (int i = 0; phrase[i] != '\0'; i++) {
        char c = phrase[i];

        if (isalpha(c)) {
            char lower = tolower(c);

            int index = lower - 'a';
            counts[index]++;

            if (counts[index] > 1) {
                return false;
            }
        }
    }
    return true;
}
