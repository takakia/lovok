#include "../lovok_handle_internal.h"
#include <iostream>
#include "fiin_sub_boxes.h"
#include "paen_sub_boxes.h"

LovokStatusCode ParsePaen(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "fire")) {
              result = ParseFire(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "fpar")) {
              result = ParseFpar(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "fecr")) {
              result = ParseFecr(fileWrapper, header.size, byteOffset);
          } else {
              std::cout << "Encountered unknown box while parsing paen box: ";
              std::cout << header.name << std::endl;
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseSegr(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseGitn(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    //todo if this is involved in an exploit
}
