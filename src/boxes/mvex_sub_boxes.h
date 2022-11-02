#ifndef LOVOK_MVEX_SUB_BOXES_H
#define LOVOK_MVEX_SUB_BOXES_H

#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

LovokStatusCode ParseMehd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTrex(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseLeva(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_MVEX_SUB_BOXES_H
