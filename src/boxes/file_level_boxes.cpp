#include "file_level_boxes.h"
#include "movie_box.h"
#include "../lovok_handle_internal.h"
#include "moov_sub_boxes.h"
#include "moof_sub_boxes.h"
#include "meta_sub_boxes.h"
#include "mfra_sub_boxes.h"
#include "skip_sub_boxes.h"
#include "meco_sub_boxes.h"

LovokStatusCode ParseMoov(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
               length,
               byteOffset,
               [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
        LovokStatusCode result = SUCCESS;
        if (!strcmp(header.name, "trak")) {
            result = ParseTrak(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "mvhd")) {
            result = ParseMvhd(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "meta")) {
            result = ParseMoovMeta(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "mvex")) {
            result = ParseMvex(fileWrapper, header.size, byteOffset);
        }
        return result;
    });
    return parseResults;
}

LovokStatusCode ParseMoof(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "mfhd")) {
              result = ParseMfhd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "meta")) {
              result = ParseMoofMeta(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "traf")) {
              result = ParseTraf(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseMeta(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "hdlr")) {
              result = ParseHdlr(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "dinf")) {
              result = ParseDinf(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "iloc")) {
              result = ParseIloc(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "ipro")) {
              result = ParseIpro(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "iinf")) {
              result = ParseIinf(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "xml")) {
              result = ParseXml(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "bxml")) {
              result = ParseBxml(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "pitm")) {
              result = ParsePitm(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "fiin")) {
              result = ParseFiin(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "idat")) {
              result = ParseIdat(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "iref")) {
              result = ParseIref(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseMfra(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "tfra")) {
              result = ParseTfra(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "mfro")) {
              result = ParseMfro(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseSkip(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "udta")) {
              result = ParseSkipUdta(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseMeco(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "mere")) {
              result = ParseMere(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}