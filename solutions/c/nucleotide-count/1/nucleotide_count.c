#include "nucleotide_count.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *count(const char *dna_strand) {
    if (dna_strand == NULL)
        return NULL;

    size_t counts[4] = {0};

    for (const char *p = dna_strand; *p != '\0'; p++) {
        switch (*p) {
        case 'A':
            counts[0]++;
            break;
        case 'C':
            counts[1]++;
            break;
        case 'G':
            counts[2]++;
            break;
        case 'T':
            counts[3]++;
            break;
        default: {
            char *err_res = malloc(1);
            if (err_res)
                err_res[0] = '\0';
            return err_res;
        }
        }
    }

    size_t buffer_len = 128;
    char *result = (char *)malloc(buffer_len);
    if (result == NULL)
        return NULL;

    int written = snprintf(result, buffer_len, "A:%zu C:%zu G:%zu T:%zu",
                           counts[0], counts[1], counts[2], counts[3]);

    if (written < 0 || (size_t)written >= buffer_len) {
        free(result);
        return NULL;
    }
    return result;
}
