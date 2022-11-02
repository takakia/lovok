#include "box.h"
#include "movie_header_box.h"

#ifndef LOVOK_MOVIE_BOX_H
#define LOVOK_MOVIE_BOX_H

class MoovBox : public Box {
public:

    MoovBox() {}
    MoovBox(int s, char n[4]) {
        size = s;
        strncpy(name, n, 4);
    }
};

#endif //LOVOK_MOVIE_BOX_H