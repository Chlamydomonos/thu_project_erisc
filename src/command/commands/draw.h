#ifndef DRAW_H
#define DRAW_H

#include "../command.h"
#include "../../image/canvas.h"

namespace erisc {
	class Draw :public Command {
		Draw();
		~Draw();
		void run(vm::VM* vm);
	};
}

#endif