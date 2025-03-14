#ifndef LIBFS_H
#define LIBFS_H

#include <stdio.h>
#include <stdlib.h>

FILE* fileOpen(const char* filename, const char* mode);
int fileCreate(const char* filename);
void fileRead(FILE* file);
size_t fileWrite(const char* data, FILE* file);
int fileClose(FILE* file);
int fileDelete(const char* filename);

#endif