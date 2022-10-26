#ifndef LOVOK_MDIA_SUB_BOXES_H
#define LOVOK_MDIA_SUB_BOXES_H

#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

LovokStatusCode ParseMdhd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseMdiaHdlr(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseElng(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseMinf(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_MDIA_SUB_BOXES_H
