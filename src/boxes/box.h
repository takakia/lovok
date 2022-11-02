#include <string>
#include <cstring>

#ifndef LOVOK_BOX_H
#define LOVOK_BOX_H

class Box {
public:
    uint64_t size;
    char name[5];

    Box() {}
    explicit Box(char n[4]) { strncpy(name, n, 4); }
};

#endif //LOVOK_BOX_H