#ifndef _TypeDenoter
#define _TypeDenoter

#include <stdio.h> 
#include <stdlib.h> 
#include <string>
#include "AST.h"
#include "../SourcePosition.h"
using namespace std;


class TypeDenoter : public AST 
{
public:

	TypeDenoter(SourcePosition* thePosition):AST(thePosition){};

	virtual bool equals(Object* obj)
	{
		return false;
	}
};

#endif
