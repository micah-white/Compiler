#ifndef _UserBinaryOperatorDeclaration
#define _UserBinaryOperatorDeclaration


#include "Declaration.h"
#include "Operator.h"
#include "TypeDenoter.h"
#include "FormalParameterSequence.h"
#include "Expression.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class UserBinaryOperatorDeclaration : public Declaration {

public:
	Operator *O;
	FormalParameterSequence* FPS;
	TypeDenoter *T;
	Expression* E;
	
	UserBinaryOperatorDeclaration (Operator* oAST, FormalParameterSequence* fpsAST, TypeDenoter* rAST, Expression* eAST, SourcePosition* thePosition):Declaration(thePosition) {
		O = oAST;
		FPS = fpsAST;
		T = rAST;
		E = eAST;
 	}

	Object* visit (Visitor* v, Object* o) {
		return v->visitUserBinaryOperatorDeclaration(this, o);
	}  

	string class_type()	{
		string temp = "USERBINARYOPERATORDECLARATION";
		return temp;
	}

};

#endif

