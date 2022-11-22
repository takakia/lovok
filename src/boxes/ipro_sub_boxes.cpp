#include "../lovok_handle_internal.h"
#include "ipro_sub_boxes.h"
#include "sinf_sub_boxes.h"

LovokStatusCode ParseSinf(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "frma")) {
              result = ParseFrma(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "schm")) {
              result = ParseSchm(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "schi")) {
              result = ParseSchi(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}