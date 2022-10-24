#include "../lovok_handle_internal.h"
#include "moov_sub_boxes.h"
#include "trak_sub_boxes.h"
#include "mvex_sub_boxes.h"

LovokStatusCode ParseTrak(FileWrapper *fileWrapper, uint64_t length) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              [&fileWrapper] (const Box &header) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "tkhd")) {
              result = ParseTkhd(fileWrapper, header.size);
          } else if (!strcmp(header.name, "tref")) {
              result = ParseTref(fileWrapper, header.size);
          } else if (!strcmp(header.name, "trgr")) {
              result = ParseTrgr(fileWrapper, header.size);
          } else if (!strcmp(header.name, "edts")) {
              result = ParseEdts(fileWrapper, header.size);
          } else if (!strcmp(header.name, "meta")) {
              result = ParseMeta(fileWrapper, header.size);
          } else if (!strcmp(header.name, "mdia")) {
              result = ParseMdia(fileWrapper, header.size);
          } else if (!strcmp(header.name, "udta")) {
              result = ParseUdta(fileWrapper, header.size);
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseMvhd(FileWrapper *fileWrapper, uint64_t length) {
    return SUCCESS;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseMeta(FileWrapper *fileWrapper, uint64_t length) {
    return SUCCESS;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseMvex(FileWrapper *fileWrapper, uint64_t length) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              [&fileWrapper] (const Box &header) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "mehd")) {
              result = ParseMehd(fileWrapper, header.size);
          } else if (!strcmp(header.name, "trex")) {
              result = ParseTrex(fileWrapper, header.size);
          } else if (!strcmp(header.name, "leva")) {
              result = ParseLeva(fileWrapper, header.size);
          }
          return result;
      });
    return parseResults;
}