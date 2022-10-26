#ifndef LOVOK_TIME_TO_SAMPLE_BOX_H
#define LOVOK_TIME_TO_SAMPLE_BOX_H

#include "full_box.h"

class TimeToSampleBox : public FullBox {
private:
    uint32_t entry_count;
public:
    TimeToSampleBox(int s, char boxtype[4], const uint32_t ec) : FullBox(s, boxtype, 0, 0), entry_count(ec) {}
    
    virtual ~TimeToSampleBox() {}
};

#endif