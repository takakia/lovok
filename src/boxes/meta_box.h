#ifndef LOVOK_META_BOX_H
#define LOVOK_META_BOX_H

#include "box.h"
#include <utility>
#include <vector>

class HandlerBox : public Box {
    uint32_t handler_type;

    HandlerBox(int s, char n[BOX_NAME_BUFFER_LEN], uint32_t ht) : Box(n, s), handler_type(ht) {}
};

class MetaBox : public Box {
    // The boxes containing metadata
    std::vector<Box> boxes;
    // Handler describing metadata
    HandlerBox handler_box;

    MetaBox(int s, char n[BOX_NAME_BUFFER_LEN], std::vector<Box> b, HandlerBox hb) : handler_box(hb), Box(n, s) 
    {
        boxes = std::move(b);
        handler_box = std::move(hb);
    }
};

#endif //LOVOK_META_BOX_H
