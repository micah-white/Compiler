#ifndef _VnameExpression
#define _VnameExpression

#include "Expression.h"
#include "Vname.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class VnameExpression : public Expression {

public:
	Vname* V;

	VnameExpression (Vname* vAST, SourcePosition* thePosition):Expression(thePosition) {
    V = vAST;
  }

 Object* visit(Visitor* v, Object* o) {
    return v->visitVnameExpression(this, o);
  }
  
	string class_type(){
		string temp = "VNAMEEXPRESSION";
		return temp;
	}  
	 
};

#endif

