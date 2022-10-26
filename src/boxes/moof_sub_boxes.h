#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

#ifndef LOVOK_MOOF_SUB_BOXES_H
#define LOVOK_MOOF_SUB_BOXES_H

LovokStatusCode ParseMfhd(FileWrapper *, uint64_t, uint64_t);

//LovokStatusCode ParseMeta(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTraf(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_MOOF_SUB_BOXES_H
