#ifndef _PVInt
#define _PVInt

#include "../AST/Object.h"

class PVInt : public Object
{
public:
	int value;

	PVInt() : Object("PVINT")
	{
		value = 0;
	}

	PVInt(int x) : Object("PVINT")
	{
		value = x;
	}
};

#endif

