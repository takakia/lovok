#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

#ifndef LOVOK_PAEN_SUB_BOXES_H
#define LOVOK_PAEN_SUB_BOXES_H

LovokStatusCode ParseFire(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseFpar(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseFecr(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_PAEN_SUB_BOXES_H
