#ifndef LOVOK_LOVOK_H
#define LOVOK_LOVOK_H

typedef struct LovokHandleInternal *LOVOK_HANDLE;

LOVOK_HANDLE Lovok_create();

void Lovok_destroy(LOVOK_HANDLE);

#endif //LOVOK_LOVOK_H
