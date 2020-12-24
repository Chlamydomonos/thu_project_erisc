#include "vmconfigreader.h"
#include "../fuckide/fuckide.h"

input::VMConfigReader::VMConfigReader(const char* fileName)
{
    FILE* config = fuckIDEfopen(fileName, "rb");
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
