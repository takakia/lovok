#ifndef LOVOK_MEDIA_DATA_BOX_H
#define LOVOK_MEDIA_DATA_BOX_H

#include "box.h"

class MediaDataBox: public Box
{
private:
    uint8_t* data;
public:
    MediaDataBox(): Box("mdat") {
        data = nullptr;
    }
    MediaDataBox(uint8_t* d): Box("mdat") {
        data = d;//temporary not copied
    }
    
    virtual ~MediaDataBox() {
        // delete[] data;
    };
};

#endif