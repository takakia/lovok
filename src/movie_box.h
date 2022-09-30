#include "box.h"
#include "movie_header_box.h"

#ifndef LOVOK_MOVIE_BOX_H
#define LOVOK_MOVIE_BOX_H

class MovieBox : public Box {
public:

    MovieBox(int s, std::string n) {
        size = s;
        name = std::move(n);
    }
};

#endif //LOVOK_MOVIE_BOX_H