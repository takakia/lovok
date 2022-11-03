#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

#ifndef LOVOK_MFRA_SUB_BOXES_H
#define LOVOK_MFRA_SUB_BOXES_H

LovokStatusCode ParseTfra(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseMfro(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_MFRA_SUB_BOXES_H
