#include <utility>
#include <vector>
#include "box.h"

#ifndef LOVOK_MOVIE_FRAGMENT_BOX_H
#define LOVOK_MOVIE_FRAGMENT_BOX_H


class MovieFragmentHeaderBox : public Box {
public:
    uint32_t sequence_number;

    MovieFragmentHeaderBox(int s, std::string n, uint32_t sn) {
        size = s;
        name = std::move(n);
        sequence_number = sn;
    }
};


class TrackFragmentHeaderBox : public Box {
    uint32_t track_id;
    uint32_t base_data_offset;
    uint32_t sample_description_index;
    uint32_t default_sample_duration;
    uint32_t default_sample_size;
    uint32_t default_sample_flags;

    TrackFragmentHeaderBox(int s, std::string n, uint32_t tid, uint32_t b=9999,uint32_t si=9999,
                           uint32_t dsd=9999, uint32_t dss=9999, uint32_t dsf=9999) {
        size = s;
        name = std::move(n);
        track_id = tid;
        base_data_offset = b;
        sample_description_index = si;
        default_sample_duration = dsd;
        default_sample_size = dss;
        default_sample_flags = dsf;
    }
};




class MovieFragmentBox : public Box {
    MovieFragmentHeaderBox mfhd;
    std::vector<TrackFragmentHeaderBox> tfhd;

    MovieFragmentBox(int s, std::string n, MovieFragmentHeaderBox m,
                     std::vector<TrackFragmentHeaderBox> t) : mfhd(std::move(m)) {
        size = s;
        name = std::move(n);
        tfhd = std::move(t);
    }
};



#endif //LOVOK_MOVIE_FRAGMENT_BOX_H
