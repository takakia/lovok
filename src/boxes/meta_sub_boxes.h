#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

#ifndef LOVOK_META_SUB_BOXES_H
#define LOVOK_META_SUB_BOXES_H

LovokStatusCode ParseHdlr(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseDinf(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseIloc(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseIpro(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseIinf(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseXml(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseBxml(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParsePitm(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseFiin(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseIdat(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseIref(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_META_SUB_BOXES_H
