#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

#ifndef LOVOK_STRK_SUB_BOXES_H
#define LOVOK_STRK_SUB_BOXES_H

LovokStatusCode ParseStri(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStrd(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_STRK_SUB_BOXES_H
