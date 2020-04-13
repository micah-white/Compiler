#ifndef _SimpleTypeDenoter
#define _SimpleTypeDenoter

#include "TypeDenoter.h"
#include "Identifier.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class SimpleTypeDenoter : public TypeDenoter {

public:
	Identifier *I;
	SimpleTypeDenoter (Identifier* iAST, SourcePosition* thePosition):TypeDenoter(thePosition) {
    I = iAST;
  }
  
  Object* visit (Visitor* v, Object* o) {
    return v->visitSimpleTypeDenoter(this, o);
  }

  bool equals (Object* obj) {
    return false;
  }

	string class_type()	{
		string temp = "SIMPLETYPEDENOTER";
		return temp;
	}  
};


#endif
