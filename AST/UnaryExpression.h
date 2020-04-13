#ifndef _UnaryExpression
#define _UnaryExpression

#include "Expression.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class UnaryExpression : public Expression {

public:
	Expression* E;
    Operator* O;

	UnaryExpression (Operator* oAST, Expression* eAST,
		SourcePosition* thePosition):Expression(thePosition) {
    O = oAST;
    E = eAST;
  }

  Object* visit(Visitor* v, Object* o) {
    return v->visitUnaryExpression(this, o);
  }

	string class_type()	{
		string temp = "UNARYEXPRESSION";
		return temp;
	}
  
};


#endif
