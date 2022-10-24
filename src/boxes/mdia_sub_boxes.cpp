#include "../lovok_handle_internal.h"
#include "mdia_sub_boxes.h"
#include "minf_sub_boxes.h"

LovokStatusCode ParseMdhd(FileWrapper * fileWrapper, uint64_t length) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseHdlr(FileWrapper * fileWrapper, uint64_t length) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseElng(FileWrapper * fileWrapper, uint64_t length) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseMinf(FileWrapper * fileWrapper, uint64_t length) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              [&fileWrapper] (const Box &header) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "vmhd")) {
              result = ParseVmhd(fileWrapper, header.size);
          } else if (!strcmp(header.name, "smhd")) {
              result = ParseSmhd(fileWrapper, header.size);
          } else if (!strcmp(header.name, "hmhd")) {
              result = ParseHmhd(fileWrapper, header.size);
          } else if (!strcmp(header.name, "sthd")) {
              result = ParseSthd(fileWrapper, header.size);
          } else if (!strcmp(header.name, "nmhd")) {
              result = ParseNmhd(fileWrapper, header.size);
          } else if (!strcmp(header.name, "dinf")) {
              result = ParseDinf(fileWrapper, header.size);
          } else if (!strcmp(header.name, "dref")) {
              result = ParseDref(fileWrapper, header.size);
          }
          return result;
      });
    return parseResults;
}
