#include <cstdlib>
#include "../include/lovok.h"
#include "../libs/io/file_io.h"
#include "lovok_handle_internal.h"


LOVOK_HANDLE Lovok_create(const char *name) {
    LOVOK_HANDLE handle = NULL;
    handle = (LOVOK_HANDLE) malloc(sizeof(LOVOK_HANDLE_INTERNAL));
    handle->wrapper = FileWrapper_Open(name);
    return handle;
}

LOVOK_HANDLE Lovok_create_by_handle(FileWrapper *wrapper) {
    LOVOK_HANDLE handle = NULL;
    handle = (LOVOK_HANDLE) malloc(sizeof(LOVOK_HANDLE_INTERNAL));
    handle->wrapper = wrapper;
    return handle;
}

void Lovok_destroy(LOVOK_HANDLE h) {
    FileWrapper_Close(h->wrapper);
    free(h);
}

LovokStatusCode valid_mp4(LOVOK_HANDLE h) {
    return ParseMp4(h);
}
