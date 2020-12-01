#ifndef LINEIDLIST_H
#define LINEIDLIST_H
#include "../command/lineid.h"

namespace vm
{
	struct RBTreeNode
	{
		bool red;
		erisc::LineId* value;
	};
}

#endif // !LINEIDLIST_H
