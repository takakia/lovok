#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

#ifndef LOVOK_TRAF_SUB_BOXES_H
#define LOVOK_TRAF_SUB_BOXES_H

LovokStatusCode ParseTfhd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTrun(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTrafSbgp(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTrafSgpd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTrafSubs(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTrafSaiz(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTrafSaio(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTfdt(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseTrafMeta(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_TRAF_SUB_BOXES_H
