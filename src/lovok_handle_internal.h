#ifndef LOVOK_LOVOK_HANDLE_INTERNAL_H
#define LOVOK_LOVOK_HANDLE_INTERNAL_H

typedef struct LovokHandleInternal {
    const char * name;
} *LOVOK_HANDLE_INTERNAL;

bool parse_mp4(LOVOK_HANDLE_INTERNAL);

#endif //LOVOK_LOVOK_HANDLE_INTERNAL_H
