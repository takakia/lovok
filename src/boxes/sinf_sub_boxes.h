#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

#ifndef LOVOK_SINF_SUB_BOXES_H
#define LOVOK_SINF_SUB_BOXES_H

LovokStatusCode ParseFrma(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseSchm(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseSchi(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_SINF_SUB_BOXES_H
