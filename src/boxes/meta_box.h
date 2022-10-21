#include "box.h"
#include <utility>
#include <vector>

#ifndef LOVOK_META_BOX_H
#define LOVOK_META_BOX_H

class HandlerBox : public Box {
    uint32_t handler_type;

    HandlerBox(int s, const std::string& n, uint32_t ht) : Box(n, s), handler_type(ht) {}
};

class MetaBox : public Box {
    // The boxes containing metadata
    std::vector<Box> boxes;
    // Handler describing metadata
    HandlerBox handler_box;

    MetaBox(int s, const std::string& n, std::vector<Box> b, HandlerBox hb) : handler_box(hb), Box(n, s) 
    {
        boxes = std::move(b);
        handler_box = std::move(hb);
    }
};

#endif //LOVOK_META_BOX_H
