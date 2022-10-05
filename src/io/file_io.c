#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "file_io.h"

struct FileCallbackOperations {
    ssize_t (*read) (void *context, void *buffer, size_t len);
    int (*seek) (void *context, uint64_t pos);
    void (*close) (void *context);
};

struct FileWrapper {
    const struct FileCallbackOperations *ops;
} *FILE_WRAPPER;

ssize_t FileWrapper_Read(struct FileWrapper *wrap, void *buf, ssize_t len) {
    return wrap->ops->read(wrap, buf, len);
}

int FileWrapper_Seek(struct FileWrapper *wrap, uint64_t pos) {
    return wrap->ops->seek(wrap, pos);
}

void FileWrapper_Close(struct FileWrapper *wrap) {
    if (wrap) {
        wrap->ops->close(wrap);
    }
}

struct FileWrapper_StdIO {
    struct FileWrapper base;
    FILE *f;
};

static ssize_t fopen_read(void *contextp, void *buf, size_t len) {
    struct FileWrapper_StdIO *context = (struct FileWrapper_StdIO*) contextp;
    size_t r = fread(buf, 1, len, context-> f);
    return r;
}

static int fopen_seek(void *contextp, uint64_t pos) {
    struct FileWrapper_StdIO *context = (struct FileWrapper_StdIO*) contextp;
    return fseek(context->f, pos, SEEK_SET);
}

static void fopen_close(void *contextp) {
    struct FileWrapper_StdIO *context = (struct FileWrapper_StdIO*) contextp;
    fclose(context->f);
    free(context);
}

static const struct FileCallbackOperations fopen_ops =
        {fopen_read,
         fopen_seek,
         fopen_close,
         };

struct FileWrapper *FileWrapper_Open(const char *name) {
    struct FileWrapper_StdIO *r = malloc(sizeof(*r));
    if (r) {
        r->base.ops = &fopen_ops;
        r->f = fopen(name, "rb");
        if (!r->f) {
            FileWrapper_Close(&r->base);
            return NULL;
        }
        return &r->base;
    }
    return NULL;
}
