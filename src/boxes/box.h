#ifndef LOVOK_BOX_H
#define LOVOK_BOX_H

#include <string>
#include "util.h"

class Box {
public:
    uint64_t size;
    char name[BOX_NAME_BUFFER_LEN];

    Box() {}
    explicit Box(char n[BOX_NAME_BUFFER_LEN]) { Util::BoxNameCopy(name, n); }
    Box(char n[BOX_NAME_BUFFER_LEN], uint64_t s) : size(s) { Util::BoxNameCopy(name, n); }
};

#endif //LOVOK_BOX_H