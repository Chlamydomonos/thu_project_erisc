#include "inpututil.h"
#include "../vm/vm.h"
#include "../fuckide/fuckide.h"
#include "../io/textreader.h"
#include "../command/command.h"
#include "../command/allcommands.h"
using namespace erisc;

Command** input::readCommandsFromFile(const char* fileName)
{
	TextReader* a = new TextReader(fileName);
	int n = 0;
	while (a->readLine()[0] != 0)
		n++;
	delete a;
	a = new TextReader(fileName);

	Command** commands = new Command * [n];

	for(int i=0;i<n;i++)
	{
		char* order = a->readLine();

		while (*order == ' ')
			order++;

		if (order[0] == 'a' && order[1] == 'd' && order[2] == 'd') {
			//add
			Command* c = new Add(order + 3);
			commands[i] = c;
		//	commands[i].
		}
		else if (order[0] ==97 && order[1]==110 && order[2]==100) {
			//and
			Command* c = new And(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 98 && order[1] == 101 && order[2] == 113) {
			//beq
			Command* c = new Beq(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 98 && order[1] == 103 && order[2] == 101) {
			//bge
			Command* c = new Bge(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 98 && order[1] == 108 && order[2] == 116) {
			//blt
			Command* c = new Blt(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 98 && order[1] == 110 && order[2] == 101) {
			//bne
			Command* c = new Bne(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 99 && order[1] == 97 && order[2] == 108) {
			//cal
			Command* c = new Cal(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 100 && order[1] == 105 && order[2] == 118) {
			//div
			Command* c = new Div(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 100 && order[1] == 114 && order[2] == 97 && order[3] == 119) {
			//draw
			Command* c = new Draw();
			commands[i] = c;
		}
		else if (order[0] == 101 && order[1] == 110 && order[2] == 100) {
			//end
			Command* c = new End();
			commands[i] = c;
		}
		else if (order[0] == 106 && order[1] == 97 && order[2] == 108) {
			//jal
			Command* c = new Jal(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 108 && order[1] == 111 && order[2] == 97 && order[3] == 100) {
			//load
			Command* c = new Load(order + 4);
			commands[i] = c;
		}
		else if (order[0] == 109 && order[1] == 111 && order[2] == 118) {
			//mov
			Command* c = new Mov(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 109 && order[1] == 117 && order[2] == 108) {
			//mul
			Command* c = new Mul(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 111 && order[1] == 114) {
			//or
			Command* c = new Or(order + 2);
			commands[i] = c;
		}
		else if (order[0] == 112 && order[1] == 111 && order[2] == 102) {
			//pop
			Command* c = new Pop(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 112 && order[1] == 117 && order[2] == 115 && order[3] == 104) {
			//push
			Command* c = new Push(order + 4);
			commands[i] = c;
		}
		else if (order[0] == 114 && order[1] == 101 && order[2] == 109) {
			//rem
			Command* c = new Rem(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 114 && order[1] == 101 && order[2] == 116) {
			//ret
			Command* c = new Ret();
			commands[i] = c;
		}
		else if (order[0] == 115 && order[1] == 116 && order[2] == 111 && order[3] == 114 && order[4]==101) {
			//store
			Command* c = new Store(order + 5);
			commands[i] = c;
		}
		else if (order[0] == 115 && order[1] == 117 && order[2] == 98) {
			//sub
			Command* c = new Sub(order + 3);
			commands[i] = c;
			//Command *comands1通过new出来这样一个东西对*commands[]进行赋值
			//还要加上order后面的x5,x6
		}
	}
	return nullptr;
}