#ifndef _EmptyExpression
#define _EmptyExpression

#include "Expression.h"
#include "../SourcePosition.h"
#include "Object.h"
#include <string>

using namespace std;

class EmptyExpression : public Expression 
{
public:

	EmptyExpression (SourcePosition* thePosition):Expression(thePosition) {};
	
	Object* visit(Visitor* v, Object* o) 
	{
		return v->visitEmptyExpression(this, o);
	}

    string class_type()
	{
		string temp = "EMPTYEXPRESSION";
		return temp;
	}
};

#endif
