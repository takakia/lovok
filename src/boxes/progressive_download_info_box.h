#ifndef LOVOK_PROGRESSIVE_DOWNLOAD_INFO_BOX_H
#define LOVOK_PROGRESSIVE_DOWNLOAD_INFO_BOX_H

#include "box.h"

class ProgressiveDownloadInfoBox : public Box {
public:
    uint32_t rate;
    uint32_t initial_delay;

    ProgressiveDownloadInfoBox(int s, char n[BOX_NAME_BUFFER_LEN], uint32_t r, uint32_t d) : Box(n, s), rate(r), initial_delay(d) {}
};

#endif //LOVOK_PROGRESSIVE_DOWNLOAD_INFO_BOX_H
