#include "../lovok_handle_internal.h"
#include "meco_sub_boxes.h"
#include "mere_sub_boxes.h"

LovokStatusCode ParseMere(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "meta")) {
              result = ParseMereMeta(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}