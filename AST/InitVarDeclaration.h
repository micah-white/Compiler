#ifndef _InitVarDeclaration
#define _InitVarDeclaration

#include "AST.h"
#include "../SourcePosition.h"
#include "Declaration.h"
#include "Identifier.h"
#include "Expression.h"
#include "TypeDenoter.h"
#include <string>
using namespace std;

class InitVarDeclaration : public Declaration 
{
public:

	Identifier* I;
	Expression* E;
	TypeDenoter* T;

	InitVarDeclaration (Identifier* iAST, Expression* eAST, SourcePosition* thePosition):Declaration(thePosition) 
	{
		E = eAST;
		I = iAST;
		// T = eAST->typ;
	}

	Object* visit(Visitor* v, Object* o) {
		return v->visitInitVarDeclaration(this, o);
	}
  
	string class_type(){
		string temp = "INITVARDECLARATION";
		return temp;
	}  

	
};

#endif
