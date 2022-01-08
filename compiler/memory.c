#include "memory.h"
#include "common.h"

void *reallocate(void *ptr, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free(ptr);
        return NULL;
    }

    void *result = realloc(ptr, newSize);
    if (result == NULL) {
        exit(1);
    }

    return result;
}
