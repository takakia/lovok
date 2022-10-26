#include <string>
#include <cstring>

#ifndef LOVOK_BOX_H
#define LOVOK_BOX_H

#define BOX_NAME_BUFFER_LEN 5

int BoxNameCopy(char boxName[BOX_NAME_BUFFER_LEN], char* s) {
    size_t len = strlen(s);
    if (len > 4) { return -1; }
    strncpy(boxName, s, 4);
    boxName[4] = '\0';
    return 0;
}

class Box {
public:
    uint64_t size;
    char name[BOX_NAME_BUFFER_LEN];

    Box() {}
    explicit Box(char n[BOX_NAME_BUFFER_LEN]) { BoxNameCopy(name, n); }
    Box(char n[BOX_NAME_BUFFER_LEN], uint64_t s) : size(s) { BoxNameCopy(name, n); }
};

#endif //LOVOK_BOX_H