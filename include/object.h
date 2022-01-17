#pragma once

#include "chunk.h"
#include "common.h"
#include "value.h"

#define OBJ_TYPE(value) (AS_OBJ(value)->type)

#define IS_STRING(value) isObjType(value, OBJ_STRING)
#define IS_FUNCTION(value) isObjType(value, OBJ_FUNCTION)
#define IS_CLOSURE(value) isObjType(value, OBJ_CLOSURE)
#define IS_NATIVE(value) isObjType(value, OBJ_NATIVE)

#define AS_STRING(value) ((ObjString *) AS_OBJ(value))
#define AS_CSTRING(value) (((ObjString *) AS_OBJ(value))->chars)
#define AS_FUNCTION(value) ((ObjFunction *) AS_OBJ(value))
#define AS_NATIVE(value) ((ObjNative *) AS_OBJ(value))
#define AS_CLOSURE(value) ((ObjClosure *) AS_OBJ(value))

typedef enum {
    OBJ_STRING,
    OBJ_FUNCTION,
    OBJ_CLOSURE,
    OBJ_UPVALUE,
    OBJ_NATIVE,
} ObjType;

struct Obj {
    ObjType     type;
    bool        isMarked;
    struct Obj *next;
};

typedef struct {
    Obj        obj;
    int        arity;
    int        upvalueCount;
    Chunk      chunk;
    ObjString *name;
} ObjFunction;

typedef Value (*NativeFn)(int argCount, Value *args);

typedef struct {
    Obj      obj;
    NativeFn function;
} ObjNative;


typedef struct ObjUpvalue {
    Obj                obj;
    Value             *location;
    Value              closed;
    struct ObjUpvalue *next;
} ObjUpvalue;

typedef struct {
    Obj          obj;
    ObjFunction *function;
    ObjUpvalue **upvalues;
    int          upvalueCount;
} ObjClosure;


struct ObjString {
    Obj      obj;
    int      length;
    char    *chars;
    uint32_t hash;
};

static inline bool isObjType(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

ObjString   *takeString(char *chars, int length);
ObjString   *copyString(const char *chars, int length);
ObjFunction *newFunction();
ObjClosure  *newClosure(ObjFunction *function);
ObjUpvalue  *newUpvalue(Value *slot);
ObjNative   *newNative(NativeFn function);
void         printObject(Value value);
