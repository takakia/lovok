#include <iostream>
#include "file_level_boxes.h"
#include "../lovok_handle_internal.h"
#include "moov_sub_boxes.h"
#include "moof_sub_boxes.h"
#include "meta_sub_boxes.h"
#include "mfra_sub_boxes.h"
#include "skip_sub_boxes.h"
#include "meco_sub_boxes.h"

LovokStatusCode ParseMoov(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
               length,
               byteOffset,
               8,
               [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
        LovokStatusCode result = UNKNOWN_BOX;
        if (!strcmp(header.name, "trak")) {
            result = ParseTrak(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "mvhd")) {
            result = ParseMvhd(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "meta")) {
            result = ParseMoovMeta(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "mvex")) {
            result = ParseMvex(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "udta")) {
            result = ParseMoovUdta(fileWrapper, header.size, byteOffset);
        } else {
            std::cout << "Encountered unknown box while parsing moov box: ";
            std::cout << header.name << std::endl;
        }
        return result;
    });
    return parseResults;
}

LovokStatusCode ParseMoof(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              8,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "mfhd")) {
              result = ParseMfhd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "meta")) {
              result = ParseMoofMeta(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "traf")) {
              result = ParseTraf(fileWrapper, header.size, byteOffset);
          } else {
              std::cout << "Encountered unknown box while parsing moof box: ";
              std::cout << header.name << std::endl;
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseMeta(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              8,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
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
          } else {
              std::cout << "Encountered unknown box while parsing meta box: ";
              std::cout << header.name << std::endl;
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseMfra(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              8,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "tfra")) {
              result = ParseTfra(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "mfro")) {
              result = ParseMfro(fileWrapper, header.size, byteOffset);
          } else {
              std::cout << "Encountered unknown box while parsing mfra box: ";
              std::cout << header.name << std::endl;
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseSkip(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              8,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "udta")) {
              result = ParseSkipUdta(fileWrapper, header.size, byteOffset);
          } else {
              std::cout << "Encountered unknown box while parsing skip box: ";
              std::cout << header.name << std::endl;
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseMeco(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              8,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = UNKNOWN_BOX;
          if (!strcmp(header.name, "mere")) {
              result = ParseMere(fileWrapper, header.size, byteOffset);
          } else {
              std::cout << "Encountered unknown box while parsing meco box: ";
              std::cout << header.name << std::endl;
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseFtyp(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParsePdin(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseMdat(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseFree(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseStyp(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseSidx(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseSsix(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}

LovokStatusCode ParsePrft(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return VALID_FILE;
    // todo if this is involved in an exploit
}