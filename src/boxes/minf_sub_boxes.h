#ifndef LOVOK_MINF_SUB_BOXES_H
#define LOVOK_MINF_SUB_BOXES_H

#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

LovokStatusCode ParseVmhd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseSmhd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseHmhd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseSthd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseNmhd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseMinfDinf(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStbl(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_MINF_SUB_BOXES_H
