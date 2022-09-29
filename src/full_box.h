#ifndef LOVOK_FULL_BOX_H
#define LOVOK_FULL_BOX_H

#include <string.h>
#include "box.h"
#define FLAG_LEN 3

class full_box : public box {
private:
    uint8_t version;
    uint8_t flags[FLAG_LEN];
public:
    full_box(const std::string& boxtype, const uint8_t v = '\0', const uint8_t* f = nullptr) : box(boxtype) {
        version = v;
        if (nullptr == f) {
            memset(flags, 0, sizeof(flags));
        } else {
            memcpy(flags, f, FLAG_LEN);
        }
    }
    virtual ~full_box() {}
};

#endif