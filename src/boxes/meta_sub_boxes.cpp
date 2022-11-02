#include "../lovok_handle_internal.h"
#include "meta_sub_boxes.h"
#include "dinf_sub_boxes.h"
#include "ipro_sub_boxes.h"
#include "fiin_sub_boxes.h"

LovokStatusCode ParseHdlr(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseDinf(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "dref")) {
              result = ParseDref(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseIloc(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseIpro(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "sinf")) {
              result = ParseSinf(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseIinf(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseXml(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseBxml(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    //todo if this is involved in an exploit
}

LovokStatusCode ParsePitm(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseFiin(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "paen")) {
              result = ParsePaen(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "segr")) {
              result = ParseSegr(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "gitn")) {
              result = ParseGitn(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseIdat(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    //todo if this is involved in an exploit
}

LovokStatusCode ParseIref(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    //todo if this is involved in an exploit
}