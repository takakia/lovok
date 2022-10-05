#include <iostream>
#include "io/file_io.h"


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
    char *boxName = buffer + 4;
    std::cout << boxName << std::endl;


    std::cout << wrapper << std::endl;
    FileWrapper_Close(wrapper);

    return 0;
}