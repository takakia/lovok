#include <functional>
#include <cstring>
#include <iostream>
#include "lovok_handle_internal.h"
#include "io/file_io.h"
#include "boxes/box.h"
#include "../include/lovok.h"
#include "boxes/file_level_boxes.h"

uint32_t BoxSize32(unsigned char s[4]) {
    uint32_t size = s[3];
    size |= (uint32_t) s[2] << 8;
    size |= (uint32_t) s[1] << 16;
    size |= (uint32_t) s[0] << 24;
    return size;
}

uint64_t BoxSize64(unsigned char s[8]) {
    uint64_t size = s[7];
    size |= (uint64_t) s[6] << 8;
    size |= (uint64_t) s[5] << 16;
    size |= (uint64_t) s[4] << 24;
    size |= (uint64_t) s[3] << 32;
    size |= (uint64_t) s[2] << 40;
    size |= (uint64_t) s[1] << 48;
    size |= (uint64_t) s[0] << 56;
    return size;
}

LovokStatusCode ParseHeader(FileWrapper *fileWrapper, Box *header) {
    unsigned char size[4];
    ssize_t read = FileWrapper_Read(fileWrapper, size, sizeof(size));
    if (read != sizeof(size)) {
        return PARSE_ERROR;
    }
    char box_name[5] = "\0";
    read = FileWrapper_Read(fileWrapper, box_name, sizeof(box_name) - 1);
    if (read != sizeof(box_name) - 1) {
        return PARSE_ERROR;
    }
    strncpy(header->name, box_name, 5);
    uint32_t boxSize = BoxSize32(size);
    if (boxSize == 1) {
        unsigned char largeSize[8];
        read = FileWrapper_Read(fileWrapper, largeSize, sizeof(largeSize));
        if (read != sizeof(largeSize)) {
            return PARSE_ERROR;
        }
        header->size = BoxSize64(largeSize);
    } else {
        header->size = boxSize;
    }
    return VALID_FILE;
}

bool AdditionOverflow(uint64_t a, uint64_t b) {
    uint64_t result = a + b;
    if (result < a || result < b) {
        return true;
    }
    return false;
}

bool AdditionUnderflow(uint64_t a, uint64_t b) {
    uint64_t result = a - b;
    if ((result > a) || (result > b && a < b)) {
        return true;
    }
    return false;
}

LovokStatusCode ParseBoxes(FileWrapper *fileWrapper, uint64_t length, uint64_t byteOffset, const std::function<LovokStatusCode(const Box &, uint64_t)> &f) {
    if (length < 0) { return PARSE_ERROR; }
    while (length > 0) {
        Box header = Box();
        LovokStatusCode parsedHeader = ParseHeader(fileWrapper, &header);
        if (parsedHeader != VALID_FILE) {
            return PARSE_ERROR;
        }

        // Parse Boxes within this box with function f
        LovokStatusCode boxResult = f(header, byteOffset);
        if (boxResult != VALID_FILE && boxResult != UNKNOWN_BOX) {
            return boxResult;
        }
        // seek to next box
        int err = FileWrapper_Seek(fileWrapper, byteOffset + header.size);
        if (err != 0) {
            return PARSE_ERROR;
        }
        if (AdditionOverflow(byteOffset, header.size)) {
            return INVALID_FILE;
        }
        byteOffset += header.size;

        if (AdditionUnderflow(length, header.size)) {
            return INVALID_FILE;
        }
        length -= header.size;
    }
    return VALID_FILE;
}

LovokStatusCode ParseMp4(LOVOK_HANDLE_INTERNAL handle) {
    FileWrapper *fileWrapper = handle->wrapper;
    if (!fileWrapper) {
        return PARSE_ERROR;
    }
    uint64_t length = FileWrapper_Size(fileWrapper);
    uint64_t byteOffset = 0;
    LovokStatusCode parseResults = ParseBoxes(fileWrapper, length, byteOffset,
                                              [&fileWrapper] (const Box &header, uint64_t byteOffset) -> LovokStatusCode {
        // TODO add logic for Moov and other top level boxes
        LovokStatusCode result = UNKNOWN_BOX;
        if (!strcmp(header.name, "moov")) {
            result = ParseMoov(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "moof")) {
            result = ParseMoof(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "meta")) {
            result = ParseMeta(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "mfra")) {
            result = ParseMfra(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "skip")) {
            result = ParseSkip(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "meco")) {
            result = ParseMeco(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "ftyp")) {
            result = ParseFtyp(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "pdin")) {
            result = ParsePdin(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "mdat")) {
            result = ParseMdat(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "free")) {
            result = ParseFree(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "styp")) {
            result = ParseStyp(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "sidx")) {
            result = ParseSidx(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "ssix")) {
            result = ParseSsix(fileWrapper, header.size, byteOffset);
        } else if (!strcmp(header.name, "prft")) {
            result = ParsePrft(fileWrapper, header.size, byteOffset);
        } else {
            std::cout << "Encountered unknown box while parsing mp4 top level boxes: ";
            std::cout << header.name << std::endl;
        }
        return result;
    });
    return parseResults;
}