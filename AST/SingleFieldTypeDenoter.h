#ifndef _SingleFieldTypeDenoter
#define _SingleFieldTypeDenoter

#include "FieldTypeDenoter.h"
#include "Identifier.h"
#include "TypeDenoter.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class SingleFieldTypeDenoter : public FieldTypeDenoter {

public:
	Identifier* I;
    TypeDenoter* T;

	SingleFieldTypeDenoter (Identifier* iAST, TypeDenoter* tAST,
		SourcePosition* thePosition): FieldTypeDenoter(thePosition) {
    I = iAST;
    T = tAST;
  }
  
  Object* visit (Visitor* v, Object* o) {
    return v->visitSingleFieldTypeDenoter(this, o);
  }

	bool equals (Object* obj) 
	{
		if (obj != NULL && obj->class_type() == "SINGLEFIELDTYPEDENOTER")
		{
			SingleFieldTypeDenoter* ft = (SingleFieldTypeDenoter*)obj;
			return (this->I->spelling == ft->I->spelling) && this->T->equals(ft->T);
		}
		else
			return false;
	}

	string class_type()	{
		string temp = "SINGLEFIELDTYPEDENOTER";
		return temp;
	}
};

#endif
