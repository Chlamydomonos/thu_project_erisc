#ifndef LOAD_H
#define LOAD_H
#include "../command.h"
namespace erisc
{
	class Load : public Command
	{
	public:
		Load(char* paramString);
		~Load();
		void run(VM* vm);
	};
}

#endif // !LOAD_H
