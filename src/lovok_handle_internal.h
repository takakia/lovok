#include "../include/lovok.h"

#ifndef LOVOK_LOVOK_HANDLE_INTERNAL_H
#define LOVOK_LOVOK_HANDLE_INTERNAL_H

typedef struct LovokHandleInternal {
    const char * name;
} *LOVOK_HANDLE_INTERNAL;

LovokStatusCode ParseMp4(LOVOK_HANDLE_INTERNAL);

#endif //LOVOK_LOVOK_HANDLE_INTERNAL_H
