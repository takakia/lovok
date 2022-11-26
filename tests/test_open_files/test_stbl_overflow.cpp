//
// Created by Andrew Molis on 11/22/22.
//
#include <iostream>
#include "lovok.h"

int main(int argc, char **argv) {
    const char *name = "test_data/test_sample_exploit_stsc.mp4";
    std::cout << "Parsing" << name << std::endl;
    FileWrapper *wrapper = FileWrapper_Open(name);
    if (!wrapper) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    LOVOK_HANDLE handle = Lovok_create_by_handle(wrapper);
    if (!handle) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    LovokStatusCode valid = valid_mp4(handle);
    if (valid != INVALID_FILE) {
        std::cout << "Error validating mp4 file" << std::endl;
        return 1;
    }
    Lovok_destroy(handle);
    return 0;
}
