#ifndef LOVOK_MOVIE_FRAGMENT_RANDOM_ACCESS_BOX_H
#define LOVOK_MOVIE_FRAGMENT_RANDOM_ACCESS_BOX_H

#include "box.h"
#include "movie_header_box.h"

class MovieFragmentRandomAccessBox : public Box {
public:

    MovieFragmentRandomAccessBox(int s, char n[BOX_NAME_BUFFER_LEN]) : Box(n, s) {}
};

#endif //LOVOK_MOVIE_FRAGMENT_RANDOM_ACCESS_BOX_H