#include "circular_buffer.h"
#include <stdlib.h>
#include <errno.h>

struct circular_buffer_s {
    buffer_value_t *values;
    size_t capacity;
    size_t read_idx;
    size_t write_idx;
    size_t count;
};

circular_buffer_t *new_circular_buffer(size_t capacity) {
    circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));
    if (!buffer) return NULL;

    buffer->values = malloc(sizeof(buffer_value_t) * capacity);
    if (!buffer->values) {
        free(buffer);
        return NULL;
    }

    buffer->capacity = capacity;
    buffer->read_idx = 0;
    buffer->write_idx = 0;
    buffer->count = 0;

    return buffer;
}

void delete_buffer(circular_buffer_t *buffer) {
    if (buffer) {
        free(buffer->values);
        free(buffer);
    }

}

int16_t write(circular_buffer_t *buffer, buffer_value_t value) {
    if (buffer->count == buffer->capacity) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    buffer->values[buffer->write_idx] = value;
    buffer->write_idx = (buffer->write_idx + 1) % buffer->capacity;
    buffer->count++;

    return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value) {
    if (buffer->count == 0) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    *value = buffer->values[buffer->read_idx];
    buffer->read_idx = (buffer->read_idx + 1) % buffer->capacity;
    buffer->count--;

    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
    if (buffer->count < buffer->capacity) {
        return write(buffer, value);
    }

    buffer->values[buffer->write_idx] = value;

    buffer->write_idx = (buffer->write_idx + 1) % buffer->capacity;
    buffer->read_idx = (buffer->read_idx + 1) % buffer->capacity;

    return EXIT_SUCCESS;
}

void clear_buffer(circular_buffer_t *buffer) {
    buffer->count = 0;
    buffer->write_idx = 0;
    buffer->read_idx = 0;
}
