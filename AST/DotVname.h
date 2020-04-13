#include <stdio.h> 
#include <stdlib.h> 
#include <string>
#include "AST.h"
#include "Identifier.h"
#include "Vname.h"
#include "../SourcePosition.h"


using namespace std;

#ifndef _DotVname
#define _DotVname


class DotVname : public Vname {

public:
	Identifier* I;
	Vname* V;

	DotVname (Vname* vAST, Identifier* iAST, SourcePosition* thePosition): Vname(thePosition) {
    V = vAST;
    I = iAST;
  }

   Object* visit (Visitor* v, Object* o) {
    return v->visitDotVname(this, o);
  }

	string class_type(){
		string temp = "DOTVNAME";
		return temp;
	}
  
};


#endif
