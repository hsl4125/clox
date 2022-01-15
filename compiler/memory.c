#include "memory.h"
#include "common.h"
#include "vm.h"

#include <stdio.h>

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

static void freeObject(Obj *object) {
    switch (object->type) {
    case OBJ_STRING: {
        ObjString *string = (ObjString *) object;
        FREE_ARRAY(char, string->chars, string->length + 1);
        FREE(ObjString, object);
        break;
    }
    case OBJ_FUNCTION: {
        ObjFunction *function = (ObjFunction *) object;
        freeChunk(&function->chunk);
        FREE(ObjFunction, object);
        break;
    }
    case OBJ_CLOSURE: {
        FREE(ObjClosure, object);
        break;
    }
    case OBJ_NATIVE: {
        printf("<native fn>");
        break;
    }
    }
}

void freeObjects() {
    Obj *object = vm.objects;
    while (object != NULL) {
        Obj *next = object->next;
        freeObject(object);
        object = next;
    }
}
