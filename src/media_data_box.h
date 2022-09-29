#ifndef LOVOK_MEDIA_DATA_BOX_H
#define LOVOK_MEDIA_DATA_BOX_H

#include "box.h"

class media_data_box: public box
{
private:
    uint8_t* data;
public:
    media_data_box(): box("mdat") {
        data = nullptr;
    }
    media_data_box(uint8_t* d): box("mdat") {
        data = d;//temporary not copied
    }
    
    virtual ~media_data_box() {
        // delete[] data;
    };
};

#endif