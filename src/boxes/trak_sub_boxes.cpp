#include "../lovok_handle_internal.h"
#include "trak_sub_boxes.h"
#include "edts_sub_boxes.h"
#include "mdia_sub_boxes.h"

LovokStatusCode ParseTkhd(FileWrapper * fileWrapper, uint64_t length) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseTref(FileWrapper * fileWrapper, uint64_t length) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseTrgr(FileWrapper * fileWrapper, uint64_t length) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseEdts(FileWrapper * fileWrapper, uint64_t length) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              [&fileWrapper] (const Box &header) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "edts")) {
              result = ParseEdts(fileWrapper, header.size);
          }
          return result;
        });
    return parseResults;
}

LovokStatusCode ParseMeta(FileWrapper * fileWrapper, uint64_t length) { // Redeclare here? Since it is a different level metadata box
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseMdia(FileWrapper * fileWrapper, uint64_t length) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              [&fileWrapper] (const Box &header) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "mdhd")) {
              result = ParseMdhd(fileWrapper, header.size);
          } else if (!strcmp(header.name, "hdlr")) {
              result = ParseHdlr(fileWrapper, header.size);
          } else if (!strcmp(header.name, "elng")) {
              result = ParseElng(fileWrapper, header.size);
          } else if (!strcmp(header.name, "minf")) {
              result = ParseMinf(fileWrapper, header.size);
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseUdta(FileWrapper * fileWrapper, uint64_t length) {
    return SUCCESS;
    // todo if this is involved in an exploit
}
