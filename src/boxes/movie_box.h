#include "box.h"
#include "movie_header_box.h"

#ifndef LOVOK_MOVIE_BOX_H
#define LOVOK_MOVIE_BOX_H

class MoovBox : public Box {
public:

    MoovBox(int s, const std::string& n) : Box(n, s) {}
};

#endif //LOVOK_MOVIE_BOX_H