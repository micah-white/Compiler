#ifndef _LetExpression
#define _LetExpression

#include "AST.h"
#include "Expression.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class LetExpression : public Expression {

public:
	Declaration* D;
	Expression* E;

	LetExpression (Declaration* dAST, Expression* eAST, SourcePosition* thePosition): Expression(thePosition) {
    D = dAST;
    E = eAST;
  }

  Object* visit(Visitor* v, Object* o) {
    return v->visitLetExpression(this, o);
  }

	string class_type(){
		string temp = "LETEXPRESSION";
		return temp;
	}  
};

#endif

