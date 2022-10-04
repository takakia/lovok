#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void print_usage() {
    std::cout << "Invalid inputs, usage: <full_file_path>";
}

int main(int argc, char** argv) {
    std::cout << "Num args: " <<  argc << "\n";
    std::cout << "Arguments: \n";

    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << "\n";
    }

    std::string inputFilename;

    if (argc > 1) {
        inputFilename = argv[1];
    } else {
        print_usage();
        return -1;
    }

    std::ifstream f(inputFilename);

    if (f) {
        std::cout << &f;
    } else {
        std::cout << "Unable to open file: " << inputFilename;
    }

    return 0;
}