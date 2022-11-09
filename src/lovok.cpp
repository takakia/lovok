#include <cstdlib>
#include "../include/lovok.h"
#include "../libs/io/file_io.h"
#include "lovok_handle_internal.h"


LOVOK_HANDLE Lovok_create(const char *name) {
    LOVOK_HANDLE handle = NULL;

    handle = (LOVOK_HANDLE) malloc(sizeof(LOVOK_HANDLE_INTERNAL));
    if (handle)
    {
        handle->wrapper = FileWrapper_Open(name);
        if (handle->wrapper)
            return handle;

        free(handle);
        handle = nullptr;
    }

    return handle;
}

LOVOK_HANDLE Lovok_create_by_handle(FileWrapper *wrapper) {
    LOVOK_HANDLE handle = NULL;
    handle = (LOVOK_HANDLE) malloc(sizeof(LOVOK_HANDLE_INTERNAL));
    if (handle)
        handle->wrapper = wrapper;
    return handle;
}

void Lovok_destroy(LOVOK_HANDLE h) {
    if (!h)
        return;

    FileWrapper_Close(h->wrapper);
    free(h);
}

LovokStatusCode valid_mp4(LOVOK_HANDLE h) {
    return ParseMp4(h);
}
