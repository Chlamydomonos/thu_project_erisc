#include "inpututil.h"
#include "../vm/vm.h"
#include "../fuckide/fuckide.h"
#include "../io/textreader.h"
#include "../command/command.h"
#include "../command/allcommands.h"
#include <cmath>

#define HEAD_LEN 19
#define BUFFER_LEN 64

#define ALPHA(x) ((x) >= 'a' && (x) <= 'z')
#define CAPITAL(x) ((x) >= 'A' && (x) <= 'Z')
#define IS_LINE_ID(x) (ALPHA(x) || CAPITAL(x))
#define BLANK(x) ((x) == ' ' || (x) == '\t')
#define END(x) ((x) == '\n' || (x) == 0 || (x) == EOF)
#define NOCHR(x) (BLANK(x) || END(x))

using namespace erisc;

namespace
{
	const char* exceptionHead = "Error reading line ";

	char* genExceptionStr(int line)
	{
		char* buffer = new char[BUFFER_LEN];

		for (int i = 0; i < HEAD_LEN; i++)
			buffer[i] = exceptionHead[i];
		char* i = buffer + HEAD_LEN + (int)floor(log10(line));
		i[1] = 0;
		while (line > 0)
		{
			*i = line % 10 + '0';
			line /= 10;
			i--;
		}
		return buffer;
	}

	bool matches(const char** str, const char* format)
	{
		int len = strlen(format);
		for (int i = 0; i < len; i++)
			if ((*str)[i] != format[i])
				return false;
		if (!NOCHR((*str)[len]))
			return false;
		*str += len;
		return true;
	}
}

Command** input::readCommandsFromFile(const char* fileName, vm::VM* vm)
{
	TextReader* text;
	try
	{
		text = new TextReader(fileName);
	}
	catch (Exception& e)
	{
		throw e;
	}

	int lines = 0;
	while (text->readLine()[0] != 0)
		lines++;

	delete text;

	text = new TextReader(fileName);

	Command** commands = new Command * [lines + 2];
	commands[0] = new Command();
	commands[lines + 1] = nullptr;

	for (int i = 1; i <= lines; i++)
	{
		try 
		{
			commands[i] = readSingleCommand(text->readLine(), vm, i);
		}
		catch (Exception e)
		{
			throw e;
		}
	}
	return commands;
}

Command* input::readSingleCommand(const char* str, vm::VM* vm, int lineNum)
{
	try
	{
		bool isEmptyCommand = false;

		while (NOCHR(*str))
		{
			str++;
			if (END(*str))
			{
				isEmptyCommand = true;
				break;
			}
		}

		if (isEmptyCommand)
		{
			Command* temp = new Command();
			return temp;
		}
		else if (matches(&str, "add"))
		{
			Command* temp = new Add(str);
			return temp;
		}
		else if (matches(&str, "and"))
		{
			Command* temp = new And(str);
			return temp;
		}
		else if (matches(&str, "beq"))
		{
			Command* temp = new Beq(str);
			return temp;
		}
		else if (matches(&str, "bge"))
		{
			Command* temp = new Bge(str);
			return temp;
		}
		else if (matches(&str, "blt"))
		{
			Command* temp = new Blt(str);
			return temp;
		}
		else if (matches(&str, "bne"))
		{
			Command* temp = new Bne(str);
			return temp;
		}
		else if (matches(&str, "call"))
		{
			Command* temp = new Call(str);
			return temp;
		}
		else if (matches(&str, "div"))
		{
			Command* temp = new Div(str);
			return temp;
		}
		else if (matches(&str, "draw"))
		{
			Command* temp = new Draw();
			return temp;
		}
		else if (matches(&str, "end"))
		{
			Command* temp = new End();
			return temp;
		}
		else if (matches(&str, "jal"))
		{
			Command* temp = new Jal(str);
			return temp;
		}
		else if (matches(&str, "load"))
		{
			Command* temp = new Load(str);
			return temp;
		}
		else if (matches(&str, "mov"))
		{
			Command* temp = new Mov(str);
			return temp;
		}
		else if (matches(&str, "mul"))
		{
			Command* temp = new Mul(str);
			return temp;
		}
		else if (matches(&str, "or"))
		{
			Command* temp = new Or(str);
			return temp;
		}
		else if (matches(&str, "pop"))
		{
			Command* temp = new Pop(str);
			return temp;
		}
		else if (matches(&str, "push"))
		{
			Command* temp = new Push(str);
			return temp;
		}
		else if (matches(&str, "rem"))
		{
			Command* temp = new Rem(str);
			return temp;
		}
		else if (matches(&str, "ret"))
		{
			Command* temp = new Ret();
			return temp;
		}
		else if (matches(&str, "store"))
		{
			Command* temp = new Store(str);
			return temp;
		}
		else if (matches(&str, "sub"))
		{
			Command* temp = new Sub(str);
			return temp;
		}
		else
		{
			int lineLen = strlen(str);

			bool lineIdEnded = false;
			int lineIdLen;

			for (int j = 0; j < lineLen; j++)
			{
				if (!lineIdEnded)
				{
					if (IS_LINE_ID(str[j]));
					else if (str[j] == ':')
					{
						lineIdEnded = true;
						lineIdLen = j;
					}
					else
						throw Exception("This line is not a command");
				}
				else
				{
					if (!NOCHR(str[j]))
						throw Exception("Invalid character after lineId");
				}
			}

			char* lineIdName = new char[lineIdLen + 1];
			for (int j = 0; j < lineIdLen; j++)
				lineIdName[j] = str[j];
			lineIdName[lineIdLen] = 0;

			LineId* temp = new LineId(lineIdName, lineNum);
			vm->getLineIdList()->add(temp);
			return (Command*)temp;
		}
	}
	catch (Exception& e)
	{
		char* str = genExceptionStr(lineNum);
		Exception exception(str, e);
		delete str;
		throw exception;
	}
}
