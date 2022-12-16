#include "../libs/io/file_io.h"
#include <stdarg.h>

#ifndef LOVOK_LOVOK_H
#define LOVOK_LOVOK_H

#if defined(__cplusplus)
extern "C" {
#endif

enum LovokStatusCode {
    PARSE_ERROR = 0,
    VALID_FILE = 1,
    INVALID_FILE = 2,
    UNKNOWN_BOX = 3,
};

typedef struct LovokHandleInternal *LOVOK_HANDLE;

LOVOK_HANDLE Lovok_create(const char *name);

LOVOK_HANDLE Lovok_create_by_handle(FileWrapper *);

void Lovok_set_logger(LOVOK_HANDLE h, void (*fn)(void *ctx, const char *msg, size_t len), void *ctx);

void Lovok_log(LOVOK_HANDLE h, const char *msg, size_t n);
void Lovok_log_puts(LOVOK_HANDLE h, const char *msg);
void Lovok_log_printf(LOVOK_HANDLE h, const char *fmt, ...);
void Lovok_log_vprintf(LOVOK_HANDLE h, const char *fmt, va_list ap);

LovokStatusCode valid_mp4(LOVOK_HANDLE);

void Lovok_destroy(LOVOK_HANDLE);

#if defined(__cplusplus)
}
#endif
#endif //LOVOK_LOVOK_H
