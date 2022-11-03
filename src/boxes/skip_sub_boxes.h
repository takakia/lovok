#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

#ifndef LOVOK_SKIP_SUB_BOXES_H
#define LOVOK_SKIP_SUB_BOXES_H

LovokStatusCode ParseSkipUdta(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_SKIP_SUB_BOXES_H
