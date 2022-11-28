#include <iostream>
#include "../lovok_handle_internal.h"
#include "moov_sub_boxes.h"
#include "trak_sub_boxes.h"
#include "mvex_sub_boxes.h"

LovokStatusCode ParseTrak(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "tkhd")) {
              result = ParseTkhd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "tref")) {
              result = ParseTref(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "trgr")) {
              result = ParseTrgr(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "edts")) {
              result = ParseEdts(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "meta")) {
              result = ParseTrakMeta(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "mdia")) {
              result = ParseMdia(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "udta")) {
              result = ParseTrakUdta(fileWrapper, header.size, byteOffset);
          } else {
              std::cout << "Unknown box name in ParseTrak: ";
              std::cout << header.name << std::endl;
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseMvhd(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseMoovMeta(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseMvex(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "mehd")) {
              result = ParseMehd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "trex")) {
              result = ParseTrex(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "leva")) {
              result = ParseLeva(fileWrapper, header.size, byteOffset);
          } else {
              std::cout << "Unknown box name in ParseMvex: ";
              std::cout << header.name << std::endl;
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseMoovUdta(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    //todo if this is involved in an exploit
}