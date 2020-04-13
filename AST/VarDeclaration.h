#ifndef _VarDeclaration
#define _VarDeclaration


#include "Declaration.h"
#include "Identifier.h"
#include "TypeDenoter.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;


class VarDeclaration : public Declaration {

	public:
		Identifier *I;
		TypeDenoter *T;

	VarDeclaration (Identifier* iAST, TypeDenoter* tAST, SourcePosition* thePosition):Declaration(thePosition) {
		I = iAST;
		T = tAST;
	}
  
	Object* visit(Visitor* v, Object* o) {
	return v->visitVarDeclaration(this, o);
	}

	string class_type()	{
		string temp = "VARDECLARATION";
		return temp;
	}

};

#endif
