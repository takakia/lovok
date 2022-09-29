//
//
#ifndef LOVOK_BOX_H
#define LOVOK_BOX_H


#include <string>

class box {
public:
    int size;
    std::string name;

    box() {}
    explicit box(const std::string& n) { name = n; }
};

#endif //LOVOK_BOX_H
