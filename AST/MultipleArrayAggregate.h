#ifndef _MultipleArrayAggregate
#define _MultipleArrayAggregate

#include "AST.h"
#include "ArrayAggregate.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class MultipleArrayAggregate : public ArrayAggregate {

public:
	Expression* E;
	ArrayAggregate* AA;

	MultipleArrayAggregate (Expression *eAST, ArrayAggregate *aaAST,
		SourcePosition *thePosition): ArrayAggregate(thePosition) 
	{
		E = eAST;
		AA = aaAST;
	}

	Object* visit (Visitor* v, Object* o)
	{
		return v->visitMultipleArrayAggregate(this, o);
	}

	string class_type()
	{
		string temp = "MULTIPLEARRAYAGGREGATE";
		return temp;
	}  
};

#endif
