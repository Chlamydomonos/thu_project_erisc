#ifndef FUCKIDE_H
#define FUCKIDE_H
#include <cstdio>

/**
* @brief 用于避免Visual Studio报错的fopen函数，用法与C语言中的fopen一致
*/
FILE* fuckIDEfopen(const char* fileName, const char* mode);

#endif // !FUCKIDE_H
