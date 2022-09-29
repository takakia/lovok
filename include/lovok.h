#ifndef LOVOK_LOVOK_H
#define LOVOK_LOVOK_H
#if defined(__cplusplus)
extern "C" {
#endif

typedef struct LovokHandleInternal *LOVOK_HANDLE;

LOVOK_HANDLE Lovok_create();

void Lovok_destroy(LOVOK_HANDLE);

#if defined(__cplusplus)
}
#endif
#endif //LOVOK_LOVOK_H
