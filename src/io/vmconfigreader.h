#ifndef VMCONFIGREADER_H
#define VMCONFIGREADER_H

#include <cstdio>

namespace input
{
	class VMConfigReader
	{
	public:
		VMConfigReader(const char* fileName);
		~VMConfigReader();
		int getMaxCommandAmount();
	private:
		int maxCommandAmount;
	};
}
#endif // !VMCONFIGREADER_H
