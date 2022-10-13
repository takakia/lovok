#include <cstdlib>
#include "../include/lovok.h"
#include "lovok_handle_internal.h"


LOVOK_HANDLE Lovok_create(const char *name) {
    LOVOK_HANDLE handle = NULL;
    handle = (LOVOK_HANDLE) malloc(sizeof(LOVOK_HANDLE_INTERNAL));
    handle->name = name;
    return handle;
}

void Lovok_destroy(LOVOK_HANDLE h) {
    free(h);
}