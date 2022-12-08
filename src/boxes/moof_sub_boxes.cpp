#include <iostream>
#include "../lovok_handle_internal.h"
#include "moof_sub_boxes.h"
#include "traf_sub_boxes.h"

LovokStatusCode ParseMfhd(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseMoofMeta(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseTraf(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              8,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "tfhd")) {
              result = ParseTfhd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "trun")) {
              result = ParseTrun(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "sbgp")) {
              result = ParseTrafSbgp(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "sgpd")) {
              result = ParseTrafSgpd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "subs")) {
              result = ParseTrafSubs(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "saiz")) {
              result = ParseTrafSaiz(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "saio")) {
              result = ParseTrafSaio(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "tfdt")) {
              result = ParseTfdt(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "meta")) {
              result = ParseTrafMeta(fileWrapper, header.size, byteOffset);
          } else {
              std::cout << "Encountered unknown box while parsing traf box: ";
              std::cout << header.name << std::endl;
          }
          return result;
      });
    return parseResults;
}