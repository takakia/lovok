#include "../lovok_handle_internal.h"
#include "fiin_sub_boxes.h"
#include "paen_sub_boxes.h"

LovokStatusCode ParsePaen(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "fire")) {
              result = ParseFire(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "fpar")) {
              result = ParseFpar(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "fecr")) {
              result = ParseFecr(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseSegr(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseGitn(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    //todo if this is involved in an exploit
}
