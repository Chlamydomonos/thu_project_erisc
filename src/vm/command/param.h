#ifndef PARAM_H
#define PARAM_H

namespace erisc
{
	enum ParamType
	{
		REGISTER,
		NUMBER
	};
	struct Param
	{
		ParamType type;
		int value;
		Param(ParamType type, int value);
	};
}

#endif // !PARAM_H
