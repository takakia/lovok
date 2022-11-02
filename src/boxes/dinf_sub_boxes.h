#ifndef LOVOK_DINF_SUB_BOXES_H
#define LOVOK_DINF_SUB_BOXES_H

#include "box.h"
#include "../lovok_handle_internal.h"
#include "../include/lovok.h"
#include "io/file_io.h"
#include <functional>

LovokStatusCode ParseDref(FileWrapper *, uint64_t, uint64_t);

#endif //LOVOK_DINF_SUB_BOXES_H
