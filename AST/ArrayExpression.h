#ifndef _ArrayExpression
#define _ArrayExpression


#include "AST.h"
#include "Expression.h"
#include "../SourcePosition.h"
#include "Object.h"
#include <string>

using namespace std;


class ArrayExpression : public Expression {

public:
	ArrayAggregate* AA;

	ArrayExpression (ArrayAggregate* aaAST,SourcePosition* thePosition):Expression(thePosition) {
    AA = aaAST;
  }


  Object* visit (Visitor* v, Object* o) {
    return v->visitArrayExpression(this, o);
  }
  
  string class_type(){
	string temp = "ARRAYEXPRESSION";
	return temp;
}
  
};

#endif
