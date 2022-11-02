#ifndef LOVOK_SAMPLE_SIZE_BOX_H
#define LOVOK_SAMPLE_SIZE_BOX_H

#include "box.h"

class SampleSizeBox : public Box {
    // Specifies default sample size
    // 0 -> each sample has a different size, stored in a sample_size table
    // !0 -> constant sample size, no need for table
    uint32_t sample_size;
    // Number of samples in the track (0 means it is the same as the number of entries in the given table)
    uint32_t sample_count;

    SampleSizeBox(int s, char n[BOX_NAME_BUFFER_LEN], uint32_t ss, uint32_t sc) : Box(n, s), sample_size(ss), sample_count(sc) {}
};

#endif //LOVOK_SAMPLE_SIZE_BOX_H
