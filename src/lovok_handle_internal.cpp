#include "lovok_handle_internal.h"
#include "io/file_io.h"
#include "boxes/box.h"

enum LovokStatusCode {
    SUCCESS = 0,
    PARSE_ERROR = 1,
};

LovokStatusCode parse_header(FileWrapper *fileWrapper, Box *header);

uint32_t box_size32(unsigned char s[4]) {
    uint32_t size = s[3];
    size |= (uint32_t) s[2] << 8;
    size |= (uint32_t) s[1] << 16;
    size |= (uint32_t) s[0] << 24;
    return size;
}

uint64_t box_size64(unsigned char s[8]) {
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

bool parse_mp4(LOVOK_HANDLE_INTERNAL handle) {
    FileWrapper *fileWrapper = FileWrapper_Open(handle->name);
    if (!fileWrapper) {
        return false;
    }
    uint64_t length = FileWrapper_Size(fileWrapper);
    uint64_t byteOffset = 0;
    while (length > 0) {
        Box header = Box();
        LovokStatusCode parsedHeader = parse_header(fileWrapper, &header);
        if (parsedHeader != SUCCESS) {
            FileWrapper_Close(fileWrapper);
            return false;
        }

        // seek to next box
        int err = FileWrapper_Seek(fileWrapper, byteOffset + header.size);
        if (err != 0) {
            FileWrapper_Close(fileWrapper);
            return false;
        }
        byteOffset += header.size;
        length -= header.size;
    }
    FileWrapper_Close(fileWrapper);
    return true;
}

LovokStatusCode parse_header(FileWrapper *fileWrapper, Box *header) {
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
    header->name = std::string(box_name);
    uint32_t boxSize = box_size32(size);
    if (boxSize == 1) {
        unsigned char largeSize[8];
        read = FileWrapper_Read(fileWrapper, largeSize, sizeof(largeSize));
        if (read != sizeof(largeSize)) {
            return PARSE_ERROR;
        }
        header->size = box_size64(largeSize);
    } else {
        header->size = boxSize;
    }
    return SUCCESS;
}
