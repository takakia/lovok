#include "box.h"
#include <vector>

#ifndef LOVOK_FILE_TYPE_BOX_H
#define LOVOK_FILE_TYPE_BOX_H

class FileTypeBox : public box {
public:
    uint32_t major_brand;
    uint32_t minor_version;
    std::vector <uint32_t> compatible_brands;

    FileTypeBox(int s, std::string n, uint32_t mb, uint32_t mv, std::vector <uint32_t> cb) {
        size = s;
        name = std::move(n);
        major_brand = mb;
        minor_version = mv;
        compatible_brands = std::move(cb);
    }
};

#endif //LOVOK_FILE_TYPE_BOX_H
