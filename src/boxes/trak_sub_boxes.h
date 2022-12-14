#ifndef LOVOK_TRAK_SUB_BOXES_H
#define LOVOK_TRAK_SUB_BOXES_H

#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

LovokStatusCode ParseTkhd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTref(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTrgr(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseEdts(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTrakMeta(FileWrapper *, uint64_t, uint64_t); // Redeclare here? Since it is a different level metadata box

LovokStatusCode ParseMdia(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTrakUdta(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_TRAK_SUB_BOXES_H
