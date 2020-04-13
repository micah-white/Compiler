#ifndef _BinaryExpression
#define _BinaryExpression


#include "Operator.h"
#include "Expression.h"
#include "Object.h"
#include "../SourcePosition.h"
#include <string>

using namespace std;


class BinaryExpression : public Expression {

public:
	Expression* E1;
	Expression* E2;
  Operator* O;	

	BinaryExpression (Expression* e1AST, Operator* oAST, Expression* e2AST,
		SourcePosition* thePosition):Expression(thePosition) {
    O = oAST;
    E1 = e1AST;
    E2 = e2AST;
  }



  Object* visit(Visitor* v, Object* o) {
    return v->visitBinaryExpression(this, o);
  }

  string class_type(){
	string temp = "BINARYEXPRESSION";
	return temp;
}
  
};

#endif

