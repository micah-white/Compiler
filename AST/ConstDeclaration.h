#ifndef _ConstDeclaration
#define _ConstDeclaration



#include "Declaration.h"
#include "../SourcePosition.h"
#include "Object.h"

#include <string>

using namespace std;


class ConstDeclaration : public Declaration {

public:

	Identifier* I;
	Expression* E;	

	ConstDeclaration (Identifier* iAST, Expression* eAST,
		SourcePosition* thePosition): Declaration(thePosition) {
    I = iAST;
    E = eAST;
  }

  
	Object* visit(Visitor* v, Object* o) {
    return v->visitConstDeclaration(this, o);
  }

	string class_type(){
	string temp = "CONSTDECLARATION";
	return temp;
	}

};

#endif
