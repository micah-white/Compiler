#ifndef _SimpleVname
#define _SimpleVname

#include "Vname.h"
#include "Identifier.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class SimpleVname : public Vname {

public:
	Identifier* I;

	SimpleVname (Identifier* iAST, SourcePosition* thePosition):Vname(thePosition) {
    I = iAST;
  }
  
  Object* visit (Visitor* v, Object* o) {
    return v->visitSimpleVname(this, o);
  }
  
	string class_type()	{
		string temp = "SIMPLEVNAME";
		return temp;
	}  
};

#endif

