#include "../include/lovok.h"
#include "lovok_handle_internal.h"

#include <string.h>

void Lovok_set_logger(LOVOK_HANDLE h, void (*fn)(void *ctx, const char *msg, size_t len), void *ctx) {
    if (h) {
        h->log_callback = fn;
        h->log_context = ctx;
    }
}

void Lovok_log(LOVOK_HANDLE h, const char *msg, size_t n) {
    if (h && h->log_callback)
        h->log_callback(h->log_context, msg, n);
}

void Lovok_log_puts(LOVOK_HANDLE h, const char *msg) {
    if (msg)
        Lovok_log(h, msg, strlen(msg));
}

void Lovok_log_printf(LOVOK_HANDLE h, const char *fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    Lovok_log_vprintf(h, fmt, ap);
    va_end(ap);
}

void Lovok_log_vprintf(LOVOK_HANDLE h, const char *fmt, va_list ap) {
    char buf[128];

    vsnprintf(buf, sizeof(buf), fmt, ap);
    Lovok_log_puts(h, buf);
}
