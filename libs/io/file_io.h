#ifndef LOVOK_FILE_IO_H
#define LOVOK_FILE_IO_H

#if defined(__cplusplus)
extern "C" {
#endif

struct FileWrapper *FILE_WRAPPER;

struct FileWrapper *FileWrapper_Open(const char *name);
ssize_t FileWrapper_Read(struct FileWrapper *wrap, void *buf, ssize_t len);
int FileWrapper_Seek(struct FileWrapper *wrap, uint64_t pos);
void FileWrapper_Close(struct FileWrapper *wrap);


#if defined(__cplusplus)
}
#endif
#endif //LOVOK_FILE_IO_H
