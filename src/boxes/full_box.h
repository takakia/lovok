#include "box.h"
#include <string>

#ifndef LOVOK_FULL_BOX_H
#define LOVOK_FULL_BOX_H

class FullBox : public Box {
public:
    uint8_t version;
    unsigned int flags : 24;

    FullBox(int s, char n[4], uint8_t v, unsigned int f)
        : Box(n, s), version(v) 
    {
        flags = std::move(f);
    }
};

#endif //LOVOK_FULL_BOX_H