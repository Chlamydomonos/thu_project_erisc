#include "vmconfigreader.h"
#include "../fuckide/fuckide.h"
#include <cstring>
#include "../exception/exception.h"

input::VMConfigReader::VMConfigReader(const char* fileName)
{
    FILE* config = fuckIDEfopen(fileName, "rb");

    if (config == nullptr)
    {
		const char* head = "Config file \"";
		int len1 = strlen(head);
		int len2 = len1 + strlen(fileName);
		const char* tail = "\" lost";
		int len3 = len2 + strlen(tail);
		char* message = new char[len3 + 1];
		for (int i = 0; i < len1; i++)
			message[i] = head[i];
		for (int i = len1; i < len2; i++)
			message[i] = fileName[i - len1];
		for (int i = len2; i < len3; i++)
			message[i] = tail[i - len2];
		message[len3] = 0;
		Exception exception(message);
		delete[] message;
		throw exception;
    }

    fread(&maxCommandAmount, 4, 1, config);
    fclose(config);
}

input::VMConfigReader::~VMConfigReader()
{

}

int input::VMConfigReader::getMaxCommandAmount()
{
    return maxCommandAmount;
}
