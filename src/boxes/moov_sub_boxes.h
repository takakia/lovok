#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

#ifndef LOVOK_MOOV_SUB_BOXES_H
#define LOVOK_MOOV_SUB_BOXES_H

LovokStatusCode ParseTrak(FileWrapper *, uint64_t);

LovokStatusCode ParseMvhd(FileWrapper *, uint64_t);

LovokStatusCode ParseMeta(FileWrapper *, uint64_t);

#endif //LOVOK_MOOV_SUB_BOXES_H
