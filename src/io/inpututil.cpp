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

	Command** commands = new Command * [n + 2];
	commands[n + 1] = nullptr;
	commands[0] = new Command();

	for(int i=1;i<=n;i++)
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
		else if (order[0] =='a' && order[1]=='n' && order[2]=='d') {
			//and
			Command* c = new And(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 'b' && order[1] == 'e' && order[2] == 'q') {
			//beq
			Command* c = new Beq(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 'b' && order[1] == 'g' && order[2] == 'e') {
			//bge
			Command* c = new Bge(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 'b' && order[1] == 'l' && order[2] == 't') {
			//blt
			Command* c = new Blt(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 'b' && order[1] == 'n' && order[2] == 'e') {
			//bne
			Command* c = new Bne(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 'c' && order[1] == 'a' && order[2] == 'l') {
			//cal
			Command* c = new Cal(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 'd' && order[1] == 'i' && order[2] == 'v') {
			//div
			Command* c = new Div(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 'd' && order[1] == 'r' && order[2] == 'a' && order[3] == 'w') {
			//draw
			Command* c = new Draw();
			commands[i] = c;
		}
		else if (order[0] == 'e' && order[1] == 'n' && order[2] == 'd') {
			//end
			Command* c = new End();
			commands[i] = c;
		}
		else if (order[0] == 'j' && order[1] == 'a' && order[2] == 'l') {
			//jal
			Command* c = new Jal(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 'l' && order[1] == 'o' && order[2] == 'a' && order[3] == 'd') {
			//load
			Command* c = new Load(order + 4);
			commands[i] = c;
		}
		else if (order[0] == 'm' && order[1] == 'o' && order[2] == 'v') {
			//mov
			Command* c = new Mov(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 'm' && order[1] == 'u' && order[2] == 'l') {
			//mul
			Command* c = new Mul(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 'o' && order[1] == 'r') {
			//or
			Command* c = new Or(order + 2);
			commands[i] = c;
		}
		else if (order[0] == 'p' && order[1] == 'o' && order[2] == 'p') {
			//pop
			Command* c = new Pop(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 'p' && order[1] == 'u' && order[2] == 's' && order[3] == 'h') {
			//push
			Command* c = new Push(order + 4);
			commands[i] = c;
		}
		else if (order[0] == 'r' && order[1] == 'e' && order[2] == 'm') {
			//rem
			Command* c = new Rem(order + 3);
			commands[i] = c;
		}
		else if (order[0] == 'r' && order[1] == 'e' && order[2] == 't') {
			//ret
			Command* c = new Ret();
			commands[i] = c;
		}
		else if (order[0] == 's' && order[1] == 't' && order[2] == 'o' && order[3] == 'r' && order[4]=='e') {
			//store
			Command* c = new Store(order + 5);
			commands[i] = c;
		}
		else if (order[0] == 's' && order[1] == 'u' && order[2] == 'b') {
			//sub
			Command* c = new Sub(order + 3);
			commands[i] = c;
			//Command *comands1通过new出来这样一个东西对*commands[]进行赋值
			//还要加上order后面的x5,x6
		}
	}
	return commands;
}