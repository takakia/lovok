#include "../lovok_handle_internal.h"
#include "trak_sub_boxes.h"

LovokStatusCode ParseTkhd(FileWrapper *, uint64_t) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseTref(FileWrapper *, uint64_t) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseTrgr(FileWrapper *, uint64_t) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseEdts(FileWrapper *, uint64_t) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseMeta(FileWrapper *, uint64_t) { // Redeclare here? Since it is a different level metadata box
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseMdia(FileWrapper *, uint64_t) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseUdta(FileWrapper *, uint64_t) {
    return SUCCESS;
    // todo if this is involved in an exploit
}
