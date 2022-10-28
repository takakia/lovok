#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

#ifndef LOVOK_FIIN_SUB_BOXES_H
#define LOVOK_FIIN_SUB_BOXES_H

LovokStatusCode ParsePaen(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseSegr(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseGitn(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_FIIN_SUB_BOXES_H
