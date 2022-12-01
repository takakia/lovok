#include <iostream>
#include "../lovok_handle_internal.h"
#include "trak_sub_boxes.h"
#include "edts_sub_boxes.h"
#include "mdia_sub_boxes.h"

LovokStatusCode ParseTkhd(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseTref(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseTrgr(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseEdts(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "elst")) {
              result = ParseElst(fileWrapper, header.size, byteOffset);
          } else {
              std::cout << "Encountered unknown box while parsing edts box: ";
              std::cout << header.name << std::endl;
          }
          return result;
        });
    return parseResults;
}

LovokStatusCode ParseTrakMeta(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) { // Redeclare here? Since it is a different level metadata box
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseMdia(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "mdhd")) {
              result = ParseMdhd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "hdlr")) {
              result = ParseMdiaHdlr(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "elng")) {
              result = ParseElng(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "minf")) {
              result = ParseMinf(fileWrapper, header.size, byteOffset);
          } else {
              std::cout << "Encountered unknown box while parsing mdia box: ";
              std::cout << header.name << std::endl;
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseTrakUdta(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}
