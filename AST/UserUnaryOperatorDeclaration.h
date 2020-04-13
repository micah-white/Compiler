#ifndef _UserUnaryOperatorDeclaration
#define _UserUnaryOperatorDeclaration


#include "Declaration.h"
#include "Operator.h"
#include "TypeDenoter.h"
#include "FormalParameterSequence.h"
#include "Expression.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class UserUnaryOperatorDeclaration : public Declaration {

public:
	Operator *O;
	FormalParameterSequence* FPS;
	TypeDenoter *T;
	Expression* E;
	
	UserUnaryOperatorDeclaration (Operator* oAST, FormalParameterSequence* fpsAST, TypeDenoter* rAST, Expression* eAST, SourcePosition* thePosition):Declaration(thePosition) {
		O = oAST;
		FPS = fpsAST;
		T = rAST;
		E = eAST;
 	}

	Object* visit (Visitor* v, Object* o) {
		return v->visitUserUnaryOperatorDeclaration(this, o);
	}

	string class_type()	{
		string temp = "USERUNARYOPERATORDECLARATION";
		return temp;
	}

};

#endif

