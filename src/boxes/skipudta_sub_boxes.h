#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

#ifndef LOVOK_SKIPUDTA_SUB_BOXES_H
#define LOVOK_SKIPUDTA_SUB_BOXES_H

LovokStatusCode ParseCprt(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTsel(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStrk(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_SKIPUDTA_SUB_BOXES_H
