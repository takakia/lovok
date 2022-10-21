#include "box.h"
#include <utility>
#include <vector>

#ifndef LOVOK_META_BOX_H
#define LOVOK_META_BOX_H

class HandlerBox : public Box {
    uint32_t handler_type;

    HandlerBox(int s, char n[4], uint32_t ht) {
        size = s;
        strncpy(name, n, 4);
        handler_type = ht;
    }
};

class MetaBox : public Box {
    // The boxes containing metadata
    std::vector<Box> boxes;
    // Handler describing metadata
    HandlerBox handler_box;

    MetaBox(int s, char n[4], std::vector<Box> b, HandlerBox hb) : handler_box(hb) {
        size = s;
        strncpy(name, n, 4);
        boxes = std::move(b);
        handler_box = std::move(hb);
    }
};

#endif //LOVOK_META_BOX_H
