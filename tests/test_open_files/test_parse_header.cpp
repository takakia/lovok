#include <iostream>
#include "lovok.h"

int main(int argc, char **argv) {
    const char *name = "test_data/test_recording0.mp4";
    std::cout << "Parsing" << name << std::endl;
    LOVOK_HANDLE handle = Lovok_create(name);
    if (!handle) {
      std::cout << "Error  opening file" << std::endl;
      return 1;
    }
    LovokStatusCode valid = valid_mp4(handle);
    if (valid != SUCCESS) {
        std::cout << "Error validating mp4 file" << std::endl;
        return 1;
    }
    Lovok_destroy(handle);
    return 0;
}
