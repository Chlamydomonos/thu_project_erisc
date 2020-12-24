#include "testmain.h"
#include "../io/imageconfigreader.h"
#include <iostream>
using namespace std;
using namespace input;
int testMain()
{
	ImageConfigReader* i = new ImageConfigReader("images/image.imgcfg");
	printf("%d %d, %d %d, %d %d, %d %d, %d %d", i->getRegisterOffsetX(), i->getRegisterOffsetY(),
		i->getMemoryOffsetX(), i->getMemoryOffsetY(), i->getStackOffsetX(), i->getStackOffsetY(),
		i->getRegisterSquareWidth(), i->getRegisterSquareHeight(), i->getMemorySquareWidth(), i->getMemorySquareHeight());
	return 0;
}
