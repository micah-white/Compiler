#ifndef _SequentialDeclaration
#define _SequentialDeclaration

#include "Declaration.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class SequentialDeclaration : public Declaration {

public:
	Declaration *D1, *D2;

	SequentialDeclaration (Declaration *d1AST, Declaration *d2AST,
		SourcePosition *thePosition) : Declaration(thePosition) {
    D1 = d1AST;
    D2 = d2AST;
  }
  
  Object* visit(Visitor* v, Object* o) {
    return v->visitSequentialDeclaration(this, o);
  }

	string class_type()	{
		string temp = "SEQUENTIALDECLARATION";
		return temp;
	}

};

#endif
