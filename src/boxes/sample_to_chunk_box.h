#include "box.h"
#include <vector>

#ifndef LOVOK_SAMPLE_TO_CHUNK_BOX_H
#define LOVOK_SAMPLE_TO_CHUNK_BOX_H

class Entry {
public:
    // index of first chunk in run of chunks that share same samples_per_chunk and sample_description_idx
    uint32_t first_chunk_idx;
    // the number of samples in each chunk
    uint32_t samples_per_chunk;
    // index of sample entry that describes samples in this chunk
    uint32_t sample_description_idx;

    Entry(uint32_t fci, uint32_t spc, uint32_t sdi) : first_chunk_idx(fci), samples_per_chunk(spc), sample_description_idx(sdi) {}
};

class SampleToChunkBox : public Box {
public:
    // The number of entries in the entries table
    uint32_t entry_count;
    // Array of entries
    std::vector<Entry> entries;

    SampleToChunkBox(int s, char n[4], uint32_t ec, std::vector<Entry> e) 
        : Box(n, s), entry_count(ec) 
    {
        entries = std::move(e);
    }
};

#endif //LOVOK_SAMPLE_TO_CHUNK_BOX_H
