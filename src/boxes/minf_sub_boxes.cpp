#include "../lovok_handle_internal.h"
#include "minf_sub_boxes.h"
#include "dinf_sub_boxes.h"
#include "stbl_sub_boxes.h"

LovokStatusCode ParseVmhd(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseSmhd(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseHmhd(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseSthd(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseNmhd(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    // todo if this is involved in an exploit
}

LovokStatusCode ParseMinfDinf(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
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

LovokStatusCode ParseStbl(FileWrapper * fileWrapper, uint64_t length, uint64_t byteOffset) {
    byteOffset += 8;
    length -= 8;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
                                              length,
                                              byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
          LovokStatusCode result = SUCCESS;
          if (!strcmp(header.name, "stsd")) {
              result = ParseStsd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "stts")) {
              result = ParseStts(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "ctts")) {
              result = ParseCtts(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "cslg")) {
              result = ParseCslg(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "stsc")) {
              result = ParseStsc(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "stsz")) {
              result = ParseStsz(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "stz2")) {
              result = ParseStz2(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "stco")) {
              result = ParseStco(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "co64")) {
              result = ParseCo64(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "stss")) {
              result = ParseStss(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "stsh")) {
              result = ParseStsh(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "padb")) {
              result = ParsePadb(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "stdp")) {
              result = ParseStdp(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "sdtp")) {
              result = ParseSdtp(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "sbgp")) {
              result = ParseStblSbgp(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "sgpd")) {
              result = ParseStblSgpd(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "subs")) {
              result = ParseStblSubs(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "saiz")) {
              result = ParseStblSaiz(fileWrapper, header.size, byteOffset);
          } else if (!strcmp(header.name, "saio")) {
              result = ParseStblSaio(fileWrapper, header.size, byteOffset);
          }
          return result;
      });
    return parseResults;
}
