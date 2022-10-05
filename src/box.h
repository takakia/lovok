//
//
#ifndef LOVOK_BOX_H
#define LOVOK_BOX_H


#include <string>

class Box {
public:
    int size;
    std::string name;

    Box() {}
    explicit Box(const std::string& n) { name = n; }
};

#endif //LOVOK_BOX_H
