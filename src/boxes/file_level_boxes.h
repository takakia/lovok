#ifndef LOVOK_FILE_LEVEL_BOXES_H
#define LOVOK_FILE_LEVEL_BOXES_H

#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

LovokStatusCode ParseMoov(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseMoof(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseMeta(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseMfra(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseSkip(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_FILE_LEVEL_BOXES_H
