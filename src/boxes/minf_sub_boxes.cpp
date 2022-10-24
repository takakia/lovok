#include "../lovok_handle_internal.h"
#include "minf_sub_boxes.h"
#include "dinf_sub_boxes.h"
#include "stbl_sub_boxes.h"

LovokStatusCode ParseVmhd(FileWrapper * fileWrapper, uint64_t length) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseSmhd(FileWrapper * fileWrapper, uint64_t length) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseHmhd(FileWrapper * fileWrapper, uint64_t length) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseSthd(FileWrapper * fileWrapper, uint64_t length) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseNmhd(FileWrapper * fileWrapper, uint64_t length) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseDinf(FileWrapper * fileWrapper, uint64_t length) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              [&fileWrapper] (const Box &header) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "dref")) {
              result = ParseDref(fileWrapper, header.size);
          }
          return result;
      });
    return parseResults;
}

LovokStatusCode ParseStbl(FileWrapper * fileWrapper, uint64_t length) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              [&fileWrapper] (const Box &header) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "stsd")) {
              result = ParseStsd(fileWrapper, header.size);
          } else if (!strcmp(header.name, "stts")) {
              result = ParseStts(fileWrapper, header.size);
          } else if (!strcmp(header.name, "ctts")) {
              result = ParseCtts(fileWrapper, header.size);
          } else if (!strcmp(header.name, "cslg")) {
              result = ParseCslg(fileWrapper, header.size);
          } else if (!strcmp(header.name, "stsc")) {
              result = ParseStsc(fileWrapper, header.size);
          } else if (!strcmp(header.name, "stsz")) {
              result = ParseStsz(fileWrapper, header.size);
          } else if (!strcmp(header.name, "stz2")) {
              result = ParseStz2(fileWrapper, header.size);
          } else if (!strcmp(header.name, "stco")) {
              result = ParseStco(fileWrapper, header.size);
          } else if (!strcmp(header.name, "co64")) {
              result = ParseCo64(fileWrapper, header.size);
          } else if (!strcmp(header.name, "stss")) {
              result = ParseStss(fileWrapper, header.size);
          } else if (!strcmp(header.name, "stsh")) {
              result = ParseStsh(fileWrapper, header.size);
          } else if (!strcmp(header.name, "padb")) {
              result = ParsePadb(fileWrapper, header.size);
          } else if (!strcmp(header.name, "stdp")) {
              result = ParseStdp(fileWrapper, header.size);
          } else if (!strcmp(header.name, "sdtp")) {
              result = ParseSdtp(fileWrapper, header.size);
          } else if (!strcmp(header.name, "sbgp")) {
              result = ParseSbgp(fileWrapper, header.size);
          } else if (!strcmp(header.name, "sgpd")) {
              result = ParseSgpd(fileWrapper, header.size);
          } else if (!strcmp(header.name, "subs")) {
              result = ParseSubs(fileWrapper, header.size);
          } else if (!strcmp(header.name, "saiz")) {
              result = ParseSaiz(fileWrapper, header.size);
          } else if (!strcmp(header.name, "saio")) {
              result = ParseSaio(fileWrapper, header.size);
          }
          return result;
      });
    return parseResults;
}
