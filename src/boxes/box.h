#include <string>
#include <cstring>

#ifndef LOVOK_BOX_H
#define LOVOK_BOX_H

class Box {
public:
    uint64_t size;
    char name[5];

    Box() {}

    explicit Box(const std::string& n) : name(n) {}
    Box(const std::string& n, uint64_t s) : name(n), size(s) {}
};

#endif //LOVOK_BOX_H