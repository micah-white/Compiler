#ifndef _Ifexpression
#define _Ifexpression

#include "AST.h"
#include "Expression.h"
#include <string>
using namespace std;

class IfExpression : public Expression {

public:
	Expression *E1, *E2, *E3;
	
	IfExpression (Expression* e1AST, Expression* e2AST, Expression* e3AST,
		SourcePosition* thePosition): Expression(thePosition) 
	{
		E1 = e1AST;
		E2 = e2AST;
		E3 = e3AST;
	}
    
	Object* visit(Visitor* v, Object* o) {
		return v->visitIfExpression(this, o);
	}
  
	string class_type(){
		string temp = "IFEXPRESSION";
		return temp;
	}
};

#endif
