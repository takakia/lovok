#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

#ifndef LOVOK_STBL_SUB_BOXES_H
#define LOVOK_STBL_SUB_BOXES_H

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

LovokStatusCode ParseStblSbgp(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStblSgpd(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStblSubs(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStblSaiz(FileWrapper *, uint64_t, uint64_t);

LovokStatusCode ParseStblSaio(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_STBL_SUB_BOXES_H
