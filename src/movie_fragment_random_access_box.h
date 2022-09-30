#include "box.h"
#include "movie_header_box.h"

#ifndef LOVOK_MOVIE_FRAGMENT_RANDOM_ACCESS_BOX_H
#define LOVOK_MOVIE_FRAGMENT_RANDOM_ACCESS_BOX_H

class MovieFragmentRandomAccessBox : public Box {
public:

    MovieFragmentRandomAccessBox(int s, std::string n) {
        size = s;
        name = std::move(n);
    }
};

#endif //LOVOK_MOVIE_FRAGMENT_RANDOM_ACCESS_BOX_H