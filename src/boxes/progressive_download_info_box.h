#include "box.h"

#ifndef LOVOK_PROGRESSIVE_DOWNLOAD_INFO_BOX_H
#define LOVOK_PROGRESSIVE_DOWNLOAD_INFO_BOX_H

class ProgressiveDownloadInfoBox : public Box {
public:
    uint32_t rate;
    uint32_t initial_delay;

    ProgressiveDownloadInfoBox(int s, std::string n, uint32_t r, uint32_t d){
        size = s;
        name = std::move(n);
        rate = r;
        initial_delay = d;
    }
};

#endif //LOVOK_PROGRESSIVE_DOWNLOAD_INFO_BOX_H
