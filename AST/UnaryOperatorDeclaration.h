#ifndef _UnaryOperatorDeclaration
#define _UnaryOperatorDeclaration


#include "Declaration.h"
#include "Operator.h"
#include "TypeDenoter.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class UnaryOperatorDeclaration : public Declaration {

public:
	Operator *O;
	TypeDenoter *ARG, *RES;

	
	UnaryOperatorDeclaration (Operator* oAST, TypeDenoter* argAST, TypeDenoter* resultAST, SourcePosition* thePosition):Declaration(thePosition) {
    O = oAST;
    ARG = argAST;
    RES = resultAST;
  }

  Object* visit (Visitor* v, Object* o) {
    return v->visitUnaryOperatorDeclaration(this, o);
  }  

	string class_type()	{
		string temp = "UNARYOPERATORDECLARATION";
		return temp;
	}



};

#endif

