#include "fuckide.h"

#ifdef _MSC_VER
FILE* fuckIDEfopen(const char* fileName, const char* mode)
{
	FILE* temp = nullptr;
	if (fopen_s(&temp, fileName, mode) != 0)
		return nullptr;
	return temp;
}

#else

FILE* fuckIDEfopen(const char* fileName, const char* mode)
{
	FILE* temp = nullptr;
	temp = fopen(fileName, mode);
	return temp;
}

#endif