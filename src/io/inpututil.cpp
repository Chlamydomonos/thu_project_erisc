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
	TextReader* text = new TextReader(fileName);

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
			const char* line = text->readLine();

			bool isEmptyCommand = false;

			while (NOCHR(*line))
			{
				line++;
				if (END(*line))
				{
					isEmptyCommand = true;
					break;
				}
			}

			if (isEmptyCommand)
			{
				Command* temp = new Command();
				commands[i] = temp;
			}
			else if (matches(&line, "add"))
			{
				Command* temp = new Add(line);
				commands[i] = temp;
			}
			else if (matches(&line, "and"))
			{
				Command* temp = new And(line);
				commands[i] = temp;
			}
			else if (matches(&line, "beq"))
			{
				Command* temp = new Beq(line);
				commands[i] = temp;
			}
			else if (matches(&line, "bge"))
			{
				Command* temp = new Bge(line);
				commands[i] = temp;
			}
			else if (matches(&line, "blt"))
			{
				Command* temp = new Blt(line);
				commands[i] = temp;
			}
			else if (matches(&line, "bne"))
			{
				Command* temp = new Bne(line);
				commands[i] = temp;
			}
			else if (matches(&line, "call"))
			{
				Command* temp = new Call(line);
				commands[i] = temp;
			}
			else if (matches(&line, "div"))
			{
				Command* temp = new Div(line);
				commands[i] = temp;
			}
			else if (matches(&line, "draw"))
			{
				Command* temp = new Draw();
				commands[i] = temp;
			}
			else if (matches(&line, "end"))
			{
				Command* temp = new End();
				commands[i] = temp;
			}
			else if (matches(&line, "jal"))
			{
				Command* temp = new Jal(line);
				commands[i] = temp;
			}
			else if (matches(&line, "load"))
			{
				Command* temp = new Load(line);
				commands[i] = temp;
			}
			else if (matches(&line, "mov"))
			{
				Command* temp = new Mov(line);
				commands[i] = temp;
			}
			else if (matches(&line, "mul"))
			{
				Command* temp = new Mul(line);
				commands[i] = temp;
			}
			else if (matches(&line, "or"))
			{
				Command* temp = new Or(line);
				commands[i] = temp;
			}
			else if (matches(&line, "pop"))
			{
				Command* temp = new Pop(line);
				commands[i] = temp;
			}
			else if (matches(&line, "push"))
			{
				Command* temp = new Push(line);
				commands[i] = temp;
			}
			else if (matches(&line, "rem"))
			{
				Command* temp = new Rem(line);
				commands[i] = temp;
			}
			else if (matches(&line, "ret"))
			{
				Command* temp = new Ret();
				commands[i] = temp;
			}
			else if (matches(&line, "store"))
			{
				Command* temp = new Store(line);
				commands[i] = temp;
			}
			else if (matches(&line, "sub"))
			{
				Command* temp = new Sub(line);
				commands[i] = temp;
			}
			else
			{
				int lineLen = strlen(line);

				bool lineIdEnded = false;
				int lineIdLen;

				for (int j = 0; j < lineLen; j++)
				{
					if (!lineIdEnded)
					{
						if (IS_LINE_ID(line[j]));
						else if (line[j] == ':')
						{
							lineIdEnded = true;
							lineIdLen = j;
						}
						else
							throw Exception("This line is not a command");
					}
					else
					{
						if (!NOCHR(line[j]))
							throw Exception("Invalid character after lineId");
					}
				}

				char* lineIdName = new char[lineIdLen + 1];
				for (int j = 0; j < lineIdLen; j++)
					lineIdName[j] = line[j];
				lineIdName[lineIdLen] = 0;

				LineId* temp = new LineId(lineIdName, i);
				vm->getLineIdList()->add(temp);
				commands[i] = (Command*)temp;
			}
		}
		catch (Exception& e)
		{
			char* str = genExceptionStr(i);
			Exception exception(str, e);
			delete str;
			throw exception;
		}
	}
	return commands;
}