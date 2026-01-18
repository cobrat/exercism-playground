#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna) {
    if (!dna) return NULL;

    size_t len = strlen(dna);
    char *rna = malloc(len + 1);
    if (!rna) return NULL;

    const char *p_dna = dna;
    char *p_rna = rna;

    while (*p_dna) {
        switch (*p_dna) {
            case 'G': *p_rna = 'C'; break;
            case 'C': *p_rna = 'G'; break;
            case 'T': *p_rna = 'A'; break;
            case 'A': *p_rna = 'U'; break;
            default: *p_rna = '\0'; break;
        }
        p_dna++;
        p_rna++;
    }

    *p_rna = '\0';
    return rna;
}
