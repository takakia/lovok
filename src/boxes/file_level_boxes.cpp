#include "file_level_boxes.h"
#include "movie_box.h"
#include "../lovok_handle_internal.h"
#include "moov_sub_boxes.h"

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
            result = ParseMeta(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "mvex")) {
            result = ParseMvex(fileWrapper, header.size, byteOffset);
        }
        return result;
    });
    return parseResults;
}

LovokStatusCode ParseMoof(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset) {
    return SUCCESS;
    //todo do the real thing
}