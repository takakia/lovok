#include "box.h"
#include "movie_header_box.h"

#ifndef LOVOK_MOVIE_BOX_H
#define LOVOK_MOVIE_BOX_H

class MoovBox : public Box {
public:
	MoovBox() {}

    MoovBox(int s, char n[BOX_NAME_BUFFER_LEN]) : Box(n, s) {}
};

#endif //LOVOK_MOVIE_BOX_H