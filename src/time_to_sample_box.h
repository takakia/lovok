#ifndef LOVOK_TIME_TO_SAMPLE_BOX_H
#define LOVOK_TIME_TO_SAMPLE_BOX_H

#include "full_box.h"

class time_to_sample_box : public full_box {
private:
    uint32_t entry_count;
public:
    time_to_sample_box(const std::string& boxtype, const uint32_t ec) : full_box(boxtype) {
        entry_count = ec;
    }
    virtual ~time_to_sample_box() {}
};

#endif