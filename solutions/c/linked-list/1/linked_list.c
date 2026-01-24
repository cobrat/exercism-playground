#include "linked_list.h"
#include <stdlib.h>

struct list_node {
    struct list_node *prev, *next;
    ll_data_t data;
};

struct list {
    struct list_node *first, *last;
};

struct list *list_create(void) {
    struct list *new_list = malloc(sizeof(struct list));

    if (!new_list)
        return NULL;

    new_list->first = NULL;
    new_list->last = NULL;

    return new_list;
}

size_t list_count(const struct list *list) {
    size_t count = 0;

    struct list_node *current = list->first;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void list_push(struct list *list, ll_data_t item_data) {
    struct list_node *new_node = malloc(sizeof(struct list_node));
    if (!new_node)
        return;

    new_node->data = item_data;
    new_node->prev = list->last;
    new_node->next = NULL;

    if (list->last != NULL) {
        list->last->next = new_node;
    } else {
        list->first = new_node;
    }

    list->last = new_node;
}

ll_data_t list_pop(struct list *list) {
    struct list_node *node = list->last;
    ll_data_t data = node->data;

    if (node->prev != NULL) {
        node->prev->next = NULL;
        list->last = node->prev;
    } else {
        list->first = NULL;
        list->last = NULL;
    }

    free(node);

    return data;
}

void list_unshift(struct list *list, ll_data_t item_data) {
    struct list_node *new_node = malloc(sizeof(struct list_node));
    if (!new_node) return;

    new_node->prev = NULL;
    new_node->data = item_data;
    new_node->next = list->first;

    if (list->first != NULL) {
        list->first->prev = new_node;
    } else {
        list->last = new_node;
    }

    list->first = new_node;
}

ll_data_t list_shift(struct list *list) {
    struct list_node *node = list->first;
    ll_data_t data = node->data;

    if (node->next != NULL) {
        node->next->prev = NULL;
        list->first = node->next;
    } else {
        list->first = NULL;
        list->last = NULL;
    }

    free(node);

    return data;
}

void list_delete(struct list *list, ll_data_t data) {
    struct list_node *current = list->first;

    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->first = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->last = current->prev;
            }

            free(current);
            return;
        }

        current = current->next;
    }
}

void list_destroy(struct list *list) {
    struct list_node *current = list->first;

    while (current != NULL) {
        struct list_node *next = current->next;

        free(current);

        current = next;
    }

    free(list);
}
