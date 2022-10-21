#include "box.h"
#include "full_box.h"

#ifndef LOVOK_MOVIE_HEADER_BOX_H
#define LOVOK_MOVIE_HEADER_BOX_H

class MovieHeaderBox : public FullBox {
public:
    // if version == 1
    uint64_t creation_time;
    uint64_t modification_time;
    uint32_t timescale;
    uint64_t duration;
    // TODO find a way to change the class variables based on the version
    // else version == 0
//    uint32_t creation_time;
//    uint32_t modification_time;
//    uint32_t timescale;
//    uint32_t duration;

    // these will be bitwise masks
    int32_t rate = 0x00010000; //typically 1.0
    int16_t volume = 0x0100; //typically, full volume
    uint16_t reserved = 0;
    int32_t matrix [9] = {0x00010000,0,0,0,0x00010000,0,0,0,0x40000000};
    uint32_t pre_defined = 0;
    uint32_t next_track_ID;
    MovieHeaderBox(int s, std::string n, uint8_t v, unsigned int f, uint64_t c, uint64_t m, uint32_t t, uint64_t d) 
        : FullBox(s, n, v, f), creation_time(c), modification_time(m), timescale(t), duration(d) {}
};

#endif //LOVOK_MOVIE_HEADER_BOX_H