#ifndef LOVOK_MOOV_SUB_BOXES_H
#define LOVOK_MOOV_SUB_BOXES_H

#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

LovokStatusCode ParseTrak(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseMvhd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseMoovMeta(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseMvex(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseMoovUdta(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_MOOV_SUB_BOXES_H
