#include "draw.h"
#include "../../vm/vm.h"
#include "../../fuckide/fuckide.h"
#include "../../exception/exception.h"
#include "../../io/imageconfigreader.h"
#include <cmath>

using namespace erisc;
using namespace image;
using namespace vm;
using namespace input;

namespace {
	//将数字转化为字符串，零位存储数字最高位
	char* int_to_string(int n) {
		char num[10];
		for (int i = 0; i < 10; i++)
			num[i] = '0';
		int len = floor(log10(n)) + 1;
		for (int i = 0; i < len; i++) {
			num[i] = n % 10+'0';
			n /= 10;
		}char* res = new char[len];
		for (int i = len - 1; i >= 0; i--)
			res[i] = num[len - 1 - i];
		return res;
	}
}
erisc::Draw::Draw()
{
}

erisc::Draw::~Draw()
{
}

void erisc::Draw::run(vm::VM* vm)
{
	try {
		vm->timesOfDraw++;
		bool stack = vm->getStack()->getAccessed();
		bool memory[16];
		bool register_r[32];
		bool register_w[32];
		for (int i = 0; i < 16; i++)
			memory[i] = vm->getMemory()->getAccessed(i);
		for (int i = 0; i < 32; i++) {
			register_r[i] = vm->getRegister(i)->getRead();
			register_w[i] = vm->getRegister(i)->getWritten();
		}
		Canvas* artist = new Canvas("images/frame.bmp");
		ImageConfigReader* reader = new ImageConfigReader("images/image.imgcfg");
		int x_register;
		int y_register;
		int x_memory;
		int y_memory;
		int x_stack;
		int y_stack;
		int width_register;
		int height_register;
		int width_memory;
		int height_memory;
		x_register = reader->getRegisterOffsetX();
		y_register = reader->getRegisterOffsetY();
		x_memory = reader->getMemoryOffsetX();
		y_memory = reader->getMemoryOffsetY();
		x_stack = reader->getStackOffsetX();
		y_stack = reader->getStackOffsetY();
		width_register = reader->getRegisterSquareWidth();
		height_register = reader->getRegisterSquareHeight();
		width_memory = reader->getMemorySquareWidth();
		height_memory = reader->getMemorySquareHeight();
		Canvas* memory_green = new Canvas("images/memory_green.bmp");
		Canvas* register_red = new Canvas("images/register_red.bmp");
		Canvas* register_blue = new Canvas("images/register_blue.bmp");
		Canvas* register_purple = new Canvas("images/register_purple.bmp");
		Canvas* stack_orange = new Canvas("images/stack_orange.bmp");
		Canvas* register_white = new Canvas("images/register_white.bmp");
		Canvas* memory_white = new Canvas("images/memory_white.bmp");
		Canvas* stack_white = new Canvas("images/stack_white.bmp");
		if (stack)
			artist->applyCanvas(x_stack, y_stack, stack_orange);
		else
			artist->applyCanvas(x_stack, y_stack, stack_white);
		for (int i = 0; i < 16; i++)
			if (memory[i])
				artist->applyCanvas(x_memory + (i % 4) * width_memory, y_memory + (i / 4) * height_memory, memory_green);
			else
				artist->applyCanvas(x_memory + (i % 4) * width_memory, y_memory + (i / 4) * height_memory, memory_white);
		for (int i = 0; i < 32; i++) {
			if (register_w[i] && !register_r[i])
				artist->applyCanvas(x_register + (i % 8) * width_register, y_register + (i / 8) * height_register, register_red);
			else if (!register_w[i] && register_r[i])
				artist->applyCanvas(x_register + (i % 8) * width_register, y_register + (i / 8) * height_register, register_blue);
			else if (register_r[i] && register_w[i])
				artist->applyCanvas(x_register + (i % 8) * width_register, y_register + (i / 8) * height_register, register_purple);
			else
				artist->applyCanvas(x_register + (i % 8) * width_register, y_register + (i / 8) * height_register, register_white);

		}
		char name[20];
		char* number = int_to_string(vm->timesOfDraw);
		int len = (int)(floor(log10(vm->timesOfDraw)) + 1);
		for (int i = 0; i < len; i++)
			name[i] = number[i];
		name[len] = '.';
		name[len + 1] = 'b';
		name[len + 2] = 'm';
		name[len + 3] = 'p';
		name[len + 4] = 0;
		artist->writeToFile(name);
		delete artist;
		delete memory_green;
		delete stack_orange;
		delete register_blue;
		delete register_red;
		delete register_purple;
		vm->getStack()->clearHistory();
		vm->getMemory()->clearHistory();
		for (int i = 0; i < 32; i++)
			vm->getRegister(i)->clearHistory();
	}
	catch (Exception& e) {
		throw Exception("Failed to run command \"draw\"", e);
	}
}
