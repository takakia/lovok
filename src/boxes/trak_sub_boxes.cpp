#include "../lovok_handle_internal.h"
#include "trak_sub_boxes.h"
#include "edts_sub_boxes.h"
#include "mdia_sub_boxes.h"

LovokStatusCode ParseTkhd(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseTref(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseTrgr(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseEdts(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "edts")) {
              result = ParseEdts(fileWrapper, header.size, byteOffset);
          }
          return result;
        });
    return parseResults;
}

LovokStatusCode ParseTrakMeta(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) { // Redeclare here? Since it is a different level metadata box
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseMdia(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "mdhd")) {
              result = ParseMdhd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "hdlr")) {
              result = ParseMdiaHdlr(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "elng")) {
              result = ParseElng(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "minf")) {
              result = ParseMinf(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseUdta(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    // todo if this is involved in an exploit
}
