#ifndef LOVOK_STBL_SUB_BOXES_H
#define LOVOK_STBL_SUB_BOXES_H

#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

LovokStatusCode ParseStsd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStts(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseCtts(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseCslg(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStsc(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStsz(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStz2(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStco(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseCo64(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStss(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStsh(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParsePadb(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStdp(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseSdtp(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseSbgp(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseSgpd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseSubs(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseSaiz(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseSaio(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_STBL_SUB_BOXES_H
