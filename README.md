# Lovok

### Summary
Lovok is a dynamic library for validating mp4 files. 
Validation of files is designed around mp4 files on end-to-end encrypted clients. 
The library currently parses mp4 files as per [ISO/IEC 14496-17:2006](https://www.iso.org/standard/39478.html). 
As an mp4 file is parsed each boxes sub-boxes are validated to ensure that size in the header does not create integer overflow/underflow.

### Usage
The public header lovok.h contains public `C` functions to open and validate an mp4 file. 

A file pointer or file name is used to create a `LOVOK_HANDLE`. 
The LOVOK_HANDLE can be used to validate the mp4 file with the function `valid_mp4` which returns a `LovokStatusCode`. 
```c
int main(int argc, char **argv) {
    const char *name = "example.mp4";
    LOVOK_HANDLE handle = Lovok_create(name);
    if (!handle) {
      std::cout << "Error opening file" << std::endl;
      return 1;
    }
    LovokStatusCode valid = valid_mp4(handle);
    if (valid != VALID_FILE) {
        std::cout << "Error validating mp4 file" << std::endl;
        return 1;
    }
    Lovok_destroy(handle);
    return 0;
}
```


### Runing Tests
The tests can be run with the following
```bash
mkdir build
cd build
cmake ..
make
ctest
```