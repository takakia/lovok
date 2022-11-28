#include <iostream>
#include "../lovok_handle_internal.h"
#include "mdia_sub_boxes.h"
#include "minf_sub_boxes.h"

LovokStatusCode ParseMdhd(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseMdiaHdlr(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseElng(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseMinf(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "vmhd")) {
              result = ParseVmhd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "smhd")) {
              result = ParseSmhd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "hmhd")) {
              result = ParseHmhd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "sthd")) {
              result = ParseSthd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "nmhd")) {
              result = ParseNmhd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "dinf")) {
              result = ParseMinfDinf(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "stbl")) {
              result = ParseStbl(fileWrapper, header.size, byteOffset);
          } else {
              std::cout << "Unknown box name in ParseMinf: ";
              std::cout << header.name << std::endl;
          }
          return result;
      });
    return parseResults;
}
