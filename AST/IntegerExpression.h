#ifndef _IntegerExpression
#define _IntegerExpression


#include "AST.h"
#include "../SourcePosition.h"
#include "Expression.h"
#include <string>
using namespace std;

class IntegerExpression : public Expression {

public:
	IntegerLiteral* IL;

	IntegerExpression (IntegerLiteral* ilAST, SourcePosition* thePosition): Expression(thePosition) {
    IL = ilAST;
  }

	Object* visit(Visitor* v, Object* o) {
		return v->visitIntegerExpression(this, o);
	}

	string class_type(){
		string temp = "INTEGEREXPRESSION";
		return temp;
	}  
};


#endif

