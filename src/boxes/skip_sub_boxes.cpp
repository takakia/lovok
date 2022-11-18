#include "../lovok_handle_internal.h"
#include "skipudta_sub_boxes.h"

LovokStatusCode ParseSkipUdta(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "cprt")) {
              result = ParseCprt(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "tsel")) {
              result = ParseTsel(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "strk")) {
              result = ParseStrk(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}