#ifndef LOVOK_MEDIA_DATA_BOX_H
#define LOVOK_MEDIA_DATA_BOX_H

#include "box.h"

class MediaDataBox: public Box
{
private:
    uint8_t* data;
public:
    MediaDataBox(): Box((char*)"mdat") {
        data = nullptr;
    }
    explicit MediaDataBox(uint8_t* d): Box((char*)"mdat") {
        data = d;//temporary not copied
    }
    
    virtual ~MediaDataBox() {
        // delete[] data;
    };
};

#endif