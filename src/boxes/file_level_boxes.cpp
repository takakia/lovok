#include "file_level_boxes.h"
#include "movie_box.h"
#include "../lovok_handle_internal.h"
#include "moov_sub_boxes.h"

LovokStatusCode ParseMoov(FileWrapper *fileWrapper, uint64_t length) {
    LovokStatusCode parseResults = ParseBoxes(fileWrapper,
               length,
               [&fileWrapper] (const Box &header) -> LovokStatusCode {
        LovokStatusCode result = SUCCESS;
        if (!strcmp(header.name, "trak")) {
            result = ParseTrak(fileWrapper, header.size);
        } else if (!strcmp(header.name, "mvhd")) {
            result = ParseMvhd(fileWrapper, header.size);
        } else if (!strcmp(header.name, "meta")) {
            result = ParseMeta(fileWrapper, header.size);
        } else if (!strcmp(header.name, "mvex")) {
            result = ParseMvex(fileWrapper, header.size);
        }
        return result;
    });
    return parseResults;
}

LovokStatusCode ParseMoof(FileWrapper *fileWrapper, uint64_t length) {
    return SUCCESS;
    //todo do the real thing
}