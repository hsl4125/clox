#pragma once

#include "vm.h"

ObjFunction *compile(const char *source);
void         markCompilerRoots();
