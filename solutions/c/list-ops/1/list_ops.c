#include "list_ops.h"
#include <string.h>

list_t *new_list(size_t length, list_element_t elements[]) {
    list_t *list = malloc(sizeof(list_t) + length * sizeof(list_element_t));
    if(!list) return NULL;

    list->length = length;
    if (length > 0 && elements) {
        memcpy(list->elements, elements, length * sizeof(list_element_t));
    }
    return list;
}

size_t length_list(list_t *list) {
    if (!list) return 0;
    return list->length;
}

void delete_list(list_t *list) {
    free(list);
}

list_t *append_list(list_t *list1, list_t *list2) {
    if (!list1 || !list2) return NULL;

    size_t total_len = list1->length + list2->length;
    list_t *combined = malloc(sizeof(list_t) + total_len * sizeof(list_element_t));
    if (!combined) return NULL;

    combined->length = total_len;
    memcpy(combined->elements, list1->elements, list1->length * sizeof(list_element_t));
    memcpy(&combined->elements[list1->length], list2->elements, list2->length * sizeof(list_element_t));

    return combined;
}

list_t *reverse_list(list_t *list) {
    if (!list) return NULL;

    list_t *rev = new_list(list->length, NULL);
    if (!rev) return NULL;

    for (size_t i = 0; i < list->length; i++) {
        rev->elements[i] = list->elements[list->length - 1 - i];
    }

    return rev;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
    if (!list) return NULL;

    list_t *result = malloc(sizeof(list_t) + list->length * sizeof(list_element_t));
    if (!result) return NULL;

    result->length = list->length;
    for (size_t i = 0; i < list->length; i++) {
        result->elements[i] = map(list->elements[i]);
    }

    return result;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
    if (!list) return NULL;

    size_t filtered_count = 0;
    for (size_t i = 0; i < list->length; i++) {
        if (filter(list->elements[i])) {
            filtered_count++;
        }
    }

    list_t *result = malloc(sizeof(list_t) + filtered_count * sizeof(list_element_t));
    if (!result) return NULL;
    result->length = filtered_count;

    for (size_t i = 0, j = 0; i < list->length; i++) {
        if (filter(list->elements[i])) {
            result->elements[j++] = list->elements[i];
        }
    }

    return result;
}

list_element_t foldl_list(list_t *list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t)) {
    if (!list) return initial;

    list_element_t accumulator = initial;
    for (size_t i = 0; i < list->length; i++) {
        accumulator = foldl(accumulator, list->elements[i]);
    }

    return accumulator;
}

list_element_t foldr_list(list_t *list, list_element_t initial, list_element_t (*foldr)(list_element_t, list_element_t)){
    if (!list) return initial;

    list_element_t accumulator = initial;
    for (size_t i = list->length; i > 0; i--) {
        accumulator = foldr(list->elements[i - 1], accumulator);
    }

    return accumulator;
}
