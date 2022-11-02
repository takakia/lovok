#ifndef UTIL_H
#define UTIL_H

#define BOX_NAME_BUFFER_LEN 5

#include <cstring>

class Util {
public:
    static int BoxNameCopy(char boxName[BOX_NAME_BUFFER_LEN], char* s) {
        size_t len = strlen(s);
        if (len > 4) { return -1; }
        strncpy(boxName, s, 4);
        boxName[4] = '\0';
        return 0;
    }
};

#endif //UTIL_H