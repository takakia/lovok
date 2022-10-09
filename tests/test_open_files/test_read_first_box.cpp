#include <iostream>
#include "io/file_io.h"
#include <cstring>

int main(int argc, char **argv) {
    const char *name = "test_data/test_recording0.mp4";
    std::cout << name << std::endl;
    FileWrapper *wrapper = FileWrapper_Open(name);
    if (!wrapper) {
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }

    char buffer[8];
    FileWrapper_Read(wrapper, buffer, sizeof(buffer));
    char box_name[5] = "\0";
    const char *ftyp = "ftyp";
    std::cout << sizeof box_name << std::endl;
    snprintf(box_name, sizeof box_name, "%s", buffer + 4);
    if (strncmp(box_name, ftyp, sizeof box_name) != 0) {
        std::cout << ftyp << " != " << box_name << std::endl;
        FileWrapper_Close(wrapper);
        return 1;
    }
    std::cout << box_name << std::endl;
    FileWrapper_Close(wrapper);

    return 0;
}
