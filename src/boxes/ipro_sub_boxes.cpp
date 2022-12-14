#include <iostream>
#include "../lovok_handle_internal.h"
#include "ipro_sub_boxes.h"
#include "sinf_sub_boxes.h"

LovokStatusCode ParseSinf(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              8,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "frma")) {
              result = ParseFrma(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "schm")) {
              result = ParseSchm(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "schi")) {
              result = ParseSchi(fileWrapper, header.size, byteOffset);
          } else {
              std::cout << "Encountered unknown box while parsing sinf box: ";
              std::cout << header.name << std::endl;
          }
          return result;
      });
    return parseResults;
}