#include <functional>
#include "../include/lovok.h"
#include "io/file_io.h"
#include "boxes/box.h"

#ifndef LOVOK_LOVOK_HANDLE_INTERNAL_H
#define LOVOK_LOVOK_HANDLE_INTERNAL_H

typedef struct LovokHandleInternal {
    const char * name;
} *LOVOK_HANDLE_INTERNAL;

LovokStatusCode ParseBoxes(FileWrapper *, uint64_t, const std::function<LovokStatusCode(const Box &)> &);

LovokStatusCode ParseMp4(LOVOK_HANDLE_INTERNAL);

#endif //LOVOK_LOVOK_HANDLE_INTERNAL_H
