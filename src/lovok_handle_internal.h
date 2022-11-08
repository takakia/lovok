#include <functional>
#include "../include/lovok.h"
#include "io/file_io.h"
#include "boxes/box.h"

#ifndef LOVOK_LOVOK_HANDLE_INTERNAL_H
#define LOVOK_LOVOK_HANDLE_INTERNAL_H

typedef struct LovokHandleInternal {
    FileWrapper *wrapper;
} *LOVOK_HANDLE_INTERNAL;

LovokStatusCode ParseBoxes(FileWrapper *, uint64_t, uint64_t, const std::function<LovokStatusCode(const Box &, uint64_t)> &);

LovokStatusCode ParseMp4(LOVOK_HANDLE_INTERNAL);

#endif //LOVOK_LOVOK_HANDLE_INTERNAL_H
