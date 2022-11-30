#include <iostream>
#include "../lovok_handle_internal.h"
#include "skip_sub_boxes.h"
#include "strk_sub_boxes.h"

LovokStatusCode ParseCprt(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    //todo: Handling exploit for box if one is known
}

LovokStatusCode ParseTsel(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    //todo: Handling exploit for box if one is known
}

LovokStatusCode ParseStrk(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "stri")) {
              result = ParseStri(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "strd")) {
              result = ParseStrd(fileWrapper, header.size, byteOffset);
          } else {
              std::cout << "Encountered unknown box while parsing 'strk' box: ";
              std::cout << header.name << std::endl;
          }
          return result;
      });
    return parseResults;
}
