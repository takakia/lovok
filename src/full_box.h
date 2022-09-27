#include "box.h"
#include <string>

#ifndef LOVOK_FULL_BOX_H
#define LOVOK_FULL_BOX_H

class FullBox : public box {
public:
    uint8_t version;
    unsigned int flags : 24;

    FullBox(int s, std::string n, uint8_t v, unsigned int f) {
        size = s;
        name = std::move(n);
        version = v;
        flags = std::move(f);
    }
};

#endif //LOVOK_FULL_BOX_H