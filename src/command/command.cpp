#include "command.h"
#include <cstdio>
#include <cstring>

using vm::VM;

#define DIGIT(x) ((x) >= '0' && (x) <= '9')
#define HEX(x) (DIGIT(x) || ((x) >= 'A' && (x) <= 'F') || ((x) >= 'a' && (x) <= 'f'))
#define HEX_TO_NUM(x) ((x) >= 'a' ? x - 'a' + 10 : ((x) > 'A' ? x - 'A' + 10 : x - '0'))
#define ALPHA(x) ((x) >= 'a' && (x) <= 'z')
#define CAPITAL(x) ((x) >= 'A' && (x) <= 'Z')
#define IS_LINE_ID(x) (ALPHA(x) || CAPITAL(x))
#define BLANK(x) ((x) == ' ' || (x) == '\t' || (x) == ',')
#define REAL_BLANK(x) ((x) == ' ' || (x) == '\t')
#define END(x) ((x) == '\n' || (x) == 0 || (x) == EOF)
#define NOCHR(x) (BLANK(x) || END(x))
namespace
{
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

	bool isLineId(const char* str)
	{
		for (int i = 0; !NOCHR(str[i]); i++)
			if (!IS_LINE_ID(str[i]))
				return false;
		return true;
	}
}
erisc::Param::Param(ParamType type, int value)
{
	this->type = type;
	this->value = value;
	id = nullptr;
}

erisc::Param::Param(const char* id)
{
	value = 0;
	type = ParamType::LINE_ID;
	int len = strlen(id);
	this->id = new char[len + 1];
	for (int i = 0; i < len; i++)
		this->id[i] = id[i];
	this->id[len] = 0;
}

erisc::Param::Param()
{
	type = ParamType::NUMBER;
	value = 0;
}

int erisc::Param::getValue(VM* vm)
{
	if (type == ParamType::NUMBER)
		return value;
	else
	{
		try
		{
			return vm->getRegister(value)->read();
		}
		catch (const char* e)
		{
			throw e;
		}
	}
}

erisc::Command::Command()
{
	paramAmount = 0;
	params = nullptr;
}

erisc::Command::Command(int paramAmount, const char* paramString)
{
	this->paramAmount = paramAmount;
	getParamsFromString(paramString);
}

erisc::Command::~Command()
{
	delete []params;
}

void erisc::Command::run(VM* vm)
{
}

void erisc::Command::getParamsFromString(const char* str)
{
	params = new Param[paramAmount];
	const char* i = str;
	for (int paramIndex = 0; paramIndex < paramAmount; paramIndex++)
	{
		Param& currentParam = params[paramIndex];
		if (!NOCHR(*i))
			throw Exception("Command params format error");

		bool hasComma = false;
		if (paramIndex == 0)
			hasComma = true;

		while (BLANK(*i))
		{
			if (*i == ',')
			{
				if (paramIndex == 0)
					throw Exception("Command params format error");
				hasComma = true;
			}
			i++;
		}
		if (!hasComma)
			throw Exception("Command params format error");

		if (*i == 'x' && DIGIT(i[1]))
		{
			currentParam.type = ParamType::REGISTER;
			if(!DIGIT(i[1]) || (!NOCHR(i[2]) && !DIGIT(i[2])) || (DIGIT(i[1]) && DIGIT(i[2]) && !NOCHR(i[3])))
				throw Exception("Command params format error");
			if (NOCHR(i[2]))
			{
				currentParam.value = i[1] - '0';
				i += 2;
			}
			else
			{
				currentParam.value = (i[1] - '0') * 10 + i[2] - '0';
				i += 3;
			}
			if (currentParam.value >= 32)
				throw Exception("Command params format error");
		}

		else if (ALPHA(*i))
		{
			currentParam.type = ParamType::REGISTER;
			if (matches(&i, "zero"))
				currentParam.value = 0;
			else if (matches(&i, "ra"))
				currentParam.value = 1;
			else if (matches(&i, "sp"))
				currentParam.value = 2;
			else if (matches(&i, "gp"))
				currentParam.value = 3;
			else if (matches(&i, "tp"))
				currentParam.value = 4;
			else if (matches(&i, "t0"))
				currentParam.value = 5;
			else if (matches(&i, "t1"))
				currentParam.value = 6;
			else if (matches(&i, "t2"))
				currentParam.value = 7;
			else if (matches(&i, "fp"))
				currentParam.value = 8;
			else if (matches(&i, "s1"))
				currentParam.value = 9;
			else if (matches(&i, "a0"))
				currentParam.value = 10;
			else if (matches(&i, "a1"))
				currentParam.value = 11;
			else if (matches(&i, "a2"))
				currentParam.value = 12;
			else if (matches(&i, "a3"))
				currentParam.value = 13;
			else if (matches(&i, "a4"))
				currentParam.value = 14;
			else if (matches(&i, "a5"))
				currentParam.value = 15;
			else if (matches(&i, "a6"))
				currentParam.value = 16;
			else if (matches(&i, "a7"))
				currentParam.value = 17;
			else if (matches(&i, "s2"))
				currentParam.value = 18;
			else if (matches(&i, "s3"))
				currentParam.value = 19;
			else if (matches(&i, "s4"))
				currentParam.value = 20;
			else if (matches(&i, "s5"))
				currentParam.value = 21;
			else if (matches(&i, "s6"))
				currentParam.value = 22;
			else if (matches(&i, "s7"))
				currentParam.value = 23;
			else if (matches(&i, "s8"))
				currentParam.value = 24;
			else if (matches(&i, "s9"))
				currentParam.value = 25;
			else if (matches(&i, "s10"))
				currentParam.value = 26;
			else if (matches(&i, "s11"))
				currentParam.value = 27;
			else if (matches(&i, "t3"))
				currentParam.value = 28;
			else if (matches(&i, "t4"))
				currentParam.value = 29;
			else if (matches(&i, "t5"))
				currentParam.value = 30;
			else if (matches(&i, "t6"))
				currentParam.value = 31;
			else if (isLineId(i))
			{
				currentParam.type = ParamType::LINE_ID;
				int len = 0;
				for (const char* temp = i; !NOCHR(*temp); temp++)
					len++;
				currentParam.id = new char[len + 1];
				for (int j = 0; j <= len; j++)
					currentParam.id[j] = i[j];
				i += len;
				currentParam.id[len] = 0;
			}
			else
				throw Exception("Command params format error");
		}

		else if (*i == '-')
		{
			i++;
			while (DIGIT(*i))
			{
				if (currentParam.value > 214748364)
					throw Exception("Command params format error");
				if (currentParam.value == 214748364)
				{
					if (*i > '8')
					{
						throw Exception("Command params format error");
					}
					else if(*i == '8')
					{
						if (!NOCHR(*(i + 1)))
							throw Exception("Command params format error");
						currentParam.value = -2147483648;
						goto end;
					}
				}
				currentParam.value *= 10;
				currentParam.value += *i - '0';
				i++;
			}
			if (!NOCHR(*i))
				throw Exception("Command params format error");
			currentParam.value *= -1;
		end:;
		}

		else if (*i == '0' && *(i + 1) == 'x')
		{
			i += 2;
			unsigned int temp = 0;
			while (HEX(*i))
			{
				if (temp > 0xfffffff)
					throw Exception("Command params format error");
				temp *= 16;
				temp += HEX_TO_NUM(*i);
				i++;
			}
			currentParam.value |= temp;
			if (!NOCHR(*i))
				throw Exception("Command params format error");
		}
		
		else if (DIGIT(*i))
		{
			while (DIGIT(*i))
			{
				if (currentParam.value > 214748364)
					throw Exception("Command params format error");
				if (currentParam.value == 214748364)
				{
					if (*i > '7')
						throw Exception("Command params format error");
				}
				currentParam.value *= 10;
				currentParam.value += *i - '0';
				i++;
			}
			if (!NOCHR(*i))
				throw Exception("Command params format error");
		}

		else
		{
			throw Exception("Command params format error");
		}
	}

	while (REAL_BLANK(*i))
		i++;

	if(!END(*i))
		throw Exception("Command params format error");
}
