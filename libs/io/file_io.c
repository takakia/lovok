#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "file_io.h"

struct FileCallbackOperations {
    ssize_t (*read) (void *context, void *buffer, size_t len);
    int (*seek) (void *context, uint64_t pos);
    void (*close) (void *context);
    bool (*end) (void *context);
    uint64_t (*size) (void *context);
    uint64_t (*offset) (void *context);
};

struct FileWrapper {
    const struct FileCallbackOperations *ops;
};

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

uint64_t FileWrapper_Size(struct FileWrapper *wrap) {
    return wrap->ops->size(wrap);
}

uint64_t FileWrapper_Offset(struct FileWrapper *wrap) {
    return wrap->ops->offset(wrap);
}



bool FileWrapper_End(struct FileWrapper *wrap) {
    return wrap->ops->end(wrap);
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

static bool pread_end(void * contextp) {
    struct FileWrapper_StdIO *context = (struct FileWrapper_StdIO*) contextp;
    int end = feof(context->f);
    if (end != 0) {
       return false;
    }
    return end; 
}

static uint64_t ftello_offset(void * contextp) {
    struct FileWrapper_StdIO *context = (struct FileWrapper_StdIO*) contextp;
    return ftello(context->f);
}

static uint64_t size(void * contextp) {
    // TODO check if need to account for other operating systems

    struct FileWrapper_StdIO *context = (struct FileWrapper_StdIO*) contextp;
    uint64_t currentOffset = ftello_offset(context);

    // Handles errors with current offset by returning number less than 0
    if (currentOffset < 0) {
        return currentOffset;
    }

    if (fseek(context->f, 0, SEEK_END)) {
        return -1;
    }
    uint64_t size = ftello_offset(contextp);
    if (fseeko(context->f, (int64_t) currentOffset, SEEK_SET)) {
        return -1;
    }
    return size;
}

static const struct FileCallbackOperations fopen_ops =
        {fopen_read,
         fopen_seek,
         fopen_close,
         pread_end,
         size,
         ftello_offset,
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
